/*
 * $Id: DBSelectionPanel.java,v 1.2 2004/12/07 17:53:22 bdickie Exp $
 *
 * Repository Explorer and Repository Grapher
 * Copyright (C) 2004 Blake Dickie
 *
 * This program is free software; you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation; either version 2 of the License, or 
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program; if not, write to the Free Software 
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, 
 * MA 02111-1307 USA
 *
 */

package ca.uvic.cs.gold.bdickie.db;

import java.io.*;
import ca.uvic.cs.gold.bdickie.ErrorLog;

/** This is a panel that can be placed in a configuration dialog to select and
 *  configure a db module.  It is important that the containing frame calls the closing
 *  method is it wants the result saved.
 *
 * @author  Blake Dickie
 */
public class DBSelectionPanel extends javax.swing.JPanel {
    private DBOption currentOption;
    private DBOption firstOption;
    private DBConfigPanel innerPanel;
    
    /** Creates new form DBSelectionPanel */
    public DBSelectionPanel() {
        firstOption = DBOption.getInstance();
        initComponents();
        loadDBOptions();
        if (firstOption != null)
            cmbOption.setSelectedItem(firstOption);
    }
    
    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    private void initComponents() {//GEN-BEGIN:initComponents
        panTop = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        cmbOption = new javax.swing.JComboBox();
        panMain = new javax.swing.JPanel();

        setLayout(new java.awt.BorderLayout());

        jLabel1.setText("Avaliable Options:");
        panTop.add(jLabel1);

        cmbOption.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cmbOptionActionPerformed(evt);
            }
        });

        panTop.add(cmbOption);

        add(panTop, java.awt.BorderLayout.NORTH);

        add(panMain, java.awt.BorderLayout.CENTER);

    }//GEN-END:initComponents

    private void cmbOptionActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cmbOptionActionPerformed
        if (cmbOption.getSelectedItem() == null)
            return;
        currentOption = (DBOption)cmbOption.getSelectedItem();
        panMain.removeAll();
        innerPanel = currentOption.getConfigPanel();
        panMain.add(innerPanel);
    }//GEN-LAST:event_cmbOptionActionPerformed
    
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JComboBox cmbOption;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JPanel panMain;
    private javax.swing.JPanel panTop;
    // End of variables declaration//GEN-END:variables
    
    public void closing()
    {
        currentOption.setInstance();
        innerPanel.closing();
    }
    
    private void loadDBOptions() {
        try {
            InputStream in = getClass().getClassLoader().getResourceAsStream("ca/uvic/cs/gold/bdickie/db/DBs.txt");
            if (in == null)
                ErrorLog.reportError("Error loading avaliable databsae engines.", "Unable to find list file.", true);
            BufferedReader input = new BufferedReader(new InputStreamReader(in));
            String line = input.readLine();
            while(line != null)
            {
                try {
                    Class c = Class.forName(line);
                    cmbOption.addItem(c.newInstance());
                } catch (ClassNotFoundException e) {
                    ErrorLog.reportError("Unable to find DB class: " + line, e.getMessage(), false);
                }
                
                line = input.readLine();
            }
        } catch (Exception e) {
            ErrorLog.reportError("Error loading avaliable database engines.", e.getMessage(), true);
        }
    }
}

/* ChangeLog:
 *   $Log: DBSelectionPanel.java,v $
 *   Revision 1.2  2004/12/07 17:53:22  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 *   Revision 1.1  2004/11/01 00:43:33  bdickie
 *   Database backend for file explorer done.
 *
 */
