static XEN gxg_gtk_alignment_set_padding(XEN alignment, XEN padding_top, XEN padding_bottom, XEN padding_left, XEN padding_right)
{
  #define H_gtk_alignment_set_padding "void gtk_alignment_set_padding(GtkAlignment* alignment, guint padding_top, \
guint padding_bottom, guint padding_left, guint padding_right)"
  XEN_ASSERT_TYPE(XEN_GtkAlignment__P(alignment), alignment, 1, "gtk_alignment_set_padding", "GtkAlignment*");
  XEN_ASSERT_TYPE(XEN_guint_P(padding_top), padding_top, 2, "gtk_alignment_set_padding", "guint");
  XEN_ASSERT_TYPE(XEN_guint_P(padding_bottom), padding_bottom, 3, "gtk_alignment_set_padding", "guint");
  XEN_ASSERT_TYPE(XEN_guint_P(padding_left), padding_left, 4, "gtk_alignment_set_padding", "guint");
  XEN_ASSERT_TYPE(XEN_guint_P(padding_right), padding_right, 5, "gtk_alignment_set_padding", "guint");
  gtk_alignment_set_padding(XEN_TO_C_GtkAlignment_(alignment), XEN_TO_C_guint(padding_top), XEN_TO_C_guint(padding_bottom), 
                            XEN_TO_C_guint(padding_left), XEN_TO_C_guint(padding_right));
  return(XEN_FALSE);
}
static XEN gxg_gtk_alignment_get_padding(XEN alignment, XEN padding_top, XEN padding_bottom, XEN padding_left, XEN padding_right)
{
  #define H_gtk_alignment_get_padding "void gtk_alignment_get_padding(GtkAlignment* alignment, guint* [padding_top], \
guint* [padding_bottom], guint* [padding_left], guint* [padding_right])"
  guint ref_padding_top;
  guint ref_padding_bottom;
  guint ref_padding_left;
  guint ref_padding_right;
  XEN_ASSERT_TYPE(XEN_GtkAlignment__P(alignment), alignment, 1, "gtk_alignment_get_padding", "GtkAlignment*");
  gtk_alignment_get_padding(XEN_TO_C_GtkAlignment_(alignment), &ref_padding_top, &ref_padding_bottom, &ref_padding_left, 
                            &ref_padding_right);
  return(XEN_LIST_4(C_TO_XEN_guint(ref_padding_top), C_TO_XEN_guint(ref_padding_bottom), C_TO_XEN_guint(ref_padding_left), C_TO_XEN_guint(ref_padding_right)));
}
static XEN gxg_gtk_button_box_get_child_secondary(XEN widget, XEN child)
{
  #define H_gtk_button_box_get_child_secondary "gboolean gtk_button_box_get_child_secondary(GtkButtonBox* widget, \
GtkWidget* child)"
  XEN_ASSERT_TYPE(XEN_GtkButtonBox__P(widget), widget, 1, "gtk_button_box_get_child_secondary", "GtkButtonBox*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_button_box_get_child_secondary", "GtkWidget*");
  return(C_TO_XEN_gboolean(gtk_button_box_get_child_secondary(XEN_TO_C_GtkButtonBox_(widget), XEN_TO_C_GtkWidget_(child))));
}
static XEN gxg_gtk_button_set_focus_on_click(XEN button, XEN focus_on_click)
{
  #define H_gtk_button_set_focus_on_click "void gtk_button_set_focus_on_click(GtkButton* button, gboolean focus_on_click)"
  XEN_ASSERT_TYPE(XEN_GtkButton__P(button), button, 1, "gtk_button_set_focus_on_click", "GtkButton*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(focus_on_click), focus_on_click, 2, "gtk_button_set_focus_on_click", "gboolean");
  gtk_button_set_focus_on_click(XEN_TO_C_GtkButton_(button), XEN_TO_C_gboolean(focus_on_click));
  return(XEN_FALSE);
}
static XEN gxg_gtk_button_get_focus_on_click(XEN button)
{
  #define H_gtk_button_get_focus_on_click "gboolean gtk_button_get_focus_on_click(GtkButton* button)"
  XEN_ASSERT_TYPE(XEN_GtkButton__P(button), button, 1, "gtk_button_get_focus_on_click", "GtkButton*");
  return(C_TO_XEN_gboolean(gtk_button_get_focus_on_click(XEN_TO_C_GtkButton_(button))));
}
static XEN gxg_gtk_calendar_set_display_options(XEN calendar, XEN flags)
{
  #define H_gtk_calendar_set_display_options "void gtk_calendar_set_display_options(GtkCalendar* calendar, \
GtkCalendarDisplayOptions flags)"
  XEN_ASSERT_TYPE(XEN_GtkCalendar__P(calendar), calendar, 1, "gtk_calendar_set_display_options", "GtkCalendar*");
  XEN_ASSERT_TYPE(XEN_GtkCalendarDisplayOptions_P(flags), flags, 2, "gtk_calendar_set_display_options", "GtkCalendarDisplayOptions");
  gtk_calendar_set_display_options(XEN_TO_C_GtkCalendar_(calendar), XEN_TO_C_GtkCalendarDisplayOptions(flags));
  return(XEN_FALSE);
}
static XEN gxg_gtk_calendar_get_display_options(XEN calendar)
{
  #define H_gtk_calendar_get_display_options "GtkCalendarDisplayOptions gtk_calendar_get_display_options(GtkCalendar* calendar)"
  XEN_ASSERT_TYPE(XEN_GtkCalendar__P(calendar), calendar, 1, "gtk_calendar_get_display_options", "GtkCalendar*");
  return(C_TO_XEN_GtkCalendarDisplayOptions(gtk_calendar_get_display_options(XEN_TO_C_GtkCalendar_(calendar))));
}
static XEN gxg_gtk_check_menu_item_set_draw_as_radio(XEN check_menu_item, XEN draw_as_radio)
{
  #define H_gtk_check_menu_item_set_draw_as_radio "void gtk_check_menu_item_set_draw_as_radio(GtkCheckMenuItem* check_menu_item, \
gboolean draw_as_radio)"
  XEN_ASSERT_TYPE(XEN_GtkCheckMenuItem__P(check_menu_item), check_menu_item, 1, "gtk_check_menu_item_set_draw_as_radio", "GtkCheckMenuItem*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(draw_as_radio), draw_as_radio, 2, "gtk_check_menu_item_set_draw_as_radio", "gboolean");
  gtk_check_menu_item_set_draw_as_radio(XEN_TO_C_GtkCheckMenuItem_(check_menu_item), XEN_TO_C_gboolean(draw_as_radio));
  return(XEN_FALSE);
}
static XEN gxg_gtk_check_menu_item_get_draw_as_radio(XEN check_menu_item)
{
  #define H_gtk_check_menu_item_get_draw_as_radio "gboolean gtk_check_menu_item_get_draw_as_radio(GtkCheckMenuItem* check_menu_item)"
  XEN_ASSERT_TYPE(XEN_GtkCheckMenuItem__P(check_menu_item), check_menu_item, 1, "gtk_check_menu_item_get_draw_as_radio", "GtkCheckMenuItem*");
  return(C_TO_XEN_gboolean(gtk_check_menu_item_get_draw_as_radio(XEN_TO_C_GtkCheckMenuItem_(check_menu_item))));
}
static XEN gxg_gtk_entry_set_completion(XEN entry, XEN completion)
{
  #define H_gtk_entry_set_completion "void gtk_entry_set_completion(GtkEntry* entry, GtkEntryCompletion* completion)"
  XEN_ASSERT_TYPE(XEN_GtkEntry__P(entry), entry, 1, "gtk_entry_set_completion", "GtkEntry*");
  XEN_ASSERT_TYPE(XEN_GtkEntryCompletion__P(completion), completion, 2, "gtk_entry_set_completion", "GtkEntryCompletion*");
  gtk_entry_set_completion(XEN_TO_C_GtkEntry_(entry), XEN_TO_C_GtkEntryCompletion_(completion));
  return(XEN_FALSE);
}
static XEN gxg_gtk_entry_get_completion(XEN entry)
{
  #define H_gtk_entry_get_completion "GtkEntryCompletion* gtk_entry_get_completion(GtkEntry* entry)"
  XEN_ASSERT_TYPE(XEN_GtkEntry__P(entry), entry, 1, "gtk_entry_get_completion", "GtkEntry*");
  return(C_TO_XEN_GtkEntryCompletion_(gtk_entry_get_completion(XEN_TO_C_GtkEntry_(entry))));
}
static XEN gxg_gtk_event_box_get_visible_window(XEN event_box)
{
  #define H_gtk_event_box_get_visible_window "gboolean gtk_event_box_get_visible_window(GtkEventBox* event_box)"
  XEN_ASSERT_TYPE(XEN_GtkEventBox__P(event_box), event_box, 1, "gtk_event_box_get_visible_window", "GtkEventBox*");
  return(C_TO_XEN_gboolean(gtk_event_box_get_visible_window(XEN_TO_C_GtkEventBox_(event_box))));
}
static XEN gxg_gtk_event_box_set_visible_window(XEN event_box, XEN visible_window)
{
  #define H_gtk_event_box_set_visible_window "void gtk_event_box_set_visible_window(GtkEventBox* event_box, \
gboolean visible_window)"
  XEN_ASSERT_TYPE(XEN_GtkEventBox__P(event_box), event_box, 1, "gtk_event_box_set_visible_window", "GtkEventBox*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(visible_window), visible_window, 2, "gtk_event_box_set_visible_window", "gboolean");
  gtk_event_box_set_visible_window(XEN_TO_C_GtkEventBox_(event_box), XEN_TO_C_gboolean(visible_window));
  return(XEN_FALSE);
}
static XEN gxg_gtk_event_box_get_above_child(XEN event_box)
{
  #define H_gtk_event_box_get_above_child "gboolean gtk_event_box_get_above_child(GtkEventBox* event_box)"
  XEN_ASSERT_TYPE(XEN_GtkEventBox__P(event_box), event_box, 1, "gtk_event_box_get_above_child", "GtkEventBox*");
  return(C_TO_XEN_gboolean(gtk_event_box_get_above_child(XEN_TO_C_GtkEventBox_(event_box))));
}
static XEN gxg_gtk_event_box_set_above_child(XEN event_box, XEN above_child)
{
  #define H_gtk_event_box_set_above_child "void gtk_event_box_set_above_child(GtkEventBox* event_box, \
gboolean above_child)"
  XEN_ASSERT_TYPE(XEN_GtkEventBox__P(event_box), event_box, 1, "gtk_event_box_set_above_child", "GtkEventBox*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(above_child), above_child, 2, "gtk_event_box_set_above_child", "gboolean");
  gtk_event_box_set_above_child(XEN_TO_C_GtkEventBox_(event_box), XEN_TO_C_gboolean(above_child));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_source_get_icon_name(XEN source)
{
  #define H_gtk_icon_source_get_icon_name "gchar* gtk_icon_source_get_icon_name(GtkIconSource* source)"
  XEN_ASSERT_TYPE(XEN_GtkIconSource__P(source), source, 1, "gtk_icon_source_get_icon_name", "GtkIconSource*");
  return(C_TO_XEN_gchar_(gtk_icon_source_get_icon_name(XEN_TO_C_GtkIconSource_(source))));
}
static XEN gxg_gtk_menu_attach(XEN menu, XEN child, XEN left_attach, XEN right_attach, XEN top_attach, XEN bottom_attach)
{
  #define H_gtk_menu_attach "void gtk_menu_attach(GtkMenu* menu, GtkWidget* child, guint left_attach, \
guint right_attach, guint top_attach, guint bottom_attach)"
  XEN_ASSERT_TYPE(XEN_GtkMenu__P(menu), menu, 1, "gtk_menu_attach", "GtkMenu*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_menu_attach", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_guint_P(left_attach), left_attach, 3, "gtk_menu_attach", "guint");
  XEN_ASSERT_TYPE(XEN_guint_P(right_attach), right_attach, 4, "gtk_menu_attach", "guint");
  XEN_ASSERT_TYPE(XEN_guint_P(top_attach), top_attach, 5, "gtk_menu_attach", "guint");
  XEN_ASSERT_TYPE(XEN_guint_P(bottom_attach), bottom_attach, 6, "gtk_menu_attach", "guint");
  gtk_menu_attach(XEN_TO_C_GtkMenu_(menu), XEN_TO_C_GtkWidget_(child), XEN_TO_C_guint(left_attach), XEN_TO_C_guint(right_attach), 
                  XEN_TO_C_guint(top_attach), XEN_TO_C_guint(bottom_attach));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_select_range(XEN buffer, XEN ins, XEN bound)
{
  #define H_gtk_text_buffer_select_range "void gtk_text_buffer_select_range(GtkTextBuffer* buffer, GtkTextIter* ins, \
GtkTextIter* bound)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_select_range", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(ins), ins, 2, "gtk_text_buffer_select_range", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(bound), bound, 3, "gtk_text_buffer_select_range", "GtkTextIter*");
  gtk_text_buffer_select_range(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkTextIter_(ins), XEN_TO_C_GtkTextIter_(bound));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_view_set_overwrite(XEN text_view, XEN overwrite)
{
  #define H_gtk_text_view_set_overwrite "void gtk_text_view_set_overwrite(GtkTextView* text_view, gboolean overwrite)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_set_overwrite", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(overwrite), overwrite, 2, "gtk_text_view_set_overwrite", "gboolean");
  gtk_text_view_set_overwrite(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_gboolean(overwrite));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_view_get_overwrite(XEN text_view)
{
  #define H_gtk_text_view_get_overwrite "gboolean gtk_text_view_get_overwrite(GtkTextView* text_view)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_get_overwrite", "GtkTextView*");
  return(C_TO_XEN_gboolean(gtk_text_view_get_overwrite(XEN_TO_C_GtkTextView_(text_view))));
}
static XEN gxg_gtk_text_view_set_accepts_tab(XEN text_view, XEN accepts_tab)
{
  #define H_gtk_text_view_set_accepts_tab "void gtk_text_view_set_accepts_tab(GtkTextView* text_view, \
gboolean accepts_tab)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_set_accepts_tab", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(accepts_tab), accepts_tab, 2, "gtk_text_view_set_accepts_tab", "gboolean");
  gtk_text_view_set_accepts_tab(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_gboolean(accepts_tab));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_view_get_accepts_tab(XEN text_view)
{
  #define H_gtk_text_view_get_accepts_tab "gboolean gtk_text_view_get_accepts_tab(GtkTextView* text_view)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_get_accepts_tab", "GtkTextView*");
  return(C_TO_XEN_gboolean(gtk_text_view_get_accepts_tab(XEN_TO_C_GtkTextView_(text_view))));
}
static XEN gxg_gtk_toolbar_insert(XEN toolbar, XEN item, XEN pos)
{
  #define H_gtk_toolbar_insert "void gtk_toolbar_insert(GtkToolbar* toolbar, GtkToolItem* item, gint pos)"
  XEN_ASSERT_TYPE(XEN_GtkToolbar__P(toolbar), toolbar, 1, "gtk_toolbar_insert", "GtkToolbar*");
  XEN_ASSERT_TYPE(XEN_GtkToolItem__P(item), item, 2, "gtk_toolbar_insert", "GtkToolItem*");
  XEN_ASSERT_TYPE(XEN_gint_P(pos), pos, 3, "gtk_toolbar_insert", "gint");
  gtk_toolbar_insert(XEN_TO_C_GtkToolbar_(toolbar), XEN_TO_C_GtkToolItem_(item), XEN_TO_C_gint(pos));
  return(XEN_FALSE);
}
static XEN gxg_gtk_toolbar_get_item_index(XEN toolbar, XEN item)
{
  #define H_gtk_toolbar_get_item_index "gint gtk_toolbar_get_item_index(GtkToolbar* toolbar, GtkToolItem* item)"
  XEN_ASSERT_TYPE(XEN_GtkToolbar__P(toolbar), toolbar, 1, "gtk_toolbar_get_item_index", "GtkToolbar*");
  XEN_ASSERT_TYPE(XEN_GtkToolItem__P(item), item, 2, "gtk_toolbar_get_item_index", "GtkToolItem*");
  return(C_TO_XEN_gint(gtk_toolbar_get_item_index(XEN_TO_C_GtkToolbar_(toolbar), XEN_TO_C_GtkToolItem_(item))));
}
static XEN gxg_gtk_toolbar_get_n_items(XEN toolbar)
{
  #define H_gtk_toolbar_get_n_items "gint gtk_toolbar_get_n_items(GtkToolbar* toolbar)"
  XEN_ASSERT_TYPE(XEN_GtkToolbar__P(toolbar), toolbar, 1, "gtk_toolbar_get_n_items", "GtkToolbar*");
  return(C_TO_XEN_gint(gtk_toolbar_get_n_items(XEN_TO_C_GtkToolbar_(toolbar))));
}
static XEN gxg_gtk_toolbar_get_nth_item(XEN toolbar, XEN n)
{
  #define H_gtk_toolbar_get_nth_item "GtkToolItem* gtk_toolbar_get_nth_item(GtkToolbar* toolbar, gint n)"
  XEN_ASSERT_TYPE(XEN_GtkToolbar__P(toolbar), toolbar, 1, "gtk_toolbar_get_nth_item", "GtkToolbar*");
  XEN_ASSERT_TYPE(XEN_gint_P(n), n, 2, "gtk_toolbar_get_nth_item", "gint");
  return(C_TO_XEN_GtkToolItem_(gtk_toolbar_get_nth_item(XEN_TO_C_GtkToolbar_(toolbar), XEN_TO_C_gint(n))));
}
static XEN gxg_gtk_toolbar_set_show_arrow(XEN toolbar, XEN show_arrow)
{
  #define H_gtk_toolbar_set_show_arrow "void gtk_toolbar_set_show_arrow(GtkToolbar* toolbar, gboolean show_arrow)"
  XEN_ASSERT_TYPE(XEN_GtkToolbar__P(toolbar), toolbar, 1, "gtk_toolbar_set_show_arrow", "GtkToolbar*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(show_arrow), show_arrow, 2, "gtk_toolbar_set_show_arrow", "gboolean");
  gtk_toolbar_set_show_arrow(XEN_TO_C_GtkToolbar_(toolbar), XEN_TO_C_gboolean(show_arrow));
  return(XEN_FALSE);
}
static XEN gxg_gtk_toolbar_get_show_arrow(XEN toolbar)
{
  #define H_gtk_toolbar_get_show_arrow "gboolean gtk_toolbar_get_show_arrow(GtkToolbar* toolbar)"
  XEN_ASSERT_TYPE(XEN_GtkToolbar__P(toolbar), toolbar, 1, "gtk_toolbar_get_show_arrow", "GtkToolbar*");
  return(C_TO_XEN_gboolean(gtk_toolbar_get_show_arrow(XEN_TO_C_GtkToolbar_(toolbar))));
}
static XEN gxg_gtk_toolbar_get_relief_style(XEN toolbar)
{
  #define H_gtk_toolbar_get_relief_style "GtkReliefStyle gtk_toolbar_get_relief_style(GtkToolbar* toolbar)"
  XEN_ASSERT_TYPE(XEN_GtkToolbar__P(toolbar), toolbar, 1, "gtk_toolbar_get_relief_style", "GtkToolbar*");
  return(C_TO_XEN_GtkReliefStyle(gtk_toolbar_get_relief_style(XEN_TO_C_GtkToolbar_(toolbar))));
}
static XEN gxg_gtk_toolbar_get_drop_index(XEN toolbar, XEN x, XEN y)
{
  #define H_gtk_toolbar_get_drop_index "gint gtk_toolbar_get_drop_index(GtkToolbar* toolbar, gint x, \
gint y)"
  XEN_ASSERT_TYPE(XEN_GtkToolbar__P(toolbar), toolbar, 1, "gtk_toolbar_get_drop_index", "GtkToolbar*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 2, "gtk_toolbar_get_drop_index", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 3, "gtk_toolbar_get_drop_index", "gint");
  return(C_TO_XEN_gint(gtk_toolbar_get_drop_index(XEN_TO_C_GtkToolbar_(toolbar), XEN_TO_C_gint(x), XEN_TO_C_gint(y))));
}
static XEN gxg_gtk_tree_view_column_set_expand(XEN tree_column, XEN expand)
{
  #define H_gtk_tree_view_column_set_expand "void gtk_tree_view_column_set_expand(GtkTreeViewColumn* tree_column, \
gboolean expand)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_set_expand", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(expand), expand, 2, "gtk_tree_view_column_set_expand", "gboolean");
  gtk_tree_view_column_set_expand(XEN_TO_C_GtkTreeViewColumn_(tree_column), XEN_TO_C_gboolean(expand));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_column_get_expand(XEN tree_column)
{
  #define H_gtk_tree_view_column_get_expand "gboolean gtk_tree_view_column_get_expand(GtkTreeViewColumn* tree_column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_get_expand", "GtkTreeViewColumn*");
  return(C_TO_XEN_gboolean(gtk_tree_view_column_get_expand(XEN_TO_C_GtkTreeViewColumn_(tree_column))));
}
static XEN gxg_gtk_widget_set_no_show_all(XEN widget, XEN no_show_all)
{
  #define H_gtk_widget_set_no_show_all "void gtk_widget_set_no_show_all(GtkWidget* widget, gboolean no_show_all)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_set_no_show_all", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(no_show_all), no_show_all, 2, "gtk_widget_set_no_show_all", "gboolean");
  gtk_widget_set_no_show_all(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gboolean(no_show_all));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_get_no_show_all(XEN widget)
{
  #define H_gtk_widget_get_no_show_all "gboolean gtk_widget_get_no_show_all(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_get_no_show_all", "GtkWidget*");
  return(C_TO_XEN_gboolean(gtk_widget_get_no_show_all(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_widget_queue_resize_no_redraw(XEN widget)
{
  #define H_gtk_widget_queue_resize_no_redraw "void gtk_widget_queue_resize_no_redraw(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_queue_resize_no_redraw", "GtkWidget*");
  gtk_widget_queue_resize_no_redraw(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_set_default_icon(XEN icon)
{
  #define H_gtk_window_set_default_icon "void gtk_window_set_default_icon(GdkPixbuf* icon)"
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(icon), icon, 1, "gtk_window_set_default_icon", "GdkPixbuf*");
  gtk_window_set_default_icon(XEN_TO_C_GdkPixbuf_(icon));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_set_keep_above(XEN window, XEN setting)
{
  #define H_gtk_window_set_keep_above "void gtk_window_set_keep_above(GtkWindow* window, gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_set_keep_above", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gtk_window_set_keep_above", "gboolean");
  gtk_window_set_keep_above(XEN_TO_C_GtkWindow_(window), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_set_keep_below(XEN window, XEN setting)
{
  #define H_gtk_window_set_keep_below "void gtk_window_set_keep_below(GtkWindow* window, gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_set_keep_below", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gtk_window_set_keep_below", "gboolean");
  gtk_window_set_keep_below(XEN_TO_C_GtkWindow_(window), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_file_chooser_dialog_new(XEN title, XEN parent, XEN action, XEN buttons)
{
  #define H_gtk_file_chooser_dialog_new "GtkWidget* gtk_file_chooser_dialog_new(gchar* title, GtkWindow* parent, \
GtkFileChooserAction action, etc buttons)"
  XEN_ASSERT_TYPE(XEN_gchar__P(title), title, 1, "gtk_file_chooser_dialog_new", "gchar*");
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(parent), parent, 2, "gtk_file_chooser_dialog_new", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkFileChooserAction_P(action), action, 3, "gtk_file_chooser_dialog_new", "GtkFileChooserAction");
  if (XEN_NOT_BOUND_P(buttons)) buttons = XEN_FALSE; 
  else XEN_ASSERT_TYPE(XEN_etc_P(buttons), buttons, 4, "gtk_file_chooser_dialog_new", "etc");
  {
    int etc_len = 0;
    GtkWidget* result = NULL;
    gchar* p_arg0;
    GtkWindow* p_arg1;
    GtkFileChooserAction p_arg2;
    if (XEN_LIST_P(buttons)) etc_len = XEN_LIST_LENGTH(buttons);
    if (etc_len > 10) XEN_OUT_OF_RANGE_ERROR("gtk_file_chooser_dialog_new", 3, buttons, "... list too long (max len: 10)");
    if ((etc_len % 2) != 0) XEN_OUT_OF_RANGE_ERROR("gtk_file_chooser_dialog_new", 3, buttons, "... list len must be multiple of 2");
    p_arg0 = XEN_TO_C_gchar_(title);
    p_arg1 = XEN_TO_C_GtkWindow_(parent);
    p_arg2 = XEN_TO_C_GtkFileChooserAction(action);
    switch (etc_len)
      {
        case 0: result = gtk_file_chooser_dialog_new(p_arg0, p_arg1, p_arg2, NULL); break;
        case 2: result = gtk_file_chooser_dialog_new(p_arg0, p_arg1, p_arg2, XLS(buttons, 0), XLI(buttons, 1), NULL); break;
        case 4: result = gtk_file_chooser_dialog_new(p_arg0, p_arg1, p_arg2, XLS(buttons, 0), XLI(buttons, 1), XLS(buttons, 2), XLI(buttons, 3), NULL); break;
        case 6: result = gtk_file_chooser_dialog_new(p_arg0, p_arg1, p_arg2, XLS(buttons, 0), XLI(buttons, 1), XLS(buttons, 2), XLI(buttons, 3), XLS(buttons, 4), XLI(buttons, 5), NULL); break;
        case 8: result = gtk_file_chooser_dialog_new(p_arg0, p_arg1, p_arg2, XLS(buttons, 0), XLI(buttons, 1), XLS(buttons, 2), XLI(buttons, 3), XLS(buttons, 4), XLI(buttons, 5), XLS(buttons, 6), XLI(buttons, 7), NULL); break;
        case 10: result = gtk_file_chooser_dialog_new(p_arg0, p_arg1, p_arg2, XLS(buttons, 0), XLI(buttons, 1), XLS(buttons, 2), XLI(buttons, 3), XLS(buttons, 4), XLI(buttons, 5), XLS(buttons, 6), XLI(buttons, 7), XLS(buttons, 8), XLI(buttons, 9), NULL); break;
      }
    return(C_TO_XEN_GtkWidget_(result));
  }
}
static XEN gxg_gtk_file_chooser_dialog_get_type(void)
{
  #define H_gtk_file_chooser_dialog_get_type "GType gtk_file_chooser_dialog_get_type( void)"
  return(C_TO_XEN_GType(gtk_file_chooser_dialog_get_type()));
}
static XEN gxg_gtk_file_chooser_widget_get_type(void)
{
  #define H_gtk_file_chooser_widget_get_type "GType gtk_file_chooser_widget_get_type( void)"
  return(C_TO_XEN_GType(gtk_file_chooser_widget_get_type()));
}
static XEN gxg_gtk_file_chooser_widget_new(XEN action)
{
  #define H_gtk_file_chooser_widget_new "GtkWidget* gtk_file_chooser_widget_new(GtkFileChooserAction action)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooserAction_P(action), action, 1, "gtk_file_chooser_widget_new", "GtkFileChooserAction");
  return(C_TO_XEN_GtkWidget_(gtk_file_chooser_widget_new(XEN_TO_C_GtkFileChooserAction(action))));
}
static XEN gxg_gtk_tree_model_filter_get_type(void)
{
  #define H_gtk_tree_model_filter_get_type "GType gtk_tree_model_filter_get_type( void)"
  return(C_TO_XEN_GType(gtk_tree_model_filter_get_type()));
}
static XEN gxg_gtk_tree_model_filter_new(XEN child_model, XEN root)
{
  #define H_gtk_tree_model_filter_new "GtkTreeModel* gtk_tree_model_filter_new(GtkTreeModel* child_model, \
GtkTreePath* root)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(child_model), child_model, 1, "gtk_tree_model_filter_new", "GtkTreeModel*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(root), root, 2, "gtk_tree_model_filter_new", "GtkTreePath*");
  return(C_TO_XEN_GtkTreeModel_(gtk_tree_model_filter_new(XEN_TO_C_GtkTreeModel_(child_model), XEN_TO_C_GtkTreePath_(root))));
}
static XEN gxg_gtk_tree_model_filter_set_visible_column(XEN filter, XEN column)
{
  #define H_gtk_tree_model_filter_set_visible_column "void gtk_tree_model_filter_set_visible_column(GtkTreeModelFilter* filter, \
gint column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModelFilter__P(filter), filter, 1, "gtk_tree_model_filter_set_visible_column", "GtkTreeModelFilter*");
  XEN_ASSERT_TYPE(XEN_gint_P(column), column, 2, "gtk_tree_model_filter_set_visible_column", "gint");
  gtk_tree_model_filter_set_visible_column(XEN_TO_C_GtkTreeModelFilter_(filter), XEN_TO_C_gint(column));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_model_filter_get_model(XEN filter)
{
  #define H_gtk_tree_model_filter_get_model "GtkTreeModel* gtk_tree_model_filter_get_model(GtkTreeModelFilter* filter)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModelFilter__P(filter), filter, 1, "gtk_tree_model_filter_get_model", "GtkTreeModelFilter*");
  return(C_TO_XEN_GtkTreeModel_(gtk_tree_model_filter_get_model(XEN_TO_C_GtkTreeModelFilter_(filter))));
}
static XEN gxg_gtk_tree_model_filter_convert_child_iter_to_iter(XEN filter, XEN filter_iter, XEN child_iter)
{
  #define H_gtk_tree_model_filter_convert_child_iter_to_iter "void gtk_tree_model_filter_convert_child_iter_to_iter(GtkTreeModelFilter* filter, \
GtkTreeIter* filter_iter, GtkTreeIter* child_iter)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModelFilter__P(filter), filter, 1, "gtk_tree_model_filter_convert_child_iter_to_iter", "GtkTreeModelFilter*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(filter_iter), filter_iter, 2, "gtk_tree_model_filter_convert_child_iter_to_iter", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(child_iter), child_iter, 3, "gtk_tree_model_filter_convert_child_iter_to_iter", "GtkTreeIter*");
  gtk_tree_model_filter_convert_child_iter_to_iter(XEN_TO_C_GtkTreeModelFilter_(filter), XEN_TO_C_GtkTreeIter_(filter_iter), 
                                                   XEN_TO_C_GtkTreeIter_(child_iter));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_model_filter_convert_iter_to_child_iter(XEN filter, XEN child_iter, XEN filter_iter)
{
  #define H_gtk_tree_model_filter_convert_iter_to_child_iter "void gtk_tree_model_filter_convert_iter_to_child_iter(GtkTreeModelFilter* filter, \
GtkTreeIter* child_iter, GtkTreeIter* filter_iter)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModelFilter__P(filter), filter, 1, "gtk_tree_model_filter_convert_iter_to_child_iter", "GtkTreeModelFilter*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(child_iter), child_iter, 2, "gtk_tree_model_filter_convert_iter_to_child_iter", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(filter_iter), filter_iter, 3, "gtk_tree_model_filter_convert_iter_to_child_iter", "GtkTreeIter*");
  gtk_tree_model_filter_convert_iter_to_child_iter(XEN_TO_C_GtkTreeModelFilter_(filter), XEN_TO_C_GtkTreeIter_(child_iter), 
                                                   XEN_TO_C_GtkTreeIter_(filter_iter));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_model_filter_convert_child_path_to_path(XEN filter, XEN child_path)
{
  #define H_gtk_tree_model_filter_convert_child_path_to_path "GtkTreePath* gtk_tree_model_filter_convert_child_path_to_path(GtkTreeModelFilter* filter, \
GtkTreePath* child_path)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModelFilter__P(filter), filter, 1, "gtk_tree_model_filter_convert_child_path_to_path", "GtkTreeModelFilter*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(child_path), child_path, 2, "gtk_tree_model_filter_convert_child_path_to_path", "GtkTreePath*");
  return(C_TO_XEN_GtkTreePath_(gtk_tree_model_filter_convert_child_path_to_path(XEN_TO_C_GtkTreeModelFilter_(filter), XEN_TO_C_GtkTreePath_(child_path))));
}
static XEN gxg_gtk_tree_model_filter_convert_path_to_child_path(XEN path, XEN filter_path)
{
  #define H_gtk_tree_model_filter_convert_path_to_child_path "GtkTreePath* gtk_tree_model_filter_convert_path_to_child_path(GtkTreeModelFilter* path, \
GtkTreePath* filter_path)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModelFilter__P(path), path, 1, "gtk_tree_model_filter_convert_path_to_child_path", "GtkTreeModelFilter*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(filter_path), filter_path, 2, "gtk_tree_model_filter_convert_path_to_child_path", "GtkTreePath*");
  return(C_TO_XEN_GtkTreePath_(gtk_tree_model_filter_convert_path_to_child_path(XEN_TO_C_GtkTreeModelFilter_(path), XEN_TO_C_GtkTreePath_(filter_path))));
}
static XEN gxg_gtk_tree_model_filter_refilter(XEN filter)
{
  #define H_gtk_tree_model_filter_refilter "void gtk_tree_model_filter_refilter(GtkTreeModelFilter* filter)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModelFilter__P(filter), filter, 1, "gtk_tree_model_filter_refilter", "GtkTreeModelFilter*");
  gtk_tree_model_filter_refilter(XEN_TO_C_GtkTreeModelFilter_(filter));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_model_filter_clear_cache(XEN filter)
{
  #define H_gtk_tree_model_filter_clear_cache "void gtk_tree_model_filter_clear_cache(GtkTreeModelFilter* filter)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModelFilter__P(filter), filter, 1, "gtk_tree_model_filter_clear_cache", "GtkTreeModelFilter*");
  gtk_tree_model_filter_clear_cache(XEN_TO_C_GtkTreeModelFilter_(filter));
  return(XEN_FALSE);
}
static XEN gxg_gtk_action_get_type(void)
{
  #define H_gtk_action_get_type "GType gtk_action_get_type( void)"
  return(C_TO_XEN_GType(gtk_action_get_type()));
}
static XEN gxg_gtk_action_get_name(XEN action)
{
  #define H_gtk_action_get_name "gchar* gtk_action_get_name(GtkAction* action)"
  XEN_ASSERT_TYPE(XEN_GtkAction__P(action), action, 1, "gtk_action_get_name", "GtkAction*");
  return(C_TO_XEN_gchar_(gtk_action_get_name(XEN_TO_C_GtkAction_(action))));
}
static XEN gxg_gtk_action_activate(XEN action)
{
  #define H_gtk_action_activate "void gtk_action_activate(GtkAction* action)"
  XEN_ASSERT_TYPE(XEN_GtkAction__P(action), action, 1, "gtk_action_activate", "GtkAction*");
  gtk_action_activate(XEN_TO_C_GtkAction_(action));
  return(XEN_FALSE);
}
static XEN gxg_gtk_action_create_icon(XEN action, XEN icon_size)
{
  #define H_gtk_action_create_icon "GtkWidget* gtk_action_create_icon(GtkAction* action, GtkIconSize icon_size)"
  XEN_ASSERT_TYPE(XEN_GtkAction__P(action), action, 1, "gtk_action_create_icon", "GtkAction*");
  XEN_ASSERT_TYPE(XEN_GtkIconSize_P(icon_size), icon_size, 2, "gtk_action_create_icon", "GtkIconSize");
  return(C_TO_XEN_GtkWidget_(gtk_action_create_icon(XEN_TO_C_GtkAction_(action), XEN_TO_C_GtkIconSize(icon_size))));
}
static XEN gxg_gtk_action_create_menu_item(XEN action)
{
  #define H_gtk_action_create_menu_item "GtkWidget* gtk_action_create_menu_item(GtkAction* action)"
  XEN_ASSERT_TYPE(XEN_GtkAction__P(action), action, 1, "gtk_action_create_menu_item", "GtkAction*");
  return(C_TO_XEN_GtkWidget_(gtk_action_create_menu_item(XEN_TO_C_GtkAction_(action))));
}
static XEN gxg_gtk_action_create_tool_item(XEN action)
{
  #define H_gtk_action_create_tool_item "GtkWidget* gtk_action_create_tool_item(GtkAction* action)"
  XEN_ASSERT_TYPE(XEN_GtkAction__P(action), action, 1, "gtk_action_create_tool_item", "GtkAction*");
  return(C_TO_XEN_GtkWidget_(gtk_action_create_tool_item(XEN_TO_C_GtkAction_(action))));
}
static XEN gxg_gtk_action_connect_proxy(XEN action, XEN proxy)
{
  #define H_gtk_action_connect_proxy "void gtk_action_connect_proxy(GtkAction* action, GtkWidget* proxy)"
  XEN_ASSERT_TYPE(XEN_GtkAction__P(action), action, 1, "gtk_action_connect_proxy", "GtkAction*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(proxy), proxy, 2, "gtk_action_connect_proxy", "GtkWidget*");
  gtk_action_connect_proxy(XEN_TO_C_GtkAction_(action), XEN_TO_C_GtkWidget_(proxy));
  return(XEN_FALSE);
}
static XEN gxg_gtk_action_disconnect_proxy(XEN action, XEN proxy)
{
  #define H_gtk_action_disconnect_proxy "void gtk_action_disconnect_proxy(GtkAction* action, GtkWidget* proxy)"
  XEN_ASSERT_TYPE(XEN_GtkAction__P(action), action, 1, "gtk_action_disconnect_proxy", "GtkAction*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(proxy), proxy, 2, "gtk_action_disconnect_proxy", "GtkWidget*");
  gtk_action_disconnect_proxy(XEN_TO_C_GtkAction_(action), XEN_TO_C_GtkWidget_(proxy));
  return(XEN_FALSE);
}
static XEN gxg_gtk_action_get_proxies(XEN action)
{
  #define H_gtk_action_get_proxies "GSList* gtk_action_get_proxies(GtkAction* action)"
  XEN_ASSERT_TYPE(XEN_GtkAction__P(action), action, 1, "gtk_action_get_proxies", "GtkAction*");
  return(C_TO_XEN_GSList_(gtk_action_get_proxies(XEN_TO_C_GtkAction_(action))));
}
static XEN gxg_gtk_action_connect_accelerator(XEN action)
{
  #define H_gtk_action_connect_accelerator "void gtk_action_connect_accelerator(GtkAction* action)"
  XEN_ASSERT_TYPE(XEN_GtkAction__P(action), action, 1, "gtk_action_connect_accelerator", "GtkAction*");
  gtk_action_connect_accelerator(XEN_TO_C_GtkAction_(action));
  return(XEN_FALSE);
}
static XEN gxg_gtk_action_disconnect_accelerator(XEN action)
{
  #define H_gtk_action_disconnect_accelerator "void gtk_action_disconnect_accelerator(GtkAction* action)"
  XEN_ASSERT_TYPE(XEN_GtkAction__P(action), action, 1, "gtk_action_disconnect_accelerator", "GtkAction*");
  gtk_action_disconnect_accelerator(XEN_TO_C_GtkAction_(action));
  return(XEN_FALSE);
}
static XEN gxg_gtk_action_group_get_type(void)
{
  #define H_gtk_action_group_get_type "GType gtk_action_group_get_type( void)"
  return(C_TO_XEN_GType(gtk_action_group_get_type()));
}
static XEN gxg_gtk_action_group_new(XEN name)
{
  #define H_gtk_action_group_new "GtkActionGroup* gtk_action_group_new(gchar* name)"
  XEN_ASSERT_TYPE(XEN_gchar__P(name), name, 1, "gtk_action_group_new", "gchar*");
  return(C_TO_XEN_GtkActionGroup_(gtk_action_group_new(XEN_TO_C_gchar_(name))));
}
static XEN gxg_gtk_action_group_get_name(XEN action_group)
{
  #define H_gtk_action_group_get_name "gchar* gtk_action_group_get_name(GtkActionGroup* action_group)"
  XEN_ASSERT_TYPE(XEN_GtkActionGroup__P(action_group), action_group, 1, "gtk_action_group_get_name", "GtkActionGroup*");
  return(C_TO_XEN_gchar_(gtk_action_group_get_name(XEN_TO_C_GtkActionGroup_(action_group))));
}
static XEN gxg_gtk_action_group_get_action(XEN action_group, XEN action_name)
{
  #define H_gtk_action_group_get_action "GtkAction* gtk_action_group_get_action(GtkActionGroup* action_group, \
gchar* action_name)"
  XEN_ASSERT_TYPE(XEN_GtkActionGroup__P(action_group), action_group, 1, "gtk_action_group_get_action", "GtkActionGroup*");
  XEN_ASSERT_TYPE(XEN_gchar__P(action_name), action_name, 2, "gtk_action_group_get_action", "gchar*");
  return(C_TO_XEN_GtkAction_(gtk_action_group_get_action(XEN_TO_C_GtkActionGroup_(action_group), XEN_TO_C_gchar_(action_name))));
}
static XEN gxg_gtk_action_group_list_actions(XEN action_group)
{
  #define H_gtk_action_group_list_actions "GList* gtk_action_group_list_actions(GtkActionGroup* action_group)"
  XEN_ASSERT_TYPE(XEN_GtkActionGroup__P(action_group), action_group, 1, "gtk_action_group_list_actions", "GtkActionGroup*");
  return(C_TO_XEN_GList_(gtk_action_group_list_actions(XEN_TO_C_GtkActionGroup_(action_group))));
}
static XEN gxg_gtk_action_group_add_action(XEN action_group, XEN action)
{
  #define H_gtk_action_group_add_action "void gtk_action_group_add_action(GtkActionGroup* action_group, \
GtkAction* action)"
  XEN_ASSERT_TYPE(XEN_GtkActionGroup__P(action_group), action_group, 1, "gtk_action_group_add_action", "GtkActionGroup*");
  XEN_ASSERT_TYPE(XEN_GtkAction__P(action), action, 2, "gtk_action_group_add_action", "GtkAction*");
  gtk_action_group_add_action(XEN_TO_C_GtkActionGroup_(action_group), XEN_TO_C_GtkAction_(action));
  return(XEN_FALSE);
}
static XEN gxg_gtk_action_group_remove_action(XEN action_group, XEN action)
{
  #define H_gtk_action_group_remove_action "void gtk_action_group_remove_action(GtkActionGroup* action_group, \
GtkAction* action)"
  XEN_ASSERT_TYPE(XEN_GtkActionGroup__P(action_group), action_group, 1, "gtk_action_group_remove_action", "GtkActionGroup*");
  XEN_ASSERT_TYPE(XEN_GtkAction__P(action), action, 2, "gtk_action_group_remove_action", "GtkAction*");
  gtk_action_group_remove_action(XEN_TO_C_GtkActionGroup_(action_group), XEN_TO_C_GtkAction_(action));
  return(XEN_FALSE);
}
static XEN gxg_gtk_action_group_add_actions(XEN action_group, XEN entries, XEN n_entries, XEN user_data)
{
  #define H_gtk_action_group_add_actions "void gtk_action_group_add_actions(GtkActionGroup* action_group, \
GtkActionEntry* entries, guint n_entries, gpointer user_data)"
  XEN_ASSERT_TYPE(XEN_GtkActionGroup__P(action_group), action_group, 1, "gtk_action_group_add_actions", "GtkActionGroup*");
  XEN_ASSERT_TYPE(XEN_GtkActionEntry__P(entries), entries, 2, "gtk_action_group_add_actions", "GtkActionEntry*");
  XEN_ASSERT_TYPE(XEN_guint_P(n_entries), n_entries, 3, "gtk_action_group_add_actions", "guint");
  XEN_ASSERT_TYPE(XEN_gpointer_P(user_data), user_data, 4, "gtk_action_group_add_actions", "gpointer");
  gtk_action_group_add_actions(XEN_TO_C_GtkActionGroup_(action_group), XEN_TO_C_GtkActionEntry_(entries), XEN_TO_C_guint(n_entries), 
                               XEN_TO_C_gpointer(user_data));
  return(XEN_FALSE);
}
static XEN gxg_gtk_action_group_add_toggle_actions(XEN action_group, XEN entries, XEN n_entries, XEN user_data)
{
  #define H_gtk_action_group_add_toggle_actions "void gtk_action_group_add_toggle_actions(GtkActionGroup* action_group, \
GtkToggleActionEntry* entries, guint n_entries, gpointer user_data)"
  XEN_ASSERT_TYPE(XEN_GtkActionGroup__P(action_group), action_group, 1, "gtk_action_group_add_toggle_actions", "GtkActionGroup*");
  XEN_ASSERT_TYPE(XEN_GtkToggleActionEntry__P(entries), entries, 2, "gtk_action_group_add_toggle_actions", "GtkToggleActionEntry*");
  XEN_ASSERT_TYPE(XEN_guint_P(n_entries), n_entries, 3, "gtk_action_group_add_toggle_actions", "guint");
  XEN_ASSERT_TYPE(XEN_gpointer_P(user_data), user_data, 4, "gtk_action_group_add_toggle_actions", "gpointer");
  gtk_action_group_add_toggle_actions(XEN_TO_C_GtkActionGroup_(action_group), XEN_TO_C_GtkToggleActionEntry_(entries), XEN_TO_C_guint(n_entries), 
                                      XEN_TO_C_gpointer(user_data));
  return(XEN_FALSE);
}
static XEN gxg_gtk_action_group_add_toggle_actions_full(XEN action_group, XEN entries, XEN n_entries, XEN func_data, XEN destroy)
{
  #define H_gtk_action_group_add_toggle_actions_full "void gtk_action_group_add_toggle_actions_full(GtkActionGroup* action_group, \
GtkToggleActionEntry* entries, guint n_entries, lambda_data func_data, GtkDestroyNotify destroy)"
  XEN_ASSERT_TYPE(XEN_GtkActionGroup__P(action_group), action_group, 1, "gtk_action_group_add_toggle_actions_full", "GtkActionGroup*");
  XEN_ASSERT_TYPE(XEN_GtkToggleActionEntry__P(entries), entries, 2, "gtk_action_group_add_toggle_actions_full", "GtkToggleActionEntry*");
  XEN_ASSERT_TYPE(XEN_guint_P(n_entries), n_entries, 3, "gtk_action_group_add_toggle_actions_full", "guint");
  XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 4, "gtk_action_group_add_toggle_actions_full", "lambda_data");
  XEN_ASSERT_TYPE(XEN_GtkDestroyNotify_P(destroy), destroy, 5, "gtk_action_group_add_toggle_actions_full", "GtkDestroyNotify");
  {
    XEN gxg_ptr = XEN_LIST_5(XEN_FALSE, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 3, destroy);
    gtk_action_group_add_toggle_actions_full(XEN_TO_C_GtkActionGroup_(action_group), XEN_TO_C_GtkToggleActionEntry_(entries), 
                                         XEN_TO_C_guint(n_entries), XEN_TO_C_lambda_data(func_data), XEN_TO_C_GtkDestroyNotify(destroy));
    return(XEN_FALSE);
   }
}
static XEN gxg_gtk_action_group_set_translation_domain(XEN action_group, XEN domain)
{
  #define H_gtk_action_group_set_translation_domain "void gtk_action_group_set_translation_domain(GtkActionGroup* action_group, \
gchar* domain)"
  XEN_ASSERT_TYPE(XEN_GtkActionGroup__P(action_group), action_group, 1, "gtk_action_group_set_translation_domain", "GtkActionGroup*");
  XEN_ASSERT_TYPE(XEN_gchar__P(domain), domain, 2, "gtk_action_group_set_translation_domain", "gchar*");
  gtk_action_group_set_translation_domain(XEN_TO_C_GtkActionGroup_(action_group), XEN_TO_C_gchar_(domain));
  return(XEN_FALSE);
}
static XEN gxg_gtk_combo_box_get_type(void)
{
  #define H_gtk_combo_box_get_type "GType gtk_combo_box_get_type( void)"
  return(C_TO_XEN_GType(gtk_combo_box_get_type()));
}
static XEN gxg_gtk_combo_box_set_wrap_width(XEN combo_box, XEN width)
{
  #define H_gtk_combo_box_set_wrap_width "void gtk_combo_box_set_wrap_width(GtkComboBox* combo_box, gint width)"
  XEN_ASSERT_TYPE(XEN_GtkComboBox__P(combo_box), combo_box, 1, "gtk_combo_box_set_wrap_width", "GtkComboBox*");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 2, "gtk_combo_box_set_wrap_width", "gint");
  gtk_combo_box_set_wrap_width(XEN_TO_C_GtkComboBox_(combo_box), XEN_TO_C_gint(width));
  return(XEN_FALSE);
}
static XEN gxg_gtk_combo_box_set_row_span_column(XEN combo_box, XEN row_span)
{
  #define H_gtk_combo_box_set_row_span_column "void gtk_combo_box_set_row_span_column(GtkComboBox* combo_box, \
gint row_span)"
  XEN_ASSERT_TYPE(XEN_GtkComboBox__P(combo_box), combo_box, 1, "gtk_combo_box_set_row_span_column", "GtkComboBox*");
  XEN_ASSERT_TYPE(XEN_gint_P(row_span), row_span, 2, "gtk_combo_box_set_row_span_column", "gint");
  gtk_combo_box_set_row_span_column(XEN_TO_C_GtkComboBox_(combo_box), XEN_TO_C_gint(row_span));
  return(XEN_FALSE);
}
static XEN gxg_gtk_combo_box_set_column_span_column(XEN combo_box, XEN column_span)
{
  #define H_gtk_combo_box_set_column_span_column "void gtk_combo_box_set_column_span_column(GtkComboBox* combo_box, \
gint column_span)"
  XEN_ASSERT_TYPE(XEN_GtkComboBox__P(combo_box), combo_box, 1, "gtk_combo_box_set_column_span_column", "GtkComboBox*");
  XEN_ASSERT_TYPE(XEN_gint_P(column_span), column_span, 2, "gtk_combo_box_set_column_span_column", "gint");
  gtk_combo_box_set_column_span_column(XEN_TO_C_GtkComboBox_(combo_box), XEN_TO_C_gint(column_span));
  return(XEN_FALSE);
}
static XEN gxg_gtk_combo_box_get_active(XEN combo_box)
{
  #define H_gtk_combo_box_get_active "gint gtk_combo_box_get_active(GtkComboBox* combo_box)"
  XEN_ASSERT_TYPE(XEN_GtkComboBox__P(combo_box), combo_box, 1, "gtk_combo_box_get_active", "GtkComboBox*");
  return(C_TO_XEN_gint(gtk_combo_box_get_active(XEN_TO_C_GtkComboBox_(combo_box))));
}
static XEN gxg_gtk_combo_box_set_active(XEN combo_box, XEN index)
{
  #define H_gtk_combo_box_set_active "void gtk_combo_box_set_active(GtkComboBox* combo_box, gint index)"
  XEN_ASSERT_TYPE(XEN_GtkComboBox__P(combo_box), combo_box, 1, "gtk_combo_box_set_active", "GtkComboBox*");
  XEN_ASSERT_TYPE(XEN_gint_P(index), index, 2, "gtk_combo_box_set_active", "gint");
  gtk_combo_box_set_active(XEN_TO_C_GtkComboBox_(combo_box), XEN_TO_C_gint(index));
  return(XEN_FALSE);
}
static XEN gxg_gtk_combo_box_get_active_iter(XEN combo_box, XEN iter)
{
  #define H_gtk_combo_box_get_active_iter "gboolean gtk_combo_box_get_active_iter(GtkComboBox* combo_box, \
GtkTreeIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkComboBox__P(combo_box), combo_box, 1, "gtk_combo_box_get_active_iter", "GtkComboBox*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_combo_box_get_active_iter", "GtkTreeIter*");
  return(C_TO_XEN_gboolean(gtk_combo_box_get_active_iter(XEN_TO_C_GtkComboBox_(combo_box), XEN_TO_C_GtkTreeIter_(iter))));
}
static XEN gxg_gtk_combo_box_set_active_iter(XEN combo_box, XEN iter)
{
  #define H_gtk_combo_box_set_active_iter "void gtk_combo_box_set_active_iter(GtkComboBox* combo_box, \
GtkTreeIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkComboBox__P(combo_box), combo_box, 1, "gtk_combo_box_set_active_iter", "GtkComboBox*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_combo_box_set_active_iter", "GtkTreeIter*");
  gtk_combo_box_set_active_iter(XEN_TO_C_GtkComboBox_(combo_box), XEN_TO_C_GtkTreeIter_(iter));
  return(XEN_FALSE);
}
static XEN gxg_gtk_combo_box_get_model(XEN combo_box)
{
  #define H_gtk_combo_box_get_model "GtkTreeModel* gtk_combo_box_get_model(GtkComboBox* combo_box)"
  XEN_ASSERT_TYPE(XEN_GtkComboBox__P(combo_box), combo_box, 1, "gtk_combo_box_get_model", "GtkComboBox*");
  return(C_TO_XEN_GtkTreeModel_(gtk_combo_box_get_model(XEN_TO_C_GtkComboBox_(combo_box))));
}
static XEN gxg_gtk_combo_box_new_text(void)
{
  #define H_gtk_combo_box_new_text "GtkWidget* gtk_combo_box_new_text( void)"
  return(C_TO_XEN_GtkWidget_(gtk_combo_box_new_text()));
}
static XEN gxg_gtk_combo_box_append_text(XEN combo_box, XEN text)
{
  #define H_gtk_combo_box_append_text "void gtk_combo_box_append_text(GtkComboBox* combo_box, gchar* text)"
  XEN_ASSERT_TYPE(XEN_GtkComboBox__P(combo_box), combo_box, 1, "gtk_combo_box_append_text", "GtkComboBox*");
  XEN_ASSERT_TYPE(XEN_gchar__P(text), text, 2, "gtk_combo_box_append_text", "gchar*");
  gtk_combo_box_append_text(XEN_TO_C_GtkComboBox_(combo_box), XEN_TO_C_gchar_(text));
  return(XEN_FALSE);
}
static XEN gxg_gtk_combo_box_insert_text(XEN combo_box, XEN position, XEN text)
{
  #define H_gtk_combo_box_insert_text "void gtk_combo_box_insert_text(GtkComboBox* combo_box, gint position, \
gchar* text)"
  XEN_ASSERT_TYPE(XEN_GtkComboBox__P(combo_box), combo_box, 1, "gtk_combo_box_insert_text", "GtkComboBox*");
  XEN_ASSERT_TYPE(XEN_gint_P(position), position, 2, "gtk_combo_box_insert_text", "gint");
  XEN_ASSERT_TYPE(XEN_gchar__P(text), text, 3, "gtk_combo_box_insert_text", "gchar*");
  gtk_combo_box_insert_text(XEN_TO_C_GtkComboBox_(combo_box), XEN_TO_C_gint(position), XEN_TO_C_gchar_(text));
  return(XEN_FALSE);
}
static XEN gxg_gtk_combo_box_prepend_text(XEN combo_box, XEN text)
{
  #define H_gtk_combo_box_prepend_text "void gtk_combo_box_prepend_text(GtkComboBox* combo_box, gchar* text)"
  XEN_ASSERT_TYPE(XEN_GtkComboBox__P(combo_box), combo_box, 1, "gtk_combo_box_prepend_text", "GtkComboBox*");
  XEN_ASSERT_TYPE(XEN_gchar__P(text), text, 2, "gtk_combo_box_prepend_text", "gchar*");
  gtk_combo_box_prepend_text(XEN_TO_C_GtkComboBox_(combo_box), XEN_TO_C_gchar_(text));
  return(XEN_FALSE);
}
static XEN gxg_gtk_combo_box_entry_get_type(void)
{
  #define H_gtk_combo_box_entry_get_type "GType gtk_combo_box_entry_get_type( void)"
  return(C_TO_XEN_GType(gtk_combo_box_entry_get_type()));
}
static XEN gxg_gtk_combo_box_entry_get_text_column(XEN entry_box)
{
  #define H_gtk_combo_box_entry_get_text_column "gint gtk_combo_box_entry_get_text_column(GtkComboBoxEntry* entry_box)"
  XEN_ASSERT_TYPE(XEN_GtkComboBoxEntry__P(entry_box), entry_box, 1, "gtk_combo_box_entry_get_text_column", "GtkComboBoxEntry*");
  return(C_TO_XEN_gint(gtk_combo_box_entry_get_text_column(XEN_TO_C_GtkComboBoxEntry_(entry_box))));
}
static XEN gxg_gtk_expander_get_type(void)
{
  #define H_gtk_expander_get_type "GType gtk_expander_get_type( void)"
  return(C_TO_XEN_GType(gtk_expander_get_type()));
}
static XEN gxg_gtk_expander_new(XEN label)
{
  #define H_gtk_expander_new "GtkWidget* gtk_expander_new(gchar* label)"
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 1, "gtk_expander_new", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_expander_new(XEN_TO_C_gchar_(label))));
}
static XEN gxg_gtk_expander_new_with_mnemonic(XEN label)
{
  #define H_gtk_expander_new_with_mnemonic "GtkWidget* gtk_expander_new_with_mnemonic(gchar* label)"
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 1, "gtk_expander_new_with_mnemonic", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_expander_new_with_mnemonic(XEN_TO_C_gchar_(label))));
}
static XEN gxg_gtk_expander_set_expanded(XEN expander, XEN expanded)
{
  #define H_gtk_expander_set_expanded "void gtk_expander_set_expanded(GtkExpander* expander, gboolean expanded)"
  XEN_ASSERT_TYPE(XEN_GtkExpander__P(expander), expander, 1, "gtk_expander_set_expanded", "GtkExpander*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(expanded), expanded, 2, "gtk_expander_set_expanded", "gboolean");
  gtk_expander_set_expanded(XEN_TO_C_GtkExpander_(expander), XEN_TO_C_gboolean(expanded));
  return(XEN_FALSE);
}
static XEN gxg_gtk_expander_get_expanded(XEN expander)
{
  #define H_gtk_expander_get_expanded "gboolean gtk_expander_get_expanded(GtkExpander* expander)"
  XEN_ASSERT_TYPE(XEN_GtkExpander__P(expander), expander, 1, "gtk_expander_get_expanded", "GtkExpander*");
  return(C_TO_XEN_gboolean(gtk_expander_get_expanded(XEN_TO_C_GtkExpander_(expander))));
}
static XEN gxg_gtk_expander_set_spacing(XEN expander, XEN spacing)
{
  #define H_gtk_expander_set_spacing "void gtk_expander_set_spacing(GtkExpander* expander, gint spacing)"
  XEN_ASSERT_TYPE(XEN_GtkExpander__P(expander), expander, 1, "gtk_expander_set_spacing", "GtkExpander*");
  XEN_ASSERT_TYPE(XEN_gint_P(spacing), spacing, 2, "gtk_expander_set_spacing", "gint");
  gtk_expander_set_spacing(XEN_TO_C_GtkExpander_(expander), XEN_TO_C_gint(spacing));
  return(XEN_FALSE);
}
static XEN gxg_gtk_expander_get_spacing(XEN expander)
{
  #define H_gtk_expander_get_spacing "gint gtk_expander_get_spacing(GtkExpander* expander)"
  XEN_ASSERT_TYPE(XEN_GtkExpander__P(expander), expander, 1, "gtk_expander_get_spacing", "GtkExpander*");
  return(C_TO_XEN_gint(gtk_expander_get_spacing(XEN_TO_C_GtkExpander_(expander))));
}
static XEN gxg_gtk_expander_set_label(XEN expander, XEN label)
{
  #define H_gtk_expander_set_label "void gtk_expander_set_label(GtkExpander* expander, gchar* label)"
  XEN_ASSERT_TYPE(XEN_GtkExpander__P(expander), expander, 1, "gtk_expander_set_label", "GtkExpander*");
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 2, "gtk_expander_set_label", "gchar*");
  gtk_expander_set_label(XEN_TO_C_GtkExpander_(expander), XEN_TO_C_gchar_(label));
  return(XEN_FALSE);
}
static XEN gxg_gtk_expander_get_label(XEN expander)
{
  #define H_gtk_expander_get_label "gchar* gtk_expander_get_label(GtkExpander* expander)"
  XEN_ASSERT_TYPE(XEN_GtkExpander__P(expander), expander, 1, "gtk_expander_get_label", "GtkExpander*");
  return(C_TO_XEN_gchar_(gtk_expander_get_label(XEN_TO_C_GtkExpander_(expander))));
}
static XEN gxg_gtk_expander_set_use_underline(XEN expander, XEN use_underline)
{
  #define H_gtk_expander_set_use_underline "void gtk_expander_set_use_underline(GtkExpander* expander, \
gboolean use_underline)"
  XEN_ASSERT_TYPE(XEN_GtkExpander__P(expander), expander, 1, "gtk_expander_set_use_underline", "GtkExpander*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(use_underline), use_underline, 2, "gtk_expander_set_use_underline", "gboolean");
  gtk_expander_set_use_underline(XEN_TO_C_GtkExpander_(expander), XEN_TO_C_gboolean(use_underline));
  return(XEN_FALSE);
}
static XEN gxg_gtk_expander_get_use_underline(XEN expander)
{
  #define H_gtk_expander_get_use_underline "gboolean gtk_expander_get_use_underline(GtkExpander* expander)"
  XEN_ASSERT_TYPE(XEN_GtkExpander__P(expander), expander, 1, "gtk_expander_get_use_underline", "GtkExpander*");
  return(C_TO_XEN_gboolean(gtk_expander_get_use_underline(XEN_TO_C_GtkExpander_(expander))));
}
static XEN gxg_gtk_expander_set_label_widget(XEN expander, XEN label_widget)
{
  #define H_gtk_expander_set_label_widget "void gtk_expander_set_label_widget(GtkExpander* expander, \
GtkWidget* label_widget)"
  XEN_ASSERT_TYPE(XEN_GtkExpander__P(expander), expander, 1, "gtk_expander_set_label_widget", "GtkExpander*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(label_widget), label_widget, 2, "gtk_expander_set_label_widget", "GtkWidget*");
  gtk_expander_set_label_widget(XEN_TO_C_GtkExpander_(expander), XEN_TO_C_GtkWidget_(label_widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_expander_get_label_widget(XEN expander)
{
  #define H_gtk_expander_get_label_widget "GtkWidget* gtk_expander_get_label_widget(GtkExpander* expander)"
  XEN_ASSERT_TYPE(XEN_GtkExpander__P(expander), expander, 1, "gtk_expander_get_label_widget", "GtkExpander*");
  return(C_TO_XEN_GtkWidget_(gtk_expander_get_label_widget(XEN_TO_C_GtkExpander_(expander))));
}
static XEN gxg_gtk_font_button_get_type(void)
{
  #define H_gtk_font_button_get_type "GType gtk_font_button_get_type( void)"
  return(C_TO_XEN_GType(gtk_font_button_get_type()));
}
static XEN gxg_gtk_font_button_new(void)
{
  #define H_gtk_font_button_new "GtkWidget* gtk_font_button_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_font_button_new()));
}
static XEN gxg_gtk_font_button_new_with_font(XEN fontname)
{
  #define H_gtk_font_button_new_with_font "GtkWidget* gtk_font_button_new_with_font(gchar* fontname)"
  XEN_ASSERT_TYPE(XEN_gchar__P(fontname), fontname, 1, "gtk_font_button_new_with_font", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_font_button_new_with_font(XEN_TO_C_gchar_(fontname))));
}
static XEN gxg_gtk_font_button_get_title(XEN font_button)
{
  #define H_gtk_font_button_get_title "gchar* gtk_font_button_get_title(GtkFontButton* font_button)"
  XEN_ASSERT_TYPE(XEN_GtkFontButton__P(font_button), font_button, 1, "gtk_font_button_get_title", "GtkFontButton*");
  return(C_TO_XEN_gchar_(gtk_font_button_get_title(XEN_TO_C_GtkFontButton_(font_button))));
}
static XEN gxg_gtk_font_button_set_title(XEN font_button, XEN title)
{
  #define H_gtk_font_button_set_title "void gtk_font_button_set_title(GtkFontButton* font_button, gchar* title)"
  XEN_ASSERT_TYPE(XEN_GtkFontButton__P(font_button), font_button, 1, "gtk_font_button_set_title", "GtkFontButton*");
  XEN_ASSERT_TYPE(XEN_gchar__P(title), title, 2, "gtk_font_button_set_title", "gchar*");
  gtk_font_button_set_title(XEN_TO_C_GtkFontButton_(font_button), XEN_TO_C_gchar_(title));
  return(XEN_FALSE);
}
static XEN gxg_gtk_font_button_get_use_font(XEN font_button)
{
  #define H_gtk_font_button_get_use_font "gboolean gtk_font_button_get_use_font(GtkFontButton* font_button)"
  XEN_ASSERT_TYPE(XEN_GtkFontButton__P(font_button), font_button, 1, "gtk_font_button_get_use_font", "GtkFontButton*");
  return(C_TO_XEN_gboolean(gtk_font_button_get_use_font(XEN_TO_C_GtkFontButton_(font_button))));
}
static XEN gxg_gtk_font_button_set_use_font(XEN font_button, XEN use_font)
{
  #define H_gtk_font_button_set_use_font "void gtk_font_button_set_use_font(GtkFontButton* font_button, \
gboolean use_font)"
  XEN_ASSERT_TYPE(XEN_GtkFontButton__P(font_button), font_button, 1, "gtk_font_button_set_use_font", "GtkFontButton*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(use_font), use_font, 2, "gtk_font_button_set_use_font", "gboolean");
  gtk_font_button_set_use_font(XEN_TO_C_GtkFontButton_(font_button), XEN_TO_C_gboolean(use_font));
  return(XEN_FALSE);
}
static XEN gxg_gtk_font_button_get_use_size(XEN font_button)
{
  #define H_gtk_font_button_get_use_size "gboolean gtk_font_button_get_use_size(GtkFontButton* font_button)"
  XEN_ASSERT_TYPE(XEN_GtkFontButton__P(font_button), font_button, 1, "gtk_font_button_get_use_size", "GtkFontButton*");
  return(C_TO_XEN_gboolean(gtk_font_button_get_use_size(XEN_TO_C_GtkFontButton_(font_button))));
}
static XEN gxg_gtk_font_button_set_use_size(XEN font_button, XEN use_size)
{
  #define H_gtk_font_button_set_use_size "void gtk_font_button_set_use_size(GtkFontButton* font_button, \
gboolean use_size)"
  XEN_ASSERT_TYPE(XEN_GtkFontButton__P(font_button), font_button, 1, "gtk_font_button_set_use_size", "GtkFontButton*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(use_size), use_size, 2, "gtk_font_button_set_use_size", "gboolean");
  gtk_font_button_set_use_size(XEN_TO_C_GtkFontButton_(font_button), XEN_TO_C_gboolean(use_size));
  return(XEN_FALSE);
}
static XEN gxg_gtk_font_button_get_font_name(XEN font_button)
{
  #define H_gtk_font_button_get_font_name "gchar* gtk_font_button_get_font_name(GtkFontButton* font_button)"
  XEN_ASSERT_TYPE(XEN_GtkFontButton__P(font_button), font_button, 1, "gtk_font_button_get_font_name", "GtkFontButton*");
  return(C_TO_XEN_gchar_(gtk_font_button_get_font_name(XEN_TO_C_GtkFontButton_(font_button))));
}
static XEN gxg_gtk_font_button_set_font_name(XEN font_button, XEN fontname)
{
  #define H_gtk_font_button_set_font_name "gboolean gtk_font_button_set_font_name(GtkFontButton* font_button, \
gchar* fontname)"
  XEN_ASSERT_TYPE(XEN_GtkFontButton__P(font_button), font_button, 1, "gtk_font_button_set_font_name", "GtkFontButton*");
  XEN_ASSERT_TYPE(XEN_gchar__P(fontname), fontname, 2, "gtk_font_button_set_font_name", "gchar*");
  return(C_TO_XEN_gboolean(gtk_font_button_set_font_name(XEN_TO_C_GtkFontButton_(font_button), XEN_TO_C_gchar_(fontname))));
}
static XEN gxg_gtk_font_button_get_show_style(XEN font_button)
{
  #define H_gtk_font_button_get_show_style "gboolean gtk_font_button_get_show_style(GtkFontButton* font_button)"
  XEN_ASSERT_TYPE(XEN_GtkFontButton__P(font_button), font_button, 1, "gtk_font_button_get_show_style", "GtkFontButton*");
  return(C_TO_XEN_gboolean(gtk_font_button_get_show_style(XEN_TO_C_GtkFontButton_(font_button))));
}
static XEN gxg_gtk_font_button_set_show_style(XEN font_button, XEN show_style)
{
  #define H_gtk_font_button_set_show_style "void gtk_font_button_set_show_style(GtkFontButton* font_button, \
gboolean show_style)"
  XEN_ASSERT_TYPE(XEN_GtkFontButton__P(font_button), font_button, 1, "gtk_font_button_set_show_style", "GtkFontButton*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(show_style), show_style, 2, "gtk_font_button_set_show_style", "gboolean");
  gtk_font_button_set_show_style(XEN_TO_C_GtkFontButton_(font_button), XEN_TO_C_gboolean(show_style));
  return(XEN_FALSE);
}
static XEN gxg_gtk_font_button_get_show_size(XEN font_button)
{
  #define H_gtk_font_button_get_show_size "gboolean gtk_font_button_get_show_size(GtkFontButton* font_button)"
  XEN_ASSERT_TYPE(XEN_GtkFontButton__P(font_button), font_button, 1, "gtk_font_button_get_show_size", "GtkFontButton*");
  return(C_TO_XEN_gboolean(gtk_font_button_get_show_size(XEN_TO_C_GtkFontButton_(font_button))));
}
static XEN gxg_gtk_font_button_set_show_size(XEN font_button, XEN show_size)
{
  #define H_gtk_font_button_set_show_size "void gtk_font_button_set_show_size(GtkFontButton* font_button, \
gboolean show_size)"
  XEN_ASSERT_TYPE(XEN_GtkFontButton__P(font_button), font_button, 1, "gtk_font_button_set_show_size", "GtkFontButton*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(show_size), show_size, 2, "gtk_font_button_set_show_size", "gboolean");
  gtk_font_button_set_show_size(XEN_TO_C_GtkFontButton_(font_button), XEN_TO_C_gboolean(show_size));
  return(XEN_FALSE);
}
static XEN gxg_gtk_color_button_get_type(void)
{
  #define H_gtk_color_button_get_type "GType gtk_color_button_get_type( void)"
  return(C_TO_XEN_GType(gtk_color_button_get_type()));
}
static XEN gxg_gtk_color_button_new(void)
{
  #define H_gtk_color_button_new "GtkWidget* gtk_color_button_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_color_button_new()));
}
static XEN gxg_gtk_color_button_new_with_color(XEN color)
{
  #define H_gtk_color_button_new_with_color "GtkWidget* gtk_color_button_new_with_color(GdkColor* color)"
  XEN_ASSERT_TYPE(XEN_GdkColor__P(color), color, 1, "gtk_color_button_new_with_color", "GdkColor*");
  return(C_TO_XEN_GtkWidget_(gtk_color_button_new_with_color(XEN_TO_C_GdkColor_(color))));
}
static XEN gxg_gtk_color_button_set_color(XEN color_button, XEN color)
{
  #define H_gtk_color_button_set_color "void gtk_color_button_set_color(GtkColorButton* color_button, \
GdkColor* color)"
  XEN_ASSERT_TYPE(XEN_GtkColorButton__P(color_button), color_button, 1, "gtk_color_button_set_color", "GtkColorButton*");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(color), color, 2, "gtk_color_button_set_color", "GdkColor*");
  gtk_color_button_set_color(XEN_TO_C_GtkColorButton_(color_button), XEN_TO_C_GdkColor_(color));
  return(XEN_FALSE);
}
static XEN gxg_gtk_color_button_set_alpha(XEN color_button, XEN alpha)
{
  #define H_gtk_color_button_set_alpha "void gtk_color_button_set_alpha(GtkColorButton* color_button, \
guint16 alpha)"
  XEN_ASSERT_TYPE(XEN_GtkColorButton__P(color_button), color_button, 1, "gtk_color_button_set_alpha", "GtkColorButton*");
  XEN_ASSERT_TYPE(XEN_guint16_P(alpha), alpha, 2, "gtk_color_button_set_alpha", "guint16");
  gtk_color_button_set_alpha(XEN_TO_C_GtkColorButton_(color_button), XEN_TO_C_guint16(alpha));
  return(XEN_FALSE);
}
static XEN gxg_gtk_color_button_get_color(XEN color_button, XEN color)
{
  #define H_gtk_color_button_get_color "void gtk_color_button_get_color(GtkColorButton* color_button, \
GdkColor* color)"
  XEN_ASSERT_TYPE(XEN_GtkColorButton__P(color_button), color_button, 1, "gtk_color_button_get_color", "GtkColorButton*");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(color), color, 2, "gtk_color_button_get_color", "GdkColor*");
  gtk_color_button_get_color(XEN_TO_C_GtkColorButton_(color_button), XEN_TO_C_GdkColor_(color));
  return(XEN_FALSE);
}
static XEN gxg_gtk_color_button_get_alpha(XEN color_button)
{
  #define H_gtk_color_button_get_alpha "guint16 gtk_color_button_get_alpha(GtkColorButton* color_button)"
  XEN_ASSERT_TYPE(XEN_GtkColorButton__P(color_button), color_button, 1, "gtk_color_button_get_alpha", "GtkColorButton*");
  return(C_TO_XEN_guint16(gtk_color_button_get_alpha(XEN_TO_C_GtkColorButton_(color_button))));
}
static XEN gxg_gtk_color_button_set_use_alpha(XEN color_button, XEN use_alpha)
{
  #define H_gtk_color_button_set_use_alpha "void gtk_color_button_set_use_alpha(GtkColorButton* color_button, \
gboolean use_alpha)"
  XEN_ASSERT_TYPE(XEN_GtkColorButton__P(color_button), color_button, 1, "gtk_color_button_set_use_alpha", "GtkColorButton*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(use_alpha), use_alpha, 2, "gtk_color_button_set_use_alpha", "gboolean");
  gtk_color_button_set_use_alpha(XEN_TO_C_GtkColorButton_(color_button), XEN_TO_C_gboolean(use_alpha));
  return(XEN_FALSE);
}
static XEN gxg_gtk_color_button_get_use_alpha(XEN color_button)
{
  #define H_gtk_color_button_get_use_alpha "gboolean gtk_color_button_get_use_alpha(GtkColorButton* color_button)"
  XEN_ASSERT_TYPE(XEN_GtkColorButton__P(color_button), color_button, 1, "gtk_color_button_get_use_alpha", "GtkColorButton*");
  return(C_TO_XEN_gboolean(gtk_color_button_get_use_alpha(XEN_TO_C_GtkColorButton_(color_button))));
}
static XEN gxg_gtk_color_button_set_title(XEN color_button, XEN title)
{
  #define H_gtk_color_button_set_title "void gtk_color_button_set_title(GtkColorButton* color_button, \
gchar* title)"
  XEN_ASSERT_TYPE(XEN_GtkColorButton__P(color_button), color_button, 1, "gtk_color_button_set_title", "GtkColorButton*");
  XEN_ASSERT_TYPE(XEN_gchar__P(title), title, 2, "gtk_color_button_set_title", "gchar*");
  gtk_color_button_set_title(XEN_TO_C_GtkColorButton_(color_button), XEN_TO_C_gchar_(title));
  return(XEN_FALSE);
}
static XEN gxg_gtk_color_button_get_title(XEN color_button)
{
  #define H_gtk_color_button_get_title "gchar* gtk_color_button_get_title(GtkColorButton* color_button)"
  XEN_ASSERT_TYPE(XEN_GtkColorButton__P(color_button), color_button, 1, "gtk_color_button_get_title", "GtkColorButton*");
  return(C_TO_XEN_gchar_(gtk_color_button_get_title(XEN_TO_C_GtkColorButton_(color_button))));
}
static XEN gxg_gtk_entry_completion_get_type(void)
{
  #define H_gtk_entry_completion_get_type "GType gtk_entry_completion_get_type( void)"
  return(C_TO_XEN_GType(gtk_entry_completion_get_type()));
}
static XEN gxg_gtk_entry_completion_new(void)
{
  #define H_gtk_entry_completion_new "GtkEntryCompletion* gtk_entry_completion_new( void)"
  return(C_TO_XEN_GtkEntryCompletion_(gtk_entry_completion_new()));
}
static XEN gxg_gtk_entry_completion_get_entry(XEN entry)
{
  #define H_gtk_entry_completion_get_entry "GtkWidget* gtk_entry_completion_get_entry(GtkEntryCompletion* entry)"
  XEN_ASSERT_TYPE(XEN_GtkEntryCompletion__P(entry), entry, 1, "gtk_entry_completion_get_entry", "GtkEntryCompletion*");
  return(C_TO_XEN_GtkWidget_(gtk_entry_completion_get_entry(XEN_TO_C_GtkEntryCompletion_(entry))));
}
static XEN gxg_gtk_entry_completion_set_model(XEN completion, XEN model)
{
  #define H_gtk_entry_completion_set_model "void gtk_entry_completion_set_model(GtkEntryCompletion* completion, \
GtkTreeModel* model)"
  XEN_ASSERT_TYPE(XEN_GtkEntryCompletion__P(completion), completion, 1, "gtk_entry_completion_set_model", "GtkEntryCompletion*");
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(model), model, 2, "gtk_entry_completion_set_model", "GtkTreeModel*");
  gtk_entry_completion_set_model(XEN_TO_C_GtkEntryCompletion_(completion), XEN_TO_C_GtkTreeModel_(model));
  return(XEN_FALSE);
}
static XEN gxg_gtk_entry_completion_get_model(XEN completion)
{
  #define H_gtk_entry_completion_get_model "GtkTreeModel* gtk_entry_completion_get_model(GtkEntryCompletion* completion)"
  XEN_ASSERT_TYPE(XEN_GtkEntryCompletion__P(completion), completion, 1, "gtk_entry_completion_get_model", "GtkEntryCompletion*");
  return(C_TO_XEN_GtkTreeModel_(gtk_entry_completion_get_model(XEN_TO_C_GtkEntryCompletion_(completion))));
}
static XEN gxg_gtk_entry_completion_set_match_func(XEN completion, XEN func, XEN func_data, XEN func_notify)
{
  #define H_gtk_entry_completion_set_match_func "void gtk_entry_completion_set_match_func(GtkEntryCompletion* completion, \
GtkEntryCompletionMatchFunc func, lambda_data func_data, GtkDestroyNotify func_notify)"
  XEN_ASSERT_TYPE(XEN_GtkEntryCompletion__P(completion), completion, 1, "gtk_entry_completion_set_match_func", "GtkEntryCompletion*");
  XEN_ASSERT_TYPE(XEN_GtkEntryCompletionMatchFunc_P(func), func, 2, "gtk_entry_completion_set_match_func", "GtkEntryCompletionMatchFunc");
  XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 3, "gtk_entry_completion_set_match_func", "lambda_data");
  XEN_ASSERT_TYPE(XEN_GtkDestroyNotify_P(func_notify), func_notify, 4, "gtk_entry_completion_set_match_func", "GtkDestroyNotify");
  {
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 3, func_notify);
    gtk_entry_completion_set_match_func(XEN_TO_C_GtkEntryCompletion_(completion), XEN_TO_C_GtkEntryCompletionMatchFunc(func), 
                                    XEN_TO_C_lambda_data(func_data), XEN_TO_C_GtkDestroyNotify(func_notify));
    return(XEN_FALSE);
   }
}
static XEN gxg_gtk_entry_completion_set_minimum_key_length(XEN completion, XEN length)
{
  #define H_gtk_entry_completion_set_minimum_key_length "void gtk_entry_completion_set_minimum_key_length(GtkEntryCompletion* completion, \
gint length)"
  XEN_ASSERT_TYPE(XEN_GtkEntryCompletion__P(completion), completion, 1, "gtk_entry_completion_set_minimum_key_length", "GtkEntryCompletion*");
  XEN_ASSERT_TYPE(XEN_gint_P(length), length, 2, "gtk_entry_completion_set_minimum_key_length", "gint");
  gtk_entry_completion_set_minimum_key_length(XEN_TO_C_GtkEntryCompletion_(completion), XEN_TO_C_gint(length));
  return(XEN_FALSE);
}
static XEN gxg_gtk_entry_completion_get_minimum_key_length(XEN completion)
{
  #define H_gtk_entry_completion_get_minimum_key_length "gint gtk_entry_completion_get_minimum_key_length(GtkEntryCompletion* completion)"
  XEN_ASSERT_TYPE(XEN_GtkEntryCompletion__P(completion), completion, 1, "gtk_entry_completion_get_minimum_key_length", "GtkEntryCompletion*");
  return(C_TO_XEN_gint(gtk_entry_completion_get_minimum_key_length(XEN_TO_C_GtkEntryCompletion_(completion))));
}
static XEN gxg_gtk_entry_completion_complete(XEN completion)
{
  #define H_gtk_entry_completion_complete "void gtk_entry_completion_complete(GtkEntryCompletion* completion)"
  XEN_ASSERT_TYPE(XEN_GtkEntryCompletion__P(completion), completion, 1, "gtk_entry_completion_complete", "GtkEntryCompletion*");
  gtk_entry_completion_complete(XEN_TO_C_GtkEntryCompletion_(completion));
  return(XEN_FALSE);
}
static XEN gxg_gtk_entry_completion_insert_action_text(XEN completion, XEN index, XEN text)
{
  #define H_gtk_entry_completion_insert_action_text "void gtk_entry_completion_insert_action_text(GtkEntryCompletion* completion, \
gint index, gchar* text)"
  XEN_ASSERT_TYPE(XEN_GtkEntryCompletion__P(completion), completion, 1, "gtk_entry_completion_insert_action_text", "GtkEntryCompletion*");
  XEN_ASSERT_TYPE(XEN_gint_P(index), index, 2, "gtk_entry_completion_insert_action_text", "gint");
  XEN_ASSERT_TYPE(XEN_gchar__P(text), text, 3, "gtk_entry_completion_insert_action_text", "gchar*");
  gtk_entry_completion_insert_action_text(XEN_TO_C_GtkEntryCompletion_(completion), XEN_TO_C_gint(index), XEN_TO_C_gchar_(text));
  return(XEN_FALSE);
}
static XEN gxg_gtk_entry_completion_insert_action_markup(XEN completion, XEN index, XEN markup)
{
  #define H_gtk_entry_completion_insert_action_markup "void gtk_entry_completion_insert_action_markup(GtkEntryCompletion* completion, \
gint index, gchar* markup)"
  XEN_ASSERT_TYPE(XEN_GtkEntryCompletion__P(completion), completion, 1, "gtk_entry_completion_insert_action_markup", "GtkEntryCompletion*");
  XEN_ASSERT_TYPE(XEN_gint_P(index), index, 2, "gtk_entry_completion_insert_action_markup", "gint");
  XEN_ASSERT_TYPE(XEN_gchar__P(markup), markup, 3, "gtk_entry_completion_insert_action_markup", "gchar*");
  gtk_entry_completion_insert_action_markup(XEN_TO_C_GtkEntryCompletion_(completion), XEN_TO_C_gint(index), XEN_TO_C_gchar_(markup));
  return(XEN_FALSE);
}
static XEN gxg_gtk_entry_completion_delete_action(XEN completion, XEN index)
{
  #define H_gtk_entry_completion_delete_action "void gtk_entry_completion_delete_action(GtkEntryCompletion* completion, \
gint index)"
  XEN_ASSERT_TYPE(XEN_GtkEntryCompletion__P(completion), completion, 1, "gtk_entry_completion_delete_action", "GtkEntryCompletion*");
  XEN_ASSERT_TYPE(XEN_gint_P(index), index, 2, "gtk_entry_completion_delete_action", "gint");
  gtk_entry_completion_delete_action(XEN_TO_C_GtkEntryCompletion_(completion), XEN_TO_C_gint(index));
  return(XEN_FALSE);
}
static XEN gxg_gtk_entry_completion_set_text_column(XEN completion, XEN column)
{
  #define H_gtk_entry_completion_set_text_column "void gtk_entry_completion_set_text_column(GtkEntryCompletion* completion, \
gint column)"
  XEN_ASSERT_TYPE(XEN_GtkEntryCompletion__P(completion), completion, 1, "gtk_entry_completion_set_text_column", "GtkEntryCompletion*");
  XEN_ASSERT_TYPE(XEN_gint_P(column), column, 2, "gtk_entry_completion_set_text_column", "gint");
  gtk_entry_completion_set_text_column(XEN_TO_C_GtkEntryCompletion_(completion), XEN_TO_C_gint(column));
  return(XEN_FALSE);
}
static XEN gxg_gtk_ui_manager_get_type(void)
{
  #define H_gtk_ui_manager_get_type "GType gtk_ui_manager_get_type( void)"
  return(C_TO_XEN_GType(gtk_ui_manager_get_type()));
}
static XEN gxg_gtk_ui_manager_new(void)
{
  #define H_gtk_ui_manager_new "GtkUIManager* gtk_ui_manager_new( void)"
  return(C_TO_XEN_GtkUIManager_(gtk_ui_manager_new()));
}
static XEN gxg_gtk_ui_manager_set_add_tearoffs(XEN self, XEN add_tearoffs)
{
  #define H_gtk_ui_manager_set_add_tearoffs "void gtk_ui_manager_set_add_tearoffs(GtkUIManager* self, \
gboolean add_tearoffs)"
  XEN_ASSERT_TYPE(XEN_GtkUIManager__P(self), self, 1, "gtk_ui_manager_set_add_tearoffs", "GtkUIManager*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(add_tearoffs), add_tearoffs, 2, "gtk_ui_manager_set_add_tearoffs", "gboolean");
  gtk_ui_manager_set_add_tearoffs(XEN_TO_C_GtkUIManager_(self), XEN_TO_C_gboolean(add_tearoffs));
  return(XEN_FALSE);
}
static XEN gxg_gtk_ui_manager_get_add_tearoffs(XEN self)
{
  #define H_gtk_ui_manager_get_add_tearoffs "gboolean gtk_ui_manager_get_add_tearoffs(GtkUIManager* self)"
  XEN_ASSERT_TYPE(XEN_GtkUIManager__P(self), self, 1, "gtk_ui_manager_get_add_tearoffs", "GtkUIManager*");
  return(C_TO_XEN_gboolean(gtk_ui_manager_get_add_tearoffs(XEN_TO_C_GtkUIManager_(self))));
}
static XEN gxg_gtk_ui_manager_insert_action_group(XEN self, XEN action_group, XEN pos)
{
  #define H_gtk_ui_manager_insert_action_group "void gtk_ui_manager_insert_action_group(GtkUIManager* self, \
GtkActionGroup* action_group, gint pos)"
  XEN_ASSERT_TYPE(XEN_GtkUIManager__P(self), self, 1, "gtk_ui_manager_insert_action_group", "GtkUIManager*");
  XEN_ASSERT_TYPE(XEN_GtkActionGroup__P(action_group), action_group, 2, "gtk_ui_manager_insert_action_group", "GtkActionGroup*");
  XEN_ASSERT_TYPE(XEN_gint_P(pos), pos, 3, "gtk_ui_manager_insert_action_group", "gint");
  gtk_ui_manager_insert_action_group(XEN_TO_C_GtkUIManager_(self), XEN_TO_C_GtkActionGroup_(action_group), XEN_TO_C_gint(pos));
  return(XEN_FALSE);
}
static XEN gxg_gtk_ui_manager_remove_action_group(XEN self, XEN action_group)
{
  #define H_gtk_ui_manager_remove_action_group "void gtk_ui_manager_remove_action_group(GtkUIManager* self, \
GtkActionGroup* action_group)"
  XEN_ASSERT_TYPE(XEN_GtkUIManager__P(self), self, 1, "gtk_ui_manager_remove_action_group", "GtkUIManager*");
  XEN_ASSERT_TYPE(XEN_GtkActionGroup__P(action_group), action_group, 2, "gtk_ui_manager_remove_action_group", "GtkActionGroup*");
  gtk_ui_manager_remove_action_group(XEN_TO_C_GtkUIManager_(self), XEN_TO_C_GtkActionGroup_(action_group));
  return(XEN_FALSE);
}
static XEN gxg_gtk_ui_manager_get_action_groups(XEN self)
{
  #define H_gtk_ui_manager_get_action_groups "GList* gtk_ui_manager_get_action_groups(GtkUIManager* self)"
  XEN_ASSERT_TYPE(XEN_GtkUIManager__P(self), self, 1, "gtk_ui_manager_get_action_groups", "GtkUIManager*");
  return(C_TO_XEN_GList_(gtk_ui_manager_get_action_groups(XEN_TO_C_GtkUIManager_(self))));
}
static XEN gxg_gtk_ui_manager_get_accel_group(XEN self)
{
  #define H_gtk_ui_manager_get_accel_group "GtkAccelGroup* gtk_ui_manager_get_accel_group(GtkUIManager* self)"
  XEN_ASSERT_TYPE(XEN_GtkUIManager__P(self), self, 1, "gtk_ui_manager_get_accel_group", "GtkUIManager*");
  return(C_TO_XEN_GtkAccelGroup_(gtk_ui_manager_get_accel_group(XEN_TO_C_GtkUIManager_(self))));
}
static XEN gxg_gtk_ui_manager_get_widget(XEN self, XEN path)
{
  #define H_gtk_ui_manager_get_widget "GtkWidget* gtk_ui_manager_get_widget(GtkUIManager* self, gchar* path)"
  XEN_ASSERT_TYPE(XEN_GtkUIManager__P(self), self, 1, "gtk_ui_manager_get_widget", "GtkUIManager*");
  XEN_ASSERT_TYPE(XEN_gchar__P(path), path, 2, "gtk_ui_manager_get_widget", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_ui_manager_get_widget(XEN_TO_C_GtkUIManager_(self), XEN_TO_C_gchar_(path))));
}
static XEN gxg_gtk_ui_manager_get_action(XEN self, XEN path)
{
  #define H_gtk_ui_manager_get_action "GtkAction* gtk_ui_manager_get_action(GtkUIManager* self, gchar* path)"
  XEN_ASSERT_TYPE(XEN_GtkUIManager__P(self), self, 1, "gtk_ui_manager_get_action", "GtkUIManager*");
  XEN_ASSERT_TYPE(XEN_gchar__P(path), path, 2, "gtk_ui_manager_get_action", "gchar*");
  return(C_TO_XEN_GtkAction_(gtk_ui_manager_get_action(XEN_TO_C_GtkUIManager_(self), XEN_TO_C_gchar_(path))));
}
static XEN gxg_gtk_ui_manager_add_ui_from_string(XEN self, XEN buffer, XEN length, XEN error)
{
  #define H_gtk_ui_manager_add_ui_from_string "guint gtk_ui_manager_add_ui_from_string(GtkUIManager* self, \
gchar* buffer, gssize length, GError** [error])"
  GError* ref_error = NULL;
  XEN_ASSERT_TYPE(XEN_GtkUIManager__P(self), self, 1, "gtk_ui_manager_add_ui_from_string", "GtkUIManager*");
  XEN_ASSERT_TYPE(XEN_gchar__P(buffer), buffer, 2, "gtk_ui_manager_add_ui_from_string", "gchar*");
  XEN_ASSERT_TYPE(XEN_gssize_P(length), length, 3, "gtk_ui_manager_add_ui_from_string", "gssize");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_guint(gtk_ui_manager_add_ui_from_string(XEN_TO_C_GtkUIManager_(self), XEN_TO_C_gchar_(buffer), XEN_TO_C_gssize(length), 
                                                              &ref_error));
    return(XEN_LIST_2(result, C_TO_XEN_GError_(ref_error)));
   }
}
static XEN gxg_gtk_ui_manager_add_ui_from_file(XEN self, XEN filename, XEN error)
{
  #define H_gtk_ui_manager_add_ui_from_file "guint gtk_ui_manager_add_ui_from_file(GtkUIManager* self, \
gchar* filename, GError** [error])"
  GError* ref_error = NULL;
  XEN_ASSERT_TYPE(XEN_GtkUIManager__P(self), self, 1, "gtk_ui_manager_add_ui_from_file", "GtkUIManager*");
  XEN_ASSERT_TYPE(XEN_gchar__P(filename), filename, 2, "gtk_ui_manager_add_ui_from_file", "gchar*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_guint(gtk_ui_manager_add_ui_from_file(XEN_TO_C_GtkUIManager_(self), XEN_TO_C_gchar_(filename), &ref_error));
    return(XEN_LIST_2(result, C_TO_XEN_GError_(ref_error)));
   }
}
static XEN gxg_gtk_ui_manager_add_ui(XEN self, XEN merge_id, XEN path, XEN name, XEN action, XEN type, XEN top)
{
  #define H_gtk_ui_manager_add_ui "void gtk_ui_manager_add_ui(GtkUIManager* self, guint merge_id, gchar* path, \
gchar* name, gchar* action, GtkUIManagerItemType type, gboolean top)"
  XEN_ASSERT_TYPE(XEN_GtkUIManager__P(self), self, 1, "gtk_ui_manager_add_ui", "GtkUIManager*");
  XEN_ASSERT_TYPE(XEN_guint_P(merge_id), merge_id, 2, "gtk_ui_manager_add_ui", "guint");
  XEN_ASSERT_TYPE(XEN_gchar__P(path), path, 3, "gtk_ui_manager_add_ui", "gchar*");
  XEN_ASSERT_TYPE(XEN_gchar__P(name), name, 4, "gtk_ui_manager_add_ui", "gchar*");
  XEN_ASSERT_TYPE(XEN_gchar__P(action), action, 5, "gtk_ui_manager_add_ui", "gchar*");
  XEN_ASSERT_TYPE(XEN_GtkUIManagerItemType_P(type), type, 6, "gtk_ui_manager_add_ui", "GtkUIManagerItemType");
  XEN_ASSERT_TYPE(XEN_gboolean_P(top), top, 7, "gtk_ui_manager_add_ui", "gboolean");
  gtk_ui_manager_add_ui(XEN_TO_C_GtkUIManager_(self), XEN_TO_C_guint(merge_id), XEN_TO_C_gchar_(path), XEN_TO_C_gchar_(name), 
                        XEN_TO_C_gchar_(action), XEN_TO_C_GtkUIManagerItemType(type), XEN_TO_C_gboolean(top));
  return(XEN_FALSE);
}
static XEN gxg_gtk_ui_manager_remove_ui(XEN self, XEN merge_id)
{
  #define H_gtk_ui_manager_remove_ui "void gtk_ui_manager_remove_ui(GtkUIManager* self, guint merge_id)"
  XEN_ASSERT_TYPE(XEN_GtkUIManager__P(self), self, 1, "gtk_ui_manager_remove_ui", "GtkUIManager*");
  XEN_ASSERT_TYPE(XEN_guint_P(merge_id), merge_id, 2, "gtk_ui_manager_remove_ui", "guint");
  gtk_ui_manager_remove_ui(XEN_TO_C_GtkUIManager_(self), XEN_TO_C_guint(merge_id));
  return(XEN_FALSE);
}
static XEN gxg_gtk_ui_manager_get_ui(XEN self)
{
  #define H_gtk_ui_manager_get_ui "gchar* gtk_ui_manager_get_ui(GtkUIManager* self)"
  XEN_ASSERT_TYPE(XEN_GtkUIManager__P(self), self, 1, "gtk_ui_manager_get_ui", "GtkUIManager*");
  return(C_TO_XEN_gchar_(gtk_ui_manager_get_ui(XEN_TO_C_GtkUIManager_(self))));
}
static XEN gxg_gtk_ui_manager_ensure_update(XEN self)
{
  #define H_gtk_ui_manager_ensure_update "void gtk_ui_manager_ensure_update(GtkUIManager* self)"
  XEN_ASSERT_TYPE(XEN_GtkUIManager__P(self), self, 1, "gtk_ui_manager_ensure_update", "GtkUIManager*");
  gtk_ui_manager_ensure_update(XEN_TO_C_GtkUIManager_(self));
  return(XEN_FALSE);
}
static XEN gxg_gtk_ui_manager_new_merge_id(XEN self)
{
  #define H_gtk_ui_manager_new_merge_id "guint gtk_ui_manager_new_merge_id(GtkUIManager* self)"
  XEN_ASSERT_TYPE(XEN_GtkUIManager__P(self), self, 1, "gtk_ui_manager_new_merge_id", "GtkUIManager*");
  return(C_TO_XEN_guint(gtk_ui_manager_new_merge_id(XEN_TO_C_GtkUIManager_(self))));
}
static XEN gxg_gtk_radio_tool_button_get_type(void)
{
  #define H_gtk_radio_tool_button_get_type "GType gtk_radio_tool_button_get_type( void)"
  return(C_TO_XEN_GType(gtk_radio_tool_button_get_type()));
}
static XEN gxg_gtk_radio_tool_button_new(XEN group)
{
  #define H_gtk_radio_tool_button_new "GtkToolItem* gtk_radio_tool_button_new(GSList* group)"
  XEN_ASSERT_TYPE(XEN_GSList__P(group), group, 1, "gtk_radio_tool_button_new", "GSList*");
  return(C_TO_XEN_GtkToolItem_(gtk_radio_tool_button_new(XEN_TO_C_GSList_(group))));
}
static XEN gxg_gtk_radio_tool_button_new_from_stock(XEN group, XEN stock_id)
{
  #define H_gtk_radio_tool_button_new_from_stock "GtkToolItem* gtk_radio_tool_button_new_from_stock(GSList* group, \
gchar* stock_id)"
  XEN_ASSERT_TYPE(XEN_GSList__P(group), group, 1, "gtk_radio_tool_button_new_from_stock", "GSList*");
  XEN_ASSERT_TYPE(XEN_gchar__P(stock_id), stock_id, 2, "gtk_radio_tool_button_new_from_stock", "gchar*");
  return(C_TO_XEN_GtkToolItem_(gtk_radio_tool_button_new_from_stock(XEN_TO_C_GSList_(group), XEN_TO_C_gchar_(stock_id))));
}
static XEN gxg_gtk_radio_tool_button_get_group(XEN button)
{
  #define H_gtk_radio_tool_button_get_group "GSList* gtk_radio_tool_button_get_group(GtkRadioToolButton* button)"
  XEN_ASSERT_TYPE(XEN_GtkRadioToolButton__P(button), button, 1, "gtk_radio_tool_button_get_group", "GtkRadioToolButton*");
  return(C_TO_XEN_GSList_(gtk_radio_tool_button_get_group(XEN_TO_C_GtkRadioToolButton_(button))));
}
static XEN gxg_gtk_radio_tool_button_set_group(XEN button, XEN group)
{
  #define H_gtk_radio_tool_button_set_group "void gtk_radio_tool_button_set_group(GtkRadioToolButton* button, \
GSList* group)"
  XEN_ASSERT_TYPE(XEN_GtkRadioToolButton__P(button), button, 1, "gtk_radio_tool_button_set_group", "GtkRadioToolButton*");
  XEN_ASSERT_TYPE(XEN_GSList__P(group), group, 2, "gtk_radio_tool_button_set_group", "GSList*");
  gtk_radio_tool_button_set_group(XEN_TO_C_GtkRadioToolButton_(button), XEN_TO_C_GSList_(group));
  return(XEN_FALSE);
}
static XEN gxg_gtk_radio_action_get_type(void)
{
  #define H_gtk_radio_action_get_type "GType gtk_radio_action_get_type( void)"
  return(C_TO_XEN_GType(gtk_radio_action_get_type()));
}
static XEN gxg_gtk_radio_action_get_group(XEN action)
{
  #define H_gtk_radio_action_get_group "GSList* gtk_radio_action_get_group(GtkRadioAction* action)"
  XEN_ASSERT_TYPE(XEN_GtkRadioAction__P(action), action, 1, "gtk_radio_action_get_group", "GtkRadioAction*");
  return(C_TO_XEN_GSList_(gtk_radio_action_get_group(XEN_TO_C_GtkRadioAction_(action))));
}
static XEN gxg_gtk_radio_action_set_group(XEN action, XEN group)
{
  #define H_gtk_radio_action_set_group "void gtk_radio_action_set_group(GtkRadioAction* action, GSList* group)"
  XEN_ASSERT_TYPE(XEN_GtkRadioAction__P(action), action, 1, "gtk_radio_action_set_group", "GtkRadioAction*");
  XEN_ASSERT_TYPE(XEN_GSList__P(group), group, 2, "gtk_radio_action_set_group", "GSList*");
  gtk_radio_action_set_group(XEN_TO_C_GtkRadioAction_(action), XEN_TO_C_GSList_(group));
  return(XEN_FALSE);
}
static XEN gxg_gtk_radio_action_get_current_value(XEN action)
{
  #define H_gtk_radio_action_get_current_value "gint gtk_radio_action_get_current_value(GtkRadioAction* action)"
  XEN_ASSERT_TYPE(XEN_GtkRadioAction__P(action), action, 1, "gtk_radio_action_get_current_value", "GtkRadioAction*");
  return(C_TO_XEN_gint(gtk_radio_action_get_current_value(XEN_TO_C_GtkRadioAction_(action))));
}
static XEN gxg_gtk_separator_tool_item_get_type(void)
{
  #define H_gtk_separator_tool_item_get_type "GType gtk_separator_tool_item_get_type( void)"
  return(C_TO_XEN_GType(gtk_separator_tool_item_get_type()));
}
static XEN gxg_gtk_separator_tool_item_new(void)
{
  #define H_gtk_separator_tool_item_new "GtkToolItem* gtk_separator_tool_item_new( void)"
  return(C_TO_XEN_GtkToolItem_(gtk_separator_tool_item_new()));
}
static XEN gxg_gtk_toggle_action_get_type(void)
{
  #define H_gtk_toggle_action_get_type "GType gtk_toggle_action_get_type( void)"
  return(C_TO_XEN_GType(gtk_toggle_action_get_type()));
}
static XEN gxg_gtk_toggle_action_toggled(XEN action)
{
  #define H_gtk_toggle_action_toggled "void gtk_toggle_action_toggled(GtkToggleAction* action)"
  XEN_ASSERT_TYPE(XEN_GtkToggleAction__P(action), action, 1, "gtk_toggle_action_toggled", "GtkToggleAction*");
  gtk_toggle_action_toggled(XEN_TO_C_GtkToggleAction_(action));
  return(XEN_FALSE);
}
static XEN gxg_gtk_toggle_action_set_active(XEN action, XEN is_active)
{
  #define H_gtk_toggle_action_set_active "void gtk_toggle_action_set_active(GtkToggleAction* action, \
gboolean is_active)"
  XEN_ASSERT_TYPE(XEN_GtkToggleAction__P(action), action, 1, "gtk_toggle_action_set_active", "GtkToggleAction*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(is_active), is_active, 2, "gtk_toggle_action_set_active", "gboolean");
  gtk_toggle_action_set_active(XEN_TO_C_GtkToggleAction_(action), XEN_TO_C_gboolean(is_active));
  return(XEN_FALSE);
}
static XEN gxg_gtk_toggle_action_get_active(XEN action)
{
  #define H_gtk_toggle_action_get_active "gboolean gtk_toggle_action_get_active(GtkToggleAction* action)"
  XEN_ASSERT_TYPE(XEN_GtkToggleAction__P(action), action, 1, "gtk_toggle_action_get_active", "GtkToggleAction*");
  return(C_TO_XEN_gboolean(gtk_toggle_action_get_active(XEN_TO_C_GtkToggleAction_(action))));
}
static XEN gxg_gtk_toggle_action_set_draw_as_radio(XEN action, XEN draw_as_radio)
{
  #define H_gtk_toggle_action_set_draw_as_radio "void gtk_toggle_action_set_draw_as_radio(GtkToggleAction* action, \
gboolean draw_as_radio)"
  XEN_ASSERT_TYPE(XEN_GtkToggleAction__P(action), action, 1, "gtk_toggle_action_set_draw_as_radio", "GtkToggleAction*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(draw_as_radio), draw_as_radio, 2, "gtk_toggle_action_set_draw_as_radio", "gboolean");
  gtk_toggle_action_set_draw_as_radio(XEN_TO_C_GtkToggleAction_(action), XEN_TO_C_gboolean(draw_as_radio));
  return(XEN_FALSE);
}
static XEN gxg_gtk_toggle_action_get_draw_as_radio(XEN action)
{
  #define H_gtk_toggle_action_get_draw_as_radio "gboolean gtk_toggle_action_get_draw_as_radio(GtkToggleAction* action)"
  XEN_ASSERT_TYPE(XEN_GtkToggleAction__P(action), action, 1, "gtk_toggle_action_get_draw_as_radio", "GtkToggleAction*");
  return(C_TO_XEN_gboolean(gtk_toggle_action_get_draw_as_radio(XEN_TO_C_GtkToggleAction_(action))));
}
static XEN gxg_gtk_toggle_tool_button_get_type(void)
{
  #define H_gtk_toggle_tool_button_get_type "GType gtk_toggle_tool_button_get_type( void)"
  return(C_TO_XEN_GType(gtk_toggle_tool_button_get_type()));
}
static XEN gxg_gtk_toggle_tool_button_new(void)
{
  #define H_gtk_toggle_tool_button_new "GtkToolItem* gtk_toggle_tool_button_new( void)"
  return(C_TO_XEN_GtkToolItem_(gtk_toggle_tool_button_new()));
}
static XEN gxg_gtk_toggle_tool_button_new_from_stock(XEN stock_id)
{
  #define H_gtk_toggle_tool_button_new_from_stock "GtkToolItem* gtk_toggle_tool_button_new_from_stock(gchar* stock_id)"
  XEN_ASSERT_TYPE(XEN_gchar__P(stock_id), stock_id, 1, "gtk_toggle_tool_button_new_from_stock", "gchar*");
  return(C_TO_XEN_GtkToolItem_(gtk_toggle_tool_button_new_from_stock(XEN_TO_C_gchar_(stock_id))));
}
static XEN gxg_gtk_toggle_tool_button_set_active(XEN button, XEN is_active)
{
  #define H_gtk_toggle_tool_button_set_active "void gtk_toggle_tool_button_set_active(GtkToggleToolButton* button, \
gboolean is_active)"
  XEN_ASSERT_TYPE(XEN_GtkToggleToolButton__P(button), button, 1, "gtk_toggle_tool_button_set_active", "GtkToggleToolButton*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(is_active), is_active, 2, "gtk_toggle_tool_button_set_active", "gboolean");
  gtk_toggle_tool_button_set_active(XEN_TO_C_GtkToggleToolButton_(button), XEN_TO_C_gboolean(is_active));
  return(XEN_FALSE);
}
static XEN gxg_gtk_toggle_tool_button_get_active(XEN button)
{
  #define H_gtk_toggle_tool_button_get_active "gboolean gtk_toggle_tool_button_get_active(GtkToggleToolButton* button)"
  XEN_ASSERT_TYPE(XEN_GtkToggleToolButton__P(button), button, 1, "gtk_toggle_tool_button_get_active", "GtkToggleToolButton*");
  return(C_TO_XEN_gboolean(gtk_toggle_tool_button_get_active(XEN_TO_C_GtkToggleToolButton_(button))));
}
static XEN gxg_g_timeout_add_full(XEN priority, XEN interval, XEN func, XEN func_data, XEN notify)
{
  #define H_g_timeout_add_full "guint g_timeout_add_full(gint priority, guint interval, GSourceFunc func, \
lambda_data func_data, GtkDestroyNotify notify)"
  XEN_ASSERT_TYPE(XEN_gint_P(priority), priority, 1, "g_timeout_add_full", "gint");
  XEN_ASSERT_TYPE(XEN_guint_P(interval), interval, 2, "g_timeout_add_full", "guint");
  XEN_ASSERT_TYPE(XEN_GSourceFunc_P(func), func, 3, "g_timeout_add_full", "GSourceFunc");
  XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 4, "g_timeout_add_full", "lambda_data");
  XEN_ASSERT_TYPE(XEN_GtkDestroyNotify_P(notify), notify, 5, "g_timeout_add_full", "GtkDestroyNotify");
  {
    XEN result = XEN_FALSE;
    int loc;
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    loc = xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 2, C_TO_XEN_INT(loc));
    XEN_LIST_SET(gxg_ptr, 3, notify);
    result = C_TO_XEN_guint(g_timeout_add_full(XEN_TO_C_gint(priority), XEN_TO_C_guint(interval), XEN_TO_C_GSourceFunc(func), 
                                               XEN_TO_C_lambda_data(func_data), XEN_TO_C_GtkDestroyNotify(notify)));
    XEN_LIST_SET(gxg_ptr, 2, XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("idler"), result, C_TO_XEN_INT(loc)));
    return(result);
   }
}
static XEN gxg_g_timeout_add(XEN interval, XEN func, XEN func_data)
{
  #define H_g_timeout_add "guint g_timeout_add(guint interval, GSourceFunc func, lambda_data func_data)"
  XEN_ASSERT_TYPE(XEN_guint_P(interval), interval, 1, "g_timeout_add", "guint");
  XEN_ASSERT_TYPE(XEN_GSourceFunc_P(func), func, 2, "g_timeout_add", "GSourceFunc");
  if (XEN_NOT_BOUND_P(func_data)) func_data = XEN_FALSE; 
  else XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 3, "g_timeout_add", "lambda_data");
  {
    XEN result = XEN_FALSE;
    int loc;
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    loc = xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 2, C_TO_XEN_INT(loc));
    result = C_TO_XEN_guint(g_timeout_add(XEN_TO_C_guint(interval), XEN_TO_C_GSourceFunc(func), XEN_TO_C_lambda_data(func_data)));
    XEN_LIST_SET(gxg_ptr, 2, XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("idler"), result, C_TO_XEN_INT(loc)));
    return(result);
   }
}
static XEN gxg_g_idle_add(XEN func, XEN func_data)
{
  #define H_g_idle_add "guint g_idle_add(GSourceFunc func, lambda_data func_data)"
  XEN_ASSERT_TYPE(XEN_GSourceFunc_P(func), func, 1, "g_idle_add", "GSourceFunc");
  if (XEN_NOT_BOUND_P(func_data)) func_data = XEN_FALSE; 
  else XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 2, "g_idle_add", "lambda_data");
  {
    XEN result = XEN_FALSE;
    int loc;
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    loc = xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 2, C_TO_XEN_INT(loc));
    result = C_TO_XEN_guint(g_idle_add(XEN_TO_C_GSourceFunc(func), XEN_TO_C_lambda_data(func_data)));
    XEN_LIST_SET(gxg_ptr, 2, XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("idler"), result, C_TO_XEN_INT(loc)));
    return(result);
   }
}
static XEN gxg_g_idle_add_full(XEN priority, XEN func, XEN func_data, XEN notify)
{
  #define H_g_idle_add_full "guint g_idle_add_full(gint priority, GSourceFunc func, lambda_data func_data, \
GtkDestroyNotify notify)"
  XEN_ASSERT_TYPE(XEN_gint_P(priority), priority, 1, "g_idle_add_full", "gint");
  XEN_ASSERT_TYPE(XEN_GSourceFunc_P(func), func, 2, "g_idle_add_full", "GSourceFunc");
  XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 3, "g_idle_add_full", "lambda_data");
  XEN_ASSERT_TYPE(XEN_GtkDestroyNotify_P(notify), notify, 4, "g_idle_add_full", "GtkDestroyNotify");
  {
    XEN result = XEN_FALSE;
    int loc;
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    loc = xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 2, C_TO_XEN_INT(loc));
    XEN_LIST_SET(gxg_ptr, 3, notify);
    result = C_TO_XEN_guint(g_idle_add_full(XEN_TO_C_gint(priority), XEN_TO_C_GSourceFunc(func), XEN_TO_C_lambda_data(func_data), 
                                            XEN_TO_C_GtkDestroyNotify(notify)));
    XEN_LIST_SET(gxg_ptr, 2, XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("idler"), result, C_TO_XEN_INT(loc)));
    return(result);
   }
}
static XEN gxg_g_idle_remove_by_data(XEN data)
{
  #define H_g_idle_remove_by_data "gboolean g_idle_remove_by_data(gpointer data)"
  XEN_ASSERT_TYPE(XEN_gpointer_P(data), data, 1, "g_idle_remove_by_data", "gpointer");
  return(C_TO_XEN_gboolean(g_idle_remove_by_data(XEN_TO_C_gpointer(data))));
  xm_unprotect_at(XEN_TO_C_INT(XEN_CADDR(data)));
}
static XEN gxg_g_source_remove(XEN tag)
{
  #define H_g_source_remove "gboolean g_source_remove(guint tag)"
  XEN_ASSERT_TYPE(XEN_guint_P(tag), tag, 1, "g_source_remove", "guint");
  return(C_TO_XEN_gboolean(g_source_remove(XEN_TO_C_guint(tag))));
  xm_unprotect_at(XEN_TO_C_INT(XEN_CADDR(tag)));
}
static XEN gxg_gtk_file_filter_get_type(void)
{
  #define H_gtk_file_filter_get_type "GType gtk_file_filter_get_type( void)"
  return(C_TO_XEN_GType(gtk_file_filter_get_type()));
}
static XEN gxg_gtk_file_filter_new(void)
{
  #define H_gtk_file_filter_new "GtkFileFilter* gtk_file_filter_new( void)"
  return(C_TO_XEN_GtkFileFilter_(gtk_file_filter_new()));
}
static XEN gxg_gtk_file_filter_set_name(XEN filter, XEN name)
{
  #define H_gtk_file_filter_set_name "void gtk_file_filter_set_name(GtkFileFilter* filter, gchar* name)"
  XEN_ASSERT_TYPE(XEN_GtkFileFilter__P(filter), filter, 1, "gtk_file_filter_set_name", "GtkFileFilter*");
  XEN_ASSERT_TYPE(XEN_gchar__P(name), name, 2, "gtk_file_filter_set_name", "gchar*");
  gtk_file_filter_set_name(XEN_TO_C_GtkFileFilter_(filter), XEN_TO_C_gchar_(name));
  return(XEN_FALSE);
}
static XEN gxg_gtk_file_filter_get_name(XEN filter)
{
  #define H_gtk_file_filter_get_name "gchar* gtk_file_filter_get_name(GtkFileFilter* filter)"
  XEN_ASSERT_TYPE(XEN_GtkFileFilter__P(filter), filter, 1, "gtk_file_filter_get_name", "GtkFileFilter*");
  return(C_TO_XEN_gchar_(gtk_file_filter_get_name(XEN_TO_C_GtkFileFilter_(filter))));
}
static XEN gxg_gtk_file_filter_add_mime_type(XEN filter, XEN mime_type)
{
  #define H_gtk_file_filter_add_mime_type "void gtk_file_filter_add_mime_type(GtkFileFilter* filter, \
gchar* mime_type)"
  XEN_ASSERT_TYPE(XEN_GtkFileFilter__P(filter), filter, 1, "gtk_file_filter_add_mime_type", "GtkFileFilter*");
  XEN_ASSERT_TYPE(XEN_gchar__P(mime_type), mime_type, 2, "gtk_file_filter_add_mime_type", "gchar*");
  gtk_file_filter_add_mime_type(XEN_TO_C_GtkFileFilter_(filter), XEN_TO_C_gchar_(mime_type));
  return(XEN_FALSE);
}
static XEN gxg_gtk_file_filter_add_pattern(XEN filter, XEN pattern)
{
  #define H_gtk_file_filter_add_pattern "void gtk_file_filter_add_pattern(GtkFileFilter* filter, gchar* pattern)"
  XEN_ASSERT_TYPE(XEN_GtkFileFilter__P(filter), filter, 1, "gtk_file_filter_add_pattern", "GtkFileFilter*");
  XEN_ASSERT_TYPE(XEN_gchar__P(pattern), pattern, 2, "gtk_file_filter_add_pattern", "gchar*");
  gtk_file_filter_add_pattern(XEN_TO_C_GtkFileFilter_(filter), XEN_TO_C_gchar_(pattern));
  return(XEN_FALSE);
}
static XEN gxg_gtk_file_filter_add_custom(XEN filter, XEN needed, XEN func, XEN func_data, XEN notify)
{
  #define H_gtk_file_filter_add_custom "void gtk_file_filter_add_custom(GtkFileFilter* filter, GtkFileFilterFlags needed, \
GtkFileFilterFunc func, lambda_data func_data, GtkDestroyNotify notify)"
  XEN_ASSERT_TYPE(XEN_GtkFileFilter__P(filter), filter, 1, "gtk_file_filter_add_custom", "GtkFileFilter*");
  XEN_ASSERT_TYPE(XEN_GtkFileFilterFlags_P(needed), needed, 2, "gtk_file_filter_add_custom", "GtkFileFilterFlags");
  XEN_ASSERT_TYPE(XEN_GtkFileFilterFunc_P(func), func, 3, "gtk_file_filter_add_custom", "GtkFileFilterFunc");
  XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 4, "gtk_file_filter_add_custom", "lambda_data");
  XEN_ASSERT_TYPE(XEN_GtkDestroyNotify_P(notify), notify, 5, "gtk_file_filter_add_custom", "GtkDestroyNotify");
  {
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 3, notify);
    gtk_file_filter_add_custom(XEN_TO_C_GtkFileFilter_(filter), XEN_TO_C_GtkFileFilterFlags(needed), XEN_TO_C_GtkFileFilterFunc(func), 
                           XEN_TO_C_lambda_data(func_data), XEN_TO_C_GtkDestroyNotify(notify));
    return(XEN_FALSE);
   }
}
static XEN gxg_gtk_file_filter_get_needed(XEN filter)
{
  #define H_gtk_file_filter_get_needed "GtkFileFilterFlags gtk_file_filter_get_needed(GtkFileFilter* filter)"
  XEN_ASSERT_TYPE(XEN_GtkFileFilter__P(filter), filter, 1, "gtk_file_filter_get_needed", "GtkFileFilter*");
  return(C_TO_XEN_GtkFileFilterFlags(gtk_file_filter_get_needed(XEN_TO_C_GtkFileFilter_(filter))));
}
static XEN gxg_gtk_file_filter_filter(XEN filter, XEN filter_info)
{
  #define H_gtk_file_filter_filter "gboolean gtk_file_filter_filter(GtkFileFilter* filter, GtkFileFilterInfo* filter_info)"
  XEN_ASSERT_TYPE(XEN_GtkFileFilter__P(filter), filter, 1, "gtk_file_filter_filter", "GtkFileFilter*");
  XEN_ASSERT_TYPE(XEN_GtkFileFilterInfo__P(filter_info), filter_info, 2, "gtk_file_filter_filter", "GtkFileFilterInfo*");
  return(C_TO_XEN_gboolean(gtk_file_filter_filter(XEN_TO_C_GtkFileFilter_(filter), XEN_TO_C_GtkFileFilterInfo_(filter_info))));
}
static XEN gxg_gtk_cell_layout_get_type(void)
{
  #define H_gtk_cell_layout_get_type "GType gtk_cell_layout_get_type( void)"
  return(C_TO_XEN_GType(gtk_cell_layout_get_type()));
}
static XEN gxg_gtk_cell_layout_pack_start(XEN cell_layout, XEN cell, XEN expand)
{
  #define H_gtk_cell_layout_pack_start "void gtk_cell_layout_pack_start(GtkCellLayout* cell_layout, GtkCellRenderer* cell, \
gboolean expand)"
  XEN_ASSERT_TYPE(XEN_GtkCellLayout__P(cell_layout), cell_layout, 1, "gtk_cell_layout_pack_start", "GtkCellLayout*");
  XEN_ASSERT_TYPE(XEN_GtkCellRenderer__P(cell), cell, 2, "gtk_cell_layout_pack_start", "GtkCellRenderer*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(expand), expand, 3, "gtk_cell_layout_pack_start", "gboolean");
  gtk_cell_layout_pack_start(XEN_TO_C_GtkCellLayout_(cell_layout), XEN_TO_C_GtkCellRenderer_(cell), XEN_TO_C_gboolean(expand));
  return(XEN_FALSE);
}
static XEN gxg_gtk_cell_layout_pack_end(XEN cell_layout, XEN cell, XEN expand)
{
  #define H_gtk_cell_layout_pack_end "void gtk_cell_layout_pack_end(GtkCellLayout* cell_layout, GtkCellRenderer* cell, \
gboolean expand)"
  XEN_ASSERT_TYPE(XEN_GtkCellLayout__P(cell_layout), cell_layout, 1, "gtk_cell_layout_pack_end", "GtkCellLayout*");
  XEN_ASSERT_TYPE(XEN_GtkCellRenderer__P(cell), cell, 2, "gtk_cell_layout_pack_end", "GtkCellRenderer*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(expand), expand, 3, "gtk_cell_layout_pack_end", "gboolean");
  gtk_cell_layout_pack_end(XEN_TO_C_GtkCellLayout_(cell_layout), XEN_TO_C_GtkCellRenderer_(cell), XEN_TO_C_gboolean(expand));
  return(XEN_FALSE);
}
static XEN gxg_gtk_cell_layout_clear(XEN cell_layout)
{
  #define H_gtk_cell_layout_clear "void gtk_cell_layout_clear(GtkCellLayout* cell_layout)"
  XEN_ASSERT_TYPE(XEN_GtkCellLayout__P(cell_layout), cell_layout, 1, "gtk_cell_layout_clear", "GtkCellLayout*");
  gtk_cell_layout_clear(XEN_TO_C_GtkCellLayout_(cell_layout));
  return(XEN_FALSE);
}
static XEN gxg_gtk_cell_layout_set_attributes(XEN cell_layout, XEN cell, XEN attributes)
{
  #define H_gtk_cell_layout_set_attributes "void gtk_cell_layout_set_attributes(GtkCellLayout* cell_layout, \
GtkCellRenderer* cell, etc attributes)"
  XEN_ASSERT_TYPE(XEN_GtkCellLayout__P(cell_layout), cell_layout, 1, "gtk_cell_layout_set_attributes", "GtkCellLayout*");
  XEN_ASSERT_TYPE(XEN_GtkCellRenderer__P(cell), cell, 2, "gtk_cell_layout_set_attributes", "GtkCellRenderer*");
  XEN_ASSERT_TYPE(XEN_etc_P(attributes), attributes, 3, "gtk_cell_layout_set_attributes", "etc");
  {
    int etc_len = 0;
    GtkCellLayout* p_arg0;
    GtkCellRenderer* p_arg1;
    if (XEN_LIST_P(attributes)) etc_len = XEN_LIST_LENGTH(attributes);
    if (etc_len < 2) XEN_OUT_OF_RANGE_ERROR("gtk_cell_layout_set_attributes", 2, attributes, "... list must have at least 2 entries");
    if (etc_len > 10) XEN_OUT_OF_RANGE_ERROR("gtk_cell_layout_set_attributes", 2, attributes, "... list too long (max len: 10)");
    if ((etc_len % 2) != 0) XEN_OUT_OF_RANGE_ERROR("gtk_cell_layout_set_attributes", 2, attributes, "... list len must be multiple of 2");
    p_arg0 = XEN_TO_C_GtkCellLayout_(cell_layout);
    p_arg1 = XEN_TO_C_GtkCellRenderer_(cell);
    switch (etc_len)
      {
        case 2: gtk_cell_layout_set_attributes(p_arg0, p_arg1, XLS(attributes, 0), XLI(attributes, 1), NULL); break;
        case 4: gtk_cell_layout_set_attributes(p_arg0, p_arg1, XLS(attributes, 0), XLI(attributes, 1), XLS(attributes, 2), XLI(attributes, 3), NULL); break;
        case 6: gtk_cell_layout_set_attributes(p_arg0, p_arg1, XLS(attributes, 0), XLI(attributes, 1), XLS(attributes, 2), XLI(attributes, 3), XLS(attributes, 4), XLI(attributes, 5), NULL); break;
        case 8: gtk_cell_layout_set_attributes(p_arg0, p_arg1, XLS(attributes, 0), XLI(attributes, 1), XLS(attributes, 2), XLI(attributes, 3), XLS(attributes, 4), XLI(attributes, 5), XLS(attributes, 6), XLI(attributes, 7), NULL); break;
        case 10: gtk_cell_layout_set_attributes(p_arg0, p_arg1, XLS(attributes, 0), XLI(attributes, 1), XLS(attributes, 2), XLI(attributes, 3), XLS(attributes, 4), XLI(attributes, 5), XLS(attributes, 6), XLI(attributes, 7), XLS(attributes, 8), XLI(attributes, 9), NULL); break;
      }
    return(XEN_FALSE);
  }
}
static XEN gxg_gtk_cell_layout_add_attribute(XEN cell_layout, XEN cell, XEN attribute, XEN column)
{
  #define H_gtk_cell_layout_add_attribute "void gtk_cell_layout_add_attribute(GtkCellLayout* cell_layout, \
GtkCellRenderer* cell, gchar* attribute, gint column)"
  XEN_ASSERT_TYPE(XEN_GtkCellLayout__P(cell_layout), cell_layout, 1, "gtk_cell_layout_add_attribute", "GtkCellLayout*");
  XEN_ASSERT_TYPE(XEN_GtkCellRenderer__P(cell), cell, 2, "gtk_cell_layout_add_attribute", "GtkCellRenderer*");
  XEN_ASSERT_TYPE(XEN_gchar__P(attribute), attribute, 3, "gtk_cell_layout_add_attribute", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(column), column, 4, "gtk_cell_layout_add_attribute", "gint");
  gtk_cell_layout_add_attribute(XEN_TO_C_GtkCellLayout_(cell_layout), XEN_TO_C_GtkCellRenderer_(cell), XEN_TO_C_gchar_(attribute), 
                                XEN_TO_C_gint(column));
  return(XEN_FALSE);
}
static XEN gxg_gtk_cell_layout_set_cell_data_func(XEN cell_layout, XEN cell, XEN func, XEN func_data, XEN destroy)
{
  #define H_gtk_cell_layout_set_cell_data_func "void gtk_cell_layout_set_cell_data_func(GtkCellLayout* cell_layout, \
GtkCellRenderer* cell, GtkCellLayoutDataFunc func, lambda_data func_data, GtkDestroyNotify destroy)"
  XEN_ASSERT_TYPE(XEN_GtkCellLayout__P(cell_layout), cell_layout, 1, "gtk_cell_layout_set_cell_data_func", "GtkCellLayout*");
  XEN_ASSERT_TYPE(XEN_GtkCellRenderer__P(cell), cell, 2, "gtk_cell_layout_set_cell_data_func", "GtkCellRenderer*");
  XEN_ASSERT_TYPE(XEN_GtkCellLayoutDataFunc_P(func), func, 3, "gtk_cell_layout_set_cell_data_func", "GtkCellLayoutDataFunc");
  XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 4, "gtk_cell_layout_set_cell_data_func", "lambda_data");
  XEN_ASSERT_TYPE(XEN_GtkDestroyNotify_P(destroy), destroy, 5, "gtk_cell_layout_set_cell_data_func", "GtkDestroyNotify");
  {
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 3, destroy);
    gtk_cell_layout_set_cell_data_func(XEN_TO_C_GtkCellLayout_(cell_layout), XEN_TO_C_GtkCellRenderer_(cell), XEN_TO_C_GtkCellLayoutDataFunc(func), 
                                   XEN_TO_C_lambda_data(func_data), XEN_TO_C_GtkDestroyNotify(destroy));
    return(XEN_FALSE);
   }
}
static XEN gxg_gtk_cell_layout_clear_attributes(XEN cell_layout, XEN cell)
{
  #define H_gtk_cell_layout_clear_attributes "void gtk_cell_layout_clear_attributes(GtkCellLayout* cell_layout, \
GtkCellRenderer* cell)"
  XEN_ASSERT_TYPE(XEN_GtkCellLayout__P(cell_layout), cell_layout, 1, "gtk_cell_layout_clear_attributes", "GtkCellLayout*");
  XEN_ASSERT_TYPE(XEN_GtkCellRenderer__P(cell), cell, 2, "gtk_cell_layout_clear_attributes", "GtkCellRenderer*");
  gtk_cell_layout_clear_attributes(XEN_TO_C_GtkCellLayout_(cell_layout), XEN_TO_C_GtkCellRenderer_(cell));
  return(XEN_FALSE);
}
static XEN gxg_gtk_file_chooser_get_type(void)
{
  #define H_gtk_file_chooser_get_type "GType gtk_file_chooser_get_type( void)"
  return(C_TO_XEN_GType(gtk_file_chooser_get_type()));
}
static XEN gxg_gtk_file_chooser_set_action(XEN chooser, XEN action)
{
  #define H_gtk_file_chooser_set_action "void gtk_file_chooser_set_action(GtkFileChooser* chooser, GtkFileChooserAction action)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_set_action", "GtkFileChooser*");
  XEN_ASSERT_TYPE(XEN_GtkFileChooserAction_P(action), action, 2, "gtk_file_chooser_set_action", "GtkFileChooserAction");
  gtk_file_chooser_set_action(XEN_TO_C_GtkFileChooser_(chooser), XEN_TO_C_GtkFileChooserAction(action));
  return(XEN_FALSE);
}
static XEN gxg_gtk_file_chooser_get_action(XEN chooser)
{
  #define H_gtk_file_chooser_get_action "GtkFileChooserAction gtk_file_chooser_get_action(GtkFileChooser* chooser)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_get_action", "GtkFileChooser*");
  return(C_TO_XEN_GtkFileChooserAction(gtk_file_chooser_get_action(XEN_TO_C_GtkFileChooser_(chooser))));
}
static XEN gxg_gtk_file_chooser_set_local_only(XEN chooser, XEN files_only)
{
  #define H_gtk_file_chooser_set_local_only "void gtk_file_chooser_set_local_only(GtkFileChooser* chooser, \
gboolean files_only)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_set_local_only", "GtkFileChooser*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(files_only), files_only, 2, "gtk_file_chooser_set_local_only", "gboolean");
  gtk_file_chooser_set_local_only(XEN_TO_C_GtkFileChooser_(chooser), XEN_TO_C_gboolean(files_only));
  return(XEN_FALSE);
}
static XEN gxg_gtk_file_chooser_get_local_only(XEN chooser)
{
  #define H_gtk_file_chooser_get_local_only "gboolean gtk_file_chooser_get_local_only(GtkFileChooser* chooser)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_get_local_only", "GtkFileChooser*");
  return(C_TO_XEN_gboolean(gtk_file_chooser_get_local_only(XEN_TO_C_GtkFileChooser_(chooser))));
}
static XEN gxg_gtk_file_chooser_set_select_multiple(XEN chooser, XEN select_multiple)
{
  #define H_gtk_file_chooser_set_select_multiple "void gtk_file_chooser_set_select_multiple(GtkFileChooser* chooser, \
gboolean select_multiple)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_set_select_multiple", "GtkFileChooser*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(select_multiple), select_multiple, 2, "gtk_file_chooser_set_select_multiple", "gboolean");
  gtk_file_chooser_set_select_multiple(XEN_TO_C_GtkFileChooser_(chooser), XEN_TO_C_gboolean(select_multiple));
  return(XEN_FALSE);
}
static XEN gxg_gtk_file_chooser_get_select_multiple(XEN chooser)
{
  #define H_gtk_file_chooser_get_select_multiple "gboolean gtk_file_chooser_get_select_multiple(GtkFileChooser* chooser)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_get_select_multiple", "GtkFileChooser*");
  return(C_TO_XEN_gboolean(gtk_file_chooser_get_select_multiple(XEN_TO_C_GtkFileChooser_(chooser))));
}
static XEN gxg_gtk_file_chooser_set_current_name(XEN chooser, XEN name)
{
  #define H_gtk_file_chooser_set_current_name "void gtk_file_chooser_set_current_name(GtkFileChooser* chooser, \
gchar* name)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_set_current_name", "GtkFileChooser*");
  XEN_ASSERT_TYPE(XEN_gchar__P(name), name, 2, "gtk_file_chooser_set_current_name", "gchar*");
  gtk_file_chooser_set_current_name(XEN_TO_C_GtkFileChooser_(chooser), XEN_TO_C_gchar_(name));
  return(XEN_FALSE);
}
static XEN gxg_gtk_file_chooser_get_filename(XEN chooser)
{
  #define H_gtk_file_chooser_get_filename "gchar* gtk_file_chooser_get_filename(GtkFileChooser* chooser)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_get_filename", "GtkFileChooser*");
  return(C_TO_XEN_gchar_(gtk_file_chooser_get_filename(XEN_TO_C_GtkFileChooser_(chooser))));
}
static XEN gxg_gtk_file_chooser_unselect_filename(XEN chooser, XEN filename)
{
  #define H_gtk_file_chooser_unselect_filename "void gtk_file_chooser_unselect_filename(GtkFileChooser* chooser, \
char* filename)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_unselect_filename", "GtkFileChooser*");
  XEN_ASSERT_TYPE(XEN_char__P(filename), filename, 2, "gtk_file_chooser_unselect_filename", "char*");
  gtk_file_chooser_unselect_filename(XEN_TO_C_GtkFileChooser_(chooser), XEN_TO_C_char_(filename));
  return(XEN_FALSE);
}
static XEN gxg_gtk_file_chooser_select_all(XEN chooser)
{
  #define H_gtk_file_chooser_select_all "void gtk_file_chooser_select_all(GtkFileChooser* chooser)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_select_all", "GtkFileChooser*");
  gtk_file_chooser_select_all(XEN_TO_C_GtkFileChooser_(chooser));
  return(XEN_FALSE);
}
static XEN gxg_gtk_file_chooser_unselect_all(XEN chooser)
{
  #define H_gtk_file_chooser_unselect_all "void gtk_file_chooser_unselect_all(GtkFileChooser* chooser)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_unselect_all", "GtkFileChooser*");
  gtk_file_chooser_unselect_all(XEN_TO_C_GtkFileChooser_(chooser));
  return(XEN_FALSE);
}
static XEN gxg_gtk_file_chooser_get_filenames(XEN chooser)
{
  #define H_gtk_file_chooser_get_filenames "GSList* gtk_file_chooser_get_filenames(GtkFileChooser* chooser)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_get_filenames", "GtkFileChooser*");
  return(C_TO_XEN_GSList_(gtk_file_chooser_get_filenames(XEN_TO_C_GtkFileChooser_(chooser))));
}
static XEN gxg_gtk_file_chooser_get_current_folder(XEN chooser)
{
  #define H_gtk_file_chooser_get_current_folder "gchar* gtk_file_chooser_get_current_folder(GtkFileChooser* chooser)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_get_current_folder", "GtkFileChooser*");
  return(C_TO_XEN_gchar_(gtk_file_chooser_get_current_folder(XEN_TO_C_GtkFileChooser_(chooser))));
}
static XEN gxg_gtk_file_chooser_get_uri(XEN chooser)
{
  #define H_gtk_file_chooser_get_uri "gchar* gtk_file_chooser_get_uri(GtkFileChooser* chooser)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_get_uri", "GtkFileChooser*");
  return(C_TO_XEN_gchar_(gtk_file_chooser_get_uri(XEN_TO_C_GtkFileChooser_(chooser))));
}
static XEN gxg_gtk_file_chooser_unselect_uri(XEN chooser, XEN uri)
{
  #define H_gtk_file_chooser_unselect_uri "void gtk_file_chooser_unselect_uri(GtkFileChooser* chooser, \
char* uri)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_unselect_uri", "GtkFileChooser*");
  XEN_ASSERT_TYPE(XEN_char__P(uri), uri, 2, "gtk_file_chooser_unselect_uri", "char*");
  gtk_file_chooser_unselect_uri(XEN_TO_C_GtkFileChooser_(chooser), XEN_TO_C_char_(uri));
  return(XEN_FALSE);
}
static XEN gxg_gtk_file_chooser_get_uris(XEN chooser)
{
  #define H_gtk_file_chooser_get_uris "GSList* gtk_file_chooser_get_uris(GtkFileChooser* chooser)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_get_uris", "GtkFileChooser*");
  return(C_TO_XEN_GSList_(gtk_file_chooser_get_uris(XEN_TO_C_GtkFileChooser_(chooser))));
}
static XEN gxg_gtk_file_chooser_get_current_folder_uri(XEN chooser)
{
  #define H_gtk_file_chooser_get_current_folder_uri "gchar* gtk_file_chooser_get_current_folder_uri(GtkFileChooser* chooser)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_get_current_folder_uri", "GtkFileChooser*");
  return(C_TO_XEN_gchar_(gtk_file_chooser_get_current_folder_uri(XEN_TO_C_GtkFileChooser_(chooser))));
}
static XEN gxg_gtk_file_chooser_set_preview_widget(XEN chooser, XEN preview_widget)
{
  #define H_gtk_file_chooser_set_preview_widget "void gtk_file_chooser_set_preview_widget(GtkFileChooser* chooser, \
GtkWidget* preview_widget)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_set_preview_widget", "GtkFileChooser*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(preview_widget), preview_widget, 2, "gtk_file_chooser_set_preview_widget", "GtkWidget*");
  gtk_file_chooser_set_preview_widget(XEN_TO_C_GtkFileChooser_(chooser), XEN_TO_C_GtkWidget_(preview_widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_file_chooser_get_preview_widget(XEN chooser)
{
  #define H_gtk_file_chooser_get_preview_widget "GtkWidget* gtk_file_chooser_get_preview_widget(GtkFileChooser* chooser)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_get_preview_widget", "GtkFileChooser*");
  return(C_TO_XEN_GtkWidget_(gtk_file_chooser_get_preview_widget(XEN_TO_C_GtkFileChooser_(chooser))));
}
static XEN gxg_gtk_file_chooser_set_preview_widget_active(XEN chooser, XEN active)
{
  #define H_gtk_file_chooser_set_preview_widget_active "void gtk_file_chooser_set_preview_widget_active(GtkFileChooser* chooser, \
gboolean active)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_set_preview_widget_active", "GtkFileChooser*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(active), active, 2, "gtk_file_chooser_set_preview_widget_active", "gboolean");
  gtk_file_chooser_set_preview_widget_active(XEN_TO_C_GtkFileChooser_(chooser), XEN_TO_C_gboolean(active));
  return(XEN_FALSE);
}
static XEN gxg_gtk_file_chooser_get_preview_widget_active(XEN chooser)
{
  #define H_gtk_file_chooser_get_preview_widget_active "gboolean gtk_file_chooser_get_preview_widget_active(GtkFileChooser* chooser)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_get_preview_widget_active", "GtkFileChooser*");
  return(C_TO_XEN_gboolean(gtk_file_chooser_get_preview_widget_active(XEN_TO_C_GtkFileChooser_(chooser))));
}
static XEN gxg_gtk_file_chooser_get_preview_filename(XEN file_chooser)
{
  #define H_gtk_file_chooser_get_preview_filename "char* gtk_file_chooser_get_preview_filename(GtkFileChooser* file_chooser)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(file_chooser), file_chooser, 1, "gtk_file_chooser_get_preview_filename", "GtkFileChooser*");
  return(C_TO_XEN_char_(gtk_file_chooser_get_preview_filename(XEN_TO_C_GtkFileChooser_(file_chooser))));
}
static XEN gxg_gtk_file_chooser_get_preview_uri(XEN file_chooser)
{
  #define H_gtk_file_chooser_get_preview_uri "char* gtk_file_chooser_get_preview_uri(GtkFileChooser* file_chooser)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(file_chooser), file_chooser, 1, "gtk_file_chooser_get_preview_uri", "GtkFileChooser*");
  return(C_TO_XEN_char_(gtk_file_chooser_get_preview_uri(XEN_TO_C_GtkFileChooser_(file_chooser))));
}
static XEN gxg_gtk_file_chooser_set_extra_widget(XEN chooser, XEN extra_widget)
{
  #define H_gtk_file_chooser_set_extra_widget "void gtk_file_chooser_set_extra_widget(GtkFileChooser* chooser, \
GtkWidget* extra_widget)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_set_extra_widget", "GtkFileChooser*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(extra_widget), extra_widget, 2, "gtk_file_chooser_set_extra_widget", "GtkWidget*");
  gtk_file_chooser_set_extra_widget(XEN_TO_C_GtkFileChooser_(chooser), XEN_TO_C_GtkWidget_(extra_widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_file_chooser_get_extra_widget(XEN chooser)
{
  #define H_gtk_file_chooser_get_extra_widget "GtkWidget* gtk_file_chooser_get_extra_widget(GtkFileChooser* chooser)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_get_extra_widget", "GtkFileChooser*");
  return(C_TO_XEN_GtkWidget_(gtk_file_chooser_get_extra_widget(XEN_TO_C_GtkFileChooser_(chooser))));
}
static XEN gxg_gtk_file_chooser_add_filter(XEN chooser, XEN filter)
{
  #define H_gtk_file_chooser_add_filter "void gtk_file_chooser_add_filter(GtkFileChooser* chooser, GtkFileFilter* filter)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_add_filter", "GtkFileChooser*");
  XEN_ASSERT_TYPE(XEN_GtkFileFilter__P(filter), filter, 2, "gtk_file_chooser_add_filter", "GtkFileFilter*");
  gtk_file_chooser_add_filter(XEN_TO_C_GtkFileChooser_(chooser), XEN_TO_C_GtkFileFilter_(filter));
  return(XEN_FALSE);
}
static XEN gxg_gtk_file_chooser_remove_filter(XEN chooser, XEN filter)
{
  #define H_gtk_file_chooser_remove_filter "void gtk_file_chooser_remove_filter(GtkFileChooser* chooser, \
GtkFileFilter* filter)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_remove_filter", "GtkFileChooser*");
  XEN_ASSERT_TYPE(XEN_GtkFileFilter__P(filter), filter, 2, "gtk_file_chooser_remove_filter", "GtkFileFilter*");
  gtk_file_chooser_remove_filter(XEN_TO_C_GtkFileChooser_(chooser), XEN_TO_C_GtkFileFilter_(filter));
  return(XEN_FALSE);
}
static XEN gxg_gtk_file_chooser_list_filters(XEN chooser)
{
  #define H_gtk_file_chooser_list_filters "GSList* gtk_file_chooser_list_filters(GtkFileChooser* chooser)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_list_filters", "GtkFileChooser*");
  return(C_TO_XEN_GSList_(gtk_file_chooser_list_filters(XEN_TO_C_GtkFileChooser_(chooser))));
}
static XEN gxg_gtk_file_chooser_set_filter(XEN chooser, XEN filter)
{
  #define H_gtk_file_chooser_set_filter "void gtk_file_chooser_set_filter(GtkFileChooser* chooser, GtkFileFilter* filter)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_set_filter", "GtkFileChooser*");
  XEN_ASSERT_TYPE(XEN_GtkFileFilter__P(filter), filter, 2, "gtk_file_chooser_set_filter", "GtkFileFilter*");
  gtk_file_chooser_set_filter(XEN_TO_C_GtkFileChooser_(chooser), XEN_TO_C_GtkFileFilter_(filter));
  return(XEN_FALSE);
}
static XEN gxg_gtk_file_chooser_get_filter(XEN chooser)
{
  #define H_gtk_file_chooser_get_filter "GtkFileFilter* gtk_file_chooser_get_filter(GtkFileChooser* chooser)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_get_filter", "GtkFileChooser*");
  return(C_TO_XEN_GtkFileFilter_(gtk_file_chooser_get_filter(XEN_TO_C_GtkFileChooser_(chooser))));
}
static XEN gxg_gtk_file_chooser_add_shortcut_folder(XEN chooser, XEN folder, XEN error)
{
  #define H_gtk_file_chooser_add_shortcut_folder "gboolean gtk_file_chooser_add_shortcut_folder(GtkFileChooser* chooser, \
char* folder, GError** [error])"
  GError* ref_error = NULL;
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_add_shortcut_folder", "GtkFileChooser*");
  XEN_ASSERT_TYPE(XEN_char__P(folder), folder, 2, "gtk_file_chooser_add_shortcut_folder", "char*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gtk_file_chooser_add_shortcut_folder(XEN_TO_C_GtkFileChooser_(chooser), XEN_TO_C_char_(folder), 
                                                                    &ref_error));
    return(XEN_LIST_2(result, C_TO_XEN_GError_(ref_error)));
   }
}
static XEN gxg_gtk_file_chooser_remove_shortcut_folder(XEN chooser, XEN folder, XEN error)
{
  #define H_gtk_file_chooser_remove_shortcut_folder "gboolean gtk_file_chooser_remove_shortcut_folder(GtkFileChooser* chooser, \
char* folder, GError** [error])"
  GError* ref_error = NULL;
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_remove_shortcut_folder", "GtkFileChooser*");
  XEN_ASSERT_TYPE(XEN_char__P(folder), folder, 2, "gtk_file_chooser_remove_shortcut_folder", "char*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gtk_file_chooser_remove_shortcut_folder(XEN_TO_C_GtkFileChooser_(chooser), XEN_TO_C_char_(folder), 
                                                                       &ref_error));
    return(XEN_LIST_2(result, C_TO_XEN_GError_(ref_error)));
   }
}
static XEN gxg_gtk_file_chooser_list_shortcut_folders(XEN chooser)
{
  #define H_gtk_file_chooser_list_shortcut_folders "GSList* gtk_file_chooser_list_shortcut_folders(GtkFileChooser* chooser)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_list_shortcut_folders", "GtkFileChooser*");
  return(C_TO_XEN_GSList_(gtk_file_chooser_list_shortcut_folders(XEN_TO_C_GtkFileChooser_(chooser))));
}
static XEN gxg_gtk_file_chooser_add_shortcut_folder_uri(XEN chooser, XEN folder, XEN error)
{
  #define H_gtk_file_chooser_add_shortcut_folder_uri "gboolean gtk_file_chooser_add_shortcut_folder_uri(GtkFileChooser* chooser, \
char* folder, GError** [error])"
  GError* ref_error = NULL;
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_add_shortcut_folder_uri", "GtkFileChooser*");
  XEN_ASSERT_TYPE(XEN_char__P(folder), folder, 2, "gtk_file_chooser_add_shortcut_folder_uri", "char*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gtk_file_chooser_add_shortcut_folder_uri(XEN_TO_C_GtkFileChooser_(chooser), XEN_TO_C_char_(folder), 
                                                                        &ref_error));
    return(XEN_LIST_2(result, C_TO_XEN_GError_(ref_error)));
   }
}
static XEN gxg_gtk_file_chooser_remove_shortcut_folder_uri(XEN chooser, XEN folder, XEN error)
{
  #define H_gtk_file_chooser_remove_shortcut_folder_uri "gboolean gtk_file_chooser_remove_shortcut_folder_uri(GtkFileChooser* chooser, \
char* folder, GError** [error])"
  GError* ref_error = NULL;
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_remove_shortcut_folder_uri", "GtkFileChooser*");
  XEN_ASSERT_TYPE(XEN_char__P(folder), folder, 2, "gtk_file_chooser_remove_shortcut_folder_uri", "char*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gtk_file_chooser_remove_shortcut_folder_uri(XEN_TO_C_GtkFileChooser_(chooser), XEN_TO_C_char_(folder), 
                                                                           &ref_error));
    return(XEN_LIST_2(result, C_TO_XEN_GError_(ref_error)));
   }
}
static XEN gxg_gtk_file_chooser_list_shortcut_folder_uris(XEN chooser)
{
  #define H_gtk_file_chooser_list_shortcut_folder_uris "GSList* gtk_file_chooser_list_shortcut_folder_uris(GtkFileChooser* chooser)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_list_shortcut_folder_uris", "GtkFileChooser*");
  return(C_TO_XEN_GSList_(gtk_file_chooser_list_shortcut_folder_uris(XEN_TO_C_GtkFileChooser_(chooser))));
}
static XEN gxg_gtk_icon_theme_get_type(void)
{
  #define H_gtk_icon_theme_get_type "GType gtk_icon_theme_get_type( void)"
  return(C_TO_XEN_GType(gtk_icon_theme_get_type()));
}
static XEN gxg_gtk_icon_theme_new(void)
{
  #define H_gtk_icon_theme_new "GtkIconTheme* gtk_icon_theme_new( void)"
  return(C_TO_XEN_GtkIconTheme_(gtk_icon_theme_new()));
}
static XEN gxg_gtk_icon_theme_get_default(void)
{
  #define H_gtk_icon_theme_get_default "GtkIconTheme* gtk_icon_theme_get_default( void)"
  return(C_TO_XEN_GtkIconTheme_(gtk_icon_theme_get_default()));
}
static XEN gxg_gtk_icon_theme_get_for_screen(XEN screen)
{
  #define H_gtk_icon_theme_get_for_screen "GtkIconTheme* gtk_icon_theme_get_for_screen(GdkScreen* screen)"
  XEN_ASSERT_TYPE(XEN_GdkScreen__P(screen), screen, 1, "gtk_icon_theme_get_for_screen", "GdkScreen*");
  return(C_TO_XEN_GtkIconTheme_(gtk_icon_theme_get_for_screen(XEN_TO_C_GdkScreen_(screen))));
}
static XEN gxg_gtk_icon_theme_set_screen(XEN icon_theme, XEN screen)
{
  #define H_gtk_icon_theme_set_screen "void gtk_icon_theme_set_screen(GtkIconTheme* icon_theme, GdkScreen* screen)"
  XEN_ASSERT_TYPE(XEN_GtkIconTheme__P(icon_theme), icon_theme, 1, "gtk_icon_theme_set_screen", "GtkIconTheme*");
  XEN_ASSERT_TYPE(XEN_GdkScreen__P(screen), screen, 2, "gtk_icon_theme_set_screen", "GdkScreen*");
  gtk_icon_theme_set_screen(XEN_TO_C_GtkIconTheme_(icon_theme), XEN_TO_C_GdkScreen_(screen));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_theme_get_search_path(XEN icon_theme, XEN path, XEN n_elements)
{
  #define H_gtk_icon_theme_get_search_path "void gtk_icon_theme_get_search_path(GtkIconTheme* icon_theme, \
gchar*** [path], gint* [n_elements])"
  gchar** ref_path = NULL;
  gint ref_n_elements;
  XEN_ASSERT_TYPE(XEN_GtkIconTheme__P(icon_theme), icon_theme, 1, "gtk_icon_theme_get_search_path", "GtkIconTheme*");
  gtk_icon_theme_get_search_path(XEN_TO_C_GtkIconTheme_(icon_theme), &ref_path, &ref_n_elements);
  return(XEN_LIST_2(C_TO_XEN_gchar__(ref_path), C_TO_XEN_gint(ref_n_elements)));
}
static XEN gxg_gtk_icon_theme_append_search_path(XEN icon_theme, XEN path)
{
  #define H_gtk_icon_theme_append_search_path "void gtk_icon_theme_append_search_path(GtkIconTheme* icon_theme, \
gchar* path)"
  XEN_ASSERT_TYPE(XEN_GtkIconTheme__P(icon_theme), icon_theme, 1, "gtk_icon_theme_append_search_path", "GtkIconTheme*");
  XEN_ASSERT_TYPE(XEN_gchar__P(path), path, 2, "gtk_icon_theme_append_search_path", "gchar*");
  gtk_icon_theme_append_search_path(XEN_TO_C_GtkIconTheme_(icon_theme), XEN_TO_C_gchar_(path));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_theme_prepend_search_path(XEN icon_theme, XEN path)
{
  #define H_gtk_icon_theme_prepend_search_path "void gtk_icon_theme_prepend_search_path(GtkIconTheme* icon_theme, \
gchar* path)"
  XEN_ASSERT_TYPE(XEN_GtkIconTheme__P(icon_theme), icon_theme, 1, "gtk_icon_theme_prepend_search_path", "GtkIconTheme*");
  XEN_ASSERT_TYPE(XEN_gchar__P(path), path, 2, "gtk_icon_theme_prepend_search_path", "gchar*");
  gtk_icon_theme_prepend_search_path(XEN_TO_C_GtkIconTheme_(icon_theme), XEN_TO_C_gchar_(path));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_theme_set_custom_theme(XEN icon_theme, XEN theme_name)
{
  #define H_gtk_icon_theme_set_custom_theme "void gtk_icon_theme_set_custom_theme(GtkIconTheme* icon_theme, \
gchar* theme_name)"
  XEN_ASSERT_TYPE(XEN_GtkIconTheme__P(icon_theme), icon_theme, 1, "gtk_icon_theme_set_custom_theme", "GtkIconTheme*");
  XEN_ASSERT_TYPE(XEN_gchar__P(theme_name), theme_name, 2, "gtk_icon_theme_set_custom_theme", "gchar*");
  gtk_icon_theme_set_custom_theme(XEN_TO_C_GtkIconTheme_(icon_theme), XEN_TO_C_gchar_(theme_name));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_theme_has_icon(XEN icon_theme, XEN icon_name)
{
  #define H_gtk_icon_theme_has_icon "gboolean gtk_icon_theme_has_icon(GtkIconTheme* icon_theme, gchar* icon_name)"
  XEN_ASSERT_TYPE(XEN_GtkIconTheme__P(icon_theme), icon_theme, 1, "gtk_icon_theme_has_icon", "GtkIconTheme*");
  XEN_ASSERT_TYPE(XEN_gchar__P(icon_name), icon_name, 2, "gtk_icon_theme_has_icon", "gchar*");
  return(C_TO_XEN_gboolean(gtk_icon_theme_has_icon(XEN_TO_C_GtkIconTheme_(icon_theme), XEN_TO_C_gchar_(icon_name))));
}
static XEN gxg_gtk_icon_theme_lookup_icon(XEN icon_theme, XEN icon_name, XEN size, XEN flags)
{
  #define H_gtk_icon_theme_lookup_icon "GtkIconInfo* gtk_icon_theme_lookup_icon(GtkIconTheme* icon_theme, \
gchar* icon_name, gint size, GtkIconLookupFlags flags)"
  XEN_ASSERT_TYPE(XEN_GtkIconTheme__P(icon_theme), icon_theme, 1, "gtk_icon_theme_lookup_icon", "GtkIconTheme*");
  XEN_ASSERT_TYPE(XEN_gchar__P(icon_name), icon_name, 2, "gtk_icon_theme_lookup_icon", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(size), size, 3, "gtk_icon_theme_lookup_icon", "gint");
  XEN_ASSERT_TYPE(XEN_GtkIconLookupFlags_P(flags), flags, 4, "gtk_icon_theme_lookup_icon", "GtkIconLookupFlags");
  return(C_TO_XEN_GtkIconInfo_(gtk_icon_theme_lookup_icon(XEN_TO_C_GtkIconTheme_(icon_theme), XEN_TO_C_gchar_(icon_name), 
                                                          XEN_TO_C_gint(size), XEN_TO_C_GtkIconLookupFlags(flags))));
}
static XEN gxg_gtk_icon_theme_load_icon(XEN icon_theme, XEN icon_name, XEN size, XEN flags, XEN error)
{
  #define H_gtk_icon_theme_load_icon "GdkPixbuf* gtk_icon_theme_load_icon(GtkIconTheme* icon_theme, gchar* icon_name, \
gint size, GtkIconLookupFlags flags, GError** [error])"
  GError* ref_error = NULL;
  XEN_ASSERT_TYPE(XEN_GtkIconTheme__P(icon_theme), icon_theme, 1, "gtk_icon_theme_load_icon", "GtkIconTheme*");
  XEN_ASSERT_TYPE(XEN_gchar__P(icon_name), icon_name, 2, "gtk_icon_theme_load_icon", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(size), size, 3, "gtk_icon_theme_load_icon", "gint");
  XEN_ASSERT_TYPE(XEN_GtkIconLookupFlags_P(flags), flags, 4, "gtk_icon_theme_load_icon", "GtkIconLookupFlags");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_GdkPixbuf_(gtk_icon_theme_load_icon(XEN_TO_C_GtkIconTheme_(icon_theme), XEN_TO_C_gchar_(icon_name), 
                                                          XEN_TO_C_gint(size), XEN_TO_C_GtkIconLookupFlags(flags), &ref_error));
    return(XEN_LIST_2(result, C_TO_XEN_GError_(ref_error)));
   }
}
static XEN gxg_gtk_icon_theme_list_icons(XEN icon_theme, XEN context)
{
  #define H_gtk_icon_theme_list_icons "GList* gtk_icon_theme_list_icons(GtkIconTheme* icon_theme, gchar* context)"
  XEN_ASSERT_TYPE(XEN_GtkIconTheme__P(icon_theme), icon_theme, 1, "gtk_icon_theme_list_icons", "GtkIconTheme*");
  XEN_ASSERT_TYPE(XEN_gchar__P(context), context, 2, "gtk_icon_theme_list_icons", "gchar*");
  return(C_TO_XEN_GList_(gtk_icon_theme_list_icons(XEN_TO_C_GtkIconTheme_(icon_theme), XEN_TO_C_gchar_(context))));
}
static XEN gxg_gtk_icon_theme_get_example_icon_name(XEN icon_theme)
{
  #define H_gtk_icon_theme_get_example_icon_name "char* gtk_icon_theme_get_example_icon_name(GtkIconTheme* icon_theme)"
  XEN_ASSERT_TYPE(XEN_GtkIconTheme__P(icon_theme), icon_theme, 1, "gtk_icon_theme_get_example_icon_name", "GtkIconTheme*");
  return(C_TO_XEN_char_(gtk_icon_theme_get_example_icon_name(XEN_TO_C_GtkIconTheme_(icon_theme))));
}
static XEN gxg_gtk_icon_theme_rescan_if_needed(XEN icon_theme)
{
  #define H_gtk_icon_theme_rescan_if_needed "gboolean gtk_icon_theme_rescan_if_needed(GtkIconTheme* icon_theme)"
  XEN_ASSERT_TYPE(XEN_GtkIconTheme__P(icon_theme), icon_theme, 1, "gtk_icon_theme_rescan_if_needed", "GtkIconTheme*");
  return(C_TO_XEN_gboolean(gtk_icon_theme_rescan_if_needed(XEN_TO_C_GtkIconTheme_(icon_theme))));
}
static XEN gxg_gtk_icon_theme_add_builtin_icon(XEN icon_name, XEN size, XEN pixbuf)
{
  #define H_gtk_icon_theme_add_builtin_icon "void gtk_icon_theme_add_builtin_icon(gchar* icon_name, gint size, \
GdkPixbuf* pixbuf)"
  XEN_ASSERT_TYPE(XEN_gchar__P(icon_name), icon_name, 1, "gtk_icon_theme_add_builtin_icon", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(size), size, 2, "gtk_icon_theme_add_builtin_icon", "gint");
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(pixbuf), pixbuf, 3, "gtk_icon_theme_add_builtin_icon", "GdkPixbuf*");
  gtk_icon_theme_add_builtin_icon(XEN_TO_C_gchar_(icon_name), XEN_TO_C_gint(size), XEN_TO_C_GdkPixbuf_(pixbuf));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_info_get_type(void)
{
  #define H_gtk_icon_info_get_type "GType gtk_icon_info_get_type( void)"
  return(C_TO_XEN_GType(gtk_icon_info_get_type()));
}
static XEN gxg_gtk_icon_info_copy(XEN icon_info)
{
  #define H_gtk_icon_info_copy "GtkIconInfo* gtk_icon_info_copy(GtkIconInfo* icon_info)"
  XEN_ASSERT_TYPE(XEN_GtkIconInfo__P(icon_info), icon_info, 1, "gtk_icon_info_copy", "GtkIconInfo*");
  return(C_TO_XEN_GtkIconInfo_(gtk_icon_info_copy(XEN_TO_C_GtkIconInfo_(icon_info))));
}
static XEN gxg_gtk_icon_info_free(XEN icon_info)
{
  #define H_gtk_icon_info_free "void gtk_icon_info_free(GtkIconInfo* icon_info)"
  XEN_ASSERT_TYPE(XEN_GtkIconInfo__P(icon_info), icon_info, 1, "gtk_icon_info_free", "GtkIconInfo*");
  gtk_icon_info_free(XEN_TO_C_GtkIconInfo_(icon_info));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_info_get_base_size(XEN icon_info)
{
  #define H_gtk_icon_info_get_base_size "gint gtk_icon_info_get_base_size(GtkIconInfo* icon_info)"
  XEN_ASSERT_TYPE(XEN_GtkIconInfo__P(icon_info), icon_info, 1, "gtk_icon_info_get_base_size", "GtkIconInfo*");
  return(C_TO_XEN_gint(gtk_icon_info_get_base_size(XEN_TO_C_GtkIconInfo_(icon_info))));
}
static XEN gxg_gtk_icon_info_get_filename(XEN icon_info)
{
  #define H_gtk_icon_info_get_filename "gchar* gtk_icon_info_get_filename(GtkIconInfo* icon_info)"
  XEN_ASSERT_TYPE(XEN_GtkIconInfo__P(icon_info), icon_info, 1, "gtk_icon_info_get_filename", "GtkIconInfo*");
  return(C_TO_XEN_gchar_(gtk_icon_info_get_filename(XEN_TO_C_GtkIconInfo_(icon_info))));
}
static XEN gxg_gtk_icon_info_get_builtin_pixbuf(XEN icon_info)
{
  #define H_gtk_icon_info_get_builtin_pixbuf "GdkPixbuf* gtk_icon_info_get_builtin_pixbuf(GtkIconInfo* icon_info)"
  XEN_ASSERT_TYPE(XEN_GtkIconInfo__P(icon_info), icon_info, 1, "gtk_icon_info_get_builtin_pixbuf", "GtkIconInfo*");
  return(C_TO_XEN_GdkPixbuf_(gtk_icon_info_get_builtin_pixbuf(XEN_TO_C_GtkIconInfo_(icon_info))));
}
static XEN gxg_gtk_icon_info_load_icon(XEN icon_info, XEN error)
{
  #define H_gtk_icon_info_load_icon "GdkPixbuf* gtk_icon_info_load_icon(GtkIconInfo* icon_info, GError** [error])"
  GError* ref_error = NULL;
  XEN_ASSERT_TYPE(XEN_GtkIconInfo__P(icon_info), icon_info, 1, "gtk_icon_info_load_icon", "GtkIconInfo*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_GdkPixbuf_(gtk_icon_info_load_icon(XEN_TO_C_GtkIconInfo_(icon_info), &ref_error));
    return(XEN_LIST_2(result, C_TO_XEN_GError_(ref_error)));
   }
}
static XEN gxg_gtk_icon_info_set_raw_coordinates(XEN icon_info, XEN raw_coordinates)
{
  #define H_gtk_icon_info_set_raw_coordinates "void gtk_icon_info_set_raw_coordinates(GtkIconInfo* icon_info, \
gboolean raw_coordinates)"
  XEN_ASSERT_TYPE(XEN_GtkIconInfo__P(icon_info), icon_info, 1, "gtk_icon_info_set_raw_coordinates", "GtkIconInfo*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(raw_coordinates), raw_coordinates, 2, "gtk_icon_info_set_raw_coordinates", "gboolean");
  gtk_icon_info_set_raw_coordinates(XEN_TO_C_GtkIconInfo_(icon_info), XEN_TO_C_gboolean(raw_coordinates));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_info_get_embedded_rect(XEN icon_info, XEN rectangle)
{
  #define H_gtk_icon_info_get_embedded_rect "gboolean gtk_icon_info_get_embedded_rect(GtkIconInfo* icon_info, \
GdkRectangle* rectangle)"
  XEN_ASSERT_TYPE(XEN_GtkIconInfo__P(icon_info), icon_info, 1, "gtk_icon_info_get_embedded_rect", "GtkIconInfo*");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(rectangle), rectangle, 2, "gtk_icon_info_get_embedded_rect", "GdkRectangle*");
  return(C_TO_XEN_gboolean(gtk_icon_info_get_embedded_rect(XEN_TO_C_GtkIconInfo_(icon_info), XEN_TO_C_GdkRectangle_(rectangle))));
}
static XEN gxg_gtk_icon_info_get_attach_points(XEN icon_info, XEN points, XEN n_points)
{
  #define H_gtk_icon_info_get_attach_points "gboolean gtk_icon_info_get_attach_points(GtkIconInfo* icon_info, \
GdkPoint** [points], gint* [n_points])"
  GdkPoint* ref_points = NULL;
  gint ref_n_points;
  XEN_ASSERT_TYPE(XEN_GtkIconInfo__P(icon_info), icon_info, 1, "gtk_icon_info_get_attach_points", "GtkIconInfo*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gtk_icon_info_get_attach_points(XEN_TO_C_GtkIconInfo_(icon_info), &ref_points, &ref_n_points));
    return(XEN_LIST_3(result, C_TO_XEN_GdkPoint_(ref_points), C_TO_XEN_gint(ref_n_points)));
   }
}
static XEN gxg_gtk_icon_info_get_display_name(XEN icon_info)
{
  #define H_gtk_icon_info_get_display_name "gchar* gtk_icon_info_get_display_name(GtkIconInfo* icon_info)"
  XEN_ASSERT_TYPE(XEN_GtkIconInfo__P(icon_info), icon_info, 1, "gtk_icon_info_get_display_name", "GtkIconInfo*");
  return(C_TO_XEN_gchar_(gtk_icon_info_get_display_name(XEN_TO_C_GtkIconInfo_(icon_info))));
}
static XEN gxg_gtk_tool_button_get_type(void)
{
  #define H_gtk_tool_button_get_type "GType gtk_tool_button_get_type( void)"
  return(C_TO_XEN_GType(gtk_tool_button_get_type()));
}
static XEN gxg_gtk_tool_button_new(XEN icon_widget, XEN label)
{
  #define H_gtk_tool_button_new "GtkToolItem* gtk_tool_button_new(GtkWidget* icon_widget, gchar* label)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(icon_widget), icon_widget, 1, "gtk_tool_button_new", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 2, "gtk_tool_button_new", "gchar*");
  return(C_TO_XEN_GtkToolItem_(gtk_tool_button_new(XEN_TO_C_GtkWidget_(icon_widget), XEN_TO_C_gchar_(label))));
}
static XEN gxg_gtk_tool_button_new_from_stock(XEN stock_id)
{
  #define H_gtk_tool_button_new_from_stock "GtkToolItem* gtk_tool_button_new_from_stock(gchar* stock_id)"
  XEN_ASSERT_TYPE(XEN_gchar__P(stock_id), stock_id, 1, "gtk_tool_button_new_from_stock", "gchar*");
  return(C_TO_XEN_GtkToolItem_(gtk_tool_button_new_from_stock(XEN_TO_C_gchar_(stock_id))));
}
static XEN gxg_gtk_tool_button_set_label(XEN button, XEN label)
{
  #define H_gtk_tool_button_set_label "void gtk_tool_button_set_label(GtkToolButton* button, gchar* label)"
  XEN_ASSERT_TYPE(XEN_GtkToolButton__P(button), button, 1, "gtk_tool_button_set_label", "GtkToolButton*");
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 2, "gtk_tool_button_set_label", "gchar*");
  gtk_tool_button_set_label(XEN_TO_C_GtkToolButton_(button), XEN_TO_C_gchar_(label));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tool_button_get_label(XEN button)
{
  #define H_gtk_tool_button_get_label "gchar* gtk_tool_button_get_label(GtkToolButton* button)"
  XEN_ASSERT_TYPE(XEN_GtkToolButton__P(button), button, 1, "gtk_tool_button_get_label", "GtkToolButton*");
  return(C_TO_XEN_gchar_(gtk_tool_button_get_label(XEN_TO_C_GtkToolButton_(button))));
}
static XEN gxg_gtk_tool_button_set_use_underline(XEN button, XEN use_underline)
{
  #define H_gtk_tool_button_set_use_underline "void gtk_tool_button_set_use_underline(GtkToolButton* button, \
gboolean use_underline)"
  XEN_ASSERT_TYPE(XEN_GtkToolButton__P(button), button, 1, "gtk_tool_button_set_use_underline", "GtkToolButton*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(use_underline), use_underline, 2, "gtk_tool_button_set_use_underline", "gboolean");
  gtk_tool_button_set_use_underline(XEN_TO_C_GtkToolButton_(button), XEN_TO_C_gboolean(use_underline));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tool_button_get_use_underline(XEN button)
{
  #define H_gtk_tool_button_get_use_underline "gboolean gtk_tool_button_get_use_underline(GtkToolButton* button)"
  XEN_ASSERT_TYPE(XEN_GtkToolButton__P(button), button, 1, "gtk_tool_button_get_use_underline", "GtkToolButton*");
  return(C_TO_XEN_gboolean(gtk_tool_button_get_use_underline(XEN_TO_C_GtkToolButton_(button))));
}
static XEN gxg_gtk_tool_button_set_stock_id(XEN button, XEN stock_id)
{
  #define H_gtk_tool_button_set_stock_id "void gtk_tool_button_set_stock_id(GtkToolButton* button, gchar* stock_id)"
  XEN_ASSERT_TYPE(XEN_GtkToolButton__P(button), button, 1, "gtk_tool_button_set_stock_id", "GtkToolButton*");
  XEN_ASSERT_TYPE(XEN_gchar__P(stock_id), stock_id, 2, "gtk_tool_button_set_stock_id", "gchar*");
  gtk_tool_button_set_stock_id(XEN_TO_C_GtkToolButton_(button), XEN_TO_C_gchar_(stock_id));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tool_button_get_stock_id(XEN button)
{
  #define H_gtk_tool_button_get_stock_id "gchar* gtk_tool_button_get_stock_id(GtkToolButton* button)"
  XEN_ASSERT_TYPE(XEN_GtkToolButton__P(button), button, 1, "gtk_tool_button_get_stock_id", "GtkToolButton*");
  return(C_TO_XEN_gchar_(gtk_tool_button_get_stock_id(XEN_TO_C_GtkToolButton_(button))));
}
static XEN gxg_gtk_tool_button_set_icon_widget(XEN button, XEN icon_widget)
{
  #define H_gtk_tool_button_set_icon_widget "void gtk_tool_button_set_icon_widget(GtkToolButton* button, \
GtkWidget* icon_widget)"
  XEN_ASSERT_TYPE(XEN_GtkToolButton__P(button), button, 1, "gtk_tool_button_set_icon_widget", "GtkToolButton*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(icon_widget), icon_widget, 2, "gtk_tool_button_set_icon_widget", "GtkWidget*");
  gtk_tool_button_set_icon_widget(XEN_TO_C_GtkToolButton_(button), XEN_TO_C_GtkWidget_(icon_widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tool_button_get_icon_widget(XEN button)
{
  #define H_gtk_tool_button_get_icon_widget "GtkWidget* gtk_tool_button_get_icon_widget(GtkToolButton* button)"
  XEN_ASSERT_TYPE(XEN_GtkToolButton__P(button), button, 1, "gtk_tool_button_get_icon_widget", "GtkToolButton*");
  return(C_TO_XEN_GtkWidget_(gtk_tool_button_get_icon_widget(XEN_TO_C_GtkToolButton_(button))));
}
static XEN gxg_gtk_tool_button_set_label_widget(XEN button, XEN label_widget)
{
  #define H_gtk_tool_button_set_label_widget "void gtk_tool_button_set_label_widget(GtkToolButton* button, \
GtkWidget* label_widget)"
  XEN_ASSERT_TYPE(XEN_GtkToolButton__P(button), button, 1, "gtk_tool_button_set_label_widget", "GtkToolButton*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(label_widget), label_widget, 2, "gtk_tool_button_set_label_widget", "GtkWidget*");
  gtk_tool_button_set_label_widget(XEN_TO_C_GtkToolButton_(button), XEN_TO_C_GtkWidget_(label_widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tool_button_get_label_widget(XEN button)
{
  #define H_gtk_tool_button_get_label_widget "GtkWidget* gtk_tool_button_get_label_widget(GtkToolButton* button)"
  XEN_ASSERT_TYPE(XEN_GtkToolButton__P(button), button, 1, "gtk_tool_button_get_label_widget", "GtkToolButton*");
  return(C_TO_XEN_GtkWidget_(gtk_tool_button_get_label_widget(XEN_TO_C_GtkToolButton_(button))));
}
static XEN gxg_gtk_tool_item_get_type(void)
{
  #define H_gtk_tool_item_get_type "GType gtk_tool_item_get_type( void)"
  return(C_TO_XEN_GType(gtk_tool_item_get_type()));
}
static XEN gxg_gtk_tool_item_new(void)
{
  #define H_gtk_tool_item_new "GtkToolItem* gtk_tool_item_new( void)"
  return(C_TO_XEN_GtkToolItem_(gtk_tool_item_new()));
}
static XEN gxg_gtk_tool_item_set_homogeneous(XEN tool_item, XEN homogeneous)
{
  #define H_gtk_tool_item_set_homogeneous "void gtk_tool_item_set_homogeneous(GtkToolItem* tool_item, \
gboolean homogeneous)"
  XEN_ASSERT_TYPE(XEN_GtkToolItem__P(tool_item), tool_item, 1, "gtk_tool_item_set_homogeneous", "GtkToolItem*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(homogeneous), homogeneous, 2, "gtk_tool_item_set_homogeneous", "gboolean");
  gtk_tool_item_set_homogeneous(XEN_TO_C_GtkToolItem_(tool_item), XEN_TO_C_gboolean(homogeneous));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tool_item_get_homogeneous(XEN tool_item)
{
  #define H_gtk_tool_item_get_homogeneous "gboolean gtk_tool_item_get_homogeneous(GtkToolItem* tool_item)"
  XEN_ASSERT_TYPE(XEN_GtkToolItem__P(tool_item), tool_item, 1, "gtk_tool_item_get_homogeneous", "GtkToolItem*");
  return(C_TO_XEN_gboolean(gtk_tool_item_get_homogeneous(XEN_TO_C_GtkToolItem_(tool_item))));
}
static XEN gxg_gtk_tool_item_set_expand(XEN tool_item, XEN expand)
{
  #define H_gtk_tool_item_set_expand "void gtk_tool_item_set_expand(GtkToolItem* tool_item, gboolean expand)"
  XEN_ASSERT_TYPE(XEN_GtkToolItem__P(tool_item), tool_item, 1, "gtk_tool_item_set_expand", "GtkToolItem*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(expand), expand, 2, "gtk_tool_item_set_expand", "gboolean");
  gtk_tool_item_set_expand(XEN_TO_C_GtkToolItem_(tool_item), XEN_TO_C_gboolean(expand));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tool_item_get_expand(XEN tool_item)
{
  #define H_gtk_tool_item_get_expand "gboolean gtk_tool_item_get_expand(GtkToolItem* tool_item)"
  XEN_ASSERT_TYPE(XEN_GtkToolItem__P(tool_item), tool_item, 1, "gtk_tool_item_get_expand", "GtkToolItem*");
  return(C_TO_XEN_gboolean(gtk_tool_item_get_expand(XEN_TO_C_GtkToolItem_(tool_item))));
}
static XEN gxg_gtk_tool_item_set_tooltip(XEN tool_item, XEN tooltips, XEN tip_text, XEN tip_private)
{
  #define H_gtk_tool_item_set_tooltip "void gtk_tool_item_set_tooltip(GtkToolItem* tool_item, GtkTooltips* tooltips, \
gchar* tip_text, gchar* tip_private)"
  XEN_ASSERT_TYPE(XEN_GtkToolItem__P(tool_item), tool_item, 1, "gtk_tool_item_set_tooltip", "GtkToolItem*");
  XEN_ASSERT_TYPE(XEN_GtkTooltips__P(tooltips), tooltips, 2, "gtk_tool_item_set_tooltip", "GtkTooltips*");
  XEN_ASSERT_TYPE(XEN_gchar__P(tip_text), tip_text, 3, "gtk_tool_item_set_tooltip", "gchar*");
  XEN_ASSERT_TYPE(XEN_gchar__P(tip_private), tip_private, 4, "gtk_tool_item_set_tooltip", "gchar*");
  gtk_tool_item_set_tooltip(XEN_TO_C_GtkToolItem_(tool_item), XEN_TO_C_GtkTooltips_(tooltips), XEN_TO_C_gchar_(tip_text), 
                            XEN_TO_C_gchar_(tip_private));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tool_item_set_use_drag_window(XEN toolitem, XEN use_drag_window)
{
  #define H_gtk_tool_item_set_use_drag_window "void gtk_tool_item_set_use_drag_window(GtkToolItem* toolitem, \
gboolean use_drag_window)"
  XEN_ASSERT_TYPE(XEN_GtkToolItem__P(toolitem), toolitem, 1, "gtk_tool_item_set_use_drag_window", "GtkToolItem*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(use_drag_window), use_drag_window, 2, "gtk_tool_item_set_use_drag_window", "gboolean");
  gtk_tool_item_set_use_drag_window(XEN_TO_C_GtkToolItem_(toolitem), XEN_TO_C_gboolean(use_drag_window));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tool_item_get_use_drag_window(XEN toolitem)
{
  #define H_gtk_tool_item_get_use_drag_window "gboolean gtk_tool_item_get_use_drag_window(GtkToolItem* toolitem)"
  XEN_ASSERT_TYPE(XEN_GtkToolItem__P(toolitem), toolitem, 1, "gtk_tool_item_get_use_drag_window", "GtkToolItem*");
  return(C_TO_XEN_gboolean(gtk_tool_item_get_use_drag_window(XEN_TO_C_GtkToolItem_(toolitem))));
}
static XEN gxg_gtk_tool_item_set_visible_horizontal(XEN toolitem, XEN visible_horizontal)
{
  #define H_gtk_tool_item_set_visible_horizontal "void gtk_tool_item_set_visible_horizontal(GtkToolItem* toolitem, \
gboolean visible_horizontal)"
  XEN_ASSERT_TYPE(XEN_GtkToolItem__P(toolitem), toolitem, 1, "gtk_tool_item_set_visible_horizontal", "GtkToolItem*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(visible_horizontal), visible_horizontal, 2, "gtk_tool_item_set_visible_horizontal", "gboolean");
  gtk_tool_item_set_visible_horizontal(XEN_TO_C_GtkToolItem_(toolitem), XEN_TO_C_gboolean(visible_horizontal));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tool_item_get_visible_horizontal(XEN toolitem)
{
  #define H_gtk_tool_item_get_visible_horizontal "gboolean gtk_tool_item_get_visible_horizontal(GtkToolItem* toolitem)"
  XEN_ASSERT_TYPE(XEN_GtkToolItem__P(toolitem), toolitem, 1, "gtk_tool_item_get_visible_horizontal", "GtkToolItem*");
  return(C_TO_XEN_gboolean(gtk_tool_item_get_visible_horizontal(XEN_TO_C_GtkToolItem_(toolitem))));
}
static XEN gxg_gtk_tool_item_set_visible_vertical(XEN toolitem, XEN visible_vertical)
{
  #define H_gtk_tool_item_set_visible_vertical "void gtk_tool_item_set_visible_vertical(GtkToolItem* toolitem, \
gboolean visible_vertical)"
  XEN_ASSERT_TYPE(XEN_GtkToolItem__P(toolitem), toolitem, 1, "gtk_tool_item_set_visible_vertical", "GtkToolItem*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(visible_vertical), visible_vertical, 2, "gtk_tool_item_set_visible_vertical", "gboolean");
  gtk_tool_item_set_visible_vertical(XEN_TO_C_GtkToolItem_(toolitem), XEN_TO_C_gboolean(visible_vertical));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tool_item_get_visible_vertical(XEN toolitem)
{
  #define H_gtk_tool_item_get_visible_vertical "gboolean gtk_tool_item_get_visible_vertical(GtkToolItem* toolitem)"
  XEN_ASSERT_TYPE(XEN_GtkToolItem__P(toolitem), toolitem, 1, "gtk_tool_item_get_visible_vertical", "GtkToolItem*");
  return(C_TO_XEN_gboolean(gtk_tool_item_get_visible_vertical(XEN_TO_C_GtkToolItem_(toolitem))));
}
static XEN gxg_gtk_tool_item_get_is_important(XEN tool_item)
{
  #define H_gtk_tool_item_get_is_important "gboolean gtk_tool_item_get_is_important(GtkToolItem* tool_item)"
  XEN_ASSERT_TYPE(XEN_GtkToolItem__P(tool_item), tool_item, 1, "gtk_tool_item_get_is_important", "GtkToolItem*");
  return(C_TO_XEN_gboolean(gtk_tool_item_get_is_important(XEN_TO_C_GtkToolItem_(tool_item))));
}
static XEN gxg_gtk_tool_item_set_is_important(XEN tool_item, XEN is_important)
{
  #define H_gtk_tool_item_set_is_important "void gtk_tool_item_set_is_important(GtkToolItem* tool_item, \
gboolean is_important)"
  XEN_ASSERT_TYPE(XEN_GtkToolItem__P(tool_item), tool_item, 1, "gtk_tool_item_set_is_important", "GtkToolItem*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(is_important), is_important, 2, "gtk_tool_item_set_is_important", "gboolean");
  gtk_tool_item_set_is_important(XEN_TO_C_GtkToolItem_(tool_item), XEN_TO_C_gboolean(is_important));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tool_item_get_icon_size(XEN tool_item)
{
  #define H_gtk_tool_item_get_icon_size "GtkIconSize gtk_tool_item_get_icon_size(GtkToolItem* tool_item)"
  XEN_ASSERT_TYPE(XEN_GtkToolItem__P(tool_item), tool_item, 1, "gtk_tool_item_get_icon_size", "GtkToolItem*");
  return(C_TO_XEN_GtkIconSize(gtk_tool_item_get_icon_size(XEN_TO_C_GtkToolItem_(tool_item))));
}
static XEN gxg_gtk_tool_item_get_orientation(XEN tool_item)
{
  #define H_gtk_tool_item_get_orientation "GtkOrientation gtk_tool_item_get_orientation(GtkToolItem* tool_item)"
  XEN_ASSERT_TYPE(XEN_GtkToolItem__P(tool_item), tool_item, 1, "gtk_tool_item_get_orientation", "GtkToolItem*");
  return(C_TO_XEN_GtkOrientation(gtk_tool_item_get_orientation(XEN_TO_C_GtkToolItem_(tool_item))));
}
static XEN gxg_gtk_tool_item_get_toolbar_style(XEN tool_item)
{
  #define H_gtk_tool_item_get_toolbar_style "GtkToolbarStyle gtk_tool_item_get_toolbar_style(GtkToolItem* tool_item)"
  XEN_ASSERT_TYPE(XEN_GtkToolItem__P(tool_item), tool_item, 1, "gtk_tool_item_get_toolbar_style", "GtkToolItem*");
  return(C_TO_XEN_GtkToolbarStyle(gtk_tool_item_get_toolbar_style(XEN_TO_C_GtkToolItem_(tool_item))));
}
static XEN gxg_gtk_tool_item_get_relief_style(XEN tool_item)
{
  #define H_gtk_tool_item_get_relief_style "GtkReliefStyle gtk_tool_item_get_relief_style(GtkToolItem* tool_item)"
  XEN_ASSERT_TYPE(XEN_GtkToolItem__P(tool_item), tool_item, 1, "gtk_tool_item_get_relief_style", "GtkToolItem*");
  return(C_TO_XEN_GtkReliefStyle(gtk_tool_item_get_relief_style(XEN_TO_C_GtkToolItem_(tool_item))));
}
static XEN gxg_gtk_tool_item_retrieve_proxy_menu_item(XEN tool_item)
{
  #define H_gtk_tool_item_retrieve_proxy_menu_item "GtkWidget* gtk_tool_item_retrieve_proxy_menu_item(GtkToolItem* tool_item)"
  XEN_ASSERT_TYPE(XEN_GtkToolItem__P(tool_item), tool_item, 1, "gtk_tool_item_retrieve_proxy_menu_item", "GtkToolItem*");
  return(C_TO_XEN_GtkWidget_(gtk_tool_item_retrieve_proxy_menu_item(XEN_TO_C_GtkToolItem_(tool_item))));
}
static XEN gxg_gtk_tool_item_get_proxy_menu_item(XEN tool_item, XEN menu_item_id)
{
  #define H_gtk_tool_item_get_proxy_menu_item "GtkWidget* gtk_tool_item_get_proxy_menu_item(GtkToolItem* tool_item, \
gchar* menu_item_id)"
  XEN_ASSERT_TYPE(XEN_GtkToolItem__P(tool_item), tool_item, 1, "gtk_tool_item_get_proxy_menu_item", "GtkToolItem*");
  XEN_ASSERT_TYPE(XEN_gchar__P(menu_item_id), menu_item_id, 2, "gtk_tool_item_get_proxy_menu_item", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_tool_item_get_proxy_menu_item(XEN_TO_C_GtkToolItem_(tool_item), XEN_TO_C_gchar_(menu_item_id))));
}
static XEN gxg_gtk_tool_item_set_proxy_menu_item(XEN tool_item, XEN menu_item_id, XEN menu_item)
{
  #define H_gtk_tool_item_set_proxy_menu_item "void gtk_tool_item_set_proxy_menu_item(GtkToolItem* tool_item, \
gchar* menu_item_id, GtkWidget* menu_item)"
  XEN_ASSERT_TYPE(XEN_GtkToolItem__P(tool_item), tool_item, 1, "gtk_tool_item_set_proxy_menu_item", "GtkToolItem*");
  XEN_ASSERT_TYPE(XEN_gchar__P(menu_item_id), menu_item_id, 2, "gtk_tool_item_set_proxy_menu_item", "gchar*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(menu_item), menu_item, 3, "gtk_tool_item_set_proxy_menu_item", "GtkWidget*");
  gtk_tool_item_set_proxy_menu_item(XEN_TO_C_GtkToolItem_(tool_item), XEN_TO_C_gchar_(menu_item_id), XEN_TO_C_GtkWidget_(menu_item));
  return(XEN_FALSE);
}
static XEN gxg_gtk_list_store_remove(XEN list_store, XEN iter)
{
  #define H_gtk_list_store_remove "gboolean gtk_list_store_remove(GtkListStore* list_store, GtkTreeIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkListStore__P(list_store), list_store, 1, "gtk_list_store_remove", "GtkListStore*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_list_store_remove", "GtkTreeIter*");
  return(C_TO_XEN_gboolean(gtk_list_store_remove(XEN_TO_C_GtkListStore_(list_store), XEN_TO_C_GtkTreeIter_(iter))));
}
#endif

#if HAVE_GTK_EXPANDER_GET_USE_MARKUP
static XEN gxg_gdk_drawable_copy_to_image(XEN drawable, XEN image, XEN src_x, XEN src_y, XEN dest_x, XEN dest_y, XEN width, XEN height)
{
  #define H_gdk_drawable_copy_to_image "GdkImage* gdk_drawable_copy_to_image(GdkDrawable* drawable, GdkImage* image, \
gint src_x, gint src_y, gint dest_x, gint dest_y, gint width, gint height)"
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_drawable_copy_to_image", "GdkDrawable*");
  XEN_ASSERT_TYPE(XEN_GdkImage__P(image), image, 2, "gdk_drawable_copy_to_image", "GdkImage*");
  XEN_ASSERT_TYPE(XEN_gint_P(src_x), src_x, 3, "gdk_drawable_copy_to_image", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(src_y), src_y, 4, "gdk_drawable_copy_to_image", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(dest_x), dest_x, 5, "gdk_drawable_copy_to_image", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(dest_y), dest_y, 6, "gdk_drawable_copy_to_image", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 7, "gdk_drawable_copy_to_image", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 8, "gdk_drawable_copy_to_image", "gint");
  return(C_TO_XEN_GdkImage_(gdk_drawable_copy_to_image(XEN_TO_C_GdkDrawable_(drawable), XEN_TO_C_GdkImage_(image), XEN_TO_C_gint(src_x), 
                                                       XEN_TO_C_gint(src_y), XEN_TO_C_gint(dest_x), XEN_TO_C_gint(dest_y), 
                                                       XEN_TO_C_gint(width), XEN_TO_C_gint(height))));
}
static XEN gxg_gtk_accel_group_activate(XEN accel_group, XEN accel_quark, XEN acceleratable, XEN accel_key, XEN accel_mods)
{
  #define H_gtk_accel_group_activate "gboolean gtk_accel_group_activate(GtkAccelGroup* accel_group, GQuark accel_quark, \
GObject* acceleratable, guint accel_key, GdkModifierType accel_mods)"
  XEN_ASSERT_TYPE(XEN_GtkAccelGroup__P(accel_group), accel_group, 1, "gtk_accel_group_activate", "GtkAccelGroup*");
  XEN_ASSERT_TYPE(XEN_GQuark_P(accel_quark), accel_quark, 2, "gtk_accel_group_activate", "GQuark");
  XEN_ASSERT_TYPE(XEN_GObject__P(acceleratable), acceleratable, 3, "gtk_accel_group_activate", "GObject*");
  XEN_ASSERT_TYPE(XEN_guint_P(accel_key), accel_key, 4, "gtk_accel_group_activate", "guint");
  XEN_ASSERT_TYPE(XEN_GdkModifierType_P(accel_mods), accel_mods, 5, "gtk_accel_group_activate", "GdkModifierType");
  return(C_TO_XEN_gboolean(gtk_accel_group_activate(XEN_TO_C_GtkAccelGroup_(accel_group), XEN_TO_C_GQuark(accel_quark), XEN_TO_C_GObject_(acceleratable), 
                                                    XEN_TO_C_guint(accel_key), XEN_TO_C_GdkModifierType(accel_mods))));
}
static XEN gxg_gtk_menu_set_monitor(XEN menu, XEN monitor_num)
{
  #define H_gtk_menu_set_monitor "void gtk_menu_set_monitor(GtkMenu* menu, gint monitor_num)"
  XEN_ASSERT_TYPE(XEN_GtkMenu__P(menu), menu, 1, "gtk_menu_set_monitor", "GtkMenu*");
  XEN_ASSERT_TYPE(XEN_gint_P(monitor_num), monitor_num, 2, "gtk_menu_set_monitor", "gint");
  gtk_menu_set_monitor(XEN_TO_C_GtkMenu_(menu), XEN_TO_C_gint(monitor_num));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_can_activate_accel(XEN widget, XEN signal_id)
{
  #define H_gtk_widget_can_activate_accel "gboolean gtk_widget_can_activate_accel(GtkWidget* widget, \
guint signal_id)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_can_activate_accel", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_guint_P(signal_id), signal_id, 2, "gtk_widget_can_activate_accel", "guint");
  return(C_TO_XEN_gboolean(gtk_widget_can_activate_accel(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_guint(signal_id))));
}
static XEN gxg_gtk_window_is_active(XEN window)
{
  #define H_gtk_window_is_active "gboolean gtk_window_is_active(GtkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_is_active", "GtkWindow*");
  return(C_TO_XEN_gboolean(gtk_window_is_active(XEN_TO_C_GtkWindow_(window))));
}
static XEN gxg_gtk_window_has_toplevel_focus(XEN window)
{
  #define H_gtk_window_has_toplevel_focus "gboolean gtk_window_has_toplevel_focus(GtkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_has_toplevel_focus", "GtkWindow*");
  return(C_TO_XEN_gboolean(gtk_window_has_toplevel_focus(XEN_TO_C_GtkWindow_(window))));
}
static XEN gxg_gtk_combo_box_new(void)
{
  #define H_gtk_combo_box_new "GtkWidget* gtk_combo_box_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_combo_box_new()));
}
static XEN gxg_gtk_combo_box_new_with_model(XEN model)
{
  #define H_gtk_combo_box_new_with_model "GtkWidget* gtk_combo_box_new_with_model(GtkTreeModel* model)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(model), model, 1, "gtk_combo_box_new_with_model", "GtkTreeModel*");
  return(C_TO_XEN_GtkWidget_(gtk_combo_box_new_with_model(XEN_TO_C_GtkTreeModel_(model))));
}
static XEN gxg_gtk_combo_box_set_model(XEN combo_box, XEN model)
{
  #define H_gtk_combo_box_set_model "void gtk_combo_box_set_model(GtkComboBox* combo_box, GtkTreeModel* model)"
  XEN_ASSERT_TYPE(XEN_GtkComboBox__P(combo_box), combo_box, 1, "gtk_combo_box_set_model", "GtkComboBox*");
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(model), model, 2, "gtk_combo_box_set_model", "GtkTreeModel*");
  gtk_combo_box_set_model(XEN_TO_C_GtkComboBox_(combo_box), XEN_TO_C_GtkTreeModel_(model));
  return(XEN_FALSE);
}
static XEN gxg_gtk_combo_box_remove_text(XEN combo_box, XEN position)
{
  #define H_gtk_combo_box_remove_text "void gtk_combo_box_remove_text(GtkComboBox* combo_box, gint position)"
  XEN_ASSERT_TYPE(XEN_GtkComboBox__P(combo_box), combo_box, 1, "gtk_combo_box_remove_text", "GtkComboBox*");
  XEN_ASSERT_TYPE(XEN_gint_P(position), position, 2, "gtk_combo_box_remove_text", "gint");
  gtk_combo_box_remove_text(XEN_TO_C_GtkComboBox_(combo_box), XEN_TO_C_gint(position));
  return(XEN_FALSE);
}
static XEN gxg_gtk_combo_box_entry_new(void)
{
  #define H_gtk_combo_box_entry_new "GtkWidget* gtk_combo_box_entry_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_combo_box_entry_new()));
}
static XEN gxg_gtk_combo_box_entry_new_with_model(XEN model, XEN text_column)
{
  #define H_gtk_combo_box_entry_new_with_model "GtkWidget* gtk_combo_box_entry_new_with_model(GtkTreeModel* model, \
gint text_column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(model), model, 1, "gtk_combo_box_entry_new_with_model", "GtkTreeModel*");
  XEN_ASSERT_TYPE(XEN_gint_P(text_column), text_column, 2, "gtk_combo_box_entry_new_with_model", "gint");
  return(C_TO_XEN_GtkWidget_(gtk_combo_box_entry_new_with_model(XEN_TO_C_GtkTreeModel_(model), XEN_TO_C_gint(text_column))));
}
static XEN gxg_gtk_combo_box_entry_set_text_column(XEN entry_box, XEN text_column)
{
  #define H_gtk_combo_box_entry_set_text_column "void gtk_combo_box_entry_set_text_column(GtkComboBoxEntry* entry_box, \
gint text_column)"
  XEN_ASSERT_TYPE(XEN_GtkComboBoxEntry__P(entry_box), entry_box, 1, "gtk_combo_box_entry_set_text_column", "GtkComboBoxEntry*");
  XEN_ASSERT_TYPE(XEN_gint_P(text_column), text_column, 2, "gtk_combo_box_entry_set_text_column", "gint");
  gtk_combo_box_entry_set_text_column(XEN_TO_C_GtkComboBoxEntry_(entry_box), XEN_TO_C_gint(text_column));
  return(XEN_FALSE);
}
static XEN gxg_gtk_expander_set_use_markup(XEN expander, XEN use_markup)
{
  #define H_gtk_expander_set_use_markup "void gtk_expander_set_use_markup(GtkExpander* expander, gboolean use_markup)"
  XEN_ASSERT_TYPE(XEN_GtkExpander__P(expander), expander, 1, "gtk_expander_set_use_markup", "GtkExpander*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(use_markup), use_markup, 2, "gtk_expander_set_use_markup", "gboolean");
  gtk_expander_set_use_markup(XEN_TO_C_GtkExpander_(expander), XEN_TO_C_gboolean(use_markup));
  return(XEN_FALSE);
}
static XEN gxg_gtk_expander_get_use_markup(XEN expander)
{
  #define H_gtk_expander_get_use_markup "gboolean gtk_expander_get_use_markup(GtkExpander* expander)"
  XEN_ASSERT_TYPE(XEN_GtkExpander__P(expander), expander, 1, "gtk_expander_get_use_markup", "GtkExpander*");
  return(C_TO_XEN_gboolean(gtk_expander_get_use_markup(XEN_TO_C_GtkExpander_(expander))));
}
static XEN gxg_gtk_radio_tool_button_new_from_widget(XEN group)
{
  #define H_gtk_radio_tool_button_new_from_widget "GtkToolItem* gtk_radio_tool_button_new_from_widget(GtkRadioToolButton* group)"
  XEN_ASSERT_TYPE(XEN_GtkRadioToolButton__P(group), group, 1, "gtk_radio_tool_button_new_from_widget", "GtkRadioToolButton*");
  return(C_TO_XEN_GtkToolItem_(gtk_radio_tool_button_new_from_widget(XEN_TO_C_GtkRadioToolButton_(group))));
}
static XEN gxg_gtk_separator_tool_item_get_draw(XEN item)
{
  #define H_gtk_separator_tool_item_get_draw "gboolean gtk_separator_tool_item_get_draw(GtkSeparatorToolItem* item)"
  XEN_ASSERT_TYPE(XEN_GtkSeparatorToolItem__P(item), item, 1, "gtk_separator_tool_item_get_draw", "GtkSeparatorToolItem*");
  return(C_TO_XEN_gboolean(gtk_separator_tool_item_get_draw(XEN_TO_C_GtkSeparatorToolItem_(item))));
}
static XEN gxg_gtk_separator_tool_item_set_draw(XEN tool_item, XEN draw)
{
  #define H_gtk_separator_tool_item_set_draw "void gtk_separator_tool_item_set_draw(GtkSeparatorToolItem* tool_item, \
gboolean draw)"
  XEN_ASSERT_TYPE(XEN_GtkSeparatorToolItem__P(tool_item), tool_item, 1, "gtk_separator_tool_item_set_draw", "GtkSeparatorToolItem*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(draw), draw, 2, "gtk_separator_tool_item_set_draw", "gboolean");
  gtk_separator_tool_item_set_draw(XEN_TO_C_GtkSeparatorToolItem_(tool_item), XEN_TO_C_gboolean(draw));
  return(XEN_FALSE);
}
#endif

#if HAVE_GTK_MENU_SHELL_CANCEL
static XEN gxg_gtk_notebook_append_page(XEN notebook, XEN child, XEN tab_label)
{
  #define H_gtk_notebook_append_page "gint gtk_notebook_append_page(GtkNotebook* notebook, GtkWidget* child, \
GtkWidget* tab_label)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_append_page", "GtkNotebook*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_notebook_append_page", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(tab_label) || XEN_FALSE_P(tab_label), tab_label, 3, "gtk_notebook_append_page", "GtkWidget*");
  return(C_TO_XEN_gint(gtk_notebook_append_page(XEN_TO_C_GtkNotebook_(notebook), XEN_TO_C_GtkWidget_(child), XEN_TO_C_GtkWidget_(tab_label))));
}
static XEN gxg_gtk_notebook_append_page_menu(XEN notebook, XEN child, XEN tab_label, XEN menu_label)
{
  #define H_gtk_notebook_append_page_menu "gint gtk_notebook_append_page_menu(GtkNotebook* notebook, \
GtkWidget* child, GtkWidget* tab_label, GtkWidget* menu_label)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_append_page_menu", "GtkNotebook*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_notebook_append_page_menu", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(tab_label) || XEN_FALSE_P(tab_label), tab_label, 3, "gtk_notebook_append_page_menu", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(menu_label) || XEN_FALSE_P(menu_label), menu_label, 4, "gtk_notebook_append_page_menu", "GtkWidget*");
  return(C_TO_XEN_gint(gtk_notebook_append_page_menu(XEN_TO_C_GtkNotebook_(notebook), XEN_TO_C_GtkWidget_(child), XEN_TO_C_GtkWidget_(tab_label), 
                                                     XEN_TO_C_GtkWidget_(menu_label))));
}
static XEN gxg_gtk_notebook_prepend_page(XEN notebook, XEN child, XEN tab_label)
{
  #define H_gtk_notebook_prepend_page "gint gtk_notebook_prepend_page(GtkNotebook* notebook, GtkWidget* child, \
GtkWidget* tab_label)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_prepend_page", "GtkNotebook*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_notebook_prepend_page", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(tab_label) || XEN_FALSE_P(tab_label), tab_label, 3, "gtk_notebook_prepend_page", "GtkWidget*");
  return(C_TO_XEN_gint(gtk_notebook_prepend_page(XEN_TO_C_GtkNotebook_(notebook), XEN_TO_C_GtkWidget_(child), XEN_TO_C_GtkWidget_(tab_label))));
}
static XEN gxg_gtk_notebook_prepend_page_menu(XEN notebook, XEN child, XEN tab_label, XEN menu_label)
{
  #define H_gtk_notebook_prepend_page_menu "gint gtk_notebook_prepend_page_menu(GtkNotebook* notebook, \
GtkWidget* child, GtkWidget* tab_label, GtkWidget* menu_label)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_prepend_page_menu", "GtkNotebook*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_notebook_prepend_page_menu", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(tab_label) || XEN_FALSE_P(tab_label), tab_label, 3, "gtk_notebook_prepend_page_menu", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(menu_label) || XEN_FALSE_P(menu_label), menu_label, 4, "gtk_notebook_prepend_page_menu", "GtkWidget*");
  return(C_TO_XEN_gint(gtk_notebook_prepend_page_menu(XEN_TO_C_GtkNotebook_(notebook), XEN_TO_C_GtkWidget_(child), XEN_TO_C_GtkWidget_(tab_label), 
                                                      XEN_TO_C_GtkWidget_(menu_label))));
}
static XEN gxg_gtk_notebook_insert_page(XEN notebook, XEN child, XEN tab_label, XEN position)
{
  #define H_gtk_notebook_insert_page "gint gtk_notebook_insert_page(GtkNotebook* notebook, GtkWidget* child, \
GtkWidget* tab_label, gint position)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_insert_page", "GtkNotebook*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_notebook_insert_page", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(tab_label) || XEN_FALSE_P(tab_label), tab_label, 3, "gtk_notebook_insert_page", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gint_P(position), position, 4, "gtk_notebook_insert_page", "gint");
  return(C_TO_XEN_gint(gtk_notebook_insert_page(XEN_TO_C_GtkNotebook_(notebook), XEN_TO_C_GtkWidget_(child), XEN_TO_C_GtkWidget_(tab_label), 
                                                XEN_TO_C_gint(position))));
}
static XEN gxg_gtk_notebook_insert_page_menu(XEN notebook, XEN child, XEN tab_label, XEN menu_label, XEN position)
{
  #define H_gtk_notebook_insert_page_menu "gint gtk_notebook_insert_page_menu(GtkNotebook* notebook, \
GtkWidget* child, GtkWidget* tab_label, GtkWidget* menu_label, gint position)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_insert_page_menu", "GtkNotebook*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_notebook_insert_page_menu", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(tab_label) || XEN_FALSE_P(tab_label), tab_label, 3, "gtk_notebook_insert_page_menu", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(menu_label) || XEN_FALSE_P(menu_label), menu_label, 4, "gtk_notebook_insert_page_menu", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gint_P(position), position, 5, "gtk_notebook_insert_page_menu", "gint");
  return(C_TO_XEN_gint(gtk_notebook_insert_page_menu(XEN_TO_C_GtkNotebook_(notebook), XEN_TO_C_GtkWidget_(child), XEN_TO_C_GtkWidget_(tab_label), 
                                                     XEN_TO_C_GtkWidget_(menu_label), XEN_TO_C_gint(position))));
}
static XEN gxg_gtk_radio_tool_button_new_with_stock_from_widget(XEN group, XEN stock_id)
{
  #define H_gtk_radio_tool_button_new_with_stock_from_widget "GtkToolItem* gtk_radio_tool_button_new_with_stock_from_widget(GtkRadioToolButton* group, \
gchar* stock_id)"
  XEN_ASSERT_TYPE(XEN_GtkRadioToolButton__P(group), group, 1, "gtk_radio_tool_button_new_with_stock_from_widget", "GtkRadioToolButton*");
  XEN_ASSERT_TYPE(XEN_gchar__P(stock_id), stock_id, 2, "gtk_radio_tool_button_new_with_stock_from_widget", "gchar*");
  return(C_TO_XEN_GtkToolItem_(gtk_radio_tool_button_new_with_stock_from_widget(XEN_TO_C_GtkRadioToolButton_(group), XEN_TO_C_gchar_(stock_id))));
}
static XEN gxg_gdk_display_set_double_click_distance(XEN display, XEN distance)
{
  #define H_gdk_display_set_double_click_distance "void gdk_display_set_double_click_distance(GdkDisplay* display, \
guint distance)"
  XEN_ASSERT_TYPE(XEN_GdkDisplay__P(display), display, 1, "gdk_display_set_double_click_distance", "GdkDisplay*");
  XEN_ASSERT_TYPE(XEN_guint_P(distance), distance, 2, "gdk_display_set_double_click_distance", "guint");
  gdk_display_set_double_click_distance(XEN_TO_C_GdkDisplay_(display), XEN_TO_C_guint(distance));
  return(XEN_FALSE);
}
static XEN gxg_gdk_display_get_default_group(XEN display)
{
  #define H_gdk_display_get_default_group "GdkWindow* gdk_display_get_default_group(GdkDisplay* display)"
  XEN_ASSERT_TYPE(XEN_GdkDisplay__P(display), display, 1, "gdk_display_get_default_group", "GdkDisplay*");
  return(C_TO_XEN_GdkWindow_(gdk_display_get_default_group(XEN_TO_C_GdkDisplay_(display))));
}
static XEN gxg_gdk_window_set_accept_focus(XEN window, XEN accept_focus)
{
  #define H_gdk_window_set_accept_focus "void gdk_window_set_accept_focus(GdkWindow* window, gboolean accept_focus)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_set_accept_focus", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(accept_focus), accept_focus, 2, "gdk_window_set_accept_focus", "gboolean");
  gdk_window_set_accept_focus(XEN_TO_C_GdkWindow_(window), XEN_TO_C_gboolean(accept_focus));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_get_group(XEN window)
{
  #define H_gdk_window_get_group "GdkWindow* gdk_window_get_group(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_get_group", "GdkWindow*");
  return(C_TO_XEN_GdkWindow_(gdk_window_get_group(XEN_TO_C_GdkWindow_(window))));
}
static XEN gxg_gtk_action_group_get_sensitive(XEN action_group)
{
  #define H_gtk_action_group_get_sensitive "gboolean gtk_action_group_get_sensitive(GtkActionGroup* action_group)"
  XEN_ASSERT_TYPE(XEN_GtkActionGroup__P(action_group), action_group, 1, "gtk_action_group_get_sensitive", "GtkActionGroup*");
  return(C_TO_XEN_gboolean(gtk_action_group_get_sensitive(XEN_TO_C_GtkActionGroup_(action_group))));
}
static XEN gxg_gtk_action_group_set_sensitive(XEN action_group, XEN sensitive)
{
  #define H_gtk_action_group_set_sensitive "void gtk_action_group_set_sensitive(GtkActionGroup* action_group, \
gboolean sensitive)"
  XEN_ASSERT_TYPE(XEN_GtkActionGroup__P(action_group), action_group, 1, "gtk_action_group_set_sensitive", "GtkActionGroup*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(sensitive), sensitive, 2, "gtk_action_group_set_sensitive", "gboolean");
  gtk_action_group_set_sensitive(XEN_TO_C_GtkActionGroup_(action_group), XEN_TO_C_gboolean(sensitive));
  return(XEN_FALSE);
}
static XEN gxg_gtk_action_group_get_visible(XEN action_group)
{
  #define H_gtk_action_group_get_visible "gboolean gtk_action_group_get_visible(GtkActionGroup* action_group)"
  XEN_ASSERT_TYPE(XEN_GtkActionGroup__P(action_group), action_group, 1, "gtk_action_group_get_visible", "GtkActionGroup*");
  return(C_TO_XEN_gboolean(gtk_action_group_get_visible(XEN_TO_C_GtkActionGroup_(action_group))));
}
static XEN gxg_gtk_action_group_set_visible(XEN action_group, XEN visible)
{
  #define H_gtk_action_group_set_visible "void gtk_action_group_set_visible(GtkActionGroup* action_group, \
gboolean visible)"
  XEN_ASSERT_TYPE(XEN_GtkActionGroup__P(action_group), action_group, 1, "gtk_action_group_set_visible", "GtkActionGroup*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(visible), visible, 2, "gtk_action_group_set_visible", "gboolean");
  gtk_action_group_set_visible(XEN_TO_C_GtkActionGroup_(action_group), XEN_TO_C_gboolean(visible));
  return(XEN_FALSE);
}
static XEN gxg_gtk_action_group_add_action_with_accel(XEN action_group, XEN action, XEN accelerator)
{
  #define H_gtk_action_group_add_action_with_accel "void gtk_action_group_add_action_with_accel(GtkActionGroup* action_group, \
GtkAction* action, gchar* accelerator)"
  XEN_ASSERT_TYPE(XEN_GtkActionGroup__P(action_group), action_group, 1, "gtk_action_group_add_action_with_accel", "GtkActionGroup*");
  XEN_ASSERT_TYPE(XEN_GtkAction__P(action), action, 2, "gtk_action_group_add_action_with_accel", "GtkAction*");
  XEN_ASSERT_TYPE(XEN_gchar__P(accelerator), accelerator, 3, "gtk_action_group_add_action_with_accel", "gchar*");
  gtk_action_group_add_action_with_accel(XEN_TO_C_GtkActionGroup_(action_group), XEN_TO_C_GtkAction_(action), XEN_TO_C_gchar_(accelerator));
  return(XEN_FALSE);
}
static XEN gxg_gtk_action_new(XEN name, XEN label, XEN tooltip, XEN stock_id)
{
  #define H_gtk_action_new "GtkAction* gtk_action_new(gchar* name, gchar* label, gchar* tooltip, gchar* stock_id)"
  XEN_ASSERT_TYPE(XEN_gchar__P(name), name, 1, "gtk_action_new", "gchar*");
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 2, "gtk_action_new", "gchar*");
  XEN_ASSERT_TYPE(XEN_gchar__P(tooltip), tooltip, 3, "gtk_action_new", "gchar*");
  XEN_ASSERT_TYPE(XEN_gchar__P(stock_id), stock_id, 4, "gtk_action_new", "gchar*");
  return(C_TO_XEN_GtkAction_(gtk_action_new(XEN_TO_C_gchar_(name), XEN_TO_C_gchar_(label), XEN_TO_C_gchar_(tooltip), XEN_TO_C_gchar_(stock_id))));
}
static XEN gxg_gtk_action_is_sensitive(XEN action)
{
  #define H_gtk_action_is_sensitive "gboolean gtk_action_is_sensitive(GtkAction* action)"
  XEN_ASSERT_TYPE(XEN_GtkAction__P(action), action, 1, "gtk_action_is_sensitive", "GtkAction*");
  return(C_TO_XEN_gboolean(gtk_action_is_sensitive(XEN_TO_C_GtkAction_(action))));
}
static XEN gxg_gtk_action_get_sensitive(XEN action)
{
  #define H_gtk_action_get_sensitive "gboolean gtk_action_get_sensitive(GtkAction* action)"
  XEN_ASSERT_TYPE(XEN_GtkAction__P(action), action, 1, "gtk_action_get_sensitive", "GtkAction*");
  return(C_TO_XEN_gboolean(gtk_action_get_sensitive(XEN_TO_C_GtkAction_(action))));
}
static XEN gxg_gtk_action_is_visible(XEN action)
{
  #define H_gtk_action_is_visible "gboolean gtk_action_is_visible(GtkAction* action)"
  XEN_ASSERT_TYPE(XEN_GtkAction__P(action), action, 1, "gtk_action_is_visible", "GtkAction*");
  return(C_TO_XEN_gboolean(gtk_action_is_visible(XEN_TO_C_GtkAction_(action))));
}
static XEN gxg_gtk_action_get_visible(XEN action)
{
  #define H_gtk_action_get_visible "gboolean gtk_action_get_visible(GtkAction* action)"
  XEN_ASSERT_TYPE(XEN_GtkAction__P(action), action, 1, "gtk_action_get_visible", "GtkAction*");
  return(C_TO_XEN_gboolean(gtk_action_get_visible(XEN_TO_C_GtkAction_(action))));
}
static XEN gxg_gtk_button_set_alignment(XEN button, XEN xalign, XEN yalign)
{
  #define H_gtk_button_set_alignment "void gtk_button_set_alignment(GtkButton* button, gfloat xalign, \
gfloat yalign)"
  XEN_ASSERT_TYPE(XEN_GtkButton__P(button), button, 1, "gtk_button_set_alignment", "GtkButton*");
  XEN_ASSERT_TYPE(XEN_gfloat_P(xalign), xalign, 2, "gtk_button_set_alignment", "gfloat");
  XEN_ASSERT_TYPE(XEN_gfloat_P(yalign), yalign, 3, "gtk_button_set_alignment", "gfloat");
  gtk_button_set_alignment(XEN_TO_C_GtkButton_(button), XEN_TO_C_gfloat(xalign), XEN_TO_C_gfloat(yalign));
  return(XEN_FALSE);
}
static XEN gxg_gtk_button_get_alignment(XEN button, XEN xalign, XEN yalign)
{
  #define H_gtk_button_get_alignment "void gtk_button_get_alignment(GtkButton* button, gfloat* [xalign], \
gfloat* [yalign])"
  gfloat ref_xalign;
  gfloat ref_yalign;
  XEN_ASSERT_TYPE(XEN_GtkButton__P(button), button, 1, "gtk_button_get_alignment", "GtkButton*");
  gtk_button_get_alignment(XEN_TO_C_GtkButton_(button), &ref_xalign, &ref_yalign);
  return(XEN_LIST_2(C_TO_XEN_gfloat(ref_xalign), C_TO_XEN_gfloat(ref_yalign)));
}
static XEN gxg_gtk_cell_layout_reorder(XEN cell_layout, XEN cell, XEN position)
{
  #define H_gtk_cell_layout_reorder "void gtk_cell_layout_reorder(GtkCellLayout* cell_layout, GtkCellRenderer* cell, \
gint position)"
  XEN_ASSERT_TYPE(XEN_GtkCellLayout__P(cell_layout), cell_layout, 1, "gtk_cell_layout_reorder", "GtkCellLayout*");
  XEN_ASSERT_TYPE(XEN_GtkCellRenderer__P(cell), cell, 2, "gtk_cell_layout_reorder", "GtkCellRenderer*");
  XEN_ASSERT_TYPE(XEN_gint_P(position), position, 3, "gtk_cell_layout_reorder", "gint");
  gtk_cell_layout_reorder(XEN_TO_C_GtkCellLayout_(cell_layout), XEN_TO_C_GtkCellRenderer_(cell), XEN_TO_C_gint(position));
  return(XEN_FALSE);
}
static XEN gxg_gtk_clipboard_request_targets(XEN clipboard, XEN func, XEN func_data)
{
  #define H_gtk_clipboard_request_targets "void gtk_clipboard_request_targets(GtkClipboard* clipboard, \
GtkClipboardTargetsReceivedFunc func, lambda_data func_data)"
  XEN_ASSERT_TYPE(XEN_GtkClipboard__P(clipboard), clipboard, 1, "gtk_clipboard_request_targets", "GtkClipboard*");
  XEN_ASSERT_TYPE(XEN_GtkClipboardTargetsReceivedFunc_P(func), func, 2, "gtk_clipboard_request_targets", "GtkClipboardTargetsReceivedFunc");
  if (XEN_NOT_BOUND_P(func_data)) func_data = XEN_FALSE; 
  else XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 3, "gtk_clipboard_request_targets", "lambda_data");
  {
    int loc;
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    loc = xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 2, C_TO_XEN_INT(loc));
    gtk_clipboard_request_targets(XEN_TO_C_GtkClipboard_(clipboard), XEN_TO_C_GtkClipboardTargetsReceivedFunc(func), XEN_TO_C_lambda_data(func_data));
    xm_unprotect_at(loc);
    return(XEN_FALSE);
   }
}
static XEN gxg_gtk_clipboard_wait_for_targets(XEN clipboard, XEN targets, XEN n_targets)
{
  #define H_gtk_clipboard_wait_for_targets "gboolean gtk_clipboard_wait_for_targets(GtkClipboard* clipboard, \
GdkAtom** [targets], gint* [n_targets])"
  GdkAtom* ref_targets = NULL;
  gint ref_n_targets;
  XEN_ASSERT_TYPE(XEN_GtkClipboard__P(clipboard), clipboard, 1, "gtk_clipboard_wait_for_targets", "GtkClipboard*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gtk_clipboard_wait_for_targets(XEN_TO_C_GtkClipboard_(clipboard), &ref_targets, &ref_n_targets));
    return(XEN_LIST_3(result, C_TO_XEN_GdkAtom_(ref_targets), C_TO_XEN_gint(ref_n_targets)));
   }
}
static XEN gxg_gtk_menu_shell_cancel(XEN menu_shell)
{
  #define H_gtk_menu_shell_cancel "void gtk_menu_shell_cancel(GtkMenuShell* menu_shell)"
  XEN_ASSERT_TYPE(XEN_GtkMenuShell__P(menu_shell), menu_shell, 1, "gtk_menu_shell_cancel", "GtkMenuShell*");
  gtk_menu_shell_cancel(XEN_TO_C_GtkMenuShell_(menu_shell));
  return(XEN_FALSE);
}
static XEN gxg_gtk_paned_get_child1(XEN paned)
{
  #define H_gtk_paned_get_child1 "GtkWidget* gtk_paned_get_child1(GtkPaned* paned)"
  XEN_ASSERT_TYPE(XEN_GtkPaned__P(paned), paned, 1, "gtk_paned_get_child1", "GtkPaned*");
  return(C_TO_XEN_GtkWidget_(gtk_paned_get_child1(XEN_TO_C_GtkPaned_(paned))));
}
static XEN gxg_gtk_paned_get_child2(XEN paned)
{
  #define H_gtk_paned_get_child2 "GtkWidget* gtk_paned_get_child2(GtkPaned* paned)"
  XEN_ASSERT_TYPE(XEN_GtkPaned__P(paned), paned, 1, "gtk_paned_get_child2", "GtkPaned*");
  return(C_TO_XEN_GtkWidget_(gtk_paned_get_child2(XEN_TO_C_GtkPaned_(paned))));
}
static XEN gxg_gtk_radio_action_new(XEN name, XEN label, XEN tooltip, XEN stock_id, XEN value)
{
  #define H_gtk_radio_action_new "GtkRadioAction* gtk_radio_action_new(gchar* name, gchar* label, gchar* tooltip, \
gchar* stock_id, gint value)"
  XEN_ASSERT_TYPE(XEN_gchar__P(name), name, 1, "gtk_radio_action_new", "gchar*");
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 2, "gtk_radio_action_new", "gchar*");
  XEN_ASSERT_TYPE(XEN_gchar__P(tooltip), tooltip, 3, "gtk_radio_action_new", "gchar*");
  XEN_ASSERT_TYPE(XEN_gchar__P(stock_id), stock_id, 4, "gtk_radio_action_new", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(value), value, 5, "gtk_radio_action_new", "gint");
  return(C_TO_XEN_GtkRadioAction_(gtk_radio_action_new(XEN_TO_C_gchar_(name), XEN_TO_C_gchar_(label), XEN_TO_C_gchar_(tooltip), 
                                                       XEN_TO_C_gchar_(stock_id), XEN_TO_C_gint(value))));
}
static XEN gxg_gtk_toggle_action_new(XEN name, XEN label, XEN tooltip, XEN stock_id)
{
  #define H_gtk_toggle_action_new "GtkToggleAction* gtk_toggle_action_new(gchar* name, gchar* label, \
gchar* tooltip, gchar* stock_id)"
  XEN_ASSERT_TYPE(XEN_gchar__P(name), name, 1, "gtk_toggle_action_new", "gchar*");
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 2, "gtk_toggle_action_new", "gchar*");
  XEN_ASSERT_TYPE(XEN_gchar__P(tooltip), tooltip, 3, "gtk_toggle_action_new", "gchar*");
  XEN_ASSERT_TYPE(XEN_gchar__P(stock_id), stock_id, 4, "gtk_toggle_action_new", "gchar*");
  return(C_TO_XEN_GtkToggleAction_(gtk_toggle_action_new(XEN_TO_C_gchar_(name), XEN_TO_C_gchar_(label), XEN_TO_C_gchar_(tooltip), 
                                                         XEN_TO_C_gchar_(stock_id))));
}
static XEN gxg_gtk_window_set_accept_focus(XEN window, XEN setting)
{
  #define H_gtk_window_set_accept_focus "void gtk_window_set_accept_focus(GtkWindow* window, gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_set_accept_focus", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gtk_window_set_accept_focus", "gboolean");
  gtk_window_set_accept_focus(XEN_TO_C_GtkWindow_(window), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_get_accept_focus(XEN window)
{
  #define H_gtk_window_get_accept_focus "gboolean gtk_window_get_accept_focus(GtkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_get_accept_focus", "GtkWindow*");
  return(C_TO_XEN_gboolean(gtk_window_get_accept_focus(XEN_TO_C_GtkWindow_(window))));
}
#endif

#if HAVE_GTK_COMBO_BOX_POPUP
static XEN gxg_gtk_accel_map_get_type(void)
{
  #define H_gtk_accel_map_get_type "GType gtk_accel_map_get_type( void)"
  return(C_TO_XEN_GType(gtk_accel_map_get_type()));
}
static XEN gxg_gtk_accel_map_get(void)
{
  #define H_gtk_accel_map_get "GtkAccelMap* gtk_accel_map_get( void)"
  return(C_TO_XEN_GtkAccelMap_(gtk_accel_map_get()));
}
static XEN gxg_gtk_combo_box_popup(XEN combo_box)
{
  #define H_gtk_combo_box_popup "void gtk_combo_box_popup(GtkComboBox* combo_box)"
  XEN_ASSERT_TYPE(XEN_GtkComboBox__P(combo_box), combo_box, 1, "gtk_combo_box_popup", "GtkComboBox*");
  gtk_combo_box_popup(XEN_TO_C_GtkComboBox_(combo_box));
  return(XEN_FALSE);
}
static XEN gxg_gtk_combo_box_popdown(XEN combo_box)
{
  #define H_gtk_combo_box_popdown "void gtk_combo_box_popdown(GtkComboBox* combo_box)"
  XEN_ASSERT_TYPE(XEN_GtkComboBox__P(combo_box), combo_box, 1, "gtk_combo_box_popdown", "GtkComboBox*");
  gtk_combo_box_popdown(XEN_TO_C_GtkComboBox_(combo_box));
  return(XEN_FALSE);
}
static XEN gxg_gtk_radio_menu_item_new_from_widget(XEN group)
{
  #define H_gtk_radio_menu_item_new_from_widget "GtkWidget* gtk_radio_menu_item_new_from_widget(GtkRadioMenuItem* group)"
  XEN_ASSERT_TYPE(XEN_GtkRadioMenuItem__P(group), group, 1, "gtk_radio_menu_item_new_from_widget", "GtkRadioMenuItem*");
  return(C_TO_XEN_GtkWidget_(gtk_radio_menu_item_new_from_widget(XEN_TO_C_GtkRadioMenuItem_(group))));
}
static XEN gxg_gtk_radio_menu_item_new_with_mnemonic_from_widget(XEN group, XEN label)
{
  #define H_gtk_radio_menu_item_new_with_mnemonic_from_widget "GtkWidget* gtk_radio_menu_item_new_with_mnemonic_from_widget(GtkRadioMenuItem* group, \
gchar* label)"
  XEN_ASSERT_TYPE(XEN_GtkRadioMenuItem__P(group), group, 1, "gtk_radio_menu_item_new_with_mnemonic_from_widget", "GtkRadioMenuItem*");
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 2, "gtk_radio_menu_item_new_with_mnemonic_from_widget", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_radio_menu_item_new_with_mnemonic_from_widget(XEN_TO_C_GtkRadioMenuItem_(group), XEN_TO_C_gchar_(label))));
}
static XEN gxg_gtk_radio_menu_item_new_with_label_from_widget(XEN group, XEN label)
{
  #define H_gtk_radio_menu_item_new_with_label_from_widget "GtkWidget* gtk_radio_menu_item_new_with_label_from_widget(GtkRadioMenuItem* group, \
gchar* label)"
  XEN_ASSERT_TYPE(XEN_GtkRadioMenuItem__P(group), group, 1, "gtk_radio_menu_item_new_with_label_from_widget", "GtkRadioMenuItem*");
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 2, "gtk_radio_menu_item_new_with_label_from_widget", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_radio_menu_item_new_with_label_from_widget(XEN_TO_C_GtkRadioMenuItem_(group), XEN_TO_C_gchar_(label))));
}
static XEN gxg_gtk_scale_get_layout(XEN scale)
{
  #define H_gtk_scale_get_layout "PangoLayout* gtk_scale_get_layout(GtkScale* scale)"
  XEN_ASSERT_TYPE(XEN_GtkScale__P(scale), scale, 1, "gtk_scale_get_layout", "GtkScale*");
  return(C_TO_XEN_PangoLayout_(gtk_scale_get_layout(XEN_TO_C_GtkScale_(scale))));
}
static XEN gxg_gtk_scale_get_layout_offsets(XEN scale, XEN x, XEN y)
{
  #define H_gtk_scale_get_layout_offsets "void gtk_scale_get_layout_offsets(GtkScale* scale, gint* [x], \
gint* [y])"
  gint ref_x;
  gint ref_y;
  XEN_ASSERT_TYPE(XEN_GtkScale__P(scale), scale, 1, "gtk_scale_get_layout_offsets", "GtkScale*");
  gtk_scale_get_layout_offsets(XEN_TO_C_GtkScale_(scale), &ref_x, &ref_y);
  return(XEN_LIST_2(C_TO_XEN_gint(ref_x), C_TO_XEN_gint(ref_y)));
}
static XEN gxg_gtk_tooltips_get_info_from_tip_window(XEN tip_window, XEN tooltips, XEN current_widget)
{
  #define H_gtk_tooltips_get_info_from_tip_window "gboolean gtk_tooltips_get_info_from_tip_window(GtkWindow* tip_window, \
GtkTooltips** [tooltips], GtkWidget** [current_widget])"
  GtkTooltips* ref_tooltips = NULL;
  GtkWidget* ref_current_widget = NULL;
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(tip_window), tip_window, 1, "gtk_tooltips_get_info_from_tip_window", "GtkWindow*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gtk_tooltips_get_info_from_tip_window(XEN_TO_C_GtkWindow_(tip_window), &ref_tooltips, &ref_current_widget));
    return(XEN_LIST_3(result, C_TO_XEN_GtkTooltips_(ref_tooltips), C_TO_XEN_GtkWidget_(ref_current_widget)));
   }
}
#endif

#if HAVE_GTK_COMBO_BOX_ENTRY_NEW_TEXT
static XEN gxg_gtk_combo_box_entry_new_text(void)
{
  #define H_gtk_combo_box_entry_new_text "GtkWidget* gtk_combo_box_entry_new_text( void)"
  return(C_TO_XEN_GtkWidget_(gtk_combo_box_entry_new_text()));
}
static XEN gxg_gtk_drag_source_get_target_list(XEN widget)
{
  #define H_gtk_drag_source_get_target_list "GtkTargetList* gtk_drag_source_get_target_list(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_drag_source_get_target_list", "GtkWidget*");
  return(C_TO_XEN_GtkTargetList_(gtk_drag_source_get_target_list(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_drag_source_set_target_list(XEN widget, XEN target_list)
{
  #define H_gtk_drag_source_set_target_list "void gtk_drag_source_set_target_list(GtkWidget* widget, \
GtkTargetList* target_list)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_drag_source_set_target_list", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkTargetList__P(target_list), target_list, 2, "gtk_drag_source_set_target_list", "GtkTargetList*");
  gtk_drag_source_set_target_list(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GtkTargetList_(target_list));
  return(XEN_FALSE);
}
static XEN gxg_gtk_entry_set_alignment(XEN entry, XEN xalign)
{
  #define H_gtk_entry_set_alignment "void gtk_entry_set_alignment(GtkEntry* entry, gfloat xalign)"
  XEN_ASSERT_TYPE(XEN_GtkEntry__P(entry), entry, 1, "gtk_entry_set_alignment", "GtkEntry*");
  XEN_ASSERT_TYPE(XEN_gfloat_P(xalign), xalign, 2, "gtk_entry_set_alignment", "gfloat");
  gtk_entry_set_alignment(XEN_TO_C_GtkEntry_(entry), XEN_TO_C_gfloat(xalign));
  return(XEN_FALSE);
}
static XEN gxg_gtk_entry_get_alignment(XEN entry)
{
  #define H_gtk_entry_get_alignment "gfloat gtk_entry_get_alignment(GtkEntry* entry)"
  XEN_ASSERT_TYPE(XEN_GtkEntry__P(entry), entry, 1, "gtk_entry_get_alignment", "GtkEntry*");
  return(C_TO_XEN_gfloat(gtk_entry_get_alignment(XEN_TO_C_GtkEntry_(entry))));
}
static XEN gxg_gtk_file_chooser_set_use_preview_label(XEN chooser, XEN use_label)
{
  #define H_gtk_file_chooser_set_use_preview_label "void gtk_file_chooser_set_use_preview_label(GtkFileChooser* chooser, \
gboolean use_label)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_set_use_preview_label", "GtkFileChooser*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(use_label), use_label, 2, "gtk_file_chooser_set_use_preview_label", "gboolean");
  gtk_file_chooser_set_use_preview_label(XEN_TO_C_GtkFileChooser_(chooser), XEN_TO_C_gboolean(use_label));
  return(XEN_FALSE);
}
static XEN gxg_gtk_file_chooser_get_use_preview_label(XEN chooser)
{
  #define H_gtk_file_chooser_get_use_preview_label "gboolean gtk_file_chooser_get_use_preview_label(GtkFileChooser* chooser)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_get_use_preview_label", "GtkFileChooser*");
  return(C_TO_XEN_gboolean(gtk_file_chooser_get_use_preview_label(XEN_TO_C_GtkFileChooser_(chooser))));
}
static XEN gxg_gtk_file_chooser_widget_new_with_backend(XEN action, XEN backend)
{
  #define H_gtk_file_chooser_widget_new_with_backend "GtkWidget* gtk_file_chooser_widget_new_with_backend(GtkFileChooserAction action, \
gchar* backend)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooserAction_P(action), action, 1, "gtk_file_chooser_widget_new_with_backend", "GtkFileChooserAction");
  XEN_ASSERT_TYPE(XEN_gchar__P(backend), backend, 2, "gtk_file_chooser_widget_new_with_backend", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_file_chooser_widget_new_with_backend(XEN_TO_C_GtkFileChooserAction(action), XEN_TO_C_gchar_(backend))));
}
static XEN gxg_gtk_widget_list_mnemonic_labels(XEN widget)
{
  #define H_gtk_widget_list_mnemonic_labels "GList* gtk_widget_list_mnemonic_labels(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_list_mnemonic_labels", "GtkWidget*");
  return(C_TO_XEN_GList_(gtk_widget_list_mnemonic_labels(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_widget_add_mnemonic_label(XEN widget, XEN label)
{
  #define H_gtk_widget_add_mnemonic_label "void gtk_widget_add_mnemonic_label(GtkWidget* widget, GtkWidget* label)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_add_mnemonic_label", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(label), label, 2, "gtk_widget_add_mnemonic_label", "GtkWidget*");
  gtk_widget_add_mnemonic_label(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GtkWidget_(label));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_remove_mnemonic_label(XEN widget, XEN label)
{
  #define H_gtk_widget_remove_mnemonic_label "void gtk_widget_remove_mnemonic_label(GtkWidget* widget, \
GtkWidget* label)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_remove_mnemonic_label", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(label), label, 2, "gtk_widget_remove_mnemonic_label", "GtkWidget*");
  gtk_widget_remove_mnemonic_label(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GtkWidget_(label));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_activate_key(XEN window, XEN event)
{
  #define H_gtk_window_activate_key "gboolean gtk_window_activate_key(GtkWindow* window, GdkEventKey* event)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_activate_key", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkEventKey__P(event), event, 2, "gtk_window_activate_key", "GdkEventKey*");
  return(C_TO_XEN_gboolean(gtk_window_activate_key(XEN_TO_C_GtkWindow_(window), XEN_TO_C_GdkEventKey_(event))));
}
static XEN gxg_gtk_window_propagate_key_event(XEN window, XEN event)
{
  #define H_gtk_window_propagate_key_event "gboolean gtk_window_propagate_key_event(GtkWindow* window, \
GdkEventKey* event)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_propagate_key_event", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkEventKey__P(event), event, 2, "gtk_window_propagate_key_event", "GdkEventKey*");
  return(C_TO_XEN_gboolean(gtk_window_propagate_key_event(XEN_TO_C_GtkWindow_(window), XEN_TO_C_GdkEventKey_(event))));
}
#endif

#if HAVE_GBOOLEAN_GTK_FILE_CHOOSER_SET_FILENAME
static XEN gxg_gtk_file_chooser_set_filename(XEN chooser, XEN filename)
{
  #define H_gtk_file_chooser_set_filename "gboolean gtk_file_chooser_set_filename(GtkFileChooser* chooser, \
char* filename)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_set_filename", "GtkFileChooser*");
  XEN_ASSERT_TYPE(XEN_char__P(filename), filename, 2, "gtk_file_chooser_set_filename", "char*");
  return(C_TO_XEN_gboolean(gtk_file_chooser_set_filename(XEN_TO_C_GtkFileChooser_(chooser), XEN_TO_C_char_(filename))));
}
static XEN gxg_gtk_file_chooser_select_filename(XEN chooser, XEN filename)
{
  #define H_gtk_file_chooser_select_filename "gboolean gtk_file_chooser_select_filename(GtkFileChooser* chooser, \
char* filename)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_select_filename", "GtkFileChooser*");
  XEN_ASSERT_TYPE(XEN_char__P(filename), filename, 2, "gtk_file_chooser_select_filename", "char*");
  return(C_TO_XEN_gboolean(gtk_file_chooser_select_filename(XEN_TO_C_GtkFileChooser_(chooser), XEN_TO_C_char_(filename))));
}
static XEN gxg_gtk_file_chooser_set_current_folder(XEN chooser, XEN filename)
{
  #define H_gtk_file_chooser_set_current_folder "gboolean gtk_file_chooser_set_current_folder(GtkFileChooser* chooser, \
gchar* filename)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_set_current_folder", "GtkFileChooser*");
  XEN_ASSERT_TYPE(XEN_gchar__P(filename), filename, 2, "gtk_file_chooser_set_current_folder", "gchar*");
  return(C_TO_XEN_gboolean(gtk_file_chooser_set_current_folder(XEN_TO_C_GtkFileChooser_(chooser), XEN_TO_C_gchar_(filename))));
}
static XEN gxg_gtk_file_chooser_set_uri(XEN chooser, XEN uri)
{
  #define H_gtk_file_chooser_set_uri "gboolean gtk_file_chooser_set_uri(GtkFileChooser* chooser, char* uri)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_set_uri", "GtkFileChooser*");
  XEN_ASSERT_TYPE(XEN_char__P(uri), uri, 2, "gtk_file_chooser_set_uri", "char*");
  return(C_TO_XEN_gboolean(gtk_file_chooser_set_uri(XEN_TO_C_GtkFileChooser_(chooser), XEN_TO_C_char_(uri))));
}
static XEN gxg_gtk_file_chooser_select_uri(XEN chooser, XEN uri)
{
  #define H_gtk_file_chooser_select_uri "gboolean gtk_file_chooser_select_uri(GtkFileChooser* chooser, \
char* uri)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_select_uri", "GtkFileChooser*");
  XEN_ASSERT_TYPE(XEN_char__P(uri), uri, 2, "gtk_file_chooser_select_uri", "char*");
  return(C_TO_XEN_gboolean(gtk_file_chooser_select_uri(XEN_TO_C_GtkFileChooser_(chooser), XEN_TO_C_char_(uri))));
}
static XEN gxg_gtk_file_chooser_set_current_folder_uri(XEN chooser, XEN uri)
{
  #define H_gtk_file_chooser_set_current_folder_uri "gboolean gtk_file_chooser_set_current_folder_uri(GtkFileChooser* chooser, \
gchar* uri)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_set_current_folder_uri", "GtkFileChooser*");
  XEN_ASSERT_TYPE(XEN_gchar__P(uri), uri, 2, "gtk_file_chooser_set_current_folder_uri", "gchar*");
  return(C_TO_XEN_gboolean(gtk_file_chooser_set_current_folder_uri(XEN_TO_C_GtkFileChooser_(chooser), XEN_TO_C_gchar_(uri))));
}
#endif

#if HAVE_GTK_ABOUT_DIALOG_NEW
static XEN gxg_gtk_cell_view_get_type(void)
{
  #define H_gtk_cell_view_get_type "GType gtk_cell_view_get_type( void)"
  return(C_TO_XEN_GType(gtk_cell_view_get_type()));
}
static XEN gxg_gtk_cell_view_new(void)
{
  #define H_gtk_cell_view_new "GtkWidget* gtk_cell_view_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_cell_view_new()));
}
static XEN gxg_gtk_cell_view_new_with_text(XEN text)
{
  #define H_gtk_cell_view_new_with_text "GtkWidget* gtk_cell_view_new_with_text(gchar* text)"
  XEN_ASSERT_TYPE(XEN_gchar__P(text), text, 1, "gtk_cell_view_new_with_text", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_cell_view_new_with_text(XEN_TO_C_gchar_(text))));
}
static XEN gxg_gtk_cell_view_new_with_markup(XEN markup)
{
  #define H_gtk_cell_view_new_with_markup "GtkWidget* gtk_cell_view_new_with_markup(gchar* markup)"
  XEN_ASSERT_TYPE(XEN_gchar__P(markup), markup, 1, "gtk_cell_view_new_with_markup", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_cell_view_new_with_markup(XEN_TO_C_gchar_(markup))));
}
static XEN gxg_gtk_cell_view_new_with_pixbuf(XEN pixbuf)
{
  #define H_gtk_cell_view_new_with_pixbuf "GtkWidget* gtk_cell_view_new_with_pixbuf(GdkPixbuf* pixbuf)"
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(pixbuf), pixbuf, 1, "gtk_cell_view_new_with_pixbuf", "GdkPixbuf*");
  return(C_TO_XEN_GtkWidget_(gtk_cell_view_new_with_pixbuf(XEN_TO_C_GdkPixbuf_(pixbuf))));
}
static XEN gxg_gtk_cell_view_set_value(XEN cell_view, XEN renderer, XEN property, XEN value)
{
  #define H_gtk_cell_view_set_value "void gtk_cell_view_set_value(GtkCellView* cell_view, GtkCellRenderer* renderer, \
gchar* property, GValue* value)"
  XEN_ASSERT_TYPE(XEN_GtkCellView__P(cell_view), cell_view, 1, "gtk_cell_view_set_value", "GtkCellView*");
  XEN_ASSERT_TYPE(XEN_GtkCellRenderer__P(renderer), renderer, 2, "gtk_cell_view_set_value", "GtkCellRenderer*");
  XEN_ASSERT_TYPE(XEN_gchar__P(property), property, 3, "gtk_cell_view_set_value", "gchar*");
  XEN_ASSERT_TYPE(XEN_GValue__P(value), value, 4, "gtk_cell_view_set_value", "GValue*");
  gtk_cell_view_set_value(XEN_TO_C_GtkCellView_(cell_view), XEN_TO_C_GtkCellRenderer_(renderer), XEN_TO_C_gchar_(property), 
                          XEN_TO_C_GValue_(value));
  return(XEN_FALSE);
}
static XEN gxg_gtk_cell_view_set_model(XEN cell_view, XEN model)
{
  #define H_gtk_cell_view_set_model "void gtk_cell_view_set_model(GtkCellView* cell_view, GtkTreeModel* model)"
  XEN_ASSERT_TYPE(XEN_GtkCellView__P(cell_view), cell_view, 1, "gtk_cell_view_set_model", "GtkCellView*");
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(model), model, 2, "gtk_cell_view_set_model", "GtkTreeModel*");
  gtk_cell_view_set_model(XEN_TO_C_GtkCellView_(cell_view), XEN_TO_C_GtkTreeModel_(model));
  return(XEN_FALSE);
}
static XEN gxg_gtk_cell_view_set_displayed_row(XEN cell_view, XEN path)
{
  #define H_gtk_cell_view_set_displayed_row "void gtk_cell_view_set_displayed_row(GtkCellView* cell_view, \
GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GtkCellView__P(cell_view), cell_view, 1, "gtk_cell_view_set_displayed_row", "GtkCellView*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 2, "gtk_cell_view_set_displayed_row", "GtkTreePath*");
  gtk_cell_view_set_displayed_row(XEN_TO_C_GtkCellView_(cell_view), XEN_TO_C_GtkTreePath_(path));
  return(XEN_FALSE);
}
static XEN gxg_gtk_cell_view_get_displayed_row(XEN cell_view)
{
  #define H_gtk_cell_view_get_displayed_row "GtkTreePath* gtk_cell_view_get_displayed_row(GtkCellView* cell_view)"
  XEN_ASSERT_TYPE(XEN_GtkCellView__P(cell_view), cell_view, 1, "gtk_cell_view_get_displayed_row", "GtkCellView*");
  return(C_TO_XEN_GtkTreePath_(gtk_cell_view_get_displayed_row(XEN_TO_C_GtkCellView_(cell_view))));
}
static XEN gxg_gtk_cell_view_get_size_of_row(XEN cell_view, XEN path, XEN requisition)
{
  #define H_gtk_cell_view_get_size_of_row "gboolean gtk_cell_view_get_size_of_row(GtkCellView* cell_view, \
GtkTreePath* path, GtkRequisition* requisition)"
  XEN_ASSERT_TYPE(XEN_GtkCellView__P(cell_view), cell_view, 1, "gtk_cell_view_get_size_of_row", "GtkCellView*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 2, "gtk_cell_view_get_size_of_row", "GtkTreePath*");
  XEN_ASSERT_TYPE(XEN_GtkRequisition__P(requisition), requisition, 3, "gtk_cell_view_get_size_of_row", "GtkRequisition*");
  return(C_TO_XEN_gboolean(gtk_cell_view_get_size_of_row(XEN_TO_C_GtkCellView_(cell_view), XEN_TO_C_GtkTreePath_(path), XEN_TO_C_GtkRequisition_(requisition))));
}
static XEN gxg_gtk_cell_view_set_background_color(XEN cell_view, XEN color)
{
  #define H_gtk_cell_view_set_background_color "void gtk_cell_view_set_background_color(GtkCellView* cell_view, \
GdkColor* color)"
  XEN_ASSERT_TYPE(XEN_GtkCellView__P(cell_view), cell_view, 1, "gtk_cell_view_set_background_color", "GtkCellView*");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(color), color, 2, "gtk_cell_view_set_background_color", "GdkColor*");
  gtk_cell_view_set_background_color(XEN_TO_C_GtkCellView_(cell_view), XEN_TO_C_GdkColor_(color));
  return(XEN_FALSE);
}
static XEN gxg_gtk_cell_view_set_cell_data(XEN cellview)
{
  #define H_gtk_cell_view_set_cell_data "void gtk_cell_view_set_cell_data(GtkCellView* cellview)"
  XEN_ASSERT_TYPE(XEN_GtkCellView__P(cellview), cellview, 1, "gtk_cell_view_set_cell_data", "GtkCellView*");
  gtk_cell_view_set_cell_data(XEN_TO_C_GtkCellView_(cellview));
  return(XEN_FALSE);
}
static XEN gxg_gtk_cell_view_get_cell_renderers(XEN cellview)
{
  #define H_gtk_cell_view_get_cell_renderers "GList* gtk_cell_view_get_cell_renderers(GtkCellView* cellview)"
  XEN_ASSERT_TYPE(XEN_GtkCellView__P(cellview), cellview, 1, "gtk_cell_view_get_cell_renderers", "GtkCellView*");
  return(C_TO_XEN_GList_(gtk_cell_view_get_cell_renderers(XEN_TO_C_GtkCellView_(cellview))));
}
static XEN gxg_gdk_window_set_focus_on_map(XEN window, XEN focus_on_map)
{
  #define H_gdk_window_set_focus_on_map "void gdk_window_set_focus_on_map(GdkWindow* window, gboolean focus_on_map)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_set_focus_on_map", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(focus_on_map), focus_on_map, 2, "gdk_window_set_focus_on_map", "gboolean");
  gdk_window_set_focus_on_map(XEN_TO_C_GdkWindow_(window), XEN_TO_C_gboolean(focus_on_map));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_enable_synchronized_configure(XEN window)
{
  #define H_gdk_window_enable_synchronized_configure "void gdk_window_enable_synchronized_configure(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_enable_synchronized_configure", "GdkWindow*");
  gdk_window_enable_synchronized_configure(XEN_TO_C_GdkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_configure_finished(XEN window)
{
  #define H_gdk_window_configure_finished "void gdk_window_configure_finished(GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_configure_finished", "GdkWindow*");
  gdk_window_configure_finished(XEN_TO_C_GdkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gtk_combo_box_get_wrap_width(XEN combo_box)
{
  #define H_gtk_combo_box_get_wrap_width "gint gtk_combo_box_get_wrap_width(GtkComboBox* combo_box)"
  XEN_ASSERT_TYPE(XEN_GtkComboBox__P(combo_box), combo_box, 1, "gtk_combo_box_get_wrap_width", "GtkComboBox*");
  return(C_TO_XEN_gint(gtk_combo_box_get_wrap_width(XEN_TO_C_GtkComboBox_(combo_box))));
}
static XEN gxg_gtk_combo_box_get_row_span_column(XEN combo_box)
{
  #define H_gtk_combo_box_get_row_span_column "gint gtk_combo_box_get_row_span_column(GtkComboBox* combo_box)"
  XEN_ASSERT_TYPE(XEN_GtkComboBox__P(combo_box), combo_box, 1, "gtk_combo_box_get_row_span_column", "GtkComboBox*");
  return(C_TO_XEN_gint(gtk_combo_box_get_row_span_column(XEN_TO_C_GtkComboBox_(combo_box))));
}
static XEN gxg_gtk_combo_box_get_column_span_column(XEN combo_box)
{
  #define H_gtk_combo_box_get_column_span_column "gint gtk_combo_box_get_column_span_column(GtkComboBox* combo_box)"
  XEN_ASSERT_TYPE(XEN_GtkComboBox__P(combo_box), combo_box, 1, "gtk_combo_box_get_column_span_column", "GtkComboBox*");
  return(C_TO_XEN_gint(gtk_combo_box_get_column_span_column(XEN_TO_C_GtkComboBox_(combo_box))));
}
static XEN gxg_gtk_combo_box_get_add_tearoffs(XEN combo_box)
{
  #define H_gtk_combo_box_get_add_tearoffs "gboolean gtk_combo_box_get_add_tearoffs(GtkComboBox* combo_box)"
  XEN_ASSERT_TYPE(XEN_GtkComboBox__P(combo_box), combo_box, 1, "gtk_combo_box_get_add_tearoffs", "GtkComboBox*");
  return(C_TO_XEN_gboolean(gtk_combo_box_get_add_tearoffs(XEN_TO_C_GtkComboBox_(combo_box))));
}
static XEN gxg_gtk_combo_box_set_add_tearoffs(XEN combo_box, XEN add_tearoffs)
{
  #define H_gtk_combo_box_set_add_tearoffs "void gtk_combo_box_set_add_tearoffs(GtkComboBox* combo_box, \
gboolean add_tearoffs)"
  XEN_ASSERT_TYPE(XEN_GtkComboBox__P(combo_box), combo_box, 1, "gtk_combo_box_set_add_tearoffs", "GtkComboBox*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(add_tearoffs), add_tearoffs, 2, "gtk_combo_box_set_add_tearoffs", "gboolean");
  gtk_combo_box_set_add_tearoffs(XEN_TO_C_GtkComboBox_(combo_box), XEN_TO_C_gboolean(add_tearoffs));
  return(XEN_FALSE);
}
static XEN gxg_gtk_combo_box_get_active_text(XEN combo_box)
{
  #define H_gtk_combo_box_get_active_text "gchar* gtk_combo_box_get_active_text(GtkComboBox* combo_box)"
  XEN_ASSERT_TYPE(XEN_GtkComboBox__P(combo_box), combo_box, 1, "gtk_combo_box_get_active_text", "GtkComboBox*");
  return(C_TO_XEN_gchar_(gtk_combo_box_get_active_text(XEN_TO_C_GtkComboBox_(combo_box))));
}
static XEN gxg_gtk_drag_dest_add_text_targets(XEN widget)
{
  #define H_gtk_drag_dest_add_text_targets "void gtk_drag_dest_add_text_targets(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_drag_dest_add_text_targets", "GtkWidget*");
  gtk_drag_dest_add_text_targets(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_drag_source_add_text_targets(XEN widget)
{
  #define H_gtk_drag_source_add_text_targets "void gtk_drag_source_add_text_targets(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_drag_source_add_text_targets", "GtkWidget*");
  gtk_drag_source_add_text_targets(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_entry_completion_insert_prefix(XEN completion)
{
  #define H_gtk_entry_completion_insert_prefix "void gtk_entry_completion_insert_prefix(GtkEntryCompletion* completion)"
  XEN_ASSERT_TYPE(XEN_GtkEntryCompletion__P(completion), completion, 1, "gtk_entry_completion_insert_prefix", "GtkEntryCompletion*");
  gtk_entry_completion_insert_prefix(XEN_TO_C_GtkEntryCompletion_(completion));
  return(XEN_FALSE);
}
static XEN gxg_gtk_entry_completion_set_inline_completion(XEN completion, XEN inline_completion)
{
  #define H_gtk_entry_completion_set_inline_completion "void gtk_entry_completion_set_inline_completion(GtkEntryCompletion* completion, \
gboolean inline_completion)"
  XEN_ASSERT_TYPE(XEN_GtkEntryCompletion__P(completion), completion, 1, "gtk_entry_completion_set_inline_completion", "GtkEntryCompletion*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(inline_completion), inline_completion, 2, "gtk_entry_completion_set_inline_completion", "gboolean");
  gtk_entry_completion_set_inline_completion(XEN_TO_C_GtkEntryCompletion_(completion), XEN_TO_C_gboolean(inline_completion));
  return(XEN_FALSE);
}
static XEN gxg_gtk_entry_completion_get_inline_completion(XEN completion)
{
  #define H_gtk_entry_completion_get_inline_completion "gboolean gtk_entry_completion_get_inline_completion(GtkEntryCompletion* completion)"
  XEN_ASSERT_TYPE(XEN_GtkEntryCompletion__P(completion), completion, 1, "gtk_entry_completion_get_inline_completion", "GtkEntryCompletion*");
  return(C_TO_XEN_gboolean(gtk_entry_completion_get_inline_completion(XEN_TO_C_GtkEntryCompletion_(completion))));
}
static XEN gxg_gtk_entry_completion_set_popup_completion(XEN completion, XEN popup_completion)
{
  #define H_gtk_entry_completion_set_popup_completion "void gtk_entry_completion_set_popup_completion(GtkEntryCompletion* completion, \
gboolean popup_completion)"
  XEN_ASSERT_TYPE(XEN_GtkEntryCompletion__P(completion), completion, 1, "gtk_entry_completion_set_popup_completion", "GtkEntryCompletion*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(popup_completion), popup_completion, 2, "gtk_entry_completion_set_popup_completion", "gboolean");
  gtk_entry_completion_set_popup_completion(XEN_TO_C_GtkEntryCompletion_(completion), XEN_TO_C_gboolean(popup_completion));
  return(XEN_FALSE);
}
static XEN gxg_gtk_entry_completion_get_popup_completion(XEN completion)
{
  #define H_gtk_entry_completion_get_popup_completion "gboolean gtk_entry_completion_get_popup_completion(GtkEntryCompletion* completion)"
  XEN_ASSERT_TYPE(XEN_GtkEntryCompletion__P(completion), completion, 1, "gtk_entry_completion_get_popup_completion", "GtkEntryCompletion*");
  return(C_TO_XEN_gboolean(gtk_entry_completion_get_popup_completion(XEN_TO_C_GtkEntryCompletion_(completion))));
}
static XEN gxg_gtk_entry_completion_get_text_column(XEN completion)
{
  #define H_gtk_entry_completion_get_text_column "gint gtk_entry_completion_get_text_column(GtkEntryCompletion* completion)"
  XEN_ASSERT_TYPE(XEN_GtkEntryCompletion__P(completion), completion, 1, "gtk_entry_completion_get_text_column", "GtkEntryCompletion*");
  return(C_TO_XEN_gint(gtk_entry_completion_get_text_column(XEN_TO_C_GtkEntryCompletion_(completion))));
}
static XEN gxg_gtk_icon_theme_get_icon_sizes(XEN icon_theme, XEN icon_name)
{
  #define H_gtk_icon_theme_get_icon_sizes "gint* gtk_icon_theme_get_icon_sizes(GtkIconTheme* icon_theme, \
gchar* icon_name)"
  XEN_ASSERT_TYPE(XEN_GtkIconTheme__P(icon_theme), icon_theme, 1, "gtk_icon_theme_get_icon_sizes", "GtkIconTheme*");
  XEN_ASSERT_TYPE(XEN_gchar__P(icon_name), icon_name, 2, "gtk_icon_theme_get_icon_sizes", "gchar*");
  return(C_TO_XEN_gint_(gtk_icon_theme_get_icon_sizes(XEN_TO_C_GtkIconTheme_(icon_theme), XEN_TO_C_gchar_(icon_name))));
}
static XEN gxg_gtk_menu_get_for_attach_widget(XEN widget )
{
  #define H_gtk_menu_get_for_attach_widget "GList* gtk_menu_get_for_attach_widget(GtkWidget* widget, \
)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget ), widget , 1, "gtk_menu_get_for_attach_widget", "GtkWidget*");
  return(C_TO_XEN_GList_(gtk_menu_get_for_attach_widget(XEN_TO_C_GtkWidget_(widget ))));
}
static XEN gxg_gtk_tree_view_set_fixed_height_mode(XEN tree_view, XEN enable)
{
  #define H_gtk_tree_view_set_fixed_height_mode "void gtk_tree_view_set_fixed_height_mode(GtkTreeView* tree_view, \
gboolean enable)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_set_fixed_height_mode", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(enable), enable, 2, "gtk_tree_view_set_fixed_height_mode", "gboolean");
  gtk_tree_view_set_fixed_height_mode(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_gboolean(enable));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_get_fixed_height_mode(XEN tree_view)
{
  #define H_gtk_tree_view_get_fixed_height_mode "gboolean gtk_tree_view_get_fixed_height_mode(GtkTreeView* tree_view)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_get_fixed_height_mode", "GtkTreeView*");
  return(C_TO_XEN_gboolean(gtk_tree_view_get_fixed_height_mode(XEN_TO_C_GtkTreeView_(tree_view))));
}
static XEN gxg_gtk_tree_view_set_hover_selection(XEN tree_view, XEN hover)
{
  #define H_gtk_tree_view_set_hover_selection "void gtk_tree_view_set_hover_selection(GtkTreeView* tree_view, \
gboolean hover)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_set_hover_selection", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(hover), hover, 2, "gtk_tree_view_set_hover_selection", "gboolean");
  gtk_tree_view_set_hover_selection(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_gboolean(hover));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_get_hover_selection(XEN tree_view)
{
  #define H_gtk_tree_view_get_hover_selection "gboolean gtk_tree_view_get_hover_selection(GtkTreeView* tree_view)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_get_hover_selection", "GtkTreeView*");
  return(C_TO_XEN_gboolean(gtk_tree_view_get_hover_selection(XEN_TO_C_GtkTreeView_(tree_view))));
}
static XEN gxg_gtk_tree_view_set_row_separator_func(XEN tree_view, XEN func, XEN func_data, XEN destroy)
{
  #define H_gtk_tree_view_set_row_separator_func "void gtk_tree_view_set_row_separator_func(GtkTreeView* tree_view, \
GtkTreeViewRowSeparatorFunc func, lambda_data func_data, GtkDestroyNotify destroy)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_set_row_separator_func", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_GtkTreeViewRowSeparatorFunc_P(func), func, 2, "gtk_tree_view_set_row_separator_func", "GtkTreeViewRowSeparatorFunc");
  XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 3, "gtk_tree_view_set_row_separator_func", "lambda_data");
  XEN_ASSERT_TYPE(XEN_GtkDestroyNotify_P(destroy), destroy, 4, "gtk_tree_view_set_row_separator_func", "GtkDestroyNotify");
  {
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 3, destroy);
    gtk_tree_view_set_row_separator_func(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_GtkTreeViewRowSeparatorFunc(func), XEN_TO_C_lambda_data(func_data), 
                                     XEN_TO_C_GtkDestroyNotify(destroy));
    return(XEN_FALSE);
   }
}
static XEN gxg_gtk_window_set_focus_on_map(XEN window, XEN setting)
{
  #define H_gtk_window_set_focus_on_map "void gtk_window_set_focus_on_map(GtkWindow* window, gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_set_focus_on_map", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gtk_window_set_focus_on_map", "gboolean");
  gtk_window_set_focus_on_map(XEN_TO_C_GtkWindow_(window), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_get_focus_on_map(XEN window)
{
  #define H_gtk_window_get_focus_on_map "gboolean gtk_window_get_focus_on_map(GtkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_get_focus_on_map", "GtkWindow*");
  return(C_TO_XEN_gboolean(gtk_window_get_focus_on_map(XEN_TO_C_GtkWindow_(window))));
}
static XEN gxg_gtk_window_set_icon_name(XEN window, XEN name)
{
  #define H_gtk_window_set_icon_name "void gtk_window_set_icon_name(GtkWindow* window, gchar* name)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_set_icon_name", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_gchar__P(name), name, 2, "gtk_window_set_icon_name", "gchar*");
  gtk_window_set_icon_name(XEN_TO_C_GtkWindow_(window), XEN_TO_C_gchar_(name));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_get_icon_name(XEN window)
{
  #define H_gtk_window_get_icon_name "gchar* gtk_window_get_icon_name(GtkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_get_icon_name", "GtkWindow*");
  return(C_TO_XEN_gchar_(gtk_window_get_icon_name(XEN_TO_C_GtkWindow_(window))));
}
static XEN gxg_gtk_window_set_default_icon_name(XEN name)
{
  #define H_gtk_window_set_default_icon_name "void gtk_window_set_default_icon_name(gchar* name)"
  XEN_ASSERT_TYPE(XEN_gchar__P(name), name, 1, "gtk_window_set_default_icon_name", "gchar*");
  gtk_window_set_default_icon_name(XEN_TO_C_gchar_(name));
  return(XEN_FALSE);
}
static XEN gxg_gtk_about_dialog_get_type(void)
{
  #define H_gtk_about_dialog_get_type "GType gtk_about_dialog_get_type( void)"
  return(C_TO_XEN_GType(gtk_about_dialog_get_type()));
}
static XEN gxg_gtk_about_dialog_new(void)
{
  #define H_gtk_about_dialog_new "GtkWidget* gtk_about_dialog_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_about_dialog_new()));
}
static XEN gxg_gtk_about_dialog_get_name(XEN about)
{
  #define H_gtk_about_dialog_get_name "gchar* gtk_about_dialog_get_name(GtkAboutDialog* about)"
  XEN_ASSERT_TYPE(XEN_GtkAboutDialog__P(about), about, 1, "gtk_about_dialog_get_name", "GtkAboutDialog*");
  return(C_TO_XEN_gchar_(gtk_about_dialog_get_name(XEN_TO_C_GtkAboutDialog_(about))));
}
static XEN gxg_gtk_about_dialog_set_name(XEN about, XEN name)
{
  #define H_gtk_about_dialog_set_name "void gtk_about_dialog_set_name(GtkAboutDialog* about, gchar* name)"
  XEN_ASSERT_TYPE(XEN_GtkAboutDialog__P(about), about, 1, "gtk_about_dialog_set_name", "GtkAboutDialog*");
  XEN_ASSERT_TYPE(XEN_gchar__P(name), name, 2, "gtk_about_dialog_set_name", "gchar*");
  gtk_about_dialog_set_name(XEN_TO_C_GtkAboutDialog_(about), XEN_TO_C_gchar_(name));
  return(XEN_FALSE);
}
static XEN gxg_gtk_about_dialog_get_version(XEN about)
{
  #define H_gtk_about_dialog_get_version "gchar* gtk_about_dialog_get_version(GtkAboutDialog* about)"
  XEN_ASSERT_TYPE(XEN_GtkAboutDialog__P(about), about, 1, "gtk_about_dialog_get_version", "GtkAboutDialog*");
  return(C_TO_XEN_gchar_(gtk_about_dialog_get_version(XEN_TO_C_GtkAboutDialog_(about))));
}
static XEN gxg_gtk_about_dialog_set_version(XEN about, XEN version)
{
  #define H_gtk_about_dialog_set_version "void gtk_about_dialog_set_version(GtkAboutDialog* about, gchar* version)"
  XEN_ASSERT_TYPE(XEN_GtkAboutDialog__P(about), about, 1, "gtk_about_dialog_set_version", "GtkAboutDialog*");
  XEN_ASSERT_TYPE(XEN_gchar__P(version), version, 2, "gtk_about_dialog_set_version", "gchar*");
  gtk_about_dialog_set_version(XEN_TO_C_GtkAboutDialog_(about), XEN_TO_C_gchar_(version));
  return(XEN_FALSE);
}
static XEN gxg_gtk_about_dialog_get_copyright(XEN about)
{
  #define H_gtk_about_dialog_get_copyright "gchar* gtk_about_dialog_get_copyright(GtkAboutDialog* about)"
  XEN_ASSERT_TYPE(XEN_GtkAboutDialog__P(about), about, 1, "gtk_about_dialog_get_copyright", "GtkAboutDialog*");
  return(C_TO_XEN_gchar_(gtk_about_dialog_get_copyright(XEN_TO_C_GtkAboutDialog_(about))));
}
static XEN gxg_gtk_about_dialog_set_copyright(XEN about, XEN copyright)
{
  #define H_gtk_about_dialog_set_copyright "void gtk_about_dialog_set_copyright(GtkAboutDialog* about, \
gchar* copyright)"
  XEN_ASSERT_TYPE(XEN_GtkAboutDialog__P(about), about, 1, "gtk_about_dialog_set_copyright", "GtkAboutDialog*");
  XEN_ASSERT_TYPE(XEN_gchar__P(copyright), copyright, 2, "gtk_about_dialog_set_copyright", "gchar*");
  gtk_about_dialog_set_copyright(XEN_TO_C_GtkAboutDialog_(about), XEN_TO_C_gchar_(copyright));
  return(XEN_FALSE);
}
static XEN gxg_gtk_about_dialog_get_comments(XEN about)
{
  #define H_gtk_about_dialog_get_comments "gchar* gtk_about_dialog_get_comments(GtkAboutDialog* about)"
  XEN_ASSERT_TYPE(XEN_GtkAboutDialog__P(about), about, 1, "gtk_about_dialog_get_comments", "GtkAboutDialog*");
  return(C_TO_XEN_gchar_(gtk_about_dialog_get_comments(XEN_TO_C_GtkAboutDialog_(about))));
}
static XEN gxg_gtk_about_dialog_set_comments(XEN about, XEN comments)
{
  #define H_gtk_about_dialog_set_comments "void gtk_about_dialog_set_comments(GtkAboutDialog* about, \
gchar* comments)"
  XEN_ASSERT_TYPE(XEN_GtkAboutDialog__P(about), about, 1, "gtk_about_dialog_set_comments", "GtkAboutDialog*");
  XEN_ASSERT_TYPE(XEN_gchar__P(comments), comments, 2, "gtk_about_dialog_set_comments", "gchar*");
  gtk_about_dialog_set_comments(XEN_TO_C_GtkAboutDialog_(about), XEN_TO_C_gchar_(comments));
  return(XEN_FALSE);
}
static XEN gxg_gtk_about_dialog_get_license(XEN about)
{
  #define H_gtk_about_dialog_get_license "gchar* gtk_about_dialog_get_license(GtkAboutDialog* about)"
  XEN_ASSERT_TYPE(XEN_GtkAboutDialog__P(about), about, 1, "gtk_about_dialog_get_license", "GtkAboutDialog*");
  return(C_TO_XEN_gchar_(gtk_about_dialog_get_license(XEN_TO_C_GtkAboutDialog_(about))));
}
static XEN gxg_gtk_about_dialog_set_license(XEN about, XEN license)
{
  #define H_gtk_about_dialog_set_license "void gtk_about_dialog_set_license(GtkAboutDialog* about, gchar* license)"
  XEN_ASSERT_TYPE(XEN_GtkAboutDialog__P(about), about, 1, "gtk_about_dialog_set_license", "GtkAboutDialog*");
  XEN_ASSERT_TYPE(XEN_gchar__P(license), license, 2, "gtk_about_dialog_set_license", "gchar*");
  gtk_about_dialog_set_license(XEN_TO_C_GtkAboutDialog_(about), XEN_TO_C_gchar_(license));
  return(XEN_FALSE);
}
static XEN gxg_gtk_about_dialog_get_website(XEN about)
{
  #define H_gtk_about_dialog_get_website "gchar* gtk_about_dialog_get_website(GtkAboutDialog* about)"
  XEN_ASSERT_TYPE(XEN_GtkAboutDialog__P(about), about, 1, "gtk_about_dialog_get_website", "GtkAboutDialog*");
  return(C_TO_XEN_gchar_(gtk_about_dialog_get_website(XEN_TO_C_GtkAboutDialog_(about))));
}
static XEN gxg_gtk_about_dialog_set_website(XEN about, XEN website)
{
  #define H_gtk_about_dialog_set_website "void gtk_about_dialog_set_website(GtkAboutDialog* about, gchar* website)"
  XEN_ASSERT_TYPE(XEN_GtkAboutDialog__P(about), about, 1, "gtk_about_dialog_set_website", "GtkAboutDialog*");
  XEN_ASSERT_TYPE(XEN_gchar__P(website), website, 2, "gtk_about_dialog_set_website", "gchar*");
  gtk_about_dialog_set_website(XEN_TO_C_GtkAboutDialog_(about), XEN_TO_C_gchar_(website));
  return(XEN_FALSE);
}
static XEN gxg_gtk_about_dialog_get_website_label(XEN about)
{
  #define H_gtk_about_dialog_get_website_label "gchar* gtk_about_dialog_get_website_label(GtkAboutDialog* about)"
  XEN_ASSERT_TYPE(XEN_GtkAboutDialog__P(about), about, 1, "gtk_about_dialog_get_website_label", "GtkAboutDialog*");
  return(C_TO_XEN_gchar_(gtk_about_dialog_get_website_label(XEN_TO_C_GtkAboutDialog_(about))));
}
static XEN gxg_gtk_about_dialog_set_website_label(XEN about, XEN website_label)
{
  #define H_gtk_about_dialog_set_website_label "void gtk_about_dialog_set_website_label(GtkAboutDialog* about, \
gchar* website_label)"
  XEN_ASSERT_TYPE(XEN_GtkAboutDialog__P(about), about, 1, "gtk_about_dialog_set_website_label", "GtkAboutDialog*");
  XEN_ASSERT_TYPE(XEN_gchar__P(website_label), website_label, 2, "gtk_about_dialog_set_website_label", "gchar*");
  gtk_about_dialog_set_website_label(XEN_TO_C_GtkAboutDialog_(about), XEN_TO_C_gchar_(website_label));
  return(XEN_FALSE);
}
static XEN gxg_gtk_about_dialog_get_authors(XEN about)
{
  #define H_gtk_about_dialog_get_authors "gchar** gtk_about_dialog_get_authors(GtkAboutDialog* about)"
  XEN_ASSERT_TYPE(XEN_GtkAboutDialog__P(about), about, 1, "gtk_about_dialog_get_authors", "GtkAboutDialog*");
    return(C_TO_XEN_gchar__((gchar**)gtk_about_dialog_get_authors(XEN_TO_C_GtkAboutDialog_(about))));
}
static XEN gxg_gtk_about_dialog_set_authors(XEN about, XEN authors)
{
  #define H_gtk_about_dialog_set_authors "void gtk_about_dialog_set_authors(GtkAboutDialog* about, gchar** authors)"
  XEN_ASSERT_TYPE(XEN_GtkAboutDialog__P(about), about, 1, "gtk_about_dialog_set_authors", "GtkAboutDialog*");
  XEN_ASSERT_TYPE(XEN_gchar___P(authors), authors, 2, "gtk_about_dialog_set_authors", "gchar**");
  gtk_about_dialog_set_authors(XEN_TO_C_GtkAboutDialog_(about), (const gchar**)XEN_TO_C_gchar__(authors));
  return(XEN_FALSE);
}
static XEN gxg_gtk_about_dialog_get_documenters(XEN about)
{
  #define H_gtk_about_dialog_get_documenters "gchar** gtk_about_dialog_get_documenters(GtkAboutDialog* about)"
  XEN_ASSERT_TYPE(XEN_GtkAboutDialog__P(about), about, 1, "gtk_about_dialog_get_documenters", "GtkAboutDialog*");
    return(C_TO_XEN_gchar__((gchar**)gtk_about_dialog_get_documenters(XEN_TO_C_GtkAboutDialog_(about))));
}
static XEN gxg_gtk_about_dialog_set_documenters(XEN about, XEN documenters)
{
  #define H_gtk_about_dialog_set_documenters "void gtk_about_dialog_set_documenters(GtkAboutDialog* about, \
gchar** documenters)"
  XEN_ASSERT_TYPE(XEN_GtkAboutDialog__P(about), about, 1, "gtk_about_dialog_set_documenters", "GtkAboutDialog*");
  XEN_ASSERT_TYPE(XEN_gchar___P(documenters), documenters, 2, "gtk_about_dialog_set_documenters", "gchar**");
  gtk_about_dialog_set_documenters(XEN_TO_C_GtkAboutDialog_(about), (const gchar**)XEN_TO_C_gchar__(documenters));
  return(XEN_FALSE);
}
static XEN gxg_gtk_about_dialog_get_artists(XEN about)
{
  #define H_gtk_about_dialog_get_artists "gchar** gtk_about_dialog_get_artists(GtkAboutDialog* about)"
  XEN_ASSERT_TYPE(XEN_GtkAboutDialog__P(about), about, 1, "gtk_about_dialog_get_artists", "GtkAboutDialog*");
    return(C_TO_XEN_gchar__((gchar**)gtk_about_dialog_get_artists(XEN_TO_C_GtkAboutDialog_(about))));
}
static XEN gxg_gtk_about_dialog_set_artists(XEN about, XEN artists)
{
  #define H_gtk_about_dialog_set_artists "void gtk_about_dialog_set_artists(GtkAboutDialog* about, gchar** artists)"
  XEN_ASSERT_TYPE(XEN_GtkAboutDialog__P(about), about, 1, "gtk_about_dialog_set_artists", "GtkAboutDialog*");
  XEN_ASSERT_TYPE(XEN_gchar___P(artists), artists, 2, "gtk_about_dialog_set_artists", "gchar**");
  gtk_about_dialog_set_artists(XEN_TO_C_GtkAboutDialog_(about), (const gchar**)XEN_TO_C_gchar__(artists));
  return(XEN_FALSE);
}
static XEN gxg_gtk_about_dialog_get_translator_credits(XEN about)
{
  #define H_gtk_about_dialog_get_translator_credits "gchar* gtk_about_dialog_get_translator_credits(GtkAboutDialog* about)"
  XEN_ASSERT_TYPE(XEN_GtkAboutDialog__P(about), about, 1, "gtk_about_dialog_get_translator_credits", "GtkAboutDialog*");
  return(C_TO_XEN_gchar_(gtk_about_dialog_get_translator_credits(XEN_TO_C_GtkAboutDialog_(about))));
}
static XEN gxg_gtk_about_dialog_set_translator_credits(XEN about, XEN translator_credits)
{
  #define H_gtk_about_dialog_set_translator_credits "void gtk_about_dialog_set_translator_credits(GtkAboutDialog* about, \
gchar* translator_credits)"
  XEN_ASSERT_TYPE(XEN_GtkAboutDialog__P(about), about, 1, "gtk_about_dialog_set_translator_credits", "GtkAboutDialog*");
  XEN_ASSERT_TYPE(XEN_gchar__P(translator_credits), translator_credits, 2, "gtk_about_dialog_set_translator_credits", "gchar*");
  gtk_about_dialog_set_translator_credits(XEN_TO_C_GtkAboutDialog_(about), XEN_TO_C_gchar_(translator_credits));
  return(XEN_FALSE);
}
static XEN gxg_gtk_about_dialog_get_logo(XEN about)
{
  #define H_gtk_about_dialog_get_logo "GdkPixbuf* gtk_about_dialog_get_logo(GtkAboutDialog* about)"
  XEN_ASSERT_TYPE(XEN_GtkAboutDialog__P(about), about, 1, "gtk_about_dialog_get_logo", "GtkAboutDialog*");
  return(C_TO_XEN_GdkPixbuf_(gtk_about_dialog_get_logo(XEN_TO_C_GtkAboutDialog_(about))));
}
static XEN gxg_gtk_about_dialog_set_logo(XEN about, XEN logo)
{
  #define H_gtk_about_dialog_set_logo "void gtk_about_dialog_set_logo(GtkAboutDialog* about, GdkPixbuf* logo)"
  XEN_ASSERT_TYPE(XEN_GtkAboutDialog__P(about), about, 1, "gtk_about_dialog_set_logo", "GtkAboutDialog*");
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(logo), logo, 2, "gtk_about_dialog_set_logo", "GdkPixbuf*");
  gtk_about_dialog_set_logo(XEN_TO_C_GtkAboutDialog_(about), XEN_TO_C_GdkPixbuf_(logo));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_view_get_type(void)
{
  #define H_gtk_icon_view_get_type "GType gtk_icon_view_get_type( void)"
  return(C_TO_XEN_GType(gtk_icon_view_get_type()));
}
static XEN gxg_gtk_icon_view_new(void)
{
  #define H_gtk_icon_view_new "GtkWidget* gtk_icon_view_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_icon_view_new()));
}
static XEN gxg_gtk_icon_view_new_with_model(XEN model)
{
  #define H_gtk_icon_view_new_with_model "GtkWidget* gtk_icon_view_new_with_model(GtkTreeModel* model)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(model), model, 1, "gtk_icon_view_new_with_model", "GtkTreeModel*");
  return(C_TO_XEN_GtkWidget_(gtk_icon_view_new_with_model(XEN_TO_C_GtkTreeModel_(model))));
}
static XEN gxg_gtk_icon_view_set_model(XEN icon_view, XEN model)
{
  #define H_gtk_icon_view_set_model "void gtk_icon_view_set_model(GtkIconView* icon_view, GtkTreeModel* model)"
  XEN_ASSERT_TYPE(XEN_GtkIconView__P(icon_view), icon_view, 1, "gtk_icon_view_set_model", "GtkIconView*");
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(model), model, 2, "gtk_icon_view_set_model", "GtkTreeModel*");
  gtk_icon_view_set_model(XEN_TO_C_GtkIconView_(icon_view), XEN_TO_C_GtkTreeModel_(model));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_view_get_model(XEN icon_view)
{
  #define H_gtk_icon_view_get_model "GtkTreeModel* gtk_icon_view_get_model(GtkIconView* icon_view)"
  XEN_ASSERT_TYPE(XEN_GtkIconView__P(icon_view), icon_view, 1, "gtk_icon_view_get_model", "GtkIconView*");
  return(C_TO_XEN_GtkTreeModel_(gtk_icon_view_get_model(XEN_TO_C_GtkIconView_(icon_view))));
}
static XEN gxg_gtk_icon_view_set_text_column(XEN icon_view, XEN column)
{
  #define H_gtk_icon_view_set_text_column "void gtk_icon_view_set_text_column(GtkIconView* icon_view, \
gint column)"
  XEN_ASSERT_TYPE(XEN_GtkIconView__P(icon_view), icon_view, 1, "gtk_icon_view_set_text_column", "GtkIconView*");
  XEN_ASSERT_TYPE(XEN_gint_P(column), column, 2, "gtk_icon_view_set_text_column", "gint");
  gtk_icon_view_set_text_column(XEN_TO_C_GtkIconView_(icon_view), XEN_TO_C_gint(column));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_view_get_text_column(XEN icon_view)
{
  #define H_gtk_icon_view_get_text_column "gint gtk_icon_view_get_text_column(GtkIconView* icon_view)"
  XEN_ASSERT_TYPE(XEN_GtkIconView__P(icon_view), icon_view, 1, "gtk_icon_view_get_text_column", "GtkIconView*");
  return(C_TO_XEN_gint(gtk_icon_view_get_text_column(XEN_TO_C_GtkIconView_(icon_view))));
}
static XEN gxg_gtk_icon_view_set_markup_column(XEN icon_view, XEN column)
{
  #define H_gtk_icon_view_set_markup_column "void gtk_icon_view_set_markup_column(GtkIconView* icon_view, \
gint column)"
  XEN_ASSERT_TYPE(XEN_GtkIconView__P(icon_view), icon_view, 1, "gtk_icon_view_set_markup_column", "GtkIconView*");
  XEN_ASSERT_TYPE(XEN_gint_P(column), column, 2, "gtk_icon_view_set_markup_column", "gint");
  gtk_icon_view_set_markup_column(XEN_TO_C_GtkIconView_(icon_view), XEN_TO_C_gint(column));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_view_get_markup_column(XEN icon_view)
{
  #define H_gtk_icon_view_get_markup_column "gint gtk_icon_view_get_markup_column(GtkIconView* icon_view)"
  XEN_ASSERT_TYPE(XEN_GtkIconView__P(icon_view), icon_view, 1, "gtk_icon_view_get_markup_column", "GtkIconView*");
  return(C_TO_XEN_gint(gtk_icon_view_get_markup_column(XEN_TO_C_GtkIconView_(icon_view))));
}
static XEN gxg_gtk_icon_view_set_pixbuf_column(XEN icon_view, XEN column)
{
  #define H_gtk_icon_view_set_pixbuf_column "void gtk_icon_view_set_pixbuf_column(GtkIconView* icon_view, \
gint column)"
  XEN_ASSERT_TYPE(XEN_GtkIconView__P(icon_view), icon_view, 1, "gtk_icon_view_set_pixbuf_column", "GtkIconView*");
  XEN_ASSERT_TYPE(XEN_gint_P(column), column, 2, "gtk_icon_view_set_pixbuf_column", "gint");
  gtk_icon_view_set_pixbuf_column(XEN_TO_C_GtkIconView_(icon_view), XEN_TO_C_gint(column));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_view_get_pixbuf_column(XEN icon_view)
{
  #define H_gtk_icon_view_get_pixbuf_column "gint gtk_icon_view_get_pixbuf_column(GtkIconView* icon_view)"
  XEN_ASSERT_TYPE(XEN_GtkIconView__P(icon_view), icon_view, 1, "gtk_icon_view_get_pixbuf_column", "GtkIconView*");
  return(C_TO_XEN_gint(gtk_icon_view_get_pixbuf_column(XEN_TO_C_GtkIconView_(icon_view))));
}
static XEN gxg_gtk_icon_view_set_orientation(XEN icon_view, XEN orientation)
{
  #define H_gtk_icon_view_set_orientation "void gtk_icon_view_set_orientation(GtkIconView* icon_view, \
GtkOrientation orientation)"
  XEN_ASSERT_TYPE(XEN_GtkIconView__P(icon_view), icon_view, 1, "gtk_icon_view_set_orientation", "GtkIconView*");
  XEN_ASSERT_TYPE(XEN_GtkOrientation_P(orientation), orientation, 2, "gtk_icon_view_set_orientation", "GtkOrientation");
  gtk_icon_view_set_orientation(XEN_TO_C_GtkIconView_(icon_view), XEN_TO_C_GtkOrientation(orientation));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_view_get_orientation(XEN icon_view)
{
  #define H_gtk_icon_view_get_orientation "GtkOrientation gtk_icon_view_get_orientation(GtkIconView* icon_view)"
  XEN_ASSERT_TYPE(XEN_GtkIconView__P(icon_view), icon_view, 1, "gtk_icon_view_get_orientation", "GtkIconView*");
  return(C_TO_XEN_GtkOrientation(gtk_icon_view_get_orientation(XEN_TO_C_GtkIconView_(icon_view))));
}
static XEN gxg_gtk_icon_view_get_path_at_pos(XEN icon_view, XEN x, XEN y)
{
  #define H_gtk_icon_view_get_path_at_pos "GtkTreePath* gtk_icon_view_get_path_at_pos(GtkIconView* icon_view, \
gint x, gint y)"
  XEN_ASSERT_TYPE(XEN_GtkIconView__P(icon_view), icon_view, 1, "gtk_icon_view_get_path_at_pos", "GtkIconView*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 2, "gtk_icon_view_get_path_at_pos", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 3, "gtk_icon_view_get_path_at_pos", "gint");
  return(C_TO_XEN_GtkTreePath_(gtk_icon_view_get_path_at_pos(XEN_TO_C_GtkIconView_(icon_view), XEN_TO_C_gint(x), XEN_TO_C_gint(y))));
}
static XEN gxg_gtk_icon_view_selected_foreach(XEN icon_view, XEN func, XEN func_data)
{
  #define H_gtk_icon_view_selected_foreach "void gtk_icon_view_selected_foreach(GtkIconView* icon_view, \
GtkIconViewForeachFunc func, lambda_data func_data)"
  XEN_ASSERT_TYPE(XEN_GtkIconView__P(icon_view), icon_view, 1, "gtk_icon_view_selected_foreach", "GtkIconView*");
  XEN_ASSERT_TYPE(XEN_GtkIconViewForeachFunc_P(func), func, 2, "gtk_icon_view_selected_foreach", "GtkIconViewForeachFunc");
  XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 3, "gtk_icon_view_selected_foreach", "lambda_data");
  {
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    xm_protect(gxg_ptr);
    gtk_icon_view_selected_foreach(XEN_TO_C_GtkIconView_(icon_view), XEN_TO_C_GtkIconViewForeachFunc(func), XEN_TO_C_lambda_data(func_data));
    return(XEN_FALSE);
   }
}
static XEN gxg_gtk_icon_view_set_selection_mode(XEN icon_view, XEN mode)
{
  #define H_gtk_icon_view_set_selection_mode "void gtk_icon_view_set_selection_mode(GtkIconView* icon_view, \
GtkSelectionMode mode)"
  XEN_ASSERT_TYPE(XEN_GtkIconView__P(icon_view), icon_view, 1, "gtk_icon_view_set_selection_mode", "GtkIconView*");
  XEN_ASSERT_TYPE(XEN_GtkSelectionMode_P(mode), mode, 2, "gtk_icon_view_set_selection_mode", "GtkSelectionMode");
  gtk_icon_view_set_selection_mode(XEN_TO_C_GtkIconView_(icon_view), XEN_TO_C_GtkSelectionMode(mode));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_view_get_selection_mode(XEN icon_view)
{
  #define H_gtk_icon_view_get_selection_mode "GtkSelectionMode gtk_icon_view_get_selection_mode(GtkIconView* icon_view)"
  XEN_ASSERT_TYPE(XEN_GtkIconView__P(icon_view), icon_view, 1, "gtk_icon_view_get_selection_mode", "GtkIconView*");
  return(C_TO_XEN_GtkSelectionMode(gtk_icon_view_get_selection_mode(XEN_TO_C_GtkIconView_(icon_view))));
}
static XEN gxg_gtk_icon_view_select_path(XEN icon_view, XEN path)
{
  #define H_gtk_icon_view_select_path "void gtk_icon_view_select_path(GtkIconView* icon_view, GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GtkIconView__P(icon_view), icon_view, 1, "gtk_icon_view_select_path", "GtkIconView*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 2, "gtk_icon_view_select_path", "GtkTreePath*");
  gtk_icon_view_select_path(XEN_TO_C_GtkIconView_(icon_view), XEN_TO_C_GtkTreePath_(path));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_view_unselect_path(XEN icon_view, XEN path)
{
  #define H_gtk_icon_view_unselect_path "void gtk_icon_view_unselect_path(GtkIconView* icon_view, GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GtkIconView__P(icon_view), icon_view, 1, "gtk_icon_view_unselect_path", "GtkIconView*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 2, "gtk_icon_view_unselect_path", "GtkTreePath*");
  gtk_icon_view_unselect_path(XEN_TO_C_GtkIconView_(icon_view), XEN_TO_C_GtkTreePath_(path));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_view_path_is_selected(XEN icon_view, XEN path)
{
  #define H_gtk_icon_view_path_is_selected "gboolean gtk_icon_view_path_is_selected(GtkIconView* icon_view, \
GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GtkIconView__P(icon_view), icon_view, 1, "gtk_icon_view_path_is_selected", "GtkIconView*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 2, "gtk_icon_view_path_is_selected", "GtkTreePath*");
  return(C_TO_XEN_gboolean(gtk_icon_view_path_is_selected(XEN_TO_C_GtkIconView_(icon_view), XEN_TO_C_GtkTreePath_(path))));
}
static XEN gxg_gtk_icon_view_get_selected_items(XEN icon_view)
{
  #define H_gtk_icon_view_get_selected_items "GList* gtk_icon_view_get_selected_items(GtkIconView* icon_view)"
  XEN_ASSERT_TYPE(XEN_GtkIconView__P(icon_view), icon_view, 1, "gtk_icon_view_get_selected_items", "GtkIconView*");
  return(C_TO_XEN_GList_(gtk_icon_view_get_selected_items(XEN_TO_C_GtkIconView_(icon_view))));
}
static XEN gxg_gtk_icon_view_select_all(XEN icon_view)
{
  #define H_gtk_icon_view_select_all "void gtk_icon_view_select_all(GtkIconView* icon_view)"
  XEN_ASSERT_TYPE(XEN_GtkIconView__P(icon_view), icon_view, 1, "gtk_icon_view_select_all", "GtkIconView*");
  gtk_icon_view_select_all(XEN_TO_C_GtkIconView_(icon_view));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_view_unselect_all(XEN icon_view)
{
  #define H_gtk_icon_view_unselect_all "void gtk_icon_view_unselect_all(GtkIconView* icon_view)"
  XEN_ASSERT_TYPE(XEN_GtkIconView__P(icon_view), icon_view, 1, "gtk_icon_view_unselect_all", "GtkIconView*");
  gtk_icon_view_unselect_all(XEN_TO_C_GtkIconView_(icon_view));
  return(XEN_FALSE);
}
static XEN gxg_gtk_icon_view_item_activated(XEN icon_view, XEN path)
{
  #define H_gtk_icon_view_item_activated "void gtk_icon_view_item_activated(GtkIconView* icon_view, GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GtkIconView__P(icon_view), icon_view, 1, "gtk_icon_view_item_activated", "GtkIconView*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 2, "gtk_icon_view_item_activated", "GtkTreePath*");
  gtk_icon_view_item_activated(XEN_TO_C_GtkIconView_(icon_view), XEN_TO_C_GtkTreePath_(path));
  return(XEN_FALSE);
}
static XEN gxg_gtk_cell_renderer_combo_get_type(void)
{
  #define H_gtk_cell_renderer_combo_get_type "GType gtk_cell_renderer_combo_get_type( void)"
  return(C_TO_XEN_GType(gtk_cell_renderer_combo_get_type()));
}
static XEN gxg_gtk_cell_renderer_combo_new(void)
{
  #define H_gtk_cell_renderer_combo_new "GtkCellRenderer* gtk_cell_renderer_combo_new( void)"
  return(C_TO_XEN_GtkCellRenderer_(gtk_cell_renderer_combo_new()));
}
static XEN gxg_gtk_cell_renderer_progress_get_type(void)
{
  #define H_gtk_cell_renderer_progress_get_type "GType gtk_cell_renderer_progress_get_type( void)"
  return(C_TO_XEN_GType(gtk_cell_renderer_progress_get_type()));
}
static XEN gxg_gtk_cell_renderer_progress_new(void)
{
  #define H_gtk_cell_renderer_progress_new "GtkCellRenderer* gtk_cell_renderer_progress_new( void)"
  return(C_TO_XEN_GtkCellRenderer_(gtk_cell_renderer_progress_new()));
}
#endif

#if HAVE_GTK_LABEL_SET_ELLIPSIZE
static XEN gxg_gtk_combo_box_set_row_separator_func(XEN combo_box, XEN func, XEN func_data, XEN destroy)
{
  #define H_gtk_combo_box_set_row_separator_func "void gtk_combo_box_set_row_separator_func(GtkComboBox* combo_box, \
GtkTreeViewRowSeparatorFunc func, lambda_data func_data, GtkDestroyNotify destroy)"
  XEN_ASSERT_TYPE(XEN_GtkComboBox__P(combo_box), combo_box, 1, "gtk_combo_box_set_row_separator_func", "GtkComboBox*");
  XEN_ASSERT_TYPE(XEN_GtkTreeViewRowSeparatorFunc_P(func), func, 2, "gtk_combo_box_set_row_separator_func", "GtkTreeViewRowSeparatorFunc");
  XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 3, "gtk_combo_box_set_row_separator_func", "lambda_data");
  XEN_ASSERT_TYPE(XEN_GtkDestroyNotify_P(destroy), destroy, 4, "gtk_combo_box_set_row_separator_func", "GtkDestroyNotify");
  {
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 3, destroy);
    gtk_combo_box_set_row_separator_func(XEN_TO_C_GtkComboBox_(combo_box), XEN_TO_C_GtkTreeViewRowSeparatorFunc(func), XEN_TO_C_lambda_data(func_data), 
                                     XEN_TO_C_GtkDestroyNotify(destroy));
    return(XEN_FALSE);
   }
}
static XEN gxg_gtk_label_set_ellipsize(XEN label, XEN mode)
{
  #define H_gtk_label_set_ellipsize "void gtk_label_set_ellipsize(GtkLabel* label, PangoEllipsizeMode mode)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_set_ellipsize", "GtkLabel*");
  XEN_ASSERT_TYPE(XEN_PangoEllipsizeMode_P(mode), mode, 2, "gtk_label_set_ellipsize", "PangoEllipsizeMode");
  gtk_label_set_ellipsize(XEN_TO_C_GtkLabel_(label), XEN_TO_C_PangoEllipsizeMode(mode));
  return(XEN_FALSE);
}
static XEN gxg_gtk_label_get_ellipsize(XEN label)
{
  #define H_gtk_label_get_ellipsize "PangoEllipsizeMode gtk_label_get_ellipsize(GtkLabel* label)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_get_ellipsize", "GtkLabel*");
  return(C_TO_XEN_PangoEllipsizeMode(gtk_label_get_ellipsize(XEN_TO_C_GtkLabel_(label))));
}
static XEN gxg_pango_attr_fallback_new(XEN enable_fallback)
{
  #define H_pango_attr_fallback_new "PangoAttribute* pango_attr_fallback_new(gboolean enable_fallback)"
  XEN_ASSERT_TYPE(XEN_gboolean_P(enable_fallback), enable_fallback, 1, "pango_attr_fallback_new", "gboolean");
  return(C_TO_XEN_PangoAttribute_(pango_attr_fallback_new(XEN_TO_C_gboolean(enable_fallback))));
}
static XEN gxg_pango_attr_letter_spacing_new(XEN letter_spacing)
{
  #define H_pango_attr_letter_spacing_new "PangoAttribute* pango_attr_letter_spacing_new(int letter_spacing)"
  XEN_ASSERT_TYPE(XEN_int_P(letter_spacing), letter_spacing, 1, "pango_attr_letter_spacing_new", "int");
  return(C_TO_XEN_PangoAttribute_(pango_attr_letter_spacing_new(XEN_TO_C_int(letter_spacing))));
}
static XEN gxg_pango_attr_list_filter(XEN list, XEN func, XEN data)
{
  #define H_pango_attr_list_filter "PangoAttrList* pango_attr_list_filter(PangoAttrList* list, PangoAttrFilterFunc func, \
gpointer data)"
  XEN_ASSERT_TYPE(XEN_PangoAttrList__P(list), list, 1, "pango_attr_list_filter", "PangoAttrList*");
  XEN_ASSERT_TYPE(XEN_PangoAttrFilterFunc_P(func), func, 2, "pango_attr_list_filter", "PangoAttrFilterFunc");
  XEN_ASSERT_TYPE(XEN_gpointer_P(data), data, 3, "pango_attr_list_filter", "gpointer");
  return(C_TO_XEN_PangoAttrList_(pango_attr_list_filter(XEN_TO_C_PangoAttrList_(list), XEN_TO_C_PangoAttrFilterFunc(func), 
                                                        XEN_TO_C_gpointer(data))));
}
static XEN gxg_pango_attr_iterator_get_attrs(XEN iterator)
{
  #define H_pango_attr_iterator_get_attrs "GSList* pango_attr_iterator_get_attrs(PangoAttrIterator* iterator)"
  XEN_ASSERT_TYPE(XEN_PangoAttrIterator__P(iterator), iterator, 1, "pango_attr_iterator_get_attrs", "PangoAttrIterator*");
  return(C_TO_XEN_GSList_(pango_attr_iterator_get_attrs(XEN_TO_C_PangoAttrIterator_(iterator))));
}
static XEN gxg_pango_font_metrics_get_underline_position(XEN metrics)
{
  #define H_pango_font_metrics_get_underline_position "int pango_font_metrics_get_underline_position(PangoFontMetrics* metrics)"
  XEN_ASSERT_TYPE(XEN_PangoFontMetrics__P(metrics), metrics, 1, "pango_font_metrics_get_underline_position", "PangoFontMetrics*");
  return(C_TO_XEN_int(pango_font_metrics_get_underline_position(XEN_TO_C_PangoFontMetrics_(metrics))));
}
static XEN gxg_pango_font_metrics_get_underline_thickness(XEN metrics)
{
  #define H_pango_font_metrics_get_underline_thickness "int pango_font_metrics_get_underline_thickness(PangoFontMetrics* metrics)"
  XEN_ASSERT_TYPE(XEN_PangoFontMetrics__P(metrics), metrics, 1, "pango_font_metrics_get_underline_thickness", "PangoFontMetrics*");
  return(C_TO_XEN_int(pango_font_metrics_get_underline_thickness(XEN_TO_C_PangoFontMetrics_(metrics))));
}
static XEN gxg_pango_font_metrics_get_strikethrough_position(XEN metrics)
{
  #define H_pango_font_metrics_get_strikethrough_position "int pango_font_metrics_get_strikethrough_position(PangoFontMetrics* metrics)"
  XEN_ASSERT_TYPE(XEN_PangoFontMetrics__P(metrics), metrics, 1, "pango_font_metrics_get_strikethrough_position", "PangoFontMetrics*");
  return(C_TO_XEN_int(pango_font_metrics_get_strikethrough_position(XEN_TO_C_PangoFontMetrics_(metrics))));
}
static XEN gxg_pango_font_metrics_get_strikethrough_thickness(XEN metrics)
{
  #define H_pango_font_metrics_get_strikethrough_thickness "int pango_font_metrics_get_strikethrough_thickness(PangoFontMetrics* metrics)"
  XEN_ASSERT_TYPE(XEN_PangoFontMetrics__P(metrics), metrics, 1, "pango_font_metrics_get_strikethrough_thickness", "PangoFontMetrics*");
  return(C_TO_XEN_int(pango_font_metrics_get_strikethrough_thickness(XEN_TO_C_PangoFontMetrics_(metrics))));
}
static XEN gxg_pango_font_family_is_monospace(XEN family)
{
  #define H_pango_font_family_is_monospace "gboolean pango_font_family_is_monospace(PangoFontFamily* family)"
  XEN_ASSERT_TYPE(XEN_PangoFontFamily__P(family), family, 1, "pango_font_family_is_monospace", "PangoFontFamily*");
  return(C_TO_XEN_gboolean(pango_font_family_is_monospace(XEN_TO_C_PangoFontFamily_(family))));
}
static XEN gxg_pango_font_face_list_sizes(XEN face, XEN sizes, XEN n_sizes)
{
  #define H_pango_font_face_list_sizes "void pango_font_face_list_sizes(PangoFontFace* face, int** [sizes], \
int* [n_sizes])"
  int* ref_sizes = NULL;
  int ref_n_sizes;
  XEN_ASSERT_TYPE(XEN_PangoFontFace__P(face), face, 1, "pango_font_face_list_sizes", "PangoFontFace*");
  pango_font_face_list_sizes(XEN_TO_C_PangoFontFace_(face), &ref_sizes, &ref_n_sizes);
  return(XEN_LIST_2(C_TO_XEN_int_(ref_sizes), C_TO_XEN_int(ref_n_sizes)));
}
static XEN gxg_pango_layout_set_auto_dir(XEN layout, XEN auto_dir)
{
  #define H_pango_layout_set_auto_dir "void pango_layout_set_auto_dir(PangoLayout* layout, gboolean auto_dir)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_set_auto_dir", "PangoLayout*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(auto_dir), auto_dir, 2, "pango_layout_set_auto_dir", "gboolean");
  pango_layout_set_auto_dir(XEN_TO_C_PangoLayout_(layout), XEN_TO_C_gboolean(auto_dir));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_get_auto_dir(XEN layout)
{
  #define H_pango_layout_get_auto_dir "gboolean pango_layout_get_auto_dir(PangoLayout* layout)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_get_auto_dir", "PangoLayout*");
  return(C_TO_XEN_gboolean(pango_layout_get_auto_dir(XEN_TO_C_PangoLayout_(layout))));
}
static XEN gxg_pango_script_for_unichar(XEN ch)
{
  #define H_pango_script_for_unichar "PangoScript pango_script_for_unichar(gunichar ch)"
  XEN_ASSERT_TYPE(XEN_gunichar_P(ch), ch, 1, "pango_script_for_unichar", "gunichar");
  return(C_TO_XEN_PangoScript(pango_script_for_unichar(XEN_TO_C_gunichar(ch))));
}
static XEN gxg_pango_script_iter_new(XEN text, XEN length)
{
  #define H_pango_script_iter_new "PangoScriptIter* pango_script_iter_new(char* text, int length)"
  XEN_ASSERT_TYPE(XEN_char__P(text), text, 1, "pango_script_iter_new", "char*");
  XEN_ASSERT_TYPE(XEN_int_P(length), length, 2, "pango_script_iter_new", "int");
  return(C_TO_XEN_PangoScriptIter_(pango_script_iter_new(XEN_TO_C_char_(text), XEN_TO_C_int(length))));
}
static XEN gxg_pango_script_iter_get_range(XEN iter, XEN start, XEN end, XEN script)
{
  #define H_pango_script_iter_get_range "void pango_script_iter_get_range(PangoScriptIter* iter, char** [start], \
char** [end], PangoScript* [script])"
  char* ref_start = NULL;
  char* ref_end = NULL;
  PangoScript ref_script;
  XEN_ASSERT_TYPE(XEN_PangoScriptIter__P(iter), iter, 1, "pango_script_iter_get_range", "PangoScriptIter*");
  pango_script_iter_get_range(XEN_TO_C_PangoScriptIter_(iter), (const char**)&ref_start, (const char**)&ref_end, &ref_script);
  return(XEN_LIST_3(C_TO_XEN_char_(ref_start), C_TO_XEN_char_(ref_end), C_TO_XEN_PangoScript(ref_script)));
}
static XEN gxg_pango_script_iter_next(XEN iter)
{
  #define H_pango_script_iter_next "gboolean pango_script_iter_next(PangoScriptIter* iter)"
  XEN_ASSERT_TYPE(XEN_PangoScriptIter__P(iter), iter, 1, "pango_script_iter_next", "PangoScriptIter*");
  return(C_TO_XEN_gboolean(pango_script_iter_next(XEN_TO_C_PangoScriptIter_(iter))));
}
static XEN gxg_pango_script_iter_free(XEN iter)
{
  #define H_pango_script_iter_free "void pango_script_iter_free(PangoScriptIter* iter)"
  XEN_ASSERT_TYPE(XEN_PangoScriptIter__P(iter), iter, 1, "pango_script_iter_free", "PangoScriptIter*");
  pango_script_iter_free(XEN_TO_C_PangoScriptIter_(iter));
  return(XEN_FALSE);
}
#endif

#if HAVE_GTK_FILE_CHOOSER_BUTTON_NEW
static XEN gxg_gtk_file_chooser_button_get_type(void)
{
  #define H_gtk_file_chooser_button_get_type "GType gtk_file_chooser_button_get_type( void)"
  return(C_TO_XEN_GType(gtk_file_chooser_button_get_type()));
}
static XEN gxg_gtk_file_chooser_button_new(XEN title)
{
  #define H_gtk_file_chooser_button_new "GtkWidget* gtk_file_chooser_button_new(gchar* title)"
  XEN_ASSERT_TYPE(XEN_gchar__P(title), title, 1, "gtk_file_chooser_button_new", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_file_chooser_button_new(XEN_TO_C_gchar_(title))));
}
static XEN gxg_gtk_file_chooser_button_new_with_backend(XEN title, XEN backend)
{
  #define H_gtk_file_chooser_button_new_with_backend "GtkWidget* gtk_file_chooser_button_new_with_backend(gchar* title, \
gchar* backend)"
  XEN_ASSERT_TYPE(XEN_gchar__P(title), title, 1, "gtk_file_chooser_button_new_with_backend", "gchar*");
  XEN_ASSERT_TYPE(XEN_gchar__P(backend), backend, 2, "gtk_file_chooser_button_new_with_backend", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_file_chooser_button_new_with_backend(XEN_TO_C_gchar_(title), XEN_TO_C_gchar_(backend))));
}
static XEN gxg_gtk_file_chooser_button_new_with_dialog(XEN dialog)
{
  #define H_gtk_file_chooser_button_new_with_dialog "GtkWidget* gtk_file_chooser_button_new_with_dialog(GtkWidget* dialog)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(dialog), dialog, 1, "gtk_file_chooser_button_new_with_dialog", "GtkWidget*");
  return(C_TO_XEN_GtkWidget_(gtk_file_chooser_button_new_with_dialog(XEN_TO_C_GtkWidget_(dialog))));
}
static XEN gxg_gtk_file_chooser_button_get_title(XEN button)
{
  #define H_gtk_file_chooser_button_get_title "gchar* gtk_file_chooser_button_get_title(GtkFileChooserButton* button)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooserButton__P(button), button, 1, "gtk_file_chooser_button_get_title", "GtkFileChooserButton*");
  return(C_TO_XEN_gchar_(gtk_file_chooser_button_get_title(XEN_TO_C_GtkFileChooserButton_(button))));
}
static XEN gxg_gtk_file_chooser_button_set_title(XEN button, XEN title)
{
  #define H_gtk_file_chooser_button_set_title "void gtk_file_chooser_button_set_title(GtkFileChooserButton* button, \
gchar* title)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooserButton__P(button), button, 1, "gtk_file_chooser_button_set_title", "GtkFileChooserButton*");
  XEN_ASSERT_TYPE(XEN_gchar__P(title), title, 2, "gtk_file_chooser_button_set_title", "gchar*");
  gtk_file_chooser_button_set_title(XEN_TO_C_GtkFileChooserButton_(button), XEN_TO_C_gchar_(title));
  return(XEN_FALSE);
}
static XEN gxg_gtk_file_chooser_button_get_active(XEN button)
{
  #define H_gtk_file_chooser_button_get_active "gboolean gtk_file_chooser_button_get_active(GtkFileChooserButton* button)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooserButton__P(button), button, 1, "gtk_file_chooser_button_get_active", "GtkFileChooserButton*");
  return(C_TO_XEN_gboolean(gtk_file_chooser_button_get_active(XEN_TO_C_GtkFileChooserButton_(button))));
}
static XEN gxg_gtk_file_chooser_button_set_active(XEN button, XEN is_active)
{
  #define H_gtk_file_chooser_button_set_active "void gtk_file_chooser_button_set_active(GtkFileChooserButton* button, \
gboolean is_active)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooserButton__P(button), button, 1, "gtk_file_chooser_button_set_active", "GtkFileChooserButton*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(is_active), is_active, 2, "gtk_file_chooser_button_set_active", "gboolean");
  gtk_file_chooser_button_set_active(XEN_TO_C_GtkFileChooserButton_(button), XEN_TO_C_gboolean(is_active));
  return(XEN_FALSE);
}
static XEN gxg_gdk_drag_drop_succeeded(XEN context)
{
  #define H_gdk_drag_drop_succeeded "gboolean gdk_drag_drop_succeeded(GdkDragContext* context)"
  XEN_ASSERT_TYPE(XEN_GdkDragContext__P(context), context, 1, "gdk_drag_drop_succeeded", "GdkDragContext*");
  return(C_TO_XEN_gboolean(gdk_drag_drop_succeeded(XEN_TO_C_GdkDragContext_(context))));
}
static XEN gxg_gdk_rgb_colormap_ditherable(XEN cmap)
{
  #define H_gdk_rgb_colormap_ditherable "gboolean gdk_rgb_colormap_ditherable(GdkColormap* cmap)"
  XEN_ASSERT_TYPE(XEN_GdkColormap__P(cmap), cmap, 1, "gdk_rgb_colormap_ditherable", "GdkColormap*");
  return(C_TO_XEN_gboolean(gdk_rgb_colormap_ditherable(XEN_TO_C_GdkColormap_(cmap))));
}
static XEN gxg_gtk_action_set_sensitive(XEN action, XEN sensitive)
{
  #define H_gtk_action_set_sensitive "void gtk_action_set_sensitive(GtkAction* action, gboolean sensitive)"
  XEN_ASSERT_TYPE(XEN_GtkAction__P(action), action, 1, "gtk_action_set_sensitive", "GtkAction*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(sensitive), sensitive, 2, "gtk_action_set_sensitive", "gboolean");
  gtk_action_set_sensitive(XEN_TO_C_GtkAction_(action), XEN_TO_C_gboolean(sensitive));
  return(XEN_FALSE);
}
static XEN gxg_gtk_action_set_visible(XEN action, XEN visible)
{
  #define H_gtk_action_set_visible "void gtk_action_set_visible(GtkAction* action, gboolean visible)"
  XEN_ASSERT_TYPE(XEN_GtkAction__P(action), action, 1, "gtk_action_set_visible", "GtkAction*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(visible), visible, 2, "gtk_action_set_visible", "gboolean");
  gtk_action_set_visible(XEN_TO_C_GtkAction_(action), XEN_TO_C_gboolean(visible));
  return(XEN_FALSE);
}
static XEN gxg_gtk_combo_box_get_focus_on_click(XEN combo)
{
  #define H_gtk_combo_box_get_focus_on_click "gboolean gtk_combo_box_get_focus_on_click(GtkComboBox* combo)"
  XEN_ASSERT_TYPE(XEN_GtkComboBox__P(combo), combo, 1, "gtk_combo_box_get_focus_on_click", "GtkComboBox*");
  return(C_TO_XEN_gboolean(gtk_combo_box_get_focus_on_click(XEN_TO_C_GtkComboBox_(combo))));
}
static XEN gxg_gtk_combo_box_set_focus_on_click(XEN combo, XEN focus_on_click)
{
  #define H_gtk_combo_box_set_focus_on_click "void gtk_combo_box_set_focus_on_click(GtkComboBox* combo, \
gboolean focus_on_click)"
  XEN_ASSERT_TYPE(XEN_GtkComboBox__P(combo), combo, 1, "gtk_combo_box_set_focus_on_click", "GtkComboBox*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(focus_on_click), focus_on_click, 2, "gtk_combo_box_set_focus_on_click", "gboolean");
  gtk_combo_box_set_focus_on_click(XEN_TO_C_GtkComboBox_(combo), XEN_TO_C_gboolean(focus_on_click));
  return(XEN_FALSE);
}
static XEN gxg_gtk_entry_layout_index_to_text_index(XEN entry, XEN layout_index)
{
  #define H_gtk_entry_layout_index_to_text_index "gint gtk_entry_layout_index_to_text_index(GtkEntry* entry, \
gint layout_index)"
  XEN_ASSERT_TYPE(XEN_GtkEntry__P(entry), entry, 1, "gtk_entry_layout_index_to_text_index", "GtkEntry*");
  XEN_ASSERT_TYPE(XEN_gint_P(layout_index), layout_index, 2, "gtk_entry_layout_index_to_text_index", "gint");
  return(C_TO_XEN_gint(gtk_entry_layout_index_to_text_index(XEN_TO_C_GtkEntry_(entry), XEN_TO_C_gint(layout_index))));
}
static XEN gxg_gtk_entry_text_index_to_layout_index(XEN entry, XEN text_index)
{
  #define H_gtk_entry_text_index_to_layout_index "gint gtk_entry_text_index_to_layout_index(GtkEntry* entry, \
gint text_index)"
  XEN_ASSERT_TYPE(XEN_GtkEntry__P(entry), entry, 1, "gtk_entry_text_index_to_layout_index", "GtkEntry*");
  XEN_ASSERT_TYPE(XEN_gint_P(text_index), text_index, 2, "gtk_entry_text_index_to_layout_index", "gint");
  return(C_TO_XEN_gint(gtk_entry_text_index_to_layout_index(XEN_TO_C_GtkEntry_(entry), XEN_TO_C_gint(text_index))));
}
static XEN gxg_gtk_file_chooser_set_show_hidden(XEN chooser, XEN show_hidden)
{
  #define H_gtk_file_chooser_set_show_hidden "void gtk_file_chooser_set_show_hidden(GtkFileChooser* chooser, \
gboolean show_hidden)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_set_show_hidden", "GtkFileChooser*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(show_hidden), show_hidden, 2, "gtk_file_chooser_set_show_hidden", "gboolean");
  gtk_file_chooser_set_show_hidden(XEN_TO_C_GtkFileChooser_(chooser), XEN_TO_C_gboolean(show_hidden));
  return(XEN_FALSE);
}
static XEN gxg_gtk_file_chooser_get_show_hidden(XEN chooser)
{
  #define H_gtk_file_chooser_get_show_hidden "gboolean gtk_file_chooser_get_show_hidden(GtkFileChooser* chooser)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooser__P(chooser), chooser, 1, "gtk_file_chooser_get_show_hidden", "GtkFileChooser*");
  return(C_TO_XEN_gboolean(gtk_file_chooser_get_show_hidden(XEN_TO_C_GtkFileChooser_(chooser))));
}
static XEN gxg_gtk_tree_view_set_hover_expand(XEN tree_view, XEN expand)
{
  #define H_gtk_tree_view_set_hover_expand "void gtk_tree_view_set_hover_expand(GtkTreeView* tree_view, \
gboolean expand)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_set_hover_expand", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(expand), expand, 2, "gtk_tree_view_set_hover_expand", "gboolean");
  gtk_tree_view_set_hover_expand(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_gboolean(expand));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_get_hover_expand(XEN tree_view)
{
  #define H_gtk_tree_view_get_hover_expand "gboolean gtk_tree_view_get_hover_expand(GtkTreeView* tree_view)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_get_hover_expand", "GtkTreeView*");
  return(C_TO_XEN_gboolean(gtk_tree_view_get_hover_expand(XEN_TO_C_GtkTreeView_(tree_view))));
}
#endif

#if HAVE_GTK_MENU_TOOL_BUTTON_NEW
static XEN gxg_gtk_tool_item_rebuild_menu(XEN tool_item)
{
  #define H_gtk_tool_item_rebuild_menu "void gtk_tool_item_rebuild_menu(GtkToolItem* tool_item)"
  XEN_ASSERT_TYPE(XEN_GtkToolItem__P(tool_item), tool_item, 1, "gtk_tool_item_rebuild_menu", "GtkToolItem*");
  gtk_tool_item_rebuild_menu(XEN_TO_C_GtkToolItem_(tool_item));
  return(XEN_FALSE);
}
static XEN gxg_gtk_menu_tool_button_get_type(void)
{
  #define H_gtk_menu_tool_button_get_type "GType gtk_menu_tool_button_get_type( void)"
  return(C_TO_XEN_GType(gtk_menu_tool_button_get_type()));
}
static XEN gxg_gtk_menu_tool_button_new(XEN icon_widget, XEN label)
{
  #define H_gtk_menu_tool_button_new "GtkToolItem* gtk_menu_tool_button_new(GtkWidget* icon_widget, gchar* label)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(icon_widget), icon_widget, 1, "gtk_menu_tool_button_new", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 2, "gtk_menu_tool_button_new", "gchar*");
  return(C_TO_XEN_GtkToolItem_(gtk_menu_tool_button_new(XEN_TO_C_GtkWidget_(icon_widget), XEN_TO_C_gchar_(label))));
}
static XEN gxg_gtk_menu_tool_button_new_from_stock(XEN stock_id)
{
  #define H_gtk_menu_tool_button_new_from_stock "GtkToolItem* gtk_menu_tool_button_new_from_stock(gchar* stock_id)"
  XEN_ASSERT_TYPE(XEN_gchar__P(stock_id), stock_id, 1, "gtk_menu_tool_button_new_from_stock", "gchar*");
  return(C_TO_XEN_GtkToolItem_(gtk_menu_tool_button_new_from_stock(XEN_TO_C_gchar_(stock_id))));
}
static XEN gxg_gtk_menu_tool_button_set_menu(XEN button, XEN menu)
{
  #define H_gtk_menu_tool_button_set_menu "void gtk_menu_tool_button_set_menu(GtkMenuToolButton* button, \
GtkWidget* menu)"
  XEN_ASSERT_TYPE(XEN_GtkMenuToolButton__P(button), button, 1, "gtk_menu_tool_button_set_menu", "GtkMenuToolButton*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(menu), menu, 2, "gtk_menu_tool_button_set_menu", "GtkWidget*");
  gtk_menu_tool_button_set_menu(XEN_TO_C_GtkMenuToolButton_(button), XEN_TO_C_GtkWidget_(menu));
  return(XEN_FALSE);
}
static XEN gxg_gtk_menu_tool_button_get_menu(XEN button)
{
  #define H_gtk_menu_tool_button_get_menu "GtkWidget* gtk_menu_tool_button_get_menu(GtkMenuToolButton* button)"
  XEN_ASSERT_TYPE(XEN_GtkMenuToolButton__P(button), button, 1, "gtk_menu_tool_button_get_menu", "GtkMenuToolButton*");
  return(C_TO_XEN_GtkWidget_(gtk_menu_tool_button_get_menu(XEN_TO_C_GtkMenuToolButton_(button))));
}
static XEN gxg_gtk_menu_tool_button_set_arrow_tooltip(XEN button, XEN tooltips, XEN tip_text, XEN tip_private)
{
  #define H_gtk_menu_tool_button_set_arrow_tooltip "void gtk_menu_tool_button_set_arrow_tooltip(GtkMenuToolButton* button, \
GtkTooltips* tooltips, gchar* tip_text, gchar* tip_private)"
  XEN_ASSERT_TYPE(XEN_GtkMenuToolButton__P(button), button, 1, "gtk_menu_tool_button_set_arrow_tooltip", "GtkMenuToolButton*");
  XEN_ASSERT_TYPE(XEN_GtkTooltips__P(tooltips), tooltips, 2, "gtk_menu_tool_button_set_arrow_tooltip", "GtkTooltips*");
  XEN_ASSERT_TYPE(XEN_gchar__P(tip_text), tip_text, 3, "gtk_menu_tool_button_set_arrow_tooltip", "gchar*");
  XEN_ASSERT_TYPE(XEN_gchar__P(tip_private), tip_private, 4, "gtk_menu_tool_button_set_arrow_tooltip", "gchar*");
  gtk_menu_tool_button_set_arrow_tooltip(XEN_TO_C_GtkMenuToolButton_(button), XEN_TO_C_GtkTooltips_(tooltips), XEN_TO_C_gchar_(tip_text), 
                                         XEN_TO_C_gchar_(tip_private));
  return(XEN_FALSE);
}
static XEN gxg_gdk_display_supports_clipboard_persistence(XEN display)
{
  #define H_gdk_display_supports_clipboard_persistence "gboolean gdk_display_supports_clipboard_persistence(GdkDisplay* display)"
  XEN_ASSERT_TYPE(XEN_GdkDisplay__P(display), display, 1, "gdk_display_supports_clipboard_persistence", "GdkDisplay*");
  return(C_TO_XEN_gboolean(gdk_display_supports_clipboard_persistence(XEN_TO_C_GdkDisplay_(display))));
}
static XEN gxg_gtk_about_dialog_get_logo_icon_name(XEN about)
{
  #define H_gtk_about_dialog_get_logo_icon_name "gchar* gtk_about_dialog_get_logo_icon_name(GtkAboutDialog* about)"
  XEN_ASSERT_TYPE(XEN_GtkAboutDialog__P(about), about, 1, "gtk_about_dialog_get_logo_icon_name", "GtkAboutDialog*");
  return(C_TO_XEN_gchar_(gtk_about_dialog_get_logo_icon_name(XEN_TO_C_GtkAboutDialog_(about))));
}
static XEN gxg_gtk_about_dialog_set_logo_icon_name(XEN about, XEN icon_name)
{
  #define H_gtk_about_dialog_set_logo_icon_name "void gtk_about_dialog_set_logo_icon_name(GtkAboutDialog* about, \
gchar* icon_name)"
  XEN_ASSERT_TYPE(XEN_GtkAboutDialog__P(about), about, 1, "gtk_about_dialog_set_logo_icon_name", "GtkAboutDialog*");
  XEN_ASSERT_TYPE(XEN_gchar__P(icon_name), icon_name, 2, "gtk_about_dialog_set_logo_icon_name", "gchar*");
  gtk_about_dialog_set_logo_icon_name(XEN_TO_C_GtkAboutDialog_(about), XEN_TO_C_gchar_(icon_name));
  return(XEN_FALSE);
}
static XEN gxg_gtk_accelerator_get_label(XEN accelerator_key, XEN accelerator_mods)
{
  #define H_gtk_accelerator_get_label "gchar* gtk_accelerator_get_label(guint accelerator_key, GdkModifierType accelerator_mods)"
  XEN_ASSERT_TYPE(XEN_guint_P(accelerator_key), accelerator_key, 1, "gtk_accelerator_get_label", "guint");
  XEN_ASSERT_TYPE(XEN_GdkModifierType_P(accelerator_mods), accelerator_mods, 2, "gtk_accelerator_get_label", "GdkModifierType");
  return(C_TO_XEN_gchar_(gtk_accelerator_get_label(XEN_TO_C_guint(accelerator_key), XEN_TO_C_GdkModifierType(accelerator_mods))));
}
static XEN gxg_gtk_clipboard_wait_is_target_available(XEN clipboard, XEN target)
{
  #define H_gtk_clipboard_wait_is_target_available "gboolean gtk_clipboard_wait_is_target_available(GtkClipboard* clipboard, \
GdkAtom target)"
  XEN_ASSERT_TYPE(XEN_GtkClipboard__P(clipboard), clipboard, 1, "gtk_clipboard_wait_is_target_available", "GtkClipboard*");
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(target), target, 2, "gtk_clipboard_wait_is_target_available", "GdkAtom");
  return(C_TO_XEN_gboolean(gtk_clipboard_wait_is_target_available(XEN_TO_C_GtkClipboard_(clipboard), XEN_TO_C_GdkAtom(target))));
}
static XEN gxg_gtk_clipboard_set_can_store(XEN clipboard, XEN targets, XEN n_targets)
{
  #define H_gtk_clipboard_set_can_store "void gtk_clipboard_set_can_store(GtkClipboard* clipboard, GtkTargetEntry* targets, \
gint n_targets)"
  XEN_ASSERT_TYPE(XEN_GtkClipboard__P(clipboard), clipboard, 1, "gtk_clipboard_set_can_store", "GtkClipboard*");
  XEN_ASSERT_TYPE(XEN_GtkTargetEntry__P(targets), targets, 2, "gtk_clipboard_set_can_store", "GtkTargetEntry*");
  XEN_ASSERT_TYPE(XEN_gint_P(n_targets), n_targets, 3, "gtk_clipboard_set_can_store", "gint");
  gtk_clipboard_set_can_store(XEN_TO_C_GtkClipboard_(clipboard), XEN_TO_C_GtkTargetEntry_(targets), XEN_TO_C_gint(n_targets));
  return(XEN_FALSE);
}
static XEN gxg_gtk_clipboard_store(XEN clipboard)
{
  #define H_gtk_clipboard_store "void gtk_clipboard_store(GtkClipboard* clipboard)"
  XEN_ASSERT_TYPE(XEN_GtkClipboard__P(clipboard), clipboard, 1, "gtk_clipboard_store", "GtkClipboard*");
  gtk_clipboard_store(XEN_TO_C_GtkClipboard_(clipboard));
  return(XEN_FALSE);
}
static XEN gxg_gtk_alternative_dialog_button_order(XEN screen)
{
  #define H_gtk_alternative_dialog_button_order "gboolean gtk_alternative_dialog_button_order(GdkScreen* screen)"
  XEN_ASSERT_TYPE(XEN_GdkScreen__P(screen), screen, 1, "gtk_alternative_dialog_button_order", "GdkScreen*");
  return(C_TO_XEN_gboolean(gtk_alternative_dialog_button_order(XEN_TO_C_GdkScreen_(screen))));
}
static XEN gxg_gtk_drag_dest_add_image_targets(XEN widget)
{
  #define H_gtk_drag_dest_add_image_targets "void gtk_drag_dest_add_image_targets(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_drag_dest_add_image_targets", "GtkWidget*");
  gtk_drag_dest_add_image_targets(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_drag_dest_add_uri_targets(XEN widget)
{
  #define H_gtk_drag_dest_add_uri_targets "void gtk_drag_dest_add_uri_targets(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_drag_dest_add_uri_targets", "GtkWidget*");
  gtk_drag_dest_add_uri_targets(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_drag_source_add_image_targets(XEN widget)
{
  #define H_gtk_drag_source_add_image_targets "void gtk_drag_source_add_image_targets(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_drag_source_add_image_targets", "GtkWidget*");
  gtk_drag_source_add_image_targets(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_drag_source_add_uri_targets(XEN widget)
{
  #define H_gtk_drag_source_add_uri_targets "void gtk_drag_source_add_uri_targets(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_drag_source_add_uri_targets", "GtkWidget*");
  gtk_drag_source_add_uri_targets(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_file_chooser_button_get_width_chars(XEN button)
{
  #define H_gtk_file_chooser_button_get_width_chars "gint gtk_file_chooser_button_get_width_chars(GtkFileChooserButton* button)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooserButton__P(button), button, 1, "gtk_file_chooser_button_get_width_chars", "GtkFileChooserButton*");
  return(C_TO_XEN_gint(gtk_file_chooser_button_get_width_chars(XEN_TO_C_GtkFileChooserButton_(button))));
}
static XEN gxg_gtk_file_chooser_button_set_width_chars(XEN button, XEN n_chars)
{
  #define H_gtk_file_chooser_button_set_width_chars "void gtk_file_chooser_button_set_width_chars(GtkFileChooserButton* button, \
gint n_chars)"
  XEN_ASSERT_TYPE(XEN_GtkFileChooserButton__P(button), button, 1, "gtk_file_chooser_button_set_width_chars", "GtkFileChooserButton*");
  XEN_ASSERT_TYPE(XEN_gint_P(n_chars), n_chars, 2, "gtk_file_chooser_button_set_width_chars", "gint");
  gtk_file_chooser_button_set_width_chars(XEN_TO_C_GtkFileChooserButton_(button), XEN_TO_C_gint(n_chars));
  return(XEN_FALSE);
}
static XEN gxg_gtk_image_new_from_icon_name(XEN icon_name, XEN size)
{
  #define H_gtk_image_new_from_icon_name "GtkWidget* gtk_image_new_from_icon_name(gchar* icon_name, GtkIconSize size)"
  XEN_ASSERT_TYPE(XEN_gchar__P(icon_name), icon_name, 1, "gtk_image_new_from_icon_name", "gchar*");
  XEN_ASSERT_TYPE(XEN_GtkIconSize_P(size), size, 2, "gtk_image_new_from_icon_name", "GtkIconSize");
  return(C_TO_XEN_GtkWidget_(gtk_image_new_from_icon_name(XEN_TO_C_gchar_(icon_name), XEN_TO_C_GtkIconSize(size))));
}
static XEN gxg_gtk_image_set_from_icon_name(XEN image, XEN icon_name, XEN size)
{
  #define H_gtk_image_set_from_icon_name "void gtk_image_set_from_icon_name(GtkImage* image, gchar* icon_name, \
GtkIconSize size)"
  XEN_ASSERT_TYPE(XEN_GtkImage__P(image), image, 1, "gtk_image_set_from_icon_name", "GtkImage*");
  XEN_ASSERT_TYPE(XEN_gchar__P(icon_name), icon_name, 2, "gtk_image_set_from_icon_name", "gchar*");
  XEN_ASSERT_TYPE(XEN_GtkIconSize_P(size), size, 3, "gtk_image_set_from_icon_name", "GtkIconSize");
  gtk_image_set_from_icon_name(XEN_TO_C_GtkImage_(image), XEN_TO_C_gchar_(icon_name), XEN_TO_C_GtkIconSize(size));
  return(XEN_FALSE);
}
static XEN gxg_gtk_image_set_pixel_size(XEN image, XEN pixel_size)
{
  #define H_gtk_image_set_pixel_size "void gtk_image_set_pixel_size(GtkImage* image, gint pixel_size)"
  XEN_ASSERT_TYPE(XEN_GtkImage__P(image), image, 1, "gtk_image_set_pixel_size", "GtkImage*");
  XEN_ASSERT_TYPE(XEN_gint_P(pixel_size), pixel_size, 2, "gtk_image_set_pixel_size", "gint");
  gtk_image_set_pixel_size(XEN_TO_C_GtkImage_(image), XEN_TO_C_gint(pixel_size));
  return(XEN_FALSE);
}
static XEN gxg_gtk_image_get_pixel_size(XEN image)
{
  #define H_gtk_image_get_pixel_size "gint gtk_image_get_pixel_size(GtkImage* image)"
  XEN_ASSERT_TYPE(XEN_GtkImage__P(image), image, 1, "gtk_image_get_pixel_size", "GtkImage*");
  return(C_TO_XEN_gint(gtk_image_get_pixel_size(XEN_TO_C_GtkImage_(image))));
}
static XEN gxg_gtk_label_set_width_chars(XEN label, XEN n_chars)
{
  #define H_gtk_label_set_width_chars "void gtk_label_set_width_chars(GtkLabel* label, gint n_chars)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_set_width_chars", "GtkLabel*");
  XEN_ASSERT_TYPE(XEN_gint_P(n_chars), n_chars, 2, "gtk_label_set_width_chars", "gint");
  gtk_label_set_width_chars(XEN_TO_C_GtkLabel_(label), XEN_TO_C_gint(n_chars));
  return(XEN_FALSE);
}
static XEN gxg_gtk_label_get_width_chars(XEN label)
{
  #define H_gtk_label_get_width_chars "gint gtk_label_get_width_chars(GtkLabel* label)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_get_width_chars", "GtkLabel*");
  return(C_TO_XEN_gint(gtk_label_get_width_chars(XEN_TO_C_GtkLabel_(label))));
}
static XEN gxg_gtk_target_list_add_text_targets(XEN list, XEN info)
{
  #define H_gtk_target_list_add_text_targets "void gtk_target_list_add_text_targets(GtkTargetList* list, \
guint info)"
  XEN_ASSERT_TYPE(XEN_GtkTargetList__P(list), list, 1, "gtk_target_list_add_text_targets", "GtkTargetList*");
  XEN_ASSERT_TYPE(XEN_guint_P(info), info, 2, "gtk_target_list_add_text_targets", "guint");
  gtk_target_list_add_text_targets(XEN_TO_C_GtkTargetList_(list), XEN_TO_C_guint(info));
  return(XEN_FALSE);
}
static XEN gxg_gtk_target_list_add_image_targets(XEN list, XEN info, XEN writable)
{
  #define H_gtk_target_list_add_image_targets "void gtk_target_list_add_image_targets(GtkTargetList* list, \
guint info, gboolean writable)"
  XEN_ASSERT_TYPE(XEN_GtkTargetList__P(list), list, 1, "gtk_target_list_add_image_targets", "GtkTargetList*");
  XEN_ASSERT_TYPE(XEN_guint_P(info), info, 2, "gtk_target_list_add_image_targets", "guint");
  XEN_ASSERT_TYPE(XEN_gboolean_P(writable), writable, 3, "gtk_target_list_add_image_targets", "gboolean");
  gtk_target_list_add_image_targets(XEN_TO_C_GtkTargetList_(list), XEN_TO_C_guint(info), XEN_TO_C_gboolean(writable));
  return(XEN_FALSE);
}
static XEN gxg_gtk_target_list_add_uri_targets(XEN list, XEN info)
{
  #define H_gtk_target_list_add_uri_targets "void gtk_target_list_add_uri_targets(GtkTargetList* list, \
guint info)"
  XEN_ASSERT_TYPE(XEN_GtkTargetList__P(list), list, 1, "gtk_target_list_add_uri_targets", "GtkTargetList*");
  XEN_ASSERT_TYPE(XEN_guint_P(info), info, 2, "gtk_target_list_add_uri_targets", "guint");
  gtk_target_list_add_uri_targets(XEN_TO_C_GtkTargetList_(list), XEN_TO_C_guint(info));
  return(XEN_FALSE);
}
static XEN gxg_gtk_selection_data_set_pixbuf(XEN selection_data, XEN pixbuf)
{
  #define H_gtk_selection_data_set_pixbuf "gboolean gtk_selection_data_set_pixbuf(GtkSelectionData* selection_data, \
GdkPixbuf* pixbuf)"
  XEN_ASSERT_TYPE(XEN_GtkSelectionData__P(selection_data), selection_data, 1, "gtk_selection_data_set_pixbuf", "GtkSelectionData*");
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(pixbuf), pixbuf, 2, "gtk_selection_data_set_pixbuf", "GdkPixbuf*");
  return(C_TO_XEN_gboolean(gtk_selection_data_set_pixbuf(XEN_TO_C_GtkSelectionData_(selection_data), XEN_TO_C_GdkPixbuf_(pixbuf))));
}
static XEN gxg_gtk_selection_data_get_pixbuf(XEN selection_data)
{
  #define H_gtk_selection_data_get_pixbuf "GdkPixbuf* gtk_selection_data_get_pixbuf(GtkSelectionData* selection_data)"
  XEN_ASSERT_TYPE(XEN_GtkSelectionData__P(selection_data), selection_data, 1, "gtk_selection_data_get_pixbuf", "GtkSelectionData*");
  return(C_TO_XEN_GdkPixbuf_(gtk_selection_data_get_pixbuf(XEN_TO_C_GtkSelectionData_(selection_data))));
}
static XEN gxg_gtk_selection_data_set_uris(XEN selection_data, XEN uris)
{
  #define H_gtk_selection_data_set_uris "gboolean gtk_selection_data_set_uris(GtkSelectionData* selection_data, \
gchar** uris)"
  XEN_ASSERT_TYPE(XEN_GtkSelectionData__P(selection_data), selection_data, 1, "gtk_selection_data_set_uris", "GtkSelectionData*");
  XEN_ASSERT_TYPE(XEN_gchar___P(uris), uris, 2, "gtk_selection_data_set_uris", "gchar**");
  return(C_TO_XEN_gboolean(gtk_selection_data_set_uris(XEN_TO_C_GtkSelectionData_(selection_data), XEN_TO_C_gchar__(uris))));
}
static XEN gxg_gtk_selection_data_get_uris(XEN selection_data)
{
  #define H_gtk_selection_data_get_uris "gchar** gtk_selection_data_get_uris(GtkSelectionData* selection_data)"
  XEN_ASSERT_TYPE(XEN_GtkSelectionData__P(selection_data), selection_data, 1, "gtk_selection_data_get_uris", "GtkSelectionData*");
  return(C_TO_XEN_gchar__(gtk_selection_data_get_uris(XEN_TO_C_GtkSelectionData_(selection_data))));
}
static XEN gxg_gtk_text_buffer_backspace(XEN buffer, XEN iter, XEN interactive, XEN default_editable)
{
  #define H_gtk_text_buffer_backspace "gboolean gtk_text_buffer_backspace(GtkTextBuffer* buffer, GtkTextIter* iter, \
gboolean interactive, gboolean default_editable)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_backspace", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 2, "gtk_text_buffer_backspace", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(interactive), interactive, 3, "gtk_text_buffer_backspace", "gboolean");
  XEN_ASSERT_TYPE(XEN_gboolean_P(default_editable), default_editable, 4, "gtk_text_buffer_backspace", "gboolean");
  return(C_TO_XEN_gboolean(gtk_text_buffer_backspace(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gboolean(interactive), 
                                                     XEN_TO_C_gboolean(default_editable))));
}
#endif

#if HAVE_GTK_LABEL_GET_SINGLE_LINE_MODE
static XEN gxg_gtk_clipboard_set_image(XEN clipboard, XEN pixbuf)
{
  #define H_gtk_clipboard_set_image "void gtk_clipboard_set_image(GtkClipboard* clipboard, GdkPixbuf* pixbuf)"
  XEN_ASSERT_TYPE(XEN_GtkClipboard__P(clipboard), clipboard, 1, "gtk_clipboard_set_image", "GtkClipboard*");
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(pixbuf), pixbuf, 2, "gtk_clipboard_set_image", "GdkPixbuf*");
  gtk_clipboard_set_image(XEN_TO_C_GtkClipboard_(clipboard), XEN_TO_C_GdkPixbuf_(pixbuf));
  return(XEN_FALSE);
}
static XEN gxg_gtk_clipboard_request_image(XEN clipboard, XEN func, XEN func_data)
{
  #define H_gtk_clipboard_request_image "void gtk_clipboard_request_image(GtkClipboard* clipboard, GtkClipboardImageReceivedFunc func, \
lambda_data func_data)"
  XEN_ASSERT_TYPE(XEN_GtkClipboard__P(clipboard), clipboard, 1, "gtk_clipboard_request_image", "GtkClipboard*");
  XEN_ASSERT_TYPE(XEN_GtkClipboardImageReceivedFunc_P(func), func, 2, "gtk_clipboard_request_image", "GtkClipboardImageReceivedFunc");
  if (XEN_NOT_BOUND_P(func_data)) func_data = XEN_FALSE; 
  else XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 3, "gtk_clipboard_request_image", "lambda_data");
  {
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    xm_protect(gxg_ptr);
    gtk_clipboard_request_image(XEN_TO_C_GtkClipboard_(clipboard), XEN_TO_C_GtkClipboardImageReceivedFunc(func), XEN_TO_C_lambda_data(func_data));
    return(XEN_FALSE);
   }
}
static XEN gxg_gtk_clipboard_wait_for_image(XEN clipboard)
{
  #define H_gtk_clipboard_wait_for_image "GdkPixbuf* gtk_clipboard_wait_for_image(GtkClipboard* clipboard)"
  XEN_ASSERT_TYPE(XEN_GtkClipboard__P(clipboard), clipboard, 1, "gtk_clipboard_wait_for_image", "GtkClipboard*");
  return(C_TO_XEN_GdkPixbuf_(gtk_clipboard_wait_for_image(XEN_TO_C_GtkClipboard_(clipboard))));
}
static XEN gxg_gtk_clipboard_wait_is_image_available(XEN clipboard)
{
  #define H_gtk_clipboard_wait_is_image_available "gboolean gtk_clipboard_wait_is_image_available(GtkClipboard* clipboard)"
  XEN_ASSERT_TYPE(XEN_GtkClipboard__P(clipboard), clipboard, 1, "gtk_clipboard_wait_is_image_available", "GtkClipboard*");
  return(C_TO_XEN_gboolean(gtk_clipboard_wait_is_image_available(XEN_TO_C_GtkClipboard_(clipboard))));
}
static XEN gxg_gtk_file_filter_add_pixbuf_formats(XEN filter)
{
  #define H_gtk_file_filter_add_pixbuf_formats "void gtk_file_filter_add_pixbuf_formats(GtkFileFilter* filter)"
  XEN_ASSERT_TYPE(XEN_GtkFileFilter__P(filter), filter, 1, "gtk_file_filter_add_pixbuf_formats", "GtkFileFilter*");
  gtk_file_filter_add_pixbuf_formats(XEN_TO_C_GtkFileFilter_(filter));
  return(XEN_FALSE);
}
static XEN gxg_gtk_label_set_single_line_mode(XEN label, XEN single_line_mode)
{
  #define H_gtk_label_set_single_line_mode "void gtk_label_set_single_line_mode(GtkLabel* label, gboolean single_line_mode)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_set_single_line_mode", "GtkLabel*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(single_line_mode), single_line_mode, 2, "gtk_label_set_single_line_mode", "gboolean");
  gtk_label_set_single_line_mode(XEN_TO_C_GtkLabel_(label), XEN_TO_C_gboolean(single_line_mode));
  return(XEN_FALSE);
}
static XEN gxg_gtk_label_get_single_line_mode(XEN label)
{
  #define H_gtk_label_get_single_line_mode "gboolean gtk_label_get_single_line_mode(GtkLabel* label)"
  XEN_ASSERT_TYPE(XEN_GtkLabel__P(label), label, 1, "gtk_label_get_single_line_mode", "GtkLabel*");
  return(C_TO_XEN_gboolean(gtk_label_get_single_line_mode(XEN_TO_C_GtkLabel_(label))));
}
static XEN gxg_gtk_progress_bar_set_ellipsize(XEN pbar, XEN mode)
{
  #define H_gtk_progress_bar_set_ellipsize "void gtk_progress_bar_set_ellipsize(GtkProgressBar* pbar, \
PangoEllipsizeMode mode)"
  XEN_ASSERT_TYPE(XEN_GtkProgressBar__P(pbar), pbar, 1, "gtk_progress_bar_set_ellipsize", "GtkProgressBar*");
  XEN_ASSERT_TYPE(XEN_PangoEllipsizeMode_P(mode), mode, 2, "gtk_progress_bar_set_ellipsize", "PangoEllipsizeMode");
  gtk_progress_bar_set_ellipsize(XEN_TO_C_GtkProgressBar_(pbar), XEN_TO_C_PangoEllipsizeMode(mode));
  return(XEN_FALSE);
}
static XEN gxg_gtk_progress_bar_get_ellipsize(XEN pbar)
{
  #define H_gtk_progress_bar_get_ellipsize "PangoEllipsizeMode gtk_progress_bar_get_ellipsize(GtkProgressBar* pbar)"
  XEN_ASSERT_TYPE(XEN_GtkProgressBar__P(pbar), pbar, 1, "gtk_progress_bar_get_ellipsize", "GtkProgressBar*");
  return(C_TO_XEN_PangoEllipsizeMode(gtk_progress_bar_get_ellipsize(XEN_TO_C_GtkProgressBar_(pbar))));
}
static XEN gxg_gtk_selection_data_targets_include_image(XEN selection_data, XEN writable)
{
  #define H_gtk_selection_data_targets_include_image "gboolean gtk_selection_data_targets_include_image(GtkSelectionData* selection_data, \
gboolean writable)"
  XEN_ASSERT_TYPE(XEN_GtkSelectionData__P(selection_data), selection_data, 1, "gtk_selection_data_targets_include_image", "GtkSelectionData*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(writable), writable, 2, "gtk_selection_data_targets_include_image", "gboolean");
  return(C_TO_XEN_gboolean(gtk_selection_data_targets_include_image(XEN_TO_C_GtkSelectionData_(selection_data), XEN_TO_C_gboolean(writable))));
}
#endif

static XEN gxg_GDK_COLORMAP(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkColormap_"), XEN_CADR(obj)));}
static XEN gxg_GDK_DRAG_CONTEXT(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkDragContext_"), XEN_CADR(obj)));}
static XEN gxg_GDK_DRAWABLE(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkDrawable_"), XEN_CADR(obj)));}
static XEN gxg_GDK_GC(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkGC_"), XEN_CADR(obj)));}
static XEN gxg_GDK_IMAGE(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkImage_"), XEN_CADR(obj)));}
static XEN gxg_GDK_DEVICE(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkDevice_"), XEN_CADR(obj)));}
static XEN gxg_GDK_KEYMAP(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkKeymap_"), XEN_CADR(obj)));}
static XEN gxg_GDK_PIXMAP(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkPixmap_"), XEN_CADR(obj)));}
static XEN gxg_GDK_VISUAL(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkVisual_"), XEN_CADR(obj)));}
static XEN gxg_GDK_WINDOW(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkWindow_"), XEN_CADR(obj)));}
static XEN gxg_GDK_PIXBUF(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkPixbuf_"), XEN_CADR(obj)));}
static XEN gxg_GDK_PIXBUF_ANIMATION(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkPixbufAnimation_"), XEN_CADR(obj)));}
static XEN gxg_GDK_PIXBUF_ANIMATION_ITER(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkPixbufAnimationIter_"), XEN_CADR(obj)));}
static XEN gxg_GDK_PIXBUF_LOADER(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkPixbufLoader_"), XEN_CADR(obj)));}
static XEN gxg_GTK_VBOX(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkVBox_"), XEN_CADR(obj)));}
static XEN gxg_GTK_ACCEL_GROUP(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkAccelGroup_"), XEN_CADR(obj)));}
static XEN gxg_GTK_ACCEL_LABEL(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkAccelLabel_"), XEN_CADR(obj)));}
static XEN gxg_GTK_ACCESSIBLE(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkAccessible_"), XEN_CADR(obj)));}
static XEN gxg_GTK_ADJUSTMENT(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkAdjustment_"), XEN_CADR(obj)));}
static XEN gxg_GTK_ALIGNMENT(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkAlignment_"), XEN_CADR(obj)));}
static XEN gxg_GTK_ARROW(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkArrow_"), XEN_CADR(obj)));}
static XEN gxg_GTK_ASPECT_FRAME(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkAspectFrame_"), XEN_CADR(obj)));}
static XEN gxg_GTK_BUTTON_BOX(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkButtonBox_"), XEN_CADR(obj)));}
static XEN gxg_GTK_BIN(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkBin_"), XEN_CADR(obj)));}
static XEN gxg_GTK_BOX(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkBox_"), XEN_CADR(obj)));}
static XEN gxg_GTK_BUTTON(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkButton_"), XEN_CADR(obj)));}
static XEN gxg_GTK_CALENDAR(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkCalendar_"), XEN_CADR(obj)));}
static XEN gxg_GTK_CELL_EDITABLE(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkCellEditable_"), XEN_CADR(obj)));}
static XEN gxg_GTK_CELL_RENDERER(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkCellRenderer_"), XEN_CADR(obj)));}
static XEN gxg_GTK_CELL_RENDERER_PIXBUF(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkCellRendererPixbuf_"), XEN_CADR(obj)));}
static XEN gxg_GTK_CELL_RENDERER_TEXT(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkCellRendererText_"), XEN_CADR(obj)));}
static XEN gxg_GTK_CELL_RENDERER_TOGGLE(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkCellRendererToggle_"), XEN_CADR(obj)));}
static XEN gxg_GTK_CHECK_BUTTON(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkCheckButton_"), XEN_CADR(obj)));}
static XEN gxg_GTK_CHECK_MENU_ITEM(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkCheckMenuItem_"), XEN_CADR(obj)));}
static XEN gxg_GTK_COLOR_SELECTION_DIALOG(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkColorSelectionDialog_"), XEN_CADR(obj)));}
static XEN gxg_GTK_COLOR_SELECTION(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkColorSelection_"), XEN_CADR(obj)));}
static XEN gxg_GTK_CONTAINER(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkContainer_"), XEN_CADR(obj)));}
static XEN gxg_GTK_CURVE(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkCurve_"), XEN_CADR(obj)));}
static XEN gxg_GTK_DIALOG(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkDialog_"), XEN_CADR(obj)));}
static XEN gxg_GTK_DRAWING_AREA(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkDrawingArea_"), XEN_CADR(obj)));}
static XEN gxg_GTK_EDITABLE(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkEditable_"), XEN_CADR(obj)));}
static XEN gxg_GTK_ENTRY(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkEntry_"), XEN_CADR(obj)));}
static XEN gxg_GTK_EVENT_BOX(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkEventBox_"), XEN_CADR(obj)));}
static XEN gxg_GTK_FILE_SELECTION(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkFileSelection_"), XEN_CADR(obj)));}
static XEN gxg_GTK_FIXED(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkFixed_"), XEN_CADR(obj)));}
static XEN gxg_GTK_FONT_SELECTION(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkFontSelection_"), XEN_CADR(obj)));}
static XEN gxg_GTK_FONT_SELECTION_DIALOG(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkFontSelectionDialog_"), XEN_CADR(obj)));}
static XEN gxg_GTK_FRAME(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkFrame_"), XEN_CADR(obj)));}
static XEN gxg_GTK_GAMMA_CURVE(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkGammaCurve_"), XEN_CADR(obj)));}
static XEN gxg_GTK_HANDLE_BOX(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkHandleBox_"), XEN_CADR(obj)));}
static XEN gxg_GTK_HBUTTON_BOX(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkHButtonBox_"), XEN_CADR(obj)));}
static XEN gxg_GTK_HBOX(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkHBox_"), XEN_CADR(obj)));}
static XEN gxg_GTK_HPANED(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkHPaned_"), XEN_CADR(obj)));}
static XEN gxg_GTK_HRULER(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkHRuler_"), XEN_CADR(obj)));}
static XEN gxg_GTK_HSCALE(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkHScale_"), XEN_CADR(obj)));}
static XEN gxg_GTK_HSCROLLBAR(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkHScrollbar_"), XEN_CADR(obj)));}
static XEN gxg_GTK_HSEPARATOR(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkHSeparator_"), XEN_CADR(obj)));}
static XEN gxg_GTK_ICON_FACTORY(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkIconFactory_"), XEN_CADR(obj)));}
static XEN gxg_GTK_IMAGE(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkImage_"), XEN_CADR(obj)));}
static XEN gxg_GTK_IMAGE_MENU_ITEM(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkImageMenuItem_"), XEN_CADR(obj)));}
static XEN gxg_GTK_IM_CONTEXT(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkIMContext_"), XEN_CADR(obj)));}
static XEN gxg_GTK_IM_CONTEXT_SIMPLE(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkIMContextSimple_"), XEN_CADR(obj)));}
static XEN gxg_GTK_IM_MULTICONTEXT(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkIMMulticontext_"), XEN_CADR(obj)));}
static XEN gxg_GTK_INPUT_DIALOG(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkInputDialog_"), XEN_CADR(obj)));}
static XEN gxg_GTK_INVISIBLE(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkInvisible_"), XEN_CADR(obj)));}
static XEN gxg_GTK_ITEM(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkItem_"), XEN_CADR(obj)));}
static XEN gxg_GTK_LABEL(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkLabel_"), XEN_CADR(obj)));}
static XEN gxg_GTK_LAYOUT(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkLayout_"), XEN_CADR(obj)));}
static XEN gxg_GTK_LIST_STORE(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkListStore_"), XEN_CADR(obj)));}
static XEN gxg_GTK_MENU_BAR(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkMenuBar_"), XEN_CADR(obj)));}
static XEN gxg_GTK_MENU(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkMenu_"), XEN_CADR(obj)));}
static XEN gxg_GTK_MENU_ITEM(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkMenuItem_"), XEN_CADR(obj)));}
static XEN gxg_GTK_MENU_SHELL(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkMenuShell_"), XEN_CADR(obj)));}
static XEN gxg_GTK_MESSAGE_DIALOG(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkMessageDialog_"), XEN_CADR(obj)));}
static XEN gxg_GTK_MISC(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkMisc_"), XEN_CADR(obj)));}
static XEN gxg_GTK_NOTEBOOK(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkNotebook_"), XEN_CADR(obj)));}
static XEN gxg_GTK_OBJECT(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkObject_"), XEN_CADR(obj)));}
static XEN gxg_GTK_PANED(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkPaned_"), XEN_CADR(obj)));}
static XEN gxg_GTK_PLUG(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkPlug_"), XEN_CADR(obj)));}
static XEN gxg_GTK_PROGRESS_BAR(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkProgressBar_"), XEN_CADR(obj)));}
static XEN gxg_GTK_RADIO_BUTTON(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkRadioButton_"), XEN_CADR(obj)));}
static XEN gxg_GTK_RADIO_MENU_ITEM(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkRadioMenuItem_"), XEN_CADR(obj)));}
static XEN gxg_GTK_RANGE(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkRange_"), XEN_CADR(obj)));}
static XEN gxg_GTK_RULER(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkRuler_"), XEN_CADR(obj)));}
static XEN gxg_GTK_SCALE(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkScale_"), XEN_CADR(obj)));}
static XEN gxg_GTK_SCROLLBAR(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkScrollbar_"), XEN_CADR(obj)));}
static XEN gxg_GTK_SCROLLED_WINDOW(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkScrolledWindow_"), XEN_CADR(obj)));}
static XEN gxg_GTK_SEPARATOR(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkSeparator_"), XEN_CADR(obj)));}
static XEN gxg_GTK_SEPARATOR_MENU_ITEM(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkSeparatorMenuItem_"), XEN_CADR(obj)));}
static XEN gxg_GTK_SIZE_GROUP(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkSizeGroup_"), XEN_CADR(obj)));}
static XEN gxg_GTK_SOCKET(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkSocket_"), XEN_CADR(obj)));}
static XEN gxg_GTK_SPIN_BUTTON(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkSpinButton_"), XEN_CADR(obj)));}
static XEN gxg_GTK_STATUSBAR(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkStatusbar_"), XEN_CADR(obj)));}
static XEN gxg_GTK_STYLE(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkStyle_"), XEN_CADR(obj)));}
static XEN gxg_GTK_TABLE(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkTable_"), XEN_CADR(obj)));}
static XEN gxg_GTK_TEAROFF_MENU_ITEM(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkTearoffMenuItem_"), XEN_CADR(obj)));}
static XEN gxg_GTK_TEXT_BUFFER(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkTextBuffer_"), XEN_CADR(obj)));}
static XEN gxg_GTK_TEXT_CHILD_ANCHOR(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkTextChildAnchor_"), XEN_CADR(obj)));}
static XEN gxg_GTK_TEXT_MARK(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkTextMark_"), XEN_CADR(obj)));}
static XEN gxg_GTK_TEXT_TAG(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkTextTag_"), XEN_CADR(obj)));}
static XEN gxg_GTK_TEXT_TAG_TABLE(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkTextTagTable_"), XEN_CADR(obj)));}
static XEN gxg_GTK_TEXT_VIEW(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkTextView_"), XEN_CADR(obj)));}
static XEN gxg_GTK_TOGGLE_BUTTON(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkToggleButton_"), XEN_CADR(obj)));}
static XEN gxg_GTK_TOOLBAR(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkToolbar_"), XEN_CADR(obj)));}
static XEN gxg_GTK_TOOLTIPS(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkTooltips_"), XEN_CADR(obj)));}
static XEN gxg_GTK_TREE_DRAG_SOURCE(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkTreeDragSource_"), XEN_CADR(obj)));}
static XEN gxg_GTK_TREE_DRAG_DEST(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkTreeDragDest_"), XEN_CADR(obj)));}
static XEN gxg_GTK_TREE_MODEL(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkTreeModel_"), XEN_CADR(obj)));}
static XEN gxg_GTK_TREE_MODEL_SORT(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkTreeModelSort_"), XEN_CADR(obj)));}
static XEN gxg_GTK_TREE_SELECTION(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkTreeSelection_"), XEN_CADR(obj)));}
static XEN gxg_GTK_TREE_SORTABLE(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkTreeSortable_"), XEN_CADR(obj)));}
static XEN gxg_GTK_TREE_STORE(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkTreeStore_"), XEN_CADR(obj)));}
static XEN gxg_GTK_TREE_VIEW_COLUMN(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkTreeViewColumn_"), XEN_CADR(obj)));}
static XEN gxg_GTK_TREE_VIEW(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkTreeView_"), XEN_CADR(obj)));}
static XEN gxg_GTK_VBUTTON_BOX(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkVButtonBox_"), XEN_CADR(obj)));}
static XEN gxg_GTK_VIEWPORT(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkViewport_"), XEN_CADR(obj)));}
static XEN gxg_GTK_VPANED(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkVPaned_"), XEN_CADR(obj)));}
static XEN gxg_GTK_VRULER(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkVRuler_"), XEN_CADR(obj)));}
static XEN gxg_GTK_VSCALE(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkVScale_"), XEN_CADR(obj)));}
static XEN gxg_GTK_VSCROLLBAR(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkVScrollbar_"), XEN_CADR(obj)));}
static XEN gxg_GTK_VSEPARATOR(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkVSeparator_"), XEN_CADR(obj)));}
static XEN gxg_GTK_WIDGET(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkWidget_"), XEN_CADR(obj)));}
static XEN gxg_GTK_WINDOW(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkWindow_"), XEN_CADR(obj)));}
static XEN gxg_PANGO_CONTEXT(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("PangoContext_"), XEN_CADR(obj)));}
static XEN gxg_PANGO_FONT_FAMILY(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("PangoFontFamily_"), XEN_CADR(obj)));}
static XEN gxg_PANGO_FONT_FACE(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("PangoFontFace_"), XEN_CADR(obj)));}
static XEN gxg_PANGO_FONT(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("PangoFont_"), XEN_CADR(obj)));}
static XEN gxg_PANGO_FONT_MAP(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("PangoFontMap_"), XEN_CADR(obj)));}
static XEN gxg_PANGO_LAYOUT(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("PangoLayout_"), XEN_CADR(obj)));}
static XEN gxg_G_OBJECT(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GObject_"), XEN_CADR(obj)));}
static XEN gxg_GPOINTER(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("gpointer"), XEN_CADR(obj)));}
static XEN gxg_GDK_EVENT_ANY(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkEventAny_"), XEN_CADR(obj)));}
static XEN gxg_GDK_EVENT_EXPOSE(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkEventExpose_"), XEN_CADR(obj)));}
static XEN gxg_GDK_EVENT_NOEXPOSE(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkEventNoExpose_"), XEN_CADR(obj)));}
static XEN gxg_GDK_EVENT_VISIBILITY(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkEventVisibility_"), XEN_CADR(obj)));}
static XEN gxg_GDK_EVENT_MOTION(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkEventMotion_"), XEN_CADR(obj)));}
static XEN gxg_GDK_EVENT_BUTTON(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkEventButton_"), XEN_CADR(obj)));}
static XEN gxg_GDK_EVENT_SCROLL(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkEventScroll_"), XEN_CADR(obj)));}
static XEN gxg_GDK_EVENT_KEY(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkEventKey_"), XEN_CADR(obj)));}
static XEN gxg_GDK_EVENT_CROSSING(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkEventCrossing_"), XEN_CADR(obj)));}
static XEN gxg_GDK_EVENT_FOCUS(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkEventFocus_"), XEN_CADR(obj)));}
static XEN gxg_GDK_EVENT_CONFIGURE(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkEventConfigure_"), XEN_CADR(obj)));}
static XEN gxg_GDK_EVENT_PROPERTY(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkEventProperty_"), XEN_CADR(obj)));}
static XEN gxg_GDK_EVENT_SELECTION(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkEventSelection_"), XEN_CADR(obj)));}
static XEN gxg_GDK_EVENT_PROXIMITY(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkEventProximity_"), XEN_CADR(obj)));}
static XEN gxg_GDK_EVENT_SETTING(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkEventSetting_"), XEN_CADR(obj)));}
static XEN gxg_GDK_EVENT_WINDOWSTATE(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkEventWindowState_"), XEN_CADR(obj)));}
static XEN gxg_GDK_EVENT_DND(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkEventDND_"), XEN_CADR(obj)));}
#if HAVE_GDK_DRAW_PIXBUF
static XEN gxg_GDK_SCREEN(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkScreen_"), XEN_CADR(obj)));}
static XEN gxg_GDK_DISPLAY_OBJECT(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GdkDisplay_"), XEN_CADR(obj)));}
#endif

#if HAVE_GTK_FILE_CHOOSER_DIALOG_NEW
static XEN gxg_GTK_FILE_CHOOSER_DIALOG(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkFileChooserDialog_"), XEN_CADR(obj)));}
static XEN gxg_GTK_FILE_CHOOSER_WIDGET(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkFileChooserWidget_"), XEN_CADR(obj)));}
static XEN gxg_GTK_TREE_MODEL_FILTER(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkTreeModelFilter_"), XEN_CADR(obj)));}
static XEN gxg_GTK_ACTION(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkAction_"), XEN_CADR(obj)));}
static XEN gxg_GTK_ACTION_GROUP(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkActionGroup_"), XEN_CADR(obj)));}
static XEN gxg_GTK_COMBO_BOX(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkComboBox_"), XEN_CADR(obj)));}
static XEN gxg_GTK_COMBO_BOX_ENTRY(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkComboBoxEntry_"), XEN_CADR(obj)));}
static XEN gxg_GTK_EXPANDER(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkExpander_"), XEN_CADR(obj)));}
static XEN gxg_GTK_FONT_BUTTON(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkFontButton_"), XEN_CADR(obj)));}
static XEN gxg_GTK_COLOR_BUTTON(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkColorButton_"), XEN_CADR(obj)));}
static XEN gxg_GTK_ENTRY_COMPLETION(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkEntryCompletion_"), XEN_CADR(obj)));}
static XEN gxg_GTK_UI_MANAGER(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkUIManager_"), XEN_CADR(obj)));}
static XEN gxg_GTK_RADIO_TOOL_BUTTON(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkRadioToolButton_"), XEN_CADR(obj)));}
static XEN gxg_GTK_RADIO_ACTION(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkRadioAction_"), XEN_CADR(obj)));}
static XEN gxg_GTK_SEPARATOR_TOOL_ITEM(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkSeparatorToolItem_"), XEN_CADR(obj)));}
static XEN gxg_GTK_TOGGLE_ACTION(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkToggleAction_"), XEN_CADR(obj)));}
static XEN gxg_GTK_TOGGLE_TOOL_BUTTON(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkToggleToolButton_"), XEN_CADR(obj)));}
static XEN gxg_GTK_FILE_FILTER(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkFileFilter_"), XEN_CADR(obj)));}
static XEN gxg_GTK_CELL_LAYOUT(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkCellLayout_"), XEN_CADR(obj)));}
static XEN gxg_GTK_CLIPBOARD(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkClipboard_"), XEN_CADR(obj)));}
static XEN gxg_GTK_FILE_CHOOSER(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkFileChooser_"), XEN_CADR(obj)));}
static XEN gxg_GTK_ICON_THEME(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkIconTheme_"), XEN_CADR(obj)));}
static XEN gxg_GTK_TOOL_BUTTON(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkToolButton_"), XEN_CADR(obj)));}
static XEN gxg_GTK_TOOL_ITEM(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkToolItem_"), XEN_CADR(obj)));}
#endif

#if HAVE_GTK_COMBO_BOX_POPUP
static XEN gxg_GTK_ACCEL_MAP(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkAccelMap"), XEN_CADR(obj)));}
#endif

#if HAVE_GTK_ABOUT_DIALOG_NEW
static XEN gxg_GTK_CELL_VIEW(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkCellView_"), XEN_CADR(obj)));}
static XEN gxg_GTK_ABOUT_DIALOG(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkAboutDialog_"), XEN_CADR(obj)));}
static XEN gxg_GTK_CELL_RENDERER_COMBO(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkCellRendererCombo_"), XEN_CADR(obj)));}
static XEN gxg_GTK_CELL_RENDERER_PROGRESS(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkCellRendererProgress_"), XEN_CADR(obj)));}
static XEN gxg_GTK_ICON_VIEW(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkIconView_"), XEN_CADR(obj)));}
#endif

#if HAVE_GTK_FILE_CHOOSER_BUTTON_NEW
static XEN gxg_GTK_FILE_CHOOSER_BUTTON(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkFileChooserButton_"), XEN_CADR(obj)));}
#endif

#if HAVE_GTK_MENU_TOOL_BUTTON_NEW
static XEN gxg_GTK_MENU_TOOL_BUTTON(XEN obj) {return(XEN_LIST_2(C_STRING_TO_XEN_SYMBOL("GtkMenuToolButton_"), XEN_CADR(obj)));}
#endif

static XEN gxg_GDK_IS_COLORMAP(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GDK_IS_COLORMAP((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GDK_IS_DRAG_CONTEXT(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GDK_IS_DRAG_CONTEXT((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GDK_IS_DRAWABLE(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GDK_IS_DRAWABLE((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GDK_IS_GC(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GDK_IS_GC((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GDK_IS_IMAGE(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GDK_IS_IMAGE((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GDK_IS_DEVICE(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GDK_IS_DEVICE((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GDK_IS_KEYMAP(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GDK_IS_KEYMAP((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GDK_IS_PIXMAP(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GDK_IS_PIXMAP((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GDK_IS_VISUAL(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GDK_IS_VISUAL((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GDK_IS_WINDOW(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GDK_IS_WINDOW((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GDK_IS_PIXBUF(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GDK_IS_PIXBUF((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GDK_IS_PIXBUF_ANIMATION(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GDK_IS_PIXBUF_ANIMATION((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GDK_IS_PIXBUF_ANIMATION_ITER(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GDK_IS_PIXBUF_ANIMATION_ITER((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GDK_IS_PIXBUF_LOADER(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GDK_IS_PIXBUF_LOADER((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_VBOX(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_VBOX((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_ACCEL_GROUP(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_ACCEL_GROUP((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_ACCEL_LABEL(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_ACCEL_LABEL((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_ACCESSIBLE(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_ACCESSIBLE((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_ADJUSTMENT(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_ADJUSTMENT((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_ALIGNMENT(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_ALIGNMENT((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_ARROW(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_ARROW((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_ASPECT_FRAME(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_ASPECT_FRAME((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_BUTTON_BOX(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_BUTTON_BOX((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_BIN(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_BIN((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_BOX(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_BOX((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_BUTTON(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_BUTTON((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_CALENDAR(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_CALENDAR((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_CELL_EDITABLE(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_CELL_EDITABLE((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_CELL_RENDERER(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_CELL_RENDERER((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_CELL_RENDERER_PIXBUF(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_CELL_RENDERER_PIXBUF((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_CELL_RENDERER_TEXT(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_CELL_RENDERER_TEXT((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_CELL_RENDERER_TOGGLE(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_CELL_RENDERER_TOGGLE((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_CHECK_BUTTON(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_CHECK_BUTTON((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_CHECK_MENU_ITEM(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_CHECK_MENU_ITEM((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_COLOR_SELECTION_DIALOG(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_COLOR_SELECTION_DIALOG((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_COLOR_SELECTION(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_COLOR_SELECTION((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_CONTAINER(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_CONTAINER((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_CURVE(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_CURVE((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_DIALOG(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_DIALOG((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_DRAWING_AREA(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_DRAWING_AREA((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_EDITABLE(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_EDITABLE((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_ENTRY(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_ENTRY((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_EVENT_BOX(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_EVENT_BOX((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_FILE_SELECTION(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_FILE_SELECTION((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_FIXED(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_FIXED((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_FONT_SELECTION(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_FONT_SELECTION((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_FONT_SELECTION_DIALOG(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_FONT_SELECTION_DIALOG((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_FRAME(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_FRAME((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_GAMMA_CURVE(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_GAMMA_CURVE((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_HANDLE_BOX(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_HANDLE_BOX((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_HBUTTON_BOX(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_HBUTTON_BOX((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_HBOX(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_HBOX((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_HPANED(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_HPANED((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_HRULER(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_HRULER((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_HSCALE(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_HSCALE((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_HSCROLLBAR(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_HSCROLLBAR((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_HSEPARATOR(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_HSEPARATOR((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_ICON_FACTORY(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_ICON_FACTORY((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_IMAGE(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_IMAGE((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_IMAGE_MENU_ITEM(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_IMAGE_MENU_ITEM((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_IM_CONTEXT(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_IM_CONTEXT((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_IM_CONTEXT_SIMPLE(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_IM_CONTEXT_SIMPLE((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_IM_MULTICONTEXT(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_IM_MULTICONTEXT((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_INPUT_DIALOG(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_INPUT_DIALOG((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_INVISIBLE(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_INVISIBLE((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_ITEM(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_ITEM((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_LABEL(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_LABEL((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_LAYOUT(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_LAYOUT((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_LIST_STORE(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_LIST_STORE((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_MENU_BAR(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_MENU_BAR((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_MENU(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_MENU((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_MENU_ITEM(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_MENU_ITEM((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_MENU_SHELL(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_MENU_SHELL((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_MESSAGE_DIALOG(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_MESSAGE_DIALOG((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_MISC(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_MISC((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_NOTEBOOK(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_NOTEBOOK((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_OBJECT(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_OBJECT((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_PANED(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_PANED((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_PLUG(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_PLUG((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_PROGRESS_BAR(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_PROGRESS_BAR((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_RADIO_BUTTON(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_RADIO_BUTTON((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_RADIO_MENU_ITEM(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_RADIO_MENU_ITEM((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_RANGE(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_RANGE((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_RC_STYLE(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_RC_STYLE((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_RULER(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_RULER((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_SCALE(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_SCALE((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_SCROLLBAR(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_SCROLLBAR((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_SCROLLED_WINDOW(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_SCROLLED_WINDOW((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_SEPARATOR(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_SEPARATOR((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_SEPARATOR_MENU_ITEM(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_SEPARATOR_MENU_ITEM((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_SIZE_GROUP(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_SIZE_GROUP((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_SOCKET(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_SOCKET((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_SPIN_BUTTON(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_SPIN_BUTTON((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_STATUSBAR(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_STATUSBAR((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_STYLE(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_STYLE((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_TABLE(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_TABLE((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_TEAROFF_MENU_ITEM(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_TEAROFF_MENU_ITEM((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_TEXT_BUFFER(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_TEXT_BUFFER((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_TEXT_CHILD_ANCHOR(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_TEXT_CHILD_ANCHOR((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_TEXT_MARK(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_TEXT_MARK((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_TEXT_TAG(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_TEXT_TAG((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_TEXT_TAG_TABLE(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_TEXT_TAG_TABLE((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_TEXT_VIEW(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_TEXT_VIEW((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_TOGGLE_BUTTON(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_TOGGLE_BUTTON((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_TOOLBAR(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_TOOLBAR((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_TOOLTIPS(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_TOOLTIPS((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_TREE_DRAG_SOURCE(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_TREE_DRAG_SOURCE((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_TREE_DRAG_DEST(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_TREE_DRAG_DEST((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_TREE_MODEL(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_TREE_MODEL((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_TREE_MODEL_SORT(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_TREE_MODEL_SORT((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_TREE_SELECTION(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_TREE_SELECTION((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_TREE_SORTABLE(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_TREE_SORTABLE((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_TREE_STORE(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_TREE_STORE((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_TREE_VIEW_COLUMN(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_TREE_VIEW_COLUMN((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_TREE_VIEW(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_TREE_VIEW((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_VBUTTON_BOX(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_VBUTTON_BOX((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_VIEWPORT(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_VIEWPORT((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_VPANED(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_VPANED((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_VRULER(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_VRULER((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_VSCALE(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_VSCALE((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_VSCROLLBAR(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_VSCROLLBAR((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_VSEPARATOR(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_VSEPARATOR((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_WIDGET(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_WIDGET((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_WINDOW(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_WINDOW((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_PANGO_IS_CONTEXT(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && PANGO_IS_CONTEXT((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_PANGO_IS_FONT_FAMILY(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && PANGO_IS_FONT_FAMILY((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_PANGO_IS_FONT_FACE(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && PANGO_IS_FONT_FACE((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_PANGO_IS_FONT(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && PANGO_IS_FONT((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_PANGO_IS_FONT_MAP(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && PANGO_IS_FONT_MAP((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_PANGO_IS_LAYOUT(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && PANGO_IS_LAYOUT((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_G_IS_OBJECT(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && G_IS_OBJECT((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
#if HAVE_GDK_DRAW_PIXBUF
static XEN gxg_GDK_IS_SCREEN(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GDK_IS_SCREEN((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GDK_IS_DISPLAY(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GDK_IS_DISPLAY((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
#endif

#if HAVE_GTK_FILE_CHOOSER_DIALOG_NEW
static XEN gxg_GTK_IS_FILE_CHOOSER_DIALOG(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_FILE_CHOOSER_DIALOG((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_FILE_CHOOSER_WIDGET(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_FILE_CHOOSER_WIDGET((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_TREE_MODEL_FILTER(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_TREE_MODEL_FILTER((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_ACTION(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_ACTION((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_ACTION_GROUP(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_ACTION_GROUP((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_COMBO_BOX(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_COMBO_BOX((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_COMBO_BOX_ENTRY(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_COMBO_BOX_ENTRY((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_EXPANDER(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_EXPANDER((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_FONT_BUTTON(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_FONT_BUTTON((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_COLOR_BUTTON(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_COLOR_BUTTON((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_ENTRY_COMPLETION(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_ENTRY_COMPLETION((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_UI_MANAGER(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_UI_MANAGER((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_RADIO_TOOL_BUTTON(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_RADIO_TOOL_BUTTON((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_RADIO_ACTION(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_RADIO_ACTION((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_SEPARATOR_TOOL_ITEM(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_SEPARATOR_TOOL_ITEM((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_TOGGLE_ACTION(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_TOGGLE_ACTION((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_TOGGLE_TOOL_BUTTON(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_TOGGLE_TOOL_BUTTON((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_FILE_FILTER(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_FILE_FILTER((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_CELL_LAYOUT(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_CELL_LAYOUT((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_CLIPBOARD(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_CLIPBOARD((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_FILE_CHOOSER(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_FILE_CHOOSER((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_ICON_THEME(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_ICON_THEME((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_TOOL_BUTTON(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_TOOL_BUTTON((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_TOOL_ITEM(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_TOOL_ITEM((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
#endif

#if HAVE_GTK_COMBO_BOX_POPUP
static XEN gxg_GTK_IS_ACCEL_MAP(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_ACCEL_MAP((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
#endif

#if HAVE_GTK_ABOUT_DIALOG_NEW
static XEN gxg_GTK_IS_CELL_VIEW(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_CELL_VIEW((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_ABOUT_DIALOG(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_ABOUT_DIALOG((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_CELL_RENDERER_COMBO(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_CELL_RENDERER_COMBO((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_CELL_RENDERER_PROGRESS(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_CELL_RENDERER_PROGRESS((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
static XEN gxg_GTK_IS_ICON_VIEW(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_ICON_VIEW((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
#endif

#if HAVE_GTK_FILE_CHOOSER_BUTTON_NEW
static XEN gxg_GTK_IS_FILE_CHOOSER_BUTTON(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_FILE_CHOOSER_BUTTON((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
#endif

#if HAVE_GTK_MENU_TOOL_BUTTON_NEW
static XEN gxg_GTK_IS_MENU_TOOL_BUTTON(XEN obj) {return(C_TO_XEN_BOOLEAN(XEN_LIST_P(obj) && GTK_IS_MENU_TOOL_BUTTON((GTypeInstance *)XEN_TO_C_ULONG(XEN_CADR(obj)))));}
#endif



/* ---------------------------------------- special functions ---------------------------------------- */

static XEN gxg_vector2GdkPoints(XEN arg1)
{
  #define H_vector2GdkPoints "(vector->GdkPoints vect) packages point data in vect as an (opaque) array of GdkPoints"
  int i, j, len;
  XEN *velts;
  GdkPoint *pt;
  XEN_ASSERT_TYPE(XEN_VECTOR_P(arg1), arg1, XEN_ONLY_ARG, "vector->GdkPoints", "vector of x,y values");
  len = XEN_VECTOR_LENGTH(arg1) / 2;
  if (len <= 0) XEN_ASSERT_TYPE(0, arg1, 1, "vector->GdkPoints", "positive integer");
  velts = XEN_VECTOR_ELEMENTS(arg1);
  pt = (GdkPoint *)CALLOC(len, sizeof(GdkPoint));
  for (i = 0, j = 0; i < len; i++, j += 2)
    {
      pt[i].x = XEN_TO_C_INT(velts[j]);
      pt[i].y = XEN_TO_C_INT(velts[j + 1]);
    }
  return(C_TO_XEN_ULONG((unsigned long)pt));
}

static XEN gxg_freeGdkPoints(XEN arg1)
{
  void *pts;
  #define H_freeGdkPoints "(freeGdkPoints vect) frees an (opaque) GdkPoint array created by vector->Gdkpoints"
  XEN_ASSERT_TYPE(XEN_ULONG_P(arg1), arg1, XEN_ONLY_ARG, "freeGdkPoints", "opaque GdkPoint array");
  pts = (void *)(XEN_TO_C_ULONG(arg1));
  FREE(pts);
  return(XEN_FALSE);
}

static XEN gxg_make_target_entry(XEN lst)
{
  GtkTargetEntry* targets;
  XEN val;
  int i, len;
  #define H_make_target_entry "(make-target-entry lst) -> GtkTargetEntry*, each member of 'lst' should be (list target flags info)"
  XEN_ASSERT_TYPE(XEN_LIST_P(lst), lst, XEN_ONLY_ARG, "make-target-entry", "a list of lists describing each target");
  len = XEN_LIST_LENGTH(lst);
  if (len == 0) return(XEN_FALSE);
  targets = (GtkTargetEntry *)CALLOC(len, sizeof(GtkTargetEntry));
  for (i = 0; i < len; i++)
    {
      val = XEN_LIST_REF(lst, i);
      targets[i].target = strdup(XEN_TO_C_STRING(XEN_LIST_REF(val, 0)));
      targets[i].flags = (guint)XEN_TO_C_ULONG(XEN_LIST_REF(val, 1));
      targets[i].info = (guint)XEN_TO_C_ULONG(XEN_LIST_REF(val, 2));
    }
  return(C_TO_XEN_GtkTargetEntry_(targets));
}
static XEN c_array_to_xen_list(XEN val, XEN clen);
static XEN xen_list_to_c_array(XEN val, XEN type);

  #define XG_DEFINE_PROCEDURE(Name, Value, A1, A2, A3, Help) XEN_DEFINE_PROCEDURE(XG_PRE #Name XG_POST, Value, A1, A2, A3, Help)
#if HAVE_GUILE

#endif
/* ---------------------------------------- structs ---------------------------------------- */

  #define XG_DEFINE_READER(Name, Value, A1, A2, A3, Help) XEN_DEFINE_PROCEDURE(XG_FIELD_PRE #Name XG_POST, Value, A1, A2, A3, Help)
  #if HAVE_RUBY
  #define XG_DEFINE_ACCESSOR(Name, Value, SetValue, A1, A2, A3, A4) \
    XEN_DEFINE_PROCEDURE_WITH_SETTER(XG_FIELD_PRE #Name XG_POST, Value, NULL, XG_FIELD_PRE "set_" #Name XG_POST, SetValue, A1, A2, A3, A4)
  #else
  #define XG_DEFINE_ACCESSOR(Name, Value, SetValue, A1, A2, A3, A4) \
    XEN_DEFINE_PROCEDURE_WITH_SETTER(XG_FIELD_PRE #Name XG_POST, Value, NULL, "set! " XG_FIELD_PRE #Name XG_POST, SetValue, A1, A2, A3, A4)
  #endif

/* conversions */
static XEN c_array_to_xen_list(XEN val_1, XEN clen)
{
  XEN result = XEN_EMPTY_LIST;
  XEN val;
  int i, len = -1;
  char *ctype;
  if (XEN_INTEGER_P(clen))
    len = XEN_TO_C_INT(clen);
  if (!(XEN_LIST_P(val_1))) return(XEN_FALSE); /* type:location cons */
  val = XEN_COPY_ARG(val_1); /* protect Ruby arg */
  ctype = XEN_SYMBOL_TO_C_STRING(XEN_CAR(val));
  if (strcmp(ctype, "gint_") == 0)
    {
      gint* arr; arr = (gint*)XEN_TO_C_ULONG(XEN_CADR(val)); 
      if (len == -1) {for (i = 0; arr[i]; i++); len = i;}
      for (i = len - 1; i >= 0; i--) result = XEN_CONS(C_TO_XEN_gint(arr[i]), result);
    }
  if (strcmp(ctype, "gboolean_") == 0)
    {
      gboolean* arr; arr = (gboolean*)XEN_TO_C_ULONG(XEN_CADR(val)); 
      if (len == -1) {for (i = 0; arr[i]; i++); len = i;}
      for (i = len - 1; i >= 0; i--) result = XEN_CONS(C_TO_XEN_gboolean(arr[i]), result);
    }
  if (strcmp(ctype, "GType_") == 0)
    {
      GType* arr; arr = (GType*)XEN_TO_C_ULONG(XEN_CADR(val)); 
      if (len == -1) {for (i = 0; arr[i]; i++); len = i;}
      for (i = len - 1; i >= 0; i--) result = XEN_CONS(C_TO_XEN_GType(arr[i]), result);
    }
  if (strcmp(ctype, "guint_") == 0)
    {
      guint* arr; arr = (guint*)XEN_TO_C_ULONG(XEN_CADR(val)); 
      if (len == -1) {for (i = 0; arr[i]; i++); len = i;}
      for (i = len - 1; i >= 0; i--) result = XEN_CONS(C_TO_XEN_guint(arr[i]), result);
    }
  if (strcmp(ctype, "gint8_") == 0)
    {
      gint8* arr; arr = (gint8*)XEN_TO_C_ULONG(XEN_CADR(val)); 
      if (len == -1) {for (i = 0; arr[i]; i++); len = i;}
      for (i = len - 1; i >= 0; i--) result = XEN_CONS(C_TO_XEN_gint8(arr[i]), result);
    }
  if (strcmp(ctype, "gchar__") == 0)
    {
      gchar** arr; arr = (gchar**)XEN_TO_C_ULONG(XEN_CADR(val)); 
      if (len == -1) {for (i = 0; arr[i]; i++); len = i;}
      for (i = len - 1; i >= 0; i--) result = XEN_CONS(C_TO_XEN_gchar_(arr[i]), result);
    }
  if (strcmp(ctype, "gdouble_") == 0)
    {
      gdouble* arr; arr = (gdouble*)XEN_TO_C_ULONG(XEN_CADR(val)); 
      if (len == -1) {for (i = 0; arr[i]; i++); len = i;}
      for (i = len - 1; i >= 0; i--) result = XEN_CONS(C_TO_XEN_gdouble(arr[i]), result);
    }
  if (strcmp(ctype, "guchar_") == 0)
    {
      guchar* arr; arr = (guchar*)XEN_TO_C_ULONG(XEN_CADR(val)); 
      if (len == -1) {for (i = 0; arr[i]; i++); len = i;}
      for (i = len - 1; i >= 0; i--) result = XEN_CONS(C_TO_XEN_guchar(arr[i]), result);
    }
  if (strcmp(ctype, "guint32_") == 0)
    {
      guint32* arr; arr = (guint32*)XEN_TO_C_ULONG(XEN_CADR(val)); 
      if (len == -1) {for (i = 0; arr[i]; i++); len = i;}
      for (i = len - 1; i >= 0; i--) result = XEN_CONS(C_TO_XEN_guint32(arr[i]), result);
    }
  if (strcmp(ctype, "GdkVisualType_") == 0)
    {
      GdkVisualType* arr; arr = (GdkVisualType*)XEN_TO_C_ULONG(XEN_CADR(val)); 
      if (len == -1) {for (i = 0; arr[i]; i++); len = i;}
      for (i = len - 1; i >= 0; i--) result = XEN_CONS(C_TO_XEN_GdkVisualType(arr[i]), result);
    }
  if (strcmp(ctype, "char__") == 0)
    {
      char** arr; arr = (char**)XEN_TO_C_ULONG(XEN_CADR(val)); 
      if (len == -1) {for (i = 0; arr[i]; i++); len = i;}
      for (i = len - 1; i >= 0; i--) result = XEN_CONS(C_TO_XEN_char_(arr[i]), result);
    }
  if (strcmp(ctype, "guint8_") == 0)
    {
      guint8* arr; arr = (guint8*)XEN_TO_C_ULONG(XEN_CADR(val)); 
      if (len == -1) {for (i = 0; arr[i]; i++); len = i;}
      for (i = len - 1; i >= 0; i--) result = XEN_CONS(C_TO_XEN_guint8(arr[i]), result);
    }
  if (strcmp(ctype, "gfloat_") == 0)
    {
      gfloat* arr; arr = (gfloat*)XEN_TO_C_ULONG(XEN_CADR(val)); 
      if (len == -1) {for (i = 0; arr[i]; i++); len = i;}
      for (i = len - 1; i >= 0; i--) result = XEN_CONS(C_TO_XEN_gfloat(arr[i]), result);
    }
  if (strcmp(ctype, "GtkIconSize_") == 0)
    {
      GtkIconSize* arr; arr = (GtkIconSize*)XEN_TO_C_ULONG(XEN_CADR(val)); 
      if (len == -1) {for (i = 0; arr[i]; i++); len = i;}
      for (i = len - 1; i >= 0; i--) result = XEN_CONS(C_TO_XEN_GtkIconSize(arr[i]), result);
    }
  if (strcmp(ctype, "guint16_") == 0)
    {
      guint16* arr; arr = (guint16*)XEN_TO_C_ULONG(XEN_CADR(val)); 
      if (len == -1) {for (i = 0; arr[i]; i++); len = i;}
      for (i = len - 1; i >= 0; i--) result = XEN_CONS(C_TO_XEN_guint16(arr[i]), result);
    }
  if (strcmp(ctype, "gunichar_") == 0)
    {
      gunichar* arr; arr = (gunichar*)XEN_TO_C_ULONG(XEN_CADR(val)); 
      if (len == -1) {for (i = 0; arr[i]; i++); len = i;}
      for (i = len - 1; i >= 0; i--) result = XEN_CONS(C_TO_XEN_gunichar(arr[i]), result);
    }
  if (strcmp(ctype, "int_") == 0)
    {
      int* arr; arr = (int*)XEN_TO_C_ULONG(XEN_CADR(val)); 
      if (len == -1) {for (i = 0; arr[i]; i++); len = i;}
      for (i = len - 1; i >= 0; i--) result = XEN_CONS(C_TO_XEN_int(arr[i]), result);
    }
  if (strcmp(ctype, "GdkPixmap__") == 0)
    {
      GdkPixmap** arr; arr = (GdkPixmap**)XEN_TO_C_ULONG(XEN_CADR(val)); 
      if (len == -1) {for (i = 0; arr[i]; i++); len = i;}
      for (i = len - 1; i >= 0; i--) result = XEN_CONS(C_TO_XEN_GdkPixmap_(arr[i]), result);
    }
  if (strcmp(ctype, "GdkGC__") == 0)
    {
      GdkGC** arr; arr = (GdkGC**)XEN_TO_C_ULONG(XEN_CADR(val)); 
      if (len == -1) {for (i = 0; arr[i]; i++); len = i;}
      for (i = len - 1; i >= 0; i--) result = XEN_CONS(C_TO_XEN_GdkGC_(arr[i]), result);
    }
  if (strcmp(ctype, "PangoFontFace__") == 0)
    {
      PangoFontFace** arr; arr = (PangoFontFace**)XEN_TO_C_ULONG(XEN_CADR(val)); 
      if (len == -1) {for (i = 0; arr[i]; i++); len = i;}
      for (i = len - 1; i >= 0; i--) result = XEN_CONS(C_TO_XEN_PangoFontFace_(arr[i]), result);
    }
  if (strcmp(ctype, "PangoFontDescription__") == 0)
    {
      PangoFontDescription** arr; arr = (PangoFontDescription**)XEN_TO_C_ULONG(XEN_CADR(val)); 
      if (len == -1) {for (i = 0; arr[i]; i++); len = i;}
      for (i = len - 1; i >= 0; i--) result = XEN_CONS(C_TO_XEN_PangoFontDescription_(arr[i]), result);
    }
  if (strcmp(ctype, "PangoFontFamily__") == 0)
    {
      PangoFontFamily** arr; arr = (PangoFontFamily**)XEN_TO_C_ULONG(XEN_CADR(val)); 
      if (len == -1) {for (i = 0; arr[i]; i++); len = i;}
      for (i = len - 1; i >= 0; i--) result = XEN_CONS(C_TO_XEN_PangoFontFamily_(arr[i]), result);
    }
  if (strcmp(ctype, "PangoAttrList__") == 0)
    {
      PangoAttrList** arr; arr = (PangoAttrList**)XEN_TO_C_ULONG(XEN_CADR(val)); 
      if (len == -1) {for (i = 0; arr[i]; i++); len = i;}
      for (i = len - 1; i >= 0; i--) result = XEN_CONS(C_TO_XEN_PangoAttrList_(arr[i]), result);
    }
  if (strcmp(ctype, "GtkTreeModel__") == 0)
    {
      GtkTreeModel** arr; arr = (GtkTreeModel**)XEN_TO_C_ULONG(XEN_CADR(val)); 
      if (len == -1) {for (i = 0; arr[i]; i++); len = i;}
      for (i = len - 1; i >= 0; i--) result = XEN_CONS(C_TO_XEN_GtkTreeModel_(arr[i]), result);
    }
  if (strcmp(ctype, "GdkBitmap__") == 0)
    {
      GdkBitmap** arr; arr = (GdkBitmap**)XEN_TO_C_ULONG(XEN_CADR(val)); 
      if (len == -1) {for (i = 0; arr[i]; i++); len = i;}
      for (i = len - 1; i >= 0; i--) result = XEN_CONS(C_TO_XEN_GdkBitmap_(arr[i]), result);
    }
  if (strcmp(ctype, "GList_") == 0)
    { /* tagging these pointers is currently up to the caller */
      GList* lst;
      lst = (GList*)XEN_TO_C_ULONG(XEN_CADR(val));
      len = g_list_length(lst);
      for (i = len - 1; i >= 0; i--) result = XEN_CONS(C_TO_XEN_ULONG(g_list_nth_data(lst, i)), result);
    }
  return(result);
}

static XEN xen_list_to_c_array(XEN val, XEN type)
{
  int i, len;
  char *ctype;
  len = XEN_LIST_LENGTH(val);
  ctype = XEN_TO_C_STRING(type);
  if (strcmp(ctype, "gint*") == 0)
    {
      gint* arr; arr = (gint*)CALLOC(len + 1, sizeof(gint));
      for (i = 0; i < len; i++, val = XEN_CDR(val)) arr[i] = XEN_TO_C_gint(XEN_CAR(val));
      return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("gint_"), C_TO_XEN_ULONG((unsigned long)arr), make_xm_obj(arr)));
    }
  if (strcmp(ctype, "gboolean*") == 0)
    {
      gboolean* arr; arr = (gboolean*)CALLOC(len + 1, sizeof(gboolean));
      for (i = 0; i < len; i++, val = XEN_CDR(val)) arr[i] = XEN_TO_C_gboolean(XEN_CAR(val));
      return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("gboolean_"), C_TO_XEN_ULONG((unsigned long)arr), make_xm_obj(arr)));
    }
  if (strcmp(ctype, "GType*") == 0)
    {
      GType* arr; arr = (GType*)CALLOC(len + 1, sizeof(GType));
      for (i = 0; i < len; i++, val = XEN_CDR(val)) arr[i] = XEN_TO_C_GType(XEN_CAR(val));
      return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("GType_"), C_TO_XEN_ULONG((unsigned long)arr), make_xm_obj(arr)));
    }
  if (strcmp(ctype, "guint*") == 0)
    {
      guint* arr; arr = (guint*)CALLOC(len + 1, sizeof(guint));
      for (i = 0; i < len; i++, val = XEN_CDR(val)) arr[i] = XEN_TO_C_guint(XEN_CAR(val));
      return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("guint_"), C_TO_XEN_ULONG((unsigned long)arr), make_xm_obj(arr)));
    }
  if (strcmp(ctype, "gint8*") == 0)
    {
      gint8* arr; arr = (gint8*)CALLOC(len + 1, sizeof(gint8));
      for (i = 0; i < len; i++, val = XEN_CDR(val)) arr[i] = XEN_TO_C_gint8(XEN_CAR(val));
      return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("gint8_"), C_TO_XEN_ULONG((unsigned long)arr), make_xm_obj(arr)));
    }
  if (strcmp(ctype, "gchar**") == 0)
    {
      gchar** arr; arr = (gchar**)CALLOC(len + 1, sizeof(gchar*));
      for (i = 0; i < len; i++, val = XEN_CDR(val)) arr[i] = XEN_TO_C_gchar_(XEN_CAR(val));
      return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("gchar__"), C_TO_XEN_ULONG((unsigned long)arr), make_xm_obj(arr)));
    }
  if (strcmp(ctype, "gdouble*") == 0)
    {
      gdouble* arr; arr = (gdouble*)CALLOC(len + 1, sizeof(gdouble));
      for (i = 0; i < len; i++, val = XEN_CDR(val)) arr[i] = XEN_TO_C_gdouble(XEN_CAR(val));
      return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("gdouble_"), C_TO_XEN_ULONG((unsigned long)arr), make_xm_obj(arr)));
    }
  if (strcmp(ctype, "guchar*") == 0)
    {
      guchar* arr; arr = (guchar*)CALLOC(len + 1, sizeof(guchar));
      for (i = 0; i < len; i++, val = XEN_CDR(val)) arr[i] = XEN_TO_C_guchar(XEN_CAR(val));
      return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("guchar_"), C_TO_XEN_ULONG((unsigned long)arr), make_xm_obj(arr)));
    }
  if (strcmp(ctype, "guint32*") == 0)
    {
      guint32* arr; arr = (guint32*)CALLOC(len + 1, sizeof(guint32));
      for (i = 0; i < len; i++, val = XEN_CDR(val)) arr[i] = XEN_TO_C_guint32(XEN_CAR(val));
      return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("guint32_"), C_TO_XEN_ULONG((unsigned long)arr), make_xm_obj(arr)));
    }
  if (strcmp(ctype, "GdkVisualType*") == 0)
    {
      GdkVisualType* arr; arr = (GdkVisualType*)CALLOC(len + 1, sizeof(GdkVisualType));
      for (i = 0; i < len; i++, val = XEN_CDR(val)) arr[i] = XEN_TO_C_GdkVisualType(XEN_CAR(val));
      return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("GdkVisualType_"), C_TO_XEN_ULONG((unsigned long)arr), make_xm_obj(arr)));
    }
  if (strcmp(ctype, "char**") == 0)
    {
      char** arr; arr = (char**)CALLOC(len + 1, sizeof(char*));
      for (i = 0; i < len; i++, val = XEN_CDR(val)) arr[i] = XEN_TO_C_char_(XEN_CAR(val));
      return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("char__"), C_TO_XEN_ULONG((unsigned long)arr), make_xm_obj(arr)));
    }
  if (strcmp(ctype, "guint8*") == 0)
    {
      guint8* arr; arr = (guint8*)CALLOC(len + 1, sizeof(guint8));
      for (i = 0; i < len; i++, val = XEN_CDR(val)) arr[i] = XEN_TO_C_guint8(XEN_CAR(val));
      return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("guint8_"), C_TO_XEN_ULONG((unsigned long)arr), make_xm_obj(arr)));
    }
  if (strcmp(ctype, "gfloat*") == 0)
    {
      gfloat* arr; arr = (gfloat*)CALLOC(len + 1, sizeof(gfloat));
      for (i = 0; i < len; i++, val = XEN_CDR(val)) arr[i] = XEN_TO_C_gfloat(XEN_CAR(val));
      return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("gfloat_"), C_TO_XEN_ULONG((unsigned long)arr), make_xm_obj(arr)));
    }
  if (strcmp(ctype, "GtkIconSize*") == 0)
    {
      GtkIconSize* arr; arr = (GtkIconSize*)CALLOC(len + 1, sizeof(GtkIconSize));
      for (i = 0; i < len; i++, val = XEN_CDR(val)) arr[i] = XEN_TO_C_GtkIconSize(XEN_CAR(val));
      return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("GtkIconSize_"), C_TO_XEN_ULONG((unsigned long)arr), make_xm_obj(arr)));
    }
  if (strcmp(ctype, "guint16*") == 0)
    {
      guint16* arr; arr = (guint16*)CALLOC(len + 1, sizeof(guint16));
      for (i = 0; i < len; i++, val = XEN_CDR(val)) arr[i] = XEN_TO_C_guint16(XEN_CAR(val));
      return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("guint16_"), C_TO_XEN_ULONG((unsigned long)arr), make_xm_obj(arr)));
    }
  if (strcmp(ctype, "gunichar*") == 0)
    {
      gunichar* arr; arr = (gunichar*)CALLOC(len + 1, sizeof(gunichar));
      for (i = 0; i < len; i++, val = XEN_CDR(val)) arr[i] = XEN_TO_C_gunichar(XEN_CAR(val));
      return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("gunichar_"), C_TO_XEN_ULONG((unsigned long)arr), make_xm_obj(arr)));
    }
  if (strcmp(ctype, "int*") == 0)
    {
      int* arr; arr = (int*)CALLOC(len + 1, sizeof(int));
      for (i = 0; i < len; i++, val = XEN_CDR(val)) arr[i] = XEN_TO_C_int(XEN_CAR(val));
      return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("int_"), C_TO_XEN_ULONG((unsigned long)arr), make_xm_obj(arr)));
    }
  if (strcmp(ctype, "GdkPixmap**") == 0)
    {
      GdkPixmap** arr; arr = (GdkPixmap**)CALLOC(len + 1, sizeof(GdkPixmap*));
      for (i = 0; i < len; i++, val = XEN_CDR(val)) arr[i] = XEN_TO_C_GdkPixmap_(XEN_CAR(val));
      return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("GdkPixmap__"), C_TO_XEN_ULONG((unsigned long)arr), make_xm_obj(arr)));
    }
  if (strcmp(ctype, "GdkGC**") == 0)
    {
      GdkGC** arr; arr = (GdkGC**)CALLOC(len + 1, sizeof(GdkGC*));
      for (i = 0; i < len; i++, val = XEN_CDR(val)) arr[i] = XEN_TO_C_GdkGC_(XEN_CAR(val));
      return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("GdkGC__"), C_TO_XEN_ULONG((unsigned long)arr), make_xm_obj(arr)));
    }
  if (strcmp(ctype, "PangoFontFace**") == 0)
    {
      PangoFontFace** arr; arr = (PangoFontFace**)CALLOC(len + 1, sizeof(PangoFontFace*));
      for (i = 0; i < len; i++, val = XEN_CDR(val)) arr[i] = XEN_TO_C_PangoFontFace_(XEN_CAR(val));
      return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("PangoFontFace__"), C_TO_XEN_ULONG((unsigned long)arr), make_xm_obj(arr)));
    }
  if (strcmp(ctype, "PangoFontDescription**") == 0)
    {
      PangoFontDescription** arr; arr = (PangoFontDescription**)CALLOC(len + 1, sizeof(PangoFontDescription*));
      for (i = 0; i < len; i++, val = XEN_CDR(val)) arr[i] = XEN_TO_C_PangoFontDescription_(XEN_CAR(val));
      return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("PangoFontDescription__"), C_TO_XEN_ULONG((unsigned long)arr), make_xm_obj(arr)));
    }
  if (strcmp(ctype, "PangoFontFamily**") == 0)
    {
      PangoFontFamily** arr; arr = (PangoFontFamily**)CALLOC(len + 1, sizeof(PangoFontFamily*));
      for (i = 0; i < len; i++, val = XEN_CDR(val)) arr[i] = XEN_TO_C_PangoFontFamily_(XEN_CAR(val));
      return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("PangoFontFamily__"), C_TO_XEN_ULONG((unsigned long)arr), make_xm_obj(arr)));
    }
  if (strcmp(ctype, "PangoAttrList**") == 0)
    {
      PangoAttrList** arr; arr = (PangoAttrList**)CALLOC(len + 1, sizeof(PangoAttrList*));
      for (i = 0; i < len; i++, val = XEN_CDR(val)) arr[i] = XEN_TO_C_PangoAttrList_(XEN_CAR(val));
      return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("PangoAttrList__"), C_TO_XEN_ULONG((unsigned long)arr), make_xm_obj(arr)));
    }
  if (strcmp(ctype, "GtkTreeModel**") == 0)
    {
      GtkTreeModel** arr; arr = (GtkTreeModel**)CALLOC(len + 1, sizeof(GtkTreeModel*));
      for (i = 0; i < len; i++, val = XEN_CDR(val)) arr[i] = XEN_TO_C_GtkTreeModel_(XEN_CAR(val));
      return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("GtkTreeModel__"), C_TO_XEN_ULONG((unsigned long)arr), make_xm_obj(arr)));
    }
  if (strcmp(ctype, "GdkBitmap**") == 0)
    {
      GdkBitmap** arr; arr = (GdkBitmap**)CALLOC(len + 1, sizeof(GdkBitmap*));
      for (i = 0; i < len; i++, val = XEN_CDR(val)) arr[i] = XEN_TO_C_GdkBitmap_(XEN_CAR(val));
      return(XEN_LIST_3(C_STRING_TO_XEN_SYMBOL("GdkBitmap__"), C_TO_XEN_ULONG((unsigned long)arr), make_xm_obj(arr)));
    }
  return(XEN_FALSE);
}


static XEN gxg_size(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkColormap__P(ptr), ptr, XEN_ONLY_ARG, "size", "GdkColormap");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkColormap_(ptr))->size)));
}

static XEN gxg_colors(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkColormap__P(ptr) || XEN_GdkRgbCmap__P(ptr), ptr, XEN_ONLY_ARG, "colors", "GdkColormap" " or " "GdkRgbCmap");
  if (XEN_GdkColormap__P(ptr)) return(C_TO_XEN_GdkColor_((GdkColor*)((XEN_TO_C_GdkColormap_(ptr))->colors)));
  return(C_TO_XEN_guint32_((guint32*)((XEN_TO_C_GdkRgbCmap_(ptr))->colors)));
}

gxg_static XEN gxg_visual(XEN ptr)
{
  if (XEN_GdkColormap__P(ptr)) return(C_TO_XEN_GdkVisual_((GdkVisual*)((XEN_TO_C_GdkColormap_(ptr))->visual)));
  if (XEN_GdkImage__P(ptr)) return(C_TO_XEN_GdkVisual_((GdkVisual*)((XEN_TO_C_GdkImage_(ptr))->visual)));
  if (XEN_GdkWindowAttr__P(ptr)) return(C_TO_XEN_GdkVisual_((GdkVisual*)((XEN_TO_C_GdkWindowAttr_(ptr))->visual)));
  XEN_ASSERT_TYPE(0, ptr, XEN_ONLY_ARG, "visual", "pointer to struct with visual field");
}

static XEN gxg_windowing_data(XEN ptr)
{
  if (XEN_GdkColormap__P(ptr)) return(C_TO_XEN_gpointer((gpointer)((XEN_TO_C_GdkColormap_(ptr))->windowing_data)));
  if (XEN_GdkDragContext__P(ptr)) return(C_TO_XEN_gpointer((gpointer)((XEN_TO_C_GdkDragContext_(ptr))->windowing_data)));
  if (XEN_GdkImage__P(ptr)) return(C_TO_XEN_gpointer((gpointer)((XEN_TO_C_GdkImage_(ptr))->windowing_data)));
  XEN_ASSERT_TYPE(0, ptr, XEN_ONLY_ARG, "windowing_data", "pointer to struct with windowing_data field");
}

gxg_static XEN gxg_type(XEN ptr)
{
  if (XEN_GdkCursor__P(ptr)) return(C_TO_XEN_GdkCursorType((GdkCursorType)((XEN_TO_C_GdkCursor_(ptr))->type)));
  if (XEN_GdkEventAny__P(ptr)) return(C_TO_XEN_GdkEventType((GdkEventType)((XEN_TO_C_GdkEventAny_(ptr))->type)));
  if (XEN_GdkEventExpose__P(ptr)) return(C_TO_XEN_GdkEventType((GdkEventType)((XEN_TO_C_GdkEventExpose_(ptr))->type)));
  if (XEN_GdkEventNoExpose__P(ptr)) return(C_TO_XEN_GdkEventType((GdkEventType)((XEN_TO_C_GdkEventNoExpose_(ptr))->type)));
  if (XEN_GdkEventVisibility__P(ptr)) return(C_TO_XEN_GdkEventType((GdkEventType)((XEN_TO_C_GdkEventVisibility_(ptr))->type)));
  if (XEN_GdkEventMotion__P(ptr)) return(C_TO_XEN_GdkEventType((GdkEventType)((XEN_TO_C_GdkEventMotion_(ptr))->type)));
  if (XEN_GdkEventButton__P(ptr)) return(C_TO_XEN_GdkEventType((GdkEventType)((XEN_TO_C_GdkEventButton_(ptr))->type)));
  if (XEN_GdkEventScroll__P(ptr)) return(C_TO_XEN_GdkEventType((GdkEventType)((XEN_TO_C_GdkEventScroll_(ptr))->type)));
  if (XEN_GdkEventKey__P(ptr)) return(C_TO_XEN_GdkEventType((GdkEventType)((XEN_TO_C_GdkEventKey_(ptr))->type)));
  if (XEN_GdkEventCrossing__P(ptr)) return(C_TO_XEN_GdkEventType((GdkEventType)((XEN_TO_C_GdkEventCrossing_(ptr))->type)));
  if (XEN_GdkEventFocus__P(ptr)) return(C_TO_XEN_GdkEventType((GdkEventType)((XEN_TO_C_GdkEventFocus_(ptr))->type)));
  if (XEN_GdkEventConfigure__P(ptr)) return(C_TO_XEN_GdkEventType((GdkEventType)((XEN_TO_C_GdkEventConfigure_(ptr))->type)));
  if (XEN_GdkEventProperty__P(ptr)) return(C_TO_XEN_GdkEventType((GdkEventType)((XEN_TO_C_GdkEventProperty_(ptr))->type)));
  if (XEN_GdkEventSelection__P(ptr)) return(C_TO_XEN_GdkEventType((GdkEventType)((XEN_TO_C_GdkEventSelection_(ptr))->type)));
  if (XEN_GdkEventProximity__P(ptr)) return(C_TO_XEN_GdkEventType((GdkEventType)((XEN_TO_C_GdkEventProximity_(ptr))->type)));
  if (XEN_GdkEventSetting__P(ptr)) return(C_TO_XEN_GdkEventType((GdkEventType)((XEN_TO_C_GdkEventSetting_(ptr))->type)));
  if (XEN_GdkEventWindowState__P(ptr)) return(C_TO_XEN_GdkEventType((GdkEventType)((XEN_TO_C_GdkEventWindowState_(ptr))->type)));
  if (XEN_GdkEventDND__P(ptr)) return(C_TO_XEN_GdkEventType((GdkEventType)((XEN_TO_C_GdkEventDND_(ptr))->type)));
  if (XEN_GdkImage__P(ptr)) return(C_TO_XEN_GdkImageType((GdkImageType)((XEN_TO_C_GdkImage_(ptr))->type)));
  if (XEN_GdkVisual__P(ptr)) return(C_TO_XEN_GdkVisualType((GdkVisualType)((XEN_TO_C_GdkVisual_(ptr))->type)));
  XEN_ASSERT_TYPE(0, ptr, XEN_ONLY_ARG, "type", "pointer to struct with type field");
}

static XEN gxg_ref_count(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkCursor__P(ptr), ptr, XEN_ONLY_ARG, "ref_count", "GdkCursor");
  return(C_TO_XEN_guint((guint)((XEN_TO_C_GdkCursor_(ptr))->ref_count)));
}

static XEN gxg_protocol(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkDragContext__P(ptr), ptr, XEN_ONLY_ARG, "protocol", "GdkDragContext");
  return(C_TO_XEN_GdkDragProtocol((GdkDragProtocol)((XEN_TO_C_GdkDragContext_(ptr))->protocol)));
}

static XEN gxg_is_source(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkDragContext__P(ptr), ptr, XEN_ONLY_ARG, "is_source", "GdkDragContext");
  return(C_TO_XEN_gboolean((gboolean)((XEN_TO_C_GdkDragContext_(ptr))->is_source)));
}

static XEN gxg_source_window(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkDragContext__P(ptr), ptr, XEN_ONLY_ARG, "source_window", "GdkDragContext");
  return(C_TO_XEN_GdkWindow_((GdkWindow*)((XEN_TO_C_GdkDragContext_(ptr))->source_window)));
}

static XEN gxg_dest_window(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkDragContext__P(ptr), ptr, XEN_ONLY_ARG, "dest_window", "GdkDragContext");
  return(C_TO_XEN_GdkWindow_((GdkWindow*)((XEN_TO_C_GdkDragContext_(ptr))->dest_window)));
}

static XEN gxg_targets(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkDragContext__P(ptr), ptr, XEN_ONLY_ARG, "targets", "GdkDragContext");
  return(C_TO_XEN_GList_((GList*)((XEN_TO_C_GdkDragContext_(ptr))->targets)));
}

static XEN gxg_actions(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkDragContext__P(ptr), ptr, XEN_ONLY_ARG, "actions", "GdkDragContext");
  return(C_TO_XEN_GdkDragAction((GdkDragAction)((XEN_TO_C_GdkDragContext_(ptr))->actions)));
}

static XEN gxg_suggested_action(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkDragContext__P(ptr), ptr, XEN_ONLY_ARG, "suggested_action", "GdkDragContext");
  return(C_TO_XEN_GdkDragAction((GdkDragAction)((XEN_TO_C_GdkDragContext_(ptr))->suggested_action)));
}

static XEN gxg_action(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkDragContext__P(ptr) || XEN_GdkEventSetting__P(ptr), ptr, XEN_ONLY_ARG, "action", "GdkDragContext" " or " "GdkEventSetting");
  if (XEN_GdkDragContext__P(ptr)) return(C_TO_XEN_GdkDragAction((GdkDragAction)((XEN_TO_C_GdkDragContext_(ptr))->action)));
  return(C_TO_XEN_GdkSettingAction((GdkSettingAction)((XEN_TO_C_GdkEventSetting_(ptr))->action)));
}

static XEN gxg_start_time(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkDragContext__P(ptr), ptr, XEN_ONLY_ARG, "start_time", "GdkDragContext");
  return(C_TO_XEN_guint32((guint32)((XEN_TO_C_GdkDragContext_(ptr))->start_time)));
}

gxg_static XEN gxg_window(XEN ptr)
{
  if (XEN_GdkEventAny__P(ptr)) return(C_TO_XEN_GdkWindow_((GdkWindow*)((XEN_TO_C_GdkEventAny_(ptr))->window)));
  if (XEN_GdkEventExpose__P(ptr)) return(C_TO_XEN_GdkWindow_((GdkWindow*)((XEN_TO_C_GdkEventExpose_(ptr))->window)));
  if (XEN_GdkEventNoExpose__P(ptr)) return(C_TO_XEN_GdkWindow_((GdkWindow*)((XEN_TO_C_GdkEventNoExpose_(ptr))->window)));
  if (XEN_GdkEventVisibility__P(ptr)) return(C_TO_XEN_GdkWindow_((GdkWindow*)((XEN_TO_C_GdkEventVisibility_(ptr))->window)));
  if (XEN_GdkEventMotion__P(ptr)) return(C_TO_XEN_GdkWindow_((GdkWindow*)((XEN_TO_C_GdkEventMotion_(ptr))->window)));
  if (XEN_GdkEventButton__P(ptr)) return(C_TO_XEN_GdkWindow_((GdkWindow*)((XEN_TO_C_GdkEventButton_(ptr))->window)));
  if (XEN_GdkEventScroll__P(ptr)) return(C_TO_XEN_GdkWindow_((GdkWindow*)((XEN_TO_C_GdkEventScroll_(ptr))->window)));
  if (XEN_GdkEventKey__P(ptr)) return(C_TO_XEN_GdkWindow_((GdkWindow*)((XEN_TO_C_GdkEventKey_(ptr))->window)));
  if (XEN_GdkEventCrossing__P(ptr)) return(C_TO_XEN_GdkWindow_((GdkWindow*)((XEN_TO_C_GdkEventCrossing_(ptr))->window)));
  if (XEN_GdkEventFocus__P(ptr)) return(C_TO_XEN_GdkWindow_((GdkWindow*)((XEN_TO_C_GdkEventFocus_(ptr))->window)));
  if (XEN_GdkEventConfigure__P(ptr)) return(C_TO_XEN_GdkWindow_((GdkWindow*)((XEN_TO_C_GdkEventConfigure_(ptr))->window)));
  if (XEN_GdkEventProperty__P(ptr)) return(C_TO_XEN_GdkWindow_((GdkWindow*)((XEN_TO_C_GdkEventProperty_(ptr))->window)));
  if (XEN_GdkEventSelection__P(ptr)) return(C_TO_XEN_GdkWindow_((GdkWindow*)((XEN_TO_C_GdkEventSelection_(ptr))->window)));
  if (XEN_GdkEventProximity__P(ptr)) return(C_TO_XEN_GdkWindow_((GdkWindow*)((XEN_TO_C_GdkEventProximity_(ptr))->window)));
  if (XEN_GdkEventSetting__P(ptr)) return(C_TO_XEN_GdkWindow_((GdkWindow*)((XEN_TO_C_GdkEventSetting_(ptr))->window)));
  if (XEN_GdkEventWindowState__P(ptr)) return(C_TO_XEN_GdkWindow_((GdkWindow*)((XEN_TO_C_GdkEventWindowState_(ptr))->window)));
  if (XEN_GdkEventDND__P(ptr)) return(C_TO_XEN_GdkWindow_((GdkWindow*)((XEN_TO_C_GdkEventDND_(ptr))->window)));
  if (XEN_GtkWidget__P(ptr)) return(C_TO_XEN_GdkWindow_((GdkWindow*)((XEN_TO_C_GtkWidget_(ptr))->window)));
  XEN_ASSERT_TYPE(0, ptr, XEN_ONLY_ARG, "window", "pointer to struct with window field");
}

gxg_static XEN gxg_send_event(XEN ptr)
{
  if (XEN_GdkEventAny__P(ptr)) return(C_TO_XEN_gint8((gint8)((XEN_TO_C_GdkEventAny_(ptr))->send_event)));
  if (XEN_GdkEventExpose__P(ptr)) return(C_TO_XEN_gint8((gint8)((XEN_TO_C_GdkEventExpose_(ptr))->send_event)));
  if (XEN_GdkEventNoExpose__P(ptr)) return(C_TO_XEN_gint8((gint8)((XEN_TO_C_GdkEventNoExpose_(ptr))->send_event)));
  if (XEN_GdkEventVisibility__P(ptr)) return(C_TO_XEN_gint8((gint8)((XEN_TO_C_GdkEventVisibility_(ptr))->send_event)));
  if (XEN_GdkEventMotion__P(ptr)) return(C_TO_XEN_gint8((gint8)((XEN_TO_C_GdkEventMotion_(ptr))->send_event)));
  if (XEN_GdkEventButton__P(ptr)) return(C_TO_XEN_gint8((gint8)((XEN_TO_C_GdkEventButton_(ptr))->send_event)));
  if (XEN_GdkEventScroll__P(ptr)) return(C_TO_XEN_gint8((gint8)((XEN_TO_C_GdkEventScroll_(ptr))->send_event)));
  if (XEN_GdkEventKey__P(ptr)) return(C_TO_XEN_gint8((gint8)((XEN_TO_C_GdkEventKey_(ptr))->send_event)));
  if (XEN_GdkEventCrossing__P(ptr)) return(C_TO_XEN_gint8((gint8)((XEN_TO_C_GdkEventCrossing_(ptr))->send_event)));
  if (XEN_GdkEventFocus__P(ptr)) return(C_TO_XEN_gint8((gint8)((XEN_TO_C_GdkEventFocus_(ptr))->send_event)));
  if (XEN_GdkEventConfigure__P(ptr)) return(C_TO_XEN_gint8((gint8)((XEN_TO_C_GdkEventConfigure_(ptr))->send_event)));
  if (XEN_GdkEventProperty__P(ptr)) return(C_TO_XEN_gint8((gint8)((XEN_TO_C_GdkEventProperty_(ptr))->send_event)));
  if (XEN_GdkEventSelection__P(ptr)) return(C_TO_XEN_gint8((gint8)((XEN_TO_C_GdkEventSelection_(ptr))->send_event)));
  if (XEN_GdkEventProximity__P(ptr)) return(C_TO_XEN_gint8((gint8)((XEN_TO_C_GdkEventProximity_(ptr))->send_event)));
  if (XEN_GdkEventSetting__P(ptr)) return(C_TO_XEN_gint8((gint8)((XEN_TO_C_GdkEventSetting_(ptr))->send_event)));
  if (XEN_GdkEventWindowState__P(ptr)) return(C_TO_XEN_gint8((gint8)((XEN_TO_C_GdkEventWindowState_(ptr))->send_event)));
  if (XEN_GdkEventDND__P(ptr)) return(C_TO_XEN_gint8((gint8)((XEN_TO_C_GdkEventDND_(ptr))->send_event)));
  XEN_ASSERT_TYPE(0, ptr, XEN_ONLY_ARG, "send_event", "pointer to struct with send_event field");
}

static XEN gxg_region(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkEventExpose__P(ptr), ptr, XEN_ONLY_ARG, "region", "GdkEventExpose");
  return(C_TO_XEN_GdkRegion_((GdkRegion*)((XEN_TO_C_GdkEventExpose_(ptr))->region)));
}

gxg_static XEN gxg_count(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkEventExpose__P(ptr), ptr, XEN_ONLY_ARG, "count", "GdkEventExpose");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkEventExpose_(ptr))->count)));
}

gxg_static XEN gxg_state(XEN ptr)
{
  if (XEN_GdkEventVisibility__P(ptr)) return(C_TO_XEN_GdkVisibilityState((GdkVisibilityState)((XEN_TO_C_GdkEventVisibility_(ptr))->state)));
  if (XEN_GdkEventMotion__P(ptr)) return(C_TO_XEN_guint((guint)((XEN_TO_C_GdkEventMotion_(ptr))->state)));
  if (XEN_GdkEventButton__P(ptr)) return(C_TO_XEN_guint((guint)((XEN_TO_C_GdkEventButton_(ptr))->state)));
  if (XEN_GdkEventScroll__P(ptr)) return(C_TO_XEN_guint((guint)((XEN_TO_C_GdkEventScroll_(ptr))->state)));
  if (XEN_GdkEventKey__P(ptr)) return(C_TO_XEN_guint((guint)((XEN_TO_C_GdkEventKey_(ptr))->state)));
  if (XEN_GdkEventCrossing__P(ptr)) return(C_TO_XEN_guint((guint)((XEN_TO_C_GdkEventCrossing_(ptr))->state)));
  if (XEN_GdkEventProperty__P(ptr)) return(C_TO_XEN_guint((guint)((XEN_TO_C_GdkEventProperty_(ptr))->state)));
  if (XEN_GtkWidget__P(ptr)) return(C_TO_XEN_guint8((guint8)((XEN_TO_C_GtkWidget_(ptr))->state)));
  XEN_ASSERT_TYPE(0, ptr, XEN_ONLY_ARG, "state", "pointer to struct with state field");
}

gxg_static XEN gxg_time(XEN ptr)
{
  if (XEN_GdkEventMotion__P(ptr)) return(C_TO_XEN_guint32((guint32)((XEN_TO_C_GdkEventMotion_(ptr))->time)));
  if (XEN_GdkEventButton__P(ptr)) return(C_TO_XEN_guint32((guint32)((XEN_TO_C_GdkEventButton_(ptr))->time)));
  if (XEN_GdkEventScroll__P(ptr)) return(C_TO_XEN_guint32((guint32)((XEN_TO_C_GdkEventScroll_(ptr))->time)));
  if (XEN_GdkEventKey__P(ptr)) return(C_TO_XEN_guint32((guint32)((XEN_TO_C_GdkEventKey_(ptr))->time)));
  if (XEN_GdkEventCrossing__P(ptr)) return(C_TO_XEN_guint32((guint32)((XEN_TO_C_GdkEventCrossing_(ptr))->time)));
  if (XEN_GdkEventProperty__P(ptr)) return(C_TO_XEN_guint32((guint32)((XEN_TO_C_GdkEventProperty_(ptr))->time)));
  if (XEN_GdkEventSelection__P(ptr)) return(C_TO_XEN_guint32((guint32)((XEN_TO_C_GdkEventSelection_(ptr))->time)));
  if (XEN_GdkEventProximity__P(ptr)) return(C_TO_XEN_guint32((guint32)((XEN_TO_C_GdkEventProximity_(ptr))->time)));
  if (XEN_GdkEventDND__P(ptr)) return(C_TO_XEN_guint32((guint32)((XEN_TO_C_GdkEventDND_(ptr))->time)));
  XEN_ASSERT_TYPE(0, ptr, XEN_ONLY_ARG, "time", "pointer to struct with time field");
}

gxg_static XEN gxg_x(XEN ptr)
{
  if (XEN_GdkEventMotion__P(ptr)) return(C_TO_XEN_gdouble((gdouble)((XEN_TO_C_GdkEventMotion_(ptr))->x)));
  if (XEN_GdkEventButton__P(ptr)) return(C_TO_XEN_gdouble((gdouble)((XEN_TO_C_GdkEventButton_(ptr))->x)));
  if (XEN_GdkEventScroll__P(ptr)) return(C_TO_XEN_gdouble((gdouble)((XEN_TO_C_GdkEventScroll_(ptr))->x)));
  if (XEN_GdkEventCrossing__P(ptr)) return(C_TO_XEN_gdouble((gdouble)((XEN_TO_C_GdkEventCrossing_(ptr))->x)));
  if (XEN_GdkEventConfigure__P(ptr)) return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkEventConfigure_(ptr))->x)));
  if (XEN_GdkPoint__P(ptr)) return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkPoint_(ptr))->x)));
  if (XEN_GdkRectangle__P(ptr)) return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkRectangle_(ptr))->x)));
  if (XEN_GdkWindowAttr__P(ptr)) return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkWindowAttr_(ptr))->x)));
  XEN_ASSERT_TYPE(0, ptr, XEN_ONLY_ARG, "x", "pointer to struct with x field");
}

gxg_static XEN gxg_y(XEN ptr)
{
  if (XEN_GdkEventMotion__P(ptr)) return(C_TO_XEN_gdouble((gdouble)((XEN_TO_C_GdkEventMotion_(ptr))->y)));
  if (XEN_GdkEventButton__P(ptr)) return(C_TO_XEN_gdouble((gdouble)((XEN_TO_C_GdkEventButton_(ptr))->y)));
  if (XEN_GdkEventScroll__P(ptr)) return(C_TO_XEN_gdouble((gdouble)((XEN_TO_C_GdkEventScroll_(ptr))->y)));
  if (XEN_GdkEventCrossing__P(ptr)) return(C_TO_XEN_gdouble((gdouble)((XEN_TO_C_GdkEventCrossing_(ptr))->y)));
  if (XEN_GdkEventConfigure__P(ptr)) return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkEventConfigure_(ptr))->y)));
  if (XEN_GdkPoint__P(ptr)) return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkPoint_(ptr))->y)));
  if (XEN_GdkRectangle__P(ptr)) return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkRectangle_(ptr))->y)));
  if (XEN_GdkWindowAttr__P(ptr)) return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkWindowAttr_(ptr))->y)));
  XEN_ASSERT_TYPE(0, ptr, XEN_ONLY_ARG, "y", "pointer to struct with y field");
}

static XEN gxg_axes(XEN ptr)
{
  if (XEN_GdkEventMotion__P(ptr)) return(C_TO_XEN_gdouble_((gdouble*)((XEN_TO_C_GdkEventMotion_(ptr))->axes)));
  if (XEN_GdkEventButton__P(ptr)) return(C_TO_XEN_gdouble_((gdouble*)((XEN_TO_C_GdkEventButton_(ptr))->axes)));
  if (XEN_GdkDevice__P(ptr)) return(C_TO_XEN_GdkDeviceAxis_((GdkDeviceAxis*)((XEN_TO_C_GdkDevice_(ptr))->axes)));
  XEN_ASSERT_TYPE(0, ptr, XEN_ONLY_ARG, "axes", "pointer to struct with axes field");
}

gxg_static XEN gxg_is_hint(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkEventMotion__P(ptr), ptr, XEN_ONLY_ARG, "is_hint", "GdkEventMotion");
  return(C_TO_XEN_gint16((gint16)((XEN_TO_C_GdkEventMotion_(ptr))->is_hint)));
}

static XEN gxg_device(XEN ptr)
{
  if (XEN_GdkEventMotion__P(ptr)) return(C_TO_XEN_GdkDevice_((GdkDevice*)((XEN_TO_C_GdkEventMotion_(ptr))->device)));
  if (XEN_GdkEventButton__P(ptr)) return(C_TO_XEN_GdkDevice_((GdkDevice*)((XEN_TO_C_GdkEventButton_(ptr))->device)));
  if (XEN_GdkEventScroll__P(ptr)) return(C_TO_XEN_GdkDevice_((GdkDevice*)((XEN_TO_C_GdkEventScroll_(ptr))->device)));
  if (XEN_GdkEventProximity__P(ptr)) return(C_TO_XEN_GdkDevice_((GdkDevice*)((XEN_TO_C_GdkEventProximity_(ptr))->device)));
  XEN_ASSERT_TYPE(0, ptr, XEN_ONLY_ARG, "device", "pointer to struct with device field");
}

gxg_static XEN gxg_x_root(XEN ptr)
{
  if (XEN_GdkEventMotion__P(ptr)) return(C_TO_XEN_gdouble((gdouble)((XEN_TO_C_GdkEventMotion_(ptr))->x_root)));
  if (XEN_GdkEventButton__P(ptr)) return(C_TO_XEN_gdouble((gdouble)((XEN_TO_C_GdkEventButton_(ptr))->x_root)));
  if (XEN_GdkEventScroll__P(ptr)) return(C_TO_XEN_gdouble((gdouble)((XEN_TO_C_GdkEventScroll_(ptr))->x_root)));
  if (XEN_GdkEventCrossing__P(ptr)) return(C_TO_XEN_gdouble((gdouble)((XEN_TO_C_GdkEventCrossing_(ptr))->x_root)));
  if (XEN_GdkEventDND__P(ptr)) return(C_TO_XEN_gshort((gshort)((XEN_TO_C_GdkEventDND_(ptr))->x_root)));
  XEN_ASSERT_TYPE(0, ptr, XEN_ONLY_ARG, "x_root", "pointer to struct with x_root field");
}

gxg_static XEN gxg_y_root(XEN ptr)
{
  if (XEN_GdkEventMotion__P(ptr)) return(C_TO_XEN_gdouble((gdouble)((XEN_TO_C_GdkEventMotion_(ptr))->y_root)));
  if (XEN_GdkEventButton__P(ptr)) return(C_TO_XEN_gdouble((gdouble)((XEN_TO_C_GdkEventButton_(ptr))->y_root)));
  if (XEN_GdkEventScroll__P(ptr)) return(C_TO_XEN_gdouble((gdouble)((XEN_TO_C_GdkEventScroll_(ptr))->y_root)));
  if (XEN_GdkEventCrossing__P(ptr)) return(C_TO_XEN_gdouble((gdouble)((XEN_TO_C_GdkEventCrossing_(ptr))->y_root)));
  if (XEN_GdkEventDND__P(ptr)) return(C_TO_XEN_gshort((gshort)((XEN_TO_C_GdkEventDND_(ptr))->y_root)));
  XEN_ASSERT_TYPE(0, ptr, XEN_ONLY_ARG, "y_root", "pointer to struct with y_root field");
}

gxg_static XEN gxg_button(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkEventButton__P(ptr), ptr, XEN_ONLY_ARG, "button", "GdkEventButton");
  return(C_TO_XEN_guint((guint)((XEN_TO_C_GdkEventButton_(ptr))->button)));
}

static XEN gxg_direction(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkEventScroll__P(ptr), ptr, XEN_ONLY_ARG, "direction", "GdkEventScroll");
  return(C_TO_XEN_GdkScrollDirection((GdkScrollDirection)((XEN_TO_C_GdkEventScroll_(ptr))->direction)));
}

static XEN gxg_keyval(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkEventKey__P(ptr), ptr, XEN_ONLY_ARG, "keyval", "GdkEventKey");
  return(C_TO_XEN_guint((guint)((XEN_TO_C_GdkEventKey_(ptr))->keyval)));
}

static XEN gxg_length(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkEventKey__P(ptr), ptr, XEN_ONLY_ARG, "length", "GdkEventKey");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkEventKey_(ptr))->length)));
}

static XEN gxg_string(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkEventKey__P(ptr), ptr, XEN_ONLY_ARG, "string", "GdkEventKey");
  return(C_TO_XEN_gchar_((gchar*)((XEN_TO_C_GdkEventKey_(ptr))->string)));
}

static XEN gxg_hardware_keycode(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkEventKey__P(ptr), ptr, XEN_ONLY_ARG, "hardware_keycode", "GdkEventKey");
  return(C_TO_XEN_guint16((guint16)((XEN_TO_C_GdkEventKey_(ptr))->hardware_keycode)));
}

static XEN gxg_group(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkEventKey__P(ptr) || XEN_GdkKeymapKey__P(ptr), ptr, XEN_ONLY_ARG, "group", "GdkEventKey" " or " "GdkKeymapKey");
  if (XEN_GdkEventKey__P(ptr)) return(C_TO_XEN_guint8((guint8)((XEN_TO_C_GdkEventKey_(ptr))->group)));
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkKeymapKey_(ptr))->group)));
}

gxg_static XEN gxg_subwindow(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkEventCrossing__P(ptr), ptr, XEN_ONLY_ARG, "subwindow", "GdkEventCrossing");
  return(C_TO_XEN_GdkWindow_((GdkWindow*)((XEN_TO_C_GdkEventCrossing_(ptr))->subwindow)));
}

gxg_static XEN gxg_mode(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkEventCrossing__P(ptr) || XEN_GdkDevice__P(ptr), ptr, XEN_ONLY_ARG, "mode", "GdkEventCrossing" " or " "GdkDevice");
  if (XEN_GdkEventCrossing__P(ptr)) return(C_TO_XEN_GdkCrossingMode((GdkCrossingMode)((XEN_TO_C_GdkEventCrossing_(ptr))->mode)));
  return(C_TO_XEN_GdkInputMode((GdkInputMode)((XEN_TO_C_GdkDevice_(ptr))->mode)));
}

gxg_static XEN gxg_detail(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkEventCrossing__P(ptr), ptr, XEN_ONLY_ARG, "detail", "GdkEventCrossing");
  return(C_TO_XEN_GdkNotifyType((GdkNotifyType)((XEN_TO_C_GdkEventCrossing_(ptr))->detail)));
}

gxg_static XEN gxg_focus(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkEventCrossing__P(ptr), ptr, XEN_ONLY_ARG, "focus", "GdkEventCrossing");
  return(C_TO_XEN_gboolean((gboolean)((XEN_TO_C_GdkEventCrossing_(ptr))->focus)));
}

static XEN gxg_in(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkEventFocus__P(ptr), ptr, XEN_ONLY_ARG, "in", "GdkEventFocus");
  return(C_TO_XEN_gint16((gint16)((XEN_TO_C_GdkEventFocus_(ptr))->in)));
}

gxg_static XEN gxg_width(XEN ptr)
{
  if (XEN_GdkEventConfigure__P(ptr)) return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkEventConfigure_(ptr))->width)));
  if (XEN_GdkImage__P(ptr)) return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkImage_(ptr))->width)));
  if (XEN_GdkRectangle__P(ptr)) return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkRectangle_(ptr))->width)));
  if (XEN_GdkWindowAttr__P(ptr)) return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkWindowAttr_(ptr))->width)));
  if (XEN_GtkRequisition__P(ptr)) return(C_TO_XEN_gint((gint)((XEN_TO_C_GtkRequisition_(ptr))->width)));
  XEN_ASSERT_TYPE(0, ptr, XEN_ONLY_ARG, "width", "pointer to struct with width field");
}

gxg_static XEN gxg_height(XEN ptr)
{
  if (XEN_GdkEventConfigure__P(ptr)) return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkEventConfigure_(ptr))->height)));
  if (XEN_GdkImage__P(ptr)) return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkImage_(ptr))->height)));
  if (XEN_GdkRectangle__P(ptr)) return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkRectangle_(ptr))->height)));
  if (XEN_GdkWindowAttr__P(ptr)) return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkWindowAttr_(ptr))->height)));
  if (XEN_GtkRequisition__P(ptr)) return(C_TO_XEN_gint((gint)((XEN_TO_C_GtkRequisition_(ptr))->height)));
  XEN_ASSERT_TYPE(0, ptr, XEN_ONLY_ARG, "height", "pointer to struct with height field");
}

gxg_static XEN gxg_atom(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkEventProperty__P(ptr), ptr, XEN_ONLY_ARG, "atom", "GdkEventProperty");
  return(C_TO_XEN_GdkAtom((GdkAtom)((XEN_TO_C_GdkEventProperty_(ptr))->atom)));
}

gxg_static XEN gxg_selection(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkEventSelection__P(ptr), ptr, XEN_ONLY_ARG, "selection", "GdkEventSelection");
  return(C_TO_XEN_GdkAtom((GdkAtom)((XEN_TO_C_GdkEventSelection_(ptr))->selection)));
}

gxg_static XEN gxg_target(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkEventSelection__P(ptr), ptr, XEN_ONLY_ARG, "target", "GdkEventSelection");
  return(C_TO_XEN_GdkAtom((GdkAtom)((XEN_TO_C_GdkEventSelection_(ptr))->target)));
}

gxg_static XEN gxg_property(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkEventSelection__P(ptr), ptr, XEN_ONLY_ARG, "property", "GdkEventSelection");
  return(C_TO_XEN_GdkAtom((GdkAtom)((XEN_TO_C_GdkEventSelection_(ptr))->property)));
}

gxg_static XEN gxg_requestor(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkEventSelection__P(ptr), ptr, XEN_ONLY_ARG, "requestor", "GdkEventSelection");
  return(C_TO_XEN_GdkNativeWindow((GdkNativeWindow)((XEN_TO_C_GdkEventSelection_(ptr))->requestor)));
}

gxg_static XEN gxg_name(XEN ptr)
{
  if (XEN_GdkEventSetting__P(ptr)) return(C_TO_XEN_char_((char*)((XEN_TO_C_GdkEventSetting_(ptr))->name)));
  if (XEN_GdkDevice__P(ptr)) return(C_TO_XEN_gchar_((gchar*)((XEN_TO_C_GdkDevice_(ptr))->name)));
  if (XEN_GtkWidget__P(ptr)) return(C_TO_XEN_gchar_((gchar*)((XEN_TO_C_GtkWidget_(ptr))->name)));
  XEN_ASSERT_TYPE(0, ptr, XEN_ONLY_ARG, "name", "pointer to struct with name field");
}

static XEN gxg_changed_mask(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkEventWindowState__P(ptr), ptr, XEN_ONLY_ARG, "changed_mask", "GdkEventWindowState");
  return(C_TO_XEN_GdkWindowState((GdkWindowState)((XEN_TO_C_GdkEventWindowState_(ptr))->changed_mask)));
}

static XEN gxg_new_window_state(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkEventWindowState__P(ptr), ptr, XEN_ONLY_ARG, "new_window_state", "GdkEventWindowState");
  return(C_TO_XEN_GdkWindowState((GdkWindowState)((XEN_TO_C_GdkEventWindowState_(ptr))->new_window_state)));
}

static XEN gxg_context(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkEventDND__P(ptr), ptr, XEN_ONLY_ARG, "context", "GdkEventDND");
  return(C_TO_XEN_GdkDragContext_((GdkDragContext*)((XEN_TO_C_GdkEventDND_(ptr))->context)));
}

gxg_static XEN gxg_function(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkGCValues__P(ptr), ptr, XEN_ONLY_ARG, "function", "GdkGCValues");
  return(C_TO_XEN_GdkFunction((GdkFunction)((XEN_TO_C_GdkGCValues_(ptr))->function)));
}

static XEN gxg_fill(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkGCValues__P(ptr), ptr, XEN_ONLY_ARG, "fill", "GdkGCValues");
  return(C_TO_XEN_GdkFill((GdkFill)((XEN_TO_C_GdkGCValues_(ptr))->fill)));
}

gxg_static XEN gxg_tile(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkGCValues__P(ptr), ptr, XEN_ONLY_ARG, "tile", "GdkGCValues");
  return(C_TO_XEN_GdkPixmap_((GdkPixmap*)((XEN_TO_C_GdkGCValues_(ptr))->tile)));
}

gxg_static XEN gxg_stipple(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkGCValues__P(ptr), ptr, XEN_ONLY_ARG, "stipple", "GdkGCValues");
  return(C_TO_XEN_GdkPixmap_((GdkPixmap*)((XEN_TO_C_GdkGCValues_(ptr))->stipple)));
}

gxg_static XEN gxg_clip_mask(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkGCValues__P(ptr), ptr, XEN_ONLY_ARG, "clip_mask", "GdkGCValues");
  return(C_TO_XEN_GdkPixmap_((GdkPixmap*)((XEN_TO_C_GdkGCValues_(ptr))->clip_mask)));
}

gxg_static XEN gxg_subwindow_mode(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkGCValues__P(ptr), ptr, XEN_ONLY_ARG, "subwindow_mode", "GdkGCValues");
  return(C_TO_XEN_GdkSubwindowMode((GdkSubwindowMode)((XEN_TO_C_GdkGCValues_(ptr))->subwindow_mode)));
}

gxg_static XEN gxg_ts_x_origin(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkGCValues__P(ptr) || XEN_GdkGC__P(ptr), ptr, XEN_ONLY_ARG, "ts_x_origin", "GdkGCValues" " or " "GdkGC");
  if (XEN_GdkGCValues__P(ptr)) return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkGCValues_(ptr))->ts_x_origin)));
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkGC_(ptr))->ts_x_origin)));
}

gxg_static XEN gxg_ts_y_origin(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkGCValues__P(ptr) || XEN_GdkGC__P(ptr), ptr, XEN_ONLY_ARG, "ts_y_origin", "GdkGCValues" " or " "GdkGC");
  if (XEN_GdkGCValues__P(ptr)) return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkGCValues_(ptr))->ts_y_origin)));
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkGC_(ptr))->ts_y_origin)));
}

gxg_static XEN gxg_clip_x_origin(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkGCValues__P(ptr) || XEN_GdkGC__P(ptr), ptr, XEN_ONLY_ARG, "clip_x_origin", "GdkGCValues" " or " "GdkGC");
  if (XEN_GdkGCValues__P(ptr)) return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkGCValues_(ptr))->clip_x_origin)));
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkGC_(ptr))->clip_x_origin)));
}

gxg_static XEN gxg_clip_y_origin(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkGCValues__P(ptr) || XEN_GdkGC__P(ptr), ptr, XEN_ONLY_ARG, "clip_y_origin", "GdkGCValues" " or " "GdkGC");
  if (XEN_GdkGCValues__P(ptr)) return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkGCValues_(ptr))->clip_y_origin)));
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkGC_(ptr))->clip_y_origin)));
}

gxg_static XEN gxg_graphics_exposures(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkGCValues__P(ptr), ptr, XEN_ONLY_ARG, "graphics_exposures", "GdkGCValues");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkGCValues_(ptr))->graphics_exposures)));
}

gxg_static XEN gxg_line_width(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkGCValues__P(ptr), ptr, XEN_ONLY_ARG, "line_width", "GdkGCValues");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkGCValues_(ptr))->line_width)));
}

gxg_static XEN gxg_line_style(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkGCValues__P(ptr), ptr, XEN_ONLY_ARG, "line_style", "GdkGCValues");
  return(C_TO_XEN_GdkLineStyle((GdkLineStyle)((XEN_TO_C_GdkGCValues_(ptr))->line_style)));
}

gxg_static XEN gxg_cap_style(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkGCValues__P(ptr), ptr, XEN_ONLY_ARG, "cap_style", "GdkGCValues");
  return(C_TO_XEN_GdkCapStyle((GdkCapStyle)((XEN_TO_C_GdkGCValues_(ptr))->cap_style)));
}

gxg_static XEN gxg_join_style(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkGCValues__P(ptr), ptr, XEN_ONLY_ARG, "join_style", "GdkGCValues");
  return(C_TO_XEN_GdkJoinStyle((GdkJoinStyle)((XEN_TO_C_GdkGCValues_(ptr))->join_style)));
}

gxg_static XEN gxg_colormap(XEN ptr)
{
  if (XEN_GdkGC__P(ptr)) return(C_TO_XEN_GdkColormap_((GdkColormap*)((XEN_TO_C_GdkGC_(ptr))->colormap)));
  if (XEN_GdkImage__P(ptr)) return(C_TO_XEN_GdkColormap_((GdkColormap*)((XEN_TO_C_GdkImage_(ptr))->colormap)));
  if (XEN_GdkWindowAttr__P(ptr)) return(C_TO_XEN_GdkColormap_((GdkColormap*)((XEN_TO_C_GdkWindowAttr_(ptr))->colormap)));
  if (XEN_GtkStyle__P(ptr)) return(C_TO_XEN_GdkColormap_((GdkColormap*)((XEN_TO_C_GtkStyle_(ptr))->colormap)));
  XEN_ASSERT_TYPE(0, ptr, XEN_ONLY_ARG, "colormap", "pointer to struct with colormap field");
}

gxg_static XEN gxg_byte_order(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkImage__P(ptr) || XEN_GdkVisual__P(ptr), ptr, XEN_ONLY_ARG, "byte_order", "GdkImage" " or " "GdkVisual");
  if (XEN_GdkImage__P(ptr)) return(C_TO_XEN_GdkByteOrder((GdkByteOrder)((XEN_TO_C_GdkImage_(ptr))->byte_order)));
  return(C_TO_XEN_GdkByteOrder((GdkByteOrder)((XEN_TO_C_GdkVisual_(ptr))->byte_order)));
}

gxg_static XEN gxg_depth(XEN ptr)
{
  if (XEN_GdkImage__P(ptr)) return(C_TO_XEN_guint16((guint16)((XEN_TO_C_GdkImage_(ptr))->depth)));
  if (XEN_GdkVisual__P(ptr)) return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkVisual_(ptr))->depth)));
  if (XEN_GtkStyle__P(ptr)) return(C_TO_XEN_gint((gint)((XEN_TO_C_GtkStyle_(ptr))->depth)));
  XEN_ASSERT_TYPE(0, ptr, XEN_ONLY_ARG, "depth", "pointer to struct with depth field");
}

static XEN gxg_bpp(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkImage__P(ptr), ptr, XEN_ONLY_ARG, "bpp", "GdkImage");
  return(C_TO_XEN_guint16((guint16)((XEN_TO_C_GdkImage_(ptr))->bpp)));
}

static XEN gxg_bpl(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkImage__P(ptr), ptr, XEN_ONLY_ARG, "bpl", "GdkImage");
  return(C_TO_XEN_guint16((guint16)((XEN_TO_C_GdkImage_(ptr))->bpl)));
}

gxg_static XEN gxg_bits_per_pixel(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkImage__P(ptr), ptr, XEN_ONLY_ARG, "bits_per_pixel", "GdkImage");
  return(C_TO_XEN_guint16((guint16)((XEN_TO_C_GdkImage_(ptr))->bits_per_pixel)));
}

static XEN gxg_mem(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkImage__P(ptr), ptr, XEN_ONLY_ARG, "mem", "GdkImage");
  return(C_TO_XEN_gpointer((gpointer)((XEN_TO_C_GdkImage_(ptr))->mem)));
}

static XEN gxg_source(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkDevice__P(ptr), ptr, XEN_ONLY_ARG, "source", "GdkDevice");
  return(C_TO_XEN_GdkInputSource((GdkInputSource)((XEN_TO_C_GdkDevice_(ptr))->source)));
}

static XEN gxg_has_cursor(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkDevice__P(ptr), ptr, XEN_ONLY_ARG, "has_cursor", "GdkDevice");
  return(C_TO_XEN_gboolean((gboolean)((XEN_TO_C_GdkDevice_(ptr))->has_cursor)));
}

static XEN gxg_num_axes(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkDevice__P(ptr), ptr, XEN_ONLY_ARG, "num_axes", "GdkDevice");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkDevice_(ptr))->num_axes)));
}

static XEN gxg_num_keys(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkDevice__P(ptr), ptr, XEN_ONLY_ARG, "num_keys", "GdkDevice");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkDevice_(ptr))->num_keys)));
}

static XEN gxg_keys(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkDevice__P(ptr), ptr, XEN_ONLY_ARG, "keys", "GdkDevice");
  return(C_TO_XEN_GdkDeviceKey_((GdkDeviceKey*)((XEN_TO_C_GdkDevice_(ptr))->keys)));
}

gxg_static XEN gxg_keycode(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkKeymapKey__P(ptr), ptr, XEN_ONLY_ARG, "keycode", "GdkKeymapKey");
  return(C_TO_XEN_guint((guint)((XEN_TO_C_GdkKeymapKey_(ptr))->keycode)));
}

static XEN gxg_level(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkKeymapKey__P(ptr), ptr, XEN_ONLY_ARG, "level", "GdkKeymapKey");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkKeymapKey_(ptr))->level)));
}

static XEN gxg_n_colors(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkRgbCmap__P(ptr), ptr, XEN_ONLY_ARG, "n_colors", "GdkRgbCmap");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkRgbCmap_(ptr))->n_colors)));
}

static XEN gxg_info_list(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkRgbCmap__P(ptr), ptr, XEN_ONLY_ARG, "info_list", "GdkRgbCmap");
  return(C_TO_XEN_GSList_((GSList*)((XEN_TO_C_GdkRgbCmap_(ptr))->info_list)));
}

gxg_static XEN gxg_colormap_size(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkVisual__P(ptr), ptr, XEN_ONLY_ARG, "colormap_size", "GdkVisual");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkVisual_(ptr))->colormap_size)));
}

gxg_static XEN gxg_bits_per_rgb(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkVisual__P(ptr), ptr, XEN_ONLY_ARG, "bits_per_rgb", "GdkVisual");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkVisual_(ptr))->bits_per_rgb)));
}

gxg_static XEN gxg_red_mask(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkVisual__P(ptr), ptr, XEN_ONLY_ARG, "red_mask", "GdkVisual");
  return(C_TO_XEN_guint32((guint32)((XEN_TO_C_GdkVisual_(ptr))->red_mask)));
}

static XEN gxg_red_shift(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkVisual__P(ptr), ptr, XEN_ONLY_ARG, "red_shift", "GdkVisual");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkVisual_(ptr))->red_shift)));
}

static XEN gxg_red_prec(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkVisual__P(ptr), ptr, XEN_ONLY_ARG, "red_prec", "GdkVisual");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkVisual_(ptr))->red_prec)));
}

gxg_static XEN gxg_green_mask(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkVisual__P(ptr), ptr, XEN_ONLY_ARG, "green_mask", "GdkVisual");
  return(C_TO_XEN_guint32((guint32)((XEN_TO_C_GdkVisual_(ptr))->green_mask)));
}

static XEN gxg_green_shift(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkVisual__P(ptr), ptr, XEN_ONLY_ARG, "green_shift", "GdkVisual");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkVisual_(ptr))->green_shift)));
}

static XEN gxg_green_prec(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkVisual__P(ptr), ptr, XEN_ONLY_ARG, "green_prec", "GdkVisual");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkVisual_(ptr))->green_prec)));
}

gxg_static XEN gxg_blue_mask(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkVisual__P(ptr), ptr, XEN_ONLY_ARG, "blue_mask", "GdkVisual");
  return(C_TO_XEN_guint32((guint32)((XEN_TO_C_GdkVisual_(ptr))->blue_mask)));
}

static XEN gxg_blue_shift(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkVisual__P(ptr), ptr, XEN_ONLY_ARG, "blue_shift", "GdkVisual");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkVisual_(ptr))->blue_shift)));
}

static XEN gxg_blue_prec(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkVisual__P(ptr), ptr, XEN_ONLY_ARG, "blue_prec", "GdkVisual");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkVisual_(ptr))->blue_prec)));
}

static XEN gxg_title(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkWindowAttr__P(ptr), ptr, XEN_ONLY_ARG, "title", "GdkWindowAttr");
  return(C_TO_XEN_gchar_((gchar*)((XEN_TO_C_GdkWindowAttr_(ptr))->title)));
}

gxg_static XEN gxg_event_mask(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkWindowAttr__P(ptr), ptr, XEN_ONLY_ARG, "event_mask", "GdkWindowAttr");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkWindowAttr_(ptr))->event_mask)));
}

static XEN gxg_window_type(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkWindowAttr__P(ptr), ptr, XEN_ONLY_ARG, "window_type", "GdkWindowAttr");
  return(C_TO_XEN_GdkWindowType((GdkWindowType)((XEN_TO_C_GdkWindowAttr_(ptr))->window_type)));
}

gxg_static XEN gxg_cursor(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkWindowAttr__P(ptr), ptr, XEN_ONLY_ARG, "cursor", "GdkWindowAttr");
  return(C_TO_XEN_GdkCursor_((GdkCursor*)((XEN_TO_C_GdkWindowAttr_(ptr))->cursor)));
}

static XEN gxg_wmclass_name(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkWindowAttr__P(ptr), ptr, XEN_ONLY_ARG, "wmclass_name", "GdkWindowAttr");
  return(C_TO_XEN_gchar_((gchar*)((XEN_TO_C_GdkWindowAttr_(ptr))->wmclass_name)));
}

static XEN gxg_wmclass_class(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkWindowAttr__P(ptr), ptr, XEN_ONLY_ARG, "wmclass_class", "GdkWindowAttr");
  return(C_TO_XEN_gchar_((gchar*)((XEN_TO_C_GdkWindowAttr_(ptr))->wmclass_class)));
}

gxg_static XEN gxg_override_redirect(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkWindowAttr__P(ptr), ptr, XEN_ONLY_ARG, "override_redirect", "GdkWindowAttr");
  return(C_TO_XEN_gboolean((gboolean)((XEN_TO_C_GdkWindowAttr_(ptr))->override_redirect)));
}

gxg_static XEN gxg_min_width(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkGeometry__P(ptr), ptr, XEN_ONLY_ARG, "min_width", "GdkGeometry");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkGeometry_(ptr))->min_width)));
}

gxg_static XEN gxg_min_height(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkGeometry__P(ptr), ptr, XEN_ONLY_ARG, "min_height", "GdkGeometry");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkGeometry_(ptr))->min_height)));
}

gxg_static XEN gxg_max_width(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkGeometry__P(ptr), ptr, XEN_ONLY_ARG, "max_width", "GdkGeometry");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkGeometry_(ptr))->max_width)));
}

gxg_static XEN gxg_max_height(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkGeometry__P(ptr), ptr, XEN_ONLY_ARG, "max_height", "GdkGeometry");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkGeometry_(ptr))->max_height)));
}

static XEN gxg_base_width(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkGeometry__P(ptr), ptr, XEN_ONLY_ARG, "base_width", "GdkGeometry");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkGeometry_(ptr))->base_width)));
}

static XEN gxg_base_height(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkGeometry__P(ptr), ptr, XEN_ONLY_ARG, "base_height", "GdkGeometry");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkGeometry_(ptr))->base_height)));
}

gxg_static XEN gxg_width_inc(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkGeometry__P(ptr), ptr, XEN_ONLY_ARG, "width_inc", "GdkGeometry");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkGeometry_(ptr))->width_inc)));
}

gxg_static XEN gxg_height_inc(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkGeometry__P(ptr), ptr, XEN_ONLY_ARG, "height_inc", "GdkGeometry");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GdkGeometry_(ptr))->height_inc)));
}

static XEN gxg_min_aspect(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkGeometry__P(ptr), ptr, XEN_ONLY_ARG, "min_aspect", "GdkGeometry");
  return(C_TO_XEN_gdouble((gdouble)((XEN_TO_C_GdkGeometry_(ptr))->min_aspect)));
}

static XEN gxg_max_aspect(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkGeometry__P(ptr), ptr, XEN_ONLY_ARG, "max_aspect", "GdkGeometry");
  return(C_TO_XEN_gdouble((gdouble)((XEN_TO_C_GdkGeometry_(ptr))->max_aspect)));
}

gxg_static XEN gxg_win_gravity(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GdkGeometry__P(ptr), ptr, XEN_ONLY_ARG, "win_gravity", "GdkGeometry");
  return(C_TO_XEN_GdkGravity((GdkGravity)((XEN_TO_C_GdkGeometry_(ptr))->win_gravity)));
}

static XEN gxg_lower(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(ptr), ptr, XEN_ONLY_ARG, "lower", "GtkAdjustment");
  return(C_TO_XEN_gdouble((gdouble)((XEN_TO_C_GtkAdjustment_(ptr))->lower)));
}

static XEN gxg_upper(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(ptr), ptr, XEN_ONLY_ARG, "upper", "GtkAdjustment");
  return(C_TO_XEN_gdouble((gdouble)((XEN_TO_C_GtkAdjustment_(ptr))->upper)));
}

static XEN gxg_step_increment(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(ptr), ptr, XEN_ONLY_ARG, "step_increment", "GtkAdjustment");
  return(C_TO_XEN_gdouble((gdouble)((XEN_TO_C_GtkAdjustment_(ptr))->step_increment)));
}

static XEN gxg_page_increment(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(ptr), ptr, XEN_ONLY_ARG, "page_increment", "GtkAdjustment");
  return(C_TO_XEN_gdouble((gdouble)((XEN_TO_C_GtkAdjustment_(ptr))->page_increment)));
}

static XEN gxg_page_size(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(ptr), ptr, XEN_ONLY_ARG, "page_size", "GtkAdjustment");
  return(C_TO_XEN_gdouble((gdouble)((XEN_TO_C_GtkAdjustment_(ptr))->page_size)));
}

static XEN gxg_colorsel(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkColorSelectionDialog__P(ptr), ptr, XEN_ONLY_ARG, "colorsel", "GtkColorSelectionDialog");
  return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkColorSelectionDialog_(ptr))->colorsel)));
}

static XEN gxg_ok_button(XEN ptr)
{
  if (XEN_GtkColorSelectionDialog__P(ptr)) return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkColorSelectionDialog_(ptr))->ok_button)));
  if (XEN_GtkFileSelection__P(ptr)) return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkFileSelection_(ptr))->ok_button)));
  if (XEN_GtkFontSelectionDialog__P(ptr)) return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkFontSelectionDialog_(ptr))->ok_button)));
  XEN_ASSERT_TYPE(0, ptr, XEN_ONLY_ARG, "ok_button", "pointer to struct with ok_button field");
}

static XEN gxg_cancel_button(XEN ptr)
{
  if (XEN_GtkColorSelectionDialog__P(ptr)) return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkColorSelectionDialog_(ptr))->cancel_button)));
  if (XEN_GtkFileSelection__P(ptr)) return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkFileSelection_(ptr))->cancel_button)));
  if (XEN_GtkFontSelectionDialog__P(ptr)) return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkFontSelectionDialog_(ptr))->cancel_button)));
  XEN_ASSERT_TYPE(0, ptr, XEN_ONLY_ARG, "cancel_button", "pointer to struct with cancel_button field");
}

static XEN gxg_help_button(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkColorSelectionDialog__P(ptr) || XEN_GtkFileSelection__P(ptr), ptr, XEN_ONLY_ARG, "help_button", "GtkColorSelectionDialog" " or " "GtkFileSelection");
  if (XEN_GtkColorSelectionDialog__P(ptr)) return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkColorSelectionDialog_(ptr))->help_button)));
  return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkFileSelection_(ptr))->help_button)));
}

static XEN gxg_vbox(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkDialog__P(ptr), ptr, XEN_ONLY_ARG, "vbox", "GtkDialog");
  return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkDialog_(ptr))->vbox)));
}

static XEN gxg_action_area(XEN ptr)
{
  if (XEN_GtkDialog__P(ptr)) return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkDialog_(ptr))->action_area)));
  if (XEN_GtkFileSelection__P(ptr)) return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkFileSelection_(ptr))->action_area)));
  if (XEN_GtkFontSelectionDialog__P(ptr)) return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkFontSelectionDialog_(ptr))->action_area)));
  XEN_ASSERT_TYPE(0, ptr, XEN_ONLY_ARG, "action_area", "pointer to struct with action_area field");
}

static XEN gxg_separator(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkDialog__P(ptr), ptr, XEN_ONLY_ARG, "separator", "GtkDialog");
  return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkDialog_(ptr))->separator)));
}

static XEN gxg_dir_list(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkFileSelection__P(ptr), ptr, XEN_ONLY_ARG, "dir_list", "GtkFileSelection");
  return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkFileSelection_(ptr))->dir_list)));
}

static XEN gxg_file_list(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkFileSelection__P(ptr), ptr, XEN_ONLY_ARG, "file_list", "GtkFileSelection");
  return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkFileSelection_(ptr))->file_list)));
}

static XEN gxg_selection_entry(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkFileSelection__P(ptr), ptr, XEN_ONLY_ARG, "selection_entry", "GtkFileSelection");
  return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkFileSelection_(ptr))->selection_entry)));
}

static XEN gxg_selection_text(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkFileSelection__P(ptr), ptr, XEN_ONLY_ARG, "selection_text", "GtkFileSelection");
  return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkFileSelection_(ptr))->selection_text)));
}

static XEN gxg_main_vbox(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkFileSelection__P(ptr) || XEN_GtkFontSelectionDialog__P(ptr), ptr, XEN_ONLY_ARG, "main_vbox", "GtkFileSelection" " or " "GtkFontSelectionDialog");
  if (XEN_GtkFileSelection__P(ptr)) return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkFileSelection_(ptr))->main_vbox)));
  return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkFontSelectionDialog_(ptr))->main_vbox)));
}

static XEN gxg_history_pulldown(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkFileSelection__P(ptr), ptr, XEN_ONLY_ARG, "history_pulldown", "GtkFileSelection");
  return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkFileSelection_(ptr))->history_pulldown)));
}

static XEN gxg_history_menu(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkFileSelection__P(ptr), ptr, XEN_ONLY_ARG, "history_menu", "GtkFileSelection");
  return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkFileSelection_(ptr))->history_menu)));
}

static XEN gxg_history_list(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkFileSelection__P(ptr), ptr, XEN_ONLY_ARG, "history_list", "GtkFileSelection");
  return(C_TO_XEN_GList_((GList*)((XEN_TO_C_GtkFileSelection_(ptr))->history_list)));
}

static XEN gxg_fileop_dialog(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkFileSelection__P(ptr), ptr, XEN_ONLY_ARG, "fileop_dialog", "GtkFileSelection");
  return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkFileSelection_(ptr))->fileop_dialog)));
}

static XEN gxg_fileop_entry(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkFileSelection__P(ptr), ptr, XEN_ONLY_ARG, "fileop_entry", "GtkFileSelection");
  return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkFileSelection_(ptr))->fileop_entry)));
}

static XEN gxg_fileop_file(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkFileSelection__P(ptr), ptr, XEN_ONLY_ARG, "fileop_file", "GtkFileSelection");
  return(C_TO_XEN_gchar_((gchar*)((XEN_TO_C_GtkFileSelection_(ptr))->fileop_file)));
}

static XEN gxg_cmpl_state(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkFileSelection__P(ptr), ptr, XEN_ONLY_ARG, "cmpl_state", "GtkFileSelection");
  return(C_TO_XEN_gpointer((gpointer)((XEN_TO_C_GtkFileSelection_(ptr))->cmpl_state)));
}

static XEN gxg_fileop_c_dir(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkFileSelection__P(ptr), ptr, XEN_ONLY_ARG, "fileop_c_dir", "GtkFileSelection");
  return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkFileSelection_(ptr))->fileop_c_dir)));
}

static XEN gxg_fileop_del_file(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkFileSelection__P(ptr), ptr, XEN_ONLY_ARG, "fileop_del_file", "GtkFileSelection");
  return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkFileSelection_(ptr))->fileop_del_file)));
}

static XEN gxg_fileop_ren_file(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkFileSelection__P(ptr), ptr, XEN_ONLY_ARG, "fileop_ren_file", "GtkFileSelection");
  return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkFileSelection_(ptr))->fileop_ren_file)));
}

static XEN gxg_button_area(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkFileSelection__P(ptr), ptr, XEN_ONLY_ARG, "button_area", "GtkFileSelection");
  return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkFileSelection_(ptr))->button_area)));
}

static XEN gxg_fontsel(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkFontSelectionDialog__P(ptr), ptr, XEN_ONLY_ARG, "fontsel", "GtkFontSelectionDialog");
  return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkFontSelectionDialog_(ptr))->fontsel)));
}

static XEN gxg_apply_button(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkFontSelectionDialog__P(ptr), ptr, XEN_ONLY_ARG, "apply_button", "GtkFontSelectionDialog");
  return(C_TO_XEN_GtkWidget_((GtkWidget*)((XEN_TO_C_GtkFontSelectionDialog_(ptr))->apply_button)));
}

static XEN gxg_dialog_width(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkFontSelectionDialog__P(ptr), ptr, XEN_ONLY_ARG, "dialog_width", "GtkFontSelectionDialog");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GtkFontSelectionDialog_(ptr))->dialog_width)));
}

static XEN gxg_auto_resize(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkFontSelectionDialog__P(ptr), ptr, XEN_ONLY_ARG, "auto_resize", "GtkFontSelectionDialog");
  return(C_TO_XEN_gboolean((gboolean)((XEN_TO_C_GtkFontSelectionDialog_(ptr))->auto_resize)));
}

static XEN gxg_fg(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(ptr), ptr, XEN_ONLY_ARG, "fg", "GtkStyle");
  return(C_TO_XEN_GdkColor_((GdkColor*)((XEN_TO_C_GtkStyle_(ptr))->fg)));
}

static XEN gxg_bg(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(ptr), ptr, XEN_ONLY_ARG, "bg", "GtkStyle");
  return(C_TO_XEN_GdkColor_((GdkColor*)((XEN_TO_C_GtkStyle_(ptr))->bg)));
}

static XEN gxg_light(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(ptr), ptr, XEN_ONLY_ARG, "light", "GtkStyle");
  return(C_TO_XEN_GdkColor_((GdkColor*)((XEN_TO_C_GtkStyle_(ptr))->light)));
}

static XEN gxg_dark(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(ptr), ptr, XEN_ONLY_ARG, "dark", "GtkStyle");
  return(C_TO_XEN_GdkColor_((GdkColor*)((XEN_TO_C_GtkStyle_(ptr))->dark)));
}

static XEN gxg_mid(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(ptr), ptr, XEN_ONLY_ARG, "mid", "GtkStyle");
  return(C_TO_XEN_GdkColor_((GdkColor*)((XEN_TO_C_GtkStyle_(ptr))->mid)));
}

static XEN gxg_text(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(ptr), ptr, XEN_ONLY_ARG, "text", "GtkStyle");
  return(C_TO_XEN_GdkColor_((GdkColor*)((XEN_TO_C_GtkStyle_(ptr))->text)));
}

static XEN gxg_base(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(ptr), ptr, XEN_ONLY_ARG, "base", "GtkStyle");
  return(C_TO_XEN_GdkColor_((GdkColor*)((XEN_TO_C_GtkStyle_(ptr))->base)));
}

static XEN gxg_text_aa(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(ptr), ptr, XEN_ONLY_ARG, "text_aa", "GtkStyle");
  return(C_TO_XEN_GdkColor_((GdkColor*)((XEN_TO_C_GtkStyle_(ptr))->text_aa)));
}

static XEN gxg_font_desc(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(ptr), ptr, XEN_ONLY_ARG, "font_desc", "GtkStyle");
  return(C_TO_XEN_PangoFontDescription_((PangoFontDescription*)((XEN_TO_C_GtkStyle_(ptr))->font_desc)));
}

static XEN gxg_xthickness(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(ptr), ptr, XEN_ONLY_ARG, "xthickness", "GtkStyle");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GtkStyle_(ptr))->xthickness)));
}

static XEN gxg_ythickness(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(ptr), ptr, XEN_ONLY_ARG, "ythickness", "GtkStyle");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GtkStyle_(ptr))->ythickness)));
}

static XEN gxg_fg_gc(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(ptr), ptr, XEN_ONLY_ARG, "fg_gc", "GtkStyle");
  return(C_TO_XEN_GdkGC__((GdkGC**)((XEN_TO_C_GtkStyle_(ptr))->fg_gc)));
}

static XEN gxg_bg_gc(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(ptr), ptr, XEN_ONLY_ARG, "bg_gc", "GtkStyle");
  return(C_TO_XEN_GdkGC__((GdkGC**)((XEN_TO_C_GtkStyle_(ptr))->bg_gc)));
}

static XEN gxg_light_gc(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(ptr), ptr, XEN_ONLY_ARG, "light_gc", "GtkStyle");
  return(C_TO_XEN_GdkGC__((GdkGC**)((XEN_TO_C_GtkStyle_(ptr))->light_gc)));
}

static XEN gxg_dark_gc(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(ptr), ptr, XEN_ONLY_ARG, "dark_gc", "GtkStyle");
  return(C_TO_XEN_GdkGC__((GdkGC**)((XEN_TO_C_GtkStyle_(ptr))->dark_gc)));
}

static XEN gxg_mid_gc(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(ptr), ptr, XEN_ONLY_ARG, "mid_gc", "GtkStyle");
  return(C_TO_XEN_GdkGC__((GdkGC**)((XEN_TO_C_GtkStyle_(ptr))->mid_gc)));
}

static XEN gxg_text_gc(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(ptr), ptr, XEN_ONLY_ARG, "text_gc", "GtkStyle");
  return(C_TO_XEN_GdkGC__((GdkGC**)((XEN_TO_C_GtkStyle_(ptr))->text_gc)));
}

static XEN gxg_base_gc(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(ptr), ptr, XEN_ONLY_ARG, "base_gc", "GtkStyle");
  return(C_TO_XEN_GdkGC__((GdkGC**)((XEN_TO_C_GtkStyle_(ptr))->base_gc)));
}

static XEN gxg_text_aa_gc(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(ptr), ptr, XEN_ONLY_ARG, "text_aa_gc", "GtkStyle");
  return(C_TO_XEN_GdkGC__((GdkGC**)((XEN_TO_C_GtkStyle_(ptr))->text_aa_gc)));
}

static XEN gxg_black_gc(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(ptr), ptr, XEN_ONLY_ARG, "black_gc", "GtkStyle");
  return(C_TO_XEN_GdkGC_((GdkGC*)((XEN_TO_C_GtkStyle_(ptr))->black_gc)));
}

static XEN gxg_white_gc(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(ptr), ptr, XEN_ONLY_ARG, "white_gc", "GtkStyle");
  return(C_TO_XEN_GdkGC_((GdkGC*)((XEN_TO_C_GtkStyle_(ptr))->white_gc)));
}

static XEN gxg_bg_pixmap(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(ptr), ptr, XEN_ONLY_ARG, "bg_pixmap", "GtkStyle");
  return(C_TO_XEN_GdkPixmap__((GdkPixmap**)((XEN_TO_C_GtkStyle_(ptr))->bg_pixmap)));
}

static XEN gxg_attach_count(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(ptr), ptr, XEN_ONLY_ARG, "attach_count", "GtkStyle");
  return(C_TO_XEN_gint((gint)((XEN_TO_C_GtkStyle_(ptr))->attach_count)));
}

static XEN gxg_rc_style(XEN ptr)
{
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(ptr), ptr, XEN_ONLY_ARG, "rc_style", "GtkStyle");
  return(C_TO_XEN_GtkRcStyle_((GtkRcStyle*)((XEN_TO_C_GtkStyle_(ptr))->rc_style)));
}

