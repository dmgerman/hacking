/*
 * $Id: TimesModifiedView.java,v 1.1 2004/12/07 17:53:23 bdickie Exp $
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

package ca.uvic.cs.gold.bdickie.graphview.TimesModified;

import java.util.*;
import java.awt.*;

import ca.uvic.cs.gold.bdickie.graphview.framework.*;
import ca.uvic.cs.gold.bdickie.fs.*;
import ca.uvic.cs.gold.bdickie.db.DBConnection;

/** View mode for showing the relative number of revisions of each file.
 *
 * @author  Blake Dickie
 */
public class TimesModifiedView extends AbstractGraphViewMode {
    private TimesModifiedPanel panel = null;
    private int maxModifications;
    private Map fileToProperties;
    
    private final static Color highModificationColor = new Color(160, 65, 13);
    private final static Color modifiedBorderColor = new Color(200, 0, 0);
    
    
    /** Creates a new instance of TimesModifiedView */
    public TimesModifiedView() {
        super(VIEW_ALL);
        fileToProperties = new HashMap();
    }
    
    protected void childAddToGraph(Graph graph) {
        maxModifications = 0;
        fileToProperties.clear();
        
        Map timesModified = DBConnection.getInstance().getFilesUpdatedOnRange(graph.getSettings().getStartDate(), graph.getSettings().getEndDate(), 
            graph.getSettings().getRoot().getPath(), graph.getSettings().getRegexpPattern());
        
        Iterator i = timesModified.keySet().iterator();
        while(i.hasNext())
        {
            String filename = (String)i.next();
            int modified = ((Integer)timesModified.get(filename)).intValue();
            new FileModificationProperties(Directory.getFile(filename), modified);
        }
    }
    
    public java.awt.Component getControlPane() {
        if (panel == null)
            panel = new TimesModifiedPanel(this, graph.getSettings().getStartDate(), graph.getSettings().getEndDate());
        return panel;
    }
    
    public GraphViewSpecification getViewFor(ca.uvic.cs.gold.bdickie.fs.DirectoryContent node) {
        int count;
        if (node.isDirectory())
            count = 0;
        else {
            FileModificationProperties props = (FileModificationProperties)fileToProperties.get(node);
            if (props == null)
                count = 0;
            else
                count = props.timesModified;
        }
        
        GraphViewSpecification specs = new GraphViewSpecification();
        
        if (count == 0)
            specs.setBackgroundColor(Color.WHITE);
        else if (count >= maxModifications)
            specs.setBackgroundColor(highModificationColor);
        else {
            double ratio = ((double)count) / maxModifications;
            int red = 255 - (int)((255 - highModificationColor.getRed())*ratio);
            int green = 255 - (int)((255 - highModificationColor.getGreen())*ratio);
            int blue = 255 - (int)((255 - highModificationColor.getBlue())*ratio);
            
            specs.setBackgroundColor(new Color(red, green, blue));
        }
        
        if (count == 0)
        {
            specs.setBorderColor(Color.BLACK);
            specs.setBorderWidth(1);
        } else {
            specs.setBorderColor(modifiedBorderColor);
            specs.setBorderWidth(3);
        }
        
        specs.setTextColor(Color.BLACK);
        specs.setText(node.getFilename());
        
        return specs;
    }
    
    public void mousePressed(DirectoryContent node, java.awt.event.MouseEvent evt) {
        if (!node.isDirectory() && panel != null)
            panel.setFile(node);
    }
    
    public String getDescription()
    {
        return "Times Modified";
    }
    
    
    
    private class FileModificationProperties {
        public DirectoryContent file;
        public int timesModified;
        
        public FileModificationProperties(DirectoryContent file, int timesModified) {
            this.file = file;
            this.timesModified = timesModified;
            if (timesModified > maxModifications)
                maxModifications = timesModified;
            
            fileToProperties.put(file, this);
        }
    }
    
}

/* ChangeLog:
 *   $Log: TimesModifiedView.java,v $
 *   Revision 1.1  2004/12/07 17:53:23  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 */
