/*
 * $Id: JDBCConnection.java,v 1.2 2004/12/07 17:53:22 bdickie Exp $
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
import java.sql.*;

/** An extended version of DBConnection that is designed to work with JDBC
 *  databases.  Adds functions that handle a lot of the unglier JDBC functions.
 *
 * @author  Blake Dickie
 */
public abstract class JDBCConnection extends DBConnection {
    private boolean connected = false;
    private Connection conn;
    
    /** Creates a new instance of JDBCConnection */
    public JDBCConnection() {
        
        
    }
    
    /** Initializes a new connection to the JDBC database and sets it to be the
     *  current database connection.
     *
     *  @param driverName The class name of the JDBC driver to use.
     *  @param connectionString The JDBC connection string to use.
     *  @param username The username to connect with.
     *  @param password The password to connect with.
     */
    public synchronized boolean init(String driverName, String connectionString, String username, String password) {
        try {
            Class.forName(driverName);
            
            conn = DriverManager.getConnection(connectionString, username, password);
            connected = true;
            setInstance(this);
        } catch (ClassNotFoundException e) {
            ErrorLog.reportError("Unable to find database driver",
            e.getMessage(), true);
        } catch (SQLException e) {
            ErrorLog.reportError("Unable to connect to database", e.getMessage(), true);
        }
        
        return true;
    }
    
    /** Disconnects from the server.
     */
    public synchronized void disconnect() {
        if (connected()) {
            try {
                conn.close();
                connected = false;
                setInstance(null);
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
    
    /** Runs a query on the JDBC database and returns the result.
     *  @param query The query to run.
     */
    public ResultSet runQuery(String query) {
        System.out.println("Query: " + query);
        try {
            Statement stmt = conn.createStatement();
            return stmt.executeQuery(query);
            
        } catch (SQLException e) {
            ErrorLog.reportError("Error Running Query", e.getMessage(), true);
            return null;
        }
    }
    
    /** Checks if the database is currently connected.
     */
    public synchronized boolean connected() {
        return connected;
    }
    
    /** Preforms some SQL string escaping on the input.
     */
    protected String escape(String str)
    {
        StringBuffer result = new StringBuffer(str.length() * 2);
        for(int i = 0; i < str.length(); i++)
        {
            char c = str.charAt(i);
            switch (c)
            {
                case '\\':
                    result.append("\\\\");
                    break;
                case '\'':
                    result.append("\\'");
                    break;
                default:
                    result.append(c);
            }
        }
        return result.toString();
    }
}

/* ChangeLog:
 *   $Log: JDBCConnection.java,v $
 *   Revision 1.2  2004/12/07 17:53:22  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 *   Revision 1.1  2004/11/01 00:43:33  bdickie
 *   Database backend for file explorer done.
 *
 */

