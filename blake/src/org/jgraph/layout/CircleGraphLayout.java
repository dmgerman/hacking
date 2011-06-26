/*
 * @(#)CircleLayoutAlgorithm.java 1.0 18-MAY-2004
 * 
 * Copyright (c) 2004, Gaudenz Alder
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
package org.jgraph.layout;

import java.awt.geom.Rectangle2D;
import java.util.ArrayList;
import java.util.List;

import org.jgraph.JGraph;
import org.jgraph.graph.CellView;
import org.jgraph.graph.VertexView;


/**
 * @author Gaudenz Alder
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Generation - Code and Comments
 */
public class CircleGraphLayout extends JGraphLayoutAlgorithm {
	
	/**
	 * Returns the name of this algorithm in human
	 * readable form.
	 */
	public String toString() {
		return "Simple Circle";
	}
	
	/* (non-Javadoc)
	 * @see java.lang.Runnable#run()
	 */
	public void run(JGraph graph, Object[] cells, int step) {
		// Fetch All Views
		CellView[] views = graph.getGraphLayoutCache().getMapping(cells);
		// Create list to hold vertices
		List vertices = new ArrayList();
		// Maximum width or height
		int max = 0;
		// Loop through all views
		for (int i = 0; i < views.length; i++) {
			// Add vertex to list
			if (views[i] instanceof VertexView) {
				vertices.add(views[i]);
				// Fetch Bounds
				Rectangle2D bounds = views[i].getBounds();
				// Update Maximum
				if (bounds != null)
					max = (int) Math.max(max, 
							Math.max(bounds.getWidth(), bounds.getHeight()));
			}
		}
		// Compute Radius
		int r = (int) Math.max(vertices.size() * max / Math.PI, 100);
		// Compute angle step
		double phi = 2 * Math.PI / vertices.size();
		// Arrange vertices in a circle
		for (int i = 0; i < vertices.size(); i++) {
			Rectangle2D bounds = ((CellView) vertices.get(i)).getBounds();
			// Update Location
			if (bounds != null)
				bounds.setFrame(
					r + r * Math.sin(i * phi),
					r + r * Math.cos(i * phi),
					bounds.getWidth(),
					bounds.getHeight());
		}
	}
	
}
