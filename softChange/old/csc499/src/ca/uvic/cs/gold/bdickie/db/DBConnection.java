/*
 * $Id: DBConnection.java,v 1.3 2004/12/07 17:53:22 bdickie Exp $
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

package ca.uvic.cs.gold.bdickie.db;

import ca.uvic.cs.gold.bdickie.*;
import ca.uvic.cs.gold.bdickie.fs.*;


import java.util.*;
import java.sql.*;

/** This is the heart of a database backend for the repository viewing programs.
 *  All data backends must implement all of the abstract methods in this class
 *  and be able to preform them in a reasonable time.
 *
 *  The is only ever one active DBConnection with can be obtained through the
 *  getInstance() method.
 *
 * @author  Blake Dickie
 */
public abstract class DBConnection {
    
    private static DBConnection instance = null;
    
    /** Creates a new instance of DBConnection */
    public DBConnection() {
        
    }
    
    /** Gets the currently active DBConnection.
     */
    public static synchronized DBConnection getInstance() {
        return instance;
    }
    
    /** Checks if there is a currently active DBConnection.
     */
    public static synchronized boolean exists() {
        return instance != null;
    }
    
    /** Sets the currently active DBConnection.
     */
    protected static synchronized void setInstance(DBConnection i) {
        instance = i;
    }
    
    
    /** If the current directory is not populated with its next level of
     *  content populates it.  Only the direct children have to be fully
     *  loaded (ie. sub-directories' content doesn't need to be loaded).
     *
     *  @param d The directory to populate.
     */
    public abstract void populateDirectory(Directory d);
    
    /** Gets the given revision from the repository if possible.
     *  @param f The file to recieve.
     *  @param revision The revision of the file to get.
     *  @return The REvisionDetails for the revision or null if unable to 
     *          obtain the information.
     */
    public abstract RevisionDetails getRevision(File f, String revision);
    
    /** Gets a list of the revision ids for a file that have the revision
     *  contents avaliable.
     *  @param f The file to get the revisions of.
     *  @return A list of the revision strings in sorted order with the newest
     *          revision first.
     */
    public abstract List getFileRevisions(File f);
    
    /** Gets the "diff" for the given file revision.  This result should be
     *  the result of the Unix diff command on the given revision and the one
     *  before it.
     *
     *  @param file The file to get the revisions of.
     *  @param revision The revision to get the diff of.
     */ 
    public abstract String getDifference(File file, String revision);  
    
    /** Gets a Vector of Vectors containing information about the revisions for
     *  the given file.  Each revision for the file should have a vector and each
     *  vector should contain the following in order:
     *
     *  -The revision (String)
     *  -The state of the file ("Delete" or "Commit")
     *  -The date of the revision (String)
     *  -The time of the revision (String)
     *  -Weither the content of the revision is avaliable (Boolean)
     *  -The mrid of the mrs of the revision (String).
     *
     *  @param file The file to get the revisions of.
     */
    public abstract Vector getRevisions(File file);
    
    /** Gets a Vector of Vectors containing information about the revisions for
     *  the given file.  Each revision for the file should have a vector and each
     *  vector should contain the following in order:
     *
     *  -The revision (String)
     *  -The state of the file ("Delete" or "Commit")
     *  -The date of the revision (String)
     *  -The time of the revision (String)
     *  -Weither the content of the revision is avaliable (Boolean)
     *  -The mrid of the mrs of the revision (String).
     *
     *  @param file The file to get the revisions of.
     */
    public abstract Vector getRevisions(File file, java.util.Date startDate, java.util.Date endDate);
    
    /** Gets a Vector of Vectors containing information about the revisions for
     *  the given MR.  Each revision for the MR should have a vector and each
     *  vector should contain the following in order:
     *
     *  -The full path of the file (String)
     *  -The revision (String)
     *  -The state of the file ("Delete" or "Commit")
     *  -The date of the revision (String)
     *  -The time of the revision (String)
     *  -Weither the content of the revision is avaliable (Boolean)
     *
     *  @param mrid The id of the MR to get the revisions in.
     *  @param path The path that every file should be under.
     */
    public abstract Vector getRevisionsForMRS(String mrid, String path);
    
    /** Gets a Vector of Vectors containing information about the revisions for
     *  the given MR.  Each revision for the MR should have a vector and each
     *  vector should contain the following in order:
     *
     *  -The full path of the file (String)
     *  -The revision (String)
     *  -The state of the file ("Delete" or "Commit")
     *  -The date of the revision (String)
     *  -The time of the revision (String)
     *  -Weither the content of the revision is avaliable (Boolean)
     *
     *  @param mrid The id of the MR to get the revisions in.
     */
    public Vector getRevisionsForMRS(String mrid)
    {
        return getRevisionsForMRS(mrid, "/");
    }
    
    
    
    /** Gets the basicly information about a MRS.
     *  @param mrid The id of the MR to get the revision of.
     */
    public abstract MRSInfo getMRSInfo(String mrid);
    
    
    /** Gets an array of Dates where with the following format:
     *    0 Index = Earliest Date of Revisions
     *    1 Index - Last Date of Revision
     */
    public abstract java.util.Date[] getDateRange();
    
    /** Returns a Mapping of the files that exist at the start of the given
     *  date, pointing to an Integer of the number of revisions that they have 
     * had.
     */
    public abstract Map getFilesThatExistAt(java.util.Date date, String path, String regexp);
    
    /** Returns a Mapping of the files that are revisised over the given date
     *  range, pointing to an Integer of the number of revisions that they had.
     */
    public abstract Map getFilesUpdatedOnRange(java.util.Date start, java.util.Date stop, String path, String regexp);
    
    /** Returns a vector of vectors where:
     *   The sub-vectors contain:
     *      0 - A filepath
     *      1 - An author name
     *      2 - An Integer of the number of times the author editted the file.
     *   The sub-vectors should be ordered so the author who editted the file the most
     *   comes first.
     */
    public abstract Vector getAuthorsOfFiles(java.util.Date start, java.util.Date stop, String path, String regexp);
    
    
    /** When called the implementation should cleanup all connections and prepare
     *  to shutdown.
     */
    public abstract void disconnect();
}

/* ChangeLog:
 *   $Log: DBConnection.java,v $
 *   Revision 1.3  2004/12/07 17:53:22  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 *   Revision 1.2  2004/11/01 00:45:23  bdickie
 *   Accedentally commented out one of the functions.
 *
 *   Revision 1.1  2004/11/01 00:43:33  bdickie
 *   Database backend for file explorer done.
 *
 */
