/*
 * @(#)GraphConstants.java 1.0 03-JUL-04
 * 
 * Copyright (c) 2001-2004 Gaudenz Alder
 *  
 */
package org.jgraph.graph;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Point;
import java.awt.Stroke;
import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;
import java.util.Hashtable;
import java.util.Iterator;
import java.util.Map;

import javax.swing.Icon;
import javax.swing.JLabel;
import javax.swing.UIManager;
import javax.swing.border.Border;

/**
 * A collection of well known or common attribute keys and methods to apply to
 * an Map to get/set the properties in a typesafe manner. The following
 * attributes and methods need special attention: removeAttributes, removeAll
 * and value. RemoveAttributes and RemoveAll are not stored in a map, but remove
 * the specified entries. The value entry of a propertyMap is always in sync
 * with the userObject of a GraphCell. The isMoveable, isAutoSize and isSizeable
 * are used indepedently (see
 * http://sourceforge.net/forum/forum.php?thread_id=770111&forum_id=140880)
 * 
 * @version 1.0 1/1/02
 * @author Gaudenz Alder
 */
public class GraphConstants {

	public static Font DEFAULTFONT = UIManager.getFont("Tree.font");

	/** Default decoration size. */
	public static final int DEFAULTDECORATIONSIZE = 10;

	/** Default group border. */
	public static final int DEFAULTGROUPBORDER = 20;
	
	/** 100 percent unit for relative positioning. Current value is 1000. */
	public static final int PERMILLE = 1000;

	/** Global Stroke To Highlight Selection */
	static protected float[] dash = {5f, 5f};

	static public Stroke SELECTION_STROKE = new BasicStroke(1,
			BasicStroke.CAP_BUTT, BasicStroke.JOIN_MITER, 10.0f, dash, 0.0f);

	/** Represents no decoration */
	public static final int ARROW_NONE = 0;

	/** Represents a classic arrow decoration */
	public static final int ARROW_CLASSIC = 1;

	/** Represents a technical arrow decoration */
	public static final int ARROW_TECHNICAL = 2;

	/** Represents a simple arrow decoration */
	public static final int ARROW_SIMPLE = 4;

	/** Represents a circle decoration */
	public static final int ARROW_CIRCLE = 5;

	/** Represents a line decoration */
	public static final int ARROW_LINE = 7;

	/** Represents a double line decoration */
	public static final int ARROW_DOUBLELINE = 8;

	/** Represents a diamond decoration */
	public static final int ARROW_DIAMOND = 9;

	/** Represents an orthogonal line style */
	public static final int STYLE_ORTHOGONAL = 11;

	/** Represents a bezier line style */
	public static final int STYLE_BEZIER = 12;

	/** Represents an spline line style */
	public static final int STYLE_SPLINE = 13;
	
	/** Represents an bezier line style */
	public static final int X_AXIS = 1;

	/** Represents an bezier line style */
	public static final int Y_AXIS = 2;

	/**
	 * A simple default Routing.
	 */
	public static final Edge.Routing ROUTING_SIMPLE = new DefaultEdge.DefaultRouting();

	/**
	 * Key for the <code>replaceAttributes</code> attribute. This special
	 * attribute contains a Boolean instance indicating whether a map of
	 * attributes should replace the attributes of the receiving view.
	 */
	public final static String SIZEABLEAXIS = "sizeableAxis";

	/**
	 * Key for the <code>replaceAttributes</code> attribute. This special
	 * attribute contains a Boolean instance indicating whether a map of
	 * attributes should replace the attributes of the receiving view.
	 */
	public final static String MOVEABLEAXIS = "moveableAxis";

	/**
	 * Key for the <code>replaceAttributes</code> attribute. This special
	 * attribute contains a Boolean instance indicating whether a map of
	 * attributes should replace the attributes of the receiving view.
	 */
	public final static String REPLACEATTRIBUTES = "replaceAttributes";

	/**
	 * Key for the <code>removeAttributes</code> attribute. This special
	 * attribute contains a list of attribute-keys which should be removed at
	 * the receiving views.
	 */
	public final static String REMOVEATTRIBUTES = "removeAttributes";

	/**
	 * Key for the <code>removeAll</code> attribute. This causes the receivers
	 * attributes to be replaced by the the map that contains this attribute.
	 */
	public final static String REMOVEALL = "removeAll";

	/**
	 * Key for the <code>icon</code> attribute. Use instances of Icon as
	 * values for this key.
	 */
	public final static String ICON = "icon";

	/**
	 * Key for the <code>font</code> attribute. Use instances of Font as
	 * values for this key.
	 */
	public final static String FONT = "font";

