/*
 * $Id: GraphSettings.java,v 1.1 2004/12/07 17:53:23 bdickie Exp $
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

import ca.uvic.cs.gold.bdickie.fs.Directory;
import java.util.*;

/** A class which contains the settings that are needed to crate a graph.
 *  Generally created by the NewGraphViewWizard and given to the graph
 *  during initalization.
 *
 * @author  Blake Dickie
 */
public class GraphSettings {
    private Date startDate;
    private Date endDate;
    private Directory root;
    private String regexpPattern;
    private GraphViewMode viewMode;
    
    
    /** Creates a new instance of GraphSettings */
    public GraphSettings() {
        
    }
    
    
    /**
     * Getter for property startDate.
     * @return Value of property startDate.
     */
    public java.util.Date getStartDate() {
        return startDate;
    }
    
    /**
     * Setter for property startDate.
     * @param startDate New value of property startDate.
     */
    public void setStartDate(java.util.Date startDate) {
        this.startDate = startDate;
    }
    
    /**
     * Getter for property endDate.
     * @return Value of property endDate.
     */
    public java.util.Date getEndDate() {
        return endDate;
    }
    
    /**
     * Setter for property endDate.
     * @param endDate New value of property endDate.
     */
    public void setEndDate(java.util.Date endDate) {
        this.endDate = endDate;
    }
    
    /**
     * Getter for property root.
     * @return Value of property root.
     */
    public ca.uvic.cs.gold.bdickie.fs.Directory getRoot() {
        return root;
    }
    
    /**
     * Setter for property root.
     * @param root New value of property root.
     */
    public void setRoot(ca.uvic.cs.gold.bdickie.fs.Directory root) {
        this.root = root;
    }
    
    
    /**
     * Getter for property viewMode.
     * @return Value of property viewMode.
     */
    public ca.uvic.cs.gold.bdickie.graphview.framework.GraphViewMode getViewMode() {
        return viewMode;
    }    
    
    /**
     * Setter for property viewMode.
     * @param viewMode New value of property viewMode.
     */
    public void setViewMode(ca.uvic.cs.gold.bdickie.graphview.framework.GraphViewMode viewMode) {
        this.viewMode = viewMode;
    }    
    
    /**
     * Getter for property regexpPattern.
     * @return Value of property regexpPattern.
     */
    public java.lang.String getRegexpPattern() {
        return regexpPattern;
    }
    
    /**
     * Setter for property regexpPattern.
     * @param regexpPattern New value of property regexpPattern.
     */
    public void setRegexpPattern(java.lang.String regexpPattern) {
        this.regexpPattern = regexpPattern;
    }
    
}

/* ChangeLog:
 *   $Log: GraphSettings.java,v $
 *   Revision 1.1  2004/12/07 17:53:23  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 */
