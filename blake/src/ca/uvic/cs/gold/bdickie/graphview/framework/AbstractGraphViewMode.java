/*
 * $Id: AbstractGraphViewMode.java,v 1.1 2004/12/07 17:53:23 bdickie Exp $
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

package ca.uvic.cs.gold.bdickie.graphview.framework;

import java.util.*;
import java.util.regex.*;

import ca.uvic.cs.gold.bdickie.db.DBConnection;
import ca.uvic.cs.gold.bdickie.fs.*;

/** A special case of the GraphViewMode that can be extended to make
 *  Graph View Modes as well.  Has the code for having the graph contains
 *  one of the following views:
 *
 *  1 - All of the files in the modules.
 *  2 - All the files that are modified over the date range.
 *  3 - All the files that exist over the date range.
 *
 *  It checks the regular expression values as well.
 *
 *  If you extend this class don't override containsFile or addedToGraph.
 *  Preform any addional inilalization you need into childAddToGraph. 
 *
 * @author  Blake Dickie
 */
public abstract class AbstractGraphViewMode implements GraphViewMode {
    public static final int VIEW_ALL = 1;
    public static final int VIEW_EXISTS = 2;
    public static final int VIEW_MODIFIED = 3;
    
    protected Graph graph;
    
    private Pattern regExp;
    
    private Set includedNodes;
    private int mode;
    
    private DBConnection db;
    
    /** Creates a new instance of AbstractGraphView */
    public AbstractGraphViewMode(int mode) {
        this.mode = mode;
    }
    
    public void addedToGraph(Graph graph)
    {
        this.graph = graph;
        db = DBConnection.getInstance();
        
        if (!graph.getSettings().getRegexpPattern().equals(""))
            regExp = Pattern.compile(graph.getSettings().getRegexpPattern());
        
        if (mode != VIEW_ALL)
            includedNodes = new HashSet();
        
        switch(mode)
        {
            case VIEW_EXISTS:
                addFilesThatExistBeforePeriod();
            case VIEW_MODIFIED:
                addFilesModifiedOverPeriod();
        }
        
        childAddToGraph(graph);
    }
    
    public boolean containsFile(DirectoryContent node)
    {
        // If there's a regular expression and we can't find a match
        // in the path return false.
        if ((regExp != null) && (!regExp.matcher(node.getPath()).find()))
            return false;
        
        if (mode == VIEW_ALL)
            return true;
        else
            return includedNodes.contains(node.getPath());
    }
    
    private void addFilesModifiedOverPeriod()
    {
        Map active = db.getFilesUpdatedOnRange(graph.getSettings().getStartDate(), graph.getSettings().getEndDate(), graph.getSettings().getRoot().getPath(), graph.getSettings().getRegexpPattern());
        includedNodes.addAll(active.keySet());
    }
    
    private void addFilesThatExistBeforePeriod()
    {
        Map files = db.getFilesThatExistAt(graph.getSettings().getStartDate(), graph.getSettings().getRoot().getPath(), graph.getSettings().getRegexpPattern());
        includedNodes.addAll(files.keySet());
    }
    
    
    /** The replacement for addedToGraph that AbstractGraphViewMode implementations
     *  should use.  Is called during addedToGraph after this class's
     *  inialization is complete.
     */
    protected abstract void childAddToGraph(Graph graph);
}

/* ChangeLog:
 *   $Log: AbstractGraphViewMode.java,v $
 *   Revision 1.1  2004/12/07 17:53:23  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 */
