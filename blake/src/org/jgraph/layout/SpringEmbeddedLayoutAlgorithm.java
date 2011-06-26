/*
 * Copyright (c) 2004, Jeremy Jedynak, NetCentric Technology Inc All rights reserved.
 *
 * Copyright (c) 2004, Sven Luzar All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *  - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer. - Redistributions in
 * binary form must reproduce the above copyright notice, this list of
 * conditions and the following disclaimer in the documentation and/or other
 * materials provided with the distribution. - Neither the name of JGraph nor
 * the names of its contributors may be used to endorse or promote products
 * derived from this software without specific prior written permission.
 *
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
 *
 */
package org.jgraph.layout;

import java.awt.Rectangle;
import java.awt.geom.Rectangle2D;
import java.util.ArrayList;
import java.util.Hashtable;
import java.util.List;
import java.util.Map;
import java.util.Random;

import org.jgraph.JGraph;
import org.jgraph.graph.AttributeMap;
import org.jgraph.graph.CellView;
import org.jgraph.graph.EdgeView;
import org.jgraph.graph.GraphConstants;
import org.jgraph.graph.GraphLayoutCache;
import org.jgraph.graph.GraphModel;
import org.jgraph.graph.PortView;
import org.jgraph.graph.VertexView;

/**
 * Arranges the nodes with the Spring Embedded Layout Algorithm. <br>
 * 
 * The algorithm takes O(|V|^2 * |E|) time.
 * 
 * Jeremy Jedynak NetCentric Technology Inc www.NetCentricInc.com
 * 
 * <br>
 * 
 * This layout algorithm is derived from the one written by Sven Luzar. It fixes
 * a bug in how the "u" and "v" vectors were stored and retrieved, which
 * frequently caused IllegalArgumentExceptions and NullPointerExceptions,
 * depending upon your luck.
 * 
 * <br>
 * 
 * Also, the original run method has been broken into several methods. Two new
 * constructors and methods were added to support two constraints: the graph
 * rendering frame and maxIterations. Most variable names have been modified for
 * readability.
 * 
 * <br>
 * 
 * It now properly lays out the graph according to the algorithm. Work still
 * needs to be done to better space vertices so that they do not overlap and so
 * that edges do not pass through vertices. The new "step" parameter of the run
 * method is currently not used. All that being said, this is a good starting
 * point to understand the algorithm and make those changes.
 * 
 * <br>
 * <br>
 * 
 * @author <a href="mailto:Jeremy.Jedynak@NetCentricInc.com">Jeremy Jedynak </a>
 * @author <a href="mailto:Sven.Luzar@web.de">Sven Luzar </a>
 * @since 1.2.2
 * @version 1.0 init
 */
public class SpringEmbeddedLayoutAlgorithm extends JGraphLayoutAlgorithm {
	/**
	 * Key for an attribute. The value for this key is a Rectangle object and
	 * specifies the disposement.
	 */
	public static final String SPRING_EMBEDDED_DISP = "SpringEmbeddedDisp";

	/**
	 * Key for an attribute. The value for this key is a Rectangle object and
	 * specifies the calculated position.
	 */
	public static final String SPRING_EMBEDDED_POS = "SpringEmbeddedPos";

	private Rectangle myFrame = null;

	private int myMaxIterations = -1;

	public SpringEmbeddedLayoutAlgorithm() {
		myFrame = new Rectangle(0, 0, 320, 200);
		myMaxIterations = 100;
	}

	public SpringEmbeddedLayoutAlgorithm(Rectangle frame, int maxIterations) {
		if (frame == null) {
			throw new IllegalArgumentException("frame may not be null");
		}
		if (frame.width <= 0) {
			throw new IllegalArgumentException("frame width must be positive");
		}

		if (frame.height <= 0) {
			throw new IllegalArgumentException("frame height must be positive");
		} else {
			myFrame = frame;
		}

		if (maxIterations < 0) {
			throw new IllegalArgumentException(
					"maxIterations must be a positive integer");
		} else {
			myMaxIterations = maxIterations;
		}
	}

