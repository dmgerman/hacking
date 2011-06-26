/*
 * $Id: HTMLizer.java,v 1.2 2004/12/07 17:53:23 bdickie Exp $
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

package ca.uvic.cs.gold.bdickie.explorer;

import java.util.*;
import ca.uvic.cs.gold.bdickie.explorer.difference.DifferenceObject;

/** A helper class that converts a difference to HTML.
 *
 * @author  Blake Dickie
 */
public class HTMLizer {
    private static final String header = "<html>\n<body>\n";
    private static final String footer = "</body>\n</html>";
    
    private StringBuffer result = new StringBuffer();
    private boolean lastCharIsSpace = false;
    
    /** Preforms the actual conversion.
     */
    private String convert(List l) {
        
        Iterator i = l.iterator();
        result.append(header);
        while(i.hasNext()) {
            DifferenceObject d = (DifferenceObject)i.next();
            switch(d.getType())
            {
                case DifferenceObject.SAME:
                    printString(d.getValue());
                    break;
                case DifferenceObject.NEW:
                    result.append("<font color=\"blue\">");
                    printString(d.getValue());
                    result.append("</font>");
                    break;
                case DifferenceObject.REMOVED:
                    result.append("<font color=\"red\"><strike>");
                    printString(d.getValue());
                    result.append("</strike></font>");
                    break;
            }
        }
        result.append(footer);
        return result.toString();
    }
    
    /** Convert the List of DifferenceObjects (as supplied by a DiffCalculator
     *  to an HTML page.
     */
    public static String generateHTML(List l) {
        return (new HTMLizer()).convert(l);
    }
    
    /** Convert the string to an HTML page as if it is entirely a same object.
     */
    public static String generateHTML(String s) {
        DifferenceObject o = new DifferenceObject(s, DifferenceObject.SAME);
        ArrayList l  = new ArrayList(1);
        l.add(o);
        return generateHTML(l);
    }
    
    
    /** Prints a string, escaping characters as needed for html.
     */
    private void printString(String s) {
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            
            if (c == ' ') {
                if (lastCharIsSpace)
                    result.append("&nbsp;");
                else {
                    lastCharIsSpace = true;
                    result.append(' ');
                }
            } else if (c == '\n') {
                lastCharIsSpace = true;
                result.append("<br>\n");
            } else if (c == '\t') {
                if (lastCharIsSpace)
                    result.append("&nbsp;");
                else {
                    lastCharIsSpace = true;
                    result.append(' ');
                }
                result.append("&nbsp;&nbsp;&nbsp;");
            } else if (c == '<') {
                result.append("&lt;");
                lastCharIsSpace = false;
            } else if (c == '>') {
                result.append("&gt;");
                lastCharIsSpace = false;
            } else if (c >= '(' && c <= '~') {
                result.append(c);
                lastCharIsSpace = false;
            } else {
                int value = (int)c;
                result.append("&#");
                result.append(value);
                result.append(';');
                lastCharIsSpace = false;
            }
        }
    }
}

/* ChangeLog:
 *   $Log: HTMLizer.java,v $
 *   Revision 1.2  2004/12/07 17:53:23  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 *   Revision 1.1  2004/11/01 02:24:20  bdickie
 *   Done Repository Browser.
 *
 */
