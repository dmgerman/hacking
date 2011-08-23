/*
 * $Id: EvolutionConnection.java,v 1.2 2004/12/07 17:53:22 bdickie Exp $
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

package ca.uvic.cs.gold.bdickie.db.evolution;

import java.util.*;
import java.sql.*;
import java.text.SimpleDateFormat;


import ca.uvic.cs.gold.bdickie.fs.*;
import ca.uvic.cs.gold.bdickie.db.*;
import ca.uvic.cs.gold.bdickie.*;

/** DBConnection for the newevolution backend.
 *
 * @author  Blake Dickie
 */
public class EvolutionConnection extends JDBCConnection {
    private static SimpleDateFormat dateForamtter = new SimpleDateFormat("yyyy-MM-dd");
    
    
    /** Creates a new instance of EvolutionConnection */
    public EvolutionConnection() {
        init("org.postgresql.Driver", "jdbc:postgresql://" + EvolutionOptions.getHostname() + "/" +
        EvolutionOptions.getDatabase(), EvolutionOptions.getUsername(), EvolutionOptions.getPassword());
    }
    
    public synchronized void populateDirectory(Directory d) {
        if (d.hasContents())
            d.clearContents();
        
        try {
            // Get Files
            
            ResultSet rs = runQuery("Select basename, extension, latestversion, inattic From files " +
            " Where directory = '" + convertToCVSPath(d.getPath()) + "'");
            
            while(rs.next()) {
                File f = new File(rs.getString("basename").trim() + rs.getString("extension").trim(),
                d, rs.getString("latestversion").trim(), rs.getString("inattic").equals("1"));
                d.addContents(f);
            }
            rs.close();
            
            
            // Get Directories
            
            String dirPrefix = convertToDirRegExp(d.getPath());
            String rootPath  = getRootPath(d.getPath());
            
            rs = runQuery("select distinct trim(substring(directory from '" + dirPrefix + "')) as d from files where directory like '"+ rootPath + "%'");
            while(rs.next()) {
                String dir = rs.getString("d");
                if (dir != null) {
                    //dir = dir.trim();
                    
                    if (!dir.equals("./")) {
                        dir = dir.substring(rootPath.length(), dir.length() - 1);
                        
                        Directory newDir = new Directory(dir, d);
                        d.addContents(newDir);
                    }
                }
            }
            rs.close();
           
        } catch (SQLException e) {
            ErrorLog.reportError("Error getting directory contents", e.getMessage(), true);
        }
    }
    
    public synchronized RevisionDetails getRevision(File f, String revision) {
        RevisionDetails result = null;
        try {
            String filename = convertToCVSFilename(f.getPath());
            
            ResultSet rs = runQuery("Select F.newfile, R.state, R.daterev, R.timerev, M.author from " +
            "((revisions as R inner join filerevisions as F on " +
            "(R.revisionid = F.revisionid AND R.filename = F.filename)) " +
            "Inner Join mrsfiles as MF On (R.revisionid = MF.revisionid AND R.filename = MF.filename)) " +
            "Inner Join mrs2 as M On (MF.mrid = M.mrid) " +
            "Where R.filename = '" + filename + "' " +
            "And R.revisionid = '" + revision + "'");
            
            if (rs.next()) {
                result = new RevisionDetails(f, revision, rs.getString("newfile"), rs.getString("daterev") + " " + rs.getString("timerev"),
                rs.getString("author").trim(), rs.getString("state").trim().equals("dead"));
            }
            rs.close();
            return result;
        } catch (SQLException e) {
            ErrorLog.reportError("Error getting revisions of file.", e.getMessage(), true);
        }
        return null;
    }
    
    
    public synchronized List getFileRevisions(File f) {
        LinkedList result = new LinkedList();
        try {
            String filename = convertToCVSFilename(f.getPath());
            
            ResultSet rs = runQuery("Select F.revisionid from " +
            "revisions as R inner join filerevisions as F on " +
            "(R.revisionid = F.revisionid AND R.filename = F.filename) " +
            "Where F.filename = '" + filename + "' AND R.state <> 'dead' " +
            "Order By R.daterev DESC, R.timerev DESC");
            while(rs.next())
                result.add(rs.getString("revisionid").trim());
            rs.close();
            return result;
        } catch (SQLException e) {
            ErrorLog.reportError("Error getting revisions of file.", e.getMessage(), true);
        }
        return null;
    }
    
