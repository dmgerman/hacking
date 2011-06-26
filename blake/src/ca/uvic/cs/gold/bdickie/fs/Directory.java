/*
 * $Id: Directory.java,v 1.2 2004/12/07 17:53:23 bdickie Exp $
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

import java.util.*;
import ca.uvic.cs.gold.bdickie.db.DBConnection;

/** A data structure representing a directory in the repository.
 * 
 * @author Blake Dickie
 */
public class Directory extends DirectoryContent {
    private TreeSet m_contents = new TreeSet(new DirContentCompare());
    private TreeMap m_filenames = new TreeMap();
    private boolean m_hasContents = false;
    private static Directory root = new Directory();
    
    /** Creates a new instance of Directory */
    private Directory() {
        super();
    }
    
    /**
     * Creates a new directory with the given filename and parent directory.
     * @param name The name of the directory (not the full path).
     * @param parent The parent directory.
     */    
    public Directory(String name, Directory parent)
    {
        super(name, parent);
    }
    
    /** Returns true.
     */
    public boolean isDirectory() {
        return true;
    }
    
    /** Checks if this directory's contents have been initalized yet.
     */
    public boolean hasContents()
    {
        return m_hasContents;
    }
    
    /** Marks that this directory's contents are now loaded.
     */
    public void setContents()
    {
        m_hasContents = true;
    }
    
    /** Adds an item to the directory.
     */
    public void addContents(DirectoryContent content)
    {
        m_hasContents = true;
        m_contents.add(content);
        m_filenames.put(content.getFilename(), content);
    }
    
    /** Gets the items in the directory.
     */
    public Collection getContents()
    {
        return m_contents;
    }
    
    /** Flushes the directory's contents.
     */
    public void clearContents()
    {
        m_contents.clear();
        m_hasContents = false;
    }
    
    /** Finds the root directory of the repository.
     */
    public static Directory getRoot()
    {
        return root;
    }
    
    public static Directory createNewRoot()
    {
        return new Directory();
    }
    
    
    public String toString()
    {
        return getPath();
    }
    
    public static File getFile(String filename)
    {
        return getFile(getRoot(), filename);
    }
    
    /** Finds a File in the repository, initalizing parent directories as needed.
     * @param filename The filename to find.
     * @return The File object for the filename or null if it can't be found.
     */
    public static File getFile(Directory root, String filename)
    {
        DBConnection db = DBConnection.getInstance();
        if (filename.startsWith("/"))
            filename = filename.substring(1);
        Directory cDir = root;
        StringTokenizer tokenizer = new StringTokenizer(filename, "/");
        while(tokenizer.hasMoreTokens())
        {
            if (!cDir.hasContents())
                db.populateDirectory(cDir);
            DirectoryContent content = (DirectoryContent)cDir.m_filenames.get(tokenizer.nextToken());
            if (tokenizer.hasMoreTokens())
                cDir = (Directory)content;
            else if (content instanceof File)
                return (File)content;
        }
        return null;
    }
    
    /** Checks if two directories are equal.
     */
    public boolean equals(Object o)
    {
        if (!(o instanceof Directory))
            return false;
        
        Directory f = (Directory)o;
        boolean good = f.getFilename().equals(getFilename());
        if (f.getFilename().equals(getFilename()))
        {
            if (getParent() == null)
                return f.getParent() == null;
            else
                return getParent().equals(f.getParent());
        }
        return false;
        
    }
    
    public boolean exists() {
        Iterator i = m_contents.iterator();
        while(i.hasNext())
        {
            DirectoryContent content = (DirectoryContent)i.next();
            if (content.exists())
                return true;
        }
        return false;
    }
    
    public boolean show() {
        if (getViewMode() == VIEW_MODE_YES)
            return true;
        else if (getViewMode() == VIEW_MODE_NO)
            return false;
        
        Iterator i = m_contents.iterator();
        while(i.hasNext())
        {
            DirectoryContent content = (DirectoryContent)i.next();
            if (content.show())
                return true;
        }
        return false;
    }
    
    /** Special comparator that puts directories before files and interweaves upper and lower case
     *  letters.
     */
    private class DirContentCompare implements Comparator
    {
        
        public int compare(Object obj1, Object obj2) {
            if ((obj1 instanceof Directory) && (obj2 instanceof File))
                return -1;
            else if ((obj2 instanceof Directory) && (obj1 instanceof File))
                return 1;
            
            DirectoryContent c1 = (DirectoryContent)obj1;
            DirectoryContent c2 = (DirectoryContent)obj2;
            
            String s1 = c1.getFilename();
            String s2 = c2.getFilename();
            
            int result = s1.compareToIgnoreCase(s2);
            if (result == 0)
            {
                if (s1.equals(s2))
                    return 0;
                else
                    return s1.compareTo(s2);
            } else
                return result;
        }
        
    }
}

/* ChangeLog:
 *   $Log: Directory.java,v $
 *   Revision 1.2  2004/12/07 17:53:23  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 *   Revision 1.1  2004/10/31 23:53:40  bdickie
 *
 *   File system data structures.
 *
 */
