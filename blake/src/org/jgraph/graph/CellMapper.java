/*
 * @(#)CellMapper.java	1.0 03-JUL-04
 * 
 * Copyright (c) 2001-2004 Gaudenz Alder
 *  
 */
package org.jgraph.graph;

/**
 * Defines the requirements for objects that may be used as
 * a cell mapper.
 *
 * @version 1.0 1/1/02
 * @author Gaudenz Alder
 */

public interface CellMapper {

	/**
	 * Returns the view that is associated with <code>cell</code>.
	 *
	 * @param create whether a new view should created
	 */
	CellView getMapping(Object cell, boolean create);

	/**
	 * Inserts the association between <code>cell</code> and <code>view</code>.
	 *
	 * @param cell the cell that constitutes the model element
	 * @param view the view that constitutes the view element
	 */
	void putMapping(Object cell, CellView view);

}