    private static String convertToCVSPath(String path) {
        if (path.equals(""))
            return "./";
        else
            return path.substring(1) + "/";
    }
    
    private static String convertToDirRegExp(String path) {
        String rootPath = getRootPath(path);
        
        return "^" + rootPath + "[^/]*/ *$";
    }
    
    private static String getRootPath(String path) {
        String rootPath;
        if (path.equals(""))
            rootPath = "";
        else
            rootPath = path.substring(1) + "/";
        return rootPath;
    }
    
    private static String convertToCVSFilename(String path) {
        return path.substring(1);
    }
    
    
    public String getDifference(File f, String revision) {
        String result = null;
        try {
            String filename = convertToCVSFilename(f.getPath());
            
            ResultSet rs = runQuery("Select diff from " +
            "revisiondiffs Where filename = '" + filename + "' and revisionid='" + revision + "'");
            if (rs.next())
                result = rs.getString(1);
            rs.close();
            return result;
        } catch (SQLException e) {
            ErrorLog.reportError("Error getting revisions of file.", e.getMessage(), true);
        }
        return null;
    }
    
    public Vector getRevisions(File f) {
        Vector result = new Vector();
        
        try {
            String filename = convertToCVSFilename(f.getPath());
            
            ResultSet rs = runQuery("Select R.revisionid, R.state, R.daterev, R.timerev, M.mrid, F.state as FileState from " +
            "(revisions as R inner join mrsfiles as M on " +
            "(R.revisionid = M.revisionid AND R.filename = M.filename)) left join filerevisions as F on " +
            "(R.revisionid = F.revisionid AND F.filename = M.filename)  " +
            "Where R.filename = '" + filename + "' Order By R.daterev DESC, R.timerev DESC");
            while(rs.next()) {
                Vector currentRow = new Vector(6);
                currentRow.add(rs.getString("revisionid").trim());
                
                boolean deletedRow = rs.getString("state").trim().equals("dead");
                
                if (deletedRow)
                    currentRow.add("Delete");
                else
                    currentRow.add("Commit");
                
                currentRow.add(rs.getString("daterev").trim());
                currentRow.add(rs.getString("timerev").trim());
                currentRow.add(new Boolean(!deletedRow && rs.getString("FileState") != null));
                currentRow.add(rs.getString("mrid").trim());
                result.add(currentRow);
                
            }
            rs.close();
            return result;
        } catch (SQLException e) {
            ErrorLog.reportError("Error getting revisions of file.", e.getMessage(), true);
        }
        
        return result;
    }
    
    
    public Vector getRevisions(File f, java.util.Date start, java.util.Date end) {
        Vector result = new Vector();
        
        try {
            String filename = convertToCVSFilename(f.getPath());
            
            ResultSet rs = runQuery("Select R.revisionid, R.state, mrs2.daterev, mrs2.timerev, M.mrid, F.state as FileState from " +
            "((revisions as R inner join mrsfiles as M on " +
            "(R.revisionid = M.revisionid AND R.filename = M.filename)) left join filerevisions as F on " +
            "(R.revisionid = F.revisionid AND F.filename = M.filename))  Inner Join " +
            "mrs2 on (mrs2.mrid = M.mrid)" +
            "Where R.filename = '" + filename + "' " +
            "AND mrs2.daterev >= '" + convertDate(start) + "' AND " +
            "mrs2.daterev <= '" + convertDate(end) + "' " +
            "Order By mrs2.daterev DESC, mrs2.timerev DESC");
            while(rs.next()) {
                Vector currentRow = new Vector(6);
                currentRow.add(rs.getString("revisionid").trim());
                
                boolean deletedRow = rs.getString("state").trim().equals("dead");
                
                if (deletedRow)
                    currentRow.add("Delete");
                else
                    currentRow.add("Commit");
                
                currentRow.add(rs.getString("daterev").trim());
                currentRow.add(rs.getString("timerev").trim());
                currentRow.add(rs.getString("mrid").trim());
                result.add(currentRow);
                
            }
            rs.close();
            return result;
        } catch (SQLException e) {
            ErrorLog.reportError("Error getting revisions of file.", e.getMessage(), true);
        }
        
        return result;
    }
    
