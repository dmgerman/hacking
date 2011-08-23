/*
 * $Id: RevisionDiffTable.java,v 1.3 2004/12/07 17:53:23 bdickie Exp $
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

import java.util.*;
import java.util.regex.*;
import java.io.*;

import ca.uvic.cs.gold.bdickie.ErrorLog;
import ca.uvic.cs.gold.bdickie.db.DBConnection;
import ca.uvic.cs.gold.bdickie.fs.File;

/** A difference calculator that uses the diff output in the database.
 *
 * @author  Blake Dickie
 */
public class RevisionDiffTable implements DiffCalculator {
    private static final Pattern lineCommand = Pattern.compile("([0-9]+(?:,[0-9]+)?)(a|c|d)([0-9]+(?:,[0-9]+)?)");
    private static final Pattern lineSet = Pattern.compile("([0-9]+)(?:,([0-9]+))?");
    
    /** Creates a new instance of RevisionDiffTable */
    public RevisionDiffTable() {
    }
    
    /** Calculates the difference in the revision.
     */
    public List getDifference(File file, String newRevision) {
        String diff = DBConnection.getInstance().getDifference(file, newRevision);
        String newData = DBConnection.getInstance().getRevision(file, newRevision).getContent();
        List result = new ArrayList();
        
        if (diff == null)
        {
            DifferenceObject diffO = new DifferenceObject(newData, DifferenceObject.SAME);
            result.add(diffO);
            return result;
        }
        
        // Its easier to work with things one line at a time.
        BufferedReader diffInput = new BufferedReader(new StringReader(diff));
        BufferedReader fileInput = new BufferedReader(new StringReader(newData));
        
        try {
            int currentLine = 0;
            String diffLine;
            // Continure until the end of the diff input is reached.
            while((diffLine = diffInput.readLine()) != null) {
                LinesDifference lDiff = parseDifference(diffLine);
                if (lDiff != null) {
                    int linesMoved = 0;
                    switch(lDiff.type) {
                        case DifferenceObject.REMOVED:
                            linesMoved = lDiff.newLow - currentLine;
                            moveLines(fileInput, linesMoved, result, DifferenceObject.SAME, 0);
                            moveLines(diffInput, lDiff.oldHigh - lDiff.oldLow + 1,
                            result, DifferenceObject.REMOVED, 2);
                            break;
                        case DifferenceObject.NEW:
                            linesMoved = Math.max(lDiff.newLow - currentLine - 1, 0);
                            moveLines(fileInput, linesMoved, result, DifferenceObject.SAME, 0);
                            moveLines(fileInput, lDiff.newHigh - lDiff.newLow + 1,
                            result, DifferenceObject.NEW, 0);
                            linesMoved += lDiff.newHigh - lDiff.newLow + 1;
                            eatLines(diffInput, lDiff.newHigh - lDiff.newLow + 1);
                            break;
                        case DifferenceObject.CHANGED:
                            linesMoved = Math.max(lDiff.newLow - currentLine - 1, 0);
                            moveLines(fileInput, linesMoved, result, DifferenceObject.SAME, 0);
                            moveLines(diffInput, lDiff.oldHigh - lDiff.oldLow + 1,
                            result, DifferenceObject.REMOVED, 2);
                            moveLines(fileInput, lDiff.newHigh - lDiff.newLow + 1,
                            result, DifferenceObject.NEW, 0);
                            linesMoved += lDiff.newHigh - lDiff.newLow + 1;
                            eatLines(diffInput, lDiff.newHigh - lDiff.newLow + 2);
                    }
                    currentLine += linesMoved;
                }
            }
            
            // Move the rest of the file to the result.
            moveLines(fileInput, -1, result, DifferenceObject.SAME, 0);
        } catch (IOException e) {
            ErrorLog.reportError("Unable to make difference.", e.getMessage(), true);
        }
        return result;
    }
    
    /** Reads a number of lines from a BufferedReader and does nothing with them.
     */
    private void eatLines(BufferedReader fileInput, int numLines) throws IOException {
        for(int i = 0; i < numLines; i++)
            fileInput.readLine();
    }
    
    
    /** Copies a number of files from a BufferedReader to a new DifferenceObject.
     *  @param fileInput The source of the lines.
     *  @param numLines The number of lines to copy.  -1 for all remaining lines.
     *  @param result The list to store the DifferenceObject into.
     *  @param type The type of the DifferenceObject to make.
     *  @param strip_chars Delete this many characters from the start of each
     *           line.  Used to remove the '> ' and '< '.
     */
    private void moveLines(BufferedReader fileInput, int numLines, List result, int type, int strip_chars) throws IOException {
        int currentLine = 0;
        String line;
        StringBuffer res = new StringBuffer();
        while( (numLines == -1 || currentLine < numLines) && ((line = fileInput.readLine()) != null)) {
            if (strip_chars > 0)
                line = line.substring(strip_chars);
            res.append(line);
            res.append('\n');
            currentLine++;
        }
        DifferenceObject diff = new DifferenceObject(res.toString(), type);
        if (diff.getValue().length() != 0)
            result.add(diff);
    }
    
    
    /** Parses a change defination (ie 43,32c48).
     */
    private static LinesDifference parseDifference(String line) {
        Matcher m = lineCommand.matcher(line.trim());
        if (!m.matches())
            return null;
        LinesDifference result = new LinesDifference();
        
        // Extract the type.
        String type = m.group(2);
        if (type.equals("a"))
            result.type = DifferenceObject.NEW;
        else if (type.equals("c"))
            result.type = DifferenceObject.CHANGED;
        else if (type.equals("d"))
            result.type = DifferenceObject.REMOVED;
        
        // Extract the first line range, it may or may not be a single number.
        Matcher m2 = lineSet.matcher(m.group(1));
        m2.matches();
        result.oldLow = Integer.parseInt(m2.group(1));
        if (m2.group(2) == null)
            result.oldHigh = result.oldLow;
        else
            result.oldHigh = Integer.parseInt(m2.group(2));
        
        // Extract the second line range, it may or may not be a single number.
        m2 = lineSet.matcher(m.group(3));
        m2.matches();
        result.newLow = Integer.parseInt(m2.group(1));
        if (m2.group(2) == null)
            result.newHigh = result.newLow;
        else
            result.newHigh = Integer.parseInt(m2.group(2));
        
        return result;
    }
    
    private static class LinesDifference {
        public int oldLow;
        public int oldHigh;
        public int newLow;
        public int newHigh;
        public int type;
    }
}

/* ChangeLog:
 *   $Log: RevisionDiffTable.java,v $
 *   Revision 1.3  2004/12/07 17:53:23  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 *   Revision 1.2  2004/11/01 17:18:44  bdickie
 *   Fixed bug where new revisions don't have a diff.
 *
 *   Revision 1.1  2004/11/01 01:48:08  bdickie
 *   Difference calculation system done.
 *
 */