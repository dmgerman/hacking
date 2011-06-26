/*
 * Created on 16.10.2004
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package org.jgraph.util;

import java.awt.event.ActionEvent;
import java.awt.geom.Rectangle2D;

import org.jgraph.JGraph;
import org.jgraph.cellview.JGraphEllipseView;
import org.jgraph.graph.CellView;

/**
 * @author Gaudenz Alder
 * 
 * TODO To change the template for this generated type comment go to Window -
 * Preferences - Java - Code Style - Code Templates
 */
public class JGraphImageMapEncoder {

	/**
	 * Override or implement to map from cells to urls.
	 * 
	 * @param cell
	 *            Cell that should be converted to a URL
	 * @return String String that can be used as a href
	 */
	public boolean isURL(Object url) {
		return (url != null && (url.toString().startsWith("http:")
				|| url.toString().startsWith("mailto:")
				|| url.toString().startsWith("ftp:")
				|| url.toString().startsWith("telnet:")
				|| url.toString().startsWith("gopher:")
				|| url.toString().startsWith("file:")
				|| url.toString().startsWith("https:") || url.toString()
				.startsWith("webdav:")));
	}

	/**
	 * Override or implement to map from cells to urls.
	 * 
	 * @param cell
	 *            Cell that should be converted to a URL
	 * @return String String that can be used as a href
	 */
	public String getURL(JGraph graph, Object cell) {
		String url = getLabel(graph, cell);
		if (isURL(url))
			return url.toString();
		return "";
	}

	/**
	 * Override or implement to map from cells to labels.
	 * 
	 * @param cell
	 *            Cell that should be converted to a label
	 * @return String String that can be used as a label
	 */
	public String getLabel(JGraph graph, Object cell) {
		return graph.convertValueToString(cell.toString());
	}

	/**
	 * Use &lt;img src="yourimage.png" border="0" ismap usemap="#map"&gt;
	 * in your HTML markup to refer to this image map.
	 * @see java.awt.event.ActionListener#actionPerformed(ActionEvent)
	 */
	public String encode(JGraph graph, String mapName) {
		if (graph.getModel().getRootCount() > 0) {
			String html = "<map NAME=\""+mapName+"\">\n";
			Rectangle2D bounds = graph.getCellBounds(graph.getRoots());
			Object[] vertices = JGraphUtilities.getAll(graph);
			for (int i = 0; i < vertices.length; i++) {
				String alt = getLabel(graph, vertices[i]);
				String href = getURL(graph, vertices[i]);
				CellView view = graph.getGraphLayoutCache().getMapping(
						vertices[i], false);
				if (view != null && href != null && href.length() > 0) {
					Rectangle2D b = (Rectangle2D) graph
							.toScreen((Rectangle2D) ((Rectangle2D) view
									.getBounds()).clone());
					b.setFrame(b.getX() - bounds.getX() + 5, b.getY()
							- bounds.getY() + 5, b.getWidth(), b.getHeight());
					String rect = (int) b.getX() + "," + (int) b.getY() + ","
							+ (int) (b.getX() + b.getWidth()) + ","
							+ (int) (b.getY() + b.getHeight());
					String shape = (view instanceof JGraphEllipseView) ? "circle"
							: "rect";
					String map = "<area shape=" + shape + " coords=\"" + rect
							+ "\" href=\"" + href + "\" alt=\"" + alt + "\">\n";
					html += map;
				} // if view != null
			} // for
			html += "</map>";
			return html;
		} // if img != null
		return null;
	}

}