	/**
	 * Key for the <code>opaque</code> attribute. Use instances of Boolean as
	 * values for this key.
	 */
	public final static String OPAQUE = "opaque";

	/**
	 * Key for the <code>border</code> attribute. Use instances of Border as
	 * values for this key. Optionally, you can set the global instance of
	 * LineBorder.
	 */
	public final static String BORDER = "border";

	/**
	 * Key for the <code>linecolor</code> attribute. Use instances of Color as
	 * values for this key.
	 */
	public final static String LINECOLOR = "linecolor";

	/**
	 * Key for the <code>bordercolor</code> attribute. Use instances of Color
	 * as values for this key.
	 */
	public final static String BORDERCOLOR = "bordercolor";

	/**
	 * Key for the <code>linewidth</code> attribute. Use instances of Float as
	 * values for this key.
	 */
	public final static String LINEWIDTH = "linewidth";

	/**
	 * Key for the <code>foreground</code> attribute. Use instances of Color
	 * as values for this key.
	 */
	public final static String FOREGROUND = "foregroundColor";

	/**
	 * Key for the <code>background</code> attribute. Use instances of Color
	 * as values for this key.
	 */
	public final static String BACKGROUND = "backgroundColor";

	/**
	 * Key for the <code>background</code> attribute. Use instances of Color
	 * as values for this key.
	 */
	public final static String GRADIENTCOLOR = "gradientColor";
	
	/**
	 * Key for the <code>verticalAlignment</code> attribute. Use instances of
	 * Integer as values for this key. Constants defined in JLabel class.
	 */
	public final static String VERTICAL_ALIGNMENT = "verticalAlignment";

	/**
	 * Key for the <code>horizontalAlignment</code> attribute. Use instances
	 * of Integer as values for this key. Constants defined in JLabel class.
	 */
	public final static String HORIZONTAL_ALIGNMENT = "horizontalAlignment";

	/**
	 * Key for the <code>verticalTextPosition</code> attribute. Use instances
	 * of Integer as values for this key. Constants defined in JLabel class.
	 */
	public final static String VERTICAL_TEXT_POSITION = "verticalTextPosition";

	/**
	 * Key for the <code>horizontalTextPosition</code> attribute. Use
	 * instances of Integer as values for this key. Constants defined in JLabel
	 * class.
	 */
	public final static String HORIZONTAL_TEXT_POSITION = "horizontalTextPosition";

	/**
	 * Key for the <code>dashPattern</code> attribute. Use instances of
	 * float[] as values for this key.
	 */
	public final static String DASHPATTERN = "dashPattern";

	/**
	 * Key for the <code>dashOffset</code> attribute. Use instances of
	 * float as values for this key.
	 */
	public final static String DASHOFFSET = "dashOffset";
 

	/**	
	 * Key for the <code>lineStyle</code> attribute. Use instances of Integer
	 * as values for this key. Constants defined in this class.
	 */
	public final static String LINESTYLE = "lineStyle";

	/**
	 * Key for the <code>start</code> attribute. Use instances of Integer as
	 * values for this key. Constants defined in this class.
	 */
	public final static String LINEBEGIN = "lineBegin";

	/**
	 * Key for the <code>start</code> attribute. Use instances of Integer as
	 * values for this key. Constants defined in this class.
	 */
	public final static String LINEEND = "lineEnd";

	/**
	 * Key for the <code>startsize</code> attribute. Use instances of Integer
	 * as values for this key.
	 */
	public final static String BEGINSIZE = "beginSize";

	/**
	 * Key for the <code>endsize</code> attribute. Use instances of Integer as
	 * values for this key.
	 */
	public final static String ENDSIZE = "endsize";

	/**
	 * Key for the <code>startsize</code> attribute. Use instances of Integer
	 * as values for this key.
	 */
	public final static String BEGINFILL = "beginFill";

	/**
	 * Key for the <code>endsize</code> attribute. Use instances of Integer as
	 * values for this key.
	 */
	public final static String ENDFILL = "endFill";

	/**
	 * Key for the <code>value</code> attribute. You can use any Object as a
	 * value for this key.
	 */
	public static final String VALUE = "value";

	/**
	 * Key for the <code>editable</code> attribute. Use instances of Boolean
	 * as values for this key.
	 */
	public static final String EDITABLE = "editable";

	/**
	 * Key for the <code>moveable</code> attribute. Use instances of Boolean
	 * as values for this key.
	 */
	public static final String MOVEABLE = "moveable";

	/**
	 * Key for the <code>sizeable</code> attribute. Use instances of Boolean
	 * as values for this key.
	 */
	public static final String SIZEABLE = "sizeable";

