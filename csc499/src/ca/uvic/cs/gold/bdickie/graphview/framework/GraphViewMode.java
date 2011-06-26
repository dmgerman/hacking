/*
 * $Id: GraphViewMode.java,v 1.1 2004/12/07 17:53:23 bdickie Exp $
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

import ca.uvic.cs.gold.bdickie.fs.*;
import java.awt.event.MouseEvent;
import ca.uvic.cs.gold.bdickie.graphview.*;

/** The interface that display plugins for the graph should implement.
 *
 * @author  Blake Dickie
 */
public interface GraphViewMode {
    /** Called before a node is rendered.  Returns the display options for the
     *  node.  If null is returned the node is not rendered.
     *  
     *  @param node The file or directory about to be rendered.
     *  @return The properties to display with or if null do not
     *          display the node.
     */
    public GraphViewSpecification getViewFor(DirectoryContent node);
    
    
    /** Checks if the given file will be shown on the graph at some points in
     *  time.  If it doesn't return true here, space may not be allocated for
     *  in the graph.
     */
    public boolean containsFile(DirectoryContent node);
    
    /** Called when a view mode is added to a graph.  Useful if the
     *  view wants to set some properties of the graph (ie. what
     *  mouse events to report).  This is also when a view mode should
     *  do any queries to the database before hand.
     *
     *  @param graph The graph that the view was added to.
     */
    public void addedToGraph(Graph graph);
        
    /** Called when a mouse is clicked over a node.  Only is called if
     *  specified on the graph.
     */
    public void mousePressed(DirectoryContent node, MouseEvent evt);
    
    /** Creates and returns a Java control panel that can be placed at the
     *  bottom of the window to control options specific to this view.
     */
    public java.awt.Component getControlPane();
    
    /** Returns a short string describing the view provided by the plugin.
     */
    public String getDescription();
}

/* ChangeLog:
 *   $Log: GraphViewMode.java,v $
 *   Revision 1.1  2004/12/07 17:53:23  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 */
