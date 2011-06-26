/*
 * $Id: AuthorsViewMode.java,v 1.1 2004/12/07 17:53:23 bdickie Exp $
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

package ca.uvic.cs.gold.bdickie.graphview.AuthorsView;

import ca.uvic.cs.gold.bdickie.graphview.framework.*;
import ca.uvic.cs.gold.bdickie.fs.*;
import ca.uvic.cs.gold.bdickie.db.DBConnection;

import java.awt.Color;
import java.util.*;

/** The view mode for the author who edited a file the most over a period.
 *  If you need more colors add them to the colors array.
 *
 * @author  Blake Dickie
 */
public class AuthorsViewMode extends AbstractGraphViewMode {
    private Color[] colors = {
        Color.LIGHT_GRAY,
        new Color(255, 255, 127),
        new Color(200, 127, 127),
        new Color(255, 195, 76),
        new Color(127, 200, 127),
        new Color(127, 127, 200),
        new Color(171, 160, 0),
        new Color(255, 127, 255),
        new Color(122, 204, 200),
        new Color(247, 148, 29),
        Color.GRAY
    };
    
    private Map authorToColor;
    private Map authorToCount;
    private Map fileToAuthor;
    private List authorList;
    private Vector edits;
    
    private AuthorViewPanel panel = null;
    
    /** Creates a new instance of AuthorsViewMode */
    public AuthorsViewMode() {
        super(VIEW_MODIFIED);
        authorToColor = new HashMap();
        authorToCount = new HashMap();
        fileToAuthor = new HashMap();
    }
    
    protected void childAddToGraph(Graph graph) {
        Vector result = DBConnection.getInstance().getAuthorsOfFiles(graph.getSettings().getStartDate(), graph.getSettings().getEndDate(),
        graph.getSettings().getRoot().getPath(), graph.getSettings().getRegexpPattern());
        
        edits = result;
        
        Iterator i = result.iterator();
        while(i.hasNext()) {
            Vector item = (Vector)i.next();
            DirectoryContent c = Directory.getFile((String)item.get(0));
            String author = (String)item.get(1);
            int count = ((Integer)item.get(2)).intValue();
            if (!fileToAuthor.containsKey(c))
                fileToAuthor.put(c, author);
            
            AuthorCount authorCount;
            if (authorToCount.containsKey(author))
                authorCount = (AuthorCount)authorToCount.get(author);
            else {
                authorCount = new AuthorCount();
                authorCount.count = 0;
                authorCount.author = author;
                authorToCount.put(author, authorCount);
            }
            authorCount.count += count;
        }
        
        authorList = new ArrayList(authorToCount.values());
        Collections.sort(authorList, new AuthorCountComparator());
        
        for(int j = 1; j <= authorList.size(); j++) {
            AuthorCount count = (AuthorCount)authorList.get(j - 1);
            
            if (j >= colors.length)
                authorToColor.put(count.author, colors[0]);
            else
                authorToColor.put(count.author, colors[j]);
        }
        
    }
    
    public java.awt.Component getControlPane() {
        if (panel == null) { 
            panel = new AuthorViewPanel(edits);
            Iterator i = authorList.iterator();
            while(i.hasNext()) {
                AuthorCount count = (AuthorCount)i.next();
                panel.addAuthor(count.author, count.count, (Color)authorToColor.get(count.author));
            }
        }
        
        return panel;
    }
    
    public String getDescription() {
        return "Author View";
    }
    
    public GraphViewSpecification getViewFor(ca.uvic.cs.gold.bdickie.fs.DirectoryContent node) {
        GraphViewSpecification specs = new GraphViewSpecification();
        if (node.isDirectory()) {
            specs.setBackgroundColor(Color.WHITE);
        } else {
            specs.setBackgroundColor((Color)authorToColor.get(fileToAuthor.get(node)));
        }
        
        specs.setText(node.getFilename());
        
        return specs;
    }
    
    public void mousePressed(ca.uvic.cs.gold.bdickie.fs.DirectoryContent node, java.awt.event.MouseEvent evt) {
        if ((!node.isDirectory()) && (panel != null))
            panel.setFile((File)node);
    }
    
    private class AuthorCount {
        int count;
        String author;
    }
    
    private class AuthorCountComparator implements Comparator {
        
        public int compare(Object obj, Object obj1) {
            AuthorCount a1 = (AuthorCount)obj;
            AuthorCount a2 = (AuthorCount)obj1;
            return a2.count - a1.count;
        }
        
    }
}

/* ChangeLog:
 *   $Log: AuthorsViewMode.java,v $
 *   Revision 1.1  2004/12/07 17:53:23  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 */
