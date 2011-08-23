/*
 * $Id: ErrorLog.java,v 1.2 2004/12/07 17:53:22 bdickie Exp $
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

package ca.uvic.cs.gold.bdickie;

import ca.uvic.cs.gold.bdickie.db.DBConnection;
import javax.swing.JOptionPane;

/** Hanlder class that handlers reporting errors to the user and shutting down
 *  the program.
 *
 * @author  Blake Dickie
 */
public class ErrorLog {
    private static boolean inError = false;
    
    /** Display an error to the user.
     *  @param short_err A short description of the problem.
     *  @param desc The full description of the error.
     *  @param fatal Should the program exit as a result of the error.
     */
    public static void reportError(String short_err, String desc, boolean fatal) {
        if (!inError) {
            inError = true;
            
            System.err.println(short_err + ":\n\t" + desc);
            JOptionPane.showMessageDialog(null, short_err + ":\n\t" + desc);
            if (fatal)
                exit(-1);
            inError = false;
        }
    }
    
    /** Exits the program with the given exit code.  Shuts down the database if needed.
     */
    public static void exit(int status) {
        if (DBConnection.exists())
            DBConnection.getInstance().disconnect();
        //System.out.println("Exiting with code " + status);
        System.exit(status);
    }
}


/* ChangeLog:
 *   $Log: ErrorLog.java,v $
 *   Revision 1.2  2004/12/07 17:53:22  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 *   Revision 1.1  2004/10/31 23:43:51  bdickie
 *   Done prelimiary version of repository explorer.
 *
 */
