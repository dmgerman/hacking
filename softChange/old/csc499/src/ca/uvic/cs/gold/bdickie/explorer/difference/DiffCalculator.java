/*
 * $Id: DiffCalculator.java,v 1.2 2004/12/07 17:53:23 bdickie Exp $
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
import ca.uvic.cs.gold.bdickie.fs.File;

/** An interface for finding differences in an revision.
 *
 * @author  Blake Dickie
 */
public interface DiffCalculator {
    /** Finds the difference of the given revision from the previous one.
     *  @param file The file of the revision.
     *  @param newRevision The revision's id.
     *  @return A list of DifferenceObjects in order.  The concatination of the
     *          difference object's should give the output of the file.
     */
    public List getDifference(File file, String newRevision);
}

/* ChangeLog:
 *   $Log: DiffCalculator.java,v $
 *   Revision 1.2  2004/12/07 17:53:23  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 *   Revision 1.1  2004/11/01 01:48:08  bdickie
 *   Difference calculation system done.
 *
 */