/*
 * $Id: GraphsTabbedPane.java,v 1.1 2004/12/07 17:53:23 bdickie Exp $
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

package ca.uvic.cs.gold.bdickie.graphview;


import com.infosys.closeandmaxtabbedpane.*;
import java.util.*;
import java.awt.*;

import ca.uvic.cs.gold.bdickie.graphview.framework.*;

/** A tabbed panel that displays Graphs (or more accuratly GraphPanels).
 *
 * @author  Blake Dickie
 */
public class GraphsTabbedPane extends CloseAndMaxTabbedPane {
    private Map files = new HashMap();
    private Map mrses = new HashMap();
    private Frame parent;
    
    /** Creates a new instance of FilesTabbedPane */
    public GraphsTabbedPane(Frame parent) {
        super(true);
        this.parent = parent;
        setMaxIcon(false);
    }
    
    
    /** Open an graph.
     */
    public void open(Graph graph) {
        
        GraphPanel pane = new GraphPanel(graph, parent);
        addTab(graph.getSettings().getRoot().getPath(), pane);
        setSelectedComponent(pane);
    }
    
}

/* ChangeLog
 *   $Log: GraphsTabbedPane.java,v $
 *   Revision 1.1  2004/12/07 17:53:23  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 */