/*
 * $Id: GraphViewSpecification.java,v 1.1 2004/12/07 17:53:23 bdickie Exp $
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

import java.awt.*;

/** Specifies properties about how a graph node should be displayed.
 *  Used by a GraphViewMode to inform the renderer about what to show.
 *
 * @author  Blake Dickie
 */
public class GraphViewSpecification {
    private String text;
    private Color textColor;
    private Color backgroundColor;
    private Color borderColor;
    private int borderWidth;
    
    
    /** Creates a new instance of GraphViewSpecification */
    public GraphViewSpecification() {
        text = "";
        textColor = Color.BLACK;
        borderColor = Color.BLACK;
        backgroundColor = Color.WHITE;
        borderWidth = 1;
    }
    
    /**
     * Getter for property text.
     * @return Value of property text.
     */
    public java.lang.String getText() {
        return text;
    }    
   
    /**
     * Setter for property text.
     * @param text New value of property text.
     */
    public void setText(java.lang.String text) {
        this.text = text;
    }
    
    /**
     * Getter for property textColor.
     * @return Value of property textColor.
     */
    public java.awt.Color getTextColor() {
        return textColor;
    }
    
    /**
     * Setter for property textColor.
     * @param textColor New value of property textColor.
     */
    public void setTextColor(java.awt.Color textColor) {
        this.textColor = textColor;
    }
    
    /**
     * Getter for property backgroundColor.
     * @return Value of property backgroundColor.
     */
    public java.awt.Color getBackgroundColor() {
        return backgroundColor;
    }
    
    /**
     * Setter for property backgroundColor.
     * @param backgroundColor New value of property backgroundColor.
     */
    public void setBackgroundColor(java.awt.Color backgroundColor) {
        this.backgroundColor = backgroundColor;
    }
    
    /**
     * Getter for property borderColor.
     * @return Value of property borderColor.
     */
    public java.awt.Color getBorderColor() {
        return borderColor;
    }
    
    /**
     * Setter for property borderColor.
     * @param borderColor New value of property borderColor.
     */
    public void setBorderColor(java.awt.Color borderColor) {
        if (borderColor == null)
            this.borderColor = Color.WHITE;
        else
            this.borderColor = borderColor;
    }
    
    /**
     * Getter for property borderWidth.
     * @return Value of property borderWidth.
     */
    public int getBorderWidth() {
        return borderWidth;
    }
    
    /**
     * Setter for property borderWidth.
     * @param borderWidth New value of property borderWidth.
     */
    public void setBorderWidth(int borderWidth) {
        this.borderWidth = borderWidth;
    }
    
}

/* ChangeLog:
 *   $Log: GraphViewSpecification.java,v $
 *   Revision 1.1  2004/12/07 17:53:23  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 */
