/*
 * $Id: FilesTabbedPane.java,v 1.2 2004/12/07 17:53:22 bdickie Exp $
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

import ca.uvic.cs.gold.bdickie.fs.*;

import com.infosys.closeandmaxtabbedpane.*;
import java.util.*;
import java.awt.Component;

/** A tabbed panel that displays Files and MRs.
 *
 * @author  Blake Dickie
 */
public class FilesTabbedPane extends CloseAndMaxTabbedPane {
    private Map files = new HashMap();
    private Map mrses = new HashMap();
    private static FilesTabbedPane instance = null;
    
    /** Creates a new instance of FilesTabbedPane */
    public FilesTabbedPane() {
        super(true);
        setMaxIcon(false);
        this.addCloseListener(new CloseWatcher());
        instance = this;
    }
    
    /** Opens the given file in a tab.
     *  @param reuse If the file is already open, should we just view the old
     *               window.
     */
    public void openFile(File f, boolean reuse)
    {
        openFile(f, f.getLatestRevision(), reuse, false);
    }
    
    /** Opens the given file and revision in a tab.
     *  @param reuse If the file is already open, should we just view the old
     *               window.
     *  @param toFileView Should the content view be shown (otherwise the Info
     *               view will be shown).
     */
    public void openFile(File f, String revision_id, boolean reuse, boolean toFileView)
    {
        String tab = (toFileView ? "View" : "Info");
        boolean exists = files.containsKey(f);
        List tabs;
        if (exists)
            tabs = (List)files.get(f);
        else
        {
            tabs = new ArrayList(2);
            files.put(f, tabs);
        }
        
        if (reuse && exists)
        {
            FileViewPane pane = (FileViewPane)tabs.get(0);
            pane.setCard(tab);
            pane.setRevision(revision_id);
            setSelectedComponent(pane);
        }
        else {
            FileViewPane pane = new FileViewPane(f, revision_id);
            tabs.add(pane);
            addTab(f.getFilename(), pane);
            pane.setCard(tab);
            setSelectedComponent(pane);
        }
    }
    
    /** Open an MR, reusing as needed.
     */
    public void openMR(String mrid)
    {
        boolean exists = mrses.containsKey(mrid);
        List tabs;
        
        if (exists)
            setSelectedComponent((Component)mrses.get(mrid));
        else {
            MRSViewPanel pane = new MRSViewPanel(mrid);
            addTab(mrid, pane);
            mrses.put(mrid, pane);
            setSelectedComponent(pane);
        }
    }
    
    /** A listenter for when a tab closes, cleans up the vars associated with it.
     */
    private class CloseWatcher implements CloseListener
    {
        public void closeOperation(int tabIndex, java.awt.Component item) {
            if (item instanceof FileViewPane)
            {
            FileViewPane pane = (FileViewPane)item;
            List tabs = (List)files.get(pane.getFile());
            tabs.remove(pane);
            if (tabs.size() == 0)
                files.remove(pane.getFile());
            } else if (item instanceof MRSViewPanel) {
                MRSViewPanel pane = (MRSViewPanel)item;
                mrses.remove(pane.getMRID());
            }
        }
    }
    
    /** Gets the last initalized one of these panes.
     */
    public static synchronized FilesTabbedPane getInstance()
    {
        return instance;
    }
}

/* ChangeLog
 *   $Log: FilesTabbedPane.java,v $
 *   Revision 1.2  2004/12/07 17:53:22  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 *   Revision 1.1  2004/11/01 02:24:20  bdickie
 *   Done Repository Browser.
 *
 */