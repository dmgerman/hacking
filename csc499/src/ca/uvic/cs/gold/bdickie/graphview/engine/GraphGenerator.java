/*
 * $Id: GraphGenerator.java,v 1.1 2004/12/07 17:53:23 bdickie Exp $
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
import java.awt.*;


import ca.uvic.cs.gold.bdickie.db.DBConnection;
import ca.uvic.cs.gold.bdickie.fs.*;
import ca.uvic.cs.gold.bdickie.graphview.framework.*;


/** Populates the RadialLayoutTree with the files and directories.
 *
 * @author  Blake Dickie
 */
public class GraphGenerator {
    private Set includedFiles;
    private Directory root;
    private RadialLayoutTree tree;
    private GraphSettings settings;
    
    
    /** Creates a new instance of GraphGenerator */
    public GraphGenerator(GraphSettings settings) {
        this.settings = settings;
        includedFiles = new TreeSet();
        this.root = settings.getRoot();
        tree = new RadialLayoutTree(250, root);
    }
    
    public RadialLayoutTree getGraph() {
        
        
        return tree;
    }
    
    public RadialLayoutTree generateGraph() {
        addChildren(root);
        return getGraph();
    }
    
    private void addChildren(DirectoryContent c) {
        if (c instanceof Directory) {
            Directory dir = (Directory)c;
            if (!dir.hasContents()) {
                DBConnection.getInstance().populateDirectory(dir);
            }
            Iterator i = dir.getContents().iterator();
            while(i.hasNext()) {
                DirectoryContent child = (DirectoryContent)i.next();
                if (includeDirectoryContent(child)) {
                    tree.addNode(child);
                    addChildren(child);
                }
            }
        }
    }
    
    private boolean includeDirectoryContent(DirectoryContent c)
    {
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
}

/* ChangeLog:
 *   $Log: GraphGenerator.java,v $
 *   Revision 1.1  2004/12/07 17:53:23  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 */
