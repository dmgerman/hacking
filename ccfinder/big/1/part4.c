static XEN gxg_styles(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(ptr), ptr, XEN_ONLY_ARG, "styles", "GtkStyle");
  return(C_TO_XEN_GSList_((GSList*)((XEN_TO_C_GtkStyle_(ptr))->styles)));
}

static XEN gxg_property_cache(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(ptr), ptr, XEN_ONLY_ARG, "property_cache", "GtkStyle");
  return(C_TO_XEN_GArray_((GArray*)((XEN_TO_C_GtkStyle_(ptr))->property_cache)));
}

static XEN gxg_icon_factories(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(ptr), ptr, XEN_ONLY_ARG, "icon_factories", "GtkStyle");
  return(C_TO_XEN_GSList_((GSList*)((XEN_TO_C_GtkStyle_(ptr))->icon_factories)));
}

static XEN gxg_saved_state(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(ptr), ptr, XEN_ONLY_ARG, "saved_state", "GtkWidget");
  return(C_TO_XEN_guint8((guint8)((XEN_TO_C_GtkWidget_(ptr))->saved_state)));
}

static XEN gxg_style(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(ptr), ptr, XEN_ONLY_ARG, "style", "GtkWidget");
  return(C_TO_XEN_GtkStyle_((GtkStyle*)((XEN_TO_C_GtkWidget_(ptr))->style)));
}

gxg_static XEN gxg_parent(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(ptr), ptr, XEN_ONLY_ARG, "parent", "GtkWidget");
  return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkWidget_(ptr))->parent)));
}

gxg_static XEN gxg_pixel(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkColor__P(ptr), ptr, XEN_ONLY_ARG, "pixel", "GdkColor");
  return(C_TO_XEN_guint32((guint32)((XEN_TO_C_GdkColor_(ptr))->pixel)));
}

gxg_static XEN gxg_red(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkColor__P(ptr), ptr, XEN_ONLY_ARG, "red", "GdkColor");
  return(C_TO_XEN_guint16((guint16)((XEN_TO_C_GdkColor_(ptr))->red)));
}

gxg_static XEN gxg_green(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkColor__P(ptr), ptr, XEN_ONLY_ARG, "green", "GdkColor");
  return(C_TO_XEN_guint16((guint16)((XEN_TO_C_GdkColor_(ptr))->green)));
}

gxg_static XEN gxg_blue(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkColor__P(ptr), ptr, XEN_ONLY_ARG, "blue", "GdkColor");
  return(C_TO_XEN_guint16((guint16)((XEN_TO_C_GdkColor_(ptr))->blue)));
}

static XEN gxg_value(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(ptr), ptr, XEN_ONLY_ARG, "value", "GtkAdjustment");
  return(C_TO_XEN_gdouble((gdouble)((XEN_TO_C_GtkAdjustment_(ptr))->value)));
}

gxg_static XEN gxg_set_pixel(XEN ptr, XEN val)
{
  XEN_ASSERT_TYPE(XEN_GdkColor__P(ptr), ptr, XEN_ARG_1, "pixel", "GdkColor");
  (XEN_TO_C_GdkColor_(ptr))->pixel = XEN_TO_C_guint32(val);
  return(val);
}

gxg_static XEN gxg_set_red(XEN ptr, XEN val)
{
  XEN_ASSERT_TYPE(XEN_GdkColor__P(ptr), ptr, XEN_ARG_1, "red", "GdkColor");
  (XEN_TO_C_GdkColor_(ptr))->red = XEN_TO_C_guint16(val);
  return(val);
}

gxg_static XEN gxg_set_green(XEN ptr, XEN val)
{
  XEN_ASSERT_TYPE(XEN_GdkColor__P(ptr), ptr, XEN_ARG_1, "green", "GdkColor");
  (XEN_TO_C_GdkColor_(ptr))->green = XEN_TO_C_guint16(val);
  return(val);
}

gxg_static XEN gxg_set_blue(XEN ptr, XEN val)
{
  XEN_ASSERT_TYPE(XEN_GdkColor__P(ptr), ptr, XEN_ARG_1, "blue", "GdkColor");
  (XEN_TO_C_GdkColor_(ptr))->blue = XEN_TO_C_guint16(val);
  return(val);
}

