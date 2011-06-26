/*
 * @(#)IconExample.java 1.0 28-SEPT-04
 * 
 * Copyright (c) 2001-2004, Dean Mao All rights reserved.
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

package org.jgraph.cellview;

import java.awt.Color;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;

import javax.swing.Icon;
import javax.swing.JComponent;
import javax.swing.JEditorPane;
import javax.swing.JLabel;
import javax.swing.UIManager;

import org.jgraph.JGraph;
import org.jgraph.graph.CellMapper;
import org.jgraph.graph.CellView;
import org.jgraph.graph.CellViewRenderer;
import org.jgraph.graph.GraphCellEditor;
import org.jgraph.graph.GraphConstants;
import org.jgraph.graph.VertexView;


/**
   * The cell view modifies the center point of the vertex such that it is
   * relative to the icon rather than the entire vertex. The perimeter
   * 
   * @author Dean Mao
   * @created Sep 28, 2004
   */
  public class JGraphIconView extends VertexView {
    private MyMultiLinedEditor editor = new MyMultiLinedEditor();

    protected static IconRenderer viewRenderer = new IconRenderer();

    public JGraphIconView(Object cell, JGraph jgraph, CellMapper cm) {
      super(cell, jgraph, cm);
    }

    public GraphCellEditor getEditor() {
      return editor;
    }

    private boolean isMouseOver;

    /**
     * The mouse over boolean is here so that we could potentially render the
     * icon differently when the mouse is hovering above the vertex.
     * 
     * @return
     */
    public boolean isMouseOver() {
      return isMouseOver;
    }

    public void setMouseOver(boolean isMouseOver) {
      this.isMouseOver = isMouseOver;
    }

    /**
     * The center point of the vertex should be in the middle of the icon
     * instead of the middle of the icon/description duo. The reason we must
     * calculate this is so that edges know where to point. We want to make the
     * edges look like they are pointing to an icon from an icon.
     */
    public Point2D getCenterPoint() {
      Dimension dim = ((IconRenderer) this.getRendererComponent(this.getGraph(), false, false, false)).getIconDisplay()
          .getPreferredSize();
      return getAttributes().createPoint(getBounds().getX() + dim.getWidth() / 2,
          getBounds().getY() + dim.getHeight() / 2);
    }

    /**
     * We don't want to calculate a perimeter point around the entire vertex.
     * Only the perimeter around the icon will be calculated. This calculation
     * is generic for elliptical perimeters.
     */
    public Point2D getPerimeterPoint(Point2D source, Point2D p) {
      Rectangle2D bounds = this.getBounds();

      Icon icon = GraphConstants.getIcon(getAllAttributes());
      double iconWidth = icon.getIconWidth();
      double iconHeight = icon.getIconHeight();

      double x = bounds.getX();
      double y = bounds.getY();
      double a = iconWidth / 2;
      double b = iconHeight / 2;
      double eccentricity = Math.sqrt(1 - ((b / a) * (b / a)));

      double width = bounds.getWidth();
      double height = viewRenderer.getIconDisplay().getPreferredSize().getHeight();

      double xCenter = (x + (width / 2));
      double yCenter = (y + (height / 2));
      double dx = p.getX() - xCenter;
      double dy = p.getY() - yCenter;

      double theta = Math.atan2(dy, dx);
      double eSquared = eccentricity * eccentricity;
      double rPrime = a * Math.sqrt((1 - eSquared) / (1 - (eSquared * (Math.cos(theta) * Math.cos(theta)))));

      double ex = rPrime * Math.cos(theta);
      double ey = rPrime * Math.sin(theta);

      return new Point2D.Double(ex + xCenter, ey + yCenter);
    }

    public CellViewRenderer getRenderer() {
      return viewRenderer;
    }

    class MyMultiLinedEditor extends JGraphMultilineView.MultiLinedEditor {
      /**
       * We offset the multi-lined editor by the height of the icon so that the
       * multi-lined editor appears directly over the description text that we
       * are editing.
       */
      public Component getGraphCellEditorComponent(JGraph graph, Object cell, boolean isSelected) {
        Component component = super.getGraphCellEditorComponent(graph, cell, isSelected);
        Dimension dim = ((IconRenderer) JGraphIconView.this.getRendererComponent(graph, false, false, false))
            .getIconDisplay().getPreferredSize();
        offsetY = (int) dim.getHeight();
        return component;
      }
    }

	/**
	   * This is a combination renderer that displays both an icon and a description
	   * under the icon. The description is html rendered so that it can be
	   * multi-lined.
	   * 
	   * @author Dean Mao
	   * @created Sep 28, 2004
	   */
	  public static class IconRenderer extends JComponent implements CellViewRenderer {
	    private IconDisplay iconDisplay;
	
	    private DescriptionTextArea textRenderer;
	
	    public IconRenderer() {
	      super();
	      iconDisplay = new IconDisplay();
	      textRenderer = new DescriptionTextArea("text/html", "");
	      textRenderer.setOpaque(true);
	      iconDisplay.setOpaque(false);
	
	      GridBagLayout gbl = new GridBagLayout();
	      setLayout(gbl);
	
	      GridBagConstraints defaultRendererConstraint = new GridBagConstraints();
	      defaultRendererConstraint.gridx = 0;
	      defaultRendererConstraint.gridy = 0;
	      defaultRendererConstraint.gridwidth = 1;
	      defaultRendererConstraint.gridheight = 1;
	      defaultRendererConstraint.weightx = 1;
	      defaultRendererConstraint.weighty = 0;
	      defaultRendererConstraint.fill = GridBagConstraints.HORIZONTAL;
	
	      // add icon renderer:
	      gbl.setConstraints(iconDisplay, defaultRendererConstraint);
	      this.add(iconDisplay);
	
	      GridBagConstraints textRendererConstraint = new GridBagConstraints();
	      textRendererConstraint.gridx = 0;
	      textRendererConstraint.gridy = 1;
	      textRendererConstraint.gridwidth = 1;
	      textRendererConstraint.gridheight = GridBagConstraints.REMAINDER;
	      textRendererConstraint.weightx = 1;
	      textRendererConstraint.weighty = 1;
	      textRendererConstraint.fill = GridBagConstraints.BOTH;
	      textRendererConstraint.insets = new Insets(3, 3, 3, 3);
	
	      // add description renderer:
	      gbl.setConstraints(textRenderer, textRendererConstraint);
	      this.add(textRenderer);
	    }
	
	    public Dimension getPreferredSize() {
	      Dimension dim = super.getPreferredSize();
	      dim.setSize(dim.getWidth() + 40, dim.getHeight());
	      return dim;
	    }
	
	    private JGraphIconView view;
	
	    private boolean isSelected;
	
	    private boolean isFocused;
	
	    private boolean isPreview;
	
	    public java.awt.Component getRendererComponent(JGraph graph, CellView view, boolean sel, boolean focus,
	        boolean preview) {
	      if (view instanceof JGraphIconView) {
	        if (graph.getEditingCell() != view.getCell()) {
	          setBackground(Color.white);
	        }
	
	        this.view = (JGraphIconView) view;
	        this.isSelected = sel;
	        this.isFocused = focus;
	        this.isPreview = preview;
	
	        iconDisplay.setIcon(GraphConstants.getIcon(view.getAllAttributes()));
	        textRenderer.setDescription(graph.convertValueToString(view));
	        return this;
	      }
	      return null;
	    }
	
	    public JGraphIconView getView() {
	      return this.view;
	    }
	
	    public boolean isSelected() {
	      return this.isSelected;
	    }
	
	    public boolean isFocused() {
	      return this.isFocused;
	    }
	
	    public boolean isPreview() {
	      return this.isPreview;
	    }
	
	    public IconDisplay getIconDisplay() {
	      return this.iconDisplay;
	    }
	  }

	/**
	   * This JComponent only displays an icon as the upper part of the
	   * icon/description duo.
	   * 
	   * @author Dean Mao
	   * @created Sep 28, 2004
	   */
	  public static class IconDisplay extends JLabel {
	    public IconDisplay() {
	      super();
	      setVerticalAlignment(JLabel.CENTER);
	      setHorizontalAlignment(JLabel.CENTER);
	      setHorizontalTextPosition(JLabel.CENTER);
	      setVerticalTextPosition(JLabel.BOTTOM);
	      setFont(UIManager.getFont("Tree.font"));
	      setForeground(UIManager.getColor("Tree.textForeground"));
	      setBackground(UIManager.getColor("Tree.textBackground"));
	    }
	
	    public Dimension getMinimumSize() {
	      Dimension dim = super.getMinimumSize();
	      dim.setSize(dim.getWidth(), dim.getHeight() + 2);
	      return dim;
	    }
	
	    public Dimension getPreferredSize() {
	      return this.getMinimumSize();
	    }
	
	    public void paint(Graphics g) {
	      setBackground(Color.white);
	      setBorder(null);
	
	      // preview mode is "true" when we are dragging the component in the graph
	      if (!((IconRenderer) this.getParent()).isPreview()) {
	        // paint the icon only in preview mode.
	        super.paint(g);
	      } else {
	        // This is how we will paint the component when we are in preview
	        // mode (dragging component around).
	        g.setColor(Color.BLACK);
	        Dimension d = getSize();
	        g.drawOval((int) (d.width / 2 - 20), (int) (d.height / 2 - 20), 40, 40);
	      }
	    }
	  }

	/**
	   * This JComponent only displays html renderered text as the lower part of the
	   * icon/description duo.
	   * 
	   * @author Dean Mao
	   * @created Sep 28, 2004
	   */
	  public static class DescriptionTextArea extends JEditorPane {
	    public DescriptionTextArea(String type, String text) {
	      super(type, text);
	    }
	
	    private String description;
	
	    public void setDescription(String description) {
	      this.description = description;
	      setText(this.description);
	    }
	
	    public void setText(String text) {
	      // display only the description if not blank
	      if (text != null && !text.equals("")) {
	        // make new lines appear as line breaks in the html renderered text
	        text = text.replaceAll("\n", "<br>");
	        super.setText("<center><font color=\"#337733\" face=Arial size=-1>" + text + "</font></center>");
	      } else {
	        super.setText("");
	      }
	    }
	  }
  }