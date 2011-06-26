/*
 * $Id: FileExplorer.java,v 1.2 2004/12/07 17:53:22 bdickie Exp $
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

import ca.uvic.cs.gold.bdickie.db.*;
import ca.uvic.cs.gold.bdickie.*;
import ca.uvic.cs.gold.bdickie.fs.Directory;

/** The main class of the Repository Browser program.
 *
 * @author  Blake Dickie
 */
public class FileExplorer {
    private static ExplorerFrame myFrame;
    
    /** Creates a new instance of FileExplorer */
    public FileExplorer() {
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        ExplorerOptions.loadSettings();
        
        DBOption.getInstance().createConnection();
        
        myFrame = new ExplorerFrame();
        myFrame.show();
    }
    
    /** Resets the program, loading any new configuraitons.
     */
    public static void reset()
    {
        myFrame.hide();
        Directory.getRoot().clearContents();
        DBConnection.getInstance().disconnect();
        
        main(new String[0]);
    }
}

/* ChangeLog
 *   $Log: FileExplorer.java,v $
 *   Revision 1.2  2004/12/07 17:53:22  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 *   Revision 1.1  2004/11/01 02:24:20  bdickie
 *   Done Repository Browser.
 *
 */