/*
 * $Id: DBOption.java,v 1.2 2004/12/07 17:53:22 bdickie Exp $
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

import org.w3c.dom.*;

/** Implementations of database backends for these programs must implement this
 *  class and add the full classname of the implementation to the DBs.txt file.
 *
 * @author  Blake Dickie
 */
public abstract class DBOption {
    private static DBOption instance = null;
    
    /** When called the db module must create a DBConnection and set it as the 
     *  currently active DBConnection.
     */
    public abstract void createConnection();
    
    /** When called the db modules should return a panel that can be placed in a
     *  configuration gui to setup the module.
     */
    public abstract DBConfigPanel getConfigPanel();
    
    /** Saves any persistent settings for the db modules to the give XML element.
     * Any changes must be children of the element and shouldn't for example edit
     * the attributes or name of the element.
     */
    public abstract void saveOptions(Document document, Element tag);
    
    /**
     * Loads any persistent settings for the db modules from the given XML element.
     *  The element provided should be the same as the one saved.
     */
    public abstract void loadOptions(Element tag);
    
    /** Returns a string describing the db module for describing it to the user.
     */
    public abstract String getDescription();
    
    /** Gets the currently active DBOption for the program.
     */
    public static synchronized DBOption getInstance()
    {
        return instance;
    }
    
    /** Check if there is an active DBOption for the program.
     */
    public static synchronized boolean exists()
    {
        return instance != null;
    }
    
    /** Sets the currently active DBOption to the current calling one.
     */
    public void setInstance()
    {
        instance = this;
    }
    
    public String toString()
    {
        return getDescription();
    }
    
    public boolean equals(Object other)
    {
        return (getClass().equals(other.getClass()));
    }
}

/* ChangeLog:
 *   $Log: DBOption.java,v $
 *   Revision 1.2  2004/12/07 17:53:22  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 *   Revision 1.1  2004/11/01 00:43:33  bdickie
 *   Database backend for file explorer done.
 *
 */
