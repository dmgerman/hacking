/*
 * $Id: FileSystemRenderer.java,v 1.2 2004/12/07 17:53:22 bdickie Exp $
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

import javax.swing.*;
import javax.swing.tree.*;
import java.awt.Color;

import ca.uvic.cs.gold.bdickie.ErrorLog;
import ca.uvic.cs.gold.bdickie.fs.*;

/** A specialized Cell Renderer that displays the repository correctly.  If
 *  a non-initalized directory is extended it will initalize it.
 *
 * @author  Blake Dickie
 */
public class FileSystemRenderer extends DefaultTreeCellRenderer {
    private Color normal;
    private Color deleted;
    
    /** Creates a new instance of FileSystemRenderer */
    public FileSystemRenderer() {
        super();
        normal = getForeground();
        deleted = Color.GRAY;
    }
    
    public java.awt.Component getTreeCellRendererComponent(JTree tree, Object n, boolean isSelected, boolean expanded, boolean leaf, int row, boolean hasFocus) {
        super.getTreeCellRendererComponent(tree, n, isSelected, expanded, leaf, row, hasFocus);
        
        DefaultMutableTreeNode node = (DefaultMutableTreeNode)n;
        Object value = node.getUserObject();
                
        if (value instanceof File)
        {
            File f = (File)value;
            setText(f.getFilename());
            if (f.isDeleted())
                setForeground(deleted);
        } else if (value instanceof Directory) {
            Directory d = (Directory)value;
            if (d.isRoot())
                setText("/");
            else
                setText(d.getFilename());
            if ((!d.hasContents()) && expanded)
                TreeModelGenerator.loadDirectory(node);
        }
        
        return this;
    }
    
}


/* ChangeLog:
 *   $Log: FileSystemRenderer.java,v $
 *   Revision 1.2  2004/12/07 17:53:22  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 *   Revision 1.1  2004/11/01 02:24:20  bdickie
 *   Done Repository Browser.
 *
 */