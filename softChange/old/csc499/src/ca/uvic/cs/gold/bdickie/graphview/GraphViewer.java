/*
 * $Id: GraphViewer.java,v 1.1 2004/12/07 17:53:23 bdickie Exp $
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

import ca.uvic.cs.gold.bdickie.db.*;
import ca.uvic.cs.gold.bdickie.*;
import ca.uvic.cs.gold.bdickie.fs.Directory;

/** The main class of the Repository Graphers program.
 *
 * @author  Blake Dickie
 */
public class GraphViewer {
    private static GraphFrame myFrame;
    
    /** Creates a new instance of GraphViewer */
    public GraphViewer() {
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        GraphViewOptions.loadSettings();
        
        DBOption.getInstance().createConnection();
        
        myFrame = new GraphFrame();
        myFrame.show();
    }
}

/* ChangeLog
 *   $Log: GraphViewer.java,v $
 *   Revision 1.1  2004/12/07 17:53:23  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 */