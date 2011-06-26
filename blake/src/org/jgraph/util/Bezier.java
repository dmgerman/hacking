/* This code is PUBLIC DOMAIN */
package org.jgraph.util;

import java.awt.Point;
import java.awt.geom.Point2D;

/**
 * Interpolates given points by a bezier curve. The first
 * and the last two points are interpolated by a quadratic
 * bezier curve; the other points by a cubic bezier curve.
 * 
 * Let p a list of given points and b the calculated bezier points,
 * then one get the whole curve by:
 * 
 * sharedPath.moveTo(p[0])
 * sharedPath.quadTo(b[0].x, b[0].getY(), p[1].x, p[1].getY());
 * 
 * for(int i = 2; i < p.length - 1; i++ ) {
 *    Point b0 = b[2*i-3];
 *	  Point b1 = b[2*i-2];
 *	  sharedPath.curveTo(b0.x, b0.getY(), b1.x, b1.getY(), p[i].x, p[i].getY());
 * }
 * 
 * sharedPath.quadTo(b[b.length-1].x, b[b.length-1].getY(), p[n - 1].x, p[n - 1].getY());
 * 
 * @author krueger
 */
public class Bezier {

	private static final float AP = 0.5f;
	private Point2D[] bPoints;

	/**
	 * Creates a new Bezier curve.
	 * @param points
	 */
	public Bezier(Point2D[] points) {
		int n = points.length;
		if (n < 3) {
			bPoints = new Point[1];
		} else {
			bPoints = new Point[2 * (n - 2)];
		}

		for (int i = 0; i < n - 2; i++) {
			Point2D pa = points[i];
			Point2D pb = points[i + 1];
			Point2D pc = points[i + 2];
			Point2D.Double ab = new Point2D.Double(pb.getX() - pa.getX(), pb.getY() - pa.getY());
			Point2D.Double ac = new Point2D.Double(pc.getX() - pa.getX(), pc.getY() - pa.getY());
			double lac = Math.sqrt(ac.getX() * ac.getX() + ac.getY() * ac.getY());
			ac.setLocation(ac.getX() / lac, ac.getY() / lac);

			double proj = ab.getX() * ac.getX() + ab.getY() * ac.getY();
			proj = proj < 0 ? -proj : proj;
			Point2D.Float ap = new Point2D.Float();
			ap.setLocation(proj * ac.getX(), proj * ac.getY());

			Point2D.Double p1 =
				new Point2D.Double(pb.getX() - AP * ap.getX(), pb.getY() - AP * ap.getY());
			bPoints[2 * i] = new Point((int) p1.getX(), (int) p1.getY());

			ac.setLocation(-ac.getX(), -ac.getY());
			Point2D.Double cb = new Point2D.Double(pb.getX() - pc.getX(), pb.getY() - pc.getY());
			proj = cb.getX() * ac.getX() + cb.getY() * ac.getY();
			proj = proj < 0 ? -proj : proj;
			ap.setLocation(proj * ac.getX(), proj * ac.getY());

			Point2D.Double p2 =
				new Point2D.Double(pb.getX() - AP * ap.getX(), pb.getY() - AP * ap.getY());
			bPoints[2 * i + 1] = new Point((int) p2.getX(), (int) p2.getY());
		}
	}

	/**
	 * Returns the calculated bezier points.
	 * @return
	 */
	public Point2D[] getPoints() {
		return bPoints;
	}

	/**
	 * Returns the number of bezier points.
	 * @return
	 */
	public int getPointCount() {
		return bPoints.length;
	}

	/**
	 * Returns the bezier points at position i.
	 * @param i
	 * @return
	 */
	public Point2D getPoint(int i) {
		return bPoints[i];
	}

}
