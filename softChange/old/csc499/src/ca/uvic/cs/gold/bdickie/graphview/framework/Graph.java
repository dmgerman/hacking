/*
 * $Id: Graph.java,v 1.1 2004/12/07 17:53:23 bdickie Exp $
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

package ca.uvic.cs.gold.bdickie.graphview.framework;


import java.util.*;
import java.awt.*;

import org.w3c.dom.*;
import ca.uvic.cs.gold.bdickie.*;
import java.io.*;

import ca.uvic.cs.gold.bdickie.graphview.engine.*;
import ca.uvic.cs.gold.bdickie.fs.*;
import ca.uvic.cs.gold.bdickie.db.DBConnection;

/** The parent data structure of the the graph system.
 *  Handles setting up the other classes and access to the
 *  settings.
 *
 * @author  Blake Dickie
 */
public class Graph {
    public static final String initalDescription =  "--Inital State--";
    
    private GraphSettings settings;
    
    private int layerDepth = 200;
    
    
    private RadialLayoutTree tree;
    private GraphDisplayer display;
    
    private GraphViewMode view;
    
    
    /** Creates a new instance of Graph */
    public Graph(GraphSettings settings) {
        this.settings = settings;
        view = settings.getViewMode();
        view.addedToGraph(this);
        initalize();
    }
    
    public GraphSettings getSettings() {
        return settings;
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
        tree.setLayerDepth(layerDepth);
        forceUpdate();
    }
    
    /** Get the display component that should be used to render this graph.
     */
    public GraphDisplayer getDisplay() {
        return display;
    }
    
    
    
    private void initalize() {
        
        
        GraphGenerator generator = new GraphGenerator(settings);
        tree = generator.generateGraph();
        tree.setLayerDepth(getLayerDepth());
        tree.generateLayout();
        display = new GraphDisplayer(tree, this);
        
    }
    
    /** Saves the graph's information to a XML file.
     */
    public void generateXML(java.io.File output) {
        try {
            Document doc = XMLSupportFunctions.newXMLTree("export");
            Element root = doc.getDocumentElement();
            root.setAttribute("rootpath",  settings.getRoot().getPath());
            XMLAddChildren(settings.getRoot(), root, doc);
            
            FileWriter out = new FileWriter(output);
            XMLSupportFunctions.writeXMLToStream(doc, out);
            out.close();
        } catch (Exception e) {
            ErrorLog.reportError("Error exporting to XML.", e.getMessage(), false);
        }
    }
    
    
    private void XMLAddChildren(DirectoryContent c, Element parent, Document doc) {
        GraphViewSpecification specs = view.getViewFor(c);
        if (specs == null)
            return;
        
        Element node = doc.createElement("node");
        parent.appendChild(node);
        
        node.setAttribute("filename", c.getFilename());
        node.setAttribute("text", specs.getText());
        node.setAttribute("borderwidth", String.valueOf(specs.getBorderWidth()));
        saveColor(specs.getBackgroundColor(), "backgroundcolor", node, doc);
        saveColor(specs.getTextColor() , "textcolor", node, doc);
        saveColor(specs.getBorderColor() , "bordercolor", node, doc);
        
        if (c instanceof Directory) {
            Directory dir = (Directory)c;
            if (!dir.hasContents()) {
                DBConnection.getInstance().populateDirectory(dir);
            }
            
            Iterator i = dir.getContents().iterator();
            while(i.hasNext()) {
                DirectoryContent child = (DirectoryContent)i.next();
                if (includeDirectoryContent(child)) {
                    
                    XMLAddChildren(child, node, doc);
                }
            }
        }
    }
    
    private void saveColor(Color c, String name, Element in, Document doc) {
        Element n = doc.createElement(name);
        n.setAttribute("red", String.valueOf(c.getRed()));
        n.setAttribute("green", String.valueOf(c.getGreen()));
        n.setAttribute("blue", String.valueOf(c.getBlue()));
        in.appendChild(n);
    }
    
    
    
    private boolean includeDirectoryContent(DirectoryContent c) {
        if (settings.getViewMode().containsFile(c))
            return true;
        
        if (!c.isDirectory())
            return false;
        
        Directory d = (Directory)c;
        Iterator i = d.getContents().iterator();
        while(i.hasNext())
            if (includeDirectoryContent((DirectoryContent)i.next()))
                return true;
        return false;
    }
    
    
    public void forceUpdate() {
        display.initalizeViewer();
        display.repaint();
    }
    
    public GraphViewMode getViewMode() {
        return view;
    }
    
    
}

/* ChangeLog:
 *   $Log: Graph.java,v $
 *   Revision 1.1  2004/12/07 17:53:23  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 */