static XEN gxg_set_value(XEN ptr, XEN val)
{
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(ptr), ptr, XEN_ARG_1, "value", "GtkAdjustment");
  (XEN_TO_C_GtkAdjustment_(ptr))->value = XEN_TO_C_gdouble(val);
  return(val);
}
static XEN gxg_make_GdkColor(XEN arglist)
{
  GdkColor* result;
  int i, len;
  result = (GdkColor*)CALLOC(1, sizeof(GdkColor));
  len = XEN_LIST_LENGTH(arglist);
  for (i = 0; i < len; i++)
    switch (i)
      {
      case 0: result->pixel = XEN_TO_C_guint32(XEN_LIST_REF(arglist, 0));
      case 1: result->red = XEN_TO_C_guint16(XEN_LIST_REF(arglist, 1));
      case 2: result->green = XEN_TO_C_guint16(XEN_LIST_REF(arglist, 2));
      case 3: result->blue = XEN_TO_C_guint16(XEN_LIST_REF(arglist, 3));
      }
  return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("GdkColor_"), C_TO_XEN_ULONG((unsigned long)result), make_xm_obj(result)));
}

static XEN gxg_make_GdkCursor(XEN arglist)
{
  GdkCursor* result;
  int i, len;
  result = (GdkCursor*)CALLOC(1, sizeof(GdkCursor));
  len = XEN_LIST_LENGTH(arglist);
  for (i = 0; i < len; i++)
    switch (i)
      {
      case 0: result->type = XEN_TO_C_GdkCursorType(XEN_LIST_REF(arglist, 0));
      case 1: result->ref_count = XEN_TO_C_guint(XEN_LIST_REF(arglist, 1));
      }
  return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("GdkCursor_"), C_TO_XEN_ULONG((unsigned long)result), make_xm_obj(result)));
}

static XEN gxg_make_GdkPoint(XEN arglist)
{
  GdkPoint* result;
  int i, len;
  result = (GdkPoint*)CALLOC(1, sizeof(GdkPoint));
  len = XEN_LIST_LENGTH(arglist);
  for (i = 0; i < len; i++)
    switch (i)
      {
      case 0: result->x = XEN_TO_C_gint(XEN_LIST_REF(arglist, 0));
      case 1: result->y = XEN_TO_C_gint(XEN_LIST_REF(arglist, 1));
      }
  return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("GdkPoint_"), C_TO_XEN_ULONG((unsigned long)result), make_xm_obj(result)));
}

static XEN gxg_make_GdkRectangle(XEN arglist)
{
  GdkRectangle* result;
  int i, len;
  result = (GdkRectangle*)CALLOC(1, sizeof(GdkRectangle));
  len = XEN_LIST_LENGTH(arglist);
  for (i = 0; i < len; i++)
    switch (i)
      {
      case 0: result->x = XEN_TO_C_gint(XEN_LIST_REF(arglist, 0));
      case 1: result->y = XEN_TO_C_gint(XEN_LIST_REF(arglist, 1));
      case 2: result->width = XEN_TO_C_gint(XEN_LIST_REF(arglist, 2));
      case 3: result->height = XEN_TO_C_gint(XEN_LIST_REF(arglist, 3));
      }
  return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("GdkRectangle_"), C_TO_XEN_ULONG((unsigned long)result), make_xm_obj(result)));
}

static XEN gxg_make_GtkStockItem(void)
{
  GtkStockItem* result;
  result = (GtkStockItem*)CALLOC(1, sizeof(GtkStockItem));
  return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("GtkStockItem_"), C_TO_XEN_ULONG((unsigned long)result), make_xm_obj(result)));
}

static XEN gxg_make_GtkTextIter(void)
{
  GtkTextIter* result;
  result = (GtkTextIter*)CALLOC(1, sizeof(GtkTextIter));
  return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("GtkTextIter_"), C_TO_XEN_ULONG((unsigned long)result), make_xm_obj(result)));
}

