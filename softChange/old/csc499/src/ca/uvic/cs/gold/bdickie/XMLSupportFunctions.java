/*
 * $Id: XMLSupportFunctions.java,v 1.2 2004/12/07 17:53:22 bdickie Exp $
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

package ca.uvic.cs.gold.bdickie;

import org.w3c.dom.*;

import javax.xml.transform.*;
import javax.xml.transform.dom.*;
import javax.xml.transform.stream.*;
import org.xml.sax.helpers.DefaultHandler;
import javax.xml.parsers.*;
import org.xml.sax.InputSource;

import java.io.*;
import java.util.*;

/** This class provides a number of static support methods which help with
 *  XML activity.
 *
 * @author  Blake Dickie
 */
public class XMLSupportFunctions {
    private static String m_path;
    public static final String xmlnsURI = "http://www.w3.org/2000/xmlns/";
    public static final String schemaInstanceNS = "http://www.w3.org/2001/XMLSchema-instance";
    public static final String xsdBase = "http://www.csc.uvic.ca/~bdickie/seng450/";
    
    /*********************** PUBLIC METHODS ********************/
    
    
    /** Converts a String into a DOM tree.
     * @param xml The string containing the XML content to parse into a DOM tree.
     * @param validating Weither the parser should do schema validation on the input.
     * @return The document root of the object if successful, null otherwise.
     */
    public static Document parseXML(String xml, boolean validating) {
        try {
            return parseXML(new StringReader(xml), validating);
        } catch (Exception e) {
            ErrorLog.reportError("Error parsing XML file.", e.getMessage(), true);
            return null;
        }
    }
    
    public static Document parseXML(Reader xml, boolean validating) {
        try {
            DocumentBuilderFactory f = DocumentBuilderFactory.newInstance();
            if (validating)
                f.setAttribute("http://java.sun.com/xml/jaxp/properties/schemaLanguage", "http://www.w3.org/2001/XMLSchema");
            
            f.setNamespaceAware(true);
            f.setValidating(validating);
            DocumentBuilder db = f.newDocumentBuilder();
            SAXHandler handle = new SAXHandler();
            db.setErrorHandler(handle);
            InputSource src = new InputSource(xml);
            Document doc = db.parse(src);
            if (handle.isError())
                return null;
            return doc;
        } catch (Exception e) {
            ErrorLog.reportError("Error parsing XML file.", e.getMessage(), true);
            return null;
        }
    }
    
    public static Document parseXML(File xml, boolean validating) {
        try {
            DocumentBuilderFactory f = DocumentBuilderFactory.newInstance();
            if (validating)
                f.setAttribute("http://java.sun.com/xml/jaxp/properties/schemaLanguage", "http://www.w3.org/2001/XMLSchema");
            
            f.setNamespaceAware(true);
            f.setValidating(validating);
            DocumentBuilder db = f.newDocumentBuilder();
            SAXHandler handle = new SAXHandler();
            db.setErrorHandler(handle);
            Document doc = db.parse(xml);
            if (handle.isError())
                return null;
            return doc;
        } catch (Exception e) {
            ErrorLog.reportError("Error parsing XML file.", e.getMessage(), false);
            return null;
        }
    }
    
    /** Converts a DOM Tree to a String.
     * @param xml The DOM document to convert.
     * @return A string containing the XML if successful, false otherwise.
     */
    public static String xmlToString(Document xml) {
        StringWriter writer = new StringWriter();
        writeXMLToStream(xml, writer);
        return writer.toString();
    }
    
    public static void writeXMLToStream(Document xml, Writer out)
    {
        try {
            TransformerFactory f = TransformerFactory.newInstance();
            Transformer t = f.newTransformer();
            DOMSource src = new DOMSource(xml);
            StreamResult result = new StreamResult(out);
            t.transform(src, result);
        } catch (TransformerException e) {
            ErrorLog.reportError("Error writing XML file.", e.getMessage(), false);
        }
    }
    
    
    /** Runs the given SAXHandler on the input string
     * @param xml The String to parse.
     * @param handler The SAXHandler to use on the xml.
     * @param validating Weither the parser should do schema validation on the input.
     * @return true iff no errors were reported in the parsing.
     */
    public static boolean saxParse(String xml, SAXHandler handler, boolean validating) {
        return saxParse(new InputSource(new StringReader(xml)), handler, validating);
    }
    
    
    /** Runs the given SAXHandler on the input string
     * @param xml The InputSource to parse.
     * @param handler The SAXHandler to use on the xml.
     * @param validating Weither the parser should do schema validation on the input.
     * @return true iff no errors were reported in the parsing.
     */
    public static boolean saxParse(InputSource xml, SAXHandler handler, boolean validating) {
        try {
            SAXParserFactory factory = SAXParserFactory.newInstance();
            factory.setValidating(validating);
            factory.setNamespaceAware(true);
            
            SAXParser parser = factory.newSAXParser();
            if (validating)
                parser.setProperty("http://java.sun.com/xml/jaxp/properties/schemaLanguage", "http://www.w3.org/2001/XMLSchema");
            
            parser.parse(xml, handler);
            return !handler.isError();
        } catch (Exception e) {
            return false;
        }
    }
    
