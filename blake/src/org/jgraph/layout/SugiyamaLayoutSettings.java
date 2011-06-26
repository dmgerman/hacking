/*
 * @(#)SugiyamaLayoutSettings.java 1.0 12-JUL-2004
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

import java.awt.GridLayout;

import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;


/**
 * A Dialog for configuring a SugiyamaLayoutAlgorithm.
 * You can use horizontal and vertical spacing.<br>
 * <br>
 * Will be shown by the SugiyamaLayoutController.<br>
 *<br>
 *<br>
 * @author Gaudenz Alder<br>
 * @version 1.0 init
 */
public class SugiyamaLayoutSettings extends JPanel implements JGraphLayoutSettings {

	protected SugiyamaLayoutAlgorithm layout;
	
    private JTextField verticalSpacingTextField = new JTextField(),
					   horizontalSpacingTextField = new JTextField();

    /**
     * Creates new form SugiyamaLayoutConfigurationDialog
     */
    public SugiyamaLayoutSettings(SugiyamaLayoutAlgorithm layout) {
    	this.layout = layout;
        JPanel jPanel1 = new javax.swing.JPanel(new GridLayout(2,2));
        jPanel1.add(new JLabel("Horizontal Spacing"));
        jPanel1.add(horizontalSpacingTextField);
        jPanel1.add(new JLabel("Vertical Spacing"));
        jPanel1.add(verticalSpacingTextField);
        add(jPanel1, java.awt.BorderLayout.CENTER);
        revert();
    }
    
    public void revert() {
    	horizontalSpacingTextField.setText(String.valueOf(layout.spacing.x));
    	verticalSpacingTextField.setText(String.valueOf(layout.spacing.y));
    }
    
	/**
	 * Implementation.
	 */
	public void apply() {
		check();
		layout.spacing.x = Integer.parseInt(getIndention());
		layout.spacing.y = Integer.parseInt(getVerticalSpacing());
	}
    
    private void check() {
        try {
            Integer.parseInt(horizontalSpacingTextField.getText());
            Integer.parseInt(verticalSpacingTextField.getText());
        } catch (Exception e) {
            throw new IllegalArgumentException(e.getMessage());
        }
    }
	
    /**
     * Returns the value of the "Horizontal spacing" as text.
     */
    public String getIndention() {
        return horizontalSpacingTextField.getText().trim();
    }
    /**
     * Set the value of the "Horizontal spacing" text field.
     */
    public void setIndention(String text) {
        horizontalSpacingTextField.setText(text);
    }
    
    /**
     * Returns the value of the "Vertical spacing" as text.
     */
    public String getVerticalSpacing() {
        return verticalSpacingTextField.getText().trim();
    }
        
    /**
     * Set the value of the "Vertical Spacing" text field.
     */
    public void setVerticalSpacing(String text) {
        verticalSpacingTextField.setText(text);
    }

}

