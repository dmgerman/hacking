/*
 * @(#)AbstractCellView.java	1.0 03-JUL-04
 * 
 * Copyright (c) 2001-2004 Gaudenz Alder
 *  
 */
package org.jgraph.graph;

import java.awt.Component;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map;
import java.util.Stack;

import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.TreeNode;

import org.jgraph.JGraph;

/**
 * The abstract base class for all cell views.
 *
 * @version 1.0 1/3/02
 * @author Gaudenz Alder
 */

public abstract class AbstractCellView implements CellView, Serializable {

	/** Editor for the cell. */
	protected static GraphCellEditor cellEditor = new DefaultGraphCellEditor();

	/** Reference to the graph*/
	protected JGraph graph = null;

	/** Reference to the cell mapper for the view */
	protected CellMapper mapper = null;

	/** Reference to the cell for this view */
	protected Object cell = null;

	/** Cached parent view */
	protected CellView parent = null;

	/** Cached child views. */
	protected java.util.List childViews = new ArrayList();

	/** Cached bounds of all children if vertex is a group */
	protected Rectangle2D groupBounds = DefaultGraphCell.defaultBounds;

	/** Hashtable for attributes. Initially null. */
	protected AttributeMap attributes = createLocalAttributeMap();

	protected AttributeMap allAttributes;

	/**
	 * Constructs a view for the specified model object,
	 * and invokes update on the new instance.
	 *
	 * @param cell reference to the model object
	 */
	public AbstractCellView(Object cell, JGraph graph, CellMapper mapper) {
		this.cell = cell;
		this.graph = graph;
		this.mapper = mapper;
		updateAllAttributes();
	}

	//
	// Data Source
	//

	/**
	 * Returns the graph associated with the view.
	 */
	public JGraph getGraph() {
		return graph;
	}

	/**
	 * Returns the model associated with the view.
	 */
	public GraphModel getModel() {
		return graph.getModel();
	}

	/**
	 * Returns the cell mapper associated with the view.
	 */
	public CellMapper getMapper() {
		return mapper;
	}

	/**
	 * Returns the model object that this view represents.
	 */
	public Object getCell() {
		return cell;
	}

	/**
	 * Create child views and reload properties. Invokes update first.
	 */
	public void refresh(boolean createDependentViews) {
		// Cache Cell Attributes in View
		update();
		// Cache Parent View
		if (mapper != null && getModel() != null) {
			// Create parent only if it's visible in the graph
			Object par = getModel().getParent(cell);
			if (graph.getGraphLayoutCache().isVisible(par)) {
				CellView tmp = mapper.getMapping(par, createDependentViews);
				if (tmp != parent)
					removeFromParent();
				parent = tmp;
			} else if (parent != null) {
				removeFromParent();
				parent = null;
			}
		}
		// Re-load Child Views
		childViews.clear();
		GraphModel model = getModel();
		for (int i = 0; i < model.getChildCount(cell); i++) {
			Object child = model.getChild(cell, i);
			if (graph.getGraphLayoutCache().isVisible(child)) {
				CellView view = mapper.getMapping(child, createDependentViews);
				if (view != null) {
					// Ignore Ports
					if (!model.isPort(child))
						childViews.add(view);
				}
			}
		}
	}

	/**
	 * Update attributes and recurse children.
	 */
	public void update() {
		updateAllAttributes();
		// Notify Parent
		groupBounds = null;
		childUpdated();
	}

	/**
	 * This method implements the merge between the
	 * cell's and the view's attributes. The view's
	 * attributes override the cell's attributes
	 * with one exception.
	 */
	protected void updateAllAttributes() {
		allAttributes = getModel().getAttributes(cell);
		if (allAttributes != null) {
			allAttributes = (AttributeMap) allAttributes.clone();
		} else
			allAttributes = createLocalAttributeMap();
		allAttributes.putAll(attributes);
	}
	
	/**
	 * Default implementation returns an <code>AttributeMap</code>
	 * @return
	 */
	protected AttributeMap createLocalAttributeMap() {
		return new AttributeMap();
	}

	public void childUpdated() {
		if (parent != null)
			parent.childUpdated();
		groupBounds = null;
	}

	//
	// Graph Structure
	//

