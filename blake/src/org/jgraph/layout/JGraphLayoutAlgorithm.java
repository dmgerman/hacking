/*
 * @(#)JGraphLayoutAlgorithm.java 1.0 18-MAY-2004
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
package org.jgraph.layout;

import java.awt.BorderLayout;
import java.awt.Component;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.geom.Rectangle2D;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.Map;
import java.util.Set;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JPanel;

import org.jgraph.JGraph;
import org.jgraph.graph.CellView;
import org.jgraph.graph.GraphConstants;
import org.jgraph.graph.GraphLayoutCache;
import org.jgraph.graph.VertexView;

/**
 *
 */
public abstract class JGraphLayoutAlgorithm {

	/**
	 * @return
	 */
	protected static Set LAYOUT_ATTRIBUTES = new HashSet();
	
	/**
	 * @return
	 */
	static {
		LAYOUT_ATTRIBUTES.add(GraphConstants.BOUNDS);
		LAYOUT_ATTRIBUTES.add(GraphConstants.POINTS);
		LAYOUT_ATTRIBUTES.add(GraphConstants.LABELPOSITION);
		LAYOUT_ATTRIBUTES.add(GraphConstants.ROUTING);
	}
	
	/**
	 * Set to false if the algorithm should terminate immediately
	 */
	boolean isAllowedToRun = true;
	
	/**
	 * Set to non zero if you want to indicate progress
	 */
	int progress = 0, maximumProgress = 0;

	/**
	 * Subclassers may return a new JComponent that
	 * allows to configure the layout. The default
	 * implementation returns <code>null</code>.<br>
	 * Note: Settings creation may be expensive so
	 * the UI should cache the values returned by
	 * this method.
	 */
	public JGraphLayoutSettings createSettings() {
		return null;
	}
	
	/**
	 * Get a human readable hint for using this layout.
	 */
	public String getHint() {
		return "";
	}
	
	/**
	 * Call run with step = 0;
	 */
	public void run(JGraph graph, Object[] cells) {
		run(graph, cells, 0);
	}
	
	/**
	 * Executes the layout algorithm.
	 */
	public abstract void run(JGraph jgraph, Object[] cells, int step);

	/**
	 * @return Returns the isAllowedToRun.
	 */
	public boolean isAllowedToRun() {
		return isAllowedToRun;
	}
	/**
	 * @param isAllowedToRun The isAllowedToRun to set.
	 */
	public void setAllowedToRun(boolean isAllowedToRun) {
		this.isAllowedToRun = isAllowedToRun;
	}
	
	/**
	 * Returns the maximum progress
	 */
	public int getMaximumProgress() {
		return maximumProgress;
	}

	/**
	 * Sets the maximum progress.
	 */
	public void setMaximumProgress(int maximumProgress) {
		this.maximumProgress = maximumProgress;
	}

	/**
	 * Returns the current progress
	 */
	public int getProgress() {
		return progress;
	}

	/**
	 * @param progress The progress to set.
	 */
	public void setProgress(int progress) {
		this.progress = progress;
	}

	/**
	 * A utility method to create a simple dialog with
	 * close and apply button.
	 */
	public static JDialog createDialog(final JGraphLayoutSettings settings, 
				JFrame parent, String title, String close, String apply)
	{
		if (settings instanceof Component)
			return populateDialog(settings, new JDialog(parent, title, true), close, apply);
		return null;
	}
	
	/**
	 * A utility method to create a simple dialog with
	 * close and apply button.
	 */
	public static JDialog createDialog(final JGraphLayoutSettings settings, 
				JDialog parent, String title, String close, String apply)
	{
		if (settings instanceof Component)
			return populateDialog(settings, new JDialog(parent, title, true), close, apply);
		return null;
	}
	
	/**
	 * A utility method to create a simple dialog with
	 * close and apply button.
	 */
	public static JDialog populateDialog(final JGraphLayoutSettings settings, 
				final JDialog dialog, String close, String apply)
	{
		if (dialog != null && settings instanceof Component) {
			dialog.getContentPane().setLayout(new BorderLayout());
			dialog.getContentPane().add((Component) settings, BorderLayout.CENTER);
			JButton cancelButton = new JButton(close);
			cancelButton.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					dialog.dispose();
				}
			});
			JButton applyButton = new JButton(apply);
			applyButton.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					settings.apply();
					dialog.dispose();
				}
			});
			JPanel buttonPanel = new JPanel(new FlowLayout(FlowLayout.RIGHT));
			buttonPanel.add(applyButton);
			buttonPanel.add(cancelButton);
			dialog.getContentPane().add(buttonPanel, BorderLayout.SOUTH);
			dialog.getRootPane().setDefaultButton(applyButton);
			return dialog;
		}
		return dialog;
	}

	/**
	 * @return
	 */
	public static void applyLayout(JGraph sourceGraph, Object[] cells, JGraphLayoutAlgorithm layout) {
		JGraph localGraph = new JGraph(sourceGraph.getModel());
		localGraph.setBounds(sourceGraph.getBounds());
		GraphLayoutCache cache = localGraph.getGraphLayoutCache();
		cache.setLocalAttributes(LAYOUT_ATTRIBUTES);
		layout.run(localGraph, cells);
		if (layout.isAllowedToRun()) {
			// fetch attributes from cellview and write to source Graph
			Map nested = new Hashtable();
			CellView[] cellViews = cache.getAllDescendants(cache.getRoots());
			for (int i = 0; i < cellViews.length; i++) {
				Map attrs = cellViews[i].getAttributes();
				Rectangle2D bounds = GraphConstants.getBounds(attrs);
				if (cellViews[i] instanceof VertexView && bounds == null) {
					//System.out.println("Collecting layout data:
					// bounds="+cellViews[i].getBounds());
					GraphConstants.setBounds(attrs, cellViews[i].getBounds());
				}
				if (!attrs.isEmpty())
					nested.put(cellViews[i].getCell(), attrs);
			}
			if (!nested.isEmpty())
				sourceGraph.getGraphLayoutCache().edit(nested, null, null, null);
		}
	}
	
	
}
