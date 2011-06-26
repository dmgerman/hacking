/*
 * @(#)JGraphUtilities.java 1.0 12-MAY-2004
 * 
 * Copyright (c) 2001-2004, Gaudenz Alder
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
package org.jgraph.util;

import java.awt.AlphaComposite;
import java.awt.Graphics2D;
import java.awt.Transparency;
import java.awt.color.ColorSpace;
import java.awt.geom.Rectangle2D;
import java.awt.image.BufferedImage;
import java.awt.image.ColorModel;
import java.awt.image.ComponentColorModel;
import java.awt.image.DataBuffer;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;

import javax.swing.SwingConstants;

import org.jgraph.JGraph;
import org.jgraph.algebra.CostFunction;
import org.jgraph.algebra.DefaultCostFunction;
import org.jgraph.algebra.PriorityQueue;
import org.jgraph.algebra.UnionFind;
import org.jgraph.graph.CellView;
import org.jgraph.graph.ConnectionSet;
import org.jgraph.graph.DefaultGraphCell;
import org.jgraph.graph.DefaultGraphModel;
import org.jgraph.graph.GraphConstants;
import org.jgraph.graph.GraphLayoutCache;
import org.jgraph.graph.GraphModel;
import org.jgraph.graph.ParentMap;
import org.jgraph.layout.JGraphLayoutAlgorithm;

/**
 * @author Gaudenz Alder
 * 
 * TODO Add code for BFS and DFS traversal (iterators)
 */
public class JGraphUtilities {
	
	public static final int ALIGN_LEFT = SwingConstants.LEFT;
	
	public static final int ALIGN_RIGHT = SwingConstants.RIGHT;
	
	public static final int ALIGN_TOP = SwingConstants.TOP;
	
	public static final int ALIGN_BOTTOM = SwingConstants.BOTTOM;
	
	public static final int ALIGN_CENTER = SwingConstants.CENTER;
	
	public static final int ALIGN_MIDDLE = SwingConstants.NEXT;

  /**
	 * @return
	 */
	public static BufferedImage toImage(JGraph graph, int inset) {
		Object[] cells = graph.getRoots();
		if (cells.length > 0) {
			Rectangle2D bounds = graph.getCellBounds(cells);
			graph.toScreen(bounds);
			ColorSpace cs = ColorSpace.getInstance(ColorSpace.CS_sRGB);
			ColorModel cm = new ComponentColorModel(cs, false, true,
					Transparency.OPAQUE, DataBuffer.TYPE_BYTE);
			BufferedImage img = new BufferedImage((int) bounds.getWidth() + 2
					* inset, (int) bounds.getHeight() + 2 * inset,
					BufferedImage.TYPE_INT_ARGB);
			Graphics2D graphics = img.createGraphics();
			if (graph.isOpaque()) {
				graphics.setColor(graph.getBackground());
				graphics.fillRect(0, 0, img.getWidth(), img.getHeight());

			} else {
				graphics.setComposite(AlphaComposite.getInstance(
						  AlphaComposite.CLEAR, 0.0f));
				graphics.fillRect(0, 0, img.getWidth(), img.getHeight());
				graphics.setComposite(AlphaComposite.SrcOver);
			}
			graphics.translate((int) (-bounds.getX() + inset), (int) (-bounds
					.getY() + inset));
			boolean tmp = graph.isDoubleBuffered();
			graph.setDoubleBuffered(false);
			graph.paint(graphics);
			graph.setDoubleBuffered(tmp);
			return img;
		}
		return null;
	}
	
	/**
	 * @return
	 */
	public static Object[] getAll(JGraph graph) {
		return graph.getDescendants(graph.getRoots());
	}

	/**
	 * @return
	 */
	public static Object[] getVertices(JGraph graph, Object[] cells) {
		if (cells != null) {
			ArrayList result = new ArrayList();
			GraphModel model = graph.getModel();
			for (int i = 0; i < cells.length; i++) {
				if (!model.isPort(cells[i]) && !model.isEdge(cells[i])
						&& !isGroup(graph, cells[i]))
					result.add(cells[i]);
			}
			return result.toArray();
		}
		return null;
	}

	/**
	 * @return
	 */
	public static Object[] getEdges(JGraph graph) {
		Object[] cells = graph.getDescendants(graph.getRoots());
		if (cells != null) {
			ArrayList result = new ArrayList();
			GraphModel model = graph.getModel();
			for (int i = 0; i < cells.length; i++)
				if (model.isEdge(cells[i]))
					result.add(cells[i]);
			return result.toArray();
		}
		return null;
	}

