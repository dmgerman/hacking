/*
 * @(#)AttributeMap 1.0 03-JUL-04
 * 
 * Copyright (c) 2001-2004 Gaudenz Alder
 *  
 */
package org.jgraph.graph;

import java.awt.Point;
import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

/**
 * @author Gaudenz Alder
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Generation - Code and Comments
 */
public class AttributeMap extends Hashtable {
	
	/**
	 * @return
	 */
	public AttributeMap() {
		// empty constructor
	}
	
	/**
	 * @return
	 */
	public AttributeMap(Map map) {
		super(map);
	}
	
	/**
	 * @return
	 */
	public Point2D createPoint() {
		return new SerializablePoint2D();
	}
	
	/**
	 * @return
	 */
	public Point2D createPoint(Point2D p) {
		if (p != null) {
			return createPoint(p.getX(), p.getY());
		}
		return null;
	}
	
	/**
	 * @return
	 */
	public Point2D createPoint(double x, double y) {
		return new SerializablePoint2D(x, y);
	}
	
	/**
	 * @return
	 */
	public Rectangle2D createRect() {
		return new SerializableRectangle2D();
	}
	
	/**
	 * @return
	 */
	public Rectangle2D createRect(double x, double y, double w, double h) {
		return new SerializableRectangle2D(x, y, w, h);
	}
	
	/**
	 * @return
	 */
	public Rectangle2D createRect(Point2D pt) {
		return createRect(pt, 0);
	}
	
	/**
	 * @return
	 */
	public Rectangle2D createRect(Point2D pt, double size) {
		if (pt != null) {
			return createRect(pt.getX(), pt.getY(), size, size);
		}
		return null;
	}
	
	/**
	 * @return
	 */
	public Rectangle2D createRect(Rectangle2D rect) {
		if (rect != null) {
			return createRect(rect.getX(), rect.getY(), rect.getWidth(), rect
					.getHeight());
		}
		return null;
	}
	
	/**
	 * @return
	 */
	public Rectangle2D createRect(double x, double y, double w,
			double h, double grow1, double grow2) {
		return createRect(x - grow1, y - grow1, w + grow1 + grow2, h + grow1
				+ grow2);
	}
	
	/**
	 * @return
	 */
	public Rectangle2D createRect(Rectangle2D rect, double grow1,
			double grow2) {
		if (rect != null) {
			return createRect(rect.getX(), rect.getY(), rect.getWidth(), rect
					.getHeight(), grow1, grow2);
		}
		return null;
	}
	
	/**
	 * Apply the <code>change</code> to the <code>target</code>.
	 * <code>change</code> must be a <code>Map</code> previously obtained
	 * from this object. Returns a map that may be used to undo the change to
	 * target.
	 */
	public AttributeMap applyMap(Map change) {
		AttributeMap undo = new AttributeMap();
		if (change != null) {
			// Handle Remove All
			if (GraphConstants.isRemoveAll(change)) {
				undo.putAll(this);
				clear();
			}
			// Handle Remove Individual
			Object[] remove = GraphConstants.getRemoveAttributes(change);
			if (remove != null) {
				// don't store command
				for (int i = 0; i < remove.length; i++) {
					Object oldValue = remove(remove[i]);
					if (oldValue != null)
						undo.put(remove[i], oldValue);
				}
			}
			// Attributes that were empty are added
			// to removeattibutes
			Set removeAttributes = new HashSet();
			Iterator it = change.entrySet().iterator();
			while (it.hasNext()) {
				Map.Entry entry = (Map.Entry) it.next();
				Object key = entry.getKey();
				if (!key.equals(GraphConstants.REMOVEALL) &&
					!key.equals(GraphConstants.REMOVEATTRIBUTES)) {
					Object oldValue = applyValue(key, entry.getValue());
					if (oldValue == null)
						removeAttributes.add(key);
					else
						undo.put(key, oldValue);
				}
			}
			if (!removeAttributes.isEmpty())
				GraphConstants.setRemoveAttributes(undo, removeAttributes.toArray());
		}
		return undo;
	}
	
