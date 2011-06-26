/*
 * $Id: GraphDisplayer.java,v 1.1 2004/12/07 17:53:23 bdickie Exp $
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

import java.awt.*;
import java.awt.geom.*;
import java.awt.image.*;
import javax.swing.*;
import java.util.*;
import java.awt.event.*;

import java.io.*;
import javax.imageio.ImageIO;

import org.w3c.dom.*;

import ca.uvic.cs.gold.bdickie.*;
import ca.uvic.cs.gold.bdickie.fs.*;
import ca.uvic.cs.gold.bdickie.graphview.framework.*;
import ca.uvic.cs.gold.bdickie.graphview.*;

/** The actual Java GUI item that renders the graph to the screen.
 *
 * @author  Blake Dickie
 */
public class GraphDisplayer extends JComponent {
    private static final int MARGIN = 5;
    
    private GraphGenerator generator;
    private RadialLayoutTree tree;
    private Directory root;
    private AffineTransform identity = new AffineTransform();
    private HashMap renderPoints;
    private int maxWidth = Integer.MAX_VALUE;
    private int boxWidth;
    private Graphics2D graphics;
    private BufferedImage image;
    private FontMetrics fontMetrics;
    private Map areaToFile;
    private Graph graph;
    
    
    private final static double halfPI = Math.PI / 2;
    private final static double oneHalfPI = Math.PI + halfPI;
    
    /** Creates a new instance of GraphDisplayer */
    public GraphDisplayer(RadialLayoutTree tree, Graph g) {
        this.tree = tree;
        graph = g;
        root = g.getSettings().getRoot();
        renderPoints = new HashMap();
        areaToFile = new HashMap();
        addMouseListener(new MouseClientWatcher());
        initalizeViewer();
    }
    
