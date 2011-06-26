/*
 * @(#)JGraphHeavyweightRedirector.java 1.0 12-OCT-2004
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

import java.awt.Component;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Point;
import java.awt.Rectangle;
import java.awt.event.MouseEvent;
import java.awt.geom.Rectangle2D;

import javax.swing.JComponent;
import javax.swing.SwingUtilities;
import javax.swing.event.MouseInputAdapter;

import org.jgraph.JGraph;
import org.jgraph.cellview.JGraphHeavyweightView;
import org.jgraph.graph.CellView;

/**
 * @author Gaudenz Alder
 * 
 * TODO To change the template for this generated type comment go to Window -
 * Preferences - Java - Code Style - Code Templates
 */
public class JGraphHeavyweightRedirector extends MouseInputAdapter {

    // catch all mouse events and redispatch them
    public void mouseMoved(MouseEvent e) {
      redispatchMouseEvent(e);
    }

    public void mouseDragged(MouseEvent e) {
      redispatchMouseEvent(e);
    }

    public void mouseClicked(MouseEvent e) {
      redispatchMouseEvent(e);
    }

    public void mouseEntered(MouseEvent e) {
      redispatchMouseEvent(e);
    }

    public void mouseExited(MouseEvent e) {
      redispatchMouseEvent(e);
    }

    public void mousePressed(MouseEvent e) {
      redispatchMouseEvent(e);
    }

    public void mouseReleased(MouseEvent e) {
      redispatchMouseEvent(e);
    }

	private void redispatchMouseEvent(final MouseEvent evt) {
		if (evt.getSource() instanceof JGraph) {
			final JGraph graph = (JGraph) evt.getSource();
			Point containerPoint = evt.getPoint();
			Object cell = graph.getFirstCellForLocation((int) containerPoint.getX(),
					(int) containerPoint.getY());
			if (cell != null) {
				CellView view = graph.getGraphLayoutCache().getMapping(cell, false);
				if (view instanceof JGraphHeavyweightView) {
					Component renderer = view.getRendererComponent(graph,
							false, false, false);
					final Rectangle2D rectBounds = view.getBounds();
					containerPoint.x -= rectBounds.getX();
					containerPoint.y -= rectBounds.getY();
					boolean isContainer = false;
					if (renderer instanceof Container) {
						isContainer = ((Container) renderer)
								.getComponentCount() > 1;
					}
					if (isContainer) {
						// TODO: JScrollPane is a special case
						renderer.setBounds(new Rectangle((int) rectBounds
								.getX(), (int) rectBounds.getY(),
								(int) rectBounds.getWidth(), (int) rectBounds
										.getHeight()));
						if (renderer instanceof JComponent) {	
							((JComponent) renderer).setPreferredSize(new Dimension(
								(int) rectBounds.getWidth(), (int) rectBounds
										.getHeight()));
						}
						// find the component under this point
						renderer = SwingUtilities.getDeepestComponentAt(
								renderer, containerPoint.x, containerPoint.y);

						if (renderer != null) {
							containerPoint.x -= renderer.getLocation().getX();
							containerPoint.y -= renderer.getLocation().getY();
						}

					}
					// redispatch the event
					if (renderer != null) {
						final Component component = renderer;
						final MouseEvent event = new MouseEvent(component, evt
								.getID(), evt.getWhen(), evt.getModifiers(),
								(int) containerPoint.getX(),
								(int) containerPoint.getY(), evt
										.getClickCount(), evt.isPopupTrigger(), evt.getButton());
						SwingUtilities.invokeLater(new Runnable() {
							public void run() {
								component.dispatchEvent(event);
								graph.repaint(new Rectangle((int) rectBounds
										.getX(), (int) rectBounds.getY(),
										(int) rectBounds.getWidth(), (int) rectBounds
												.getHeight()));
							}
						});
					}
				}
			}
			evt.consume();
		}
	}
}

