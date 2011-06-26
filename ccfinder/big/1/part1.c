/* xg.c: Guile and Ruby bindings for gdk/gtk/pango, some of glib
 *   this file generated automatically from makexg.scm and xgdata.scm
 *   needs xen.h
 *
 *   compile-time flags:
 *     HAVE_GDK_DRAW_PIXBUF for gtk+-2.1 additions
 *     GTK_CELL_RENDERER_FOCUSED for gtk+-2.2
 *     HAVE_GTK_FILE_CHOOSER_DIALOG_NEW for gtk+-2.3
 *     HAVE_GTK_EXPANDER_GET_USE_MARKUP for gtk+-2.3.1
 *     HAVE_GTK_MENU_SHELL_CANCEL for gtk+-2.3.2
 *     HAVE_GTK_COMBO_BOX_POPUP for gtk+-2.3.4
 *     HAVE_GTK_COMBO_BOX_ENTRY_NEW_TEXT for gtk+-2.3.5
 *     HAVE_GBOOLEAN_GTK_FILE_CHOOSER_SET_FILENAME for gtk+-2.3.6
 *     HAVE_GTK_ABOUT_DIALOG_NEW for gtk+-2.5.0
 *     HAVE_GTK_LABEL_SET_ELLIPSIZE for gtk+-2.5.1
 *     HAVE_GTK_FILE_CHOOSER_BUTTON_NEW for gtk+-2.5.2
 *     HAVE_GTK_MENU_TOOL_BUTTON_NEW for gtk+-2.5.3 and 2.5.4
 *     HAVE_GTK_LABEL_GET_SINGLE_LINE_MODE for gtk+-2.5.5
 *
 * reference args initial values are usually ignored, resultant values are returned in a list.
 * null ptrs are passed and returned as #f, trailing "user_data" callback function arguments are optional (default: #f).
 * where supported, "..." args are passed as a list, trailing NULL or -1 should be omitted.
 * 'xg is added to *features*
 *
 * added funcs:
 *    (xm-version) -> date string.
 *    (->string val) interprets 'val' as a string.
 *    (c-array->list arr len) derefs each member of arr, returning lisp list, len=#f: null terminated array
 *    (list->c-array lst ctype) packages each member of list as c-type "type" returning (wrapped) c array
 *    (make-target-entry lst) returns a GtkTargetEntry table, each member of 'lst' should be (list target flags info)
 *    (GdkColor #:optional pixel red green blue) -> GdkColor struct
 *    (GdkCursor #:optional type ref_count) -> GdkCursor struct
 *    (GdkPoint #:optional x y) -> GdkPoint struct
 *    (GdkRectangle #:optional x y width height) -> GdkRectangle struct
 *    (GtkStockItem) -> GtkStockItem struct
 *    (GtkTextIter) -> GtkTextIter struct
 *    (GtkTreeIter) -> GtkTreeIter struct
 *    (GtkRequisition #:optional width height) -> GtkRequisition struct
 *    (PangoColor) -> PangoColor struct
 *    (PangoRectangle) -> PangoRectangle struct
 *    (PangoLogAttr) -> PangoLogAttr struct
 *
 * omitted functions and macros:
 *     anything with a va_list or GtkArg* argument.
 *     most of the unusual keysym names
 *     all *_CLASS, *_IFACE macros
 *     win32-specific functions
 *
 * HISTORY:
 *     15-Nov:    gtk 2.5.5 changes.
 *     29-Oct:    gtk 2.5.4 changes.
 *     27-Aug:    gtk 2.5.2 changes. removed the PANGO_ENGINE and PANGO_BACKEND stuff.
 *     5-Aug:     gtk 2.5.1 changes.
 *     21-Jul:    gtk 2.5.0 changes.
 *     2-Jun:     gdk_atom_name needs to free return value
 *     28-May:    GtkFileSelection struct support put back in -- need ok_button et al.
 *     14-Apr:    make-target-entry.
 *     4-Apr:     various additions, deletions, and bugfixes for snd-test 26
 *     29-Mar:    support for some ... args.
 *     22-Mar:    g_source_remove and related changes.
 *     11-Mar:    gtk 2.3.6 changes.
 *     4-Mar:     gtk 2.3.5 changes.
 *     26-Feb:    gtk 3.2.4 changes.
 *     12-Feb:    g_list_nth_data (Kjetil S. Matheussen).
 *     6-Feb:     gtk 2.3.2 changes.
 *     --------
 *     16-Dec:    gtk 2.3.1 changes.
 *     1-Dec:     gtk 2.3 changes.
 *     15-Sep:    removed client_window GtkIMMulticontext struct field (for Gtk 2.2.4).
 *     26-May:    removed nugatory GdkInputFunction stuff and some unused type converters.
 *     7-Apr:     GTK_RC_STYLE has two incompatible definitions in gtk! (gtkwidget.h, gtkrc.h) -- will use int case.
 *     1-Apr:     gdk_property_get uses scm_mem2string in some cases now.
 *     31-Mar:    gchar* -> xen string bugfix (thanks to Friedrich Delgado Friedrichs).
 *     10-Mar:    Ruby Xm_Version.
 *     6-Jan-03:  gtk 2.2 changes.
 *     --------
 *     18-Nov:    Ruby/Gtk bugfixes.
 *     28-Oct:    gtk 2.1 additions.
 *     25-Oct:    removed (deprecated) gdk_set_pointer_hooks
 *     31-Jul:    removed GTK 1.n support
 *     24-Jul:    changed Guile prefix (R5RS reserves vertical-bar).
 *     19-Jul:    XG_FIELD_PRE for change from using vertical-bar (reserved in R5RS)
 *     2-Jun:     removed deprecated and broken stuff
 *     4-Apr:     minor changes for Gtk 2.0.2
 *     13-Mar:    Gtk 2.0.0
 *     12-Mar:    support for GtkDestroyNotify callbacks
 *     27-Feb:    remove gtk_tree_view_column_cell_render, gtk_tree_view_column_cell_focus, 
 *                  gtk_tree_view_column_cell_draw_focus and gtk_tree_view_column_cell_set_dirty (privatized in 1.3.15)
 *                add (on HAVE-* switches) gtk_file_selection_get_selections, gtk_file_selection_set_select_multiple
 *                  and gtk_file_selection_get_select_multiple (new functions in 1.3.15)
 *                  also gtk_tree_path_new_first void and gtk_tree_model_get_iter_first (new names in 1.3.15)
 *     26-Feb:    Gtk 1.2.10 support, also 1.3.15
 *     25-Feb:    dialog example in libxm.html
 *                Ruby support via xg-ruby.c
 *     21-Feb:    #f=NULL throughout, gdk-pixbuf, GTypes.
 *     11-Feb-02: initial version.
 */

#include <config.h>

#if UNDEF_USE_SND
  #undef USE_SND
  #define USE_SND 0
#endif

#include <glib.h>
#include <gdk/gdk.h>
#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>
#include <glib-object.h>
#include <pango/pango.h>
#include <string.h>
#include <stdlib.h>

#if USE_SND
  /* USE_SND causes xm to use Snd's error handlers which are much smarter than xen's fallback versions */
  #include "snd.h"
#else
  #include "xen.h"
#endif
#ifndef CALLOC
  #define CALLOC(a, b)  calloc((size_t)(a), (size_t)(b))
  #define FREE(a)       free(a)
#endif

/* -------------------------------- smob for GC -------------------------------- */
static XEN_OBJECT_TYPE xm_obj_tag;
#if HAVE_GUILE
static size_t xm_obj_free(XEN obj)
{
  void *val;
  val = (void *)XEN_OBJECT_REF(obj);
  FREE(val);
  return(0);
}
#endif
#if HAVE_RUBY
static void *xm_obj_free(XEN obj)
{
  FREE((void *)obj);
  return(NULL);
}
#endif
static XEN make_xm_obj(void *ptr)
{
  XEN_MAKE_AND_RETURN_OBJECT(xm_obj_tag, ptr, 0, xm_obj_free);
}
static void define_xm_obj(void)
{
  xm_obj_tag = XEN_MAKE_OBJECT_TYPE("XmObj", sizeof(void *));
#if HAVE_GUILE
  scm_set_smob_free(xm_obj_tag, xm_obj_free);
#endif
}  

/* prefix for all names */
#if HAVE_GUILE
  #define XG_PRE ""
  #define XG_FIELD_PRE "."
  #define XG_POST ""
#else
/* for Ruby, XG PRE needs to be uppercase */
  #define XG_PRE "R"
  #define XG_POST ""
  #define XG_FIELD_PRE "R"
#endif

#define WRAP_FOR_XEN(Name, Value) XEN_LIST_2(C_STRING_TO_XEN_SYMBOL(Name), C_TO_XEN_ULONG((unsigned long)Value))
#define WRAP_P(Name, Value) (XEN_LIST_P(Value) && \
                            (XEN_LIST_LENGTH(Value) >= 2) && \
                            (XEN_SYMBOL_P(XEN_CAR(Value))) && \
                            (strcmp(Name, XEN_SYMBOL_TO_C_STRING(XEN_CAR(Value))) == 0))

#define XM_TYPE(Name, XType) \
  static XEN C_TO_XEN_ ## Name (XType val) {return(WRAP_FOR_XEN(#Name, val));} \
  static XType XEN_TO_C_ ## Name (XEN val) {return((XType)XEN_TO_C_ULONG(XEN_CADR(val)));} \
  static bool XEN_ ## Name ## _P(XEN val) {return(WRAP_P(#Name, val));}

#define XM_TYPE_1(Name, XType) \
  static XType XEN_TO_C_ ## Name (XEN val) {return((XType)XEN_TO_C_ULONG(XEN_CADR(val)));} \
  static bool XEN_ ## Name ## _P(XEN val) {return(WRAP_P(#Name, val));}

#define XM_TYPE_NO_P(Name, XType) \
  static XEN C_TO_XEN_ ## Name (XType val) {return(WRAP_FOR_XEN(#Name, val));} \
  static XType XEN_TO_C_ ## Name (XEN val) {return((XType)XEN_TO_C_ULONG(XEN_CADR(val)));} \

#define XM_TYPE_NO_P_2(Name, XType) \
  static XEN C_TO_XEN_ ## Name (XType val) {return(WRAP_FOR_XEN(#Name, val));}

#define XM_TYPE_PTR(Name, XType) \
  static XEN C_TO_XEN_ ## Name (XType val) {if (val) return(WRAP_FOR_XEN(#Name, val)); return(XEN_FALSE);} \
  static XType XEN_TO_C_ ## Name (XEN val) {if (XEN_FALSE_P(val)) return(NULL); return((XType)XEN_TO_C_ULONG(XEN_CADR(val)));} \
  static bool XEN_ ## Name ## _P(XEN val) {return(XEN_FALSE_P(val) || (WRAP_P(#Name, val)));} /* if NULL ok, should be explicit? */

#define XM_TYPE_PTR_NO_P(Name, XType) \
  static XEN C_TO_XEN_ ## Name (XType val) {if (val) return(WRAP_FOR_XEN(#Name, val)); return(XEN_FALSE);} \
  static XType XEN_TO_C_ ## Name (XEN val) {if (XEN_FALSE_P(val)) return(NULL); return((XType)XEN_TO_C_ULONG(XEN_CADR(val)));} \

#define XM_TYPE_PTR_1(Name, XType) \
  static XType XEN_TO_C_ ## Name (XEN val) {if (XEN_FALSE_P(val)) return(NULL); return((XType)XEN_TO_C_ULONG(XEN_CADR(val)));} \
  static bool XEN_ ## Name ## _P(XEN val) {return(XEN_FALSE_P(val) || (WRAP_P(#Name, val)));} /* if NULL ok, should be explicit? */

#define XM_TYPE_PTR_2(Name, XType) \
  static XEN C_TO_XEN_ ## Name (XType val) {if (val) return(WRAP_FOR_XEN(#Name, val)); return(XEN_FALSE);} \

/* type checks for callback wrappers */
#define XEN_lambda2_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 2)))
#define XEN_lambda3_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 3)))
#define XEN_GtkCallback_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 2)))
#define XEN_GSourceFunc_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 1)))
#define XEN_GtkDestroyNotify_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 1)))
#define XEN_GdkFilterFunc_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 3)))
#define XEN_GdkEventFunc_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 2)))
#define XEN_GtkFunction_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 1)))
#define XEN_GtkKeySnoopFunc_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 3)))
#define XEN_GtkMenuPositionFunc_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 5)))
#define XEN_GtkTextTagTableForeach_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 2)))
#define XEN_GtkAccelMapForeach_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 5)))
#define XEN_GtkTreeModelForeachFunc_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 4)))
#define XEN_GtkTreeSelectionForeachFunc_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 4)))
#define XEN_GtkClipboardReceivedFunc_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 3)))
#define XEN_GtkClipboardTextReceivedFunc_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 3)))
#define XEN_GtkClipboardTargetsReceivedFunc_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 4)))
#define XEN_GtkMenuPositionFunc_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 5)))
#define XEN_GtkTextCharPredicate_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 2)))
#define XEN_GtkTreeViewColumnDropFunc_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 5)))
#define XEN_GtkTreeViewMappingFunc_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 3)))
#define XEN_GtkTreeViewSearchEqualFunc_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 5)))
#define XEN_GtkTreeCellDataFunc_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 5)))
#define XEN_GtkTreeIterCompareFunc_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 4)))
#define XEN_GtkTreeSelectionFunc_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 5)))
#define XEN_GtkClipboardGetFunc_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 4)))
#define XEN_GtkClipboardClearFunc_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 2)))
#if HAVE_GTK_FILE_CHOOSER_DIALOG_NEW
#define XEN_GtkFileFilterFunc_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 2)))
#define XEN_GtkEntryCompletionMatchFunc_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 4)))
#endif

#if HAVE_GTK_ABOUT_DIALOG_NEW
#define XEN_GtkTreeViewRowSeparatorFunc_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 3)))
#define XEN_GtkIconViewForeachFunc_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 3)))
#endif

#if HAVE_GTK_LABEL_GET_SINGLE_LINE_MODE
#define XEN_GtkClipboardImageReceivedFunc_P(Arg)  XEN_FALSE_P(Arg) || (XEN_PROCEDURE_P(Arg) && (XEN_REQUIRED_ARGS_OK(Arg, 3)))
#endif

#define XEN_lambda_P(Arg) XEN_PROCEDURE_P(Arg)
#define XEN_GCallback_P(Arg) XEN_PROCEDURE_P(Arg) && ((XEN_REQUIRED_ARGS_OK(Arg, 2)) || (XEN_REQUIRED_ARGS_OK(Arg, 3)))
#define XEN_TO_C_lambda2(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_child_func
#define XEN_TO_C_lambda3(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_find_func
#define XEN_TO_C_GtkCallback(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_func2
#define XEN_TO_C_GSourceFunc(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_timer_func
#define XEN_TO_C_GtkDestroyNotify(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_destroy_func
#define XEN_TO_C_GdkFilterFunc(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_filter_func
#define XEN_TO_C_GdkEventFunc(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_event_func
#define XEN_TO_C_GtkFunction(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_func1
#define XEN_TO_C_GtkKeySnoopFunc(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_snoop_func
#define XEN_TO_C_GtkMenuPositionFunc(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_menu_position_func
#define XEN_TO_C_GtkTextTagTableForeach(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_text_tag_table_foreach
#define XEN_TO_C_GtkAccelMapForeach(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_accel_map_foreach
#define XEN_TO_C_GtkTreeModelForeachFunc(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_model_func
#define XEN_TO_C_GtkTreeSelectionForeachFunc(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_tree_selection_func
#define XEN_TO_C_GtkClipboardReceivedFunc(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_clip_received
#define XEN_TO_C_GtkClipboardTextReceivedFunc(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_clip_text_received
#define XEN_TO_C_GtkClipboardTargetsReceivedFunc(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_clip_targets_received
#define XEN_TO_C_GtkMenuPositionFunc(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_menu_position_func
#define XEN_TO_C_GtkTextCharPredicate(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_text_char_predicate
#define XEN_TO_C_GtkTreeViewColumnDropFunc(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_tree_column
#define XEN_TO_C_GtkTreeViewMappingFunc(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_tree_mapping
#define XEN_TO_C_GtkTreeViewSearchEqualFunc(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_tree_search
#define XEN_TO_C_GtkTreeCellDataFunc(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_cell_data
#define XEN_TO_C_GtkTreeIterCompareFunc(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_iter_compare
#define XEN_TO_C_GtkTreeSelectionFunc(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_tree_selection
#define XEN_TO_C_GtkClipboardGetFunc(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_clip_get
#define XEN_TO_C_GtkClipboardClearFunc(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_clip_clear
#if HAVE_GTK_FILE_CHOOSER_DIALOG_NEW
#define XEN_TO_C_GtkFileFilterFunc(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_file_filter
#define XEN_TO_C_GtkEntryCompletionMatchFunc(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_entry_completion_match
#endif

#if HAVE_GTK_ABOUT_DIALOG_NEW
#define XEN_TO_C_GtkTreeViewRowSeparatorFunc(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_row_separator
#define XEN_TO_C_GtkIconViewForeachFunc(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_icon_view_foreach
#endif

#if HAVE_GTK_LABEL_GET_SINGLE_LINE_MODE
#define XEN_TO_C_GtkClipboardImageReceivedFunc(Arg) XEN_FALSE_P(Arg) ? NULL : gxg_clip_image_received
#endif

#define XEN_TO_C_GCallback(Arg) ((XEN_REQUIRED_ARGS_OK(Arg, 3)) ? (GCallback)gxg_func3 : (GCallback)gxg_func2)
#define XEN_TO_C_lambda_data(Arg) (gpointer)gxg_ptr
#define XEN_lambda_data_P(Arg) 1
#define C_TO_XEN_GtkTreeViewSearchEqualFunc(Arg) WRAP_FOR_XEN("GtkTreeViewSearchEqualFunc", Arg)
#define C_TO_XEN_GtkTreeIterCompareFunc(Arg) WRAP_FOR_XEN("GtkTreeViewSearchEqualFunc", Arg)
#define C_TO_XEN_GtkTreeSelectionFunc(Arg) WRAP_FOR_XEN("GtkTreeSelectionFunc", Arg)
#define C_TO_XEN_GtkMenuPositionFunc(Arg) WRAP_FOR_XEN("GtkMenuPositionFunc", Arg)
#define C_TO_XEN_GtkDestroyNotify(Arg) WRAP_FOR_XEN("GtkDestroyNotify", Arg)
#define XEN_TO_C_GdkFilterReturn(Arg) (GdkFilterReturn)XEN_TO_C_INT(Arg)
#define XEN_TO_C_String(Arg) ((XEN_STRING_P(Arg)) ? XEN_TO_C_STRING(Arg) : NULL)
#define C_TO_XEN_String(Arg) ((Arg != NULL) ? C_TO_XEN_STRING(Arg) : XEN_FALSE)
#define XEN_String_P(Arg) ((XEN_FALSE_P(Arg)) || (XEN_STRING_P(Arg)))

#ifdef GTK_CELL_RENDERER_FOCUSED
  static GdkDrawable* XEN_TO_C_DRAWABLE_WAS_WINDOW (XEN val) {if (XEN_FALSE_P(val)) return(NULL); return((GdkDrawable *)XEN_TO_C_ULONG(XEN_CADR(val)));}
  static bool XEN_DRAWABLE_WAS_WINDOW_P(XEN val) {return(XEN_FALSE_P(val) || (WRAP_P("GdkDrawable_", val)));}
  #define Drawable_was_Window GdkDrawable
#else
  static GdkWindow* XEN_TO_C_DRAWABLE_WAS_WINDOW (XEN val) {if (XEN_FALSE_P(val)) return(NULL); return((GdkWindow *)XEN_TO_C_ULONG(XEN_CADR(val)));}
  static bool XEN_DRAWABLE_WAS_WINDOW_P(XEN val) {return(XEN_FALSE_P(val) || (WRAP_P("GdkWindow_", val)));}
  #define Drawable_was_Window GdkWindow
#endif


/* ---------------------------------------- types ---------------------------------------- */

XM_TYPE_PTR(GdkWindow_, GdkWindow*)
XM_TYPE_PTR(GtkAccelKey_, GtkAccelKey*)
XM_TYPE_PTR(GClosure_, GClosure*)
XM_TYPE_PTR(GtkWidget_, GtkWidget*)
XM_TYPE_PTR_2(GdkXEvent_, GdkXEvent*)
XM_TYPE_PTR(GdkEvent_, GdkEvent*)
XM_TYPE_PTR(GdkEventKey_, GdkEventKey*)
XM_TYPE_PTR(GtkMenu_, GtkMenu*)
XM_TYPE_PTR(gint_, gint*)
XM_TYPE_PTR(gboolean_, gboolean*)
XM_TYPE_PTR(GtkTextTag_, GtkTextTag*)
#define C_TO_XEN_gchar_(Arg) C_TO_XEN_String(Arg)
#define XEN_TO_C_gchar_(Arg) (gchar*)(XEN_TO_C_String(Arg))
#define XEN_gchar__P(Arg) XEN_String_P(Arg)
#define C_TO_XEN_guint(Arg) C_TO_XEN_ULONG(Arg)
#define XEN_TO_C_guint(Arg) (guint)(XEN_TO_C_ULONG(Arg))
#define XEN_guint_P(Arg) XEN_ULONG_P(Arg)
#define C_TO_XEN_GdkModifierType(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkModifierType(Arg) (GdkModifierType)(XEN_TO_C_INT(Arg))
#define XEN_GdkModifierType_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_gboolean(Arg) C_TO_XEN_BOOLEAN(Arg)
#define XEN_TO_C_gboolean(Arg) (gboolean)(XEN_TO_C_BOOLEAN(Arg))
#define XEN_gboolean_P(Arg) XEN_BOOLEAN_P(Arg)
XM_TYPE_PTR(GtkTreeModel_, GtkTreeModel*)
XM_TYPE_PTR(GtkTreePath_, GtkTreePath*)
XM_TYPE_PTR(GtkTreeIter_, GtkTreeIter*)
XM_TYPE_PTR(GtkClipboard_, GtkClipboard*)
XM_TYPE_PTR(GtkSelectionData_, GtkSelectionData*)
XM_TYPE_PTR_2(GdkAtom_, GdkAtom*)
#define C_TO_XEN_gint(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_gint(Arg) (gint)(XEN_TO_C_INT(Arg))
#define XEN_gint_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_gunichar(Arg) C_TO_XEN_ULONG(Arg)
#define XEN_TO_C_gunichar(Arg) (gunichar)(XEN_TO_C_ULONG(Arg))
#define XEN_gunichar_P(Arg) XEN_ULONG_P(Arg)
XM_TYPE_PTR(GtkTreeView_, GtkTreeView*)
XM_TYPE_PTR(GtkTreeViewColumn_, GtkTreeViewColumn*)
XM_TYPE_PTR(GtkCellRenderer_, GtkCellRenderer*)
XM_TYPE_PTR(GtkTreeSelection_, GtkTreeSelection*)
XM_TYPE_PTR(GdkPixbuf_, GdkPixbuf*)
#define C_TO_XEN_GType(Arg) C_TO_XEN_ULONG(Arg)
#define XEN_TO_C_GType(Arg) (GType)(XEN_TO_C_ULONG(Arg))
#define XEN_GType_P(Arg) XEN_ULONG_P(Arg)
#define C_TO_XEN_GQuark(Arg) C_TO_XEN_ULONG(Arg)
#define XEN_TO_C_GQuark(Arg) (GQuark)(XEN_TO_C_ULONG(Arg))
#define XEN_GQuark_P(Arg) XEN_ULONG_P(Arg)
XM_TYPE_PTR_1(GClosureNotify, GClosureNotify)
#define C_TO_XEN_GSignalFlags(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GSignalFlags(Arg) (GSignalFlags)(XEN_TO_C_INT(Arg))
#define XEN_GSignalFlags_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_1(GSignalAccumulator, GSignalAccumulator)
XM_TYPE_PTR(gpointer, gpointer)
XM_TYPE_1(GSignalCMarshaller, GSignalCMarshaller)
XM_TYPE_PTR_1(GType_, GType*)
XM_TYPE_PTR_1(GSignalQuery_, GSignalQuery*)
XM_TYPE_PTR(guint_, guint*)
XM_TYPE_PTR_2(GSignalInvocationHint_, GSignalInvocationHint*)
#define C_TO_XEN_gulong(Arg) C_TO_XEN_ULONG(Arg)
#define XEN_TO_C_gulong(Arg) (gulong)(XEN_TO_C_ULONG(Arg))
#define XEN_gulong_P(Arg) XEN_ULONG_P(Arg)
XM_TYPE_1(GSignalEmissionHook, GSignalEmissionHook)
#define C_TO_XEN_GConnectFlags(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GConnectFlags(Arg) (GConnectFlags)(XEN_TO_C_INT(Arg))
#define XEN_GConnectFlags_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GSignalMatchType(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GSignalMatchType(Arg) (GSignalMatchType)(XEN_TO_C_INT(Arg))
#define XEN_GSignalMatchType_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR(GdkColormap_, GdkColormap*)
XM_TYPE_PTR(GdkVisual_, GdkVisual*)
XM_TYPE_PTR(GdkColor_, GdkColor*)
XM_TYPE_PTR(GdkCursor_, GdkCursor*)
#define C_TO_XEN_GdkCursorType(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkCursorType(Arg) (GdkCursorType)(XEN_TO_C_INT(Arg))
#define XEN_GdkCursorType_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR(GdkPixmap_, GdkPixmap*)
XM_TYPE_PTR(GdkDragContext_, GdkDragContext*)
#define C_TO_XEN_GdkDragAction(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkDragAction(Arg) (GdkDragAction)(XEN_TO_C_INT(Arg))
#define XEN_GdkDragAction_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_guint32(Arg) C_TO_XEN_ULONG(Arg)
#define XEN_TO_C_guint32(Arg) (guint32)(XEN_TO_C_ULONG(Arg))
#define XEN_guint32_P(Arg) XEN_ULONG_P(Arg)
XM_TYPE(GdkAtom, GdkAtom)
XM_TYPE_PTR(GList_, GList*)
#define C_TO_XEN_GdkDragProtocol(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkDragProtocol(Arg) (GdkDragProtocol)(XEN_TO_C_INT(Arg))
#define XEN_GdkDragProtocol_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR(GdkDrawable_, GdkDrawable*)
XM_TYPE_PTR(GdkGC_, GdkGC*)
XM_TYPE_PTR(GdkPoint_, GdkPoint*)
XM_TYPE_PTR(GdkImage_, GdkImage*)
XM_TYPE_PTR_1(GdkSegment_, GdkSegment*)
XM_TYPE_PTR(PangoFont_, PangoFont*)
XM_TYPE_PTR(PangoGlyphString_, PangoGlyphString*)
XM_TYPE_PTR(PangoLayoutLine_, PangoLayoutLine*)
XM_TYPE_PTR(PangoLayout_, PangoLayout*)
XM_TYPE_PTR(GdkRegion_, GdkRegion*)
#define C_TO_XEN_gdouble(Arg) C_TO_XEN_DOUBLE(Arg)
#define XEN_TO_C_gdouble(Arg) (gdouble)(XEN_TO_C_DOUBLE(Arg))
#define XEN_gdouble_P(Arg) XEN_NUMBER_P(Arg)
#define C_TO_XEN_GdkAxisUse(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkAxisUse(Arg) (GdkAxisUse)(XEN_TO_C_INT(Arg))
#define XEN_GdkAxisUse_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GdkGCValues_, GdkGCValues*)
#define C_TO_XEN_GdkGCValuesMask(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkGCValuesMask(Arg) (GdkGCValuesMask)(XEN_TO_C_INT(Arg))
#define XEN_GdkGCValuesMask_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GdkFunction(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkFunction(Arg) (GdkFunction)(XEN_TO_C_INT(Arg))
#define XEN_GdkFunction_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GdkFill(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkFill(Arg) (GdkFill)(XEN_TO_C_INT(Arg))
#define XEN_GdkFill_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR(GdkBitmap_, GdkBitmap*)
XM_TYPE_PTR(GdkRectangle_, GdkRectangle*)
#define C_TO_XEN_GdkSubwindowMode(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkSubwindowMode(Arg) (GdkSubwindowMode)(XEN_TO_C_INT(Arg))
#define XEN_GdkSubwindowMode_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GdkLineStyle(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkLineStyle(Arg) (GdkLineStyle)(XEN_TO_C_INT(Arg))
#define XEN_GdkLineStyle_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GdkCapStyle(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkCapStyle(Arg) (GdkCapStyle)(XEN_TO_C_INT(Arg))
#define XEN_GdkCapStyle_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GdkJoinStyle(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkJoinStyle(Arg) (GdkJoinStyle)(XEN_TO_C_INT(Arg))
#define XEN_GdkJoinStyle_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(gint8_, gint8*)
XM_TYPE_PTR(gchar__, gchar**)
#define C_TO_XEN_char_(Arg) C_TO_XEN_String(Arg)
#define XEN_TO_C_char_(Arg) (char*)(XEN_TO_C_String(Arg))
#define XEN_char__P(Arg) XEN_String_P(Arg)
#define C_TO_XEN_GdkGrabStatus(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkGrabStatus(Arg) (GdkGrabStatus)(XEN_TO_C_INT(Arg))
#define XEN_GdkGrabStatus_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GdkEventMask(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkEventMask(Arg) (GdkEventMask)(XEN_TO_C_INT(Arg))
#define XEN_GdkEventMask_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GdkImageType(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkImageType(Arg) (GdkImageType)(XEN_TO_C_INT(Arg))
#define XEN_GdkImageType_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR(GdkDevice_, GdkDevice*)
#define C_TO_XEN_GdkInputSource(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkInputSource(Arg) (GdkInputSource)(XEN_TO_C_INT(Arg))
#define XEN_GdkInputSource_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GdkInputMode(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkInputMode(Arg) (GdkInputMode)(XEN_TO_C_INT(Arg))
#define XEN_GdkInputMode_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR(gdouble_, gdouble*)
XM_TYPE_PTR(GdkTimeCoord__, GdkTimeCoord**)
#define C_TO_XEN_GdkExtensionMode(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkExtensionMode(Arg) (GdkExtensionMode)(XEN_TO_C_INT(Arg))
#define XEN_GdkExtensionMode_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR(GdkKeymap_, GdkKeymap*)
XM_TYPE_PTR(GdkKeymapKey_, GdkKeymapKey*)
#define C_TO_XEN_PangoDirection(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_PangoDirection(Arg) (PangoDirection)(XEN_TO_C_INT(Arg))
#define XEN_PangoDirection_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR(PangoContext_, PangoContext*)
XM_TYPE_PTR(PangoAttribute_, PangoAttribute*)
#define C_TO_XEN_int(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_int(Arg) (int)(XEN_TO_C_INT(Arg))
#define XEN_int_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_Drawable_was_Window_(Arg) C_TO_XEN_DRAWABLE_WAS_WINDOW(Arg)
#define XEN_TO_C_Drawable_was_Window_(Arg) (Drawable_was_Window*)(XEN_TO_C_DRAWABLE_WAS_WINDOW(Arg))
#define XEN_Drawable_was_Window__P(Arg) XEN_DRAWABLE_WAS_WINDOW_P(Arg)
XM_TYPE_PTR_1(GdkBitmap__, GdkBitmap**)
#define C_TO_XEN_GdkNativeWindow(Arg) C_TO_XEN_ULONG(Arg)
#define XEN_TO_C_GdkNativeWindow(Arg) (GdkNativeWindow)(XEN_TO_C_ULONG(Arg))
#define XEN_GdkNativeWindow_P(Arg) XEN_ULONG_P(Arg)
#define C_TO_XEN_guchar_(Arg) C_TO_XEN_String(Arg)
#define XEN_TO_C_guchar_(Arg) (guchar*)(XEN_TO_C_String(Arg))
#define XEN_guchar__P(Arg) XEN_String_P(Arg)
#define C_TO_XEN_GdkPropMode(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkPropMode(Arg) (GdkPropMode)(XEN_TO_C_INT(Arg))
#define XEN_GdkPropMode_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GdkFillRule(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkFillRule(Arg) (GdkFillRule)(XEN_TO_C_INT(Arg))
#define XEN_GdkFillRule_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GdkOverlapType(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkOverlapType(Arg) (GdkOverlapType)(XEN_TO_C_INT(Arg))
#define XEN_GdkOverlapType_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GdkRgbDither(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkRgbDither(Arg) (GdkRgbDither)(XEN_TO_C_INT(Arg))
#define XEN_GdkRgbDither_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR(GdkRgbCmap_, GdkRgbCmap*)
XM_TYPE_PTR(guint32_, guint32*)
#define C_TO_XEN_GdkVisualType(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkVisualType(Arg) (GdkVisualType)(XEN_TO_C_INT(Arg))
#define XEN_GdkVisualType_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_2(GdkVisualType_, GdkVisualType*)
XM_TYPE_PTR_1(GdkWindowAttr_, GdkWindowAttr*)
#define C_TO_XEN_GdkWindowType(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkWindowType(Arg) (GdkWindowType)(XEN_TO_C_INT(Arg))
#define XEN_GdkWindowType_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GdkWindowState(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkWindowState(Arg) (GdkWindowState)(XEN_TO_C_INT(Arg))
#define XEN_GdkWindowState_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GdkWMDecoration(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkWMDecoration(Arg) (GdkWMDecoration)(XEN_TO_C_INT(Arg))
#define XEN_GdkWMDecoration_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GdkWMFunction(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkWMFunction(Arg) (GdkWMFunction)(XEN_TO_C_INT(Arg))
#define XEN_GdkWMFunction_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GdkWindowEdge(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkWindowEdge(Arg) (GdkWindowEdge)(XEN_TO_C_INT(Arg))
#define XEN_GdkWindowEdge_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GdkGeometry_, GdkGeometry*)
XM_TYPE_PTR(GtkWindow_, GtkWindow*)
#define C_TO_XEN_GdkWindowTypeHint(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkWindowTypeHint(Arg) (GdkWindowTypeHint)(XEN_TO_C_INT(Arg))
#define XEN_GdkWindowTypeHint_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GdkWindowHints(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkWindowHints(Arg) (GdkWindowHints)(XEN_TO_C_INT(Arg))
#define XEN_GdkWindowHints_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE(GdkColorspace, GdkColorspace)
XM_TYPE_PTR_2(GError_, GError*)
XM_TYPE_1(GdkPixbufDestroyNotify, GdkPixbufDestroyNotify)
XM_TYPE_PTR(char__, char**)
XM_TYPE_PTR_1(guint8_, guint8*)
#define C_TO_XEN_guchar(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_guchar(Arg) (guchar)(XEN_TO_C_INT(Arg))
#define XEN_guchar_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_gfloat(Arg) C_TO_XEN_DOUBLE(Arg)
#define XEN_TO_C_gfloat(Arg) (gfloat)(XEN_TO_C_DOUBLE(Arg))
#define XEN_gfloat_P(Arg) XEN_NUMBER_P(Arg)
#define C_TO_XEN_double(Arg) C_TO_XEN_DOUBLE(Arg)
#define XEN_TO_C_double(Arg) (double)(XEN_TO_C_DOUBLE(Arg))
#define XEN_double_P(Arg) XEN_NUMBER_P(Arg)
XM_TYPE_1(GdkInterpType, GdkInterpType)
XM_TYPE_PTR(GdkPixbufAnimation_, GdkPixbufAnimation*)
XM_TYPE_PTR(GdkPixbufAnimationIter_, GdkPixbufAnimationIter*)
XM_TYPE_PTR_1(GTimeVal_, GTimeVal*)
XM_TYPE_PTR(GdkPixbufLoader_, GdkPixbufLoader*)
XM_TYPE_1(gsize, gsize)
#define C_TO_XEN_GtkType(Arg) C_TO_XEN_ULONG(Arg)
#define XEN_TO_C_GtkType(Arg) (GtkType)(XEN_TO_C_ULONG(Arg))
#define XEN_GtkType_P(Arg) XEN_ULONG_P(Arg)
XM_TYPE_PTR(GtkAccelGroup_, GtkAccelGroup*)
#define C_TO_XEN_GtkAccelFlags(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkAccelFlags(Arg) (GtkAccelFlags)(XEN_TO_C_INT(Arg))
#define XEN_GtkAccelFlags_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR(GObject_, GObject*)
XM_TYPE_PTR(GSList_, GSList*)
XM_TYPE_PTR_2(GtkAccelGroupEntry_, GtkAccelGroupEntry*)
XM_TYPE_PTR_1(GtkAccelLabel_, GtkAccelLabel*)
XM_TYPE_PTR(GScanner_, GScanner*)
XM_TYPE_PTR_1(GtkAccessible_, GtkAccessible*)
XM_TYPE_PTR(GtkObject_, GtkObject*)
XM_TYPE_PTR(GtkAdjustment_, GtkAdjustment*)
XM_TYPE_PTR_1(GtkAlignment_, GtkAlignment*)
#define C_TO_XEN_GtkArrowType(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkArrowType(Arg) (GtkArrowType)(XEN_TO_C_INT(Arg))
#define XEN_GtkArrowType_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GtkShadowType(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkShadowType(Arg) (GtkShadowType)(XEN_TO_C_INT(Arg))
#define XEN_GtkShadowType_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GtkArrow_, GtkArrow*)
XM_TYPE_PTR_1(GtkAspectFrame_, GtkAspectFrame*)
#define C_TO_XEN_GtkButtonBoxStyle(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkButtonBoxStyle(Arg) (GtkButtonBoxStyle)(XEN_TO_C_INT(Arg))
#define XEN_GtkButtonBoxStyle_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GtkButtonBox_, GtkButtonBox*)
XM_TYPE_PTR(GtkBindingSet_, GtkBindingSet*)
#define C_TO_XEN_GtkPathType(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkPathType(Arg) (GtkPathType)(XEN_TO_C_INT(Arg))
#define XEN_GtkPathType_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GtkPathPriorityType(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkPathPriorityType(Arg) (GtkPathPriorityType)(XEN_TO_C_INT(Arg))
#define XEN_GtkPathPriorityType_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GtkBin_, GtkBin*)
XM_TYPE_PTR_1(GtkBox_, GtkBox*)
#define C_TO_XEN_GtkPackType(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkPackType(Arg) (GtkPackType)(XEN_TO_C_INT(Arg))
#define XEN_GtkPackType_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GtkButton_, GtkButton*)
#define C_TO_XEN_GtkReliefStyle(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkReliefStyle(Arg) (GtkReliefStyle)(XEN_TO_C_INT(Arg))
#define XEN_GtkReliefStyle_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GtkCalendar_, GtkCalendar*)
XM_TYPE_PTR(GtkCellEditable_, GtkCellEditable*)
#define C_TO_XEN_GtkCellRendererState(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkCellRendererState(Arg) (GtkCellRendererState)(XEN_TO_C_INT(Arg))
#define XEN_GtkCellRendererState_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GtkCellRendererText_, GtkCellRendererText*)
XM_TYPE_PTR_1(GtkCellRendererToggle_, GtkCellRendererToggle*)
XM_TYPE_PTR_1(GtkCheckMenuItem_, GtkCheckMenuItem*)
XM_TYPE_PTR(GtkTargetEntry_, GtkTargetEntry*)
XM_TYPE_PTR_1(GtkColorSelection_, GtkColorSelection*)
#define C_TO_XEN_guint16(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_guint16(Arg) (guint16)(XEN_TO_C_INT(Arg))
#define XEN_guint16_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GtkContainer_, GtkContainer*)
#define C_TO_XEN_GtkResizeMode(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkResizeMode(Arg) (GtkResizeMode)(XEN_TO_C_INT(Arg))
#define XEN_GtkResizeMode_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GtkCurve_, GtkCurve*)
XM_TYPE_PTR_1(gfloat_, gfloat*)
#define C_TO_XEN_GtkCurveType(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkCurveType(Arg) (GtkCurveType)(XEN_TO_C_INT(Arg))
#define XEN_GtkCurveType_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GtkDialogFlags(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkDialogFlags(Arg) (GtkDialogFlags)(XEN_TO_C_INT(Arg))
#define XEN_GtkDialogFlags_P(Arg) XEN_INTEGER_P(Arg)
#define XEN_etc_P(Arg) (XEN_LIST_P(Arg))
#define XEN_TO_C_etc(Arg) ((gpointer)Arg)
XM_TYPE_PTR_1(GtkDialog_, GtkDialog*)
#define C_TO_XEN_GtkDestDefaults(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkDestDefaults(Arg) (GtkDestDefaults)(XEN_TO_C_INT(Arg))
#define XEN_GtkDestDefaults_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR(GtkTargetList_, GtkTargetList*)
XM_TYPE_PTR_1(GtkEditable_, GtkEditable*)
XM_TYPE_PTR_1(GtkEntry_, GtkEntry*)
XM_TYPE_PTR_1(GtkFileSelection_, GtkFileSelection*)
XM_TYPE_PTR_1(GtkFixed_, GtkFixed*)
XM_TYPE_PTR_1(GtkFontSelection_, GtkFontSelection*)
XM_TYPE_PTR_1(GtkFontSelectionDialog_, GtkFontSelectionDialog*)
XM_TYPE_PTR_1(GtkFrame_, GtkFrame*)
XM_TYPE_PTR_1(GtkHandleBox_, GtkHandleBox*)
#define C_TO_XEN_GtkPositionType(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkPositionType(Arg) (GtkPositionType)(XEN_TO_C_INT(Arg))
#define XEN_GtkPositionType_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR(GtkIconFactory_, GtkIconFactory*)
XM_TYPE_PTR(GtkIconSet_, GtkIconSet*)
#define C_TO_XEN_GtkIconSize(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkIconSize(Arg) (GtkIconSize)(XEN_TO_C_INT(Arg))
#define XEN_GtkIconSize_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR(GtkStyle_, GtkStyle*)
#define C_TO_XEN_GtkTextDirection(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkTextDirection(Arg) (GtkTextDirection)(XEN_TO_C_INT(Arg))
#define XEN_GtkTextDirection_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GtkStateType(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkStateType(Arg) (GtkStateType)(XEN_TO_C_INT(Arg))
#define XEN_GtkStateType_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR(GtkIconSource_, GtkIconSource*)
XM_TYPE_PTR_2(GtkIconSize_, GtkIconSize*)
XM_TYPE_PTR_1(GtkImage_, GtkImage*)
#define C_TO_XEN_GtkImageType(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkImageType(Arg) (GtkImageType)(XEN_TO_C_INT(Arg))
#define XEN_GtkImageType_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GtkImageMenuItem_, GtkImageMenuItem*)
XM_TYPE_PTR(GtkIMContext_, GtkIMContext*)
XM_TYPE_PTR(PangoAttrList_, PangoAttrList*)
XM_TYPE_PTR_1(GtkIMContextSimple_, GtkIMContextSimple*)
XM_TYPE_PTR_1(guint16_, guint16*)
XM_TYPE_PTR_1(GtkIMMulticontext_, GtkIMMulticontext*)
XM_TYPE_PTR_1(GtkMenuShell_, GtkMenuShell*)
XM_TYPE_PTR_1(GtkItem_, GtkItem*)
XM_TYPE_PTR_1(GtkLabel_, GtkLabel*)
#define C_TO_XEN_GtkJustification(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkJustification(Arg) (GtkJustification)(XEN_TO_C_INT(Arg))
#define XEN_GtkJustification_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GtkLayout_, GtkLayout*)
XM_TYPE_PTR(GtkListStore_, GtkListStore*)
XM_TYPE_PTR(PangoLanguage_, PangoLanguage*)
#define XEN_xen_P(Arg) ((XEN_LIST_P(Arg)) && (XEN_LIST_LENGTH(Arg) > 2))
#define XEN_TO_C_xen(Arg) ((gpointer)Arg)
XM_TYPE_PTR_1(GtkMenuItem_, GtkMenuItem*)
XM_TYPE_PTR_1(GtkMisc_, GtkMisc*)
XM_TYPE_PTR_1(GtkNotebook_, GtkNotebook*)
XM_TYPE_PTR_1(GtkPaned_, GtkPaned*)
XM_TYPE_PTR_1(GtkPlug_, GtkPlug*)
XM_TYPE_PTR_1(GtkProgressBar_, GtkProgressBar*)
#define C_TO_XEN_GtkProgressBarOrientation(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkProgressBarOrientation(Arg) (GtkProgressBarOrientation)(XEN_TO_C_INT(Arg))
#define XEN_GtkProgressBarOrientation_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GtkRadioButton_, GtkRadioButton*)
XM_TYPE_PTR_1(GtkRadioMenuItem_, GtkRadioMenuItem*)
XM_TYPE_PTR_1(GtkRange_, GtkRange*)
#define C_TO_XEN_GtkUpdateType(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkUpdateType(Arg) (GtkUpdateType)(XEN_TO_C_INT(Arg))
#define XEN_GtkUpdateType_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR(GtkRcStyle_, GtkRcStyle*)
XM_TYPE_PTR_1(GtkRuler_, GtkRuler*)
#define C_TO_XEN_GtkMetricType(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkMetricType(Arg) (GtkMetricType)(XEN_TO_C_INT(Arg))
#define XEN_GtkMetricType_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GtkScale_, GtkScale*)
XM_TYPE_PTR_1(GtkScrolledWindow_, GtkScrolledWindow*)
#define C_TO_XEN_GtkPolicyType(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkPolicyType(Arg) (GtkPolicyType)(XEN_TO_C_INT(Arg))
#define XEN_GtkPolicyType_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GtkCornerType(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkCornerType(Arg) (GtkCornerType)(XEN_TO_C_INT(Arg))
#define XEN_GtkCornerType_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR(GtkSizeGroup_, GtkSizeGroup*)
#define C_TO_XEN_GtkSizeGroupMode(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkSizeGroupMode(Arg) (GtkSizeGroupMode)(XEN_TO_C_INT(Arg))
#define XEN_GtkSizeGroupMode_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GtkSocket_, GtkSocket*)
XM_TYPE_PTR_1(GtkSpinButton_, GtkSpinButton*)
#define C_TO_XEN_GtkSpinButtonUpdatePolicy(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkSpinButtonUpdatePolicy(Arg) (GtkSpinButtonUpdatePolicy)(XEN_TO_C_INT(Arg))
#define XEN_GtkSpinButtonUpdatePolicy_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GtkSpinType(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkSpinType(Arg) (GtkSpinType)(XEN_TO_C_INT(Arg))
#define XEN_GtkSpinType_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GtkStatusbar_, GtkStatusbar*)
XM_TYPE_PTR(GtkStockItem_, GtkStockItem*)
#define C_TO_XEN_GtkOrientation(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkOrientation(Arg) (GtkOrientation)(XEN_TO_C_INT(Arg))
#define XEN_GtkOrientation_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GtkExpanderStyle(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkExpanderStyle(Arg) (GtkExpanderStyle)(XEN_TO_C_INT(Arg))
#define XEN_GtkExpanderStyle_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR(GtkBorder_, GtkBorder*)
XM_TYPE_PTR_1(GtkTable_, GtkTable*)
#define C_TO_XEN_GtkAttachOptions(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkAttachOptions(Arg) (GtkAttachOptions)(XEN_TO_C_INT(Arg))
#define XEN_GtkAttachOptions_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR(GtkTextBuffer_, GtkTextBuffer*)
XM_TYPE_PTR(GtkTextTagTable_, GtkTextTagTable*)
XM_TYPE_PTR(GtkTextIter_, GtkTextIter*)
XM_TYPE_PTR(GtkTextChildAnchor_, GtkTextChildAnchor*)
XM_TYPE_PTR(GtkTextMark_, GtkTextMark*)
XM_TYPE_PTR(GtkTextAttributes_, GtkTextAttributes*)
#define C_TO_XEN_GtkTextSearchFlags(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkTextSearchFlags(Arg) (GtkTextSearchFlags)(XEN_TO_C_INT(Arg))
#define XEN_GtkTextSearchFlags_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GtkTextView_, GtkTextView*)
#define C_TO_XEN_GtkTextWindowType(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkTextWindowType(Arg) (GtkTextWindowType)(XEN_TO_C_INT(Arg))
#define XEN_GtkTextWindowType_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GtkWrapMode(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkWrapMode(Arg) (GtkWrapMode)(XEN_TO_C_INT(Arg))
#define XEN_GtkWrapMode_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR(PangoTabArray_, PangoTabArray*)
XM_TYPE_PTR_1(GtkToggleButton_, GtkToggleButton*)
XM_TYPE_PTR_1(GtkToolbar_, GtkToolbar*)
#define C_TO_XEN_GtkToolbarStyle(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkToolbarStyle(Arg) (GtkToolbarStyle)(XEN_TO_C_INT(Arg))
#define XEN_GtkToolbarStyle_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR(GtkTooltips_, GtkTooltips*)
XM_TYPE_PTR_2(GtkTooltipsData_, GtkTooltipsData*)
XM_TYPE_PTR_1(GtkTreeDragSource_, GtkTreeDragSource*)
XM_TYPE_PTR_1(GtkTreeDragDest_, GtkTreeDragDest*)
XM_TYPE_PTR(GtkTreeRowReference_, GtkTreeRowReference*)
#define C_TO_XEN_GtkTreeModelFlags(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkTreeModelFlags(Arg) (GtkTreeModelFlags)(XEN_TO_C_INT(Arg))
#define XEN_GtkTreeModelFlags_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GtkTreeModelSort_, GtkTreeModelSort*)
#define C_TO_XEN_GtkSelectionMode(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkSelectionMode(Arg) (GtkSelectionMode)(XEN_TO_C_INT(Arg))
#define XEN_GtkSelectionMode_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GtkTreeModel__, GtkTreeModel**)
XM_TYPE_PTR_1(GtkTreeSortable_, GtkTreeSortable*)
#define C_TO_XEN_GtkSortType(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkSortType(Arg) (GtkSortType)(XEN_TO_C_INT(Arg))
#define XEN_GtkSortType_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR(GtkTreeStore_, GtkTreeStore*)
#define C_TO_XEN_GtkTreeViewColumnSizing(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkTreeViewColumnSizing(Arg) (GtkTreeViewColumnSizing)(XEN_TO_C_INT(Arg))
#define XEN_GtkTreeViewColumnSizing_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GtkTreeViewDropPosition(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkTreeViewDropPosition(Arg) (GtkTreeViewDropPosition)(XEN_TO_C_INT(Arg))
#define XEN_GtkTreeViewDropPosition_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GtkViewport_, GtkViewport*)
XM_TYPE_PTR(GtkRequisition_, GtkRequisition*)
XM_TYPE_PTR_1(GtkAllocation_, GtkAllocation*)
#define C_TO_XEN_GtkDirectionType(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkDirectionType(Arg) (GtkDirectionType)(XEN_TO_C_INT(Arg))
#define XEN_GtkDirectionType_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_2(AtkObject_, AtkObject*)
XM_TYPE_PTR(PangoFontDescription_, PangoFontDescription*)
#define C_TO_XEN_GtkWindowType(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkWindowType(Arg) (GtkWindowType)(XEN_TO_C_INT(Arg))
#define XEN_GtkWindowType_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GtkWindowPosition(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkWindowPosition(Arg) (GtkWindowPosition)(XEN_TO_C_INT(Arg))
#define XEN_GtkWindowPosition_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GdkGravity(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkGravity(Arg) (GdkGravity)(XEN_TO_C_INT(Arg))
#define XEN_GdkGravity_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR(PangoColor_, PangoColor*)
#define C_TO_XEN_PangoAttrType(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_PangoAttrType(Arg) (PangoAttrType)(XEN_TO_C_INT(Arg))
#define XEN_PangoAttrType_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_PangoStyle(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_PangoStyle(Arg) (PangoStyle)(XEN_TO_C_INT(Arg))
#define XEN_PangoStyle_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_PangoWeight(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_PangoWeight(Arg) (PangoWeight)(XEN_TO_C_INT(Arg))
#define XEN_PangoWeight_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_PangoVariant(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_PangoVariant(Arg) (PangoVariant)(XEN_TO_C_INT(Arg))
#define XEN_PangoVariant_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_PangoStretch(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_PangoStretch(Arg) (PangoStretch)(XEN_TO_C_INT(Arg))
#define XEN_PangoStretch_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_PangoUnderline(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_PangoUnderline(Arg) (PangoUnderline)(XEN_TO_C_INT(Arg))
#define XEN_PangoUnderline_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(PangoRectangle_, PangoRectangle*)
XM_TYPE_PTR(PangoAttrIterator_, PangoAttrIterator*)
XM_TYPE_PTR_1(PangoAttrList__, PangoAttrList**)
XM_TYPE_PTR_1(gunichar_, gunichar*)
XM_TYPE_PTR_1(PangoAnalysis_, PangoAnalysis*)
XM_TYPE_PTR(PangoLogAttr_, PangoLogAttr*)
XM_TYPE_PTR_2(PangoFontFamily__, PangoFontFamily**)
XM_TYPE_PTR_2(PangoFontset_, PangoFontset*)
XM_TYPE_PTR(PangoFontMetrics_, PangoFontMetrics*)
XM_TYPE_PTR(PangoCoverage_, PangoCoverage*)
#define C_TO_XEN_PangoCoverageLevel(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_PangoCoverageLevel(Arg) (PangoCoverageLevel)(XEN_TO_C_INT(Arg))
#define XEN_PangoCoverageLevel_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(PangoFontDescription__, PangoFontDescription**)
#define C_TO_XEN_PangoFontMask(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_PangoFontMask(Arg) (PangoFontMask)(XEN_TO_C_INT(Arg))
#define XEN_PangoFontMask_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR(PangoFontFamily_, PangoFontFamily*)
XM_TYPE_PTR_2(PangoFontFace__, PangoFontFace**)
XM_TYPE_PTR(PangoFontFace_, PangoFontFace*)
#define C_TO_XEN_PangoGlyph(Arg) C_TO_XEN_ULONG(Arg)
#define XEN_TO_C_PangoGlyph(Arg) (PangoGlyph)(XEN_TO_C_ULONG(Arg))
#define XEN_PangoGlyph_P(Arg) XEN_ULONG_P(Arg)
XM_TYPE_PTR_1(PangoFontMap_, PangoFontMap*)
XM_TYPE_PTR(PangoItem_, PangoItem*)
#define C_TO_XEN_PangoWrapMode(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_PangoWrapMode(Arg) (PangoWrapMode)(XEN_TO_C_INT(Arg))
#define XEN_PangoWrapMode_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_PangoAlignment(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_PangoAlignment(Arg) (PangoAlignment)(XEN_TO_C_INT(Arg))
#define XEN_PangoAlignment_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR(int_, int*)
XM_TYPE_PTR(PangoLayoutIter_, PangoLayoutIter*)
XM_TYPE_PTR_2(PangoLayoutRun_, PangoLayoutRun*)
#define C_TO_XEN_GdkEventType(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkEventType(Arg) (GdkEventType)(XEN_TO_C_INT(Arg))
#define XEN_GdkEventType_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_gint8(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_gint8(Arg) (gint8)(XEN_TO_C_INT(Arg))
#define XEN_gint8_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR(GdkEventAny_, GdkEventAny*)
XM_TYPE_PTR_1(GdkEventExpose_, GdkEventExpose*)
XM_TYPE_PTR_1(GdkEventNoExpose_, GdkEventNoExpose*)
#define C_TO_XEN_GdkVisibilityState(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkVisibilityState(Arg) (GdkVisibilityState)(XEN_TO_C_INT(Arg))
#define XEN_GdkVisibilityState_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GdkEventVisibility_, GdkEventVisibility*)
#define C_TO_XEN_gint16(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_gint16(Arg) (gint16)(XEN_TO_C_INT(Arg))
#define XEN_gint16_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GdkEventMotion_, GdkEventMotion*)
XM_TYPE_PTR_1(GdkEventButton_, GdkEventButton*)
#define C_TO_XEN_GdkScrollDirection(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkScrollDirection(Arg) (GdkScrollDirection)(XEN_TO_C_INT(Arg))
#define XEN_GdkScrollDirection_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GdkEventScroll_, GdkEventScroll*)
#define C_TO_XEN_guint8(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_guint8(Arg) (guint8)(XEN_TO_C_INT(Arg))
#define XEN_guint8_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GdkCrossingMode(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkCrossingMode(Arg) (GdkCrossingMode)(XEN_TO_C_INT(Arg))
#define XEN_GdkCrossingMode_P(Arg) XEN_INTEGER_P(Arg)
#define C_TO_XEN_GdkNotifyType(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkNotifyType(Arg) (GdkNotifyType)(XEN_TO_C_INT(Arg))
#define XEN_GdkNotifyType_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GdkEventCrossing_, GdkEventCrossing*)
XM_TYPE_PTR_1(GdkEventFocus_, GdkEventFocus*)
XM_TYPE_PTR_1(GdkEventConfigure_, GdkEventConfigure*)
XM_TYPE_PTR_1(GdkEventProperty_, GdkEventProperty*)
XM_TYPE_PTR_1(GdkEventSelection_, GdkEventSelection*)
XM_TYPE_PTR_1(GdkEventProximity_, GdkEventProximity*)
#define C_TO_XEN_GdkSettingAction(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkSettingAction(Arg) (GdkSettingAction)(XEN_TO_C_INT(Arg))
#define XEN_GdkSettingAction_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GdkEventSetting_, GdkEventSetting*)
XM_TYPE_PTR_1(GdkEventWindowState_, GdkEventWindowState*)
#define C_TO_XEN_gshort(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_gshort(Arg) (gshort)(XEN_TO_C_INT(Arg))
#define XEN_gshort_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GdkEventDND_, GdkEventDND*)
#define C_TO_XEN_GdkByteOrder(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GdkByteOrder(Arg) (GdkByteOrder)(XEN_TO_C_INT(Arg))
#define XEN_GdkByteOrder_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_2(GdkDeviceAxis_, GdkDeviceAxis*)
XM_TYPE_PTR_2(GdkDeviceKey_, GdkDeviceKey*)
XM_TYPE_PTR_1(GtkColorSelectionDialog_, GtkColorSelectionDialog*)
XM_TYPE_PTR_2(GdkGC__, GdkGC**)
XM_TYPE_PTR_2(GdkPixmap__, GdkPixmap**)
XM_TYPE_PTR_2(GArray_, GArray*)
#if HAVE_GDK_DRAW_PIXBUF
XM_TYPE_PTR(GdkDisplay_, GdkDisplay*)
XM_TYPE_PTR(GdkScreen_, GdkScreen*)
#endif

#if HAVE_GTK_FILE_CHOOSER_DIALOG_NEW
XM_TYPE_PTR(GtkFileFilterInfo_, GtkFileFilterInfo*)
XM_TYPE_PTR(GtkEntryCompletion_, GtkEntryCompletion*)
#define C_TO_XEN_GtkCalendarDisplayOptions(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkCalendarDisplayOptions(Arg) (GtkCalendarDisplayOptions)(XEN_TO_C_INT(Arg))
#define XEN_GtkCalendarDisplayOptions_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GtkEventBox_, GtkEventBox*)
XM_TYPE_PTR(GtkToolItem_, GtkToolItem*)
#define C_TO_XEN_GtkFileChooserAction(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkFileChooserAction(Arg) (GtkFileChooserAction)(XEN_TO_C_INT(Arg))
#define XEN_GtkFileChooserAction_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GtkTreeModelFilter_, GtkTreeModelFilter*)
XM_TYPE_PTR(GtkAction_, GtkAction*)
XM_TYPE_PTR(GtkActionGroup_, GtkActionGroup*)
XM_TYPE_PTR_1(GtkActionEntry_, GtkActionEntry*)
XM_TYPE_PTR_1(GtkToggleActionEntry_, GtkToggleActionEntry*)
XM_TYPE_PTR_1(GtkComboBox_, GtkComboBox*)
XM_TYPE_PTR_1(GtkComboBoxEntry_, GtkComboBoxEntry*)
XM_TYPE_PTR_1(GtkExpander_, GtkExpander*)
XM_TYPE_PTR_1(GtkFontButton_, GtkFontButton*)
XM_TYPE_PTR_1(GtkColorButton_, GtkColorButton*)
XM_TYPE_PTR(GtkUIManager_, GtkUIManager*)
XM_TYPE_1(gssize, gssize)
#define C_TO_XEN_GtkUIManagerItemType(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkUIManagerItemType(Arg) (GtkUIManagerItemType)(XEN_TO_C_INT(Arg))
#define XEN_GtkUIManagerItemType_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GtkRadioToolButton_, GtkRadioToolButton*)
XM_TYPE_PTR(GtkRadioAction_, GtkRadioAction*)
XM_TYPE_PTR_1(GtkSeparatorToolItem_, GtkSeparatorToolItem*)
XM_TYPE_PTR(GtkToggleAction_, GtkToggleAction*)
XM_TYPE_PTR_1(GtkToggleToolButton_, GtkToggleToolButton*)
XM_TYPE_PTR(GtkFileFilter_, GtkFileFilter*)
#define C_TO_XEN_GtkFileFilterFlags(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkFileFilterFlags(Arg) (GtkFileFilterFlags)(XEN_TO_C_INT(Arg))
#define XEN_GtkFileFilterFlags_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GtkCellLayout_, GtkCellLayout*)
XM_TYPE_1(GtkCellLayoutDataFunc, GtkCellLayoutDataFunc)
XM_TYPE_PTR_1(GtkFileChooser_, GtkFileChooser*)
XM_TYPE_PTR(GtkIconTheme_, GtkIconTheme*)
XM_TYPE_PTR(GtkIconInfo_, GtkIconInfo*)
#define C_TO_XEN_GtkIconLookupFlags(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_GtkIconLookupFlags(Arg) (GtkIconLookupFlags)(XEN_TO_C_INT(Arg))
#define XEN_GtkIconLookupFlags_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_PTR_1(GtkToolButton_, GtkToolButton*)
#endif

#if HAVE_GTK_COMBO_BOX_POPUP
XM_TYPE_PTR_2(GtkAccelMap_, GtkAccelMap*)
#endif

#if HAVE_GTK_ABOUT_DIALOG_NEW
XM_TYPE_PTR(GtkIconView_, GtkIconView*)
XM_TYPE_PTR_1(GtkCellView_, GtkCellView*)
XM_TYPE_PTR_1(GValue_, GValue*)
XM_TYPE_PTR_1(GtkAboutDialog_, GtkAboutDialog*)
#endif

#if HAVE_GTK_LABEL_SET_ELLIPSIZE
#define C_TO_XEN_PangoEllipsizeMode(Arg) C_TO_XEN_INT(Arg)
#define XEN_TO_C_PangoEllipsizeMode(Arg) (PangoEllipsizeMode)(XEN_TO_C_INT(Arg))
#define XEN_PangoEllipsizeMode_P(Arg) XEN_INTEGER_P(Arg)
XM_TYPE_1(PangoAttrFilterFunc, PangoAttrFilterFunc)
XM_TYPE_NO_P_2(PangoScript, PangoScript)
XM_TYPE_PTR(PangoScriptIter_, PangoScriptIter*)
#endif

#if HAVE_GTK_FILE_CHOOSER_BUTTON_NEW
XM_TYPE_PTR_1(GtkFileChooserButton_, GtkFileChooserButton*)
#endif

#if HAVE_GTK_MENU_TOOL_BUTTON_NEW
XM_TYPE_PTR_1(GtkMenuToolButton_, GtkMenuToolButton*)
#endif

#if HAVE_GTK_LABEL_GET_SINGLE_LINE_MODE
#endif

#define XLS(a, b) XEN_TO_C_gchar_(XEN_LIST_REF(a, b))
#define XLI(a, b) XEN_TO_C_INT(XEN_LIST_REF(a, b))
#define XLG(a, b) XEN_TO_C_GType(XEN_LIST_REF(a, b))
#define XLT(a, b) XEN_TO_C_GtkTextTag_(XEN_LIST_REF(a, b))

static XEN c_to_xen_string(XEN str)
{
  return(C_TO_XEN_STRING((char *)XEN_TO_C_ULONG(str)));
}

/* -------------------------------- gc protection -------------------------------- */

static XEN xm_protected = XEN_FALSE;
static int xm_protected_size = 0;
static XEN xm_gc_table = XEN_FALSE;
static int last_xm_unprotect = -1;

static int xm_protect(XEN obj)
{
  int i, new_size;
  XEN new_table;
  XEN *older, *newer;
  older = XEN_VECTOR_ELEMENTS(xm_protected);
  if (last_xm_unprotect >= 0)
    {
      i = last_xm_unprotect;
      if (XEN_FALSE_P(older[i]))
	{
	  older[i] = obj;
	  last_xm_unprotect = -1;
	  return(i);
	}
      last_xm_unprotect = -1;
    }
  for (i = 0; i < xm_protected_size; i++)
    if (XEN_FALSE_P(older[i]))
      {
	older[i] = obj;
	return(i);
      }
  new_size = xm_protected_size * 2;
  new_table = XEN_MAKE_VECTOR(new_size, XEN_FALSE);
  newer = XEN_VECTOR_ELEMENTS(new_table);
  for (i = 0; i < xm_protected_size; i++)
    {
      newer[i] = older[i];
      older[i] = XEN_FALSE;
    }
  newer[xm_protected_size] = obj;
  XEN_VECTOR_SET(xm_gc_table, 0, new_table);
  i = xm_protected_size;
  xm_protected_size = new_size;
  xm_protected = new_table;
  return(i);
}

#if 0
static void xm_unprotect_idler(guint id)
{
  int i;
  XEN *velts;
  XEN cur, idler;
  velts = XEN_VECTOR_ELEMENTS(xm_protected);
  for (i = 0; i < xm_protected_size; i++)
    {
      cur = velts[i];
      if ((XEN_LIST_P(cur)) && (XEN_LIST_LENGTH(cur) == 3) && (XEN_LIST_P(XEN_CADDR(cur))))
        {
          idler = XEN_CADDR(cur);
          if ((XEN_SYMBOL_P(XEN_CAR(idler))) &&
              (strcmp("idler", XEN_SYMBOL_TO_C_STRING(XEN_CAR(idler))) == 0) &&
              (id == (guint)(XEN_TO_C_INT(XEN_CADR(idler)))))
            {
              velts[i] = XEN_FALSE;
              last_xm_unprotect = i;
              return;
            }}}
}
#endif
static void xm_unprotect_at(int ind)
{
  XEN *velts;
  velts = XEN_VECTOR_ELEMENTS(xm_protected);
  velts[ind] = XEN_FALSE;
  last_xm_unprotect = ind;
}



/* ---------------------------------------- callback handlers ---------------------------------------- */

#if WITH_GTK_AND_X11
  #include "xg-x11.h"
  #define gxg_static
#else
  #define gxg_static static
#endif

static gboolean gxg_child_func(GdkWindow* window, gpointer func_data)
{
  return(XEN_TO_C_gboolean(XEN_CALL_2(XEN_CAR((XEN)func_data),
                                      C_TO_XEN_GdkWindow_(window),
                                      XEN_CADR((XEN)func_data),
                                      c__FUNCTION__)));
}
static gboolean gxg_find_func(GtkAccelKey* key, GClosure* closure, gpointer func_data)
{
  return(XEN_TO_C_gboolean(XEN_CALL_3(XEN_CAR((XEN)func_data),
                                      C_TO_XEN_GtkAccelKey_(key),
                                      C_TO_XEN_GClosure_(closure),
                                      XEN_CADR((XEN)func_data),
                                      c__FUNCTION__)));
}
static void gxg_func2(GtkWidget* w, gpointer func_data)
{
  XEN_CALL_2(XEN_CAR((XEN)func_data),
             C_TO_XEN_GtkWidget_(w),
             XEN_CADR((XEN)func_data),
             c__FUNCTION__);
}
static gboolean gxg_timer_func(gpointer func_data)
{
  return(XEN_TO_C_gboolean(XEN_CALL_1(XEN_CAR((XEN)func_data),
                                      XEN_CADR((XEN)func_data),
                                      c__FUNCTION__)));
}
static void gxg_destroy_func(gpointer func_data)
{
  XEN_CALL_1(XEN_CADDDR((XEN)func_data),
             XEN_CADR((XEN)func_data),
             c__FUNCTION__);
}
static GdkFilterReturn gxg_filter_func(GdkXEvent* xevent, GdkEvent* event, gpointer func_data)
{
  return(XEN_TO_C_GdkFilterReturn(XEN_CALL_3(XEN_CAR((XEN)func_data),
                                             C_TO_XEN_GdkXEvent_(xevent),
                                             C_TO_XEN_GdkEvent_(event),
                                             XEN_CADR((XEN)func_data),
                                             c__FUNCTION__)));
}
static void gxg_event_func(GdkEvent* event, gpointer func_data)
{
  XEN_CALL_2(XEN_CAR((XEN)func_data),
             C_TO_XEN_GdkEvent_(event),
             XEN_CADR((XEN)func_data),
             c__FUNCTION__);
}
static gboolean gxg_func1(gpointer func_data)
{
  return(XEN_TO_C_gboolean(XEN_CALL_1(XEN_CAR((XEN)func_data),
                                      XEN_CADR((XEN)func_data),
                                      c__FUNCTION__)));
}
static gint gxg_snoop_func(GtkWidget* widget, GdkEventKey* event, gpointer func_data)
{
  return(XEN_TO_C_gint(XEN_CALL_3(XEN_CAR((XEN)func_data),
                                  C_TO_XEN_GtkWidget_(widget),
                                  C_TO_XEN_GdkEventKey_(event),
                                  XEN_CADR((XEN)func_data),
                                  c__FUNCTION__)));
}
static void gxg_menu_position_func(GtkMenu* menu, gint* x, gint* y, gboolean* push, gpointer func_data)
{
  XEN_CALL_5(XEN_CAR((XEN)func_data),
             C_TO_XEN_GtkMenu_(menu),
             C_TO_XEN_gint_(x),
             C_TO_XEN_gint_(y),
             C_TO_XEN_gboolean_(push),
             XEN_CADR((XEN)func_data),
             c__FUNCTION__);
}
static void gxg_text_tag_table_foreach(GtkTextTag* tag, gpointer func_data)
{
  XEN_CALL_2(XEN_CAR((XEN)func_data),
             C_TO_XEN_GtkTextTag_(tag),
             XEN_CADR((XEN)func_data),
             c__FUNCTION__);
}
static void gxg_accel_map_foreach(gpointer func_data, const gchar* accel_path, guint accel_key, GdkModifierType accel_mods, gboolean changed)
{
  XEN_CALL_5(XEN_CAR((XEN)func_data),
             XEN_CADR((XEN)func_data),
             C_TO_XEN_gchar_(accel_path),
             C_TO_XEN_guint(accel_key),
             C_TO_XEN_GdkModifierType(accel_mods),
             C_TO_XEN_gboolean(changed),
             c__FUNCTION__);
}
static gboolean gxg_model_func(GtkTreeModel* model, GtkTreePath* path, GtkTreeIter* iter, gpointer func_data)
{
  return(XEN_TO_C_gboolean(XEN_CALL_4(XEN_CAR((XEN)func_data),
                                      C_TO_XEN_GtkTreeModel_(model),
                                      C_TO_XEN_GtkTreePath_(path),
                                      C_TO_XEN_GtkTreeIter_(iter),
                                      XEN_CADR((XEN)func_data),
                                      c__FUNCTION__)));
}
static void gxg_tree_selection_func(GtkTreeModel* model, GtkTreePath* path, GtkTreeIter* iter, gpointer func_data)
{
  XEN_CALL_4(XEN_CAR((XEN)func_data),
             C_TO_XEN_GtkTreeModel_(model),
             C_TO_XEN_GtkTreePath_(path),
             C_TO_XEN_GtkTreeIter_(iter),
             XEN_CADR((XEN)func_data),
             c__FUNCTION__);
}
static void gxg_clip_received(GtkClipboard* clipboard, GtkSelectionData* selection_data, gpointer func_data)
{
  XEN_CALL_3(XEN_CAR((XEN)func_data),
             C_TO_XEN_GtkClipboard_(clipboard),
             C_TO_XEN_GtkSelectionData_(selection_data),
             XEN_CADR((XEN)func_data),
             c__FUNCTION__);
}
static void gxg_clip_text_received(GtkClipboard* clipboard, const gchar* text, gpointer func_data)
{
  XEN_CALL_3(XEN_CAR((XEN)func_data),
             C_TO_XEN_GtkClipboard_(clipboard),
             C_TO_XEN_gchar_(text),
             XEN_CADR((XEN)func_data),
             c__FUNCTION__);
}
static void gxg_clip_targets_received(GtkClipboard* clipboard, GdkAtom* atoms, gint n_atoms, gpointer func_data)
{
  XEN_CALL_4(XEN_CAR((XEN)func_data),
             C_TO_XEN_GtkClipboard_(clipboard),
             C_TO_XEN_GdkAtom_(atoms),
             C_TO_XEN_gint(n_atoms),
             XEN_CADR((XEN)func_data),
             c__FUNCTION__);
}
static gboolean gxg_text_char_predicate(gunichar ch, gpointer func_data)
{
  return(XEN_TO_C_gboolean(XEN_CALL_2(XEN_CAR((XEN)func_data),
                                      C_TO_XEN_gunichar(ch),
                                      XEN_CADR((XEN)func_data),
                                      c__FUNCTION__)));
}
static gboolean gxg_tree_column(GtkTreeView* tree_view, GtkTreeViewColumn* column, GtkTreeViewColumn* prev_column, GtkTreeViewColumn* next_column, gpointer func_data)
{
  return(XEN_TO_C_gboolean(XEN_CALL_5(XEN_CAR((XEN)func_data),
                                      C_TO_XEN_GtkTreeView_(tree_view),
                                      C_TO_XEN_GtkTreeViewColumn_(column),
                                      C_TO_XEN_GtkTreeViewColumn_(prev_column),
                                      C_TO_XEN_GtkTreeViewColumn_(next_column),
                                      XEN_CADR((XEN)func_data),
                                      c__FUNCTION__)));
}
static void gxg_tree_mapping(GtkTreeView* tree_view, GtkTreePath* path, gpointer func_data)
{
  XEN_CALL_3(XEN_CAR((XEN)func_data),
             C_TO_XEN_GtkTreeView_(tree_view),
             C_TO_XEN_GtkTreePath_(path),
             XEN_CADR((XEN)func_data),
             c__FUNCTION__);
}
static gboolean gxg_tree_search(GtkTreeModel* model, gint column, const gchar* key, GtkTreeIter* iter, gpointer func_data)
{
  return(XEN_TO_C_gboolean(XEN_CALL_5(XEN_CAR((XEN)func_data),
                                      C_TO_XEN_GtkTreeModel_(model),
                                      C_TO_XEN_gint(column),
                                      C_TO_XEN_gchar_(key),
                                      C_TO_XEN_GtkTreeIter_(iter),
                                      XEN_CADR((XEN)func_data),
                                      c__FUNCTION__)));
}
static void gxg_cell_data(GtkTreeViewColumn* tree_column, GtkCellRenderer* cell, GtkTreeModel* tree_model, GtkTreeIter* iter, gpointer func_data)
{
  XEN_CALL_5(XEN_CAR((XEN)func_data),
             C_TO_XEN_GtkTreeViewColumn_(tree_column),
             C_TO_XEN_GtkCellRenderer_(cell),
             C_TO_XEN_GtkTreeModel_(tree_model),
             C_TO_XEN_GtkTreeIter_(iter),
             XEN_CADR((XEN)func_data),
             c__FUNCTION__);
}
static gint gxg_iter_compare(GtkTreeModel* model, GtkTreeIter* a, GtkTreeIter* b, gpointer func_data)
{
  return(XEN_TO_C_gint(XEN_CALL_4(XEN_CAR((XEN)func_data),
                                  C_TO_XEN_GtkTreeModel_(model),
                                  C_TO_XEN_GtkTreeIter_(a),
                                  C_TO_XEN_GtkTreeIter_(b),
                                  XEN_CADR((XEN)func_data),
                                  c__FUNCTION__)));
}
static gboolean gxg_tree_selection(GtkTreeSelection* selection, GtkTreeModel* model, GtkTreePath* path, gboolean path_currently_selected, gpointer func_data)
{
  return(XEN_TO_C_gboolean(XEN_CALL_5(XEN_CAR((XEN)func_data),
                                      C_TO_XEN_GtkTreeSelection_(selection),
                                      C_TO_XEN_GtkTreeModel_(model),
                                      C_TO_XEN_GtkTreePath_(path),
                                      C_TO_XEN_gboolean(path_currently_selected),
                                      XEN_CADR((XEN)func_data),
                                      c__FUNCTION__)));
}
static void gxg_clip_get(GtkClipboard* clipboard, GtkSelectionData* selection_data, guint info, gpointer func_data)
{
  XEN_CALL_4(XEN_CAR((XEN)func_data),
             C_TO_XEN_GtkClipboard_(clipboard),
             C_TO_XEN_GtkSelectionData_(selection_data),
             C_TO_XEN_guint(info),
             XEN_CADR((XEN)func_data),
             c__FUNCTION__);
}
static void gxg_clip_clear(GtkClipboard* clipboard, gpointer func_data)
{
  XEN_CALL_2(XEN_CADDR((XEN)func_data),
             C_TO_XEN_GtkClipboard_(clipboard),
             XEN_CADR((XEN)func_data),
             c__FUNCTION__);
}
#if HAVE_GTK_FILE_CHOOSER_DIALOG_NEW
static gboolean gxg_file_filter(const GtkFileFilterInfo* info, gpointer func_data)
{
  return(XEN_TO_C_gboolean(XEN_CALL_2(XEN_CAR((XEN)func_data),
                                      C_TO_XEN_GtkFileFilterInfo_((GtkFileFilterInfo *)info),
                                      XEN_CADR((XEN)func_data),
                                      c__FUNCTION__)));
}
static gboolean gxg_entry_completion_match(GtkEntryCompletion* completion, const gchar* key, GtkTreeIter* iter, gpointer func_data)
{
  return(XEN_TO_C_gboolean(XEN_CALL_4(XEN_CAR((XEN)func_data),
                                      C_TO_XEN_GtkEntryCompletion_(completion),
                                      C_TO_XEN_gchar_(key),
                                      C_TO_XEN_GtkTreeIter_(iter),
                                      XEN_CADR((XEN)func_data),
                                      c__FUNCTION__)));
}
#endif

#if HAVE_GTK_ABOUT_DIALOG_NEW
static gboolean gxg_row_separator(GtkTreeModel* model, GtkTreeIter* iter, gpointer func_data)
{
  return(XEN_TO_C_gboolean(XEN_CALL_3(XEN_CAR((XEN)func_data),
                                      C_TO_XEN_GtkTreeModel_(model),
                                      C_TO_XEN_GtkTreeIter_(iter),
                                      XEN_CADR((XEN)func_data),
                                      c__FUNCTION__)));
}
static void gxg_icon_view_foreach(GtkIconView* icon_view, GtkTreePath* path, gpointer func_data)
{
  XEN_CALL_3(XEN_CAR((XEN)func_data),
             C_TO_XEN_GtkIconView_(icon_view),
             C_TO_XEN_GtkTreePath_(path),
             XEN_CADR((XEN)func_data),
             c__FUNCTION__);
}
#endif

#if HAVE_GTK_LABEL_GET_SINGLE_LINE_MODE
static void gxg_clip_image_received(GtkClipboard* clipboard, GdkPixbuf* pixbuf, gpointer func_data)
{
  XEN_CALL_3(XEN_CAR((XEN)func_data),
             C_TO_XEN_GtkClipboard_(clipboard),
             C_TO_XEN_GdkPixbuf_(pixbuf),
             XEN_CADR((XEN)func_data),
             c__FUNCTION__);
}
#endif


static gboolean gxg_func3(GtkWidget *w, GdkEventAny *ev, gpointer data)
{
  return(XEN_TO_C_BOOLEAN(XEN_CALL_3(XEN_CAR((XEN)data),
                          C_TO_XEN_GtkWidget_(w),
                          C_TO_XEN_GdkEventAny_(ev),
                          XEN_CADR((XEN)data),
                          c__FUNCTION__)));
}



/* ---------------------------------------- functions ---------------------------------------- */

static XEN gxg_g_type_name(XEN type)
{
  #define H_g_type_name "gchar* g_type_name(GType type)"
  XEN_ASSERT_TYPE(XEN_GType_P(type), type, 1, "g_type_name", "GType");
  return(C_TO_XEN_gchar_(g_type_name(XEN_TO_C_GType(type))));
}
static XEN gxg_g_type_qname(XEN type)
{
  #define H_g_type_qname "GQuark g_type_qname(GType type)"
  XEN_ASSERT_TYPE(XEN_GType_P(type), type, 1, "g_type_qname", "GType");
  return(C_TO_XEN_GQuark(g_type_qname(XEN_TO_C_GType(type))));
}
static XEN gxg_g_type_from_name(XEN name)
{
  #define H_g_type_from_name "GType g_type_from_name(gchar* name)"
  XEN_ASSERT_TYPE(XEN_gchar__P(name), name, 1, "g_type_from_name", "gchar*");
  return(C_TO_XEN_GType(g_type_from_name(XEN_TO_C_gchar_(name))));
}
static XEN gxg_g_type_parent(XEN type)
{
  #define H_g_type_parent "GType g_type_parent(GType type)"
  XEN_ASSERT_TYPE(XEN_GType_P(type), type, 1, "g_type_parent", "GType");
  return(C_TO_XEN_GType(g_type_parent(XEN_TO_C_GType(type))));
}
static XEN gxg_g_type_is_a(XEN type, XEN is_a_type)
{
  #define H_g_type_is_a "gboolean g_type_is_a(GType type, GType is_a_type)"
  XEN_ASSERT_TYPE(XEN_GType_P(type), type, 1, "g_type_is_a", "GType");
  XEN_ASSERT_TYPE(XEN_GType_P(is_a_type), is_a_type, 2, "g_type_is_a", "GType");
  return(C_TO_XEN_gboolean(g_type_is_a(XEN_TO_C_GType(type), XEN_TO_C_GType(is_a_type))));
}
static XEN gxg_g_cclosure_new(XEN func, XEN func_data, XEN destroy_data)
{
  #define H_g_cclosure_new "GClosure* g_cclosure_new(GCallback func, lambda_data func_data, GClosureNotify destroy_data)"
  XEN_ASSERT_TYPE(XEN_GCallback_P(func), func, 1, "g_cclosure_new", "GCallback");
  XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 2, "g_cclosure_new", "lambda_data");
  XEN_ASSERT_TYPE(XEN_GClosureNotify_P(destroy_data), destroy_data, 3, "g_cclosure_new", "GClosureNotify");
  {
    XEN result = XEN_FALSE;
    int loc;
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    loc = xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 2, C_TO_XEN_INT(loc));
    result = C_TO_XEN_GClosure_(g_cclosure_new(XEN_TO_C_GCallback(func), XEN_TO_C_lambda_data(func_data), XEN_TO_C_GClosureNotify(destroy_data)));
    return(result);
   }
}
static XEN gxg_g_signal_newv(XEN arglist)
{
  #define H_g_signal_newv "guint g_signal_newv(gchar* signal_name, GType itype, GSignalFlags signal_flags, \
GClosure* class_closure, GSignalAccumulator accumulator, gpointer accu_data, GSignalCMarshaller c_marshaller, \
GType return_type, guint n_params, GType* param_types)"
  XEN signal_name, itype, signal_flags, class_closure, accumulator, accu_data, c_marshaller, return_type, n_params, param_types;
  signal_name = XEN_LIST_REF(arglist, 0);
  itype = XEN_LIST_REF(arglist, 1);
  signal_flags = XEN_LIST_REF(arglist, 2);
  class_closure = XEN_LIST_REF(arglist, 3);
  accumulator = XEN_LIST_REF(arglist, 4);
  accu_data = XEN_LIST_REF(arglist, 5);
  c_marshaller = XEN_LIST_REF(arglist, 6);
  return_type = XEN_LIST_REF(arglist, 7);
  n_params = XEN_LIST_REF(arglist, 8);
  param_types = XEN_LIST_REF(arglist, 9);
  XEN_ASSERT_TYPE(XEN_gchar__P(signal_name), signal_name, 1, "g_signal_newv", "gchar*");
  XEN_ASSERT_TYPE(XEN_GType_P(itype), itype, 2, "g_signal_newv", "GType");
  XEN_ASSERT_TYPE(XEN_GSignalFlags_P(signal_flags), signal_flags, 3, "g_signal_newv", "GSignalFlags");
  XEN_ASSERT_TYPE(XEN_GClosure__P(class_closure), class_closure, 4, "g_signal_newv", "GClosure*");
  XEN_ASSERT_TYPE(XEN_GSignalAccumulator_P(accumulator), accumulator, 5, "g_signal_newv", "GSignalAccumulator");
  XEN_ASSERT_TYPE(XEN_gpointer_P(accu_data), accu_data, 6, "g_signal_newv", "gpointer");
  XEN_ASSERT_TYPE(XEN_GSignalCMarshaller_P(c_marshaller), c_marshaller, 7, "g_signal_newv", "GSignalCMarshaller");
  XEN_ASSERT_TYPE(XEN_GType_P(return_type), return_type, 8, "g_signal_newv", "GType");
  XEN_ASSERT_TYPE(XEN_guint_P(n_params), n_params, 9, "g_signal_newv", "guint");
  XEN_ASSERT_TYPE(XEN_GType__P(param_types), param_types, 10, "g_signal_newv", "GType*");
  return(C_TO_XEN_guint(g_signal_newv(XEN_TO_C_gchar_(signal_name), XEN_TO_C_GType(itype), XEN_TO_C_GSignalFlags(signal_flags), 
                                      XEN_TO_C_GClosure_(class_closure), XEN_TO_C_GSignalAccumulator(accumulator), XEN_TO_C_gpointer(accu_data), 
                                      XEN_TO_C_GSignalCMarshaller(c_marshaller), XEN_TO_C_GType(return_type), XEN_TO_C_guint(n_params), 
                                      XEN_TO_C_GType_(param_types))));
}
static XEN gxg_g_signal_lookup(XEN name, XEN itype)
{
  #define H_g_signal_lookup "guint g_signal_lookup(gchar* name, GType itype)"
  XEN_ASSERT_TYPE(XEN_gchar__P(name), name, 1, "g_signal_lookup", "gchar*");
  XEN_ASSERT_TYPE(XEN_GType_P(itype), itype, 2, "g_signal_lookup", "GType");
  return(C_TO_XEN_guint(g_signal_lookup(XEN_TO_C_gchar_(name), XEN_TO_C_GType(itype))));
}
static XEN gxg_g_signal_name(XEN signal_id)
{
  #define H_g_signal_name "gchar* g_signal_name(guint signal_id)"
  XEN_ASSERT_TYPE(XEN_guint_P(signal_id), signal_id, 1, "g_signal_name", "guint");
  return(C_TO_XEN_gchar_(g_signal_name(XEN_TO_C_guint(signal_id))));
}
static XEN gxg_g_signal_query(XEN signal_id, XEN query)
{
  #define H_g_signal_query "void g_signal_query(guint signal_id, GSignalQuery* query)"
  XEN_ASSERT_TYPE(XEN_guint_P(signal_id), signal_id, 1, "g_signal_query", "guint");
  XEN_ASSERT_TYPE(XEN_GSignalQuery__P(query), query, 2, "g_signal_query", "GSignalQuery*");
  g_signal_query(XEN_TO_C_guint(signal_id), XEN_TO_C_GSignalQuery_(query));
  return(XEN_FALSE);
}
static XEN gxg_g_signal_list_ids(XEN itype, XEN n_ids)
{
  #define H_g_signal_list_ids "guint* g_signal_list_ids(GType itype, guint* n_ids)"
  XEN_ASSERT_TYPE(XEN_GType_P(itype), itype, 1, "g_signal_list_ids", "GType");
  XEN_ASSERT_TYPE(XEN_guint__P(n_ids), n_ids, 2, "g_signal_list_ids", "guint*");
  return(C_TO_XEN_guint_(g_signal_list_ids(XEN_TO_C_GType(itype), XEN_TO_C_guint_(n_ids))));
}
static XEN gxg_g_signal_parse_name(XEN detailed_signal, XEN itype, XEN signal_id_p, XEN detail_p, XEN force_detail_quark)
{
  #define H_g_signal_parse_name "gboolean g_signal_parse_name(gchar* detailed_signal, GType itype, guint* [signal_id_p], \
GQuark* [detail_p], gboolean force_detail_quark)"
  guint ref_signal_id_p;
  GQuark ref_detail_p;
  XEN_ASSERT_TYPE(XEN_gchar__P(detailed_signal), detailed_signal, 1, "g_signal_parse_name", "gchar*");
  XEN_ASSERT_TYPE(XEN_GType_P(itype), itype, 2, "g_signal_parse_name", "GType");
  XEN_ASSERT_TYPE(XEN_gboolean_P(force_detail_quark), force_detail_quark, 5, "g_signal_parse_name", "gboolean");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(g_signal_parse_name(XEN_TO_C_gchar_(detailed_signal), XEN_TO_C_GType(itype), &ref_signal_id_p, 
                                                   &ref_detail_p, XEN_TO_C_gboolean(force_detail_quark)));
    return(XEN_LIST_3(result, C_TO_XEN_guint(ref_signal_id_p), C_TO_XEN_GQuark(ref_detail_p)));
   }
}
static XEN gxg_g_signal_get_invocation_hint(XEN instance)
{
  #define H_g_signal_get_invocation_hint "GSignalInvocationHint* g_signal_get_invocation_hint(gpointer instance)"
  XEN_ASSERT_TYPE(XEN_gpointer_P(instance), instance, 1, "g_signal_get_invocation_hint", "gpointer");
  return(C_TO_XEN_GSignalInvocationHint_(g_signal_get_invocation_hint(XEN_TO_C_gpointer(instance))));
}
static XEN gxg_g_signal_stop_emission(XEN instance, XEN signal_id, XEN detail)
{
  #define H_g_signal_stop_emission "void g_signal_stop_emission(gpointer instance, guint signal_id, GQuark detail)"
  XEN_ASSERT_TYPE(XEN_gpointer_P(instance), instance, 1, "g_signal_stop_emission", "gpointer");
  XEN_ASSERT_TYPE(XEN_guint_P(signal_id), signal_id, 2, "g_signal_stop_emission", "guint");
  XEN_ASSERT_TYPE(XEN_GQuark_P(detail), detail, 3, "g_signal_stop_emission", "GQuark");
  g_signal_stop_emission(XEN_TO_C_gpointer(instance), XEN_TO_C_guint(signal_id), XEN_TO_C_GQuark(detail));
  return(XEN_FALSE);
}
static XEN gxg_g_signal_stop_emission_by_name(XEN instance, XEN detailed_signal)
{
  #define H_g_signal_stop_emission_by_name "void g_signal_stop_emission_by_name(gpointer instance, gchar* detailed_signal)"
  XEN_ASSERT_TYPE(XEN_gpointer_P(instance), instance, 1, "g_signal_stop_emission_by_name", "gpointer");
  XEN_ASSERT_TYPE(XEN_gchar__P(detailed_signal), detailed_signal, 2, "g_signal_stop_emission_by_name", "gchar*");
  g_signal_stop_emission_by_name(XEN_TO_C_gpointer(instance), XEN_TO_C_gchar_(detailed_signal));
  return(XEN_FALSE);
}
static XEN gxg_g_signal_add_emission_hook(XEN signal_id, XEN quark, XEN hook_func, XEN func_data, XEN data_destroy)
{
  #define H_g_signal_add_emission_hook "gulong g_signal_add_emission_hook(guint signal_id, GQuark quark, \
GSignalEmissionHook hook_func, lambda_data func_data, GtkDestroyNotify data_destroy)"
  XEN_ASSERT_TYPE(XEN_guint_P(signal_id), signal_id, 1, "g_signal_add_emission_hook", "guint");
  XEN_ASSERT_TYPE(XEN_GQuark_P(quark), quark, 2, "g_signal_add_emission_hook", "GQuark");
  XEN_ASSERT_TYPE(XEN_GSignalEmissionHook_P(hook_func), hook_func, 3, "g_signal_add_emission_hook", "GSignalEmissionHook");
  XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 4, "g_signal_add_emission_hook", "lambda_data");
  XEN_ASSERT_TYPE(XEN_GtkDestroyNotify_P(data_destroy), data_destroy, 5, "g_signal_add_emission_hook", "GtkDestroyNotify");
  {
    XEN result = XEN_FALSE;
    XEN gxg_ptr = XEN_LIST_5(XEN_FALSE, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 3, data_destroy);
    result = C_TO_XEN_gulong(g_signal_add_emission_hook(XEN_TO_C_guint(signal_id), XEN_TO_C_GQuark(quark), XEN_TO_C_GSignalEmissionHook(hook_func), 
                                                        XEN_TO_C_lambda_data(func_data), XEN_TO_C_GtkDestroyNotify(data_destroy)));
    return(result);
   }
}
static XEN gxg_g_signal_remove_emission_hook(XEN signal_id, XEN hook_id)
{
  #define H_g_signal_remove_emission_hook "void g_signal_remove_emission_hook(guint signal_id, gulong hook_id)"
  XEN_ASSERT_TYPE(XEN_guint_P(signal_id), signal_id, 1, "g_signal_remove_emission_hook", "guint");
  XEN_ASSERT_TYPE(XEN_gulong_P(hook_id), hook_id, 2, "g_signal_remove_emission_hook", "gulong");
  g_signal_remove_emission_hook(XEN_TO_C_guint(signal_id), XEN_TO_C_gulong(hook_id));
  return(XEN_FALSE);
}
static XEN gxg_g_signal_has_handler_pending(XEN instance, XEN signal_id, XEN detail, XEN may_be_blocked)
{
  #define H_g_signal_has_handler_pending "gboolean g_signal_has_handler_pending(gpointer instance, guint signal_id, \
GQuark detail, gboolean may_be_blocked)"
  XEN_ASSERT_TYPE(XEN_gpointer_P(instance), instance, 1, "g_signal_has_handler_pending", "gpointer");
  XEN_ASSERT_TYPE(XEN_guint_P(signal_id), signal_id, 2, "g_signal_has_handler_pending", "guint");
  XEN_ASSERT_TYPE(XEN_GQuark_P(detail), detail, 3, "g_signal_has_handler_pending", "GQuark");
  XEN_ASSERT_TYPE(XEN_gboolean_P(may_be_blocked), may_be_blocked, 4, "g_signal_has_handler_pending", "gboolean");
  return(C_TO_XEN_gboolean(g_signal_has_handler_pending(XEN_TO_C_gpointer(instance), XEN_TO_C_guint(signal_id), XEN_TO_C_GQuark(detail), 
                                                        XEN_TO_C_gboolean(may_be_blocked))));
}
static XEN gxg_g_signal_connect_closure_by_id(XEN instance, XEN signal_id, XEN detail, XEN closure, XEN after)
{
  #define H_g_signal_connect_closure_by_id "gulong g_signal_connect_closure_by_id(gpointer instance, \
guint signal_id, GQuark detail, GClosure* closure, gboolean after)"
  XEN_ASSERT_TYPE(XEN_gpointer_P(instance), instance, 1, "g_signal_connect_closure_by_id", "gpointer");
  XEN_ASSERT_TYPE(XEN_guint_P(signal_id), signal_id, 2, "g_signal_connect_closure_by_id", "guint");
  XEN_ASSERT_TYPE(XEN_GQuark_P(detail), detail, 3, "g_signal_connect_closure_by_id", "GQuark");
  XEN_ASSERT_TYPE(XEN_GClosure__P(closure), closure, 4, "g_signal_connect_closure_by_id", "GClosure*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(after), after, 5, "g_signal_connect_closure_by_id", "gboolean");
  return(C_TO_XEN_gulong(g_signal_connect_closure_by_id(XEN_TO_C_gpointer(instance), XEN_TO_C_guint(signal_id), XEN_TO_C_GQuark(detail), 
                                                        XEN_TO_C_GClosure_(closure), XEN_TO_C_gboolean(after))));
}
static XEN gxg_g_signal_connect_closure(XEN instance, XEN detailed_signal, XEN closure, XEN after)
{
  #define H_g_signal_connect_closure "gulong g_signal_connect_closure(gpointer instance, gchar* detailed_signal, \
GClosure* closure, gboolean after)"
  XEN_ASSERT_TYPE(XEN_gpointer_P(instance), instance, 1, "g_signal_connect_closure", "gpointer");
  XEN_ASSERT_TYPE(XEN_gchar__P(detailed_signal), detailed_signal, 2, "g_signal_connect_closure", "gchar*");
  XEN_ASSERT_TYPE(XEN_GClosure__P(closure), closure, 3, "g_signal_connect_closure", "GClosure*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(after), after, 4, "g_signal_connect_closure", "gboolean");
  return(C_TO_XEN_gulong(g_signal_connect_closure(XEN_TO_C_gpointer(instance), XEN_TO_C_gchar_(detailed_signal), XEN_TO_C_GClosure_(closure), 
                                                  XEN_TO_C_gboolean(after))));
}
static XEN gxg_g_signal_connect_data(XEN instance, XEN detailed_signal, XEN func, XEN func_data, XEN destroy_data, XEN connect_flags)
{
  #define H_g_signal_connect_data "gulong g_signal_connect_data(gpointer instance, gchar* detailed_signal, \
GCallback func, lambda_data func_data, GClosureNotify destroy_data, GConnectFlags connect_flags)"
  XEN_ASSERT_TYPE(XEN_gpointer_P(instance), instance, 1, "g_signal_connect_data", "gpointer");
  XEN_ASSERT_TYPE(XEN_gchar__P(detailed_signal), detailed_signal, 2, "g_signal_connect_data", "gchar*");
  XEN_ASSERT_TYPE(XEN_GCallback_P(func), func, 3, "g_signal_connect_data", "GCallback");
  XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 4, "g_signal_connect_data", "lambda_data");
  XEN_ASSERT_TYPE(XEN_GClosureNotify_P(destroy_data), destroy_data, 5, "g_signal_connect_data", "GClosureNotify");
  XEN_ASSERT_TYPE(XEN_GConnectFlags_P(connect_flags), connect_flags, 6, "g_signal_connect_data", "GConnectFlags");
  {
    XEN result = XEN_FALSE;
    int loc;
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    loc = xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 2, C_TO_XEN_INT(loc));
    result = C_TO_XEN_gulong(g_signal_connect_data(XEN_TO_C_gpointer(instance), XEN_TO_C_gchar_(detailed_signal), XEN_TO_C_GCallback(func), 
                                                   XEN_TO_C_lambda_data(func_data), XEN_TO_C_GClosureNotify(destroy_data), 
                                                   XEN_TO_C_GConnectFlags(connect_flags)));
    return(result);
   }
}
static XEN gxg_g_signal_handler_block(XEN instance, XEN handler_id)
{
  #define H_g_signal_handler_block "void g_signal_handler_block(gpointer instance, gulong handler_id)"
  XEN_ASSERT_TYPE(XEN_gpointer_P(instance), instance, 1, "g_signal_handler_block", "gpointer");
  XEN_ASSERT_TYPE(XEN_gulong_P(handler_id), handler_id, 2, "g_signal_handler_block", "gulong");
  g_signal_handler_block(XEN_TO_C_gpointer(instance), XEN_TO_C_gulong(handler_id));
  return(XEN_FALSE);
}
static XEN gxg_g_signal_handler_unblock(XEN instance, XEN handler_id)
{
  #define H_g_signal_handler_unblock "void g_signal_handler_unblock(gpointer instance, gulong handler_id)"
  XEN_ASSERT_TYPE(XEN_gpointer_P(instance), instance, 1, "g_signal_handler_unblock", "gpointer");
  XEN_ASSERT_TYPE(XEN_gulong_P(handler_id), handler_id, 2, "g_signal_handler_unblock", "gulong");
  g_signal_handler_unblock(XEN_TO_C_gpointer(instance), XEN_TO_C_gulong(handler_id));
  return(XEN_FALSE);
}
static XEN gxg_g_signal_handler_disconnect(XEN instance, XEN handler_id)
{
  #define H_g_signal_handler_disconnect "void g_signal_handler_disconnect(gpointer instance, gulong handler_id)"
  XEN_ASSERT_TYPE(XEN_gpointer_P(instance), instance, 1, "g_signal_handler_disconnect", "gpointer");
  XEN_ASSERT_TYPE(XEN_gulong_P(handler_id), handler_id, 2, "g_signal_handler_disconnect", "gulong");
  g_signal_handler_disconnect(XEN_TO_C_gpointer(instance), XEN_TO_C_gulong(handler_id));
  return(XEN_FALSE);
}
static XEN gxg_g_signal_handler_is_connected(XEN instance, XEN handler_id)
{
  #define H_g_signal_handler_is_connected "gboolean g_signal_handler_is_connected(gpointer instance, \
gulong handler_id)"
  XEN_ASSERT_TYPE(XEN_gpointer_P(instance), instance, 1, "g_signal_handler_is_connected", "gpointer");
  XEN_ASSERT_TYPE(XEN_gulong_P(handler_id), handler_id, 2, "g_signal_handler_is_connected", "gulong");
  return(C_TO_XEN_gboolean(g_signal_handler_is_connected(XEN_TO_C_gpointer(instance), XEN_TO_C_gulong(handler_id))));
}
static XEN gxg_g_signal_handler_find(XEN instance, XEN mask, XEN signal_id, XEN detail, XEN closure, XEN func, XEN data)
{
  #define H_g_signal_handler_find "gulong g_signal_handler_find(gpointer instance, GSignalMatchType mask, \
guint signal_id, GQuark detail, GClosure* closure, gpointer func, gpointer data)"
  XEN_ASSERT_TYPE(XEN_gpointer_P(instance), instance, 1, "g_signal_handler_find", "gpointer");
  XEN_ASSERT_TYPE(XEN_GSignalMatchType_P(mask), mask, 2, "g_signal_handler_find", "GSignalMatchType");
  XEN_ASSERT_TYPE(XEN_guint_P(signal_id), signal_id, 3, "g_signal_handler_find", "guint");
  XEN_ASSERT_TYPE(XEN_GQuark_P(detail), detail, 4, "g_signal_handler_find", "GQuark");
  XEN_ASSERT_TYPE(XEN_GClosure__P(closure), closure, 5, "g_signal_handler_find", "GClosure*");
  XEN_ASSERT_TYPE(XEN_gpointer_P(func), func, 6, "g_signal_handler_find", "gpointer");
  XEN_ASSERT_TYPE(XEN_gpointer_P(data), data, 7, "g_signal_handler_find", "gpointer");
  return(C_TO_XEN_gulong(g_signal_handler_find(XEN_TO_C_gpointer(instance), XEN_TO_C_GSignalMatchType(mask), XEN_TO_C_guint(signal_id), 
                                               XEN_TO_C_GQuark(detail), XEN_TO_C_GClosure_(closure), XEN_TO_C_gpointer(func), 
                                               XEN_TO_C_gpointer(data))));
}
static XEN gxg_g_signal_handlers_block_matched(XEN instance, XEN mask, XEN signal_id, XEN detail, XEN closure, XEN func, XEN data)
{
  #define H_g_signal_handlers_block_matched "guint g_signal_handlers_block_matched(gpointer instance, \
GSignalMatchType mask, guint signal_id, GQuark detail, GClosure* closure, gpointer func, gpointer data)"
  XEN_ASSERT_TYPE(XEN_gpointer_P(instance), instance, 1, "g_signal_handlers_block_matched", "gpointer");
  XEN_ASSERT_TYPE(XEN_GSignalMatchType_P(mask), mask, 2, "g_signal_handlers_block_matched", "GSignalMatchType");
  XEN_ASSERT_TYPE(XEN_guint_P(signal_id), signal_id, 3, "g_signal_handlers_block_matched", "guint");
  XEN_ASSERT_TYPE(XEN_GQuark_P(detail), detail, 4, "g_signal_handlers_block_matched", "GQuark");
  XEN_ASSERT_TYPE(XEN_GClosure__P(closure), closure, 5, "g_signal_handlers_block_matched", "GClosure*");
  XEN_ASSERT_TYPE(XEN_gpointer_P(func), func, 6, "g_signal_handlers_block_matched", "gpointer");
  XEN_ASSERT_TYPE(XEN_gpointer_P(data), data, 7, "g_signal_handlers_block_matched", "gpointer");
  return(C_TO_XEN_guint(g_signal_handlers_block_matched(XEN_TO_C_gpointer(instance), XEN_TO_C_GSignalMatchType(mask), XEN_TO_C_guint(signal_id), 
                                                        XEN_TO_C_GQuark(detail), XEN_TO_C_GClosure_(closure), XEN_TO_C_gpointer(func), 
                                                        XEN_TO_C_gpointer(data))));
}
static XEN gxg_g_signal_handlers_unblock_matched(XEN instance, XEN mask, XEN signal_id, XEN detail, XEN closure, XEN func, XEN data)
{
  #define H_g_signal_handlers_unblock_matched "guint g_signal_handlers_unblock_matched(gpointer instance, \
GSignalMatchType mask, guint signal_id, GQuark detail, GClosure* closure, gpointer func, gpointer data)"
  XEN_ASSERT_TYPE(XEN_gpointer_P(instance), instance, 1, "g_signal_handlers_unblock_matched", "gpointer");
  XEN_ASSERT_TYPE(XEN_GSignalMatchType_P(mask), mask, 2, "g_signal_handlers_unblock_matched", "GSignalMatchType");
  XEN_ASSERT_TYPE(XEN_guint_P(signal_id), signal_id, 3, "g_signal_handlers_unblock_matched", "guint");
  XEN_ASSERT_TYPE(XEN_GQuark_P(detail), detail, 4, "g_signal_handlers_unblock_matched", "GQuark");
  XEN_ASSERT_TYPE(XEN_GClosure__P(closure), closure, 5, "g_signal_handlers_unblock_matched", "GClosure*");
  XEN_ASSERT_TYPE(XEN_gpointer_P(func), func, 6, "g_signal_handlers_unblock_matched", "gpointer");
  XEN_ASSERT_TYPE(XEN_gpointer_P(data), data, 7, "g_signal_handlers_unblock_matched", "gpointer");
  return(C_TO_XEN_guint(g_signal_handlers_unblock_matched(XEN_TO_C_gpointer(instance), XEN_TO_C_GSignalMatchType(mask), XEN_TO_C_guint(signal_id), 
                                                          XEN_TO_C_GQuark(detail), XEN_TO_C_GClosure_(closure), XEN_TO_C_gpointer(func), 
                                                          XEN_TO_C_gpointer(data))));
}
static XEN gxg_g_signal_handlers_disconnect_matched(XEN instance, XEN mask, XEN signal_id, XEN detail, XEN closure, XEN func, XEN data)
{
  #define H_g_signal_handlers_disconnect_matched "guint g_signal_handlers_disconnect_matched(gpointer instance, \
GSignalMatchType mask, guint signal_id, GQuark detail, GClosure* closure, gpointer func, gpointer data)"
  XEN_ASSERT_TYPE(XEN_gpointer_P(instance), instance, 1, "g_signal_handlers_disconnect_matched", "gpointer");
  XEN_ASSERT_TYPE(XEN_GSignalMatchType_P(mask), mask, 2, "g_signal_handlers_disconnect_matched", "GSignalMatchType");
  XEN_ASSERT_TYPE(XEN_guint_P(signal_id), signal_id, 3, "g_signal_handlers_disconnect_matched", "guint");
  XEN_ASSERT_TYPE(XEN_GQuark_P(detail), detail, 4, "g_signal_handlers_disconnect_matched", "GQuark");
  XEN_ASSERT_TYPE(XEN_GClosure__P(closure), closure, 5, "g_signal_handlers_disconnect_matched", "GClosure*");
  XEN_ASSERT_TYPE(XEN_gpointer_P(func), func, 6, "g_signal_handlers_disconnect_matched", "gpointer");
  XEN_ASSERT_TYPE(XEN_gpointer_P(data), data, 7, "g_signal_handlers_disconnect_matched", "gpointer");
  return(C_TO_XEN_guint(g_signal_handlers_disconnect_matched(XEN_TO_C_gpointer(instance), XEN_TO_C_GSignalMatchType(mask), 
                                                             XEN_TO_C_guint(signal_id), XEN_TO_C_GQuark(detail), XEN_TO_C_GClosure_(closure), 
                                                             XEN_TO_C_gpointer(func), XEN_TO_C_gpointer(data))));
}
static XEN gxg_g_signal_handlers_destroy(XEN instance)
{
  #define H_g_signal_handlers_destroy "void g_signal_handlers_destroy(gpointer instance)"
  XEN_ASSERT_TYPE(XEN_gpointer_P(instance), instance, 1, "g_signal_handlers_destroy", "gpointer");
  g_signal_handlers_destroy(XEN_TO_C_gpointer(instance));
  return(XEN_FALSE);
}
static XEN gxg_g_object_ref(XEN object)
{
  #define H_g_object_ref "gpointer g_object_ref(gpointer object)"
  XEN_ASSERT_TYPE(XEN_gpointer_P(object), object, 1, "g_object_ref", "gpointer");
  return(C_TO_XEN_gpointer(g_object_ref(XEN_TO_C_gpointer(object))));
}
static XEN gxg_g_object_unref(XEN object)
{
  #define H_g_object_unref "void g_object_unref(gpointer object)"
  XEN_ASSERT_TYPE(XEN_gpointer_P(object), object, 1, "g_object_unref", "gpointer");
  g_object_unref(XEN_TO_C_gpointer(object));
  return(XEN_FALSE);
}
static XEN gxg_gdk_colormap_get_type(void)
{
  #define H_gdk_colormap_get_type "GType gdk_colormap_get_type( void)"
  return(C_TO_XEN_GType(gdk_colormap_get_type()));
}
static XEN gxg_gdk_colormap_new(XEN visual, XEN allocate)
{
  #define H_gdk_colormap_new "GdkColormap* gdk_colormap_new(GdkVisual* visual, gboolean allocate)"
  XEN_ASSERT_TYPE(XEN_GdkVisual__P(visual), visual, 1, "gdk_colormap_new", "GdkVisual*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(allocate), allocate, 2, "gdk_colormap_new", "gboolean");
  return(C_TO_XEN_GdkColormap_(gdk_colormap_new(XEN_TO_C_GdkVisual_(visual), XEN_TO_C_gboolean(allocate))));
}
static XEN gxg_gdk_colormap_get_system(void)
{
  #define H_gdk_colormap_get_system "GdkColormap* gdk_colormap_get_system( void)"
  return(C_TO_XEN_GdkColormap_(gdk_colormap_get_system()));
}
static XEN gxg_gdk_colormap_alloc_colors(XEN colormap, XEN colors, XEN ncolors, XEN writeable, XEN best_match, XEN success)
{
  #define H_gdk_colormap_alloc_colors "gint gdk_colormap_alloc_colors(GdkColormap* colormap, GdkColor* colors, \
gint ncolors, gboolean writeable, gboolean best_match, gboolean* success)"
  XEN_ASSERT_TYPE(XEN_GdkColormap__P(colormap), colormap, 1, "gdk_colormap_alloc_colors", "GdkColormap*");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(colors), colors, 2, "gdk_colormap_alloc_colors", "GdkColor*");
  XEN_ASSERT_TYPE(XEN_gint_P(ncolors), ncolors, 3, "gdk_colormap_alloc_colors", "gint");
  XEN_ASSERT_TYPE(XEN_gboolean_P(writeable), writeable, 4, "gdk_colormap_alloc_colors", "gboolean");
  XEN_ASSERT_TYPE(XEN_gboolean_P(best_match), best_match, 5, "gdk_colormap_alloc_colors", "gboolean");
  XEN_ASSERT_TYPE(XEN_gboolean__P(success), success, 6, "gdk_colormap_alloc_colors", "gboolean*");
  return(C_TO_XEN_gint(gdk_colormap_alloc_colors(XEN_TO_C_GdkColormap_(colormap), XEN_TO_C_GdkColor_(colors), XEN_TO_C_gint(ncolors), 
                                                 XEN_TO_C_gboolean(writeable), XEN_TO_C_gboolean(best_match), XEN_TO_C_gboolean_(success))));
}
static XEN gxg_gdk_colormap_alloc_color(XEN colormap, XEN color, XEN writeable, XEN best_match)
{
  #define H_gdk_colormap_alloc_color "gboolean gdk_colormap_alloc_color(GdkColormap* colormap, GdkColor* color, \
gboolean writeable, gboolean best_match)"
  XEN_ASSERT_TYPE(XEN_GdkColormap__P(colormap), colormap, 1, "gdk_colormap_alloc_color", "GdkColormap*");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(color), color, 2, "gdk_colormap_alloc_color", "GdkColor*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(writeable), writeable, 3, "gdk_colormap_alloc_color", "gboolean");
  XEN_ASSERT_TYPE(XEN_gboolean_P(best_match), best_match, 4, "gdk_colormap_alloc_color", "gboolean");
  return(C_TO_XEN_gboolean(gdk_colormap_alloc_color(XEN_TO_C_GdkColormap_(colormap), XEN_TO_C_GdkColor_(color), XEN_TO_C_gboolean(writeable), 
                                                    XEN_TO_C_gboolean(best_match))));
}
static XEN gxg_gdk_colormap_query_color(XEN colormap, XEN pixel, XEN result)
{
  #define H_gdk_colormap_query_color "void gdk_colormap_query_color(GdkColormap* colormap, gulong pixel, \
GdkColor* result)"
  XEN_ASSERT_TYPE(XEN_GdkColormap__P(colormap), colormap, 1, "gdk_colormap_query_color", "GdkColormap*");
  XEN_ASSERT_TYPE(XEN_gulong_P(pixel), pixel, 2, "gdk_colormap_query_color", "gulong");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(result), result, 3, "gdk_colormap_query_color", "GdkColor*");
  gdk_colormap_query_color(XEN_TO_C_GdkColormap_(colormap), XEN_TO_C_gulong(pixel), XEN_TO_C_GdkColor_(result));
  return(XEN_FALSE);
}
static XEN gxg_gdk_colormap_get_visual(XEN colormap)
{
  #define H_gdk_colormap_get_visual "GdkVisual* gdk_colormap_get_visual(GdkColormap* colormap)"
  XEN_ASSERT_TYPE(XEN_GdkColormap__P(colormap), colormap, 1, "gdk_colormap_get_visual", "GdkColormap*");
  return(C_TO_XEN_GdkVisual_(gdk_colormap_get_visual(XEN_TO_C_GdkColormap_(colormap))));
}
static XEN gxg_gdk_color_copy(XEN color)
{
  #define H_gdk_color_copy "GdkColor* gdk_color_copy(GdkColor* color)"
  XEN_ASSERT_TYPE(XEN_GdkColor__P(color), color, 1, "gdk_color_copy", "GdkColor*");
  return(C_TO_XEN_GdkColor_(gdk_color_copy(XEN_TO_C_GdkColor_(color))));
}
static XEN gxg_gdk_color_free(XEN color)
{
  #define H_gdk_color_free "void gdk_color_free(GdkColor* color)"
  XEN_ASSERT_TYPE(XEN_GdkColor__P(color), color, 1, "gdk_color_free", "GdkColor*");
  gdk_color_free(XEN_TO_C_GdkColor_(color));
  return(XEN_FALSE);
}
static XEN gxg_gdk_color_parse(XEN spec, XEN color)
{
  #define H_gdk_color_parse "gint gdk_color_parse(gchar* spec, GdkColor* color)"
  XEN_ASSERT_TYPE(XEN_gchar__P(spec), spec, 1, "gdk_color_parse", "gchar*");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(color), color, 2, "gdk_color_parse", "GdkColor*");
  return(C_TO_XEN_gint(gdk_color_parse(XEN_TO_C_gchar_(spec), XEN_TO_C_GdkColor_(color))));
}
static XEN gxg_gdk_color_hash(XEN colora)
{
  #define H_gdk_color_hash "guint gdk_color_hash(GdkColor* colora)"
  XEN_ASSERT_TYPE(XEN_GdkColor__P(colora), colora, 1, "gdk_color_hash", "GdkColor*");
  return(C_TO_XEN_guint(gdk_color_hash(XEN_TO_C_GdkColor_(colora))));
}
static XEN gxg_gdk_color_equal(XEN colora, XEN colorb)
{
  #define H_gdk_color_equal "gboolean gdk_color_equal(GdkColor* colora, GdkColor* colorb)"
  XEN_ASSERT_TYPE(XEN_GdkColor__P(colora), colora, 1, "gdk_color_equal", "GdkColor*");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(colorb), colorb, 2, "gdk_color_equal", "GdkColor*");
  return(C_TO_XEN_gboolean(gdk_color_equal(XEN_TO_C_GdkColor_(colora), XEN_TO_C_GdkColor_(colorb))));
}
static XEN gxg_gdk_color_get_type(void)
{
  #define H_gdk_color_get_type "GType gdk_color_get_type( void)"
  return(C_TO_XEN_GType(gdk_color_get_type()));
}
static XEN gxg_gdk_cursor_get_type(void)
{
  #define H_gdk_cursor_get_type "GType gdk_cursor_get_type( void)"
  return(C_TO_XEN_GType(gdk_cursor_get_type()));
}
static XEN gxg_gdk_cursor_new(XEN cursor_type)
{
  #define H_gdk_cursor_new "GdkCursor* gdk_cursor_new(GdkCursorType cursor_type)"
  XEN_ASSERT_TYPE(XEN_GdkCursorType_P(cursor_type), cursor_type, 1, "gdk_cursor_new", "GdkCursorType");
  return(C_TO_XEN_GdkCursor_(gdk_cursor_new(XEN_TO_C_GdkCursorType(cursor_type))));
}
static XEN gxg_gdk_cursor_new_from_pixmap(XEN source, XEN mask, XEN fg, XEN bg, XEN x, XEN y)
{
  #define H_gdk_cursor_new_from_pixmap "GdkCursor* gdk_cursor_new_from_pixmap(GdkPixmap* source, GdkPixmap* mask, \
GdkColor* fg, GdkColor* bg, gint x, gint y)"
  XEN_ASSERT_TYPE(XEN_GdkPixmap__P(source), source, 1, "gdk_cursor_new_from_pixmap", "GdkPixmap*");
  XEN_ASSERT_TYPE(XEN_GdkPixmap__P(mask), mask, 2, "gdk_cursor_new_from_pixmap", "GdkPixmap*");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(fg), fg, 3, "gdk_cursor_new_from_pixmap", "GdkColor*");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(bg), bg, 4, "gdk_cursor_new_from_pixmap", "GdkColor*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 5, "gdk_cursor_new_from_pixmap", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 6, "gdk_cursor_new_from_pixmap", "gint");
  return(C_TO_XEN_GdkCursor_(gdk_cursor_new_from_pixmap(XEN_TO_C_GdkPixmap_(source), XEN_TO_C_GdkPixmap_(mask), XEN_TO_C_GdkColor_(fg), 
                                                        XEN_TO_C_GdkColor_(bg), XEN_TO_C_gint(x), XEN_TO_C_gint(y))));
}
static XEN gxg_gdk_cursor_ref(XEN cursor)
{
  #define H_gdk_cursor_ref "GdkCursor* gdk_cursor_ref(GdkCursor* cursor)"
  XEN_ASSERT_TYPE(XEN_GdkCursor__P(cursor), cursor, 1, "gdk_cursor_ref", "GdkCursor*");
  return(C_TO_XEN_GdkCursor_(gdk_cursor_ref(XEN_TO_C_GdkCursor_(cursor))));
}
static XEN gxg_gdk_cursor_unref(XEN cursor)
{
  #define H_gdk_cursor_unref "void gdk_cursor_unref(GdkCursor* cursor)"
  XEN_ASSERT_TYPE(XEN_GdkCursor__P(cursor), cursor, 1, "gdk_cursor_unref", "GdkCursor*");
  gdk_cursor_unref(XEN_TO_C_GdkCursor_(cursor));
  return(XEN_FALSE);
}
static XEN gxg_gdk_drag_context_get_type(void)
{
  #define H_gdk_drag_context_get_type "GType gdk_drag_context_get_type( void)"
  return(C_TO_XEN_GType(gdk_drag_context_get_type()));
}
static XEN gxg_gdk_drag_context_new(void)
{
  #define H_gdk_drag_context_new "GdkDragContext* gdk_drag_context_new( void)"
  return(C_TO_XEN_GdkDragContext_(gdk_drag_context_new()));
}
static XEN gxg_gdk_drag_status(XEN context, XEN action, XEN time)
{
  #define H_gdk_drag_status "void gdk_drag_status(GdkDragContext* context, GdkDragAction action, guint32 time)"
  XEN_ASSERT_TYPE(XEN_GdkDragContext__P(context), context, 1, "gdk_drag_status", "GdkDragContext*");
  XEN_ASSERT_TYPE(XEN_GdkDragAction_P(action), action, 2, "gdk_drag_status", "GdkDragAction");
  XEN_ASSERT_TYPE(XEN_guint32_P(time), time, 3, "gdk_drag_status", "guint32");
  gdk_drag_status(XEN_TO_C_GdkDragContext_(context), XEN_TO_C_GdkDragAction(action), XEN_TO_C_guint32(time));
  return(XEN_FALSE);
}
static XEN gxg_gdk_drop_reply(XEN context, XEN ok, XEN time)
{
  #define H_gdk_drop_reply "void gdk_drop_reply(GdkDragContext* context, gboolean ok, guint32 time)"
  XEN_ASSERT_TYPE(XEN_GdkDragContext__P(context), context, 1, "gdk_drop_reply", "GdkDragContext*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(ok), ok, 2, "gdk_drop_reply", "gboolean");
  XEN_ASSERT_TYPE(XEN_guint32_P(time), time, 3, "gdk_drop_reply", "guint32");
  gdk_drop_reply(XEN_TO_C_GdkDragContext_(context), XEN_TO_C_gboolean(ok), XEN_TO_C_guint32(time));
  return(XEN_FALSE);
}
static XEN gxg_gdk_drop_finish(XEN context, XEN success, XEN time)
{
  #define H_gdk_drop_finish "void gdk_drop_finish(GdkDragContext* context, gboolean success, guint32 time)"
  XEN_ASSERT_TYPE(XEN_GdkDragContext__P(context), context, 1, "gdk_drop_finish", "GdkDragContext*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(success), success, 2, "gdk_drop_finish", "gboolean");
  XEN_ASSERT_TYPE(XEN_guint32_P(time), time, 3, "gdk_drop_finish", "guint32");
  gdk_drop_finish(XEN_TO_C_GdkDragContext_(context), XEN_TO_C_gboolean(success), XEN_TO_C_guint32(time));
  return(XEN_FALSE);
}
static XEN gxg_gdk_drag_get_selection(XEN context)
{
  #define H_gdk_drag_get_selection "GdkAtom gdk_drag_get_selection(GdkDragContext* context)"
  XEN_ASSERT_TYPE(XEN_GdkDragContext__P(context), context, 1, "gdk_drag_get_selection", "GdkDragContext*");
  return(C_TO_XEN_GdkAtom(gdk_drag_get_selection(XEN_TO_C_GdkDragContext_(context))));
}
static XEN gxg_gdk_drag_begin(XEN window, XEN targets)
{
  #define H_gdk_drag_begin "GdkDragContext* gdk_drag_begin(GdkWindow* window, GList* targets)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_drag_begin", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GList__P(targets), targets, 2, "gdk_drag_begin", "GList*");
  return(C_TO_XEN_GdkDragContext_(gdk_drag_begin(XEN_TO_C_GdkWindow_(window), XEN_TO_C_GList_(targets))));
}
static XEN gxg_gdk_drag_get_protocol(XEN xid, XEN protocol)
{
  #define H_gdk_drag_get_protocol "guint32 gdk_drag_get_protocol(guint32 xid, GdkDragProtocol* [protocol])"
  GdkDragProtocol ref_protocol;
  XEN_ASSERT_TYPE(XEN_guint32_P(xid), xid, 1, "gdk_drag_get_protocol", "guint32");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_guint32(gdk_drag_get_protocol(XEN_TO_C_guint32(xid), &ref_protocol));
    return(XEN_LIST_2(result, C_TO_XEN_GdkDragProtocol(ref_protocol)));
   }
}
static XEN gxg_gdk_drag_find_window(XEN context, XEN drag_window, XEN x_root, XEN y_root, XEN dest_window, XEN protocol)
{
  #define H_gdk_drag_find_window "void gdk_drag_find_window(GdkDragContext* context, GdkWindow* drag_window, \
gint x_root, gint y_root, GdkWindow** [dest_window], GdkDragProtocol* [protocol])"
  GdkWindow* ref_dest_window = NULL;
  GdkDragProtocol ref_protocol;
  XEN_ASSERT_TYPE(XEN_GdkDragContext__P(context), context, 1, "gdk_drag_find_window", "GdkDragContext*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(drag_window), drag_window, 2, "gdk_drag_find_window", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_gint_P(x_root), x_root, 3, "gdk_drag_find_window", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y_root), y_root, 4, "gdk_drag_find_window", "gint");
  gdk_drag_find_window(XEN_TO_C_GdkDragContext_(context), XEN_TO_C_GdkWindow_(drag_window), XEN_TO_C_gint(x_root), XEN_TO_C_gint(y_root), 
                       &ref_dest_window, &ref_protocol);
  return(XEN_LIST_2(C_TO_XEN_GdkWindow_(ref_dest_window), C_TO_XEN_GdkDragProtocol(ref_protocol)));
}
static XEN gxg_gdk_drag_motion(XEN context, XEN dest_window, XEN protocol, XEN x_root, XEN y_root, XEN suggested_action, XEN possible_actions, XEN time)
{
  #define H_gdk_drag_motion "gboolean gdk_drag_motion(GdkDragContext* context, GdkWindow* dest_window, \
GdkDragProtocol protocol, gint x_root, gint y_root, GdkDragAction suggested_action, GdkDragAction possible_actions, \
guint32 time)"
  XEN_ASSERT_TYPE(XEN_GdkDragContext__P(context), context, 1, "gdk_drag_motion", "GdkDragContext*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(dest_window), dest_window, 2, "gdk_drag_motion", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkDragProtocol_P(protocol), protocol, 3, "gdk_drag_motion", "GdkDragProtocol");
  XEN_ASSERT_TYPE(XEN_gint_P(x_root), x_root, 4, "gdk_drag_motion", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y_root), y_root, 5, "gdk_drag_motion", "gint");
  XEN_ASSERT_TYPE(XEN_GdkDragAction_P(suggested_action), suggested_action, 6, "gdk_drag_motion", "GdkDragAction");
  XEN_ASSERT_TYPE(XEN_GdkDragAction_P(possible_actions), possible_actions, 7, "gdk_drag_motion", "GdkDragAction");
  XEN_ASSERT_TYPE(XEN_guint32_P(time), time, 8, "gdk_drag_motion", "guint32");
  return(C_TO_XEN_gboolean(gdk_drag_motion(XEN_TO_C_GdkDragContext_(context), XEN_TO_C_GdkWindow_(dest_window), XEN_TO_C_GdkDragProtocol(protocol), 
                                           XEN_TO_C_gint(x_root), XEN_TO_C_gint(y_root), XEN_TO_C_GdkDragAction(suggested_action), 
                                           XEN_TO_C_GdkDragAction(possible_actions), XEN_TO_C_guint32(time))));
}
static XEN gxg_gdk_drag_drop(XEN context, XEN time)
{
  #define H_gdk_drag_drop "void gdk_drag_drop(GdkDragContext* context, guint32 time)"
  XEN_ASSERT_TYPE(XEN_GdkDragContext__P(context), context, 1, "gdk_drag_drop", "GdkDragContext*");
  XEN_ASSERT_TYPE(XEN_guint32_P(time), time, 2, "gdk_drag_drop", "guint32");
  gdk_drag_drop(XEN_TO_C_GdkDragContext_(context), XEN_TO_C_guint32(time));
  return(XEN_FALSE);
}
static XEN gxg_gdk_drag_abort(XEN context, XEN time)
{
  #define H_gdk_drag_abort "void gdk_drag_abort(GdkDragContext* context, guint32 time)"
  XEN_ASSERT_TYPE(XEN_GdkDragContext__P(context), context, 1, "gdk_drag_abort", "GdkDragContext*");
  XEN_ASSERT_TYPE(XEN_guint32_P(time), time, 2, "gdk_drag_abort", "guint32");
  gdk_drag_abort(XEN_TO_C_GdkDragContext_(context), XEN_TO_C_guint32(time));
  return(XEN_FALSE);
}
static XEN gxg_gdk_drawable_get_type(void)
{
  #define H_gdk_drawable_get_type "GType gdk_drawable_get_type( void)"
  return(C_TO_XEN_GType(gdk_drawable_get_type()));
}
static XEN gxg_gdk_drawable_get_size(XEN drawable, XEN width, XEN height)
{
  #define H_gdk_drawable_get_size "void gdk_drawable_get_size(GdkDrawable* drawable, gint* [width], gint* [height])"
  gint ref_width;
  gint ref_height;
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_drawable_get_size", "GdkDrawable*");
  gdk_drawable_get_size(XEN_TO_C_GdkDrawable_(drawable), &ref_width, &ref_height);
  return(XEN_LIST_2(C_TO_XEN_gint(ref_width), C_TO_XEN_gint(ref_height)));
}
static XEN gxg_gdk_drawable_set_colormap(XEN drawable, XEN colormap)
{
  #define H_gdk_drawable_set_colormap "void gdk_drawable_set_colormap(GdkDrawable* drawable, GdkColormap* colormap)"
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_drawable_set_colormap", "GdkDrawable*");
  XEN_ASSERT_TYPE(XEN_GdkColormap__P(colormap), colormap, 2, "gdk_drawable_set_colormap", "GdkColormap*");
  gdk_drawable_set_colormap(XEN_TO_C_GdkDrawable_(drawable), XEN_TO_C_GdkColormap_(colormap));
  return(XEN_FALSE);
}
static XEN gxg_gdk_drawable_get_colormap(XEN drawable)
{
  #define H_gdk_drawable_get_colormap "GdkColormap* gdk_drawable_get_colormap(GdkDrawable* drawable)"
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_drawable_get_colormap", "GdkDrawable*");
  return(C_TO_XEN_GdkColormap_(gdk_drawable_get_colormap(XEN_TO_C_GdkDrawable_(drawable))));
}
static XEN gxg_gdk_drawable_get_visual(XEN drawable)
{
  #define H_gdk_drawable_get_visual "GdkVisual* gdk_drawable_get_visual(GdkDrawable* drawable)"
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_drawable_get_visual", "GdkDrawable*");
  return(C_TO_XEN_GdkVisual_(gdk_drawable_get_visual(XEN_TO_C_GdkDrawable_(drawable))));
}
static XEN gxg_gdk_drawable_get_depth(XEN drawable)
{
  #define H_gdk_drawable_get_depth "gint gdk_drawable_get_depth(GdkDrawable* drawable)"
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_drawable_get_depth", "GdkDrawable*");
  return(C_TO_XEN_gint(gdk_drawable_get_depth(XEN_TO_C_GdkDrawable_(drawable))));
}
static XEN gxg_gdk_draw_point(XEN drawable, XEN gc, XEN x, XEN y)
{
  #define H_gdk_draw_point "void gdk_draw_point(GdkDrawable* drawable, GdkGC* gc, gint x, gint y)"
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_draw_point", "GdkDrawable*");
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 2, "gdk_draw_point", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 3, "gdk_draw_point", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 4, "gdk_draw_point", "gint");
  gdk_draw_point(XEN_TO_C_GdkDrawable_(drawable), XEN_TO_C_GdkGC_(gc), XEN_TO_C_gint(x), XEN_TO_C_gint(y));
  return(XEN_FALSE);
}
static XEN gxg_gdk_draw_line(XEN drawable, XEN gc, XEN x1, XEN y1, XEN x2, XEN y2)
{
  #define H_gdk_draw_line "void gdk_draw_line(GdkDrawable* drawable, GdkGC* gc, gint x1, gint y1, gint x2, \
gint y2)"
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_draw_line", "GdkDrawable*");
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 2, "gdk_draw_line", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_gint_P(x1), x1, 3, "gdk_draw_line", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y1), y1, 4, "gdk_draw_line", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(x2), x2, 5, "gdk_draw_line", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y2), y2, 6, "gdk_draw_line", "gint");
  gdk_draw_line(XEN_TO_C_GdkDrawable_(drawable), XEN_TO_C_GdkGC_(gc), XEN_TO_C_gint(x1), XEN_TO_C_gint(y1), XEN_TO_C_gint(x2), 
                XEN_TO_C_gint(y2));
  return(XEN_FALSE);
}
static XEN gxg_gdk_draw_rectangle(XEN drawable, XEN gc, XEN filled, XEN x, XEN y, XEN width, XEN height)
{
  #define H_gdk_draw_rectangle "void gdk_draw_rectangle(GdkDrawable* drawable, GdkGC* gc, gboolean filled, \
gint x, gint y, gint width, gint height)"
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_draw_rectangle", "GdkDrawable*");
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 2, "gdk_draw_rectangle", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(filled), filled, 3, "gdk_draw_rectangle", "gboolean");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 4, "gdk_draw_rectangle", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 5, "gdk_draw_rectangle", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 6, "gdk_draw_rectangle", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 7, "gdk_draw_rectangle", "gint");
  gdk_draw_rectangle(XEN_TO_C_GdkDrawable_(drawable), XEN_TO_C_GdkGC_(gc), XEN_TO_C_gboolean(filled), XEN_TO_C_gint(x), XEN_TO_C_gint(y), 
                     XEN_TO_C_gint(width), XEN_TO_C_gint(height));
  return(XEN_FALSE);
}
static XEN gxg_gdk_draw_arc(XEN drawable, XEN gc, XEN filled, XEN x, XEN y, XEN width, XEN height, XEN angle1, XEN angle2)
{
  #define H_gdk_draw_arc "void gdk_draw_arc(GdkDrawable* drawable, GdkGC* gc, gboolean filled, gint x, \
gint y, gint width, gint height, gint angle1, gint angle2)"
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_draw_arc", "GdkDrawable*");
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 2, "gdk_draw_arc", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(filled), filled, 3, "gdk_draw_arc", "gboolean");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 4, "gdk_draw_arc", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 5, "gdk_draw_arc", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 6, "gdk_draw_arc", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 7, "gdk_draw_arc", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(angle1), angle1, 8, "gdk_draw_arc", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(angle2), angle2, 9, "gdk_draw_arc", "gint");
  gdk_draw_arc(XEN_TO_C_GdkDrawable_(drawable), XEN_TO_C_GdkGC_(gc), XEN_TO_C_gboolean(filled), XEN_TO_C_gint(x), XEN_TO_C_gint(y), 
               XEN_TO_C_gint(width), XEN_TO_C_gint(height), XEN_TO_C_gint(angle1), XEN_TO_C_gint(angle2));
  return(XEN_FALSE);
}
static XEN gxg_gdk_draw_polygon(XEN drawable, XEN gc, XEN filled, XEN points, XEN npoints)
{
  #define H_gdk_draw_polygon "void gdk_draw_polygon(GdkDrawable* drawable, GdkGC* gc, gboolean filled, \
GdkPoint* points, gint npoints)"
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_draw_polygon", "GdkDrawable*");
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 2, "gdk_draw_polygon", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(filled), filled, 3, "gdk_draw_polygon", "gboolean");
  XEN_ASSERT_TYPE(XEN_GdkPoint__P(points), points, 4, "gdk_draw_polygon", "GdkPoint*");
  XEN_ASSERT_TYPE(XEN_gint_P(npoints), npoints, 5, "gdk_draw_polygon", "gint");
  gdk_draw_polygon(XEN_TO_C_GdkDrawable_(drawable), XEN_TO_C_GdkGC_(gc), XEN_TO_C_gboolean(filled), XEN_TO_C_GdkPoint_(points), 
                   XEN_TO_C_gint(npoints));
  return(XEN_FALSE);
}
static XEN gxg_gdk_draw_drawable(XEN drawable, XEN gc, XEN src, XEN xsrc, XEN ysrc, XEN xdest, XEN ydest, XEN width, XEN height)
{
  #define H_gdk_draw_drawable "void gdk_draw_drawable(GdkDrawable* drawable, GdkGC* gc, GdkDrawable* src, \
gint xsrc, gint ysrc, gint xdest, gint ydest, gint width, gint height)"
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_draw_drawable", "GdkDrawable*");
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 2, "gdk_draw_drawable", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(src), src, 3, "gdk_draw_drawable", "GdkDrawable*");
  XEN_ASSERT_TYPE(XEN_gint_P(xsrc), xsrc, 4, "gdk_draw_drawable", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(ysrc), ysrc, 5, "gdk_draw_drawable", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(xdest), xdest, 6, "gdk_draw_drawable", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(ydest), ydest, 7, "gdk_draw_drawable", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 8, "gdk_draw_drawable", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 9, "gdk_draw_drawable", "gint");
  gdk_draw_drawable(XEN_TO_C_GdkDrawable_(drawable), XEN_TO_C_GdkGC_(gc), XEN_TO_C_GdkDrawable_(src), XEN_TO_C_gint(xsrc), 
                    XEN_TO_C_gint(ysrc), XEN_TO_C_gint(xdest), XEN_TO_C_gint(ydest), XEN_TO_C_gint(width), XEN_TO_C_gint(height));
  return(XEN_FALSE);
}
static XEN gxg_gdk_draw_image(XEN drawable, XEN gc, XEN image, XEN xsrc, XEN ysrc, XEN xdest, XEN ydest, XEN width, XEN height)
{
  #define H_gdk_draw_image "void gdk_draw_image(GdkDrawable* drawable, GdkGC* gc, GdkImage* image, gint xsrc, \
gint ysrc, gint xdest, gint ydest, gint width, gint height)"
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_draw_image", "GdkDrawable*");
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 2, "gdk_draw_image", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_GdkImage__P(image), image, 3, "gdk_draw_image", "GdkImage*");
  XEN_ASSERT_TYPE(XEN_gint_P(xsrc), xsrc, 4, "gdk_draw_image", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(ysrc), ysrc, 5, "gdk_draw_image", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(xdest), xdest, 6, "gdk_draw_image", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(ydest), ydest, 7, "gdk_draw_image", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 8, "gdk_draw_image", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 9, "gdk_draw_image", "gint");
  gdk_draw_image(XEN_TO_C_GdkDrawable_(drawable), XEN_TO_C_GdkGC_(gc), XEN_TO_C_GdkImage_(image), XEN_TO_C_gint(xsrc), XEN_TO_C_gint(ysrc), 
                 XEN_TO_C_gint(xdest), XEN_TO_C_gint(ydest), XEN_TO_C_gint(width), XEN_TO_C_gint(height));
  return(XEN_FALSE);
}
static XEN gxg_gdk_draw_points(XEN drawable, XEN gc, XEN points, XEN npoints)
{
  #define H_gdk_draw_points "void gdk_draw_points(GdkDrawable* drawable, GdkGC* gc, GdkPoint* points, \
gint npoints)"
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_draw_points", "GdkDrawable*");
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 2, "gdk_draw_points", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_GdkPoint__P(points), points, 3, "gdk_draw_points", "GdkPoint*");
  XEN_ASSERT_TYPE(XEN_gint_P(npoints), npoints, 4, "gdk_draw_points", "gint");
  gdk_draw_points(XEN_TO_C_GdkDrawable_(drawable), XEN_TO_C_GdkGC_(gc), XEN_TO_C_GdkPoint_(points), XEN_TO_C_gint(npoints));
  return(XEN_FALSE);
}
static XEN gxg_gdk_draw_segments(XEN drawable, XEN gc, XEN segs, XEN nsegs)
{
  #define H_gdk_draw_segments "void gdk_draw_segments(GdkDrawable* drawable, GdkGC* gc, GdkSegment* segs, \
gint nsegs)"
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_draw_segments", "GdkDrawable*");
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 2, "gdk_draw_segments", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_GdkSegment__P(segs), segs, 3, "gdk_draw_segments", "GdkSegment*");
  XEN_ASSERT_TYPE(XEN_gint_P(nsegs), nsegs, 4, "gdk_draw_segments", "gint");
  gdk_draw_segments(XEN_TO_C_GdkDrawable_(drawable), XEN_TO_C_GdkGC_(gc), XEN_TO_C_GdkSegment_(segs), XEN_TO_C_gint(nsegs));
  return(XEN_FALSE);
}
static XEN gxg_gdk_draw_lines(XEN drawable, XEN gc, XEN points, XEN npoints)
{
  #define H_gdk_draw_lines "void gdk_draw_lines(GdkDrawable* drawable, GdkGC* gc, GdkPoint* points, gint npoints)"
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_draw_lines", "GdkDrawable*");
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 2, "gdk_draw_lines", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_GdkPoint__P(points), points, 3, "gdk_draw_lines", "GdkPoint*");
  XEN_ASSERT_TYPE(XEN_gint_P(npoints), npoints, 4, "gdk_draw_lines", "gint");
  gdk_draw_lines(XEN_TO_C_GdkDrawable_(drawable), XEN_TO_C_GdkGC_(gc), XEN_TO_C_GdkPoint_(points), XEN_TO_C_gint(npoints));
  return(XEN_FALSE);
}
static XEN gxg_gdk_draw_glyphs(XEN drawable, XEN gc, XEN font, XEN x, XEN y, XEN glyphs)
{
  #define H_gdk_draw_glyphs "void gdk_draw_glyphs(GdkDrawable* drawable, GdkGC* gc, PangoFont* font, \
gint x, gint y, PangoGlyphString* glyphs)"
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_draw_glyphs", "GdkDrawable*");
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 2, "gdk_draw_glyphs", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_PangoFont__P(font), font, 3, "gdk_draw_glyphs", "PangoFont*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 4, "gdk_draw_glyphs", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 5, "gdk_draw_glyphs", "gint");
  XEN_ASSERT_TYPE(XEN_PangoGlyphString__P(glyphs), glyphs, 6, "gdk_draw_glyphs", "PangoGlyphString*");
  gdk_draw_glyphs(XEN_TO_C_GdkDrawable_(drawable), XEN_TO_C_GdkGC_(gc), XEN_TO_C_PangoFont_(font), XEN_TO_C_gint(x), XEN_TO_C_gint(y), 
                  XEN_TO_C_PangoGlyphString_(glyphs));
  return(XEN_FALSE);
}
static XEN gxg_gdk_draw_layout_line(XEN drawable, XEN gc, XEN x, XEN y, XEN line)
{
  #define H_gdk_draw_layout_line "void gdk_draw_layout_line(GdkDrawable* drawable, GdkGC* gc, gint x, \
gint y, PangoLayoutLine* line)"
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_draw_layout_line", "GdkDrawable*");
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 2, "gdk_draw_layout_line", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 3, "gdk_draw_layout_line", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 4, "gdk_draw_layout_line", "gint");
  XEN_ASSERT_TYPE(XEN_PangoLayoutLine__P(line), line, 5, "gdk_draw_layout_line", "PangoLayoutLine*");
  gdk_draw_layout_line(XEN_TO_C_GdkDrawable_(drawable), XEN_TO_C_GdkGC_(gc), XEN_TO_C_gint(x), XEN_TO_C_gint(y), XEN_TO_C_PangoLayoutLine_(line));
  return(XEN_FALSE);
}
static XEN gxg_gdk_draw_layout(XEN drawable, XEN gc, XEN x, XEN y, XEN layout)
{
  #define H_gdk_draw_layout "void gdk_draw_layout(GdkDrawable* drawable, GdkGC* gc, gint x, gint y, PangoLayout* layout)"
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_draw_layout", "GdkDrawable*");
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 2, "gdk_draw_layout", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 3, "gdk_draw_layout", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 4, "gdk_draw_layout", "gint");
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 5, "gdk_draw_layout", "PangoLayout*");
  gdk_draw_layout(XEN_TO_C_GdkDrawable_(drawable), XEN_TO_C_GdkGC_(gc), XEN_TO_C_gint(x), XEN_TO_C_gint(y), XEN_TO_C_PangoLayout_(layout));
  return(XEN_FALSE);
}
static XEN gxg_gdk_draw_layout_line_with_colors(XEN drawable, XEN gc, XEN x, XEN y, XEN line, XEN foreground, XEN background)
{
  #define H_gdk_draw_layout_line_with_colors "void gdk_draw_layout_line_with_colors(GdkDrawable* drawable, \
GdkGC* gc, gint x, gint y, PangoLayoutLine* line, GdkColor* foreground, GdkColor* background)"
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_draw_layout_line_with_colors", "GdkDrawable*");
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 2, "gdk_draw_layout_line_with_colors", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 3, "gdk_draw_layout_line_with_colors", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 4, "gdk_draw_layout_line_with_colors", "gint");
  XEN_ASSERT_TYPE(XEN_PangoLayoutLine__P(line), line, 5, "gdk_draw_layout_line_with_colors", "PangoLayoutLine*");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(foreground) || XEN_FALSE_P(foreground), foreground, 6, "gdk_draw_layout_line_with_colors", "GdkColor*");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(background) || XEN_FALSE_P(background), background, 7, "gdk_draw_layout_line_with_colors", "GdkColor*");
  gdk_draw_layout_line_with_colors(XEN_TO_C_GdkDrawable_(drawable), XEN_TO_C_GdkGC_(gc), XEN_TO_C_gint(x), XEN_TO_C_gint(y), 
                                   XEN_TO_C_PangoLayoutLine_(line), XEN_TO_C_GdkColor_(foreground), XEN_TO_C_GdkColor_(background));
  return(XEN_FALSE);
}
static XEN gxg_gdk_draw_layout_with_colors(XEN drawable, XEN gc, XEN x, XEN y, XEN layout, XEN foreground, XEN background)
{
  #define H_gdk_draw_layout_with_colors "void gdk_draw_layout_with_colors(GdkDrawable* drawable, GdkGC* gc, \
gint x, gint y, PangoLayout* layout, GdkColor* foreground, GdkColor* background)"
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_draw_layout_with_colors", "GdkDrawable*");
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 2, "gdk_draw_layout_with_colors", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 3, "gdk_draw_layout_with_colors", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 4, "gdk_draw_layout_with_colors", "gint");
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 5, "gdk_draw_layout_with_colors", "PangoLayout*");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(foreground) || XEN_FALSE_P(foreground), foreground, 6, "gdk_draw_layout_with_colors", "GdkColor*");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(background) || XEN_FALSE_P(background), background, 7, "gdk_draw_layout_with_colors", "GdkColor*");
  gdk_draw_layout_with_colors(XEN_TO_C_GdkDrawable_(drawable), XEN_TO_C_GdkGC_(gc), XEN_TO_C_gint(x), XEN_TO_C_gint(y), XEN_TO_C_PangoLayout_(layout), 
                              XEN_TO_C_GdkColor_(foreground), XEN_TO_C_GdkColor_(background));
  return(XEN_FALSE);
}
static XEN gxg_gdk_drawable_get_image(XEN drawable, XEN x, XEN y, XEN width, XEN height)
{
  #define H_gdk_drawable_get_image "GdkImage* gdk_drawable_get_image(GdkDrawable* drawable, gint x, gint y, \
gint width, gint height)"
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_drawable_get_image", "GdkDrawable*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 2, "gdk_drawable_get_image", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 3, "gdk_drawable_get_image", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 4, "gdk_drawable_get_image", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 5, "gdk_drawable_get_image", "gint");
  return(C_TO_XEN_GdkImage_(gdk_drawable_get_image(XEN_TO_C_GdkDrawable_(drawable), XEN_TO_C_gint(x), XEN_TO_C_gint(y), XEN_TO_C_gint(width), 
                                                   XEN_TO_C_gint(height))));
}
static XEN gxg_gdk_drawable_get_clip_region(XEN drawable)
{
  #define H_gdk_drawable_get_clip_region "GdkRegion* gdk_drawable_get_clip_region(GdkDrawable* drawable)"
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_drawable_get_clip_region", "GdkDrawable*");
  return(C_TO_XEN_GdkRegion_(gdk_drawable_get_clip_region(XEN_TO_C_GdkDrawable_(drawable))));
}
static XEN gxg_gdk_drawable_get_visible_region(XEN drawable)
{
  #define H_gdk_drawable_get_visible_region "GdkRegion* gdk_drawable_get_visible_region(GdkDrawable* drawable)"
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_drawable_get_visible_region", "GdkDrawable*");
  return(C_TO_XEN_GdkRegion_(gdk_drawable_get_visible_region(XEN_TO_C_GdkDrawable_(drawable))));
}
static XEN gxg_gdk_cursor_type_get_type(void)
{
  #define H_gdk_cursor_type_get_type "GType gdk_cursor_type_get_type( void)"
  return(C_TO_XEN_GType(gdk_cursor_type_get_type()));
}
static XEN gxg_gdk_drag_action_get_type(void)
{
  #define H_gdk_drag_action_get_type "GType gdk_drag_action_get_type( void)"
  return(C_TO_XEN_GType(gdk_drag_action_get_type()));
}
static XEN gxg_gdk_drag_protocol_get_type(void)
{
  #define H_gdk_drag_protocol_get_type "GType gdk_drag_protocol_get_type( void)"
  return(C_TO_XEN_GType(gdk_drag_protocol_get_type()));
}
static XEN gxg_gdk_filter_return_get_type(void)
{
  #define H_gdk_filter_return_get_type "GType gdk_filter_return_get_type( void)"
  return(C_TO_XEN_GType(gdk_filter_return_get_type()));
}
static XEN gxg_gdk_event_type_get_type(void)
{
  #define H_gdk_event_type_get_type "GType gdk_event_type_get_type( void)"
  return(C_TO_XEN_GType(gdk_event_type_get_type()));
}
static XEN gxg_gdk_event_mask_get_type(void)
{
  #define H_gdk_event_mask_get_type "GType gdk_event_mask_get_type( void)"
  return(C_TO_XEN_GType(gdk_event_mask_get_type()));
}
static XEN gxg_gdk_visibility_state_get_type(void)
{
  #define H_gdk_visibility_state_get_type "GType gdk_visibility_state_get_type( void)"
  return(C_TO_XEN_GType(gdk_visibility_state_get_type()));
}
static XEN gxg_gdk_scroll_direction_get_type(void)
{
  #define H_gdk_scroll_direction_get_type "GType gdk_scroll_direction_get_type( void)"
  return(C_TO_XEN_GType(gdk_scroll_direction_get_type()));
}
static XEN gxg_gdk_notify_type_get_type(void)
{
  #define H_gdk_notify_type_get_type "GType gdk_notify_type_get_type( void)"
  return(C_TO_XEN_GType(gdk_notify_type_get_type()));
}
static XEN gxg_gdk_crossing_mode_get_type(void)
{
  #define H_gdk_crossing_mode_get_type "GType gdk_crossing_mode_get_type( void)"
  return(C_TO_XEN_GType(gdk_crossing_mode_get_type()));
}
static XEN gxg_gdk_property_state_get_type(void)
{
  #define H_gdk_property_state_get_type "GType gdk_property_state_get_type( void)"
  return(C_TO_XEN_GType(gdk_property_state_get_type()));
}
static XEN gxg_gdk_window_state_get_type(void)
{
  #define H_gdk_window_state_get_type "GType gdk_window_state_get_type( void)"
  return(C_TO_XEN_GType(gdk_window_state_get_type()));
}
static XEN gxg_gdk_setting_action_get_type(void)
{
  #define H_gdk_setting_action_get_type "GType gdk_setting_action_get_type( void)"
  return(C_TO_XEN_GType(gdk_setting_action_get_type()));
}
static XEN gxg_gdk_font_type_get_type(void)
{
  #define H_gdk_font_type_get_type "GType gdk_font_type_get_type( void)"
  return(C_TO_XEN_GType(gdk_font_type_get_type()));
}
static XEN gxg_gdk_cap_style_get_type(void)
{
  #define H_gdk_cap_style_get_type "GType gdk_cap_style_get_type( void)"
  return(C_TO_XEN_GType(gdk_cap_style_get_type()));
}
static XEN gxg_gdk_fill_get_type(void)
{
  #define H_gdk_fill_get_type "GType gdk_fill_get_type( void)"
  return(C_TO_XEN_GType(gdk_fill_get_type()));
}
static XEN gxg_gdk_function_get_type(void)
{
  #define H_gdk_function_get_type "GType gdk_function_get_type( void)"
  return(C_TO_XEN_GType(gdk_function_get_type()));
}
static XEN gxg_gdk_join_style_get_type(void)
{
  #define H_gdk_join_style_get_type "GType gdk_join_style_get_type( void)"
  return(C_TO_XEN_GType(gdk_join_style_get_type()));
}
static XEN gxg_gdk_line_style_get_type(void)
{
  #define H_gdk_line_style_get_type "GType gdk_line_style_get_type( void)"
  return(C_TO_XEN_GType(gdk_line_style_get_type()));
}
static XEN gxg_gdk_subwindow_mode_get_type(void)
{
  #define H_gdk_subwindow_mode_get_type "GType gdk_subwindow_mode_get_type( void)"
  return(C_TO_XEN_GType(gdk_subwindow_mode_get_type()));
}
static XEN gxg_gdk_gc_values_mask_get_type(void)
{
  #define H_gdk_gc_values_mask_get_type "GType gdk_gc_values_mask_get_type( void)"
  return(C_TO_XEN_GType(gdk_gc_values_mask_get_type()));
}
static XEN gxg_gdk_image_type_get_type(void)
{
  #define H_gdk_image_type_get_type "GType gdk_image_type_get_type( void)"
  return(C_TO_XEN_GType(gdk_image_type_get_type()));
}
static XEN gxg_gdk_extension_mode_get_type(void)
{
  #define H_gdk_extension_mode_get_type "GType gdk_extension_mode_get_type( void)"
  return(C_TO_XEN_GType(gdk_extension_mode_get_type()));
}
static XEN gxg_gdk_input_source_get_type(void)
{
  #define H_gdk_input_source_get_type "GType gdk_input_source_get_type( void)"
  return(C_TO_XEN_GType(gdk_input_source_get_type()));
}
static XEN gxg_gdk_input_mode_get_type(void)
{
  #define H_gdk_input_mode_get_type "GType gdk_input_mode_get_type( void)"
  return(C_TO_XEN_GType(gdk_input_mode_get_type()));
}
static XEN gxg_gdk_axis_use_get_type(void)
{
  #define H_gdk_axis_use_get_type "GType gdk_axis_use_get_type( void)"
  return(C_TO_XEN_GType(gdk_axis_use_get_type()));
}
static XEN gxg_gdk_prop_mode_get_type(void)
{
  #define H_gdk_prop_mode_get_type "GType gdk_prop_mode_get_type( void)"
  return(C_TO_XEN_GType(gdk_prop_mode_get_type()));
}
static XEN gxg_gdk_fill_rule_get_type(void)
{
  #define H_gdk_fill_rule_get_type "GType gdk_fill_rule_get_type( void)"
  return(C_TO_XEN_GType(gdk_fill_rule_get_type()));
}
static XEN gxg_gdk_overlap_type_get_type(void)
{
  #define H_gdk_overlap_type_get_type "GType gdk_overlap_type_get_type( void)"
  return(C_TO_XEN_GType(gdk_overlap_type_get_type()));
}
static XEN gxg_gdk_rgb_dither_get_type(void)
{
  #define H_gdk_rgb_dither_get_type "GType gdk_rgb_dither_get_type( void)"
  return(C_TO_XEN_GType(gdk_rgb_dither_get_type()));
}
static XEN gxg_gdk_byte_order_get_type(void)
{
  #define H_gdk_byte_order_get_type "GType gdk_byte_order_get_type( void)"
  return(C_TO_XEN_GType(gdk_byte_order_get_type()));
}
static XEN gxg_gdk_modifier_type_get_type(void)
{
  #define H_gdk_modifier_type_get_type "GType gdk_modifier_type_get_type( void)"
  return(C_TO_XEN_GType(gdk_modifier_type_get_type()));
}
static XEN gxg_gdk_input_condition_get_type(void)
{
  #define H_gdk_input_condition_get_type "GType gdk_input_condition_get_type( void)"
  return(C_TO_XEN_GType(gdk_input_condition_get_type()));
}
static XEN gxg_gdk_status_get_type(void)
{
  #define H_gdk_status_get_type "GType gdk_status_get_type( void)"
  return(C_TO_XEN_GType(gdk_status_get_type()));
}
static XEN gxg_gdk_grab_status_get_type(void)
{
  #define H_gdk_grab_status_get_type "GType gdk_grab_status_get_type( void)"
  return(C_TO_XEN_GType(gdk_grab_status_get_type()));
}
static XEN gxg_gdk_visual_type_get_type(void)
{
  #define H_gdk_visual_type_get_type "GType gdk_visual_type_get_type( void)"
  return(C_TO_XEN_GType(gdk_visual_type_get_type()));
}
static XEN gxg_gdk_window_class_get_type(void)
{
  #define H_gdk_window_class_get_type "GType gdk_window_class_get_type( void)"
  return(C_TO_XEN_GType(gdk_window_class_get_type()));
}
static XEN gxg_gdk_window_type_get_type(void)
{
  #define H_gdk_window_type_get_type "GType gdk_window_type_get_type( void)"
  return(C_TO_XEN_GType(gdk_window_type_get_type()));
}
static XEN gxg_gdk_window_attributes_type_get_type(void)
{
  #define H_gdk_window_attributes_type_get_type "GType gdk_window_attributes_type_get_type( void)"
  return(C_TO_XEN_GType(gdk_window_attributes_type_get_type()));
}
static XEN gxg_gdk_window_hints_get_type(void)
{
  #define H_gdk_window_hints_get_type "GType gdk_window_hints_get_type( void)"
  return(C_TO_XEN_GType(gdk_window_hints_get_type()));
}
static XEN gxg_gdk_window_type_hint_get_type(void)
{
  #define H_gdk_window_type_hint_get_type "GType gdk_window_type_hint_get_type( void)"
  return(C_TO_XEN_GType(gdk_window_type_hint_get_type()));
}
static XEN gxg_gdk_wm_decoration_get_type(void)
{
  #define H_gdk_wm_decoration_get_type "GType gdk_wm_decoration_get_type( void)"
  return(C_TO_XEN_GType(gdk_wm_decoration_get_type()));
}
static XEN gxg_gdk_wm_function_get_type(void)
{
  #define H_gdk_wm_function_get_type "GType gdk_wm_function_get_type( void)"
  return(C_TO_XEN_GType(gdk_wm_function_get_type()));
}
static XEN gxg_gdk_gravity_get_type(void)
{
  #define H_gdk_gravity_get_type "GType gdk_gravity_get_type( void)"
  return(C_TO_XEN_GType(gdk_gravity_get_type()));
}
static XEN gxg_gdk_window_edge_get_type(void)
{
  #define H_gdk_window_edge_get_type "GType gdk_window_edge_get_type( void)"
  return(C_TO_XEN_GType(gdk_window_edge_get_type()));
}
static XEN gxg_gdk_event_get_type(void)
{
  #define H_gdk_event_get_type "GType gdk_event_get_type( void)"
  return(C_TO_XEN_GType(gdk_event_get_type()));
}
static XEN gxg_gdk_events_pending(void)
{
  #define H_gdk_events_pending "gboolean gdk_events_pending( void)"
  return(C_TO_XEN_gboolean(gdk_events_pending()));
}
static XEN gxg_gdk_event_get(void)
{
  #define H_gdk_event_get "GdkEvent* gdk_event_get( void)"
  return(C_TO_XEN_GdkEvent_(gdk_event_get()));
}
static XEN gxg_gdk_event_peek(void)
{
  #define H_gdk_event_peek "GdkEvent* gdk_event_peek( void)"
  return(C_TO_XEN_GdkEvent_(gdk_event_peek()));
}
static XEN gxg_gdk_event_get_graphics_expose(XEN window)
{
  #define H_gdk_event_get_graphics_expose "GdkEvent* gdk_event_get_graphics_expose(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_event_get_graphics_expose", "GdkWindow*");
  return(C_TO_XEN_GdkEvent_(gdk_event_get_graphics_expose(XEN_TO_C_GdkWindow_(window))));
}
static XEN gxg_gdk_event_put(XEN event)
{
  #define H_gdk_event_put "void gdk_event_put(GdkEvent* event)"
  XEN_ASSERT_TYPE(XEN_GdkEvent__P(event), event, 1, "gdk_event_put", "GdkEvent*");
  gdk_event_put(XEN_TO_C_GdkEvent_(event));
  return(XEN_FALSE);
}
static XEN gxg_gdk_event_copy(XEN event)
{
  #define H_gdk_event_copy "GdkEvent* gdk_event_copy(GdkEvent* event)"
  XEN_ASSERT_TYPE(XEN_GdkEvent__P(event), event, 1, "gdk_event_copy", "GdkEvent*");
  return(C_TO_XEN_GdkEvent_(gdk_event_copy(XEN_TO_C_GdkEvent_(event))));
}
static XEN gxg_gdk_event_free(XEN event)
{
  #define H_gdk_event_free "void gdk_event_free(GdkEvent* event)"
  XEN_ASSERT_TYPE(XEN_GdkEvent__P(event), event, 1, "gdk_event_free", "GdkEvent*");
  gdk_event_free(XEN_TO_C_GdkEvent_(event));
  return(XEN_FALSE);
}
static XEN gxg_gdk_event_get_time(XEN event)
{
  #define H_gdk_event_get_time "guint32 gdk_event_get_time(GdkEvent* event)"
  XEN_ASSERT_TYPE(XEN_GdkEvent__P(event) || XEN_FALSE_P(event), event, 1, "gdk_event_get_time", "GdkEvent*");
  return(C_TO_XEN_guint32(gdk_event_get_time(XEN_TO_C_GdkEvent_(event))));
}
static XEN gxg_gdk_event_get_state(XEN event, XEN state)
{
  #define H_gdk_event_get_state "gboolean gdk_event_get_state(GdkEvent* event, GdkModifierType* [state])"
  GdkModifierType ref_state;
  XEN_ASSERT_TYPE(XEN_GdkEvent__P(event), event, 1, "gdk_event_get_state", "GdkEvent*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gdk_event_get_state(XEN_TO_C_GdkEvent_(event), &ref_state));
    return(XEN_LIST_2(result, C_TO_XEN_GdkModifierType(ref_state)));
   }
}
static XEN gxg_gdk_event_get_coords(XEN event, XEN x_win, XEN y_win)
{
  #define H_gdk_event_get_coords "gboolean gdk_event_get_coords(GdkEvent* event, gdouble* [x_win], gdouble* [y_win])"
  gdouble ref_x_win;
  gdouble ref_y_win;
  XEN_ASSERT_TYPE(XEN_GdkEvent__P(event), event, 1, "gdk_event_get_coords", "GdkEvent*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gdk_event_get_coords(XEN_TO_C_GdkEvent_(event), &ref_x_win, &ref_y_win));
    return(XEN_LIST_3(result, C_TO_XEN_gdouble(ref_x_win), C_TO_XEN_gdouble(ref_y_win)));
   }
}
static XEN gxg_gdk_event_get_root_coords(XEN event, XEN x_root, XEN y_root)
{
  #define H_gdk_event_get_root_coords "gboolean gdk_event_get_root_coords(GdkEvent* event, gdouble* [x_root], \
gdouble* [y_root])"
  gdouble ref_x_root;
  gdouble ref_y_root;
  XEN_ASSERT_TYPE(XEN_GdkEvent__P(event), event, 1, "gdk_event_get_root_coords", "GdkEvent*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gdk_event_get_root_coords(XEN_TO_C_GdkEvent_(event), &ref_x_root, &ref_y_root));
    return(XEN_LIST_3(result, C_TO_XEN_gdouble(ref_x_root), C_TO_XEN_gdouble(ref_y_root)));
   }
}
static XEN gxg_gdk_event_get_axis(XEN event, XEN axis_use, XEN value)
{
  #define H_gdk_event_get_axis "gboolean gdk_event_get_axis(GdkEvent* event, GdkAxisUse axis_use, gdouble* [value])"
  gdouble ref_value;
  XEN_ASSERT_TYPE(XEN_GdkEvent__P(event), event, 1, "gdk_event_get_axis", "GdkEvent*");
  XEN_ASSERT_TYPE(XEN_GdkAxisUse_P(axis_use), axis_use, 2, "gdk_event_get_axis", "GdkAxisUse");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gdk_event_get_axis(XEN_TO_C_GdkEvent_(event), XEN_TO_C_GdkAxisUse(axis_use), &ref_value));
    return(XEN_LIST_2(result, C_TO_XEN_gdouble(ref_value)));
   }
}
static XEN gxg_gdk_event_handler_set(XEN func, XEN func_data, XEN notify)
{
  #define H_gdk_event_handler_set "void gdk_event_handler_set(GdkEventFunc func, lambda_data func_data, \
GtkDestroyNotify notify)"
  XEN_ASSERT_TYPE(XEN_GdkEventFunc_P(func), func, 1, "gdk_event_handler_set", "GdkEventFunc");
  XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 2, "gdk_event_handler_set", "lambda_data");
  XEN_ASSERT_TYPE(XEN_GtkDestroyNotify_P(notify), notify, 3, "gdk_event_handler_set", "GtkDestroyNotify");
  {
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 3, notify);
    gdk_event_handler_set(XEN_TO_C_GdkEventFunc(func), XEN_TO_C_lambda_data(func_data), XEN_TO_C_GtkDestroyNotify(notify));
    return(XEN_FALSE);
   }
}
static XEN gxg_gdk_set_show_events(XEN show_events)
{
  #define H_gdk_set_show_events "void gdk_set_show_events(gboolean show_events)"
  XEN_ASSERT_TYPE(XEN_gboolean_P(show_events), show_events, 1, "gdk_set_show_events", "gboolean");
  gdk_set_show_events(XEN_TO_C_gboolean(show_events));
  return(XEN_FALSE);
}
static XEN gxg_gdk_get_show_events(void)
{
  #define H_gdk_get_show_events "gboolean gdk_get_show_events( void)"
  return(C_TO_XEN_gboolean(gdk_get_show_events()));
}
static XEN gxg_gdk_add_client_message_filter(XEN message_type, XEN func, XEN func_data)
{
  #define H_gdk_add_client_message_filter "void gdk_add_client_message_filter(GdkAtom message_type, GdkFilterFunc func, \
lambda_data func_data)"
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(message_type), message_type, 1, "gdk_add_client_message_filter", "GdkAtom");
  XEN_ASSERT_TYPE(XEN_GdkFilterFunc_P(func), func, 2, "gdk_add_client_message_filter", "GdkFilterFunc");
  if (XEN_NOT_BOUND_P(func_data)) func_data = XEN_FALSE; 
  else XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 3, "gdk_add_client_message_filter", "lambda_data");
  {
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    xm_protect(gxg_ptr);
    gdk_add_client_message_filter(XEN_TO_C_GdkAtom(message_type), XEN_TO_C_GdkFilterFunc(func), XEN_TO_C_lambda_data(func_data));
    return(XEN_FALSE);
   }
}
static XEN gxg_gdk_gc_get_type(void)
{
  #define H_gdk_gc_get_type "GType gdk_gc_get_type( void)"
  return(C_TO_XEN_GType(gdk_gc_get_type()));
}
static XEN gxg_gdk_gc_new(XEN drawable)
{
  #define H_gdk_gc_new "GdkGC* gdk_gc_new(GdkDrawable* drawable)"
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_gc_new", "GdkDrawable*");
  return(C_TO_XEN_GdkGC_(gdk_gc_new(XEN_TO_C_GdkDrawable_(drawable))));
}
static XEN gxg_gdk_gc_new_with_values(XEN drawable, XEN values, XEN values_mask)
{
  #define H_gdk_gc_new_with_values "GdkGC* gdk_gc_new_with_values(GdkDrawable* drawable, GdkGCValues* values, \
GdkGCValuesMask values_mask)"
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_gc_new_with_values", "GdkDrawable*");
  XEN_ASSERT_TYPE(XEN_GdkGCValues__P(values), values, 2, "gdk_gc_new_with_values", "GdkGCValues*");
  XEN_ASSERT_TYPE(XEN_GdkGCValuesMask_P(values_mask), values_mask, 3, "gdk_gc_new_with_values", "GdkGCValuesMask");
  return(C_TO_XEN_GdkGC_(gdk_gc_new_with_values(XEN_TO_C_GdkDrawable_(drawable), XEN_TO_C_GdkGCValues_(values), XEN_TO_C_GdkGCValuesMask(values_mask))));
}
static XEN gxg_gdk_gc_get_values(XEN gc, XEN values)
{
  #define H_gdk_gc_get_values "void gdk_gc_get_values(GdkGC* gc, GdkGCValues* values)"
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 1, "gdk_gc_get_values", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_GdkGCValues__P(values), values, 2, "gdk_gc_get_values", "GdkGCValues*");
  gdk_gc_get_values(XEN_TO_C_GdkGC_(gc), XEN_TO_C_GdkGCValues_(values));
  return(XEN_FALSE);
}
static XEN gxg_gdk_gc_set_values(XEN gc, XEN values, XEN values_mask)
{
  #define H_gdk_gc_set_values "void gdk_gc_set_values(GdkGC* gc, GdkGCValues* values, GdkGCValuesMask values_mask)"
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 1, "gdk_gc_set_values", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_GdkGCValues__P(values), values, 2, "gdk_gc_set_values", "GdkGCValues*");
  XEN_ASSERT_TYPE(XEN_GdkGCValuesMask_P(values_mask), values_mask, 3, "gdk_gc_set_values", "GdkGCValuesMask");
  gdk_gc_set_values(XEN_TO_C_GdkGC_(gc), XEN_TO_C_GdkGCValues_(values), XEN_TO_C_GdkGCValuesMask(values_mask));
  return(XEN_FALSE);
}
static XEN gxg_gdk_gc_set_foreground(XEN gc, XEN color)
{
  #define H_gdk_gc_set_foreground "void gdk_gc_set_foreground(GdkGC* gc, GdkColor* color)"
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 1, "gdk_gc_set_foreground", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(color), color, 2, "gdk_gc_set_foreground", "GdkColor*");
  gdk_gc_set_foreground(XEN_TO_C_GdkGC_(gc), XEN_TO_C_GdkColor_(color));
  return(XEN_FALSE);
}
static XEN gxg_gdk_gc_set_background(XEN gc, XEN color)
{
  #define H_gdk_gc_set_background "void gdk_gc_set_background(GdkGC* gc, GdkColor* color)"
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 1, "gdk_gc_set_background", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(color), color, 2, "gdk_gc_set_background", "GdkColor*");
  gdk_gc_set_background(XEN_TO_C_GdkGC_(gc), XEN_TO_C_GdkColor_(color));
  return(XEN_FALSE);
}
static XEN gxg_gdk_gc_set_function(XEN gc, XEN function)
{
  #define H_gdk_gc_set_function "void gdk_gc_set_function(GdkGC* gc, GdkFunction function)"
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 1, "gdk_gc_set_function", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_GdkFunction_P(function), function, 2, "gdk_gc_set_function", "GdkFunction");
  gdk_gc_set_function(XEN_TO_C_GdkGC_(gc), XEN_TO_C_GdkFunction(function));
  return(XEN_FALSE);
}
static XEN gxg_gdk_gc_set_fill(XEN gc, XEN fill)
{
  #define H_gdk_gc_set_fill "void gdk_gc_set_fill(GdkGC* gc, GdkFill fill)"
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 1, "gdk_gc_set_fill", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_GdkFill_P(fill), fill, 2, "gdk_gc_set_fill", "GdkFill");
  gdk_gc_set_fill(XEN_TO_C_GdkGC_(gc), XEN_TO_C_GdkFill(fill));
  return(XEN_FALSE);
}
static XEN gxg_gdk_gc_set_tile(XEN gc, XEN tile)
{
  #define H_gdk_gc_set_tile "void gdk_gc_set_tile(GdkGC* gc, GdkPixmap* tile)"
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 1, "gdk_gc_set_tile", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_GdkPixmap__P(tile), tile, 2, "gdk_gc_set_tile", "GdkPixmap*");
  gdk_gc_set_tile(XEN_TO_C_GdkGC_(gc), XEN_TO_C_GdkPixmap_(tile));
  return(XEN_FALSE);
}
static XEN gxg_gdk_gc_set_stipple(XEN gc, XEN stipple)
{
  #define H_gdk_gc_set_stipple "void gdk_gc_set_stipple(GdkGC* gc, GdkPixmap* stipple)"
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 1, "gdk_gc_set_stipple", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_GdkPixmap__P(stipple), stipple, 2, "gdk_gc_set_stipple", "GdkPixmap*");
  gdk_gc_set_stipple(XEN_TO_C_GdkGC_(gc), XEN_TO_C_GdkPixmap_(stipple));
  return(XEN_FALSE);
}
static XEN gxg_gdk_gc_set_ts_origin(XEN gc, XEN x, XEN y)
{
  #define H_gdk_gc_set_ts_origin "void gdk_gc_set_ts_origin(GdkGC* gc, gint x, gint y)"
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 1, "gdk_gc_set_ts_origin", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 2, "gdk_gc_set_ts_origin", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 3, "gdk_gc_set_ts_origin", "gint");
  gdk_gc_set_ts_origin(XEN_TO_C_GdkGC_(gc), XEN_TO_C_gint(x), XEN_TO_C_gint(y));
  return(XEN_FALSE);
}
static XEN gxg_gdk_gc_set_clip_origin(XEN gc, XEN x, XEN y)
{
  #define H_gdk_gc_set_clip_origin "void gdk_gc_set_clip_origin(GdkGC* gc, gint x, gint y)"
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 1, "gdk_gc_set_clip_origin", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 2, "gdk_gc_set_clip_origin", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 3, "gdk_gc_set_clip_origin", "gint");
  gdk_gc_set_clip_origin(XEN_TO_C_GdkGC_(gc), XEN_TO_C_gint(x), XEN_TO_C_gint(y));
  return(XEN_FALSE);
}
static XEN gxg_gdk_gc_set_clip_mask(XEN gc, XEN mask)
{
  #define H_gdk_gc_set_clip_mask "void gdk_gc_set_clip_mask(GdkGC* gc, GdkBitmap* mask)"
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 1, "gdk_gc_set_clip_mask", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_GdkBitmap__P(mask), mask, 2, "gdk_gc_set_clip_mask", "GdkBitmap*");
  gdk_gc_set_clip_mask(XEN_TO_C_GdkGC_(gc), XEN_TO_C_GdkBitmap_(mask));
  return(XEN_FALSE);
}
static XEN gxg_gdk_gc_set_clip_rectangle(XEN gc, XEN rectangle)
{
  #define H_gdk_gc_set_clip_rectangle "void gdk_gc_set_clip_rectangle(GdkGC* gc, GdkRectangle* rectangle)"
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 1, "gdk_gc_set_clip_rectangle", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(rectangle), rectangle, 2, "gdk_gc_set_clip_rectangle", "GdkRectangle*");
  gdk_gc_set_clip_rectangle(XEN_TO_C_GdkGC_(gc), XEN_TO_C_GdkRectangle_(rectangle));
  return(XEN_FALSE);
}
static XEN gxg_gdk_gc_set_clip_region(XEN gc, XEN region)
{
  #define H_gdk_gc_set_clip_region "void gdk_gc_set_clip_region(GdkGC* gc, GdkRegion* region)"
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 1, "gdk_gc_set_clip_region", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_GdkRegion__P(region), region, 2, "gdk_gc_set_clip_region", "GdkRegion*");
  gdk_gc_set_clip_region(XEN_TO_C_GdkGC_(gc), XEN_TO_C_GdkRegion_(region));
  return(XEN_FALSE);
}
static XEN gxg_gdk_gc_set_subwindow(XEN gc, XEN mode)
{
  #define H_gdk_gc_set_subwindow "void gdk_gc_set_subwindow(GdkGC* gc, GdkSubwindowMode mode)"
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 1, "gdk_gc_set_subwindow", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_GdkSubwindowMode_P(mode), mode, 2, "gdk_gc_set_subwindow", "GdkSubwindowMode");
  gdk_gc_set_subwindow(XEN_TO_C_GdkGC_(gc), XEN_TO_C_GdkSubwindowMode(mode));
  return(XEN_FALSE);
}
static XEN gxg_gdk_gc_set_exposures(XEN gc, XEN exposures)
{
  #define H_gdk_gc_set_exposures "void gdk_gc_set_exposures(GdkGC* gc, gboolean exposures)"
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 1, "gdk_gc_set_exposures", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(exposures), exposures, 2, "gdk_gc_set_exposures", "gboolean");
  gdk_gc_set_exposures(XEN_TO_C_GdkGC_(gc), XEN_TO_C_gboolean(exposures));
  return(XEN_FALSE);
}
static XEN gxg_gdk_gc_set_line_attributes(XEN gc, XEN line_width, XEN line_style, XEN cap_style, XEN join_style)
{
  #define H_gdk_gc_set_line_attributes "void gdk_gc_set_line_attributes(GdkGC* gc, gint line_width, GdkLineStyle line_style, \
GdkCapStyle cap_style, GdkJoinStyle join_style)"
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 1, "gdk_gc_set_line_attributes", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_gint_P(line_width), line_width, 2, "gdk_gc_set_line_attributes", "gint");
  XEN_ASSERT_TYPE(XEN_GdkLineStyle_P(line_style), line_style, 3, "gdk_gc_set_line_attributes", "GdkLineStyle");
  XEN_ASSERT_TYPE(XEN_GdkCapStyle_P(cap_style), cap_style, 4, "gdk_gc_set_line_attributes", "GdkCapStyle");
  XEN_ASSERT_TYPE(XEN_GdkJoinStyle_P(join_style), join_style, 5, "gdk_gc_set_line_attributes", "GdkJoinStyle");
  gdk_gc_set_line_attributes(XEN_TO_C_GdkGC_(gc), XEN_TO_C_gint(line_width), XEN_TO_C_GdkLineStyle(line_style), XEN_TO_C_GdkCapStyle(cap_style), 
                             XEN_TO_C_GdkJoinStyle(join_style));
  return(XEN_FALSE);
}
static XEN gxg_gdk_gc_set_dashes(XEN gc, XEN dash_offset, XEN dash_list, XEN n)
{
  #define H_gdk_gc_set_dashes "void gdk_gc_set_dashes(GdkGC* gc, gint dash_offset, gint8* dash_list, \
gint n)"
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 1, "gdk_gc_set_dashes", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_gint_P(dash_offset), dash_offset, 2, "gdk_gc_set_dashes", "gint");
  XEN_ASSERT_TYPE(XEN_gint8__P(dash_list), dash_list, 3, "gdk_gc_set_dashes", "gint8*");
  XEN_ASSERT_TYPE(XEN_gint_P(n), n, 4, "gdk_gc_set_dashes", "gint");
  gdk_gc_set_dashes(XEN_TO_C_GdkGC_(gc), XEN_TO_C_gint(dash_offset), XEN_TO_C_gint8_(dash_list), XEN_TO_C_gint(n));
  return(XEN_FALSE);
}
static XEN gxg_gdk_gc_offset(XEN gc, XEN x_offset, XEN y_offset)
{
  #define H_gdk_gc_offset "void gdk_gc_offset(GdkGC* gc, gint x_offset, gint y_offset)"
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 1, "gdk_gc_offset", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_gint_P(x_offset), x_offset, 2, "gdk_gc_offset", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y_offset), y_offset, 3, "gdk_gc_offset", "gint");
  gdk_gc_offset(XEN_TO_C_GdkGC_(gc), XEN_TO_C_gint(x_offset), XEN_TO_C_gint(y_offset));
  return(XEN_FALSE);
}
static XEN gxg_gdk_gc_copy(XEN dst_gc, XEN src_gc)
{
  #define H_gdk_gc_copy "void gdk_gc_copy(GdkGC* dst_gc, GdkGC* src_gc)"
  XEN_ASSERT_TYPE(XEN_GdkGC__P(dst_gc), dst_gc, 1, "gdk_gc_copy", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_GdkGC__P(src_gc), src_gc, 2, "gdk_gc_copy", "GdkGC*");
  gdk_gc_copy(XEN_TO_C_GdkGC_(dst_gc), XEN_TO_C_GdkGC_(src_gc));
  return(XEN_FALSE);
}
static XEN gxg_gdk_gc_set_colormap(XEN gc, XEN colormap)
{
  #define H_gdk_gc_set_colormap "void gdk_gc_set_colormap(GdkGC* gc, GdkColormap* colormap)"
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 1, "gdk_gc_set_colormap", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_GdkColormap__P(colormap), colormap, 2, "gdk_gc_set_colormap", "GdkColormap*");
  gdk_gc_set_colormap(XEN_TO_C_GdkGC_(gc), XEN_TO_C_GdkColormap_(colormap));
  return(XEN_FALSE);
}
static XEN gxg_gdk_gc_get_colormap(XEN gc)
{
  #define H_gdk_gc_get_colormap "GdkColormap* gdk_gc_get_colormap(GdkGC* gc)"
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 1, "gdk_gc_get_colormap", "GdkGC*");
  return(C_TO_XEN_GdkColormap_(gdk_gc_get_colormap(XEN_TO_C_GdkGC_(gc))));
}
static XEN gxg_gdk_gc_set_rgb_fg_color(XEN gc, XEN color)
{
  #define H_gdk_gc_set_rgb_fg_color "void gdk_gc_set_rgb_fg_color(GdkGC* gc, GdkColor* color)"
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 1, "gdk_gc_set_rgb_fg_color", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(color), color, 2, "gdk_gc_set_rgb_fg_color", "GdkColor*");
  gdk_gc_set_rgb_fg_color(XEN_TO_C_GdkGC_(gc), XEN_TO_C_GdkColor_(color));
  return(XEN_FALSE);
}
static XEN gxg_gdk_gc_set_rgb_bg_color(XEN gc, XEN color)
{
  #define H_gdk_gc_set_rgb_bg_color "void gdk_gc_set_rgb_bg_color(GdkGC* gc, GdkColor* color)"
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 1, "gdk_gc_set_rgb_bg_color", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(color), color, 2, "gdk_gc_set_rgb_bg_color", "GdkColor*");
  gdk_gc_set_rgb_bg_color(XEN_TO_C_GdkGC_(gc), XEN_TO_C_GdkColor_(color));
  return(XEN_FALSE);
}
static XEN gxg_gdk_init(XEN argc, XEN argv)
{
  #define H_gdk_init "void gdk_init(gint* {argc}, gchar*** |argv|)"
  gint ref_argc;
  gchar** ref_argv = NULL;
  ref_argc = XEN_TO_C_gint(argc);
  ref_argv = (gchar**)calloc(ref_argc, sizeof(gchar*));
  {
   int i;
   XEN lst;
   lst = XEN_COPY_ARG(argv);
   for (i = 0; i < ref_argc; i++, lst = XEN_CDR(lst)) ref_argv[i] = XEN_TO_C_gchar_(XEN_CAR(lst));
  }
  gdk_init(&ref_argc, &ref_argv);
  return(XEN_LIST_2(C_TO_XEN_gint(ref_argc), C_TO_XEN_gchar__(ref_argv)));
}
static XEN gxg_gdk_init_check(XEN argc, XEN argv)
{
  #define H_gdk_init_check "gboolean gdk_init_check(gint* {argc}, gchar*** |argv|)"
  gint ref_argc;
  gchar** ref_argv = NULL;
  ref_argc = XEN_TO_C_gint(argc);
  ref_argv = (gchar**)calloc(ref_argc, sizeof(gchar*));
  {
   int i;
   XEN lst;
   lst = XEN_COPY_ARG(argv);
   for (i = 0; i < ref_argc; i++, lst = XEN_CDR(lst)) ref_argv[i] = XEN_TO_C_gchar_(XEN_CAR(lst));
  }
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gdk_init_check(&ref_argc, &ref_argv));
    return(XEN_LIST_3(result, C_TO_XEN_gint(ref_argc), C_TO_XEN_gchar__(ref_argv)));
   }
}
static XEN gxg_gdk_set_locale(void)
{
  #define H_gdk_set_locale "gchar* gdk_set_locale( void)"
  return(C_TO_XEN_gchar_(gdk_set_locale()));
}
static XEN gxg_gdk_get_program_class(void)
{
  #define H_gdk_get_program_class "char* gdk_get_program_class( void)"
  return(C_TO_XEN_char_(gdk_get_program_class()));
}
static XEN gxg_gdk_set_program_class(XEN program_class)
{
  #define H_gdk_set_program_class "void gdk_set_program_class(char* program_class)"
  XEN_ASSERT_TYPE(XEN_char__P(program_class), program_class, 1, "gdk_set_program_class", "char*");
  gdk_set_program_class(XEN_TO_C_char_(program_class));
  return(XEN_FALSE);
}
static XEN gxg_gdk_error_trap_push(void)
{
  #define H_gdk_error_trap_push "void gdk_error_trap_push( void)"
  gdk_error_trap_push();
  return(XEN_FALSE);
}
static XEN gxg_gdk_error_trap_pop(void)
{
  #define H_gdk_error_trap_pop "gint gdk_error_trap_pop( void)"
  return(C_TO_XEN_gint(gdk_error_trap_pop()));
}
static XEN gxg_gdk_get_display(void)
{
  #define H_gdk_get_display "gchar* gdk_get_display( void)"
  return(C_TO_XEN_gchar_(gdk_get_display()));
}
static XEN gxg_gdk_pointer_grab(XEN window, XEN owner_events, XEN event_mask, XEN confine_to, XEN cursor, XEN time)
{
  #define H_gdk_pointer_grab "GdkGrabStatus gdk_pointer_grab(GdkWindow* window, gboolean owner_events, \
GdkEventMask event_mask, GdkWindow* confine_to, GdkCursor* cursor, guint32 time)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_pointer_grab", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(owner_events), owner_events, 2, "gdk_pointer_grab", "gboolean");
  XEN_ASSERT_TYPE(XEN_GdkEventMask_P(event_mask), event_mask, 3, "gdk_pointer_grab", "GdkEventMask");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(confine_to), confine_to, 4, "gdk_pointer_grab", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkCursor__P(cursor), cursor, 5, "gdk_pointer_grab", "GdkCursor*");
  XEN_ASSERT_TYPE(XEN_guint32_P(time), time, 6, "gdk_pointer_grab", "guint32");
  return(C_TO_XEN_GdkGrabStatus(gdk_pointer_grab(XEN_TO_C_GdkWindow_(window), XEN_TO_C_gboolean(owner_events), XEN_TO_C_GdkEventMask(event_mask), 
                                                 XEN_TO_C_GdkWindow_(confine_to), XEN_TO_C_GdkCursor_(cursor), XEN_TO_C_guint32(time))));
}
static XEN gxg_gdk_pointer_ungrab(XEN time)
{
  #define H_gdk_pointer_ungrab "void gdk_pointer_ungrab(guint32 time)"
  XEN_ASSERT_TYPE(XEN_guint32_P(time), time, 1, "gdk_pointer_ungrab", "guint32");
  gdk_pointer_ungrab(XEN_TO_C_guint32(time));
  return(XEN_FALSE);
}
static XEN gxg_gdk_keyboard_grab(XEN window, XEN owner_events, XEN time)
{
  #define H_gdk_keyboard_grab "GdkGrabStatus gdk_keyboard_grab(GdkWindow* window, gboolean owner_events, \
guint32 time)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_keyboard_grab", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(owner_events), owner_events, 2, "gdk_keyboard_grab", "gboolean");
  XEN_ASSERT_TYPE(XEN_guint32_P(time), time, 3, "gdk_keyboard_grab", "guint32");
  return(C_TO_XEN_GdkGrabStatus(gdk_keyboard_grab(XEN_TO_C_GdkWindow_(window), XEN_TO_C_gboolean(owner_events), XEN_TO_C_guint32(time))));
}
static XEN gxg_gdk_keyboard_ungrab(XEN time)
{
  #define H_gdk_keyboard_ungrab "void gdk_keyboard_ungrab(guint32 time)"
  XEN_ASSERT_TYPE(XEN_guint32_P(time), time, 1, "gdk_keyboard_ungrab", "guint32");
  gdk_keyboard_ungrab(XEN_TO_C_guint32(time));
  return(XEN_FALSE);
}
static XEN gxg_gdk_pointer_is_grabbed(void)
{
  #define H_gdk_pointer_is_grabbed "gboolean gdk_pointer_is_grabbed( void)"
  return(C_TO_XEN_gboolean(gdk_pointer_is_grabbed()));
}
static XEN gxg_gdk_screen_width(void)
{
  #define H_gdk_screen_width "gint gdk_screen_width( void)"
  return(C_TO_XEN_gint(gdk_screen_width()));
}
static XEN gxg_gdk_screen_height(void)
{
  #define H_gdk_screen_height "gint gdk_screen_height( void)"
  return(C_TO_XEN_gint(gdk_screen_height()));
}
static XEN gxg_gdk_screen_width_mm(void)
{
  #define H_gdk_screen_width_mm "gint gdk_screen_width_mm( void)"
  return(C_TO_XEN_gint(gdk_screen_width_mm()));
}
static XEN gxg_gdk_screen_height_mm(void)
{
  #define H_gdk_screen_height_mm "gint gdk_screen_height_mm( void)"
  return(C_TO_XEN_gint(gdk_screen_height_mm()));
}
static XEN gxg_gdk_flush(void)
{
  #define H_gdk_flush "void gdk_flush( void)"
  gdk_flush();
  return(XEN_FALSE);
}
static XEN gxg_gdk_beep(void)
{
  #define H_gdk_beep "void gdk_beep( void)"
  gdk_beep();
  return(XEN_FALSE);
}
static XEN gxg_gdk_set_double_click_time(XEN msec)
{
  #define H_gdk_set_double_click_time "void gdk_set_double_click_time(guint msec)"
  XEN_ASSERT_TYPE(XEN_guint_P(msec), msec, 1, "gdk_set_double_click_time", "guint");
  gdk_set_double_click_time(XEN_TO_C_guint(msec));
  return(XEN_FALSE);
}
static XEN gxg_gdk_rectangle_intersect(XEN src1, XEN src2, XEN dest)
{
  #define H_gdk_rectangle_intersect "gboolean gdk_rectangle_intersect(GdkRectangle* src1, GdkRectangle* src2, \
GdkRectangle* dest)"
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(src1), src1, 1, "gdk_rectangle_intersect", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(src2), src2, 2, "gdk_rectangle_intersect", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(dest), dest, 3, "gdk_rectangle_intersect", "GdkRectangle*");
  return(C_TO_XEN_gboolean(gdk_rectangle_intersect(XEN_TO_C_GdkRectangle_(src1), XEN_TO_C_GdkRectangle_(src2), XEN_TO_C_GdkRectangle_(dest))));
}
static XEN gxg_gdk_rectangle_union(XEN src1, XEN src2, XEN dest)
{
  #define H_gdk_rectangle_union "void gdk_rectangle_union(GdkRectangle* src1, GdkRectangle* src2, GdkRectangle* dest)"
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(src1), src1, 1, "gdk_rectangle_union", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(src2), src2, 2, "gdk_rectangle_union", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(dest), dest, 3, "gdk_rectangle_union", "GdkRectangle*");
  gdk_rectangle_union(XEN_TO_C_GdkRectangle_(src1), XEN_TO_C_GdkRectangle_(src2), XEN_TO_C_GdkRectangle_(dest));
  return(XEN_FALSE);
}
static XEN gxg_gdk_rectangle_get_type(void)
{
  #define H_gdk_rectangle_get_type "GType gdk_rectangle_get_type( void)"
  return(C_TO_XEN_GType(gdk_rectangle_get_type()));
}
static XEN gxg_gdk_event_send_clientmessage_toall(XEN event)
{
  #define H_gdk_event_send_clientmessage_toall "void gdk_event_send_clientmessage_toall(GdkEvent* event)"
  XEN_ASSERT_TYPE(XEN_GdkEvent__P(event), event, 1, "gdk_event_send_clientmessage_toall", "GdkEvent*");
  gdk_event_send_clientmessage_toall(XEN_TO_C_GdkEvent_(event));
  return(XEN_FALSE);
}
static XEN gxg_gdk_event_send_client_message(XEN event, XEN xid)
{
  #define H_gdk_event_send_client_message "gboolean gdk_event_send_client_message(GdkEvent* event, guint32 xid)"
  XEN_ASSERT_TYPE(XEN_GdkEvent__P(event), event, 1, "gdk_event_send_client_message", "GdkEvent*");
  XEN_ASSERT_TYPE(XEN_guint32_P(xid), xid, 2, "gdk_event_send_client_message", "guint32");
  return(C_TO_XEN_gboolean(gdk_event_send_client_message(XEN_TO_C_GdkEvent_(event), XEN_TO_C_guint32(xid))));
}
static XEN gxg_gdk_threads_enter(void)
{
  #define H_gdk_threads_enter "void gdk_threads_enter( void)"
  gdk_threads_enter();
  return(XEN_FALSE);
}
static XEN gxg_gdk_threads_leave(void)
{
  #define H_gdk_threads_leave "void gdk_threads_leave( void)"
  gdk_threads_leave();
  return(XEN_FALSE);
}
static XEN gxg_gdk_threads_init(void)
{
  #define H_gdk_threads_init "void gdk_threads_init( void)"
  gdk_threads_init();
  return(XEN_FALSE);
}
static XEN gxg_gdk_image_get_type(void)
{
  #define H_gdk_image_get_type "GType gdk_image_get_type( void)"
  return(C_TO_XEN_GType(gdk_image_get_type()));
}
static XEN gxg_gdk_image_new(XEN type, XEN visual, XEN width, XEN height)
{
  #define H_gdk_image_new "GdkImage* gdk_image_new(GdkImageType type, GdkVisual* visual, gint width, \
gint height)"
  XEN_ASSERT_TYPE(XEN_GdkImageType_P(type), type, 1, "gdk_image_new", "GdkImageType");
  XEN_ASSERT_TYPE(XEN_GdkVisual__P(visual), visual, 2, "gdk_image_new", "GdkVisual*");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 3, "gdk_image_new", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 4, "gdk_image_new", "gint");
  return(C_TO_XEN_GdkImage_(gdk_image_new(XEN_TO_C_GdkImageType(type), XEN_TO_C_GdkVisual_(visual), XEN_TO_C_gint(width), 
                                          XEN_TO_C_gint(height))));
}
static XEN gxg_gdk_device_get_type(void)
{
  #define H_gdk_device_get_type "GType gdk_device_get_type( void)"
  return(C_TO_XEN_GType(gdk_device_get_type()));
}
static XEN gxg_gdk_devices_list(void)
{
  #define H_gdk_devices_list "GList* gdk_devices_list( void)"
  return(C_TO_XEN_GList_(gdk_devices_list()));
}
static XEN gxg_gdk_device_set_source(XEN device, XEN source)
{
  #define H_gdk_device_set_source "void gdk_device_set_source(GdkDevice* device, GdkInputSource source)"
  XEN_ASSERT_TYPE(XEN_GdkDevice__P(device), device, 1, "gdk_device_set_source", "GdkDevice*");
  XEN_ASSERT_TYPE(XEN_GdkInputSource_P(source), source, 2, "gdk_device_set_source", "GdkInputSource");
  gdk_device_set_source(XEN_TO_C_GdkDevice_(device), XEN_TO_C_GdkInputSource(source));
  return(XEN_FALSE);
}
static XEN gxg_gdk_device_set_mode(XEN device, XEN mode)
{
  #define H_gdk_device_set_mode "gboolean gdk_device_set_mode(GdkDevice* device, GdkInputMode mode)"
  XEN_ASSERT_TYPE(XEN_GdkDevice__P(device), device, 1, "gdk_device_set_mode", "GdkDevice*");
  XEN_ASSERT_TYPE(XEN_GdkInputMode_P(mode), mode, 2, "gdk_device_set_mode", "GdkInputMode");
  return(C_TO_XEN_gboolean(gdk_device_set_mode(XEN_TO_C_GdkDevice_(device), XEN_TO_C_GdkInputMode(mode))));
}
static XEN gxg_gdk_device_set_key(XEN device, XEN index, XEN keyval, XEN modifiers)
{
  #define H_gdk_device_set_key "void gdk_device_set_key(GdkDevice* device, guint index, guint keyval, \
GdkModifierType modifiers)"
  XEN_ASSERT_TYPE(XEN_GdkDevice__P(device), device, 1, "gdk_device_set_key", "GdkDevice*");
  XEN_ASSERT_TYPE(XEN_guint_P(index), index, 2, "gdk_device_set_key", "guint");
  XEN_ASSERT_TYPE(XEN_guint_P(keyval), keyval, 3, "gdk_device_set_key", "guint");
  XEN_ASSERT_TYPE(XEN_GdkModifierType_P(modifiers), modifiers, 4, "gdk_device_set_key", "GdkModifierType");
  gdk_device_set_key(XEN_TO_C_GdkDevice_(device), XEN_TO_C_guint(index), XEN_TO_C_guint(keyval), XEN_TO_C_GdkModifierType(modifiers));
  return(XEN_FALSE);
}
static XEN gxg_gdk_device_set_axis_use(XEN device, XEN index, XEN use)
{
  #define H_gdk_device_set_axis_use "void gdk_device_set_axis_use(GdkDevice* device, guint index, GdkAxisUse use)"
  XEN_ASSERT_TYPE(XEN_GdkDevice__P(device), device, 1, "gdk_device_set_axis_use", "GdkDevice*");
  XEN_ASSERT_TYPE(XEN_guint_P(index), index, 2, "gdk_device_set_axis_use", "guint");
  XEN_ASSERT_TYPE(XEN_GdkAxisUse_P(use), use, 3, "gdk_device_set_axis_use", "GdkAxisUse");
  gdk_device_set_axis_use(XEN_TO_C_GdkDevice_(device), XEN_TO_C_guint(index), XEN_TO_C_GdkAxisUse(use));
  return(XEN_FALSE);
}
static XEN gxg_gdk_device_get_state(XEN device, XEN window, XEN axes, XEN mask)
{
  #define H_gdk_device_get_state "void gdk_device_get_state(GdkDevice* device, GdkWindow* window, gdouble* axes, \
GdkModifierType* [mask])"
  GdkModifierType ref_mask;
  XEN_ASSERT_TYPE(XEN_GdkDevice__P(device), device, 1, "gdk_device_get_state", "GdkDevice*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 2, "gdk_device_get_state", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_gdouble__P(axes), axes, 3, "gdk_device_get_state", "gdouble*");
  gdk_device_get_state(XEN_TO_C_GdkDevice_(device), XEN_TO_C_GdkWindow_(window), XEN_TO_C_gdouble_(axes), &ref_mask);
  return(XEN_LIST_1(C_TO_XEN_GdkModifierType(ref_mask)));
}
static XEN gxg_gdk_device_get_history(XEN device, XEN window, XEN start, XEN stop, XEN events, XEN n_events)
{
  #define H_gdk_device_get_history "gboolean gdk_device_get_history(GdkDevice* device, GdkWindow* window, \
guint32 start, guint32 stop, GdkTimeCoord*** [events], gint* [n_events])"
  GdkTimeCoord** ref_events = NULL;
  gint ref_n_events;
  XEN_ASSERT_TYPE(XEN_GdkDevice__P(device), device, 1, "gdk_device_get_history", "GdkDevice*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 2, "gdk_device_get_history", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_guint32_P(start), start, 3, "gdk_device_get_history", "guint32");
  XEN_ASSERT_TYPE(XEN_guint32_P(stop), stop, 4, "gdk_device_get_history", "guint32");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gdk_device_get_history(XEN_TO_C_GdkDevice_(device), XEN_TO_C_GdkWindow_(window), XEN_TO_C_guint32(start), 
                                                      XEN_TO_C_guint32(stop), &ref_events, &ref_n_events));
    return(XEN_LIST_3(result, C_TO_XEN_GdkTimeCoord__(ref_events), C_TO_XEN_gint(ref_n_events)));
   }
}
static XEN gxg_gdk_device_free_history(XEN events, XEN n_events)
{
  #define H_gdk_device_free_history "void gdk_device_free_history(GdkTimeCoord** events, gint n_events)"
  XEN_ASSERT_TYPE(XEN_GdkTimeCoord___P(events), events, 1, "gdk_device_free_history", "GdkTimeCoord**");
  XEN_ASSERT_TYPE(XEN_gint_P(n_events), n_events, 2, "gdk_device_free_history", "gint");
  gdk_device_free_history(XEN_TO_C_GdkTimeCoord__(events), XEN_TO_C_gint(n_events));
  return(XEN_FALSE);
}
static XEN gxg_gdk_device_get_axis(XEN device, XEN axes, XEN use, XEN value)
{
  #define H_gdk_device_get_axis "gboolean gdk_device_get_axis(GdkDevice* device, gdouble* axes, GdkAxisUse use, \
gdouble* value)"
  XEN_ASSERT_TYPE(XEN_GdkDevice__P(device), device, 1, "gdk_device_get_axis", "GdkDevice*");
  XEN_ASSERT_TYPE(XEN_gdouble__P(axes), axes, 2, "gdk_device_get_axis", "gdouble*");
  XEN_ASSERT_TYPE(XEN_GdkAxisUse_P(use), use, 3, "gdk_device_get_axis", "GdkAxisUse");
  XEN_ASSERT_TYPE(XEN_gdouble__P(value), value, 4, "gdk_device_get_axis", "gdouble*");
  return(C_TO_XEN_gboolean(gdk_device_get_axis(XEN_TO_C_GdkDevice_(device), XEN_TO_C_gdouble_(axes), XEN_TO_C_GdkAxisUse(use), 
                                               XEN_TO_C_gdouble_(value))));
}
static XEN gxg_gdk_input_set_extension_events(XEN window, XEN mask, XEN mode)
{
  #define H_gdk_input_set_extension_events "void gdk_input_set_extension_events(GdkWindow* window, gint mask, \
GdkExtensionMode mode)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_input_set_extension_events", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_gint_P(mask), mask, 2, "gdk_input_set_extension_events", "gint");
  XEN_ASSERT_TYPE(XEN_GdkExtensionMode_P(mode), mode, 3, "gdk_input_set_extension_events", "GdkExtensionMode");
  gdk_input_set_extension_events(XEN_TO_C_GdkWindow_(window), XEN_TO_C_gint(mask), XEN_TO_C_GdkExtensionMode(mode));
  return(XEN_FALSE);
}
static XEN gxg_gdk_device_get_core_pointer(void)
{
  #define H_gdk_device_get_core_pointer "GdkDevice* gdk_device_get_core_pointer( void)"
  return(C_TO_XEN_GdkDevice_(gdk_device_get_core_pointer()));
}
static XEN gxg_gdk_keymap_get_type(void)
{
  #define H_gdk_keymap_get_type "GType gdk_keymap_get_type( void)"
  return(C_TO_XEN_GType(gdk_keymap_get_type()));
}
static XEN gxg_gdk_keymap_get_default(void)
{
  #define H_gdk_keymap_get_default "GdkKeymap* gdk_keymap_get_default( void)"
  return(C_TO_XEN_GdkKeymap_(gdk_keymap_get_default()));
}
static XEN gxg_gdk_keymap_lookup_key(XEN keymap, XEN key)
{
  #define H_gdk_keymap_lookup_key "guint gdk_keymap_lookup_key(GdkKeymap* keymap, GdkKeymapKey* key)"
  XEN_ASSERT_TYPE(XEN_GdkKeymap__P(keymap), keymap, 1, "gdk_keymap_lookup_key", "GdkKeymap*");
  XEN_ASSERT_TYPE(XEN_GdkKeymapKey__P(key), key, 2, "gdk_keymap_lookup_key", "GdkKeymapKey*");
  return(C_TO_XEN_guint(gdk_keymap_lookup_key(XEN_TO_C_GdkKeymap_(keymap), XEN_TO_C_GdkKeymapKey_(key))));
}
static XEN gxg_gdk_keymap_get_entries_for_keyval(XEN keymap, XEN keyval, XEN keys, XEN n_keys)
{
  #define H_gdk_keymap_get_entries_for_keyval "gboolean gdk_keymap_get_entries_for_keyval(GdkKeymap* keymap, \
guint keyval, GdkKeymapKey** [keys], gint* [n_keys])"
  GdkKeymapKey* ref_keys = NULL;
  gint ref_n_keys;
  XEN_ASSERT_TYPE(XEN_GdkKeymap__P(keymap), keymap, 1, "gdk_keymap_get_entries_for_keyval", "GdkKeymap*");
  XEN_ASSERT_TYPE(XEN_guint_P(keyval), keyval, 2, "gdk_keymap_get_entries_for_keyval", "guint");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gdk_keymap_get_entries_for_keyval(XEN_TO_C_GdkKeymap_(keymap), XEN_TO_C_guint(keyval), &ref_keys, 
                                                                 &ref_n_keys));
    return(XEN_LIST_3(result, C_TO_XEN_GdkKeymapKey_(ref_keys), C_TO_XEN_gint(ref_n_keys)));
   }
}
static XEN gxg_gdk_keymap_get_entries_for_keycode(XEN keymap, XEN hardware_keycode, XEN keys, XEN keyvals, XEN n_entries)
{
  #define H_gdk_keymap_get_entries_for_keycode "gboolean gdk_keymap_get_entries_for_keycode(GdkKeymap* keymap, \
guint hardware_keycode, GdkKeymapKey** [keys], guint** [keyvals], gint* [n_entries])"
  GdkKeymapKey* ref_keys = NULL;
  guint* ref_keyvals = NULL;
  gint ref_n_entries;
  XEN_ASSERT_TYPE(XEN_GdkKeymap__P(keymap), keymap, 1, "gdk_keymap_get_entries_for_keycode", "GdkKeymap*");
  XEN_ASSERT_TYPE(XEN_guint_P(hardware_keycode), hardware_keycode, 2, "gdk_keymap_get_entries_for_keycode", "guint");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gdk_keymap_get_entries_for_keycode(XEN_TO_C_GdkKeymap_(keymap), XEN_TO_C_guint(hardware_keycode), 
                                                                  &ref_keys, &ref_keyvals, &ref_n_entries));
    return(XEN_LIST_4(result, C_TO_XEN_GdkKeymapKey_(ref_keys), C_TO_XEN_guint_(ref_keyvals), C_TO_XEN_gint(ref_n_entries)));
   }
}
static XEN gxg_gdk_keymap_get_direction(XEN keymap)
{
  #define H_gdk_keymap_get_direction "PangoDirection gdk_keymap_get_direction(GdkKeymap* keymap)"
  XEN_ASSERT_TYPE(XEN_GdkKeymap__P(keymap), keymap, 1, "gdk_keymap_get_direction", "GdkKeymap*");
  return(C_TO_XEN_PangoDirection(gdk_keymap_get_direction(XEN_TO_C_GdkKeymap_(keymap))));
}
static XEN gxg_gdk_keyval_name(XEN keyval)
{
  #define H_gdk_keyval_name "gchar* gdk_keyval_name(guint keyval)"
  XEN_ASSERT_TYPE(XEN_guint_P(keyval), keyval, 1, "gdk_keyval_name", "guint");
  return(C_TO_XEN_gchar_(gdk_keyval_name(XEN_TO_C_guint(keyval))));
}
static XEN gxg_gdk_keyval_from_name(XEN keyval_name)
{
  #define H_gdk_keyval_from_name "guint gdk_keyval_from_name(gchar* keyval_name)"
  XEN_ASSERT_TYPE(XEN_gchar__P(keyval_name), keyval_name, 1, "gdk_keyval_from_name", "gchar*");
  return(C_TO_XEN_guint(gdk_keyval_from_name(XEN_TO_C_gchar_(keyval_name))));
}
static XEN gxg_gdk_keyval_convert_case(XEN symbol, XEN lower, XEN upper)
{
  #define H_gdk_keyval_convert_case "void gdk_keyval_convert_case(guint symbol, guint* [lower], guint* [upper])"
  guint ref_lower;
  guint ref_upper;
  XEN_ASSERT_TYPE(XEN_guint_P(symbol), symbol, 1, "gdk_keyval_convert_case", "guint");
  gdk_keyval_convert_case(XEN_TO_C_guint(symbol), &ref_lower, &ref_upper);
  return(XEN_LIST_2(C_TO_XEN_guint(ref_lower), C_TO_XEN_guint(ref_upper)));
}
static XEN gxg_gdk_keyval_to_upper(XEN keyval)
{
  #define H_gdk_keyval_to_upper "guint gdk_keyval_to_upper(guint keyval)"
  XEN_ASSERT_TYPE(XEN_guint_P(keyval), keyval, 1, "gdk_keyval_to_upper", "guint");
  return(C_TO_XEN_guint(gdk_keyval_to_upper(XEN_TO_C_guint(keyval))));
}
static XEN gxg_gdk_keyval_to_lower(XEN keyval)
{
  #define H_gdk_keyval_to_lower "guint gdk_keyval_to_lower(guint keyval)"
  XEN_ASSERT_TYPE(XEN_guint_P(keyval), keyval, 1, "gdk_keyval_to_lower", "guint");
  return(C_TO_XEN_guint(gdk_keyval_to_lower(XEN_TO_C_guint(keyval))));
}
static XEN gxg_gdk_keyval_is_upper(XEN keyval)
{
  #define H_gdk_keyval_is_upper "gboolean gdk_keyval_is_upper(guint keyval)"
  XEN_ASSERT_TYPE(XEN_guint_P(keyval), keyval, 1, "gdk_keyval_is_upper", "guint");
  return(C_TO_XEN_gboolean(gdk_keyval_is_upper(XEN_TO_C_guint(keyval))));
}
static XEN gxg_gdk_keyval_is_lower(XEN keyval)
{
  #define H_gdk_keyval_is_lower "gboolean gdk_keyval_is_lower(guint keyval)"
  XEN_ASSERT_TYPE(XEN_guint_P(keyval), keyval, 1, "gdk_keyval_is_lower", "guint");
  return(C_TO_XEN_gboolean(gdk_keyval_is_lower(XEN_TO_C_guint(keyval))));
}
static XEN gxg_gdk_keyval_to_unicode(XEN keyval)
{
  #define H_gdk_keyval_to_unicode "guint32 gdk_keyval_to_unicode(guint keyval)"
  XEN_ASSERT_TYPE(XEN_guint_P(keyval), keyval, 1, "gdk_keyval_to_unicode", "guint");
  return(C_TO_XEN_guint32(gdk_keyval_to_unicode(XEN_TO_C_guint(keyval))));
}
static XEN gxg_gdk_unicode_to_keyval(XEN wc)
{
  #define H_gdk_unicode_to_keyval "guint gdk_unicode_to_keyval(guint32 wc)"
  XEN_ASSERT_TYPE(XEN_guint32_P(wc), wc, 1, "gdk_unicode_to_keyval", "guint32");
  return(C_TO_XEN_guint(gdk_unicode_to_keyval(XEN_TO_C_guint32(wc))));
}
static XEN gxg_gdk_pango_context_get(void)
{
  #define H_gdk_pango_context_get "PangoContext* gdk_pango_context_get( void)"
  return(C_TO_XEN_PangoContext_(gdk_pango_context_get()));
}
static XEN gxg_gdk_pango_context_set_colormap(XEN context, XEN colormap)
{
  #define H_gdk_pango_context_set_colormap "void gdk_pango_context_set_colormap(PangoContext* context, \
GdkColormap* colormap)"
  XEN_ASSERT_TYPE(XEN_PangoContext__P(context), context, 1, "gdk_pango_context_set_colormap", "PangoContext*");
  XEN_ASSERT_TYPE(XEN_GdkColormap__P(colormap), colormap, 2, "gdk_pango_context_set_colormap", "GdkColormap*");
  gdk_pango_context_set_colormap(XEN_TO_C_PangoContext_(context), XEN_TO_C_GdkColormap_(colormap));
  return(XEN_FALSE);
}
static XEN gxg_gdk_pango_layout_line_get_clip_region(XEN line, XEN x_origin, XEN y_origin, XEN index_ranges, XEN n_ranges)
{
  #define H_gdk_pango_layout_line_get_clip_region "GdkRegion* gdk_pango_layout_line_get_clip_region(PangoLayoutLine* line, \
gint x_origin, gint y_origin, gint* index_ranges, gint n_ranges)"
  XEN_ASSERT_TYPE(XEN_PangoLayoutLine__P(line), line, 1, "gdk_pango_layout_line_get_clip_region", "PangoLayoutLine*");
  XEN_ASSERT_TYPE(XEN_gint_P(x_origin), x_origin, 2, "gdk_pango_layout_line_get_clip_region", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y_origin), y_origin, 3, "gdk_pango_layout_line_get_clip_region", "gint");
  XEN_ASSERT_TYPE(XEN_gint__P(index_ranges), index_ranges, 4, "gdk_pango_layout_line_get_clip_region", "gint*");
  XEN_ASSERT_TYPE(XEN_gint_P(n_ranges), n_ranges, 5, "gdk_pango_layout_line_get_clip_region", "gint");
  return(C_TO_XEN_GdkRegion_(gdk_pango_layout_line_get_clip_region(XEN_TO_C_PangoLayoutLine_(line), XEN_TO_C_gint(x_origin), 
                                                                   XEN_TO_C_gint(y_origin), XEN_TO_C_gint_(index_ranges), 
                                                                   XEN_TO_C_gint(n_ranges))));
}
static XEN gxg_gdk_pango_layout_get_clip_region(XEN layout, XEN x_origin, XEN y_origin, XEN index_ranges, XEN n_ranges)
{
  #define H_gdk_pango_layout_get_clip_region "GdkRegion* gdk_pango_layout_get_clip_region(PangoLayout* layout, \
gint x_origin, gint y_origin, gint* index_ranges, gint n_ranges)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "gdk_pango_layout_get_clip_region", "PangoLayout*");
  XEN_ASSERT_TYPE(XEN_gint_P(x_origin), x_origin, 2, "gdk_pango_layout_get_clip_region", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y_origin), y_origin, 3, "gdk_pango_layout_get_clip_region", "gint");
  XEN_ASSERT_TYPE(XEN_gint__P(index_ranges), index_ranges, 4, "gdk_pango_layout_get_clip_region", "gint*");
  XEN_ASSERT_TYPE(XEN_gint_P(n_ranges), n_ranges, 5, "gdk_pango_layout_get_clip_region", "gint");
  return(C_TO_XEN_GdkRegion_(gdk_pango_layout_get_clip_region(XEN_TO_C_PangoLayout_(layout), XEN_TO_C_gint(x_origin), XEN_TO_C_gint(y_origin), 
                                                              XEN_TO_C_gint_(index_ranges), XEN_TO_C_gint(n_ranges))));
}
static XEN gxg_gdk_pango_attr_stipple_new(XEN stipple)
{
  #define H_gdk_pango_attr_stipple_new "PangoAttribute* gdk_pango_attr_stipple_new(GdkBitmap* stipple)"
  XEN_ASSERT_TYPE(XEN_GdkBitmap__P(stipple), stipple, 1, "gdk_pango_attr_stipple_new", "GdkBitmap*");
  return(C_TO_XEN_PangoAttribute_(gdk_pango_attr_stipple_new(XEN_TO_C_GdkBitmap_(stipple))));
}
static XEN gxg_gdk_pango_attr_embossed_new(XEN embossed)
{
  #define H_gdk_pango_attr_embossed_new "PangoAttribute* gdk_pango_attr_embossed_new(gboolean embossed)"
  XEN_ASSERT_TYPE(XEN_gboolean_P(embossed), embossed, 1, "gdk_pango_attr_embossed_new", "gboolean");
  return(C_TO_XEN_PangoAttribute_(gdk_pango_attr_embossed_new(XEN_TO_C_gboolean(embossed))));
}
static XEN gxg_gdk_pixbuf_render_threshold_alpha(XEN pixbuf, XEN bitmap, XEN src_x, XEN src_y, XEN dest_x, XEN dest_y, XEN width, XEN height, XEN alpha_threshold)
{
  #define H_gdk_pixbuf_render_threshold_alpha "void gdk_pixbuf_render_threshold_alpha(GdkPixbuf* pixbuf, \
GdkBitmap* bitmap, int src_x, int src_y, int dest_x, int dest_y, int width, int height, int alpha_threshold)"
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(pixbuf), pixbuf, 1, "gdk_pixbuf_render_threshold_alpha", "GdkPixbuf*");
  XEN_ASSERT_TYPE(XEN_GdkBitmap__P(bitmap), bitmap, 2, "gdk_pixbuf_render_threshold_alpha", "GdkBitmap*");
  XEN_ASSERT_TYPE(XEN_int_P(src_x), src_x, 3, "gdk_pixbuf_render_threshold_alpha", "int");
  XEN_ASSERT_TYPE(XEN_int_P(src_y), src_y, 4, "gdk_pixbuf_render_threshold_alpha", "int");
  XEN_ASSERT_TYPE(XEN_int_P(dest_x), dest_x, 5, "gdk_pixbuf_render_threshold_alpha", "int");
  XEN_ASSERT_TYPE(XEN_int_P(dest_y), dest_y, 6, "gdk_pixbuf_render_threshold_alpha", "int");
  XEN_ASSERT_TYPE(XEN_int_P(width), width, 7, "gdk_pixbuf_render_threshold_alpha", "int");
  XEN_ASSERT_TYPE(XEN_int_P(height), height, 8, "gdk_pixbuf_render_threshold_alpha", "int");
  XEN_ASSERT_TYPE(XEN_int_P(alpha_threshold), alpha_threshold, 9, "gdk_pixbuf_render_threshold_alpha", "int");
  gdk_pixbuf_render_threshold_alpha(XEN_TO_C_GdkPixbuf_(pixbuf), XEN_TO_C_GdkBitmap_(bitmap), XEN_TO_C_int(src_x), XEN_TO_C_int(src_y), 
                                    XEN_TO_C_int(dest_x), XEN_TO_C_int(dest_y), XEN_TO_C_int(width), XEN_TO_C_int(height), 
                                    XEN_TO_C_int(alpha_threshold));
  return(XEN_FALSE);
}
static XEN gxg_gdk_pixbuf_render_pixmap_and_mask_for_colormap(XEN pixbuf, XEN colormap, XEN pixmap_return, XEN mask_return, XEN alpha_threshold)
{
  #define H_gdk_pixbuf_render_pixmap_and_mask_for_colormap "void gdk_pixbuf_render_pixmap_and_mask_for_colormap(GdkPixbuf* pixbuf, \
GdkColormap* colormap, GdkPixmap** [pixmap_return], GdkBitmap** [mask_return], int alpha_threshold)"
  GdkPixmap* ref_pixmap_return = NULL;
  GdkBitmap* ref_mask_return = NULL;
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(pixbuf), pixbuf, 1, "gdk_pixbuf_render_pixmap_and_mask_for_colormap", "GdkPixbuf*");
  XEN_ASSERT_TYPE(XEN_GdkColormap__P(colormap), colormap, 2, "gdk_pixbuf_render_pixmap_and_mask_for_colormap", "GdkColormap*");
  XEN_ASSERT_TYPE(XEN_int_P(alpha_threshold), alpha_threshold, 5, "gdk_pixbuf_render_pixmap_and_mask_for_colormap", "int");
  gdk_pixbuf_render_pixmap_and_mask_for_colormap(XEN_TO_C_GdkPixbuf_(pixbuf), XEN_TO_C_GdkColormap_(colormap), &ref_pixmap_return, 
                                                 &ref_mask_return, XEN_TO_C_int(alpha_threshold));
  return(XEN_LIST_2(C_TO_XEN_GdkPixmap_(ref_pixmap_return), C_TO_XEN_GdkBitmap_(ref_mask_return)));
}
static XEN gxg_gdk_pixbuf_render_pixmap_and_mask(XEN pixbuf, XEN pixmap_return, XEN mask_return, XEN alpha_threshold)
{
  #define H_gdk_pixbuf_render_pixmap_and_mask "void gdk_pixbuf_render_pixmap_and_mask(GdkPixbuf* pixbuf, \
GdkPixmap** [pixmap_return], GdkBitmap** [mask_return], int alpha_threshold)"
  GdkPixmap* ref_pixmap_return = NULL;
  GdkBitmap* ref_mask_return = NULL;
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(pixbuf), pixbuf, 1, "gdk_pixbuf_render_pixmap_and_mask", "GdkPixbuf*");
  XEN_ASSERT_TYPE(XEN_int_P(alpha_threshold), alpha_threshold, 4, "gdk_pixbuf_render_pixmap_and_mask", "int");
  gdk_pixbuf_render_pixmap_and_mask(XEN_TO_C_GdkPixbuf_(pixbuf), &ref_pixmap_return, &ref_mask_return, XEN_TO_C_int(alpha_threshold));
  return(XEN_LIST_2(C_TO_XEN_GdkPixmap_(ref_pixmap_return), C_TO_XEN_GdkBitmap_(ref_mask_return)));
}
static XEN gxg_gdk_pixbuf_get_from_drawable(XEN dest, XEN src, XEN cmap, XEN src_x, XEN src_y, XEN dest_x, XEN dest_y, XEN width, XEN height)
{
  #define H_gdk_pixbuf_get_from_drawable "GdkPixbuf* gdk_pixbuf_get_from_drawable(GdkPixbuf* dest, GdkDrawable* src, \
GdkColormap* cmap, int src_x, int src_y, int dest_x, int dest_y, int width, int height)"
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(dest), dest, 1, "gdk_pixbuf_get_from_drawable", "GdkPixbuf*");
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(src), src, 2, "gdk_pixbuf_get_from_drawable", "GdkDrawable*");
  XEN_ASSERT_TYPE(XEN_GdkColormap__P(cmap), cmap, 3, "gdk_pixbuf_get_from_drawable", "GdkColormap*");
  XEN_ASSERT_TYPE(XEN_int_P(src_x), src_x, 4, "gdk_pixbuf_get_from_drawable", "int");
  XEN_ASSERT_TYPE(XEN_int_P(src_y), src_y, 5, "gdk_pixbuf_get_from_drawable", "int");
  XEN_ASSERT_TYPE(XEN_int_P(dest_x), dest_x, 6, "gdk_pixbuf_get_from_drawable", "int");
  XEN_ASSERT_TYPE(XEN_int_P(dest_y), dest_y, 7, "gdk_pixbuf_get_from_drawable", "int");
  XEN_ASSERT_TYPE(XEN_int_P(width), width, 8, "gdk_pixbuf_get_from_drawable", "int");
  XEN_ASSERT_TYPE(XEN_int_P(height), height, 9, "gdk_pixbuf_get_from_drawable", "int");
  return(C_TO_XEN_GdkPixbuf_(gdk_pixbuf_get_from_drawable(XEN_TO_C_GdkPixbuf_(dest), XEN_TO_C_GdkDrawable_(src), XEN_TO_C_GdkColormap_(cmap), 
                                                          XEN_TO_C_int(src_x), XEN_TO_C_int(src_y), XEN_TO_C_int(dest_x), 
                                                          XEN_TO_C_int(dest_y), XEN_TO_C_int(width), XEN_TO_C_int(height))));
}
static XEN gxg_gdk_pixbuf_get_from_image(XEN dest, XEN src, XEN cmap, XEN src_x, XEN src_y, XEN dest_x, XEN dest_y, XEN width, XEN height)
{
  #define H_gdk_pixbuf_get_from_image "GdkPixbuf* gdk_pixbuf_get_from_image(GdkPixbuf* dest, GdkImage* src, \
GdkColormap* cmap, int src_x, int src_y, int dest_x, int dest_y, int width, int height)"
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(dest), dest, 1, "gdk_pixbuf_get_from_image", "GdkPixbuf*");
  XEN_ASSERT_TYPE(XEN_GdkImage__P(src), src, 2, "gdk_pixbuf_get_from_image", "GdkImage*");
  XEN_ASSERT_TYPE(XEN_GdkColormap__P(cmap), cmap, 3, "gdk_pixbuf_get_from_image", "GdkColormap*");
  XEN_ASSERT_TYPE(XEN_int_P(src_x), src_x, 4, "gdk_pixbuf_get_from_image", "int");
  XEN_ASSERT_TYPE(XEN_int_P(src_y), src_y, 5, "gdk_pixbuf_get_from_image", "int");
  XEN_ASSERT_TYPE(XEN_int_P(dest_x), dest_x, 6, "gdk_pixbuf_get_from_image", "int");
  XEN_ASSERT_TYPE(XEN_int_P(dest_y), dest_y, 7, "gdk_pixbuf_get_from_image", "int");
  XEN_ASSERT_TYPE(XEN_int_P(width), width, 8, "gdk_pixbuf_get_from_image", "int");
  XEN_ASSERT_TYPE(XEN_int_P(height), height, 9, "gdk_pixbuf_get_from_image", "int");
  return(C_TO_XEN_GdkPixbuf_(gdk_pixbuf_get_from_image(XEN_TO_C_GdkPixbuf_(dest), XEN_TO_C_GdkImage_(src), XEN_TO_C_GdkColormap_(cmap), 
                                                       XEN_TO_C_int(src_x), XEN_TO_C_int(src_y), XEN_TO_C_int(dest_x), XEN_TO_C_int(dest_y), 
                                                       XEN_TO_C_int(width), XEN_TO_C_int(height))));
}
static XEN gxg_gdk_pixmap_get_type(void)
{
  #define H_gdk_pixmap_get_type "GType gdk_pixmap_get_type( void)"
  return(C_TO_XEN_GType(gdk_pixmap_get_type()));
}
static XEN gxg_gdk_pixmap_new(XEN window, XEN width, XEN height, XEN depth)
{
  #define H_gdk_pixmap_new "GdkPixmap* gdk_pixmap_new(Drawable_was_Window* window, gint width, gint height, \
gint depth)"
  XEN_ASSERT_TYPE(XEN_Drawable_was_Window__P(window), window, 1, "gdk_pixmap_new", "Drawable_was_Window*");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 2, "gdk_pixmap_new", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 3, "gdk_pixmap_new", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(depth), depth, 4, "gdk_pixmap_new", "gint");
  return(C_TO_XEN_GdkPixmap_(gdk_pixmap_new(XEN_TO_C_Drawable_was_Window_(window), XEN_TO_C_gint(width), XEN_TO_C_gint(height), 
                                            XEN_TO_C_gint(depth))));
}
static XEN gxg_gdk_bitmap_create_from_data(XEN window, XEN data, XEN width, XEN height)
{
  #define H_gdk_bitmap_create_from_data "GdkBitmap* gdk_bitmap_create_from_data(Drawable_was_Window* window, \
gchar* data, gint width, gint height)"
  XEN_ASSERT_TYPE(XEN_Drawable_was_Window__P(window), window, 1, "gdk_bitmap_create_from_data", "Drawable_was_Window*");
  XEN_ASSERT_TYPE(XEN_gchar__P(data), data, 2, "gdk_bitmap_create_from_data", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 3, "gdk_bitmap_create_from_data", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 4, "gdk_bitmap_create_from_data", "gint");
  return(C_TO_XEN_GdkBitmap_(gdk_bitmap_create_from_data(XEN_TO_C_Drawable_was_Window_(window), XEN_TO_C_gchar_(data), XEN_TO_C_gint(width), 
                                                         XEN_TO_C_gint(height))));
}
static XEN gxg_gdk_pixmap_create_from_data(XEN window, XEN data, XEN width, XEN height, XEN depth, XEN fg, XEN bg)
{
  #define H_gdk_pixmap_create_from_data "GdkPixmap* gdk_pixmap_create_from_data(Drawable_was_Window* window, \
gchar* data, gint width, gint height, gint depth, GdkColor* fg, GdkColor* bg)"
  XEN_ASSERT_TYPE(XEN_Drawable_was_Window__P(window), window, 1, "gdk_pixmap_create_from_data", "Drawable_was_Window*");
  XEN_ASSERT_TYPE(XEN_gchar__P(data), data, 2, "gdk_pixmap_create_from_data", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 3, "gdk_pixmap_create_from_data", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 4, "gdk_pixmap_create_from_data", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(depth), depth, 5, "gdk_pixmap_create_from_data", "gint");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(fg), fg, 6, "gdk_pixmap_create_from_data", "GdkColor*");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(bg), bg, 7, "gdk_pixmap_create_from_data", "GdkColor*");
  return(C_TO_XEN_GdkPixmap_(gdk_pixmap_create_from_data(XEN_TO_C_Drawable_was_Window_(window), XEN_TO_C_gchar_(data), XEN_TO_C_gint(width), 
                                                         XEN_TO_C_gint(height), XEN_TO_C_gint(depth), XEN_TO_C_GdkColor_(fg), 
                                                         XEN_TO_C_GdkColor_(bg))));
}
static XEN gxg_gdk_pixmap_create_from_xpm(XEN window, XEN mask, XEN transparent_color, XEN filename)
{
  #define H_gdk_pixmap_create_from_xpm "GdkPixmap* gdk_pixmap_create_from_xpm(Drawable_was_Window* window, \
GdkBitmap** mask, GdkColor* transparent_color, gchar* filename)"
  XEN_ASSERT_TYPE(XEN_Drawable_was_Window__P(window), window, 1, "gdk_pixmap_create_from_xpm", "Drawable_was_Window*");
  XEN_ASSERT_TYPE(XEN_GdkBitmap___P(mask), mask, 2, "gdk_pixmap_create_from_xpm", "GdkBitmap**");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(transparent_color), transparent_color, 3, "gdk_pixmap_create_from_xpm", "GdkColor*");
  XEN_ASSERT_TYPE(XEN_gchar__P(filename), filename, 4, "gdk_pixmap_create_from_xpm", "gchar*");
  return(C_TO_XEN_GdkPixmap_(gdk_pixmap_create_from_xpm(XEN_TO_C_Drawable_was_Window_(window), XEN_TO_C_GdkBitmap__(mask), 
                                                        XEN_TO_C_GdkColor_(transparent_color), XEN_TO_C_gchar_(filename))));
}
static XEN gxg_gdk_pixmap_colormap_create_from_xpm(XEN window, XEN colormap, XEN mask, XEN transparent_color, XEN filename)
{
  #define H_gdk_pixmap_colormap_create_from_xpm "GdkPixmap* gdk_pixmap_colormap_create_from_xpm(Drawable_was_Window* window, \
GdkColormap* colormap, GdkBitmap** mask, GdkColor* transparent_color, gchar* filename)"
  XEN_ASSERT_TYPE(XEN_Drawable_was_Window__P(window), window, 1, "gdk_pixmap_colormap_create_from_xpm", "Drawable_was_Window*");
  XEN_ASSERT_TYPE(XEN_GdkColormap__P(colormap), colormap, 2, "gdk_pixmap_colormap_create_from_xpm", "GdkColormap*");
  XEN_ASSERT_TYPE(XEN_GdkBitmap___P(mask), mask, 3, "gdk_pixmap_colormap_create_from_xpm", "GdkBitmap**");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(transparent_color), transparent_color, 4, "gdk_pixmap_colormap_create_from_xpm", "GdkColor*");
  XEN_ASSERT_TYPE(XEN_gchar__P(filename), filename, 5, "gdk_pixmap_colormap_create_from_xpm", "gchar*");
  return(C_TO_XEN_GdkPixmap_(gdk_pixmap_colormap_create_from_xpm(XEN_TO_C_Drawable_was_Window_(window), XEN_TO_C_GdkColormap_(colormap), 
                                                                 XEN_TO_C_GdkBitmap__(mask), XEN_TO_C_GdkColor_(transparent_color), 
                                                                 XEN_TO_C_gchar_(filename))));
}
static XEN gxg_gdk_pixmap_create_from_xpm_d(XEN window, XEN mask, XEN transparent_color, XEN data)
{
  #define H_gdk_pixmap_create_from_xpm_d "GdkPixmap* gdk_pixmap_create_from_xpm_d(Drawable_was_Window* window, \
GdkBitmap** mask, GdkColor* transparent_color, gchar** data)"
  XEN_ASSERT_TYPE(XEN_Drawable_was_Window__P(window), window, 1, "gdk_pixmap_create_from_xpm_d", "Drawable_was_Window*");
  XEN_ASSERT_TYPE(XEN_GdkBitmap___P(mask), mask, 2, "gdk_pixmap_create_from_xpm_d", "GdkBitmap**");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(transparent_color), transparent_color, 3, "gdk_pixmap_create_from_xpm_d", "GdkColor*");
  XEN_ASSERT_TYPE(XEN_gchar___P(data), data, 4, "gdk_pixmap_create_from_xpm_d", "gchar**");
  return(C_TO_XEN_GdkPixmap_(gdk_pixmap_create_from_xpm_d(XEN_TO_C_Drawable_was_Window_(window), XEN_TO_C_GdkBitmap__(mask), 
                                                          XEN_TO_C_GdkColor_(transparent_color), XEN_TO_C_gchar__(data))));
}
static XEN gxg_gdk_pixmap_colormap_create_from_xpm_d(XEN window, XEN colormap, XEN mask, XEN transparent_color, XEN data)
{
  #define H_gdk_pixmap_colormap_create_from_xpm_d "GdkPixmap* gdk_pixmap_colormap_create_from_xpm_d(Drawable_was_Window* window, \
GdkColormap* colormap, GdkBitmap** mask, GdkColor* transparent_color, gchar** data)"
  XEN_ASSERT_TYPE(XEN_Drawable_was_Window__P(window), window, 1, "gdk_pixmap_colormap_create_from_xpm_d", "Drawable_was_Window*");
  XEN_ASSERT_TYPE(XEN_GdkColormap__P(colormap), colormap, 2, "gdk_pixmap_colormap_create_from_xpm_d", "GdkColormap*");
  XEN_ASSERT_TYPE(XEN_GdkBitmap___P(mask), mask, 3, "gdk_pixmap_colormap_create_from_xpm_d", "GdkBitmap**");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(transparent_color), transparent_color, 4, "gdk_pixmap_colormap_create_from_xpm_d", "GdkColor*");
  XEN_ASSERT_TYPE(XEN_gchar___P(data), data, 5, "gdk_pixmap_colormap_create_from_xpm_d", "gchar**");
  return(C_TO_XEN_GdkPixmap_(gdk_pixmap_colormap_create_from_xpm_d(XEN_TO_C_Drawable_was_Window_(window), XEN_TO_C_GdkColormap_(colormap), 
                                                                   XEN_TO_C_GdkBitmap__(mask), XEN_TO_C_GdkColor_(transparent_color), 
                                                                   XEN_TO_C_gchar__(data))));
}
static XEN gxg_gdk_pixmap_foreign_new(XEN anid)
{
  #define H_gdk_pixmap_foreign_new "GdkPixmap* gdk_pixmap_foreign_new(GdkNativeWindow anid)"
  XEN_ASSERT_TYPE(XEN_GdkNativeWindow_P(anid), anid, 1, "gdk_pixmap_foreign_new", "GdkNativeWindow");
  return(C_TO_XEN_GdkPixmap_(gdk_pixmap_foreign_new(XEN_TO_C_GdkNativeWindow(anid))));
}
static XEN gxg_gdk_pixmap_lookup(XEN anid)
{
  #define H_gdk_pixmap_lookup "GdkPixmap* gdk_pixmap_lookup(GdkNativeWindow anid)"
  XEN_ASSERT_TYPE(XEN_GdkNativeWindow_P(anid), anid, 1, "gdk_pixmap_lookup", "GdkNativeWindow");
  return(C_TO_XEN_GdkPixmap_(gdk_pixmap_lookup(XEN_TO_C_GdkNativeWindow(anid))));
}
static XEN gxg_gdk_atom_intern(XEN atom_name, XEN only_if_exists)
{
  #define H_gdk_atom_intern "GdkAtom gdk_atom_intern(gchar* atom_name, gboolean only_if_exists)"
  XEN_ASSERT_TYPE(XEN_gchar__P(atom_name), atom_name, 1, "gdk_atom_intern", "gchar*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(only_if_exists), only_if_exists, 2, "gdk_atom_intern", "gboolean");
  return(C_TO_XEN_GdkAtom(gdk_atom_intern(XEN_TO_C_gchar_(atom_name), XEN_TO_C_gboolean(only_if_exists))));
}
static XEN gxg_gdk_atom_name(XEN atom)
{
  #define H_gdk_atom_name "gchar* gdk_atom_name(GdkAtom atom)"
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(atom), atom, 1, "gdk_atom_name", "GdkAtom");
  {
   gchar* result;
   XEN rtn;
   result = gdk_atom_name(XEN_TO_C_GdkAtom(atom));
   rtn = C_TO_XEN_gchar_(result);
   g_free(result);
   return(rtn);
  }
}
static XEN gxg_gdk_property_get(XEN arglist)
{
  #define H_gdk_property_get "gboolean gdk_property_get(GdkWindow* window, GdkAtom property, GdkAtom type, \
gulong offset, gulong length, gint pdelete, GdkAtom* [actual_property_type], gint* [actual_format], gint* [actual_length], \
guchar** [data])"
  GdkAtom ref_actual_property_type;
  gint ref_actual_format;
  gint ref_actual_length;
  guchar* ref_data = NULL;
  XEN window, property, type, offset, length, pdelete;
  window = XEN_LIST_REF(arglist, 0);
  property = XEN_LIST_REF(arglist, 1);
  type = XEN_LIST_REF(arglist, 2);
  offset = XEN_LIST_REF(arglist, 3);
  length = XEN_LIST_REF(arglist, 4);
  pdelete = XEN_LIST_REF(arglist, 5);
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_property_get", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(property), property, 2, "gdk_property_get", "GdkAtom");
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(type), type, 3, "gdk_property_get", "GdkAtom");
  XEN_ASSERT_TYPE(XEN_gulong_P(offset), offset, 4, "gdk_property_get", "gulong");
  XEN_ASSERT_TYPE(XEN_gulong_P(length), length, 5, "gdk_property_get", "gulong");
  XEN_ASSERT_TYPE(XEN_gint_P(pdelete), pdelete, 6, "gdk_property_get", "gint");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gdk_property_get(XEN_TO_C_GdkWindow_(window), XEN_TO_C_GdkAtom(property), XEN_TO_C_GdkAtom(type), 
                                                XEN_TO_C_gulong(offset), XEN_TO_C_gulong(length), XEN_TO_C_gint(pdelete), 
                                                &ref_actual_property_type, &ref_actual_format, &ref_actual_length, &ref_data));
    {
      XEN data_val = XEN_FALSE;
#if HAVE_GUILE && (HAVE_SCM_MEM2STRING || HAVE_SCM_C_MAKE_RECTANGULAR)
      if (ref_actual_property_type == GDK_TARGET_STRING)
	data_val = C_TO_XEN_STRING((char *)ref_data);
      else if (ref_actual_length > 0) data_val = C_TO_XEN_STRINGN((char *)ref_data, ref_actual_length * ref_actual_format / 8);
#else
      data_val = C_TO_XEN_STRING((char *)ref_data);
#endif
     return(XEN_LIST_5(result, C_TO_XEN_GdkAtom(ref_actual_property_type), C_TO_XEN_gint(ref_actual_format), 
                       C_TO_XEN_gint(ref_actual_length), data_val));
    }
  }
}
static XEN gxg_gdk_property_change(XEN window, XEN property, XEN type, XEN format, XEN mode, XEN data, XEN nelements)
{
  #define H_gdk_property_change "void gdk_property_change(GdkWindow* window, GdkAtom property, GdkAtom type, \
gint format, GdkPropMode mode, guchar* data, gint nelements)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_property_change", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(property), property, 2, "gdk_property_change", "GdkAtom");
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(type), type, 3, "gdk_property_change", "GdkAtom");
  XEN_ASSERT_TYPE(XEN_gint_P(format), format, 4, "gdk_property_change", "gint");
  XEN_ASSERT_TYPE(XEN_GdkPropMode_P(mode), mode, 5, "gdk_property_change", "GdkPropMode");
  XEN_ASSERT_TYPE(XEN_guchar__P(data), data, 6, "gdk_property_change", "guchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(nelements), nelements, 7, "gdk_property_change", "gint");
  gdk_property_change(XEN_TO_C_GdkWindow_(window), XEN_TO_C_GdkAtom(property), XEN_TO_C_GdkAtom(type), XEN_TO_C_gint(format), 
                      XEN_TO_C_GdkPropMode(mode), XEN_TO_C_guchar_(data), XEN_TO_C_gint(nelements));
  return(XEN_FALSE);
}
static XEN gxg_gdk_property_delete(XEN window, XEN property)
{
  #define H_gdk_property_delete "void gdk_property_delete(GdkWindow* window, GdkAtom property)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_property_delete", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(property), property, 2, "gdk_property_delete", "GdkAtom");
  gdk_property_delete(XEN_TO_C_GdkWindow_(window), XEN_TO_C_GdkAtom(property));
  return(XEN_FALSE);
}
static XEN gxg_gdk_utf8_to_string_target(XEN str)
{
  #define H_gdk_utf8_to_string_target "gchar* gdk_utf8_to_string_target(gchar* str)"
  XEN_ASSERT_TYPE(XEN_gchar__P(str), str, 1, "gdk_utf8_to_string_target", "gchar*");
  return(C_TO_XEN_gchar_(gdk_utf8_to_string_target(XEN_TO_C_gchar_(str))));
}
static XEN gxg_gdk_region_new(void)
{
  #define H_gdk_region_new "GdkRegion* gdk_region_new( void)"
  return(C_TO_XEN_GdkRegion_(gdk_region_new()));
}
static XEN gxg_gdk_region_polygon(XEN points, XEN npoints, XEN fill_rule)
{
  #define H_gdk_region_polygon "GdkRegion* gdk_region_polygon(GdkPoint* points, gint npoints, GdkFillRule fill_rule)"
  XEN_ASSERT_TYPE(XEN_GdkPoint__P(points), points, 1, "gdk_region_polygon", "GdkPoint*");
  XEN_ASSERT_TYPE(XEN_gint_P(npoints), npoints, 2, "gdk_region_polygon", "gint");
  XEN_ASSERT_TYPE(XEN_GdkFillRule_P(fill_rule), fill_rule, 3, "gdk_region_polygon", "GdkFillRule");
  return(C_TO_XEN_GdkRegion_(gdk_region_polygon(XEN_TO_C_GdkPoint_(points), XEN_TO_C_gint(npoints), XEN_TO_C_GdkFillRule(fill_rule))));
}
static XEN gxg_gdk_region_copy(XEN region)
{
  #define H_gdk_region_copy "GdkRegion* gdk_region_copy(GdkRegion* region)"
  XEN_ASSERT_TYPE(XEN_GdkRegion__P(region), region, 1, "gdk_region_copy", "GdkRegion*");
  return(C_TO_XEN_GdkRegion_(gdk_region_copy(XEN_TO_C_GdkRegion_(region))));
}
static XEN gxg_gdk_region_rectangle(XEN rectangle)
{
  #define H_gdk_region_rectangle "GdkRegion* gdk_region_rectangle(GdkRectangle* rectangle)"
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(rectangle), rectangle, 1, "gdk_region_rectangle", "GdkRectangle*");
  return(C_TO_XEN_GdkRegion_(gdk_region_rectangle(XEN_TO_C_GdkRectangle_(rectangle))));
}
static XEN gxg_gdk_region_destroy(XEN region)
{
  #define H_gdk_region_destroy "void gdk_region_destroy(GdkRegion* region)"
  XEN_ASSERT_TYPE(XEN_GdkRegion__P(region), region, 1, "gdk_region_destroy", "GdkRegion*");
  gdk_region_destroy(XEN_TO_C_GdkRegion_(region));
  return(XEN_FALSE);
}
static XEN gxg_gdk_region_get_clipbox(XEN region, XEN rectangle)
{
  #define H_gdk_region_get_clipbox "void gdk_region_get_clipbox(GdkRegion* region, GdkRectangle* rectangle)"
  XEN_ASSERT_TYPE(XEN_GdkRegion__P(region), region, 1, "gdk_region_get_clipbox", "GdkRegion*");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(rectangle), rectangle, 2, "gdk_region_get_clipbox", "GdkRectangle*");
  gdk_region_get_clipbox(XEN_TO_C_GdkRegion_(region), XEN_TO_C_GdkRectangle_(rectangle));
  return(XEN_FALSE);
}
static XEN gxg_gdk_region_get_rectangles(XEN region, XEN rectangles, XEN n_rectangles)
{
  #define H_gdk_region_get_rectangles "void gdk_region_get_rectangles(GdkRegion* region, GdkRectangle** [rectangles], \
gint* [n_rectangles])"
  GdkRectangle* ref_rectangles = NULL;
  gint ref_n_rectangles;
  XEN_ASSERT_TYPE(XEN_GdkRegion__P(region), region, 1, "gdk_region_get_rectangles", "GdkRegion*");
  gdk_region_get_rectangles(XEN_TO_C_GdkRegion_(region), &ref_rectangles, &ref_n_rectangles);
  return(XEN_LIST_2(C_TO_XEN_GdkRectangle_(ref_rectangles), C_TO_XEN_gint(ref_n_rectangles)));
}
static XEN gxg_gdk_region_empty(XEN region)
{
  #define H_gdk_region_empty "gboolean gdk_region_empty(GdkRegion* region)"
  XEN_ASSERT_TYPE(XEN_GdkRegion__P(region), region, 1, "gdk_region_empty", "GdkRegion*");
  return(C_TO_XEN_gboolean(gdk_region_empty(XEN_TO_C_GdkRegion_(region))));
}
static XEN gxg_gdk_region_equal(XEN region1, XEN region2)
{
  #define H_gdk_region_equal "gboolean gdk_region_equal(GdkRegion* region1, GdkRegion* region2)"
  XEN_ASSERT_TYPE(XEN_GdkRegion__P(region1), region1, 1, "gdk_region_equal", "GdkRegion*");
  XEN_ASSERT_TYPE(XEN_GdkRegion__P(region2), region2, 2, "gdk_region_equal", "GdkRegion*");
  return(C_TO_XEN_gboolean(gdk_region_equal(XEN_TO_C_GdkRegion_(region1), XEN_TO_C_GdkRegion_(region2))));
}
static XEN gxg_gdk_region_point_in(XEN region, XEN x, XEN y)
{
  #define H_gdk_region_point_in "gboolean gdk_region_point_in(GdkRegion* region, int x, int y)"
  XEN_ASSERT_TYPE(XEN_GdkRegion__P(region), region, 1, "gdk_region_point_in", "GdkRegion*");
  XEN_ASSERT_TYPE(XEN_int_P(x), x, 2, "gdk_region_point_in", "int");
  XEN_ASSERT_TYPE(XEN_int_P(y), y, 3, "gdk_region_point_in", "int");
  return(C_TO_XEN_gboolean(gdk_region_point_in(XEN_TO_C_GdkRegion_(region), XEN_TO_C_int(x), XEN_TO_C_int(y))));
}
static XEN gxg_gdk_region_rect_in(XEN region, XEN rect)
{
  #define H_gdk_region_rect_in "GdkOverlapType gdk_region_rect_in(GdkRegion* region, GdkRectangle* rect)"
  XEN_ASSERT_TYPE(XEN_GdkRegion__P(region), region, 1, "gdk_region_rect_in", "GdkRegion*");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(rect), rect, 2, "gdk_region_rect_in", "GdkRectangle*");
  return(C_TO_XEN_GdkOverlapType(gdk_region_rect_in(XEN_TO_C_GdkRegion_(region), XEN_TO_C_GdkRectangle_(rect))));
}
static XEN gxg_gdk_region_offset(XEN region, XEN dx, XEN dy)
{
  #define H_gdk_region_offset "void gdk_region_offset(GdkRegion* region, gint dx, gint dy)"
  XEN_ASSERT_TYPE(XEN_GdkRegion__P(region), region, 1, "gdk_region_offset", "GdkRegion*");
  XEN_ASSERT_TYPE(XEN_gint_P(dx), dx, 2, "gdk_region_offset", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(dy), dy, 3, "gdk_region_offset", "gint");
  gdk_region_offset(XEN_TO_C_GdkRegion_(region), XEN_TO_C_gint(dx), XEN_TO_C_gint(dy));
  return(XEN_FALSE);
}
static XEN gxg_gdk_region_shrink(XEN region, XEN dx, XEN dy)
{
  #define H_gdk_region_shrink "void gdk_region_shrink(GdkRegion* region, gint dx, gint dy)"
  XEN_ASSERT_TYPE(XEN_GdkRegion__P(region), region, 1, "gdk_region_shrink", "GdkRegion*");
  XEN_ASSERT_TYPE(XEN_gint_P(dx), dx, 2, "gdk_region_shrink", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(dy), dy, 3, "gdk_region_shrink", "gint");
  gdk_region_shrink(XEN_TO_C_GdkRegion_(region), XEN_TO_C_gint(dx), XEN_TO_C_gint(dy));
  return(XEN_FALSE);
}
static XEN gxg_gdk_region_union_with_rect(XEN region, XEN rect)
{
  #define H_gdk_region_union_with_rect "void gdk_region_union_with_rect(GdkRegion* region, GdkRectangle* rect)"
  XEN_ASSERT_TYPE(XEN_GdkRegion__P(region), region, 1, "gdk_region_union_with_rect", "GdkRegion*");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(rect), rect, 2, "gdk_region_union_with_rect", "GdkRectangle*");
  gdk_region_union_with_rect(XEN_TO_C_GdkRegion_(region), XEN_TO_C_GdkRectangle_(rect));
  return(XEN_FALSE);
}
static XEN gxg_gdk_region_intersect(XEN source1, XEN source2)
{
  #define H_gdk_region_intersect "void gdk_region_intersect(GdkRegion* source1, GdkRegion* source2)"
  XEN_ASSERT_TYPE(XEN_GdkRegion__P(source1), source1, 1, "gdk_region_intersect", "GdkRegion*");
  XEN_ASSERT_TYPE(XEN_GdkRegion__P(source2), source2, 2, "gdk_region_intersect", "GdkRegion*");
  gdk_region_intersect(XEN_TO_C_GdkRegion_(source1), XEN_TO_C_GdkRegion_(source2));
  return(XEN_FALSE);
}
static XEN gxg_gdk_region_union(XEN source1, XEN source2)
{
  #define H_gdk_region_union "void gdk_region_union(GdkRegion* source1, GdkRegion* source2)"
  XEN_ASSERT_TYPE(XEN_GdkRegion__P(source1), source1, 1, "gdk_region_union", "GdkRegion*");
  XEN_ASSERT_TYPE(XEN_GdkRegion__P(source2), source2, 2, "gdk_region_union", "GdkRegion*");
  gdk_region_union(XEN_TO_C_GdkRegion_(source1), XEN_TO_C_GdkRegion_(source2));
  return(XEN_FALSE);
}
static XEN gxg_gdk_region_subtract(XEN source1, XEN source2)
{
  #define H_gdk_region_subtract "void gdk_region_subtract(GdkRegion* source1, GdkRegion* source2)"
  XEN_ASSERT_TYPE(XEN_GdkRegion__P(source1), source1, 1, "gdk_region_subtract", "GdkRegion*");
  XEN_ASSERT_TYPE(XEN_GdkRegion__P(source2), source2, 2, "gdk_region_subtract", "GdkRegion*");
  gdk_region_subtract(XEN_TO_C_GdkRegion_(source1), XEN_TO_C_GdkRegion_(source2));
  return(XEN_FALSE);
}
static XEN gxg_gdk_region_xor(XEN source1, XEN source2)
{
  #define H_gdk_region_xor "void gdk_region_xor(GdkRegion* source1, GdkRegion* source2)"
  XEN_ASSERT_TYPE(XEN_GdkRegion__P(source1), source1, 1, "gdk_region_xor", "GdkRegion*");
  XEN_ASSERT_TYPE(XEN_GdkRegion__P(source2), source2, 2, "gdk_region_xor", "GdkRegion*");
  gdk_region_xor(XEN_TO_C_GdkRegion_(source1), XEN_TO_C_GdkRegion_(source2));
  return(XEN_FALSE);
}
static XEN gxg_gdk_rgb_find_color(XEN colormap, XEN color)
{
  #define H_gdk_rgb_find_color "void gdk_rgb_find_color(GdkColormap* colormap, GdkColor* color)"
  XEN_ASSERT_TYPE(XEN_GdkColormap__P(colormap), colormap, 1, "gdk_rgb_find_color", "GdkColormap*");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(color), color, 2, "gdk_rgb_find_color", "GdkColor*");
  gdk_rgb_find_color(XEN_TO_C_GdkColormap_(colormap), XEN_TO_C_GdkColor_(color));
  return(XEN_FALSE);
}
static XEN gxg_gdk_draw_rgb_image(XEN drawable, XEN gc, XEN x, XEN y, XEN width, XEN height, XEN dith, XEN rgb_buf, XEN rowstride)
{
  #define H_gdk_draw_rgb_image "void gdk_draw_rgb_image(GdkDrawable* drawable, GdkGC* gc, gint x, gint y, \
gint width, gint height, GdkRgbDither dith, guchar* rgb_buf, gint rowstride)"
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_draw_rgb_image", "GdkDrawable*");
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 2, "gdk_draw_rgb_image", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 3, "gdk_draw_rgb_image", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 4, "gdk_draw_rgb_image", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 5, "gdk_draw_rgb_image", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 6, "gdk_draw_rgb_image", "gint");
  XEN_ASSERT_TYPE(XEN_GdkRgbDither_P(dith), dith, 7, "gdk_draw_rgb_image", "GdkRgbDither");
  XEN_ASSERT_TYPE(XEN_guchar__P(rgb_buf), rgb_buf, 8, "gdk_draw_rgb_image", "guchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(rowstride), rowstride, 9, "gdk_draw_rgb_image", "gint");
  gdk_draw_rgb_image(XEN_TO_C_GdkDrawable_(drawable), XEN_TO_C_GdkGC_(gc), XEN_TO_C_gint(x), XEN_TO_C_gint(y), XEN_TO_C_gint(width), 
                     XEN_TO_C_gint(height), XEN_TO_C_GdkRgbDither(dith), XEN_TO_C_guchar_(rgb_buf), XEN_TO_C_gint(rowstride));
  return(XEN_FALSE);
}
static XEN gxg_gdk_draw_rgb_image_dithalign(XEN arglist)
{
  #define H_gdk_draw_rgb_image_dithalign "void gdk_draw_rgb_image_dithalign(GdkDrawable* drawable, GdkGC* gc, \
gint x, gint y, gint width, gint height, GdkRgbDither dith, guchar* rgb_buf, gint rowstride, gint xdith, \
gint ydith)"
  XEN drawable, gc, x, y, width, height, dith, rgb_buf, rowstride, xdith, ydith;
  drawable = XEN_LIST_REF(arglist, 0);
  gc = XEN_LIST_REF(arglist, 1);
  x = XEN_LIST_REF(arglist, 2);
  y = XEN_LIST_REF(arglist, 3);
  width = XEN_LIST_REF(arglist, 4);
  height = XEN_LIST_REF(arglist, 5);
  dith = XEN_LIST_REF(arglist, 6);
  rgb_buf = XEN_LIST_REF(arglist, 7);
  rowstride = XEN_LIST_REF(arglist, 8);
  xdith = XEN_LIST_REF(arglist, 9);
  ydith = XEN_LIST_REF(arglist, 10);
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_draw_rgb_image_dithalign", "GdkDrawable*");
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 2, "gdk_draw_rgb_image_dithalign", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 3, "gdk_draw_rgb_image_dithalign", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 4, "gdk_draw_rgb_image_dithalign", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 5, "gdk_draw_rgb_image_dithalign", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 6, "gdk_draw_rgb_image_dithalign", "gint");
  XEN_ASSERT_TYPE(XEN_GdkRgbDither_P(dith), dith, 7, "gdk_draw_rgb_image_dithalign", "GdkRgbDither");
  XEN_ASSERT_TYPE(XEN_guchar__P(rgb_buf), rgb_buf, 8, "gdk_draw_rgb_image_dithalign", "guchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(rowstride), rowstride, 9, "gdk_draw_rgb_image_dithalign", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(xdith), xdith, 10, "gdk_draw_rgb_image_dithalign", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(ydith), ydith, 11, "gdk_draw_rgb_image_dithalign", "gint");
  gdk_draw_rgb_image_dithalign(XEN_TO_C_GdkDrawable_(drawable), XEN_TO_C_GdkGC_(gc), XEN_TO_C_gint(x), XEN_TO_C_gint(y), 
                               XEN_TO_C_gint(width), XEN_TO_C_gint(height), XEN_TO_C_GdkRgbDither(dith), XEN_TO_C_guchar_(rgb_buf), 
                               XEN_TO_C_gint(rowstride), XEN_TO_C_gint(xdith), XEN_TO_C_gint(ydith));
  return(xen_return_first(XEN_FALSE, arglist));
}
static XEN gxg_gdk_draw_rgb_32_image(XEN drawable, XEN gc, XEN x, XEN y, XEN width, XEN height, XEN dith, XEN buf, XEN rowstride)
{
  #define H_gdk_draw_rgb_32_image "void gdk_draw_rgb_32_image(GdkDrawable* drawable, GdkGC* gc, gint x, \
gint y, gint width, gint height, GdkRgbDither dith, guchar* buf, gint rowstride)"
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_draw_rgb_32_image", "GdkDrawable*");
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 2, "gdk_draw_rgb_32_image", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 3, "gdk_draw_rgb_32_image", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 4, "gdk_draw_rgb_32_image", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 5, "gdk_draw_rgb_32_image", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 6, "gdk_draw_rgb_32_image", "gint");
  XEN_ASSERT_TYPE(XEN_GdkRgbDither_P(dith), dith, 7, "gdk_draw_rgb_32_image", "GdkRgbDither");
  XEN_ASSERT_TYPE(XEN_guchar__P(buf), buf, 8, "gdk_draw_rgb_32_image", "guchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(rowstride), rowstride, 9, "gdk_draw_rgb_32_image", "gint");
  gdk_draw_rgb_32_image(XEN_TO_C_GdkDrawable_(drawable), XEN_TO_C_GdkGC_(gc), XEN_TO_C_gint(x), XEN_TO_C_gint(y), XEN_TO_C_gint(width), 
                        XEN_TO_C_gint(height), XEN_TO_C_GdkRgbDither(dith), XEN_TO_C_guchar_(buf), XEN_TO_C_gint(rowstride));
  return(XEN_FALSE);
}
static XEN gxg_gdk_draw_rgb_32_image_dithalign(XEN arglist)
{
  #define H_gdk_draw_rgb_32_image_dithalign "void gdk_draw_rgb_32_image_dithalign(GdkDrawable* drawable, \
GdkGC* gc, gint x, gint y, gint width, gint height, GdkRgbDither dith, guchar* buf, gint rowstride, gint xdith, \
gint ydith)"
  XEN drawable, gc, x, y, width, height, dith, buf, rowstride, xdith, ydith;
  drawable = XEN_LIST_REF(arglist, 0);
  gc = XEN_LIST_REF(arglist, 1);
  x = XEN_LIST_REF(arglist, 2);
  y = XEN_LIST_REF(arglist, 3);
  width = XEN_LIST_REF(arglist, 4);
  height = XEN_LIST_REF(arglist, 5);
  dith = XEN_LIST_REF(arglist, 6);
  buf = XEN_LIST_REF(arglist, 7);
  rowstride = XEN_LIST_REF(arglist, 8);
  xdith = XEN_LIST_REF(arglist, 9);
  ydith = XEN_LIST_REF(arglist, 10);
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_draw_rgb_32_image_dithalign", "GdkDrawable*");
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 2, "gdk_draw_rgb_32_image_dithalign", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 3, "gdk_draw_rgb_32_image_dithalign", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 4, "gdk_draw_rgb_32_image_dithalign", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 5, "gdk_draw_rgb_32_image_dithalign", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 6, "gdk_draw_rgb_32_image_dithalign", "gint");
  XEN_ASSERT_TYPE(XEN_GdkRgbDither_P(dith), dith, 7, "gdk_draw_rgb_32_image_dithalign", "GdkRgbDither");
  XEN_ASSERT_TYPE(XEN_guchar__P(buf), buf, 8, "gdk_draw_rgb_32_image_dithalign", "guchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(rowstride), rowstride, 9, "gdk_draw_rgb_32_image_dithalign", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(xdith), xdith, 10, "gdk_draw_rgb_32_image_dithalign", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(ydith), ydith, 11, "gdk_draw_rgb_32_image_dithalign", "gint");
  gdk_draw_rgb_32_image_dithalign(XEN_TO_C_GdkDrawable_(drawable), XEN_TO_C_GdkGC_(gc), XEN_TO_C_gint(x), XEN_TO_C_gint(y), 
                                  XEN_TO_C_gint(width), XEN_TO_C_gint(height), XEN_TO_C_GdkRgbDither(dith), XEN_TO_C_guchar_(buf), 
                                  XEN_TO_C_gint(rowstride), XEN_TO_C_gint(xdith), XEN_TO_C_gint(ydith));
  return(xen_return_first(XEN_FALSE, arglist));
}
static XEN gxg_gdk_draw_gray_image(XEN drawable, XEN gc, XEN x, XEN y, XEN width, XEN height, XEN dith, XEN buf, XEN rowstride)
{
  #define H_gdk_draw_gray_image "void gdk_draw_gray_image(GdkDrawable* drawable, GdkGC* gc, gint x, gint y, \
gint width, gint height, GdkRgbDither dith, guchar* buf, gint rowstride)"
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_draw_gray_image", "GdkDrawable*");
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 2, "gdk_draw_gray_image", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 3, "gdk_draw_gray_image", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 4, "gdk_draw_gray_image", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 5, "gdk_draw_gray_image", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 6, "gdk_draw_gray_image", "gint");
  XEN_ASSERT_TYPE(XEN_GdkRgbDither_P(dith), dith, 7, "gdk_draw_gray_image", "GdkRgbDither");
  XEN_ASSERT_TYPE(XEN_guchar__P(buf), buf, 8, "gdk_draw_gray_image", "guchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(rowstride), rowstride, 9, "gdk_draw_gray_image", "gint");
  gdk_draw_gray_image(XEN_TO_C_GdkDrawable_(drawable), XEN_TO_C_GdkGC_(gc), XEN_TO_C_gint(x), XEN_TO_C_gint(y), XEN_TO_C_gint(width), 
                      XEN_TO_C_gint(height), XEN_TO_C_GdkRgbDither(dith), XEN_TO_C_guchar_(buf), XEN_TO_C_gint(rowstride));
  return(XEN_FALSE);
}
static XEN gxg_gdk_draw_indexed_image(XEN arglist)
{
  #define H_gdk_draw_indexed_image "void gdk_draw_indexed_image(GdkDrawable* drawable, GdkGC* gc, gint x, \
gint y, gint width, gint height, GdkRgbDither dith, guchar* buf, gint rowstride, GdkRgbCmap* cmap)"
  XEN drawable, gc, x, y, width, height, dith, buf, rowstride, cmap;
  drawable = XEN_LIST_REF(arglist, 0);
  gc = XEN_LIST_REF(arglist, 1);
  x = XEN_LIST_REF(arglist, 2);
  y = XEN_LIST_REF(arglist, 3);
  width = XEN_LIST_REF(arglist, 4);
  height = XEN_LIST_REF(arglist, 5);
  dith = XEN_LIST_REF(arglist, 6);
  buf = XEN_LIST_REF(arglist, 7);
  rowstride = XEN_LIST_REF(arglist, 8);
  cmap = XEN_LIST_REF(arglist, 9);
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_draw_indexed_image", "GdkDrawable*");
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 2, "gdk_draw_indexed_image", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 3, "gdk_draw_indexed_image", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 4, "gdk_draw_indexed_image", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 5, "gdk_draw_indexed_image", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 6, "gdk_draw_indexed_image", "gint");
  XEN_ASSERT_TYPE(XEN_GdkRgbDither_P(dith), dith, 7, "gdk_draw_indexed_image", "GdkRgbDither");
  XEN_ASSERT_TYPE(XEN_guchar__P(buf), buf, 8, "gdk_draw_indexed_image", "guchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(rowstride), rowstride, 9, "gdk_draw_indexed_image", "gint");
  XEN_ASSERT_TYPE(XEN_GdkRgbCmap__P(cmap), cmap, 10, "gdk_draw_indexed_image", "GdkRgbCmap*");
  gdk_draw_indexed_image(XEN_TO_C_GdkDrawable_(drawable), XEN_TO_C_GdkGC_(gc), XEN_TO_C_gint(x), XEN_TO_C_gint(y), XEN_TO_C_gint(width), 
                         XEN_TO_C_gint(height), XEN_TO_C_GdkRgbDither(dith), XEN_TO_C_guchar_(buf), XEN_TO_C_gint(rowstride), 
                         XEN_TO_C_GdkRgbCmap_(cmap));
  return(xen_return_first(XEN_FALSE, arglist));
}
static XEN gxg_gdk_rgb_cmap_new(XEN colors, XEN n_colors)
{
  #define H_gdk_rgb_cmap_new "GdkRgbCmap* gdk_rgb_cmap_new(guint32* colors, gint n_colors)"
  XEN_ASSERT_TYPE(XEN_guint32__P(colors), colors, 1, "gdk_rgb_cmap_new", "guint32*");
  XEN_ASSERT_TYPE(XEN_gint_P(n_colors), n_colors, 2, "gdk_rgb_cmap_new", "gint");
  return(C_TO_XEN_GdkRgbCmap_(gdk_rgb_cmap_new(XEN_TO_C_guint32_(colors), XEN_TO_C_gint(n_colors))));
}
static XEN gxg_gdk_rgb_cmap_free(XEN cmap)
{
  #define H_gdk_rgb_cmap_free "void gdk_rgb_cmap_free(GdkRgbCmap* cmap)"
  XEN_ASSERT_TYPE(XEN_GdkRgbCmap__P(cmap), cmap, 1, "gdk_rgb_cmap_free", "GdkRgbCmap*");
  gdk_rgb_cmap_free(XEN_TO_C_GdkRgbCmap_(cmap));
  return(XEN_FALSE);
}
static XEN gxg_gdk_rgb_ditherable(void)
{
  #define H_gdk_rgb_ditherable "gboolean gdk_rgb_ditherable( void)"
  return(C_TO_XEN_gboolean(gdk_rgb_ditherable()));
}
static XEN gxg_gdk_rgb_set_verbose(XEN verbose)
{
  #define H_gdk_rgb_set_verbose "void gdk_rgb_set_verbose(gboolean verbose)"
  XEN_ASSERT_TYPE(XEN_gboolean_P(verbose), verbose, 1, "gdk_rgb_set_verbose", "gboolean");
  gdk_rgb_set_verbose(XEN_TO_C_gboolean(verbose));
  return(XEN_FALSE);
}
static XEN gxg_gdk_rgb_set_install(XEN install)
{
  #define H_gdk_rgb_set_install "void gdk_rgb_set_install(gboolean install)"
  XEN_ASSERT_TYPE(XEN_gboolean_P(install), install, 1, "gdk_rgb_set_install", "gboolean");
  gdk_rgb_set_install(XEN_TO_C_gboolean(install));
  return(XEN_FALSE);
}
static XEN gxg_gdk_rgb_set_min_colors(XEN min_colors)
{
  #define H_gdk_rgb_set_min_colors "void gdk_rgb_set_min_colors(gint min_colors)"
  XEN_ASSERT_TYPE(XEN_gint_P(min_colors), min_colors, 1, "gdk_rgb_set_min_colors", "gint");
  gdk_rgb_set_min_colors(XEN_TO_C_gint(min_colors));
  return(XEN_FALSE);
}
static XEN gxg_gdk_rgb_get_colormap(void)
{
  #define H_gdk_rgb_get_colormap "GdkColormap* gdk_rgb_get_colormap( void)"
  return(C_TO_XEN_GdkColormap_(gdk_rgb_get_colormap()));
}
static XEN gxg_gdk_rgb_get_visual(void)
{
  #define H_gdk_rgb_get_visual "GdkVisual* gdk_rgb_get_visual( void)"
  return(C_TO_XEN_GdkVisual_(gdk_rgb_get_visual()));
}
static XEN gxg_gdk_selection_owner_set(XEN owner, XEN selection, XEN time, XEN send_event)
{
  #define H_gdk_selection_owner_set "gboolean gdk_selection_owner_set(GdkWindow* owner, GdkAtom selection, \
guint32 time, gboolean send_event)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(owner), owner, 1, "gdk_selection_owner_set", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(selection), selection, 2, "gdk_selection_owner_set", "GdkAtom");
  XEN_ASSERT_TYPE(XEN_guint32_P(time), time, 3, "gdk_selection_owner_set", "guint32");
  XEN_ASSERT_TYPE(XEN_gboolean_P(send_event), send_event, 4, "gdk_selection_owner_set", "gboolean");
  return(C_TO_XEN_gboolean(gdk_selection_owner_set(XEN_TO_C_GdkWindow_(owner), XEN_TO_C_GdkAtom(selection), XEN_TO_C_guint32(time), 
                                                   XEN_TO_C_gboolean(send_event))));
}
static XEN gxg_gdk_selection_owner_get(XEN selection)
{
  #define H_gdk_selection_owner_get "GdkWindow* gdk_selection_owner_get(GdkAtom selection)"
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(selection), selection, 1, "gdk_selection_owner_get", "GdkAtom");
  return(C_TO_XEN_GdkWindow_(gdk_selection_owner_get(XEN_TO_C_GdkAtom(selection))));
}
static XEN gxg_gdk_selection_convert(XEN requestor, XEN selection, XEN target, XEN time)
{
  #define H_gdk_selection_convert "void gdk_selection_convert(GdkWindow* requestor, GdkAtom selection, \
GdkAtom target, guint32 time)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(requestor), requestor, 1, "gdk_selection_convert", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(selection), selection, 2, "gdk_selection_convert", "GdkAtom");
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(target), target, 3, "gdk_selection_convert", "GdkAtom");
  XEN_ASSERT_TYPE(XEN_guint32_P(time), time, 4, "gdk_selection_convert", "guint32");
  gdk_selection_convert(XEN_TO_C_GdkWindow_(requestor), XEN_TO_C_GdkAtom(selection), XEN_TO_C_GdkAtom(target), XEN_TO_C_guint32(time));
  return(XEN_FALSE);
}
static XEN gxg_gdk_selection_property_get(XEN requestor, XEN data, XEN prop_type, XEN prop_format)
{
  #define H_gdk_selection_property_get "gboolean gdk_selection_property_get(GdkWindow* requestor, guchar** [data], \
GdkAtom* [prop_type], gint* [prop_format])"
  guchar* ref_data = NULL;
  GdkAtom ref_prop_type;
  gint ref_prop_format;
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(requestor), requestor, 1, "gdk_selection_property_get", "GdkWindow*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gdk_selection_property_get(XEN_TO_C_GdkWindow_(requestor), &ref_data, &ref_prop_type, &ref_prop_format));
    return(XEN_LIST_4(result, C_TO_XEN_guchar_(ref_data), C_TO_XEN_GdkAtom(ref_prop_type), C_TO_XEN_gint(ref_prop_format)));
   }
}
static XEN gxg_gdk_selection_send_notify(XEN requestor, XEN selection, XEN target, XEN property, XEN time)
{
  #define H_gdk_selection_send_notify "void gdk_selection_send_notify(guint32 requestor, GdkAtom selection, \
GdkAtom target, GdkAtom property, guint32 time)"
  XEN_ASSERT_TYPE(XEN_guint32_P(requestor), requestor, 1, "gdk_selection_send_notify", "guint32");
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(selection), selection, 2, "gdk_selection_send_notify", "GdkAtom");
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(target), target, 3, "gdk_selection_send_notify", "GdkAtom");
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(property), property, 4, "gdk_selection_send_notify", "GdkAtom");
  XEN_ASSERT_TYPE(XEN_guint32_P(time), time, 5, "gdk_selection_send_notify", "guint32");
  gdk_selection_send_notify(XEN_TO_C_guint32(requestor), XEN_TO_C_GdkAtom(selection), XEN_TO_C_GdkAtom(target), XEN_TO_C_GdkAtom(property), 
                            XEN_TO_C_guint32(time));
  return(XEN_FALSE);
}
static XEN gxg_gdk_visual_get_type(void)
{
  #define H_gdk_visual_get_type "GType gdk_visual_get_type( void)"
  return(C_TO_XEN_GType(gdk_visual_get_type()));
}
static XEN gxg_gdk_visual_get_best_depth(void)
{
  #define H_gdk_visual_get_best_depth "gint gdk_visual_get_best_depth( void)"
  return(C_TO_XEN_gint(gdk_visual_get_best_depth()));
}
static XEN gxg_gdk_visual_get_best_type(void)
{
  #define H_gdk_visual_get_best_type "GdkVisualType gdk_visual_get_best_type( void)"
  return(C_TO_XEN_GdkVisualType(gdk_visual_get_best_type()));
}
static XEN gxg_gdk_visual_get_system(void)
{
  #define H_gdk_visual_get_system "GdkVisual* gdk_visual_get_system( void)"
  return(C_TO_XEN_GdkVisual_(gdk_visual_get_system()));
}
static XEN gxg_gdk_visual_get_best(void)
{
  #define H_gdk_visual_get_best "GdkVisual* gdk_visual_get_best( void)"
  return(C_TO_XEN_GdkVisual_(gdk_visual_get_best()));
}
static XEN gxg_gdk_visual_get_best_with_depth(XEN depth)
{
  #define H_gdk_visual_get_best_with_depth "GdkVisual* gdk_visual_get_best_with_depth(gint depth)"
  XEN_ASSERT_TYPE(XEN_gint_P(depth), depth, 1, "gdk_visual_get_best_with_depth", "gint");
  return(C_TO_XEN_GdkVisual_(gdk_visual_get_best_with_depth(XEN_TO_C_gint(depth))));
}
static XEN gxg_gdk_visual_get_best_with_type(XEN visual_type)
{
  #define H_gdk_visual_get_best_with_type "GdkVisual* gdk_visual_get_best_with_type(GdkVisualType visual_type)"
  XEN_ASSERT_TYPE(XEN_GdkVisualType_P(visual_type), visual_type, 1, "gdk_visual_get_best_with_type", "GdkVisualType");
  return(C_TO_XEN_GdkVisual_(gdk_visual_get_best_with_type(XEN_TO_C_GdkVisualType(visual_type))));
}
static XEN gxg_gdk_visual_get_best_with_both(XEN depth, XEN visual_type)
{
  #define H_gdk_visual_get_best_with_both "GdkVisual* gdk_visual_get_best_with_both(gint depth, GdkVisualType visual_type)"
  XEN_ASSERT_TYPE(XEN_gint_P(depth), depth, 1, "gdk_visual_get_best_with_both", "gint");
  XEN_ASSERT_TYPE(XEN_GdkVisualType_P(visual_type), visual_type, 2, "gdk_visual_get_best_with_both", "GdkVisualType");
  return(C_TO_XEN_GdkVisual_(gdk_visual_get_best_with_both(XEN_TO_C_gint(depth), XEN_TO_C_GdkVisualType(visual_type))));
}
static XEN gxg_gdk_query_depths(XEN depths, XEN count)
{
  #define H_gdk_query_depths "void gdk_query_depths(gint** [depths], gint* [count])"
  gint* ref_depths = NULL;
  gint ref_count;
  gdk_query_depths(&ref_depths, &ref_count);
  return(XEN_LIST_2(C_TO_XEN_gint_(ref_depths), C_TO_XEN_gint(ref_count)));
}
static XEN gxg_gdk_query_visual_types(XEN visual_types, XEN count)
{
  #define H_gdk_query_visual_types "void gdk_query_visual_types(GdkVisualType** [visual_types], gint* [count])"
  GdkVisualType* ref_visual_types = NULL;
  gint ref_count;
  gdk_query_visual_types(&ref_visual_types, &ref_count);
  return(XEN_LIST_2(C_TO_XEN_GdkVisualType_(ref_visual_types), C_TO_XEN_gint(ref_count)));
}
static XEN gxg_gdk_list_visuals(void)
{
  #define H_gdk_list_visuals "GList* gdk_list_visuals( void)"
  return(C_TO_XEN_GList_(gdk_list_visuals()));
}
static XEN gxg_gdk_window_new(XEN parent, XEN attributes, XEN attributes_mask)
{
  #define H_gdk_window_new "GdkWindow* gdk_window_new(GdkWindow* parent, GdkWindowAttr* attributes, gint attributes_mask)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(parent), parent, 1, "gdk_window_new", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkWindowAttr__P(attributes), attributes, 2, "gdk_window_new", "GdkWindowAttr*");
  XEN_ASSERT_TYPE(XEN_gint_P(attributes_mask), attributes_mask, 3, "gdk_window_new", "gint");
  return(C_TO_XEN_GdkWindow_(gdk_window_new(XEN_TO_C_GdkWindow_(parent), XEN_TO_C_GdkWindowAttr_(attributes), XEN_TO_C_gint(attributes_mask))));
}
static XEN gxg_gdk_window_destroy(XEN window)
{
  #define H_gdk_window_destroy "void gdk_window_destroy(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_destroy", "GdkWindow*");
  gdk_window_destroy(XEN_TO_C_GdkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_get_window_type(XEN window)
{
  #define H_gdk_window_get_window_type "GdkWindowType gdk_window_get_window_type(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_get_window_type", "GdkWindow*");
  return(C_TO_XEN_GdkWindowType(gdk_window_get_window_type(XEN_TO_C_GdkWindow_(window))));
}
static XEN gxg_gdk_window_at_pointer(XEN win_x, XEN win_y)
{
  #define H_gdk_window_at_pointer "GdkWindow* gdk_window_at_pointer(gint* [win_x], gint* [win_y])"
  gint ref_win_x;
  gint ref_win_y;
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_GdkWindow_(gdk_window_at_pointer(&ref_win_x, &ref_win_y));
    return(XEN_LIST_3(result, C_TO_XEN_gint(ref_win_x), C_TO_XEN_gint(ref_win_y)));
   }
}
static XEN gxg_gdk_window_show(XEN window)
{
  #define H_gdk_window_show "void gdk_window_show(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_show", "GdkWindow*");
  gdk_window_show(XEN_TO_C_GdkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_hide(XEN window)
{
  #define H_gdk_window_hide "void gdk_window_hide(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_hide", "GdkWindow*");
  gdk_window_hide(XEN_TO_C_GdkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_withdraw(XEN window)
{
  #define H_gdk_window_withdraw "void gdk_window_withdraw(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_withdraw", "GdkWindow*");
  gdk_window_withdraw(XEN_TO_C_GdkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_show_unraised(XEN window)
{
  #define H_gdk_window_show_unraised "void gdk_window_show_unraised(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_show_unraised", "GdkWindow*");
  gdk_window_show_unraised(XEN_TO_C_GdkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_move(XEN window, XEN x, XEN y)
{
  #define H_gdk_window_move "void gdk_window_move(GdkWindow* window, gint x, gint y)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_move", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 2, "gdk_window_move", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 3, "gdk_window_move", "gint");
  gdk_window_move(XEN_TO_C_GdkWindow_(window), XEN_TO_C_gint(x), XEN_TO_C_gint(y));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_resize(XEN window, XEN width, XEN height)
{
  #define H_gdk_window_resize "void gdk_window_resize(GdkWindow* window, gint width, gint height)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_resize", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 2, "gdk_window_resize", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 3, "gdk_window_resize", "gint");
  gdk_window_resize(XEN_TO_C_GdkWindow_(window), XEN_TO_C_gint(width), XEN_TO_C_gint(height));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_move_resize(XEN window, XEN x, XEN y, XEN width, XEN height)
{
  #define H_gdk_window_move_resize "void gdk_window_move_resize(GdkWindow* window, gint x, gint y, gint width, \
gint height)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_move_resize", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 2, "gdk_window_move_resize", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 3, "gdk_window_move_resize", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 4, "gdk_window_move_resize", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 5, "gdk_window_move_resize", "gint");
  gdk_window_move_resize(XEN_TO_C_GdkWindow_(window), XEN_TO_C_gint(x), XEN_TO_C_gint(y), XEN_TO_C_gint(width), XEN_TO_C_gint(height));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_reparent(XEN window, XEN new_parent, XEN x, XEN y)
{
  #define H_gdk_window_reparent "void gdk_window_reparent(GdkWindow* window, GdkWindow* new_parent, gint x, \
gint y)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_reparent", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(new_parent), new_parent, 2, "gdk_window_reparent", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 3, "gdk_window_reparent", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 4, "gdk_window_reparent", "gint");
  gdk_window_reparent(XEN_TO_C_GdkWindow_(window), XEN_TO_C_GdkWindow_(new_parent), XEN_TO_C_gint(x), XEN_TO_C_gint(y));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_clear(XEN window)
{
  #define H_gdk_window_clear "void gdk_window_clear(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_clear", "GdkWindow*");
  gdk_window_clear(XEN_TO_C_GdkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_clear_area(XEN window, XEN x, XEN y, XEN width, XEN height)
{
  #define H_gdk_window_clear_area "void gdk_window_clear_area(GdkWindow* window, gint x, gint y, gint width, \
gint height)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_clear_area", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 2, "gdk_window_clear_area", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 3, "gdk_window_clear_area", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 4, "gdk_window_clear_area", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 5, "gdk_window_clear_area", "gint");
  gdk_window_clear_area(XEN_TO_C_GdkWindow_(window), XEN_TO_C_gint(x), XEN_TO_C_gint(y), XEN_TO_C_gint(width), XEN_TO_C_gint(height));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_clear_area_e(XEN window, XEN x, XEN y, XEN width, XEN height)
{
  #define H_gdk_window_clear_area_e "void gdk_window_clear_area_e(GdkWindow* window, gint x, gint y, \
gint width, gint height)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_clear_area_e", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 2, "gdk_window_clear_area_e", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 3, "gdk_window_clear_area_e", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 4, "gdk_window_clear_area_e", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 5, "gdk_window_clear_area_e", "gint");
  gdk_window_clear_area_e(XEN_TO_C_GdkWindow_(window), XEN_TO_C_gint(x), XEN_TO_C_gint(y), XEN_TO_C_gint(width), XEN_TO_C_gint(height));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_raise(XEN window)
{
  #define H_gdk_window_raise "void gdk_window_raise(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_raise", "GdkWindow*");
  gdk_window_raise(XEN_TO_C_GdkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_lower(XEN window)
{
  #define H_gdk_window_lower "void gdk_window_lower(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_lower", "GdkWindow*");
  gdk_window_lower(XEN_TO_C_GdkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_focus(XEN window, XEN timestamp)
{
  #define H_gdk_window_focus "void gdk_window_focus(GdkWindow* window, guint32 timestamp)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_focus", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_guint32_P(timestamp), timestamp, 2, "gdk_window_focus", "guint32");
  gdk_window_focus(XEN_TO_C_GdkWindow_(window), XEN_TO_C_guint32(timestamp));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_set_user_data(XEN window, XEN user_data)
{
  #define H_gdk_window_set_user_data "void gdk_window_set_user_data(GdkWindow* window, gpointer user_data)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window) || XEN_FALSE_P(window), window, 1, "gdk_window_set_user_data", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_gpointer_P(user_data), user_data, 2, "gdk_window_set_user_data", "gpointer");
  gdk_window_set_user_data(XEN_TO_C_GdkWindow_(window), XEN_TO_C_gpointer(user_data));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_set_override_redirect(XEN window, XEN override_redirect)
{
  #define H_gdk_window_set_override_redirect "void gdk_window_set_override_redirect(GdkWindow* window, \
gboolean override_redirect)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_set_override_redirect", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(override_redirect), override_redirect, 2, "gdk_window_set_override_redirect", "gboolean");
  gdk_window_set_override_redirect(XEN_TO_C_GdkWindow_(window), XEN_TO_C_gboolean(override_redirect));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_add_filter(XEN window, XEN func, XEN func_data)
{
  #define H_gdk_window_add_filter "void gdk_window_add_filter(GdkWindow* window, GdkFilterFunc func, \
lambda_data func_data)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_add_filter", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkFilterFunc_P(func), func, 2, "gdk_window_add_filter", "GdkFilterFunc");
  if (XEN_NOT_BOUND_P(func_data)) func_data = XEN_FALSE; 
  else XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 3, "gdk_window_add_filter", "lambda_data");
  {
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    xm_protect(gxg_ptr);
    gdk_window_add_filter(XEN_TO_C_GdkWindow_(window), XEN_TO_C_GdkFilterFunc(func), XEN_TO_C_lambda_data(func_data));
    return(XEN_FALSE);
   }
}
static XEN gxg_gdk_window_remove_filter(XEN window, XEN func, XEN func_data)
{
  #define H_gdk_window_remove_filter "void gdk_window_remove_filter(GdkWindow* window, GdkFilterFunc func, \
lambda_data func_data)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_remove_filter", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkFilterFunc_P(func), func, 2, "gdk_window_remove_filter", "GdkFilterFunc");
  if (XEN_NOT_BOUND_P(func_data)) func_data = XEN_FALSE; 
  else XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 3, "gdk_window_remove_filter", "lambda_data");
  {
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    xm_protect(gxg_ptr);
    gdk_window_remove_filter(XEN_TO_C_GdkWindow_(window), XEN_TO_C_GdkFilterFunc(func), XEN_TO_C_lambda_data(func_data));
    return(XEN_FALSE);
   }
}
static XEN gxg_gdk_window_scroll(XEN window, XEN dx, XEN dy)
{
  #define H_gdk_window_scroll "void gdk_window_scroll(GdkWindow* window, gint dx, gint dy)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_scroll", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_gint_P(dx), dx, 2, "gdk_window_scroll", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(dy), dy, 3, "gdk_window_scroll", "gint");
  gdk_window_scroll(XEN_TO_C_GdkWindow_(window), XEN_TO_C_gint(dx), XEN_TO_C_gint(dy));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_shape_combine_mask(XEN window, XEN mask, XEN x, XEN y)
{
  #define H_gdk_window_shape_combine_mask "void gdk_window_shape_combine_mask(GdkWindow* window, GdkBitmap* mask, \
gint x, gint y)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_shape_combine_mask", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkBitmap__P(mask), mask, 2, "gdk_window_shape_combine_mask", "GdkBitmap*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 3, "gdk_window_shape_combine_mask", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 4, "gdk_window_shape_combine_mask", "gint");
  gdk_window_shape_combine_mask(XEN_TO_C_GdkWindow_(window), XEN_TO_C_GdkBitmap_(mask), XEN_TO_C_gint(x), XEN_TO_C_gint(y));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_shape_combine_region(XEN window, XEN shape_region, XEN offset_x, XEN offset_y)
{
  #define H_gdk_window_shape_combine_region "void gdk_window_shape_combine_region(GdkWindow* window, \
GdkRegion* shape_region, gint offset_x, gint offset_y)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_shape_combine_region", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkRegion__P(shape_region), shape_region, 2, "gdk_window_shape_combine_region", "GdkRegion*");
  XEN_ASSERT_TYPE(XEN_gint_P(offset_x), offset_x, 3, "gdk_window_shape_combine_region", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(offset_y), offset_y, 4, "gdk_window_shape_combine_region", "gint");
  gdk_window_shape_combine_region(XEN_TO_C_GdkWindow_(window), XEN_TO_C_GdkRegion_(shape_region), XEN_TO_C_gint(offset_x), 
                                  XEN_TO_C_gint(offset_y));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_set_child_shapes(XEN window)
{
  #define H_gdk_window_set_child_shapes "void gdk_window_set_child_shapes(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_set_child_shapes", "GdkWindow*");
  gdk_window_set_child_shapes(XEN_TO_C_GdkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_merge_child_shapes(XEN window)
{
  #define H_gdk_window_merge_child_shapes "void gdk_window_merge_child_shapes(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_merge_child_shapes", "GdkWindow*");
  gdk_window_merge_child_shapes(XEN_TO_C_GdkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_is_visible(XEN window)
{
  #define H_gdk_window_is_visible "gboolean gdk_window_is_visible(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_is_visible", "GdkWindow*");
  return(C_TO_XEN_gboolean(gdk_window_is_visible(XEN_TO_C_GdkWindow_(window))));
}
static XEN gxg_gdk_window_is_viewable(XEN window)
{
  #define H_gdk_window_is_viewable "gboolean gdk_window_is_viewable(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_is_viewable", "GdkWindow*");
  return(C_TO_XEN_gboolean(gdk_window_is_viewable(XEN_TO_C_GdkWindow_(window))));
}
static XEN gxg_gdk_window_get_state(XEN window)
{
  #define H_gdk_window_get_state "GdkWindowState gdk_window_get_state(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_get_state", "GdkWindow*");
  return(C_TO_XEN_GdkWindowState(gdk_window_get_state(XEN_TO_C_GdkWindow_(window))));
}
static XEN gxg_gdk_window_set_static_gravities(XEN window, XEN use_static)
{
  #define H_gdk_window_set_static_gravities "gboolean gdk_window_set_static_gravities(GdkWindow* window, \
gboolean use_static)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_set_static_gravities", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(use_static), use_static, 2, "gdk_window_set_static_gravities", "gboolean");
  return(C_TO_XEN_gboolean(gdk_window_set_static_gravities(XEN_TO_C_GdkWindow_(window), XEN_TO_C_gboolean(use_static))));
}
static XEN gxg_gdk_window_foreign_new(XEN anid)
{
  #define H_gdk_window_foreign_new "GdkWindow* gdk_window_foreign_new(GdkNativeWindow anid)"
  XEN_ASSERT_TYPE(XEN_GdkNativeWindow_P(anid), anid, 1, "gdk_window_foreign_new", "GdkNativeWindow");
  return(C_TO_XEN_GdkWindow_(gdk_window_foreign_new(XEN_TO_C_GdkNativeWindow(anid))));
}
static XEN gxg_gdk_window_lookup(XEN anid)
{
  #define H_gdk_window_lookup "GdkWindow* gdk_window_lookup(GdkNativeWindow anid)"
  XEN_ASSERT_TYPE(XEN_GdkNativeWindow_P(anid), anid, 1, "gdk_window_lookup", "GdkNativeWindow");
  return(C_TO_XEN_GdkWindow_(gdk_window_lookup(XEN_TO_C_GdkNativeWindow(anid))));
}
static XEN gxg_gdk_window_get_root_origin(XEN window, XEN x, XEN y)
{
  #define H_gdk_window_get_root_origin "void gdk_window_get_root_origin(GdkWindow* window, gint* [x], \
gint* [y])"
  gint ref_x;
  gint ref_y;
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_get_root_origin", "GdkWindow*");
  gdk_window_get_root_origin(XEN_TO_C_GdkWindow_(window), &ref_x, &ref_y);
  return(XEN_LIST_2(C_TO_XEN_gint(ref_x), C_TO_XEN_gint(ref_y)));
}
static XEN gxg_gdk_window_get_frame_extents(XEN window, XEN rect)
{
  #define H_gdk_window_get_frame_extents "void gdk_window_get_frame_extents(GdkWindow* window, GdkRectangle* rect)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_get_frame_extents", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(rect), rect, 2, "gdk_window_get_frame_extents", "GdkRectangle*");
  gdk_window_get_frame_extents(XEN_TO_C_GdkWindow_(window), XEN_TO_C_GdkRectangle_(rect));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_get_pointer(XEN window, XEN x, XEN y, XEN mask)
{
  #define H_gdk_window_get_pointer "GdkWindow* gdk_window_get_pointer(GdkWindow* window, gint* [x], gint* [y], \
GdkModifierType* [mask])"
  gint ref_x;
  gint ref_y;
  GdkModifierType ref_mask;
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_get_pointer", "GdkWindow*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_GdkWindow_(gdk_window_get_pointer(XEN_TO_C_GdkWindow_(window), &ref_x, &ref_y, &ref_mask));
    return(XEN_LIST_4(result, C_TO_XEN_gint(ref_x), C_TO_XEN_gint(ref_y), C_TO_XEN_GdkModifierType(ref_mask)));
   }
}
static XEN gxg_gdk_window_get_parent(XEN window)
{
  #define H_gdk_window_get_parent "GdkWindow* gdk_window_get_parent(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_get_parent", "GdkWindow*");
  return(C_TO_XEN_GdkWindow_(gdk_window_get_parent(XEN_TO_C_GdkWindow_(window))));
}
static XEN gxg_gdk_window_get_toplevel(XEN window)
{
  #define H_gdk_window_get_toplevel "GdkWindow* gdk_window_get_toplevel(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_get_toplevel", "GdkWindow*");
  return(C_TO_XEN_GdkWindow_(gdk_window_get_toplevel(XEN_TO_C_GdkWindow_(window))));
}
static XEN gxg_gdk_window_get_children(XEN window)
{
  #define H_gdk_window_get_children "GList* gdk_window_get_children(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_get_children", "GdkWindow*");
  return(C_TO_XEN_GList_(gdk_window_get_children(XEN_TO_C_GdkWindow_(window))));
}
static XEN gxg_gdk_window_peek_children(XEN window)
{
  #define H_gdk_window_peek_children "GList* gdk_window_peek_children(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_peek_children", "GdkWindow*");
  return(C_TO_XEN_GList_(gdk_window_peek_children(XEN_TO_C_GdkWindow_(window))));
}
static XEN gxg_gdk_window_get_events(XEN window)
{
  #define H_gdk_window_get_events "GdkEventMask gdk_window_get_events(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_get_events", "GdkWindow*");
  return(C_TO_XEN_GdkEventMask(gdk_window_get_events(XEN_TO_C_GdkWindow_(window))));
}
static XEN gxg_gdk_window_set_events(XEN window, XEN event_mask)
{
  #define H_gdk_window_set_events "void gdk_window_set_events(GdkWindow* window, GdkEventMask event_mask)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_set_events", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkEventMask_P(event_mask), event_mask, 2, "gdk_window_set_events", "GdkEventMask");
  gdk_window_set_events(XEN_TO_C_GdkWindow_(window), XEN_TO_C_GdkEventMask(event_mask));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_set_icon_list(XEN window, XEN pixbufs)
{
  #define H_gdk_window_set_icon_list "void gdk_window_set_icon_list(GdkWindow* window, GList* pixbufs)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_set_icon_list", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GList__P(pixbufs), pixbufs, 2, "gdk_window_set_icon_list", "GList*");
  gdk_window_set_icon_list(XEN_TO_C_GdkWindow_(window), XEN_TO_C_GList_(pixbufs));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_set_icon(XEN window, XEN icon_window, XEN pixmap, XEN mask)
{
  #define H_gdk_window_set_icon "void gdk_window_set_icon(GdkWindow* window, GdkWindow* icon_window, \
GdkPixmap* pixmap, GdkBitmap* mask)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_set_icon", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(icon_window), icon_window, 2, "gdk_window_set_icon", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkPixmap__P(pixmap), pixmap, 3, "gdk_window_set_icon", "GdkPixmap*");
  XEN_ASSERT_TYPE(XEN_GdkBitmap__P(mask), mask, 4, "gdk_window_set_icon", "GdkBitmap*");
  gdk_window_set_icon(XEN_TO_C_GdkWindow_(window), XEN_TO_C_GdkWindow_(icon_window), XEN_TO_C_GdkPixmap_(pixmap), XEN_TO_C_GdkBitmap_(mask));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_set_icon_name(XEN window, XEN name)
{
  #define H_gdk_window_set_icon_name "void gdk_window_set_icon_name(GdkWindow* window, gchar* name)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_set_icon_name", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_gchar__P(name), name, 2, "gdk_window_set_icon_name", "gchar*");
  gdk_window_set_icon_name(XEN_TO_C_GdkWindow_(window), XEN_TO_C_gchar_(name));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_set_group(XEN window, XEN leader)
{
  #define H_gdk_window_set_group "void gdk_window_set_group(GdkWindow* window, GdkWindow* leader)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_set_group", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(leader), leader, 2, "gdk_window_set_group", "GdkWindow*");
  gdk_window_set_group(XEN_TO_C_GdkWindow_(window), XEN_TO_C_GdkWindow_(leader));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_set_decorations(XEN window, XEN decorations)
{
  #define H_gdk_window_set_decorations "void gdk_window_set_decorations(GdkWindow* window, GdkWMDecoration decorations)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_set_decorations", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkWMDecoration_P(decorations), decorations, 2, "gdk_window_set_decorations", "GdkWMDecoration");
  gdk_window_set_decorations(XEN_TO_C_GdkWindow_(window), XEN_TO_C_GdkWMDecoration(decorations));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_get_decorations(XEN window, XEN decorations)
{
  #define H_gdk_window_get_decorations "gboolean gdk_window_get_decorations(GdkWindow* window, GdkWMDecoration* [decorations])"
  GdkWMDecoration ref_decorations;
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_get_decorations", "GdkWindow*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gdk_window_get_decorations(XEN_TO_C_GdkWindow_(window), &ref_decorations));
    return(XEN_LIST_2(result, C_TO_XEN_GdkWMDecoration(ref_decorations)));
   }
}
static XEN gxg_gdk_window_set_functions(XEN window, XEN functions)
{
  #define H_gdk_window_set_functions "void gdk_window_set_functions(GdkWindow* window, GdkWMFunction functions)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_set_functions", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkWMFunction_P(functions), functions, 2, "gdk_window_set_functions", "GdkWMFunction");
  gdk_window_set_functions(XEN_TO_C_GdkWindow_(window), XEN_TO_C_GdkWMFunction(functions));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_get_toplevels(void)
{
  #define H_gdk_window_get_toplevels "GList* gdk_window_get_toplevels( void)"
  return(C_TO_XEN_GList_(gdk_window_get_toplevels()));
}
static XEN gxg_gdk_window_iconify(XEN window)
{
  #define H_gdk_window_iconify "void gdk_window_iconify(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_iconify", "GdkWindow*");
  gdk_window_iconify(XEN_TO_C_GdkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_deiconify(XEN window)
{
  #define H_gdk_window_deiconify "void gdk_window_deiconify(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_deiconify", "GdkWindow*");
  gdk_window_deiconify(XEN_TO_C_GdkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_stick(XEN window)
{
  #define H_gdk_window_stick "void gdk_window_stick(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_stick", "GdkWindow*");
  gdk_window_stick(XEN_TO_C_GdkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_unstick(XEN window)
{
  #define H_gdk_window_unstick "void gdk_window_unstick(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_unstick", "GdkWindow*");
  gdk_window_unstick(XEN_TO_C_GdkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_maximize(XEN window)
{
  #define H_gdk_window_maximize "void gdk_window_maximize(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_maximize", "GdkWindow*");
  gdk_window_maximize(XEN_TO_C_GdkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_unmaximize(XEN window)
{
  #define H_gdk_window_unmaximize "void gdk_window_unmaximize(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_unmaximize", "GdkWindow*");
  gdk_window_unmaximize(XEN_TO_C_GdkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_register_dnd(XEN window)
{
  #define H_gdk_window_register_dnd "void gdk_window_register_dnd(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_register_dnd", "GdkWindow*");
  gdk_window_register_dnd(XEN_TO_C_GdkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_begin_resize_drag(XEN window, XEN edge, XEN button, XEN root_x, XEN root_y, XEN timestamp)
{
  #define H_gdk_window_begin_resize_drag "void gdk_window_begin_resize_drag(GdkWindow* window, GdkWindowEdge edge, \
gint button, gint root_x, gint root_y, guint32 timestamp)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_begin_resize_drag", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkWindowEdge_P(edge), edge, 2, "gdk_window_begin_resize_drag", "GdkWindowEdge");
  XEN_ASSERT_TYPE(XEN_gint_P(button), button, 3, "gdk_window_begin_resize_drag", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(root_x), root_x, 4, "gdk_window_begin_resize_drag", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(root_y), root_y, 5, "gdk_window_begin_resize_drag", "gint");
  XEN_ASSERT_TYPE(XEN_guint32_P(timestamp), timestamp, 6, "gdk_window_begin_resize_drag", "guint32");
  gdk_window_begin_resize_drag(XEN_TO_C_GdkWindow_(window), XEN_TO_C_GdkWindowEdge(edge), XEN_TO_C_gint(button), XEN_TO_C_gint(root_x), 
                               XEN_TO_C_gint(root_y), XEN_TO_C_guint32(timestamp));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_begin_move_drag(XEN window, XEN button, XEN root_x, XEN root_y, XEN timestamp)
{
  #define H_gdk_window_begin_move_drag "void gdk_window_begin_move_drag(GdkWindow* window, gint button, \
gint root_x, gint root_y, guint32 timestamp)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_begin_move_drag", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_gint_P(button), button, 2, "gdk_window_begin_move_drag", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(root_x), root_x, 3, "gdk_window_begin_move_drag", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(root_y), root_y, 4, "gdk_window_begin_move_drag", "gint");
  XEN_ASSERT_TYPE(XEN_guint32_P(timestamp), timestamp, 5, "gdk_window_begin_move_drag", "guint32");
  gdk_window_begin_move_drag(XEN_TO_C_GdkWindow_(window), XEN_TO_C_gint(button), XEN_TO_C_gint(root_x), XEN_TO_C_gint(root_y), 
                             XEN_TO_C_guint32(timestamp));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_invalidate_rect(XEN window, XEN rect, XEN invalidate_children)
{
  #define H_gdk_window_invalidate_rect "void gdk_window_invalidate_rect(GdkWindow* window, GdkRectangle* rect, \
gboolean invalidate_children)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_invalidate_rect", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(rect), rect, 2, "gdk_window_invalidate_rect", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(invalidate_children), invalidate_children, 3, "gdk_window_invalidate_rect", "gboolean");
  gdk_window_invalidate_rect(XEN_TO_C_GdkWindow_(window), XEN_TO_C_GdkRectangle_(rect), XEN_TO_C_gboolean(invalidate_children));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_invalidate_region(XEN window, XEN region, XEN invalidate_children)
{
  #define H_gdk_window_invalidate_region "void gdk_window_invalidate_region(GdkWindow* window, GdkRegion* region, \
gboolean invalidate_children)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_invalidate_region", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkRegion__P(region), region, 2, "gdk_window_invalidate_region", "GdkRegion*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(invalidate_children), invalidate_children, 3, "gdk_window_invalidate_region", "gboolean");
  gdk_window_invalidate_region(XEN_TO_C_GdkWindow_(window), XEN_TO_C_GdkRegion_(region), XEN_TO_C_gboolean(invalidate_children));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_invalidate_maybe_recurse(XEN window, XEN region, XEN func, XEN func_data)
{
  #define H_gdk_window_invalidate_maybe_recurse "void gdk_window_invalidate_maybe_recurse(GdkWindow* window, \
GdkRegion* region, lambda2 func, lambda_data func_data)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_invalidate_maybe_recurse", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkRegion__P(region), region, 2, "gdk_window_invalidate_maybe_recurse", "GdkRegion*");
  XEN_ASSERT_TYPE(XEN_lambda2_P(func), func, 3, "gdk_window_invalidate_maybe_recurse", "lambda2");
  if (XEN_NOT_BOUND_P(func_data)) func_data = XEN_FALSE; 
  else XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 4, "gdk_window_invalidate_maybe_recurse", "lambda_data");
  {
    int loc;
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    loc = xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 2, C_TO_XEN_INT(loc));
    gdk_window_invalidate_maybe_recurse(XEN_TO_C_GdkWindow_(window), XEN_TO_C_GdkRegion_(region), XEN_TO_C_lambda2(func), XEN_TO_C_lambda_data(func_data));
    xm_unprotect_at(loc);
    return(XEN_FALSE);
   }
}
static XEN gxg_gdk_window_get_update_area(XEN window)
{
  #define H_gdk_window_get_update_area "GdkRegion* gdk_window_get_update_area(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_get_update_area", "GdkWindow*");
  return(C_TO_XEN_GdkRegion_(gdk_window_get_update_area(XEN_TO_C_GdkWindow_(window))));
}
static XEN gxg_gdk_window_freeze_updates(XEN window)
{
  #define H_gdk_window_freeze_updates "void gdk_window_freeze_updates(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_freeze_updates", "GdkWindow*");
  gdk_window_freeze_updates(XEN_TO_C_GdkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_thaw_updates(XEN window)
{
  #define H_gdk_window_thaw_updates "void gdk_window_thaw_updates(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_thaw_updates", "GdkWindow*");
  gdk_window_thaw_updates(XEN_TO_C_GdkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_process_all_updates(void)
{
  #define H_gdk_window_process_all_updates "void gdk_window_process_all_updates( void)"
  gdk_window_process_all_updates();
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_process_updates(XEN window, XEN update_children)
{
  #define H_gdk_window_process_updates "void gdk_window_process_updates(GdkWindow* window, gboolean update_children)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_process_updates", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(update_children), update_children, 2, "gdk_window_process_updates", "gboolean");
  gdk_window_process_updates(XEN_TO_C_GdkWindow_(window), XEN_TO_C_gboolean(update_children));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_set_debug_updates(XEN setting)
{
  #define H_gdk_window_set_debug_updates "void gdk_window_set_debug_updates(gboolean setting)"
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 1, "gdk_window_set_debug_updates", "gboolean");
  gdk_window_set_debug_updates(XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_constrain_size(XEN geometry, XEN flags, XEN width, XEN height, XEN new_width, XEN new_height)
{
  #define H_gdk_window_constrain_size "void gdk_window_constrain_size(GdkGeometry* geometry, guint flags, \
gint width, gint height, gint* [new_width], gint* [new_height])"
  gint ref_new_width;
  gint ref_new_height;
  XEN_ASSERT_TYPE(XEN_GdkGeometry__P(geometry), geometry, 1, "gdk_window_constrain_size", "GdkGeometry*");
  XEN_ASSERT_TYPE(XEN_guint_P(flags), flags, 2, "gdk_window_constrain_size", "guint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 3, "gdk_window_constrain_size", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 4, "gdk_window_constrain_size", "gint");
  gdk_window_constrain_size(XEN_TO_C_GdkGeometry_(geometry), XEN_TO_C_guint(flags), XEN_TO_C_gint(width), XEN_TO_C_gint(height), 
                            &ref_new_width, &ref_new_height);
  return(XEN_LIST_2(C_TO_XEN_gint(ref_new_width), C_TO_XEN_gint(ref_new_height)));
}
static XEN gxg_gdk_window_get_internal_paint_info(XEN window, XEN real_drawable, XEN x_offset, XEN y_offset)
{
  #define H_gdk_window_get_internal_paint_info "void gdk_window_get_internal_paint_info(GdkWindow* window, \
GdkDrawable** [real_drawable], gint* [x_offset], gint* [y_offset])"
  GdkDrawable* ref_real_drawable = NULL;
  gint ref_x_offset;
  gint ref_y_offset;
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_get_internal_paint_info", "GdkWindow*");
  gdk_window_get_internal_paint_info(XEN_TO_C_GdkWindow_(window), &ref_real_drawable, &ref_x_offset, &ref_y_offset);
  return(XEN_LIST_3(C_TO_XEN_GdkDrawable_(ref_real_drawable), C_TO_XEN_gint(ref_x_offset), C_TO_XEN_gint(ref_y_offset)));
}
static XEN gxg_gtk_window_remove_embedded_xid(XEN window, XEN xid)
{
  #define H_gtk_window_remove_embedded_xid "void gtk_window_remove_embedded_xid(GtkWindow* window, guint xid)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_remove_embedded_xid", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_guint_P(xid), xid, 2, "gtk_window_remove_embedded_xid", "guint");
  gtk_window_remove_embedded_xid(XEN_TO_C_GtkWindow_(window), XEN_TO_C_guint(xid));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_add_embedded_xid(XEN window, XEN xid)
{
  #define H_gtk_window_add_embedded_xid "void gtk_window_add_embedded_xid(GtkWindow* window, guint xid)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_add_embedded_xid", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_guint_P(xid), xid, 2, "gtk_window_add_embedded_xid", "guint");
  gtk_window_add_embedded_xid(XEN_TO_C_GtkWindow_(window), XEN_TO_C_guint(xid));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_set_type_hint(XEN window, XEN hint)
{
  #define H_gdk_window_set_type_hint "void gdk_window_set_type_hint(GdkWindow* window, GdkWindowTypeHint hint)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_set_type_hint", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkWindowTypeHint_P(hint), hint, 2, "gdk_window_set_type_hint", "GdkWindowTypeHint");
  gdk_window_set_type_hint(XEN_TO_C_GdkWindow_(window), XEN_TO_C_GdkWindowTypeHint(hint));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_set_modal_hint(XEN window, XEN modal)
{
  #define H_gdk_window_set_modal_hint "void gdk_window_set_modal_hint(GdkWindow* window, gboolean modal)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_set_modal_hint", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(modal), modal, 2, "gdk_window_set_modal_hint", "gboolean");
  gdk_window_set_modal_hint(XEN_TO_C_GdkWindow_(window), XEN_TO_C_gboolean(modal));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_set_geometry_hints(XEN window, XEN geometry, XEN geom_mask)
{
  #define H_gdk_window_set_geometry_hints "void gdk_window_set_geometry_hints(GdkWindow* window, GdkGeometry* geometry, \
GdkWindowHints geom_mask)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_set_geometry_hints", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkGeometry__P(geometry), geometry, 2, "gdk_window_set_geometry_hints", "GdkGeometry*");
  XEN_ASSERT_TYPE(XEN_GdkWindowHints_P(geom_mask), geom_mask, 3, "gdk_window_set_geometry_hints", "GdkWindowHints");
  gdk_window_set_geometry_hints(XEN_TO_C_GdkWindow_(window), XEN_TO_C_GdkGeometry_(geometry), XEN_TO_C_GdkWindowHints(geom_mask));
  return(XEN_FALSE);
}
static XEN gxg_gdk_set_sm_client_id(XEN sm_client_id)
{
  #define H_gdk_set_sm_client_id "void gdk_set_sm_client_id(gchar* sm_client_id)"
  XEN_ASSERT_TYPE(XEN_gchar__P(sm_client_id), sm_client_id, 1, "gdk_set_sm_client_id", "gchar*");
  gdk_set_sm_client_id(XEN_TO_C_gchar_(sm_client_id));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_begin_paint_rect(XEN window, XEN rectangle)
{
  #define H_gdk_window_begin_paint_rect "void gdk_window_begin_paint_rect(GdkWindow* window, GdkRectangle* rectangle)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_begin_paint_rect", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(rectangle), rectangle, 2, "gdk_window_begin_paint_rect", "GdkRectangle*");
  gdk_window_begin_paint_rect(XEN_TO_C_GdkWindow_(window), XEN_TO_C_GdkRectangle_(rectangle));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_begin_paint_region(XEN window, XEN region)
{
  #define H_gdk_window_begin_paint_region "void gdk_window_begin_paint_region(GdkWindow* window, GdkRegion* region)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_begin_paint_region", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkRegion__P(region), region, 2, "gdk_window_begin_paint_region", "GdkRegion*");
  gdk_window_begin_paint_region(XEN_TO_C_GdkWindow_(window), XEN_TO_C_GdkRegion_(region));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_end_paint(XEN window)
{
  #define H_gdk_window_end_paint "void gdk_window_end_paint(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_end_paint", "GdkWindow*");
  gdk_window_end_paint(XEN_TO_C_GdkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_set_title(XEN window, XEN title)
{
  #define H_gdk_window_set_title "void gdk_window_set_title(GdkWindow* window, gchar* title)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_set_title", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_gchar__P(title), title, 2, "gdk_window_set_title", "gchar*");
  gdk_window_set_title(XEN_TO_C_GdkWindow_(window), XEN_TO_C_gchar_(title));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_set_role(XEN window, XEN role)
{
  #define H_gdk_window_set_role "void gdk_window_set_role(GdkWindow* window, gchar* role)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_set_role", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_gchar__P(role), role, 2, "gdk_window_set_role", "gchar*");
  gdk_window_set_role(XEN_TO_C_GdkWindow_(window), XEN_TO_C_gchar_(role));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_set_transient_for(XEN window, XEN parent)
{
  #define H_gdk_window_set_transient_for "void gdk_window_set_transient_for(GdkWindow* window, GdkWindow* parent)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_set_transient_for", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(parent), parent, 2, "gdk_window_set_transient_for", "GdkWindow*");
  gdk_window_set_transient_for(XEN_TO_C_GdkWindow_(window), XEN_TO_C_GdkWindow_(parent));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_set_background(XEN window, XEN color)
{
  #define H_gdk_window_set_background "void gdk_window_set_background(GdkWindow* window, GdkColor* color)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_set_background", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(color), color, 2, "gdk_window_set_background", "GdkColor*");
  gdk_window_set_background(XEN_TO_C_GdkWindow_(window), XEN_TO_C_GdkColor_(color));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_set_back_pixmap(XEN window, XEN pixmap, XEN parent_relative)
{
  #define H_gdk_window_set_back_pixmap "void gdk_window_set_back_pixmap(GdkWindow* window, GdkPixmap* pixmap, \
gboolean parent_relative)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_set_back_pixmap", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkPixmap__P(pixmap), pixmap, 2, "gdk_window_set_back_pixmap", "GdkPixmap*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(parent_relative), parent_relative, 3, "gdk_window_set_back_pixmap", "gboolean");
  gdk_window_set_back_pixmap(XEN_TO_C_GdkWindow_(window), XEN_TO_C_GdkPixmap_(pixmap), XEN_TO_C_gboolean(parent_relative));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_set_cursor(XEN window, XEN cursor)
{
  #define H_gdk_window_set_cursor "void gdk_window_set_cursor(GdkWindow* window, GdkCursor* cursor)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_set_cursor", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkCursor__P(cursor), cursor, 2, "gdk_window_set_cursor", "GdkCursor*");
  gdk_window_set_cursor(XEN_TO_C_GdkWindow_(window), XEN_TO_C_GdkCursor_(cursor));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_get_user_data(XEN window, XEN data)
{
  #define H_gdk_window_get_user_data "void gdk_window_get_user_data(GdkWindow* window, gpointer* [data])"
  gpointer ref_data;
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_get_user_data", "GdkWindow*");
  gdk_window_get_user_data(XEN_TO_C_GdkWindow_(window), &ref_data);
  return(XEN_LIST_1(C_TO_XEN_gpointer(ref_data)));
}
static XEN gxg_gdk_window_get_geometry(XEN window, XEN x, XEN y, XEN width, XEN height, XEN depth)
{
  #define H_gdk_window_get_geometry "void gdk_window_get_geometry(GdkWindow* window, gint* [x], gint* [y], \
gint* [width], gint* [height], gint* [depth])"
  gint ref_x;
  gint ref_y;
  gint ref_width;
  gint ref_height;
  gint ref_depth;
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_get_geometry", "GdkWindow*");
  gdk_window_get_geometry(XEN_TO_C_GdkWindow_(window), &ref_x, &ref_y, &ref_width, &ref_height, &ref_depth);
  return(XEN_LIST_5(C_TO_XEN_gint(ref_x), C_TO_XEN_gint(ref_y), C_TO_XEN_gint(ref_width), C_TO_XEN_gint(ref_height), C_TO_XEN_gint(ref_depth)));
}
static XEN gxg_gdk_window_get_position(XEN window, XEN x, XEN y)
{
  #define H_gdk_window_get_position "void gdk_window_get_position(GdkWindow* window, gint* [x], gint* [y])"
  gint ref_x;
  gint ref_y;
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_get_position", "GdkWindow*");
  gdk_window_get_position(XEN_TO_C_GdkWindow_(window), &ref_x, &ref_y);
  return(XEN_LIST_2(C_TO_XEN_gint(ref_x), C_TO_XEN_gint(ref_y)));
}
static XEN gxg_gdk_window_get_origin(XEN window, XEN x, XEN y)
{
  #define H_gdk_window_get_origin "gint gdk_window_get_origin(GdkWindow* window, gint* [x], gint* [y])"
  gint ref_x;
  gint ref_y;
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_get_origin", "GdkWindow*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gint(gdk_window_get_origin(XEN_TO_C_GdkWindow_(window), &ref_x, &ref_y));
    return(XEN_LIST_3(result, C_TO_XEN_gint(ref_x), C_TO_XEN_gint(ref_y)));
   }
}
static XEN gxg_gdk_get_default_root_window(void)
{
  #define H_gdk_get_default_root_window "GdkWindow* gdk_get_default_root_window( void)"
  return(C_TO_XEN_GdkWindow_(gdk_get_default_root_window()));
}
static XEN gxg_gdk_pixbuf_error_quark(void)
{
  #define H_gdk_pixbuf_error_quark "GQuark gdk_pixbuf_error_quark( void)"
  return(C_TO_XEN_GQuark(gdk_pixbuf_error_quark()));
}
static XEN gxg_gdk_pixbuf_get_type(void)
{
  #define H_gdk_pixbuf_get_type "GType gdk_pixbuf_get_type( void)"
  return(C_TO_XEN_GType(gdk_pixbuf_get_type()));
}
static XEN gxg_gdk_pixbuf_get_colorspace(XEN pixbuf)
{
  #define H_gdk_pixbuf_get_colorspace "GdkColorspace gdk_pixbuf_get_colorspace(GdkPixbuf* pixbuf)"
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(pixbuf), pixbuf, 1, "gdk_pixbuf_get_colorspace", "GdkPixbuf*");
  return(C_TO_XEN_GdkColorspace(gdk_pixbuf_get_colorspace(XEN_TO_C_GdkPixbuf_(pixbuf))));
}
static XEN gxg_gdk_pixbuf_get_n_channels(XEN pixbuf)
{
  #define H_gdk_pixbuf_get_n_channels "int gdk_pixbuf_get_n_channels(GdkPixbuf* pixbuf)"
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(pixbuf), pixbuf, 1, "gdk_pixbuf_get_n_channels", "GdkPixbuf*");
  return(C_TO_XEN_int(gdk_pixbuf_get_n_channels(XEN_TO_C_GdkPixbuf_(pixbuf))));
}
static XEN gxg_gdk_pixbuf_get_has_alpha(XEN pixbuf)
{
  #define H_gdk_pixbuf_get_has_alpha "gboolean gdk_pixbuf_get_has_alpha(GdkPixbuf* pixbuf)"
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(pixbuf), pixbuf, 1, "gdk_pixbuf_get_has_alpha", "GdkPixbuf*");
  return(C_TO_XEN_gboolean(gdk_pixbuf_get_has_alpha(XEN_TO_C_GdkPixbuf_(pixbuf))));
}
static XEN gxg_gdk_pixbuf_get_bits_per_sample(XEN pixbuf)
{
  #define H_gdk_pixbuf_get_bits_per_sample "int gdk_pixbuf_get_bits_per_sample(GdkPixbuf* pixbuf)"
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(pixbuf), pixbuf, 1, "gdk_pixbuf_get_bits_per_sample", "GdkPixbuf*");
  return(C_TO_XEN_int(gdk_pixbuf_get_bits_per_sample(XEN_TO_C_GdkPixbuf_(pixbuf))));
}
static XEN gxg_gdk_pixbuf_get_pixels(XEN pixbuf)
{
  #define H_gdk_pixbuf_get_pixels "guchar* gdk_pixbuf_get_pixels(GdkPixbuf* pixbuf)"
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(pixbuf), pixbuf, 1, "gdk_pixbuf_get_pixels", "GdkPixbuf*");
  return(C_TO_XEN_guchar_(gdk_pixbuf_get_pixels(XEN_TO_C_GdkPixbuf_(pixbuf))));
}
static XEN gxg_gdk_pixbuf_get_width(XEN pixbuf)
{
  #define H_gdk_pixbuf_get_width "int gdk_pixbuf_get_width(GdkPixbuf* pixbuf)"
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(pixbuf), pixbuf, 1, "gdk_pixbuf_get_width", "GdkPixbuf*");
  return(C_TO_XEN_int(gdk_pixbuf_get_width(XEN_TO_C_GdkPixbuf_(pixbuf))));
}
static XEN gxg_gdk_pixbuf_get_height(XEN pixbuf)
{
  #define H_gdk_pixbuf_get_height "int gdk_pixbuf_get_height(GdkPixbuf* pixbuf)"
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(pixbuf), pixbuf, 1, "gdk_pixbuf_get_height", "GdkPixbuf*");
  return(C_TO_XEN_int(gdk_pixbuf_get_height(XEN_TO_C_GdkPixbuf_(pixbuf))));
}
static XEN gxg_gdk_pixbuf_get_rowstride(XEN pixbuf)
{
  #define H_gdk_pixbuf_get_rowstride "int gdk_pixbuf_get_rowstride(GdkPixbuf* pixbuf)"
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(pixbuf), pixbuf, 1, "gdk_pixbuf_get_rowstride", "GdkPixbuf*");
  return(C_TO_XEN_int(gdk_pixbuf_get_rowstride(XEN_TO_C_GdkPixbuf_(pixbuf))));
}
static XEN gxg_gdk_pixbuf_new(XEN colorspace, XEN has_alpha, XEN bits_per_sample, XEN width, XEN height)
{
  #define H_gdk_pixbuf_new "GdkPixbuf* gdk_pixbuf_new(GdkColorspace colorspace, gboolean has_alpha, int bits_per_sample, \
int width, int height)"
  XEN_ASSERT_TYPE(XEN_GdkColorspace_P(colorspace), colorspace, 1, "gdk_pixbuf_new", "GdkColorspace");
  XEN_ASSERT_TYPE(XEN_gboolean_P(has_alpha), has_alpha, 2, "gdk_pixbuf_new", "gboolean");
  XEN_ASSERT_TYPE(XEN_int_P(bits_per_sample), bits_per_sample, 3, "gdk_pixbuf_new", "int");
  XEN_ASSERT_TYPE(XEN_int_P(width), width, 4, "gdk_pixbuf_new", "int");
  XEN_ASSERT_TYPE(XEN_int_P(height), height, 5, "gdk_pixbuf_new", "int");
  return(C_TO_XEN_GdkPixbuf_(gdk_pixbuf_new(XEN_TO_C_GdkColorspace(colorspace), XEN_TO_C_gboolean(has_alpha), XEN_TO_C_int(bits_per_sample), 
                                            XEN_TO_C_int(width), XEN_TO_C_int(height))));
}
static XEN gxg_gdk_pixbuf_copy(XEN pixbuf)
{
  #define H_gdk_pixbuf_copy "GdkPixbuf* gdk_pixbuf_copy(GdkPixbuf* pixbuf)"
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(pixbuf), pixbuf, 1, "gdk_pixbuf_copy", "GdkPixbuf*");
  return(C_TO_XEN_GdkPixbuf_(gdk_pixbuf_copy(XEN_TO_C_GdkPixbuf_(pixbuf))));
}
static XEN gxg_gdk_pixbuf_new_subpixbuf(XEN src_pixbuf, XEN src_x, XEN src_y, XEN width, XEN height)
{
  #define H_gdk_pixbuf_new_subpixbuf "GdkPixbuf* gdk_pixbuf_new_subpixbuf(GdkPixbuf* src_pixbuf, int src_x, \
int src_y, int width, int height)"
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(src_pixbuf), src_pixbuf, 1, "gdk_pixbuf_new_subpixbuf", "GdkPixbuf*");
  XEN_ASSERT_TYPE(XEN_int_P(src_x), src_x, 2, "gdk_pixbuf_new_subpixbuf", "int");
  XEN_ASSERT_TYPE(XEN_int_P(src_y), src_y, 3, "gdk_pixbuf_new_subpixbuf", "int");
  XEN_ASSERT_TYPE(XEN_int_P(width), width, 4, "gdk_pixbuf_new_subpixbuf", "int");
  XEN_ASSERT_TYPE(XEN_int_P(height), height, 5, "gdk_pixbuf_new_subpixbuf", "int");
  return(C_TO_XEN_GdkPixbuf_(gdk_pixbuf_new_subpixbuf(XEN_TO_C_GdkPixbuf_(src_pixbuf), XEN_TO_C_int(src_x), XEN_TO_C_int(src_y), 
                                                      XEN_TO_C_int(width), XEN_TO_C_int(height))));
}
static XEN gxg_gdk_pixbuf_new_from_file(XEN filename, XEN error)
{
  #define H_gdk_pixbuf_new_from_file "GdkPixbuf* gdk_pixbuf_new_from_file(char* filename, GError** [error])"
  GError* ref_error = NULL;
  XEN_ASSERT_TYPE(XEN_char__P(filename), filename, 1, "gdk_pixbuf_new_from_file", "char*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_GdkPixbuf_(gdk_pixbuf_new_from_file(XEN_TO_C_char_(filename), &ref_error));
    return(XEN_LIST_2(result, C_TO_XEN_GError_(ref_error)));
   }
}
static XEN gxg_gdk_pixbuf_new_from_data(XEN data, XEN colorspace, XEN has_alpha, XEN bits_per_sample, XEN width, XEN height, XEN rowstride, XEN destroy_fn, XEN destroy_fn_data)
{
  #define H_gdk_pixbuf_new_from_data "GdkPixbuf* gdk_pixbuf_new_from_data(guchar* data, GdkColorspace colorspace, \
gboolean has_alpha, int bits_per_sample, int width, int height, int rowstride, GdkPixbufDestroyNotify destroy_fn, \
gpointer destroy_fn_data)"
  XEN_ASSERT_TYPE(XEN_guchar__P(data), data, 1, "gdk_pixbuf_new_from_data", "guchar*");
  XEN_ASSERT_TYPE(XEN_GdkColorspace_P(colorspace), colorspace, 2, "gdk_pixbuf_new_from_data", "GdkColorspace");
  XEN_ASSERT_TYPE(XEN_gboolean_P(has_alpha), has_alpha, 3, "gdk_pixbuf_new_from_data", "gboolean");
  XEN_ASSERT_TYPE(XEN_int_P(bits_per_sample), bits_per_sample, 4, "gdk_pixbuf_new_from_data", "int");
  XEN_ASSERT_TYPE(XEN_int_P(width), width, 5, "gdk_pixbuf_new_from_data", "int");
  XEN_ASSERT_TYPE(XEN_int_P(height), height, 6, "gdk_pixbuf_new_from_data", "int");
  XEN_ASSERT_TYPE(XEN_int_P(rowstride), rowstride, 7, "gdk_pixbuf_new_from_data", "int");
  XEN_ASSERT_TYPE(XEN_GdkPixbufDestroyNotify_P(destroy_fn), destroy_fn, 8, "gdk_pixbuf_new_from_data", "GdkPixbufDestroyNotify");
  XEN_ASSERT_TYPE(XEN_gpointer_P(destroy_fn_data), destroy_fn_data, 9, "gdk_pixbuf_new_from_data", "gpointer");
  return(C_TO_XEN_GdkPixbuf_(gdk_pixbuf_new_from_data(XEN_TO_C_guchar_(data), XEN_TO_C_GdkColorspace(colorspace), XEN_TO_C_gboolean(has_alpha), 
                                                      XEN_TO_C_int(bits_per_sample), XEN_TO_C_int(width), XEN_TO_C_int(height), 
                                                      XEN_TO_C_int(rowstride), XEN_TO_C_GdkPixbufDestroyNotify(destroy_fn), 
                                                      XEN_TO_C_gpointer(destroy_fn_data))));
}
static XEN gxg_gdk_pixbuf_new_from_xpm_data(XEN data)
{
  #define H_gdk_pixbuf_new_from_xpm_data "GdkPixbuf* gdk_pixbuf_new_from_xpm_data(char** data)"
  XEN_ASSERT_TYPE(XEN_char___P(data), data, 1, "gdk_pixbuf_new_from_xpm_data", "char**");
  return(C_TO_XEN_GdkPixbuf_(gdk_pixbuf_new_from_xpm_data((const char**)XEN_TO_C_char__(data))));
}
static XEN gxg_gdk_pixbuf_new_from_inline(XEN data_length, XEN data, XEN copy_pixels, XEN error)
{
  #define H_gdk_pixbuf_new_from_inline "GdkPixbuf* gdk_pixbuf_new_from_inline(gint data_length, guint8* data, \
gboolean copy_pixels, GError** [error])"
  GError* ref_error = NULL;
  XEN_ASSERT_TYPE(XEN_gint_P(data_length), data_length, 1, "gdk_pixbuf_new_from_inline", "gint");
  XEN_ASSERT_TYPE(XEN_guint8__P(data), data, 2, "gdk_pixbuf_new_from_inline", "guint8*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(copy_pixels), copy_pixels, 3, "gdk_pixbuf_new_from_inline", "gboolean");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_GdkPixbuf_(gdk_pixbuf_new_from_inline(XEN_TO_C_gint(data_length), XEN_TO_C_guint8_(data), XEN_TO_C_gboolean(copy_pixels), 
                                                            &ref_error));
    return(XEN_LIST_2(result, C_TO_XEN_GError_(ref_error)));
   }
}
static XEN gxg_gdk_pixbuf_fill(XEN pixbuf, XEN pixel)
{
  #define H_gdk_pixbuf_fill "void gdk_pixbuf_fill(GdkPixbuf* pixbuf, guint32 pixel)"
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(pixbuf), pixbuf, 1, "gdk_pixbuf_fill", "GdkPixbuf*");
  XEN_ASSERT_TYPE(XEN_guint32_P(pixel), pixel, 2, "gdk_pixbuf_fill", "guint32");
  gdk_pixbuf_fill(XEN_TO_C_GdkPixbuf_(pixbuf), XEN_TO_C_guint32(pixel));
  return(XEN_FALSE);
}
static XEN gxg_gdk_pixbuf_savev(XEN pixbuf, XEN filename, XEN type, XEN option_keys, XEN option_values, XEN error)
{
  #define H_gdk_pixbuf_savev "gboolean gdk_pixbuf_savev(GdkPixbuf* pixbuf, char* filename, char* type, \
char** option_keys, char** option_values, GError** [error])"
  GError* ref_error = NULL;
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(pixbuf), pixbuf, 1, "gdk_pixbuf_savev", "GdkPixbuf*");
  XEN_ASSERT_TYPE(XEN_char__P(filename), filename, 2, "gdk_pixbuf_savev", "char*");
  XEN_ASSERT_TYPE(XEN_char__P(type), type, 3, "gdk_pixbuf_savev", "char*");
  XEN_ASSERT_TYPE(XEN_char___P(option_keys), option_keys, 4, "gdk_pixbuf_savev", "char**");
  XEN_ASSERT_TYPE(XEN_char___P(option_values), option_values, 5, "gdk_pixbuf_savev", "char**");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gdk_pixbuf_savev(XEN_TO_C_GdkPixbuf_(pixbuf), XEN_TO_C_char_(filename), XEN_TO_C_char_(type), 
                                                XEN_TO_C_char__(option_keys), XEN_TO_C_char__(option_values), &ref_error));
    return(XEN_LIST_2(result, C_TO_XEN_GError_(ref_error)));
   }
}
static XEN gxg_gdk_pixbuf_add_alpha(XEN pixbuf, XEN substitute_color, XEN r, XEN g, XEN b)
{
  #define H_gdk_pixbuf_add_alpha "GdkPixbuf* gdk_pixbuf_add_alpha(GdkPixbuf* pixbuf, gboolean substitute_color, \
guchar r, guchar g, guchar b)"
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(pixbuf), pixbuf, 1, "gdk_pixbuf_add_alpha", "GdkPixbuf*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(substitute_color), substitute_color, 2, "gdk_pixbuf_add_alpha", "gboolean");
  XEN_ASSERT_TYPE(XEN_guchar_P(r), r, 3, "gdk_pixbuf_add_alpha", "guchar");
  XEN_ASSERT_TYPE(XEN_guchar_P(g), g, 4, "gdk_pixbuf_add_alpha", "guchar");
  XEN_ASSERT_TYPE(XEN_guchar_P(b), b, 5, "gdk_pixbuf_add_alpha", "guchar");
  return(C_TO_XEN_GdkPixbuf_(gdk_pixbuf_add_alpha(XEN_TO_C_GdkPixbuf_(pixbuf), XEN_TO_C_gboolean(substitute_color), XEN_TO_C_guchar(r), 
                                                  XEN_TO_C_guchar(g), XEN_TO_C_guchar(b))));
}
static XEN gxg_gdk_pixbuf_copy_area(XEN src_pixbuf, XEN src_x, XEN src_y, XEN width, XEN height, XEN dest_pixbuf, XEN dest_x, XEN dest_y)
{
  #define H_gdk_pixbuf_copy_area "void gdk_pixbuf_copy_area(GdkPixbuf* src_pixbuf, int src_x, int src_y, \
int width, int height, GdkPixbuf* dest_pixbuf, int dest_x, int dest_y)"
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(src_pixbuf), src_pixbuf, 1, "gdk_pixbuf_copy_area", "GdkPixbuf*");
  XEN_ASSERT_TYPE(XEN_int_P(src_x), src_x, 2, "gdk_pixbuf_copy_area", "int");
  XEN_ASSERT_TYPE(XEN_int_P(src_y), src_y, 3, "gdk_pixbuf_copy_area", "int");
  XEN_ASSERT_TYPE(XEN_int_P(width), width, 4, "gdk_pixbuf_copy_area", "int");
  XEN_ASSERT_TYPE(XEN_int_P(height), height, 5, "gdk_pixbuf_copy_area", "int");
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(dest_pixbuf), dest_pixbuf, 6, "gdk_pixbuf_copy_area", "GdkPixbuf*");
  XEN_ASSERT_TYPE(XEN_int_P(dest_x), dest_x, 7, "gdk_pixbuf_copy_area", "int");
  XEN_ASSERT_TYPE(XEN_int_P(dest_y), dest_y, 8, "gdk_pixbuf_copy_area", "int");
  gdk_pixbuf_copy_area(XEN_TO_C_GdkPixbuf_(src_pixbuf), XEN_TO_C_int(src_x), XEN_TO_C_int(src_y), XEN_TO_C_int(width), XEN_TO_C_int(height), 
                       XEN_TO_C_GdkPixbuf_(dest_pixbuf), XEN_TO_C_int(dest_x), XEN_TO_C_int(dest_y));
  return(XEN_FALSE);
}
static XEN gxg_gdk_pixbuf_saturate_and_pixelate(XEN src, XEN dest, XEN saturation, XEN pixelate)
{
  #define H_gdk_pixbuf_saturate_and_pixelate "void gdk_pixbuf_saturate_and_pixelate(GdkPixbuf* src, GdkPixbuf* dest, \
gfloat saturation, gboolean pixelate)"
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(src), src, 1, "gdk_pixbuf_saturate_and_pixelate", "GdkPixbuf*");
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(dest), dest, 2, "gdk_pixbuf_saturate_and_pixelate", "GdkPixbuf*");
  XEN_ASSERT_TYPE(XEN_gfloat_P(saturation), saturation, 3, "gdk_pixbuf_saturate_and_pixelate", "gfloat");
  XEN_ASSERT_TYPE(XEN_gboolean_P(pixelate), pixelate, 4, "gdk_pixbuf_saturate_and_pixelate", "gboolean");
  gdk_pixbuf_saturate_and_pixelate(XEN_TO_C_GdkPixbuf_(src), XEN_TO_C_GdkPixbuf_(dest), XEN_TO_C_gfloat(saturation), XEN_TO_C_gboolean(pixelate));
  return(XEN_FALSE);
}
static XEN gxg_gdk_pixbuf_scale(XEN arglist)
{
  #define H_gdk_pixbuf_scale "void gdk_pixbuf_scale(GdkPixbuf* src, GdkPixbuf* dest, int dest_x, int dest_y, \
int dest_width, int dest_height, double offset_x, double offset_y, double scale_x, double scale_y, GdkInterpType interp_type)"
  XEN src, dest, dest_x, dest_y, dest_width, dest_height, offset_x, offset_y, scale_x, scale_y, interp_type;
  src = XEN_LIST_REF(arglist, 0);
  dest = XEN_LIST_REF(arglist, 1);
  dest_x = XEN_LIST_REF(arglist, 2);
  dest_y = XEN_LIST_REF(arglist, 3);
  dest_width = XEN_LIST_REF(arglist, 4);
  dest_height = XEN_LIST_REF(arglist, 5);
  offset_x = XEN_LIST_REF(arglist, 6);
  offset_y = XEN_LIST_REF(arglist, 7);
  scale_x = XEN_LIST_REF(arglist, 8);
  scale_y = XEN_LIST_REF(arglist, 9);
  interp_type = XEN_LIST_REF(arglist, 10);
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(src), src, 1, "gdk_pixbuf_scale", "GdkPixbuf*");
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(dest), dest, 2, "gdk_pixbuf_scale", "GdkPixbuf*");
  XEN_ASSERT_TYPE(XEN_int_P(dest_x), dest_x, 3, "gdk_pixbuf_scale", "int");
  XEN_ASSERT_TYPE(XEN_int_P(dest_y), dest_y, 4, "gdk_pixbuf_scale", "int");
  XEN_ASSERT_TYPE(XEN_int_P(dest_width), dest_width, 5, "gdk_pixbuf_scale", "int");
  XEN_ASSERT_TYPE(XEN_int_P(dest_height), dest_height, 6, "gdk_pixbuf_scale", "int");
  XEN_ASSERT_TYPE(XEN_double_P(offset_x), offset_x, 7, "gdk_pixbuf_scale", "double");
  XEN_ASSERT_TYPE(XEN_double_P(offset_y), offset_y, 8, "gdk_pixbuf_scale", "double");
  XEN_ASSERT_TYPE(XEN_double_P(scale_x), scale_x, 9, "gdk_pixbuf_scale", "double");
  XEN_ASSERT_TYPE(XEN_double_P(scale_y), scale_y, 10, "gdk_pixbuf_scale", "double");
  XEN_ASSERT_TYPE(XEN_GdkInterpType_P(interp_type), interp_type, 11, "gdk_pixbuf_scale", "GdkInterpType");
  gdk_pixbuf_scale(XEN_TO_C_GdkPixbuf_(src), XEN_TO_C_GdkPixbuf_(dest), XEN_TO_C_int(dest_x), XEN_TO_C_int(dest_y), XEN_TO_C_int(dest_width), 
                   XEN_TO_C_int(dest_height), XEN_TO_C_double(offset_x), XEN_TO_C_double(offset_y), XEN_TO_C_double(scale_x), 
                   XEN_TO_C_double(scale_y), XEN_TO_C_GdkInterpType(interp_type));
  return(xen_return_first(XEN_FALSE, arglist));
}
static XEN gxg_gdk_pixbuf_composite(XEN arglist)
{
  #define H_gdk_pixbuf_composite "void gdk_pixbuf_composite(GdkPixbuf* src, GdkPixbuf* dest, int dest_x, \
int dest_y, int dest_width, int dest_height, double offset_x, double offset_y, double scale_x, double scale_y, \
GdkInterpType interp_type, int overall_alpha)"
  XEN src, dest, dest_x, dest_y, dest_width, dest_height, offset_x, offset_y, scale_x, scale_y, interp_type, overall_alpha;
  src = XEN_LIST_REF(arglist, 0);
  dest = XEN_LIST_REF(arglist, 1);
  dest_x = XEN_LIST_REF(arglist, 2);
  dest_y = XEN_LIST_REF(arglist, 3);
  dest_width = XEN_LIST_REF(arglist, 4);
  dest_height = XEN_LIST_REF(arglist, 5);
  offset_x = XEN_LIST_REF(arglist, 6);
  offset_y = XEN_LIST_REF(arglist, 7);
  scale_x = XEN_LIST_REF(arglist, 8);
  scale_y = XEN_LIST_REF(arglist, 9);
  interp_type = XEN_LIST_REF(arglist, 10);
  overall_alpha = XEN_LIST_REF(arglist, 11);
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(src), src, 1, "gdk_pixbuf_composite", "GdkPixbuf*");
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(dest), dest, 2, "gdk_pixbuf_composite", "GdkPixbuf*");
  XEN_ASSERT_TYPE(XEN_int_P(dest_x), dest_x, 3, "gdk_pixbuf_composite", "int");
  XEN_ASSERT_TYPE(XEN_int_P(dest_y), dest_y, 4, "gdk_pixbuf_composite", "int");
  XEN_ASSERT_TYPE(XEN_int_P(dest_width), dest_width, 5, "gdk_pixbuf_composite", "int");
  XEN_ASSERT_TYPE(XEN_int_P(dest_height), dest_height, 6, "gdk_pixbuf_composite", "int");
  XEN_ASSERT_TYPE(XEN_double_P(offset_x), offset_x, 7, "gdk_pixbuf_composite", "double");
  XEN_ASSERT_TYPE(XEN_double_P(offset_y), offset_y, 8, "gdk_pixbuf_composite", "double");
  XEN_ASSERT_TYPE(XEN_double_P(scale_x), scale_x, 9, "gdk_pixbuf_composite", "double");
  XEN_ASSERT_TYPE(XEN_double_P(scale_y), scale_y, 10, "gdk_pixbuf_composite", "double");
  XEN_ASSERT_TYPE(XEN_GdkInterpType_P(interp_type), interp_type, 11, "gdk_pixbuf_composite", "GdkInterpType");
  XEN_ASSERT_TYPE(XEN_int_P(overall_alpha), overall_alpha, 12, "gdk_pixbuf_composite", "int");
  gdk_pixbuf_composite(XEN_TO_C_GdkPixbuf_(src), XEN_TO_C_GdkPixbuf_(dest), XEN_TO_C_int(dest_x), XEN_TO_C_int(dest_y), XEN_TO_C_int(dest_width), 
                       XEN_TO_C_int(dest_height), XEN_TO_C_double(offset_x), XEN_TO_C_double(offset_y), XEN_TO_C_double(scale_x), 
                       XEN_TO_C_double(scale_y), XEN_TO_C_GdkInterpType(interp_type), XEN_TO_C_int(overall_alpha));
  return(xen_return_first(XEN_FALSE, arglist));
}
static XEN gxg_gdk_pixbuf_composite_color(XEN arglist)
{
  #define H_gdk_pixbuf_composite_color "void gdk_pixbuf_composite_color(GdkPixbuf* src, GdkPixbuf* dest, \
int dest_x, int dest_y, int dest_width, int dest_height, double offset_x, double offset_y, double scale_x, \
double scale_y, GdkInterpType interp_type, int overall_alpha, int check_x, int check_y, int check_size, \
guint32 color1, guint32 color2)"
  XEN src, dest, dest_x, dest_y, dest_width, dest_height, offset_x, offset_y, scale_x, scale_y, interp_type, overall_alpha, check_x, check_y, check_size, color1, color2;
  src = XEN_LIST_REF(arglist, 0);
  dest = XEN_LIST_REF(arglist, 1);
  dest_x = XEN_LIST_REF(arglist, 2);
  dest_y = XEN_LIST_REF(arglist, 3);
  dest_width = XEN_LIST_REF(arglist, 4);
  dest_height = XEN_LIST_REF(arglist, 5);
  offset_x = XEN_LIST_REF(arglist, 6);
  offset_y = XEN_LIST_REF(arglist, 7);
  scale_x = XEN_LIST_REF(arglist, 8);
  scale_y = XEN_LIST_REF(arglist, 9);
  interp_type = XEN_LIST_REF(arglist, 10);
  overall_alpha = XEN_LIST_REF(arglist, 11);
  check_x = XEN_LIST_REF(arglist, 12);
  check_y = XEN_LIST_REF(arglist, 13);
  check_size = XEN_LIST_REF(arglist, 14);
  color1 = XEN_LIST_REF(arglist, 15);
  color2 = XEN_LIST_REF(arglist, 16);
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(src), src, 1, "gdk_pixbuf_composite_color", "GdkPixbuf*");
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(dest), dest, 2, "gdk_pixbuf_composite_color", "GdkPixbuf*");
  XEN_ASSERT_TYPE(XEN_int_P(dest_x), dest_x, 3, "gdk_pixbuf_composite_color", "int");
  XEN_ASSERT_TYPE(XEN_int_P(dest_y), dest_y, 4, "gdk_pixbuf_composite_color", "int");
  XEN_ASSERT_TYPE(XEN_int_P(dest_width), dest_width, 5, "gdk_pixbuf_composite_color", "int");
  XEN_ASSERT_TYPE(XEN_int_P(dest_height), dest_height, 6, "gdk_pixbuf_composite_color", "int");
  XEN_ASSERT_TYPE(XEN_double_P(offset_x), offset_x, 7, "gdk_pixbuf_composite_color", "double");
  XEN_ASSERT_TYPE(XEN_double_P(offset_y), offset_y, 8, "gdk_pixbuf_composite_color", "double");
  XEN_ASSERT_TYPE(XEN_double_P(scale_x), scale_x, 9, "gdk_pixbuf_composite_color", "double");
  XEN_ASSERT_TYPE(XEN_double_P(scale_y), scale_y, 10, "gdk_pixbuf_composite_color", "double");
  XEN_ASSERT_TYPE(XEN_GdkInterpType_P(interp_type), interp_type, 11, "gdk_pixbuf_composite_color", "GdkInterpType");
  XEN_ASSERT_TYPE(XEN_int_P(overall_alpha), overall_alpha, 12, "gdk_pixbuf_composite_color", "int");
  XEN_ASSERT_TYPE(XEN_int_P(check_x), check_x, 13, "gdk_pixbuf_composite_color", "int");
  XEN_ASSERT_TYPE(XEN_int_P(check_y), check_y, 14, "gdk_pixbuf_composite_color", "int");
  XEN_ASSERT_TYPE(XEN_int_P(check_size), check_size, 15, "gdk_pixbuf_composite_color", "int");
  XEN_ASSERT_TYPE(XEN_guint32_P(color1), color1, 16, "gdk_pixbuf_composite_color", "guint32");
  XEN_ASSERT_TYPE(XEN_guint32_P(color2), color2, 17, "gdk_pixbuf_composite_color", "guint32");
  gdk_pixbuf_composite_color(XEN_TO_C_GdkPixbuf_(src), XEN_TO_C_GdkPixbuf_(dest), XEN_TO_C_int(dest_x), XEN_TO_C_int(dest_y), 
                             XEN_TO_C_int(dest_width), XEN_TO_C_int(dest_height), XEN_TO_C_double(offset_x), XEN_TO_C_double(offset_y), 
                             XEN_TO_C_double(scale_x), XEN_TO_C_double(scale_y), XEN_TO_C_GdkInterpType(interp_type), XEN_TO_C_int(overall_alpha), 
                             XEN_TO_C_int(check_x), XEN_TO_C_int(check_y), XEN_TO_C_int(check_size), XEN_TO_C_guint32(color1), 
                             XEN_TO_C_guint32(color2));
  return(xen_return_first(XEN_FALSE, arglist));
}
static XEN gxg_gdk_pixbuf_scale_simple(XEN src, XEN dest_width, XEN dest_height, XEN interp_type)
{
  #define H_gdk_pixbuf_scale_simple "GdkPixbuf* gdk_pixbuf_scale_simple(GdkPixbuf* src, int dest_width, \
int dest_height, GdkInterpType interp_type)"
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(src), src, 1, "gdk_pixbuf_scale_simple", "GdkPixbuf*");
  XEN_ASSERT_TYPE(XEN_int_P(dest_width), dest_width, 2, "gdk_pixbuf_scale_simple", "int");
  XEN_ASSERT_TYPE(XEN_int_P(dest_height), dest_height, 3, "gdk_pixbuf_scale_simple", "int");
  XEN_ASSERT_TYPE(XEN_GdkInterpType_P(interp_type), interp_type, 4, "gdk_pixbuf_scale_simple", "GdkInterpType");
  return(C_TO_XEN_GdkPixbuf_(gdk_pixbuf_scale_simple(XEN_TO_C_GdkPixbuf_(src), XEN_TO_C_int(dest_width), XEN_TO_C_int(dest_height), 
                                                     XEN_TO_C_GdkInterpType(interp_type))));
}
static XEN gxg_gdk_pixbuf_composite_color_simple(XEN src, XEN dest_width, XEN dest_height, XEN interp_type, XEN overall_alpha, XEN check_size, XEN color1, XEN color2)
{
  #define H_gdk_pixbuf_composite_color_simple "GdkPixbuf* gdk_pixbuf_composite_color_simple(GdkPixbuf* src, \
int dest_width, int dest_height, GdkInterpType interp_type, int overall_alpha, int check_size, guint32 color1, \
guint32 color2)"
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(src), src, 1, "gdk_pixbuf_composite_color_simple", "GdkPixbuf*");
  XEN_ASSERT_TYPE(XEN_int_P(dest_width), dest_width, 2, "gdk_pixbuf_composite_color_simple", "int");
  XEN_ASSERT_TYPE(XEN_int_P(dest_height), dest_height, 3, "gdk_pixbuf_composite_color_simple", "int");
  XEN_ASSERT_TYPE(XEN_GdkInterpType_P(interp_type), interp_type, 4, "gdk_pixbuf_composite_color_simple", "GdkInterpType");
  XEN_ASSERT_TYPE(XEN_int_P(overall_alpha), overall_alpha, 5, "gdk_pixbuf_composite_color_simple", "int");
  XEN_ASSERT_TYPE(XEN_int_P(check_size), check_size, 6, "gdk_pixbuf_composite_color_simple", "int");
  XEN_ASSERT_TYPE(XEN_guint32_P(color1), color1, 7, "gdk_pixbuf_composite_color_simple", "guint32");
  XEN_ASSERT_TYPE(XEN_guint32_P(color2), color2, 8, "gdk_pixbuf_composite_color_simple", "guint32");
  return(C_TO_XEN_GdkPixbuf_(gdk_pixbuf_composite_color_simple(XEN_TO_C_GdkPixbuf_(src), XEN_TO_C_int(dest_width), XEN_TO_C_int(dest_height), 
                                                               XEN_TO_C_GdkInterpType(interp_type), XEN_TO_C_int(overall_alpha), 
                                                               XEN_TO_C_int(check_size), XEN_TO_C_guint32(color1), XEN_TO_C_guint32(color2))));
}
static XEN gxg_gdk_pixbuf_animation_get_type(void)
{
  #define H_gdk_pixbuf_animation_get_type "GType gdk_pixbuf_animation_get_type( void)"
  return(C_TO_XEN_GType(gdk_pixbuf_animation_get_type()));
}
static XEN gxg_gdk_pixbuf_animation_new_from_file(XEN filename, XEN error)
{
  #define H_gdk_pixbuf_animation_new_from_file "GdkPixbufAnimation* gdk_pixbuf_animation_new_from_file(char* filename, \
GError** [error])"
  GError* ref_error = NULL;
  XEN_ASSERT_TYPE(XEN_char__P(filename), filename, 1, "gdk_pixbuf_animation_new_from_file", "char*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_GdkPixbufAnimation_(gdk_pixbuf_animation_new_from_file(XEN_TO_C_char_(filename), &ref_error));
    return(XEN_LIST_2(result, C_TO_XEN_GError_(ref_error)));
   }
}
static XEN gxg_gdk_pixbuf_animation_get_width(XEN animation)
{
  #define H_gdk_pixbuf_animation_get_width "int gdk_pixbuf_animation_get_width(GdkPixbufAnimation* animation)"
  XEN_ASSERT_TYPE(XEN_GdkPixbufAnimation__P(animation), animation, 1, "gdk_pixbuf_animation_get_width", "GdkPixbufAnimation*");
  return(C_TO_XEN_int(gdk_pixbuf_animation_get_width(XEN_TO_C_GdkPixbufAnimation_(animation))));
}
static XEN gxg_gdk_pixbuf_animation_get_height(XEN animation)
{
  #define H_gdk_pixbuf_animation_get_height "int gdk_pixbuf_animation_get_height(GdkPixbufAnimation* animation)"
  XEN_ASSERT_TYPE(XEN_GdkPixbufAnimation__P(animation), animation, 1, "gdk_pixbuf_animation_get_height", "GdkPixbufAnimation*");
  return(C_TO_XEN_int(gdk_pixbuf_animation_get_height(XEN_TO_C_GdkPixbufAnimation_(animation))));
}
static XEN gxg_gdk_pixbuf_animation_is_static_image(XEN animation)
{
  #define H_gdk_pixbuf_animation_is_static_image "gboolean gdk_pixbuf_animation_is_static_image(GdkPixbufAnimation* animation)"
  XEN_ASSERT_TYPE(XEN_GdkPixbufAnimation__P(animation), animation, 1, "gdk_pixbuf_animation_is_static_image", "GdkPixbufAnimation*");
  return(C_TO_XEN_gboolean(gdk_pixbuf_animation_is_static_image(XEN_TO_C_GdkPixbufAnimation_(animation))));
}
static XEN gxg_gdk_pixbuf_animation_get_static_image(XEN animation)
{
  #define H_gdk_pixbuf_animation_get_static_image "GdkPixbuf* gdk_pixbuf_animation_get_static_image(GdkPixbufAnimation* animation)"
  XEN_ASSERT_TYPE(XEN_GdkPixbufAnimation__P(animation), animation, 1, "gdk_pixbuf_animation_get_static_image", "GdkPixbufAnimation*");
  return(C_TO_XEN_GdkPixbuf_(gdk_pixbuf_animation_get_static_image(XEN_TO_C_GdkPixbufAnimation_(animation))));
}
static XEN gxg_gdk_pixbuf_animation_get_iter(XEN animation, XEN start_time)
{
  #define H_gdk_pixbuf_animation_get_iter "GdkPixbufAnimationIter* gdk_pixbuf_animation_get_iter(GdkPixbufAnimation* animation, \
GTimeVal* start_time)"
  XEN_ASSERT_TYPE(XEN_GdkPixbufAnimation__P(animation), animation, 1, "gdk_pixbuf_animation_get_iter", "GdkPixbufAnimation*");
  XEN_ASSERT_TYPE(XEN_GTimeVal__P(start_time), start_time, 2, "gdk_pixbuf_animation_get_iter", "GTimeVal*");
  return(C_TO_XEN_GdkPixbufAnimationIter_(gdk_pixbuf_animation_get_iter(XEN_TO_C_GdkPixbufAnimation_(animation), XEN_TO_C_GTimeVal_(start_time))));
}
static XEN gxg_gdk_pixbuf_animation_iter_get_type(void)
{
  #define H_gdk_pixbuf_animation_iter_get_type "GType gdk_pixbuf_animation_iter_get_type( void)"
  return(C_TO_XEN_GType(gdk_pixbuf_animation_iter_get_type()));
}
static XEN gxg_gdk_pixbuf_animation_iter_get_delay_time(XEN iter)
{
  #define H_gdk_pixbuf_animation_iter_get_delay_time "int gdk_pixbuf_animation_iter_get_delay_time(GdkPixbufAnimationIter* iter)"
  XEN_ASSERT_TYPE(XEN_GdkPixbufAnimationIter__P(iter), iter, 1, "gdk_pixbuf_animation_iter_get_delay_time", "GdkPixbufAnimationIter*");
  return(C_TO_XEN_int(gdk_pixbuf_animation_iter_get_delay_time(XEN_TO_C_GdkPixbufAnimationIter_(iter))));
}
static XEN gxg_gdk_pixbuf_animation_iter_get_pixbuf(XEN iter)
{
  #define H_gdk_pixbuf_animation_iter_get_pixbuf "GdkPixbuf* gdk_pixbuf_animation_iter_get_pixbuf(GdkPixbufAnimationIter* iter)"
  XEN_ASSERT_TYPE(XEN_GdkPixbufAnimationIter__P(iter), iter, 1, "gdk_pixbuf_animation_iter_get_pixbuf", "GdkPixbufAnimationIter*");
  return(C_TO_XEN_GdkPixbuf_(gdk_pixbuf_animation_iter_get_pixbuf(XEN_TO_C_GdkPixbufAnimationIter_(iter))));
}
static XEN gxg_gdk_pixbuf_animation_iter_on_currently_loading_frame(XEN iter)
{
  #define H_gdk_pixbuf_animation_iter_on_currently_loading_frame "gboolean gdk_pixbuf_animation_iter_on_currently_loading_frame(GdkPixbufAnimationIter* iter)"
  XEN_ASSERT_TYPE(XEN_GdkPixbufAnimationIter__P(iter), iter, 1, "gdk_pixbuf_animation_iter_on_currently_loading_frame", "GdkPixbufAnimationIter*");
  return(C_TO_XEN_gboolean(gdk_pixbuf_animation_iter_on_currently_loading_frame(XEN_TO_C_GdkPixbufAnimationIter_(iter))));
}
static XEN gxg_gdk_pixbuf_animation_iter_advance(XEN iter, XEN current_time)
{
  #define H_gdk_pixbuf_animation_iter_advance "gboolean gdk_pixbuf_animation_iter_advance(GdkPixbufAnimationIter* iter, \
GTimeVal* current_time)"
  XEN_ASSERT_TYPE(XEN_GdkPixbufAnimationIter__P(iter), iter, 1, "gdk_pixbuf_animation_iter_advance", "GdkPixbufAnimationIter*");
  XEN_ASSERT_TYPE(XEN_GTimeVal__P(current_time), current_time, 2, "gdk_pixbuf_animation_iter_advance", "GTimeVal*");
  return(C_TO_XEN_gboolean(gdk_pixbuf_animation_iter_advance(XEN_TO_C_GdkPixbufAnimationIter_(iter), XEN_TO_C_GTimeVal_(current_time))));
}
static XEN gxg_gdk_pixbuf_get_option(XEN pixbuf, XEN key)
{
  #define H_gdk_pixbuf_get_option "gchar* gdk_pixbuf_get_option(GdkPixbuf* pixbuf, gchar* key)"
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(pixbuf), pixbuf, 1, "gdk_pixbuf_get_option", "GdkPixbuf*");
  XEN_ASSERT_TYPE(XEN_gchar__P(key), key, 2, "gdk_pixbuf_get_option", "gchar*");
  return(C_TO_XEN_gchar_(gdk_pixbuf_get_option(XEN_TO_C_GdkPixbuf_(pixbuf), XEN_TO_C_gchar_(key))));
}
static XEN gxg_gdk_pixbuf_loader_get_type(void)
{
  #define H_gdk_pixbuf_loader_get_type "GType gdk_pixbuf_loader_get_type( void)"
  return(C_TO_XEN_GType(gdk_pixbuf_loader_get_type()));
}
static XEN gxg_gdk_pixbuf_loader_new(void)
{
  #define H_gdk_pixbuf_loader_new "GdkPixbufLoader* gdk_pixbuf_loader_new( void)"
  return(C_TO_XEN_GdkPixbufLoader_(gdk_pixbuf_loader_new()));
}
static XEN gxg_gdk_pixbuf_loader_new_with_type(XEN image_type, XEN error)
{
  #define H_gdk_pixbuf_loader_new_with_type "GdkPixbufLoader* gdk_pixbuf_loader_new_with_type(char* image_type, \
GError** [error])"
  GError* ref_error = NULL;
  XEN_ASSERT_TYPE(XEN_char__P(image_type), image_type, 1, "gdk_pixbuf_loader_new_with_type", "char*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_GdkPixbufLoader_(gdk_pixbuf_loader_new_with_type(XEN_TO_C_char_(image_type), &ref_error));
    return(XEN_LIST_2(result, C_TO_XEN_GError_(ref_error)));
   }
}
static XEN gxg_gdk_pixbuf_loader_write(XEN loader, XEN buf, XEN count, XEN error)
{
  #define H_gdk_pixbuf_loader_write "gboolean gdk_pixbuf_loader_write(GdkPixbufLoader* loader, guchar* buf, \
gsize count, GError** [error])"
  GError* ref_error = NULL;
  XEN_ASSERT_TYPE(XEN_GdkPixbufLoader__P(loader), loader, 1, "gdk_pixbuf_loader_write", "GdkPixbufLoader*");
  XEN_ASSERT_TYPE(XEN_guchar__P(buf), buf, 2, "gdk_pixbuf_loader_write", "guchar*");
  XEN_ASSERT_TYPE(XEN_gsize_P(count), count, 3, "gdk_pixbuf_loader_write", "gsize");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gdk_pixbuf_loader_write(XEN_TO_C_GdkPixbufLoader_(loader), XEN_TO_C_guchar_(buf), XEN_TO_C_gsize(count), 
                                                       &ref_error));
    return(XEN_LIST_2(result, C_TO_XEN_GError_(ref_error)));
   }
}
static XEN gxg_gdk_pixbuf_loader_get_pixbuf(XEN loader)
{
  #define H_gdk_pixbuf_loader_get_pixbuf "GdkPixbuf* gdk_pixbuf_loader_get_pixbuf(GdkPixbufLoader* loader)"
  XEN_ASSERT_TYPE(XEN_GdkPixbufLoader__P(loader), loader, 1, "gdk_pixbuf_loader_get_pixbuf", "GdkPixbufLoader*");
  return(C_TO_XEN_GdkPixbuf_(gdk_pixbuf_loader_get_pixbuf(XEN_TO_C_GdkPixbufLoader_(loader))));
}
static XEN gxg_gdk_pixbuf_loader_get_animation(XEN loader)
{
  #define H_gdk_pixbuf_loader_get_animation "GdkPixbufAnimation* gdk_pixbuf_loader_get_animation(GdkPixbufLoader* loader)"
  XEN_ASSERT_TYPE(XEN_GdkPixbufLoader__P(loader), loader, 1, "gdk_pixbuf_loader_get_animation", "GdkPixbufLoader*");
  return(C_TO_XEN_GdkPixbufAnimation_(gdk_pixbuf_loader_get_animation(XEN_TO_C_GdkPixbufLoader_(loader))));
}
static XEN gxg_gdk_pixbuf_loader_close(XEN loader, XEN error)
{
  #define H_gdk_pixbuf_loader_close "gboolean gdk_pixbuf_loader_close(GdkPixbufLoader* loader, GError** [error])"
  GError* ref_error = NULL;
  XEN_ASSERT_TYPE(XEN_GdkPixbufLoader__P(loader), loader, 1, "gdk_pixbuf_loader_close", "GdkPixbufLoader*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gdk_pixbuf_loader_close(XEN_TO_C_GdkPixbufLoader_(loader), &ref_error));
    return(XEN_LIST_2(result, C_TO_XEN_GError_(ref_error)));
   }
}
static XEN gxg_gdk_pixbuf_alpha_mode_get_type(void)
{
  #define H_gdk_pixbuf_alpha_mode_get_type "GType gdk_pixbuf_alpha_mode_get_type( void)"
  return(C_TO_XEN_GType(gdk_pixbuf_alpha_mode_get_type()));
}
static XEN gxg_gdk_colorspace_get_type(void)
{
  #define H_gdk_colorspace_get_type "GType gdk_colorspace_get_type( void)"
  return(C_TO_XEN_GType(gdk_colorspace_get_type()));
}
static XEN gxg_gdk_pixbuf_error_get_type(void)
{
  #define H_gdk_pixbuf_error_get_type "GType gdk_pixbuf_error_get_type( void)"
  return(C_TO_XEN_GType(gdk_pixbuf_error_get_type()));
}
static XEN gxg_gdk_interp_type_get_type(void)
{
  #define H_gdk_interp_type_get_type "GType gdk_interp_type_get_type( void)"
  return(C_TO_XEN_GType(gdk_interp_type_get_type()));
}
static XEN gxg_gtk_vbox_get_type(void)
{
  #define H_gtk_vbox_get_type "GtkType gtk_vbox_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_vbox_get_type()));
}
static XEN gxg_gtk_vbox_new(XEN homogeneous, XEN spacing)
{
  #define H_gtk_vbox_new "GtkWidget* gtk_vbox_new(gboolean homogeneous, gint spacing)"
  XEN_ASSERT_TYPE(XEN_gboolean_P(homogeneous), homogeneous, 1, "gtk_vbox_new", "gboolean");
  XEN_ASSERT_TYPE(XEN_gint_P(spacing), spacing, 2, "gtk_vbox_new", "gint");
  return(C_TO_XEN_GtkWidget_(gtk_vbox_new(XEN_TO_C_gboolean(homogeneous), XEN_TO_C_gint(spacing))));
}
static XEN gxg_gtk_accel_group_get_type(void)
{
  #define H_gtk_accel_group_get_type "GType gtk_accel_group_get_type( void)"
  return(C_TO_XEN_GType(gtk_accel_group_get_type()));
}
static XEN gxg_gtk_accel_group_new(void)
{
  #define H_gtk_accel_group_new "GtkAccelGroup* gtk_accel_group_new( void)"
  return(C_TO_XEN_GtkAccelGroup_(gtk_accel_group_new()));
}
static XEN gxg_gtk_accel_group_lock(XEN accel_group)
{
  #define H_gtk_accel_group_lock "void gtk_accel_group_lock(GtkAccelGroup* accel_group)"
  XEN_ASSERT_TYPE(XEN_GtkAccelGroup__P(accel_group), accel_group, 1, "gtk_accel_group_lock", "GtkAccelGroup*");
  gtk_accel_group_lock(XEN_TO_C_GtkAccelGroup_(accel_group));
  return(XEN_FALSE);
}
static XEN gxg_gtk_accel_group_unlock(XEN accel_group)
{
  #define H_gtk_accel_group_unlock "void gtk_accel_group_unlock(GtkAccelGroup* accel_group)"
  XEN_ASSERT_TYPE(XEN_GtkAccelGroup__P(accel_group), accel_group, 1, "gtk_accel_group_unlock", "GtkAccelGroup*");
  gtk_accel_group_unlock(XEN_TO_C_GtkAccelGroup_(accel_group));
  return(XEN_FALSE);
}
static XEN gxg_gtk_accel_group_connect(XEN accel_group, XEN accel_key, XEN accel_mods, XEN accel_flags, XEN closure)
{
  #define H_gtk_accel_group_connect "void gtk_accel_group_connect(GtkAccelGroup* accel_group, guint accel_key, \
GdkModifierType accel_mods, GtkAccelFlags accel_flags, GClosure* closure)"
  XEN_ASSERT_TYPE(XEN_GtkAccelGroup__P(accel_group), accel_group, 1, "gtk_accel_group_connect", "GtkAccelGroup*");
  XEN_ASSERT_TYPE(XEN_guint_P(accel_key), accel_key, 2, "gtk_accel_group_connect", "guint");
  XEN_ASSERT_TYPE(XEN_GdkModifierType_P(accel_mods), accel_mods, 3, "gtk_accel_group_connect", "GdkModifierType");
  XEN_ASSERT_TYPE(XEN_GtkAccelFlags_P(accel_flags), accel_flags, 4, "gtk_accel_group_connect", "GtkAccelFlags");
  XEN_ASSERT_TYPE(XEN_GClosure__P(closure), closure, 5, "gtk_accel_group_connect", "GClosure*");
  gtk_accel_group_connect(XEN_TO_C_GtkAccelGroup_(accel_group), XEN_TO_C_guint(accel_key), XEN_TO_C_GdkModifierType(accel_mods), 
                          XEN_TO_C_GtkAccelFlags(accel_flags), XEN_TO_C_GClosure_(closure));
  return(XEN_FALSE);
}
static XEN gxg_gtk_accel_group_connect_by_path(XEN accel_group, XEN accel_path, XEN closure)
{
  #define H_gtk_accel_group_connect_by_path "void gtk_accel_group_connect_by_path(GtkAccelGroup* accel_group, \
gchar* accel_path, GClosure* closure)"
  XEN_ASSERT_TYPE(XEN_GtkAccelGroup__P(accel_group), accel_group, 1, "gtk_accel_group_connect_by_path", "GtkAccelGroup*");
  XEN_ASSERT_TYPE(XEN_gchar__P(accel_path), accel_path, 2, "gtk_accel_group_connect_by_path", "gchar*");
  XEN_ASSERT_TYPE(XEN_GClosure__P(closure), closure, 3, "gtk_accel_group_connect_by_path", "GClosure*");
  gtk_accel_group_connect_by_path(XEN_TO_C_GtkAccelGroup_(accel_group), XEN_TO_C_gchar_(accel_path), XEN_TO_C_GClosure_(closure));
  return(XEN_FALSE);
}
static XEN gxg_gtk_accel_group_disconnect(XEN accel_group, XEN closure)
{
  #define H_gtk_accel_group_disconnect "gboolean gtk_accel_group_disconnect(GtkAccelGroup* accel_group, \
GClosure* closure)"
  XEN_ASSERT_TYPE(XEN_GtkAccelGroup__P(accel_group), accel_group, 1, "gtk_accel_group_disconnect", "GtkAccelGroup*");
  XEN_ASSERT_TYPE(XEN_GClosure__P(closure), closure, 2, "gtk_accel_group_disconnect", "GClosure*");
  return(C_TO_XEN_gboolean(gtk_accel_group_disconnect(XEN_TO_C_GtkAccelGroup_(accel_group), XEN_TO_C_GClosure_(closure))));
}
static XEN gxg_gtk_accel_group_disconnect_key(XEN accel_group, XEN accel_key, XEN accel_mods)
{
  #define H_gtk_accel_group_disconnect_key "gboolean gtk_accel_group_disconnect_key(GtkAccelGroup* accel_group, \
guint accel_key, GdkModifierType accel_mods)"
  XEN_ASSERT_TYPE(XEN_GtkAccelGroup__P(accel_group), accel_group, 1, "gtk_accel_group_disconnect_key", "GtkAccelGroup*");
  XEN_ASSERT_TYPE(XEN_guint_P(accel_key), accel_key, 2, "gtk_accel_group_disconnect_key", "guint");
  XEN_ASSERT_TYPE(XEN_GdkModifierType_P(accel_mods), accel_mods, 3, "gtk_accel_group_disconnect_key", "GdkModifierType");
  return(C_TO_XEN_gboolean(gtk_accel_group_disconnect_key(XEN_TO_C_GtkAccelGroup_(accel_group), XEN_TO_C_guint(accel_key), 
                                                          XEN_TO_C_GdkModifierType(accel_mods))));
}
static XEN gxg_gtk_accel_groups_activate(XEN object, XEN accel_key, XEN accel_mods)
{
  #define H_gtk_accel_groups_activate "gboolean gtk_accel_groups_activate(GObject* object, guint accel_key, \
GdkModifierType accel_mods)"
  XEN_ASSERT_TYPE(XEN_GObject__P(object), object, 1, "gtk_accel_groups_activate", "GObject*");
  XEN_ASSERT_TYPE(XEN_guint_P(accel_key), accel_key, 2, "gtk_accel_groups_activate", "guint");
  XEN_ASSERT_TYPE(XEN_GdkModifierType_P(accel_mods), accel_mods, 3, "gtk_accel_groups_activate", "GdkModifierType");
  return(C_TO_XEN_gboolean(gtk_accel_groups_activate(XEN_TO_C_GObject_(object), XEN_TO_C_guint(accel_key), XEN_TO_C_GdkModifierType(accel_mods))));
}
static XEN gxg_gtk_accel_groups_from_object(XEN object)
{
  #define H_gtk_accel_groups_from_object "GSList* gtk_accel_groups_from_object(GObject* object)"
  XEN_ASSERT_TYPE(XEN_GObject__P(object), object, 1, "gtk_accel_groups_from_object", "GObject*");
  return(C_TO_XEN_GSList_(gtk_accel_groups_from_object(XEN_TO_C_GObject_(object))));
}
static XEN gxg_gtk_accel_group_find(XEN accel_group, XEN func, XEN func_data)
{
  #define H_gtk_accel_group_find "GtkAccelKey* gtk_accel_group_find(GtkAccelGroup* accel_group, lambda3 func, \
lambda_data func_data)"
  XEN_ASSERT_TYPE(XEN_GtkAccelGroup__P(accel_group), accel_group, 1, "gtk_accel_group_find", "GtkAccelGroup*");
  XEN_ASSERT_TYPE(XEN_lambda3_P(func), func, 2, "gtk_accel_group_find", "lambda3");
  if (XEN_NOT_BOUND_P(func_data)) func_data = XEN_FALSE; 
  else XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 3, "gtk_accel_group_find", "lambda_data");
  {
    XEN result = XEN_FALSE;
    int loc;
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    loc = xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 2, C_TO_XEN_INT(loc));
    result = C_TO_XEN_GtkAccelKey_(gtk_accel_group_find(XEN_TO_C_GtkAccelGroup_(accel_group), XEN_TO_C_lambda3(func), XEN_TO_C_lambda_data(func_data)));
    xm_unprotect_at(loc);
    return(result);
   }
}
static XEN gxg_gtk_accel_group_from_accel_closure(XEN closure)
{
  #define H_gtk_accel_group_from_accel_closure "GtkAccelGroup* gtk_accel_group_from_accel_closure(GClosure* closure)"
  XEN_ASSERT_TYPE(XEN_GClosure__P(closure), closure, 1, "gtk_accel_group_from_accel_closure", "GClosure*");
  return(C_TO_XEN_GtkAccelGroup_(gtk_accel_group_from_accel_closure(XEN_TO_C_GClosure_(closure))));
}
static XEN gxg_gtk_accelerator_valid(XEN keyval, XEN modifiers)
{
  #define H_gtk_accelerator_valid "gboolean gtk_accelerator_valid(guint keyval, GdkModifierType modifiers)"
  XEN_ASSERT_TYPE(XEN_guint_P(keyval), keyval, 1, "gtk_accelerator_valid", "guint");
  XEN_ASSERT_TYPE(XEN_GdkModifierType_P(modifiers), modifiers, 2, "gtk_accelerator_valid", "GdkModifierType");
  return(C_TO_XEN_gboolean(gtk_accelerator_valid(XEN_TO_C_guint(keyval), XEN_TO_C_GdkModifierType(modifiers))));
}
static XEN gxg_gtk_accelerator_parse(XEN accelerator, XEN accelerator_key, XEN accelerator_mods)
{
  #define H_gtk_accelerator_parse "void gtk_accelerator_parse(gchar* accelerator, guint* [accelerator_key], \
GdkModifierType* [accelerator_mods])"
  guint ref_accelerator_key;
  GdkModifierType ref_accelerator_mods;
  XEN_ASSERT_TYPE(XEN_gchar__P(accelerator), accelerator, 1, "gtk_accelerator_parse", "gchar*");
  gtk_accelerator_parse(XEN_TO_C_gchar_(accelerator), &ref_accelerator_key, &ref_accelerator_mods);
  return(XEN_LIST_2(C_TO_XEN_guint(ref_accelerator_key), C_TO_XEN_GdkModifierType(ref_accelerator_mods)));
}
static XEN gxg_gtk_accelerator_name(XEN accelerator_key, XEN accelerator_mods)
{
  #define H_gtk_accelerator_name "gchar* gtk_accelerator_name(guint accelerator_key, GdkModifierType accelerator_mods)"
  XEN_ASSERT_TYPE(XEN_guint_P(accelerator_key), accelerator_key, 1, "gtk_accelerator_name", "guint");
  XEN_ASSERT_TYPE(XEN_GdkModifierType_P(accelerator_mods), accelerator_mods, 2, "gtk_accelerator_name", "GdkModifierType");
  return(C_TO_XEN_gchar_(gtk_accelerator_name(XEN_TO_C_guint(accelerator_key), XEN_TO_C_GdkModifierType(accelerator_mods))));
}
static XEN gxg_gtk_accelerator_set_default_mod_mask(XEN default_mod_mask)
{
  #define H_gtk_accelerator_set_default_mod_mask "void gtk_accelerator_set_default_mod_mask(GdkModifierType default_mod_mask)"
  XEN_ASSERT_TYPE(XEN_GdkModifierType_P(default_mod_mask), default_mod_mask, 1, "gtk_accelerator_set_default_mod_mask", "GdkModifierType");
  gtk_accelerator_set_default_mod_mask(XEN_TO_C_GdkModifierType(default_mod_mask));
  return(XEN_FALSE);
}
static XEN gxg_gtk_accelerator_get_default_mod_mask(void)
{
  #define H_gtk_accelerator_get_default_mod_mask "guint gtk_accelerator_get_default_mod_mask( void)"
  return(C_TO_XEN_guint(gtk_accelerator_get_default_mod_mask()));
}
static XEN gxg_gtk_accel_group_query(XEN accel_group, XEN accel_key, XEN accel_mods, XEN n_entries)
{
  #define H_gtk_accel_group_query "GtkAccelGroupEntry* gtk_accel_group_query(GtkAccelGroup* accel_group, \
guint accel_key, GdkModifierType accel_mods, guint* [n_entries])"
  guint ref_n_entries;
  XEN_ASSERT_TYPE(XEN_GtkAccelGroup__P(accel_group), accel_group, 1, "gtk_accel_group_query", "GtkAccelGroup*");
  XEN_ASSERT_TYPE(XEN_guint_P(accel_key), accel_key, 2, "gtk_accel_group_query", "guint");
  XEN_ASSERT_TYPE(XEN_GdkModifierType_P(accel_mods), accel_mods, 3, "gtk_accel_group_query", "GdkModifierType");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_GtkAccelGroupEntry_(gtk_accel_group_query(XEN_TO_C_GtkAccelGroup_(accel_group), XEN_TO_C_guint(accel_key), 
                                                                XEN_TO_C_GdkModifierType(accel_mods), &ref_n_entries));
    return(XEN_LIST_2(result, C_TO_XEN_guint(ref_n_entries)));
   }
}
static XEN gxg_gtk_accel_label_get_type(void)
{
  #define H_gtk_accel_label_get_type "GtkType gtk_accel_label_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_accel_label_get_type()));
}
static XEN gxg_gtk_accel_label_new(XEN string)
{
  #define H_gtk_accel_label_new "GtkWidget* gtk_accel_label_new(gchar* string)"
  XEN_ASSERT_TYPE(XEN_gchar__P(string), string, 1, "gtk_accel_label_new", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_accel_label_new(XEN_TO_C_gchar_(string))));
}
static XEN gxg_gtk_accel_label_get_accel_widget(XEN accel_label)
{
  #define H_gtk_accel_label_get_accel_widget "GtkWidget* gtk_accel_label_get_accel_widget(GtkAccelLabel* accel_label)"
  XEN_ASSERT_TYPE(XEN_GtkAccelLabel__P(accel_label), accel_label, 1, "gtk_accel_label_get_accel_widget", "GtkAccelLabel*");
  return(C_TO_XEN_GtkWidget_(gtk_accel_label_get_accel_widget(XEN_TO_C_GtkAccelLabel_(accel_label))));
}
static XEN gxg_gtk_accel_label_get_accel_width(XEN accel_label)
{
  #define H_gtk_accel_label_get_accel_width "guint gtk_accel_label_get_accel_width(GtkAccelLabel* accel_label)"
  XEN_ASSERT_TYPE(XEN_GtkAccelLabel__P(accel_label), accel_label, 1, "gtk_accel_label_get_accel_width", "GtkAccelLabel*");
  return(C_TO_XEN_guint(gtk_accel_label_get_accel_width(XEN_TO_C_GtkAccelLabel_(accel_label))));
}
static XEN gxg_gtk_accel_label_set_accel_widget(XEN accel_label, XEN accel_widget)
{
  #define H_gtk_accel_label_set_accel_widget "void gtk_accel_label_set_accel_widget(GtkAccelLabel* accel_label, \
GtkWidget* accel_widget)"
  XEN_ASSERT_TYPE(XEN_GtkAccelLabel__P(accel_label), accel_label, 1, "gtk_accel_label_set_accel_widget", "GtkAccelLabel*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(accel_widget), accel_widget, 2, "gtk_accel_label_set_accel_widget", "GtkWidget*");
  gtk_accel_label_set_accel_widget(XEN_TO_C_GtkAccelLabel_(accel_label), XEN_TO_C_GtkWidget_(accel_widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_accel_label_set_accel_closure(XEN accel_label, XEN closure)
{
  #define H_gtk_accel_label_set_accel_closure "void gtk_accel_label_set_accel_closure(GtkAccelLabel* accel_label, \
GClosure* closure)"
  XEN_ASSERT_TYPE(XEN_GtkAccelLabel__P(accel_label), accel_label, 1, "gtk_accel_label_set_accel_closure", "GtkAccelLabel*");
  XEN_ASSERT_TYPE(XEN_GClosure__P(closure), closure, 2, "gtk_accel_label_set_accel_closure", "GClosure*");
  gtk_accel_label_set_accel_closure(XEN_TO_C_GtkAccelLabel_(accel_label), XEN_TO_C_GClosure_(closure));
  return(XEN_FALSE);
}
static XEN gxg_gtk_accel_label_refetch(XEN accel_label)
{
  #define H_gtk_accel_label_refetch "gboolean gtk_accel_label_refetch(GtkAccelLabel* accel_label)"
  XEN_ASSERT_TYPE(XEN_GtkAccelLabel__P(accel_label), accel_label, 1, "gtk_accel_label_refetch", "GtkAccelLabel*");
  return(C_TO_XEN_gboolean(gtk_accel_label_refetch(XEN_TO_C_GtkAccelLabel_(accel_label))));
}
static XEN gxg_gtk_accel_map_add_entry(XEN accel_path, XEN accel_key, XEN accel_mods)
{
  #define H_gtk_accel_map_add_entry "void gtk_accel_map_add_entry(gchar* accel_path, guint accel_key, \
GdkModifierType accel_mods)"
  XEN_ASSERT_TYPE(XEN_gchar__P(accel_path), accel_path, 1, "gtk_accel_map_add_entry", "gchar*");
  XEN_ASSERT_TYPE(XEN_guint_P(accel_key), accel_key, 2, "gtk_accel_map_add_entry", "guint");
  XEN_ASSERT_TYPE(XEN_GdkModifierType_P(accel_mods), accel_mods, 3, "gtk_accel_map_add_entry", "GdkModifierType");
  gtk_accel_map_add_entry(XEN_TO_C_gchar_(accel_path), XEN_TO_C_guint(accel_key), XEN_TO_C_GdkModifierType(accel_mods));
  return(XEN_FALSE);
}
static XEN gxg_gtk_accel_map_lookup_entry(XEN accel_path, XEN key)
{
  #define H_gtk_accel_map_lookup_entry "gboolean gtk_accel_map_lookup_entry(gchar* accel_path, GtkAccelKey* key)"
  XEN_ASSERT_TYPE(XEN_gchar__P(accel_path), accel_path, 1, "gtk_accel_map_lookup_entry", "gchar*");
  XEN_ASSERT_TYPE(XEN_GtkAccelKey__P(key), key, 2, "gtk_accel_map_lookup_entry", "GtkAccelKey*");
  return(C_TO_XEN_gboolean(gtk_accel_map_lookup_entry(XEN_TO_C_gchar_(accel_path), XEN_TO_C_GtkAccelKey_(key))));
}
static XEN gxg_gtk_accel_map_change_entry(XEN accel_path, XEN accel_key, XEN accel_mods, XEN replace)
{
  #define H_gtk_accel_map_change_entry "gboolean gtk_accel_map_change_entry(gchar* accel_path, guint accel_key, \
GdkModifierType accel_mods, gboolean replace)"
  XEN_ASSERT_TYPE(XEN_gchar__P(accel_path), accel_path, 1, "gtk_accel_map_change_entry", "gchar*");
  XEN_ASSERT_TYPE(XEN_guint_P(accel_key), accel_key, 2, "gtk_accel_map_change_entry", "guint");
  XEN_ASSERT_TYPE(XEN_GdkModifierType_P(accel_mods), accel_mods, 3, "gtk_accel_map_change_entry", "GdkModifierType");
  XEN_ASSERT_TYPE(XEN_gboolean_P(replace), replace, 4, "gtk_accel_map_change_entry", "gboolean");
  return(C_TO_XEN_gboolean(gtk_accel_map_change_entry(XEN_TO_C_gchar_(accel_path), XEN_TO_C_guint(accel_key), XEN_TO_C_GdkModifierType(accel_mods), 
                                                      XEN_TO_C_gboolean(replace))));
}
static XEN gxg_gtk_accel_map_load(XEN file_name)
{
  #define H_gtk_accel_map_load "void gtk_accel_map_load(gchar* file_name)"
  XEN_ASSERT_TYPE(XEN_gchar__P(file_name), file_name, 1, "gtk_accel_map_load", "gchar*");
  gtk_accel_map_load(XEN_TO_C_gchar_(file_name));
  return(XEN_FALSE);
}
static XEN gxg_gtk_accel_map_save(XEN file_name)
{
  #define H_gtk_accel_map_save "void gtk_accel_map_save(gchar* file_name)"
  XEN_ASSERT_TYPE(XEN_gchar__P(file_name), file_name, 1, "gtk_accel_map_save", "gchar*");
  gtk_accel_map_save(XEN_TO_C_gchar_(file_name));
  return(XEN_FALSE);
}
static XEN gxg_gtk_accel_map_foreach(XEN func_data, XEN func)
{
  #define H_gtk_accel_map_foreach "void gtk_accel_map_foreach(lambda_data func_data, GtkAccelMapForeach func)"
  XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 1, "gtk_accel_map_foreach", "lambda_data");
  XEN_ASSERT_TYPE(XEN_GtkAccelMapForeach_P(func), func, 2, "gtk_accel_map_foreach", "GtkAccelMapForeach");
  {
    int loc;
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    loc = xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 2, C_TO_XEN_INT(loc));
    gtk_accel_map_foreach(XEN_TO_C_lambda_data(func_data), XEN_TO_C_GtkAccelMapForeach(func));
    xm_unprotect_at(loc);
    return(XEN_FALSE);
   }
}
static XEN gxg_gtk_accel_map_load_fd(XEN fd)
{
  #define H_gtk_accel_map_load_fd "void gtk_accel_map_load_fd(gint fd)"
  XEN_ASSERT_TYPE(XEN_gint_P(fd), fd, 1, "gtk_accel_map_load_fd", "gint");
  gtk_accel_map_load_fd(XEN_TO_C_gint(fd));
  return(XEN_FALSE);
}
static XEN gxg_gtk_accel_map_load_scanner(XEN scanner)
{
  #define H_gtk_accel_map_load_scanner "void gtk_accel_map_load_scanner(GScanner* scanner)"
  XEN_ASSERT_TYPE(XEN_GScanner__P(scanner), scanner, 1, "gtk_accel_map_load_scanner", "GScanner*");
  gtk_accel_map_load_scanner(XEN_TO_C_GScanner_(scanner));
  return(XEN_FALSE);
}
static XEN gxg_gtk_accel_map_save_fd(XEN fd)
{
  #define H_gtk_accel_map_save_fd "void gtk_accel_map_save_fd(gint fd)"
  XEN_ASSERT_TYPE(XEN_gint_P(fd), fd, 1, "gtk_accel_map_save_fd", "gint");
  gtk_accel_map_save_fd(XEN_TO_C_gint(fd));
  return(XEN_FALSE);
}
static XEN gxg_gtk_accel_map_add_filter(XEN filter_pattern)
{
  #define H_gtk_accel_map_add_filter "void gtk_accel_map_add_filter(gchar* filter_pattern)"
  XEN_ASSERT_TYPE(XEN_gchar__P(filter_pattern), filter_pattern, 1, "gtk_accel_map_add_filter", "gchar*");
  gtk_accel_map_add_filter(XEN_TO_C_gchar_(filter_pattern));
  return(XEN_FALSE);
}
static XEN gxg_gtk_accel_map_foreach_unfiltered(XEN func_data, XEN func)
{
  #define H_gtk_accel_map_foreach_unfiltered "void gtk_accel_map_foreach_unfiltered(lambda_data func_data, \
GtkAccelMapForeach func)"
  XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 1, "gtk_accel_map_foreach_unfiltered", "lambda_data");
  XEN_ASSERT_TYPE(XEN_GtkAccelMapForeach_P(func), func, 2, "gtk_accel_map_foreach_unfiltered", "GtkAccelMapForeach");
  {
    int loc;
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    loc = xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 2, C_TO_XEN_INT(loc));
    gtk_accel_map_foreach_unfiltered(XEN_TO_C_lambda_data(func_data), XEN_TO_C_GtkAccelMapForeach(func));
    xm_unprotect_at(loc);
    return(XEN_FALSE);
   }
}
static XEN gxg_gtk_accessible_get_type(void)
{
  #define H_gtk_accessible_get_type "GtkType gtk_accessible_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_accessible_get_type()));
}
static XEN gxg_gtk_accessible_connect_widget_destroyed(XEN accessible)
{
  #define H_gtk_accessible_connect_widget_destroyed "void gtk_accessible_connect_widget_destroyed(GtkAccessible* accessible)"
  XEN_ASSERT_TYPE(XEN_GtkAccessible__P(accessible), accessible, 1, "gtk_accessible_connect_widget_destroyed", "GtkAccessible*");
  gtk_accessible_connect_widget_destroyed(XEN_TO_C_GtkAccessible_(accessible));
  return(XEN_FALSE);
}
static XEN gxg_gtk_adjustment_get_type(void)
{
  #define H_gtk_adjustment_get_type "GtkType gtk_adjustment_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_adjustment_get_type()));
}
static XEN gxg_gtk_adjustment_new(XEN value, XEN lower, XEN upper, XEN step_increment, XEN page_increment, XEN page_size)
{
  #define H_gtk_adjustment_new "GtkObject* gtk_adjustment_new(gdouble value, gdouble lower, gdouble upper, \
gdouble step_increment, gdouble page_increment, gdouble page_size)"
  XEN_ASSERT_TYPE(XEN_gdouble_P(value), value, 1, "gtk_adjustment_new", "gdouble");
  XEN_ASSERT_TYPE(XEN_gdouble_P(lower), lower, 2, "gtk_adjustment_new", "gdouble");
  XEN_ASSERT_TYPE(XEN_gdouble_P(upper), upper, 3, "gtk_adjustment_new", "gdouble");
  XEN_ASSERT_TYPE(XEN_gdouble_P(step_increment), step_increment, 4, "gtk_adjustment_new", "gdouble");
  XEN_ASSERT_TYPE(XEN_gdouble_P(page_increment), page_increment, 5, "gtk_adjustment_new", "gdouble");
  XEN_ASSERT_TYPE(XEN_gdouble_P(page_size), page_size, 6, "gtk_adjustment_new", "gdouble");
  return(C_TO_XEN_GtkObject_(gtk_adjustment_new(XEN_TO_C_gdouble(value), XEN_TO_C_gdouble(lower), XEN_TO_C_gdouble(upper), 
                                                XEN_TO_C_gdouble(step_increment), XEN_TO_C_gdouble(page_increment), XEN_TO_C_gdouble(page_size))));
}
static XEN gxg_gtk_adjustment_changed(XEN adjustment)
{
  #define H_gtk_adjustment_changed "void gtk_adjustment_changed(GtkAdjustment* adjustment)"
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(adjustment), adjustment, 1, "gtk_adjustment_changed", "GtkAdjustment*");
  gtk_adjustment_changed(XEN_TO_C_GtkAdjustment_(adjustment));
  return(XEN_FALSE);
}
static XEN gxg_gtk_adjustment_value_changed(XEN adjustment)
{
  #define H_gtk_adjustment_value_changed "void gtk_adjustment_value_changed(GtkAdjustment* adjustment)"
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(adjustment), adjustment, 1, "gtk_adjustment_value_changed", "GtkAdjustment*");
  gtk_adjustment_value_changed(XEN_TO_C_GtkAdjustment_(adjustment));
  return(XEN_FALSE);
}
static XEN gxg_gtk_adjustment_clamp_page(XEN adjustment, XEN lower, XEN upper)
{
  #define H_gtk_adjustment_clamp_page "void gtk_adjustment_clamp_page(GtkAdjustment* adjustment, gdouble lower, \
gdouble upper)"
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(adjustment), adjustment, 1, "gtk_adjustment_clamp_page", "GtkAdjustment*");
  XEN_ASSERT_TYPE(XEN_gdouble_P(lower), lower, 2, "gtk_adjustment_clamp_page", "gdouble");
  XEN_ASSERT_TYPE(XEN_gdouble_P(upper), upper, 3, "gtk_adjustment_clamp_page", "gdouble");
  gtk_adjustment_clamp_page(XEN_TO_C_GtkAdjustment_(adjustment), XEN_TO_C_gdouble(lower), XEN_TO_C_gdouble(upper));
  return(XEN_FALSE);
}
static XEN gxg_gtk_adjustment_get_value(XEN adjustment)
{
  #define H_gtk_adjustment_get_value "gdouble gtk_adjustment_get_value(GtkAdjustment* adjustment)"
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(adjustment), adjustment, 1, "gtk_adjustment_get_value", "GtkAdjustment*");
  return(C_TO_XEN_gdouble(gtk_adjustment_get_value(XEN_TO_C_GtkAdjustment_(adjustment))));
}
static XEN gxg_gtk_adjustment_set_value(XEN adjustment, XEN value)
{
  #define H_gtk_adjustment_set_value "void gtk_adjustment_set_value(GtkAdjustment* adjustment, gdouble value)"
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(adjustment), adjustment, 1, "gtk_adjustment_set_value", "GtkAdjustment*");
  XEN_ASSERT_TYPE(XEN_gdouble_P(value), value, 2, "gtk_adjustment_set_value", "gdouble");
  gtk_adjustment_set_value(XEN_TO_C_GtkAdjustment_(adjustment), XEN_TO_C_gdouble(value));
  return(XEN_FALSE);
}
static XEN gxg_gtk_alignment_get_type(void)
{
  #define H_gtk_alignment_get_type "GtkType gtk_alignment_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_alignment_get_type()));
}
static XEN gxg_gtk_alignment_new(XEN xalign, XEN yalign, XEN xscale, XEN yscale)
{
  #define H_gtk_alignment_new "GtkWidget* gtk_alignment_new(gfloat xalign, gfloat yalign, gfloat xscale, \
gfloat yscale)"
  XEN_ASSERT_TYPE(XEN_gfloat_P(xalign), xalign, 1, "gtk_alignment_new", "gfloat");
  XEN_ASSERT_TYPE(XEN_gfloat_P(yalign), yalign, 2, "gtk_alignment_new", "gfloat");
  XEN_ASSERT_TYPE(XEN_gfloat_P(xscale), xscale, 3, "gtk_alignment_new", "gfloat");
  XEN_ASSERT_TYPE(XEN_gfloat_P(yscale), yscale, 4, "gtk_alignment_new", "gfloat");
  return(C_TO_XEN_GtkWidget_(gtk_alignment_new(XEN_TO_C_gfloat(xalign), XEN_TO_C_gfloat(yalign), XEN_TO_C_gfloat(xscale), 
                                               XEN_TO_C_gfloat(yscale))));
}
static XEN gxg_gtk_alignment_set(XEN alignment, XEN xalign, XEN yalign, XEN xscale, XEN yscale)
{
  #define H_gtk_alignment_set "void gtk_alignment_set(GtkAlignment* alignment, gfloat xalign, gfloat yalign, \
gfloat xscale, gfloat yscale)"
  XEN_ASSERT_TYPE(XEN_GtkAlignment__P(alignment), alignment, 1, "gtk_alignment_set", "GtkAlignment*");
  XEN_ASSERT_TYPE(XEN_gfloat_P(xalign), xalign, 2, "gtk_alignment_set", "gfloat");
  XEN_ASSERT_TYPE(XEN_gfloat_P(yalign), yalign, 3, "gtk_alignment_set", "gfloat");
  XEN_ASSERT_TYPE(XEN_gfloat_P(xscale), xscale, 4, "gtk_alignment_set", "gfloat");
  XEN_ASSERT_TYPE(XEN_gfloat_P(yscale), yscale, 5, "gtk_alignment_set", "gfloat");
  gtk_alignment_set(XEN_TO_C_GtkAlignment_(alignment), XEN_TO_C_gfloat(xalign), XEN_TO_C_gfloat(yalign), XEN_TO_C_gfloat(xscale), 
                    XEN_TO_C_gfloat(yscale));
  return(XEN_FALSE);
}
static XEN gxg_gtk_arrow_get_type(void)
{
  #define H_gtk_arrow_get_type "GtkType gtk_arrow_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_arrow_get_type()));
}
static XEN gxg_gtk_arrow_new(XEN arrow_type, XEN shadow_type)
{
  #define H_gtk_arrow_new "GtkWidget* gtk_arrow_new(GtkArrowType arrow_type, GtkShadowType shadow_type)"
  XEN_ASSERT_TYPE(XEN_GtkArrowType_P(arrow_type), arrow_type, 1, "gtk_arrow_new", "GtkArrowType");
  XEN_ASSERT_TYPE(XEN_GtkShadowType_P(shadow_type), shadow_type, 2, "gtk_arrow_new", "GtkShadowType");
  return(C_TO_XEN_GtkWidget_(gtk_arrow_new(XEN_TO_C_GtkArrowType(arrow_type), XEN_TO_C_GtkShadowType(shadow_type))));
}
static XEN gxg_gtk_arrow_set(XEN arrow, XEN arrow_type, XEN shadow_type)
{
  #define H_gtk_arrow_set "void gtk_arrow_set(GtkArrow* arrow, GtkArrowType arrow_type, GtkShadowType shadow_type)"
  XEN_ASSERT_TYPE(XEN_GtkArrow__P(arrow), arrow, 1, "gtk_arrow_set", "GtkArrow*");
  XEN_ASSERT_TYPE(XEN_GtkArrowType_P(arrow_type), arrow_type, 2, "gtk_arrow_set", "GtkArrowType");
  XEN_ASSERT_TYPE(XEN_GtkShadowType_P(shadow_type), shadow_type, 3, "gtk_arrow_set", "GtkShadowType");
  gtk_arrow_set(XEN_TO_C_GtkArrow_(arrow), XEN_TO_C_GtkArrowType(arrow_type), XEN_TO_C_GtkShadowType(shadow_type));
  return(XEN_FALSE);
}
static XEN gxg_gtk_aspect_frame_get_type(void)
{
  #define H_gtk_aspect_frame_get_type "GtkType gtk_aspect_frame_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_aspect_frame_get_type()));
}
static XEN gxg_gtk_aspect_frame_new(XEN label, XEN xalign, XEN yalign, XEN ratio, XEN obey_child)
{
  #define H_gtk_aspect_frame_new "GtkWidget* gtk_aspect_frame_new(gchar* label, gfloat xalign, gfloat yalign, \
gfloat ratio, gboolean obey_child)"
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 1, "gtk_aspect_frame_new", "gchar*");
  XEN_ASSERT_TYPE(XEN_gfloat_P(xalign), xalign, 2, "gtk_aspect_frame_new", "gfloat");
  XEN_ASSERT_TYPE(XEN_gfloat_P(yalign), yalign, 3, "gtk_aspect_frame_new", "gfloat");
  XEN_ASSERT_TYPE(XEN_gfloat_P(ratio), ratio, 4, "gtk_aspect_frame_new", "gfloat");
  XEN_ASSERT_TYPE(XEN_gboolean_P(obey_child), obey_child, 5, "gtk_aspect_frame_new", "gboolean");
  return(C_TO_XEN_GtkWidget_(gtk_aspect_frame_new(XEN_TO_C_gchar_(label), XEN_TO_C_gfloat(xalign), XEN_TO_C_gfloat(yalign), 
                                                  XEN_TO_C_gfloat(ratio), XEN_TO_C_gboolean(obey_child))));
}
static XEN gxg_gtk_aspect_frame_set(XEN aspect_frame, XEN xalign, XEN yalign, XEN ratio, XEN obey_child)
{
  #define H_gtk_aspect_frame_set "void gtk_aspect_frame_set(GtkAspectFrame* aspect_frame, gfloat xalign, \
gfloat yalign, gfloat ratio, gboolean obey_child)"
  XEN_ASSERT_TYPE(XEN_GtkAspectFrame__P(aspect_frame), aspect_frame, 1, "gtk_aspect_frame_set", "GtkAspectFrame*");
  XEN_ASSERT_TYPE(XEN_gfloat_P(xalign), xalign, 2, "gtk_aspect_frame_set", "gfloat");
  XEN_ASSERT_TYPE(XEN_gfloat_P(yalign), yalign, 3, "gtk_aspect_frame_set", "gfloat");
  XEN_ASSERT_TYPE(XEN_gfloat_P(ratio), ratio, 4, "gtk_aspect_frame_set", "gfloat");
  XEN_ASSERT_TYPE(XEN_gboolean_P(obey_child), obey_child, 5, "gtk_aspect_frame_set", "gboolean");
  gtk_aspect_frame_set(XEN_TO_C_GtkAspectFrame_(aspect_frame), XEN_TO_C_gfloat(xalign), XEN_TO_C_gfloat(yalign), XEN_TO_C_gfloat(ratio), 
                       XEN_TO_C_gboolean(obey_child));
  return(XEN_FALSE);
}
static XEN gxg_gtk_button_box_get_type(void)
{
  #define H_gtk_button_box_get_type "GtkType gtk_button_box_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_button_box_get_type()));
}
static XEN gxg_gtk_button_box_get_layout(XEN widget)
{
  #define H_gtk_button_box_get_layout "GtkButtonBoxStyle gtk_button_box_get_layout(GtkButtonBox* widget)"
  XEN_ASSERT_TYPE(XEN_GtkButtonBox__P(widget), widget, 1, "gtk_button_box_get_layout", "GtkButtonBox*");
  return(C_TO_XEN_GtkButtonBoxStyle(gtk_button_box_get_layout(XEN_TO_C_GtkButtonBox_(widget))));
}
static XEN gxg_gtk_button_box_set_layout(XEN widget, XEN layout_style)
{
  #define H_gtk_button_box_set_layout "void gtk_button_box_set_layout(GtkButtonBox* widget, GtkButtonBoxStyle layout_style)"
  XEN_ASSERT_TYPE(XEN_GtkButtonBox__P(widget), widget, 1, "gtk_button_box_set_layout", "GtkButtonBox*");
  XEN_ASSERT_TYPE(XEN_GtkButtonBoxStyle_P(layout_style), layout_style, 2, "gtk_button_box_set_layout", "GtkButtonBoxStyle");
  gtk_button_box_set_layout(XEN_TO_C_GtkButtonBox_(widget), XEN_TO_C_GtkButtonBoxStyle(layout_style));
  return(XEN_FALSE);
}
static XEN gxg_gtk_button_box_set_child_secondary(XEN widget, XEN child, XEN is_secondary)
{
  #define H_gtk_button_box_set_child_secondary "void gtk_button_box_set_child_secondary(GtkButtonBox* widget, \
GtkWidget* child, gboolean is_secondary)"
  XEN_ASSERT_TYPE(XEN_GtkButtonBox__P(widget), widget, 1, "gtk_button_box_set_child_secondary", "GtkButtonBox*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_button_box_set_child_secondary", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(is_secondary), is_secondary, 3, "gtk_button_box_set_child_secondary", "gboolean");
  gtk_button_box_set_child_secondary(XEN_TO_C_GtkButtonBox_(widget), XEN_TO_C_GtkWidget_(child), XEN_TO_C_gboolean(is_secondary));
  return(XEN_FALSE);
}
static XEN gxg_gtk_binding_set_new(XEN set_name)
{
  #define H_gtk_binding_set_new "GtkBindingSet* gtk_binding_set_new(gchar* set_name)"
  XEN_ASSERT_TYPE(XEN_gchar__P(set_name), set_name, 1, "gtk_binding_set_new", "gchar*");
  return(C_TO_XEN_GtkBindingSet_(gtk_binding_set_new(XEN_TO_C_gchar_(set_name))));
}
static XEN gxg_gtk_binding_set_by_class(XEN object_class)
{
  #define H_gtk_binding_set_by_class "GtkBindingSet* gtk_binding_set_by_class(gpointer object_class)"
  XEN_ASSERT_TYPE(XEN_gpointer_P(object_class), object_class, 1, "gtk_binding_set_by_class", "gpointer");
  return(C_TO_XEN_GtkBindingSet_(gtk_binding_set_by_class(XEN_TO_C_gpointer(object_class))));
}
static XEN gxg_gtk_binding_set_find(XEN set_name)
{
  #define H_gtk_binding_set_find "GtkBindingSet* gtk_binding_set_find(gchar* set_name)"
  XEN_ASSERT_TYPE(XEN_gchar__P(set_name), set_name, 1, "gtk_binding_set_find", "gchar*");
  return(C_TO_XEN_GtkBindingSet_(gtk_binding_set_find(XEN_TO_C_gchar_(set_name))));
}
static XEN gxg_gtk_bindings_activate(XEN object, XEN keyval, XEN modifiers)
{
  #define H_gtk_bindings_activate "gboolean gtk_bindings_activate(GtkObject* object, guint keyval, GdkModifierType modifiers)"
  XEN_ASSERT_TYPE(XEN_GtkObject__P(object), object, 1, "gtk_bindings_activate", "GtkObject*");
  XEN_ASSERT_TYPE(XEN_guint_P(keyval), keyval, 2, "gtk_bindings_activate", "guint");
  XEN_ASSERT_TYPE(XEN_GdkModifierType_P(modifiers), modifiers, 3, "gtk_bindings_activate", "GdkModifierType");
  return(C_TO_XEN_gboolean(gtk_bindings_activate(XEN_TO_C_GtkObject_(object), XEN_TO_C_guint(keyval), XEN_TO_C_GdkModifierType(modifiers))));
}
static XEN gxg_gtk_binding_set_activate(XEN binding_set, XEN keyval, XEN modifiers, XEN object)
{
  #define H_gtk_binding_set_activate "gboolean gtk_binding_set_activate(GtkBindingSet* binding_set, guint keyval, \
GdkModifierType modifiers, GtkObject* object)"
  XEN_ASSERT_TYPE(XEN_GtkBindingSet__P(binding_set), binding_set, 1, "gtk_binding_set_activate", "GtkBindingSet*");
  XEN_ASSERT_TYPE(XEN_guint_P(keyval), keyval, 2, "gtk_binding_set_activate", "guint");
  XEN_ASSERT_TYPE(XEN_GdkModifierType_P(modifiers), modifiers, 3, "gtk_binding_set_activate", "GdkModifierType");
  XEN_ASSERT_TYPE(XEN_GtkObject__P(object), object, 4, "gtk_binding_set_activate", "GtkObject*");
  return(C_TO_XEN_gboolean(gtk_binding_set_activate(XEN_TO_C_GtkBindingSet_(binding_set), XEN_TO_C_guint(keyval), XEN_TO_C_GdkModifierType(modifiers), 
                                                    XEN_TO_C_GtkObject_(object))));
}
static XEN gxg_gtk_binding_entry_clear(XEN binding_set, XEN keyval, XEN modifiers)
{
  #define H_gtk_binding_entry_clear "void gtk_binding_entry_clear(GtkBindingSet* binding_set, guint keyval, \
GdkModifierType modifiers)"
  XEN_ASSERT_TYPE(XEN_GtkBindingSet__P(binding_set), binding_set, 1, "gtk_binding_entry_clear", "GtkBindingSet*");
  XEN_ASSERT_TYPE(XEN_guint_P(keyval), keyval, 2, "gtk_binding_entry_clear", "guint");
  XEN_ASSERT_TYPE(XEN_GdkModifierType_P(modifiers), modifiers, 3, "gtk_binding_entry_clear", "GdkModifierType");
  gtk_binding_entry_clear(XEN_TO_C_GtkBindingSet_(binding_set), XEN_TO_C_guint(keyval), XEN_TO_C_GdkModifierType(modifiers));
  return(XEN_FALSE);
}
static XEN gxg_gtk_binding_set_add_path(XEN binding_set, XEN path_type, XEN path_pattern, XEN priority)
{
  #define H_gtk_binding_set_add_path "void gtk_binding_set_add_path(GtkBindingSet* binding_set, GtkPathType path_type, \
gchar* path_pattern, GtkPathPriorityType priority)"
  XEN_ASSERT_TYPE(XEN_GtkBindingSet__P(binding_set), binding_set, 1, "gtk_binding_set_add_path", "GtkBindingSet*");
  XEN_ASSERT_TYPE(XEN_GtkPathType_P(path_type), path_type, 2, "gtk_binding_set_add_path", "GtkPathType");
  XEN_ASSERT_TYPE(XEN_gchar__P(path_pattern), path_pattern, 3, "gtk_binding_set_add_path", "gchar*");
  XEN_ASSERT_TYPE(XEN_GtkPathPriorityType_P(priority), priority, 4, "gtk_binding_set_add_path", "GtkPathPriorityType");
  gtk_binding_set_add_path(XEN_TO_C_GtkBindingSet_(binding_set), XEN_TO_C_GtkPathType(path_type), XEN_TO_C_gchar_(path_pattern), 
                           XEN_TO_C_GtkPathPriorityType(priority));
  return(XEN_FALSE);
}
static XEN gxg_gtk_binding_entry_remove(XEN binding_set, XEN keyval, XEN modifiers)
{
  #define H_gtk_binding_entry_remove "void gtk_binding_entry_remove(GtkBindingSet* binding_set, guint keyval, \
GdkModifierType modifiers)"
  XEN_ASSERT_TYPE(XEN_GtkBindingSet__P(binding_set), binding_set, 1, "gtk_binding_entry_remove", "GtkBindingSet*");
  XEN_ASSERT_TYPE(XEN_guint_P(keyval), keyval, 2, "gtk_binding_entry_remove", "guint");
  XEN_ASSERT_TYPE(XEN_GdkModifierType_P(modifiers), modifiers, 3, "gtk_binding_entry_remove", "GdkModifierType");
  gtk_binding_entry_remove(XEN_TO_C_GtkBindingSet_(binding_set), XEN_TO_C_guint(keyval), XEN_TO_C_GdkModifierType(modifiers));
  return(XEN_FALSE);
}
static XEN gxg_gtk_binding_entry_add_signall(XEN binding_set, XEN keyval, XEN modifiers, XEN signal_name, XEN binding_args)
{
  #define H_gtk_binding_entry_add_signall "void gtk_binding_entry_add_signall(GtkBindingSet* binding_set, \
guint keyval, GdkModifierType modifiers, gchar* signal_name, GSList* binding_args)"
  XEN_ASSERT_TYPE(XEN_GtkBindingSet__P(binding_set), binding_set, 1, "gtk_binding_entry_add_signall", "GtkBindingSet*");
  XEN_ASSERT_TYPE(XEN_guint_P(keyval), keyval, 2, "gtk_binding_entry_add_signall", "guint");
  XEN_ASSERT_TYPE(XEN_GdkModifierType_P(modifiers), modifiers, 3, "gtk_binding_entry_add_signall", "GdkModifierType");
  XEN_ASSERT_TYPE(XEN_gchar__P(signal_name), signal_name, 4, "gtk_binding_entry_add_signall", "gchar*");
  XEN_ASSERT_TYPE(XEN_GSList__P(binding_args), binding_args, 5, "gtk_binding_entry_add_signall", "GSList*");
  gtk_binding_entry_add_signall(XEN_TO_C_GtkBindingSet_(binding_set), XEN_TO_C_guint(keyval), XEN_TO_C_GdkModifierType(modifiers), 
                                XEN_TO_C_gchar_(signal_name), XEN_TO_C_GSList_(binding_args));
  return(XEN_FALSE);
}
static XEN gxg_gtk_binding_parse_binding(XEN scanner)
{
  #define H_gtk_binding_parse_binding "guint gtk_binding_parse_binding(GScanner* scanner)"
  XEN_ASSERT_TYPE(XEN_GScanner__P(scanner), scanner, 1, "gtk_binding_parse_binding", "GScanner*");
  return(C_TO_XEN_guint(gtk_binding_parse_binding(XEN_TO_C_GScanner_(scanner))));
}
static XEN gxg_gtk_bin_get_type(void)
{
  #define H_gtk_bin_get_type "GtkType gtk_bin_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_bin_get_type()));
}
static XEN gxg_gtk_bin_get_child(XEN bin)
{
  #define H_gtk_bin_get_child "GtkWidget* gtk_bin_get_child(GtkBin* bin)"
  XEN_ASSERT_TYPE(XEN_GtkBin__P(bin), bin, 1, "gtk_bin_get_child", "GtkBin*");
  return(C_TO_XEN_GtkWidget_(gtk_bin_get_child(XEN_TO_C_GtkBin_(bin))));
}
static XEN gxg_gtk_box_get_type(void)
{
  #define H_gtk_box_get_type "GtkType gtk_box_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_box_get_type()));
}
static XEN gxg_gtk_box_pack_start(XEN box, XEN child, XEN expand, XEN fill, XEN padding)
{
  #define H_gtk_box_pack_start "void gtk_box_pack_start(GtkBox* box, GtkWidget* child, gboolean expand, \
gboolean fill, guint padding)"
  XEN_ASSERT_TYPE(XEN_GtkBox__P(box), box, 1, "gtk_box_pack_start", "GtkBox*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_box_pack_start", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(expand), expand, 3, "gtk_box_pack_start", "gboolean");
  XEN_ASSERT_TYPE(XEN_gboolean_P(fill), fill, 4, "gtk_box_pack_start", "gboolean");
  XEN_ASSERT_TYPE(XEN_guint_P(padding), padding, 5, "gtk_box_pack_start", "guint");
  gtk_box_pack_start(XEN_TO_C_GtkBox_(box), XEN_TO_C_GtkWidget_(child), XEN_TO_C_gboolean(expand), XEN_TO_C_gboolean(fill), 
                     XEN_TO_C_guint(padding));
  return(XEN_FALSE);
}
static XEN gxg_gtk_box_pack_end(XEN box, XEN child, XEN expand, XEN fill, XEN padding)
{
  #define H_gtk_box_pack_end "void gtk_box_pack_end(GtkBox* box, GtkWidget* child, gboolean expand, gboolean fill, \
guint padding)"
  XEN_ASSERT_TYPE(XEN_GtkBox__P(box), box, 1, "gtk_box_pack_end", "GtkBox*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_box_pack_end", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(expand), expand, 3, "gtk_box_pack_end", "gboolean");
  XEN_ASSERT_TYPE(XEN_gboolean_P(fill), fill, 4, "gtk_box_pack_end", "gboolean");
  XEN_ASSERT_TYPE(XEN_guint_P(padding), padding, 5, "gtk_box_pack_end", "guint");
  gtk_box_pack_end(XEN_TO_C_GtkBox_(box), XEN_TO_C_GtkWidget_(child), XEN_TO_C_gboolean(expand), XEN_TO_C_gboolean(fill), 
                   XEN_TO_C_guint(padding));
  return(XEN_FALSE);
}
static XEN gxg_gtk_box_pack_start_defaults(XEN box, XEN widget)
{
  #define H_gtk_box_pack_start_defaults "void gtk_box_pack_start_defaults(GtkBox* box, GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkBox__P(box), box, 1, "gtk_box_pack_start_defaults", "GtkBox*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 2, "gtk_box_pack_start_defaults", "GtkWidget*");
  gtk_box_pack_start_defaults(XEN_TO_C_GtkBox_(box), XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_box_pack_end_defaults(XEN box, XEN widget)
{
  #define H_gtk_box_pack_end_defaults "void gtk_box_pack_end_defaults(GtkBox* box, GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkBox__P(box), box, 1, "gtk_box_pack_end_defaults", "GtkBox*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 2, "gtk_box_pack_end_defaults", "GtkWidget*");
  gtk_box_pack_end_defaults(XEN_TO_C_GtkBox_(box), XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_box_set_homogeneous(XEN box, XEN homogeneous)
{
  #define H_gtk_box_set_homogeneous "void gtk_box_set_homogeneous(GtkBox* box, gboolean homogeneous)"
  XEN_ASSERT_TYPE(XEN_GtkBox__P(box), box, 1, "gtk_box_set_homogeneous", "GtkBox*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(homogeneous), homogeneous, 2, "gtk_box_set_homogeneous", "gboolean");
  gtk_box_set_homogeneous(XEN_TO_C_GtkBox_(box), XEN_TO_C_gboolean(homogeneous));
  return(XEN_FALSE);
}
static XEN gxg_gtk_box_get_homogeneous(XEN box)
{
  #define H_gtk_box_get_homogeneous "gboolean gtk_box_get_homogeneous(GtkBox* box)"
  XEN_ASSERT_TYPE(XEN_GtkBox__P(box), box, 1, "gtk_box_get_homogeneous", "GtkBox*");
  return(C_TO_XEN_gboolean(gtk_box_get_homogeneous(XEN_TO_C_GtkBox_(box))));
}
static XEN gxg_gtk_box_set_spacing(XEN box, XEN spacing)
{
  #define H_gtk_box_set_spacing "void gtk_box_set_spacing(GtkBox* box, gint spacing)"
  XEN_ASSERT_TYPE(XEN_GtkBox__P(box), box, 1, "gtk_box_set_spacing", "GtkBox*");
  XEN_ASSERT_TYPE(XEN_gint_P(spacing), spacing, 2, "gtk_box_set_spacing", "gint");
  gtk_box_set_spacing(XEN_TO_C_GtkBox_(box), XEN_TO_C_gint(spacing));
  return(XEN_FALSE);
}
static XEN gxg_gtk_box_get_spacing(XEN box)
{
  #define H_gtk_box_get_spacing "gint gtk_box_get_spacing(GtkBox* box)"
  XEN_ASSERT_TYPE(XEN_GtkBox__P(box), box, 1, "gtk_box_get_spacing", "GtkBox*");
  return(C_TO_XEN_gint(gtk_box_get_spacing(XEN_TO_C_GtkBox_(box))));
}
static XEN gxg_gtk_box_reorder_child(XEN box, XEN child, XEN position)
{
  #define H_gtk_box_reorder_child "void gtk_box_reorder_child(GtkBox* box, GtkWidget* child, gint position)"
  XEN_ASSERT_TYPE(XEN_GtkBox__P(box), box, 1, "gtk_box_reorder_child", "GtkBox*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_box_reorder_child", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gint_P(position), position, 3, "gtk_box_reorder_child", "gint");
  gtk_box_reorder_child(XEN_TO_C_GtkBox_(box), XEN_TO_C_GtkWidget_(child), XEN_TO_C_gint(position));
  return(XEN_FALSE);
}
static XEN gxg_gtk_box_query_child_packing(XEN box, XEN child, XEN expand, XEN fill, XEN padding, XEN pack_type)
{
  #define H_gtk_box_query_child_packing "void gtk_box_query_child_packing(GtkBox* box, GtkWidget* child, \
gboolean* [expand], gboolean* [fill], guint* [padding], GtkPackType* [pack_type])"
  gboolean ref_expand;
  gboolean ref_fill;
  guint ref_padding;
  GtkPackType ref_pack_type;
  XEN_ASSERT_TYPE(XEN_GtkBox__P(box), box, 1, "gtk_box_query_child_packing", "GtkBox*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_box_query_child_packing", "GtkWidget*");
  gtk_box_query_child_packing(XEN_TO_C_GtkBox_(box), XEN_TO_C_GtkWidget_(child), &ref_expand, &ref_fill, &ref_padding, &ref_pack_type);
  return(XEN_LIST_4(C_TO_XEN_gboolean(ref_expand), C_TO_XEN_gboolean(ref_fill), C_TO_XEN_guint(ref_padding), C_TO_XEN_GtkPackType(ref_pack_type)));
}
static XEN gxg_gtk_box_set_child_packing(XEN box, XEN child, XEN expand, XEN fill, XEN padding, XEN pack_type)
{
  #define H_gtk_box_set_child_packing "void gtk_box_set_child_packing(GtkBox* box, GtkWidget* child, \
gboolean expand, gboolean fill, guint padding, GtkPackType pack_type)"
  XEN_ASSERT_TYPE(XEN_GtkBox__P(box), box, 1, "gtk_box_set_child_packing", "GtkBox*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_box_set_child_packing", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(expand), expand, 3, "gtk_box_set_child_packing", "gboolean");
  XEN_ASSERT_TYPE(XEN_gboolean_P(fill), fill, 4, "gtk_box_set_child_packing", "gboolean");
  XEN_ASSERT_TYPE(XEN_guint_P(padding), padding, 5, "gtk_box_set_child_packing", "guint");
  XEN_ASSERT_TYPE(XEN_GtkPackType_P(pack_type), pack_type, 6, "gtk_box_set_child_packing", "GtkPackType");
  gtk_box_set_child_packing(XEN_TO_C_GtkBox_(box), XEN_TO_C_GtkWidget_(child), XEN_TO_C_gboolean(expand), XEN_TO_C_gboolean(fill), 
                            XEN_TO_C_guint(padding), XEN_TO_C_GtkPackType(pack_type));
  return(XEN_FALSE);
}
static XEN gxg_gtk_button_get_type(void)
{
  #define H_gtk_button_get_type "GtkType gtk_button_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_button_get_type()));
}
static XEN gxg_gtk_button_new(void)
{
  #define H_gtk_button_new "GtkWidget* gtk_button_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_button_new()));
}
static XEN gxg_gtk_button_new_with_label(XEN label)
{
  #define H_gtk_button_new_with_label "GtkWidget* gtk_button_new_with_label(gchar* label)"
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 1, "gtk_button_new_with_label", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_button_new_with_label(XEN_TO_C_gchar_(label))));
}
static XEN gxg_gtk_button_new_from_stock(XEN stock_id)
{
  #define H_gtk_button_new_from_stock "GtkWidget* gtk_button_new_from_stock(gchar* stock_id)"
  XEN_ASSERT_TYPE(XEN_gchar__P(stock_id), stock_id, 1, "gtk_button_new_from_stock", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_button_new_from_stock(XEN_TO_C_gchar_(stock_id))));
}
static XEN gxg_gtk_button_new_with_mnemonic(XEN label)
{
  #define H_gtk_button_new_with_mnemonic "GtkWidget* gtk_button_new_with_mnemonic(gchar* label)"
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 1, "gtk_button_new_with_mnemonic", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_button_new_with_mnemonic(XEN_TO_C_gchar_(label))));
}
static XEN gxg_gtk_button_pressed(XEN button)
{
  #define H_gtk_button_pressed "void gtk_button_pressed(GtkButton* button)"
  XEN_ASSERT_TYPE(XEN_GtkButton__P(button), button, 1, "gtk_button_pressed", "GtkButton*");
  gtk_button_pressed(XEN_TO_C_GtkButton_(button));
  return(XEN_FALSE);
}
static XEN gxg_gtk_button_released(XEN button)
{
  #define H_gtk_button_released "void gtk_button_released(GtkButton* button)"
  XEN_ASSERT_TYPE(XEN_GtkButton__P(button), button, 1, "gtk_button_released", "GtkButton*");
  gtk_button_released(XEN_TO_C_GtkButton_(button));
  return(XEN_FALSE);
}
static XEN gxg_gtk_button_clicked(XEN button)
{
  #define H_gtk_button_clicked "void gtk_button_clicked(GtkButton* button)"
  XEN_ASSERT_TYPE(XEN_GtkButton__P(button), button, 1, "gtk_button_clicked", "GtkButton*");
  gtk_button_clicked(XEN_TO_C_GtkButton_(button));
  return(XEN_FALSE);
}
static XEN gxg_gtk_button_enter(XEN button)
{
  #define H_gtk_button_enter "void gtk_button_enter(GtkButton* button)"
  XEN_ASSERT_TYPE(XEN_GtkButton__P(button), button, 1, "gtk_button_enter", "GtkButton*");
  gtk_button_enter(XEN_TO_C_GtkButton_(button));
  return(XEN_FALSE);
}
static XEN gxg_gtk_button_leave(XEN button)
{
  #define H_gtk_button_leave "void gtk_button_leave(GtkButton* button)"
  XEN_ASSERT_TYPE(XEN_GtkButton__P(button), button, 1, "gtk_button_leave", "GtkButton*");
  gtk_button_leave(XEN_TO_C_GtkButton_(button));
  return(XEN_FALSE);
}
static XEN gxg_gtk_button_set_relief(XEN button, XEN newstyle)
{
  #define H_gtk_button_set_relief "void gtk_button_set_relief(GtkButton* button, GtkReliefStyle newstyle)"
  XEN_ASSERT_TYPE(XEN_GtkButton__P(button), button, 1, "gtk_button_set_relief", "GtkButton*");
  XEN_ASSERT_TYPE(XEN_GtkReliefStyle_P(newstyle), newstyle, 2, "gtk_button_set_relief", "GtkReliefStyle");
  gtk_button_set_relief(XEN_TO_C_GtkButton_(button), XEN_TO_C_GtkReliefStyle(newstyle));
  return(XEN_FALSE);
}
static XEN gxg_gtk_button_get_relief(XEN button)
{
  #define H_gtk_button_get_relief "GtkReliefStyle gtk_button_get_relief(GtkButton* button)"
  XEN_ASSERT_TYPE(XEN_GtkButton__P(button), button, 1, "gtk_button_get_relief", "GtkButton*");
  return(C_TO_XEN_GtkReliefStyle(gtk_button_get_relief(XEN_TO_C_GtkButton_(button))));
}
static XEN gxg_gtk_button_set_label(XEN button, XEN label)
{
  #define H_gtk_button_set_label "void gtk_button_set_label(GtkButton* button, gchar* label)"
  XEN_ASSERT_TYPE(XEN_GtkButton__P(button), button, 1, "gtk_button_set_label", "GtkButton*");
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 2, "gtk_button_set_label", "gchar*");
  gtk_button_set_label(XEN_TO_C_GtkButton_(button), XEN_TO_C_gchar_(label));
  return(XEN_FALSE);
}
static XEN gxg_gtk_button_get_label(XEN button)
{
  #define H_gtk_button_get_label "gchar* gtk_button_get_label(GtkButton* button)"
  XEN_ASSERT_TYPE(XEN_GtkButton__P(button), button, 1, "gtk_button_get_label", "GtkButton*");
  return(C_TO_XEN_gchar_(gtk_button_get_label(XEN_TO_C_GtkButton_(button))));
}
static XEN gxg_gtk_button_set_use_underline(XEN button, XEN use_underline)
{
  #define H_gtk_button_set_use_underline "void gtk_button_set_use_underline(GtkButton* button, gboolean use_underline)"
  XEN_ASSERT_TYPE(XEN_GtkButton__P(button), button, 1, "gtk_button_set_use_underline", "GtkButton*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(use_underline), use_underline, 2, "gtk_button_set_use_underline", "gboolean");
  gtk_button_set_use_underline(XEN_TO_C_GtkButton_(button), XEN_TO_C_gboolean(use_underline));
  return(XEN_FALSE);
}
static XEN gxg_gtk_button_get_use_underline(XEN button)
{
  #define H_gtk_button_get_use_underline "gboolean gtk_button_get_use_underline(GtkButton* button)"
  XEN_ASSERT_TYPE(XEN_GtkButton__P(button), button, 1, "gtk_button_get_use_underline", "GtkButton*");
  return(C_TO_XEN_gboolean(gtk_button_get_use_underline(XEN_TO_C_GtkButton_(button))));
}
static XEN gxg_gtk_button_set_use_stock(XEN button, XEN use_stock)
{
  #define H_gtk_button_set_use_stock "void gtk_button_set_use_stock(GtkButton* button, gboolean use_stock)"
  XEN_ASSERT_TYPE(XEN_GtkButton__P(button), button, 1, "gtk_button_set_use_stock", "GtkButton*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(use_stock), use_stock, 2, "gtk_button_set_use_stock", "gboolean");
  gtk_button_set_use_stock(XEN_TO_C_GtkButton_(button), XEN_TO_C_gboolean(use_stock));
  return(XEN_FALSE);
}
static XEN gxg_gtk_button_get_use_stock(XEN button)
{
  #define H_gtk_button_get_use_stock "gboolean gtk_button_get_use_stock(GtkButton* button)"
  XEN_ASSERT_TYPE(XEN_GtkButton__P(button), button, 1, "gtk_button_get_use_stock", "GtkButton*");
  return(C_TO_XEN_gboolean(gtk_button_get_use_stock(XEN_TO_C_GtkButton_(button))));
}
static XEN gxg_gtk_calendar_get_type(void)
{
  #define H_gtk_calendar_get_type "GtkType gtk_calendar_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_calendar_get_type()));
}
static XEN gxg_gtk_calendar_new(void)
{
  #define H_gtk_calendar_new "GtkWidget* gtk_calendar_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_calendar_new()));
}
static XEN gxg_gtk_calendar_select_month(XEN calendar, XEN month, XEN year)
{
  #define H_gtk_calendar_select_month "gboolean gtk_calendar_select_month(GtkCalendar* calendar, guint month, \
guint year)"
  XEN_ASSERT_TYPE(XEN_GtkCalendar__P(calendar), calendar, 1, "gtk_calendar_select_month", "GtkCalendar*");
  XEN_ASSERT_TYPE(XEN_guint_P(month), month, 2, "gtk_calendar_select_month", "guint");
  XEN_ASSERT_TYPE(XEN_guint_P(year), year, 3, "gtk_calendar_select_month", "guint");
  return(C_TO_XEN_gboolean(gtk_calendar_select_month(XEN_TO_C_GtkCalendar_(calendar), XEN_TO_C_guint(month), XEN_TO_C_guint(year))));
}
static XEN gxg_gtk_calendar_select_day(XEN calendar, XEN day)
{
  #define H_gtk_calendar_select_day "void gtk_calendar_select_day(GtkCalendar* calendar, guint day)"
  XEN_ASSERT_TYPE(XEN_GtkCalendar__P(calendar), calendar, 1, "gtk_calendar_select_day", "GtkCalendar*");
  XEN_ASSERT_TYPE(XEN_guint_P(day), day, 2, "gtk_calendar_select_day", "guint");
  gtk_calendar_select_day(XEN_TO_C_GtkCalendar_(calendar), XEN_TO_C_guint(day));
  return(XEN_FALSE);
}
static XEN gxg_gtk_calendar_mark_day(XEN calendar, XEN day)
{
  #define H_gtk_calendar_mark_day "gboolean gtk_calendar_mark_day(GtkCalendar* calendar, guint day)"
  XEN_ASSERT_TYPE(XEN_GtkCalendar__P(calendar), calendar, 1, "gtk_calendar_mark_day", "GtkCalendar*");
  XEN_ASSERT_TYPE(XEN_guint_P(day), day, 2, "gtk_calendar_mark_day", "guint");
  return(C_TO_XEN_gboolean(gtk_calendar_mark_day(XEN_TO_C_GtkCalendar_(calendar), XEN_TO_C_guint(day))));
}
static XEN gxg_gtk_calendar_unmark_day(XEN calendar, XEN day)
{
  #define H_gtk_calendar_unmark_day "gboolean gtk_calendar_unmark_day(GtkCalendar* calendar, guint day)"
  XEN_ASSERT_TYPE(XEN_GtkCalendar__P(calendar), calendar, 1, "gtk_calendar_unmark_day", "GtkCalendar*");
  XEN_ASSERT_TYPE(XEN_guint_P(day), day, 2, "gtk_calendar_unmark_day", "guint");
  return(C_TO_XEN_gboolean(gtk_calendar_unmark_day(XEN_TO_C_GtkCalendar_(calendar), XEN_TO_C_guint(day))));
}
static XEN gxg_gtk_calendar_clear_marks(XEN calendar)
{
  #define H_gtk_calendar_clear_marks "void gtk_calendar_clear_marks(GtkCalendar* calendar)"
  XEN_ASSERT_TYPE(XEN_GtkCalendar__P(calendar), calendar, 1, "gtk_calendar_clear_marks", "GtkCalendar*");
  gtk_calendar_clear_marks(XEN_TO_C_GtkCalendar_(calendar));
  return(XEN_FALSE);
}
static XEN gxg_gtk_calendar_get_date(XEN calendar, XEN year, XEN month, XEN day)
{
  #define H_gtk_calendar_get_date "void gtk_calendar_get_date(GtkCalendar* calendar, guint* [year], guint* [month], \
guint* [day])"
  guint ref_year;
  guint ref_month;
  guint ref_day;
  XEN_ASSERT_TYPE(XEN_GtkCalendar__P(calendar), calendar, 1, "gtk_calendar_get_date", "GtkCalendar*");
  gtk_calendar_get_date(XEN_TO_C_GtkCalendar_(calendar), &ref_year, &ref_month, &ref_day);
  return(XEN_LIST_3(C_TO_XEN_guint(ref_year), C_TO_XEN_guint(ref_month), C_TO_XEN_guint(ref_day)));
}
static XEN gxg_gtk_calendar_freeze(XEN calendar)
{
  #define H_gtk_calendar_freeze "void gtk_calendar_freeze(GtkCalendar* calendar)"
  XEN_ASSERT_TYPE(XEN_GtkCalendar__P(calendar), calendar, 1, "gtk_calendar_freeze", "GtkCalendar*");
  gtk_calendar_freeze(XEN_TO_C_GtkCalendar_(calendar));
  return(XEN_FALSE);
}
static XEN gxg_gtk_calendar_thaw(XEN calendar)
{
  #define H_gtk_calendar_thaw "void gtk_calendar_thaw(GtkCalendar* calendar)"
  XEN_ASSERT_TYPE(XEN_GtkCalendar__P(calendar), calendar, 1, "gtk_calendar_thaw", "GtkCalendar*");
  gtk_calendar_thaw(XEN_TO_C_GtkCalendar_(calendar));
  return(XEN_FALSE);
}
static XEN gxg_gtk_cell_editable_get_type(void)
{
  #define H_gtk_cell_editable_get_type "GType gtk_cell_editable_get_type( void)"
  return(C_TO_XEN_GType(gtk_cell_editable_get_type()));
}
static XEN gxg_gtk_cell_editable_start_editing(XEN cell_editable, XEN event)
{
  #define H_gtk_cell_editable_start_editing "void gtk_cell_editable_start_editing(GtkCellEditable* cell_editable, \
GdkEvent* event)"
  XEN_ASSERT_TYPE(XEN_GtkCellEditable__P(cell_editable), cell_editable, 1, "gtk_cell_editable_start_editing", "GtkCellEditable*");
  XEN_ASSERT_TYPE(XEN_GdkEvent__P(event) || XEN_FALSE_P(event), event, 2, "gtk_cell_editable_start_editing", "GdkEvent*");
  gtk_cell_editable_start_editing(XEN_TO_C_GtkCellEditable_(cell_editable), XEN_TO_C_GdkEvent_(event));
  return(XEN_FALSE);
}
static XEN gxg_gtk_cell_editable_editing_done(XEN cell_editable)
{
  #define H_gtk_cell_editable_editing_done "void gtk_cell_editable_editing_done(GtkCellEditable* cell_editable)"
  XEN_ASSERT_TYPE(XEN_GtkCellEditable__P(cell_editable), cell_editable, 1, "gtk_cell_editable_editing_done", "GtkCellEditable*");
  gtk_cell_editable_editing_done(XEN_TO_C_GtkCellEditable_(cell_editable));
  return(XEN_FALSE);
}
static XEN gxg_gtk_cell_editable_remove_widget(XEN cell_editable)
{
  #define H_gtk_cell_editable_remove_widget "void gtk_cell_editable_remove_widget(GtkCellEditable* cell_editable)"
  XEN_ASSERT_TYPE(XEN_GtkCellEditable__P(cell_editable), cell_editable, 1, "gtk_cell_editable_remove_widget", "GtkCellEditable*");
  gtk_cell_editable_remove_widget(XEN_TO_C_GtkCellEditable_(cell_editable));
  return(XEN_FALSE);
}
static XEN gxg_gtk_cell_renderer_get_type(void)
{
  #define H_gtk_cell_renderer_get_type "GType gtk_cell_renderer_get_type( void)"
  return(C_TO_XEN_GType(gtk_cell_renderer_get_type()));
}
static XEN gxg_gtk_cell_renderer_get_size(XEN cell, XEN widget, XEN cell_area, XEN x_offset, XEN y_offset, XEN width, XEN height)
{
  #define H_gtk_cell_renderer_get_size "void gtk_cell_renderer_get_size(GtkCellRenderer* cell, GtkWidget* widget, \
GdkRectangle* cell_area, gint* [x_offset], gint* [y_offset], gint* [width], gint* [height])"
  gint ref_x_offset;
  gint ref_y_offset;
  gint ref_width;
  gint ref_height;
  XEN_ASSERT_TYPE(XEN_GtkCellRenderer__P(cell), cell, 1, "gtk_cell_renderer_get_size", "GtkCellRenderer*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 2, "gtk_cell_renderer_get_size", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(cell_area) || XEN_FALSE_P(cell_area), cell_area, 3, "gtk_cell_renderer_get_size", "GdkRectangle*");
  gtk_cell_renderer_get_size(XEN_TO_C_GtkCellRenderer_(cell), XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GdkRectangle_(cell_area), 
                             &ref_x_offset, &ref_y_offset, &ref_width, &ref_height);
  return(XEN_LIST_4(C_TO_XEN_gint(ref_x_offset), C_TO_XEN_gint(ref_y_offset), C_TO_XEN_gint(ref_width), C_TO_XEN_gint(ref_height)));
}
static XEN gxg_gtk_cell_renderer_render(XEN cell, XEN window, XEN widget, XEN background_area, XEN cell_area, XEN expose_area, XEN flags)
{
  #define H_gtk_cell_renderer_render "void gtk_cell_renderer_render(GtkCellRenderer* cell, GdkWindow* window, \
GtkWidget* widget, GdkRectangle* background_area, GdkRectangle* cell_area, GdkRectangle* expose_area, \
GtkCellRendererState flags)"
  XEN_ASSERT_TYPE(XEN_GtkCellRenderer__P(cell), cell, 1, "gtk_cell_renderer_render", "GtkCellRenderer*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 2, "gtk_cell_renderer_render", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 3, "gtk_cell_renderer_render", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(background_area), background_area, 4, "gtk_cell_renderer_render", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(cell_area), cell_area, 5, "gtk_cell_renderer_render", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(expose_area), expose_area, 6, "gtk_cell_renderer_render", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GtkCellRendererState_P(flags), flags, 7, "gtk_cell_renderer_render", "GtkCellRendererState");
  gtk_cell_renderer_render(XEN_TO_C_GtkCellRenderer_(cell), XEN_TO_C_GdkWindow_(window), XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GdkRectangle_(background_area), 
                           XEN_TO_C_GdkRectangle_(cell_area), XEN_TO_C_GdkRectangle_(expose_area), XEN_TO_C_GtkCellRendererState(flags));
  return(XEN_FALSE);
}
static XEN gxg_gtk_cell_renderer_activate(XEN cell, XEN event, XEN widget, XEN path, XEN background_area, XEN cell_area, XEN flags)
{
  #define H_gtk_cell_renderer_activate "gboolean gtk_cell_renderer_activate(GtkCellRenderer* cell, GdkEvent* event, \
GtkWidget* widget, gchar* path, GdkRectangle* background_area, GdkRectangle* cell_area, GtkCellRendererState flags)"
  XEN_ASSERT_TYPE(XEN_GtkCellRenderer__P(cell), cell, 1, "gtk_cell_renderer_activate", "GtkCellRenderer*");
  XEN_ASSERT_TYPE(XEN_GdkEvent__P(event), event, 2, "gtk_cell_renderer_activate", "GdkEvent*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 3, "gtk_cell_renderer_activate", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(path), path, 4, "gtk_cell_renderer_activate", "gchar*");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(background_area), background_area, 5, "gtk_cell_renderer_activate", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(cell_area), cell_area, 6, "gtk_cell_renderer_activate", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GtkCellRendererState_P(flags), flags, 7, "gtk_cell_renderer_activate", "GtkCellRendererState");
  return(C_TO_XEN_gboolean(gtk_cell_renderer_activate(XEN_TO_C_GtkCellRenderer_(cell), XEN_TO_C_GdkEvent_(event), XEN_TO_C_GtkWidget_(widget), 
                                                      XEN_TO_C_gchar_(path), XEN_TO_C_GdkRectangle_(background_area), XEN_TO_C_GdkRectangle_(cell_area), 
                                                      XEN_TO_C_GtkCellRendererState(flags))));
}
static XEN gxg_gtk_cell_renderer_start_editing(XEN cell, XEN event, XEN widget, XEN path, XEN background_area, XEN cell_area, XEN flags)
{
  #define H_gtk_cell_renderer_start_editing "GtkCellEditable* gtk_cell_renderer_start_editing(GtkCellRenderer* cell, \
GdkEvent* event, GtkWidget* widget, gchar* path, GdkRectangle* background_area, GdkRectangle* cell_area, \
GtkCellRendererState flags)"
  XEN_ASSERT_TYPE(XEN_GtkCellRenderer__P(cell), cell, 1, "gtk_cell_renderer_start_editing", "GtkCellRenderer*");
  XEN_ASSERT_TYPE(XEN_GdkEvent__P(event), event, 2, "gtk_cell_renderer_start_editing", "GdkEvent*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 3, "gtk_cell_renderer_start_editing", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(path), path, 4, "gtk_cell_renderer_start_editing", "gchar*");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(background_area), background_area, 5, "gtk_cell_renderer_start_editing", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(cell_area), cell_area, 6, "gtk_cell_renderer_start_editing", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GtkCellRendererState_P(flags), flags, 7, "gtk_cell_renderer_start_editing", "GtkCellRendererState");
  return(C_TO_XEN_GtkCellEditable_(gtk_cell_renderer_start_editing(XEN_TO_C_GtkCellRenderer_(cell), XEN_TO_C_GdkEvent_(event), 
                                                                   XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(path), XEN_TO_C_GdkRectangle_(background_area), 
                                                                   XEN_TO_C_GdkRectangle_(cell_area), XEN_TO_C_GtkCellRendererState(flags))));
}
static XEN gxg_gtk_cell_renderer_set_fixed_size(XEN cell, XEN width, XEN height)
{
  #define H_gtk_cell_renderer_set_fixed_size "void gtk_cell_renderer_set_fixed_size(GtkCellRenderer* cell, \
gint width, gint height)"
  XEN_ASSERT_TYPE(XEN_GtkCellRenderer__P(cell), cell, 1, "gtk_cell_renderer_set_fixed_size", "GtkCellRenderer*");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 2, "gtk_cell_renderer_set_fixed_size", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 3, "gtk_cell_renderer_set_fixed_size", "gint");
  gtk_cell_renderer_set_fixed_size(XEN_TO_C_GtkCellRenderer_(cell), XEN_TO_C_gint(width), XEN_TO_C_gint(height));
  return(XEN_FALSE);
}
static XEN gxg_gtk_cell_renderer_get_fixed_size(XEN cell, XEN width, XEN height)
{
  #define H_gtk_cell_renderer_get_fixed_size "void gtk_cell_renderer_get_fixed_size(GtkCellRenderer* cell, \
gint* [width], gint* [height])"
  gint ref_width;
  gint ref_height;
  XEN_ASSERT_TYPE(XEN_GtkCellRenderer__P(cell), cell, 1, "gtk_cell_renderer_get_fixed_size", "GtkCellRenderer*");
  gtk_cell_renderer_get_fixed_size(XEN_TO_C_GtkCellRenderer_(cell), &ref_width, &ref_height);
  return(XEN_LIST_2(C_TO_XEN_gint(ref_width), C_TO_XEN_gint(ref_height)));
}
static XEN gxg_gtk_cell_renderer_pixbuf_get_type(void)
{
  #define H_gtk_cell_renderer_pixbuf_get_type "GtkType gtk_cell_renderer_pixbuf_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_cell_renderer_pixbuf_get_type()));
}
static XEN gxg_gtk_cell_renderer_pixbuf_new(void)
{
  #define H_gtk_cell_renderer_pixbuf_new "GtkCellRenderer* gtk_cell_renderer_pixbuf_new( void)"
  return(C_TO_XEN_GtkCellRenderer_(gtk_cell_renderer_pixbuf_new()));
}
static XEN gxg_gtk_cell_renderer_text_get_type(void)
{
  #define H_gtk_cell_renderer_text_get_type "GtkType gtk_cell_renderer_text_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_cell_renderer_text_get_type()));
}
static XEN gxg_gtk_cell_renderer_text_new(void)
{
  #define H_gtk_cell_renderer_text_new "GtkCellRenderer* gtk_cell_renderer_text_new( void)"
  return(C_TO_XEN_GtkCellRenderer_(gtk_cell_renderer_text_new()));
}
static XEN gxg_gtk_cell_renderer_text_set_fixed_height_from_font(XEN renderer, XEN number_of_rows)
{
  #define H_gtk_cell_renderer_text_set_fixed_height_from_font "void gtk_cell_renderer_text_set_fixed_height_from_font(GtkCellRendererText* renderer, \
gint number_of_rows)"
  XEN_ASSERT_TYPE(XEN_GtkCellRendererText__P(renderer), renderer, 1, "gtk_cell_renderer_text_set_fixed_height_from_font", "GtkCellRendererText*");
  XEN_ASSERT_TYPE(XEN_gint_P(number_of_rows), number_of_rows, 2, "gtk_cell_renderer_text_set_fixed_height_from_font", "gint");
  gtk_cell_renderer_text_set_fixed_height_from_font(XEN_TO_C_GtkCellRendererText_(renderer), XEN_TO_C_gint(number_of_rows));
  return(XEN_FALSE);
}
static XEN gxg_gtk_cell_renderer_toggle_get_type(void)
{
  #define H_gtk_cell_renderer_toggle_get_type "GtkType gtk_cell_renderer_toggle_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_cell_renderer_toggle_get_type()));
}
static XEN gxg_gtk_cell_renderer_toggle_new(void)
{
  #define H_gtk_cell_renderer_toggle_new "GtkCellRenderer* gtk_cell_renderer_toggle_new( void)"
  return(C_TO_XEN_GtkCellRenderer_(gtk_cell_renderer_toggle_new()));
}
static XEN gxg_gtk_cell_renderer_toggle_get_radio(XEN toggle)
{
  #define H_gtk_cell_renderer_toggle_get_radio "gboolean gtk_cell_renderer_toggle_get_radio(GtkCellRendererToggle* toggle)"
  XEN_ASSERT_TYPE(XEN_GtkCellRendererToggle__P(toggle), toggle, 1, "gtk_cell_renderer_toggle_get_radio", "GtkCellRendererToggle*");
  return(C_TO_XEN_gboolean(gtk_cell_renderer_toggle_get_radio(XEN_TO_C_GtkCellRendererToggle_(toggle))));
}
static XEN gxg_gtk_cell_renderer_toggle_set_radio(XEN toggle, XEN radio)
{
  #define H_gtk_cell_renderer_toggle_set_radio "void gtk_cell_renderer_toggle_set_radio(GtkCellRendererToggle* toggle, \
gboolean radio)"
  XEN_ASSERT_TYPE(XEN_GtkCellRendererToggle__P(toggle), toggle, 1, "gtk_cell_renderer_toggle_set_radio", "GtkCellRendererToggle*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(radio), radio, 2, "gtk_cell_renderer_toggle_set_radio", "gboolean");
  gtk_cell_renderer_toggle_set_radio(XEN_TO_C_GtkCellRendererToggle_(toggle), XEN_TO_C_gboolean(radio));
  return(XEN_FALSE);
}
static XEN gxg_gtk_cell_renderer_toggle_get_active(XEN toggle)
{
  #define H_gtk_cell_renderer_toggle_get_active "gboolean gtk_cell_renderer_toggle_get_active(GtkCellRendererToggle* toggle)"
  XEN_ASSERT_TYPE(XEN_GtkCellRendererToggle__P(toggle), toggle, 1, "gtk_cell_renderer_toggle_get_active", "GtkCellRendererToggle*");
  return(C_TO_XEN_gboolean(gtk_cell_renderer_toggle_get_active(XEN_TO_C_GtkCellRendererToggle_(toggle))));
}
static XEN gxg_gtk_cell_renderer_toggle_set_active(XEN toggle, XEN setting)
{
  #define H_gtk_cell_renderer_toggle_set_active "void gtk_cell_renderer_toggle_set_active(GtkCellRendererToggle* toggle, \
gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GtkCellRendererToggle__P(toggle), toggle, 1, "gtk_cell_renderer_toggle_set_active", "GtkCellRendererToggle*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gtk_cell_renderer_toggle_set_active", "gboolean");
  gtk_cell_renderer_toggle_set_active(XEN_TO_C_GtkCellRendererToggle_(toggle), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_check_button_get_type(void)
{
  #define H_gtk_check_button_get_type "GtkType gtk_check_button_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_check_button_get_type()));
}
static XEN gxg_gtk_check_button_new(void)
{
  #define H_gtk_check_button_new "GtkWidget* gtk_check_button_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_check_button_new()));
}
static XEN gxg_gtk_check_button_new_with_label(XEN label)
{
  #define H_gtk_check_button_new_with_label "GtkWidget* gtk_check_button_new_with_label(gchar* label)"
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 1, "gtk_check_button_new_with_label", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_check_button_new_with_label(XEN_TO_C_gchar_(label))));
}
static XEN gxg_gtk_check_button_new_with_mnemonic(XEN label)
{
  #define H_gtk_check_button_new_with_mnemonic "GtkWidget* gtk_check_button_new_with_mnemonic(gchar* label)"
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 1, "gtk_check_button_new_with_mnemonic", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_check_button_new_with_mnemonic(XEN_TO_C_gchar_(label))));
}
static XEN gxg_gtk_check_menu_item_get_type(void)
{
  #define H_gtk_check_menu_item_get_type "GtkType gtk_check_menu_item_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_check_menu_item_get_type()));
}
static XEN gxg_gtk_check_menu_item_new(void)
{
  #define H_gtk_check_menu_item_new "GtkWidget* gtk_check_menu_item_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_check_menu_item_new()));
}
static XEN gxg_gtk_check_menu_item_new_with_label(XEN label)
{
  #define H_gtk_check_menu_item_new_with_label "GtkWidget* gtk_check_menu_item_new_with_label(gchar* label)"
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 1, "gtk_check_menu_item_new_with_label", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_check_menu_item_new_with_label(XEN_TO_C_gchar_(label))));
}
static XEN gxg_gtk_check_menu_item_new_with_mnemonic(XEN label)
{
  #define H_gtk_check_menu_item_new_with_mnemonic "GtkWidget* gtk_check_menu_item_new_with_mnemonic(gchar* label)"
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 1, "gtk_check_menu_item_new_with_mnemonic", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_check_menu_item_new_with_mnemonic(XEN_TO_C_gchar_(label))));
}
static XEN gxg_gtk_check_menu_item_set_active(XEN check_menu_item, XEN is_active)
{
  #define H_gtk_check_menu_item_set_active "void gtk_check_menu_item_set_active(GtkCheckMenuItem* check_menu_item, \
gboolean is_active)"
  XEN_ASSERT_TYPE(XEN_GtkCheckMenuItem__P(check_menu_item), check_menu_item, 1, "gtk_check_menu_item_set_active", "GtkCheckMenuItem*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(is_active), is_active, 2, "gtk_check_menu_item_set_active", "gboolean");
  gtk_check_menu_item_set_active(XEN_TO_C_GtkCheckMenuItem_(check_menu_item), XEN_TO_C_gboolean(is_active));
  return(XEN_FALSE);
}
static XEN gxg_gtk_check_menu_item_get_active(XEN check_menu_item)
{
  #define H_gtk_check_menu_item_get_active "gboolean gtk_check_menu_item_get_active(GtkCheckMenuItem* check_menu_item)"
  XEN_ASSERT_TYPE(XEN_GtkCheckMenuItem__P(check_menu_item), check_menu_item, 1, "gtk_check_menu_item_get_active", "GtkCheckMenuItem*");
  return(C_TO_XEN_gboolean(gtk_check_menu_item_get_active(XEN_TO_C_GtkCheckMenuItem_(check_menu_item))));
}
static XEN gxg_gtk_check_menu_item_toggled(XEN check_menu_item)
{
  #define H_gtk_check_menu_item_toggled "void gtk_check_menu_item_toggled(GtkCheckMenuItem* check_menu_item)"
  XEN_ASSERT_TYPE(XEN_GtkCheckMenuItem__P(check_menu_item), check_menu_item, 1, "gtk_check_menu_item_toggled", "GtkCheckMenuItem*");
  gtk_check_menu_item_toggled(XEN_TO_C_GtkCheckMenuItem_(check_menu_item));
  return(XEN_FALSE);
}
static XEN gxg_gtk_check_menu_item_set_inconsistent(XEN check_menu_item, XEN setting)
{
  #define H_gtk_check_menu_item_set_inconsistent "void gtk_check_menu_item_set_inconsistent(GtkCheckMenuItem* check_menu_item, \
gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GtkCheckMenuItem__P(check_menu_item), check_menu_item, 1, "gtk_check_menu_item_set_inconsistent", "GtkCheckMenuItem*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gtk_check_menu_item_set_inconsistent", "gboolean");
  gtk_check_menu_item_set_inconsistent(XEN_TO_C_GtkCheckMenuItem_(check_menu_item), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_check_menu_item_get_inconsistent(XEN check_menu_item)
{
  #define H_gtk_check_menu_item_get_inconsistent "gboolean gtk_check_menu_item_get_inconsistent(GtkCheckMenuItem* check_menu_item)"
  XEN_ASSERT_TYPE(XEN_GtkCheckMenuItem__P(check_menu_item), check_menu_item, 1, "gtk_check_menu_item_get_inconsistent", "GtkCheckMenuItem*");
  return(C_TO_XEN_gboolean(gtk_check_menu_item_get_inconsistent(XEN_TO_C_GtkCheckMenuItem_(check_menu_item))));
}
static XEN gxg_gtk_clipboard_get(XEN selection)
{
  #define H_gtk_clipboard_get "GtkClipboard* gtk_clipboard_get(GdkAtom selection)"
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(selection), selection, 1, "gtk_clipboard_get", "GdkAtom");
  return(C_TO_XEN_GtkClipboard_(gtk_clipboard_get(XEN_TO_C_GdkAtom(selection))));
}
static XEN gxg_gtk_clipboard_set_with_data(XEN clipboard, XEN targets, XEN n_targets, XEN func, XEN clear_func, XEN func_data)
{
  #define H_gtk_clipboard_set_with_data "gboolean gtk_clipboard_set_with_data(GtkClipboard* clipboard, \
GtkTargetEntry* targets, guint n_targets, GtkClipboardGetFunc func, GtkClipboardClearFunc clear_func, \
lambda_data func_data)"
  XEN_ASSERT_TYPE(XEN_GtkClipboard__P(clipboard), clipboard, 1, "gtk_clipboard_set_with_data", "GtkClipboard*");
  XEN_ASSERT_TYPE(XEN_GtkTargetEntry__P(targets), targets, 2, "gtk_clipboard_set_with_data", "GtkTargetEntry*");
  XEN_ASSERT_TYPE(XEN_guint_P(n_targets), n_targets, 3, "gtk_clipboard_set_with_data", "guint");
  XEN_ASSERT_TYPE(XEN_GtkClipboardGetFunc_P(func), func, 4, "gtk_clipboard_set_with_data", "GtkClipboardGetFunc");
  XEN_ASSERT_TYPE(XEN_GtkClipboardClearFunc_P(clear_func), clear_func, 5, "gtk_clipboard_set_with_data", "GtkClipboardClearFunc");
  if (XEN_NOT_BOUND_P(func_data)) func_data = XEN_FALSE; 
  else XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 6, "gtk_clipboard_set_with_data", "lambda_data");
  {
    XEN result = XEN_FALSE;
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 2, clear_func);
    result = C_TO_XEN_gboolean(gtk_clipboard_set_with_data(XEN_TO_C_GtkClipboard_(clipboard), XEN_TO_C_GtkTargetEntry_(targets), 
                                                           XEN_TO_C_guint(n_targets), XEN_TO_C_GtkClipboardGetFunc(func), 
                                                           XEN_TO_C_GtkClipboardClearFunc(clear_func), XEN_TO_C_lambda_data(func_data)));
    return(result);
   }
}
static XEN gxg_gtk_clipboard_get_owner(XEN clipboard)
{
  #define H_gtk_clipboard_get_owner "GObject* gtk_clipboard_get_owner(GtkClipboard* clipboard)"
  XEN_ASSERT_TYPE(XEN_GtkClipboard__P(clipboard), clipboard, 1, "gtk_clipboard_get_owner", "GtkClipboard*");
  return(C_TO_XEN_GObject_(gtk_clipboard_get_owner(XEN_TO_C_GtkClipboard_(clipboard))));
}
static XEN gxg_gtk_clipboard_clear(XEN clipboard)
{
  #define H_gtk_clipboard_clear "void gtk_clipboard_clear(GtkClipboard* clipboard)"
  XEN_ASSERT_TYPE(XEN_GtkClipboard__P(clipboard), clipboard, 1, "gtk_clipboard_clear", "GtkClipboard*");
  gtk_clipboard_clear(XEN_TO_C_GtkClipboard_(clipboard));
  return(XEN_FALSE);
}
static XEN gxg_gtk_clipboard_set_text(XEN clipboard, XEN text, XEN len)
{
  #define H_gtk_clipboard_set_text "void gtk_clipboard_set_text(GtkClipboard* clipboard, gchar* text, \
gint len)"
  XEN_ASSERT_TYPE(XEN_GtkClipboard__P(clipboard), clipboard, 1, "gtk_clipboard_set_text", "GtkClipboard*");
  XEN_ASSERT_TYPE(XEN_gchar__P(text), text, 2, "gtk_clipboard_set_text", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(len), len, 3, "gtk_clipboard_set_text", "gint");
  gtk_clipboard_set_text(XEN_TO_C_GtkClipboard_(clipboard), XEN_TO_C_gchar_(text), XEN_TO_C_gint(len));
  return(XEN_FALSE);
}
static XEN gxg_gtk_clipboard_request_contents(XEN clipboard, XEN target, XEN func, XEN func_data)
{
  #define H_gtk_clipboard_request_contents "void gtk_clipboard_request_contents(GtkClipboard* clipboard, \
GdkAtom target, GtkClipboardReceivedFunc func, lambda_data func_data)"
  XEN_ASSERT_TYPE(XEN_GtkClipboard__P(clipboard), clipboard, 1, "gtk_clipboard_request_contents", "GtkClipboard*");
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(target), target, 2, "gtk_clipboard_request_contents", "GdkAtom");
  XEN_ASSERT_TYPE(XEN_GtkClipboardReceivedFunc_P(func), func, 3, "gtk_clipboard_request_contents", "GtkClipboardReceivedFunc");
  if (XEN_NOT_BOUND_P(func_data)) func_data = XEN_FALSE; 
  else XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 4, "gtk_clipboard_request_contents", "lambda_data");
  {
    int loc;
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    loc = xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 2, C_TO_XEN_INT(loc));
    gtk_clipboard_request_contents(XEN_TO_C_GtkClipboard_(clipboard), XEN_TO_C_GdkAtom(target), XEN_TO_C_GtkClipboardReceivedFunc(func), 
                               XEN_TO_C_lambda_data(func_data));
    xm_unprotect_at(loc);
    return(XEN_FALSE);
   }
}
static XEN gxg_gtk_clipboard_request_text(XEN clipboard, XEN func, XEN func_data)
{
  #define H_gtk_clipboard_request_text "void gtk_clipboard_request_text(GtkClipboard* clipboard, GtkClipboardTextReceivedFunc func, \
lambda_data func_data)"
  XEN_ASSERT_TYPE(XEN_GtkClipboard__P(clipboard), clipboard, 1, "gtk_clipboard_request_text", "GtkClipboard*");
  XEN_ASSERT_TYPE(XEN_GtkClipboardTextReceivedFunc_P(func), func, 2, "gtk_clipboard_request_text", "GtkClipboardTextReceivedFunc");
  if (XEN_NOT_BOUND_P(func_data)) func_data = XEN_FALSE; 
  else XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 3, "gtk_clipboard_request_text", "lambda_data");
  {
    int loc;
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    loc = xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 2, C_TO_XEN_INT(loc));
    gtk_clipboard_request_text(XEN_TO_C_GtkClipboard_(clipboard), XEN_TO_C_GtkClipboardTextReceivedFunc(func), XEN_TO_C_lambda_data(func_data));
    xm_unprotect_at(loc);
    return(XEN_FALSE);
   }
}
static XEN gxg_gtk_clipboard_wait_for_contents(XEN clipboard, XEN target)
{
  #define H_gtk_clipboard_wait_for_contents "GtkSelectionData* gtk_clipboard_wait_for_contents(GtkClipboard* clipboard, \
GdkAtom target)"
  XEN_ASSERT_TYPE(XEN_GtkClipboard__P(clipboard), clipboard, 1, "gtk_clipboard_wait_for_contents", "GtkClipboard*");
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(target), target, 2, "gtk_clipboard_wait_for_contents", "GdkAtom");
  return(C_TO_XEN_GtkSelectionData_(gtk_clipboard_wait_for_contents(XEN_TO_C_GtkClipboard_(clipboard), XEN_TO_C_GdkAtom(target))));
}
static XEN gxg_gtk_clipboard_wait_for_text(XEN clipboard)
{
  #define H_gtk_clipboard_wait_for_text "gchar* gtk_clipboard_wait_for_text(GtkClipboard* clipboard)"
  XEN_ASSERT_TYPE(XEN_GtkClipboard__P(clipboard), clipboard, 1, "gtk_clipboard_wait_for_text", "GtkClipboard*");
  return(C_TO_XEN_gchar_(gtk_clipboard_wait_for_text(XEN_TO_C_GtkClipboard_(clipboard))));
}
static XEN gxg_gtk_clipboard_wait_is_text_available(XEN clipboard)
{
  #define H_gtk_clipboard_wait_is_text_available "gboolean gtk_clipboard_wait_is_text_available(GtkClipboard* clipboard)"
  XEN_ASSERT_TYPE(XEN_GtkClipboard__P(clipboard), clipboard, 1, "gtk_clipboard_wait_is_text_available", "GtkClipboard*");
  return(C_TO_XEN_gboolean(gtk_clipboard_wait_is_text_available(XEN_TO_C_GtkClipboard_(clipboard))));
}
static XEN gxg_gtk_color_selection_dialog_get_type(void)
{
  #define H_gtk_color_selection_dialog_get_type "GtkType gtk_color_selection_dialog_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_color_selection_dialog_get_type()));
}
static XEN gxg_gtk_color_selection_dialog_new(XEN title)
{
  #define H_gtk_color_selection_dialog_new "GtkWidget* gtk_color_selection_dialog_new(gchar* title)"
  XEN_ASSERT_TYPE(XEN_gchar__P(title), title, 1, "gtk_color_selection_dialog_new", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_color_selection_dialog_new(XEN_TO_C_gchar_(title))));
}
static XEN gxg_gtk_color_selection_get_type(void)
{
  #define H_gtk_color_selection_get_type "GtkType gtk_color_selection_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_color_selection_get_type()));
}
static XEN gxg_gtk_color_selection_new(void)
{
  #define H_gtk_color_selection_new "GtkWidget* gtk_color_selection_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_color_selection_new()));
}
static XEN gxg_gtk_color_selection_get_has_opacity_control(XEN colorsel)
{
  #define H_gtk_color_selection_get_has_opacity_control "gboolean gtk_color_selection_get_has_opacity_control(GtkColorSelection* colorsel)"
  XEN_ASSERT_TYPE(XEN_GtkColorSelection__P(colorsel), colorsel, 1, "gtk_color_selection_get_has_opacity_control", "GtkColorSelection*");
  return(C_TO_XEN_gboolean(gtk_color_selection_get_has_opacity_control(XEN_TO_C_GtkColorSelection_(colorsel))));
}
static XEN gxg_gtk_color_selection_set_has_opacity_control(XEN colorsel, XEN has_opacity)
{
  #define H_gtk_color_selection_set_has_opacity_control "void gtk_color_selection_set_has_opacity_control(GtkColorSelection* colorsel, \
gboolean has_opacity)"
  XEN_ASSERT_TYPE(XEN_GtkColorSelection__P(colorsel), colorsel, 1, "gtk_color_selection_set_has_opacity_control", "GtkColorSelection*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(has_opacity), has_opacity, 2, "gtk_color_selection_set_has_opacity_control", "gboolean");
  gtk_color_selection_set_has_opacity_control(XEN_TO_C_GtkColorSelection_(colorsel), XEN_TO_C_gboolean(has_opacity));
  return(XEN_FALSE);
}
static XEN gxg_gtk_color_selection_get_has_palette(XEN colorsel)
{
  #define H_gtk_color_selection_get_has_palette "gboolean gtk_color_selection_get_has_palette(GtkColorSelection* colorsel)"
  XEN_ASSERT_TYPE(XEN_GtkColorSelection__P(colorsel), colorsel, 1, "gtk_color_selection_get_has_palette", "GtkColorSelection*");
  return(C_TO_XEN_gboolean(gtk_color_selection_get_has_palette(XEN_TO_C_GtkColorSelection_(colorsel))));
}
static XEN gxg_gtk_color_selection_set_has_palette(XEN colorsel, XEN has_palette)
{
  #define H_gtk_color_selection_set_has_palette "void gtk_color_selection_set_has_palette(GtkColorSelection* colorsel, \
gboolean has_palette)"
  XEN_ASSERT_TYPE(XEN_GtkColorSelection__P(colorsel), colorsel, 1, "gtk_color_selection_set_has_palette", "GtkColorSelection*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(has_palette), has_palette, 2, "gtk_color_selection_set_has_palette", "gboolean");
  gtk_color_selection_set_has_palette(XEN_TO_C_GtkColorSelection_(colorsel), XEN_TO_C_gboolean(has_palette));
  return(XEN_FALSE);
}
static XEN gxg_gtk_color_selection_set_current_color(XEN colorsel, XEN color)
{
  #define H_gtk_color_selection_set_current_color "void gtk_color_selection_set_current_color(GtkColorSelection* colorsel, \
GdkColor* color)"
  XEN_ASSERT_TYPE(XEN_GtkColorSelection__P(colorsel), colorsel, 1, "gtk_color_selection_set_current_color", "GtkColorSelection*");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(color), color, 2, "gtk_color_selection_set_current_color", "GdkColor*");
  gtk_color_selection_set_current_color(XEN_TO_C_GtkColorSelection_(colorsel), XEN_TO_C_GdkColor_(color));
  return(XEN_FALSE);
}
static XEN gxg_gtk_color_selection_set_current_alpha(XEN colorsel, XEN alpha)
{
  #define H_gtk_color_selection_set_current_alpha "void gtk_color_selection_set_current_alpha(GtkColorSelection* colorsel, \
guint16 alpha)"
  XEN_ASSERT_TYPE(XEN_GtkColorSelection__P(colorsel), colorsel, 1, "gtk_color_selection_set_current_alpha", "GtkColorSelection*");
  XEN_ASSERT_TYPE(XEN_guint16_P(alpha), alpha, 2, "gtk_color_selection_set_current_alpha", "guint16");
  gtk_color_selection_set_current_alpha(XEN_TO_C_GtkColorSelection_(colorsel), XEN_TO_C_guint16(alpha));
  return(XEN_FALSE);
}
static XEN gxg_gtk_color_selection_get_current_color(XEN colorsel, XEN color)
{
  #define H_gtk_color_selection_get_current_color "void gtk_color_selection_get_current_color(GtkColorSelection* colorsel, \
GdkColor* color)"
  XEN_ASSERT_TYPE(XEN_GtkColorSelection__P(colorsel), colorsel, 1, "gtk_color_selection_get_current_color", "GtkColorSelection*");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(color), color, 2, "gtk_color_selection_get_current_color", "GdkColor*");
  gtk_color_selection_get_current_color(XEN_TO_C_GtkColorSelection_(colorsel), XEN_TO_C_GdkColor_(color));
  return(XEN_FALSE);
}
static XEN gxg_gtk_color_selection_get_current_alpha(XEN colorsel)
{
  #define H_gtk_color_selection_get_current_alpha "guint16 gtk_color_selection_get_current_alpha(GtkColorSelection* colorsel)"
  XEN_ASSERT_TYPE(XEN_GtkColorSelection__P(colorsel), colorsel, 1, "gtk_color_selection_get_current_alpha", "GtkColorSelection*");
  return(C_TO_XEN_guint16(gtk_color_selection_get_current_alpha(XEN_TO_C_GtkColorSelection_(colorsel))));
}
static XEN gxg_gtk_color_selection_set_previous_color(XEN colorsel, XEN color)
{
  #define H_gtk_color_selection_set_previous_color "void gtk_color_selection_set_previous_color(GtkColorSelection* colorsel, \
GdkColor* color)"
  XEN_ASSERT_TYPE(XEN_GtkColorSelection__P(colorsel), colorsel, 1, "gtk_color_selection_set_previous_color", "GtkColorSelection*");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(color), color, 2, "gtk_color_selection_set_previous_color", "GdkColor*");
  gtk_color_selection_set_previous_color(XEN_TO_C_GtkColorSelection_(colorsel), XEN_TO_C_GdkColor_(color));
  return(XEN_FALSE);
}
static XEN gxg_gtk_color_selection_set_previous_alpha(XEN colorsel, XEN alpha)
{
  #define H_gtk_color_selection_set_previous_alpha "void gtk_color_selection_set_previous_alpha(GtkColorSelection* colorsel, \
guint16 alpha)"
  XEN_ASSERT_TYPE(XEN_GtkColorSelection__P(colorsel), colorsel, 1, "gtk_color_selection_set_previous_alpha", "GtkColorSelection*");
  XEN_ASSERT_TYPE(XEN_guint16_P(alpha), alpha, 2, "gtk_color_selection_set_previous_alpha", "guint16");
  gtk_color_selection_set_previous_alpha(XEN_TO_C_GtkColorSelection_(colorsel), XEN_TO_C_guint16(alpha));
  return(XEN_FALSE);
}
static XEN gxg_gtk_color_selection_get_previous_color(XEN colorsel, XEN color)
{
  #define H_gtk_color_selection_get_previous_color "void gtk_color_selection_get_previous_color(GtkColorSelection* colorsel, \
GdkColor* color)"
  XEN_ASSERT_TYPE(XEN_GtkColorSelection__P(colorsel), colorsel, 1, "gtk_color_selection_get_previous_color", "GtkColorSelection*");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(color), color, 2, "gtk_color_selection_get_previous_color", "GdkColor*");
  gtk_color_selection_get_previous_color(XEN_TO_C_GtkColorSelection_(colorsel), XEN_TO_C_GdkColor_(color));
  return(XEN_FALSE);
}
static XEN gxg_gtk_color_selection_get_previous_alpha(XEN colorsel)
{
  #define H_gtk_color_selection_get_previous_alpha "guint16 gtk_color_selection_get_previous_alpha(GtkColorSelection* colorsel)"
  XEN_ASSERT_TYPE(XEN_GtkColorSelection__P(colorsel), colorsel, 1, "gtk_color_selection_get_previous_alpha", "GtkColorSelection*");
  return(C_TO_XEN_guint16(gtk_color_selection_get_previous_alpha(XEN_TO_C_GtkColorSelection_(colorsel))));
}
static XEN gxg_gtk_color_selection_is_adjusting(XEN colorsel)
{
  #define H_gtk_color_selection_is_adjusting "gboolean gtk_color_selection_is_adjusting(GtkColorSelection* colorsel)"
  XEN_ASSERT_TYPE(XEN_GtkColorSelection__P(colorsel), colorsel, 1, "gtk_color_selection_is_adjusting", "GtkColorSelection*");
  return(C_TO_XEN_gboolean(gtk_color_selection_is_adjusting(XEN_TO_C_GtkColorSelection_(colorsel))));
}
static XEN gxg_gtk_color_selection_palette_from_string(XEN str, XEN colors, XEN n_colors)
{
  #define H_gtk_color_selection_palette_from_string "gboolean gtk_color_selection_palette_from_string(gchar* str, \
GdkColor** [colors], gint* [n_colors])"
  GdkColor* ref_colors = NULL;
  gint ref_n_colors;
  XEN_ASSERT_TYPE(XEN_gchar__P(str), str, 1, "gtk_color_selection_palette_from_string", "gchar*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gtk_color_selection_palette_from_string(XEN_TO_C_gchar_(str), &ref_colors, &ref_n_colors));
    return(XEN_LIST_3(result, C_TO_XEN_GdkColor_(ref_colors), C_TO_XEN_gint(ref_n_colors)));
   }
}
static XEN gxg_gtk_color_selection_palette_to_string(XEN colors, XEN n_colors)
{
  #define H_gtk_color_selection_palette_to_string "gchar* gtk_color_selection_palette_to_string(GdkColor* colors, \
gint n_colors)"
  XEN_ASSERT_TYPE(XEN_GdkColor__P(colors), colors, 1, "gtk_color_selection_palette_to_string", "GdkColor*");
  XEN_ASSERT_TYPE(XEN_gint_P(n_colors), n_colors, 2, "gtk_color_selection_palette_to_string", "gint");
  return(C_TO_XEN_gchar_(gtk_color_selection_palette_to_string(XEN_TO_C_GdkColor_(colors), XEN_TO_C_gint(n_colors))));
}
static XEN gxg_GTK_IS_RESIZE_CONTAINER(XEN widget)
{
  #define H_GTK_IS_RESIZE_CONTAINER "gboolean GTK_IS_RESIZE_CONTAINER(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "GTK_IS_RESIZE_CONTAINER", "GtkWidget*");
  return(C_TO_XEN_gboolean(GTK_IS_RESIZE_CONTAINER(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_container_get_type(void)
{
  #define H_gtk_container_get_type "GtkType gtk_container_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_container_get_type()));
}
static XEN gxg_gtk_container_set_border_width(XEN container, XEN border_width)
{
  #define H_gtk_container_set_border_width "void gtk_container_set_border_width(GtkContainer* container, \
guint border_width)"
  XEN_ASSERT_TYPE(XEN_GtkContainer__P(container), container, 1, "gtk_container_set_border_width", "GtkContainer*");
  XEN_ASSERT_TYPE(XEN_guint_P(border_width), border_width, 2, "gtk_container_set_border_width", "guint");
  gtk_container_set_border_width(XEN_TO_C_GtkContainer_(container), XEN_TO_C_guint(border_width));
  return(XEN_FALSE);
}
static XEN gxg_gtk_container_get_border_width(XEN container)
{
  #define H_gtk_container_get_border_width "guint gtk_container_get_border_width(GtkContainer* container)"
  XEN_ASSERT_TYPE(XEN_GtkContainer__P(container), container, 1, "gtk_container_get_border_width", "GtkContainer*");
  return(C_TO_XEN_guint(gtk_container_get_border_width(XEN_TO_C_GtkContainer_(container))));
}
static XEN gxg_gtk_container_add(XEN container, XEN widget)
{
  #define H_gtk_container_add "void gtk_container_add(GtkContainer* container, GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkContainer__P(container), container, 1, "gtk_container_add", "GtkContainer*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 2, "gtk_container_add", "GtkWidget*");
  gtk_container_add(XEN_TO_C_GtkContainer_(container), XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_container_remove(XEN container, XEN widget)
{
  #define H_gtk_container_remove "void gtk_container_remove(GtkContainer* container, GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkContainer__P(container), container, 1, "gtk_container_remove", "GtkContainer*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 2, "gtk_container_remove", "GtkWidget*");
  gtk_container_remove(XEN_TO_C_GtkContainer_(container), XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_container_set_resize_mode(XEN container, XEN resize_mode)
{
  #define H_gtk_container_set_resize_mode "void gtk_container_set_resize_mode(GtkContainer* container, \
GtkResizeMode resize_mode)"
  XEN_ASSERT_TYPE(XEN_GtkContainer__P(container), container, 1, "gtk_container_set_resize_mode", "GtkContainer*");
  XEN_ASSERT_TYPE(XEN_GtkResizeMode_P(resize_mode), resize_mode, 2, "gtk_container_set_resize_mode", "GtkResizeMode");
  gtk_container_set_resize_mode(XEN_TO_C_GtkContainer_(container), XEN_TO_C_GtkResizeMode(resize_mode));
  return(XEN_FALSE);
}
static XEN gxg_gtk_container_get_resize_mode(XEN container)
{
  #define H_gtk_container_get_resize_mode "GtkResizeMode gtk_container_get_resize_mode(GtkContainer* container)"
  XEN_ASSERT_TYPE(XEN_GtkContainer__P(container), container, 1, "gtk_container_get_resize_mode", "GtkContainer*");
  return(C_TO_XEN_GtkResizeMode(gtk_container_get_resize_mode(XEN_TO_C_GtkContainer_(container))));
}
static XEN gxg_gtk_container_check_resize(XEN container)
{
  #define H_gtk_container_check_resize "void gtk_container_check_resize(GtkContainer* container)"
  XEN_ASSERT_TYPE(XEN_GtkContainer__P(container), container, 1, "gtk_container_check_resize", "GtkContainer*");
  gtk_container_check_resize(XEN_TO_C_GtkContainer_(container));
  return(XEN_FALSE);
}
static XEN gxg_gtk_container_foreach(XEN container, XEN func, XEN func_data)
{
  #define H_gtk_container_foreach "void gtk_container_foreach(GtkContainer* container, GtkCallback func, \
lambda_data func_data)"
  XEN_ASSERT_TYPE(XEN_GtkContainer__P(container), container, 1, "gtk_container_foreach", "GtkContainer*");
  XEN_ASSERT_TYPE(XEN_GtkCallback_P(func), func, 2, "gtk_container_foreach", "GtkCallback");
  if (XEN_NOT_BOUND_P(func_data)) func_data = XEN_FALSE; 
  else XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 3, "gtk_container_foreach", "lambda_data");
  {
    int loc;
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    loc = xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 2, C_TO_XEN_INT(loc));
    gtk_container_foreach(XEN_TO_C_GtkContainer_(container), XEN_TO_C_GtkCallback(func), XEN_TO_C_lambda_data(func_data));
    xm_unprotect_at(loc);
    return(XEN_FALSE);
   }
}
static XEN gxg_gtk_container_get_children(XEN container)
{
  #define H_gtk_container_get_children "GList* gtk_container_get_children(GtkContainer* container)"
  XEN_ASSERT_TYPE(XEN_GtkContainer__P(container), container, 1, "gtk_container_get_children", "GtkContainer*");
  return(C_TO_XEN_GList_(gtk_container_get_children(XEN_TO_C_GtkContainer_(container))));
}
static XEN gxg_gtk_curve_get_type(void)
{
  #define H_gtk_curve_get_type "GtkType gtk_curve_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_curve_get_type()));
}
static XEN gxg_gtk_curve_new(void)
{
  #define H_gtk_curve_new "GtkWidget* gtk_curve_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_curve_new()));
}
static XEN gxg_gtk_curve_reset(XEN curve)
{
  #define H_gtk_curve_reset "void gtk_curve_reset(GtkCurve* curve)"
  XEN_ASSERT_TYPE(XEN_GtkCurve__P(curve), curve, 1, "gtk_curve_reset", "GtkCurve*");
  gtk_curve_reset(XEN_TO_C_GtkCurve_(curve));
  return(XEN_FALSE);
}
static XEN gxg_gtk_curve_set_gamma(XEN curve, XEN gamma)
{
  #define H_gtk_curve_set_gamma "void gtk_curve_set_gamma(GtkCurve* curve, gfloat gamma)"
  XEN_ASSERT_TYPE(XEN_GtkCurve__P(curve), curve, 1, "gtk_curve_set_gamma", "GtkCurve*");
  XEN_ASSERT_TYPE(XEN_gfloat_P(gamma), gamma, 2, "gtk_curve_set_gamma", "gfloat");
  gtk_curve_set_gamma(XEN_TO_C_GtkCurve_(curve), XEN_TO_C_gfloat(gamma));
  return(XEN_FALSE);
}
static XEN gxg_gtk_curve_set_range(XEN curve, XEN min_x, XEN max_x, XEN min_y, XEN max_y)
{
  #define H_gtk_curve_set_range "void gtk_curve_set_range(GtkCurve* curve, gfloat min_x, gfloat max_x, \
gfloat min_y, gfloat max_y)"
  XEN_ASSERT_TYPE(XEN_GtkCurve__P(curve), curve, 1, "gtk_curve_set_range", "GtkCurve*");
  XEN_ASSERT_TYPE(XEN_gfloat_P(min_x), min_x, 2, "gtk_curve_set_range", "gfloat");
  XEN_ASSERT_TYPE(XEN_gfloat_P(max_x), max_x, 3, "gtk_curve_set_range", "gfloat");
  XEN_ASSERT_TYPE(XEN_gfloat_P(min_y), min_y, 4, "gtk_curve_set_range", "gfloat");
  XEN_ASSERT_TYPE(XEN_gfloat_P(max_y), max_y, 5, "gtk_curve_set_range", "gfloat");
  gtk_curve_set_range(XEN_TO_C_GtkCurve_(curve), XEN_TO_C_gfloat(min_x), XEN_TO_C_gfloat(max_x), XEN_TO_C_gfloat(min_y), 
                      XEN_TO_C_gfloat(max_y));
  return(XEN_FALSE);
}
static XEN gxg_gtk_curve_get_vector(XEN curve, XEN veclen, XEN vector)
{
  #define H_gtk_curve_get_vector "void gtk_curve_get_vector(GtkCurve* curve, int veclen, gfloat* vector)"
  XEN_ASSERT_TYPE(XEN_GtkCurve__P(curve), curve, 1, "gtk_curve_get_vector", "GtkCurve*");
  XEN_ASSERT_TYPE(XEN_int_P(veclen), veclen, 2, "gtk_curve_get_vector", "int");
  XEN_ASSERT_TYPE(XEN_gfloat__P(vector), vector, 3, "gtk_curve_get_vector", "gfloat*");
  gtk_curve_get_vector(XEN_TO_C_GtkCurve_(curve), XEN_TO_C_int(veclen), XEN_TO_C_gfloat_(vector));
  return(XEN_FALSE);
}
static XEN gxg_gtk_curve_set_vector(XEN curve, XEN veclen, XEN vector)
{
  #define H_gtk_curve_set_vector "void gtk_curve_set_vector(GtkCurve* curve, int veclen, gfloat* vector)"
  XEN_ASSERT_TYPE(XEN_GtkCurve__P(curve), curve, 1, "gtk_curve_set_vector", "GtkCurve*");
  XEN_ASSERT_TYPE(XEN_int_P(veclen), veclen, 2, "gtk_curve_set_vector", "int");
  XEN_ASSERT_TYPE(XEN_gfloat__P(vector), vector, 3, "gtk_curve_set_vector", "gfloat*");
  gtk_curve_set_vector(XEN_TO_C_GtkCurve_(curve), XEN_TO_C_int(veclen), XEN_TO_C_gfloat_(vector));
  return(XEN_FALSE);
}
static XEN gxg_gtk_curve_set_curve_type(XEN curve, XEN type)
{
  #define H_gtk_curve_set_curve_type "void gtk_curve_set_curve_type(GtkCurve* curve, GtkCurveType type)"
  XEN_ASSERT_TYPE(XEN_GtkCurve__P(curve), curve, 1, "gtk_curve_set_curve_type", "GtkCurve*");
  XEN_ASSERT_TYPE(XEN_GtkCurveType_P(type), type, 2, "gtk_curve_set_curve_type", "GtkCurveType");
  gtk_curve_set_curve_type(XEN_TO_C_GtkCurve_(curve), XEN_TO_C_GtkCurveType(type));
  return(XEN_FALSE);
}
static XEN gxg_gtk_dialog_get_type(void)
{
  #define H_gtk_dialog_get_type "GtkType gtk_dialog_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_dialog_get_type()));
}
static XEN gxg_gtk_dialog_new(void)
{
  #define H_gtk_dialog_new "GtkWidget* gtk_dialog_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_dialog_new()));
}
static XEN gxg_gtk_dialog_new_with_buttons(XEN title, XEN parent, XEN flags, XEN buttons)
{
  #define H_gtk_dialog_new_with_buttons "GtkWidget* gtk_dialog_new_with_buttons(gchar* title, GtkWindow* parent, \
GtkDialogFlags flags, etc buttons)"
  XEN_ASSERT_TYPE(XEN_gchar__P(title), title, 1, "gtk_dialog_new_with_buttons", "gchar*");
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(parent) || XEN_FALSE_P(parent), parent, 2, "gtk_dialog_new_with_buttons", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkDialogFlags_P(flags), flags, 3, "gtk_dialog_new_with_buttons", "GtkDialogFlags");
  if (XEN_NOT_BOUND_P(buttons)) buttons = XEN_FALSE; 
  else XEN_ASSERT_TYPE(XEN_etc_P(buttons), buttons, 4, "gtk_dialog_new_with_buttons", "etc");
  {
    int etc_len = 0;
    GtkWidget* result = NULL;
    gchar* p_arg0;
    GtkWindow* p_arg1;
    GtkDialogFlags p_arg2;
    if (XEN_LIST_P(buttons)) etc_len = XEN_LIST_LENGTH(buttons);
    if (etc_len > 10) XEN_OUT_OF_RANGE_ERROR("gtk_dialog_new_with_buttons", 3, buttons, "... list too long (max len: 10)");
    if ((etc_len % 2) != 0) XEN_OUT_OF_RANGE_ERROR("gtk_dialog_new_with_buttons", 3, buttons, "... list len must be multiple of 2");
    p_arg0 = XEN_TO_C_gchar_(title);
    p_arg1 = XEN_TO_C_GtkWindow_(parent);
    p_arg2 = XEN_TO_C_GtkDialogFlags(flags);
    switch (etc_len)
      {
        case 0: result = gtk_dialog_new_with_buttons(p_arg0, p_arg1, p_arg2, NULL); break;
        case 2: result = gtk_dialog_new_with_buttons(p_arg0, p_arg1, p_arg2, XLS(buttons, 0), XLI(buttons, 1), NULL); break;
        case 4: result = gtk_dialog_new_with_buttons(p_arg0, p_arg1, p_arg2, XLS(buttons, 0), XLI(buttons, 1), XLS(buttons, 2), XLI(buttons, 3), NULL); break;
        case 6: result = gtk_dialog_new_with_buttons(p_arg0, p_arg1, p_arg2, XLS(buttons, 0), XLI(buttons, 1), XLS(buttons, 2), XLI(buttons, 3), XLS(buttons, 4), XLI(buttons, 5), NULL); break;
        case 8: result = gtk_dialog_new_with_buttons(p_arg0, p_arg1, p_arg2, XLS(buttons, 0), XLI(buttons, 1), XLS(buttons, 2), XLI(buttons, 3), XLS(buttons, 4), XLI(buttons, 5), XLS(buttons, 6), XLI(buttons, 7), NULL); break;
        case 10: result = gtk_dialog_new_with_buttons(p_arg0, p_arg1, p_arg2, XLS(buttons, 0), XLI(buttons, 1), XLS(buttons, 2), XLI(buttons, 3), XLS(buttons, 4), XLI(buttons, 5), XLS(buttons, 6), XLI(buttons, 7), XLS(buttons, 8), XLI(buttons, 9), NULL); break;
      }
    return(C_TO_XEN_GtkWidget_(result));
  }
}
static XEN gxg_gtk_dialog_add_action_widget(XEN dialog, XEN child, XEN response_id)
{
  #define H_gtk_dialog_add_action_widget "void gtk_dialog_add_action_widget(GtkDialog* dialog, GtkWidget* child, \
gint response_id)"
  XEN_ASSERT_TYPE(XEN_GtkDialog__P(dialog), dialog, 1, "gtk_dialog_add_action_widget", "GtkDialog*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_dialog_add_action_widget", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gint_P(response_id), response_id, 3, "gtk_dialog_add_action_widget", "gint");
  gtk_dialog_add_action_widget(XEN_TO_C_GtkDialog_(dialog), XEN_TO_C_GtkWidget_(child), XEN_TO_C_gint(response_id));
  return(XEN_FALSE);
}
static XEN gxg_gtk_dialog_add_button(XEN dialog, XEN button_text, XEN response_id)
{
  #define H_gtk_dialog_add_button "GtkWidget* gtk_dialog_add_button(GtkDialog* dialog, gchar* button_text, \
gint response_id)"
  XEN_ASSERT_TYPE(XEN_GtkDialog__P(dialog), dialog, 1, "gtk_dialog_add_button", "GtkDialog*");
  XEN_ASSERT_TYPE(XEN_gchar__P(button_text), button_text, 2, "gtk_dialog_add_button", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(response_id), response_id, 3, "gtk_dialog_add_button", "gint");
  return(C_TO_XEN_GtkWidget_(gtk_dialog_add_button(XEN_TO_C_GtkDialog_(dialog), XEN_TO_C_gchar_(button_text), XEN_TO_C_gint(response_id))));
}
static XEN gxg_gtk_dialog_add_buttons(XEN dialog, XEN buttons)
{
  #define H_gtk_dialog_add_buttons "void gtk_dialog_add_buttons(GtkDialog* dialog, etc buttons)"
  XEN_ASSERT_TYPE(XEN_GtkDialog__P(dialog), dialog, 1, "gtk_dialog_add_buttons", "GtkDialog*");
  XEN_ASSERT_TYPE(XEN_etc_P(buttons), buttons, 2, "gtk_dialog_add_buttons", "etc");
  {
    int etc_len = 0;
    GtkDialog* p_arg0;
    if (XEN_LIST_P(buttons)) etc_len = XEN_LIST_LENGTH(buttons);
    if (etc_len < 2) XEN_OUT_OF_RANGE_ERROR("gtk_dialog_add_buttons", 1, buttons, "... list must have at least 2 entries");
    if (etc_len > 10) XEN_OUT_OF_RANGE_ERROR("gtk_dialog_add_buttons", 1, buttons, "... list too long (max len: 10)");
    if ((etc_len % 2) != 0) XEN_OUT_OF_RANGE_ERROR("gtk_dialog_add_buttons", 1, buttons, "... list len must be multiple of 2");
    p_arg0 = XEN_TO_C_GtkDialog_(dialog);
    switch (etc_len)
      {
        case 2: gtk_dialog_add_buttons(p_arg0, XLS(buttons, 0), XLI(buttons, 1), NULL); break;
        case 4: gtk_dialog_add_buttons(p_arg0, XLS(buttons, 0), XLI(buttons, 1), XLS(buttons, 2), XLI(buttons, 3), NULL); break;
        case 6: gtk_dialog_add_buttons(p_arg0, XLS(buttons, 0), XLI(buttons, 1), XLS(buttons, 2), XLI(buttons, 3), XLS(buttons, 4), XLI(buttons, 5), NULL); break;
        case 8: gtk_dialog_add_buttons(p_arg0, XLS(buttons, 0), XLI(buttons, 1), XLS(buttons, 2), XLI(buttons, 3), XLS(buttons, 4), XLI(buttons, 5), XLS(buttons, 6), XLI(buttons, 7), NULL); break;
        case 10: gtk_dialog_add_buttons(p_arg0, XLS(buttons, 0), XLI(buttons, 1), XLS(buttons, 2), XLI(buttons, 3), XLS(buttons, 4), XLI(buttons, 5), XLS(buttons, 6), XLI(buttons, 7), XLS(buttons, 8), XLI(buttons, 9), NULL); break;
      }
    return(XEN_FALSE);
  }
}
static XEN gxg_gtk_dialog_set_response_sensitive(XEN dialog, XEN response_id, XEN setting)
{
  #define H_gtk_dialog_set_response_sensitive "void gtk_dialog_set_response_sensitive(GtkDialog* dialog, \
gint response_id, gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GtkDialog__P(dialog), dialog, 1, "gtk_dialog_set_response_sensitive", "GtkDialog*");
  XEN_ASSERT_TYPE(XEN_gint_P(response_id), response_id, 2, "gtk_dialog_set_response_sensitive", "gint");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 3, "gtk_dialog_set_response_sensitive", "gboolean");
  gtk_dialog_set_response_sensitive(XEN_TO_C_GtkDialog_(dialog), XEN_TO_C_gint(response_id), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_dialog_set_default_response(XEN dialog, XEN response_id)
{
  #define H_gtk_dialog_set_default_response "void gtk_dialog_set_default_response(GtkDialog* dialog, \
gint response_id)"
  XEN_ASSERT_TYPE(XEN_GtkDialog__P(dialog), dialog, 1, "gtk_dialog_set_default_response", "GtkDialog*");
  XEN_ASSERT_TYPE(XEN_gint_P(response_id), response_id, 2, "gtk_dialog_set_default_response", "gint");
  gtk_dialog_set_default_response(XEN_TO_C_GtkDialog_(dialog), XEN_TO_C_gint(response_id));
  return(XEN_FALSE);
}
static XEN gxg_gtk_dialog_set_has_separator(XEN dialog, XEN setting)
{
  #define H_gtk_dialog_set_has_separator "void gtk_dialog_set_has_separator(GtkDialog* dialog, gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GtkDialog__P(dialog), dialog, 1, "gtk_dialog_set_has_separator", "GtkDialog*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gtk_dialog_set_has_separator", "gboolean");
  gtk_dialog_set_has_separator(XEN_TO_C_GtkDialog_(dialog), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_dialog_get_has_separator(XEN dialog)
{
  #define H_gtk_dialog_get_has_separator "gboolean gtk_dialog_get_has_separator(GtkDialog* dialog)"
  XEN_ASSERT_TYPE(XEN_GtkDialog__P(dialog), dialog, 1, "gtk_dialog_get_has_separator", "GtkDialog*");
  return(C_TO_XEN_gboolean(gtk_dialog_get_has_separator(XEN_TO_C_GtkDialog_(dialog))));
}
static XEN gxg_gtk_dialog_response(XEN dialog, XEN response_id)
{
  #define H_gtk_dialog_response "void gtk_dialog_response(GtkDialog* dialog, gint response_id)"
  XEN_ASSERT_TYPE(XEN_GtkDialog__P(dialog), dialog, 1, "gtk_dialog_response", "GtkDialog*");
  XEN_ASSERT_TYPE(XEN_gint_P(response_id), response_id, 2, "gtk_dialog_response", "gint");
  gtk_dialog_response(XEN_TO_C_GtkDialog_(dialog), XEN_TO_C_gint(response_id));
  return(XEN_FALSE);
}
static XEN gxg_gtk_dialog_run(XEN dialog)
{
  #define H_gtk_dialog_run "gint gtk_dialog_run(GtkDialog* dialog)"
  XEN_ASSERT_TYPE(XEN_GtkDialog__P(dialog), dialog, 1, "gtk_dialog_run", "GtkDialog*");
  return(C_TO_XEN_gint(gtk_dialog_run(XEN_TO_C_GtkDialog_(dialog))));
}
static XEN gxg_gtk_drag_get_data(XEN widget, XEN context, XEN target, XEN time)
{
  #define H_gtk_drag_get_data "void gtk_drag_get_data(GtkWidget* widget, GdkDragContext* context, GdkAtom target, \
guint32 time)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_drag_get_data", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GdkDragContext__P(context), context, 2, "gtk_drag_get_data", "GdkDragContext*");
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(target), target, 3, "gtk_drag_get_data", "GdkAtom");
  XEN_ASSERT_TYPE(XEN_guint32_P(time), time, 4, "gtk_drag_get_data", "guint32");
  gtk_drag_get_data(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GdkDragContext_(context), XEN_TO_C_GdkAtom(target), XEN_TO_C_guint32(time));
  return(XEN_FALSE);
}
static XEN gxg_gtk_drag_finish(XEN context, XEN success, XEN del, XEN time)
{
  #define H_gtk_drag_finish "void gtk_drag_finish(GdkDragContext* context, gboolean success, gboolean del, \
guint32 time)"
  XEN_ASSERT_TYPE(XEN_GdkDragContext__P(context), context, 1, "gtk_drag_finish", "GdkDragContext*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(success), success, 2, "gtk_drag_finish", "gboolean");
  XEN_ASSERT_TYPE(XEN_gboolean_P(del), del, 3, "gtk_drag_finish", "gboolean");
  XEN_ASSERT_TYPE(XEN_guint32_P(time), time, 4, "gtk_drag_finish", "guint32");
  gtk_drag_finish(XEN_TO_C_GdkDragContext_(context), XEN_TO_C_gboolean(success), XEN_TO_C_gboolean(del), XEN_TO_C_guint32(time));
  return(XEN_FALSE);
}
static XEN gxg_gtk_drag_get_source_widget(XEN context)
{
  #define H_gtk_drag_get_source_widget "GtkWidget* gtk_drag_get_source_widget(GdkDragContext* context)"
  XEN_ASSERT_TYPE(XEN_GdkDragContext__P(context), context, 1, "gtk_drag_get_source_widget", "GdkDragContext*");
  return(C_TO_XEN_GtkWidget_(gtk_drag_get_source_widget(XEN_TO_C_GdkDragContext_(context))));
}
static XEN gxg_gtk_drag_highlight(XEN widget)
{
  #define H_gtk_drag_highlight "void gtk_drag_highlight(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_drag_highlight", "GtkWidget*");
  gtk_drag_highlight(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_drag_unhighlight(XEN widget)
{
  #define H_gtk_drag_unhighlight "void gtk_drag_unhighlight(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_drag_unhighlight", "GtkWidget*");
  gtk_drag_unhighlight(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_drag_dest_set(XEN widget, XEN flags, XEN targets, XEN n_targets, XEN actions)
{
  #define H_gtk_drag_dest_set "void gtk_drag_dest_set(GtkWidget* widget, GtkDestDefaults flags, GtkTargetEntry* targets, \
gint n_targets, GdkDragAction actions)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_drag_dest_set", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkDestDefaults_P(flags), flags, 2, "gtk_drag_dest_set", "GtkDestDefaults");
  XEN_ASSERT_TYPE(XEN_GtkTargetEntry__P(targets), targets, 3, "gtk_drag_dest_set", "GtkTargetEntry*");
  XEN_ASSERT_TYPE(XEN_gint_P(n_targets), n_targets, 4, "gtk_drag_dest_set", "gint");
  XEN_ASSERT_TYPE(XEN_GdkDragAction_P(actions), actions, 5, "gtk_drag_dest_set", "GdkDragAction");
  gtk_drag_dest_set(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GtkDestDefaults(flags), XEN_TO_C_GtkTargetEntry_(targets), XEN_TO_C_gint(n_targets), 
                    XEN_TO_C_GdkDragAction(actions));
  return(XEN_FALSE);
}
static XEN gxg_gtk_drag_dest_set_proxy(XEN widget, XEN proxy_window, XEN protocol, XEN use_coordinates)
{
  #define H_gtk_drag_dest_set_proxy "void gtk_drag_dest_set_proxy(GtkWidget* widget, GdkWindow* proxy_window, \
GdkDragProtocol protocol, gboolean use_coordinates)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_drag_dest_set_proxy", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(proxy_window), proxy_window, 2, "gtk_drag_dest_set_proxy", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkDragProtocol_P(protocol), protocol, 3, "gtk_drag_dest_set_proxy", "GdkDragProtocol");
  XEN_ASSERT_TYPE(XEN_gboolean_P(use_coordinates), use_coordinates, 4, "gtk_drag_dest_set_proxy", "gboolean");
  gtk_drag_dest_set_proxy(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GdkWindow_(proxy_window), XEN_TO_C_GdkDragProtocol(protocol), 
                          XEN_TO_C_gboolean(use_coordinates));
  return(XEN_FALSE);
}
static XEN gxg_gtk_drag_dest_unset(XEN widget)
{
  #define H_gtk_drag_dest_unset "void gtk_drag_dest_unset(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_drag_dest_unset", "GtkWidget*");
  gtk_drag_dest_unset(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_drag_dest_find_target(XEN widget, XEN context, XEN target_list)
{
  #define H_gtk_drag_dest_find_target "GdkAtom gtk_drag_dest_find_target(GtkWidget* widget, GdkDragContext* context, \
GtkTargetList* target_list)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_drag_dest_find_target", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GdkDragContext__P(context), context, 2, "gtk_drag_dest_find_target", "GdkDragContext*");
  XEN_ASSERT_TYPE(XEN_GtkTargetList__P(target_list) || XEN_FALSE_P(target_list), target_list, 3, "gtk_drag_dest_find_target", "GtkTargetList*");
  return(C_TO_XEN_GdkAtom(gtk_drag_dest_find_target(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GdkDragContext_(context), XEN_TO_C_GtkTargetList_(target_list))));
}
static XEN gxg_gtk_drag_dest_get_target_list(XEN widget)
{
  #define H_gtk_drag_dest_get_target_list "GtkTargetList* gtk_drag_dest_get_target_list(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_drag_dest_get_target_list", "GtkWidget*");
  return(C_TO_XEN_GtkTargetList_(gtk_drag_dest_get_target_list(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_drag_dest_set_target_list(XEN widget, XEN target_list)
{
  #define H_gtk_drag_dest_set_target_list "void gtk_drag_dest_set_target_list(GtkWidget* widget, GtkTargetList* target_list)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_drag_dest_set_target_list", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkTargetList__P(target_list) || XEN_FALSE_P(target_list), target_list, 2, "gtk_drag_dest_set_target_list", "GtkTargetList*");
  gtk_drag_dest_set_target_list(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GtkTargetList_(target_list));
  return(XEN_FALSE);
}
static XEN gxg_gtk_drag_source_set(XEN widget, XEN start_button_mask, XEN targets, XEN n_targets, XEN actions)
{
  #define H_gtk_drag_source_set "void gtk_drag_source_set(GtkWidget* widget, GdkModifierType start_button_mask, \
GtkTargetEntry* targets, gint n_targets, GdkDragAction actions)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_drag_source_set", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GdkModifierType_P(start_button_mask), start_button_mask, 2, "gtk_drag_source_set", "GdkModifierType");
  XEN_ASSERT_TYPE(XEN_GtkTargetEntry__P(targets), targets, 3, "gtk_drag_source_set", "GtkTargetEntry*");
  XEN_ASSERT_TYPE(XEN_gint_P(n_targets), n_targets, 4, "gtk_drag_source_set", "gint");
  XEN_ASSERT_TYPE(XEN_GdkDragAction_P(actions), actions, 5, "gtk_drag_source_set", "GdkDragAction");
  gtk_drag_source_set(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GdkModifierType(start_button_mask), XEN_TO_C_GtkTargetEntry_(targets), 
                      XEN_TO_C_gint(n_targets), XEN_TO_C_GdkDragAction(actions));
  return(XEN_FALSE);
}
static XEN gxg_gtk_drag_source_unset(XEN widget)
{
  #define H_gtk_drag_source_unset "void gtk_drag_source_unset(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_drag_source_unset", "GtkWidget*");
  gtk_drag_source_unset(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_drag_source_set_icon(XEN widget, XEN colormap, XEN pixmap, XEN mask)
{
  #define H_gtk_drag_source_set_icon "void gtk_drag_source_set_icon(GtkWidget* widget, GdkColormap* colormap, \
GdkPixmap* pixmap, GdkBitmap* mask)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_drag_source_set_icon", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GdkColormap__P(colormap), colormap, 2, "gtk_drag_source_set_icon", "GdkColormap*");
  XEN_ASSERT_TYPE(XEN_GdkPixmap__P(pixmap), pixmap, 3, "gtk_drag_source_set_icon", "GdkPixmap*");
  XEN_ASSERT_TYPE(XEN_GdkBitmap__P(mask), mask, 4, "gtk_drag_source_set_icon", "GdkBitmap*");
  gtk_drag_source_set_icon(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GdkColormap_(colormap), XEN_TO_C_GdkPixmap_(pixmap), XEN_TO_C_GdkBitmap_(mask));
  return(XEN_FALSE);
}
static XEN gxg_gtk_drag_source_set_icon_pixbuf(XEN widget, XEN pixbuf)
{
  #define H_gtk_drag_source_set_icon_pixbuf "void gtk_drag_source_set_icon_pixbuf(GtkWidget* widget, \
GdkPixbuf* pixbuf)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_drag_source_set_icon_pixbuf", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(pixbuf), pixbuf, 2, "gtk_drag_source_set_icon_pixbuf", "GdkPixbuf*");
  gtk_drag_source_set_icon_pixbuf(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GdkPixbuf_(pixbuf));
  return(XEN_FALSE);
}
static XEN gxg_gtk_drag_source_set_icon_stock(XEN widget, XEN stock_id)
{
  #define H_gtk_drag_source_set_icon_stock "void gtk_drag_source_set_icon_stock(GtkWidget* widget, gchar* stock_id)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_drag_source_set_icon_stock", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(stock_id), stock_id, 2, "gtk_drag_source_set_icon_stock", "gchar*");
  gtk_drag_source_set_icon_stock(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(stock_id));
  return(XEN_FALSE);
}
static XEN gxg_gtk_drag_begin(XEN widget, XEN targets, XEN actions, XEN button, XEN event)
{
  #define H_gtk_drag_begin "GdkDragContext* gtk_drag_begin(GtkWidget* widget, GtkTargetList* targets, \
GdkDragAction actions, gint button, GdkEvent* event)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_drag_begin", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkTargetList__P(targets), targets, 2, "gtk_drag_begin", "GtkTargetList*");
  XEN_ASSERT_TYPE(XEN_GdkDragAction_P(actions), actions, 3, "gtk_drag_begin", "GdkDragAction");
  XEN_ASSERT_TYPE(XEN_gint_P(button), button, 4, "gtk_drag_begin", "gint");
  XEN_ASSERT_TYPE(XEN_GdkEvent__P(event), event, 5, "gtk_drag_begin", "GdkEvent*");
  return(C_TO_XEN_GdkDragContext_(gtk_drag_begin(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GtkTargetList_(targets), XEN_TO_C_GdkDragAction(actions), 
                                                 XEN_TO_C_gint(button), XEN_TO_C_GdkEvent_(event))));
}
static XEN gxg_gtk_drag_set_icon_widget(XEN context, XEN widget, XEN hot_x, XEN hot_y)
{
  #define H_gtk_drag_set_icon_widget "void gtk_drag_set_icon_widget(GdkDragContext* context, GtkWidget* widget, \
gint hot_x, gint hot_y)"
  XEN_ASSERT_TYPE(XEN_GdkDragContext__P(context), context, 1, "gtk_drag_set_icon_widget", "GdkDragContext*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 2, "gtk_drag_set_icon_widget", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gint_P(hot_x), hot_x, 3, "gtk_drag_set_icon_widget", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(hot_y), hot_y, 4, "gtk_drag_set_icon_widget", "gint");
  gtk_drag_set_icon_widget(XEN_TO_C_GdkDragContext_(context), XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gint(hot_x), XEN_TO_C_gint(hot_y));
  return(XEN_FALSE);
}
static XEN gxg_gtk_drag_set_icon_pixmap(XEN context, XEN colormap, XEN pixmap, XEN mask, XEN hot_x, XEN hot_y)
{
  #define H_gtk_drag_set_icon_pixmap "void gtk_drag_set_icon_pixmap(GdkDragContext* context, GdkColormap* colormap, \
GdkPixmap* pixmap, GdkBitmap* mask, gint hot_x, gint hot_y)"
  XEN_ASSERT_TYPE(XEN_GdkDragContext__P(context), context, 1, "gtk_drag_set_icon_pixmap", "GdkDragContext*");
  XEN_ASSERT_TYPE(XEN_GdkColormap__P(colormap), colormap, 2, "gtk_drag_set_icon_pixmap", "GdkColormap*");
  XEN_ASSERT_TYPE(XEN_GdkPixmap__P(pixmap), pixmap, 3, "gtk_drag_set_icon_pixmap", "GdkPixmap*");
  XEN_ASSERT_TYPE(XEN_GdkBitmap__P(mask), mask, 4, "gtk_drag_set_icon_pixmap", "GdkBitmap*");
  XEN_ASSERT_TYPE(XEN_gint_P(hot_x), hot_x, 5, "gtk_drag_set_icon_pixmap", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(hot_y), hot_y, 6, "gtk_drag_set_icon_pixmap", "gint");
  gtk_drag_set_icon_pixmap(XEN_TO_C_GdkDragContext_(context), XEN_TO_C_GdkColormap_(colormap), XEN_TO_C_GdkPixmap_(pixmap), 
                           XEN_TO_C_GdkBitmap_(mask), XEN_TO_C_gint(hot_x), XEN_TO_C_gint(hot_y));
  return(XEN_FALSE);
}
static XEN gxg_gtk_drag_set_icon_pixbuf(XEN context, XEN pixbuf, XEN hot_x, XEN hot_y)
{
  #define H_gtk_drag_set_icon_pixbuf "void gtk_drag_set_icon_pixbuf(GdkDragContext* context, GdkPixbuf* pixbuf, \
gint hot_x, gint hot_y)"
  XEN_ASSERT_TYPE(XEN_GdkDragContext__P(context), context, 1, "gtk_drag_set_icon_pixbuf", "GdkDragContext*");
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(pixbuf), pixbuf, 2, "gtk_drag_set_icon_pixbuf", "GdkPixbuf*");
  XEN_ASSERT_TYPE(XEN_gint_P(hot_x), hot_x, 3, "gtk_drag_set_icon_pixbuf", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(hot_y), hot_y, 4, "gtk_drag_set_icon_pixbuf", "gint");
  gtk_drag_set_icon_pixbuf(XEN_TO_C_GdkDragContext_(context), XEN_TO_C_GdkPixbuf_(pixbuf), XEN_TO_C_gint(hot_x), XEN_TO_C_gint(hot_y));
  return(XEN_FALSE);
}
static XEN gxg_gtk_drag_set_icon_stock(XEN context, XEN stock_id, XEN hot_x, XEN hot_y)
{
  #define H_gtk_drag_set_icon_stock "void gtk_drag_set_icon_stock(GdkDragContext* context, gchar* stock_id, \
gint hot_x, gint hot_y)"
  XEN_ASSERT_TYPE(XEN_GdkDragContext__P(context), context, 1, "gtk_drag_set_icon_stock", "GdkDragContext*");
  XEN_ASSERT_TYPE(XEN_gchar__P(stock_id), stock_id, 2, "gtk_drag_set_icon_stock", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(hot_x), hot_x, 3, "gtk_drag_set_icon_stock", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(hot_y), hot_y, 4, "gtk_drag_set_icon_stock", "gint");
  gtk_drag_set_icon_stock(XEN_TO_C_GdkDragContext_(context), XEN_TO_C_gchar_(stock_id), XEN_TO_C_gint(hot_x), XEN_TO_C_gint(hot_y));
  return(XEN_FALSE);
}
static XEN gxg_gtk_drag_set_icon_default(XEN context)
{
  #define H_gtk_drag_set_icon_default "void gtk_drag_set_icon_default(GdkDragContext* context)"
  XEN_ASSERT_TYPE(XEN_GdkDragContext__P(context), context, 1, "gtk_drag_set_icon_default", "GdkDragContext*");
  gtk_drag_set_icon_default(XEN_TO_C_GdkDragContext_(context));
  return(XEN_FALSE);
}
static XEN gxg_gtk_drag_check_threshold(XEN widget, XEN start_x, XEN start_y, XEN current_x, XEN current_y)
{
  #define H_gtk_drag_check_threshold "gboolean gtk_drag_check_threshold(GtkWidget* widget, gint start_x, \
gint start_y, gint current_x, gint current_y)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_drag_check_threshold", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gint_P(start_x), start_x, 2, "gtk_drag_check_threshold", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(start_y), start_y, 3, "gtk_drag_check_threshold", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(current_x), current_x, 4, "gtk_drag_check_threshold", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(current_y), current_y, 5, "gtk_drag_check_threshold", "gint");
  return(C_TO_XEN_gboolean(gtk_drag_check_threshold(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gint(start_x), XEN_TO_C_gint(start_y), 
                                                    XEN_TO_C_gint(current_x), XEN_TO_C_gint(current_y))));
}
static XEN gxg_gtk_drawing_area_get_type(void)
{
  #define H_gtk_drawing_area_get_type "GtkType gtk_drawing_area_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_drawing_area_get_type()));
}
static XEN gxg_gtk_drawing_area_new(void)
{
  #define H_gtk_drawing_area_new "GtkWidget* gtk_drawing_area_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_drawing_area_new()));
}
static XEN gxg_gtk_editable_get_type(void)
{
  #define H_gtk_editable_get_type "GtkType gtk_editable_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_editable_get_type()));
}
static XEN gxg_gtk_editable_select_region(XEN editable, XEN start, XEN end)
{
  #define H_gtk_editable_select_region "void gtk_editable_select_region(GtkEditable* editable, gint start, \
gint end)"
  XEN_ASSERT_TYPE(XEN_GtkEditable__P(editable), editable, 1, "gtk_editable_select_region", "GtkEditable*");
  XEN_ASSERT_TYPE(XEN_gint_P(start), start, 2, "gtk_editable_select_region", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(end), end, 3, "gtk_editable_select_region", "gint");
  gtk_editable_select_region(XEN_TO_C_GtkEditable_(editable), XEN_TO_C_gint(start), XEN_TO_C_gint(end));
  return(XEN_FALSE);
}
static XEN gxg_gtk_editable_get_selection_bounds(XEN editable, XEN start, XEN end)
{
  #define H_gtk_editable_get_selection_bounds "gboolean gtk_editable_get_selection_bounds(GtkEditable* editable, \
gint* [start], gint* [end])"
  gint ref_start;
  gint ref_end;
  XEN_ASSERT_TYPE(XEN_GtkEditable__P(editable), editable, 1, "gtk_editable_get_selection_bounds", "GtkEditable*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gtk_editable_get_selection_bounds(XEN_TO_C_GtkEditable_(editable), &ref_start, &ref_end));
    return(XEN_LIST_3(result, C_TO_XEN_gint(ref_start), C_TO_XEN_gint(ref_end)));
   }
}
static XEN gxg_gtk_editable_insert_text(XEN editable, XEN new_text, XEN new_text_length, XEN position)
{
  #define H_gtk_editable_insert_text "void gtk_editable_insert_text(GtkEditable* editable, gchar* new_text, \
gint new_text_length, gint* [position])"
  gint ref_position;
  XEN_ASSERT_TYPE(XEN_GtkEditable__P(editable), editable, 1, "gtk_editable_insert_text", "GtkEditable*");
  XEN_ASSERT_TYPE(XEN_gchar__P(new_text), new_text, 2, "gtk_editable_insert_text", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(new_text_length), new_text_length, 3, "gtk_editable_insert_text", "gint");
  gtk_editable_insert_text(XEN_TO_C_GtkEditable_(editable), XEN_TO_C_gchar_(new_text), XEN_TO_C_gint(new_text_length), &ref_position);
  return(XEN_LIST_1(C_TO_XEN_gint(ref_position)));
}
static XEN gxg_gtk_editable_delete_text(XEN editable, XEN start_pos, XEN end_pos)
{
  #define H_gtk_editable_delete_text "void gtk_editable_delete_text(GtkEditable* editable, gint start_pos, \
gint end_pos)"
  XEN_ASSERT_TYPE(XEN_GtkEditable__P(editable), editable, 1, "gtk_editable_delete_text", "GtkEditable*");
  XEN_ASSERT_TYPE(XEN_gint_P(start_pos), start_pos, 2, "gtk_editable_delete_text", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(end_pos), end_pos, 3, "gtk_editable_delete_text", "gint");
  gtk_editable_delete_text(XEN_TO_C_GtkEditable_(editable), XEN_TO_C_gint(start_pos), XEN_TO_C_gint(end_pos));
  return(XEN_FALSE);
}
static XEN gxg_gtk_editable_get_chars(XEN editable, XEN start_pos, XEN end_pos)
{
  #define H_gtk_editable_get_chars "gchar* gtk_editable_get_chars(GtkEditable* editable, gint start_pos, \
gint end_pos)"
  XEN_ASSERT_TYPE(XEN_GtkEditable__P(editable), editable, 1, "gtk_editable_get_chars", "GtkEditable*");
  XEN_ASSERT_TYPE(XEN_gint_P(start_pos), start_pos, 2, "gtk_editable_get_chars", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(end_pos), end_pos, 3, "gtk_editable_get_chars", "gint");
  return(C_TO_XEN_gchar_(gtk_editable_get_chars(XEN_TO_C_GtkEditable_(editable), XEN_TO_C_gint(start_pos), XEN_TO_C_gint(end_pos))));
}
static XEN gxg_gtk_editable_cut_clipboard(XEN editable)
{
  #define H_gtk_editable_cut_clipboard "void gtk_editable_cut_clipboard(GtkEditable* editable)"
  XEN_ASSERT_TYPE(XEN_GtkEditable__P(editable), editable, 1, "gtk_editable_cut_clipboard", "GtkEditable*");
  gtk_editable_cut_clipboard(XEN_TO_C_GtkEditable_(editable));
  return(XEN_FALSE);
}
static XEN gxg_gtk_editable_copy_clipboard(XEN editable)
{
  #define H_gtk_editable_copy_clipboard "void gtk_editable_copy_clipboard(GtkEditable* editable)"
  XEN_ASSERT_TYPE(XEN_GtkEditable__P(editable), editable, 1, "gtk_editable_copy_clipboard", "GtkEditable*");
  gtk_editable_copy_clipboard(XEN_TO_C_GtkEditable_(editable));
  return(XEN_FALSE);
}
static XEN gxg_gtk_editable_paste_clipboard(XEN editable)
{
  #define H_gtk_editable_paste_clipboard "void gtk_editable_paste_clipboard(GtkEditable* editable)"
  XEN_ASSERT_TYPE(XEN_GtkEditable__P(editable), editable, 1, "gtk_editable_paste_clipboard", "GtkEditable*");
  gtk_editable_paste_clipboard(XEN_TO_C_GtkEditable_(editable));
  return(XEN_FALSE);
}
static XEN gxg_gtk_editable_delete_selection(XEN editable)
{
  #define H_gtk_editable_delete_selection "void gtk_editable_delete_selection(GtkEditable* editable)"
  XEN_ASSERT_TYPE(XEN_GtkEditable__P(editable), editable, 1, "gtk_editable_delete_selection", "GtkEditable*");
  gtk_editable_delete_selection(XEN_TO_C_GtkEditable_(editable));
  return(XEN_FALSE);
}
static XEN gxg_gtk_editable_set_position(XEN editable, XEN position)
{
  #define H_gtk_editable_set_position "void gtk_editable_set_position(GtkEditable* editable, gint position)"
  XEN_ASSERT_TYPE(XEN_GtkEditable__P(editable), editable, 1, "gtk_editable_set_position", "GtkEditable*");
  XEN_ASSERT_TYPE(XEN_gint_P(position), position, 2, "gtk_editable_set_position", "gint");
  gtk_editable_set_position(XEN_TO_C_GtkEditable_(editable), XEN_TO_C_gint(position));
  return(XEN_FALSE);
}
static XEN gxg_gtk_editable_get_position(XEN editable)
{
  #define H_gtk_editable_get_position "gint gtk_editable_get_position(GtkEditable* editable)"
  XEN_ASSERT_TYPE(XEN_GtkEditable__P(editable), editable, 1, "gtk_editable_get_position", "GtkEditable*");
  return(C_TO_XEN_gint(gtk_editable_get_position(XEN_TO_C_GtkEditable_(editable))));
}
static XEN gxg_gtk_editable_set_editable(XEN editable, XEN is_editable)
{
  #define H_gtk_editable_set_editable "void gtk_editable_set_editable(GtkEditable* editable, gboolean is_editable)"
  XEN_ASSERT_TYPE(XEN_GtkEditable__P(editable), editable, 1, "gtk_editable_set_editable", "GtkEditable*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(is_editable), is_editable, 2, "gtk_editable_set_editable", "gboolean");
  gtk_editable_set_editable(XEN_TO_C_GtkEditable_(editable), XEN_TO_C_gboolean(is_editable));
  return(XEN_FALSE);
}
static XEN gxg_gtk_editable_get_editable(XEN editable)
{
  #define H_gtk_editable_get_editable "gboolean gtk_editable_get_editable(GtkEditable* editable)"
  XEN_ASSERT_TYPE(XEN_GtkEditable__P(editable), editable, 1, "gtk_editable_get_editable", "GtkEditable*");
  return(C_TO_XEN_gboolean(gtk_editable_get_editable(XEN_TO_C_GtkEditable_(editable))));
}
static XEN gxg_gtk_entry_get_type(void)
{
  #define H_gtk_entry_get_type "GtkType gtk_entry_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_entry_get_type()));
}
static XEN gxg_gtk_entry_new(void)
{
  #define H_gtk_entry_new "GtkWidget* gtk_entry_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_entry_new()));
}
static XEN gxg_gtk_entry_set_visibility(XEN entry, XEN visible)
{
  #define H_gtk_entry_set_visibility "void gtk_entry_set_visibility(GtkEntry* entry, gboolean visible)"
  XEN_ASSERT_TYPE(XEN_GtkEntry__P(entry), entry, 1, "gtk_entry_set_visibility", "GtkEntry*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(visible), visible, 2, "gtk_entry_set_visibility", "gboolean");
  gtk_entry_set_visibility(XEN_TO_C_GtkEntry_(entry), XEN_TO_C_gboolean(visible));
  return(XEN_FALSE);
}
static XEN gxg_gtk_entry_get_visibility(XEN entry)
{
  #define H_gtk_entry_get_visibility "gboolean gtk_entry_get_visibility(GtkEntry* entry)"
  XEN_ASSERT_TYPE(XEN_GtkEntry__P(entry), entry, 1, "gtk_entry_get_visibility", "GtkEntry*");
  return(C_TO_XEN_gboolean(gtk_entry_get_visibility(XEN_TO_C_GtkEntry_(entry))));
}
static XEN gxg_gtk_entry_set_invisible_char(XEN entry, XEN ch)
{
  #define H_gtk_entry_set_invisible_char "void gtk_entry_set_invisible_char(GtkEntry* entry, gunichar ch)"
  XEN_ASSERT_TYPE(XEN_GtkEntry__P(entry), entry, 1, "gtk_entry_set_invisible_char", "GtkEntry*");
  XEN_ASSERT_TYPE(XEN_gunichar_P(ch), ch, 2, "gtk_entry_set_invisible_char", "gunichar");
  gtk_entry_set_invisible_char(XEN_TO_C_GtkEntry_(entry), XEN_TO_C_gunichar(ch));
  return(XEN_FALSE);
}
static XEN gxg_gtk_entry_get_invisible_char(XEN entry)
{
  #define H_gtk_entry_get_invisible_char "gunichar gtk_entry_get_invisible_char(GtkEntry* entry)"
  XEN_ASSERT_TYPE(XEN_GtkEntry__P(entry), entry, 1, "gtk_entry_get_invisible_char", "GtkEntry*");
  return(C_TO_XEN_gunichar(gtk_entry_get_invisible_char(XEN_TO_C_GtkEntry_(entry))));
}
static XEN gxg_gtk_entry_set_has_frame(XEN entry, XEN setting)
{
  #define H_gtk_entry_set_has_frame "void gtk_entry_set_has_frame(GtkEntry* entry, gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GtkEntry__P(entry), entry, 1, "gtk_entry_set_has_frame", "GtkEntry*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gtk_entry_set_has_frame", "gboolean");
  gtk_entry_set_has_frame(XEN_TO_C_GtkEntry_(entry), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_entry_get_has_frame(XEN entry)
{
  #define H_gtk_entry_get_has_frame "gboolean gtk_entry_get_has_frame(GtkEntry* entry)"
  XEN_ASSERT_TYPE(XEN_GtkEntry__P(entry), entry, 1, "gtk_entry_get_has_frame", "GtkEntry*");
  return(C_TO_XEN_gboolean(gtk_entry_get_has_frame(XEN_TO_C_GtkEntry_(entry))));
}
static XEN gxg_gtk_entry_set_max_length(XEN entry, XEN max)
{
  #define H_gtk_entry_set_max_length "void gtk_entry_set_max_length(GtkEntry* entry, gint max)"
  XEN_ASSERT_TYPE(XEN_GtkEntry__P(entry), entry, 1, "gtk_entry_set_max_length", "GtkEntry*");
  XEN_ASSERT_TYPE(XEN_gint_P(max), max, 2, "gtk_entry_set_max_length", "gint");
  gtk_entry_set_max_length(XEN_TO_C_GtkEntry_(entry), XEN_TO_C_gint(max));
  return(XEN_FALSE);
}
static XEN gxg_gtk_entry_get_max_length(XEN entry)
{
  #define H_gtk_entry_get_max_length "gint gtk_entry_get_max_length(GtkEntry* entry)"
  XEN_ASSERT_TYPE(XEN_GtkEntry__P(entry), entry, 1, "gtk_entry_get_max_length", "GtkEntry*");
  return(C_TO_XEN_gint(gtk_entry_get_max_length(XEN_TO_C_GtkEntry_(entry))));
}
static XEN gxg_gtk_entry_set_activates_default(XEN entry, XEN setting)
{
  #define H_gtk_entry_set_activates_default "void gtk_entry_set_activates_default(GtkEntry* entry, gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GtkEntry__P(entry), entry, 1, "gtk_entry_set_activates_default", "GtkEntry*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gtk_entry_set_activates_default", "gboolean");
  gtk_entry_set_activates_default(XEN_TO_C_GtkEntry_(entry), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_entry_get_activates_default(XEN entry)
{
  #define H_gtk_entry_get_activates_default "gboolean gtk_entry_get_activates_default(GtkEntry* entry)"
  XEN_ASSERT_TYPE(XEN_GtkEntry__P(entry), entry, 1, "gtk_entry_get_activates_default", "GtkEntry*");
  return(C_TO_XEN_gboolean(gtk_entry_get_activates_default(XEN_TO_C_GtkEntry_(entry))));
}
static XEN gxg_gtk_entry_set_width_chars(XEN entry, XEN n_chars)
{
  #define H_gtk_entry_set_width_chars "void gtk_entry_set_width_chars(GtkEntry* entry, gint n_chars)"
  XEN_ASSERT_TYPE(XEN_GtkEntry__P(entry), entry, 1, "gtk_entry_set_width_chars", "GtkEntry*");
  XEN_ASSERT_TYPE(XEN_gint_P(n_chars), n_chars, 2, "gtk_entry_set_width_chars", "gint");
  gtk_entry_set_width_chars(XEN_TO_C_GtkEntry_(entry), XEN_TO_C_gint(n_chars));
  return(XEN_FALSE);
}
static XEN gxg_gtk_entry_get_width_chars(XEN entry)
{
  #define H_gtk_entry_get_width_chars "gint gtk_entry_get_width_chars(GtkEntry* entry)"
  XEN_ASSERT_TYPE(XEN_GtkEntry__P(entry), entry, 1, "gtk_entry_get_width_chars", "GtkEntry*");
  return(C_TO_XEN_gint(gtk_entry_get_width_chars(XEN_TO_C_GtkEntry_(entry))));
}
static XEN gxg_gtk_entry_set_text(XEN entry, XEN text)
{
  #define H_gtk_entry_set_text "void gtk_entry_set_text(GtkEntry* entry, gchar* text)"
  XEN_ASSERT_TYPE(XEN_GtkEntry__P(entry), entry, 1, "gtk_entry_set_text", "GtkEntry*");
  XEN_ASSERT_TYPE(XEN_gchar__P(text), text, 2, "gtk_entry_set_text", "gchar*");
  gtk_entry_set_text(XEN_TO_C_GtkEntry_(entry), XEN_TO_C_gchar_(text));
  return(XEN_FALSE);
}
static XEN gxg_gtk_entry_get_text(XEN entry)
{
  #define H_gtk_entry_get_text "gchar* gtk_entry_get_text(GtkEntry* entry)"
  XEN_ASSERT_TYPE(XEN_GtkEntry__P(entry), entry, 1, "gtk_entry_get_text", "GtkEntry*");
  return(C_TO_XEN_gchar_(gtk_entry_get_text(XEN_TO_C_GtkEntry_(entry))));
}
static XEN gxg_gtk_entry_get_layout(XEN entry)
{
  #define H_gtk_entry_get_layout "PangoLayout* gtk_entry_get_layout(GtkEntry* entry)"
  XEN_ASSERT_TYPE(XEN_GtkEntry__P(entry), entry, 1, "gtk_entry_get_layout", "GtkEntry*");
  return(C_TO_XEN_PangoLayout_(gtk_entry_get_layout(XEN_TO_C_GtkEntry_(entry))));
}
static XEN gxg_gtk_entry_get_layout_offsets(XEN entry, XEN x, XEN y)
{
  #define H_gtk_entry_get_layout_offsets "void gtk_entry_get_layout_offsets(GtkEntry* entry, gint* [x], \
gint* [y])"
  gint ref_x;
  gint ref_y;
  XEN_ASSERT_TYPE(XEN_GtkEntry__P(entry), entry, 1, "gtk_entry_get_layout_offsets", "GtkEntry*");
  gtk_entry_get_layout_offsets(XEN_TO_C_GtkEntry_(entry), &ref_x, &ref_y);
  return(XEN_LIST_2(C_TO_XEN_gint(ref_x), C_TO_XEN_gint(ref_y)));
}
static XEN gxg_gtk_event_box_get_type(void)
{
  #define H_gtk_event_box_get_type "GtkType gtk_event_box_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_event_box_get_type()));
}
static XEN gxg_gtk_event_box_new(void)
{
  #define H_gtk_event_box_new "GtkWidget* gtk_event_box_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_event_box_new()));
}
static XEN gxg_gtk_file_selection_get_type(void)
{
  #define H_gtk_file_selection_get_type "GtkType gtk_file_selection_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_file_selection_get_type()));
}
static XEN gxg_gtk_file_selection_new(XEN title)
{
  #define H_gtk_file_selection_new "GtkWidget* gtk_file_selection_new(gchar* title)"
  XEN_ASSERT_TYPE(XEN_gchar__P(title), title, 1, "gtk_file_selection_new", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_file_selection_new(XEN_TO_C_gchar_(title))));
}
static XEN gxg_gtk_file_selection_set_filename(XEN filesel, XEN filename)
{
  #define H_gtk_file_selection_set_filename "void gtk_file_selection_set_filename(GtkFileSelection* filesel, \
gchar* filename)"
  XEN_ASSERT_TYPE(XEN_GtkFileSelection__P(filesel), filesel, 1, "gtk_file_selection_set_filename", "GtkFileSelection*");
  XEN_ASSERT_TYPE(XEN_gchar__P(filename), filename, 2, "gtk_file_selection_set_filename", "gchar*");
  gtk_file_selection_set_filename(XEN_TO_C_GtkFileSelection_(filesel), XEN_TO_C_gchar_(filename));
  return(XEN_FALSE);
}
static XEN gxg_gtk_file_selection_get_filename(XEN filesel)
{
  #define H_gtk_file_selection_get_filename "gchar* gtk_file_selection_get_filename(GtkFileSelection* filesel)"
  XEN_ASSERT_TYPE(XEN_GtkFileSelection__P(filesel), filesel, 1, "gtk_file_selection_get_filename", "GtkFileSelection*");
  return(C_TO_XEN_gchar_(gtk_file_selection_get_filename(XEN_TO_C_GtkFileSelection_(filesel))));
}
static XEN gxg_gtk_file_selection_complete(XEN filesel, XEN pattern)
{
  #define H_gtk_file_selection_complete "void gtk_file_selection_complete(GtkFileSelection* filesel, \
gchar* pattern)"
  XEN_ASSERT_TYPE(XEN_GtkFileSelection__P(filesel), filesel, 1, "gtk_file_selection_complete", "GtkFileSelection*");
  XEN_ASSERT_TYPE(XEN_gchar__P(pattern), pattern, 2, "gtk_file_selection_complete", "gchar*");
  gtk_file_selection_complete(XEN_TO_C_GtkFileSelection_(filesel), XEN_TO_C_gchar_(pattern));
  return(XEN_FALSE);
}
static XEN gxg_gtk_file_selection_show_fileop_buttons(XEN filesel)
{
  #define H_gtk_file_selection_show_fileop_buttons "void gtk_file_selection_show_fileop_buttons(GtkFileSelection* filesel)"
  XEN_ASSERT_TYPE(XEN_GtkFileSelection__P(filesel), filesel, 1, "gtk_file_selection_show_fileop_buttons", "GtkFileSelection*");
  gtk_file_selection_show_fileop_buttons(XEN_TO_C_GtkFileSelection_(filesel));
  return(XEN_FALSE);
}
static XEN gxg_gtk_file_selection_hide_fileop_buttons(XEN filesel)
{
  #define H_gtk_file_selection_hide_fileop_buttons "void gtk_file_selection_hide_fileop_buttons(GtkFileSelection* filesel)"
  XEN_ASSERT_TYPE(XEN_GtkFileSelection__P(filesel), filesel, 1, "gtk_file_selection_hide_fileop_buttons", "GtkFileSelection*");
  gtk_file_selection_hide_fileop_buttons(XEN_TO_C_GtkFileSelection_(filesel));
  return(XEN_FALSE);
}
static XEN gxg_gtk_file_selection_get_selections(XEN filesel)
{
  #define H_gtk_file_selection_get_selections "gchar** gtk_file_selection_get_selections(GtkFileSelection* filesel)"
  XEN_ASSERT_TYPE(XEN_GtkFileSelection__P(filesel), filesel, 1, "gtk_file_selection_get_selections", "GtkFileSelection*");
  return(C_TO_XEN_gchar__(gtk_file_selection_get_selections(XEN_TO_C_GtkFileSelection_(filesel))));
}
static XEN gxg_gtk_file_selection_set_select_multiple(XEN filesel, XEN select_multiple)
{
  #define H_gtk_file_selection_set_select_multiple "void gtk_file_selection_set_select_multiple(GtkFileSelection* filesel, \
gboolean select_multiple)"
  XEN_ASSERT_TYPE(XEN_GtkFileSelection__P(filesel), filesel, 1, "gtk_file_selection_set_select_multiple", "GtkFileSelection*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(select_multiple), select_multiple, 2, "gtk_file_selection_set_select_multiple", "gboolean");
  gtk_file_selection_set_select_multiple(XEN_TO_C_GtkFileSelection_(filesel), XEN_TO_C_gboolean(select_multiple));
  return(XEN_FALSE);
}
static XEN gxg_gtk_file_selection_get_select_multiple(XEN filesel)
{
  #define H_gtk_file_selection_get_select_multiple "gboolean gtk_file_selection_get_select_multiple(GtkFileSelection* filesel)"
  XEN_ASSERT_TYPE(XEN_GtkFileSelection__P(filesel), filesel, 1, "gtk_file_selection_get_select_multiple", "GtkFileSelection*");
  return(C_TO_XEN_gboolean(gtk_file_selection_get_select_multiple(XEN_TO_C_GtkFileSelection_(filesel))));
}
static XEN gxg_gtk_icon_set_get_type(void)
{
  #define H_gtk_icon_set_get_type "GType gtk_icon_set_get_type( void)"
  return(C_TO_XEN_GType(gtk_icon_set_get_type()));
}
static XEN gxg_gtk_icon_source_get_type(void)
{
  #define H_gtk_icon_source_get_type "GType gtk_icon_source_get_type( void)"
  return(C_TO_XEN_GType(gtk_icon_source_get_type()));
}
static XEN gxg_gtk_selection_data_get_type(void)
{
  #define H_gtk_selection_data_get_type "GType gtk_selection_data_get_type( void)"
  return(C_TO_XEN_GType(gtk_selection_data_get_type()));
}
static XEN gxg_gtk_border_get_type(void)
{
  #define H_gtk_border_get_type "GType gtk_border_get_type( void)"
  return(C_TO_XEN_GType(gtk_border_get_type()));
}
static XEN gxg_gtk_tree_path_get_type(void)
{
  #define H_gtk_tree_path_get_type "GType gtk_tree_path_get_type( void)"
  return(C_TO_XEN_GType(gtk_tree_path_get_type()));
}
static XEN gxg_gtk_tree_iter_get_type(void)
{
  #define H_gtk_tree_iter_get_type "GType gtk_tree_iter_get_type( void)"
  return(C_TO_XEN_GType(gtk_tree_iter_get_type()));
}
static XEN gxg_gtk_identifier_get_type(void)
{
  #define H_gtk_identifier_get_type "GType gtk_identifier_get_type( void)"
  return(C_TO_XEN_GType(gtk_identifier_get_type()));
}
static XEN gxg_gtk_requisition_get_type(void)
{
  #define H_gtk_requisition_get_type "GType gtk_requisition_get_type( void)"
  return(C_TO_XEN_GType(gtk_requisition_get_type()));
}
static XEN gxg_gtk_fixed_get_type(void)
{
  #define H_gtk_fixed_get_type "GtkType gtk_fixed_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_fixed_get_type()));
}
static XEN gxg_gtk_fixed_new(void)
{
  #define H_gtk_fixed_new "GtkWidget* gtk_fixed_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_fixed_new()));
}
static XEN gxg_gtk_fixed_put(XEN fixed, XEN widget, XEN x, XEN y)
{
  #define H_gtk_fixed_put "void gtk_fixed_put(GtkFixed* fixed, GtkWidget* widget, gint x, gint y)"
  XEN_ASSERT_TYPE(XEN_GtkFixed__P(fixed), fixed, 1, "gtk_fixed_put", "GtkFixed*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 2, "gtk_fixed_put", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 3, "gtk_fixed_put", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 4, "gtk_fixed_put", "gint");
  gtk_fixed_put(XEN_TO_C_GtkFixed_(fixed), XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gint(x), XEN_TO_C_gint(y));
  return(XEN_FALSE);
}
static XEN gxg_gtk_fixed_move(XEN fixed, XEN widget, XEN x, XEN y)
{
  #define H_gtk_fixed_move "void gtk_fixed_move(GtkFixed* fixed, GtkWidget* widget, gint x, gint y)"
  XEN_ASSERT_TYPE(XEN_GtkFixed__P(fixed), fixed, 1, "gtk_fixed_move", "GtkFixed*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 2, "gtk_fixed_move", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 3, "gtk_fixed_move", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 4, "gtk_fixed_move", "gint");
  gtk_fixed_move(XEN_TO_C_GtkFixed_(fixed), XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gint(x), XEN_TO_C_gint(y));
  return(XEN_FALSE);
}
static XEN gxg_gtk_fixed_set_has_window(XEN fixed, XEN has_window)
{
  #define H_gtk_fixed_set_has_window "void gtk_fixed_set_has_window(GtkFixed* fixed, gboolean has_window)"
  XEN_ASSERT_TYPE(XEN_GtkFixed__P(fixed), fixed, 1, "gtk_fixed_set_has_window", "GtkFixed*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(has_window), has_window, 2, "gtk_fixed_set_has_window", "gboolean");
  gtk_fixed_set_has_window(XEN_TO_C_GtkFixed_(fixed), XEN_TO_C_gboolean(has_window));
  return(XEN_FALSE);
}
static XEN gxg_gtk_fixed_get_has_window(XEN fixed)
{
  #define H_gtk_fixed_get_has_window "gboolean gtk_fixed_get_has_window(GtkFixed* fixed)"
  XEN_ASSERT_TYPE(XEN_GtkFixed__P(fixed), fixed, 1, "gtk_fixed_get_has_window", "GtkFixed*");
  return(C_TO_XEN_gboolean(gtk_fixed_get_has_window(XEN_TO_C_GtkFixed_(fixed))));
}
static XEN gxg_gtk_font_selection_get_type(void)
{
  #define H_gtk_font_selection_get_type "GtkType gtk_font_selection_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_font_selection_get_type()));
}
static XEN gxg_gtk_font_selection_new(void)
{
  #define H_gtk_font_selection_new "GtkWidget* gtk_font_selection_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_font_selection_new()));
}
static XEN gxg_gtk_font_selection_get_font_name(XEN fontsel)
{
  #define H_gtk_font_selection_get_font_name "gchar* gtk_font_selection_get_font_name(GtkFontSelection* fontsel)"
  XEN_ASSERT_TYPE(XEN_GtkFontSelection__P(fontsel), fontsel, 1, "gtk_font_selection_get_font_name", "GtkFontSelection*");
  return(C_TO_XEN_gchar_(gtk_font_selection_get_font_name(XEN_TO_C_GtkFontSelection_(fontsel))));
}
static XEN gxg_gtk_font_selection_set_font_name(XEN fontsel, XEN fontname)
{
  #define H_gtk_font_selection_set_font_name "gboolean gtk_font_selection_set_font_name(GtkFontSelection* fontsel, \
gchar* fontname)"
  XEN_ASSERT_TYPE(XEN_GtkFontSelection__P(fontsel), fontsel, 1, "gtk_font_selection_set_font_name", "GtkFontSelection*");
  XEN_ASSERT_TYPE(XEN_gchar__P(fontname), fontname, 2, "gtk_font_selection_set_font_name", "gchar*");
  return(C_TO_XEN_gboolean(gtk_font_selection_set_font_name(XEN_TO_C_GtkFontSelection_(fontsel), XEN_TO_C_gchar_(fontname))));
}
static XEN gxg_gtk_font_selection_get_preview_text(XEN fontsel)
{
  #define H_gtk_font_selection_get_preview_text "gchar* gtk_font_selection_get_preview_text(GtkFontSelection* fontsel)"
  XEN_ASSERT_TYPE(XEN_GtkFontSelection__P(fontsel), fontsel, 1, "gtk_font_selection_get_preview_text", "GtkFontSelection*");
  return(C_TO_XEN_gchar_(gtk_font_selection_get_preview_text(XEN_TO_C_GtkFontSelection_(fontsel))));
}
static XEN gxg_gtk_font_selection_set_preview_text(XEN fontsel, XEN text)
{
  #define H_gtk_font_selection_set_preview_text "void gtk_font_selection_set_preview_text(GtkFontSelection* fontsel, \
gchar* text)"
  XEN_ASSERT_TYPE(XEN_GtkFontSelection__P(fontsel), fontsel, 1, "gtk_font_selection_set_preview_text", "GtkFontSelection*");
  XEN_ASSERT_TYPE(XEN_gchar__P(text), text, 2, "gtk_font_selection_set_preview_text", "gchar*");
  gtk_font_selection_set_preview_text(XEN_TO_C_GtkFontSelection_(fontsel), XEN_TO_C_gchar_(text));
  return(XEN_FALSE);
}
static XEN gxg_gtk_font_selection_dialog_get_type(void)
{
  #define H_gtk_font_selection_dialog_get_type "GtkType gtk_font_selection_dialog_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_font_selection_dialog_get_type()));
}
static XEN gxg_gtk_font_selection_dialog_new(XEN title)
{
  #define H_gtk_font_selection_dialog_new "GtkWidget* gtk_font_selection_dialog_new(gchar* title)"
  XEN_ASSERT_TYPE(XEN_gchar__P(title), title, 1, "gtk_font_selection_dialog_new", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_font_selection_dialog_new(XEN_TO_C_gchar_(title))));
}
static XEN gxg_gtk_font_selection_dialog_get_font_name(XEN fsd)
{
  #define H_gtk_font_selection_dialog_get_font_name "gchar* gtk_font_selection_dialog_get_font_name(GtkFontSelectionDialog* fsd)"
  XEN_ASSERT_TYPE(XEN_GtkFontSelectionDialog__P(fsd), fsd, 1, "gtk_font_selection_dialog_get_font_name", "GtkFontSelectionDialog*");
  return(C_TO_XEN_gchar_(gtk_font_selection_dialog_get_font_name(XEN_TO_C_GtkFontSelectionDialog_(fsd))));
}
static XEN gxg_gtk_font_selection_dialog_set_font_name(XEN fsd, XEN fontname)
{
  #define H_gtk_font_selection_dialog_set_font_name "gboolean gtk_font_selection_dialog_set_font_name(GtkFontSelectionDialog* fsd, \
gchar* fontname)"
  XEN_ASSERT_TYPE(XEN_GtkFontSelectionDialog__P(fsd), fsd, 1, "gtk_font_selection_dialog_set_font_name", "GtkFontSelectionDialog*");
  XEN_ASSERT_TYPE(XEN_gchar__P(fontname), fontname, 2, "gtk_font_selection_dialog_set_font_name", "gchar*");
  return(C_TO_XEN_gboolean(gtk_font_selection_dialog_set_font_name(XEN_TO_C_GtkFontSelectionDialog_(fsd), XEN_TO_C_gchar_(fontname))));
}
static XEN gxg_gtk_font_selection_dialog_get_preview_text(XEN fsd)
{
  #define H_gtk_font_selection_dialog_get_preview_text "gchar* gtk_font_selection_dialog_get_preview_text(GtkFontSelectionDialog* fsd)"
  XEN_ASSERT_TYPE(XEN_GtkFontSelectionDialog__P(fsd), fsd, 1, "gtk_font_selection_dialog_get_preview_text", "GtkFontSelectionDialog*");
  return(C_TO_XEN_gchar_(gtk_font_selection_dialog_get_preview_text(XEN_TO_C_GtkFontSelectionDialog_(fsd))));
}
static XEN gxg_gtk_font_selection_dialog_set_preview_text(XEN fsd, XEN text)
{
  #define H_gtk_font_selection_dialog_set_preview_text "void gtk_font_selection_dialog_set_preview_text(GtkFontSelectionDialog* fsd, \
gchar* text)"
  XEN_ASSERT_TYPE(XEN_GtkFontSelectionDialog__P(fsd), fsd, 1, "gtk_font_selection_dialog_set_preview_text", "GtkFontSelectionDialog*");
  XEN_ASSERT_TYPE(XEN_gchar__P(text), text, 2, "gtk_font_selection_dialog_set_preview_text", "gchar*");
  gtk_font_selection_dialog_set_preview_text(XEN_TO_C_GtkFontSelectionDialog_(fsd), XEN_TO_C_gchar_(text));
  return(XEN_FALSE);
}
static XEN gxg_gtk_frame_get_type(void)
{
  #define H_gtk_frame_get_type "GtkType gtk_frame_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_frame_get_type()));
}
static XEN gxg_gtk_frame_new(XEN label)
{
  #define H_gtk_frame_new "GtkWidget* gtk_frame_new(gchar* label)"
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 1, "gtk_frame_new", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_frame_new(XEN_TO_C_gchar_(label))));
}
static XEN gxg_gtk_frame_set_label(XEN frame, XEN label)
{
  #define H_gtk_frame_set_label "void gtk_frame_set_label(GtkFrame* frame, gchar* label)"
  XEN_ASSERT_TYPE(XEN_GtkFrame__P(frame), frame, 1, "gtk_frame_set_label", "GtkFrame*");
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 2, "gtk_frame_set_label", "gchar*");
  gtk_frame_set_label(XEN_TO_C_GtkFrame_(frame), XEN_TO_C_gchar_(label));
  return(XEN_FALSE);
}
static XEN gxg_gtk_frame_get_label(XEN frame)
{
  #define H_gtk_frame_get_label "gchar* gtk_frame_get_label(GtkFrame* frame)"
  XEN_ASSERT_TYPE(XEN_GtkFrame__P(frame), frame, 1, "gtk_frame_get_label", "GtkFrame*");
  return(C_TO_XEN_gchar_(gtk_frame_get_label(XEN_TO_C_GtkFrame_(frame))));
}
static XEN gxg_gtk_frame_set_label_widget(XEN frame, XEN label_widget)
{
  #define H_gtk_frame_set_label_widget "void gtk_frame_set_label_widget(GtkFrame* frame, GtkWidget* label_widget)"
  XEN_ASSERT_TYPE(XEN_GtkFrame__P(frame), frame, 1, "gtk_frame_set_label_widget", "GtkFrame*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(label_widget), label_widget, 2, "gtk_frame_set_label_widget", "GtkWidget*");
  gtk_frame_set_label_widget(XEN_TO_C_GtkFrame_(frame), XEN_TO_C_GtkWidget_(label_widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_frame_get_label_widget(XEN frame)
{
  #define H_gtk_frame_get_label_widget "GtkWidget* gtk_frame_get_label_widget(GtkFrame* frame)"
  XEN_ASSERT_TYPE(XEN_GtkFrame__P(frame), frame, 1, "gtk_frame_get_label_widget", "GtkFrame*");
  return(C_TO_XEN_GtkWidget_(gtk_frame_get_label_widget(XEN_TO_C_GtkFrame_(frame))));
}
static XEN gxg_gtk_frame_set_label_align(XEN frame, XEN xalign, XEN yalign)
{
  #define H_gtk_frame_set_label_align "void gtk_frame_set_label_align(GtkFrame* frame, gfloat xalign, \
gfloat yalign)"
  XEN_ASSERT_TYPE(XEN_GtkFrame__P(frame), frame, 1, "gtk_frame_set_label_align", "GtkFrame*");
  XEN_ASSERT_TYPE(XEN_gfloat_P(xalign), xalign, 2, "gtk_frame_set_label_align", "gfloat");
  XEN_ASSERT_TYPE(XEN_gfloat_P(yalign), yalign, 3, "gtk_frame_set_label_align", "gfloat");
  gtk_frame_set_label_align(XEN_TO_C_GtkFrame_(frame), XEN_TO_C_gfloat(xalign), XEN_TO_C_gfloat(yalign));
  return(XEN_FALSE);
}
static XEN gxg_gtk_frame_get_label_align(XEN frame, XEN xalign, XEN yalign)
{
  #define H_gtk_frame_get_label_align "void gtk_frame_get_label_align(GtkFrame* frame, gfloat* [xalign], \
gfloat* [yalign])"
  gfloat ref_xalign;
  gfloat ref_yalign;
  XEN_ASSERT_TYPE(XEN_GtkFrame__P(frame), frame, 1, "gtk_frame_get_label_align", "GtkFrame*");
  gtk_frame_get_label_align(XEN_TO_C_GtkFrame_(frame), &ref_xalign, &ref_yalign);
  return(XEN_LIST_2(C_TO_XEN_gfloat(ref_xalign), C_TO_XEN_gfloat(ref_yalign)));
}
static XEN gxg_gtk_frame_set_shadow_type(XEN frame, XEN type)
{
  #define H_gtk_frame_set_shadow_type "void gtk_frame_set_shadow_type(GtkFrame* frame, GtkShadowType type)"
  XEN_ASSERT_TYPE(XEN_GtkFrame__P(frame), frame, 1, "gtk_frame_set_shadow_type", "GtkFrame*");
  XEN_ASSERT_TYPE(XEN_GtkShadowType_P(type), type, 2, "gtk_frame_set_shadow_type", "GtkShadowType");
  gtk_frame_set_shadow_type(XEN_TO_C_GtkFrame_(frame), XEN_TO_C_GtkShadowType(type));
  return(XEN_FALSE);
}
static XEN gxg_gtk_frame_get_shadow_type(XEN frame)
{
  #define H_gtk_frame_get_shadow_type "GtkShadowType gtk_frame_get_shadow_type(GtkFrame* frame)"
  XEN_ASSERT_TYPE(XEN_GtkFrame__P(frame), frame, 1, "gtk_frame_get_shadow_type", "GtkFrame*");
  return(C_TO_XEN_GtkShadowType(gtk_frame_get_shadow_type(XEN_TO_C_GtkFrame_(frame))));
}
static XEN gxg_gtk_gamma_curve_get_type(void)
{
  #define H_gtk_gamma_curve_get_type "GtkType gtk_gamma_curve_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_gamma_curve_get_type()));
}
static XEN gxg_gtk_gamma_curve_new(void)
{
  #define H_gtk_gamma_curve_new "GtkWidget* gtk_gamma_curve_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_gamma_curve_new()));
}
static XEN gxg_gtk_gc_get(XEN depth, XEN colormap, XEN values, XEN values_mask)
{
  #define H_gtk_gc_get "GdkGC* gtk_gc_get(gint depth, GdkColormap* colormap, GdkGCValues* values, GdkGCValuesMask values_mask)"
  XEN_ASSERT_TYPE(XEN_gint_P(depth), depth, 1, "gtk_gc_get", "gint");
  XEN_ASSERT_TYPE(XEN_GdkColormap__P(colormap), colormap, 2, "gtk_gc_get", "GdkColormap*");
  XEN_ASSERT_TYPE(XEN_GdkGCValues__P(values), values, 3, "gtk_gc_get", "GdkGCValues*");
  XEN_ASSERT_TYPE(XEN_GdkGCValuesMask_P(values_mask), values_mask, 4, "gtk_gc_get", "GdkGCValuesMask");
  return(C_TO_XEN_GdkGC_(gtk_gc_get(XEN_TO_C_gint(depth), XEN_TO_C_GdkColormap_(colormap), XEN_TO_C_GdkGCValues_(values), 
                                    XEN_TO_C_GdkGCValuesMask(values_mask))));
}
static XEN gxg_gtk_gc_release(XEN gc)
{
  #define H_gtk_gc_release "void gtk_gc_release(GdkGC* gc)"
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 1, "gtk_gc_release", "GdkGC*");
  gtk_gc_release(XEN_TO_C_GdkGC_(gc));
  return(XEN_FALSE);
}
static XEN gxg_gtk_handle_box_get_type(void)
{
  #define H_gtk_handle_box_get_type "GtkType gtk_handle_box_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_handle_box_get_type()));
}
static XEN gxg_gtk_handle_box_new(void)
{
  #define H_gtk_handle_box_new "GtkWidget* gtk_handle_box_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_handle_box_new()));
}
static XEN gxg_gtk_handle_box_set_shadow_type(XEN handle_box, XEN type)
{
  #define H_gtk_handle_box_set_shadow_type "void gtk_handle_box_set_shadow_type(GtkHandleBox* handle_box, \
GtkShadowType type)"
  XEN_ASSERT_TYPE(XEN_GtkHandleBox__P(handle_box), handle_box, 1, "gtk_handle_box_set_shadow_type", "GtkHandleBox*");
  XEN_ASSERT_TYPE(XEN_GtkShadowType_P(type), type, 2, "gtk_handle_box_set_shadow_type", "GtkShadowType");
  gtk_handle_box_set_shadow_type(XEN_TO_C_GtkHandleBox_(handle_box), XEN_TO_C_GtkShadowType(type));
  return(XEN_FALSE);
}
static XEN gxg_gtk_handle_box_get_shadow_type(XEN handle_box)
{
  #define H_gtk_handle_box_get_shadow_type "GtkShadowType gtk_handle_box_get_shadow_type(GtkHandleBox* handle_box)"
  XEN_ASSERT_TYPE(XEN_GtkHandleBox__P(handle_box), handle_box, 1, "gtk_handle_box_get_shadow_type", "GtkHandleBox*");
  return(C_TO_XEN_GtkShadowType(gtk_handle_box_get_shadow_type(XEN_TO_C_GtkHandleBox_(handle_box))));
}
static XEN gxg_gtk_handle_box_set_handle_position(XEN handle_box, XEN position)
{
  #define H_gtk_handle_box_set_handle_position "void gtk_handle_box_set_handle_position(GtkHandleBox* handle_box, \
GtkPositionType position)"
  XEN_ASSERT_TYPE(XEN_GtkHandleBox__P(handle_box), handle_box, 1, "gtk_handle_box_set_handle_position", "GtkHandleBox*");
  XEN_ASSERT_TYPE(XEN_GtkPositionType_P(position), position, 2, "gtk_handle_box_set_handle_position", "GtkPositionType");
  gtk_handle_box_set_handle_position(XEN_TO_C_GtkHandleBox_(handle_box), XEN_TO_C_GtkPositionType(position));
  return(XEN_FALSE);
}
static XEN gxg_gtk_handle_box_get_handle_position(XEN handle_box)
{
  #define H_gtk_handle_box_get_handle_position "GtkPositionType gtk_handle_box_get_handle_position(GtkHandleBox* handle_box)"
  XEN_ASSERT_TYPE(XEN_GtkHandleBox__P(handle_box), handle_box, 1, "gtk_handle_box_get_handle_position", "GtkHandleBox*");
  return(C_TO_XEN_GtkPositionType(gtk_handle_box_get_handle_position(XEN_TO_C_GtkHandleBox_(handle_box))));
}
static XEN gxg_gtk_handle_box_set_snap_edge(XEN handle_box, XEN edge)
{
  #define H_gtk_handle_box_set_snap_edge "void gtk_handle_box_set_snap_edge(GtkHandleBox* handle_box, \
GtkPositionType edge)"
  XEN_ASSERT_TYPE(XEN_GtkHandleBox__P(handle_box), handle_box, 1, "gtk_handle_box_set_snap_edge", "GtkHandleBox*");
  XEN_ASSERT_TYPE(XEN_GtkPositionType_P(edge), edge, 2, "gtk_handle_box_set_snap_edge", "GtkPositionType");
  gtk_handle_box_set_snap_edge(XEN_TO_C_GtkHandleBox_(handle_box), XEN_TO_C_GtkPositionType(edge));
  return(XEN_FALSE);
}
static XEN gxg_gtk_handle_box_get_snap_edge(XEN handle_box)
{
  #define H_gtk_handle_box_get_snap_edge "GtkPositionType gtk_handle_box_get_snap_edge(GtkHandleBox* handle_box)"
  XEN_ASSERT_TYPE(XEN_GtkHandleBox__P(handle_box), handle_box, 1, "gtk_handle_box_get_snap_edge", "GtkHandleBox*");
  return(C_TO_XEN_GtkPositionType(gtk_handle_box_get_snap_edge(XEN_TO_C_GtkHandleBox_(handle_box))));
}
static XEN gxg_gtk_hbutton_box_get_type(void)
{
  #define H_gtk_hbutton_box_get_type "GtkType gtk_hbutton_box_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_hbutton_box_get_type()));
}
static XEN gxg_gtk_hbutton_box_new(void)
{
  #define H_gtk_hbutton_box_new "GtkWidget* gtk_hbutton_box_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_hbutton_box_new()));
}
static XEN gxg_gtk_hbox_get_type(void)
{
  #define H_gtk_hbox_get_type "GtkType gtk_hbox_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_hbox_get_type()));
}
static XEN gxg_gtk_hbox_new(XEN homogeneous, XEN spacing)
{
  #define H_gtk_hbox_new "GtkWidget* gtk_hbox_new(gboolean homogeneous, gint spacing)"
  XEN_ASSERT_TYPE(XEN_gboolean_P(homogeneous), homogeneous, 1, "gtk_hbox_new", "gboolean");
  XEN_ASSERT_TYPE(XEN_gint_P(spacing), spacing, 2, "gtk_hbox_new", "gint");
  return(C_TO_XEN_GtkWidget_(gtk_hbox_new(XEN_TO_C_gboolean(homogeneous), XEN_TO_C_gint(spacing))));
}
static XEN gxg_gtk_hpaned_get_type(void)
{
  #define H_gtk_hpaned_get_type "GtkType gtk_hpaned_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_hpaned_get_type()));
}
static XEN gxg_gtk_hpaned_new(void)
{
  #define H_gtk_hpaned_new "GtkWidget* gtk_hpaned_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_hpaned_new()));
}
static XEN gxg_gtk_hruler_get_type(void)
{
  #define H_gtk_hruler_get_type "GtkType gtk_hruler_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_hruler_get_type()));
}
static XEN gxg_gtk_hruler_new(void)
{
  #define H_gtk_hruler_new "GtkWidget* gtk_hruler_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_hruler_new()));
}
static XEN gxg_gtk_hscale_get_type(void)
{
  #define H_gtk_hscale_get_type "GtkType gtk_hscale_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_hscale_get_type()));
}
static XEN gxg_gtk_hscale_new(XEN adjustment)
{
  #define H_gtk_hscale_new "GtkWidget* gtk_hscale_new(GtkAdjustment* adjustment)"
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(adjustment), adjustment, 1, "gtk_hscale_new", "GtkAdjustment*");
  return(C_TO_XEN_GtkWidget_(gtk_hscale_new(XEN_TO_C_GtkAdjustment_(adjustment))));
}
static XEN gxg_gtk_hscale_new_with_range(XEN min, XEN max, XEN step)
{
  #define H_gtk_hscale_new_with_range "GtkWidget* gtk_hscale_new_with_range(gdouble min, gdouble max, \
gdouble step)"
  XEN_ASSERT_TYPE(XEN_gdouble_P(min), min, 1, "gtk_hscale_new_with_range", "gdouble");
  XEN_ASSERT_TYPE(XEN_gdouble_P(max), max, 2, "gtk_hscale_new_with_range", "gdouble");
  XEN_ASSERT_TYPE(XEN_gdouble_P(step), step, 3, "gtk_hscale_new_with_range", "gdouble");
  return(C_TO_XEN_GtkWidget_(gtk_hscale_new_with_range(XEN_TO_C_gdouble(min), XEN_TO_C_gdouble(max), XEN_TO_C_gdouble(step))));
}
static XEN gxg_gtk_hscrollbar_get_type(void)
{
  #define H_gtk_hscrollbar_get_type "GtkType gtk_hscrollbar_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_hscrollbar_get_type()));
}
static XEN gxg_gtk_hscrollbar_new(XEN adjustment)
{
  #define H_gtk_hscrollbar_new "GtkWidget* gtk_hscrollbar_new(GtkAdjustment* adjustment)"
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(adjustment), adjustment, 1, "gtk_hscrollbar_new", "GtkAdjustment*");
  return(C_TO_XEN_GtkWidget_(gtk_hscrollbar_new(XEN_TO_C_GtkAdjustment_(adjustment))));
}
static XEN gxg_gtk_hseparator_get_type(void)
{
  #define H_gtk_hseparator_get_type "GtkType gtk_hseparator_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_hseparator_get_type()));
}
static XEN gxg_gtk_hseparator_new(void)
{
  #define H_gtk_hseparator_new "GtkWidget* gtk_hseparator_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_hseparator_new()));
}
static XEN gxg_gtk_icon_factory_get_type(void)
{
  #define H_gtk_icon_factory_get_type "GType gtk_icon_factory_get_type( void)"
  return(C_TO_XEN_GType(gtk_icon_factory_get_type()));
}
static XEN gxg_gtk_icon_factory_new(void)
{
  #define H_gtk_icon_factory_new "GtkIconFactory* gtk_icon_factory_new( void)"
  return(C_TO_XEN_GtkIconFactory_(gtk_icon_factory_new()));
}
static XEN gxg_gtk_icon_factory_add(XEN factory, XEN stock_id, XEN icon_set)
{
  #define H_gtk_icon_factory_add "void gtk_icon_factory_add(GtkIconFactory* factory, gchar* stock_id, \
GtkIconSet* icon_set)"
  XEN_ASSERT_TYPE(XEN_GtkIconFactory__P(factory), factory, 1, "gtk_icon_factory_add", "GtkIconFactory*");
  XEN_ASSERT_TYPE(XEN_gchar__P(stock_id), stock_id, 2, "gtk_icon_factory_add", "gchar*");
  XEN_ASSERT_TYPE(XEN_GtkIconSet__P(icon_set), icon_set, 3, "gtk_icon_factory_add", "GtkIconSet*");
  gtk_icon_factory_add(XEN_TO_C_GtkIconFactory_(factory), XEN_TO_C_gchar_(stock_id), XEN_TO_C_GtkIconSet_(icon_set));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_factory_lookup(XEN factory, XEN stock_id)
{
  #define H_gtk_icon_factory_lookup "GtkIconSet* gtk_icon_factory_lookup(GtkIconFactory* factory, gchar* stock_id)"
  XEN_ASSERT_TYPE(XEN_GtkIconFactory__P(factory), factory, 1, "gtk_icon_factory_lookup", "GtkIconFactory*");
  XEN_ASSERT_TYPE(XEN_gchar__P(stock_id), stock_id, 2, "gtk_icon_factory_lookup", "gchar*");
  return(C_TO_XEN_GtkIconSet_(gtk_icon_factory_lookup(XEN_TO_C_GtkIconFactory_(factory), XEN_TO_C_gchar_(stock_id))));
}
static XEN gxg_gtk_icon_factory_add_default(XEN factory)
{
  #define H_gtk_icon_factory_add_default "void gtk_icon_factory_add_default(GtkIconFactory* factory)"
  XEN_ASSERT_TYPE(XEN_GtkIconFactory__P(factory), factory, 1, "gtk_icon_factory_add_default", "GtkIconFactory*");
  gtk_icon_factory_add_default(XEN_TO_C_GtkIconFactory_(factory));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_factory_remove_default(XEN factory)
{
  #define H_gtk_icon_factory_remove_default "void gtk_icon_factory_remove_default(GtkIconFactory* factory)"
  XEN_ASSERT_TYPE(XEN_GtkIconFactory__P(factory), factory, 1, "gtk_icon_factory_remove_default", "GtkIconFactory*");
  gtk_icon_factory_remove_default(XEN_TO_C_GtkIconFactory_(factory));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_factory_lookup_default(XEN stock_id)
{
  #define H_gtk_icon_factory_lookup_default "GtkIconSet* gtk_icon_factory_lookup_default(gchar* stock_id)"
  XEN_ASSERT_TYPE(XEN_gchar__P(stock_id), stock_id, 1, "gtk_icon_factory_lookup_default", "gchar*");
  return(C_TO_XEN_GtkIconSet_(gtk_icon_factory_lookup_default(XEN_TO_C_gchar_(stock_id))));
}
static XEN gxg_gtk_icon_size_lookup(XEN size, XEN width, XEN height)
{
  #define H_gtk_icon_size_lookup "gboolean gtk_icon_size_lookup(GtkIconSize size, gint* [width], gint* [height])"
  gint ref_width;
  gint ref_height;
  XEN_ASSERT_TYPE(XEN_GtkIconSize_P(size), size, 1, "gtk_icon_size_lookup", "GtkIconSize");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gtk_icon_size_lookup(XEN_TO_C_GtkIconSize(size), &ref_width, &ref_height));
    return(XEN_LIST_3(result, C_TO_XEN_gint(ref_width), C_TO_XEN_gint(ref_height)));
   }
}
static XEN gxg_gtk_icon_size_register(XEN name, XEN width, XEN height)
{
  #define H_gtk_icon_size_register "GtkIconSize gtk_icon_size_register(gchar* name, gint width, gint height)"
  XEN_ASSERT_TYPE(XEN_gchar__P(name), name, 1, "gtk_icon_size_register", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 2, "gtk_icon_size_register", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 3, "gtk_icon_size_register", "gint");
  return(C_TO_XEN_GtkIconSize(gtk_icon_size_register(XEN_TO_C_gchar_(name), XEN_TO_C_gint(width), XEN_TO_C_gint(height))));
}
static XEN gxg_gtk_icon_size_register_alias(XEN alias, XEN target)
{
  #define H_gtk_icon_size_register_alias "void gtk_icon_size_register_alias(gchar* alias, GtkIconSize target)"
  XEN_ASSERT_TYPE(XEN_gchar__P(alias), alias, 1, "gtk_icon_size_register_alias", "gchar*");
  XEN_ASSERT_TYPE(XEN_GtkIconSize_P(target), target, 2, "gtk_icon_size_register_alias", "GtkIconSize");
  gtk_icon_size_register_alias(XEN_TO_C_gchar_(alias), XEN_TO_C_GtkIconSize(target));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_size_from_name(XEN name)
{
  #define H_gtk_icon_size_from_name "GtkIconSize gtk_icon_size_from_name(gchar* name)"
  XEN_ASSERT_TYPE(XEN_gchar__P(name), name, 1, "gtk_icon_size_from_name", "gchar*");
  return(C_TO_XEN_GtkIconSize(gtk_icon_size_from_name(XEN_TO_C_gchar_(name))));
}
static XEN gxg_gtk_icon_size_get_name(XEN size)
{
  #define H_gtk_icon_size_get_name "gchar* gtk_icon_size_get_name(GtkIconSize size)"
  XEN_ASSERT_TYPE(XEN_GtkIconSize_P(size), size, 1, "gtk_icon_size_get_name", "GtkIconSize");
  return(C_TO_XEN_gchar_(gtk_icon_size_get_name(XEN_TO_C_GtkIconSize(size))));
}
static XEN gxg_gtk_icon_set_new(void)
{
  #define H_gtk_icon_set_new "GtkIconSet* gtk_icon_set_new( void)"
  return(C_TO_XEN_GtkIconSet_(gtk_icon_set_new()));
}
static XEN gxg_gtk_icon_set_new_from_pixbuf(XEN pixbuf)
{
  #define H_gtk_icon_set_new_from_pixbuf "GtkIconSet* gtk_icon_set_new_from_pixbuf(GdkPixbuf* pixbuf)"
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(pixbuf), pixbuf, 1, "gtk_icon_set_new_from_pixbuf", "GdkPixbuf*");
  return(C_TO_XEN_GtkIconSet_(gtk_icon_set_new_from_pixbuf(XEN_TO_C_GdkPixbuf_(pixbuf))));
}
static XEN gxg_gtk_icon_set_ref(XEN icon_set)
{
  #define H_gtk_icon_set_ref "GtkIconSet* gtk_icon_set_ref(GtkIconSet* icon_set)"
  XEN_ASSERT_TYPE(XEN_GtkIconSet__P(icon_set), icon_set, 1, "gtk_icon_set_ref", "GtkIconSet*");
  return(C_TO_XEN_GtkIconSet_(gtk_icon_set_ref(XEN_TO_C_GtkIconSet_(icon_set))));
}
static XEN gxg_gtk_icon_set_unref(XEN icon_set)
{
  #define H_gtk_icon_set_unref "void gtk_icon_set_unref(GtkIconSet* icon_set)"
  XEN_ASSERT_TYPE(XEN_GtkIconSet__P(icon_set), icon_set, 1, "gtk_icon_set_unref", "GtkIconSet*");
  gtk_icon_set_unref(XEN_TO_C_GtkIconSet_(icon_set));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_set_copy(XEN icon_set)
{
  #define H_gtk_icon_set_copy "GtkIconSet* gtk_icon_set_copy(GtkIconSet* icon_set)"
  XEN_ASSERT_TYPE(XEN_GtkIconSet__P(icon_set), icon_set, 1, "gtk_icon_set_copy", "GtkIconSet*");
  return(C_TO_XEN_GtkIconSet_(gtk_icon_set_copy(XEN_TO_C_GtkIconSet_(icon_set))));
}
static XEN gxg_gtk_icon_set_render_icon(XEN icon_set, XEN style, XEN direction, XEN state, XEN size, XEN widget, XEN detail)
{
  #define H_gtk_icon_set_render_icon "GdkPixbuf* gtk_icon_set_render_icon(GtkIconSet* icon_set, GtkStyle* style, \
GtkTextDirection direction, GtkStateType state, GtkIconSize size, GtkWidget* widget, char* detail)"
  XEN_ASSERT_TYPE(XEN_GtkIconSet__P(icon_set), icon_set, 1, "gtk_icon_set_render_icon", "GtkIconSet*");
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(style) || XEN_FALSE_P(style), style, 2, "gtk_icon_set_render_icon", "GtkStyle*");
  XEN_ASSERT_TYPE(XEN_GtkTextDirection_P(direction), direction, 3, "gtk_icon_set_render_icon", "GtkTextDirection");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state), state, 4, "gtk_icon_set_render_icon", "GtkStateType");
  XEN_ASSERT_TYPE(XEN_GtkIconSize_P(size), size, 5, "gtk_icon_set_render_icon", "GtkIconSize");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget) || XEN_FALSE_P(widget), widget, 6, "gtk_icon_set_render_icon", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_char__P(detail), detail, 7, "gtk_icon_set_render_icon", "char*");
  return(C_TO_XEN_GdkPixbuf_(gtk_icon_set_render_icon(XEN_TO_C_GtkIconSet_(icon_set), XEN_TO_C_GtkStyle_(style), XEN_TO_C_GtkTextDirection(direction), 
                                                      XEN_TO_C_GtkStateType(state), XEN_TO_C_GtkIconSize(size), XEN_TO_C_GtkWidget_(widget), 
                                                      XEN_TO_C_char_(detail))));
}
static XEN gxg_gtk_icon_set_add_source(XEN icon_set, XEN source)
{
  #define H_gtk_icon_set_add_source "void gtk_icon_set_add_source(GtkIconSet* icon_set, GtkIconSource* source)"
  XEN_ASSERT_TYPE(XEN_GtkIconSet__P(icon_set), icon_set, 1, "gtk_icon_set_add_source", "GtkIconSet*");
  XEN_ASSERT_TYPE(XEN_GtkIconSource__P(source), source, 2, "gtk_icon_set_add_source", "GtkIconSource*");
  gtk_icon_set_add_source(XEN_TO_C_GtkIconSet_(icon_set), XEN_TO_C_GtkIconSource_(source));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_set_get_sizes(XEN icon_set, XEN sizes, XEN n_sizes)
{
  #define H_gtk_icon_set_get_sizes "void gtk_icon_set_get_sizes(GtkIconSet* icon_set, GtkIconSize** [sizes], \
gint* [n_sizes])"
  GtkIconSize* ref_sizes = NULL;
  gint ref_n_sizes;
  XEN_ASSERT_TYPE(XEN_GtkIconSet__P(icon_set), icon_set, 1, "gtk_icon_set_get_sizes", "GtkIconSet*");
  gtk_icon_set_get_sizes(XEN_TO_C_GtkIconSet_(icon_set), &ref_sizes, &ref_n_sizes);
  return(XEN_LIST_2(C_TO_XEN_GtkIconSize_(ref_sizes), C_TO_XEN_gint(ref_n_sizes)));
}
static XEN gxg_gtk_icon_source_new(void)
{
  #define H_gtk_icon_source_new "GtkIconSource* gtk_icon_source_new( void)"
  return(C_TO_XEN_GtkIconSource_(gtk_icon_source_new()));
}
static XEN gxg_gtk_icon_source_copy(XEN source)
{
  #define H_gtk_icon_source_copy "GtkIconSource* gtk_icon_source_copy(GtkIconSource* source)"
  XEN_ASSERT_TYPE(XEN_GtkIconSource__P(source), source, 1, "gtk_icon_source_copy", "GtkIconSource*");
  return(C_TO_XEN_GtkIconSource_(gtk_icon_source_copy(XEN_TO_C_GtkIconSource_(source))));
}
static XEN gxg_gtk_icon_source_free(XEN source)
{
  #define H_gtk_icon_source_free "void gtk_icon_source_free(GtkIconSource* source)"
  XEN_ASSERT_TYPE(XEN_GtkIconSource__P(source), source, 1, "gtk_icon_source_free", "GtkIconSource*");
  gtk_icon_source_free(XEN_TO_C_GtkIconSource_(source));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_source_set_filename(XEN source, XEN filename)
{
  #define H_gtk_icon_source_set_filename "void gtk_icon_source_set_filename(GtkIconSource* source, gchar* filename)"
  XEN_ASSERT_TYPE(XEN_GtkIconSource__P(source), source, 1, "gtk_icon_source_set_filename", "GtkIconSource*");
  XEN_ASSERT_TYPE(XEN_gchar__P(filename), filename, 2, "gtk_icon_source_set_filename", "gchar*");
  gtk_icon_source_set_filename(XEN_TO_C_GtkIconSource_(source), XEN_TO_C_gchar_(filename));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_source_set_pixbuf(XEN source, XEN pixbuf)
{
  #define H_gtk_icon_source_set_pixbuf "void gtk_icon_source_set_pixbuf(GtkIconSource* source, GdkPixbuf* pixbuf)"
  XEN_ASSERT_TYPE(XEN_GtkIconSource__P(source), source, 1, "gtk_icon_source_set_pixbuf", "GtkIconSource*");
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(pixbuf), pixbuf, 2, "gtk_icon_source_set_pixbuf", "GdkPixbuf*");
  gtk_icon_source_set_pixbuf(XEN_TO_C_GtkIconSource_(source), XEN_TO_C_GdkPixbuf_(pixbuf));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_source_get_filename(XEN source)
{
  #define H_gtk_icon_source_get_filename "gchar* gtk_icon_source_get_filename(GtkIconSource* source)"
  XEN_ASSERT_TYPE(XEN_GtkIconSource__P(source), source, 1, "gtk_icon_source_get_filename", "GtkIconSource*");
  return(C_TO_XEN_gchar_(gtk_icon_source_get_filename(XEN_TO_C_GtkIconSource_(source))));
}
static XEN gxg_gtk_icon_source_get_pixbuf(XEN source)
{
  #define H_gtk_icon_source_get_pixbuf "GdkPixbuf* gtk_icon_source_get_pixbuf(GtkIconSource* source)"
  XEN_ASSERT_TYPE(XEN_GtkIconSource__P(source), source, 1, "gtk_icon_source_get_pixbuf", "GtkIconSource*");
  return(C_TO_XEN_GdkPixbuf_(gtk_icon_source_get_pixbuf(XEN_TO_C_GtkIconSource_(source))));
}
static XEN gxg_gtk_icon_source_set_direction_wildcarded(XEN source, XEN setting)
{
  #define H_gtk_icon_source_set_direction_wildcarded "void gtk_icon_source_set_direction_wildcarded(GtkIconSource* source, \
gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GtkIconSource__P(source), source, 1, "gtk_icon_source_set_direction_wildcarded", "GtkIconSource*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gtk_icon_source_set_direction_wildcarded", "gboolean");
  gtk_icon_source_set_direction_wildcarded(XEN_TO_C_GtkIconSource_(source), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_source_set_state_wildcarded(XEN source, XEN setting)
{
  #define H_gtk_icon_source_set_state_wildcarded "void gtk_icon_source_set_state_wildcarded(GtkIconSource* source, \
gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GtkIconSource__P(source), source, 1, "gtk_icon_source_set_state_wildcarded", "GtkIconSource*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gtk_icon_source_set_state_wildcarded", "gboolean");
  gtk_icon_source_set_state_wildcarded(XEN_TO_C_GtkIconSource_(source), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_source_set_size_wildcarded(XEN source, XEN setting)
{
  #define H_gtk_icon_source_set_size_wildcarded "void gtk_icon_source_set_size_wildcarded(GtkIconSource* source, \
gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GtkIconSource__P(source), source, 1, "gtk_icon_source_set_size_wildcarded", "GtkIconSource*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gtk_icon_source_set_size_wildcarded", "gboolean");
  gtk_icon_source_set_size_wildcarded(XEN_TO_C_GtkIconSource_(source), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_source_get_size_wildcarded(XEN source)
{
  #define H_gtk_icon_source_get_size_wildcarded "gboolean gtk_icon_source_get_size_wildcarded(GtkIconSource* source)"
  XEN_ASSERT_TYPE(XEN_GtkIconSource__P(source), source, 1, "gtk_icon_source_get_size_wildcarded", "GtkIconSource*");
  return(C_TO_XEN_gboolean(gtk_icon_source_get_size_wildcarded(XEN_TO_C_GtkIconSource_(source))));
}
static XEN gxg_gtk_icon_source_get_state_wildcarded(XEN source)
{
  #define H_gtk_icon_source_get_state_wildcarded "gboolean gtk_icon_source_get_state_wildcarded(GtkIconSource* source)"
  XEN_ASSERT_TYPE(XEN_GtkIconSource__P(source), source, 1, "gtk_icon_source_get_state_wildcarded", "GtkIconSource*");
  return(C_TO_XEN_gboolean(gtk_icon_source_get_state_wildcarded(XEN_TO_C_GtkIconSource_(source))));
}
static XEN gxg_gtk_icon_source_get_direction_wildcarded(XEN source)
{
  #define H_gtk_icon_source_get_direction_wildcarded "gboolean gtk_icon_source_get_direction_wildcarded(GtkIconSource* source)"
  XEN_ASSERT_TYPE(XEN_GtkIconSource__P(source), source, 1, "gtk_icon_source_get_direction_wildcarded", "GtkIconSource*");
  return(C_TO_XEN_gboolean(gtk_icon_source_get_direction_wildcarded(XEN_TO_C_GtkIconSource_(source))));
}
static XEN gxg_gtk_icon_source_set_direction(XEN source, XEN direction)
{
  #define H_gtk_icon_source_set_direction "void gtk_icon_source_set_direction(GtkIconSource* source, \
GtkTextDirection direction)"
  XEN_ASSERT_TYPE(XEN_GtkIconSource__P(source), source, 1, "gtk_icon_source_set_direction", "GtkIconSource*");
  XEN_ASSERT_TYPE(XEN_GtkTextDirection_P(direction), direction, 2, "gtk_icon_source_set_direction", "GtkTextDirection");
  gtk_icon_source_set_direction(XEN_TO_C_GtkIconSource_(source), XEN_TO_C_GtkTextDirection(direction));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_source_set_state(XEN source, XEN state)
{
  #define H_gtk_icon_source_set_state "void gtk_icon_source_set_state(GtkIconSource* source, GtkStateType state)"
  XEN_ASSERT_TYPE(XEN_GtkIconSource__P(source), source, 1, "gtk_icon_source_set_state", "GtkIconSource*");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state), state, 2, "gtk_icon_source_set_state", "GtkStateType");
  gtk_icon_source_set_state(XEN_TO_C_GtkIconSource_(source), XEN_TO_C_GtkStateType(state));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_source_set_size(XEN source, XEN size)
{
  #define H_gtk_icon_source_set_size "void gtk_icon_source_set_size(GtkIconSource* source, GtkIconSize size)"
  XEN_ASSERT_TYPE(XEN_GtkIconSource__P(source), source, 1, "gtk_icon_source_set_size", "GtkIconSource*");
  XEN_ASSERT_TYPE(XEN_GtkIconSize_P(size), size, 2, "gtk_icon_source_set_size", "GtkIconSize");
  gtk_icon_source_set_size(XEN_TO_C_GtkIconSource_(source), XEN_TO_C_GtkIconSize(size));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_source_get_direction(XEN source)
{
  #define H_gtk_icon_source_get_direction "GtkTextDirection gtk_icon_source_get_direction(GtkIconSource* source)"
  XEN_ASSERT_TYPE(XEN_GtkIconSource__P(source), source, 1, "gtk_icon_source_get_direction", "GtkIconSource*");
  return(C_TO_XEN_GtkTextDirection(gtk_icon_source_get_direction(XEN_TO_C_GtkIconSource_(source))));
}
static XEN gxg_gtk_icon_source_get_state(XEN source)
{
  #define H_gtk_icon_source_get_state "GtkStateType gtk_icon_source_get_state(GtkIconSource* source)"
  XEN_ASSERT_TYPE(XEN_GtkIconSource__P(source), source, 1, "gtk_icon_source_get_state", "GtkIconSource*");
  return(C_TO_XEN_GtkStateType(gtk_icon_source_get_state(XEN_TO_C_GtkIconSource_(source))));
}
static XEN gxg_gtk_icon_source_get_size(XEN source)
{
  #define H_gtk_icon_source_get_size "GtkIconSize gtk_icon_source_get_size(GtkIconSource* source)"
  XEN_ASSERT_TYPE(XEN_GtkIconSource__P(source), source, 1, "gtk_icon_source_get_size", "GtkIconSource*");
  return(C_TO_XEN_GtkIconSize(gtk_icon_source_get_size(XEN_TO_C_GtkIconSource_(source))));
}
static XEN gxg_gtk_image_get_type(void)
{
  #define H_gtk_image_get_type "GtkType gtk_image_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_image_get_type()));
}
static XEN gxg_gtk_image_new(void)
{
  #define H_gtk_image_new "GtkWidget* gtk_image_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_image_new()));
}
static XEN gxg_gtk_image_new_from_pixmap(XEN pixmap, XEN mask)
{
  #define H_gtk_image_new_from_pixmap "GtkWidget* gtk_image_new_from_pixmap(GdkPixmap* pixmap, GdkBitmap* mask)"
  XEN_ASSERT_TYPE(XEN_GdkPixmap__P(pixmap) || XEN_FALSE_P(pixmap), pixmap, 1, "gtk_image_new_from_pixmap", "GdkPixmap*");
  XEN_ASSERT_TYPE(XEN_GdkBitmap__P(mask) || XEN_FALSE_P(mask), mask, 2, "gtk_image_new_from_pixmap", "GdkBitmap*");
  return(C_TO_XEN_GtkWidget_(gtk_image_new_from_pixmap(XEN_TO_C_GdkPixmap_(pixmap), XEN_TO_C_GdkBitmap_(mask))));
}
static XEN gxg_gtk_image_new_from_image(XEN image, XEN mask)
{
  #define H_gtk_image_new_from_image "GtkWidget* gtk_image_new_from_image(GdkImage* image, GdkBitmap* mask)"
  XEN_ASSERT_TYPE(XEN_GdkImage__P(image) || XEN_FALSE_P(image), image, 1, "gtk_image_new_from_image", "GdkImage*");
  XEN_ASSERT_TYPE(XEN_GdkBitmap__P(mask) || XEN_FALSE_P(mask), mask, 2, "gtk_image_new_from_image", "GdkBitmap*");
  return(C_TO_XEN_GtkWidget_(gtk_image_new_from_image(XEN_TO_C_GdkImage_(image), XEN_TO_C_GdkBitmap_(mask))));
}
static XEN gxg_gtk_image_new_from_file(XEN filename)
{
  #define H_gtk_image_new_from_file "GtkWidget* gtk_image_new_from_file(gchar* filename)"
  XEN_ASSERT_TYPE(XEN_gchar__P(filename), filename, 1, "gtk_image_new_from_file", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_image_new_from_file(XEN_TO_C_gchar_(filename))));
}
static XEN gxg_gtk_image_new_from_pixbuf(XEN pixbuf)
{
  #define H_gtk_image_new_from_pixbuf "GtkWidget* gtk_image_new_from_pixbuf(GdkPixbuf* pixbuf)"
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(pixbuf) || XEN_FALSE_P(pixbuf), pixbuf, 1, "gtk_image_new_from_pixbuf", "GdkPixbuf*");
  return(C_TO_XEN_GtkWidget_(gtk_image_new_from_pixbuf(XEN_TO_C_GdkPixbuf_(pixbuf))));
}
static XEN gxg_gtk_image_new_from_stock(XEN stock_id, XEN size)
{
  #define H_gtk_image_new_from_stock "GtkWidget* gtk_image_new_from_stock(gchar* stock_id, GtkIconSize size)"
  XEN_ASSERT_TYPE(XEN_gchar__P(stock_id), stock_id, 1, "gtk_image_new_from_stock", "gchar*");
  XEN_ASSERT_TYPE(XEN_GtkIconSize_P(size), size, 2, "gtk_image_new_from_stock", "GtkIconSize");
  return(C_TO_XEN_GtkWidget_(gtk_image_new_from_stock(XEN_TO_C_gchar_(stock_id), XEN_TO_C_GtkIconSize(size))));
}
static XEN gxg_gtk_image_new_from_icon_set(XEN icon_set, XEN size)
{
  #define H_gtk_image_new_from_icon_set "GtkWidget* gtk_image_new_from_icon_set(GtkIconSet* icon_set, \
GtkIconSize size)"
  XEN_ASSERT_TYPE(XEN_GtkIconSet__P(icon_set), icon_set, 1, "gtk_image_new_from_icon_set", "GtkIconSet*");
  XEN_ASSERT_TYPE(XEN_GtkIconSize_P(size), size, 2, "gtk_image_new_from_icon_set", "GtkIconSize");
  return(C_TO_XEN_GtkWidget_(gtk_image_new_from_icon_set(XEN_TO_C_GtkIconSet_(icon_set), XEN_TO_C_GtkIconSize(size))));
}
static XEN gxg_gtk_image_new_from_animation(XEN animation)
{
  #define H_gtk_image_new_from_animation "GtkWidget* gtk_image_new_from_animation(GdkPixbufAnimation* animation)"
  XEN_ASSERT_TYPE(XEN_GdkPixbufAnimation__P(animation), animation, 1, "gtk_image_new_from_animation", "GdkPixbufAnimation*");
  return(C_TO_XEN_GtkWidget_(gtk_image_new_from_animation(XEN_TO_C_GdkPixbufAnimation_(animation))));
}
static XEN gxg_gtk_image_set_from_pixmap(XEN image, XEN pixmap, XEN mask)
{
  #define H_gtk_image_set_from_pixmap "void gtk_image_set_from_pixmap(GtkImage* image, GdkPixmap* pixmap, \
GdkBitmap* mask)"
  XEN_ASSERT_TYPE(XEN_GtkImage__P(image), image, 1, "gtk_image_set_from_pixmap", "GtkImage*");
  XEN_ASSERT_TYPE(XEN_GdkPixmap__P(pixmap) || XEN_FALSE_P(pixmap), pixmap, 2, "gtk_image_set_from_pixmap", "GdkPixmap*");
  XEN_ASSERT_TYPE(XEN_GdkBitmap__P(mask) || XEN_FALSE_P(mask), mask, 3, "gtk_image_set_from_pixmap", "GdkBitmap*");
  gtk_image_set_from_pixmap(XEN_TO_C_GtkImage_(image), XEN_TO_C_GdkPixmap_(pixmap), XEN_TO_C_GdkBitmap_(mask));
  return(XEN_FALSE);
}
static XEN gxg_gtk_image_set_from_image(XEN image, XEN gdk_image, XEN mask)
{
  #define H_gtk_image_set_from_image "void gtk_image_set_from_image(GtkImage* image, GdkImage* gdk_image, \
GdkBitmap* mask)"
  XEN_ASSERT_TYPE(XEN_GtkImage__P(image), image, 1, "gtk_image_set_from_image", "GtkImage*");
  XEN_ASSERT_TYPE(XEN_GdkImage__P(gdk_image) || XEN_FALSE_P(gdk_image), gdk_image, 2, "gtk_image_set_from_image", "GdkImage*");
  XEN_ASSERT_TYPE(XEN_GdkBitmap__P(mask) || XEN_FALSE_P(mask), mask, 3, "gtk_image_set_from_image", "GdkBitmap*");
  gtk_image_set_from_image(XEN_TO_C_GtkImage_(image), XEN_TO_C_GdkImage_(gdk_image), XEN_TO_C_GdkBitmap_(mask));
  return(XEN_FALSE);
}
static XEN gxg_gtk_image_set_from_file(XEN image, XEN filename)
{
  #define H_gtk_image_set_from_file "void gtk_image_set_from_file(GtkImage* image, gchar* filename)"
  XEN_ASSERT_TYPE(XEN_GtkImage__P(image), image, 1, "gtk_image_set_from_file", "GtkImage*");
  XEN_ASSERT_TYPE(XEN_gchar__P(filename), filename, 2, "gtk_image_set_from_file", "gchar*");
  gtk_image_set_from_file(XEN_TO_C_GtkImage_(image), XEN_TO_C_gchar_(filename));
  return(XEN_FALSE);
}
static XEN gxg_gtk_image_set_from_pixbuf(XEN image, XEN pixbuf)
{
  #define H_gtk_image_set_from_pixbuf "void gtk_image_set_from_pixbuf(GtkImage* image, GdkPixbuf* pixbuf)"
  XEN_ASSERT_TYPE(XEN_GtkImage__P(image), image, 1, "gtk_image_set_from_pixbuf", "GtkImage*");
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(pixbuf) || XEN_FALSE_P(pixbuf), pixbuf, 2, "gtk_image_set_from_pixbuf", "GdkPixbuf*");
  gtk_image_set_from_pixbuf(XEN_TO_C_GtkImage_(image), XEN_TO_C_GdkPixbuf_(pixbuf));
  return(XEN_FALSE);
}
static XEN gxg_gtk_image_set_from_stock(XEN image, XEN stock_id, XEN size)
{
  #define H_gtk_image_set_from_stock "void gtk_image_set_from_stock(GtkImage* image, gchar* stock_id, \
GtkIconSize size)"
  XEN_ASSERT_TYPE(XEN_GtkImage__P(image), image, 1, "gtk_image_set_from_stock", "GtkImage*");
  XEN_ASSERT_TYPE(XEN_gchar__P(stock_id), stock_id, 2, "gtk_image_set_from_stock", "gchar*");
  XEN_ASSERT_TYPE(XEN_GtkIconSize_P(size), size, 3, "gtk_image_set_from_stock", "GtkIconSize");
  gtk_image_set_from_stock(XEN_TO_C_GtkImage_(image), XEN_TO_C_gchar_(stock_id), XEN_TO_C_GtkIconSize(size));
  return(XEN_FALSE);
}
static XEN gxg_gtk_image_set_from_icon_set(XEN image, XEN icon_set, XEN size)
{
  #define H_gtk_image_set_from_icon_set "void gtk_image_set_from_icon_set(GtkImage* image, GtkIconSet* icon_set, \
GtkIconSize size)"
  XEN_ASSERT_TYPE(XEN_GtkImage__P(image), image, 1, "gtk_image_set_from_icon_set", "GtkImage*");
  XEN_ASSERT_TYPE(XEN_GtkIconSet__P(icon_set), icon_set, 2, "gtk_image_set_from_icon_set", "GtkIconSet*");
  XEN_ASSERT_TYPE(XEN_GtkIconSize_P(size), size, 3, "gtk_image_set_from_icon_set", "GtkIconSize");
  gtk_image_set_from_icon_set(XEN_TO_C_GtkImage_(image), XEN_TO_C_GtkIconSet_(icon_set), XEN_TO_C_GtkIconSize(size));
  return(XEN_FALSE);
}
static XEN gxg_gtk_image_set_from_animation(XEN image, XEN animation)
{
  #define H_gtk_image_set_from_animation "void gtk_image_set_from_animation(GtkImage* image, GdkPixbufAnimation* animation)"
  XEN_ASSERT_TYPE(XEN_GtkImage__P(image), image, 1, "gtk_image_set_from_animation", "GtkImage*");
  XEN_ASSERT_TYPE(XEN_GdkPixbufAnimation__P(animation) || XEN_FALSE_P(animation), animation, 2, "gtk_image_set_from_animation", "GdkPixbufAnimation*");
  gtk_image_set_from_animation(XEN_TO_C_GtkImage_(image), XEN_TO_C_GdkPixbufAnimation_(animation));
  return(XEN_FALSE);
}
static XEN gxg_gtk_image_get_storage_type(XEN image)
{
  #define H_gtk_image_get_storage_type "GtkImageType gtk_image_get_storage_type(GtkImage* image)"
  XEN_ASSERT_TYPE(XEN_GtkImage__P(image), image, 1, "gtk_image_get_storage_type", "GtkImage*");
  return(C_TO_XEN_GtkImageType(gtk_image_get_storage_type(XEN_TO_C_GtkImage_(image))));
}
static XEN gxg_gtk_image_get_pixmap(XEN image, XEN pixmap, XEN mask)
{
  #define H_gtk_image_get_pixmap "void gtk_image_get_pixmap(GtkImage* image, GdkPixmap** [pixmap], GdkBitmap** [mask])"
  GdkPixmap* ref_pixmap = NULL;
  GdkBitmap* ref_mask = NULL;
  XEN_ASSERT_TYPE(XEN_GtkImage__P(image), image, 1, "gtk_image_get_pixmap", "GtkImage*");
  gtk_image_get_pixmap(XEN_TO_C_GtkImage_(image), &ref_pixmap, &ref_mask);
  return(XEN_LIST_2(C_TO_XEN_GdkPixmap_(ref_pixmap), C_TO_XEN_GdkBitmap_(ref_mask)));
}
static XEN gxg_gtk_image_get_image(XEN image, XEN gdk_image, XEN mask)
{
  #define H_gtk_image_get_image "void gtk_image_get_image(GtkImage* image, GdkImage** [gdk_image], GdkBitmap** [mask])"
  GdkImage* ref_gdk_image = NULL;
  GdkBitmap* ref_mask = NULL;
  XEN_ASSERT_TYPE(XEN_GtkImage__P(image), image, 1, "gtk_image_get_image", "GtkImage*");
  gtk_image_get_image(XEN_TO_C_GtkImage_(image), &ref_gdk_image, &ref_mask);
  return(XEN_LIST_2(C_TO_XEN_GdkImage_(ref_gdk_image), C_TO_XEN_GdkBitmap_(ref_mask)));
}
static XEN gxg_gtk_image_get_pixbuf(XEN image)
{
  #define H_gtk_image_get_pixbuf "GdkPixbuf* gtk_image_get_pixbuf(GtkImage* image)"
  XEN_ASSERT_TYPE(XEN_GtkImage__P(image), image, 1, "gtk_image_get_pixbuf", "GtkImage*");
  return(C_TO_XEN_GdkPixbuf_(gtk_image_get_pixbuf(XEN_TO_C_GtkImage_(image))));
}
static XEN gxg_gtk_image_get_stock(XEN image, XEN stock_id, XEN size)
{
  #define H_gtk_image_get_stock "void gtk_image_get_stock(GtkImage* image, gchar** [stock_id], GtkIconSize* [size])"
  gchar* ref_stock_id = NULL;
  GtkIconSize ref_size;
  XEN_ASSERT_TYPE(XEN_GtkImage__P(image), image, 1, "gtk_image_get_stock", "GtkImage*");
  gtk_image_get_stock(XEN_TO_C_GtkImage_(image), &ref_stock_id, &ref_size);
  return(XEN_LIST_2(C_TO_XEN_gchar_(ref_stock_id), C_TO_XEN_GtkIconSize(ref_size)));
}
static XEN gxg_gtk_image_get_icon_set(XEN image, XEN icon_set, XEN size)
{
  #define H_gtk_image_get_icon_set "void gtk_image_get_icon_set(GtkImage* image, GtkIconSet** [icon_set], \
GtkIconSize* [size])"
  GtkIconSet* ref_icon_set = NULL;
  GtkIconSize ref_size;
  XEN_ASSERT_TYPE(XEN_GtkImage__P(image), image, 1, "gtk_image_get_icon_set", "GtkImage*");
  gtk_image_get_icon_set(XEN_TO_C_GtkImage_(image), &ref_icon_set, &ref_size);
  return(XEN_LIST_2(C_TO_XEN_GtkIconSet_(ref_icon_set), C_TO_XEN_GtkIconSize(ref_size)));
}
static XEN gxg_gtk_image_get_animation(XEN image)
{
  #define H_gtk_image_get_animation "GdkPixbufAnimation* gtk_image_get_animation(GtkImage* image)"
  XEN_ASSERT_TYPE(XEN_GtkImage__P(image), image, 1, "gtk_image_get_animation", "GtkImage*");
  return(C_TO_XEN_GdkPixbufAnimation_(gtk_image_get_animation(XEN_TO_C_GtkImage_(image))));
}
static XEN gxg_gtk_image_menu_item_get_type(void)
{
  #define H_gtk_image_menu_item_get_type "GtkType gtk_image_menu_item_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_image_menu_item_get_type()));
}
static XEN gxg_gtk_image_menu_item_new(void)
{
  #define H_gtk_image_menu_item_new "GtkWidget* gtk_image_menu_item_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_image_menu_item_new()));
}
static XEN gxg_gtk_image_menu_item_new_with_label(XEN label)
{
  #define H_gtk_image_menu_item_new_with_label "GtkWidget* gtk_image_menu_item_new_with_label(gchar* label)"
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 1, "gtk_image_menu_item_new_with_label", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_image_menu_item_new_with_label(XEN_TO_C_gchar_(label))));
}
static XEN gxg_gtk_image_menu_item_new_with_mnemonic(XEN label)
{
  #define H_gtk_image_menu_item_new_with_mnemonic "GtkWidget* gtk_image_menu_item_new_with_mnemonic(gchar* label)"
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 1, "gtk_image_menu_item_new_with_mnemonic", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_image_menu_item_new_with_mnemonic(XEN_TO_C_gchar_(label))));
}
static XEN gxg_gtk_image_menu_item_new_from_stock(XEN stock_id, XEN accel_group)
{
  #define H_gtk_image_menu_item_new_from_stock "GtkWidget* gtk_image_menu_item_new_from_stock(gchar* stock_id, \
GtkAccelGroup* accel_group)"
  XEN_ASSERT_TYPE(XEN_gchar__P(stock_id), stock_id, 1, "gtk_image_menu_item_new_from_stock", "gchar*");
  XEN_ASSERT_TYPE(XEN_GtkAccelGroup__P(accel_group), accel_group, 2, "gtk_image_menu_item_new_from_stock", "GtkAccelGroup*");
  return(C_TO_XEN_GtkWidget_(gtk_image_menu_item_new_from_stock(XEN_TO_C_gchar_(stock_id), XEN_TO_C_GtkAccelGroup_(accel_group))));
}
static XEN gxg_gtk_image_menu_item_set_image(XEN image_menu_item, XEN image)
{
  #define H_gtk_image_menu_item_set_image "void gtk_image_menu_item_set_image(GtkImageMenuItem* image_menu_item, \
GtkWidget* image)"
  XEN_ASSERT_TYPE(XEN_GtkImageMenuItem__P(image_menu_item), image_menu_item, 1, "gtk_image_menu_item_set_image", "GtkImageMenuItem*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(image), image, 2, "gtk_image_menu_item_set_image", "GtkWidget*");
  gtk_image_menu_item_set_image(XEN_TO_C_GtkImageMenuItem_(image_menu_item), XEN_TO_C_GtkWidget_(image));
  return(XEN_FALSE);
}
static XEN gxg_gtk_image_menu_item_get_image(XEN image_menu_item)
{
  #define H_gtk_image_menu_item_get_image "GtkWidget* gtk_image_menu_item_get_image(GtkImageMenuItem* image_menu_item)"
  XEN_ASSERT_TYPE(XEN_GtkImageMenuItem__P(image_menu_item), image_menu_item, 1, "gtk_image_menu_item_get_image", "GtkImageMenuItem*");
  return(C_TO_XEN_GtkWidget_(gtk_image_menu_item_get_image(XEN_TO_C_GtkImageMenuItem_(image_menu_item))));
}
static XEN gxg_gtk_im_context_get_type(void)
{
  #define H_gtk_im_context_get_type "GtkType gtk_im_context_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_im_context_get_type()));
}
static XEN gxg_gtk_im_context_set_client_window(XEN context, XEN window)
{
  #define H_gtk_im_context_set_client_window "void gtk_im_context_set_client_window(GtkIMContext* context, \
GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkIMContext__P(context), context, 1, "gtk_im_context_set_client_window", "GtkIMContext*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window) || XEN_FALSE_P(window), window, 2, "gtk_im_context_set_client_window", "GdkWindow*");
  gtk_im_context_set_client_window(XEN_TO_C_GtkIMContext_(context), XEN_TO_C_GdkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gtk_im_context_get_preedit_string(XEN context, XEN str, XEN attrs, XEN cursor_pos)
{
  #define H_gtk_im_context_get_preedit_string "void gtk_im_context_get_preedit_string(GtkIMContext* context, \
gchar** [str], PangoAttrList** [attrs], gint* [cursor_pos])"
  gchar* ref_str = NULL;
  PangoAttrList* ref_attrs = NULL;
  gint ref_cursor_pos;
  XEN_ASSERT_TYPE(XEN_GtkIMContext__P(context), context, 1, "gtk_im_context_get_preedit_string", "GtkIMContext*");
  gtk_im_context_get_preedit_string(XEN_TO_C_GtkIMContext_(context), &ref_str, &ref_attrs, &ref_cursor_pos);
  return(XEN_LIST_3(C_TO_XEN_gchar_(ref_str), C_TO_XEN_PangoAttrList_(ref_attrs), C_TO_XEN_gint(ref_cursor_pos)));
}
static XEN gxg_gtk_im_context_filter_keypress(XEN context, XEN event)
{
  #define H_gtk_im_context_filter_keypress "gboolean gtk_im_context_filter_keypress(GtkIMContext* context, \
GdkEventKey* event)"
  XEN_ASSERT_TYPE(XEN_GtkIMContext__P(context), context, 1, "gtk_im_context_filter_keypress", "GtkIMContext*");
  XEN_ASSERT_TYPE(XEN_GdkEventKey__P(event), event, 2, "gtk_im_context_filter_keypress", "GdkEventKey*");
  return(C_TO_XEN_gboolean(gtk_im_context_filter_keypress(XEN_TO_C_GtkIMContext_(context), XEN_TO_C_GdkEventKey_(event))));
}
static XEN gxg_gtk_im_context_focus_in(XEN context)
{
  #define H_gtk_im_context_focus_in "void gtk_im_context_focus_in(GtkIMContext* context)"
  XEN_ASSERT_TYPE(XEN_GtkIMContext__P(context), context, 1, "gtk_im_context_focus_in", "GtkIMContext*");
  gtk_im_context_focus_in(XEN_TO_C_GtkIMContext_(context));
  return(XEN_FALSE);
}
static XEN gxg_gtk_im_context_focus_out(XEN context)
{
  #define H_gtk_im_context_focus_out "void gtk_im_context_focus_out(GtkIMContext* context)"
  XEN_ASSERT_TYPE(XEN_GtkIMContext__P(context), context, 1, "gtk_im_context_focus_out", "GtkIMContext*");
  gtk_im_context_focus_out(XEN_TO_C_GtkIMContext_(context));
  return(XEN_FALSE);
}
static XEN gxg_gtk_im_context_reset(XEN context)
{
  #define H_gtk_im_context_reset "void gtk_im_context_reset(GtkIMContext* context)"
  XEN_ASSERT_TYPE(XEN_GtkIMContext__P(context), context, 1, "gtk_im_context_reset", "GtkIMContext*");
  gtk_im_context_reset(XEN_TO_C_GtkIMContext_(context));
  return(XEN_FALSE);
}
static XEN gxg_gtk_im_context_set_cursor_location(XEN context, XEN area)
{
  #define H_gtk_im_context_set_cursor_location "void gtk_im_context_set_cursor_location(GtkIMContext* context, \
GdkRectangle* area)"
  XEN_ASSERT_TYPE(XEN_GtkIMContext__P(context), context, 1, "gtk_im_context_set_cursor_location", "GtkIMContext*");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(area), area, 2, "gtk_im_context_set_cursor_location", "GdkRectangle*");
  gtk_im_context_set_cursor_location(XEN_TO_C_GtkIMContext_(context), XEN_TO_C_GdkRectangle_(area));
  return(XEN_FALSE);
}
static XEN gxg_gtk_im_context_set_use_preedit(XEN context, XEN use_preedit)
{
  #define H_gtk_im_context_set_use_preedit "void gtk_im_context_set_use_preedit(GtkIMContext* context, \
gboolean use_preedit)"
  XEN_ASSERT_TYPE(XEN_GtkIMContext__P(context), context, 1, "gtk_im_context_set_use_preedit", "GtkIMContext*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(use_preedit), use_preedit, 2, "gtk_im_context_set_use_preedit", "gboolean");
  gtk_im_context_set_use_preedit(XEN_TO_C_GtkIMContext_(context), XEN_TO_C_gboolean(use_preedit));
  return(XEN_FALSE);
}
static XEN gxg_gtk_im_context_set_surrounding(XEN context, XEN text, XEN len, XEN cursor_index)
{
  #define H_gtk_im_context_set_surrounding "void gtk_im_context_set_surrounding(GtkIMContext* context, \
gchar* text, gint len, gint cursor_index)"
  XEN_ASSERT_TYPE(XEN_GtkIMContext__P(context), context, 1, "gtk_im_context_set_surrounding", "GtkIMContext*");
  XEN_ASSERT_TYPE(XEN_gchar__P(text), text, 2, "gtk_im_context_set_surrounding", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(len), len, 3, "gtk_im_context_set_surrounding", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(cursor_index), cursor_index, 4, "gtk_im_context_set_surrounding", "gint");
  gtk_im_context_set_surrounding(XEN_TO_C_GtkIMContext_(context), XEN_TO_C_gchar_(text), XEN_TO_C_gint(len), XEN_TO_C_gint(cursor_index));
  return(XEN_FALSE);
}
static XEN gxg_gtk_im_context_get_surrounding(XEN context, XEN text, XEN cursor_index)
{
  #define H_gtk_im_context_get_surrounding "gboolean gtk_im_context_get_surrounding(GtkIMContext* context, \
gchar** [text], gint* [cursor_index])"
  gchar* ref_text = NULL;
  gint ref_cursor_index;
  XEN_ASSERT_TYPE(XEN_GtkIMContext__P(context), context, 1, "gtk_im_context_get_surrounding", "GtkIMContext*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gtk_im_context_get_surrounding(XEN_TO_C_GtkIMContext_(context), &ref_text, &ref_cursor_index));
    return(XEN_LIST_3(result, C_TO_XEN_gchar_(ref_text), C_TO_XEN_gint(ref_cursor_index)));
   }
}
static XEN gxg_gtk_im_context_delete_surrounding(XEN context, XEN offset, XEN n_chars)
{
  #define H_gtk_im_context_delete_surrounding "gboolean gtk_im_context_delete_surrounding(GtkIMContext* context, \
gint offset, gint n_chars)"
  XEN_ASSERT_TYPE(XEN_GtkIMContext__P(context), context, 1, "gtk_im_context_delete_surrounding", "GtkIMContext*");
  XEN_ASSERT_TYPE(XEN_gint_P(offset), offset, 2, "gtk_im_context_delete_surrounding", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(n_chars), n_chars, 3, "gtk_im_context_delete_surrounding", "gint");
  return(C_TO_XEN_gboolean(gtk_im_context_delete_surrounding(XEN_TO_C_GtkIMContext_(context), XEN_TO_C_gint(offset), XEN_TO_C_gint(n_chars))));
}
static XEN gxg_gtk_im_context_simple_get_type(void)
{
  #define H_gtk_im_context_simple_get_type "GtkType gtk_im_context_simple_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_im_context_simple_get_type()));
}
static XEN gxg_gtk_im_context_simple_new(void)
{
  #define H_gtk_im_context_simple_new "GtkIMContext* gtk_im_context_simple_new( void)"
  return(C_TO_XEN_GtkIMContext_(gtk_im_context_simple_new()));
}
static XEN gxg_gtk_im_context_simple_add_table(XEN context_simple, XEN data, XEN max_seq_len, XEN n_seqs)
{
  #define H_gtk_im_context_simple_add_table "void gtk_im_context_simple_add_table(GtkIMContextSimple* context_simple, \
guint16* data, gint max_seq_len, gint n_seqs)"
  XEN_ASSERT_TYPE(XEN_GtkIMContextSimple__P(context_simple), context_simple, 1, "gtk_im_context_simple_add_table", "GtkIMContextSimple*");
  XEN_ASSERT_TYPE(XEN_guint16__P(data), data, 2, "gtk_im_context_simple_add_table", "guint16*");
  XEN_ASSERT_TYPE(XEN_gint_P(max_seq_len), max_seq_len, 3, "gtk_im_context_simple_add_table", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(n_seqs), n_seqs, 4, "gtk_im_context_simple_add_table", "gint");
  gtk_im_context_simple_add_table(XEN_TO_C_GtkIMContextSimple_(context_simple), XEN_TO_C_guint16_(data), XEN_TO_C_gint(max_seq_len), 
                                  XEN_TO_C_gint(n_seqs));
  return(XEN_FALSE);
}
static XEN gxg_gtk_im_multicontext_get_type(void)
{
  #define H_gtk_im_multicontext_get_type "GtkType gtk_im_multicontext_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_im_multicontext_get_type()));
}
static XEN gxg_gtk_im_multicontext_new(void)
{
  #define H_gtk_im_multicontext_new "GtkIMContext* gtk_im_multicontext_new( void)"
  return(C_TO_XEN_GtkIMContext_(gtk_im_multicontext_new()));
}
static XEN gxg_gtk_im_multicontext_append_menuitems(XEN context, XEN menushell)
{
  #define H_gtk_im_multicontext_append_menuitems "void gtk_im_multicontext_append_menuitems(GtkIMMulticontext* context, \
GtkMenuShell* menushell)"
  XEN_ASSERT_TYPE(XEN_GtkIMMulticontext__P(context), context, 1, "gtk_im_multicontext_append_menuitems", "GtkIMMulticontext*");
  XEN_ASSERT_TYPE(XEN_GtkMenuShell__P(menushell), menushell, 2, "gtk_im_multicontext_append_menuitems", "GtkMenuShell*");
  gtk_im_multicontext_append_menuitems(XEN_TO_C_GtkIMMulticontext_(context), XEN_TO_C_GtkMenuShell_(menushell));
  return(XEN_FALSE);
}
static XEN gxg_gtk_input_dialog_get_type(void)
{
  #define H_gtk_input_dialog_get_type "GtkType gtk_input_dialog_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_input_dialog_get_type()));
}
static XEN gxg_gtk_input_dialog_new(void)
{
  #define H_gtk_input_dialog_new "GtkWidget* gtk_input_dialog_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_input_dialog_new()));
}
static XEN gxg_gtk_invisible_get_type(void)
{
  #define H_gtk_invisible_get_type "GtkType gtk_invisible_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_invisible_get_type()));
}
static XEN gxg_gtk_invisible_new(void)
{
  #define H_gtk_invisible_new "GtkWidget* gtk_invisible_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_invisible_new()));
}
static XEN gxg_gtk_item_get_type(void)
{
  #define H_gtk_item_get_type "GtkType gtk_item_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_item_get_type()));
}
static XEN gxg_gtk_item_select(XEN item)
{
  #define H_gtk_item_select "void gtk_item_select(GtkItem* item)"
  XEN_ASSERT_TYPE(XEN_GtkItem__P(item), item, 1, "gtk_item_select", "GtkItem*");
  gtk_item_select(XEN_TO_C_GtkItem_(item));
  return(XEN_FALSE);
}
static XEN gxg_gtk_item_deselect(XEN item)
{
  #define H_gtk_item_deselect "void gtk_item_deselect(GtkItem* item)"
  XEN_ASSERT_TYPE(XEN_GtkItem__P(item), item, 1, "gtk_item_deselect", "GtkItem*");
  gtk_item_deselect(XEN_TO_C_GtkItem_(item));
  return(XEN_FALSE);
}
static XEN gxg_gtk_item_toggle(XEN item)
{
  #define H_gtk_item_toggle "void gtk_item_toggle(GtkItem* item)"
  XEN_ASSERT_TYPE(XEN_GtkItem__P(item), item, 1, "gtk_item_toggle", "GtkItem*");
  gtk_item_toggle(XEN_TO_C_GtkItem_(item));
  return(XEN_FALSE);
}
static XEN gxg_gtk_label_get_type(void)
{
  #define H_gtk_label_get_type "GtkType gtk_label_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_label_get_type()));
}
static XEN gxg_gtk_label_new(XEN str)
{
  #define H_gtk_label_new "GtkWidget* gtk_label_new(char* str)"
  XEN_ASSERT_TYPE(XEN_char__P(str), str, 1, "gtk_label_new", "char*");
  return(C_TO_XEN_GtkWidget_(gtk_label_new(XEN_TO_C_char_(str))));
}
static XEN gxg_gtk_label_new_with_mnemonic(XEN str)
{
  #define H_gtk_label_new_with_mnemonic "GtkWidget* gtk_label_new_with_mnemonic(char* str)"
  XEN_ASSERT_TYPE(XEN_char__P(str), str, 1, "gtk_label_new_with_mnemonic", "char*");
  return(C_TO_XEN_GtkWidget_(gtk_label_new_with_mnemonic(XEN_TO_C_char_(str))));
}
static XEN gxg_gtk_label_set_text(XEN label, XEN str)
{
  #define H_gtk_label_set_text "void gtk_label_set_text(GtkLabel* label, char* str)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_set_text", "GtkLabel*");
  XEN_ASSERT_TYPE(XEN_char__P(str), str, 2, "gtk_label_set_text", "char*");
  gtk_label_set_text(XEN_TO_C_GtkLabel_(label), XEN_TO_C_char_(str));
  return(XEN_FALSE);
}
static XEN gxg_gtk_label_get_text(XEN label)
{
  #define H_gtk_label_get_text "gchar* gtk_label_get_text(GtkLabel* label)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_get_text", "GtkLabel*");
  return(C_TO_XEN_gchar_(gtk_label_get_text(XEN_TO_C_GtkLabel_(label))));
}
static XEN gxg_gtk_label_set_attributes(XEN label, XEN attrs)
{
  #define H_gtk_label_set_attributes "void gtk_label_set_attributes(GtkLabel* label, PangoAttrList* attrs)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_set_attributes", "GtkLabel*");
  XEN_ASSERT_TYPE(XEN_PangoAttrList__P(attrs), attrs, 2, "gtk_label_set_attributes", "PangoAttrList*");
  gtk_label_set_attributes(XEN_TO_C_GtkLabel_(label), XEN_TO_C_PangoAttrList_(attrs));
  return(XEN_FALSE);
}
static XEN gxg_gtk_label_get_attributes(XEN label)
{
  #define H_gtk_label_get_attributes "PangoAttrList* gtk_label_get_attributes(GtkLabel* label)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_get_attributes", "GtkLabel*");
  return(C_TO_XEN_PangoAttrList_(gtk_label_get_attributes(XEN_TO_C_GtkLabel_(label))));
}
static XEN gxg_gtk_label_set_label(XEN label, XEN str)
{
  #define H_gtk_label_set_label "void gtk_label_set_label(GtkLabel* label, gchar* str)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_set_label", "GtkLabel*");
  XEN_ASSERT_TYPE(XEN_gchar__P(str), str, 2, "gtk_label_set_label", "gchar*");
  gtk_label_set_label(XEN_TO_C_GtkLabel_(label), XEN_TO_C_gchar_(str));
  return(XEN_FALSE);
}
static XEN gxg_gtk_label_get_label(XEN label)
{
  #define H_gtk_label_get_label "gchar* gtk_label_get_label(GtkLabel* label)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_get_label", "GtkLabel*");
  return(C_TO_XEN_gchar_(gtk_label_get_label(XEN_TO_C_GtkLabel_(label))));
}
static XEN gxg_gtk_label_set_markup(XEN label, XEN str)
{
  #define H_gtk_label_set_markup "void gtk_label_set_markup(GtkLabel* label, gchar* str)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_set_markup", "GtkLabel*");
  XEN_ASSERT_TYPE(XEN_gchar__P(str), str, 2, "gtk_label_set_markup", "gchar*");
  gtk_label_set_markup(XEN_TO_C_GtkLabel_(label), XEN_TO_C_gchar_(str));
  return(XEN_FALSE);
}
static XEN gxg_gtk_label_set_use_markup(XEN label, XEN setting)
{
  #define H_gtk_label_set_use_markup "void gtk_label_set_use_markup(GtkLabel* label, gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_set_use_markup", "GtkLabel*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gtk_label_set_use_markup", "gboolean");
  gtk_label_set_use_markup(XEN_TO_C_GtkLabel_(label), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_label_get_use_markup(XEN label)
{
  #define H_gtk_label_get_use_markup "gboolean gtk_label_get_use_markup(GtkLabel* label)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_get_use_markup", "GtkLabel*");
  return(C_TO_XEN_gboolean(gtk_label_get_use_markup(XEN_TO_C_GtkLabel_(label))));
}
static XEN gxg_gtk_label_set_use_underline(XEN label, XEN setting)
{
  #define H_gtk_label_set_use_underline "void gtk_label_set_use_underline(GtkLabel* label, gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_set_use_underline", "GtkLabel*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gtk_label_set_use_underline", "gboolean");
  gtk_label_set_use_underline(XEN_TO_C_GtkLabel_(label), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_label_get_use_underline(XEN label)
{
  #define H_gtk_label_get_use_underline "gboolean gtk_label_get_use_underline(GtkLabel* label)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_get_use_underline", "GtkLabel*");
  return(C_TO_XEN_gboolean(gtk_label_get_use_underline(XEN_TO_C_GtkLabel_(label))));
}
static XEN gxg_gtk_label_set_markup_with_mnemonic(XEN label, XEN str)
{
  #define H_gtk_label_set_markup_with_mnemonic "void gtk_label_set_markup_with_mnemonic(GtkLabel* label, \
gchar* str)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_set_markup_with_mnemonic", "GtkLabel*");
  XEN_ASSERT_TYPE(XEN_gchar__P(str), str, 2, "gtk_label_set_markup_with_mnemonic", "gchar*");
  gtk_label_set_markup_with_mnemonic(XEN_TO_C_GtkLabel_(label), XEN_TO_C_gchar_(str));
  return(XEN_FALSE);
}
static XEN gxg_gtk_label_get_mnemonic_keyval(XEN label)
{
  #define H_gtk_label_get_mnemonic_keyval "guint gtk_label_get_mnemonic_keyval(GtkLabel* label)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_get_mnemonic_keyval", "GtkLabel*");
  return(C_TO_XEN_guint(gtk_label_get_mnemonic_keyval(XEN_TO_C_GtkLabel_(label))));
}
static XEN gxg_gtk_label_set_mnemonic_widget(XEN label, XEN widget)
{
  #define H_gtk_label_set_mnemonic_widget "void gtk_label_set_mnemonic_widget(GtkLabel* label, GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_set_mnemonic_widget", "GtkLabel*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 2, "gtk_label_set_mnemonic_widget", "GtkWidget*");
  gtk_label_set_mnemonic_widget(XEN_TO_C_GtkLabel_(label), XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_label_get_mnemonic_widget(XEN label)
{
  #define H_gtk_label_get_mnemonic_widget "GtkWidget* gtk_label_get_mnemonic_widget(GtkLabel* label)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_get_mnemonic_widget", "GtkLabel*");
  return(C_TO_XEN_GtkWidget_(gtk_label_get_mnemonic_widget(XEN_TO_C_GtkLabel_(label))));
}
static XEN gxg_gtk_label_set_text_with_mnemonic(XEN label, XEN str)
{
  #define H_gtk_label_set_text_with_mnemonic "void gtk_label_set_text_with_mnemonic(GtkLabel* label, \
gchar* str)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_set_text_with_mnemonic", "GtkLabel*");
  XEN_ASSERT_TYPE(XEN_gchar__P(str), str, 2, "gtk_label_set_text_with_mnemonic", "gchar*");
  gtk_label_set_text_with_mnemonic(XEN_TO_C_GtkLabel_(label), XEN_TO_C_gchar_(str));
  return(XEN_FALSE);
}
static XEN gxg_gtk_label_set_justify(XEN label, XEN jtype)
{
  #define H_gtk_label_set_justify "void gtk_label_set_justify(GtkLabel* label, GtkJustification jtype)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_set_justify", "GtkLabel*");
  XEN_ASSERT_TYPE(XEN_GtkJustification_P(jtype), jtype, 2, "gtk_label_set_justify", "GtkJustification");
  gtk_label_set_justify(XEN_TO_C_GtkLabel_(label), XEN_TO_C_GtkJustification(jtype));
  return(XEN_FALSE);
}
static XEN gxg_gtk_label_get_justify(XEN label)
{
  #define H_gtk_label_get_justify "GtkJustification gtk_label_get_justify(GtkLabel* label)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_get_justify", "GtkLabel*");
  return(C_TO_XEN_GtkJustification(gtk_label_get_justify(XEN_TO_C_GtkLabel_(label))));
}
static XEN gxg_gtk_label_set_pattern(XEN label, XEN pattern)
{
  #define H_gtk_label_set_pattern "void gtk_label_set_pattern(GtkLabel* label, gchar* pattern)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_set_pattern", "GtkLabel*");
  XEN_ASSERT_TYPE(XEN_gchar__P(pattern), pattern, 2, "gtk_label_set_pattern", "gchar*");
  gtk_label_set_pattern(XEN_TO_C_GtkLabel_(label), XEN_TO_C_gchar_(pattern));
  return(XEN_FALSE);
}
static XEN gxg_gtk_label_set_line_wrap(XEN label, XEN wrap)
{
  #define H_gtk_label_set_line_wrap "void gtk_label_set_line_wrap(GtkLabel* label, gboolean wrap)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_set_line_wrap", "GtkLabel*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(wrap), wrap, 2, "gtk_label_set_line_wrap", "gboolean");
  gtk_label_set_line_wrap(XEN_TO_C_GtkLabel_(label), XEN_TO_C_gboolean(wrap));
  return(XEN_FALSE);
}
static XEN gxg_gtk_label_get_line_wrap(XEN label)
{
  #define H_gtk_label_get_line_wrap "gboolean gtk_label_get_line_wrap(GtkLabel* label)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_get_line_wrap", "GtkLabel*");
  return(C_TO_XEN_gboolean(gtk_label_get_line_wrap(XEN_TO_C_GtkLabel_(label))));
}
static XEN gxg_gtk_label_set_selectable(XEN label, XEN setting)
{
  #define H_gtk_label_set_selectable "void gtk_label_set_selectable(GtkLabel* label, gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_set_selectable", "GtkLabel*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gtk_label_set_selectable", "gboolean");
  gtk_label_set_selectable(XEN_TO_C_GtkLabel_(label), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_label_get_selectable(XEN label)
{
  #define H_gtk_label_get_selectable "gboolean gtk_label_get_selectable(GtkLabel* label)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_get_selectable", "GtkLabel*");
  return(C_TO_XEN_gboolean(gtk_label_get_selectable(XEN_TO_C_GtkLabel_(label))));
}
static XEN gxg_gtk_label_select_region(XEN label, XEN start_offset, XEN end_offset)
{
  #define H_gtk_label_select_region "void gtk_label_select_region(GtkLabel* label, gint start_offset, \
gint end_offset)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_select_region", "GtkLabel*");
  XEN_ASSERT_TYPE(XEN_gint_P(start_offset), start_offset, 2, "gtk_label_select_region", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(end_offset), end_offset, 3, "gtk_label_select_region", "gint");
  gtk_label_select_region(XEN_TO_C_GtkLabel_(label), XEN_TO_C_gint(start_offset), XEN_TO_C_gint(end_offset));
  return(XEN_FALSE);
}
static XEN gxg_gtk_label_get_selection_bounds(XEN label, XEN start, XEN end)
{
  #define H_gtk_label_get_selection_bounds "gboolean gtk_label_get_selection_bounds(GtkLabel* label, \
gint* [start], gint* [end])"
  gint ref_start;
  gint ref_end;
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_get_selection_bounds", "GtkLabel*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gtk_label_get_selection_bounds(XEN_TO_C_GtkLabel_(label), &ref_start, &ref_end));
    return(XEN_LIST_3(result, C_TO_XEN_gint(ref_start), C_TO_XEN_gint(ref_end)));
   }
}
static XEN gxg_gtk_label_get_layout(XEN label)
{
  #define H_gtk_label_get_layout "PangoLayout* gtk_label_get_layout(GtkLabel* label)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_get_layout", "GtkLabel*");
  return(C_TO_XEN_PangoLayout_(gtk_label_get_layout(XEN_TO_C_GtkLabel_(label))));
}
static XEN gxg_gtk_label_get_layout_offsets(XEN label, XEN x, XEN y)
{
  #define H_gtk_label_get_layout_offsets "void gtk_label_get_layout_offsets(GtkLabel* label, gint* [x], \
gint* [y])"
  gint ref_x;
  gint ref_y;
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_get_layout_offsets", "GtkLabel*");
  gtk_label_get_layout_offsets(XEN_TO_C_GtkLabel_(label), &ref_x, &ref_y);
  return(XEN_LIST_2(C_TO_XEN_gint(ref_x), C_TO_XEN_gint(ref_y)));
}
static XEN gxg_gtk_layout_get_type(void)
{
  #define H_gtk_layout_get_type "GtkType gtk_layout_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_layout_get_type()));
}
static XEN gxg_gtk_layout_new(XEN hadjustment, XEN vadjustment)
{
  #define H_gtk_layout_new "GtkWidget* gtk_layout_new(GtkAdjustment* hadjustment, GtkAdjustment* vadjustment)"
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(hadjustment), hadjustment, 1, "gtk_layout_new", "GtkAdjustment*");
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(vadjustment), vadjustment, 2, "gtk_layout_new", "GtkAdjustment*");
  return(C_TO_XEN_GtkWidget_(gtk_layout_new(XEN_TO_C_GtkAdjustment_(hadjustment), XEN_TO_C_GtkAdjustment_(vadjustment))));
}
static XEN gxg_gtk_layout_put(XEN layout, XEN child_widget, XEN x, XEN y)
{
  #define H_gtk_layout_put "void gtk_layout_put(GtkLayout* layout, GtkWidget* child_widget, gint x, gint y)"
  XEN_ASSERT_TYPE(XEN_GtkLayout__P(layout), layout, 1, "gtk_layout_put", "GtkLayout*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child_widget), child_widget, 2, "gtk_layout_put", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 3, "gtk_layout_put", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 4, "gtk_layout_put", "gint");
  gtk_layout_put(XEN_TO_C_GtkLayout_(layout), XEN_TO_C_GtkWidget_(child_widget), XEN_TO_C_gint(x), XEN_TO_C_gint(y));
  return(XEN_FALSE);
}
static XEN gxg_gtk_layout_move(XEN layout, XEN child_widget, XEN x, XEN y)
{
  #define H_gtk_layout_move "void gtk_layout_move(GtkLayout* layout, GtkWidget* child_widget, gint x, \
gint y)"
  XEN_ASSERT_TYPE(XEN_GtkLayout__P(layout), layout, 1, "gtk_layout_move", "GtkLayout*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child_widget), child_widget, 2, "gtk_layout_move", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 3, "gtk_layout_move", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 4, "gtk_layout_move", "gint");
  gtk_layout_move(XEN_TO_C_GtkLayout_(layout), XEN_TO_C_GtkWidget_(child_widget), XEN_TO_C_gint(x), XEN_TO_C_gint(y));
  return(XEN_FALSE);
}
static XEN gxg_gtk_layout_set_size(XEN layout, XEN width, XEN height)
{
  #define H_gtk_layout_set_size "void gtk_layout_set_size(GtkLayout* layout, guint width, guint height)"
  XEN_ASSERT_TYPE(XEN_GtkLayout__P(layout), layout, 1, "gtk_layout_set_size", "GtkLayout*");
  XEN_ASSERT_TYPE(XEN_guint_P(width), width, 2, "gtk_layout_set_size", "guint");
  XEN_ASSERT_TYPE(XEN_guint_P(height), height, 3, "gtk_layout_set_size", "guint");
  gtk_layout_set_size(XEN_TO_C_GtkLayout_(layout), XEN_TO_C_guint(width), XEN_TO_C_guint(height));
  return(XEN_FALSE);
}
static XEN gxg_gtk_layout_get_size(XEN layout, XEN width, XEN height)
{
  #define H_gtk_layout_get_size "void gtk_layout_get_size(GtkLayout* layout, guint* [width], guint* [height])"
  guint ref_width;
  guint ref_height;
  XEN_ASSERT_TYPE(XEN_GtkLayout__P(layout), layout, 1, "gtk_layout_get_size", "GtkLayout*");
  gtk_layout_get_size(XEN_TO_C_GtkLayout_(layout), &ref_width, &ref_height);
  return(XEN_LIST_2(C_TO_XEN_guint(ref_width), C_TO_XEN_guint(ref_height)));
}
static XEN gxg_gtk_layout_get_hadjustment(XEN layout)
{
  #define H_gtk_layout_get_hadjustment "GtkAdjustment* gtk_layout_get_hadjustment(GtkLayout* layout)"
  XEN_ASSERT_TYPE(XEN_GtkLayout__P(layout), layout, 1, "gtk_layout_get_hadjustment", "GtkLayout*");
  return(C_TO_XEN_GtkAdjustment_(gtk_layout_get_hadjustment(XEN_TO_C_GtkLayout_(layout))));
}
static XEN gxg_gtk_layout_get_vadjustment(XEN layout)
{
  #define H_gtk_layout_get_vadjustment "GtkAdjustment* gtk_layout_get_vadjustment(GtkLayout* layout)"
  XEN_ASSERT_TYPE(XEN_GtkLayout__P(layout), layout, 1, "gtk_layout_get_vadjustment", "GtkLayout*");
  return(C_TO_XEN_GtkAdjustment_(gtk_layout_get_vadjustment(XEN_TO_C_GtkLayout_(layout))));
}
static XEN gxg_gtk_layout_set_hadjustment(XEN layout, XEN adjustment)
{
  #define H_gtk_layout_set_hadjustment "void gtk_layout_set_hadjustment(GtkLayout* layout, GtkAdjustment* adjustment)"
  XEN_ASSERT_TYPE(XEN_GtkLayout__P(layout), layout, 1, "gtk_layout_set_hadjustment", "GtkLayout*");
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(adjustment), adjustment, 2, "gtk_layout_set_hadjustment", "GtkAdjustment*");
  gtk_layout_set_hadjustment(XEN_TO_C_GtkLayout_(layout), XEN_TO_C_GtkAdjustment_(adjustment));
  return(XEN_FALSE);
}
static XEN gxg_gtk_layout_set_vadjustment(XEN layout, XEN adjustment)
{
  #define H_gtk_layout_set_vadjustment "void gtk_layout_set_vadjustment(GtkLayout* layout, GtkAdjustment* adjustment)"
  XEN_ASSERT_TYPE(XEN_GtkLayout__P(layout), layout, 1, "gtk_layout_set_vadjustment", "GtkLayout*");
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(adjustment), adjustment, 2, "gtk_layout_set_vadjustment", "GtkAdjustment*");
  gtk_layout_set_vadjustment(XEN_TO_C_GtkLayout_(layout), XEN_TO_C_GtkAdjustment_(adjustment));
  return(XEN_FALSE);
}
static XEN gxg_gtk_list_store_get_type(void)
{
  #define H_gtk_list_store_get_type "GtkType gtk_list_store_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_list_store_get_type()));
}
static XEN gxg_gtk_list_store_new(XEN n_columns, XEN types)
{
  #define H_gtk_list_store_new "GtkListStore* gtk_list_store_new(gint n_columns, etc types)"
  XEN_ASSERT_TYPE(XEN_gint_P(n_columns), n_columns, 1, "gtk_list_store_new", "gint");
  XEN_ASSERT_TYPE(XEN_etc_P(types), types, 2, "gtk_list_store_new", "etc");
  {
    int etc_len = 0;
    GtkListStore* result = NULL;
    gint p_arg0;
    if (XEN_LIST_P(types)) etc_len = XEN_LIST_LENGTH(types);
    if (etc_len < 1) XEN_OUT_OF_RANGE_ERROR("gtk_list_store_new", 1, types, "... list must have at least 1 entry");
    if (etc_len > 6) XEN_OUT_OF_RANGE_ERROR("gtk_list_store_new", 1, types, "... list too long (max len: 6)");
    p_arg0 = XEN_TO_C_gint(n_columns);
    switch (etc_len)
      {
        case 1: result = gtk_list_store_new(p_arg0, XLG(types, 0)); break;
        case 2: result = gtk_list_store_new(p_arg0, XLG(types, 0), XLG(types, 1)); break;
        case 3: result = gtk_list_store_new(p_arg0, XLG(types, 0), XLG(types, 1), XLG(types, 2)); break;
        case 4: result = gtk_list_store_new(p_arg0, XLG(types, 0), XLG(types, 1), XLG(types, 2), XLG(types, 3)); break;
        case 5: result = gtk_list_store_new(p_arg0, XLG(types, 0), XLG(types, 1), XLG(types, 2), XLG(types, 3), XLG(types, 4)); break;
        case 6: result = gtk_list_store_new(p_arg0, XLG(types, 0), XLG(types, 1), XLG(types, 2), XLG(types, 3), XLG(types, 4), XLG(types, 5)); break;
      }
    return(C_TO_XEN_GtkListStore_(result));
  }
}
static XEN gxg_gtk_list_store_newv(XEN n_columns, XEN types)
{
  #define H_gtk_list_store_newv "GtkListStore* gtk_list_store_newv(gint n_columns, GType* types)"
  XEN_ASSERT_TYPE(XEN_gint_P(n_columns), n_columns, 1, "gtk_list_store_newv", "gint");
  XEN_ASSERT_TYPE(XEN_GType__P(types), types, 2, "gtk_list_store_newv", "GType*");
  return(C_TO_XEN_GtkListStore_(gtk_list_store_newv(XEN_TO_C_gint(n_columns), XEN_TO_C_GType_(types))));
}
static XEN gxg_gtk_list_store_set_column_types(XEN list_store, XEN n_columns, XEN types)
{
  #define H_gtk_list_store_set_column_types "void gtk_list_store_set_column_types(GtkListStore* list_store, \
gint n_columns, GType* types)"
  XEN_ASSERT_TYPE(XEN_GtkListStore__P(list_store), list_store, 1, "gtk_list_store_set_column_types", "GtkListStore*");
  XEN_ASSERT_TYPE(XEN_gint_P(n_columns), n_columns, 2, "gtk_list_store_set_column_types", "gint");
  XEN_ASSERT_TYPE(XEN_GType__P(types), types, 3, "gtk_list_store_set_column_types", "GType*");
  gtk_list_store_set_column_types(XEN_TO_C_GtkListStore_(list_store), XEN_TO_C_gint(n_columns), XEN_TO_C_GType_(types));
  return(XEN_FALSE);
}
static XEN gxg_gtk_list_store_set(XEN list_store, XEN iter, XEN values)
{
  #define H_gtk_list_store_set "void gtk_list_store_set(GtkListStore* list_store, GtkTreeIter* iter, \
etc values)"
  XEN_ASSERT_TYPE(XEN_GtkListStore__P(list_store), list_store, 1, "gtk_list_store_set", "GtkListStore*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_list_store_set", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_etc_P(values), values, 3, "gtk_list_store_set", "etc");
  {
    int etc_len = 0;
    GtkListStore* p_arg0;
    GtkTreeIter* p_arg1;
    if (XEN_LIST_P(values)) etc_len = XEN_LIST_LENGTH(values);
    if (etc_len < 2) XEN_OUT_OF_RANGE_ERROR("gtk_list_store_set", 2, values, "... list must have at least 2 entries");
    if (etc_len > 10) XEN_OUT_OF_RANGE_ERROR("gtk_list_store_set", 2, values, "... list too long (max len: 10)");
    if ((etc_len % 2) != 0) XEN_OUT_OF_RANGE_ERROR("gtk_list_store_set", 2, values, "... list len must be multiple of 2");
    p_arg0 = XEN_TO_C_GtkListStore_(list_store);
    p_arg1 = XEN_TO_C_GtkTreeIter_(iter);
    switch (etc_len)
      {
        case 2: gtk_list_store_set(p_arg0, p_arg1, XLI(values, 0), XLS(values, 1), -1); break;
        case 4: gtk_list_store_set(p_arg0, p_arg1, XLI(values, 0), XLS(values, 1), XLI(values, 2), XLS(values, 3), -1); break;
        case 6: gtk_list_store_set(p_arg0, p_arg1, XLI(values, 0), XLS(values, 1), XLI(values, 2), XLS(values, 3), XLI(values, 4), XLS(values, 5), -1); break;
        case 8: gtk_list_store_set(p_arg0, p_arg1, XLI(values, 0), XLS(values, 1), XLI(values, 2), XLS(values, 3), XLI(values, 4), XLS(values, 5), XLI(values, 6), XLS(values, 7), -1); break;
        case 10: gtk_list_store_set(p_arg0, p_arg1, XLI(values, 0), XLS(values, 1), XLI(values, 2), XLS(values, 3), XLI(values, 4), XLS(values, 5), XLI(values, 6), XLS(values, 7), XLI(values, 8), XLS(values, 9), -1); break;
      }
    return(XEN_FALSE);
  }
}
static XEN gxg_gtk_list_store_insert(XEN list_store, XEN iter, XEN position)
{
  #define H_gtk_list_store_insert "void gtk_list_store_insert(GtkListStore* list_store, GtkTreeIter* iter, \
gint position)"
  XEN_ASSERT_TYPE(XEN_GtkListStore__P(list_store), list_store, 1, "gtk_list_store_insert", "GtkListStore*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_list_store_insert", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_gint_P(position), position, 3, "gtk_list_store_insert", "gint");
  gtk_list_store_insert(XEN_TO_C_GtkListStore_(list_store), XEN_TO_C_GtkTreeIter_(iter), XEN_TO_C_gint(position));
  return(XEN_FALSE);
}
static XEN gxg_gtk_list_store_insert_before(XEN list_store, XEN iter, XEN sibling)
{
  #define H_gtk_list_store_insert_before "void gtk_list_store_insert_before(GtkListStore* list_store, \
GtkTreeIter* iter, GtkTreeIter* sibling)"
  XEN_ASSERT_TYPE(XEN_GtkListStore__P(list_store), list_store, 1, "gtk_list_store_insert_before", "GtkListStore*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_list_store_insert_before", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(sibling) || XEN_FALSE_P(sibling), sibling, 3, "gtk_list_store_insert_before", "GtkTreeIter*");
  gtk_list_store_insert_before(XEN_TO_C_GtkListStore_(list_store), XEN_TO_C_GtkTreeIter_(iter), XEN_TO_C_GtkTreeIter_(sibling));
  return(XEN_FALSE);
}
static XEN gxg_gtk_list_store_insert_after(XEN list_store, XEN iter, XEN sibling)
{
  #define H_gtk_list_store_insert_after "void gtk_list_store_insert_after(GtkListStore* list_store, GtkTreeIter* iter, \
GtkTreeIter* sibling)"
  XEN_ASSERT_TYPE(XEN_GtkListStore__P(list_store), list_store, 1, "gtk_list_store_insert_after", "GtkListStore*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_list_store_insert_after", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(sibling) || XEN_FALSE_P(sibling), sibling, 3, "gtk_list_store_insert_after", "GtkTreeIter*");
  gtk_list_store_insert_after(XEN_TO_C_GtkListStore_(list_store), XEN_TO_C_GtkTreeIter_(iter), XEN_TO_C_GtkTreeIter_(sibling));
  return(XEN_FALSE);
}
static XEN gxg_gtk_list_store_prepend(XEN list_store, XEN iter)
{
  #define H_gtk_list_store_prepend "void gtk_list_store_prepend(GtkListStore* list_store, GtkTreeIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkListStore__P(list_store), list_store, 1, "gtk_list_store_prepend", "GtkListStore*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_list_store_prepend", "GtkTreeIter*");
  gtk_list_store_prepend(XEN_TO_C_GtkListStore_(list_store), XEN_TO_C_GtkTreeIter_(iter));
  return(XEN_FALSE);
}
static XEN gxg_gtk_list_store_append(XEN list_store, XEN iter)
{
  #define H_gtk_list_store_append "void gtk_list_store_append(GtkListStore* list_store, GtkTreeIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkListStore__P(list_store), list_store, 1, "gtk_list_store_append", "GtkListStore*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_list_store_append", "GtkTreeIter*");
  gtk_list_store_append(XEN_TO_C_GtkListStore_(list_store), XEN_TO_C_GtkTreeIter_(iter));
  return(XEN_FALSE);
}
static XEN gxg_gtk_list_store_clear(XEN list_store)
{
  #define H_gtk_list_store_clear "void gtk_list_store_clear(GtkListStore* list_store)"
  XEN_ASSERT_TYPE(XEN_GtkListStore__P(list_store), list_store, 1, "gtk_list_store_clear", "GtkListStore*");
  gtk_list_store_clear(XEN_TO_C_GtkListStore_(list_store));
  return(XEN_FALSE);
}
static XEN gxg_gtk_check_version(XEN required_major, XEN required_minor, XEN required_micro)
{
  #define H_gtk_check_version "gchar* gtk_check_version(guint required_major, guint required_minor, guint required_micro)"
  XEN_ASSERT_TYPE(XEN_guint_P(required_major), required_major, 1, "gtk_check_version", "guint");
  XEN_ASSERT_TYPE(XEN_guint_P(required_minor), required_minor, 2, "gtk_check_version", "guint");
  XEN_ASSERT_TYPE(XEN_guint_P(required_micro), required_micro, 3, "gtk_check_version", "guint");
  return(C_TO_XEN_gchar_(gtk_check_version(XEN_TO_C_guint(required_major), XEN_TO_C_guint(required_minor), XEN_TO_C_guint(required_micro))));
}
static XEN gxg_gtk_init(XEN argc, XEN argv)
{
  #define H_gtk_init "void gtk_init(int* {argc}, char*** |argv|)"
  int ref_argc;
  char** ref_argv = NULL;
  ref_argc = XEN_TO_C_int(argc);
  ref_argv = (char**)calloc(ref_argc, sizeof(char*));
  {
   int i;
   XEN lst;
   lst = XEN_COPY_ARG(argv);
   for (i = 0; i < ref_argc; i++, lst = XEN_CDR(lst)) ref_argv[i] = XEN_TO_C_char_(XEN_CAR(lst));
  }
  gtk_init(&ref_argc, &ref_argv);
  return(XEN_LIST_2(C_TO_XEN_int(ref_argc), C_TO_XEN_char__(ref_argv)));
}
static XEN gxg_gtk_init_check(XEN argc, XEN argv)
{
  #define H_gtk_init_check "gboolean gtk_init_check(int* {argc}, char*** |argv|)"
  int ref_argc;
  char** ref_argv = NULL;
  ref_argc = XEN_TO_C_int(argc);
  ref_argv = (char**)calloc(ref_argc, sizeof(char*));
  {
   int i;
   XEN lst;
   lst = XEN_COPY_ARG(argv);
   for (i = 0; i < ref_argc; i++, lst = XEN_CDR(lst)) ref_argv[i] = XEN_TO_C_char_(XEN_CAR(lst));
  }
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gtk_init_check(&ref_argc, &ref_argv));
    return(XEN_LIST_3(result, C_TO_XEN_int(ref_argc), C_TO_XEN_char__(ref_argv)));
   }
}
static XEN gxg_gtk_disable_setlocale(void)
{
  #define H_gtk_disable_setlocale "void gtk_disable_setlocale( void)"
  gtk_disable_setlocale();
  return(XEN_FALSE);
}
static XEN gxg_gtk_set_locale(void)
{
  #define H_gtk_set_locale "gchar* gtk_set_locale( void)"
  return(C_TO_XEN_gchar_(gtk_set_locale()));
}
static XEN gxg_gtk_get_default_language(void)
{
  #define H_gtk_get_default_language "PangoLanguage* gtk_get_default_language( void)"
  return(C_TO_XEN_PangoLanguage_(gtk_get_default_language()));
}
static XEN gxg_gtk_events_pending(void)
{
  #define H_gtk_events_pending "gint gtk_events_pending( void)"
  return(C_TO_XEN_gint(gtk_events_pending()));
}
static XEN gxg_gtk_main_do_event(XEN event)
{
  #define H_gtk_main_do_event "void gtk_main_do_event(GdkEvent* event)"
  XEN_ASSERT_TYPE(XEN_GdkEvent__P(event), event, 1, "gtk_main_do_event", "GdkEvent*");
  gtk_main_do_event(XEN_TO_C_GdkEvent_(event));
  return(XEN_FALSE);
}
static XEN gxg_gtk_main(void)
{
  #define H_gtk_main "void gtk_main( void)"
  gtk_main();
  return(XEN_FALSE);
}
static XEN gxg_gtk_main_level(void)
{
  #define H_gtk_main_level "guint gtk_main_level( void)"
  return(C_TO_XEN_guint(gtk_main_level()));
}
static XEN gxg_gtk_main_quit(void)
{
  #define H_gtk_main_quit "void gtk_main_quit( void)"
  gtk_main_quit();
  return(XEN_FALSE);
}
static XEN gxg_gtk_main_iteration(void)
{
  #define H_gtk_main_iteration "gboolean gtk_main_iteration( void)"
  return(C_TO_XEN_gboolean(gtk_main_iteration()));
}
static XEN gxg_gtk_main_iteration_do(XEN blocking)
{
  #define H_gtk_main_iteration_do "gboolean gtk_main_iteration_do(gboolean blocking)"
  XEN_ASSERT_TYPE(XEN_gboolean_P(blocking), blocking, 1, "gtk_main_iteration_do", "gboolean");
  return(C_TO_XEN_gboolean(gtk_main_iteration_do(XEN_TO_C_gboolean(blocking))));
}
static XEN gxg_gtk_true(void)
{
  #define H_gtk_true "gboolean gtk_true( void)"
  return(C_TO_XEN_gboolean(gtk_true()));
}
static XEN gxg_gtk_false(void)
{
  #define H_gtk_false "gboolean gtk_false( void)"
  return(C_TO_XEN_gboolean(gtk_false()));
}
static XEN gxg_gtk_grab_add(XEN widget)
{
  #define H_gtk_grab_add "void gtk_grab_add(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_grab_add", "GtkWidget*");
  gtk_grab_add(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_grab_get_current(void)
{
  #define H_gtk_grab_get_current "GtkWidget* gtk_grab_get_current( void)"
  return(C_TO_XEN_GtkWidget_(gtk_grab_get_current()));
}
static XEN gxg_gtk_grab_remove(XEN widget)
{
  #define H_gtk_grab_remove "void gtk_grab_remove(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_grab_remove", "GtkWidget*");
  gtk_grab_remove(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_init_add(XEN func, XEN func_data)
{
  #define H_gtk_init_add "void gtk_init_add(GtkFunction func, lambda_data func_data)"
  XEN_ASSERT_TYPE(XEN_GtkFunction_P(func), func, 1, "gtk_init_add", "GtkFunction");
  if (XEN_NOT_BOUND_P(func_data)) func_data = XEN_FALSE; 
  else XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 2, "gtk_init_add", "lambda_data");
  {
    int loc;
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    loc = xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 2, C_TO_XEN_INT(loc));
    gtk_init_add(XEN_TO_C_GtkFunction(func), XEN_TO_C_lambda_data(func_data));
    XEN_LIST_SET(gxg_ptr, 2, XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("idler"), XEN_FALSE, C_TO_XEN_INT(loc)));
    return(XEN_FALSE);
   }
}
static XEN gxg_gtk_quit_add_destroy(XEN main_level, XEN object)
{
  #define H_gtk_quit_add_destroy "void gtk_quit_add_destroy(guint main_level, GtkObject* object)"
  XEN_ASSERT_TYPE(XEN_guint_P(main_level), main_level, 1, "gtk_quit_add_destroy", "guint");
  XEN_ASSERT_TYPE(XEN_GtkObject__P(object), object, 2, "gtk_quit_add_destroy", "GtkObject*");
  gtk_quit_add_destroy(XEN_TO_C_guint(main_level), XEN_TO_C_GtkObject_(object));
  return(XEN_FALSE);
}
static XEN gxg_gtk_quit_add(XEN main_level, XEN func, XEN func_data)
{
  #define H_gtk_quit_add "guint gtk_quit_add(guint main_level, GtkFunction func, lambda_data func_data)"
  XEN_ASSERT_TYPE(XEN_guint_P(main_level), main_level, 1, "gtk_quit_add", "guint");
  XEN_ASSERT_TYPE(XEN_GtkFunction_P(func), func, 2, "gtk_quit_add", "GtkFunction");
  if (XEN_NOT_BOUND_P(func_data)) func_data = XEN_FALSE; 
  else XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 3, "gtk_quit_add", "lambda_data");
  {
    XEN result = XEN_FALSE;
    int loc;
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    loc = xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 2, C_TO_XEN_INT(loc));
    result = C_TO_XEN_guint(gtk_quit_add(XEN_TO_C_guint(main_level), XEN_TO_C_GtkFunction(func), XEN_TO_C_lambda_data(func_data)));
    XEN_LIST_SET(gxg_ptr, 2, XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("idler"), result, C_TO_XEN_INT(loc)));
    return(result);
   }
}
static XEN gxg_gtk_quit_remove(XEN quit_handler_id)
{
  #define H_gtk_quit_remove "void gtk_quit_remove(guint quit_handler_id)"
  XEN_ASSERT_TYPE(XEN_guint_P(quit_handler_id), quit_handler_id, 1, "gtk_quit_remove", "guint");
  gtk_quit_remove(XEN_TO_C_guint(quit_handler_id));
  xm_unprotect_at(XEN_TO_C_INT(XEN_CADDR(quit_handler_id)));
  return(XEN_FALSE);
}
static XEN gxg_gtk_quit_remove_by_data(XEN data)
{
  #define H_gtk_quit_remove_by_data "void gtk_quit_remove_by_data(xen data)"
  XEN_ASSERT_TYPE(XEN_xen_P(data), data, 1, "gtk_quit_remove_by_data", "xen");
  gtk_quit_remove_by_data(XEN_TO_C_xen(data));
  xm_unprotect_at(XEN_TO_C_INT(XEN_CADDR(data)));
  return(XEN_FALSE);
}
static XEN gxg_gtk_key_snooper_install(XEN func, XEN func_data)
{
  #define H_gtk_key_snooper_install "guint gtk_key_snooper_install(GtkKeySnoopFunc func, lambda_data func_data)"
  XEN_ASSERT_TYPE(XEN_GtkKeySnoopFunc_P(func), func, 1, "gtk_key_snooper_install", "GtkKeySnoopFunc");
  if (XEN_NOT_BOUND_P(func_data)) func_data = XEN_FALSE; 
  else XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 2, "gtk_key_snooper_install", "lambda_data");
  {
    XEN result = XEN_FALSE;
    int loc;
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    loc = xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 2, C_TO_XEN_INT(loc));
    result = C_TO_XEN_guint(gtk_key_snooper_install(XEN_TO_C_GtkKeySnoopFunc(func), XEN_TO_C_lambda_data(func_data)));
    XEN_LIST_SET(gxg_ptr, 2, XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("idler"), result, C_TO_XEN_INT(loc)));
    return(result);
   }
}
static XEN gxg_gtk_key_snooper_remove(XEN snooper_handler_id)
{
  #define H_gtk_key_snooper_remove "void gtk_key_snooper_remove(guint snooper_handler_id)"
  XEN_ASSERT_TYPE(XEN_guint_P(snooper_handler_id), snooper_handler_id, 1, "gtk_key_snooper_remove", "guint");
  gtk_key_snooper_remove(XEN_TO_C_guint(snooper_handler_id));
  xm_unprotect_at(XEN_TO_C_INT(XEN_CADDR(snooper_handler_id)));
  return(XEN_FALSE);
}
static XEN gxg_gtk_get_current_event(void)
{
  #define H_gtk_get_current_event "GdkEvent* gtk_get_current_event( void)"
  return(C_TO_XEN_GdkEvent_(gtk_get_current_event()));
}
static XEN gxg_gtk_get_current_event_time(void)
{
  #define H_gtk_get_current_event_time "guint32 gtk_get_current_event_time( void)"
  return(C_TO_XEN_guint32(gtk_get_current_event_time()));
}
static XEN gxg_gtk_get_current_event_state(XEN state)
{
  #define H_gtk_get_current_event_state "gboolean gtk_get_current_event_state(GdkModifierType* [state])"
  GdkModifierType ref_state;
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gtk_get_current_event_state(&ref_state));
    return(XEN_LIST_2(result, C_TO_XEN_GdkModifierType(ref_state)));
   }
}
static XEN gxg_gtk_get_event_widget(XEN event)
{
  #define H_gtk_get_event_widget "GtkWidget* gtk_get_event_widget(GdkEvent* event)"
  XEN_ASSERT_TYPE(XEN_GdkEvent__P(event) || XEN_FALSE_P(event), event, 1, "gtk_get_event_widget", "GdkEvent*");
  return(C_TO_XEN_GtkWidget_(gtk_get_event_widget(XEN_TO_C_GdkEvent_(event))));
}
static XEN gxg_gtk_propagate_event(XEN widget, XEN event)
{
  #define H_gtk_propagate_event "void gtk_propagate_event(GtkWidget* widget, GdkEvent* event)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_propagate_event", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GdkEvent__P(event), event, 2, "gtk_propagate_event", "GdkEvent*");
  gtk_propagate_event(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GdkEvent_(event));
  return(XEN_FALSE);
}
static XEN gxg_gtk_menu_bar_get_type(void)
{
  #define H_gtk_menu_bar_get_type "GtkType gtk_menu_bar_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_menu_bar_get_type()));
}
static XEN gxg_gtk_menu_bar_new(void)
{
  #define H_gtk_menu_bar_new "GtkWidget* gtk_menu_bar_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_menu_bar_new()));
}
static XEN gxg_gtk_menu_get_type(void)
{
  #define H_gtk_menu_get_type "GtkType gtk_menu_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_menu_get_type()));
}
static XEN gxg_gtk_menu_new(void)
{
  #define H_gtk_menu_new "GtkWidget* gtk_menu_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_menu_new()));
}
static XEN gxg_gtk_menu_popup(XEN menu, XEN parent_menu_shell, XEN parent_menu_item, XEN func, XEN func_data, XEN button, XEN activate_time)
{
  #define H_gtk_menu_popup "void gtk_menu_popup(GtkMenu* menu, GtkWidget* parent_menu_shell, GtkWidget* parent_menu_item, \
GtkMenuPositionFunc func, lambda_data func_data, guint button, guint32 activate_time)"
  XEN_ASSERT_TYPE(XEN_GtkMenu__P(menu), menu, 1, "gtk_menu_popup", "GtkMenu*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(parent_menu_shell), parent_menu_shell, 2, "gtk_menu_popup", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(parent_menu_item), parent_menu_item, 3, "gtk_menu_popup", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkMenuPositionFunc_P(func), func, 4, "gtk_menu_popup", "GtkMenuPositionFunc");
  XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 5, "gtk_menu_popup", "lambda_data");
  XEN_ASSERT_TYPE(XEN_guint_P(button), button, 6, "gtk_menu_popup", "guint");
  XEN_ASSERT_TYPE(XEN_guint32_P(activate_time), activate_time, 7, "gtk_menu_popup", "guint32");
  {
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    xm_protect(gxg_ptr);
    gtk_menu_popup(XEN_TO_C_GtkMenu_(menu), XEN_TO_C_GtkWidget_(parent_menu_shell), XEN_TO_C_GtkWidget_(parent_menu_item), XEN_TO_C_GtkMenuPositionFunc(func), 
               XEN_TO_C_lambda_data(func_data), XEN_TO_C_guint(button), XEN_TO_C_guint32(activate_time));
    return(XEN_FALSE);
   }
}
static XEN gxg_gtk_menu_reposition(XEN menu)
{
  #define H_gtk_menu_reposition "void gtk_menu_reposition(GtkMenu* menu)"
  XEN_ASSERT_TYPE(XEN_GtkMenu__P(menu), menu, 1, "gtk_menu_reposition", "GtkMenu*");
  gtk_menu_reposition(XEN_TO_C_GtkMenu_(menu));
  return(XEN_FALSE);
}
static XEN gxg_gtk_menu_popdown(XEN menu)
{
  #define H_gtk_menu_popdown "void gtk_menu_popdown(GtkMenu* menu)"
  XEN_ASSERT_TYPE(XEN_GtkMenu__P(menu), menu, 1, "gtk_menu_popdown", "GtkMenu*");
  gtk_menu_popdown(XEN_TO_C_GtkMenu_(menu));
  return(XEN_FALSE);
}
static XEN gxg_gtk_menu_get_active(XEN menu)
{
  #define H_gtk_menu_get_active "GtkWidget* gtk_menu_get_active(GtkMenu* menu)"
  XEN_ASSERT_TYPE(XEN_GtkMenu__P(menu), menu, 1, "gtk_menu_get_active", "GtkMenu*");
  return(C_TO_XEN_GtkWidget_(gtk_menu_get_active(XEN_TO_C_GtkMenu_(menu))));
}
static XEN gxg_gtk_menu_set_active(XEN menu, XEN index)
{
  #define H_gtk_menu_set_active "void gtk_menu_set_active(GtkMenu* menu, guint index)"
  XEN_ASSERT_TYPE(XEN_GtkMenu__P(menu), menu, 1, "gtk_menu_set_active", "GtkMenu*");
  XEN_ASSERT_TYPE(XEN_guint_P(index), index, 2, "gtk_menu_set_active", "guint");
  gtk_menu_set_active(XEN_TO_C_GtkMenu_(menu), XEN_TO_C_guint(index));
  return(XEN_FALSE);
}
static XEN gxg_gtk_menu_set_accel_group(XEN menu, XEN accel_group)
{
  #define H_gtk_menu_set_accel_group "void gtk_menu_set_accel_group(GtkMenu* menu, GtkAccelGroup* accel_group)"
  XEN_ASSERT_TYPE(XEN_GtkMenu__P(menu), menu, 1, "gtk_menu_set_accel_group", "GtkMenu*");
  XEN_ASSERT_TYPE(XEN_GtkAccelGroup__P(accel_group), accel_group, 2, "gtk_menu_set_accel_group", "GtkAccelGroup*");
  gtk_menu_set_accel_group(XEN_TO_C_GtkMenu_(menu), XEN_TO_C_GtkAccelGroup_(accel_group));
  return(XEN_FALSE);
}
static XEN gxg_gtk_menu_get_accel_group(XEN menu)
{
  #define H_gtk_menu_get_accel_group "GtkAccelGroup* gtk_menu_get_accel_group(GtkMenu* menu)"
  XEN_ASSERT_TYPE(XEN_GtkMenu__P(menu), menu, 1, "gtk_menu_get_accel_group", "GtkMenu*");
  return(C_TO_XEN_GtkAccelGroup_(gtk_menu_get_accel_group(XEN_TO_C_GtkMenu_(menu))));
}
static XEN gxg_gtk_menu_set_accel_path(XEN menu, XEN accel_path)
{
  #define H_gtk_menu_set_accel_path "void gtk_menu_set_accel_path(GtkMenu* menu, gchar* accel_path)"
  XEN_ASSERT_TYPE(XEN_GtkMenu__P(menu), menu, 1, "gtk_menu_set_accel_path", "GtkMenu*");
  XEN_ASSERT_TYPE(XEN_gchar__P(accel_path), accel_path, 2, "gtk_menu_set_accel_path", "gchar*");
  gtk_menu_set_accel_path(XEN_TO_C_GtkMenu_(menu), XEN_TO_C_gchar_(accel_path));
  return(XEN_FALSE);
}
static XEN gxg_gtk_menu_detach(XEN menu)
{
  #define H_gtk_menu_detach "void gtk_menu_detach(GtkMenu* menu)"
  XEN_ASSERT_TYPE(XEN_GtkMenu__P(menu), menu, 1, "gtk_menu_detach", "GtkMenu*");
  gtk_menu_detach(XEN_TO_C_GtkMenu_(menu));
  return(XEN_FALSE);
}
static XEN gxg_gtk_menu_get_attach_widget(XEN menu)
{
  #define H_gtk_menu_get_attach_widget "GtkWidget* gtk_menu_get_attach_widget(GtkMenu* menu)"
  XEN_ASSERT_TYPE(XEN_GtkMenu__P(menu), menu, 1, "gtk_menu_get_attach_widget", "GtkMenu*");
  return(C_TO_XEN_GtkWidget_(gtk_menu_get_attach_widget(XEN_TO_C_GtkMenu_(menu))));
}
static XEN gxg_gtk_menu_set_tearoff_state(XEN menu, XEN torn_off)
{
  #define H_gtk_menu_set_tearoff_state "void gtk_menu_set_tearoff_state(GtkMenu* menu, gboolean torn_off)"
  XEN_ASSERT_TYPE(XEN_GtkMenu__P(menu), menu, 1, "gtk_menu_set_tearoff_state", "GtkMenu*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(torn_off), torn_off, 2, "gtk_menu_set_tearoff_state", "gboolean");
  gtk_menu_set_tearoff_state(XEN_TO_C_GtkMenu_(menu), XEN_TO_C_gboolean(torn_off));
  return(XEN_FALSE);
}
static XEN gxg_gtk_menu_get_tearoff_state(XEN menu)
{
  #define H_gtk_menu_get_tearoff_state "gboolean gtk_menu_get_tearoff_state(GtkMenu* menu)"
  XEN_ASSERT_TYPE(XEN_GtkMenu__P(menu), menu, 1, "gtk_menu_get_tearoff_state", "GtkMenu*");
  return(C_TO_XEN_gboolean(gtk_menu_get_tearoff_state(XEN_TO_C_GtkMenu_(menu))));
}
static XEN gxg_gtk_menu_set_title(XEN menu, XEN title)
{
  #define H_gtk_menu_set_title "void gtk_menu_set_title(GtkMenu* menu, gchar* title)"
  XEN_ASSERT_TYPE(XEN_GtkMenu__P(menu), menu, 1, "gtk_menu_set_title", "GtkMenu*");
  XEN_ASSERT_TYPE(XEN_gchar__P(title), title, 2, "gtk_menu_set_title", "gchar*");
  gtk_menu_set_title(XEN_TO_C_GtkMenu_(menu), XEN_TO_C_gchar_(title));
  return(XEN_FALSE);
}
static XEN gxg_gtk_menu_get_title(XEN menu)
{
  #define H_gtk_menu_get_title "gchar* gtk_menu_get_title(GtkMenu* menu)"
  XEN_ASSERT_TYPE(XEN_GtkMenu__P(menu), menu, 1, "gtk_menu_get_title", "GtkMenu*");
  return(C_TO_XEN_gchar_(gtk_menu_get_title(XEN_TO_C_GtkMenu_(menu))));
}
static XEN gxg_gtk_menu_reorder_child(XEN menu, XEN child, XEN position)
{
  #define H_gtk_menu_reorder_child "void gtk_menu_reorder_child(GtkMenu* menu, GtkWidget* child, gint position)"
  XEN_ASSERT_TYPE(XEN_GtkMenu__P(menu), menu, 1, "gtk_menu_reorder_child", "GtkMenu*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_menu_reorder_child", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gint_P(position), position, 3, "gtk_menu_reorder_child", "gint");
  gtk_menu_reorder_child(XEN_TO_C_GtkMenu_(menu), XEN_TO_C_GtkWidget_(child), XEN_TO_C_gint(position));
  return(XEN_FALSE);
}
static XEN gxg_gtk_menu_item_get_type(void)
{
  #define H_gtk_menu_item_get_type "GtkType gtk_menu_item_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_menu_item_get_type()));
}
static XEN gxg_gtk_menu_item_new(void)
{
  #define H_gtk_menu_item_new "GtkWidget* gtk_menu_item_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_menu_item_new()));
}
static XEN gxg_gtk_menu_item_new_with_label(XEN label)
{
  #define H_gtk_menu_item_new_with_label "GtkWidget* gtk_menu_item_new_with_label(gchar* label)"
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 1, "gtk_menu_item_new_with_label", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_menu_item_new_with_label(XEN_TO_C_gchar_(label))));
}
static XEN gxg_gtk_menu_item_new_with_mnemonic(XEN label)
{
  #define H_gtk_menu_item_new_with_mnemonic "GtkWidget* gtk_menu_item_new_with_mnemonic(gchar* label)"
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 1, "gtk_menu_item_new_with_mnemonic", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_menu_item_new_with_mnemonic(XEN_TO_C_gchar_(label))));
}
static XEN gxg_gtk_menu_item_set_submenu(XEN menu_item, XEN submenu)
{
  #define H_gtk_menu_item_set_submenu "void gtk_menu_item_set_submenu(GtkMenuItem* menu_item, GtkWidget* submenu)"
  XEN_ASSERT_TYPE(XEN_GtkMenuItem__P(menu_item), menu_item, 1, "gtk_menu_item_set_submenu", "GtkMenuItem*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(submenu), submenu, 2, "gtk_menu_item_set_submenu", "GtkWidget*");
  gtk_menu_item_set_submenu(XEN_TO_C_GtkMenuItem_(menu_item), XEN_TO_C_GtkWidget_(submenu));
  return(XEN_FALSE);
}
static XEN gxg_gtk_menu_item_get_submenu(XEN menu_item)
{
  #define H_gtk_menu_item_get_submenu "GtkWidget* gtk_menu_item_get_submenu(GtkMenuItem* menu_item)"
  XEN_ASSERT_TYPE(XEN_GtkMenuItem__P(menu_item), menu_item, 1, "gtk_menu_item_get_submenu", "GtkMenuItem*");
  return(C_TO_XEN_GtkWidget_(gtk_menu_item_get_submenu(XEN_TO_C_GtkMenuItem_(menu_item))));
}
static XEN gxg_gtk_menu_item_remove_submenu(XEN menu_item)
{
  #define H_gtk_menu_item_remove_submenu "void gtk_menu_item_remove_submenu(GtkMenuItem* menu_item)"
  XEN_ASSERT_TYPE(XEN_GtkMenuItem__P(menu_item), menu_item, 1, "gtk_menu_item_remove_submenu", "GtkMenuItem*");
  gtk_menu_item_remove_submenu(XEN_TO_C_GtkMenuItem_(menu_item));
  return(XEN_FALSE);
}
static XEN gxg_gtk_menu_item_select(XEN menu_item)
{
  #define H_gtk_menu_item_select "void gtk_menu_item_select(GtkMenuItem* menu_item)"
  XEN_ASSERT_TYPE(XEN_GtkMenuItem__P(menu_item), menu_item, 1, "gtk_menu_item_select", "GtkMenuItem*");
  gtk_menu_item_select(XEN_TO_C_GtkMenuItem_(menu_item));
  return(XEN_FALSE);
}
static XEN gxg_gtk_menu_item_deselect(XEN menu_item)
{
  #define H_gtk_menu_item_deselect "void gtk_menu_item_deselect(GtkMenuItem* menu_item)"
  XEN_ASSERT_TYPE(XEN_GtkMenuItem__P(menu_item), menu_item, 1, "gtk_menu_item_deselect", "GtkMenuItem*");
  gtk_menu_item_deselect(XEN_TO_C_GtkMenuItem_(menu_item));
  return(XEN_FALSE);
}
static XEN gxg_gtk_menu_item_activate(XEN menu_item)
{
  #define H_gtk_menu_item_activate "void gtk_menu_item_activate(GtkMenuItem* menu_item)"
  XEN_ASSERT_TYPE(XEN_GtkMenuItem__P(menu_item), menu_item, 1, "gtk_menu_item_activate", "GtkMenuItem*");
  gtk_menu_item_activate(XEN_TO_C_GtkMenuItem_(menu_item));
  return(XEN_FALSE);
}
static XEN gxg_gtk_menu_item_toggle_size_request(XEN menu_item, XEN requisition)
{
  #define H_gtk_menu_item_toggle_size_request "void gtk_menu_item_toggle_size_request(GtkMenuItem* menu_item, \
gint* requisition)"
  XEN_ASSERT_TYPE(XEN_GtkMenuItem__P(menu_item), menu_item, 1, "gtk_menu_item_toggle_size_request", "GtkMenuItem*");
  XEN_ASSERT_TYPE(XEN_gint__P(requisition), requisition, 2, "gtk_menu_item_toggle_size_request", "gint*");
  gtk_menu_item_toggle_size_request(XEN_TO_C_GtkMenuItem_(menu_item), XEN_TO_C_gint_(requisition));
  return(XEN_FALSE);
}
static XEN gxg_gtk_menu_item_toggle_size_allocate(XEN menu_item, XEN allocation)
{
  #define H_gtk_menu_item_toggle_size_allocate "void gtk_menu_item_toggle_size_allocate(GtkMenuItem* menu_item, \
gint allocation)"
  XEN_ASSERT_TYPE(XEN_GtkMenuItem__P(menu_item), menu_item, 1, "gtk_menu_item_toggle_size_allocate", "GtkMenuItem*");
  XEN_ASSERT_TYPE(XEN_gint_P(allocation), allocation, 2, "gtk_menu_item_toggle_size_allocate", "gint");
  gtk_menu_item_toggle_size_allocate(XEN_TO_C_GtkMenuItem_(menu_item), XEN_TO_C_gint(allocation));
  return(XEN_FALSE);
}
static XEN gxg_gtk_menu_item_set_right_justified(XEN menu_item, XEN right_justified)
{
  #define H_gtk_menu_item_set_right_justified "void gtk_menu_item_set_right_justified(GtkMenuItem* menu_item, \
gboolean right_justified)"
  XEN_ASSERT_TYPE(XEN_GtkMenuItem__P(menu_item), menu_item, 1, "gtk_menu_item_set_right_justified", "GtkMenuItem*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(right_justified), right_justified, 2, "gtk_menu_item_set_right_justified", "gboolean");
  gtk_menu_item_set_right_justified(XEN_TO_C_GtkMenuItem_(menu_item), XEN_TO_C_gboolean(right_justified));
  return(XEN_FALSE);
}
static XEN gxg_gtk_menu_item_get_right_justified(XEN menu_item)
{
  #define H_gtk_menu_item_get_right_justified "gboolean gtk_menu_item_get_right_justified(GtkMenuItem* menu_item)"
  XEN_ASSERT_TYPE(XEN_GtkMenuItem__P(menu_item), menu_item, 1, "gtk_menu_item_get_right_justified", "GtkMenuItem*");
  return(C_TO_XEN_gboolean(gtk_menu_item_get_right_justified(XEN_TO_C_GtkMenuItem_(menu_item))));
}
static XEN gxg_gtk_menu_item_set_accel_path(XEN menu_item, XEN accel_path)
{
  #define H_gtk_menu_item_set_accel_path "void gtk_menu_item_set_accel_path(GtkMenuItem* menu_item, gchar* accel_path)"
  XEN_ASSERT_TYPE(XEN_GtkMenuItem__P(menu_item), menu_item, 1, "gtk_menu_item_set_accel_path", "GtkMenuItem*");
  XEN_ASSERT_TYPE(XEN_gchar__P(accel_path), accel_path, 2, "gtk_menu_item_set_accel_path", "gchar*");
  gtk_menu_item_set_accel_path(XEN_TO_C_GtkMenuItem_(menu_item), XEN_TO_C_gchar_(accel_path));
  return(XEN_FALSE);
}
static XEN gxg_gtk_menu_shell_get_type(void)
{
  #define H_gtk_menu_shell_get_type "GtkType gtk_menu_shell_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_menu_shell_get_type()));
}
static XEN gxg_gtk_menu_shell_append(XEN menu_shell, XEN child)
{
  #define H_gtk_menu_shell_append "void gtk_menu_shell_append(GtkMenuShell* menu_shell, GtkWidget* child)"
  XEN_ASSERT_TYPE(XEN_GtkMenuShell__P(menu_shell), menu_shell, 1, "gtk_menu_shell_append", "GtkMenuShell*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_menu_shell_append", "GtkWidget*");
  gtk_menu_shell_append(XEN_TO_C_GtkMenuShell_(menu_shell), XEN_TO_C_GtkWidget_(child));
  return(XEN_FALSE);
}
static XEN gxg_gtk_menu_shell_prepend(XEN menu_shell, XEN child)
{
  #define H_gtk_menu_shell_prepend "void gtk_menu_shell_prepend(GtkMenuShell* menu_shell, GtkWidget* child)"
  XEN_ASSERT_TYPE(XEN_GtkMenuShell__P(menu_shell), menu_shell, 1, "gtk_menu_shell_prepend", "GtkMenuShell*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_menu_shell_prepend", "GtkWidget*");
  gtk_menu_shell_prepend(XEN_TO_C_GtkMenuShell_(menu_shell), XEN_TO_C_GtkWidget_(child));
  return(XEN_FALSE);
}
static XEN gxg_gtk_menu_shell_insert(XEN menu_shell, XEN child, XEN position)
{
  #define H_gtk_menu_shell_insert "void gtk_menu_shell_insert(GtkMenuShell* menu_shell, GtkWidget* child, \
gint position)"
  XEN_ASSERT_TYPE(XEN_GtkMenuShell__P(menu_shell), menu_shell, 1, "gtk_menu_shell_insert", "GtkMenuShell*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_menu_shell_insert", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gint_P(position), position, 3, "gtk_menu_shell_insert", "gint");
  gtk_menu_shell_insert(XEN_TO_C_GtkMenuShell_(menu_shell), XEN_TO_C_GtkWidget_(child), XEN_TO_C_gint(position));
  return(XEN_FALSE);
}
static XEN gxg_gtk_menu_shell_deactivate(XEN menu_shell)
{
  #define H_gtk_menu_shell_deactivate "void gtk_menu_shell_deactivate(GtkMenuShell* menu_shell)"
  XEN_ASSERT_TYPE(XEN_GtkMenuShell__P(menu_shell), menu_shell, 1, "gtk_menu_shell_deactivate", "GtkMenuShell*");
  gtk_menu_shell_deactivate(XEN_TO_C_GtkMenuShell_(menu_shell));
  return(XEN_FALSE);
}
static XEN gxg_gtk_menu_shell_select_item(XEN menu_shell, XEN menu_item)
{
  #define H_gtk_menu_shell_select_item "void gtk_menu_shell_select_item(GtkMenuShell* menu_shell, GtkWidget* menu_item)"
  XEN_ASSERT_TYPE(XEN_GtkMenuShell__P(menu_shell), menu_shell, 1, "gtk_menu_shell_select_item", "GtkMenuShell*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(menu_item), menu_item, 2, "gtk_menu_shell_select_item", "GtkWidget*");
  gtk_menu_shell_select_item(XEN_TO_C_GtkMenuShell_(menu_shell), XEN_TO_C_GtkWidget_(menu_item));
  return(XEN_FALSE);
}
static XEN gxg_gtk_menu_shell_deselect(XEN menu_shell)
{
  #define H_gtk_menu_shell_deselect "void gtk_menu_shell_deselect(GtkMenuShell* menu_shell)"
  XEN_ASSERT_TYPE(XEN_GtkMenuShell__P(menu_shell), menu_shell, 1, "gtk_menu_shell_deselect", "GtkMenuShell*");
  gtk_menu_shell_deselect(XEN_TO_C_GtkMenuShell_(menu_shell));
  return(XEN_FALSE);
}
static XEN gxg_gtk_menu_shell_activate_item(XEN menu_shell, XEN menu_item, XEN force_deactivate)
{
  #define H_gtk_menu_shell_activate_item "void gtk_menu_shell_activate_item(GtkMenuShell* menu_shell, \
GtkWidget* menu_item, gboolean force_deactivate)"
  XEN_ASSERT_TYPE(XEN_GtkMenuShell__P(menu_shell), menu_shell, 1, "gtk_menu_shell_activate_item", "GtkMenuShell*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(menu_item), menu_item, 2, "gtk_menu_shell_activate_item", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(force_deactivate), force_deactivate, 3, "gtk_menu_shell_activate_item", "gboolean");
  gtk_menu_shell_activate_item(XEN_TO_C_GtkMenuShell_(menu_shell), XEN_TO_C_GtkWidget_(menu_item), XEN_TO_C_gboolean(force_deactivate));
  return(XEN_FALSE);
}
static XEN gxg_gtk_message_dialog_get_type(void)
{
  #define H_gtk_message_dialog_get_type "GtkType gtk_message_dialog_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_message_dialog_get_type()));
}
static XEN gxg_gtk_misc_get_type(void)
{
  #define H_gtk_misc_get_type "GtkType gtk_misc_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_misc_get_type()));
}
static XEN gxg_gtk_misc_set_alignment(XEN misc, XEN xalign, XEN yalign)
{
  #define H_gtk_misc_set_alignment "void gtk_misc_set_alignment(GtkMisc* misc, gfloat xalign, gfloat yalign)"
  XEN_ASSERT_TYPE(XEN_GtkMisc__P(misc), misc, 1, "gtk_misc_set_alignment", "GtkMisc*");
  XEN_ASSERT_TYPE(XEN_gfloat_P(xalign), xalign, 2, "gtk_misc_set_alignment", "gfloat");
  XEN_ASSERT_TYPE(XEN_gfloat_P(yalign), yalign, 3, "gtk_misc_set_alignment", "gfloat");
  gtk_misc_set_alignment(XEN_TO_C_GtkMisc_(misc), XEN_TO_C_gfloat(xalign), XEN_TO_C_gfloat(yalign));
  return(XEN_FALSE);
}
static XEN gxg_gtk_misc_get_alignment(XEN misc, XEN xalign, XEN yalign)
{
  #define H_gtk_misc_get_alignment "void gtk_misc_get_alignment(GtkMisc* misc, gfloat* [xalign], gfloat* [yalign])"
  gfloat ref_xalign;
  gfloat ref_yalign;
  XEN_ASSERT_TYPE(XEN_GtkMisc__P(misc), misc, 1, "gtk_misc_get_alignment", "GtkMisc*");
  gtk_misc_get_alignment(XEN_TO_C_GtkMisc_(misc), &ref_xalign, &ref_yalign);
  return(XEN_LIST_2(C_TO_XEN_gfloat(ref_xalign), C_TO_XEN_gfloat(ref_yalign)));
}
static XEN gxg_gtk_misc_set_padding(XEN misc, XEN xpad, XEN ypad)
{
  #define H_gtk_misc_set_padding "void gtk_misc_set_padding(GtkMisc* misc, gint xpad, gint ypad)"
  XEN_ASSERT_TYPE(XEN_GtkMisc__P(misc), misc, 1, "gtk_misc_set_padding", "GtkMisc*");
  XEN_ASSERT_TYPE(XEN_gint_P(xpad), xpad, 2, "gtk_misc_set_padding", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(ypad), ypad, 3, "gtk_misc_set_padding", "gint");
  gtk_misc_set_padding(XEN_TO_C_GtkMisc_(misc), XEN_TO_C_gint(xpad), XEN_TO_C_gint(ypad));
  return(XEN_FALSE);
}
static XEN gxg_gtk_misc_get_padding(XEN misc, XEN xpad, XEN ypad)
{
  #define H_gtk_misc_get_padding "void gtk_misc_get_padding(GtkMisc* misc, gint* [xpad], gint* [ypad])"
  gint ref_xpad;
  gint ref_ypad;
  XEN_ASSERT_TYPE(XEN_GtkMisc__P(misc), misc, 1, "gtk_misc_get_padding", "GtkMisc*");
  gtk_misc_get_padding(XEN_TO_C_GtkMisc_(misc), &ref_xpad, &ref_ypad);
  return(XEN_LIST_2(C_TO_XEN_gint(ref_xpad), C_TO_XEN_gint(ref_ypad)));
}
static XEN gxg_gtk_notebook_get_type(void)
{
  #define H_gtk_notebook_get_type "GtkType gtk_notebook_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_notebook_get_type()));
}
static XEN gxg_gtk_notebook_new(void)
{
  #define H_gtk_notebook_new "GtkWidget* gtk_notebook_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_notebook_new()));
}
static XEN gxg_gtk_notebook_remove_page(XEN notebook, XEN page_num)
{
  #define H_gtk_notebook_remove_page "void gtk_notebook_remove_page(GtkNotebook* notebook, gint page_num)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_remove_page", "GtkNotebook*");
  XEN_ASSERT_TYPE(XEN_gint_P(page_num), page_num, 2, "gtk_notebook_remove_page", "gint");
  gtk_notebook_remove_page(XEN_TO_C_GtkNotebook_(notebook), XEN_TO_C_gint(page_num));
  return(XEN_FALSE);
}
static XEN gxg_gtk_notebook_get_current_page(XEN notebook)
{
  #define H_gtk_notebook_get_current_page "gint gtk_notebook_get_current_page(GtkNotebook* notebook)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_get_current_page", "GtkNotebook*");
  return(C_TO_XEN_gint(gtk_notebook_get_current_page(XEN_TO_C_GtkNotebook_(notebook))));
}
static XEN gxg_gtk_notebook_get_nth_page(XEN notebook, XEN page_num)
{
  #define H_gtk_notebook_get_nth_page "GtkWidget* gtk_notebook_get_nth_page(GtkNotebook* notebook, gint page_num)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_get_nth_page", "GtkNotebook*");
  XEN_ASSERT_TYPE(XEN_gint_P(page_num), page_num, 2, "gtk_notebook_get_nth_page", "gint");
  return(C_TO_XEN_GtkWidget_(gtk_notebook_get_nth_page(XEN_TO_C_GtkNotebook_(notebook), XEN_TO_C_gint(page_num))));
}
static XEN gxg_gtk_notebook_page_num(XEN notebook, XEN child)
{
  #define H_gtk_notebook_page_num "gint gtk_notebook_page_num(GtkNotebook* notebook, GtkWidget* child)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_page_num", "GtkNotebook*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_notebook_page_num", "GtkWidget*");
  return(C_TO_XEN_gint(gtk_notebook_page_num(XEN_TO_C_GtkNotebook_(notebook), XEN_TO_C_GtkWidget_(child))));
}
static XEN gxg_gtk_notebook_set_current_page(XEN notebook, XEN page_num)
{
  #define H_gtk_notebook_set_current_page "void gtk_notebook_set_current_page(GtkNotebook* notebook, \
gint page_num)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_set_current_page", "GtkNotebook*");
  XEN_ASSERT_TYPE(XEN_gint_P(page_num), page_num, 2, "gtk_notebook_set_current_page", "gint");
  gtk_notebook_set_current_page(XEN_TO_C_GtkNotebook_(notebook), XEN_TO_C_gint(page_num));
  return(XEN_FALSE);
}
static XEN gxg_gtk_notebook_next_page(XEN notebook)
{
  #define H_gtk_notebook_next_page "void gtk_notebook_next_page(GtkNotebook* notebook)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_next_page", "GtkNotebook*");
  gtk_notebook_next_page(XEN_TO_C_GtkNotebook_(notebook));
  return(XEN_FALSE);
}
static XEN gxg_gtk_notebook_prev_page(XEN notebook)
{
  #define H_gtk_notebook_prev_page "void gtk_notebook_prev_page(GtkNotebook* notebook)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_prev_page", "GtkNotebook*");
  gtk_notebook_prev_page(XEN_TO_C_GtkNotebook_(notebook));
  return(XEN_FALSE);
}
static XEN gxg_gtk_notebook_set_show_border(XEN notebook, XEN show_border)
{
  #define H_gtk_notebook_set_show_border "void gtk_notebook_set_show_border(GtkNotebook* notebook, gboolean show_border)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_set_show_border", "GtkNotebook*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(show_border), show_border, 2, "gtk_notebook_set_show_border", "gboolean");
  gtk_notebook_set_show_border(XEN_TO_C_GtkNotebook_(notebook), XEN_TO_C_gboolean(show_border));
  return(XEN_FALSE);
}
static XEN gxg_gtk_notebook_get_show_border(XEN notebook)
{
  #define H_gtk_notebook_get_show_border "gboolean gtk_notebook_get_show_border(GtkNotebook* notebook)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_get_show_border", "GtkNotebook*");
  return(C_TO_XEN_gboolean(gtk_notebook_get_show_border(XEN_TO_C_GtkNotebook_(notebook))));
}
static XEN gxg_gtk_notebook_set_show_tabs(XEN notebook, XEN show_tabs)
{
  #define H_gtk_notebook_set_show_tabs "void gtk_notebook_set_show_tabs(GtkNotebook* notebook, gboolean show_tabs)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_set_show_tabs", "GtkNotebook*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(show_tabs), show_tabs, 2, "gtk_notebook_set_show_tabs", "gboolean");
  gtk_notebook_set_show_tabs(XEN_TO_C_GtkNotebook_(notebook), XEN_TO_C_gboolean(show_tabs));
  return(XEN_FALSE);
}
static XEN gxg_gtk_notebook_get_show_tabs(XEN notebook)
{
  #define H_gtk_notebook_get_show_tabs "gboolean gtk_notebook_get_show_tabs(GtkNotebook* notebook)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_get_show_tabs", "GtkNotebook*");
  return(C_TO_XEN_gboolean(gtk_notebook_get_show_tabs(XEN_TO_C_GtkNotebook_(notebook))));
}
static XEN gxg_gtk_notebook_set_tab_pos(XEN notebook, XEN pos)
{
  #define H_gtk_notebook_set_tab_pos "void gtk_notebook_set_tab_pos(GtkNotebook* notebook, GtkPositionType pos)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_set_tab_pos", "GtkNotebook*");
  XEN_ASSERT_TYPE(XEN_GtkPositionType_P(pos), pos, 2, "gtk_notebook_set_tab_pos", "GtkPositionType");
  gtk_notebook_set_tab_pos(XEN_TO_C_GtkNotebook_(notebook), XEN_TO_C_GtkPositionType(pos));
  return(XEN_FALSE);
}
static XEN gxg_gtk_notebook_get_tab_pos(XEN notebook)
{
  #define H_gtk_notebook_get_tab_pos "GtkPositionType gtk_notebook_get_tab_pos(GtkNotebook* notebook)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_get_tab_pos", "GtkNotebook*");
  return(C_TO_XEN_GtkPositionType(gtk_notebook_get_tab_pos(XEN_TO_C_GtkNotebook_(notebook))));
}
static XEN gxg_gtk_notebook_set_scrollable(XEN notebook, XEN scrollable)
{
  #define H_gtk_notebook_set_scrollable "void gtk_notebook_set_scrollable(GtkNotebook* notebook, gboolean scrollable)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_set_scrollable", "GtkNotebook*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(scrollable), scrollable, 2, "gtk_notebook_set_scrollable", "gboolean");
  gtk_notebook_set_scrollable(XEN_TO_C_GtkNotebook_(notebook), XEN_TO_C_gboolean(scrollable));
  return(XEN_FALSE);
}
static XEN gxg_gtk_notebook_get_scrollable(XEN notebook)
{
  #define H_gtk_notebook_get_scrollable "gboolean gtk_notebook_get_scrollable(GtkNotebook* notebook)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_get_scrollable", "GtkNotebook*");
  return(C_TO_XEN_gboolean(gtk_notebook_get_scrollable(XEN_TO_C_GtkNotebook_(notebook))));
}
static XEN gxg_gtk_notebook_popup_enable(XEN notebook)
{
  #define H_gtk_notebook_popup_enable "void gtk_notebook_popup_enable(GtkNotebook* notebook)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_popup_enable", "GtkNotebook*");
  gtk_notebook_popup_enable(XEN_TO_C_GtkNotebook_(notebook));
  return(XEN_FALSE);
}
static XEN gxg_gtk_notebook_popup_disable(XEN notebook)
{
  #define H_gtk_notebook_popup_disable "void gtk_notebook_popup_disable(GtkNotebook* notebook)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_popup_disable", "GtkNotebook*");
  gtk_notebook_popup_disable(XEN_TO_C_GtkNotebook_(notebook));
  return(XEN_FALSE);
}
static XEN gxg_gtk_notebook_get_tab_label(XEN notebook, XEN child)
{
  #define H_gtk_notebook_get_tab_label "GtkWidget* gtk_notebook_get_tab_label(GtkNotebook* notebook, \
GtkWidget* child)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_get_tab_label", "GtkNotebook*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_notebook_get_tab_label", "GtkWidget*");
  return(C_TO_XEN_GtkWidget_(gtk_notebook_get_tab_label(XEN_TO_C_GtkNotebook_(notebook), XEN_TO_C_GtkWidget_(child))));
}
static XEN gxg_gtk_notebook_set_tab_label(XEN notebook, XEN child, XEN tab_label)
{
  #define H_gtk_notebook_set_tab_label "void gtk_notebook_set_tab_label(GtkNotebook* notebook, GtkWidget* child, \
GtkWidget* tab_label)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_set_tab_label", "GtkNotebook*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_notebook_set_tab_label", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(tab_label) || XEN_FALSE_P(tab_label), tab_label, 3, "gtk_notebook_set_tab_label", "GtkWidget*");
  gtk_notebook_set_tab_label(XEN_TO_C_GtkNotebook_(notebook), XEN_TO_C_GtkWidget_(child), XEN_TO_C_GtkWidget_(tab_label));
  return(XEN_FALSE);
}
static XEN gxg_gtk_notebook_set_tab_label_text(XEN notebook, XEN child, XEN tab_text)
{
  #define H_gtk_notebook_set_tab_label_text "void gtk_notebook_set_tab_label_text(GtkNotebook* notebook, \
GtkWidget* child, gchar* tab_text)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_set_tab_label_text", "GtkNotebook*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_notebook_set_tab_label_text", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(tab_text), tab_text, 3, "gtk_notebook_set_tab_label_text", "gchar*");
  gtk_notebook_set_tab_label_text(XEN_TO_C_GtkNotebook_(notebook), XEN_TO_C_GtkWidget_(child), XEN_TO_C_gchar_(tab_text));
  return(XEN_FALSE);
}
static XEN gxg_gtk_notebook_get_tab_label_text(XEN notebook, XEN child)
{
  #define H_gtk_notebook_get_tab_label_text "gchar* gtk_notebook_get_tab_label_text(GtkNotebook* notebook, \
GtkWidget* child)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_get_tab_label_text", "GtkNotebook*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_notebook_get_tab_label_text", "GtkWidget*");
  return(C_TO_XEN_gchar_(gtk_notebook_get_tab_label_text(XEN_TO_C_GtkNotebook_(notebook), XEN_TO_C_GtkWidget_(child))));
}
static XEN gxg_gtk_notebook_get_menu_label(XEN notebook, XEN child)
{
  #define H_gtk_notebook_get_menu_label "GtkWidget* gtk_notebook_get_menu_label(GtkNotebook* notebook, \
GtkWidget* child)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_get_menu_label", "GtkNotebook*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_notebook_get_menu_label", "GtkWidget*");
  return(C_TO_XEN_GtkWidget_(gtk_notebook_get_menu_label(XEN_TO_C_GtkNotebook_(notebook), XEN_TO_C_GtkWidget_(child))));
}
static XEN gxg_gtk_notebook_set_menu_label(XEN notebook, XEN child, XEN menu_label)
{
  #define H_gtk_notebook_set_menu_label "void gtk_notebook_set_menu_label(GtkNotebook* notebook, GtkWidget* child, \
GtkWidget* menu_label)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_set_menu_label", "GtkNotebook*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_notebook_set_menu_label", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(menu_label), menu_label, 3, "gtk_notebook_set_menu_label", "GtkWidget*");
  gtk_notebook_set_menu_label(XEN_TO_C_GtkNotebook_(notebook), XEN_TO_C_GtkWidget_(child), XEN_TO_C_GtkWidget_(menu_label));
  return(XEN_FALSE);
}
static XEN gxg_gtk_notebook_set_menu_label_text(XEN notebook, XEN child, XEN menu_text)
{
  #define H_gtk_notebook_set_menu_label_text "void gtk_notebook_set_menu_label_text(GtkNotebook* notebook, \
GtkWidget* child, gchar* menu_text)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_set_menu_label_text", "GtkNotebook*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_notebook_set_menu_label_text", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(menu_text), menu_text, 3, "gtk_notebook_set_menu_label_text", "gchar*");
  gtk_notebook_set_menu_label_text(XEN_TO_C_GtkNotebook_(notebook), XEN_TO_C_GtkWidget_(child), XEN_TO_C_gchar_(menu_text));
  return(XEN_FALSE);
}
static XEN gxg_gtk_notebook_get_menu_label_text(XEN notebook, XEN child)
{
  #define H_gtk_notebook_get_menu_label_text "gchar* gtk_notebook_get_menu_label_text(GtkNotebook* notebook, \
GtkWidget* child)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_get_menu_label_text", "GtkNotebook*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_notebook_get_menu_label_text", "GtkWidget*");
  return(C_TO_XEN_gchar_(gtk_notebook_get_menu_label_text(XEN_TO_C_GtkNotebook_(notebook), XEN_TO_C_GtkWidget_(child))));
}
static XEN gxg_gtk_notebook_query_tab_label_packing(XEN notebook, XEN child, XEN expand, XEN fill, XEN pack_type)
{
  #define H_gtk_notebook_query_tab_label_packing "void gtk_notebook_query_tab_label_packing(GtkNotebook* notebook, \
GtkWidget* child, gboolean* [expand], gboolean* [fill], GtkPackType* [pack_type])"
  gboolean ref_expand;
  gboolean ref_fill;
  GtkPackType ref_pack_type;
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_query_tab_label_packing", "GtkNotebook*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_notebook_query_tab_label_packing", "GtkWidget*");
  gtk_notebook_query_tab_label_packing(XEN_TO_C_GtkNotebook_(notebook), XEN_TO_C_GtkWidget_(child), &ref_expand, &ref_fill, 
                                       &ref_pack_type);
  return(XEN_LIST_3(C_TO_XEN_gboolean(ref_expand), C_TO_XEN_gboolean(ref_fill), C_TO_XEN_GtkPackType(ref_pack_type)));
}
static XEN gxg_gtk_notebook_set_tab_label_packing(XEN notebook, XEN child, XEN expand, XEN fill, XEN pack_type)
{
  #define H_gtk_notebook_set_tab_label_packing "void gtk_notebook_set_tab_label_packing(GtkNotebook* notebook, \
GtkWidget* child, gboolean expand, gboolean fill, GtkPackType pack_type)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_set_tab_label_packing", "GtkNotebook*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_notebook_set_tab_label_packing", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(expand), expand, 3, "gtk_notebook_set_tab_label_packing", "gboolean");
  XEN_ASSERT_TYPE(XEN_gboolean_P(fill), fill, 4, "gtk_notebook_set_tab_label_packing", "gboolean");
  XEN_ASSERT_TYPE(XEN_GtkPackType_P(pack_type), pack_type, 5, "gtk_notebook_set_tab_label_packing", "GtkPackType");
  gtk_notebook_set_tab_label_packing(XEN_TO_C_GtkNotebook_(notebook), XEN_TO_C_GtkWidget_(child), XEN_TO_C_gboolean(expand), 
                                     XEN_TO_C_gboolean(fill), XEN_TO_C_GtkPackType(pack_type));
  return(XEN_FALSE);
}
static XEN gxg_gtk_notebook_reorder_child(XEN notebook, XEN child, XEN position)
{
  #define H_gtk_notebook_reorder_child "void gtk_notebook_reorder_child(GtkNotebook* notebook, GtkWidget* child, \
gint position)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_reorder_child", "GtkNotebook*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_notebook_reorder_child", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gint_P(position), position, 3, "gtk_notebook_reorder_child", "gint");
  gtk_notebook_reorder_child(XEN_TO_C_GtkNotebook_(notebook), XEN_TO_C_GtkWidget_(child), XEN_TO_C_gint(position));
  return(XEN_FALSE);
}
static XEN gxg_GTK_OBJECT_TYPE_NAME(XEN object)
{
  #define H_GTK_OBJECT_TYPE_NAME "char* GTK_OBJECT_TYPE_NAME(GtkObject* object)"
  XEN_ASSERT_TYPE(XEN_GtkObject__P(object), object, 1, "GTK_OBJECT_TYPE_NAME", "GtkObject*");
  return(C_TO_XEN_char_(GTK_OBJECT_TYPE_NAME(XEN_TO_C_GtkObject_(object))));
}
static XEN gxg_GTK_OBJECT_FLAGS(XEN obj)
{
  #define H_GTK_OBJECT_FLAGS "int GTK_OBJECT_FLAGS(GtkObject* obj)"
  XEN_ASSERT_TYPE(XEN_GtkObject__P(obj), obj, 1, "GTK_OBJECT_FLAGS", "GtkObject*");
  return(C_TO_XEN_int(GTK_OBJECT_FLAGS(XEN_TO_C_GtkObject_(obj))));
}
static XEN gxg_GTK_OBJECT_FLOATING(XEN obj)
{
  #define H_GTK_OBJECT_FLOATING "gboolean GTK_OBJECT_FLOATING(GtkObject* obj)"
  XEN_ASSERT_TYPE(XEN_GtkObject__P(obj), obj, 1, "GTK_OBJECT_FLOATING", "GtkObject*");
  return(C_TO_XEN_gboolean(GTK_OBJECT_FLOATING(XEN_TO_C_GtkObject_(obj))));
}
static XEN gxg_GTK_OBJECT_SET_FLAGS(XEN obj, XEN flag)
{
  #define H_GTK_OBJECT_SET_FLAGS "void GTK_OBJECT_SET_FLAGS(GtkObject* obj, int flag)"
  XEN_ASSERT_TYPE(XEN_GtkObject__P(obj), obj, 1, "GTK_OBJECT_SET_FLAGS", "GtkObject*");
  XEN_ASSERT_TYPE(XEN_int_P(flag), flag, 2, "GTK_OBJECT_SET_FLAGS", "int");
  GTK_OBJECT_SET_FLAGS(XEN_TO_C_GtkObject_(obj), XEN_TO_C_int(flag));
  return(XEN_FALSE);
}
static XEN gxg_GTK_OBJECT_UNSET_FLAGS(XEN obj, XEN flag)
{
  #define H_GTK_OBJECT_UNSET_FLAGS "void GTK_OBJECT_UNSET_FLAGS(GtkObject* obj, int flag)"
  XEN_ASSERT_TYPE(XEN_GtkObject__P(obj), obj, 1, "GTK_OBJECT_UNSET_FLAGS", "GtkObject*");
  XEN_ASSERT_TYPE(XEN_int_P(flag), flag, 2, "GTK_OBJECT_UNSET_FLAGS", "int");
  GTK_OBJECT_UNSET_FLAGS(XEN_TO_C_GtkObject_(obj), XEN_TO_C_int(flag));
  return(XEN_FALSE);
}
static XEN gxg_gtk_object_get_type(void)
{
  #define H_gtk_object_get_type "GtkType gtk_object_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_object_get_type()));
}
static XEN gxg_gtk_object_sink(XEN object)
{
  #define H_gtk_object_sink "void gtk_object_sink(GtkObject* object)"
  XEN_ASSERT_TYPE(XEN_GtkObject__P(object), object, 1, "gtk_object_sink", "GtkObject*");
  gtk_object_sink(XEN_TO_C_GtkObject_(object));
  return(XEN_FALSE);
}
static XEN gxg_gtk_object_destroy(XEN object)
{
  #define H_gtk_object_destroy "void gtk_object_destroy(GtkObject* object)"
  XEN_ASSERT_TYPE(XEN_GtkObject__P(object), object, 1, "gtk_object_destroy", "GtkObject*");
  gtk_object_destroy(XEN_TO_C_GtkObject_(object));
  return(XEN_FALSE);
}
