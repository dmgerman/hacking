/*
 * @(#)PortView.java	1.0 03-JUL-04
 * 
 * Copyright (c) 2001-2004 Gaudenz Alder
 *  
 */
package org.jgraph.graph;

import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;

import org.jgraph.JGraph;

/**
 * The default implementation of a port view.
 * 
 * @version 1.0 1/1/02
 * @author Gaudenz Alder
 */

public class PortView extends AbstractCellView {

	/** Default size for all ports is 6. */
	protected static int size = 6;

	/** Renderer for the class. */
	public static PortRenderer renderer = new PortRenderer();

	/** Cache of the last valid parent. //FIX: Better solution? */
	protected transient CellView lastParent;

	/**
	 * Constructs a view that holds a reference to the specified cell, anchor
	 * and parent vertex.
	 * 
	 * @param cell
	 *            reference to the cell in the model
	 * @param anchor
	 *            view of the parent
	 * @param anchor
	 *            view of the anchor port
	 */
	public PortView(Object cell, JGraph graph, CellMapper mapper) {
		super(cell, graph, mapper);
	}

	//
	// CellView interface
	//

	/**
	 * This method ensures a non-null value. If the super method returns null
	 * then the last valid parent is returned. Note: If a vertex is removed, all
	 * ports will be replaced in connected edges. The ports are replaced by the
	 * center point of the <i>last </i> valid vertex view.
	 */
	public CellView getParentView() {
		CellView parent = super.getParentView();
		if (parent == null)
			parent = lastParent;
		else
			lastParent = parent;
		return parent;
	}

	/**
	 * Returns the bounds for the port view.
	 */
	public Rectangle2D getBounds() {
		Rectangle2D bounds = getAttributes().createRect(getLocation(null));
		bounds.setFrame(bounds.getX() - size / 2, bounds.getY() - size / 2,
				bounds.getWidth() + size, bounds.getHeight() + size);
		return bounds;
	}

	/**
	 * Returns a renderer for the class.
	 */
	public CellViewRenderer getRenderer() {
		return renderer;
	}

	/**
	 * Returns <code>null</code>.
	 */
	public CellHandle getHandle(GraphContext context) {
		return null;
	}

	//
	// Special Methods
	//

	/**
	 * Returns the point that the port represents with respect to
	 * <code>edge</code>.<code>edge</code> may be <code>null</code>.
	 */
	public Point2D getLocation(EdgeView edge) {
		Object modelAnchor = null;
		if (cell instanceof Port)
			modelAnchor = ((Port) cell).getAnchor();
		VertexView vertex = (VertexView) getParentView();
		Point2D pos = null;
		if (vertex != null) {
			PortView anchor = (PortView) mapper.getMapping(modelAnchor, false);
			Point2D offset = GraphConstants.getOffset(allAttributes);
			// If No Edge Return Center
			if (edge == null && offset == null)
				pos = vertex.getCenterPoint();
			// Apply Offset
			if (offset != null) {
				double x = offset.getX();
				double y = offset.getY();
				Rectangle2D r = vertex.getBounds();
				// Absolute Offset
				boolean isAbsoluteX = GraphConstants.isAbsoluteX(allAttributes);
				boolean isAbsoluteY = GraphConstants.isAbsoluteY(allAttributes);
				if (!isAbsoluteX) {
					x = x * (r.getWidth() - 1) / GraphConstants.PERMILLE;
				}
				if (!isAbsoluteY) {
					y = y * (r.getHeight() - 1) / GraphConstants.PERMILLE;
				} // Offset from Anchor
				pos = (anchor != null) ? anchor.getLocation(edge)
						: getAttributes().createPoint(r.getX(), r.getY());
				pos = getAttributes().createPoint(pos.getX() + x,
						pos.getY() + y);
			} else if (edge != null) {
				// Floating Port
				Point2D p1 = getNextPoint(edge);
				if (p1 == null)
					// If "Dangling" Port Return Center
					return vertex.getCenterPoint();
				pos = vertex.getPerimeterPoint(pos, p1);
				if (shouldInvokePortMagic(edge)) {
					if (p1 != null) {
						Rectangle2D r = getParentView().getBounds();
						if (p1.getX() > r.getX()
								&& p1.getX() < r.getX() + r.getWidth()) {
							pos.setLocation(p1.getX(), pos.getY());
						} else if (p1.getY() >= r.getY()
								&& p1.getY() < r.getY() + r.getHeight()) { // vertical
							pos.setLocation(pos.getX(), p1.getY());
						}
						if (p1.getY() < r.getY())
							pos.setLocation(pos.getX(), r.getY());
						else if (p1.getY() > r.getY() + r.getHeight())
							pos.setLocation(pos.getX(), r.getY()
									+ r.getHeight());
					}
				}

			}
		}
		return pos;
	}
	
	/**
	 * Subclassers can override this to decide whether or not "port magic"
	 * should appear on a given edge. (Port magic means the port tries to
	 * make the edge horizontal or vertical if the closest control point
	 * lies within the bounds of the parent vertex.)
	 */
	protected boolean shouldInvokePortMagic(EdgeView edge) {
		return edge.getPointCount() > 2
			&& GraphConstants.getRouting(edge.getAllAttributes()) == null
			&& GraphConstants.getLineStyle(edge.getAllAttributes()) == GraphConstants.STYLE_ORTHOGONAL;
	}

	/**
	 * Returns the point that is closest to the port view on <code>edge</code>.
	 * Returns <code>null</code> if <code>edge</code> has less than 2
	 * points.
	 */
	protected Point2D getNextPoint(EdgeView edge) {
		int n = edge.getPointCount();
		if (n > 1) {
			if (edge.getSource() == this)
				return getEdgePoint(edge, 1);
			else if (edge.getTarget() == this)
				return getEdgePoint(edge, n - 2);
		}
		return null;
	}

	/**
	 * Returns the point of <code>edge</code> at index <code>index</code>.
	 * Avoids calling <code>getLocation</code> on the opposite port of
	 * <code>edge</code> (possible infinite recursion).
	 */
	protected Point2D getEdgePoint(EdgeView view, int index) {
		Object obj = view.points.get(index);
		if (obj instanceof Point2D)
			return (Point2D) obj;
		else if (obj instanceof PortView) {
			VertexView vertex = (VertexView) ((CellView) obj).getParentView();
			if (vertex != null)
				return vertex.getCenterPoint();
		}
		return null;
	}

}