	/**
	 * Key for the <code>sizeable</code> attribute. Use instances of Boolean
	 * as values for this key.
	 */
	public static final String AUTOSIZE = "autosize";

	/**
	 * Key for the <code>resize</code> attribute. Use instances of Boolean
	 * as values for this key.
	 */
	public static final String RESIZE = "resize";
	
	/**
	 * Key for the <code>sizeable</code> attribute. Use instances of Boolean
	 * as values for this key.
	 */
	public static final String BENDABLE = "bendable";

	/**
	 * Key for the <code>moveable</code> attribute. Use instances of Boolean
	 * as values for this key.
	 */
	public static final String CONNECTABLE = "connectable";

	/**
	 * Key for the <code>moveable</code> attribute. Use instances of Boolean
	 * as values for this key.
	 */
	public static final String DISCONNECTABLE = "disconnectable";

	/**
	 * Key for the <code>bounds</code> attribute. Use instances of Rectangle
	 * as values for this key.
	 */
	public static final String BOUNDS = "bounds";

	/**
	 * Key for the <code>bounds</code> attribute. Use instances of Rectangle
	 * as values for this key.
	 */
	public static final String GROUPBORDER = "groupBorder";

	/**
	 * Key for the <code>points</code> attribute. Use instances of List as
	 * values for this key. The list should contain Point instances.
	 */
	public static final String POINTS = "points";

	/**
	 * Key for the <code>routing</code> attribute. Use instances of
	 * EdgeView.EdgeRouter as values for this key. The list should contain Point
	 * instances.
	 */
	public static final String ROUTING = "routing";

	/**
	 * Key for the <code>labelposition</code> attribute. Use instances of
	 * Point as values for this key.
	 */
	public static final String LABELPOSITION = "labelposition";

	/**
	 * Key for the <code>labelposition</code> attribute. Use instances of
	 * Point as values for this key.
	 */
	public static final String EXTRALABELS = "extraLabels";

	/**
	 * Key for the <code>labelposition</code> attribute. Use instances of
	 * Point as values for this key.
	 */
	public static final String EXTRALABELPOSITIONS = "extraLabelPositions";

	/**
	 * Key for the <code>labelalongedge</code> attribute. Use instances of
	 * Boolean as values for this key.
	 */
	public static final String LABELALONGEDGE = "labelAlongEdge";

	/**
	 * Key for the <code>absoluteD</code> attribute. Use instances of Boolean
	 * as values for this key.
	 */
	public static final String ABSOLUTEX = "absoluteX";

	/**
	 * Key for the <code>absoluteY</code> attribute. Use instances of Boolean
	 * as values for this key.
	 */
	public static final String ABSOLUTEY = "absoluteY";

	/**
	 * Key for the <code>translate</code> attribute. Use instances of Point as
	 * values for this key.
	 */
	public static final String OFFSET = "offset";

	/**
	 * Key for the <code>resize</code> attribute. Use instances of Dimension
	 * as values for this key.
	 */
	public static final String SIZE = "size";

	//
	// Attributes
	//
	public static Map createAttributes(Object cell, Object key, Object value) {
		return createAttributes(new Object[]{cell}, new Object[]{key},
				new Object[]{value});
	}

	public static Map createAttributes(Object[] cells, Object key, Object value) {
		return createAttributes(cells, new Object[]{key}, new Object[]{value});
	}

	/**
	 * Returns a new (nested) map, from cells to attribute maps. The attributes
	 * are populated with the (key, value)-pairs specified by the two given
	 * arrays. The <code>keys</code> and <code>values</code> parameters must
	 * match in size.
	 */
	public static Map createAttributes(Object[] cells, Object[] keys,
			Object[] values) {
		if (keys != null && values != null && keys.length != values.length)
			throw new IllegalArgumentException(
					"Keys and values must have same length");
		Map nested = new Hashtable();
		for (int i = 0; i < cells.length; i++) {
			if (cells[i] != null) {
				Map attributes = new Hashtable();
				for (int j = 0; j < keys.length; j++)
					if (keys[j] != null && values[j] != null)
						attributes.put(keys[j], values[j]);
				nested.put(cells[i], attributes);
			}
		}
		return nested;
	}

