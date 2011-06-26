/*
 * $Id: EvolutionOptions.java,v 1.3 2004/12/07 17:53:22 bdickie Exp $
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

/** Class that contains the settings for the Evolution database connection module.
 *
 * @author  Blake Dickie
 */
public class EvolutionOptions {
    public static final String DEFAULT_HOSTNAME = "silver.cs.uvic.ca";
    public static final String DEFAULT_USERNAME = "";
    public static final String DEFAULT_PASSWORD = "";
    public static final String DEFAULT_DATABASE = "newevolution";
    
    private static String hostname = DEFAULT_HOSTNAME;
    private static String username = DEFAULT_USERNAME;
    private static String password = DEFAULT_PASSWORD;
    private static String database = DEFAULT_DATABASE;
    
    
    public static void setDefaults()
    {
        setHostname(DEFAULT_HOSTNAME);
        setHostname(DEFAULT_USERNAME);
        setHostname(DEFAULT_PASSWORD);
        setDatabase(DEFAULT_DATABASE);
    }
    
    /**
     * Getter for property password.
     * @return Value of property password.
     */
    public static java.lang.String getPassword() {
        return password;
    }
    
    /**
     * Setter for property password.
     * @param password New value of property password.
     */
    public static void setPassword(java.lang.String pass) {
        password = pass;
    }
    
    /**
     * Getter for property username.
     * @return Value of property username.
     */
    public static java.lang.String getUsername() {
        return username;
    }
    
    /**
     * Setter for property username.
     * @param username New value of property username.
     */
    public static void setUsername(java.lang.String user) {
        username = user;
    }
    
    /**
     * Getter for property hostname.
     * @return Value of property hostname.
     */
    public static java.lang.String getHostname() {
        return hostname;
    }
    
    /**
     * Setter for property hostname.
     * @param hostname New value of property hostname.
     */
    public static void setHostname(java.lang.String host) {
        hostname = host;
    }
    
    public static String getDatabase()
    {        
        return database;
    }
    
    public static void setDatabase(String db)
    {
        database = db;
    }
    
}

/* ChangeLog:
 *   $Log: EvolutionOptions.java,v $
 *   Revision 1.3  2004/12/07 17:53:22  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 *   Revision 1.2  2004/11/14 22:45:15  bdickie
 *   Change default host to silver due to gold's replacement.
 *
 *   Revision 1.1  2004/11/01 00:22:16  bdickie
 *   'newevolution' data backend.
 *
 */
