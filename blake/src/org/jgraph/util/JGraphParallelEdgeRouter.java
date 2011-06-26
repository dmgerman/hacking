/*
 * Created on 12.09.2004
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package org.jgraph.util;

import java.awt.geom.Point2D;

import org.jgraph.graph.Edge;
import org.jgraph.graph.EdgeView;
import org.jgraph.graph.PortView;


public class JGraphParallelEdgeRouter implements Edge.Routing {
	
	public static JGraphParallelEdgeRouter sharedInstance = new JGraphParallelEdgeRouter();
	
    /**
     * The distance between the control point and the middle line.  A larger number will lead to
     * a more "bubbly" appearance of the bezier edges.
     */
    private static final double EDGE_SEPARATION = 25;

    public void route(EdgeView edge, java.util.List points) {
    	if (edge.getSource() == null || edge.getTarget() == null ||
        		edge.getSource().getParentView() == null ||
    			edge.getTarget().getParentView() == null)
        		return;
      Object[] edges = JGraphUtilities.getEdgesBetween(edge.getGraph(), edge.getSource().getParentView().getCell(),
          edge.getTarget().getParentView().getCell());

      // Find the position of the current edge that we are currently routing
      int numEdges = edges.length;
      int position = 0;
      for (int i = 0; i < edges.length; i++) {
        Object e = edges[i];
        if (e == edge.getCell()) {
          position = i;
        }
      }

      // If there is only 1 edge between the two vertices, we don't need this
      // special routing
      if (edges.length < 2) {
        if (points.size() > 2) {
          points.remove(1);
        }
        return;
      }

      // Find the end point positions
      int n = points.size();
      Point2D from = ((PortView) edge.getSource()).getLocation(null);
      Point2D to = ((PortView) edge.getTarget()).getLocation(null);

      if (from != null && to != null) {
        double dy = from.getY() - to.getY();
        double dx = from.getX() - to.getX();

        // calculate mid-point of the main edge
        double midX = Math.min(from.getX(), to.getX()) + Math.abs((from.getX() - to.getX()) / 2);
        double midY = Math.min(from.getY(), to.getY()) + Math.abs((from.getY() - to.getY()) / 2);

        // compute the normal slope.  The normal of a slope is the negative inverse of the original slope.
        double m = (from.getY() - to.getY()) / (from.getX() - to.getX());
        double theta = Math.atan(-1 / m);

        // modify the location of the control point along the axis of the normal using the edge position
        double r = EDGE_SEPARATION * (Math.floor(position/2) + 1);
        if ((position % 2) == 0) {
          r = -r;
        }

        // convert polar coordinates to cartesian and translate axis to the mid-point
        double ex = r * Math.cos(theta) + midX;
        double ey = r * Math.sin(theta) + midY;
        Point2D controlPoint = new Point2D.Double(ex, ey);

        // add the control point to the points list
        if (points.size() == 2) {
          points.add(1, controlPoint);
        } else {
          points.set(1, controlPoint);
        }
      }
    }

}