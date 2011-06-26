/*
 * $Id: MRSInfo.java,v 1.2 2004/12/07 17:53:22 bdickie Exp $
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

/** Data structure for storing results of a MRSInfo request.
 *
 * @author  Blake Dickie
 */
public class MRSInfo {
    
    private String author;
    private String datePart;
    private String time;
    private String log;
    
    /** Creates a new instance of MRSInfo */
    public MRSInfo(String author, String date, String time, String log) {
        this.author = author;
        this.datePart = date;
        this.time = time;
        this.log = log;
    }
    
    public String getAuthor()
    {
        return author;
    }
    
    public String getDate()
    {
        return datePart + " " + time;
    }
    
    public String getLog()
    {
        return log;
    }
    
    /**
     * Getter for property time.
     * @return Value of property time.
     */
    public java.lang.String getTime() {
        return time;
    }
    
    /**
     * Getter for property datePart.
     * @return Value of property datePart.
     */
    public java.lang.String getDatePart() {
        return datePart;
    }
    
    
}

/* ChangeLog
 *   $Log: MRSInfo.java,v $
 *   Revision 1.2  2004/12/07 17:53:22  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 *   Revision 1.1  2004/10/31 23:43:51  bdickie
 *   Done prelimiary version of repository explorer.
 *
 */