	public void setFrame(Rectangle frame) {
		if (frame == null) {
			throw new IllegalArgumentException("Frame may not be null");
		} else if (frame.width <= 0) {
			throw new IllegalArgumentException("frame width must be positive");
		} else if (frame.height <= 0) {
			throw new IllegalArgumentException("frame height must be positive");
		}

		myFrame = frame;
	}

	/**
	 * Returns the name of this algorithm in human readable form.
	 */
	public String toString() {
		return "Spring Embedded";
	}

	public void setMaxIterations(int maxIterations) {
		if (maxIterations < 0) {
			throw new IllegalArgumentException(
					"maxIterations must be a positive integer");
		}

		myMaxIterations = maxIterations;
	}

	/**
	 * The implementation of the layout algorithm.
	 * 
	 * @see LayoutAlgorithm
	 *  
	 */

	public void run(JGraph jgraph, Object[] cells, int step) {
		GraphLayoutCache layoutCache = jgraph.getGraphLayoutCache();

		//---------------------------------------------------------------------------
		// initial work
		//---------------------------------------------------------------------------

		List Vertices = new ArrayList(); // Vertices
		List Edges = new ArrayList(); // Edges

		int maxVertexWidth = 20; // unused

		CellView[] cellviews = layoutCache.getMapping(cells, false);

		//System.out.println( " Number of Cells = " + cellviews.length ) ;

		this.partitionCells(cellviews, Vertices, Edges);

		//System.out.println( " Number of Vertices = " + Vertices.size() ) ;
		//System.out.println( " Number of Edges = " + Edges.size() ) ;

		double FrameWidth = myFrame.getWidth(); // Width of the selectionFrame
		double FrameHeight = myFrame.getHeight(); // Height of the
												  // selectionFrame
		double FrameArea = FrameWidth * FrameHeight; // area of the
													 // selectionFrame

		//System.out.println( " W = " + FrameWidth ) ;
		//System.out.println( " H = " + FrameHeight ) ;
		//System.out.println( " Area = " + FrameArea ) ;

		this.randomizeVertexPositions(Vertices);

		//---------------------------------------------------------------------------
		// start the iterations
		//---------------------------------------------------------------------------

		// calculate the field length for the area
		double AreaFieldLength = Math.sqrt((FrameArea)
				/ ((double) Vertices.size()));

		for (int Loop = 0; Loop < myMaxIterations; Loop++) {
			this.calculateRepulsiveForces(Vertices, AreaFieldLength);

			this.calculateAttractiveForces(Edges, AreaFieldLength);

			this.calculateNewPositions(Vertices, Loop);
		}

		Rectangle calculatedFrame = this.calculateNewFrame(Vertices);

		// calculate the stretch factor and the movement factor
		// to fit the calculated frame to the selected Frame
		double stretchX = ((double) myFrame.width)
				/ ((double) calculatedFrame.width);
		double stretchY = ((double) myFrame.width)
				/ ((double) calculatedFrame.width);
		int movementX = myFrame.x - calculatedFrame.x;
		int movementY = myFrame.y - calculatedFrame.y;

		Map viewMap = this.drawGraph(layoutCache.getMapping(cells, false),
				jgraph.getModel(), movementX, stretchX, movementY, stretchY);

		layoutCache.edit(viewMap, null, null, null);
	}

	private void partitionCells(CellView[] cells, List vertices, List edges) {
		// Partition the list of cells into list of vertices and list of edges
		for (int Loop = 0; Loop < cells.length; Loop++) {
			CellView cell = cells[Loop];

			if (cell == null) {
				// Skip over null cells
				continue;
			} else if (cell instanceof EdgeView) {
				EdgeView edge = (EdgeView) cell;
				edges.add(edge);
			} else if (cell instanceof VertexView) {
				VertexView vertex = (VertexView) cell;

				vertices.add(vertex);

				// find the maximum & minimum coordinates
				Rectangle2D rect = vertex.getBounds();
				Rectangle vertBounds = new Rectangle((int) rect.getX(),
						(int) rect.getY(), (int) rect.getWidth(), (int) rect
								.getHeight()); //vertView.getBounds();

				if (vertBounds.x < myFrame.x) {
					myFrame.x = vertBounds.x;
				}

				if (vertBounds.y < myFrame.y) {
					myFrame.y = vertBounds.y;

				}

				/*
				 * if( vertBounds.width > maxVertexWidth ) { maxVertexWidth =
				 * vertViewBounds.width ; }
				 */

				int width = vertBounds.x - myFrame.x;
				if (width > myFrame.width) {
					myFrame.width = width;
				}

				int height = vertBounds.y - vertBounds.y;
				if (height > vertBounds.height) {
					vertBounds.height = height;
				}

			}
		}
	}