	/**
	 * @return
	 */
	public static Object[] getEdges(JGraph graph, Object[] cells) {
		if (cells != null) {
			ArrayList result = new ArrayList();
			GraphModel model = graph.getModel();
			for (int i = 0; i < cells.length; i++) {
				if (model.isEdge(cells[i]))
					result.add(cells[i]);
			}
			return result.toArray();
		}
		return null;
	}

	/**
	 * @return
	 */
	public static Object getNeighbour(JGraph graph, Object edge, Object vertex) {
		Object source = getSourceVertex(graph, edge);
		if (vertex == source)
			return getTargetVertex(graph, edge);
		else
			return source;
	}

	/**
	 * @return
	 */
	public static Object getSourceVertex(JGraph graph, Object edge) {
		return DefaultGraphModel.getSourceVertex(graph.getModel(), edge);
	}

	/**
	 * @return
	 */
	public static Object getTargetVertex(JGraph graph, Object edge) {
		return DefaultGraphModel.getTargetVertex(graph.getModel(), edge);
	}

	/**
	 * @return
	 */
	public static boolean isVertex(JGraph graph, Object cell) {
		return !graph.getModel().isEdge(cell) &&
			   !graph.getModel().isPort(cell) &&
			   !isGroup(graph, cell);
	}

	/**
	 * @return
	 */
	public static boolean isGroup(JGraph graph, Object cell) {
		CellView view = graph.getGraphLayoutCache().getMapping(cell, false);
		if (view != null)
			return !view.isLeaf();
		return false;
	}

	/**
	 * @return
	 */
	public static boolean isVertex(GraphModel model, Object cell) {
		return !model.isEdge(cell) &&
			   !model.isPort(cell) &&
			   !isGroup(model, cell);
	}

	/**
	 * @return
	 */
	public static boolean isGroup(GraphModel model, Object cell) {
		for (int i=0; i<model.getChildCount(cell); i++) {
			if (!model.isPort(model.getChild(cell, i)))
				return true;
		}
		return false;
	}
	
	/**
	 * @return
	 */
	public static void connect(JGraph graph, DefaultGraphCell prototype,
			Object[] cells) {
		Object[] v = getVertices(graph, cells);
		if (v != null && v.length < 20) {
			ConnectionSet cs = new ConnectionSet();
			for (int i = 0; i < v.length; i++) {
				for (int j = i + 1; j < v.length; j++) {
					if (!isNeighbour(graph, v[i], v[j])) {
						Object edge = prototype.clone();
						Object sourcePort = graph.getModel().getChild(v[i], 0);
						Object targetPort = graph.getModel().getChild(v[j], 0);
						cs.connect(edge, sourcePort, targetPort);
					}
				}
			}
			if (!cs.isEmpty())
				graph.getGraphLayoutCache().insert(
						cs.getChangedEdges().toArray(), null, cs, null, null);
		} else
			throw new IllegalArgumentException("Too many cells selected");
	}

	/**
	 * Returns true if the given vertices are conntected by a single edge in
	 * this document.
	 */
	public static boolean isNeighbour(JGraph graph, Object v1, Object v2) {
		Object[] edges = getEdgesBetween(graph, v1, v2);
		return (edges != null && edges.length > 0);
	}

	/**
	 * Returns the edges between the specified vertices
	 */
	public static Object[] getEdgesBetween(JGraph graph, Object vertex1,
			Object vertex2) {
		return getEdgesBetween(graph, vertex1, vertex2, false);
	}
	

	/**
	 * Returns the edges between the specified vertices
	 */
	public static Object[] getEdgesBetween(JGraph graph, Object vertex1,
			Object vertex2, boolean directed) {
		ArrayList result = new ArrayList();
		Set edges = DefaultGraphModel.getEdges(graph.getModel(),
				new Object[]{vertex1});
		Iterator it = edges.iterator();
		while (it.hasNext()) {
			Object edge = it.next();
			if (!isGroup(graph, edge)) {
				Object source = getSourceVertex(graph, edge);
				Object target = getTargetVertex(graph, edge);
				if ((source == vertex1 && target == vertex2)
						|| (!directed && source == vertex2 && target == vertex1))
					result.add(edge);
			}
		}
		return result.toArray();
	}

