/*
 * $Id: Evolution.java,v 1.2 2004/12/07 17:53:22 bdickie Exp $
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

package ca.uvic.cs.gold.bdickie.db.evolution;

import ca.uvic.cs.gold.bdickie.db.*;
import ca.uvic.cs.gold.bdickie.*;
import org.w3c.dom.*;

/** Module info for using the evolution database source.
 *
 * @author  Blake Dickie
 */
public class Evolution extends DBOption {
    
    /** Creates a new instance of Evolution */
    public Evolution() {
    }
    
    public void createConnection() {
        new EvolutionConnection();
    }
    
    public DBConfigPanel getConfigPanel() {
        return new EvolutionConfigPanel();
    }
    
    public void loadOptions(Element tag) {
        NodeList list = tag.getChildNodes();
        
        EvolutionOptions.setDefaults();
        
        for(int i = 0; i < list.getLength(); i++)
        {
            Node n = list.item(i);
            if (n.getNodeType() == Node.ELEMENT_NODE)
            {
                Element e = (Element)n;
                String tagName = e.getTagName();
                String value = XMLSupportFunctions.getTextValue(e);
                
                if (tagName.equals("username"))
                    EvolutionOptions.setUsername(value);
                else if (tagName.equals("password"))
                    EvolutionOptions.setPassword(value);
                else if (tagName.equals("hostname"))
                    EvolutionOptions.setHostname(value);
                else if (tagName.equals("database"))
                    EvolutionOptions.setDatabase(value);
            }
        }
    }
    
    public void saveOptions(Document doc, Element tag) {
        
        XMLSupportFunctions.setTextValue(doc, tag, "\n");
        Element element = doc.createElement("username");
        XMLSupportFunctions.setTextValue(doc, element, EvolutionOptions.getUsername());
        tag.appendChild(element);
        
        XMLSupportFunctions.setTextValue(doc, tag, "\n");
        
        element = doc.createElement("password");
        XMLSupportFunctions.setTextValue(doc, element, EvolutionOptions.getPassword());
        tag.appendChild(element);
        
        XMLSupportFunctions.setTextValue(doc, tag, "\n");
        
        
        element = doc.createElement("hostname");
        XMLSupportFunctions.setTextValue(doc, element, EvolutionOptions.getHostname());
        tag.appendChild(element);
        
        XMLSupportFunctions.setTextValue(doc, tag, "\n");
        
        
        element = doc.createElement("database");
        XMLSupportFunctions.setTextValue(doc, element, EvolutionOptions.getDatabase());
        tag.appendChild(element);
        
        XMLSupportFunctions.setTextValue(doc, tag, "\n");
        
        
    }
    
    public String getDescription() {
        return "'newevolution' Database Schema";
    }
}

/* ChangeLog:
 *   $Log: Evolution.java,v $
 *   Revision 1.2  2004/12/07 17:53:22  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 *   Revision 1.1  2004/11/01 00:22:16  bdickie
 *   'newevolution' data backend.
 *
 */
