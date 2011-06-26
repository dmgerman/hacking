/*
 * $Id: DifferenceObject.java,v 1.2 2004/12/07 17:53:23 bdickie Exp $
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

package ca.uvic.cs.gold.bdickie.explorer.difference;

/** A data structure representing part of a difference output of a program.
 *  It contains a region of text and how it was modified (or possibly not 
 *  modified).
 *
 * @author  Blake Dickie
 */
public class DifferenceObject {
    private String value;
    private int type;
    
    public static final int SAME = 1;
    public static final int NEW = 2;
    public static final int CHANGED = 3;
    public static final int REMOVED = 4;
    
    /** Creates a new instance of DifferenceObject */
    public DifferenceObject(String v, int type) {
        value = v;
        this.type = type;
    }
    
    
    public String getValue()
    {
        return value;
    }
    
    public int getType()
    {
        return type;
    }
}

/* ChangeLog:
 *   $Log: DifferenceObject.java,v $
 *   Revision 1.2  2004/12/07 17:53:23  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 *   Revision 1.1  2004/11/01 01:48:08  bdickie
 *   Difference calculation system done.
 *
 */