	/**
	 * Returns the edges between the specified ports
	 */
	public static Object[] getEdgesBetweenPorts(JGraph graph, Object port1,
			Object port2) {
		return getEdgesBetweenPorts(graph, port1, port2, false);
	}

	/**
	 * Returns the edges between the specified ports
	 */
	public static Object[] getEdgesBetweenPorts(JGraph graph, Object port1,
			Object port2, boolean directed) {
		ArrayList result = new ArrayList();
		Set edges = DefaultGraphModel.getEdges(graph.getModel(),
				new Object[]{port1});
		Iterator it = edges.iterator();
		while (it.hasNext()) {
			Object edge = it.next();
			if (!isGroup(graph, edge)) {
				Object source = graph.getModel().getSource(edge);
				Object target = graph.getModel().getTarget(edge);
				if ((source == port1 && target == port2)
						|| (!directed && source == port2 && target == port1))
					result.add(edge);
			}
		}
		return result.toArray();
	}
	
	/**
	 * Returns the incoming edges for cell. Cell should be a
	 * port or a vertex.
	 */
	public static Object[] getFanIn(JGraph graph, Object cell) {
		ArrayList result = new ArrayList();
		GraphModel model = graph.getModel();
		Set edges = DefaultGraphModel.getEdges(model,
				new Object[]{cell});
		Iterator it = edges.iterator();

		while (it.hasNext()) {
			Object edge = it.next();
			if (!isGroup(graph, edge)) {
				Object target = model.getTarget(edge);
				Object parent = model.getParent(target);
				if (target == cell || parent == cell)
					result.add(edge);
			}
		}
		return result.toArray();
	}

	/**
	 * Returns the outgoing edges for cell. Cell should be a
	 * port or a vertex.
	 */
	public static Object[] getFanOut(JGraph graph, Object cell) {
		ArrayList result = new ArrayList();
		GraphModel model = graph.getModel();
		Set edges = DefaultGraphModel.getEdges(model,
				new Object[]{cell});
		Iterator it = edges.iterator();
		while (it.hasNext()) {
			Object edge = it.next();
			if (!isGroup(graph, edge)) {
				Object source = model.getSource(edge);
				Object parent = model.getParent(source);
				if (source == cell || parent == cell)
					result.add(edge);
			}
		}
		return result.toArray();
	}
	
	/**
	 * @return
	 */
	public static CostFunction createDefaultCostFunction() {
		return new DefaultCostFunction();
	}

	/**
	 * @return
	 */
	public static UnionFind getComponents(JGraph graph) {
		UnionFind uf = new UnionFind();
		// Vertices
		Object[] v = getVertices(graph, getAll(graph));
		for (int i = 0; i < v.length; i++)
			uf.find(v[i]);
		// Edges
		Object[] e = getEdges(graph);
		for (int i = 0; i < e.length; i++) {
			Object source = getSourceVertex(graph, e[i]);
			Object target = getTargetVertex(graph, e[i]);
			uf.union(uf.find(source), uf.find(target));
		}
		return uf;
	}

	/**
	 * Returns the ShortestPath. Implemented with the Dijkstra Algorithm
	 */
	public static Object[] getShortestPath(JGraph graph, Object from,
			Object to, CostFunction cf, boolean directed) {
		if (cf == null)
			cf = createDefaultCostFunction();
		GraphModel model = graph.getModel();
		PriorityQueue q = new PriorityQueue();
		Hashtable pred = new Hashtable();
		q.setPrio(from, 0);
		// Main Loop
		int jmax = getVertices(graph, getAll(graph)).length;
		for (int j = 0; j < jmax; j++) {
			double prio = q.getPrio();
			Object obj = q.pop();
			if (obj == to)
				break;
			Object[] tmp = new Object[]{obj};
			Object[] e = (directed) ? getFanOut(graph, tmp) : getEdges(graph, tmp);  
			if (e != null) {
				for (int i = 0; i < e.length; i++) {
					Object neighbour = getNeighbour(graph, e[i], obj);
					double newPrio = prio + cf.getCost(graph, e[i]);
					if (neighbour != null && neighbour != obj
							&& newPrio < q.getPrio(neighbour)) {
						pred.put(neighbour, e[i]);
						q.setPrio(neighbour, newPrio);
					}
				}
			}
			if (q.isEmpty())
				break;
		}
		// Return Path-Array
		ArrayList list = new ArrayList();
		Object obj = to;
		while (obj != null) {
			list.add(obj);
			Object edge = pred.get(obj);
			if (edge != null) {
				list.add(edge);
				obj = getNeighbour(graph, edge, obj);
			} else
				obj = null;
		}
		return list.toArray();
	}

