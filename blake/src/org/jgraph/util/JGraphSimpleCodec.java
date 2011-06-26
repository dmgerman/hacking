/*
 * @(#)JGraphGXLCodec.java 1.0 12-MAY-2004
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

import java.io.DataInputStream;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.Set;
import java.util.StringTokenizer;

import org.jgraph.JGraph;
import org.jgraph.graph.ConnectionSet;
import org.jgraph.graph.DefaultEdge;
import org.jgraph.graph.DefaultGraphCell;
import org.jgraph.graph.DefaultPort;


/**
 * @author Gaudenz Alder
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Generation - Code and Comments
 */
public class JGraphSimpleCodec {

	//
	// Simple Format a:b[:edgelabel]
	//
	// Eg. a triange:
	// a:b             /\B 
	// b:c            /  \
	// c:a:ac       A/_ac_\C
	//

	public static void decode(
			JGraph graph,
			InputStream fstream,
			String delim,
			String edgeLabel) throws Exception
	{
		// Convert our input stream to a
		// DataInputStream
		DataInputStream in = new DataInputStream(fstream);

		// Continue to read lines while
		// there are still some left to read
		// Map from keys to vertices
		Hashtable map = new Hashtable();
		// Link to Existing Vertices!
		Object[] items = JGraphUtilities.getVertices(graph, JGraphUtilities.getAll(graph));
		if (items != null) {
			for (int i = 0; i < items.length; i++)
				if (items[i] != null && items[i].toString() != null) {
					map.put(items[i].toString(), items[i]);
				}
		}
		// Vertices and Edges to insert
		Hashtable adj = new Hashtable();
		java.util.List insert = new ArrayList();
		ConnectionSet cs = new ConnectionSet();
		while (in.available() != 0) {
			// Print file line to screen
			String s = in.readLine();
			StringTokenizer st = new StringTokenizer(s, delim);
			if (st.hasMoreTokens()) {
				String srckey = st.nextToken().trim();
				// Get or create source vertex
				Object source = getVertexForKey(map, srckey);
				if (!graph.getModel().contains(source)
					&& !insert.contains(source))
					insert.add(source);
				if (st.hasMoreTokens()) {
					String tgtkey = st.nextToken().trim();
					// Get or create source vertex
					Object target = getVertexForKey(map, tgtkey);
					if (!graph.getModel().contains(target)
						&& !insert.contains(target))
						insert.add(target);
					// Create and insert Edge
					Set neighbours = (Set) adj.get(srckey);
					if (neighbours == null) {
						neighbours = new HashSet();
						adj.put(srckey, neighbours);
					}
					String label =
						(st.hasMoreTokens())
							? st.nextToken().trim()
							: edgeLabel;
					if (!(neighbours.contains(tgtkey))) {
						Object edge =
							new DefaultEdge(label);
						Object sourcePort =
							graph.getModel().getChild(source, 0);
						Object targetPort =
							graph.getModel().getChild(target, 0);
						if (sourcePort != null && targetPort != null) {
							cs.connect(edge, sourcePort, targetPort);
							insert.add(edge);
							neighbours.add(tgtkey);
						}
					}
				}
			}
		}
		in.close();
		graph.getModel().insert(insert.toArray(), null, cs, null, null);
	}

	public static Object getVertexForKey(Hashtable map, String key) {
		Object cell = map.get(key);
		if (cell == null) {
			DefaultGraphCell dgc =
				new DefaultGraphCell(key);
			dgc.add(new DefaultPort());
			cell = dgc;
			map.put(key, cell);
		}
		return cell;
	}
	
}