	/**
	 * Returns a new map, from cells to property maps. The <code>elements</code>
	 * may be instances of <code>CellView</code>, in which case the cell
	 * view's corresponding cell is used as a key, and its attributes are used
	 * as a property map. In any other case, the <code>element</code> is
	 * considered as a cell and looked-up in the cell mapper to find the
	 * corresponding view. If a view is found, its attributes are cloned and
	 * used as a property map, along with the cell as a key.
	 * <p>
	 * <strong>Note: </strong> This method returns a map of maps! This is
	 * different from the createMap method, which creates a map, from keys to
	 * values. This method returns a map, from cells to maps, which in turn map
	 * from keys to values.
	 */
	public static Map createAttributes(Object[] elements, CellMapper cm) {
		Map attributes = new Hashtable();
		for (int i = 0; i < elements.length; i++) {
			CellView view = null;
			Object key = elements[i];
			if (key instanceof CellView) {
				view = (CellView) key;
				key = view.getCell();
			} else if (cm != null) // else is assumed by clients!
				view = cm.getMapping(key, false);
			if (view != null)
				attributes.put(key, view.getAllAttributes().clone());
		}
		return attributes;
	}

	// Returns a nested map of cell, Map pairs where the map reflects
	// the attributes returned by the model for this cell.
	public static Map createAttributesFromModel(Object[] elements,
			GraphModel model) {
		Map attributes = new Hashtable();
		for (int i = 0; i < elements.length; i++) {
			AttributeMap attr = model.getAttributes(elements[i]);
			if (attr != null && attr.size() > 0)
				attributes.put(elements[i], (AttributeMap) attr.clone());
		}
		return attributes;
	}

	/**
	 * Replace the keys in <code>map</code> using <code>keyMap</code, which
	 * maps from old to new keys. The value in <code>map</code> must itself
	 * be a map, and is cloned using <code>cloneMap</code>.
	 */
	public static Map replaceKeys(Map keyMap, Map map) {
		Map newMap = new Hashtable();
		Iterator it = map.entrySet().iterator();
		while (it.hasNext()) {
			Map.Entry entry = (Map.Entry) it.next();
			if (entry.getValue() instanceof Map) {
				Object newKey = keyMap.get(entry.getKey());
				if (newKey != null) {
					AttributeMap val = (AttributeMap) ((AttributeMap) entry.getValue()).clone();
					newMap.put(newKey, val);
				}
			}
		}
		return newMap;
	}

	/**
	 * Sets the value attribute in the specified map to the specified font
	 * value.
	 * 
	 * @param map
	 *            The map to store the font attribute in.
	 * @param font
	 *            The value to set the font attribute to.
	 */
	public static void setFont(Map map, Font font) {
		map.put(FONT, font);
	}

	/**
	 * Returns the font for the specified attribute map. Uses default font if no
	 * font is specified in the attribute map.
	 */
	public static Font getFont(Map map) {
		Font font = (Font) map.get(FONT);
		if (font == null)
			font = DEFAULTFONT;
		return font;
	}

	/**
	 * Sets the value attribute in the specified map to the specified value.
	 */
	public static final void setRemoveAttributes(Map map, Object[] value) {
		map.put(REMOVEATTRIBUTES, value);
	}

	/**
	 * Returns the value attribute from the specified map.
	 */
	public static final Object[] getRemoveAttributes(Map map) {
		return (Object[]) map.get(REMOVEATTRIBUTES);
	}

	/**
	 * Sets the value attribute in the specified map to the specified value.
	 */
	public static final void setMoveableAxis(Map map, int axis) {
		map.put(MOVEABLEAXIS, new Integer(axis));
	}

	/**
	 * Returns the value attribute from the specified map.
	 */
	public static final int getMoveableAxis(Map map) {
		Integer intObj = (Integer) map.get(MOVEABLEAXIS);
		if (intObj != null)
			return intObj.intValue();
		return 0;
	}

	/**
	 * Sets the value attribute in the specified map to the specified value.
	 */
	public static final void setSizeableAxis(Map map, int axis) {
		map.put(SIZEABLEAXIS, new Integer(axis));
	}

	/**
	 * Returns the value attribute from the specified map.
	 */
	public static final int getSizeableAxis(Map map) {
		Integer intObj = (Integer) map.get(SIZEABLEAXIS);
		if (intObj != null)
			return intObj.intValue();
		return 0;
	}

	/**
	 * Sets the value attribute in the specified map to the specified value.
	 */
	public static final void setIcon(Map map, Icon value) {
		map.put(ICON, value);
	}

	/**
	 * Returns the value attribute from the specified map.
	 */
	public static final Icon getIcon(Map map) {
		return (Icon) map.get(ICON);
	}

	/**
	 * Sets the opaque attribute in the specified map to the specified value.
	 */
	public static final void setOpaque(Map map, boolean flag) {
		map.put(OPAQUE, new Boolean(flag));
	}

	/**
	 * Returns the opaque attribute from the specified map.
	 */
	public static final boolean isOpaque(Map map) {
		Boolean bool = (Boolean) map.get(OPAQUE);
		if (bool != null)
			return bool.booleanValue();
		return false;
	}