    public Vector getRevisionsForMRS(String mrid, String path) {
        Vector result = new Vector();
        path = path.substring(1);
        try {
            
            
            ResultSet rs = runQuery("Select R.revisionid, R.state, R.daterev, R.timerev, R.filename, F.state as FileState from " +
            "(revisions as R inner join mrsfiles as M on " +
            "(R.revisionid = M.revisionid AND R.filename = M.filename)) left join filerevisions as F on " +
            "(R.revisionid = F.revisionid AND F.filename = M.filename)  " +
            "Where M.mrid = '" + mrid + "' " +
            "AND position('" + path + "' in R.filename) = 1 " +
            "Order By R.filename, R.daterev DESC, R.timerev DESC");
            while(rs.next()) {
                Vector currentRow = new Vector(6);
                
                currentRow.add("/" + rs.getString("filename").trim());
                
                currentRow.add(rs.getString("revisionid").trim());
                
                boolean deletedRow = rs.getString("state").trim().equals("dead");
                
                if (deletedRow)
                    currentRow.add("Delete");
                else
                    currentRow.add("Commit");
                
                currentRow.add(rs.getString("daterev").trim());
                currentRow.add(rs.getString("timerev").trim());
                currentRow.add(new Boolean(!deletedRow && rs.getString("FileState") != null));
                
                result.add(currentRow);
                
            }
            rs.close();
            return result;
        } catch (SQLException e) {
            ErrorLog.reportError("Error getting revisions in mrs.", e.getMessage(), true);
        }
        
        return result;
    }
    
    
    public MRSInfo getMRSInfo(String mrid) {
        MRSInfo result = null;
        try {
            
            ResultSet rs = runQuery("Select log, daterev, timerev, author from " +
            "mrs2 Where mrid = '" + mrid + "'");
            
            if (rs.next()) {
                result = new MRSInfo(rs.getString("author").trim(), rs.getString("daterev"), rs.getString("timerev"),
                rs.getString("log").trim().replaceAll("NEWLINE", "\n"));
            }
            rs.close();
            return result;
        } catch (SQLException e) {
            ErrorLog.reportError("Error getting revisions of file.", e.getMessage(), true);
        }
        return null;
    }
    
    public java.util.Date[] getDateRange() {
        java.util.Date[] result = new java.util.Date[2];
        try {
            
            ResultSet rs = runQuery("Select min(daterev), max(daterev) from mrs2");
            
            if (rs.next()) {
                result[0] = rs.getDate(1);
                result[1] = rs.getDate(2);
            }
            rs.close();
            return result;
        } catch (SQLException e) {
            ErrorLog.reportError("Error getting revisions of file.", e.getMessage(), true);
        }
        return null;
    }
    
    
    public Map getFilesUpdatedOnRange(java.util.Date start, java.util.Date stop, String path, String regexp) {
        path = path.substring(1);
        Map result = new HashMap();
        try {
            
            StringBuffer query = new StringBuffer();
            
            query.append("Select trim(r.filename), count(*) from ");
            query.append("(revisions as r Inner Join ");
            query.append("mrsfiles as mf On (r.filename = mf.filename and r.revisionid = mf.revisionid)) Inner Join ");
            query.append("mrs2 as m On (m.mrid = mf.mrid) ");
            query.append("Where r.filename LIKE '");
            query.append(path);
            query.append("%' AND ");
            
            query.append("m.daterev <='");
            query.append(convertDate(stop));
            query.append("' AND m.daterev >='");
            query.append(convertDate(start));
            query.append("' ");
            
            
            if (!regexp.equals(""))
            {
                query.append("AND trim(r.filename) ~ '");
                query.append(escape(regexp));
                query.append("' ");
            }
            
            query.append("Group By r.filename");
            
            ResultSet rs = runQuery(query.toString());
            
            while (rs.next())
                result.put("/" + rs.getString(1).trim(), new Integer(rs.getInt(2)));
            rs.close();
            
            
            return result;
        } catch (SQLException e) {
            ErrorLog.reportError("Error getting file updated on date range.", e.getMessage(), true);
        }
        return null;
        
    }
    