    /** Creates a new DOM Tree with a root element containing the schema attributes.
     * @param rootName The name of the root element.
     * @param namespaceURI The uri of the namespace of the document.
     * @param namespacePrefix The prefix to use for the namespace (ie. the part
     * before the ':' in the root element.
     * @param namespaceXSD The name of the xsd file used to validate the file.
     * Should be given relative to xsdBase.
     */
    public static Document newXMLTree(String rootName) {
        try {
            DocumentBuilderFactory f = DocumentBuilderFactory.newInstance();
            
            DocumentBuilder b = f.newDocumentBuilder();
            Document doc = b.newDocument();
            Element rootNode = doc.createElement(rootName);
            
            doc.appendChild(rootNode);
            return doc;
        } catch (Exception e) {
            ErrorLog.reportError("Error creating XML file.", e.getMessage(), true);
            return null;
        }
    }
    
    /** Copies all the children elements and text nodes from one Element to another.
     * Will copy attributes on children elements.
     * @param src The element to copy from.
     * @param dst The element to copy to.
     * @param dstDoc The Document which contains the dst Element.
     */
    public static void convertChildren(Element src, Element dst, Document dstDoc) {
        String ns = dst.getNamespaceURI();
        NodeList children = src.getChildNodes();
        for (int i = 0; i < children.getLength(); i++) {
            Node curNode = children.item(i);
            if (curNode.getNodeType() == curNode.ELEMENT_NODE) {
                Element elm = (Element)curNode;
                Element newNode = dstDoc.createElementNS(ns, curNode.getLocalName());
                NamedNodeMap attrs = elm.getAttributes();
                for(int j = 0; j < attrs.getLength(); j++) {
                    Attr attr = (Attr)attrs.item(j);
                    newNode.setAttributeNS(ns, attr.getName(), attr.getValue());
                }
                
                dst.appendChild(newNode);
                
                convertChildren(elm, newNode, dstDoc);
                
            } else if (curNode.getNodeType() == curNode.TEXT_NODE) {
                Text txt = (Text)curNode;
                Text newNode = dstDoc.createTextNode(txt.getData());
                dst.appendChild(newNode);
            }
        }
    }
    
    
    
    /** Gets the text value contained in an element.
     * @param node The Element to get the text value of.
     * @return The text in the element.
     */
    public static String getTextValue(Element node)
    {
        NodeList nodes = node.getChildNodes();
        for (int i = 0; i < nodes.getLength(); i++)
        {
            Node n = nodes.item(i);
            if (n.getNodeType() == n.TEXT_NODE)
                return n.getNodeValue();
        }
        return null;
    }
    
    public static void setTextValue(Document doc, Element node, String value)
    {
        Text t = doc.createTextNode(value);
        node.appendChild(t);
    }
    
    /** Trys to find a child element in the given parent element.
     * @param parent The Element to search in.
     * @param name The name of the element to search for.
     * @return The Element if found, null otherwise.
     */
    public static Element findElement(Element parent, String name)
    {
        NodeList l = parent.getChildNodes();
        for(int i = 0; i < l.getLength(); i++)
        {
            Node n = l.item(i);
            if (n.getNodeType() == n.ELEMENT_NODE)
            {
                Element e = (Element)n;
                if (e.getNodeName().equals(name))
                    return e;
            }
        }
        return null;
    }   
}

/* ChangeLog:
 *   $Log: XMLSupportFunctions.java,v $
 *   Revision 1.2  2004/12/07 17:53:22  bdickie
 *   Done Repository Grapher and added GPL boilerplate to older files.
 *
 *   Revision 1.1  2004/10/31 23:43:51  bdickie
 *   Done prelimiary version of repository explorer.
 *
 */