	/**
	 * Sets the value attribute in the specified map to the specified value.
	 */
	public static final void setBorder(Map map, Border value) {
		map.put(BORDER, value);
	}

	/**
	 * Returns the value attribute from the specified map.
	 */
	public static final Border getBorder(Map map) {
		return (Border) map.get(BORDER);
	}

	/**
	 * Sets the value attribute in the specified map to the specified value.
	 */
	public static final void setLineColor(Map map, Color value) {
		map.put(LINECOLOR, value);
	}

	/**
	 * Returns the value attribute from the specified map.
	 */
	public static final Color getLineColor(Map map) {
		return (Color) map.get(LINECOLOR);
	}

	/**
	 * Sets the value attribute in the specified map to the specified value.
	 */
	public static final void setBorderColor(Map map, Color value) {
		map.put(BORDERCOLOR, value);
	}

	/**
	 * Returns the value attribute from the specified map.
	 */
	public static final Color getBorderColor(Map map) {
		return (Color) map.get(BORDERCOLOR);
	}

	/**
	 * Sets the opaque attribute in the specified map to the specified value.
	 */
	public static final void setLineWidth(Map map, float width) {
		map.put(LINEWIDTH, new Float(width));
	}

	/**
	 * Returns the opaque attribute from the specified map.
	 */
	public static final float getLineWidth(Map map) {
		Float floatObj = (Float) map.get(LINEWIDTH);
		if (floatObj != null)
			return floatObj.floatValue();
		return 1;
	}

	/**
	 * Sets the value attribute in the specified map to the specified value.
	 */
	public static final void setForeground(Map map, Color value) {
		map.put(FOREGROUND, value);
	}

	/**
	 * Returns the value attribute from the specified map.
	 */
	public static final Color getForeground(Map map) {
		return (Color) map.get(FOREGROUND);
	}

	/**
	 * Sets the value attribute in the specified map to the specified value.
	 */
	public static final void setBackground(Map map, Color value) {
		map.put(BACKGROUND, value);
	}

	/**
	 * Returns the value attribute from the specified map.
	 */
	public static final Color getBackground(Map map) {
		return (Color) map.get(BACKGROUND);
	}

	/**
	 * Sets the value attribute in the specified map to the specified value.
	 */
	public static final void setGradientColor(Map map, Color value) {
		map.put(GRADIENTCOLOR, value);
	}

	/**
	 * Returns the value attribute from the specified map.
	 */
	public static final Color getGradientColor(Map map) {
		return (Color) map.get(GRADIENTCOLOR);
	}
	
	/**
	 * Sets the opaque attribute in the specified map to the specified value.
	 */
	public static final void setVerticalAlignment(Map map, int width) {
		map.put(VERTICAL_ALIGNMENT, new Integer(width));
	}

	/**
	 * Returns the opaque attribute from the specified map.
	 */
	public static final int getVerticalAlignment(Map map) {
		Integer intObj = (Integer) map.get(VERTICAL_ALIGNMENT);
		if (intObj != null)
			return intObj.intValue();
		return JLabel.CENTER;
	}

	/**
	 * Sets the opaque attribute in the specified map to the specified value.
	 */
	public static final void setHorizontalAlignment(Map map, int width) {
		map.put(HORIZONTAL_ALIGNMENT, new Integer(width));
	}

	/**
	 * Returns the opaque attribute from the specified map.
	 */
	public static final int getHorizontalAlignment(Map map) {
		Integer intObj = (Integer) map.get(HORIZONTAL_ALIGNMENT);
		if (intObj != null)
			return intObj.intValue();
		return JLabel.CENTER;
	}

	/**
	 * Sets the opaque attribute in the specified map to the specified value.
	 */
	public static final void setVerticalTextPosition(Map map, int width) {
		map.put(VERTICAL_TEXT_POSITION, new Integer(width));
	}

	/**
	 * Returns the opaque attribute from the specified map.
	 */
	public static final int getVerticalTextPosition(Map map) {
		Integer intObj = (Integer) map.get(VERTICAL_TEXT_POSITION);
		if (intObj != null)
			return intObj.intValue();
		return JLabel.BOTTOM;
	}

	/**
	 * Sets the opaque attribute in the specified map to the specified value.
	 */
	public static final void setHorizontalTextPosition(Map map, int width) {
		map.put(HORIZONTAL_TEXT_POSITION, new Integer(width));
	}

	/**
	 * Returns the opaque attribute from the specified map.
	 */
	public static final int getHorizontalTextPosition(Map map) {
		Integer intObj = (Integer) map.get(HORIZONTAL_TEXT_POSITION);
		if (intObj != null)
			return intObj.intValue();
		return JLabel.CENTER;
	}

