/*
 * $Id: ExplorerOptions.java,v 1.3 2004/12/07 17:53:22 bdickie Exp $
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

import java.awt.Font;
import java.io.*;
import org.w3c.dom.*;

import ca.uvic.cs.gold.bdickie.db.DBOption;
import ca.uvic.cs.gold.bdickie.*;


/** Contains the global settings for the repository browser.
 *
 * @author  bdickie
 */
public class ExplorerOptions {
    private static String fontName = "Courier";
    private static int fontSize = 12;
    private static boolean bold;
    private static boolean italic;
    private static Font font;
    private static boolean showDeletedFiles = true;
    private static File configFile = new File(System.getProperty("user.home") + System.getProperty("file.separator") + ".rbrowse");
    private static boolean changed;
    
    public static Font getFont() {
        String style = "";
        if (bold)
            style += "BOLD";
        if (italic)
            style += "ITALIC";
        return Font.decode(fontName + "-" + style + "-" + fontSize);
        //return font;
    }
    
    public static void setFont(Font f) {
        if (!f.equals(font)) {
            changed = true;
            font = f;
            fontName = font.getName();
            fontSize = font.getSize();
            bold = font.isBold();
            italic = font.isItalic();
        }
    }
    
    public static boolean showDeletedFiles() {
        return showDeletedFiles;
    }
    
    public static void setShowDeletedFiles(boolean show) {
        if (showDeletedFiles != show)
        {
            changed = true;
            showDeletedFiles = show;
        }
    }
    
    /** Loads the settings from the ".rbrowse" file in the user's home.
     */
    public static void loadSettings() {
        
        Document doc;
        if (!configFile.exists()) {
            ConfigurationDialog.showParentless();
            saveSettings();
        } else {
            doc = XMLSupportFunctions.parseXML(configFile, false);
            if (doc == null) {
                ConfigurationDialog.showParentless();
                saveSettings();
                return;
            }
            
            Element root = doc.getDocumentElement();
            
            showDeletedFiles = Boolean.valueOf(root.getAttribute("showdeleted")).booleanValue();
            
            NodeList children = root.getChildNodes();
            for(int i = 0; i < children.getLength(); i++) {
                Node n = children.item(i);
                if (n.getNodeType() == Node.ELEMENT_NODE) {
                    Element e = (Element)n;
                    if (e.getNodeName().equals("font")) {
                        fontName = e.getAttribute("name");
                        fontSize = Integer.parseInt(e.getAttribute("size"));
                        bold = Boolean.valueOf(e.getAttribute("bold")).booleanValue();
                        italic = Boolean.valueOf(e.getAttribute("italic")).booleanValue();
                    } else if (e.getNodeName().equals("database")) {
                        if (!loadDatabaseSettings(e))
                            return;
                    }
                }
            }
        }
        changed = false;
    }
    
    /** Loads the database's settings from the XML tree and creates the backend
     *  as needed.
     */
    private static boolean loadDatabaseSettings(Element db) {
        try {
            Class c = Class.forName(db.getAttribute("class"));
            DBOption option = (DBOption)c.newInstance();
            option.setInstance();
            option.loadOptions(db);
            return true;
        } catch (Exception e) {
            ErrorLog.reportError("Unable to load database module.", e.getMessage(), false);
            ConfigurationDialog.showParentless();
            return false;
        }
    }
    
    /** Save the settings to the ".rbrowse" file in the user's home.
     */
    public static void saveSettings() {
        Document doc = XMLSupportFunctions.newXMLTree("rbrowseconf");
        Element root = doc.getDocumentElement();
        
        root.setAttribute("showdeleted", String.valueOf(showDeletedFiles));
        
        XMLSupportFunctions.setTextValue(doc, root, "\n");
        
        Element font = doc.createElement("font");
        font.setAttribute("name",  fontName);
        font.setAttribute("size", String.valueOf(fontSize));
        
        font.setAttribute("bold", String.valueOf(bold));
        font.setAttribute("italic", String.valueOf(italic));
        
        root.appendChild(font);
        
        XMLSupportFunctions.setTextValue(doc, root, "\n");
        
        DBOption currentDB = DBOption.getInstance();
        Element database  = doc.createElement("database");
        database.setAttribute("class", currentDB.getClass().getName());
        
        currentDB.saveOptions(doc, database);
        
        root.appendChild(database);
        XMLSupportFunctions.setTextValue(doc, root, "\n");
        try {
            FileWriter out = new FileWriter(configFile);
            XMLSupportFunctions.writeXMLToStream(doc, out);
            out.close();
        } catch (IOException e) {
            ErrorLog.reportError("Error saving settings to disk.", e.getMessage(), false);
        }
    }
    
    public boolean hasChanged() {
        return changed;
    }
}

/* ChangeLog:
 *   $Log: ExplorerOptions.java,v $
 *   Revision 1.3  2004/12/07 17:53:22  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 *   Revision 1.2  2004/11/14 22:57:40  bdickie
 *   Fixed small bug where it would ask for settings on first run, but not save them.
 *
 *   Revision 1.1  2004/11/01 02:24:20  bdickie
 *   Done Repository Browser.
 *
 */