	private void randomizeVertexPositions(List vertices) {
		// Fill the initial positions with random positions
		Random random = new Random();
		for (int Loop = 0; Loop < vertices.size(); Loop++) {
			VertexView vertex = (VertexView) vertices.get(Loop);

			int vertW = (int) vertex.getBounds().getWidth();
			int vertH = (int) vertex.getBounds().getHeight();

			int frameW = myFrame.width;
			int frameH = myFrame.height;

			int newX = random.nextInt(frameW);
			int newY = random.nextInt(frameH);

			Rectangle randomPosition = new Rectangle(newX, newY, vertW, vertH);

			//System.out.println( "vertex update: " + Loop + " : rand = " +
			// randomPosition ) ;

			this.updateVertexPosition(vertex, SPRING_EMBEDDED_POS,
					randomPosition);
		}
	}

	private void calculateRepulsiveForces(List Vertices, double AreaFieldLength) {
		//---------------------------------------------------------------------------
		// calculate the repulsive forces
		//---------------------------------------------------------------------------

		// calculate the repulsive forces
		for (int vCount = 0; vCount < Vertices.size(); vCount++) {
			VertexView v = (VertexView) Vertices.get(vCount);

			Rectangle vPos = this.getVertexPosition(v, SPRING_EMBEDDED_POS);

			//System.out.println( "vertex " + Loop + " get: vPos = " + vPos ) ;

			// each vertex has two vectors: pos and disp
			Rectangle vDisp = new Rectangle(0, 0);
			for (int uCount = 0; uCount < Vertices.size(); uCount++) {
				VertexView u = (VertexView) Vertices.get(uCount);

				if (u != v) {
					// delta is short hand for the difference
					// vector between the positions of the two vertices

					Rectangle uPos = this.getVertexPosition(u,
							SPRING_EMBEDDED_POS);

					//System.out.println( "vertex " + uCount + " get: uPos = "
					// + uPos ) ;

					Rectangle delta = new Rectangle();
					delta.x = vPos.x - uPos.x;
					delta.y = vPos.y - uPos.y;

					double fr = fr(norm(delta), AreaFieldLength);
					double deltaNormX = delta.x / norm(delta);
					double dispX = deltaNormX * fr;
					double deltaNormY = delta.y / norm(delta);
					double dispY = deltaNormY * fr;

					vDisp.x = vDisp.x + (int) dispX;
					vDisp.y = vDisp.y + (int) dispY;
				}
			}

			//System.out.println( "vertex " + Loop + " update: vDisp = " +
			// vDisp ) ;

			this.updateVertexPosition(v, SPRING_EMBEDDED_DISP, vDisp);
		}
	}

