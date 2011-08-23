/*
 * $Id: TreeModelGenerator.java,v 1.2 2004/12/07 17:53:23 bdickie Exp $
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

package ca.uvic.cs.gold.bdickie.explorer;

import javax.swing.tree.*;
import java.util.Iterator;
import ca.uvic.cs.gold.bdickie.fs.*;
import ca.uvic.cs.gold.bdickie.db.DBConnection;

/** A class that handles generating the JTree's model.  Populates the directories
 *  as needed.
 *
 * @author  Blake Dickie
 */
public class TreeModelGenerator {
    private static boolean showFiles = true;
    
    /** Get the inital model.
     */
    public static TreeModel getDirectoryModel(Directory rootDir) {
        DefaultMutableTreeNode root = new DefaultMutableTreeNode(rootDir);
        loadDirectory(root);
        
        return new DefaultTreeModel(root);
    }
    
    public static TreeModel getDirectoryModel()
    {
        return getDirectoryModel(Directory.getRoot());
    }
    
    /** Populate the children of a node.
     */
    public static void loadDirectory(DefaultMutableTreeNode node) {
        Directory d = (Directory)node.getUserObject();
        
        node.removeAllChildren();
        
        if (!d.hasContents())
            DBConnection.getInstance().populateDirectory(d);
        
        addChildren(node);
    }
    
    /** Adds the children to the given node if it is a directory.
     */
    private static void addChildren(DefaultMutableTreeNode n) {
        Object contents = n.getUserObject();
        if (contents instanceof Directory) {
            Directory d = (Directory)contents;
            int numAdded = 0;
            if (d.hasContents()) {
                Iterator i = d.getContents().iterator();
                while(i.hasNext()) {
                    boolean add = true;
                    DirectoryContent content = (DirectoryContent)i.next();
                    
                    if (content instanceof File)
                    {
                        File f = (File)content;
                        if ((!showFiles) || (f.isDeleted() && !ExplorerOptions.showDeletedFiles()))
                            add = false;
                    }
                    
                    if (add) {
                        numAdded++;
                        DefaultMutableTreeNode newNode = new DefaultMutableTreeNode(content);
                        n.add(newNode);
                        addChildren(newNode);
                    }
                }
                
                if (numAdded == 0)
                {
                    // Add a node to empty directories so the Swing GUI will still 
                    // use the directory icons, etc.
                    DefaultMutableTreeNode empty = new DefaultMutableTreeNode("No Viewable Files...");
                    n.add(empty);
                }
            } else {
                DefaultMutableTreeNode todo = new DefaultMutableTreeNode("Loading Contents...");
                n.add(todo);
            }
        }
    }
    
    public static void setShowFiles(boolean show)
    {
        showFiles = show;
    }
}

/* ChangeLog:
 *   $Log: TreeModelGenerator.java,v $
 *   Revision 1.2  2004/12/07 17:53:23  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 *   Revision 1.1  2004/11/01 02:24:20  bdickie
 *   Done Repository Browser.
 *
 */