    public Map getFilesThatExistAt(java.util.Date date, String path, String regexp) {
        path = path.substring(1);
        Map result = new HashMap();
        try {
            
            StringBuffer query = new StringBuffer();
            
            query.append("Select trim(r.filename), count(*) from ");
            query.append("(revisions as r Inner Join ");
            query.append("mrsfiles as mf On (r.filename = mf.filename and r.revisionid = mf.revisionid)) Inner Join ");
            query.append("mrs2 as m On (m.mrid = mf.mrid) ");
            query.append("Where r.filename LIKE '");
            query.append(path);
            query.append("%' AND ");
            
            query.append("m.daterev <'");
            query.append(convertDate(date));
            query.append("' ");
            
            
            if (!regexp.equals(""))
            {
                query.append("AND trim(r.filename) ~ '");
                query.append(escape(regexp));
                query.append("' ");
            }
            
            query.append("Group By r.filename");
            
            ResultSet rs = runQuery(query.toString());
            
            while (rs.next())
                result.put("/" + rs.getString(1).trim(), new Integer(rs.getInt(2)));
            rs.close();
            
            
            return result;
        } catch (SQLException e) {
            ErrorLog.reportError("Error getting file before on date.", e.getMessage(), true);
        }
        return null;
    }
    
    public Vector getAuthorsOfFiles(java.util.Date start, java.util.Date stop, String path, String regexp)
    {
        path = path.substring(1);
        Vector result = new Vector();
        try {
            
            StringBuffer query = new StringBuffer();
            
            query.append("Select trim(r.filename), trim(m.author), count(*) as c from ");
            query.append("(revisions as r Inner Join ");
            query.append("mrsfiles as mf On (r.filename = mf.filename and r.revisionid = mf.revisionid)) Inner Join ");
            query.append("mrs2 as m On (m.mrid = mf.mrid) ");
            query.append("Where r.filename LIKE '");
            query.append(path);
            query.append("%' AND ");
            
            query.append("m.daterev <='");
            query.append(convertDate(stop));
            query.append("' AND m.daterev >='");
            query.append(convertDate(start));
            query.append("' ");
            
            
            if (!regexp.equals(""))
            {
                query.append("AND trim(r.filename) ~ '");
                query.append(escape(regexp));
                query.append("' ");
            }
            
            query.append("Group By r.filename, m.author ");
            query.append("Order By c DESC");
            
            ResultSet rs = runQuery(query.toString());
            
            while (rs.next())
            {
                Vector t = new Vector(3);
                t.add(0, "/" + rs.getString(1));
                t.add(1, rs.getString(2));
                t.add(2, new Integer(rs.getInt(3)));
                result.add(t);
            }
            rs.close();
            
            
            return result;
        } catch (SQLException e) {
            ErrorLog.reportError("Error getting authors on date range.", e.getMessage(), true);
        }
        return null;
    }
    
    private String convertDate(java.util.Date d) {
        return dateForamtter.format(d);
    }
    
}

/* ChangeLog:
 *   $Log: EvolutionConnection.java,v $
 *   Revision 1.2  2004/12/07 17:53:22  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 *   Revision 1.1  2004/11/01 00:22:16  bdickie
 *   'newevolution' data backend.
 *
 */