	/**
	 * Sets the dash pattern attribute in the specified map to the specified value.
	 */
	public static final void setDashPattern(Map map, float[] value) {
		map.put(DASHPATTERN, value);
	}

	/**
	 * Returns the dash pattern attribute from the specified map.
	 */
	public static final float[] getDashPattern(Map map) {
		return (float[]) map.get(DASHPATTERN);
	}

	/**
	 * Sets the dash offset attribute in the specified map to the specified value.
	 */
	public static final void setDashOffset(Map map, float value) {
		map.put(DASHOFFSET, new Float(value));
	}

	/**
	 * Returns the dash offset attribute from the specified map.
	 */
	public static final float getDashOffset(Map map) {
		Float floatObj = (Float) map.get(DASHOFFSET);
		if (floatObj != null)
			return floatObj.floatValue();
		return 1;
	}
		
	/**
	 * Sets the opaque attribute in the specified map to the specified value.
	 */
	public static final void setLineStyle(Map map, int style) {
		map.put(LINESTYLE, new Integer(style));
	}

	/**
	 * Returns the opaque attribute from the specified map.
	 */
	public static final int getLineStyle(Map map) {
		Integer intObj = (Integer) map.get(LINESTYLE);
		if (intObj != null)
			return intObj.intValue();
		return STYLE_ORTHOGONAL;
	}

	/**
	 * Sets the opaque attribute in the specified map to the specified value.
	 */
	public static final void setBeginSize(Map map, int style) {
		map.put(BEGINSIZE, new Integer(style));
	}

	/**
	 * Returns the opaque attribute from the specified map.
	 */
	public static final int getBeginSize(Map map) {
		Integer intObj = (Integer) map.get(BEGINSIZE);
		if (intObj != null)
			return intObj.intValue();
		return DEFAULTDECORATIONSIZE;
	}

	/**
	 * Sets the opaque attribute in the specified map to the specified value.
	 */
	public static final void setEndSize(Map map, int style) {
		map.put(ENDSIZE, new Integer(style));
	}

	/**
	 * Returns the opaque attribute from the specified map.
	 */
	public static final int getEndSize(Map map) {
		Integer intObj = (Integer) map.get(ENDSIZE);
		if (intObj != null)
			return intObj.intValue();
		return DEFAULTDECORATIONSIZE;
	}

	/**
	 * Sets the opaque attribute in the specified map to the specified value.
	 */
	public static final void setLineBegin(Map map, int style) {
		map.put(LINEBEGIN, new Integer(style));
	}

	/**
	 * Returns the opaque attribute from the specified map.
	 */
	public static final int getLineBegin(Map map) {
		Integer intObj = (Integer) map.get(LINEBEGIN);
		if (intObj != null)
			return intObj.intValue();
		return ARROW_NONE;
	}

	/**
	 * Sets the opaque attribute in the specified map to the specified value.
	 */
	public static final void setLineEnd(Map map, int style) {
		map.put(LINEEND, new Integer(style));
	}

	/**
	 * Returns the opaque attribute from the specified map.
	 */
	public static final int getLineEnd(Map map) {
		Integer intObj = (Integer) map.get(LINEEND);
		if (intObj != null)
			return intObj.intValue();
		return ARROW_NONE;
	}

	/**
	 * Sets the value attribute in the specified map to the specified value.
	 */
	public static final void setValue(Map map, Object value) {
		map.put(VALUE, value);
	}

	/**
	 * Returns the value attribute from the specified map.
	 */
	public static final Object getValue(Map map) {
		return map.get(VALUE);
	}

	/**
	 * Sets the label position attribute in the specified map to the specified
	 * value.
	 */
	public static final void setLabelPosition(Map map, Point position) {
		map.put(LABELPOSITION, position);
	}

	/**
	 * Returns the label position attribute from the specified map.
	 */
	public static final Point getLabelPosition(Map map) {
		return (Point) map.get(LABELPOSITION);
	}
	
	/**
	 * Sets the array of additional labels.
	 */
	public static final void setExtraLabels(Map map, Object[] definitions) {
		map.put(EXTRALABELS, definitions);
	}

	/**
	 * Returns the label position attribute from the specified map.
	 */
	public static final String[] getExtraLabels(Map map) {
		return (String[]) map.get(EXTRALABELS);
	}


	/**
	 * Sets the label position attribute in the specified map to the specified
	 * value.
	 */
	public static final void setExtraLabelPositions(Map map, Point[] positions) {
		map.put(EXTRALABELPOSITIONS, positions);
	}

	/**
	 * Returns the label position attribute from the specified map.
	 */
	public static final Point[] getExtraLabelPositions(Map map) {
		return (Point[]) map.get(EXTRALABELPOSITIONS);
	}

