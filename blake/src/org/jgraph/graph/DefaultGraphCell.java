/*
 * @(#)AbstractGraphCell.java	1.0 03-JUL-04
 * 
 * Copyright (c) 2001-2004 Gaudenz Alder
 *  
 */
package org.jgraph.graph;

import java.awt.Rectangle;
import java.awt.geom.Rectangle2D;
import java.util.Collections;
import java.util.List;
import java.util.Map;

import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.MutableTreeNode;

/**
 * The default implementation for the GraphCell interface.
 *
 * @version 1.0 1/1/02
 * @author Gaudenz Alder
 */

public class DefaultGraphCell
	extends DefaultMutableTreeNode
	implements GraphCell, Cloneable {

	public final static Rectangle defaultBounds = new Rectangle(10, 10, 20, 20);

	/** Hashtable for properties. Initially empty */
	protected AttributeMap attributes = new AttributeMap();

	/**
	 * Creates an empty cell.
	 */
	public DefaultGraphCell() {
		this(null);
	}

	/**
	 * Creates a graph cell and initializes it with the specified user object.
	 *
	 * @param userObject an Object provided by the user that constitutes
	 *                   the cell's data
	 */
	public DefaultGraphCell(Object userObject) {
		this(userObject, null);
	}

	/**
	 * Constructs a cell that holds a reference to the specified user object
	 * and contains the specified array of children and sets default values
	 * for the bounds attribute.
	 *
	 * @param userObject reference to the user object
	 * @param children array of children
	 */
	public DefaultGraphCell(Object userObject, MutableTreeNode[] children) {
		super(userObject, true);
		setUserObject(userObject);
		if (children != null)
			for (int i = 0; i < children.length; i++)
				add(children[i]);
		GraphConstants.setBounds(attributes, defaultBounds);
	}

	/**
	 * Creates a graph cell and initializes it with the specified user object.
	 * The GraphCell allows children only if specified.
	 *
	 * @param userObject an Object provided by the user that constitutes
	 *                   the cell's data
	 */
	public DefaultGraphCell(Object userObject, boolean allowsChildren) {
		super(userObject, allowsChildren);
	}

	/**
	 * Override parent method to synchronize value property and userObject.
	 * The following holds for each GraphCell c:<p>
	 * GraphConstants.getValue(c.getAttributes()) == c.getUserObject()<p>
	 * <strong>Note:</strong> A cell's userObject can be set using
	 * GraphModel.edit() with a propertyMap that carries a value entry
	 * for that cell.
	 */
	public void setUserObject(Object obj) {
		super.setUserObject(obj);
		obj = getUserObject();
		if (obj == null)
			GraphConstants.setValue(attributes, "");
		else
			GraphConstants.setValue(attributes, obj);
	}

	/**
	 * Provides access to the children list to change ordering.
	 * This method returns a <code>Collections.EMPTY_LIST</code>
	 * if the list of childrenpoints to <code>null</code>.
	 */
	public List getChildren() {
		if (children == null)
			return Collections.EMPTY_LIST;
		return children;
	}

	/**
	 * Returns the properies of the cell.
	 */
	public AttributeMap getAttributes() {
		return attributes;
	}

	/**
	 * Apply <code>change</code> to the cell and sync userObject.
	 */
	public Map changeAttributes(Map change) {
		Map undo = attributes.applyMap(change);
		Object newValue = GraphConstants.getValue(attributes);
		// Check for inconsistencies
		if (userObject != null && newValue == null)
			GraphConstants.setValue(attributes, userObject);
		else
			setUserObject(newValue);
		// Ensure non-null bounds
		Rectangle2D bounds = GraphConstants.getBounds(attributes);
		if (bounds == null)
			GraphConstants.setBounds(attributes, defaultBounds);
		return undo;
	}

	/**
	 * Sets the attributes.
	 * @param attributes The attributes to set
	 */
	public void setAttributes(AttributeMap attributes) {
		this.attributes = attributes;
		if (userObject != null)
			GraphConstants.setValue(attributes, userObject);
	}

	/**
	 * Create a clone of the cell. This method uses the superclass
	 * implementation (which does not clone the children), then
	 * uses clone on the attribute map, and overrides the clone's
	 * user object with the value in the cloned attribute map.
	 *
	 * @return Object  a clone of this object.
	 */
	public Object clone() {
		DefaultGraphCell c = (DefaultGraphCell) super.clone();
		c.attributes = (AttributeMap) attributes.clone();
		c.userObject = GraphConstants.getValue(c.attributes);
		return c;
	}

}
