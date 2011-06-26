/*
 * $Id: File.java,v 1.2 2004/12/07 17:53:23 bdickie Exp $
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

/** A data structure representing a file in the repository.  Keeps track of if
 *  it is currently deleted and its newest revision.
 *
 * @author  Blake Dickie
 */
public class File extends DirectoryContent {
    private String m_rev;
    private boolean m_del;
    private boolean exists;
    
    
    /** Creates a new instance of File */
    public File(String name, Directory directory, String rev, boolean deleted) {
        super(name, directory);
        m_rev = rev;
        m_del = deleted;
    }
    
    public String getLatestRevision()
    {
        return m_rev;
    }
    
    public boolean isDeleted()
    {
        return m_del;
    }
    
    
    public boolean isDirectory()
    {
        return false;
    }
    
    public String toString()
    {
        return getPath() + "\n";
    }
    
    public boolean equals(Object o)
    {
        if (!(o instanceof File))
            return false;
        
        File f = (File)o;
        return f.getFilename().equals(getFilename()) && f.getParent().equals(getParent());
    }
    
    public boolean exists() {
        return exists();
    }
    
    public void setExists(boolean e)
    {
        exists = e;
    }
    
    public boolean show() {
        return getViewMode() == VIEW_MODE_YES;
    }
    
}

/* ChangeLog:
 *   $Log: File.java,v $
 *   Revision 1.2  2004/12/07 17:53:23  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 *   Revision 1.1  2004/10/31 23:53:40  bdickie
 *
 *   File system data structures.
 *
 */