	private void calculateAttractiveForces(List Edges, double AreaFieldLength) {
		//---------------------------------------------------------------------------
		// calculate the attractive forces
		//---------------------------------------------------------------------------

		for (int cellCount = 0; cellCount < Edges.size(); cellCount++) {
			EdgeView e = (EdgeView) Edges.get(cellCount);
			if (e.getSource() != null && e.getTarget() != null
					&& e.getSource() != e.getTarget()) {
				// extract the used fields
				CellView v = (CellView) ((PortView) e.getSource())
						.getParentView();
				CellView u = (CellView) ((PortView) e.getTarget())
						.getParentView();

				if (v == u) {
					continue;
				}

				Rectangle vPos = this.getVertexPosition(v, SPRING_EMBEDDED_POS);
				Rectangle uPos = this.getVertexPosition(u, SPRING_EMBEDDED_POS);

				//System.out.println( "vertex get: vPos = " + vPos ) ;
				//System.out.println( "vertex get: uPos = " + uPos ) ;

				if (vPos == null || uPos == null) {
					continue;
				}

				Rectangle vDisp = this.getVertexPosition(v,
						SPRING_EMBEDDED_DISP);
				Rectangle uDisp = this.getVertexPosition(u,
						SPRING_EMBEDDED_DISP);

				//System.out.println( "vertex get: vDisp = " + vDisp ) ;
				//System.out.println( "vertex get: uDisp = " + uDisp ) ;

				if (vDisp == null || uDisp == null) {
					continue;
				}

				// calculate the delta
				Rectangle delta = new Rectangle();
				delta.x = vPos.x - uPos.x;
				delta.y = vPos.y - uPos.y;

				// calculate the attractive forces
				double fa = fa(norm(delta), AreaFieldLength);
				double deltaNormX = delta.x / norm(delta);
				double deltaNormY = delta.y / norm(delta);
				double dispX = deltaNormX * fa;
				double dispY = deltaNormY * fa;

				vDisp.x = vDisp.x - (int) dispX;
				vDisp.y = vDisp.y - (int) dispY;
				uDisp.x = uDisp.x + (int) dispX;
				uDisp.y = uDisp.y + (int) dispY;

				//System.out.println( "cell update: vDisp = " + vDisp ) ;
				//System.out.println( "cell update: uDisp = " + uDisp ) ;

				// store the new values
				this.updateVertexPosition(v, SPRING_EMBEDDED_DISP, vDisp);
				this.updateVertexPosition(u, SPRING_EMBEDDED_DISP, uDisp);
			}
		}
	}

	private void calculateNewPositions(List Vertices, int curIteration) {
		//---------------------------------------------------------------------------
		// calculate the new positions
		//---------------------------------------------------------------------------

		// limit the maximum displacement to the temperature buttonText
		// and then prevent from being displacement outside frame
		double Temperature = Math.sqrt(Math.pow(myFrame.width, 2)
				+ Math.pow(myFrame.height, 2))
				* ((((double) myMaxIterations) / ((double) (curIteration + 1))) / ((double) myMaxIterations));

		for (int vCount = 0; vCount < Vertices.size(); vCount++) {
			VertexView v = (VertexView) Vertices.get(vCount);
			Rectangle vDisp = this.getVertexPosition(v, SPRING_EMBEDDED_DISP);
			Rectangle vPos = this.getVertexPosition(v, SPRING_EMBEDDED_POS);

			//System.out.println( "vertex get: vDisp = " + vDisp ) ;
			//System.out.println( "vertex get: vPos = " + vPos ) ;

			double dispNormX = vDisp.x / norm(vDisp);
			double minX = Math.min(Math.abs(vDisp.x), Temperature);

			double dispNormY = vDisp.y / norm(vDisp);
			double minY = Math.min(Math.abs(vDisp.y), Temperature);

			vPos.x = (int) (vPos.x + dispNormX * minX);
			vPos.y = (int) (vPos.y + dispNormY * minY);

			/*
			 * double maxX = Math.max(-W / 2, vPos.x); double maxY = Math.max(-L /
			 * 2, vPos.y); double minX2 = Math.min(W / 2, maxX); double minY2 =
			 * Math.min(L / 2, maxY); vPos.x = (int)minX2; vPos.y = (int)minY2;
			 */

			//System.out.println( "cell update: vPos = " + vPos ) ;
			this.updateVertexPosition(v, SPRING_EMBEDDED_POS, vPos);
		}
	}