static XEN gxg_make_GtkTreeIter(void)
{
  GtkTreeIter* result;
  result = (GtkTreeIter*)CALLOC(1, sizeof(GtkTreeIter));
  return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("GtkTreeIter_"), C_TO_XEN_ULONG((unsigned long)result), make_xm_obj(result)));
}

static XEN gxg_make_GtkRequisition(XEN arglist)
{
  GtkRequisition* result;
  int i, len;
  result = (GtkRequisition*)CALLOC(1, sizeof(GtkRequisition));
  len = XEN_LIST_LENGTH(arglist);
  for (i = 0; i < len; i++)
    switch (i)
      {
      case 0: result->width = XEN_TO_C_gint(XEN_LIST_REF(arglist, 0));
      case 1: result->height = XEN_TO_C_gint(XEN_LIST_REF(arglist, 1));
      }
  return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("GtkRequisition_"), C_TO_XEN_ULONG((unsigned long)result), make_xm_obj(result)));
}

static XEN gxg_make_PangoColor(void)
{
  PangoColor* result;
  result = (PangoColor*)CALLOC(1, sizeof(PangoColor));
  return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("PangoColor_"), C_TO_XEN_ULONG((unsigned long)result), make_xm_obj(result)));
}

static XEN gxg_make_PangoRectangle(void)
{
  PangoRectangle* result;
  result = (PangoRectangle*)CALLOC(1, sizeof(PangoRectangle));
  return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("PangoRectangle_"), C_TO_XEN_ULONG((unsigned long)result), make_xm_obj(result)));
}

static XEN gxg_make_PangoLogAttr(void)
{
  PangoLogAttr* result;
  result = (PangoLogAttr*)CALLOC(1, sizeof(PangoLogAttr));
  return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("PangoLogAttr_"), C_TO_XEN_ULONG((unsigned long)result), make_xm_obj(result)));
}


/* -------------------------------- predefined Atoms -------------------------------- */

static void define_atoms(void)
{
#if HAVE_GUILE
#if HAVE_SCM_C_DEFINE
  #define DEFINE_ATOM(Name) scm_permanent_object(scm_c_define(XG_PRE #Name XG_POST, C_TO_XEN_GdkAtom(Name)))
#else
  #define DEFINE_ATOM(Name) gh_define(XG_PRE #Name XG_POST, C_TO_XEN_GdkAtom(Name))
#endif
#else
  #define DEFINE_ATOM(Name) rb_define_global_const(XG_PRE #Name XG_POST, C_TO_XEN_GdkAtom(Name))
#endif

  DEFINE_ATOM(GDK_SELECTION_PRIMARY);
  DEFINE_ATOM(GDK_SELECTION_SECONDARY);
  DEFINE_ATOM(GDK_SELECTION_CLIPBOARD);
  DEFINE_ATOM(GDK_TARGET_BITMAP);
  DEFINE_ATOM(GDK_TARGET_COLORMAP);
  DEFINE_ATOM(GDK_TARGET_DRAWABLE);
  DEFINE_ATOM(GDK_TARGET_PIXMAP);
  DEFINE_ATOM(GDK_TARGET_STRING);
  DEFINE_ATOM(GDK_SELECTION_TYPE_ATOM);
  DEFINE_ATOM(GDK_SELECTION_TYPE_BITMAP);
  DEFINE_ATOM(GDK_SELECTION_TYPE_COLORMAP);
  DEFINE_ATOM(GDK_SELECTION_TYPE_DRAWABLE);
  DEFINE_ATOM(GDK_SELECTION_TYPE_INTEGER);
  DEFINE_ATOM(GDK_SELECTION_TYPE_PIXMAP);
  DEFINE_ATOM(GDK_SELECTION_TYPE_WINDOW);
  DEFINE_ATOM(GDK_SELECTION_TYPE_STRING);
  DEFINE_ATOM(GDK_NONE);
}

/* -------------------------------- strings -------------------------------- */