	/**
	 * Returns the parent view for this view.
	 */
	public CellView getParentView() {
		return parent;
	}

	/**
	 * Returns the child views of this view.
	 */
	public CellView[] getChildViews() {
		CellView[] array = new CellView[childViews.size()];
		childViews.toArray(array);
		return array;
	}

	/**
	 * Returns all views, including descendants that have a parent
	 * in <code>views</code> without the PortViews.
	 * Note: Iterative Implementation using view.getChildViews. This
	 * returns the array in inverse order, ie with the top most
	 * cell view at index 0.
	 */
	public static CellView[] getDescendantViews(CellView[] views) {
		Stack stack = new Stack();
		for (int i = 0; i < views.length; i++)
			stack.add(views[i]);
		ArrayList result = new ArrayList();
		while (!stack.isEmpty()) {
			CellView tmp = (CellView) stack.pop();
			Object[] children = tmp.getChildViews();
			for (int i = 0; i < children.length; i++)
				stack.add(children[i]);
			result.add(tmp);
		}
		CellView[] ret = new CellView[result.size()];
		result.toArray(ret);
		return ret;
	}

	/**
	 * Removes this view from the list of childs of the parent.
	 */
	public void removeFromParent() {
		if (parent instanceof AbstractCellView) {
			java.util.List list = ((AbstractCellView) parent).childViews;
			list.remove(this);
		}
	}

	/**
	 * Returns true if the view is a leaf.
	 */
	public boolean isLeaf() {
		return childViews.isEmpty();
	}

	//
	// View Attributes
	//

	/**
	 * Return the attributes of the view.
	 */
	public AttributeMap getAttributes() {
		return attributes;
	}

	/**
	 * Returns the attributes of the view combined with the
	 * attributes of the corresponding cell. The view's attributes
	 * override the cell's attributes with the same key.
	 */
	public AttributeMap getAllAttributes() {
		return allAttributes;
	}

	/**
	 * Applies <code>change</code> to the attributes of the view
	 * and calls update.
	 */
	public AttributeMap setAttributes(AttributeMap change) {
		AttributeMap undo = attributes.applyMap(change);
		update();
		return undo;
	}

	//
	// View Methods
	//

	/**
	 * Returns the cached bounds for the group if isleaf is false
	 */
	public Rectangle2D getBounds() {
		if (!isLeaf()) {
			if (groupBounds == null)
				updateGroupBounds();
			return groupBounds;
		}
		return null;
	}

	/**
	 * Returns the bounding box for the specified views.
	 */
	public static Rectangle2D getBounds(CellView[] views) {
		if (views != null && views.length > 0) {
			Rectangle2D ret = null;
			for (int i = 0; i < views.length; i++) {
				if (views[i] != null) {
					Rectangle2D r = views[i].getBounds();
					if (r != null) {
						if (ret == null)
							ret = views[i].getAttributes().createRect(r);
						else
							Rectangle2D.union(ret, r, ret);
					}
				}
			}
			return ret;
		}
		return null;
	}

	/**
	 * Sets the bounds of <code>view</code>.
	 * Calls translateView and scaleView.
	 */
	public void setBounds(Rectangle2D bounds) {
		Rectangle2D oldBounds = getBounds();
		Dimension last;
		if (oldBounds == null)
			oldBounds = getAttributes().createRect();
		Point2D p0 = getAttributes().createPoint(oldBounds.getX(), oldBounds.getY());
		Point2D pe = getAttributes().createPoint(bounds.getX(), bounds.getY());
		Rectangle2D localBounds = getAttributes().createRect(bounds);
		if (GraphConstants.isMoveable(getAttributes()) && !pe.equals(p0))
			translate(pe.getX() - p0.getX(), pe.getY() - p0.getY());
		else
			localBounds.setFrame(
				localBounds.getX(),
				localBounds.getY(),
				bounds.getWidth() - pe.getX() + p0.getX(),
				bounds.getHeight() - pe.getY() + p0.getY());
		double lbw = localBounds.getWidth(), lbh = localBounds.getHeight();
		double obw = oldBounds.getWidth(), obh = oldBounds.getHeight();
		if ((lbw != obw || lbh != obh) && obw > 0 && obh > 0)
			scale(lbw / obw, lbh / obh, pe);
	}