	/**
	 * Sets if the label should be painted along the edge.
	 */
	public static final void setLabelAlongEdge(Map map, boolean flag) {
		map.put(LABELALONGEDGE, new Boolean(flag));
	}

	/**
	 * Returns the true if the label should be painted along the edge. Defaults
	 * to false.
	 */
	public static final boolean isLabelAlongEdge(Map map) {
		Boolean bool = (Boolean) map.get(LABELALONGEDGE);
		if (bool != null)
			return bool.booleanValue();
		return false;
	}

	/**
	 * Sets the editable attribute in the specified map to the specified value.
	 */
	public static final void setEditable(Map map, boolean flag) {
		map.put(EDITABLE, new Boolean(flag));
	}

	/**
	 * Returns the editable attribute from the specified map.
	 */
	public static final boolean isEditable(Map map) {
		Boolean bool = (Boolean) map.get(EDITABLE);
		if (bool != null)
			return bool.booleanValue();
		return true;
	}

	/**
	 * Sets the moveable attribute in the specified map to the specified value.
	 */
	public static final void setMoveable(Map map, boolean flag) {
		map.put(MOVEABLE, new Boolean(flag));
	}

	/**
	 * Returns the moveable attribute from the specified map.
	 */
	public static final boolean isMoveable(Map map) {
		Boolean bool = (Boolean) map.get(MOVEABLE);
		if (bool != null)
			return bool.booleanValue();
		return true;
	}

	/**
	 * Sets the sizeable attribute in the specified map to the specified value.
	 */
	public static final void setSizeable(Map map, boolean flag) {
		map.put(SIZEABLE, new Boolean(flag));
	}

	/**
	 * Returns the sizeable attribute from the specified map.
	 */
	public static final boolean isSizeable(Map map) {
		Boolean bool = (Boolean) map.get(SIZEABLE);
		if (bool != null)
			return bool.booleanValue();
		return true;
	}

	/**
	 * Sets the autosize attribute in the specified map to the specified value.
	 */
	public static final void setAutoSize(Map map, boolean flag) {
		map.put(AUTOSIZE, new Boolean(flag));
	}

	/**
	 * Returns the autosize attribute from the specified map.
	 */
	public static final boolean isAutoSize(Map map) {
		Boolean bool = (Boolean) map.get(AUTOSIZE);
		if (bool != null)
			return bool.booleanValue();
		return false;
	}
	
	/**
	 * Sets the autosize attribute in the specified map to the specified value.
	 */
	public static final void setResize(Map map, boolean flag) {
		map.put(RESIZE, new Boolean(flag));
	}

	/**
	 * Returns the autosize attribute from the specified map.
	 */
	public static final boolean isResize(Map map) {
		Boolean bool = (Boolean) map.get(RESIZE);
		if (bool != null)
			return bool.booleanValue();
		return false;
	}

	/**
	 * Sets the bendable attribute in the specified map to the specified value.
	 */
	public static final void setBendable(Map map, boolean flag) {
		map.put(BENDABLE, new Boolean(flag));
	}

	/**
	 * Returns the bendable attribute from the specified map.
	 */
	public static final boolean isBendable(Map map) {
		Boolean bool = (Boolean) map.get(BENDABLE);
		if (bool != null)
			return bool.booleanValue();
		return true;
	}

	/**
	 * Sets the connectable attribute in the specified map to the specified
	 * value.
	 */
	public static final void setConnectable(Map map, boolean flag) {
		map.put(CONNECTABLE, new Boolean(flag));
	}

	/**
	 * Returns the connectable attribute from the specified map.
	 */
	public static final boolean isConnectable(Map map) {
		Boolean bool = (Boolean) map.get(CONNECTABLE);
		if (bool != null)
			return bool.booleanValue();
		return true;
	}

	/**
	 * Sets the disconnectable attribute in the specified map to the specified
	 * value.
	 */
	public static final void setDisconnectable(Map map, boolean flag) {
		map.put(DISCONNECTABLE, new Boolean(flag));
	}

	/**
	 * Returns the disconnectable attribute from the specified map.
	 */
	public static final boolean isDisconnectable(Map map) {
		Boolean bool = (Boolean) map.get(DISCONNECTABLE);
		if (bool != null)
			return bool.booleanValue();
		return true;
	}

	/**
	 * Sets the points attribute in the specified map to the specified value.
	 */
	public static final void setPoints(Map map, java.util.List list) {
		map.put(POINTS, list);
	}

	/**
	 * Returns the points attribute from the specified map.
	 */
	public static final java.util.List getPoints(Map map) {
		return (java.util.List) map.get(POINTS);
	}

