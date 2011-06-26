/*
 * $Id: RadialLayoutTree.java,v 1.1 2004/12/07 17:53:23 bdickie Exp $
 *
 * Repository Explorer and Repository Grapher
 * Copyright (C) 2004 Blake Dickie
 *
 * This program is free software; you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation; either version 2 of the License, or 
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program; if not, write to the Free Software 
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, 
 * MA 02111-1307 USA
 *
 */

package ca.uvic.cs.gold.bdickie.graphview.engine;

import java.util.*;
import ca.uvic.cs.gold.bdickie.fs.*;
import java.awt.Point;
import java.awt.Dimension;


/** The data structure that handles calculating the position each file should have
 *  on each layer.
 *
 *  Based on concepts in the paper "Radial Tree Graph Drawing Algorithm for 
 *  Representing Large Hierarchies" by Greg Book and Neeta Keshary.
 *
 * @author  Blake Dickie
 */
public class RadialLayoutTree {
    private Map objectToNode;
    private ArrayList layers;
    private int layerDepth;
    private static final double TwoPi = Math.PI * 2;
    private Point offset = null;
    private Dimension bounds = null;
    
    private Node firstDirectory = null;
    private Node lastDirectory = null;
    
    /** Creates a new instance of RadialLayout */
    public RadialLayoutTree(int layerDepth, DirectoryContent root) {
        objectToNode = new HashMap();
        layers = new ArrayList();
        this.layerDepth = layerDepth;
        addNodeHandler(root, true);
    }
    
    /** Calculates the layout of the nodes
     */
    public void generateLayout() {
        for(int level = 0; level < layers.size(); level++)
        {
            List layer = (List)layers.get(level);
            if (level == 0)
            {
                // The root goes at the center and its children get the entire
                // circle.
                Node root = (Node)layer.get(0);
                root.x = 0;
                root.y = 0;
                root.angle = 0;
                root.leftLimit = TwoPi;
                root.rightLimit = 0;
            } else {
                // Find all the parents
                HashSet parents = new HashSet(0);
                Iterator i = layer.iterator();
                while(i.hasNext())
                {
                    Node n = (Node)i.next();
                    parents.add(n.parent);
                }
                
                firstDirectory = null;
                lastDirectory = null;
                
                ArrayList prevLevel = new ArrayList((List)layers.get(level - 1));
                
                i = prevLevel.iterator();
                while(i.hasNext())
                {
                    // Go through the parents in order and add children.
                    Node parent = (Node)i.next();
                    if (parents.contains(parent))
                        addChildren(parent);
                }
                cleanUpFirst();
            }
        }
        
    }
    
    private void addChildren(Node parent)
    {
        Iterator i = parent.children.iterator();
        int childCount = 0;
        double angleSpace = parent.leftLimit - parent.rightLimit;
        while(i.hasNext())
        {
            Node n = (Node)i.next();
            n.angle = angleSpace * childCount / parent.children.size() + parent.rightLimit;
            n.x = n.layer * Math.cos(n.angle);
            n.y = n.layer * Math.sin(n.angle);
            
            if (n.isDirectory)
            {
                if (firstDirectory == null)
                    firstDirectory = n;
                
                if (lastDirectory != null)
                {
                    double splitPoint = averageAngles(lastDirectory.angle, n.angle);
                    n.rightBisectorLimit = splitPoint;
                    lastDirectory.leftBisectorLimit = splitPoint;
                    setLimits(lastDirectory);
                }
                
                double tanAngle = fixAngle(Math.acos((n.layer + 0.5)/(double)(n.layer + 1)));
                
                n.leftTangetLimit = n.angle + tanAngle;
                n.rightTangetLimit = n.angle - tanAngle;
                
                setLimits(n);
                
                lastDirectory = n;
            }
            
            childCount++;
        }
    }
    
    private void cleanUpFirst()
    {
        if (firstDirectory != null)
        {
            double splitPoint = averageAngles(lastDirectory.angle, firstDirectory.angle);
            firstDirectory.rightBisectorLimit = splitPoint;
            lastDirectory.leftBisectorLimit = splitPoint;
            
            setLimits(firstDirectory);
            setLimits(lastDirectory);
        }
    }
    
    /** Averages two angles to find the midway angle between them.
     */
    private double averageAngles(double lower, double higher)
    {
        return fixAngle((ensureAngleIsGreater(higher, lower) + lower) / 2);
    }
        
    /** Ensures that angle is within the range [then, then + 2*Pi).
     *
     *  @return The corrected value for angle.
     */
    private double ensureAngleIsGreater(double angle, double then)
    {
        double result = angle;
        
        while(result < then)
            result += TwoPi;
        while(angle - then >= TwoPi)
            result -= TwoPi;
        return result;
    }
   
    private double fixLowerLimit(double limit, double angle)
    {
        double result = limit;
        while(angle - result >= TwoPi)
            result += TwoPi;
        while(result > angle)
            result -= TwoPi;
        return result;
    }
    
