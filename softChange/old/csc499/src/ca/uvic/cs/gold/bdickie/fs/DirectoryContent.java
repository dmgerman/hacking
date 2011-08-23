/*
 * $Id: DirectoryContent.java,v 1.2 2004/12/07 17:53:23 bdickie Exp $
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

package ca.uvic.cs.gold.bdickie.fs;

/** An abstract class that represents a directory's content (either a file or
 *  another directory).
 *
 * @author  Blake Dickie
 */
public abstract class DirectoryContent {
    public static final int VIEW_MODE_YES = 0;
    public static final int VIEW_MODE_NO = 1;
    public static final int VIEW_MODE_MAYBE = 2;
    
    
    private static final String FILE_PATH_SEPERATOR = "/";
    
    private String m_name;
    private Directory m_parent;
    private boolean isRoot;
    private int viewMode;
    private String path = null;
    
    /** Creates a new instance of DirectoryContent */
    public DirectoryContent(String filename, Directory parent) {
        isRoot = false;
        m_name = filename;
        m_parent = parent;
    }
    
    /** Special constructor for the root directory.
     */
    protected DirectoryContent() {
        isRoot = true;
        m_name = "";
        
    }
    
    public String getFilename() {
        return m_name;
    }
    
    public Directory getParent() {
        return m_parent;
    }
    
    public String getPath() {
        if (path == null)
        {
        if (isRoot)
            path = "";
        else
            path =  m_parent.getPath() + FILE_PATH_SEPERATOR + m_name;
        }
        return path;
    }
    
    public boolean isRoot() {
        return isRoot;
    }
    
    public int hashCode() {
        return getPath().hashCode();
    }
    
    public abstract boolean isDirectory();
    
    public abstract boolean show();
    public abstract boolean exists();
    
    /**
     * Getter for property viewMode.
     * @return Value of property viewMode.
     */
    public int getViewMode() {
        return viewMode;
    }    
    
    /**
     * Setter for property viewMode.
     * @param viewMode New value of property viewMode.
     */
    public void setViewMode(int viewMode) {
        this.viewMode = viewMode;
    }
    
}

/* ChangeLog:
 *   $Log: DirectoryContent.java,v $
 *   Revision 1.2  2004/12/07 17:53:23  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 *   Revision 1.1  2004/10/31 23:53:40  bdickie
 *
 *   File system data structures.
 *
 */