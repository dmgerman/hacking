/*
 * $Id: NonEditableTableModel.java,v 1.2 2004/12/07 17:53:23 bdickie Exp $
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

package ca.uvic.cs.gold.bdickie.explorer;

import javax.swing.table.DefaultTableModel;

/** An extension to thhe DefaultTableModel that turns off editting and allows
 *  the specification of the object type in each column.
 *
 * @author  Blake Dickie
 */
public class NonEditableTableModel extends DefaultTableModel {
    private Class[] columnTypes;
    
    /** Creates a new instance of NonEditableTableModel */
    public NonEditableTableModel(String[] columnNames) {
        super(columnNames, 0);
        columnTypes = new Class[columnNames.length];
        for(int i = 0; i < columnTypes.length; i++)
            columnTypes[i] = Object.class;
    }
    
    
    public boolean isCellEditable(int row, int col)
    {
        return false;
    }
    
    public Class getColumnClass(int column)
    {
        return columnTypes[column];
    }
    
    public void setColumnClass(int column, Class type)
    {
        columnTypes[column] = type;
    }
}

/* ChangeLog:
 *   $Log: NonEditableTableModel.java,v $
 *   Revision 1.2  2004/12/07 17:53:23  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 *   Revision 1.1  2004/11/01 02:24:20  bdickie
 *   Done Repository Browser.
 *
 */