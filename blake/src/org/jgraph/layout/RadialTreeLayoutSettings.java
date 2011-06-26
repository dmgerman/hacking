/*
 * @(#)TreeLayoutSettings.java 1.0 12-JUL-2004
 * 
 * Copyright (c) 2004, Gaudenz Alder
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
import java.awt.GridLayout;
import java.util.Properties;

import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;


/**
 * A Dialog for configuring a TreeLayoutAlgorithm.
 * You can use horizontal and vertical spacing.<br>
 *<br>
 *<br>
 * @author Gaudenz Alder<br>
 * @version 1.0 init
 */
public class RadialTreeLayoutSettings extends JPanel implements JGraphLayoutSettings {

	protected RadialTreeLayoutAlgorithm layout;
	
    private JTextField widthTextField = new JTextField(),
    				   heightTextField = new JTextField(),
    				   radiusXTextField = new JTextField(),
					   radiusYTextField = new JTextField(),
					   centerXTextField = new JTextField(),
					   centerYTextField = new JTextField();

    /**
     * Creates new form SugiyamaLayoutConfigurationDialog
     */
    public RadialTreeLayoutSettings(RadialTreeLayoutAlgorithm layout) {
    	this.layout = layout;
        JPanel jPanel1 = new javax.swing.JPanel(new GridLayout(6,2,4,4));
        jPanel1.add(new JLabel("Width"));
        jPanel1.add(widthTextField);
        jPanel1.add(new JLabel("Height"));
        jPanel1.add(heightTextField);
        // XOr
        jPanel1.add(new JLabel("Radius X"));
        jPanel1.add(radiusXTextField);
        jPanel1.add(new JLabel("Radius Y"));
        jPanel1.add(radiusYTextField);
        jPanel1.add(new JLabel("Center X"));
        jPanel1.add(centerXTextField);
        jPanel1.add(new JLabel("Center Y"));
        jPanel1.add(centerYTextField);
        add(jPanel1, BorderLayout.CENTER);
        revert();
    }
    
	/**
	 * Implementation.
	 */
	public void revert() {
		widthTextField.setText(String.valueOf(layout.WIDTH));
		heightTextField.setText(String.valueOf(layout.HEIGHT));
		if (layout.WIDTH == 0) {
			centerXTextField.setText(String.valueOf(layout.ROOTX));
			radiusXTextField.setText(String.valueOf(layout.RADIUSX));
		} else {
			centerXTextField.setText("0");
			radiusXTextField.setText("0");
		}
		if (layout.HEIGHT == 0) {
			centerYTextField.setText(String.valueOf(layout.ROOTY));
			radiusYTextField.setText(String.valueOf(layout.RADIUSY));
		} else {
			centerYTextField.setText("0");
			radiusYTextField.setText("0");
		}
	}
    
    private void check() {
        try {
        	Double.parseDouble(widthTextField.getText());
        	Double.parseDouble(heightTextField.getText());
        	Double.parseDouble(centerXTextField.getText());
        	Double.parseDouble(centerYTextField.getText());
        	Double.parseDouble(radiusXTextField.getText());
        	Double.parseDouble(radiusYTextField.getText());
        } catch (Exception e) {
            throw new IllegalArgumentException(e.getMessage());
        }
    }
	
	/**
	 * Implementation.
	 */
	public void apply() {
		check();
		Properties props = new Properties();
		props.put(RadialTreeLayoutAlgorithm.KEY_WIDTH, widthTextField.getText());
		props.put(RadialTreeLayoutAlgorithm.KEY_HEIGHT, heightTextField.getText());
		props.put(RadialTreeLayoutAlgorithm.KEY_CENTRE_X, centerXTextField.getText());
		props.put(RadialTreeLayoutAlgorithm.KEY_CENTRE_Y, centerYTextField.getText());
		props.put(RadialTreeLayoutAlgorithm.KEY_RADIUS_X, radiusXTextField.getText());
		props.put(RadialTreeLayoutAlgorithm.KEY_RADIUS_Y, radiusYTextField.getText());
		layout.setConfiguration(props);
	}

}

