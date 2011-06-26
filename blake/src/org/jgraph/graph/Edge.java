/*
 * @(#)Edge.java	1.0 03-JUL-04
 * 
 * Copyright (c) 2001-2004 Gaudenz Alder
 *  
 */
package org.jgraph.graph;

import java.io.Serializable;

/**
 * Defines the requirements for an object that
 * represents an Edge in a GraphModel.
 *
 * @version 1.0 1/1/02
 * @author Gaudenz Alder
 */

public interface Edge extends GraphCell {

	/**
	 * Returns the source of the edge.
	 */
	Object getSource();

	/**
	 * Returns the target of the edge.
	 */
	Object getTarget();

	/**
	 * Sets the source of the edge.
	 */
	void setSource(Object port);

	/**
	 * Returns the target of <code>edge</code>.
	 */
	void setTarget(Object port);


	//
	// Routing
	//

	public static interface Routing extends Serializable {

		public void route(EdgeView edge, java.util.List points);

	}


}