	/**
	 * Apply the <code>key</code> to <code>value</code> and return
	 * the old value.
	 */
	public Object applyValue(Object key, Object value) {
		if (value instanceof Rectangle2D)
			value = createRect((Rectangle2D) value);
		if (value instanceof java.util.List)
			value = clonePoints((java.util.List) value, false);
		if (key == GraphConstants.VALUE)
			value = valueChanged(value);
		return put(key, value);
	}
	
	/**
	 * A hook for subclassers to handle in-place edit. This method
	 * is called from applyValue if the key equals VALUE. If you want
	 * undo to work you should return a clone of the new user object
	 * (ie. if it is not an immutable string).
	 */
	public Object valueChanged(Object newValue) {
		return newValue;
	}

	/**
	 * Returns a list where all instances of PortView are replaced by their
	 * correspnding Point instance.
	 */
	public java.util.List clonePoints(java.util.List points) {
		return clonePoints(points, true);
	}
	
	/**
	 * Returns a list where all instances of PortView are replaced by their
	 * correspnding Point instance.
	 */
	public java.util.List clonePoints(java.util.List points, boolean convertPortViews) {
		ArrayList newList = new ArrayList();
		Iterator it = points.iterator();
		while (it.hasNext()) {
			// Clone Point
			Object point = it.next();
			if (point instanceof PortView && convertPortViews)
				point = ((PortView) point).getLocation(null);
			else if (point instanceof Point2D)
				point = createPoint((Point2D) point);
			newList.add(point);
		}
		return newList;
	}

	/**
	 * Translates the maps in <code>c</code> using
	 * <code>translate(Map, int, int)</code>.
	 */
	public static void translate(Collection c, double dx, double dy) {
		Iterator it = c.iterator();
		while (it.hasNext()) {
			Object map = it.next();
			if (map instanceof AttributeMap)
				((AttributeMap) map).translate(dx, dy);
		}
	}

	/**
	 * Translates <code>map</code> by the given amount.
	 */
	public void translate(double dx, double dy) {
		// Translate Bounds
		if (GraphConstants.isMoveable(this)) {
			Rectangle2D bounds = GraphConstants.getBounds(this);
			if (bounds != null) {
				int moveableAxis = GraphConstants.getMoveableAxis(this);
				if (moveableAxis == GraphConstants.X_AXIS)
					dy = 0;
				else if (moveableAxis == GraphConstants.Y_AXIS)
					dx = 0;
				bounds.setFrame(bounds.getX() + dx, bounds.getY() + dy, bounds
						.getWidth(), bounds.getHeight());
			}
			// Translate Points
			java.util.List points = GraphConstants.getPoints(this);
			if (points != null) {
				for (int i = 0; i < points.size(); i++) {
					Object obj = points.get(i);
					if (obj instanceof Point2D) {
						Point2D pt = (Point2D) obj;
						pt.setLocation(pt.getX() + dx, pt.getY() + dy);
					}
				}
			}
		}
	}

	/**
	 * Scales <code>map</code> by the given amount.
	 */
	public void scale(double sx, double sy, Point2D origin) {
		// Scale Bounds
		Rectangle2D bounds = GraphConstants.getBounds(this);
		if (bounds != null) {
			Point2D p = createPoint(bounds.getX(), bounds.getY());
			Point2D loc = (Point2D) p.clone();
			int sizeableAxis = GraphConstants.getSizeableAxis(this);
			if (sizeableAxis == GraphConstants.X_AXIS)
				sy = 1;
			else if (sizeableAxis == GraphConstants.Y_AXIS)
				sx = 1;
			p.setLocation(origin.getX()
					+ Math.round((p.getX() - origin.getX()) * sx), origin
					.getY()
					+ Math.round((p.getY() - origin.getY()) * sy));
			if (!p.equals(loc)) // Scale Location
				translate(p.getX() - loc.getX(), p.getY() - loc.getY());
			double w = Math.max(1, Math.round(bounds.getWidth() * sx));
			double h = Math.max(1, Math.round(bounds.getHeight() * sy));
			// Scale Bounds
			bounds.setFrame(bounds.getX(), bounds.getY(), w, h);
		}
		// Scale Points
		java.util.List points = GraphConstants.getPoints(this);
		if (points != null) {
			Iterator it = points.iterator();
			while (it.hasNext()) {
				Object obj = it.next();
				if (obj instanceof Point2D) {
					// Scale Point
					Point2D loc = (Point2D) obj;
					Point2D p = (Point2D) loc.clone();
					p.setLocation(origin.getX()
							+ Math.round((p.getX() - origin.getX()) * sx),
							origin.getY()
									+ Math.round((p.getY() - origin.getY())
											* sy));
					// Move Point
					loc.setLocation(p);
				}
			}
		}
	}
	