	protected void updateGroupBounds() {
		// Note: Prevent infinite recursion by removing
		// child edges that point to their parent.
		CellView[] childViews = getChildViews();
		LinkedList result = new LinkedList();
		for (int i = 0; i < childViews.length; i++)
			if (includeInGroupBounds(childViews[i]))
				result.add(childViews[i]);
		childViews = new CellView[result.size()];
		result.toArray(childViews);
		Rectangle2D r = getBounds(childViews);
		if (GraphConstants.isOpaque(getAllAttributes())) {
			int groupBorder = GraphConstants.getGroupBorder(getAllAttributes());
			r.setFrame(r.getX() - groupBorder, r.getY() - groupBorder, r
					.getWidth()
					+ 2 * groupBorder, r.getHeight() + 2 * groupBorder);
		}
		groupBounds = r;
	}

	private boolean includeInGroupBounds(CellView view) {
		if (view instanceof EdgeView) {
			GraphModel model = graph.getModel();
			EdgeView edgeView = (EdgeView) view;
			if (edgeView.getCell() instanceof DefaultMutableTreeNode) {
				DefaultMutableTreeNode edge = (DefaultMutableTreeNode) edgeView
						.getCell();
				if (model.getSource(edge) instanceof TreeNode) {
					TreeNode source = (TreeNode) model.getSource(edge);
					if (((DefaultMutableTreeNode) source.getParent())
							.isNodeDescendant(edge)) {
						return false;
					}
				}
				if (model.getTarget(edge) instanceof TreeNode) {
					TreeNode target = (TreeNode) model.getTarget(edge);
					if (((DefaultMutableTreeNode) target.getParent())
							.isNodeDescendant(edge)) {
						return false;
					}
				}
			}
		}
		return true;
	}
	
	/**
	 * Translates <code>view</code> (group) by <code>dx, dy</code>.
	 */
	protected void translate(double dx, double dy) {
		if (isLeaf())
			getAttributes().translate(dx, dy);
		else {
			Iterator it = childViews.iterator();
			while (it.hasNext()) {
				Object view = it.next();
				if (view instanceof AbstractCellView) {
					AbstractCellView child = (AbstractCellView) view;
					child.translate(dx, dy);
				}
			}
		}
	}

	/**
	 * Scale <code>view</code> (group) by <code>sx, sy</code>.
	 */
	protected void scale(double sx, double sy, Point2D origin) {
		if (isLeaf())
			getAttributes().scale(sx, sy, origin);
		else {
			Iterator it = childViews.iterator();
			while (it.hasNext()) {
				Object view = it.next();
				if (view instanceof AbstractCellView) {
					AbstractCellView child = (AbstractCellView) view;
					Map attributes = child.getAttributes();
					if (GraphConstants.isSizeable(attributes)
						|| GraphConstants.isAutoSize(attributes))
						child.scale(sx, sy, origin);
				}
			}
		}
	}

	/**
	 * Returns true if the view intersects the given rectangle.
	 */
	public boolean intersects(Graphics g, Rectangle2D rect) {
		if (isLeaf() || GraphConstants.isOpaque(getAllAttributes())) {
			Rectangle2D bounds = getBounds();
			if (bounds != null)
				return bounds.intersects(rect);
		} else { // Check If Children Intersect
			Iterator it = childViews.iterator();
			while (it.hasNext())
				if (((CellView) it.next()).intersects(g, rect))
					return true;
		}
		return false;
	}

	//
	// View Editors
	//

	/**
	 * Returns a renderer component, configured for the view.
	 */
	public Component getRendererComponent(
		JGraph graph,
		boolean selected,
		boolean focus,
		boolean preview) {
		CellViewRenderer cvr = getRenderer();
		if (cvr != null)
			return cvr.getRendererComponent(
				graph,
				this,
				selected,
				focus,
				preview);
		return null;
	}

	public abstract CellViewRenderer getRenderer();

	/**
	 * Returns a cell handle for the view.
	 */
	public abstract CellHandle getHandle(GraphContext context);

	/**
	 * Returns a cell editor for the view.
	 */
	public GraphCellEditor getEditor() {
		return cellEditor;
	}

}
