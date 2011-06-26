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

import javax.swing.JComboBox;
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
public class MoenLayoutSettings extends JPanel implements JGraphLayoutSettings {

	protected MoenLayoutAlgorithm layout;
	
    private JComboBox orientationCombo = new JComboBox(new Object[]{"West-East", "North-South"});
    private JTextField nodeDistanceTextField = new JTextField();
    /**
     * Creates new form SugiyamaLayoutConfigurationDialog
     */
    public MoenLayoutSettings(MoenLayoutAlgorithm layout) {
    	this.layout = layout;
        JPanel jPanel1 = new javax.swing.JPanel(new GridLayout(2,2,4,4));
        jPanel1.add(new JLabel("Orientation"));
        jPanel1.add(orientationCombo);
        jPanel1.add(new JLabel("Node Distance"));
        jPanel1.add(nodeDistanceTextField);
        add(jPanel1, BorderLayout.CENTER);
        revert();
    }
    
	/**
	 * Implementation.
	 */
	public void revert() {
		setOrientation(layout.orientation);
		nodeDistanceTextField.setText(String.valueOf(layout.childParentDistance));
	}
    
    private void check() {
        try {
            Integer.parseInt(nodeDistanceTextField.getText());
        } catch (Exception e) {
            throw new IllegalArgumentException(e.getMessage());
        }
    }
	
	/**
	 * Implementation.
	 */
	public void apply() {
		check();
		layout.orientation = getOrientation();
		layout.childParentDistance = Integer.parseInt(nodeDistanceTextField.getText());
	}
    
    /**
     * Returns the value of the "Vertical spacing" as text.
     */
    public int getOrientation() {
    	int result = MoenLayoutAlgorithm.LEFT_TO_RIGHT;
    	switch (orientationCombo.getSelectedIndex()) {
    		case 1:
    			result = MoenLayoutAlgorithm.UP_TO_DOWN;
    	}
    	return result;
    }
    
    /**
     * Set the value of the "Vertical Spacing" text field.
     */
    public void setOrientation(int orientation) {
    	int index = 0;
    	switch (orientation) {
    		case MoenLayoutAlgorithm.UP_TO_DOWN:
    			index = 1;
    	}
    	orientationCombo.setSelectedIndex(index);
    }

}

