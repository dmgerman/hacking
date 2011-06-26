/*
 * @(#)DefaultEdge.java	1.0 03-JUL-04
 * 
 * Copyright (c) 2001-2004 Gaudenz Alder
 *  
 */
package org.jgraph.graph;

import java.awt.Point;
import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

/**
 * A simple implementation for an edge.
 *
 * @version 1.0 1/1/02
 * @author Gaudenz Alder
 */

public class DefaultEdge extends DefaultGraphCell implements Edge {

	/** Source and target of the edge. */
	protected Object source, target;

	/**
	 * Constructs an empty edge.
	 */
	public DefaultEdge() {
		this(null);
	}

	/**
	 * Constructs an edge that holds a reference to the specified user object.
	 *
	 * @param userObject reference to the user object
	 */
	public DefaultEdge(Object userObject) {
		this(userObject, true);
	}

	/**
	 * Constructs an edge that holds a reference to the specified user object
	 * and sets default values for points and the label position.
	 *
	 * @param userObject reference to the user object
	 */
	public DefaultEdge(Object userObject, boolean allowsChildren) {
		super(userObject, allowsChildren);
		checkDefaults();
	}

	/**
	 * Override parent method to ensure non-null points.
	 */
	protected void checkDefaults() {
		List points = GraphConstants.getPoints(attributes);
		if (points == null) {
			List defaultPoints = new ArrayList();
			defaultPoints.add(getAttributes().createPoint(10, 10));
			defaultPoints.add(getAttributes().createPoint(20, 20));
			GraphConstants.setPoints(attributes, defaultPoints);
		}
		Point labelPosition = GraphConstants.getLabelPosition(attributes);
		if (labelPosition == null) {
			int center = GraphConstants.PERMILLE / 2;
			labelPosition = new Point(center, center);
			GraphConstants.setLabelPosition(attributes, labelPosition);
		}
	}
	
	/**
	 * Override parent method to ensure non-null points.
	 */
	public Map changeAttributes(Map change) {
		Map undo = super.changeAttributes(change);
		checkDefaults();
		return undo;
	}

	/**
	 * Returns the source of the edge.
	 */
	public Object getSource() {
		return source;
	}

	/**
	 * Returns the target of the edge.
	 */
	public Object getTarget() {
		return target;
	}

	/**
	 * Sets the source of the edge.
	 */
	public void setSource(Object port) {
		source = port;
	}

	/**
	 * Returns the target of <code>edge</code>.
	 */
	public void setTarget(Object port) {
		target = port;
	}

	/**
	 * Create a clone of the cell. The cloning of the
	 * user object is deferred to the cloneUserObject()
	 * method.
	 *
	 * @return Object  a clone of this object.
	 */
	public Object clone() {
		DefaultEdge c = (DefaultEdge) super.clone();
		c.source = null;
		c.target = null;
		return c;
	}

	//
	// Default Routing
	// 

	public static class DefaultRouting implements Edge.Routing {

		public void route(EdgeView edge, java.util.List points) {
			int n = points.size();
			Point2D from = edge.getPoint(0);
			if (edge.getSource() instanceof PortView)
				from = ((PortView) edge.getSource()).getLocation(null);
			else if (edge.getSource() != null) {
				Rectangle2D b = edge.getSource().getBounds();
				from =
					edge.getAttributes().createPoint(b.getCenterX(), b.getCenterY());
			}
			Point2D to = edge.getPoint(n - 1);
			if (edge.getTarget() instanceof PortView)
				to = ((PortView) edge.getTarget()).getLocation(null);
			else if (edge.getTarget() != null) {
				Rectangle2D b = edge.getTarget().getBounds();
				to = edge.getAttributes().createPoint(b.getCenterX(), b.getCenterY());
			}
			if (from != null && to != null) {
				Point2D[] routed;
				// Handle self references
				if (edge.getSource() == edge.getTarget()
					&& edge.getSource() != null) {
					Rectangle2D bounds =
						edge.getSource().getParentView().getBounds();
					double height = edge.getGraph().getGridSize();
					double width = bounds.getWidth() / 3;
					routed = new Point2D[4];
					routed[0] =
						edge.getAttributes().createPoint(
							bounds.getX() + width,
							bounds.getY() + bounds.getHeight());
					routed[1] =
						edge.getAttributes().createPoint(
							bounds.getX() + width,
							bounds.getY() + bounds.getHeight() + height);
					routed[2] =
						edge.getAttributes().createPoint(
							bounds.getX() + 2 * width,
							bounds.getY() + bounds.getHeight() + height);
					routed[3] =
						edge.getAttributes().createPoint(
							bounds.getX() + 2 * width,
							bounds.getY() + bounds.getHeight());
				} else {
					double dx = Math.abs(from.getX() - to.getX());
					double dy = Math.abs(from.getY() - to.getY());
					double x2 = from.getX() + ((to.getX() - from.getX()) / 2);
					double y2 = from.getY() + ((to.getY() - from.getY()) / 2);
					routed = new Point2D[2];
					if (dx > dy) {
						routed[0] = edge.getAttributes().createPoint(x2, from.getY());
						//new Point(to.x, from.y)
						routed[1] = edge.getAttributes().createPoint(x2, to.getY());
					} else {
						routed[0] = edge.getAttributes().createPoint(from.getX(), y2);
						// new Point(from.x, to.y)
						routed[1] = edge.getAttributes().createPoint(to.getX(), y2);
					}
				}
				// Set/Add Points
				for (int i = 0; i < routed.length; i++)
					if (points.size() > i + 2)
						points.set(i + 1, routed[i]);
					else
						points.add(i + 1, routed[i]);
				// Remove spare points
				while (points.size() > routed.length + 2) {
					points.remove(points.size() - 2);
				}
			}
		}

	}

}