    private double fixUpperLimit(double limit, double angle)
    {
        double result = limit;
        while(result - angle >= TwoPi)
            result -= TwoPi;
        
        while(result < angle)
            result += TwoPi;
        return result;
    }
    
    private double fixAngle(double angle)
    {
        while(angle < 0)
            angle += TwoPi;
        while(angle >= TwoPi)
            angle -= TwoPi;
        return angle;
    }
    
    private void setLimits(Node n) {
        n.angle = fixAngle(n.angle);
        n.leftBisectorLimit = fixUpperLimit(n.leftBisectorLimit, n.angle);
        n.rightBisectorLimit = fixLowerLimit(n.rightBisectorLimit, n.angle);
        
        n.leftTangetLimit = fixUpperLimit(n.leftTangetLimit, n.angle);
        n.rightTangetLimit = fixLowerLimit(n.rightTangetLimit, n.angle);
        
        
        
        n.leftLimit = Math.min(n.leftBisectorLimit, n.leftTangetLimit);
        
        n.rightLimit = Math.max(n.rightBisectorLimit, n.rightTangetLimit);
    }
    
    public void addNode(DirectoryContent node) {
        addNodeHandler(node, false);
    }
    
    private void addNodeHandler(DirectoryContent node, boolean root) {
        Node n = new Node();
        n.object = node;
        n.isRoot = root;
        
        if (!root) {
            Node parent = getNodeFor(node.getParent());
            n.parent = parent;
            n.layer = parent.layer + 1;
            parent.children.add(n);
        } else
            n.layer = 0;
        
        for(int i = layers.size(); i <= n.layer; i++)
            layers.add(new ArrayList());
        
        n.isDirectory = node.isDirectory();
        
        if (n.isDirectory)
            n.children = new ArrayList();
        
        ((List)layers.get(n.layer)).add(n);
        objectToNode.put(node, n);
    }
    
    private Node getNodeFor(DirectoryContent content) {
        return (Node)objectToNode.get(content);
    }
    
    public GraphNodeDisplayParams getLocationFor(DirectoryContent node) {
        GraphNodeDisplayParams result = new GraphNodeDisplayParams();
        Node n = getNodeFor(node);
        Point p = getOffset();
        if (n == null)
        {
            System.out.println("Bad on " + node.getPath());
            System.exit(0);
        }

        result.x = (int)(layerDepth*n.x) + p.x;
        result.y = (int)(layerDepth*n.y) + p.y;
        result.angle = n.angle;
        result.root = n.isRoot;
        return result;
    }
    
    public Point getOffset() {
        initalizeBounds();
        
        return offset;
    }
    
    public Dimension getBounds() {
        initalizeBounds();
        return bounds;
    }
    
    private void initalizeBounds() {
        if (offset == null) {
            double minX = Double.MAX_VALUE;
	    double minY = Double.MAX_VALUE;
            double maxX = Double.MIN_VALUE;
            double maxY = Double.MIN_VALUE;
            
            Iterator i = objectToNode.values().iterator();
            while(i.hasNext()) {
                Node n = (Node)i.next();
                if (n.x < minX)
                    minX = n.x;
                if (n.y < minY)
                    minY = n.y;
                if (n.x > maxX)
                    maxX = n.x;
                if (n.y > maxY)
                    maxY = n.y;
            }
            offset = new Point((int)(layerDepth*-1*minX), (int)(layerDepth*-1*minY));
            bounds = new Dimension((int)(layerDepth*(maxX - minX)), (int)(layerDepth*(maxY - minY)));
        }
    }
    
    public List getNodes() {
        ArrayList result = new ArrayList(objectToNode.size());
        for(int i = layers.size() - 1; i >= 0; i--)
        {
            List l = (List)layers.get(i);
            Iterator i2 = l.iterator();
            while(i2.hasNext()) {
                Node n = (Node)i2.next();
                result.add(n.object);
            }
        }
        return result;
    }
    
    /**
     * Getter for property layerDepth.
     * @return Value of property layerDepth.
     */
    public int getLayerDepth() {
        return layerDepth;
    }
    
    /**
     * Setter for property layerDepth.
     * @param layerDepth New value of property layerDepth.
     */
    public void setLayerDepth(int layerDepth) {
        this.layerDepth = layerDepth;
        offset = null;
    }
    
    private class Node {
        int layer;
        Node parent;
        DirectoryContent object;
        boolean isDirectory;
        boolean isRoot;
        
        List children;
        double x, y;
        double angle;
        
        double rightBisectorLimit;
        double leftBisectorLimit;
        double rightTangetLimit;
        double leftTangetLimit;
        double rightLimit;
        double leftLimit;
    }
}

/* ChangeLog:
 *   $Log: RadialLayoutTree.java,v $
 *   Revision 1.1  2004/12/07 17:53:23  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 */
