/* This code is PUBLIC DOMAIN */
package org.jgraph.util;

import java.awt.geom.Point2D;

/**
 * Interpolates points given in the 2D plane. The resulting spline
 * is a function s: R -> R^2 with parameter t in [0,1].
 * 
 * @author krueger
 */
public class Spline2D {

	private double[] t;
	private Spline splineX;
	private Spline splineY;
	private double length;
	
	/**
	 * Creates a new Spline2D.
	 * @param points
	 */
	public Spline2D(Point2D[] points) {
		double[] x = new double[points.length];
		double[] y = new double[points.length];
		
		for(int i = 0; i< points.length; i++) {
			x[i] = points[i].getX();
			y[i] = points[i].getY(); 
		}
		
		init(x, y);
	}

	/**
	 * Creates a new Spline2D.
	 * @param x
	 * @param y
	 */
	public Spline2D(double[] x, double[] y) {
		init(x, y);
	}

	private void init(double[] x, double[] y) {
		if (x.length != y.length) {
			throw new IllegalArgumentException("Arrays must have the same length."); //$NON-NLS-1$
		}
		
		t = new double[x.length];
		for (int i = 0; i < t.length; i++) {
			if (i == 0) {
				t[0] = 0;
			} else {
				double lx = x[i] - x[i-1];
				double ly = y[i] - y[i-1];
				t[i] = Math.sqrt(lx*lx+ly*ly);
				length += t[i];
				t[i] += t[i-1];
			}
		}
		
		for(int i = 0; i< t.length; i++) {
			t[i] = t[i] / length;
		}
		
		splineX = new Spline(t, x);
		splineY = new Spline(t, y);
	}

	/**
	 * @param t 0 <= t <= 1
	 */
	public double[] getPoint(double t) {
		double[] result = new double[2];
		result[0] = splineX.getValue(t);
		result[1] = splineY.getValue(t);
		
		return result;
	}
	
	public double getDx(double t) {
		return splineX.getDx(t);
	}
	
	public double getDy(double t) {
		return splineY.getDx(t);
	}
	
	public double getLength() {
		return length;
	}

}