	/**
	 * Sets the routing attribute in the specified map to the specified value.
	 */
	public static final void setRouting(Map map, Edge.Routing routing) {
		map.put(ROUTING, routing);
	}

	/**
	 * Returns the routing attribute from the specified map.
	 */
	public static final Edge.Routing getRouting(Map map) {
		return (Edge.Routing) map.get(ROUTING);
	}

	/**
	 * Sets the bounds attribute in the specified map to the specified value.
	 */
	public static final void setBounds(Map map, Rectangle2D bounds) {
		map.put(BOUNDS, bounds);
	}

	/**
	 * Returns the bounds attribute from the specified map. Note: The CellView
	 * interface offers a getBounds method!
	 */
	public static final Rectangle2D getBounds(Map map) {
		return (Rectangle2D) map.get(BOUNDS);
	}

	/**
	 * Sets the bounds attribute in the specified map to the specified value.
	 */
	public static final void setGroupBorder(Map map, int width) {
		map.put(GROUPBORDER, new Integer(width));
	}

	/**
	 * Returns the bounds attribute from the specified map. Note: The CellView
	 * interface offers a getBounds method!
	 */
	public static final int getGroupBorder(Map map) {
		Integer intObj = (Integer) map.get(GROUPBORDER);
		if (intObj != null)
			return intObj.intValue();
		return DEFAULTGROUPBORDER;
	}

	/**
	 * Sets the size attribute in the specified map to the specified value.
	 */
	public static final void setSize(Map map, Dimension size) {
		map.put(SIZE, size);
	}

	/**
	 * Returns the size attribute from the specified map.
	 */
	public static final Dimension getSize(Map map) {
		return (Dimension) map.get(SIZE);
	}

	/**
	 * Sets the offset attribute in the specified map to the specified value.
	 */
	public static final void setOffset(Map map, Point2D offset) {
		map.put(OFFSET, offset);
	}

	/**
	 * Returns the offset attribute from the specified map.
	 */
	public static final Point2D getOffset(Map map) {
		return (Point2D) map.get(OFFSET);
	}

	/**
	 * Sets the offset attribute in the specified map to the specified value.
	 */
	public static final void setBeginFill(Map map, boolean flag) {
		map.put(BEGINFILL, new Boolean(flag));
	}

	/**
	 * Returns the offset attribute from the specified map.
	 */
	public static final boolean isBeginFill(Map map) {
		Boolean bool = (Boolean) map.get(BEGINFILL);
		if (bool != null)
			return bool.booleanValue();
		return false;
	}

	/**
	 * Sets the offset attribute in the specified map to the specified value.
	 */
	public static final void setEndFill(Map map, boolean flag) {
		map.put(ENDFILL, new Boolean(flag));
	}

	/**
	 * Returns the offset attribute from the specified map.
	 */
	public static final boolean isEndFill(Map map) {
		Boolean bool = (Boolean) map.get(ENDFILL);
		if (bool != null)
			return bool.booleanValue();
		return false;
	}

	/**
	 * Sets the offset attribute in the specified map to the specified value.
	 */
	public static final void setAbsolute(Map map, boolean flag) {
		setAbsoluteX(map, flag);
		setAbsoluteY(map, flag);
	}

	/**
	 * Sets the offset attribute in the specified map to the specified value.
	 */
	public static final void setAbsoluteY(Map map, boolean flag) {
		map.put(ABSOLUTEY, new Boolean(flag));
	}

	/**
	 * Returns the offset attribute from the specified map.
	 */
	public static final boolean isAbsoluteY(Map map) {
		Boolean bool = (Boolean) map.get(ABSOLUTEY);
		if (bool != null)
			return bool.booleanValue();
		return false;
	}

	/**
	 * Sets the offset attribute in the specified map to the specified value.
	 */
	public static final void setAbsoluteX(Map map, boolean flag) {
		map.put(ABSOLUTEX, new Boolean(flag));
	}

	/**
	 * Returns the offset attribute from the specified map.
	 */
	public static final boolean isAbsoluteX(Map map) {
		Boolean bool = (Boolean) map.get(ABSOLUTEX);
		if (bool != null)
			return bool.booleanValue();
		return false;
	}

	/**
	 * Sets the offset attribute in the specified map to the specified value.
	 */
	public static final void setRemoveAll(Map map, boolean flag) {
		map.put(REMOVEALL, new Boolean(flag));
	}

	/**
	 * Returns the offset attribute from the specified map.
	 */
	public static final boolean isRemoveAll(Map map) {
		Boolean bool = (Boolean) map.get(REMOVEALL);
		if (bool != null)
			return bool.booleanValue();
		return false;
	}

}