	private Rectangle calculateNewFrame(List Vertices) {
		// find the new positions for the
		// calculated frame
		Rectangle calculatedFrame = new Rectangle();
		for (int vCount = 0; vCount < Vertices.size(); vCount++) {
			VertexView v = (VertexView) Vertices.get(vCount);
			Rectangle vPos = this.getVertexPosition(v, SPRING_EMBEDDED_POS);

			//System.out.println( "vertex get: vPos = " + vPos ) ;

			if (vPos.x < calculatedFrame.x) {
				calculatedFrame.x = vPos.x;
			}
			if (vPos.y < calculatedFrame.y) {
				calculatedFrame.y = vPos.y;
			}

			int width = vPos.x - calculatedFrame.x;
			if (width > calculatedFrame.width) {
				calculatedFrame.width = width;
			}

			int height = vPos.y - calculatedFrame.y;
			if (height > calculatedFrame.height) {
				calculatedFrame.height = height;
			}
		}

		return (calculatedFrame);
	}

	private Map drawGraph(CellView[] cells, GraphModel model, int movementX,
			double stretchX, int movementY, double stretchY) {
		//---------------------------------------------------------------------------
		// draw the graph
		//---------------------------------------------------------------------------
		Map viewMap = new Hashtable();
		for (int Loop = 0; Loop < cells.length; Loop++) {
			CellView cell = cells[Loop];

			if (cell == null) {
				continue;
			} else if (cell instanceof EdgeView) {
				cell.update();
			} else if (cell instanceof VertexView) {
				// get the current view object
				VertexView vertex = (VertexView) cell;

				// remove the temp objects
				Rectangle newPosition = this.removeVertexPosition(vertex,
						SPRING_EMBEDDED_POS);
				this.removeVertexPosition(vertex, SPRING_EMBEDDED_DISP);

				//System.out.println( "vertex " + Loop + " newPosition = " +
				// newPosition ) ;

				// update the location to get the correct
				newPosition.x = (int) ((newPosition.x + movementX) * stretchX);
				newPosition.y = (int) ((newPosition.y + movementY) * stretchY);

				// update the view
				AttributeMap vertAttrib = new AttributeMap();
				GraphConstants.setBounds(vertAttrib, newPosition);
				vertex.setAttributes(vertAttrib);
				// The statement above fixes a bug in the original code

				viewMap.put(cells[Loop], vertAttrib);
			}
		}

		return (viewMap);
	}

	private void updateVertexPosition(CellView vert, String PosField,
			Rectangle Position) {
		AttributeMap vertAttrib = vert.getAllAttributes();

		vertAttrib.put(PosField, Position);

		/*
		 * There is no contractual guarantee that the Attribute Map returned by
		 * CellView.getAllAttributes() or (especially) CellView.getAttributes()
		 * is the same Attribute Map stored within the VertexView, so a
		 * seemingly redundant call to CellView.setAttributes msut be made
		 * below. This fixes a bug in the original code.
		 */

		vert.setAttributes(vertAttrib);
	}

	private Rectangle getVertexPosition(CellView vert, String PosField) {
		AttributeMap vertAttrib = vert.getAllAttributes();

		Rectangle Result = (Rectangle) vertAttrib.get(PosField);

		return (Result);
	}

	private Rectangle removeVertexPosition(CellView vert, String PosField) {
		AttributeMap vertAttrib = vert.getAllAttributes();

		Rectangle Result = (Rectangle) vertAttrib.remove(PosField);

		/*
		 * There is no contractual guarantee that the Attribute Map returned by
		 * CellView.getAllAttributes() or (especially) CellView.getAttributes()
		 * is the same Attribute Map stored within the VertexView, so a
		 * seemingly redundant call to CellView.setAttributes msut be made
		 * below. This fixes a bug in the original code.
		 */

		vert.setAttributes(vertAttrib);

		return (Result);
	}

	/**
	 * calculates the attractive forces
	 */
	protected double fa(double x, double k) {
		double force = (x * x / k);
		return force;
	}

	/**
	 * calculates the repulsive forces
	 */
	protected double fr(double x, double k) {
		double force = (k * k) / x;
		return force;
	}

	/**
	 * Calculates the euklidische Norm for the point p.
	 *  
	 */
	protected double norm(Rectangle p) {
		double x = p.x;
		double y = p.y;
		double norm = Math.sqrt(x * x + y * y);
		return norm;
	}
}