	/**
	 * Returns the shortest spanning tree. Implemented with the Kruskal
	 * Algorithm
	 */
	public static Object[] getSpanningTree(JGraph graph, CostFunction cf) {
		if (cf == null)
			cf = createDefaultCostFunction();
		SortedSet edges = sort(graph, getEdges(graph), cf);
		UnionFind uf = new UnionFind();
		HashSet result = new HashSet();
		while (!edges.isEmpty()) {
			Object edge = edges.first();
			edges.remove(edge);
			Object setA, setB;
			setA = uf.find(getSourceVertex(graph, edge));
			setB = uf.find(getTargetVertex(graph, edge));
			if (setA == null || setB == null || setA != setB) {
				uf.union(setA, setB);
				result.add(edge);
			}
		}
		// Create set of vertices
		HashSet v = new HashSet();
		Iterator it = result.iterator();
		while (it.hasNext()) {
			Object edge = it.next();
			Object source = getSourceVertex(graph, edge);
			Object target = getTargetVertex(graph, edge);
			if (source != null)
				v.add(source);
			if (target != null)
				v.add(target);
		}
		Object[] cells = new Object[result.size() + v.size()];
		System.arraycopy(result.toArray(), 0, cells, 0, result.size());
		System.arraycopy(v.toArray(), 0, cells, result.size(), v.size());
		return cells;
	}

	/**
	 * @return
	 */
	public static SortedSet sort(final JGraph graph, Object[] cells,
			final CostFunction cf) {
		TreeSet set = new TreeSet(new Comparator() {

			public int compare(Object o1, Object o2) {
				Double d1 = new Double(cf.getCost(graph, o1));
				Double d2 = new Double(cf.getCost(graph, o2));
				return d1.compareTo(d2);
			}
		});
		for (int i = 0; i < cells.length; i++)
			set.add(cells[i]);
		return set;
	}

	/**
	 * @return
	 */
	public static void editCells(JGraph graph, Object[] cells, Map attrs) {
		if (graph != null && attrs != null && cells != null && cells.length > 0) {
			Map nested = new Hashtable();
			for (int i = 0; i < cells.length; i++)
				nested.put(cells[i], attrs);
			if (!nested.isEmpty())
				graph.getGraphLayoutCache().edit(nested, null, null, null);
		}
	}

	/**
	 * @return
	 */
	public static void removeCells(JGraph graph, Object[] cells) {
		if (graph != null && cells != null && cells.length > 0) {
			cells = graph.getDescendants(cells);
			graph.getGraphLayoutCache().remove(cells);
		}
	}

	/**
	 * @return
	 */
	public static void group(JGraph graph, Object groupCell, Object[] cells) {
		cells = graph.order(cells);
		if (cells != null && cells.length > 0) {
			ParentMap map = new ParentMap();
			for (int i = 0; i < cells.length; i++)
				map.addEntry(cells[i], groupCell);
			Rectangle2D bounds = graph.getCellBounds(cells);
			Hashtable nested = new Hashtable();
			if (bounds != null && !graph.getModel().isEdge(groupCell)) {
				bounds = new Rectangle2D.Double(bounds.getX()+bounds.getWidth()/4,
						bounds.getY()+bounds.getHeight()/4, bounds.getWidth()/2,
						bounds.getHeight()/2);
				Map attrs = new Hashtable();
				GraphConstants.setBounds(attrs, bounds);
				nested.put(groupCell, attrs);
			}
			graph.getGraphLayoutCache().insert(new Object[]{groupCell}, nested,
					null, map, null);
		}
	}

	/**
	 * @return
	 */
	public static void ungroup(JGraph graph, Object[] cells) {
		if (cells != null && cells.length > 0) {
			ArrayList groups = new ArrayList();
			ArrayList children = new ArrayList();
			for (int i = 0; i < cells.length; i++) {
				boolean childExists = false;
				for (int j = 0; j < graph.getModel().getChildCount(cells[i]); j++) {
					Object child = graph.getModel().getChild(cells[i], j);
					if (!graph.getModel().isPort(child)) {
						children.add(child);
						childExists = true;
					}
				}
				if (childExists)
					groups.add(cells[i]);
			}
			graph.getGraphLayoutCache().remove(groups.toArray());
			graph.setSelectionCells(children.toArray());
		}
	}