	/**
	 * Returns a new map that contains all (key, value)-pairs of
	 * <code>newState</code> where either key is not used or value is
	 * different for key in <code>oldState</code>. In other words, this
	 * method removes the common entries from oldState and newState, and returns
	 * the "difference" between the two.
	 * 
	 * This method never returns null.
	 */
	public Map diff(Map newState) {
		Map diff = new Hashtable();
		Iterator it = newState.entrySet().iterator();
		while (it.hasNext()) {
			Map.Entry entry = (Map.Entry) it.next();
			Object key = entry.getKey();
			Object newValue = entry.getValue();
			Object oldValue = get(key);
			if (oldValue == null || !oldValue.equals(newValue))
				diff.put(key, newValue);
		}
		return diff;
	}
	
	/**
	 * Returns a clone of <code>map</code>, from keys to values. If the map
	 * contains bounds or points, these are cloned as well. References to
	 * <code>PortViews</code> are replaces by points. <br>
	 * <b>Note:</b> Extend this method to clone custom user objects.
	 */
	public Object clone() {
		AttributeMap newMap = new AttributeMap(this);
		// Clone Bounds
		Rectangle2D bounds = GraphConstants.getBounds(newMap);
		if (bounds != null)
			GraphConstants.setBounds(newMap, (Rectangle2D) (bounds.clone()));
		// Clone List Of Points
		java.util.List points = GraphConstants.getPoints(newMap);
		if (points != null)
			GraphConstants.setPoints(newMap, clonePoints(points));
		// Clone Edge Label
		Point label = GraphConstants.getLabelPosition(newMap);
		if (label != null)
			GraphConstants.setLabelPosition(newMap, new Point(label));
		return newMap;
	}

	public static class SerializablePoint2D extends Point2D.Double
			implements
				Serializable {

		public SerializablePoint2D() {
			super();
		}

		public SerializablePoint2D(double x, double y) {
			super(x, y);
		}

		private void writeObject(ObjectOutputStream out) throws IOException {
			out.defaultWriteObject();
			out.writeObject(new java.lang.Double(getX()));
			out.writeObject(new java.lang.Double(getY()));
		}

		private void readObject(ObjectInputStream in) throws IOException,
				ClassNotFoundException {
			in.defaultReadObject();
			java.lang.Double x = (java.lang.Double) in.readObject();
			java.lang.Double y = (java.lang.Double) in.readObject();
			setLocation(x.doubleValue(), y.doubleValue());
		}

	}

	public static class SerializableRectangle2D extends Rectangle2D.Double
			implements
				Serializable {

		public SerializableRectangle2D() {
			super();
		}

		public SerializableRectangle2D(double x, double y, double width,
				double height) {
			super(x, y, width, height);
		}

		private void writeObject(ObjectOutputStream out) throws IOException {
			out.defaultWriteObject();
			out.writeObject(new java.lang.Double(getX()));
			out.writeObject(new java.lang.Double(getY()));
			out.writeObject(new java.lang.Double(getWidth()));
			out.writeObject(new java.lang.Double(getHeight()));
		}

		private void readObject(ObjectInputStream in) throws IOException,
				ClassNotFoundException {
			in.defaultReadObject();
			java.lang.Double x = (java.lang.Double) in.readObject();
			java.lang.Double y = (java.lang.Double) in.readObject();
			java.lang.Double width = (java.lang.Double) in.readObject();
			java.lang.Double height = (java.lang.Double) in.readObject();
			setFrame(x.doubleValue(), y.doubleValue(), width.doubleValue(),
					height.doubleValue());
		}
	}
}
