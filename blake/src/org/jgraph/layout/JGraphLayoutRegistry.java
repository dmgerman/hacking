/*
 * @(#)JGraphLayoutRegistry.java 1.0 18-MAY-2004
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

import java.util.ArrayList;

/**
 * @author Gaudenz Alder
 *
 * Allows to maintain a list of layout algorithms. Contains all
 * default algorithms that ship with this package. This is
 * a singleton class.
 */
public class JGraphLayoutRegistry {
	
	/**
	 * Contains the shared registry instance
	 */
	protected static JGraphLayoutRegistry sharedJGraphLayoutRegistry = new JGraphLayoutRegistry();
	
	/**
	 * Class initialization
	 */
	static {
		// Register Local Layouts
		sharedJGraphLayoutRegistry.add(new AnnealingLayoutAlgorithm());
		sharedJGraphLayoutRegistry.add(new CircleGraphLayout());
		sharedJGraphLayoutRegistry.add(new GEMLayoutAlgorithm(new AnnealingLayoutAlgorithm(true)));
		sharedJGraphLayoutRegistry.add(new MoenLayoutAlgorithm());
		sharedJGraphLayoutRegistry.add(new RadialTreeLayoutAlgorithm());
		sharedJGraphLayoutRegistry.add(new SpringEmbeddedLayoutAlgorithm());
		sharedJGraphLayoutRegistry.add(new SugiyamaLayoutAlgorithm());
		sharedJGraphLayoutRegistry.add(new TreeLayoutAlgorithm());
	}
	
	/**
	 * Returns the current registry (singleton)
	 */
	public static JGraphLayoutRegistry getSharedJGraphLayoutRegistry() {
		return sharedJGraphLayoutRegistry;
	}

	/**
	 * Contains the registered layouts
	 */
	protected ArrayList layouts = new ArrayList();
	
	/**
	 * Register a new Layout
	 */
	public void add(JGraphLayoutAlgorithm layout) {
		layouts.add(layout);
	}
	
	/**
	 * @return Returns the layouts.
	 */
	public ArrayList getLayouts() {
		return layouts;
	}

}