	/**
	 * @return
	 */
	public static void alignCells(JGraph graph, Object[] cells, int constraint) {
		Rectangle2D bounds = graph.getCellBounds(cells);
		GraphLayoutCache layoutCache = graph.getGraphLayoutCache();
		Map nested = new Hashtable();
		for (int i = 0; i < cells.length; i++) {
			CellView cellView = layoutCache.getMapping(cells[i], false);
			Rectangle2D cellBounds = GraphConstants.getBounds(cellView
					.getAllAttributes());
			if (bounds != null && cellBounds != null) {
				Map attrs = new Hashtable();
				Rectangle2D newBounds = align(constraint, (Rectangle2D) cellBounds.clone(), bounds);
				GraphConstants.setBounds(attrs, newBounds);
				nested.put(cellView.getCell(), attrs);
			}
		}
		if (!nested.isEmpty())
			layoutCache.edit(nested, null, null, null);
	}

	/**
	 * @return
	 */
	public static Rectangle2D align(int constraint, Rectangle2D cellBounds,
			Rectangle2D bounds) {
		switch (constraint) {
			case ALIGN_LEFT :
				cellBounds.setFrame(bounds.getX(), cellBounds.getY(),
						cellBounds.getWidth(), cellBounds.getHeight());
				break;
			case ALIGN_TOP :
				cellBounds.setFrame(cellBounds.getX(), bounds.getY(),
						cellBounds.getWidth(), cellBounds.getHeight());
				break;
			case ALIGN_RIGHT :
				cellBounds.setFrame(bounds.getX() + bounds.getWidth()
						- cellBounds.getWidth(), cellBounds.getY(), cellBounds
						.getWidth(), cellBounds.getHeight());
				break;
			case ALIGN_BOTTOM :
				cellBounds.setFrame(cellBounds.getX(), bounds.getY()
						+ bounds.getHeight() - cellBounds.getHeight(),
						cellBounds.getWidth(), cellBounds.getHeight());
				break;
			case ALIGN_CENTER :
				double cx = bounds.getWidth() / 2;
				cellBounds.setFrame(bounds.getX() + cx - cellBounds.getWidth() / 2, cellBounds.getY(),
									cellBounds.getWidth(), cellBounds.getHeight());
				break;
			case ALIGN_MIDDLE :
				double cy = bounds.getHeight() / 2;
				cellBounds.setFrame(cellBounds.getX(), bounds.getY() + cy - cellBounds.getHeight() / 2,
									cellBounds.getWidth(), cellBounds.getHeight());
				break;				
		}
		return cellBounds;
	}


	/**
	 * @return
	 */
	public static void applyLayout(JGraph sourceGraph, JGraphLayoutAlgorithm layout) {
		Object[] cells = (sourceGraph.isSelectionEmpty()) ? 
				JGraphUtilities.getAll(sourceGraph) : sourceGraph.getSelectionCells();
		JGraphLayoutAlgorithm.applyLayout(sourceGraph, cells, layout);
	}
	
	
	public static void collapseGroups(JGraph graph, Object[] groups) {
		if (groups != null) {
			List cells =
					DefaultGraphModel.getDescendants(graph.getModel(), groups);
			for (int i = 0; i < groups.length; i++)
				cells.remove(groups[i]);
			// Retain child ports
			for (int i = 0; i < groups.length; i++) {
				for (int j = 0;
					j < graph.getModel().getChildCount(groups[i]);
					j++) {
					Object child = graph.getModel().getChild(groups[i], j);
					if (graph.getModel().isPort(child))
						cells.remove(child);
				}
			}
			graph.getGraphLayoutCache().setVisible(cells.toArray(), false);
		}
	}

	public static void expandGroups(JGraph graph, Object[] cells) {
		GraphModel model = graph.getModel();
		Set all = new HashSet();
		if (cells != null) {
			for (int i = 0; i < cells.length; i++) {
				for (int j = 0; j < model.getChildCount(cells[i]); j++)
					all.add(model.getChild(cells[i], j));
			}
			graph.getGraphLayoutCache().setVisible(all.toArray(), true);
		}
	}

}
