/*
 * @(#)JGraphDiamondView.java 1.0 12-MAY-2004
 * 
 * Copyright (c) 2001-2004, Gaudenz Alder
 * Copyright (c) 2003, K McCarthy
 * All rights reserved. 
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation 
 *   and/or other materials provided with the distribution.
 * - Neither the name of JGraph nor the names of its contributors may be used
 *   to endorse or promote products derived from this software without specific
 *   prior written permission.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
package org.jgraph.cellview;

import java.awt.BasicStroke;
import java.awt.Dimension;
import java.awt.GradientPaint;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Polygon;
import java.awt.event.MouseEvent;
import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;

import org.jgraph.JGraph;
import org.jgraph.graph.CellHandle;
import org.jgraph.graph.CellMapper;
import org.jgraph.graph.CellViewRenderer;
import org.jgraph.graph.GraphConstants;
import org.jgraph.graph.GraphContext;
import org.jgraph.graph.VertexRenderer;
import org.jgraph.graph.VertexView;

/**
 * Creates a diamond shaped graph cell. Correctly calculates perimeter, and
 * maintains shape when size is changed. Does NOT handle borders, or resize
 * correctly (loses square shape) when a group is resized
 *  
 */
public class JGraphDiamondView extends VertexView {

	final JGraphDiamondRenderer renderer = new JGraphDiamondRenderer(this);

	public JGraphDiamondView(Object cell, JGraph graph, CellMapper mapper) {
		super(cell, graph, mapper);
	}

	public Point2D getPerimeterPoint(Point2D source, Point2D p) {
		Point2D center = getCenterPoint();
		double halfwidth = getBounds().getWidth() / 2;
		Point2D top = new Point2D.Double(center.getX(), center.getY() - halfwidth);
		Point2D bottom = new Point2D.Double(center.getX(), center.getY() + halfwidth);
		Point2D left = new Point2D.Double(center.getX() - halfwidth, center.getY());
		Point2D right = new Point2D.Double(center.getX() + halfwidth, center.getY());
		// Special case for intersecting the diamond's points
		if (center.getX() == p.getX())
			if (center.getY() > p.getY()) // top point
				return (top);
			else
				// bottom point
				return (bottom);
		if (center.getY() == p.getY())
			if (center.getX() > p.getX()) // left point
				return (left);
			else
				// right point
				return (right);
		// In which quadrant will the intersection be?
		// set the slope and offset of the border line accordingly
		Point2D i;
		if (p.getX() < center.getX())
			if (p.getY() < center.getY())
				i = intersection(p, center, top, left);
			else
				i = intersection(p, center, bottom, left);
		else if (p.getY() < center.getY())
			i = intersection(p, center, top, right);
		else
			i = intersection(p, center, bottom, right);
		return i;
	}

	/**
	 * Find the point of intersection of two straight lines (which follow the
	 * equation y=mx+b) one line is an incoming edge and the other is one side
	 * of the diamond.
	 */
	private Point2D intersection(Point2D lineOneStart, Point2D lineOneEnd,
			Point2D lineTwoStart, Point2D lineTwoEnd) {
		// m = delta y / delta x, the slope of a line
		// b = y - mx, the axis intercept
		double m1 = (double) (lineOneEnd.getY() - lineOneStart.getY())
				/ (double) (lineOneEnd.getX() - lineOneStart.getX());
		double b1 = lineOneStart.getY() - m1 * lineOneStart.getX();
		double m2 = (double) (lineTwoEnd.getY() - lineTwoStart.getY())
				/ (double) (lineTwoEnd.getX() - lineTwoStart.getX());
		double b2 = lineTwoStart.getY() - m2 * lineTwoStart.getX();
		double xinter = (b1 - b2) / (m2 - m1);
		double yinter = m1 * xinter + b1;
		Point2D intersection = getAttributes().createPoint(xinter, yinter);
		return intersection;
	}

	public CellViewRenderer getRenderer() {
		return renderer;
	}

	/**
	 * Returns a cell handle for the view, if the graph and the view are
	 * sizeable.
	 */
	public CellHandle getHandle(GraphContext context) {
		if (GraphConstants.isSizeable(getAllAttributes())
				&& context.getGraph().isSizeable())
			return new JGraphDiamondSizeHandle(this, context);
		return null;
	}

	public static class JGraphDiamondRenderer extends VertexRenderer {

		JGraphDiamondRenderer(JGraphDiamondView view) {
			super();
		}

		public void paint(Graphics g) {
			// TODO this doesn't draw the border
			int b = borderWidth;
			Graphics2D g2 = (Graphics2D) g;
			Dimension d = getSize();
			boolean tmp = selected;
			// construct the diamond
			int size = d.width / 2;
			int width = d.width - b; // allow for border
			int halfWidth = (d.width - b) / 2;
			int[] xpoints = {halfWidth, width, halfWidth, 0};
			int[] ypoints = {0, halfWidth, width, halfWidth};
			Polygon diamond = new Polygon(xpoints, ypoints, 4);
			if (super.isOpaque()) {
				g.setColor(super.getBackground());
				if (gradientColor != null && !preview) {
					setOpaque(false);
					g2.setPaint(new GradientPaint(0, 0, getBackground(), getWidth(),
							getHeight(), gradientColor, true));
				}
				g.fillPolygon(diamond);
			}
			try {
				setBorder(null);
				setOpaque(false);
				selected = false;
				super.paint(g);
			} finally {
				selected = tmp;
			}
			if (bordercolor != null) {
				g.setColor(bordercolor);
				g2.setStroke(new BasicStroke(b));
				g.drawPolygon(diamond);
			}
			if (selected) {
				g2.setStroke(GraphConstants.SELECTION_STROKE);
				g.setColor(graph.getHighlightColor());
				g.drawPolygon(diamond);
			}
		}

		protected void paintBorder(Graphics g) {
			// TODO This needs to be implemented to paint a non-rectangular
			// border
			super.paintBorder(g);
		}
	} // end of DiamondRenderer

	public static class JGraphDiamondSizeHandle extends SizeHandle {

		public JGraphDiamondSizeHandle(VertexView arg0, GraphContext arg1) {
			super(arg0, arg1);
		}

		// maintain equal height and width to keep diamond shape
		// TODO this doesn't have effect when a group is expanding
		protected Rectangle2D computeBounds(MouseEvent event) {
			Rectangle2D r = super.computeBounds(event);
			if (r.getHeight() > r.getWidth())
				r.setFrame(r.getX(), r.getY(), r.getHeight(), r.getHeight());
			if (r.getWidth() > r.getHeight())
				r.setFrame(r.getX(), r.getY(), r.getWidth(), r.getWidth());
			return r;
		}
	}// end of DiamondSizeHandle
}