static void define_strings(void)
{
  
#if HAVE_GUILE
#if HAVE_SCM_C_DEFINE
  #define DEFINE_STRING(Name) scm_c_define(XG_PRE #Name XG_POST, C_TO_XEN_STRING(Name))
#else
  #define DEFINE_STRING(Name) gh_define(XG_PRE #Name XG_POST, C_TO_XEN_STRING(Name))
#endif
#else
  #define DEFINE_STRING(Name) rb_define_global_const(XG_PRE #Name XG_POST, C_TO_XEN_STRING(Name))
#endif
  DEFINE_STRING(GDK_PIXBUF_VERSION);
  DEFINE_STRING(GTK_STOCK_DIALOG_INFO);
  DEFINE_STRING(GTK_STOCK_DIALOG_WARNING);
  DEFINE_STRING(GTK_STOCK_DIALOG_ERROR);
  DEFINE_STRING(GTK_STOCK_DIALOG_QUESTION);
  DEFINE_STRING(GTK_STOCK_DND);
  DEFINE_STRING(GTK_STOCK_DND_MULTIPLE);
  DEFINE_STRING(GTK_STOCK_ADD);
  DEFINE_STRING(GTK_STOCK_APPLY);
  DEFINE_STRING(GTK_STOCK_BOLD);
  DEFINE_STRING(GTK_STOCK_CANCEL);
  DEFINE_STRING(GTK_STOCK_CDROM);
  DEFINE_STRING(GTK_STOCK_CLEAR);
  DEFINE_STRING(GTK_STOCK_CLOSE);
  DEFINE_STRING(GTK_STOCK_CONVERT);
  DEFINE_STRING(GTK_STOCK_COPY);
  DEFINE_STRING(GTK_STOCK_CUT);
  DEFINE_STRING(GTK_STOCK_DELETE);
  DEFINE_STRING(GTK_STOCK_EXECUTE);
  DEFINE_STRING(GTK_STOCK_FIND);
  DEFINE_STRING(GTK_STOCK_FIND_AND_REPLACE);
  DEFINE_STRING(GTK_STOCK_FLOPPY);
  DEFINE_STRING(GTK_STOCK_GOTO_BOTTOM);
  DEFINE_STRING(GTK_STOCK_GOTO_FIRST);
  DEFINE_STRING(GTK_STOCK_GOTO_LAST);
  DEFINE_STRING(GTK_STOCK_GOTO_TOP);
  DEFINE_STRING(GTK_STOCK_GO_BACK);
  DEFINE_STRING(GTK_STOCK_GO_DOWN);
  DEFINE_STRING(GTK_STOCK_GO_FORWARD);
  DEFINE_STRING(GTK_STOCK_GO_UP);
  DEFINE_STRING(GTK_STOCK_HELP);
  DEFINE_STRING(GTK_STOCK_HOME);
  DEFINE_STRING(GTK_STOCK_INDEX);
  DEFINE_STRING(GTK_STOCK_ITALIC);
  DEFINE_STRING(GTK_STOCK_JUMP_TO);
  DEFINE_STRING(GTK_STOCK_JUSTIFY_CENTER);
  DEFINE_STRING(GTK_STOCK_JUSTIFY_FILL);
  DEFINE_STRING(GTK_STOCK_JUSTIFY_LEFT);
  DEFINE_STRING(GTK_STOCK_JUSTIFY_RIGHT);
  DEFINE_STRING(GTK_STOCK_MISSING_IMAGE);
  DEFINE_STRING(GTK_STOCK_NEW);
  DEFINE_STRING(GTK_STOCK_NO);
  DEFINE_STRING(GTK_STOCK_OK);
  DEFINE_STRING(GTK_STOCK_OPEN);
  DEFINE_STRING(GTK_STOCK_PASTE);
  DEFINE_STRING(GTK_STOCK_PREFERENCES);
  DEFINE_STRING(GTK_STOCK_PRINT);
  DEFINE_STRING(GTK_STOCK_PRINT_PREVIEW);
  DEFINE_STRING(GTK_STOCK_PROPERTIES);
  DEFINE_STRING(GTK_STOCK_QUIT);
  DEFINE_STRING(GTK_STOCK_REDO);
  DEFINE_STRING(GTK_STOCK_REFRESH);
  DEFINE_STRING(GTK_STOCK_REMOVE);
  DEFINE_STRING(GTK_STOCK_REVERT_TO_SAVED);
  DEFINE_STRING(GTK_STOCK_SAVE);
  DEFINE_STRING(GTK_STOCK_SAVE_AS);
  DEFINE_STRING(GTK_STOCK_SELECT_COLOR);
  DEFINE_STRING(GTK_STOCK_SELECT_FONT);
  DEFINE_STRING(GTK_STOCK_SORT_ASCENDING);
  DEFINE_STRING(GTK_STOCK_SORT_DESCENDING);
  DEFINE_STRING(GTK_STOCK_SPELL_CHECK);
  DEFINE_STRING(GTK_STOCK_STOP);
  DEFINE_STRING(GTK_STOCK_STRIKETHROUGH);
  DEFINE_STRING(GTK_STOCK_UNDELETE);
  DEFINE_STRING(GTK_STOCK_UNDERLINE);
  DEFINE_STRING(GTK_STOCK_UNDO);
  DEFINE_STRING(GTK_STOCK_YES);
  DEFINE_STRING(GTK_STOCK_ZOOM_100);
  DEFINE_STRING(GTK_STOCK_ZOOM_FIT);
  DEFINE_STRING(GTK_STOCK_ZOOM_IN);
  DEFINE_STRING(GTK_STOCK_ZOOM_OUT);
#if HAVE_GTK_MENU_SHELL_CANCEL
  DEFINE_STRING(GTK_STOCK_COLOR_PICKER);
  DEFINE_STRING(GTK_STOCK_HARDDISK);
  DEFINE_STRING(GTK_STOCK_INDENT);
  DEFINE_STRING(GTK_STOCK_UNINDENT);
#endif

#if HAVE_GTK_COMBO_BOX_POPUP
  DEFINE_STRING(GTK_STOCK_NETWORK);
#endif

#if HAVE_GTK_ABOUT_DIALOG_NEW
  DEFINE_STRING(GTK_STOCK_ABOUT);
  DEFINE_STRING(GTK_STOCK_CONNECT);
  DEFINE_STRING(GTK_STOCK_DIRECTORY);
  DEFINE_STRING(GTK_STOCK_DISCONNECT);
  DEFINE_STRING(GTK_STOCK_EDIT);
  DEFINE_STRING(GTK_STOCK_FILE);
  DEFINE_STRING(GTK_STOCK_MEDIA_FORWARD);
  DEFINE_STRING(GTK_STOCK_MEDIA_NEXT);
  DEFINE_STRING(GTK_STOCK_MEDIA_PAUSE);
  DEFINE_STRING(GTK_STOCK_MEDIA_PLAY);
  DEFINE_STRING(GTK_STOCK_MEDIA_PREVIOUS);
  DEFINE_STRING(GTK_STOCK_MEDIA_RECORD);
  DEFINE_STRING(GTK_STOCK_MEDIA_REWIND);
  DEFINE_STRING(GTK_STOCK_MEDIA_STOP);
#endif

}

/* -------------------------------- initialization -------------------------------- */

static bool xg_already_inited = false;

#if WITH_GTK_AND_X11
#if HAVE_GUILE
 void init_x11(void);
#else
 void Init_libx11(void);
#endif
#endif

#if HAVE_GUILE
 void init_xm(void);
 void init_xm(void)
#else
 void Init_libxm(void);
 void Init_libxm(void)
#endif
{
  if (!xg_already_inited)
    {
      define_xm_obj();
      define_integers();
      define_doubles();
      define_functions();
      define_structs();
      define_atoms();
      define_strings();
      XEN_YES_WE_HAVE("xg");
#if HAVE_GUILE
      XEN_EVAL_C_STRING("(define xm-version \"14-Nov-04\")");
#endif
#if HAVE_RUBY
      rb_define_global_const("Xm_Version", C_TO_XEN_STRING("14-Nov-04"));
#endif
      xg_already_inited = true;
#if WITH_GTK_AND_X11
#if HAVE_GUILE
      init_x11();
#else
      Init_libx11();
#endif
#endif

    }
}
