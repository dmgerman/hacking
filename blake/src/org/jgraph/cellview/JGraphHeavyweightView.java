/*
 * @(#)JGraphHeavyweightView.java 1.0 12-OCT-2004
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
package org.jgraph.cellview;

import java.awt.Component;

import org.jgraph.JGraph;
import org.jgraph.graph.CellMapper;
import org.jgraph.graph.CellView;
import org.jgraph.graph.CellViewRenderer;
import org.jgraph.graph.DefaultGraphCell;
import org.jgraph.graph.VertexView;

/**
 * @author Gaudenz Alder
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class JGraphHeavyweightView extends VertexView {

	public Component component;
	public CellViewRenderer renderer;

	public JGraphHeavyweightView(
		Object cell,
		JGraph graph,
		CellMapper cm) {
		super(cell, graph, cm);
		if (cell instanceof DefaultGraphCell) {
			Object userObject = ((DefaultGraphCell) cell).getUserObject();
			if (userObject instanceof Component) {
				this.component = (Component) userObject;
				this.renderer = new JGraphHeavyweightRenderer();
			}
		}
	}

	public CellViewRenderer getRenderer() {
		if (renderer != null)
			return renderer;
		return super.getRenderer();
	}

	/**
	 * A hook for subclassers to eg. use the border from the attributes:
	 */
	protected Component configureRenderer(Component component) {
		return component;
	}
	
	public class JGraphHeavyweightRenderer implements CellViewRenderer {

		public Component getRendererComponent(
			org.jgraph.JGraph graph,
			CellView view,
			boolean sel,
			boolean focus,
			boolean preview) {
			return configureRenderer(component);
		}

	}

}
