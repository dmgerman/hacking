/*
 * $Id: RevisionDetails.java,v 1.2 2004/12/07 17:53:22 bdickie Exp $
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

import ca.uvic.cs.gold.bdickie.fs.File;

/** Data structure for storing results of a get revision request.
 *
 * @author  Blake Dickie
 */
public class RevisionDetails {
    private File file;
    private String revision_id;
    private String content;
    private String date;
    private boolean deleted;
    private String author;
    
    /** Creates a new instance of RevisionDetails */
    public RevisionDetails(File f, String rev, String content, String date, String author, boolean inattic) {
        file = f;
        revision_id = rev;
        this.content = content;
        this.date = date;
        deleted = inattic;
        this.author = author;
    }
    
    
    public File getFile()
    {
        return file;
    }
    
    public String getRevisionID()
    {
        return revision_id;
    }
    
    public String getContent()
    {
        return content;
    }
    
    public String getDate()
    {
        return date;
    }
    
    public boolean isDeleted()
    {
        return deleted;
    }
    
    public String getAuthor()
    {
        return author;
    }
     
}

/* ChangeLog:
 *   $Log: RevisionDetails.java,v $
 *   Revision 1.2  2004/12/07 17:53:22  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 *   Revision 1.1  2004/10/31 23:43:51  bdickie
 *   Done prelimiary version of repository explorer.
 *
 */