    /** Resets the viewer so that the graph is redrawn (doesn't relayout the 
     *  graph).
     */
    public void initalizeViewer() {
        
        Collection treeNodes = tree.getNodes();
        areaToFile.clear();
        fontMetrics = getFontMetrics(GraphViewOptions.getFont());
        GraphViewMode view = graph.getViewMode();
        
        
        boxWidth = tree.getLayerDepth() / 2;
        
        Dimension bounds = tree.getBounds();
        
        /* Create a buffer to save the image to so we don't have to redraw it
           for scrolling, etc.
         */
        image = new BufferedImage(bounds.width + 2 * boxWidth + 2*MARGIN, bounds.height + 2 * boxWidth + 2*MARGIN, BufferedImage.TYPE_INT_RGB);
        graphics = (Graphics2D)image.getGraphics();
        
        // Get the base transform for the class (important for when in a scroll box).
        identity = graphics.getTransform();
        
        renderPoints.clear();
        
        graphics.setBackground(Color.WHITE);
        graphics.setFont(GraphViewOptions.getFont());
        
        graphics.setColor(Color.WHITE);
        graphics.fillRect(0, 0, image.getWidth(), image.getHeight());
        
        graphics.setColor(Color.BLACK);
        
        Iterator i = treeNodes.iterator();
        while(i.hasNext()) {
            DirectoryContent c = (DirectoryContent)i.next();
            
            GraphViewSpecification specs = view.getViewFor(c);
            
            if (specs == null)
                continue;
            
            
            NodeRenderPoint p1 = findPoint(c);
            
            if (!c.equals(root)) {
                // Draw the line to its parent.
                NodeRenderPoint p2 = findPoint(c.getParent());
                
                graphics.setTransform(identity);
                graphics.drawLine(p1.baseX, p1.baseY, p2.attachX, p2.attachY);
            }
            
            graphics.setTransform(generateTransformer(p1, true));
            
            // Figure out the text size.
            int textWidth = fontMetrics.stringWidth(specs.getText());
            int textHeight = fontMetrics.getHeight();
            
            
            // Draw the background colour.
            graphics.setColor(specs.getBackgroundColor());
            graphics.fillRect(p1.baseX, p1.baseY - textHeight / 2, boxWidth, textHeight + 2);
            
            // Draw the border.
            graphics.setColor(specs.getBorderColor());
            graphics.setStroke(new BasicStroke(specs.getBorderWidth()));
            
            graphics.drawRect(p1.baseX, p1.baseY - textHeight / 2, boxWidth, textHeight + 2);
            
            
            // Get the shape of the box so we can test for clicks on it.
            Point2D[] rectangleSrc = new Point2D[4];
            rectangleSrc[0] = new Point2D.Double(p1.baseX, p1.baseY - textHeight / 2);
            rectangleSrc[1] = new Point2D.Double(p1.baseX, p1.baseY + textHeight + 2);
            rectangleSrc[2] = new Point2D.Double(p1.baseX + boxWidth, p1.baseY + textHeight + 2);
            rectangleSrc[3] = new Point2D.Double(p1.baseX + boxWidth, p1.baseY - textHeight / 2);
            Point2D[] rectangleDest = new Point2D[4];
            generateTransformer(p1, false).transform(rectangleSrc, 0, rectangleDest, 0, 4);
            
            GeneralPath rect = new GeneralPath();
            rect.moveTo((float)rectangleDest[3].getX(), (float)rectangleDest[3].getY());
            for(int index = 0; index < 4; index++)
                rect.lineTo((float)rectangleDest[index].getX(), (float)rectangleDest[index].getY());
            areaToFile.put(rect, c);
            
            // If the test is to long add ... to the end.
            String toWrite = specs.getText();
            if (fontMetrics.stringWidth(toWrite) > boxWidth - 4) {
                toWrite += "...";
                while(fontMetrics.stringWidth(toWrite) > boxWidth - 4) {
                    toWrite = toWrite.substring(0, toWrite.length() - 4) + "...";
                }
                textWidth = fontMetrics.stringWidth(toWrite);
                textHeight = fontMetrics.getHeight();
            }
            
            
            graphics.setStroke(new BasicStroke());
            graphics.setColor(specs.getTextColor());
            // Draw the text.
            if ((p1.angle > halfPI) && (p1.angle < oneHalfPI)) {
                // If in the left half of the graph we need to reverse the angle.
                AffineTransform anchorRotate = new AffineTransform();
                anchorRotate.setToRotation(p1.angle - Math.PI, p1.attachX, p1.attachY);
                anchorRotate.preConcatenate(identity);
                graphics.setTransform(anchorRotate);
                graphics.drawString(toWrite, p1.attachX + (boxWidth - textWidth) / 2, p1.attachY + (textHeight - fontMetrics.getDescent()) / 2);
            } else {
                graphics.drawString(toWrite, p1.baseX + (boxWidth - textWidth) / 2, p1.baseY  + (textHeight - fontMetrics.getDescent()) / 2);
            }
        }
        
        // Update the component size.
        Dimension componentBounds = new Dimension(image.getWidth(), image.getHeight());
        setPreferredSize(componentBounds);
        setMaximumSize(componentBounds);
        setMinimumSize(componentBounds);
        setSize(componentBounds);
        
        renderPoints.clear();
    }
    
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.clearRect(0, 0, getWidth(), getHeight());
        if (image != null)
            g.drawImage(image, 0, 0, null);
    }
    
    private NodeRenderPoint findPoint(DirectoryContent c) {
        if (renderPoints.containsKey(c))
            return (NodeRenderPoint)renderPoints.get(c);
        
        NodeRenderPoint result = new NodeRenderPoint();
        GraphNodeDisplayParams p1 = tree.getLocationFor(c);
        result.baseX = p1.x + boxWidth + MARGIN;
        result.baseY = p1.y + boxWidth + MARGIN;
        result.angle = p1.angle;
        
        if (p1.root) {
            result.attachX = result.baseX;
            result.attachY = result.baseY;
            result.baseX -= boxWidth / 2;
        } else {
            AffineTransform transformer = generateTransformer(result, false);
            Point2D p = new Point2D.Double(result.baseX + boxWidth, result.baseY);
            Point2D rotated = new Point2D.Double();
            transformer.transform(p, rotated);
            result.attachX = (int)rotated.getX();
            result.attachY = (int)rotated.getY();
        }
        
        if (c.isDirectory()) {
            renderPoints.put(c, result);
        }
        
        return result;
    }
    
    private AffineTransform generateTransformer(NodeRenderPoint point, boolean considerIdentity) {
        AffineTransform anchorRotate = new AffineTransform();
        anchorRotate.setToRotation(point.angle, point.baseX, point.baseY);
        if (considerIdentity)
            anchorRotate.preConcatenate(identity);
        return anchorRotate;
    }
    
    
    public boolean saveToFile(java.io.File file) {
        try {
            ImageIO.write(image, "png", file);
            return true;
        } catch (IOException e) {
            ErrorLog.reportError("Error saving graph.", e.getMessage(), false);
            return false;
        }
    }
    
    private class NodeRenderPoint {
        int baseX;
        int baseY;
        
        int attachX;
        int attachY;
        
        double angle;
    }
    
    private class MouseClientWatcher extends MouseAdapter {
        public void mouseClicked(MouseEvent e) {
            DirectoryContent c = getNodeAt(e.getPoint());
            if (c != null)
                graph.getViewMode().mousePressed(c, e);
        }
        
        
        
        private DirectoryContent getNodeAt(Point p) {
            Iterator i = areaToFile.keySet().iterator();
            while(i.hasNext()) {
                Shape s = (Shape)i.next();
                if (s.contains(p.x, p.y))
                    return (DirectoryContent)areaToFile.get(s);
            }
            return null;
        }
    }
    
}

/* ChangeLog:
 *   $Log: GraphDisplayer.java,v $
 *   Revision 1.1  2004/12/07 17:53:23  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 */
