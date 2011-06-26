static XEN gxg_gtk_paned_get_type(void)
{
  #define H_gtk_paned_get_type "GtkType gtk_paned_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_paned_get_type()));
}
static XEN gxg_gtk_paned_add1(XEN paned, XEN child)
{
  #define H_gtk_paned_add1 "void gtk_paned_add1(GtkPaned* paned, GtkWidget* child)"
  XEN_ASSERT_TYPE(XEN_GtkPaned__P(paned), paned, 1, "gtk_paned_add1", "GtkPaned*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_paned_add1", "GtkWidget*");
  gtk_paned_add1(XEN_TO_C_GtkPaned_(paned), XEN_TO_C_GtkWidget_(child));
  return(XEN_FALSE);
}
static XEN gxg_gtk_paned_add2(XEN paned, XEN child)
{
  #define H_gtk_paned_add2 "void gtk_paned_add2(GtkPaned* paned, GtkWidget* child)"
  XEN_ASSERT_TYPE(XEN_GtkPaned__P(paned), paned, 1, "gtk_paned_add2", "GtkPaned*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_paned_add2", "GtkWidget*");
  gtk_paned_add2(XEN_TO_C_GtkPaned_(paned), XEN_TO_C_GtkWidget_(child));
  return(XEN_FALSE);
}
static XEN gxg_gtk_paned_pack1(XEN paned, XEN child, XEN resize, XEN shrink)
{
  #define H_gtk_paned_pack1 "void gtk_paned_pack1(GtkPaned* paned, GtkWidget* child, gboolean resize, \
gboolean shrink)"
  XEN_ASSERT_TYPE(XEN_GtkPaned__P(paned), paned, 1, "gtk_paned_pack1", "GtkPaned*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_paned_pack1", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(resize), resize, 3, "gtk_paned_pack1", "gboolean");
  XEN_ASSERT_TYPE(XEN_gboolean_P(shrink), shrink, 4, "gtk_paned_pack1", "gboolean");
  gtk_paned_pack1(XEN_TO_C_GtkPaned_(paned), XEN_TO_C_GtkWidget_(child), XEN_TO_C_gboolean(resize), XEN_TO_C_gboolean(shrink));
  return(XEN_FALSE);
}
static XEN gxg_gtk_paned_pack2(XEN paned, XEN child, XEN resize, XEN shrink)
{
  #define H_gtk_paned_pack2 "void gtk_paned_pack2(GtkPaned* paned, GtkWidget* child, gboolean resize, \
gboolean shrink)"
  XEN_ASSERT_TYPE(XEN_GtkPaned__P(paned), paned, 1, "gtk_paned_pack2", "GtkPaned*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_paned_pack2", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(resize), resize, 3, "gtk_paned_pack2", "gboolean");
  XEN_ASSERT_TYPE(XEN_gboolean_P(shrink), shrink, 4, "gtk_paned_pack2", "gboolean");
  gtk_paned_pack2(XEN_TO_C_GtkPaned_(paned), XEN_TO_C_GtkWidget_(child), XEN_TO_C_gboolean(resize), XEN_TO_C_gboolean(shrink));
  return(XEN_FALSE);
}
static XEN gxg_gtk_paned_get_position(XEN paned)
{
  #define H_gtk_paned_get_position "gint gtk_paned_get_position(GtkPaned* paned)"
  XEN_ASSERT_TYPE(XEN_GtkPaned__P(paned), paned, 1, "gtk_paned_get_position", "GtkPaned*");
  return(C_TO_XEN_gint(gtk_paned_get_position(XEN_TO_C_GtkPaned_(paned))));
}
static XEN gxg_gtk_paned_set_position(XEN paned, XEN position)
{
  #define H_gtk_paned_set_position "void gtk_paned_set_position(GtkPaned* paned, gint position)"
  XEN_ASSERT_TYPE(XEN_GtkPaned__P(paned), paned, 1, "gtk_paned_set_position", "GtkPaned*");
  XEN_ASSERT_TYPE(XEN_gint_P(position), position, 2, "gtk_paned_set_position", "gint");
  gtk_paned_set_position(XEN_TO_C_GtkPaned_(paned), XEN_TO_C_gint(position));
  return(XEN_FALSE);
}
static XEN gxg_gtk_plug_get_type(void)
{
  #define H_gtk_plug_get_type "GtkType gtk_plug_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_plug_get_type()));
}
static XEN gxg_gtk_plug_construct(XEN plug, XEN socket_id)
{
  #define H_gtk_plug_construct "void gtk_plug_construct(GtkPlug* plug, GdkNativeWindow socket_id)"
  XEN_ASSERT_TYPE(XEN_GtkPlug__P(plug), plug, 1, "gtk_plug_construct", "GtkPlug*");
  XEN_ASSERT_TYPE(XEN_GdkNativeWindow_P(socket_id), socket_id, 2, "gtk_plug_construct", "GdkNativeWindow");
  gtk_plug_construct(XEN_TO_C_GtkPlug_(plug), XEN_TO_C_GdkNativeWindow(socket_id));
  return(XEN_FALSE);
}
static XEN gxg_gtk_plug_new(XEN socket_id)
{
  #define H_gtk_plug_new "GtkWidget* gtk_plug_new(GdkNativeWindow socket_id)"
  XEN_ASSERT_TYPE(XEN_GdkNativeWindow_P(socket_id), socket_id, 1, "gtk_plug_new", "GdkNativeWindow");
  return(C_TO_XEN_GtkWidget_(gtk_plug_new(XEN_TO_C_GdkNativeWindow(socket_id))));
}
static XEN gxg_gtk_plug_get_id(XEN plug)
{
  #define H_gtk_plug_get_id "GdkNativeWindow gtk_plug_get_id(GtkPlug* plug)"
  XEN_ASSERT_TYPE(XEN_GtkPlug__P(plug), plug, 1, "gtk_plug_get_id", "GtkPlug*");
  return(C_TO_XEN_GdkNativeWindow(gtk_plug_get_id(XEN_TO_C_GtkPlug_(plug))));
}
static XEN gxg_gtk_progress_bar_get_type(void)
{
  #define H_gtk_progress_bar_get_type "GtkType gtk_progress_bar_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_progress_bar_get_type()));
}
static XEN gxg_gtk_progress_bar_new(void)
{
  #define H_gtk_progress_bar_new "GtkWidget* gtk_progress_bar_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_progress_bar_new()));
}
static XEN gxg_gtk_progress_bar_pulse(XEN pbar)
{
  #define H_gtk_progress_bar_pulse "void gtk_progress_bar_pulse(GtkProgressBar* pbar)"
  XEN_ASSERT_TYPE(XEN_GtkProgressBar__P(pbar), pbar, 1, "gtk_progress_bar_pulse", "GtkProgressBar*");
  gtk_progress_bar_pulse(XEN_TO_C_GtkProgressBar_(pbar));
  return(XEN_FALSE);
}
static XEN gxg_gtk_progress_bar_set_text(XEN pbar, XEN text)
{
  #define H_gtk_progress_bar_set_text "void gtk_progress_bar_set_text(GtkProgressBar* pbar, gchar* text)"
  XEN_ASSERT_TYPE(XEN_GtkProgressBar__P(pbar), pbar, 1, "gtk_progress_bar_set_text", "GtkProgressBar*");
  XEN_ASSERT_TYPE(XEN_gchar__P(text), text, 2, "gtk_progress_bar_set_text", "gchar*");
  gtk_progress_bar_set_text(XEN_TO_C_GtkProgressBar_(pbar), XEN_TO_C_gchar_(text));
  return(XEN_FALSE);
}
static XEN gxg_gtk_progress_bar_set_fraction(XEN pbar, XEN fraction)
{
  #define H_gtk_progress_bar_set_fraction "void gtk_progress_bar_set_fraction(GtkProgressBar* pbar, gdouble fraction)"
  XEN_ASSERT_TYPE(XEN_GtkProgressBar__P(pbar), pbar, 1, "gtk_progress_bar_set_fraction", "GtkProgressBar*");
  XEN_ASSERT_TYPE(XEN_gdouble_P(fraction), fraction, 2, "gtk_progress_bar_set_fraction", "gdouble");
  gtk_progress_bar_set_fraction(XEN_TO_C_GtkProgressBar_(pbar), XEN_TO_C_gdouble(fraction));
  return(XEN_FALSE);
}
static XEN gxg_gtk_progress_bar_set_pulse_step(XEN pbar, XEN fraction)
{
  #define H_gtk_progress_bar_set_pulse_step "void gtk_progress_bar_set_pulse_step(GtkProgressBar* pbar, \
gdouble fraction)"
  XEN_ASSERT_TYPE(XEN_GtkProgressBar__P(pbar), pbar, 1, "gtk_progress_bar_set_pulse_step", "GtkProgressBar*");
  XEN_ASSERT_TYPE(XEN_gdouble_P(fraction), fraction, 2, "gtk_progress_bar_set_pulse_step", "gdouble");
  gtk_progress_bar_set_pulse_step(XEN_TO_C_GtkProgressBar_(pbar), XEN_TO_C_gdouble(fraction));
  return(XEN_FALSE);
}
static XEN gxg_gtk_progress_bar_set_orientation(XEN pbar, XEN orientation)
{
  #define H_gtk_progress_bar_set_orientation "void gtk_progress_bar_set_orientation(GtkProgressBar* pbar, \
GtkProgressBarOrientation orientation)"
  XEN_ASSERT_TYPE(XEN_GtkProgressBar__P(pbar), pbar, 1, "gtk_progress_bar_set_orientation", "GtkProgressBar*");
  XEN_ASSERT_TYPE(XEN_GtkProgressBarOrientation_P(orientation), orientation, 2, "gtk_progress_bar_set_orientation", "GtkProgressBarOrientation");
  gtk_progress_bar_set_orientation(XEN_TO_C_GtkProgressBar_(pbar), XEN_TO_C_GtkProgressBarOrientation(orientation));
  return(XEN_FALSE);
}
static XEN gxg_gtk_progress_bar_get_text(XEN pbar)
{
  #define H_gtk_progress_bar_get_text "gchar* gtk_progress_bar_get_text(GtkProgressBar* pbar)"
  XEN_ASSERT_TYPE(XEN_GtkProgressBar__P(pbar), pbar, 1, "gtk_progress_bar_get_text", "GtkProgressBar*");
  return(C_TO_XEN_gchar_(gtk_progress_bar_get_text(XEN_TO_C_GtkProgressBar_(pbar))));
}
static XEN gxg_gtk_progress_bar_get_fraction(XEN pbar)
{
  #define H_gtk_progress_bar_get_fraction "gdouble gtk_progress_bar_get_fraction(GtkProgressBar* pbar)"
  XEN_ASSERT_TYPE(XEN_GtkProgressBar__P(pbar), pbar, 1, "gtk_progress_bar_get_fraction", "GtkProgressBar*");
  return(C_TO_XEN_gdouble(gtk_progress_bar_get_fraction(XEN_TO_C_GtkProgressBar_(pbar))));
}
static XEN gxg_gtk_progress_bar_get_pulse_step(XEN pbar)
{
  #define H_gtk_progress_bar_get_pulse_step "gdouble gtk_progress_bar_get_pulse_step(GtkProgressBar* pbar)"
  XEN_ASSERT_TYPE(XEN_GtkProgressBar__P(pbar), pbar, 1, "gtk_progress_bar_get_pulse_step", "GtkProgressBar*");
  return(C_TO_XEN_gdouble(gtk_progress_bar_get_pulse_step(XEN_TO_C_GtkProgressBar_(pbar))));
}
static XEN gxg_gtk_progress_bar_get_orientation(XEN pbar)
{
  #define H_gtk_progress_bar_get_orientation "GtkProgressBarOrientation gtk_progress_bar_get_orientation(GtkProgressBar* pbar)"
  XEN_ASSERT_TYPE(XEN_GtkProgressBar__P(pbar), pbar, 1, "gtk_progress_bar_get_orientation", "GtkProgressBar*");
  return(C_TO_XEN_GtkProgressBarOrientation(gtk_progress_bar_get_orientation(XEN_TO_C_GtkProgressBar_(pbar))));
}
static XEN gxg_gtk_radio_button_get_type(void)
{
  #define H_gtk_radio_button_get_type "GtkType gtk_radio_button_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_radio_button_get_type()));
}
static XEN gxg_gtk_radio_button_new(XEN group)
{
  #define H_gtk_radio_button_new "GtkWidget* gtk_radio_button_new(GSList* group)"
  XEN_ASSERT_TYPE(XEN_GSList__P(group), group, 1, "gtk_radio_button_new", "GSList*");
  return(C_TO_XEN_GtkWidget_(gtk_radio_button_new(XEN_TO_C_GSList_(group))));
}
static XEN gxg_gtk_radio_button_new_from_widget(XEN group)
{
  #define H_gtk_radio_button_new_from_widget "GtkWidget* gtk_radio_button_new_from_widget(GtkRadioButton* group)"
  XEN_ASSERT_TYPE(XEN_GtkRadioButton__P(group), group, 1, "gtk_radio_button_new_from_widget", "GtkRadioButton*");
  return(C_TO_XEN_GtkWidget_(gtk_radio_button_new_from_widget(XEN_TO_C_GtkRadioButton_(group))));
}
static XEN gxg_gtk_radio_button_new_with_label(XEN group, XEN label)
{
  #define H_gtk_radio_button_new_with_label "GtkWidget* gtk_radio_button_new_with_label(GSList* group, \
gchar* label)"
  XEN_ASSERT_TYPE(XEN_GSList__P(group), group, 1, "gtk_radio_button_new_with_label", "GSList*");
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 2, "gtk_radio_button_new_with_label", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_radio_button_new_with_label(XEN_TO_C_GSList_(group), XEN_TO_C_gchar_(label))));
}
static XEN gxg_gtk_radio_button_new_with_label_from_widget(XEN group, XEN label)
{
  #define H_gtk_radio_button_new_with_label_from_widget "GtkWidget* gtk_radio_button_new_with_label_from_widget(GtkRadioButton* group, \
gchar* label)"
  XEN_ASSERT_TYPE(XEN_GtkRadioButton__P(group), group, 1, "gtk_radio_button_new_with_label_from_widget", "GtkRadioButton*");
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 2, "gtk_radio_button_new_with_label_from_widget", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_radio_button_new_with_label_from_widget(XEN_TO_C_GtkRadioButton_(group), XEN_TO_C_gchar_(label))));
}
static XEN gxg_gtk_radio_button_new_with_mnemonic(XEN group, XEN label)
{
  #define H_gtk_radio_button_new_with_mnemonic "GtkWidget* gtk_radio_button_new_with_mnemonic(GSList* group, \
gchar* label)"
  XEN_ASSERT_TYPE(XEN_GSList__P(group), group, 1, "gtk_radio_button_new_with_mnemonic", "GSList*");
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 2, "gtk_radio_button_new_with_mnemonic", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_radio_button_new_with_mnemonic(XEN_TO_C_GSList_(group), XEN_TO_C_gchar_(label))));
}
static XEN gxg_gtk_radio_button_new_with_mnemonic_from_widget(XEN group, XEN label)
{
  #define H_gtk_radio_button_new_with_mnemonic_from_widget "GtkWidget* gtk_radio_button_new_with_mnemonic_from_widget(GtkRadioButton* group, \
gchar* label)"
  XEN_ASSERT_TYPE(XEN_GtkRadioButton__P(group), group, 1, "gtk_radio_button_new_with_mnemonic_from_widget", "GtkRadioButton*");
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 2, "gtk_radio_button_new_with_mnemonic_from_widget", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_radio_button_new_with_mnemonic_from_widget(XEN_TO_C_GtkRadioButton_(group), XEN_TO_C_gchar_(label))));
}
static XEN gxg_gtk_radio_button_get_group(XEN radio_button)
{
  #define H_gtk_radio_button_get_group "GSList* gtk_radio_button_get_group(GtkRadioButton* radio_button)"
  XEN_ASSERT_TYPE(XEN_GtkRadioButton__P(radio_button), radio_button, 1, "gtk_radio_button_get_group", "GtkRadioButton*");
  return(C_TO_XEN_GSList_(gtk_radio_button_get_group(XEN_TO_C_GtkRadioButton_(radio_button))));
}
static XEN gxg_gtk_radio_button_set_group(XEN radio_button, XEN group)
{
  #define H_gtk_radio_button_set_group "void gtk_radio_button_set_group(GtkRadioButton* radio_button, \
GSList* group)"
  XEN_ASSERT_TYPE(XEN_GtkRadioButton__P(radio_button), radio_button, 1, "gtk_radio_button_set_group", "GtkRadioButton*");
  XEN_ASSERT_TYPE(XEN_GSList__P(group), group, 2, "gtk_radio_button_set_group", "GSList*");
  gtk_radio_button_set_group(XEN_TO_C_GtkRadioButton_(radio_button), XEN_TO_C_GSList_(group));
  return(XEN_FALSE);
}
static XEN gxg_gtk_radio_menu_item_get_type(void)
{
  #define H_gtk_radio_menu_item_get_type "GtkType gtk_radio_menu_item_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_radio_menu_item_get_type()));
}
static XEN gxg_gtk_radio_menu_item_new(XEN group)
{
  #define H_gtk_radio_menu_item_new "GtkWidget* gtk_radio_menu_item_new(GSList* group)"
  XEN_ASSERT_TYPE(XEN_GSList__P(group), group, 1, "gtk_radio_menu_item_new", "GSList*");
  return(C_TO_XEN_GtkWidget_(gtk_radio_menu_item_new(XEN_TO_C_GSList_(group))));
}
static XEN gxg_gtk_radio_menu_item_new_with_label(XEN group, XEN label)
{
  #define H_gtk_radio_menu_item_new_with_label "GtkWidget* gtk_radio_menu_item_new_with_label(GSList* group, \
gchar* label)"
  XEN_ASSERT_TYPE(XEN_GSList__P(group), group, 1, "gtk_radio_menu_item_new_with_label", "GSList*");
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 2, "gtk_radio_menu_item_new_with_label", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_radio_menu_item_new_with_label(XEN_TO_C_GSList_(group), XEN_TO_C_gchar_(label))));
}
static XEN gxg_gtk_radio_menu_item_new_with_mnemonic(XEN group, XEN label)
{
  #define H_gtk_radio_menu_item_new_with_mnemonic "GtkWidget* gtk_radio_menu_item_new_with_mnemonic(GSList* group, \
gchar* label)"
  XEN_ASSERT_TYPE(XEN_GSList__P(group), group, 1, "gtk_radio_menu_item_new_with_mnemonic", "GSList*");
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 2, "gtk_radio_menu_item_new_with_mnemonic", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_radio_menu_item_new_with_mnemonic(XEN_TO_C_GSList_(group), XEN_TO_C_gchar_(label))));
}
static XEN gxg_gtk_radio_menu_item_get_group(XEN radio_menu_item)
{
  #define H_gtk_radio_menu_item_get_group "GSList* gtk_radio_menu_item_get_group(GtkRadioMenuItem* radio_menu_item)"
  XEN_ASSERT_TYPE(XEN_GtkRadioMenuItem__P(radio_menu_item), radio_menu_item, 1, "gtk_radio_menu_item_get_group", "GtkRadioMenuItem*");
  return(C_TO_XEN_GSList_(gtk_radio_menu_item_get_group(XEN_TO_C_GtkRadioMenuItem_(radio_menu_item))));
}
static XEN gxg_gtk_radio_menu_item_set_group(XEN radio_menu_item, XEN group)
{
  #define H_gtk_radio_menu_item_set_group "void gtk_radio_menu_item_set_group(GtkRadioMenuItem* radio_menu_item, \
GSList* group)"
  XEN_ASSERT_TYPE(XEN_GtkRadioMenuItem__P(radio_menu_item), radio_menu_item, 1, "gtk_radio_menu_item_set_group", "GtkRadioMenuItem*");
  XEN_ASSERT_TYPE(XEN_GSList__P(group), group, 2, "gtk_radio_menu_item_set_group", "GSList*");
  gtk_radio_menu_item_set_group(XEN_TO_C_GtkRadioMenuItem_(radio_menu_item), XEN_TO_C_GSList_(group));
  return(XEN_FALSE);
}
static XEN gxg_gtk_range_get_type(void)
{
  #define H_gtk_range_get_type "GtkType gtk_range_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_range_get_type()));
}
static XEN gxg_gtk_range_set_update_policy(XEN range, XEN policy)
{
  #define H_gtk_range_set_update_policy "void gtk_range_set_update_policy(GtkRange* range, GtkUpdateType policy)"
  XEN_ASSERT_TYPE(XEN_GtkRange__P(range), range, 1, "gtk_range_set_update_policy", "GtkRange*");
  XEN_ASSERT_TYPE(XEN_GtkUpdateType_P(policy), policy, 2, "gtk_range_set_update_policy", "GtkUpdateType");
  gtk_range_set_update_policy(XEN_TO_C_GtkRange_(range), XEN_TO_C_GtkUpdateType(policy));
  return(XEN_FALSE);
}
static XEN gxg_gtk_range_get_update_policy(XEN range)
{
  #define H_gtk_range_get_update_policy "GtkUpdateType gtk_range_get_update_policy(GtkRange* range)"
  XEN_ASSERT_TYPE(XEN_GtkRange__P(range), range, 1, "gtk_range_get_update_policy", "GtkRange*");
  return(C_TO_XEN_GtkUpdateType(gtk_range_get_update_policy(XEN_TO_C_GtkRange_(range))));
}
static XEN gxg_gtk_range_set_adjustment(XEN range, XEN adjustment)
{
  #define H_gtk_range_set_adjustment "void gtk_range_set_adjustment(GtkRange* range, GtkAdjustment* adjustment)"
  XEN_ASSERT_TYPE(XEN_GtkRange__P(range), range, 1, "gtk_range_set_adjustment", "GtkRange*");
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(adjustment), adjustment, 2, "gtk_range_set_adjustment", "GtkAdjustment*");
  gtk_range_set_adjustment(XEN_TO_C_GtkRange_(range), XEN_TO_C_GtkAdjustment_(adjustment));
  return(XEN_FALSE);
}
static XEN gxg_gtk_range_get_adjustment(XEN range)
{
  #define H_gtk_range_get_adjustment "GtkAdjustment* gtk_range_get_adjustment(GtkRange* range)"
  XEN_ASSERT_TYPE(XEN_GtkRange__P(range), range, 1, "gtk_range_get_adjustment", "GtkRange*");
  return(C_TO_XEN_GtkAdjustment_(gtk_range_get_adjustment(XEN_TO_C_GtkRange_(range))));
}
static XEN gxg_gtk_range_set_inverted(XEN range, XEN setting)
{
  #define H_gtk_range_set_inverted "void gtk_range_set_inverted(GtkRange* range, gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GtkRange__P(range), range, 1, "gtk_range_set_inverted", "GtkRange*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gtk_range_set_inverted", "gboolean");
  gtk_range_set_inverted(XEN_TO_C_GtkRange_(range), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_range_get_inverted(XEN range)
{
  #define H_gtk_range_get_inverted "gboolean gtk_range_get_inverted(GtkRange* range)"
  XEN_ASSERT_TYPE(XEN_GtkRange__P(range), range, 1, "gtk_range_get_inverted", "GtkRange*");
  return(C_TO_XEN_gboolean(gtk_range_get_inverted(XEN_TO_C_GtkRange_(range))));
}
static XEN gxg_gtk_range_set_increments(XEN range, XEN step, XEN page)
{
  #define H_gtk_range_set_increments "void gtk_range_set_increments(GtkRange* range, gdouble step, gdouble page)"
  XEN_ASSERT_TYPE(XEN_GtkRange__P(range), range, 1, "gtk_range_set_increments", "GtkRange*");
  XEN_ASSERT_TYPE(XEN_gdouble_P(step), step, 2, "gtk_range_set_increments", "gdouble");
  XEN_ASSERT_TYPE(XEN_gdouble_P(page), page, 3, "gtk_range_set_increments", "gdouble");
  gtk_range_set_increments(XEN_TO_C_GtkRange_(range), XEN_TO_C_gdouble(step), XEN_TO_C_gdouble(page));
  return(XEN_FALSE);
}
static XEN gxg_gtk_range_set_range(XEN range, XEN min, XEN max)
{
  #define H_gtk_range_set_range "void gtk_range_set_range(GtkRange* range, gdouble min, gdouble max)"
  XEN_ASSERT_TYPE(XEN_GtkRange__P(range), range, 1, "gtk_range_set_range", "GtkRange*");
  XEN_ASSERT_TYPE(XEN_gdouble_P(min), min, 2, "gtk_range_set_range", "gdouble");
  XEN_ASSERT_TYPE(XEN_gdouble_P(max), max, 3, "gtk_range_set_range", "gdouble");
  gtk_range_set_range(XEN_TO_C_GtkRange_(range), XEN_TO_C_gdouble(min), XEN_TO_C_gdouble(max));
  return(XEN_FALSE);
}
static XEN gxg_gtk_range_set_value(XEN range, XEN value)
{
  #define H_gtk_range_set_value "void gtk_range_set_value(GtkRange* range, gdouble value)"
  XEN_ASSERT_TYPE(XEN_GtkRange__P(range), range, 1, "gtk_range_set_value", "GtkRange*");
  XEN_ASSERT_TYPE(XEN_gdouble_P(value), value, 2, "gtk_range_set_value", "gdouble");
  gtk_range_set_value(XEN_TO_C_GtkRange_(range), XEN_TO_C_gdouble(value));
  return(XEN_FALSE);
}
static XEN gxg_gtk_range_get_value(XEN range)
{
  #define H_gtk_range_get_value "gdouble gtk_range_get_value(GtkRange* range)"
  XEN_ASSERT_TYPE(XEN_GtkRange__P(range), range, 1, "gtk_range_get_value", "GtkRange*");
  return(C_TO_XEN_gdouble(gtk_range_get_value(XEN_TO_C_GtkRange_(range))));
}
static XEN gxg_gtk_rc_add_default_file(XEN filename)
{
  #define H_gtk_rc_add_default_file "void gtk_rc_add_default_file(gchar* filename)"
  XEN_ASSERT_TYPE(XEN_gchar__P(filename), filename, 1, "gtk_rc_add_default_file", "gchar*");
  gtk_rc_add_default_file(XEN_TO_C_gchar_(filename));
  return(XEN_FALSE);
}
static XEN gxg_gtk_rc_set_default_files(XEN filenames)
{
  #define H_gtk_rc_set_default_files "void gtk_rc_set_default_files(gchar** filenames)"
  XEN_ASSERT_TYPE(XEN_gchar___P(filenames), filenames, 1, "gtk_rc_set_default_files", "gchar**");
  gtk_rc_set_default_files(XEN_TO_C_gchar__(filenames));
  return(XEN_FALSE);
}
static XEN gxg_gtk_rc_get_default_files(void)
{
  #define H_gtk_rc_get_default_files "gchar** gtk_rc_get_default_files( void)"
  return(C_TO_XEN_gchar__(gtk_rc_get_default_files()));
}
static XEN gxg_gtk_rc_get_style(XEN widget)
{
  #define H_gtk_rc_get_style "GtkStyle* gtk_rc_get_style(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_rc_get_style", "GtkWidget*");
  return(C_TO_XEN_GtkStyle_(gtk_rc_get_style(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_rc_parse(XEN filename)
{
  #define H_gtk_rc_parse "void gtk_rc_parse(gchar* filename)"
  XEN_ASSERT_TYPE(XEN_gchar__P(filename), filename, 1, "gtk_rc_parse", "gchar*");
  gtk_rc_parse(XEN_TO_C_gchar_(filename));
  return(XEN_FALSE);
}
static XEN gxg_gtk_rc_parse_string(XEN rc_string)
{
  #define H_gtk_rc_parse_string "void gtk_rc_parse_string(gchar* rc_string)"
  XEN_ASSERT_TYPE(XEN_gchar__P(rc_string), rc_string, 1, "gtk_rc_parse_string", "gchar*");
  gtk_rc_parse_string(XEN_TO_C_gchar_(rc_string));
  return(XEN_FALSE);
}
static XEN gxg_gtk_rc_reparse_all(void)
{
  #define H_gtk_rc_reparse_all "gboolean gtk_rc_reparse_all( void)"
  return(C_TO_XEN_gboolean(gtk_rc_reparse_all()));
}
static XEN gxg_gtk_rc_style_get_type(void)
{
  #define H_gtk_rc_style_get_type "GType gtk_rc_style_get_type( void)"
  return(C_TO_XEN_GType(gtk_rc_style_get_type()));
}
static XEN gxg_gtk_rc_style_new(void)
{
  #define H_gtk_rc_style_new "GtkRcStyle* gtk_rc_style_new( void)"
  return(C_TO_XEN_GtkRcStyle_(gtk_rc_style_new()));
}
static XEN gxg_gtk_rc_style_copy(XEN orig)
{
  #define H_gtk_rc_style_copy "GtkRcStyle* gtk_rc_style_copy(GtkRcStyle* orig)"
  XEN_ASSERT_TYPE(XEN_GtkRcStyle__P(orig), orig, 1, "gtk_rc_style_copy", "GtkRcStyle*");
  return(C_TO_XEN_GtkRcStyle_(gtk_rc_style_copy(XEN_TO_C_GtkRcStyle_(orig))));
}
static XEN gxg_gtk_rc_style_ref(XEN rc_style)
{
  #define H_gtk_rc_style_ref "void gtk_rc_style_ref(GtkRcStyle* rc_style)"
  XEN_ASSERT_TYPE(XEN_GtkRcStyle__P(rc_style), rc_style, 1, "gtk_rc_style_ref", "GtkRcStyle*");
  gtk_rc_style_ref(XEN_TO_C_GtkRcStyle_(rc_style));
  return(XEN_FALSE);
}
static XEN gxg_gtk_rc_style_unref(XEN rc_style)
{
  #define H_gtk_rc_style_unref "void gtk_rc_style_unref(GtkRcStyle* rc_style)"
  XEN_ASSERT_TYPE(XEN_GtkRcStyle__P(rc_style), rc_style, 1, "gtk_rc_style_unref", "GtkRcStyle*");
  gtk_rc_style_unref(XEN_TO_C_GtkRcStyle_(rc_style));
  return(XEN_FALSE);
}
static XEN gxg_gtk_rc_find_module_in_path(XEN module_file)
{
  #define H_gtk_rc_find_module_in_path "gchar* gtk_rc_find_module_in_path(gchar* module_file)"
  XEN_ASSERT_TYPE(XEN_gchar__P(module_file), module_file, 1, "gtk_rc_find_module_in_path", "gchar*");
  return(C_TO_XEN_gchar_(gtk_rc_find_module_in_path(XEN_TO_C_gchar_(module_file))));
}
static XEN gxg_gtk_rc_get_theme_dir(void)
{
  #define H_gtk_rc_get_theme_dir "gchar* gtk_rc_get_theme_dir( void)"
  return(C_TO_XEN_gchar_(gtk_rc_get_theme_dir()));
}
static XEN gxg_gtk_rc_get_module_dir(void)
{
  #define H_gtk_rc_get_module_dir "gchar* gtk_rc_get_module_dir( void)"
  return(C_TO_XEN_gchar_(gtk_rc_get_module_dir()));
}
static XEN gxg_gtk_rc_get_im_module_path(void)
{
  #define H_gtk_rc_get_im_module_path "gchar* gtk_rc_get_im_module_path( void)"
  return(C_TO_XEN_gchar_(gtk_rc_get_im_module_path()));
}
static XEN gxg_gtk_rc_get_im_module_file(void)
{
  #define H_gtk_rc_get_im_module_file "gchar* gtk_rc_get_im_module_file( void)"
  return(C_TO_XEN_gchar_(gtk_rc_get_im_module_file()));
}
static XEN gxg_gtk_rc_scanner_new(void)
{
  #define H_gtk_rc_scanner_new "GScanner* gtk_rc_scanner_new( void)"
  return(C_TO_XEN_GScanner_(gtk_rc_scanner_new()));
}
static XEN gxg_gtk_rc_parse_color(XEN scanner, XEN color)
{
  #define H_gtk_rc_parse_color "guint gtk_rc_parse_color(GScanner* scanner, GdkColor* color)"
  XEN_ASSERT_TYPE(XEN_GScanner__P(scanner), scanner, 1, "gtk_rc_parse_color", "GScanner*");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(color), color, 2, "gtk_rc_parse_color", "GdkColor*");
  return(C_TO_XEN_guint(gtk_rc_parse_color(XEN_TO_C_GScanner_(scanner), XEN_TO_C_GdkColor_(color))));
}
static XEN gxg_gtk_rc_parse_state(XEN scanner, XEN state)
{
  #define H_gtk_rc_parse_state "guint gtk_rc_parse_state(GScanner* scanner, GtkStateType* [state])"
  GtkStateType ref_state;
  XEN_ASSERT_TYPE(XEN_GScanner__P(scanner), scanner, 1, "gtk_rc_parse_state", "GScanner*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_guint(gtk_rc_parse_state(XEN_TO_C_GScanner_(scanner), &ref_state));
    return(XEN_LIST_2(result, C_TO_XEN_GtkStateType(ref_state)));
   }
}
static XEN gxg_gtk_rc_parse_priority(XEN scanner, XEN priority)
{
  #define H_gtk_rc_parse_priority "guint gtk_rc_parse_priority(GScanner* scanner, GtkPathPriorityType* [priority])"
  GtkPathPriorityType ref_priority;
  XEN_ASSERT_TYPE(XEN_GScanner__P(scanner), scanner, 1, "gtk_rc_parse_priority", "GScanner*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_guint(gtk_rc_parse_priority(XEN_TO_C_GScanner_(scanner), &ref_priority));
    return(XEN_LIST_2(result, C_TO_XEN_GtkPathPriorityType(ref_priority)));
   }
}
static XEN gxg_gtk_ruler_get_type(void)
{
  #define H_gtk_ruler_get_type "GtkType gtk_ruler_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_ruler_get_type()));
}
static XEN gxg_gtk_ruler_set_metric(XEN ruler, XEN metric)
{
  #define H_gtk_ruler_set_metric "void gtk_ruler_set_metric(GtkRuler* ruler, GtkMetricType metric)"
  XEN_ASSERT_TYPE(XEN_GtkRuler__P(ruler), ruler, 1, "gtk_ruler_set_metric", "GtkRuler*");
  XEN_ASSERT_TYPE(XEN_GtkMetricType_P(metric), metric, 2, "gtk_ruler_set_metric", "GtkMetricType");
  gtk_ruler_set_metric(XEN_TO_C_GtkRuler_(ruler), XEN_TO_C_GtkMetricType(metric));
  return(XEN_FALSE);
}
static XEN gxg_gtk_ruler_set_range(XEN ruler, XEN lower, XEN upper, XEN position, XEN max_size)
{
  #define H_gtk_ruler_set_range "void gtk_ruler_set_range(GtkRuler* ruler, gdouble lower, gdouble upper, \
gdouble position, gdouble max_size)"
  XEN_ASSERT_TYPE(XEN_GtkRuler__P(ruler), ruler, 1, "gtk_ruler_set_range", "GtkRuler*");
  XEN_ASSERT_TYPE(XEN_gdouble_P(lower), lower, 2, "gtk_ruler_set_range", "gdouble");
  XEN_ASSERT_TYPE(XEN_gdouble_P(upper), upper, 3, "gtk_ruler_set_range", "gdouble");
  XEN_ASSERT_TYPE(XEN_gdouble_P(position), position, 4, "gtk_ruler_set_range", "gdouble");
  XEN_ASSERT_TYPE(XEN_gdouble_P(max_size), max_size, 5, "gtk_ruler_set_range", "gdouble");
  gtk_ruler_set_range(XEN_TO_C_GtkRuler_(ruler), XEN_TO_C_gdouble(lower), XEN_TO_C_gdouble(upper), XEN_TO_C_gdouble(position), 
                      XEN_TO_C_gdouble(max_size));
  return(XEN_FALSE);
}
static XEN gxg_gtk_ruler_draw_ticks(XEN ruler)
{
  #define H_gtk_ruler_draw_ticks "void gtk_ruler_draw_ticks(GtkRuler* ruler)"
  XEN_ASSERT_TYPE(XEN_GtkRuler__P(ruler), ruler, 1, "gtk_ruler_draw_ticks", "GtkRuler*");
  gtk_ruler_draw_ticks(XEN_TO_C_GtkRuler_(ruler));
  return(XEN_FALSE);
}
static XEN gxg_gtk_ruler_draw_pos(XEN ruler)
{
  #define H_gtk_ruler_draw_pos "void gtk_ruler_draw_pos(GtkRuler* ruler)"
  XEN_ASSERT_TYPE(XEN_GtkRuler__P(ruler), ruler, 1, "gtk_ruler_draw_pos", "GtkRuler*");
  gtk_ruler_draw_pos(XEN_TO_C_GtkRuler_(ruler));
  return(XEN_FALSE);
}
static XEN gxg_gtk_ruler_get_metric(XEN ruler)
{
  #define H_gtk_ruler_get_metric "GtkMetricType gtk_ruler_get_metric(GtkRuler* ruler)"
  XEN_ASSERT_TYPE(XEN_GtkRuler__P(ruler), ruler, 1, "gtk_ruler_get_metric", "GtkRuler*");
  return(C_TO_XEN_GtkMetricType(gtk_ruler_get_metric(XEN_TO_C_GtkRuler_(ruler))));
}
static XEN gxg_gtk_ruler_get_range(XEN ruler, XEN lower, XEN upper, XEN position, XEN max_size)
{
  #define H_gtk_ruler_get_range "void gtk_ruler_get_range(GtkRuler* ruler, gdouble* [lower], gdouble* [upper], \
gdouble* [position], gdouble* [max_size])"
  gdouble ref_lower;
  gdouble ref_upper;
  gdouble ref_position;
  gdouble ref_max_size;
  XEN_ASSERT_TYPE(XEN_GtkRuler__P(ruler), ruler, 1, "gtk_ruler_get_range", "GtkRuler*");
  gtk_ruler_get_range(XEN_TO_C_GtkRuler_(ruler), &ref_lower, &ref_upper, &ref_position, &ref_max_size);
  return(XEN_LIST_4(C_TO_XEN_gdouble(ref_lower), C_TO_XEN_gdouble(ref_upper), C_TO_XEN_gdouble(ref_position), C_TO_XEN_gdouble(ref_max_size)));
}
static XEN gxg_gtk_scale_get_type(void)
{
  #define H_gtk_scale_get_type "GtkType gtk_scale_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_scale_get_type()));
}
static XEN gxg_gtk_scale_set_digits(XEN scale, XEN digits)
{
  #define H_gtk_scale_set_digits "void gtk_scale_set_digits(GtkScale* scale, gint digits)"
  XEN_ASSERT_TYPE(XEN_GtkScale__P(scale), scale, 1, "gtk_scale_set_digits", "GtkScale*");
  XEN_ASSERT_TYPE(XEN_gint_P(digits), digits, 2, "gtk_scale_set_digits", "gint");
  gtk_scale_set_digits(XEN_TO_C_GtkScale_(scale), XEN_TO_C_gint(digits));
  return(XEN_FALSE);
}
static XEN gxg_gtk_scale_get_digits(XEN scale)
{
  #define H_gtk_scale_get_digits "gint gtk_scale_get_digits(GtkScale* scale)"
  XEN_ASSERT_TYPE(XEN_GtkScale__P(scale), scale, 1, "gtk_scale_get_digits", "GtkScale*");
  return(C_TO_XEN_gint(gtk_scale_get_digits(XEN_TO_C_GtkScale_(scale))));
}
static XEN gxg_gtk_scale_set_draw_value(XEN scale, XEN draw_value)
{
  #define H_gtk_scale_set_draw_value "void gtk_scale_set_draw_value(GtkScale* scale, gboolean draw_value)"
  XEN_ASSERT_TYPE(XEN_GtkScale__P(scale), scale, 1, "gtk_scale_set_draw_value", "GtkScale*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(draw_value), draw_value, 2, "gtk_scale_set_draw_value", "gboolean");
  gtk_scale_set_draw_value(XEN_TO_C_GtkScale_(scale), XEN_TO_C_gboolean(draw_value));
  return(XEN_FALSE);
}
static XEN gxg_gtk_scale_get_draw_value(XEN scale)
{
  #define H_gtk_scale_get_draw_value "gboolean gtk_scale_get_draw_value(GtkScale* scale)"
  XEN_ASSERT_TYPE(XEN_GtkScale__P(scale), scale, 1, "gtk_scale_get_draw_value", "GtkScale*");
  return(C_TO_XEN_gboolean(gtk_scale_get_draw_value(XEN_TO_C_GtkScale_(scale))));
}
static XEN gxg_gtk_scale_set_value_pos(XEN scale, XEN pos)
{
  #define H_gtk_scale_set_value_pos "void gtk_scale_set_value_pos(GtkScale* scale, GtkPositionType pos)"
  XEN_ASSERT_TYPE(XEN_GtkScale__P(scale), scale, 1, "gtk_scale_set_value_pos", "GtkScale*");
  XEN_ASSERT_TYPE(XEN_GtkPositionType_P(pos), pos, 2, "gtk_scale_set_value_pos", "GtkPositionType");
  gtk_scale_set_value_pos(XEN_TO_C_GtkScale_(scale), XEN_TO_C_GtkPositionType(pos));
  return(XEN_FALSE);
}
static XEN gxg_gtk_scale_get_value_pos(XEN scale)
{
  #define H_gtk_scale_get_value_pos "GtkPositionType gtk_scale_get_value_pos(GtkScale* scale)"
  XEN_ASSERT_TYPE(XEN_GtkScale__P(scale), scale, 1, "gtk_scale_get_value_pos", "GtkScale*");
  return(C_TO_XEN_GtkPositionType(gtk_scale_get_value_pos(XEN_TO_C_GtkScale_(scale))));
}
static XEN gxg_gtk_scrollbar_get_type(void)
{
  #define H_gtk_scrollbar_get_type "GtkType gtk_scrollbar_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_scrollbar_get_type()));
}
static XEN gxg_gtk_scrolled_window_get_type(void)
{
  #define H_gtk_scrolled_window_get_type "GtkType gtk_scrolled_window_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_scrolled_window_get_type()));
}
static XEN gxg_gtk_scrolled_window_new(XEN hadjustment, XEN vadjustment)
{
  #define H_gtk_scrolled_window_new "GtkWidget* gtk_scrolled_window_new(GtkAdjustment* hadjustment, GtkAdjustment* vadjustment)"
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(hadjustment), hadjustment, 1, "gtk_scrolled_window_new", "GtkAdjustment*");
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(vadjustment), vadjustment, 2, "gtk_scrolled_window_new", "GtkAdjustment*");
  return(C_TO_XEN_GtkWidget_(gtk_scrolled_window_new(XEN_TO_C_GtkAdjustment_(hadjustment), XEN_TO_C_GtkAdjustment_(vadjustment))));
}
static XEN gxg_gtk_scrolled_window_set_hadjustment(XEN scrolled_window, XEN hadjustment)
{
  #define H_gtk_scrolled_window_set_hadjustment "void gtk_scrolled_window_set_hadjustment(GtkScrolledWindow* scrolled_window, \
GtkAdjustment* hadjustment)"
  XEN_ASSERT_TYPE(XEN_GtkScrolledWindow__P(scrolled_window), scrolled_window, 1, "gtk_scrolled_window_set_hadjustment", "GtkScrolledWindow*");
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(hadjustment), hadjustment, 2, "gtk_scrolled_window_set_hadjustment", "GtkAdjustment*");
  gtk_scrolled_window_set_hadjustment(XEN_TO_C_GtkScrolledWindow_(scrolled_window), XEN_TO_C_GtkAdjustment_(hadjustment));
  return(XEN_FALSE);
}
static XEN gxg_gtk_scrolled_window_set_vadjustment(XEN scrolled_window, XEN hadjustment)
{
  #define H_gtk_scrolled_window_set_vadjustment "void gtk_scrolled_window_set_vadjustment(GtkScrolledWindow* scrolled_window, \
GtkAdjustment* hadjustment)"
  XEN_ASSERT_TYPE(XEN_GtkScrolledWindow__P(scrolled_window), scrolled_window, 1, "gtk_scrolled_window_set_vadjustment", "GtkScrolledWindow*");
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(hadjustment), hadjustment, 2, "gtk_scrolled_window_set_vadjustment", "GtkAdjustment*");
  gtk_scrolled_window_set_vadjustment(XEN_TO_C_GtkScrolledWindow_(scrolled_window), XEN_TO_C_GtkAdjustment_(hadjustment));
  return(XEN_FALSE);
}
static XEN gxg_gtk_scrolled_window_get_hadjustment(XEN scrolled_window)
{
  #define H_gtk_scrolled_window_get_hadjustment "GtkAdjustment* gtk_scrolled_window_get_hadjustment(GtkScrolledWindow* scrolled_window)"
  XEN_ASSERT_TYPE(XEN_GtkScrolledWindow__P(scrolled_window), scrolled_window, 1, "gtk_scrolled_window_get_hadjustment", "GtkScrolledWindow*");
  return(C_TO_XEN_GtkAdjustment_(gtk_scrolled_window_get_hadjustment(XEN_TO_C_GtkScrolledWindow_(scrolled_window))));
}
static XEN gxg_gtk_scrolled_window_get_vadjustment(XEN scrolled_window)
{
  #define H_gtk_scrolled_window_get_vadjustment "GtkAdjustment* gtk_scrolled_window_get_vadjustment(GtkScrolledWindow* scrolled_window)"
  XEN_ASSERT_TYPE(XEN_GtkScrolledWindow__P(scrolled_window), scrolled_window, 1, "gtk_scrolled_window_get_vadjustment", "GtkScrolledWindow*");
  return(C_TO_XEN_GtkAdjustment_(gtk_scrolled_window_get_vadjustment(XEN_TO_C_GtkScrolledWindow_(scrolled_window))));
}
static XEN gxg_gtk_scrolled_window_set_policy(XEN scrolled_window, XEN hscrollbar_policy, XEN vscrollbar_policy)
{
  #define H_gtk_scrolled_window_set_policy "void gtk_scrolled_window_set_policy(GtkScrolledWindow* scrolled_window, \
GtkPolicyType hscrollbar_policy, GtkPolicyType vscrollbar_policy)"
  XEN_ASSERT_TYPE(XEN_GtkScrolledWindow__P(scrolled_window), scrolled_window, 1, "gtk_scrolled_window_set_policy", "GtkScrolledWindow*");
  XEN_ASSERT_TYPE(XEN_GtkPolicyType_P(hscrollbar_policy), hscrollbar_policy, 2, "gtk_scrolled_window_set_policy", "GtkPolicyType");
  XEN_ASSERT_TYPE(XEN_GtkPolicyType_P(vscrollbar_policy), vscrollbar_policy, 3, "gtk_scrolled_window_set_policy", "GtkPolicyType");
  gtk_scrolled_window_set_policy(XEN_TO_C_GtkScrolledWindow_(scrolled_window), XEN_TO_C_GtkPolicyType(hscrollbar_policy), 
                                 XEN_TO_C_GtkPolicyType(vscrollbar_policy));
  return(XEN_FALSE);
}
static XEN gxg_gtk_scrolled_window_get_policy(XEN scrolled_window, XEN hscrollbar_policy, XEN vscrollbar_policy)
{
  #define H_gtk_scrolled_window_get_policy "void gtk_scrolled_window_get_policy(GtkScrolledWindow* scrolled_window, \
GtkPolicyType* [hscrollbar_policy], GtkPolicyType* [vscrollbar_policy])"
  GtkPolicyType ref_hscrollbar_policy;
  GtkPolicyType ref_vscrollbar_policy;
  XEN_ASSERT_TYPE(XEN_GtkScrolledWindow__P(scrolled_window), scrolled_window, 1, "gtk_scrolled_window_get_policy", "GtkScrolledWindow*");
  gtk_scrolled_window_get_policy(XEN_TO_C_GtkScrolledWindow_(scrolled_window), &ref_hscrollbar_policy, &ref_vscrollbar_policy);
  return(XEN_LIST_2(C_TO_XEN_GtkPolicyType(ref_hscrollbar_policy), C_TO_XEN_GtkPolicyType(ref_vscrollbar_policy)));
}
static XEN gxg_gtk_scrolled_window_set_placement(XEN scrolled_window, XEN window_placement)
{
  #define H_gtk_scrolled_window_set_placement "void gtk_scrolled_window_set_placement(GtkScrolledWindow* scrolled_window, \
GtkCornerType window_placement)"
  XEN_ASSERT_TYPE(XEN_GtkScrolledWindow__P(scrolled_window), scrolled_window, 1, "gtk_scrolled_window_set_placement", "GtkScrolledWindow*");
  XEN_ASSERT_TYPE(XEN_GtkCornerType_P(window_placement), window_placement, 2, "gtk_scrolled_window_set_placement", "GtkCornerType");
  gtk_scrolled_window_set_placement(XEN_TO_C_GtkScrolledWindow_(scrolled_window), XEN_TO_C_GtkCornerType(window_placement));
  return(XEN_FALSE);
}
static XEN gxg_gtk_scrolled_window_get_placement(XEN scrolled_window)
{
  #define H_gtk_scrolled_window_get_placement "GtkCornerType gtk_scrolled_window_get_placement(GtkScrolledWindow* scrolled_window)"
  XEN_ASSERT_TYPE(XEN_GtkScrolledWindow__P(scrolled_window), scrolled_window, 1, "gtk_scrolled_window_get_placement", "GtkScrolledWindow*");
  return(C_TO_XEN_GtkCornerType(gtk_scrolled_window_get_placement(XEN_TO_C_GtkScrolledWindow_(scrolled_window))));
}
static XEN gxg_gtk_scrolled_window_set_shadow_type(XEN scrolled_window, XEN type)
{
  #define H_gtk_scrolled_window_set_shadow_type "void gtk_scrolled_window_set_shadow_type(GtkScrolledWindow* scrolled_window, \
GtkShadowType type)"
  XEN_ASSERT_TYPE(XEN_GtkScrolledWindow__P(scrolled_window), scrolled_window, 1, "gtk_scrolled_window_set_shadow_type", "GtkScrolledWindow*");
  XEN_ASSERT_TYPE(XEN_GtkShadowType_P(type), type, 2, "gtk_scrolled_window_set_shadow_type", "GtkShadowType");
  gtk_scrolled_window_set_shadow_type(XEN_TO_C_GtkScrolledWindow_(scrolled_window), XEN_TO_C_GtkShadowType(type));
  return(XEN_FALSE);
}
static XEN gxg_gtk_scrolled_window_get_shadow_type(XEN scrolled_window)
{
  #define H_gtk_scrolled_window_get_shadow_type "GtkShadowType gtk_scrolled_window_get_shadow_type(GtkScrolledWindow* scrolled_window)"
  XEN_ASSERT_TYPE(XEN_GtkScrolledWindow__P(scrolled_window), scrolled_window, 1, "gtk_scrolled_window_get_shadow_type", "GtkScrolledWindow*");
  return(C_TO_XEN_GtkShadowType(gtk_scrolled_window_get_shadow_type(XEN_TO_C_GtkScrolledWindow_(scrolled_window))));
}
static XEN gxg_gtk_scrolled_window_add_with_viewport(XEN scrolled_window, XEN child)
{
  #define H_gtk_scrolled_window_add_with_viewport "void gtk_scrolled_window_add_with_viewport(GtkScrolledWindow* scrolled_window, \
GtkWidget* child)"
  XEN_ASSERT_TYPE(XEN_GtkScrolledWindow__P(scrolled_window), scrolled_window, 1, "gtk_scrolled_window_add_with_viewport", "GtkScrolledWindow*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_scrolled_window_add_with_viewport", "GtkWidget*");
  gtk_scrolled_window_add_with_viewport(XEN_TO_C_GtkScrolledWindow_(scrolled_window), XEN_TO_C_GtkWidget_(child));
  return(XEN_FALSE);
}
static XEN gxg_gtk_target_list_new(XEN targets, XEN ntargets)
{
  #define H_gtk_target_list_new "GtkTargetList* gtk_target_list_new(GtkTargetEntry* targets, guint ntargets)"
  XEN_ASSERT_TYPE(XEN_GtkTargetEntry__P(targets), targets, 1, "gtk_target_list_new", "GtkTargetEntry*");
  XEN_ASSERT_TYPE(XEN_guint_P(ntargets), ntargets, 2, "gtk_target_list_new", "guint");
  return(C_TO_XEN_GtkTargetList_(gtk_target_list_new(XEN_TO_C_GtkTargetEntry_(targets), XEN_TO_C_guint(ntargets))));
}
static XEN gxg_gtk_target_list_ref(XEN list)
{
  #define H_gtk_target_list_ref "void gtk_target_list_ref(GtkTargetList* list)"
  XEN_ASSERT_TYPE(XEN_GtkTargetList__P(list), list, 1, "gtk_target_list_ref", "GtkTargetList*");
  gtk_target_list_ref(XEN_TO_C_GtkTargetList_(list));
  return(XEN_FALSE);
}
static XEN gxg_gtk_target_list_unref(XEN list)
{
  #define H_gtk_target_list_unref "void gtk_target_list_unref(GtkTargetList* list)"
  XEN_ASSERT_TYPE(XEN_GtkTargetList__P(list), list, 1, "gtk_target_list_unref", "GtkTargetList*");
  gtk_target_list_unref(XEN_TO_C_GtkTargetList_(list));
  return(XEN_FALSE);
}
static XEN gxg_gtk_target_list_add(XEN list, XEN target, XEN flags, XEN info)
{
  #define H_gtk_target_list_add "void gtk_target_list_add(GtkTargetList* list, GdkAtom target, guint flags, \
guint info)"
  XEN_ASSERT_TYPE(XEN_GtkTargetList__P(list), list, 1, "gtk_target_list_add", "GtkTargetList*");
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(target), target, 2, "gtk_target_list_add", "GdkAtom");
  XEN_ASSERT_TYPE(XEN_guint_P(flags), flags, 3, "gtk_target_list_add", "guint");
  XEN_ASSERT_TYPE(XEN_guint_P(info), info, 4, "gtk_target_list_add", "guint");
  gtk_target_list_add(XEN_TO_C_GtkTargetList_(list), XEN_TO_C_GdkAtom(target), XEN_TO_C_guint(flags), XEN_TO_C_guint(info));
  return(XEN_FALSE);
}
static XEN gxg_gtk_target_list_add_table(XEN list, XEN targets, XEN ntargets)
{
  #define H_gtk_target_list_add_table "void gtk_target_list_add_table(GtkTargetList* list, GtkTargetEntry* targets, \
guint ntargets)"
  XEN_ASSERT_TYPE(XEN_GtkTargetList__P(list), list, 1, "gtk_target_list_add_table", "GtkTargetList*");
  XEN_ASSERT_TYPE(XEN_GtkTargetEntry__P(targets), targets, 2, "gtk_target_list_add_table", "GtkTargetEntry*");
  XEN_ASSERT_TYPE(XEN_guint_P(ntargets), ntargets, 3, "gtk_target_list_add_table", "guint");
  gtk_target_list_add_table(XEN_TO_C_GtkTargetList_(list), XEN_TO_C_GtkTargetEntry_(targets), XEN_TO_C_guint(ntargets));
  return(XEN_FALSE);
}
static XEN gxg_gtk_target_list_remove(XEN list, XEN target)
{
  #define H_gtk_target_list_remove "void gtk_target_list_remove(GtkTargetList* list, GdkAtom target)"
  XEN_ASSERT_TYPE(XEN_GtkTargetList__P(list), list, 1, "gtk_target_list_remove", "GtkTargetList*");
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(target), target, 2, "gtk_target_list_remove", "GdkAtom");
  gtk_target_list_remove(XEN_TO_C_GtkTargetList_(list), XEN_TO_C_GdkAtom(target));
  return(XEN_FALSE);
}
static XEN gxg_gtk_target_list_find(XEN list, XEN target, XEN info)
{
  #define H_gtk_target_list_find "gboolean gtk_target_list_find(GtkTargetList* list, GdkAtom target, \
guint* [info])"
  guint ref_info;
  XEN_ASSERT_TYPE(XEN_GtkTargetList__P(list), list, 1, "gtk_target_list_find", "GtkTargetList*");
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(target), target, 2, "gtk_target_list_find", "GdkAtom");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gtk_target_list_find(XEN_TO_C_GtkTargetList_(list), XEN_TO_C_GdkAtom(target), &ref_info));
    return(XEN_LIST_2(result, C_TO_XEN_guint(ref_info)));
   }
}
static XEN gxg_gtk_selection_owner_set(XEN widget, XEN selection, XEN time)
{
  #define H_gtk_selection_owner_set "gboolean gtk_selection_owner_set(GtkWidget* widget, GdkAtom selection, \
guint32 time)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_selection_owner_set", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(selection), selection, 2, "gtk_selection_owner_set", "GdkAtom");
  XEN_ASSERT_TYPE(XEN_guint32_P(time), time, 3, "gtk_selection_owner_set", "guint32");
  return(C_TO_XEN_gboolean(gtk_selection_owner_set(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GdkAtom(selection), XEN_TO_C_guint32(time))));
}
static XEN gxg_gtk_selection_add_target(XEN widget, XEN selection, XEN target, XEN info)
{
  #define H_gtk_selection_add_target "void gtk_selection_add_target(GtkWidget* widget, GdkAtom selection, \
GdkAtom target, guint info)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_selection_add_target", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(selection), selection, 2, "gtk_selection_add_target", "GdkAtom");
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(target), target, 3, "gtk_selection_add_target", "GdkAtom");
  XEN_ASSERT_TYPE(XEN_guint_P(info), info, 4, "gtk_selection_add_target", "guint");
  gtk_selection_add_target(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GdkAtom(selection), XEN_TO_C_GdkAtom(target), XEN_TO_C_guint(info));
  return(XEN_FALSE);
}
static XEN gxg_gtk_selection_add_targets(XEN widget, XEN selection, XEN targets, XEN ntargets)
{
  #define H_gtk_selection_add_targets "void gtk_selection_add_targets(GtkWidget* widget, GdkAtom selection, \
GtkTargetEntry* targets, guint ntargets)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_selection_add_targets", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(selection), selection, 2, "gtk_selection_add_targets", "GdkAtom");
  XEN_ASSERT_TYPE(XEN_GtkTargetEntry__P(targets), targets, 3, "gtk_selection_add_targets", "GtkTargetEntry*");
  XEN_ASSERT_TYPE(XEN_guint_P(ntargets), ntargets, 4, "gtk_selection_add_targets", "guint");
  gtk_selection_add_targets(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GdkAtom(selection), XEN_TO_C_GtkTargetEntry_(targets), 
                            XEN_TO_C_guint(ntargets));
  return(XEN_FALSE);
}
static XEN gxg_gtk_selection_clear_targets(XEN widget, XEN selection)
{
  #define H_gtk_selection_clear_targets "void gtk_selection_clear_targets(GtkWidget* widget, GdkAtom selection)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_selection_clear_targets", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(selection), selection, 2, "gtk_selection_clear_targets", "GdkAtom");
  gtk_selection_clear_targets(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GdkAtom(selection));
  return(XEN_FALSE);
}
static XEN gxg_gtk_selection_convert(XEN widget, XEN selection, XEN target, XEN time)
{
  #define H_gtk_selection_convert "gboolean gtk_selection_convert(GtkWidget* widget, GdkAtom selection, \
GdkAtom target, guint32 time)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_selection_convert", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(selection), selection, 2, "gtk_selection_convert", "GdkAtom");
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(target), target, 3, "gtk_selection_convert", "GdkAtom");
  XEN_ASSERT_TYPE(XEN_guint32_P(time), time, 4, "gtk_selection_convert", "guint32");
  return(C_TO_XEN_gboolean(gtk_selection_convert(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GdkAtom(selection), XEN_TO_C_GdkAtom(target), 
                                                 XEN_TO_C_guint32(time))));
}
static XEN gxg_gtk_selection_data_set(XEN selection_data, XEN type, XEN format, XEN data, XEN length)
{
  #define H_gtk_selection_data_set "void gtk_selection_data_set(GtkSelectionData* selection_data, GdkAtom type, \
gint format, guchar* data, gint length)"
  XEN_ASSERT_TYPE(XEN_GtkSelectionData__P(selection_data), selection_data, 1, "gtk_selection_data_set", "GtkSelectionData*");
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(type), type, 2, "gtk_selection_data_set", "GdkAtom");
  XEN_ASSERT_TYPE(XEN_gint_P(format), format, 3, "gtk_selection_data_set", "gint");
  XEN_ASSERT_TYPE(XEN_guchar__P(data), data, 4, "gtk_selection_data_set", "guchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(length), length, 5, "gtk_selection_data_set", "gint");
  gtk_selection_data_set(XEN_TO_C_GtkSelectionData_(selection_data), XEN_TO_C_GdkAtom(type), XEN_TO_C_gint(format), XEN_TO_C_guchar_(data), 
                         XEN_TO_C_gint(length));
  return(XEN_FALSE);
}
static XEN gxg_gtk_selection_data_set_text(XEN selection_data, XEN str, XEN len)
{
  #define H_gtk_selection_data_set_text "gboolean gtk_selection_data_set_text(GtkSelectionData* selection_data, \
gchar* str, gint len)"
  XEN_ASSERT_TYPE(XEN_GtkSelectionData__P(selection_data), selection_data, 1, "gtk_selection_data_set_text", "GtkSelectionData*");
  XEN_ASSERT_TYPE(XEN_gchar__P(str), str, 2, "gtk_selection_data_set_text", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(len), len, 3, "gtk_selection_data_set_text", "gint");
  return(C_TO_XEN_gboolean(gtk_selection_data_set_text(XEN_TO_C_GtkSelectionData_(selection_data), XEN_TO_C_gchar_(str), 
                                                       XEN_TO_C_gint(len))));
}
static XEN gxg_gtk_selection_data_get_text(XEN selection_data)
{
  #define H_gtk_selection_data_get_text "guchar* gtk_selection_data_get_text(GtkSelectionData* selection_data)"
  XEN_ASSERT_TYPE(XEN_GtkSelectionData__P(selection_data), selection_data, 1, "gtk_selection_data_get_text", "GtkSelectionData*");
  return(C_TO_XEN_guchar_(gtk_selection_data_get_text(XEN_TO_C_GtkSelectionData_(selection_data))));
}
static XEN gxg_gtk_selection_data_get_targets(XEN selection_data, XEN targets, XEN n_atoms)
{
  #define H_gtk_selection_data_get_targets "gboolean gtk_selection_data_get_targets(GtkSelectionData* selection_data, \
GdkAtom** [targets], gint* [n_atoms])"
  GdkAtom* ref_targets = NULL;
  gint ref_n_atoms;
  XEN_ASSERT_TYPE(XEN_GtkSelectionData__P(selection_data), selection_data, 1, "gtk_selection_data_get_targets", "GtkSelectionData*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gtk_selection_data_get_targets(XEN_TO_C_GtkSelectionData_(selection_data), &ref_targets, &ref_n_atoms));
    return(XEN_LIST_3(result, C_TO_XEN_GdkAtom_(ref_targets), C_TO_XEN_gint(ref_n_atoms)));
   }
}
static XEN gxg_gtk_selection_data_targets_include_text(XEN selection_data)
{
  #define H_gtk_selection_data_targets_include_text "gboolean gtk_selection_data_targets_include_text(GtkSelectionData* selection_data)"
  XEN_ASSERT_TYPE(XEN_GtkSelectionData__P(selection_data), selection_data, 1, "gtk_selection_data_targets_include_text", "GtkSelectionData*");
  return(C_TO_XEN_gboolean(gtk_selection_data_targets_include_text(XEN_TO_C_GtkSelectionData_(selection_data))));
}
static XEN gxg_gtk_selection_remove_all(XEN widget)
{
  #define H_gtk_selection_remove_all "void gtk_selection_remove_all(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_selection_remove_all", "GtkWidget*");
  gtk_selection_remove_all(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_selection_data_copy(XEN data)
{
  #define H_gtk_selection_data_copy "GtkSelectionData* gtk_selection_data_copy(GtkSelectionData* data)"
  XEN_ASSERT_TYPE(XEN_GtkSelectionData__P(data), data, 1, "gtk_selection_data_copy", "GtkSelectionData*");
  return(C_TO_XEN_GtkSelectionData_(gtk_selection_data_copy(XEN_TO_C_GtkSelectionData_(data))));
}
static XEN gxg_gtk_selection_data_free(XEN data)
{
  #define H_gtk_selection_data_free "void gtk_selection_data_free(GtkSelectionData* data)"
  XEN_ASSERT_TYPE(XEN_GtkSelectionData__P(data), data, 1, "gtk_selection_data_free", "GtkSelectionData*");
  gtk_selection_data_free(XEN_TO_C_GtkSelectionData_(data));
  return(XEN_FALSE);
}
static XEN gxg_gtk_separator_get_type(void)
{
  #define H_gtk_separator_get_type "GtkType gtk_separator_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_separator_get_type()));
}
static XEN gxg_gtk_separator_menu_item_get_type(void)
{
  #define H_gtk_separator_menu_item_get_type "GType gtk_separator_menu_item_get_type( void)"
  return(C_TO_XEN_GType(gtk_separator_menu_item_get_type()));
}
static XEN gxg_gtk_separator_menu_item_new(void)
{
  #define H_gtk_separator_menu_item_new "GtkWidget* gtk_separator_menu_item_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_separator_menu_item_new()));
}
static XEN gxg_gtk_size_group_get_type(void)
{
  #define H_gtk_size_group_get_type "GType gtk_size_group_get_type( void)"
  return(C_TO_XEN_GType(gtk_size_group_get_type()));
}
static XEN gxg_gtk_size_group_new(XEN mode)
{
  #define H_gtk_size_group_new "GtkSizeGroup* gtk_size_group_new(GtkSizeGroupMode mode)"
  XEN_ASSERT_TYPE(XEN_GtkSizeGroupMode_P(mode), mode, 1, "gtk_size_group_new", "GtkSizeGroupMode");
  return(C_TO_XEN_GtkSizeGroup_(gtk_size_group_new(XEN_TO_C_GtkSizeGroupMode(mode))));
}
static XEN gxg_gtk_size_group_set_mode(XEN size_group, XEN mode)
{
  #define H_gtk_size_group_set_mode "void gtk_size_group_set_mode(GtkSizeGroup* size_group, GtkSizeGroupMode mode)"
  XEN_ASSERT_TYPE(XEN_GtkSizeGroup__P(size_group), size_group, 1, "gtk_size_group_set_mode", "GtkSizeGroup*");
  XEN_ASSERT_TYPE(XEN_GtkSizeGroupMode_P(mode), mode, 2, "gtk_size_group_set_mode", "GtkSizeGroupMode");
  gtk_size_group_set_mode(XEN_TO_C_GtkSizeGroup_(size_group), XEN_TO_C_GtkSizeGroupMode(mode));
  return(XEN_FALSE);
}
static XEN gxg_gtk_size_group_get_mode(XEN size_group)
{
  #define H_gtk_size_group_get_mode "GtkSizeGroupMode gtk_size_group_get_mode(GtkSizeGroup* size_group)"
  XEN_ASSERT_TYPE(XEN_GtkSizeGroup__P(size_group), size_group, 1, "gtk_size_group_get_mode", "GtkSizeGroup*");
  return(C_TO_XEN_GtkSizeGroupMode(gtk_size_group_get_mode(XEN_TO_C_GtkSizeGroup_(size_group))));
}
static XEN gxg_gtk_size_group_add_widget(XEN size_group, XEN widget)
{
  #define H_gtk_size_group_add_widget "void gtk_size_group_add_widget(GtkSizeGroup* size_group, GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkSizeGroup__P(size_group), size_group, 1, "gtk_size_group_add_widget", "GtkSizeGroup*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 2, "gtk_size_group_add_widget", "GtkWidget*");
  gtk_size_group_add_widget(XEN_TO_C_GtkSizeGroup_(size_group), XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_size_group_remove_widget(XEN size_group, XEN widget)
{
  #define H_gtk_size_group_remove_widget "void gtk_size_group_remove_widget(GtkSizeGroup* size_group, \
GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkSizeGroup__P(size_group), size_group, 1, "gtk_size_group_remove_widget", "GtkSizeGroup*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 2, "gtk_size_group_remove_widget", "GtkWidget*");
  gtk_size_group_remove_widget(XEN_TO_C_GtkSizeGroup_(size_group), XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_socket_new(void)
{
  #define H_gtk_socket_new "GtkWidget* gtk_socket_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_socket_new()));
}
static XEN gxg_gtk_socket_get_type(void)
{
  #define H_gtk_socket_get_type "GtkType gtk_socket_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_socket_get_type()));
}
static XEN gxg_gtk_socket_add_id(XEN socket, XEN window_id)
{
  #define H_gtk_socket_add_id "void gtk_socket_add_id(GtkSocket* socket, GdkNativeWindow window_id)"
  XEN_ASSERT_TYPE(XEN_GtkSocket__P(socket), socket, 1, "gtk_socket_add_id", "GtkSocket*");
  XEN_ASSERT_TYPE(XEN_GdkNativeWindow_P(window_id), window_id, 2, "gtk_socket_add_id", "GdkNativeWindow");
  gtk_socket_add_id(XEN_TO_C_GtkSocket_(socket), XEN_TO_C_GdkNativeWindow(window_id));
  return(XEN_FALSE);
}
static XEN gxg_gtk_socket_get_id(XEN socket)
{
  #define H_gtk_socket_get_id "GdkNativeWindow gtk_socket_get_id(GtkSocket* socket)"
  XEN_ASSERT_TYPE(XEN_GtkSocket__P(socket), socket, 1, "gtk_socket_get_id", "GtkSocket*");
  return(C_TO_XEN_GdkNativeWindow(gtk_socket_get_id(XEN_TO_C_GtkSocket_(socket))));
}
static XEN gxg_gtk_spin_button_get_type(void)
{
  #define H_gtk_spin_button_get_type "GtkType gtk_spin_button_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_spin_button_get_type()));
}
static XEN gxg_gtk_spin_button_configure(XEN spin_button, XEN adjustment, XEN climb_rate, XEN digits)
{
  #define H_gtk_spin_button_configure "void gtk_spin_button_configure(GtkSpinButton* spin_button, GtkAdjustment* adjustment, \
gdouble climb_rate, guint digits)"
  XEN_ASSERT_TYPE(XEN_GtkSpinButton__P(spin_button), spin_button, 1, "gtk_spin_button_configure", "GtkSpinButton*");
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(adjustment), adjustment, 2, "gtk_spin_button_configure", "GtkAdjustment*");
  XEN_ASSERT_TYPE(XEN_gdouble_P(climb_rate), climb_rate, 3, "gtk_spin_button_configure", "gdouble");
  XEN_ASSERT_TYPE(XEN_guint_P(digits), digits, 4, "gtk_spin_button_configure", "guint");
  gtk_spin_button_configure(XEN_TO_C_GtkSpinButton_(spin_button), XEN_TO_C_GtkAdjustment_(adjustment), XEN_TO_C_gdouble(climb_rate), 
                            XEN_TO_C_guint(digits));
  return(XEN_FALSE);
}
static XEN gxg_gtk_spin_button_new(XEN adjustment, XEN climb_rate, XEN digits)
{
  #define H_gtk_spin_button_new "GtkWidget* gtk_spin_button_new(GtkAdjustment* adjustment, gdouble climb_rate, \
guint digits)"
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(adjustment), adjustment, 1, "gtk_spin_button_new", "GtkAdjustment*");
  XEN_ASSERT_TYPE(XEN_gdouble_P(climb_rate), climb_rate, 2, "gtk_spin_button_new", "gdouble");
  XEN_ASSERT_TYPE(XEN_guint_P(digits), digits, 3, "gtk_spin_button_new", "guint");
  return(C_TO_XEN_GtkWidget_(gtk_spin_button_new(XEN_TO_C_GtkAdjustment_(adjustment), XEN_TO_C_gdouble(climb_rate), XEN_TO_C_guint(digits))));
}
static XEN gxg_gtk_spin_button_new_with_range(XEN min, XEN max, XEN step)
{
  #define H_gtk_spin_button_new_with_range "GtkWidget* gtk_spin_button_new_with_range(gdouble min, gdouble max, \
gdouble step)"
  XEN_ASSERT_TYPE(XEN_gdouble_P(min), min, 1, "gtk_spin_button_new_with_range", "gdouble");
  XEN_ASSERT_TYPE(XEN_gdouble_P(max), max, 2, "gtk_spin_button_new_with_range", "gdouble");
  XEN_ASSERT_TYPE(XEN_gdouble_P(step), step, 3, "gtk_spin_button_new_with_range", "gdouble");
  return(C_TO_XEN_GtkWidget_(gtk_spin_button_new_with_range(XEN_TO_C_gdouble(min), XEN_TO_C_gdouble(max), XEN_TO_C_gdouble(step))));
}
static XEN gxg_gtk_spin_button_set_adjustment(XEN spin_button, XEN adjustment)
{
  #define H_gtk_spin_button_set_adjustment "void gtk_spin_button_set_adjustment(GtkSpinButton* spin_button, \
GtkAdjustment* adjustment)"
  XEN_ASSERT_TYPE(XEN_GtkSpinButton__P(spin_button), spin_button, 1, "gtk_spin_button_set_adjustment", "GtkSpinButton*");
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(adjustment), adjustment, 2, "gtk_spin_button_set_adjustment", "GtkAdjustment*");
  gtk_spin_button_set_adjustment(XEN_TO_C_GtkSpinButton_(spin_button), XEN_TO_C_GtkAdjustment_(adjustment));
  return(XEN_FALSE);
}
static XEN gxg_gtk_spin_button_get_adjustment(XEN spin_button)
{
  #define H_gtk_spin_button_get_adjustment "GtkAdjustment* gtk_spin_button_get_adjustment(GtkSpinButton* spin_button)"
  XEN_ASSERT_TYPE(XEN_GtkSpinButton__P(spin_button), spin_button, 1, "gtk_spin_button_get_adjustment", "GtkSpinButton*");
  return(C_TO_XEN_GtkAdjustment_(gtk_spin_button_get_adjustment(XEN_TO_C_GtkSpinButton_(spin_button))));
}
static XEN gxg_gtk_spin_button_set_digits(XEN spin_button, XEN digits)
{
  #define H_gtk_spin_button_set_digits "void gtk_spin_button_set_digits(GtkSpinButton* spin_button, guint digits)"
  XEN_ASSERT_TYPE(XEN_GtkSpinButton__P(spin_button), spin_button, 1, "gtk_spin_button_set_digits", "GtkSpinButton*");
  XEN_ASSERT_TYPE(XEN_guint_P(digits), digits, 2, "gtk_spin_button_set_digits", "guint");
  gtk_spin_button_set_digits(XEN_TO_C_GtkSpinButton_(spin_button), XEN_TO_C_guint(digits));
  return(XEN_FALSE);
}
static XEN gxg_gtk_spin_button_get_digits(XEN spin_button)
{
  #define H_gtk_spin_button_get_digits "guint gtk_spin_button_get_digits(GtkSpinButton* spin_button)"
  XEN_ASSERT_TYPE(XEN_GtkSpinButton__P(spin_button), spin_button, 1, "gtk_spin_button_get_digits", "GtkSpinButton*");
  return(C_TO_XEN_guint(gtk_spin_button_get_digits(XEN_TO_C_GtkSpinButton_(spin_button))));
}
static XEN gxg_gtk_spin_button_set_increments(XEN spin_button, XEN step, XEN page)
{
  #define H_gtk_spin_button_set_increments "void gtk_spin_button_set_increments(GtkSpinButton* spin_button, \
gdouble step, gdouble page)"
  XEN_ASSERT_TYPE(XEN_GtkSpinButton__P(spin_button), spin_button, 1, "gtk_spin_button_set_increments", "GtkSpinButton*");
  XEN_ASSERT_TYPE(XEN_gdouble_P(step), step, 2, "gtk_spin_button_set_increments", "gdouble");
  XEN_ASSERT_TYPE(XEN_gdouble_P(page), page, 3, "gtk_spin_button_set_increments", "gdouble");
  gtk_spin_button_set_increments(XEN_TO_C_GtkSpinButton_(spin_button), XEN_TO_C_gdouble(step), XEN_TO_C_gdouble(page));
  return(XEN_FALSE);
}
static XEN gxg_gtk_spin_button_get_increments(XEN spin_button, XEN step, XEN page)
{
  #define H_gtk_spin_button_get_increments "void gtk_spin_button_get_increments(GtkSpinButton* spin_button, \
gdouble* [step], gdouble* [page])"
  gdouble ref_step;
  gdouble ref_page;
  XEN_ASSERT_TYPE(XEN_GtkSpinButton__P(spin_button), spin_button, 1, "gtk_spin_button_get_increments", "GtkSpinButton*");
  gtk_spin_button_get_increments(XEN_TO_C_GtkSpinButton_(spin_button), &ref_step, &ref_page);
  return(XEN_LIST_2(C_TO_XEN_gdouble(ref_step), C_TO_XEN_gdouble(ref_page)));
}
static XEN gxg_gtk_spin_button_set_range(XEN spin_button, XEN min, XEN max)
{
  #define H_gtk_spin_button_set_range "void gtk_spin_button_set_range(GtkSpinButton* spin_button, gdouble min, \
gdouble max)"
  XEN_ASSERT_TYPE(XEN_GtkSpinButton__P(spin_button), spin_button, 1, "gtk_spin_button_set_range", "GtkSpinButton*");
  XEN_ASSERT_TYPE(XEN_gdouble_P(min), min, 2, "gtk_spin_button_set_range", "gdouble");
  XEN_ASSERT_TYPE(XEN_gdouble_P(max), max, 3, "gtk_spin_button_set_range", "gdouble");
  gtk_spin_button_set_range(XEN_TO_C_GtkSpinButton_(spin_button), XEN_TO_C_gdouble(min), XEN_TO_C_gdouble(max));
  return(XEN_FALSE);
}
static XEN gxg_gtk_spin_button_get_range(XEN spin_button, XEN min, XEN max)
{
  #define H_gtk_spin_button_get_range "void gtk_spin_button_get_range(GtkSpinButton* spin_button, gdouble* [min], \
gdouble* [max])"
  gdouble ref_min;
  gdouble ref_max;
  XEN_ASSERT_TYPE(XEN_GtkSpinButton__P(spin_button), spin_button, 1, "gtk_spin_button_get_range", "GtkSpinButton*");
  gtk_spin_button_get_range(XEN_TO_C_GtkSpinButton_(spin_button), &ref_min, &ref_max);
  return(XEN_LIST_2(C_TO_XEN_gdouble(ref_min), C_TO_XEN_gdouble(ref_max)));
}
static XEN gxg_gtk_spin_button_get_value(XEN spin_button)
{
  #define H_gtk_spin_button_get_value "gdouble gtk_spin_button_get_value(GtkSpinButton* spin_button)"
  XEN_ASSERT_TYPE(XEN_GtkSpinButton__P(spin_button), spin_button, 1, "gtk_spin_button_get_value", "GtkSpinButton*");
  return(C_TO_XEN_gdouble(gtk_spin_button_get_value(XEN_TO_C_GtkSpinButton_(spin_button))));
}
static XEN gxg_gtk_spin_button_get_value_as_int(XEN spin_button)
{
  #define H_gtk_spin_button_get_value_as_int "gint gtk_spin_button_get_value_as_int(GtkSpinButton* spin_button)"
  XEN_ASSERT_TYPE(XEN_GtkSpinButton__P(spin_button), spin_button, 1, "gtk_spin_button_get_value_as_int", "GtkSpinButton*");
  return(C_TO_XEN_gint(gtk_spin_button_get_value_as_int(XEN_TO_C_GtkSpinButton_(spin_button))));
}
static XEN gxg_gtk_spin_button_set_value(XEN spin_button, XEN value)
{
  #define H_gtk_spin_button_set_value "void gtk_spin_button_set_value(GtkSpinButton* spin_button, gdouble value)"
  XEN_ASSERT_TYPE(XEN_GtkSpinButton__P(spin_button), spin_button, 1, "gtk_spin_button_set_value", "GtkSpinButton*");
  XEN_ASSERT_TYPE(XEN_gdouble_P(value), value, 2, "gtk_spin_button_set_value", "gdouble");
  gtk_spin_button_set_value(XEN_TO_C_GtkSpinButton_(spin_button), XEN_TO_C_gdouble(value));
  return(XEN_FALSE);
}
static XEN gxg_gtk_spin_button_set_update_policy(XEN spin_button, XEN policy)
{
  #define H_gtk_spin_button_set_update_policy "void gtk_spin_button_set_update_policy(GtkSpinButton* spin_button, \
GtkSpinButtonUpdatePolicy policy)"
  XEN_ASSERT_TYPE(XEN_GtkSpinButton__P(spin_button), spin_button, 1, "gtk_spin_button_set_update_policy", "GtkSpinButton*");
  XEN_ASSERT_TYPE(XEN_GtkSpinButtonUpdatePolicy_P(policy), policy, 2, "gtk_spin_button_set_update_policy", "GtkSpinButtonUpdatePolicy");
  gtk_spin_button_set_update_policy(XEN_TO_C_GtkSpinButton_(spin_button), XEN_TO_C_GtkSpinButtonUpdatePolicy(policy));
  return(XEN_FALSE);
}
static XEN gxg_gtk_spin_button_get_update_policy(XEN spin_button)
{
  #define H_gtk_spin_button_get_update_policy "GtkSpinButtonUpdatePolicy gtk_spin_button_get_update_policy(GtkSpinButton* spin_button)"
  XEN_ASSERT_TYPE(XEN_GtkSpinButton__P(spin_button), spin_button, 1, "gtk_spin_button_get_update_policy", "GtkSpinButton*");
  return(C_TO_XEN_GtkSpinButtonUpdatePolicy(gtk_spin_button_get_update_policy(XEN_TO_C_GtkSpinButton_(spin_button))));
}
static XEN gxg_gtk_spin_button_set_numeric(XEN spin_button, XEN numeric)
{
  #define H_gtk_spin_button_set_numeric "void gtk_spin_button_set_numeric(GtkSpinButton* spin_button, \
gboolean numeric)"
  XEN_ASSERT_TYPE(XEN_GtkSpinButton__P(spin_button), spin_button, 1, "gtk_spin_button_set_numeric", "GtkSpinButton*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(numeric), numeric, 2, "gtk_spin_button_set_numeric", "gboolean");
  gtk_spin_button_set_numeric(XEN_TO_C_GtkSpinButton_(spin_button), XEN_TO_C_gboolean(numeric));
  return(XEN_FALSE);
}
static XEN gxg_gtk_spin_button_get_numeric(XEN spin_button)
{
  #define H_gtk_spin_button_get_numeric "gboolean gtk_spin_button_get_numeric(GtkSpinButton* spin_button)"
  XEN_ASSERT_TYPE(XEN_GtkSpinButton__P(spin_button), spin_button, 1, "gtk_spin_button_get_numeric", "GtkSpinButton*");
  return(C_TO_XEN_gboolean(gtk_spin_button_get_numeric(XEN_TO_C_GtkSpinButton_(spin_button))));
}
static XEN gxg_gtk_spin_button_spin(XEN spin_button, XEN direction, XEN increment)
{
  #define H_gtk_spin_button_spin "void gtk_spin_button_spin(GtkSpinButton* spin_button, GtkSpinType direction, \
gdouble increment)"
  XEN_ASSERT_TYPE(XEN_GtkSpinButton__P(spin_button), spin_button, 1, "gtk_spin_button_spin", "GtkSpinButton*");
  XEN_ASSERT_TYPE(XEN_GtkSpinType_P(direction), direction, 2, "gtk_spin_button_spin", "GtkSpinType");
  XEN_ASSERT_TYPE(XEN_gdouble_P(increment), increment, 3, "gtk_spin_button_spin", "gdouble");
  gtk_spin_button_spin(XEN_TO_C_GtkSpinButton_(spin_button), XEN_TO_C_GtkSpinType(direction), XEN_TO_C_gdouble(increment));
  return(XEN_FALSE);
}
static XEN gxg_gtk_spin_button_set_wrap(XEN spin_button, XEN wrap)
{
  #define H_gtk_spin_button_set_wrap "void gtk_spin_button_set_wrap(GtkSpinButton* spin_button, gboolean wrap)"
  XEN_ASSERT_TYPE(XEN_GtkSpinButton__P(spin_button), spin_button, 1, "gtk_spin_button_set_wrap", "GtkSpinButton*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(wrap), wrap, 2, "gtk_spin_button_set_wrap", "gboolean");
  gtk_spin_button_set_wrap(XEN_TO_C_GtkSpinButton_(spin_button), XEN_TO_C_gboolean(wrap));
  return(XEN_FALSE);
}
static XEN gxg_gtk_spin_button_get_wrap(XEN spin_button)
{
  #define H_gtk_spin_button_get_wrap "gboolean gtk_spin_button_get_wrap(GtkSpinButton* spin_button)"
  XEN_ASSERT_TYPE(XEN_GtkSpinButton__P(spin_button), spin_button, 1, "gtk_spin_button_get_wrap", "GtkSpinButton*");
  return(C_TO_XEN_gboolean(gtk_spin_button_get_wrap(XEN_TO_C_GtkSpinButton_(spin_button))));
}
static XEN gxg_gtk_spin_button_set_snap_to_ticks(XEN spin_button, XEN snap_to_ticks)
{
  #define H_gtk_spin_button_set_snap_to_ticks "void gtk_spin_button_set_snap_to_ticks(GtkSpinButton* spin_button, \
gboolean snap_to_ticks)"
  XEN_ASSERT_TYPE(XEN_GtkSpinButton__P(spin_button), spin_button, 1, "gtk_spin_button_set_snap_to_ticks", "GtkSpinButton*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(snap_to_ticks), snap_to_ticks, 2, "gtk_spin_button_set_snap_to_ticks", "gboolean");
  gtk_spin_button_set_snap_to_ticks(XEN_TO_C_GtkSpinButton_(spin_button), XEN_TO_C_gboolean(snap_to_ticks));
  return(XEN_FALSE);
}
static XEN gxg_gtk_spin_button_get_snap_to_ticks(XEN spin_button)
{
  #define H_gtk_spin_button_get_snap_to_ticks "gboolean gtk_spin_button_get_snap_to_ticks(GtkSpinButton* spin_button)"
  XEN_ASSERT_TYPE(XEN_GtkSpinButton__P(spin_button), spin_button, 1, "gtk_spin_button_get_snap_to_ticks", "GtkSpinButton*");
  return(C_TO_XEN_gboolean(gtk_spin_button_get_snap_to_ticks(XEN_TO_C_GtkSpinButton_(spin_button))));
}
static XEN gxg_gtk_spin_button_update(XEN spin_button)
{
  #define H_gtk_spin_button_update "void gtk_spin_button_update(GtkSpinButton* spin_button)"
  XEN_ASSERT_TYPE(XEN_GtkSpinButton__P(spin_button), spin_button, 1, "gtk_spin_button_update", "GtkSpinButton*");
  gtk_spin_button_update(XEN_TO_C_GtkSpinButton_(spin_button));
  return(XEN_FALSE);
}
static XEN gxg_gtk_statusbar_get_type(void)
{
  #define H_gtk_statusbar_get_type "GtkType gtk_statusbar_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_statusbar_get_type()));
}
static XEN gxg_gtk_statusbar_new(void)
{
  #define H_gtk_statusbar_new "GtkWidget* gtk_statusbar_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_statusbar_new()));
}
static XEN gxg_gtk_statusbar_get_context_id(XEN statusbar, XEN context_description)
{
  #define H_gtk_statusbar_get_context_id "guint gtk_statusbar_get_context_id(GtkStatusbar* statusbar, \
gchar* context_description)"
  XEN_ASSERT_TYPE(XEN_GtkStatusbar__P(statusbar), statusbar, 1, "gtk_statusbar_get_context_id", "GtkStatusbar*");
  XEN_ASSERT_TYPE(XEN_gchar__P(context_description), context_description, 2, "gtk_statusbar_get_context_id", "gchar*");
  return(C_TO_XEN_guint(gtk_statusbar_get_context_id(XEN_TO_C_GtkStatusbar_(statusbar), XEN_TO_C_gchar_(context_description))));
}
static XEN gxg_gtk_statusbar_push(XEN statusbar, XEN context_id, XEN text)
{
  #define H_gtk_statusbar_push "guint gtk_statusbar_push(GtkStatusbar* statusbar, guint context_id, gchar* text)"
  XEN_ASSERT_TYPE(XEN_GtkStatusbar__P(statusbar), statusbar, 1, "gtk_statusbar_push", "GtkStatusbar*");
  XEN_ASSERT_TYPE(XEN_guint_P(context_id), context_id, 2, "gtk_statusbar_push", "guint");
  XEN_ASSERT_TYPE(XEN_gchar__P(text), text, 3, "gtk_statusbar_push", "gchar*");
  return(C_TO_XEN_guint(gtk_statusbar_push(XEN_TO_C_GtkStatusbar_(statusbar), XEN_TO_C_guint(context_id), XEN_TO_C_gchar_(text))));
}
static XEN gxg_gtk_statusbar_pop(XEN statusbar, XEN context_id)
{
  #define H_gtk_statusbar_pop "void gtk_statusbar_pop(GtkStatusbar* statusbar, guint context_id)"
  XEN_ASSERT_TYPE(XEN_GtkStatusbar__P(statusbar), statusbar, 1, "gtk_statusbar_pop", "GtkStatusbar*");
  XEN_ASSERT_TYPE(XEN_guint_P(context_id), context_id, 2, "gtk_statusbar_pop", "guint");
  gtk_statusbar_pop(XEN_TO_C_GtkStatusbar_(statusbar), XEN_TO_C_guint(context_id));
  return(XEN_FALSE);
}
static XEN gxg_gtk_statusbar_remove(XEN statusbar, XEN context_id, XEN message_id)
{
  #define H_gtk_statusbar_remove "void gtk_statusbar_remove(GtkStatusbar* statusbar, guint context_id, \
guint message_id)"
  XEN_ASSERT_TYPE(XEN_GtkStatusbar__P(statusbar), statusbar, 1, "gtk_statusbar_remove", "GtkStatusbar*");
  XEN_ASSERT_TYPE(XEN_guint_P(context_id), context_id, 2, "gtk_statusbar_remove", "guint");
  XEN_ASSERT_TYPE(XEN_guint_P(message_id), message_id, 3, "gtk_statusbar_remove", "guint");
  gtk_statusbar_remove(XEN_TO_C_GtkStatusbar_(statusbar), XEN_TO_C_guint(context_id), XEN_TO_C_guint(message_id));
  return(XEN_FALSE);
}
static XEN gxg_gtk_statusbar_set_has_resize_grip(XEN statusbar, XEN setting)
{
  #define H_gtk_statusbar_set_has_resize_grip "void gtk_statusbar_set_has_resize_grip(GtkStatusbar* statusbar, \
gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GtkStatusbar__P(statusbar), statusbar, 1, "gtk_statusbar_set_has_resize_grip", "GtkStatusbar*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gtk_statusbar_set_has_resize_grip", "gboolean");
  gtk_statusbar_set_has_resize_grip(XEN_TO_C_GtkStatusbar_(statusbar), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_statusbar_get_has_resize_grip(XEN statusbar)
{
  #define H_gtk_statusbar_get_has_resize_grip "gboolean gtk_statusbar_get_has_resize_grip(GtkStatusbar* statusbar)"
  XEN_ASSERT_TYPE(XEN_GtkStatusbar__P(statusbar), statusbar, 1, "gtk_statusbar_get_has_resize_grip", "GtkStatusbar*");
  return(C_TO_XEN_gboolean(gtk_statusbar_get_has_resize_grip(XEN_TO_C_GtkStatusbar_(statusbar))));
}
static XEN gxg_gtk_stock_add(XEN items, XEN n_items)
{
  #define H_gtk_stock_add "void gtk_stock_add(GtkStockItem* items, guint n_items)"
  XEN_ASSERT_TYPE(XEN_GtkStockItem__P(items), items, 1, "gtk_stock_add", "GtkStockItem*");
  XEN_ASSERT_TYPE(XEN_guint_P(n_items), n_items, 2, "gtk_stock_add", "guint");
  gtk_stock_add(XEN_TO_C_GtkStockItem_(items), XEN_TO_C_guint(n_items));
  return(XEN_FALSE);
}
static XEN gxg_gtk_stock_add_static(XEN items, XEN n_items)
{
  #define H_gtk_stock_add_static "void gtk_stock_add_static(GtkStockItem* items, guint n_items)"
  XEN_ASSERT_TYPE(XEN_GtkStockItem__P(items), items, 1, "gtk_stock_add_static", "GtkStockItem*");
  XEN_ASSERT_TYPE(XEN_guint_P(n_items), n_items, 2, "gtk_stock_add_static", "guint");
  gtk_stock_add_static(XEN_TO_C_GtkStockItem_(items), XEN_TO_C_guint(n_items));
  return(XEN_FALSE);
}
static XEN gxg_gtk_stock_lookup(XEN stock_id, XEN item)
{
  #define H_gtk_stock_lookup "gboolean gtk_stock_lookup(gchar* stock_id, GtkStockItem* item)"
  XEN_ASSERT_TYPE(XEN_gchar__P(stock_id), stock_id, 1, "gtk_stock_lookup", "gchar*");
  XEN_ASSERT_TYPE(XEN_GtkStockItem__P(item), item, 2, "gtk_stock_lookup", "GtkStockItem*");
  return(C_TO_XEN_gboolean(gtk_stock_lookup(XEN_TO_C_gchar_(stock_id), XEN_TO_C_GtkStockItem_(item))));
}
static XEN gxg_gtk_stock_list_ids(void)
{
  #define H_gtk_stock_list_ids "GSList* gtk_stock_list_ids( void)"
  return(C_TO_XEN_GSList_(gtk_stock_list_ids()));
}
static XEN gxg_gtk_stock_item_copy(XEN item)
{
  #define H_gtk_stock_item_copy "GtkStockItem* gtk_stock_item_copy(GtkStockItem* item)"
  XEN_ASSERT_TYPE(XEN_GtkStockItem__P(item), item, 1, "gtk_stock_item_copy", "GtkStockItem*");
  return(C_TO_XEN_GtkStockItem_(gtk_stock_item_copy(XEN_TO_C_GtkStockItem_(item))));
}
static XEN gxg_gtk_stock_item_free(XEN item)
{
  #define H_gtk_stock_item_free "void gtk_stock_item_free(GtkStockItem* item)"
  XEN_ASSERT_TYPE(XEN_GtkStockItem__P(item), item, 1, "gtk_stock_item_free", "GtkStockItem*");
  gtk_stock_item_free(XEN_TO_C_GtkStockItem_(item));
  return(XEN_FALSE);
}
static XEN gxg_gtk_style_get_type(void)
{
  #define H_gtk_style_get_type "GType gtk_style_get_type( void)"
  return(C_TO_XEN_GType(gtk_style_get_type()));
}
static XEN gxg_gtk_style_new(void)
{
  #define H_gtk_style_new "GtkStyle* gtk_style_new( void)"
  return(C_TO_XEN_GtkStyle_(gtk_style_new()));
}
static XEN gxg_gtk_style_copy(XEN style)
{
  #define H_gtk_style_copy "GtkStyle* gtk_style_copy(GtkStyle* style)"
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(style), style, 1, "gtk_style_copy", "GtkStyle*");
  return(C_TO_XEN_GtkStyle_(gtk_style_copy(XEN_TO_C_GtkStyle_(style))));
}
static XEN gxg_gtk_style_attach(XEN style, XEN window)
{
  #define H_gtk_style_attach "GtkStyle* gtk_style_attach(GtkStyle* style, GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(style), style, 1, "gtk_style_attach", "GtkStyle*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 2, "gtk_style_attach", "GdkWindow*");
  return(C_TO_XEN_GtkStyle_(gtk_style_attach(XEN_TO_C_GtkStyle_(style), XEN_TO_C_GdkWindow_(window))));
}
static XEN gxg_gtk_style_detach(XEN style)
{
  #define H_gtk_style_detach "void gtk_style_detach(GtkStyle* style)"
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(style), style, 1, "gtk_style_detach", "GtkStyle*");
  gtk_style_detach(XEN_TO_C_GtkStyle_(style));
  return(XEN_FALSE);
}
static XEN gxg_gtk_style_set_background(XEN style, XEN window, XEN state_type)
{
  #define H_gtk_style_set_background "void gtk_style_set_background(GtkStyle* style, GdkWindow* window, \
GtkStateType state_type)"
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(style), style, 1, "gtk_style_set_background", "GtkStyle*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 2, "gtk_style_set_background", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state_type), state_type, 3, "gtk_style_set_background", "GtkStateType");
  gtk_style_set_background(XEN_TO_C_GtkStyle_(style), XEN_TO_C_GdkWindow_(window), XEN_TO_C_GtkStateType(state_type));
  return(XEN_FALSE);
}
static XEN gxg_gtk_style_apply_default_background(XEN style, XEN window, XEN set_bg, XEN state_type, XEN area, XEN x, XEN y, XEN width, XEN height)
{
  #define H_gtk_style_apply_default_background "void gtk_style_apply_default_background(GtkStyle* style, \
GdkWindow* window, gboolean set_bg, GtkStateType state_type, GdkRectangle* area, gint x, gint y, gint width, \
gint height)"
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(style), style, 1, "gtk_style_apply_default_background", "GtkStyle*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 2, "gtk_style_apply_default_background", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(set_bg), set_bg, 3, "gtk_style_apply_default_background", "gboolean");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state_type), state_type, 4, "gtk_style_apply_default_background", "GtkStateType");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(area), area, 5, "gtk_style_apply_default_background", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 6, "gtk_style_apply_default_background", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 7, "gtk_style_apply_default_background", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 8, "gtk_style_apply_default_background", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 9, "gtk_style_apply_default_background", "gint");
  gtk_style_apply_default_background(XEN_TO_C_GtkStyle_(style), XEN_TO_C_GdkWindow_(window), XEN_TO_C_gboolean(set_bg), XEN_TO_C_GtkStateType(state_type), 
                                     XEN_TO_C_GdkRectangle_(area), XEN_TO_C_gint(x), XEN_TO_C_gint(y), XEN_TO_C_gint(width), 
                                     XEN_TO_C_gint(height));
  return(XEN_FALSE);
}
static XEN gxg_gtk_style_lookup_icon_set(XEN style, XEN stock_id)
{
  #define H_gtk_style_lookup_icon_set "GtkIconSet* gtk_style_lookup_icon_set(GtkStyle* style, gchar* stock_id)"
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(style), style, 1, "gtk_style_lookup_icon_set", "GtkStyle*");
  XEN_ASSERT_TYPE(XEN_gchar__P(stock_id), stock_id, 2, "gtk_style_lookup_icon_set", "gchar*");
  return(C_TO_XEN_GtkIconSet_(gtk_style_lookup_icon_set(XEN_TO_C_GtkStyle_(style), XEN_TO_C_gchar_(stock_id))));
}
static XEN gxg_gtk_style_render_icon(XEN style, XEN source, XEN direction, XEN state, XEN size, XEN widget, XEN detail)
{
  #define H_gtk_style_render_icon "GdkPixbuf* gtk_style_render_icon(GtkStyle* style, GtkIconSource* source, \
GtkTextDirection direction, GtkStateType state, GtkIconSize size, GtkWidget* widget, gchar* detail)"
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(style), style, 1, "gtk_style_render_icon", "GtkStyle*");
  XEN_ASSERT_TYPE(XEN_GtkIconSource__P(source), source, 2, "gtk_style_render_icon", "GtkIconSource*");
  XEN_ASSERT_TYPE(XEN_GtkTextDirection_P(direction), direction, 3, "gtk_style_render_icon", "GtkTextDirection");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state), state, 4, "gtk_style_render_icon", "GtkStateType");
  XEN_ASSERT_TYPE(XEN_GtkIconSize_P(size), size, 5, "gtk_style_render_icon", "GtkIconSize");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 6, "gtk_style_render_icon", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(detail), detail, 7, "gtk_style_render_icon", "gchar*");
  return(C_TO_XEN_GdkPixbuf_(gtk_style_render_icon(XEN_TO_C_GtkStyle_(style), XEN_TO_C_GtkIconSource_(source), XEN_TO_C_GtkTextDirection(direction), 
                                                   XEN_TO_C_GtkStateType(state), XEN_TO_C_GtkIconSize(size), XEN_TO_C_GtkWidget_(widget), 
                                                   XEN_TO_C_gchar_(detail))));
}
static XEN gxg_gtk_paint_hline(XEN style, XEN window, XEN state_type, XEN area, XEN widget, XEN detail, XEN x1, XEN x2, XEN y)
{
  #define H_gtk_paint_hline "void gtk_paint_hline(GtkStyle* style, GdkWindow* window, GtkStateType state_type, \
GdkRectangle* area, GtkWidget* widget, gchar* detail, gint x1, gint x2, gint y)"
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(style), style, 1, "gtk_paint_hline", "GtkStyle*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 2, "gtk_paint_hline", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state_type), state_type, 3, "gtk_paint_hline", "GtkStateType");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(area), area, 4, "gtk_paint_hline", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 5, "gtk_paint_hline", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(detail), detail, 6, "gtk_paint_hline", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(x1), x1, 7, "gtk_paint_hline", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(x2), x2, 8, "gtk_paint_hline", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 9, "gtk_paint_hline", "gint");
  gtk_paint_hline(XEN_TO_C_GtkStyle_(style), XEN_TO_C_GdkWindow_(window), XEN_TO_C_GtkStateType(state_type), XEN_TO_C_GdkRectangle_(area), 
                  XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(detail), XEN_TO_C_gint(x1), XEN_TO_C_gint(x2), XEN_TO_C_gint(y));
  return(XEN_FALSE);
}
static XEN gxg_gtk_paint_vline(XEN style, XEN window, XEN state_type, XEN area, XEN widget, XEN detail, XEN y1, XEN y2, XEN x)
{
  #define H_gtk_paint_vline "void gtk_paint_vline(GtkStyle* style, GdkWindow* window, GtkStateType state_type, \
GdkRectangle* area, GtkWidget* widget, gchar* detail, gint y1, gint y2, gint x)"
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(style), style, 1, "gtk_paint_vline", "GtkStyle*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 2, "gtk_paint_vline", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state_type), state_type, 3, "gtk_paint_vline", "GtkStateType");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(area), area, 4, "gtk_paint_vline", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 5, "gtk_paint_vline", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(detail), detail, 6, "gtk_paint_vline", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(y1), y1, 7, "gtk_paint_vline", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y2), y2, 8, "gtk_paint_vline", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 9, "gtk_paint_vline", "gint");
  gtk_paint_vline(XEN_TO_C_GtkStyle_(style), XEN_TO_C_GdkWindow_(window), XEN_TO_C_GtkStateType(state_type), XEN_TO_C_GdkRectangle_(area), 
                  XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(detail), XEN_TO_C_gint(y1), XEN_TO_C_gint(y2), XEN_TO_C_gint(x));
  return(XEN_FALSE);
}
static XEN gxg_gtk_paint_shadow(XEN arglist)
{
  #define H_gtk_paint_shadow "void gtk_paint_shadow(GtkStyle* style, GdkWindow* window, GtkStateType state_type, \
GtkShadowType shadow_type, GdkRectangle* area, GtkWidget* widget, gchar* detail, gint x, gint y, gint width, \
gint height)"
  XEN style, window, state_type, shadow_type, area, widget, detail, x, y, width, height;
  style = XEN_LIST_REF(arglist, 0);
  window = XEN_LIST_REF(arglist, 1);
  state_type = XEN_LIST_REF(arglist, 2);
  shadow_type = XEN_LIST_REF(arglist, 3);
  area = XEN_LIST_REF(arglist, 4);
  widget = XEN_LIST_REF(arglist, 5);
  detail = XEN_LIST_REF(arglist, 6);
  x = XEN_LIST_REF(arglist, 7);
  y = XEN_LIST_REF(arglist, 8);
  width = XEN_LIST_REF(arglist, 9);
  height = XEN_LIST_REF(arglist, 10);
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(style), style, 1, "gtk_paint_shadow", "GtkStyle*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 2, "gtk_paint_shadow", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state_type), state_type, 3, "gtk_paint_shadow", "GtkStateType");
  XEN_ASSERT_TYPE(XEN_GtkShadowType_P(shadow_type), shadow_type, 4, "gtk_paint_shadow", "GtkShadowType");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(area), area, 5, "gtk_paint_shadow", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 6, "gtk_paint_shadow", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(detail), detail, 7, "gtk_paint_shadow", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 8, "gtk_paint_shadow", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 9, "gtk_paint_shadow", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 10, "gtk_paint_shadow", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 11, "gtk_paint_shadow", "gint");
  gtk_paint_shadow(XEN_TO_C_GtkStyle_(style), XEN_TO_C_GdkWindow_(window), XEN_TO_C_GtkStateType(state_type), XEN_TO_C_GtkShadowType(shadow_type), 
                   XEN_TO_C_GdkRectangle_(area), XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(detail), XEN_TO_C_gint(x), 
                   XEN_TO_C_gint(y), XEN_TO_C_gint(width), XEN_TO_C_gint(height));
  return(xen_return_first(XEN_FALSE, arglist));
}
static XEN gxg_gtk_paint_polygon(XEN arglist)
{
  #define H_gtk_paint_polygon "void gtk_paint_polygon(GtkStyle* style, GdkWindow* window, GtkStateType state_type, \
GtkShadowType shadow_type, GdkRectangle* area, GtkWidget* widget, gchar* detail, GdkPoint* points, gint npoints, \
gboolean fill)"
  XEN style, window, state_type, shadow_type, area, widget, detail, points, npoints, fill;
  style = XEN_LIST_REF(arglist, 0);
  window = XEN_LIST_REF(arglist, 1);
  state_type = XEN_LIST_REF(arglist, 2);
  shadow_type = XEN_LIST_REF(arglist, 3);
  area = XEN_LIST_REF(arglist, 4);
  widget = XEN_LIST_REF(arglist, 5);
  detail = XEN_LIST_REF(arglist, 6);
  points = XEN_LIST_REF(arglist, 7);
  npoints = XEN_LIST_REF(arglist, 8);
  fill = XEN_LIST_REF(arglist, 9);
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(style), style, 1, "gtk_paint_polygon", "GtkStyle*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 2, "gtk_paint_polygon", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state_type), state_type, 3, "gtk_paint_polygon", "GtkStateType");
  XEN_ASSERT_TYPE(XEN_GtkShadowType_P(shadow_type), shadow_type, 4, "gtk_paint_polygon", "GtkShadowType");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(area), area, 5, "gtk_paint_polygon", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 6, "gtk_paint_polygon", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(detail), detail, 7, "gtk_paint_polygon", "gchar*");
  XEN_ASSERT_TYPE(XEN_GdkPoint__P(points), points, 8, "gtk_paint_polygon", "GdkPoint*");
  XEN_ASSERT_TYPE(XEN_gint_P(npoints), npoints, 9, "gtk_paint_polygon", "gint");
  XEN_ASSERT_TYPE(XEN_gboolean_P(fill), fill, 10, "gtk_paint_polygon", "gboolean");
  gtk_paint_polygon(XEN_TO_C_GtkStyle_(style), XEN_TO_C_GdkWindow_(window), XEN_TO_C_GtkStateType(state_type), XEN_TO_C_GtkShadowType(shadow_type), 
                    XEN_TO_C_GdkRectangle_(area), XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(detail), XEN_TO_C_GdkPoint_(points), 
                    XEN_TO_C_gint(npoints), XEN_TO_C_gboolean(fill));
  return(xen_return_first(XEN_FALSE, arglist));
}
static XEN gxg_gtk_paint_arrow(XEN arglist)
{
  #define H_gtk_paint_arrow "void gtk_paint_arrow(GtkStyle* style, GdkWindow* window, GtkStateType state_type, \
GtkShadowType shadow_type, GdkRectangle* area, GtkWidget* widget, gchar* detail, GtkArrowType arrow_type, \
gboolean fill, gint x, gint y, gint width, gint height)"
  XEN style, window, state_type, shadow_type, area, widget, detail, arrow_type, fill, x, y, width, height;
  style = XEN_LIST_REF(arglist, 0);
  window = XEN_LIST_REF(arglist, 1);
  state_type = XEN_LIST_REF(arglist, 2);
  shadow_type = XEN_LIST_REF(arglist, 3);
  area = XEN_LIST_REF(arglist, 4);
  widget = XEN_LIST_REF(arglist, 5);
  detail = XEN_LIST_REF(arglist, 6);
  arrow_type = XEN_LIST_REF(arglist, 7);
  fill = XEN_LIST_REF(arglist, 8);
  x = XEN_LIST_REF(arglist, 9);
  y = XEN_LIST_REF(arglist, 10);
  width = XEN_LIST_REF(arglist, 11);
  height = XEN_LIST_REF(arglist, 12);
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(style), style, 1, "gtk_paint_arrow", "GtkStyle*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 2, "gtk_paint_arrow", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state_type), state_type, 3, "gtk_paint_arrow", "GtkStateType");
  XEN_ASSERT_TYPE(XEN_GtkShadowType_P(shadow_type), shadow_type, 4, "gtk_paint_arrow", "GtkShadowType");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(area), area, 5, "gtk_paint_arrow", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 6, "gtk_paint_arrow", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(detail), detail, 7, "gtk_paint_arrow", "gchar*");
  XEN_ASSERT_TYPE(XEN_GtkArrowType_P(arrow_type), arrow_type, 8, "gtk_paint_arrow", "GtkArrowType");
  XEN_ASSERT_TYPE(XEN_gboolean_P(fill), fill, 9, "gtk_paint_arrow", "gboolean");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 10, "gtk_paint_arrow", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 11, "gtk_paint_arrow", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 12, "gtk_paint_arrow", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 13, "gtk_paint_arrow", "gint");
  gtk_paint_arrow(XEN_TO_C_GtkStyle_(style), XEN_TO_C_GdkWindow_(window), XEN_TO_C_GtkStateType(state_type), XEN_TO_C_GtkShadowType(shadow_type), 
                  XEN_TO_C_GdkRectangle_(area), XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(detail), XEN_TO_C_GtkArrowType(arrow_type), 
                  XEN_TO_C_gboolean(fill), XEN_TO_C_gint(x), XEN_TO_C_gint(y), XEN_TO_C_gint(width), XEN_TO_C_gint(height));
  return(xen_return_first(XEN_FALSE, arglist));
}
static XEN gxg_gtk_paint_diamond(XEN arglist)
{
  #define H_gtk_paint_diamond "void gtk_paint_diamond(GtkStyle* style, GdkWindow* window, GtkStateType state_type, \
GtkShadowType shadow_type, GdkRectangle* area, GtkWidget* widget, gchar* detail, gint x, gint y, gint width, \
gint height)"
  XEN style, window, state_type, shadow_type, area, widget, detail, x, y, width, height;
  style = XEN_LIST_REF(arglist, 0);
  window = XEN_LIST_REF(arglist, 1);
  state_type = XEN_LIST_REF(arglist, 2);
  shadow_type = XEN_LIST_REF(arglist, 3);
  area = XEN_LIST_REF(arglist, 4);
  widget = XEN_LIST_REF(arglist, 5);
  detail = XEN_LIST_REF(arglist, 6);
  x = XEN_LIST_REF(arglist, 7);
  y = XEN_LIST_REF(arglist, 8);
  width = XEN_LIST_REF(arglist, 9);
  height = XEN_LIST_REF(arglist, 10);
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(style), style, 1, "gtk_paint_diamond", "GtkStyle*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 2, "gtk_paint_diamond", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state_type), state_type, 3, "gtk_paint_diamond", "GtkStateType");
  XEN_ASSERT_TYPE(XEN_GtkShadowType_P(shadow_type), shadow_type, 4, "gtk_paint_diamond", "GtkShadowType");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(area), area, 5, "gtk_paint_diamond", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 6, "gtk_paint_diamond", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(detail), detail, 7, "gtk_paint_diamond", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 8, "gtk_paint_diamond", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 9, "gtk_paint_diamond", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 10, "gtk_paint_diamond", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 11, "gtk_paint_diamond", "gint");
  gtk_paint_diamond(XEN_TO_C_GtkStyle_(style), XEN_TO_C_GdkWindow_(window), XEN_TO_C_GtkStateType(state_type), XEN_TO_C_GtkShadowType(shadow_type), 
                    XEN_TO_C_GdkRectangle_(area), XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(detail), XEN_TO_C_gint(x), 
                    XEN_TO_C_gint(y), XEN_TO_C_gint(width), XEN_TO_C_gint(height));
  return(xen_return_first(XEN_FALSE, arglist));
}
static XEN gxg_gtk_paint_box(XEN arglist)
{
  #define H_gtk_paint_box "void gtk_paint_box(GtkStyle* style, GdkWindow* window, GtkStateType state_type, \
GtkShadowType shadow_type, GdkRectangle* area, GtkWidget* widget, gchar* detail, gint x, gint y, gint width, \
gint height)"
  XEN style, window, state_type, shadow_type, area, widget, detail, x, y, width, height;
  style = XEN_LIST_REF(arglist, 0);
  window = XEN_LIST_REF(arglist, 1);
  state_type = XEN_LIST_REF(arglist, 2);
  shadow_type = XEN_LIST_REF(arglist, 3);
  area = XEN_LIST_REF(arglist, 4);
  widget = XEN_LIST_REF(arglist, 5);
  detail = XEN_LIST_REF(arglist, 6);
  x = XEN_LIST_REF(arglist, 7);
  y = XEN_LIST_REF(arglist, 8);
  width = XEN_LIST_REF(arglist, 9);
  height = XEN_LIST_REF(arglist, 10);
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(style), style, 1, "gtk_paint_box", "GtkStyle*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 2, "gtk_paint_box", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state_type), state_type, 3, "gtk_paint_box", "GtkStateType");
  XEN_ASSERT_TYPE(XEN_GtkShadowType_P(shadow_type), shadow_type, 4, "gtk_paint_box", "GtkShadowType");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(area), area, 5, "gtk_paint_box", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 6, "gtk_paint_box", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(detail), detail, 7, "gtk_paint_box", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 8, "gtk_paint_box", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 9, "gtk_paint_box", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 10, "gtk_paint_box", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 11, "gtk_paint_box", "gint");
  gtk_paint_box(XEN_TO_C_GtkStyle_(style), XEN_TO_C_GdkWindow_(window), XEN_TO_C_GtkStateType(state_type), XEN_TO_C_GtkShadowType(shadow_type), 
                XEN_TO_C_GdkRectangle_(area), XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(detail), XEN_TO_C_gint(x), XEN_TO_C_gint(y), 
                XEN_TO_C_gint(width), XEN_TO_C_gint(height));
  return(xen_return_first(XEN_FALSE, arglist));
}
static XEN gxg_gtk_paint_flat_box(XEN arglist)
{
  #define H_gtk_paint_flat_box "void gtk_paint_flat_box(GtkStyle* style, GdkWindow* window, GtkStateType state_type, \
GtkShadowType shadow_type, GdkRectangle* area, GtkWidget* widget, gchar* detail, gint x, gint y, gint width, \
gint height)"
  XEN style, window, state_type, shadow_type, area, widget, detail, x, y, width, height;
  style = XEN_LIST_REF(arglist, 0);
  window = XEN_LIST_REF(arglist, 1);
  state_type = XEN_LIST_REF(arglist, 2);
  shadow_type = XEN_LIST_REF(arglist, 3);
  area = XEN_LIST_REF(arglist, 4);
  widget = XEN_LIST_REF(arglist, 5);
  detail = XEN_LIST_REF(arglist, 6);
  x = XEN_LIST_REF(arglist, 7);
  y = XEN_LIST_REF(arglist, 8);
  width = XEN_LIST_REF(arglist, 9);
  height = XEN_LIST_REF(arglist, 10);
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(style), style, 1, "gtk_paint_flat_box", "GtkStyle*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 2, "gtk_paint_flat_box", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state_type), state_type, 3, "gtk_paint_flat_box", "GtkStateType");
  XEN_ASSERT_TYPE(XEN_GtkShadowType_P(shadow_type), shadow_type, 4, "gtk_paint_flat_box", "GtkShadowType");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(area), area, 5, "gtk_paint_flat_box", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 6, "gtk_paint_flat_box", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(detail), detail, 7, "gtk_paint_flat_box", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 8, "gtk_paint_flat_box", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 9, "gtk_paint_flat_box", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 10, "gtk_paint_flat_box", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 11, "gtk_paint_flat_box", "gint");
  gtk_paint_flat_box(XEN_TO_C_GtkStyle_(style), XEN_TO_C_GdkWindow_(window), XEN_TO_C_GtkStateType(state_type), XEN_TO_C_GtkShadowType(shadow_type), 
                     XEN_TO_C_GdkRectangle_(area), XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(detail), XEN_TO_C_gint(x), 
                     XEN_TO_C_gint(y), XEN_TO_C_gint(width), XEN_TO_C_gint(height));
  return(xen_return_first(XEN_FALSE, arglist));
}
static XEN gxg_gtk_paint_check(XEN arglist)
{
  #define H_gtk_paint_check "void gtk_paint_check(GtkStyle* style, GdkWindow* window, GtkStateType state_type, \
GtkShadowType shadow_type, GdkRectangle* area, GtkWidget* widget, gchar* detail, gint x, gint y, gint width, \
gint height)"
  XEN style, window, state_type, shadow_type, area, widget, detail, x, y, width, height;
  style = XEN_LIST_REF(arglist, 0);
  window = XEN_LIST_REF(arglist, 1);
  state_type = XEN_LIST_REF(arglist, 2);
  shadow_type = XEN_LIST_REF(arglist, 3);
  area = XEN_LIST_REF(arglist, 4);
  widget = XEN_LIST_REF(arglist, 5);
  detail = XEN_LIST_REF(arglist, 6);
  x = XEN_LIST_REF(arglist, 7);
  y = XEN_LIST_REF(arglist, 8);
  width = XEN_LIST_REF(arglist, 9);
  height = XEN_LIST_REF(arglist, 10);
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(style), style, 1, "gtk_paint_check", "GtkStyle*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 2, "gtk_paint_check", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state_type), state_type, 3, "gtk_paint_check", "GtkStateType");
  XEN_ASSERT_TYPE(XEN_GtkShadowType_P(shadow_type), shadow_type, 4, "gtk_paint_check", "GtkShadowType");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(area), area, 5, "gtk_paint_check", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 6, "gtk_paint_check", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(detail), detail, 7, "gtk_paint_check", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 8, "gtk_paint_check", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 9, "gtk_paint_check", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 10, "gtk_paint_check", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 11, "gtk_paint_check", "gint");
  gtk_paint_check(XEN_TO_C_GtkStyle_(style), XEN_TO_C_GdkWindow_(window), XEN_TO_C_GtkStateType(state_type), XEN_TO_C_GtkShadowType(shadow_type), 
                  XEN_TO_C_GdkRectangle_(area), XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(detail), XEN_TO_C_gint(x), XEN_TO_C_gint(y), 
                  XEN_TO_C_gint(width), XEN_TO_C_gint(height));
  return(xen_return_first(XEN_FALSE, arglist));
}
static XEN gxg_gtk_paint_option(XEN arglist)
{
  #define H_gtk_paint_option "void gtk_paint_option(GtkStyle* style, GdkWindow* window, GtkStateType state_type, \
GtkShadowType shadow_type, GdkRectangle* area, GtkWidget* widget, gchar* detail, gint x, gint y, gint width, \
gint height)"
  XEN style, window, state_type, shadow_type, area, widget, detail, x, y, width, height;
  style = XEN_LIST_REF(arglist, 0);
  window = XEN_LIST_REF(arglist, 1);
  state_type = XEN_LIST_REF(arglist, 2);
  shadow_type = XEN_LIST_REF(arglist, 3);
  area = XEN_LIST_REF(arglist, 4);
  widget = XEN_LIST_REF(arglist, 5);
  detail = XEN_LIST_REF(arglist, 6);
  x = XEN_LIST_REF(arglist, 7);
  y = XEN_LIST_REF(arglist, 8);
  width = XEN_LIST_REF(arglist, 9);
  height = XEN_LIST_REF(arglist, 10);
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(style), style, 1, "gtk_paint_option", "GtkStyle*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 2, "gtk_paint_option", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state_type), state_type, 3, "gtk_paint_option", "GtkStateType");
  XEN_ASSERT_TYPE(XEN_GtkShadowType_P(shadow_type), shadow_type, 4, "gtk_paint_option", "GtkShadowType");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(area), area, 5, "gtk_paint_option", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 6, "gtk_paint_option", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(detail), detail, 7, "gtk_paint_option", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 8, "gtk_paint_option", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 9, "gtk_paint_option", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 10, "gtk_paint_option", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 11, "gtk_paint_option", "gint");
  gtk_paint_option(XEN_TO_C_GtkStyle_(style), XEN_TO_C_GdkWindow_(window), XEN_TO_C_GtkStateType(state_type), XEN_TO_C_GtkShadowType(shadow_type), 
                   XEN_TO_C_GdkRectangle_(area), XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(detail), XEN_TO_C_gint(x), 
                   XEN_TO_C_gint(y), XEN_TO_C_gint(width), XEN_TO_C_gint(height));
  return(xen_return_first(XEN_FALSE, arglist));
}
static XEN gxg_gtk_paint_tab(XEN arglist)
{
  #define H_gtk_paint_tab "void gtk_paint_tab(GtkStyle* style, GdkWindow* window, GtkStateType state_type, \
GtkShadowType shadow_type, GdkRectangle* area, GtkWidget* widget, gchar* detail, gint x, gint y, gint width, \
gint height)"
  XEN style, window, state_type, shadow_type, area, widget, detail, x, y, width, height;
  style = XEN_LIST_REF(arglist, 0);
  window = XEN_LIST_REF(arglist, 1);
  state_type = XEN_LIST_REF(arglist, 2);
  shadow_type = XEN_LIST_REF(arglist, 3);
  area = XEN_LIST_REF(arglist, 4);
  widget = XEN_LIST_REF(arglist, 5);
  detail = XEN_LIST_REF(arglist, 6);
  x = XEN_LIST_REF(arglist, 7);
  y = XEN_LIST_REF(arglist, 8);
  width = XEN_LIST_REF(arglist, 9);
  height = XEN_LIST_REF(arglist, 10);
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(style), style, 1, "gtk_paint_tab", "GtkStyle*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 2, "gtk_paint_tab", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state_type), state_type, 3, "gtk_paint_tab", "GtkStateType");
  XEN_ASSERT_TYPE(XEN_GtkShadowType_P(shadow_type), shadow_type, 4, "gtk_paint_tab", "GtkShadowType");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(area), area, 5, "gtk_paint_tab", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 6, "gtk_paint_tab", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(detail), detail, 7, "gtk_paint_tab", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 8, "gtk_paint_tab", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 9, "gtk_paint_tab", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 10, "gtk_paint_tab", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 11, "gtk_paint_tab", "gint");
  gtk_paint_tab(XEN_TO_C_GtkStyle_(style), XEN_TO_C_GdkWindow_(window), XEN_TO_C_GtkStateType(state_type), XEN_TO_C_GtkShadowType(shadow_type), 
                XEN_TO_C_GdkRectangle_(area), XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(detail), XEN_TO_C_gint(x), XEN_TO_C_gint(y), 
                XEN_TO_C_gint(width), XEN_TO_C_gint(height));
  return(xen_return_first(XEN_FALSE, arglist));
}
static XEN gxg_gtk_paint_shadow_gap(XEN arglist)
{
  #define H_gtk_paint_shadow_gap "void gtk_paint_shadow_gap(GtkStyle* style, GdkWindow* window, GtkStateType state_type, \
GtkShadowType shadow_type, GdkRectangle* area, GtkWidget* widget, gchar* detail, gint x, gint y, gint width, \
gint height, GtkPositionType gap_side, gint gap_x, gint gap_width)"
  XEN style, window, state_type, shadow_type, area, widget, detail, x, y, width, height, gap_side, gap_x, gap_width;
  style = XEN_LIST_REF(arglist, 0);
  window = XEN_LIST_REF(arglist, 1);
  state_type = XEN_LIST_REF(arglist, 2);
  shadow_type = XEN_LIST_REF(arglist, 3);
  area = XEN_LIST_REF(arglist, 4);
  widget = XEN_LIST_REF(arglist, 5);
  detail = XEN_LIST_REF(arglist, 6);
  x = XEN_LIST_REF(arglist, 7);
  y = XEN_LIST_REF(arglist, 8);
  width = XEN_LIST_REF(arglist, 9);
  height = XEN_LIST_REF(arglist, 10);
  gap_side = XEN_LIST_REF(arglist, 11);
  gap_x = XEN_LIST_REF(arglist, 12);
  gap_width = XEN_LIST_REF(arglist, 13);
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(style), style, 1, "gtk_paint_shadow_gap", "GtkStyle*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 2, "gtk_paint_shadow_gap", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state_type), state_type, 3, "gtk_paint_shadow_gap", "GtkStateType");
  XEN_ASSERT_TYPE(XEN_GtkShadowType_P(shadow_type), shadow_type, 4, "gtk_paint_shadow_gap", "GtkShadowType");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(area), area, 5, "gtk_paint_shadow_gap", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 6, "gtk_paint_shadow_gap", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(detail), detail, 7, "gtk_paint_shadow_gap", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 8, "gtk_paint_shadow_gap", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 9, "gtk_paint_shadow_gap", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 10, "gtk_paint_shadow_gap", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 11, "gtk_paint_shadow_gap", "gint");
  XEN_ASSERT_TYPE(XEN_GtkPositionType_P(gap_side), gap_side, 12, "gtk_paint_shadow_gap", "GtkPositionType");
  XEN_ASSERT_TYPE(XEN_gint_P(gap_x), gap_x, 13, "gtk_paint_shadow_gap", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(gap_width), gap_width, 14, "gtk_paint_shadow_gap", "gint");
  gtk_paint_shadow_gap(XEN_TO_C_GtkStyle_(style), XEN_TO_C_GdkWindow_(window), XEN_TO_C_GtkStateType(state_type), XEN_TO_C_GtkShadowType(shadow_type), 
                       XEN_TO_C_GdkRectangle_(area), XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(detail), XEN_TO_C_gint(x), 
                       XEN_TO_C_gint(y), XEN_TO_C_gint(width), XEN_TO_C_gint(height), XEN_TO_C_GtkPositionType(gap_side), 
                       XEN_TO_C_gint(gap_x), XEN_TO_C_gint(gap_width));
  return(xen_return_first(XEN_FALSE, arglist));
}
static XEN gxg_gtk_paint_box_gap(XEN arglist)
{
  #define H_gtk_paint_box_gap "void gtk_paint_box_gap(GtkStyle* style, GdkWindow* window, GtkStateType state_type, \
GtkShadowType shadow_type, GdkRectangle* area, GtkWidget* widget, gchar* detail, gint x, gint y, gint width, \
gint height, GtkPositionType gap_side, gint gap_x, gint gap_width)"
  XEN style, window, state_type, shadow_type, area, widget, detail, x, y, width, height, gap_side, gap_x, gap_width;
  style = XEN_LIST_REF(arglist, 0);
  window = XEN_LIST_REF(arglist, 1);
  state_type = XEN_LIST_REF(arglist, 2);
  shadow_type = XEN_LIST_REF(arglist, 3);
  area = XEN_LIST_REF(arglist, 4);
  widget = XEN_LIST_REF(arglist, 5);
  detail = XEN_LIST_REF(arglist, 6);
  x = XEN_LIST_REF(arglist, 7);
  y = XEN_LIST_REF(arglist, 8);
  width = XEN_LIST_REF(arglist, 9);
  height = XEN_LIST_REF(arglist, 10);
  gap_side = XEN_LIST_REF(arglist, 11);
  gap_x = XEN_LIST_REF(arglist, 12);
  gap_width = XEN_LIST_REF(arglist, 13);
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(style), style, 1, "gtk_paint_box_gap", "GtkStyle*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 2, "gtk_paint_box_gap", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state_type), state_type, 3, "gtk_paint_box_gap", "GtkStateType");
  XEN_ASSERT_TYPE(XEN_GtkShadowType_P(shadow_type), shadow_type, 4, "gtk_paint_box_gap", "GtkShadowType");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(area), area, 5, "gtk_paint_box_gap", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 6, "gtk_paint_box_gap", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(detail), detail, 7, "gtk_paint_box_gap", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 8, "gtk_paint_box_gap", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 9, "gtk_paint_box_gap", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 10, "gtk_paint_box_gap", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 11, "gtk_paint_box_gap", "gint");
  XEN_ASSERT_TYPE(XEN_GtkPositionType_P(gap_side), gap_side, 12, "gtk_paint_box_gap", "GtkPositionType");
  XEN_ASSERT_TYPE(XEN_gint_P(gap_x), gap_x, 13, "gtk_paint_box_gap", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(gap_width), gap_width, 14, "gtk_paint_box_gap", "gint");
  gtk_paint_box_gap(XEN_TO_C_GtkStyle_(style), XEN_TO_C_GdkWindow_(window), XEN_TO_C_GtkStateType(state_type), XEN_TO_C_GtkShadowType(shadow_type), 
                    XEN_TO_C_GdkRectangle_(area), XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(detail), XEN_TO_C_gint(x), 
                    XEN_TO_C_gint(y), XEN_TO_C_gint(width), XEN_TO_C_gint(height), XEN_TO_C_GtkPositionType(gap_side), XEN_TO_C_gint(gap_x), 
                    XEN_TO_C_gint(gap_width));
  return(xen_return_first(XEN_FALSE, arglist));
}
static XEN gxg_gtk_paint_extension(XEN arglist)
{
  #define H_gtk_paint_extension "void gtk_paint_extension(GtkStyle* style, GdkWindow* window, GtkStateType state_type, \
GtkShadowType shadow_type, GdkRectangle* area, GtkWidget* widget, gchar* detail, gint x, gint y, gint width, \
gint height, GtkPositionType gap_side)"
  XEN style, window, state_type, shadow_type, area, widget, detail, x, y, width, height, gap_side;
  style = XEN_LIST_REF(arglist, 0);
  window = XEN_LIST_REF(arglist, 1);
  state_type = XEN_LIST_REF(arglist, 2);
  shadow_type = XEN_LIST_REF(arglist, 3);
  area = XEN_LIST_REF(arglist, 4);
  widget = XEN_LIST_REF(arglist, 5);
  detail = XEN_LIST_REF(arglist, 6);
  x = XEN_LIST_REF(arglist, 7);
  y = XEN_LIST_REF(arglist, 8);
  width = XEN_LIST_REF(arglist, 9);
  height = XEN_LIST_REF(arglist, 10);
  gap_side = XEN_LIST_REF(arglist, 11);
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(style), style, 1, "gtk_paint_extension", "GtkStyle*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 2, "gtk_paint_extension", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state_type), state_type, 3, "gtk_paint_extension", "GtkStateType");
  XEN_ASSERT_TYPE(XEN_GtkShadowType_P(shadow_type), shadow_type, 4, "gtk_paint_extension", "GtkShadowType");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(area), area, 5, "gtk_paint_extension", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 6, "gtk_paint_extension", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(detail), detail, 7, "gtk_paint_extension", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 8, "gtk_paint_extension", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 9, "gtk_paint_extension", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 10, "gtk_paint_extension", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 11, "gtk_paint_extension", "gint");
  XEN_ASSERT_TYPE(XEN_GtkPositionType_P(gap_side), gap_side, 12, "gtk_paint_extension", "GtkPositionType");
  gtk_paint_extension(XEN_TO_C_GtkStyle_(style), XEN_TO_C_GdkWindow_(window), XEN_TO_C_GtkStateType(state_type), XEN_TO_C_GtkShadowType(shadow_type), 
                      XEN_TO_C_GdkRectangle_(area), XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(detail), XEN_TO_C_gint(x), 
                      XEN_TO_C_gint(y), XEN_TO_C_gint(width), XEN_TO_C_gint(height), XEN_TO_C_GtkPositionType(gap_side));
  return(xen_return_first(XEN_FALSE, arglist));
}
static XEN gxg_gtk_paint_focus(XEN arglist)
{
  #define H_gtk_paint_focus "void gtk_paint_focus(GtkStyle* style, GdkWindow* window, GtkStateType state_type, \
GdkRectangle* area, GtkWidget* widget, gchar* detail, gint x, gint y, gint width, gint height)"
  XEN style, window, state_type, area, widget, detail, x, y, width, height;
  style = XEN_LIST_REF(arglist, 0);
  window = XEN_LIST_REF(arglist, 1);
  state_type = XEN_LIST_REF(arglist, 2);
  area = XEN_LIST_REF(arglist, 3);
  widget = XEN_LIST_REF(arglist, 4);
  detail = XEN_LIST_REF(arglist, 5);
  x = XEN_LIST_REF(arglist, 6);
  y = XEN_LIST_REF(arglist, 7);
  width = XEN_LIST_REF(arglist, 8);
  height = XEN_LIST_REF(arglist, 9);
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(style), style, 1, "gtk_paint_focus", "GtkStyle*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 2, "gtk_paint_focus", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state_type), state_type, 3, "gtk_paint_focus", "GtkStateType");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(area), area, 4, "gtk_paint_focus", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 5, "gtk_paint_focus", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(detail), detail, 6, "gtk_paint_focus", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 7, "gtk_paint_focus", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 8, "gtk_paint_focus", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 9, "gtk_paint_focus", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 10, "gtk_paint_focus", "gint");
  gtk_paint_focus(XEN_TO_C_GtkStyle_(style), XEN_TO_C_GdkWindow_(window), XEN_TO_C_GtkStateType(state_type), XEN_TO_C_GdkRectangle_(area), 
                  XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(detail), XEN_TO_C_gint(x), XEN_TO_C_gint(y), XEN_TO_C_gint(width), 
                  XEN_TO_C_gint(height));
  return(xen_return_first(XEN_FALSE, arglist));
}
static XEN gxg_gtk_paint_slider(XEN arglist)
{
  #define H_gtk_paint_slider "void gtk_paint_slider(GtkStyle* style, GdkWindow* window, GtkStateType state_type, \
GtkShadowType shadow_type, GdkRectangle* area, GtkWidget* widget, gchar* detail, gint x, gint y, gint width, \
gint height, GtkOrientation orientation)"
  XEN style, window, state_type, shadow_type, area, widget, detail, x, y, width, height, orientation;
  style = XEN_LIST_REF(arglist, 0);
  window = XEN_LIST_REF(arglist, 1);
  state_type = XEN_LIST_REF(arglist, 2);
  shadow_type = XEN_LIST_REF(arglist, 3);
  area = XEN_LIST_REF(arglist, 4);
  widget = XEN_LIST_REF(arglist, 5);
  detail = XEN_LIST_REF(arglist, 6);
  x = XEN_LIST_REF(arglist, 7);
  y = XEN_LIST_REF(arglist, 8);
  width = XEN_LIST_REF(arglist, 9);
  height = XEN_LIST_REF(arglist, 10);
  orientation = XEN_LIST_REF(arglist, 11);
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(style), style, 1, "gtk_paint_slider", "GtkStyle*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 2, "gtk_paint_slider", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state_type), state_type, 3, "gtk_paint_slider", "GtkStateType");
  XEN_ASSERT_TYPE(XEN_GtkShadowType_P(shadow_type), shadow_type, 4, "gtk_paint_slider", "GtkShadowType");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(area), area, 5, "gtk_paint_slider", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 6, "gtk_paint_slider", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(detail), detail, 7, "gtk_paint_slider", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 8, "gtk_paint_slider", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 9, "gtk_paint_slider", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 10, "gtk_paint_slider", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 11, "gtk_paint_slider", "gint");
  XEN_ASSERT_TYPE(XEN_GtkOrientation_P(orientation), orientation, 12, "gtk_paint_slider", "GtkOrientation");
  gtk_paint_slider(XEN_TO_C_GtkStyle_(style), XEN_TO_C_GdkWindow_(window), XEN_TO_C_GtkStateType(state_type), XEN_TO_C_GtkShadowType(shadow_type), 
                   XEN_TO_C_GdkRectangle_(area), XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(detail), XEN_TO_C_gint(x), 
                   XEN_TO_C_gint(y), XEN_TO_C_gint(width), XEN_TO_C_gint(height), XEN_TO_C_GtkOrientation(orientation));
  return(xen_return_first(XEN_FALSE, arglist));
}
static XEN gxg_gtk_paint_handle(XEN arglist)
{
  #define H_gtk_paint_handle "void gtk_paint_handle(GtkStyle* style, GdkWindow* window, GtkStateType state_type, \
GtkShadowType shadow_type, GdkRectangle* area, GtkWidget* widget, gchar* detail, gint x, gint y, gint width, \
gint height, GtkOrientation orientation)"
  XEN style, window, state_type, shadow_type, area, widget, detail, x, y, width, height, orientation;
  style = XEN_LIST_REF(arglist, 0);
  window = XEN_LIST_REF(arglist, 1);
  state_type = XEN_LIST_REF(arglist, 2);
  shadow_type = XEN_LIST_REF(arglist, 3);
  area = XEN_LIST_REF(arglist, 4);
  widget = XEN_LIST_REF(arglist, 5);
  detail = XEN_LIST_REF(arglist, 6);
  x = XEN_LIST_REF(arglist, 7);
  y = XEN_LIST_REF(arglist, 8);
  width = XEN_LIST_REF(arglist, 9);
  height = XEN_LIST_REF(arglist, 10);
  orientation = XEN_LIST_REF(arglist, 11);
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(style), style, 1, "gtk_paint_handle", "GtkStyle*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 2, "gtk_paint_handle", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state_type), state_type, 3, "gtk_paint_handle", "GtkStateType");
  XEN_ASSERT_TYPE(XEN_GtkShadowType_P(shadow_type), shadow_type, 4, "gtk_paint_handle", "GtkShadowType");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(area), area, 5, "gtk_paint_handle", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 6, "gtk_paint_handle", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(detail), detail, 7, "gtk_paint_handle", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 8, "gtk_paint_handle", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 9, "gtk_paint_handle", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 10, "gtk_paint_handle", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 11, "gtk_paint_handle", "gint");
  XEN_ASSERT_TYPE(XEN_GtkOrientation_P(orientation), orientation, 12, "gtk_paint_handle", "GtkOrientation");
  gtk_paint_handle(XEN_TO_C_GtkStyle_(style), XEN_TO_C_GdkWindow_(window), XEN_TO_C_GtkStateType(state_type), XEN_TO_C_GtkShadowType(shadow_type), 
                   XEN_TO_C_GdkRectangle_(area), XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(detail), XEN_TO_C_gint(x), 
                   XEN_TO_C_gint(y), XEN_TO_C_gint(width), XEN_TO_C_gint(height), XEN_TO_C_GtkOrientation(orientation));
  return(xen_return_first(XEN_FALSE, arglist));
}
static XEN gxg_gtk_paint_expander(XEN style, XEN window, XEN state_type, XEN area, XEN widget, XEN detail, XEN x, XEN y, XEN expander_style)
{
  #define H_gtk_paint_expander "void gtk_paint_expander(GtkStyle* style, GdkWindow* window, GtkStateType state_type, \
GdkRectangle* area, GtkWidget* widget, gchar* detail, gint x, gint y, GtkExpanderStyle expander_style)"
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(style), style, 1, "gtk_paint_expander", "GtkStyle*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 2, "gtk_paint_expander", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state_type), state_type, 3, "gtk_paint_expander", "GtkStateType");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(area), area, 4, "gtk_paint_expander", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 5, "gtk_paint_expander", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(detail), detail, 6, "gtk_paint_expander", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 7, "gtk_paint_expander", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 8, "gtk_paint_expander", "gint");
  XEN_ASSERT_TYPE(XEN_GtkExpanderStyle_P(expander_style), expander_style, 9, "gtk_paint_expander", "GtkExpanderStyle");
  gtk_paint_expander(XEN_TO_C_GtkStyle_(style), XEN_TO_C_GdkWindow_(window), XEN_TO_C_GtkStateType(state_type), XEN_TO_C_GdkRectangle_(area), 
                     XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(detail), XEN_TO_C_gint(x), XEN_TO_C_gint(y), XEN_TO_C_GtkExpanderStyle(expander_style));
  return(XEN_FALSE);
}
static XEN gxg_gtk_paint_layout(XEN arglist)
{
  #define H_gtk_paint_layout "void gtk_paint_layout(GtkStyle* style, GdkWindow* window, GtkStateType state_type, \
gboolean use_text, GdkRectangle* area, GtkWidget* widget, gchar* detail, gint x, gint y, PangoLayout* layout)"
  XEN style, window, state_type, use_text, area, widget, detail, x, y, layout;
  style = XEN_LIST_REF(arglist, 0);
  window = XEN_LIST_REF(arglist, 1);
  state_type = XEN_LIST_REF(arglist, 2);
  use_text = XEN_LIST_REF(arglist, 3);
  area = XEN_LIST_REF(arglist, 4);
  widget = XEN_LIST_REF(arglist, 5);
  detail = XEN_LIST_REF(arglist, 6);
  x = XEN_LIST_REF(arglist, 7);
  y = XEN_LIST_REF(arglist, 8);
  layout = XEN_LIST_REF(arglist, 9);
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(style), style, 1, "gtk_paint_layout", "GtkStyle*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 2, "gtk_paint_layout", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state_type), state_type, 3, "gtk_paint_layout", "GtkStateType");
  XEN_ASSERT_TYPE(XEN_gboolean_P(use_text), use_text, 4, "gtk_paint_layout", "gboolean");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(area), area, 5, "gtk_paint_layout", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 6, "gtk_paint_layout", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(detail), detail, 7, "gtk_paint_layout", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 8, "gtk_paint_layout", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 9, "gtk_paint_layout", "gint");
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 10, "gtk_paint_layout", "PangoLayout*");
  gtk_paint_layout(XEN_TO_C_GtkStyle_(style), XEN_TO_C_GdkWindow_(window), XEN_TO_C_GtkStateType(state_type), XEN_TO_C_gboolean(use_text), 
                   XEN_TO_C_GdkRectangle_(area), XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(detail), XEN_TO_C_gint(x), 
                   XEN_TO_C_gint(y), XEN_TO_C_PangoLayout_(layout));
  return(xen_return_first(XEN_FALSE, arglist));
}
static XEN gxg_gtk_paint_resize_grip(XEN arglist)
{
  #define H_gtk_paint_resize_grip "void gtk_paint_resize_grip(GtkStyle* style, GdkWindow* window, GtkStateType state_type, \
GdkRectangle* area, GtkWidget* widget, gchar* detail, GdkWindowEdge edge, gint x, gint y, gint width, \
gint height)"
  XEN style, window, state_type, area, widget, detail, edge, x, y, width, height;
  style = XEN_LIST_REF(arglist, 0);
  window = XEN_LIST_REF(arglist, 1);
  state_type = XEN_LIST_REF(arglist, 2);
  area = XEN_LIST_REF(arglist, 3);
  widget = XEN_LIST_REF(arglist, 4);
  detail = XEN_LIST_REF(arglist, 5);
  edge = XEN_LIST_REF(arglist, 6);
  x = XEN_LIST_REF(arglist, 7);
  y = XEN_LIST_REF(arglist, 8);
  width = XEN_LIST_REF(arglist, 9);
  height = XEN_LIST_REF(arglist, 10);
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(style), style, 1, "gtk_paint_resize_grip", "GtkStyle*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 2, "gtk_paint_resize_grip", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state_type), state_type, 3, "gtk_paint_resize_grip", "GtkStateType");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(area), area, 4, "gtk_paint_resize_grip", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 5, "gtk_paint_resize_grip", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(detail), detail, 6, "gtk_paint_resize_grip", "gchar*");
  XEN_ASSERT_TYPE(XEN_GdkWindowEdge_P(edge), edge, 7, "gtk_paint_resize_grip", "GdkWindowEdge");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 8, "gtk_paint_resize_grip", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 9, "gtk_paint_resize_grip", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 10, "gtk_paint_resize_grip", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 11, "gtk_paint_resize_grip", "gint");
  gtk_paint_resize_grip(XEN_TO_C_GtkStyle_(style), XEN_TO_C_GdkWindow_(window), XEN_TO_C_GtkStateType(state_type), XEN_TO_C_GdkRectangle_(area), 
                        XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(detail), XEN_TO_C_GdkWindowEdge(edge), XEN_TO_C_gint(x), 
                        XEN_TO_C_gint(y), XEN_TO_C_gint(width), XEN_TO_C_gint(height));
  return(xen_return_first(XEN_FALSE, arglist));
}
static XEN gxg_gtk_border_copy(XEN border)
{
  #define H_gtk_border_copy "GtkBorder* gtk_border_copy(GtkBorder* border)"
  XEN_ASSERT_TYPE(XEN_GtkBorder__P(border), border, 1, "gtk_border_copy", "GtkBorder*");
  return(C_TO_XEN_GtkBorder_(gtk_border_copy(XEN_TO_C_GtkBorder_(border))));
}
static XEN gxg_gtk_border_free(XEN border)
{
  #define H_gtk_border_free "void gtk_border_free(GtkBorder* border)"
  XEN_ASSERT_TYPE(XEN_GtkBorder__P(border), border, 1, "gtk_border_free", "GtkBorder*");
  gtk_border_free(XEN_TO_C_GtkBorder_(border));
  return(XEN_FALSE);
}
static XEN gxg_gtk_table_get_type(void)
{
  #define H_gtk_table_get_type "GtkType gtk_table_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_table_get_type()));
}
static XEN gxg_gtk_table_new(XEN rows, XEN columns, XEN homogeneous)
{
  #define H_gtk_table_new "GtkWidget* gtk_table_new(guint rows, guint columns, gboolean homogeneous)"
  XEN_ASSERT_TYPE(XEN_guint_P(rows), rows, 1, "gtk_table_new", "guint");
  XEN_ASSERT_TYPE(XEN_guint_P(columns), columns, 2, "gtk_table_new", "guint");
  XEN_ASSERT_TYPE(XEN_gboolean_P(homogeneous), homogeneous, 3, "gtk_table_new", "gboolean");
  return(C_TO_XEN_GtkWidget_(gtk_table_new(XEN_TO_C_guint(rows), XEN_TO_C_guint(columns), XEN_TO_C_gboolean(homogeneous))));
}
static XEN gxg_gtk_table_resize(XEN table, XEN rows, XEN columns)
{
  #define H_gtk_table_resize "void gtk_table_resize(GtkTable* table, guint rows, guint columns)"
  XEN_ASSERT_TYPE(XEN_GtkTable__P(table), table, 1, "gtk_table_resize", "GtkTable*");
  XEN_ASSERT_TYPE(XEN_guint_P(rows), rows, 2, "gtk_table_resize", "guint");
  XEN_ASSERT_TYPE(XEN_guint_P(columns), columns, 3, "gtk_table_resize", "guint");
  gtk_table_resize(XEN_TO_C_GtkTable_(table), XEN_TO_C_guint(rows), XEN_TO_C_guint(columns));
  return(XEN_FALSE);
}
static XEN gxg_gtk_table_attach(XEN arglist)
{
  #define H_gtk_table_attach "void gtk_table_attach(GtkTable* table, GtkWidget* child, guint left_attach, \
guint right_attach, guint top_attach, guint bottom_attach, GtkAttachOptions xoptions, GtkAttachOptions yoptions, \
guint xpadding, guint ypadding)"
  XEN table, child, left_attach, right_attach, top_attach, bottom_attach, xoptions, yoptions, xpadding, ypadding;
  table = XEN_LIST_REF(arglist, 0);
  child = XEN_LIST_REF(arglist, 1);
  left_attach = XEN_LIST_REF(arglist, 2);
  right_attach = XEN_LIST_REF(arglist, 3);
  top_attach = XEN_LIST_REF(arglist, 4);
  bottom_attach = XEN_LIST_REF(arglist, 5);
  xoptions = XEN_LIST_REF(arglist, 6);
  yoptions = XEN_LIST_REF(arglist, 7);
  xpadding = XEN_LIST_REF(arglist, 8);
  ypadding = XEN_LIST_REF(arglist, 9);
  XEN_ASSERT_TYPE(XEN_GtkTable__P(table), table, 1, "gtk_table_attach", "GtkTable*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_table_attach", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_guint_P(left_attach), left_attach, 3, "gtk_table_attach", "guint");
  XEN_ASSERT_TYPE(XEN_guint_P(right_attach), right_attach, 4, "gtk_table_attach", "guint");
  XEN_ASSERT_TYPE(XEN_guint_P(top_attach), top_attach, 5, "gtk_table_attach", "guint");
  XEN_ASSERT_TYPE(XEN_guint_P(bottom_attach), bottom_attach, 6, "gtk_table_attach", "guint");
  XEN_ASSERT_TYPE(XEN_GtkAttachOptions_P(xoptions), xoptions, 7, "gtk_table_attach", "GtkAttachOptions");
  XEN_ASSERT_TYPE(XEN_GtkAttachOptions_P(yoptions), yoptions, 8, "gtk_table_attach", "GtkAttachOptions");
  XEN_ASSERT_TYPE(XEN_guint_P(xpadding), xpadding, 9, "gtk_table_attach", "guint");
  XEN_ASSERT_TYPE(XEN_guint_P(ypadding), ypadding, 10, "gtk_table_attach", "guint");
  gtk_table_attach(XEN_TO_C_GtkTable_(table), XEN_TO_C_GtkWidget_(child), XEN_TO_C_guint(left_attach), XEN_TO_C_guint(right_attach), 
                   XEN_TO_C_guint(top_attach), XEN_TO_C_guint(bottom_attach), XEN_TO_C_GtkAttachOptions(xoptions), XEN_TO_C_GtkAttachOptions(yoptions), 
                   XEN_TO_C_guint(xpadding), XEN_TO_C_guint(ypadding));
  return(xen_return_first(XEN_FALSE, arglist));
}
static XEN gxg_gtk_table_attach_defaults(XEN table, XEN widget, XEN left_attach, XEN right_attach, XEN top_attach, XEN bottom_attach)
{
  #define H_gtk_table_attach_defaults "void gtk_table_attach_defaults(GtkTable* table, GtkWidget* widget, \
guint left_attach, guint right_attach, guint top_attach, guint bottom_attach)"
  XEN_ASSERT_TYPE(XEN_GtkTable__P(table), table, 1, "gtk_table_attach_defaults", "GtkTable*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 2, "gtk_table_attach_defaults", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_guint_P(left_attach), left_attach, 3, "gtk_table_attach_defaults", "guint");
  XEN_ASSERT_TYPE(XEN_guint_P(right_attach), right_attach, 4, "gtk_table_attach_defaults", "guint");
  XEN_ASSERT_TYPE(XEN_guint_P(top_attach), top_attach, 5, "gtk_table_attach_defaults", "guint");
  XEN_ASSERT_TYPE(XEN_guint_P(bottom_attach), bottom_attach, 6, "gtk_table_attach_defaults", "guint");
  gtk_table_attach_defaults(XEN_TO_C_GtkTable_(table), XEN_TO_C_GtkWidget_(widget), XEN_TO_C_guint(left_attach), XEN_TO_C_guint(right_attach), 
                            XEN_TO_C_guint(top_attach), XEN_TO_C_guint(bottom_attach));
  return(XEN_FALSE);
}
static XEN gxg_gtk_table_set_row_spacing(XEN table, XEN row, XEN spacing)
{
  #define H_gtk_table_set_row_spacing "void gtk_table_set_row_spacing(GtkTable* table, guint row, guint spacing)"
  XEN_ASSERT_TYPE(XEN_GtkTable__P(table), table, 1, "gtk_table_set_row_spacing", "GtkTable*");
  XEN_ASSERT_TYPE(XEN_guint_P(row), row, 2, "gtk_table_set_row_spacing", "guint");
  XEN_ASSERT_TYPE(XEN_guint_P(spacing), spacing, 3, "gtk_table_set_row_spacing", "guint");
  gtk_table_set_row_spacing(XEN_TO_C_GtkTable_(table), XEN_TO_C_guint(row), XEN_TO_C_guint(spacing));
  return(XEN_FALSE);
}
static XEN gxg_gtk_table_get_row_spacing(XEN table, XEN row)
{
  #define H_gtk_table_get_row_spacing "guint gtk_table_get_row_spacing(GtkTable* table, guint row)"
  XEN_ASSERT_TYPE(XEN_GtkTable__P(table), table, 1, "gtk_table_get_row_spacing", "GtkTable*");
  XEN_ASSERT_TYPE(XEN_guint_P(row), row, 2, "gtk_table_get_row_spacing", "guint");
  return(C_TO_XEN_guint(gtk_table_get_row_spacing(XEN_TO_C_GtkTable_(table), XEN_TO_C_guint(row))));
}
static XEN gxg_gtk_table_set_col_spacing(XEN table, XEN column, XEN spacing)
{
  #define H_gtk_table_set_col_spacing "void gtk_table_set_col_spacing(GtkTable* table, guint column, \
guint spacing)"
  XEN_ASSERT_TYPE(XEN_GtkTable__P(table), table, 1, "gtk_table_set_col_spacing", "GtkTable*");
  XEN_ASSERT_TYPE(XEN_guint_P(column), column, 2, "gtk_table_set_col_spacing", "guint");
  XEN_ASSERT_TYPE(XEN_guint_P(spacing), spacing, 3, "gtk_table_set_col_spacing", "guint");
  gtk_table_set_col_spacing(XEN_TO_C_GtkTable_(table), XEN_TO_C_guint(column), XEN_TO_C_guint(spacing));
  return(XEN_FALSE);
}
static XEN gxg_gtk_table_get_col_spacing(XEN table, XEN column)
{
  #define H_gtk_table_get_col_spacing "guint gtk_table_get_col_spacing(GtkTable* table, guint column)"
  XEN_ASSERT_TYPE(XEN_GtkTable__P(table), table, 1, "gtk_table_get_col_spacing", "GtkTable*");
  XEN_ASSERT_TYPE(XEN_guint_P(column), column, 2, "gtk_table_get_col_spacing", "guint");
  return(C_TO_XEN_guint(gtk_table_get_col_spacing(XEN_TO_C_GtkTable_(table), XEN_TO_C_guint(column))));
}
static XEN gxg_gtk_table_set_row_spacings(XEN table, XEN spacing)
{
  #define H_gtk_table_set_row_spacings "void gtk_table_set_row_spacings(GtkTable* table, guint spacing)"
  XEN_ASSERT_TYPE(XEN_GtkTable__P(table), table, 1, "gtk_table_set_row_spacings", "GtkTable*");
  XEN_ASSERT_TYPE(XEN_guint_P(spacing), spacing, 2, "gtk_table_set_row_spacings", "guint");
  gtk_table_set_row_spacings(XEN_TO_C_GtkTable_(table), XEN_TO_C_guint(spacing));
  return(XEN_FALSE);
}
static XEN gxg_gtk_table_get_default_row_spacing(XEN table)
{
  #define H_gtk_table_get_default_row_spacing "guint gtk_table_get_default_row_spacing(GtkTable* table)"
  XEN_ASSERT_TYPE(XEN_GtkTable__P(table), table, 1, "gtk_table_get_default_row_spacing", "GtkTable*");
  return(C_TO_XEN_guint(gtk_table_get_default_row_spacing(XEN_TO_C_GtkTable_(table))));
}
static XEN gxg_gtk_table_set_col_spacings(XEN table, XEN spacing)
{
  #define H_gtk_table_set_col_spacings "void gtk_table_set_col_spacings(GtkTable* table, guint spacing)"
  XEN_ASSERT_TYPE(XEN_GtkTable__P(table), table, 1, "gtk_table_set_col_spacings", "GtkTable*");
  XEN_ASSERT_TYPE(XEN_guint_P(spacing), spacing, 2, "gtk_table_set_col_spacings", "guint");
  gtk_table_set_col_spacings(XEN_TO_C_GtkTable_(table), XEN_TO_C_guint(spacing));
  return(XEN_FALSE);
}
static XEN gxg_gtk_table_get_default_col_spacing(XEN table)
{
  #define H_gtk_table_get_default_col_spacing "guint gtk_table_get_default_col_spacing(GtkTable* table)"
  XEN_ASSERT_TYPE(XEN_GtkTable__P(table), table, 1, "gtk_table_get_default_col_spacing", "GtkTable*");
  return(C_TO_XEN_guint(gtk_table_get_default_col_spacing(XEN_TO_C_GtkTable_(table))));
}
static XEN gxg_gtk_table_set_homogeneous(XEN table, XEN homogeneous)
{
  #define H_gtk_table_set_homogeneous "void gtk_table_set_homogeneous(GtkTable* table, gboolean homogeneous)"
  XEN_ASSERT_TYPE(XEN_GtkTable__P(table), table, 1, "gtk_table_set_homogeneous", "GtkTable*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(homogeneous), homogeneous, 2, "gtk_table_set_homogeneous", "gboolean");
  gtk_table_set_homogeneous(XEN_TO_C_GtkTable_(table), XEN_TO_C_gboolean(homogeneous));
  return(XEN_FALSE);
}
static XEN gxg_gtk_table_get_homogeneous(XEN table)
{
  #define H_gtk_table_get_homogeneous "gboolean gtk_table_get_homogeneous(GtkTable* table)"
  XEN_ASSERT_TYPE(XEN_GtkTable__P(table), table, 1, "gtk_table_get_homogeneous", "GtkTable*");
  return(C_TO_XEN_gboolean(gtk_table_get_homogeneous(XEN_TO_C_GtkTable_(table))));
}
static XEN gxg_gtk_tearoff_menu_item_get_type(void)
{
  #define H_gtk_tearoff_menu_item_get_type "GtkType gtk_tearoff_menu_item_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_tearoff_menu_item_get_type()));
}
static XEN gxg_gtk_tearoff_menu_item_new(void)
{
  #define H_gtk_tearoff_menu_item_new "GtkWidget* gtk_tearoff_menu_item_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_tearoff_menu_item_new()));
}
static XEN gxg_gtk_text_buffer_get_type(void)
{
  #define H_gtk_text_buffer_get_type "GType gtk_text_buffer_get_type( void)"
  return(C_TO_XEN_GType(gtk_text_buffer_get_type()));
}
static XEN gxg_gtk_text_buffer_new(XEN table)
{
  #define H_gtk_text_buffer_new "GtkTextBuffer* gtk_text_buffer_new(GtkTextTagTable* table)"
  XEN_ASSERT_TYPE(XEN_GtkTextTagTable__P(table), table, 1, "gtk_text_buffer_new", "GtkTextTagTable*");
  return(C_TO_XEN_GtkTextBuffer_(gtk_text_buffer_new(XEN_TO_C_GtkTextTagTable_(table))));
}
static XEN gxg_gtk_text_buffer_get_line_count(XEN buffer)
{
  #define H_gtk_text_buffer_get_line_count "gint gtk_text_buffer_get_line_count(GtkTextBuffer* buffer)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_get_line_count", "GtkTextBuffer*");
  return(C_TO_XEN_gint(gtk_text_buffer_get_line_count(XEN_TO_C_GtkTextBuffer_(buffer))));
}
static XEN gxg_gtk_text_buffer_get_char_count(XEN buffer)
{
  #define H_gtk_text_buffer_get_char_count "gint gtk_text_buffer_get_char_count(GtkTextBuffer* buffer)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_get_char_count", "GtkTextBuffer*");
  return(C_TO_XEN_gint(gtk_text_buffer_get_char_count(XEN_TO_C_GtkTextBuffer_(buffer))));
}
static XEN gxg_gtk_text_buffer_get_tag_table(XEN buffer)
{
  #define H_gtk_text_buffer_get_tag_table "GtkTextTagTable* gtk_text_buffer_get_tag_table(GtkTextBuffer* buffer)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_get_tag_table", "GtkTextBuffer*");
  return(C_TO_XEN_GtkTextTagTable_(gtk_text_buffer_get_tag_table(XEN_TO_C_GtkTextBuffer_(buffer))));
}
static XEN gxg_gtk_text_buffer_set_text(XEN buffer, XEN text, XEN len)
{
  #define H_gtk_text_buffer_set_text "void gtk_text_buffer_set_text(GtkTextBuffer* buffer, gchar* text, \
gint len)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_set_text", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_gchar__P(text), text, 2, "gtk_text_buffer_set_text", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(len), len, 3, "gtk_text_buffer_set_text", "gint");
  gtk_text_buffer_set_text(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_gchar_(text), XEN_TO_C_gint(len));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_insert(XEN buffer, XEN iter, XEN text, XEN len)
{
  #define H_gtk_text_buffer_insert "void gtk_text_buffer_insert(GtkTextBuffer* buffer, GtkTextIter* iter, \
gchar* text, gint len)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_insert", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 2, "gtk_text_buffer_insert", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gchar__P(text), text, 3, "gtk_text_buffer_insert", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(len), len, 4, "gtk_text_buffer_insert", "gint");
  gtk_text_buffer_insert(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gchar_(text), XEN_TO_C_gint(len));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_insert_at_cursor(XEN buffer, XEN text, XEN len)
{
  #define H_gtk_text_buffer_insert_at_cursor "void gtk_text_buffer_insert_at_cursor(GtkTextBuffer* buffer, \
gchar* text, gint len)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_insert_at_cursor", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_gchar__P(text), text, 2, "gtk_text_buffer_insert_at_cursor", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(len), len, 3, "gtk_text_buffer_insert_at_cursor", "gint");
  gtk_text_buffer_insert_at_cursor(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_gchar_(text), XEN_TO_C_gint(len));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_insert_interactive(XEN buffer, XEN iter, XEN text, XEN len, XEN default_editable)
{
  #define H_gtk_text_buffer_insert_interactive "gboolean gtk_text_buffer_insert_interactive(GtkTextBuffer* buffer, \
GtkTextIter* iter, gchar* text, gint len, gboolean default_editable)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_insert_interactive", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 2, "gtk_text_buffer_insert_interactive", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gchar__P(text), text, 3, "gtk_text_buffer_insert_interactive", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(len), len, 4, "gtk_text_buffer_insert_interactive", "gint");
  XEN_ASSERT_TYPE(XEN_gboolean_P(default_editable), default_editable, 5, "gtk_text_buffer_insert_interactive", "gboolean");
  return(C_TO_XEN_gboolean(gtk_text_buffer_insert_interactive(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkTextIter_(iter), 
                                                              XEN_TO_C_gchar_(text), XEN_TO_C_gint(len), XEN_TO_C_gboolean(default_editable))));
}
static XEN gxg_gtk_text_buffer_insert_interactive_at_cursor(XEN buffer, XEN text, XEN len, XEN default_editable)
{
  #define H_gtk_text_buffer_insert_interactive_at_cursor "gboolean gtk_text_buffer_insert_interactive_at_cursor(GtkTextBuffer* buffer, \
gchar* text, gint len, gboolean default_editable)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_insert_interactive_at_cursor", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_gchar__P(text), text, 2, "gtk_text_buffer_insert_interactive_at_cursor", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(len), len, 3, "gtk_text_buffer_insert_interactive_at_cursor", "gint");
  XEN_ASSERT_TYPE(XEN_gboolean_P(default_editable), default_editable, 4, "gtk_text_buffer_insert_interactive_at_cursor", "gboolean");
  return(C_TO_XEN_gboolean(gtk_text_buffer_insert_interactive_at_cursor(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_gchar_(text), 
                                                                        XEN_TO_C_gint(len), XEN_TO_C_gboolean(default_editable))));
}
static XEN gxg_gtk_text_buffer_insert_range(XEN buffer, XEN iter, XEN start, XEN end)
{
  #define H_gtk_text_buffer_insert_range "void gtk_text_buffer_insert_range(GtkTextBuffer* buffer, GtkTextIter* iter, \
GtkTextIter* start, GtkTextIter* end)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_insert_range", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 2, "gtk_text_buffer_insert_range", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(start), start, 3, "gtk_text_buffer_insert_range", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(end), end, 4, "gtk_text_buffer_insert_range", "GtkTextIter*");
  gtk_text_buffer_insert_range(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_GtkTextIter_(start), 
                               XEN_TO_C_GtkTextIter_(end));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_insert_range_interactive(XEN buffer, XEN iter, XEN start, XEN end, XEN default_editable)
{
  #define H_gtk_text_buffer_insert_range_interactive "gboolean gtk_text_buffer_insert_range_interactive(GtkTextBuffer* buffer, \
GtkTextIter* iter, GtkTextIter* start, GtkTextIter* end, gboolean default_editable)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_insert_range_interactive", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 2, "gtk_text_buffer_insert_range_interactive", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(start), start, 3, "gtk_text_buffer_insert_range_interactive", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(end), end, 4, "gtk_text_buffer_insert_range_interactive", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(default_editable), default_editable, 5, "gtk_text_buffer_insert_range_interactive", "gboolean");
  return(C_TO_XEN_gboolean(gtk_text_buffer_insert_range_interactive(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkTextIter_(iter), 
                                                                    XEN_TO_C_GtkTextIter_(start), XEN_TO_C_GtkTextIter_(end), 
                                                                    XEN_TO_C_gboolean(default_editable))));
}
static XEN gxg_gtk_text_buffer_insert_with_tags(XEN buffer, XEN iter, XEN text, XEN len, XEN tags)
{
  #define H_gtk_text_buffer_insert_with_tags "void gtk_text_buffer_insert_with_tags(GtkTextBuffer* buffer, \
GtkTextIter* iter, gchar* text, gint len, etc tags)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_insert_with_tags", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 2, "gtk_text_buffer_insert_with_tags", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gchar__P(text), text, 3, "gtk_text_buffer_insert_with_tags", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(len), len, 4, "gtk_text_buffer_insert_with_tags", "gint");
  XEN_ASSERT_TYPE(XEN_etc_P(tags), tags, 5, "gtk_text_buffer_insert_with_tags", "etc");
  {
    int etc_len = 0;
    GtkTextBuffer* p_arg0;
    GtkTextIter* p_arg1;
    gchar* p_arg2;
    gint p_arg3;
    if (XEN_LIST_P(tags)) etc_len = XEN_LIST_LENGTH(tags);
    if (etc_len < 1) XEN_OUT_OF_RANGE_ERROR("gtk_text_buffer_insert_with_tags", 4, tags, "... list must have at least 1 entry");
    if (etc_len > 6) XEN_OUT_OF_RANGE_ERROR("gtk_text_buffer_insert_with_tags", 4, tags, "... list too long (max len: 6)");
    p_arg0 = XEN_TO_C_GtkTextBuffer_(buffer);
    p_arg1 = XEN_TO_C_GtkTextIter_(iter);
    p_arg2 = XEN_TO_C_gchar_(text);
    p_arg3 = XEN_TO_C_gint(len);
    switch (etc_len)
      {
        case 1: gtk_text_buffer_insert_with_tags(p_arg0, p_arg1, p_arg2, p_arg3, XLT(tags, 0), NULL); break;
        case 2: gtk_text_buffer_insert_with_tags(p_arg0, p_arg1, p_arg2, p_arg3, XLT(tags, 0), XLT(tags, 1), NULL); break;
        case 3: gtk_text_buffer_insert_with_tags(p_arg0, p_arg1, p_arg2, p_arg3, XLT(tags, 0), XLT(tags, 1), XLT(tags, 2), NULL); break;
        case 4: gtk_text_buffer_insert_with_tags(p_arg0, p_arg1, p_arg2, p_arg3, XLT(tags, 0), XLT(tags, 1), XLT(tags, 2), XLT(tags, 3), NULL); break;
        case 5: gtk_text_buffer_insert_with_tags(p_arg0, p_arg1, p_arg2, p_arg3, XLT(tags, 0), XLT(tags, 1), XLT(tags, 2), XLT(tags, 3), XLT(tags, 4), NULL); break;
        case 6: gtk_text_buffer_insert_with_tags(p_arg0, p_arg1, p_arg2, p_arg3, XLT(tags, 0), XLT(tags, 1), XLT(tags, 2), XLT(tags, 3), XLT(tags, 4), XLT(tags, 5), NULL); break;
      }
    return(XEN_FALSE);
  }
}
static XEN gxg_gtk_text_buffer_insert_with_tags_by_name(XEN buffer, XEN iter, XEN text, XEN len, XEN tags)
{
  #define H_gtk_text_buffer_insert_with_tags_by_name "void gtk_text_buffer_insert_with_tags_by_name(GtkTextBuffer* buffer, \
GtkTextIter* iter, gchar* text, gint len, etc tags)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_insert_with_tags_by_name", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 2, "gtk_text_buffer_insert_with_tags_by_name", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gchar__P(text), text, 3, "gtk_text_buffer_insert_with_tags_by_name", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(len), len, 4, "gtk_text_buffer_insert_with_tags_by_name", "gint");
  XEN_ASSERT_TYPE(XEN_etc_P(tags), tags, 5, "gtk_text_buffer_insert_with_tags_by_name", "etc");
  {
    int etc_len = 0;
    GtkTextBuffer* p_arg0;
    GtkTextIter* p_arg1;
    gchar* p_arg2;
    gint p_arg3;
    if (XEN_LIST_P(tags)) etc_len = XEN_LIST_LENGTH(tags);
    if (etc_len < 1) XEN_OUT_OF_RANGE_ERROR("gtk_text_buffer_insert_with_tags_by_name", 4, tags, "... list must have at least 1 entry");
    if (etc_len > 6) XEN_OUT_OF_RANGE_ERROR("gtk_text_buffer_insert_with_tags_by_name", 4, tags, "... list too long (max len: 6)");
    p_arg0 = XEN_TO_C_GtkTextBuffer_(buffer);
    p_arg1 = XEN_TO_C_GtkTextIter_(iter);
    p_arg2 = XEN_TO_C_gchar_(text);
    p_arg3 = XEN_TO_C_gint(len);
    switch (etc_len)
      {
        case 1: gtk_text_buffer_insert_with_tags_by_name(p_arg0, p_arg1, p_arg2, p_arg3, XLS(tags, 0), NULL); break;
        case 2: gtk_text_buffer_insert_with_tags_by_name(p_arg0, p_arg1, p_arg2, p_arg3, XLS(tags, 0), XLS(tags, 1), NULL); break;
        case 3: gtk_text_buffer_insert_with_tags_by_name(p_arg0, p_arg1, p_arg2, p_arg3, XLS(tags, 0), XLS(tags, 1), XLS(tags, 2), NULL); break;
        case 4: gtk_text_buffer_insert_with_tags_by_name(p_arg0, p_arg1, p_arg2, p_arg3, XLS(tags, 0), XLS(tags, 1), XLS(tags, 2), XLS(tags, 3), NULL); break;
        case 5: gtk_text_buffer_insert_with_tags_by_name(p_arg0, p_arg1, p_arg2, p_arg3, XLS(tags, 0), XLS(tags, 1), XLS(tags, 2), XLS(tags, 3), XLS(tags, 4), NULL); break;
        case 6: gtk_text_buffer_insert_with_tags_by_name(p_arg0, p_arg1, p_arg2, p_arg3, XLS(tags, 0), XLS(tags, 1), XLS(tags, 2), XLS(tags, 3), XLS(tags, 4), XLS(tags, 5), NULL); break;
      }
    return(XEN_FALSE);
  }
}
static XEN gxg_gtk_text_buffer_delete(XEN buffer, XEN start, XEN end)
{
  #define H_gtk_text_buffer_delete "void gtk_text_buffer_delete(GtkTextBuffer* buffer, GtkTextIter* start, \
GtkTextIter* end)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_delete", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(start), start, 2, "gtk_text_buffer_delete", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(end), end, 3, "gtk_text_buffer_delete", "GtkTextIter*");
  gtk_text_buffer_delete(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkTextIter_(start), XEN_TO_C_GtkTextIter_(end));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_delete_interactive(XEN buffer, XEN start_iter, XEN end_iter, XEN default_editable)
{
  #define H_gtk_text_buffer_delete_interactive "gboolean gtk_text_buffer_delete_interactive(GtkTextBuffer* buffer, \
GtkTextIter* start_iter, GtkTextIter* end_iter, gboolean default_editable)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_delete_interactive", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(start_iter), start_iter, 2, "gtk_text_buffer_delete_interactive", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(end_iter), end_iter, 3, "gtk_text_buffer_delete_interactive", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(default_editable), default_editable, 4, "gtk_text_buffer_delete_interactive", "gboolean");
  return(C_TO_XEN_gboolean(gtk_text_buffer_delete_interactive(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkTextIter_(start_iter), 
                                                              XEN_TO_C_GtkTextIter_(end_iter), XEN_TO_C_gboolean(default_editable))));
}
static XEN gxg_gtk_text_buffer_get_text(XEN buffer, XEN start, XEN end, XEN include_hidden_chars)
{
  #define H_gtk_text_buffer_get_text "gchar* gtk_text_buffer_get_text(GtkTextBuffer* buffer, GtkTextIter* start, \
GtkTextIter* end, gboolean include_hidden_chars)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_get_text", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(start), start, 2, "gtk_text_buffer_get_text", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(end), end, 3, "gtk_text_buffer_get_text", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(include_hidden_chars), include_hidden_chars, 4, "gtk_text_buffer_get_text", "gboolean");
  return(C_TO_XEN_gchar_(gtk_text_buffer_get_text(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkTextIter_(start), XEN_TO_C_GtkTextIter_(end), 
                                                  XEN_TO_C_gboolean(include_hidden_chars))));
}
static XEN gxg_gtk_text_buffer_get_slice(XEN buffer, XEN start, XEN end, XEN include_hidden_chars)
{
  #define H_gtk_text_buffer_get_slice "gchar* gtk_text_buffer_get_slice(GtkTextBuffer* buffer, GtkTextIter* start, \
GtkTextIter* end, gboolean include_hidden_chars)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_get_slice", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(start), start, 2, "gtk_text_buffer_get_slice", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(end), end, 3, "gtk_text_buffer_get_slice", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(include_hidden_chars), include_hidden_chars, 4, "gtk_text_buffer_get_slice", "gboolean");
  return(C_TO_XEN_gchar_(gtk_text_buffer_get_slice(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkTextIter_(start), XEN_TO_C_GtkTextIter_(end), 
                                                   XEN_TO_C_gboolean(include_hidden_chars))));
}
static XEN gxg_gtk_text_buffer_insert_pixbuf(XEN buffer, XEN iter, XEN pixbuf)
{
  #define H_gtk_text_buffer_insert_pixbuf "void gtk_text_buffer_insert_pixbuf(GtkTextBuffer* buffer, \
GtkTextIter* iter, GdkPixbuf* pixbuf)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_insert_pixbuf", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 2, "gtk_text_buffer_insert_pixbuf", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(pixbuf), pixbuf, 3, "gtk_text_buffer_insert_pixbuf", "GdkPixbuf*");
  gtk_text_buffer_insert_pixbuf(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_GdkPixbuf_(pixbuf));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_insert_child_anchor(XEN buffer, XEN iter, XEN anchor)
{
  #define H_gtk_text_buffer_insert_child_anchor "void gtk_text_buffer_insert_child_anchor(GtkTextBuffer* buffer, \
GtkTextIter* iter, GtkTextChildAnchor* anchor)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_insert_child_anchor", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 2, "gtk_text_buffer_insert_child_anchor", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextChildAnchor__P(anchor), anchor, 3, "gtk_text_buffer_insert_child_anchor", "GtkTextChildAnchor*");
  gtk_text_buffer_insert_child_anchor(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_GtkTextChildAnchor_(anchor));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_create_child_anchor(XEN buffer, XEN iter)
{
  #define H_gtk_text_buffer_create_child_anchor "GtkTextChildAnchor* gtk_text_buffer_create_child_anchor(GtkTextBuffer* buffer, \
GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_create_child_anchor", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 2, "gtk_text_buffer_create_child_anchor", "GtkTextIter*");
  return(C_TO_XEN_GtkTextChildAnchor_(gtk_text_buffer_create_child_anchor(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_buffer_create_mark(XEN buffer, XEN mark_name, XEN where, XEN left_gravity)
{
  #define H_gtk_text_buffer_create_mark "GtkTextMark* gtk_text_buffer_create_mark(GtkTextBuffer* buffer, \
gchar* mark_name, GtkTextIter* where, gboolean left_gravity)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_create_mark", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_gchar__P(mark_name), mark_name, 2, "gtk_text_buffer_create_mark", "gchar*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(where), where, 3, "gtk_text_buffer_create_mark", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(left_gravity), left_gravity, 4, "gtk_text_buffer_create_mark", "gboolean");
  return(C_TO_XEN_GtkTextMark_(gtk_text_buffer_create_mark(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_gchar_(mark_name), XEN_TO_C_GtkTextIter_(where), 
                                                           XEN_TO_C_gboolean(left_gravity))));
}
static XEN gxg_gtk_text_buffer_move_mark(XEN buffer, XEN mark, XEN where)
{
  #define H_gtk_text_buffer_move_mark "void gtk_text_buffer_move_mark(GtkTextBuffer* buffer, GtkTextMark* mark, \
GtkTextIter* where)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_move_mark", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextMark__P(mark), mark, 2, "gtk_text_buffer_move_mark", "GtkTextMark*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(where), where, 3, "gtk_text_buffer_move_mark", "GtkTextIter*");
  gtk_text_buffer_move_mark(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkTextMark_(mark), XEN_TO_C_GtkTextIter_(where));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_delete_mark(XEN buffer, XEN mark)
{
  #define H_gtk_text_buffer_delete_mark "void gtk_text_buffer_delete_mark(GtkTextBuffer* buffer, GtkTextMark* mark)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_delete_mark", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextMark__P(mark), mark, 2, "gtk_text_buffer_delete_mark", "GtkTextMark*");
  gtk_text_buffer_delete_mark(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkTextMark_(mark));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_get_mark(XEN buffer, XEN name)
{
  #define H_gtk_text_buffer_get_mark "GtkTextMark* gtk_text_buffer_get_mark(GtkTextBuffer* buffer, gchar* name)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_get_mark", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_gchar__P(name), name, 2, "gtk_text_buffer_get_mark", "gchar*");
  return(C_TO_XEN_GtkTextMark_(gtk_text_buffer_get_mark(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_gchar_(name))));
}
static XEN gxg_gtk_text_buffer_move_mark_by_name(XEN buffer, XEN name, XEN where)
{
  #define H_gtk_text_buffer_move_mark_by_name "void gtk_text_buffer_move_mark_by_name(GtkTextBuffer* buffer, \
gchar* name, GtkTextIter* where)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_move_mark_by_name", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_gchar__P(name), name, 2, "gtk_text_buffer_move_mark_by_name", "gchar*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(where), where, 3, "gtk_text_buffer_move_mark_by_name", "GtkTextIter*");
  gtk_text_buffer_move_mark_by_name(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_gchar_(name), XEN_TO_C_GtkTextIter_(where));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_delete_mark_by_name(XEN buffer, XEN name)
{
  #define H_gtk_text_buffer_delete_mark_by_name "void gtk_text_buffer_delete_mark_by_name(GtkTextBuffer* buffer, \
gchar* name)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_delete_mark_by_name", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_gchar__P(name), name, 2, "gtk_text_buffer_delete_mark_by_name", "gchar*");
  gtk_text_buffer_delete_mark_by_name(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_gchar_(name));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_get_insert(XEN buffer)
{
  #define H_gtk_text_buffer_get_insert "GtkTextMark* gtk_text_buffer_get_insert(GtkTextBuffer* buffer)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_get_insert", "GtkTextBuffer*");
  return(C_TO_XEN_GtkTextMark_(gtk_text_buffer_get_insert(XEN_TO_C_GtkTextBuffer_(buffer))));
}
static XEN gxg_gtk_text_buffer_get_selection_bound(XEN buffer)
{
  #define H_gtk_text_buffer_get_selection_bound "GtkTextMark* gtk_text_buffer_get_selection_bound(GtkTextBuffer* buffer)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_get_selection_bound", "GtkTextBuffer*");
  return(C_TO_XEN_GtkTextMark_(gtk_text_buffer_get_selection_bound(XEN_TO_C_GtkTextBuffer_(buffer))));
}
static XEN gxg_gtk_text_buffer_place_cursor(XEN buffer, XEN where)
{
  #define H_gtk_text_buffer_place_cursor "void gtk_text_buffer_place_cursor(GtkTextBuffer* buffer, GtkTextIter* where)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_place_cursor", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(where), where, 2, "gtk_text_buffer_place_cursor", "GtkTextIter*");
  gtk_text_buffer_place_cursor(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkTextIter_(where));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_apply_tag(XEN buffer, XEN tag, XEN start, XEN end)
{
  #define H_gtk_text_buffer_apply_tag "void gtk_text_buffer_apply_tag(GtkTextBuffer* buffer, GtkTextTag* tag, \
GtkTextIter* start, GtkTextIter* end)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_apply_tag", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextTag__P(tag), tag, 2, "gtk_text_buffer_apply_tag", "GtkTextTag*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(start), start, 3, "gtk_text_buffer_apply_tag", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(end), end, 4, "gtk_text_buffer_apply_tag", "GtkTextIter*");
  gtk_text_buffer_apply_tag(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkTextTag_(tag), XEN_TO_C_GtkTextIter_(start), XEN_TO_C_GtkTextIter_(end));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_remove_tag(XEN buffer, XEN tag, XEN start, XEN end)
{
  #define H_gtk_text_buffer_remove_tag "void gtk_text_buffer_remove_tag(GtkTextBuffer* buffer, GtkTextTag* tag, \
GtkTextIter* start, GtkTextIter* end)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_remove_tag", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextTag__P(tag), tag, 2, "gtk_text_buffer_remove_tag", "GtkTextTag*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(start), start, 3, "gtk_text_buffer_remove_tag", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(end), end, 4, "gtk_text_buffer_remove_tag", "GtkTextIter*");
  gtk_text_buffer_remove_tag(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkTextTag_(tag), XEN_TO_C_GtkTextIter_(start), XEN_TO_C_GtkTextIter_(end));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_apply_tag_by_name(XEN buffer, XEN name, XEN start, XEN end)
{
  #define H_gtk_text_buffer_apply_tag_by_name "void gtk_text_buffer_apply_tag_by_name(GtkTextBuffer* buffer, \
gchar* name, GtkTextIter* start, GtkTextIter* end)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_apply_tag_by_name", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_gchar__P(name), name, 2, "gtk_text_buffer_apply_tag_by_name", "gchar*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(start), start, 3, "gtk_text_buffer_apply_tag_by_name", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(end), end, 4, "gtk_text_buffer_apply_tag_by_name", "GtkTextIter*");
  gtk_text_buffer_apply_tag_by_name(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_gchar_(name), XEN_TO_C_GtkTextIter_(start), 
                                    XEN_TO_C_GtkTextIter_(end));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_remove_tag_by_name(XEN buffer, XEN name, XEN start, XEN end)
{
  #define H_gtk_text_buffer_remove_tag_by_name "void gtk_text_buffer_remove_tag_by_name(GtkTextBuffer* buffer, \
gchar* name, GtkTextIter* start, GtkTextIter* end)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_remove_tag_by_name", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_gchar__P(name), name, 2, "gtk_text_buffer_remove_tag_by_name", "gchar*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(start), start, 3, "gtk_text_buffer_remove_tag_by_name", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(end), end, 4, "gtk_text_buffer_remove_tag_by_name", "GtkTextIter*");
  gtk_text_buffer_remove_tag_by_name(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_gchar_(name), XEN_TO_C_GtkTextIter_(start), 
                                     XEN_TO_C_GtkTextIter_(end));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_remove_all_tags(XEN buffer, XEN start, XEN end)
{
  #define H_gtk_text_buffer_remove_all_tags "void gtk_text_buffer_remove_all_tags(GtkTextBuffer* buffer, \
GtkTextIter* start, GtkTextIter* end)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_remove_all_tags", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(start), start, 2, "gtk_text_buffer_remove_all_tags", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(end), end, 3, "gtk_text_buffer_remove_all_tags", "GtkTextIter*");
  gtk_text_buffer_remove_all_tags(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkTextIter_(start), XEN_TO_C_GtkTextIter_(end));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_create_tag(XEN buffer, XEN tag_name, XEN tags)
{
  #define H_gtk_text_buffer_create_tag "GtkTextTag* gtk_text_buffer_create_tag(GtkTextBuffer* buffer, \
gchar* tag_name, etc tags)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_create_tag", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_gchar__P(tag_name), tag_name, 2, "gtk_text_buffer_create_tag", "gchar*");
  if (XEN_NOT_BOUND_P(tags)) tags = XEN_FALSE; 
  else XEN_ASSERT_TYPE(XEN_etc_P(tags), tags, 3, "gtk_text_buffer_create_tag", "etc");
  {
    int etc_len = 0;
    GtkTextTag* result = NULL;
    GtkTextBuffer* p_arg0;
    gchar* p_arg1;
    if (XEN_LIST_P(tags)) etc_len = XEN_LIST_LENGTH(tags);
    if (etc_len > 6) XEN_OUT_OF_RANGE_ERROR("gtk_text_buffer_create_tag", 2, tags, "... list too long (max len: 6)");
    p_arg0 = XEN_TO_C_GtkTextBuffer_(buffer);
    p_arg1 = XEN_TO_C_gchar_(tag_name);
    switch (etc_len)
      {
        case 0: result = gtk_text_buffer_create_tag(p_arg0, p_arg1, NULL); break;
        case 1: result = gtk_text_buffer_create_tag(p_arg0, p_arg1, XLS(tags, 0), NULL); break;
        case 2: result = gtk_text_buffer_create_tag(p_arg0, p_arg1, XLS(tags, 0), XLS(tags, 1), NULL); break;
        case 3: result = gtk_text_buffer_create_tag(p_arg0, p_arg1, XLS(tags, 0), XLS(tags, 1), XLS(tags, 2), NULL); break;
        case 4: result = gtk_text_buffer_create_tag(p_arg0, p_arg1, XLS(tags, 0), XLS(tags, 1), XLS(tags, 2), XLS(tags, 3), NULL); break;
        case 5: result = gtk_text_buffer_create_tag(p_arg0, p_arg1, XLS(tags, 0), XLS(tags, 1), XLS(tags, 2), XLS(tags, 3), XLS(tags, 4), NULL); break;
        case 6: result = gtk_text_buffer_create_tag(p_arg0, p_arg1, XLS(tags, 0), XLS(tags, 1), XLS(tags, 2), XLS(tags, 3), XLS(tags, 4), XLS(tags, 5), NULL); break;
      }
    return(C_TO_XEN_GtkTextTag_(result));
  }
}
static XEN gxg_gtk_text_buffer_get_iter_at_line_offset(XEN buffer, XEN iter, XEN line_number, XEN char_offset)
{
  #define H_gtk_text_buffer_get_iter_at_line_offset "void gtk_text_buffer_get_iter_at_line_offset(GtkTextBuffer* buffer, \
GtkTextIter* iter, gint line_number, gint char_offset)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_get_iter_at_line_offset", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 2, "gtk_text_buffer_get_iter_at_line_offset", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gint_P(line_number), line_number, 3, "gtk_text_buffer_get_iter_at_line_offset", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(char_offset), char_offset, 4, "gtk_text_buffer_get_iter_at_line_offset", "gint");
  gtk_text_buffer_get_iter_at_line_offset(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gint(line_number), 
                                          XEN_TO_C_gint(char_offset));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_get_iter_at_line_index(XEN buffer, XEN iter, XEN line_number, XEN byte_index)
{
  #define H_gtk_text_buffer_get_iter_at_line_index "void gtk_text_buffer_get_iter_at_line_index(GtkTextBuffer* buffer, \
GtkTextIter* iter, gint line_number, gint byte_index)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_get_iter_at_line_index", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 2, "gtk_text_buffer_get_iter_at_line_index", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gint_P(line_number), line_number, 3, "gtk_text_buffer_get_iter_at_line_index", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(byte_index), byte_index, 4, "gtk_text_buffer_get_iter_at_line_index", "gint");
  gtk_text_buffer_get_iter_at_line_index(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gint(line_number), 
                                         XEN_TO_C_gint(byte_index));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_get_iter_at_offset(XEN buffer, XEN iter, XEN char_offset)
{
  #define H_gtk_text_buffer_get_iter_at_offset "void gtk_text_buffer_get_iter_at_offset(GtkTextBuffer* buffer, \
GtkTextIter* iter, gint char_offset)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_get_iter_at_offset", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 2, "gtk_text_buffer_get_iter_at_offset", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gint_P(char_offset), char_offset, 3, "gtk_text_buffer_get_iter_at_offset", "gint");
  gtk_text_buffer_get_iter_at_offset(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gint(char_offset));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_get_iter_at_line(XEN buffer, XEN iter, XEN line_number)
{
  #define H_gtk_text_buffer_get_iter_at_line "void gtk_text_buffer_get_iter_at_line(GtkTextBuffer* buffer, \
GtkTextIter* iter, gint line_number)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_get_iter_at_line", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 2, "gtk_text_buffer_get_iter_at_line", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gint_P(line_number), line_number, 3, "gtk_text_buffer_get_iter_at_line", "gint");
  gtk_text_buffer_get_iter_at_line(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gint(line_number));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_get_start_iter(XEN buffer, XEN iter)
{
  #define H_gtk_text_buffer_get_start_iter "void gtk_text_buffer_get_start_iter(GtkTextBuffer* buffer, \
GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_get_start_iter", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 2, "gtk_text_buffer_get_start_iter", "GtkTextIter*");
  gtk_text_buffer_get_start_iter(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkTextIter_(iter));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_get_end_iter(XEN buffer, XEN iter)
{
  #define H_gtk_text_buffer_get_end_iter "void gtk_text_buffer_get_end_iter(GtkTextBuffer* buffer, GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_get_end_iter", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 2, "gtk_text_buffer_get_end_iter", "GtkTextIter*");
  gtk_text_buffer_get_end_iter(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkTextIter_(iter));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_get_bounds(XEN buffer, XEN start, XEN end)
{
  #define H_gtk_text_buffer_get_bounds "void gtk_text_buffer_get_bounds(GtkTextBuffer* buffer, GtkTextIter* start, \
GtkTextIter* end)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_get_bounds", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(start), start, 2, "gtk_text_buffer_get_bounds", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(end), end, 3, "gtk_text_buffer_get_bounds", "GtkTextIter*");
  gtk_text_buffer_get_bounds(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkTextIter_(start), XEN_TO_C_GtkTextIter_(end));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_get_iter_at_mark(XEN buffer, XEN iter, XEN mark)
{
  #define H_gtk_text_buffer_get_iter_at_mark "void gtk_text_buffer_get_iter_at_mark(GtkTextBuffer* buffer, \
GtkTextIter* iter, GtkTextMark* mark)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_get_iter_at_mark", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 2, "gtk_text_buffer_get_iter_at_mark", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextMark__P(mark), mark, 3, "gtk_text_buffer_get_iter_at_mark", "GtkTextMark*");
  gtk_text_buffer_get_iter_at_mark(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_GtkTextMark_(mark));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_get_iter_at_child_anchor(XEN buffer, XEN iter, XEN anchor)
{
  #define H_gtk_text_buffer_get_iter_at_child_anchor "void gtk_text_buffer_get_iter_at_child_anchor(GtkTextBuffer* buffer, \
GtkTextIter* iter, GtkTextChildAnchor* anchor)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_get_iter_at_child_anchor", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 2, "gtk_text_buffer_get_iter_at_child_anchor", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextChildAnchor__P(anchor), anchor, 3, "gtk_text_buffer_get_iter_at_child_anchor", "GtkTextChildAnchor*");
  gtk_text_buffer_get_iter_at_child_anchor(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_GtkTextChildAnchor_(anchor));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_get_modified(XEN buffer)
{
  #define H_gtk_text_buffer_get_modified "gboolean gtk_text_buffer_get_modified(GtkTextBuffer* buffer)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_get_modified", "GtkTextBuffer*");
  return(C_TO_XEN_gboolean(gtk_text_buffer_get_modified(XEN_TO_C_GtkTextBuffer_(buffer))));
}
static XEN gxg_gtk_text_buffer_set_modified(XEN buffer, XEN setting)
{
  #define H_gtk_text_buffer_set_modified "void gtk_text_buffer_set_modified(GtkTextBuffer* buffer, gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_set_modified", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gtk_text_buffer_set_modified", "gboolean");
  gtk_text_buffer_set_modified(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_add_selection_clipboard(XEN buffer, XEN clipboard)
{
  #define H_gtk_text_buffer_add_selection_clipboard "void gtk_text_buffer_add_selection_clipboard(GtkTextBuffer* buffer, \
GtkClipboard* clipboard)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_add_selection_clipboard", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkClipboard__P(clipboard), clipboard, 2, "gtk_text_buffer_add_selection_clipboard", "GtkClipboard*");
  gtk_text_buffer_add_selection_clipboard(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkClipboard_(clipboard));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_remove_selection_clipboard(XEN buffer, XEN clipboard)
{
  #define H_gtk_text_buffer_remove_selection_clipboard "void gtk_text_buffer_remove_selection_clipboard(GtkTextBuffer* buffer, \
GtkClipboard* clipboard)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_remove_selection_clipboard", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkClipboard__P(clipboard), clipboard, 2, "gtk_text_buffer_remove_selection_clipboard", "GtkClipboard*");
  gtk_text_buffer_remove_selection_clipboard(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkClipboard_(clipboard));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_cut_clipboard(XEN buffer, XEN clipboard, XEN default_editable)
{
  #define H_gtk_text_buffer_cut_clipboard "void gtk_text_buffer_cut_clipboard(GtkTextBuffer* buffer, \
GtkClipboard* clipboard, gboolean default_editable)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_cut_clipboard", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkClipboard__P(clipboard), clipboard, 2, "gtk_text_buffer_cut_clipboard", "GtkClipboard*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(default_editable), default_editable, 3, "gtk_text_buffer_cut_clipboard", "gboolean");
  gtk_text_buffer_cut_clipboard(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkClipboard_(clipboard), XEN_TO_C_gboolean(default_editable));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_copy_clipboard(XEN buffer, XEN clipboard)
{
  #define H_gtk_text_buffer_copy_clipboard "void gtk_text_buffer_copy_clipboard(GtkTextBuffer* buffer, \
GtkClipboard* clipboard)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_copy_clipboard", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkClipboard__P(clipboard), clipboard, 2, "gtk_text_buffer_copy_clipboard", "GtkClipboard*");
  gtk_text_buffer_copy_clipboard(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkClipboard_(clipboard));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_paste_clipboard(XEN buffer, XEN clipboard, XEN override_location, XEN default_editable)
{
  #define H_gtk_text_buffer_paste_clipboard "void gtk_text_buffer_paste_clipboard(GtkTextBuffer* buffer, \
GtkClipboard* clipboard, GtkTextIter* override_location, gboolean default_editable)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_paste_clipboard", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkClipboard__P(clipboard), clipboard, 2, "gtk_text_buffer_paste_clipboard", "GtkClipboard*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(override_location) || XEN_FALSE_P(override_location), override_location, 3, "gtk_text_buffer_paste_clipboard", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(default_editable), default_editable, 4, "gtk_text_buffer_paste_clipboard", "gboolean");
  gtk_text_buffer_paste_clipboard(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkClipboard_(clipboard), XEN_TO_C_GtkTextIter_(override_location), 
                                  XEN_TO_C_gboolean(default_editable));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_get_selection_bounds(XEN buffer, XEN start, XEN end)
{
  #define H_gtk_text_buffer_get_selection_bounds "gboolean gtk_text_buffer_get_selection_bounds(GtkTextBuffer* buffer, \
GtkTextIter* start, GtkTextIter* end)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_get_selection_bounds", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(start), start, 2, "gtk_text_buffer_get_selection_bounds", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(end), end, 3, "gtk_text_buffer_get_selection_bounds", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_buffer_get_selection_bounds(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_GtkTextIter_(start), 
                                                                XEN_TO_C_GtkTextIter_(end))));
}
static XEN gxg_gtk_text_buffer_delete_selection(XEN buffer, XEN interactive, XEN default_editable)
{
  #define H_gtk_text_buffer_delete_selection "gboolean gtk_text_buffer_delete_selection(GtkTextBuffer* buffer, \
gboolean interactive, gboolean default_editable)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_delete_selection", "GtkTextBuffer*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(interactive), interactive, 2, "gtk_text_buffer_delete_selection", "gboolean");
  XEN_ASSERT_TYPE(XEN_gboolean_P(default_editable), default_editable, 3, "gtk_text_buffer_delete_selection", "gboolean");
  return(C_TO_XEN_gboolean(gtk_text_buffer_delete_selection(XEN_TO_C_GtkTextBuffer_(buffer), XEN_TO_C_gboolean(interactive), 
                                                            XEN_TO_C_gboolean(default_editable))));
}
static XEN gxg_gtk_text_buffer_begin_user_action(XEN buffer)
{
  #define H_gtk_text_buffer_begin_user_action "void gtk_text_buffer_begin_user_action(GtkTextBuffer* buffer)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_begin_user_action", "GtkTextBuffer*");
  gtk_text_buffer_begin_user_action(XEN_TO_C_GtkTextBuffer_(buffer));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_buffer_end_user_action(XEN buffer)
{
  #define H_gtk_text_buffer_end_user_action "void gtk_text_buffer_end_user_action(GtkTextBuffer* buffer)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_buffer_end_user_action", "GtkTextBuffer*");
  gtk_text_buffer_end_user_action(XEN_TO_C_GtkTextBuffer_(buffer));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_child_anchor_get_type(void)
{
  #define H_gtk_text_child_anchor_get_type "GType gtk_text_child_anchor_get_type( void)"
  return(C_TO_XEN_GType(gtk_text_child_anchor_get_type()));
}
static XEN gxg_gtk_text_child_anchor_new(void)
{
  #define H_gtk_text_child_anchor_new "GtkTextChildAnchor* gtk_text_child_anchor_new( void)"
  return(C_TO_XEN_GtkTextChildAnchor_(gtk_text_child_anchor_new()));
}
static XEN gxg_gtk_text_child_anchor_get_widgets(XEN anchor)
{
  #define H_gtk_text_child_anchor_get_widgets "GList* gtk_text_child_anchor_get_widgets(GtkTextChildAnchor* anchor)"
  XEN_ASSERT_TYPE(XEN_GtkTextChildAnchor__P(anchor), anchor, 1, "gtk_text_child_anchor_get_widgets", "GtkTextChildAnchor*");
  return(C_TO_XEN_GList_(gtk_text_child_anchor_get_widgets(XEN_TO_C_GtkTextChildAnchor_(anchor))));
}
static XEN gxg_gtk_text_child_anchor_get_deleted(XEN anchor)
{
  #define H_gtk_text_child_anchor_get_deleted "gboolean gtk_text_child_anchor_get_deleted(GtkTextChildAnchor* anchor)"
  XEN_ASSERT_TYPE(XEN_GtkTextChildAnchor__P(anchor), anchor, 1, "gtk_text_child_anchor_get_deleted", "GtkTextChildAnchor*");
  return(C_TO_XEN_gboolean(gtk_text_child_anchor_get_deleted(XEN_TO_C_GtkTextChildAnchor_(anchor))));
}
static XEN gxg_gtk_text_iter_get_buffer(XEN iter)
{
  #define H_gtk_text_iter_get_buffer "GtkTextBuffer* gtk_text_iter_get_buffer(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_get_buffer", "GtkTextIter*");
  return(C_TO_XEN_GtkTextBuffer_(gtk_text_iter_get_buffer(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_copy(XEN iter)
{
  #define H_gtk_text_iter_copy "GtkTextIter* gtk_text_iter_copy(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_copy", "GtkTextIter*");
  return(C_TO_XEN_GtkTextIter_(gtk_text_iter_copy(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_free(XEN iter)
{
  #define H_gtk_text_iter_free "void gtk_text_iter_free(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_free", "GtkTextIter*");
  gtk_text_iter_free(XEN_TO_C_GtkTextIter_(iter));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_iter_get_offset(XEN iter)
{
  #define H_gtk_text_iter_get_offset "gint gtk_text_iter_get_offset(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_get_offset", "GtkTextIter*");
  return(C_TO_XEN_gint(gtk_text_iter_get_offset(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_get_line(XEN iter)
{
  #define H_gtk_text_iter_get_line "gint gtk_text_iter_get_line(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_get_line", "GtkTextIter*");
  return(C_TO_XEN_gint(gtk_text_iter_get_line(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_get_line_offset(XEN iter)
{
  #define H_gtk_text_iter_get_line_offset "gint gtk_text_iter_get_line_offset(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_get_line_offset", "GtkTextIter*");
  return(C_TO_XEN_gint(gtk_text_iter_get_line_offset(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_get_line_index(XEN iter)
{
  #define H_gtk_text_iter_get_line_index "gint gtk_text_iter_get_line_index(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_get_line_index", "GtkTextIter*");
  return(C_TO_XEN_gint(gtk_text_iter_get_line_index(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_get_visible_line_offset(XEN iter)
{
  #define H_gtk_text_iter_get_visible_line_offset "gint gtk_text_iter_get_visible_line_offset(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_get_visible_line_offset", "GtkTextIter*");
  return(C_TO_XEN_gint(gtk_text_iter_get_visible_line_offset(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_get_visible_line_index(XEN iter)
{
  #define H_gtk_text_iter_get_visible_line_index "gint gtk_text_iter_get_visible_line_index(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_get_visible_line_index", "GtkTextIter*");
  return(C_TO_XEN_gint(gtk_text_iter_get_visible_line_index(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_get_char(XEN iter)
{
  #define H_gtk_text_iter_get_char "gunichar gtk_text_iter_get_char(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_get_char", "GtkTextIter*");
  return(C_TO_XEN_gunichar(gtk_text_iter_get_char(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_get_slice(XEN start, XEN end)
{
  #define H_gtk_text_iter_get_slice "gchar* gtk_text_iter_get_slice(GtkTextIter* start, GtkTextIter* end)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(start), start, 1, "gtk_text_iter_get_slice", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(end), end, 2, "gtk_text_iter_get_slice", "GtkTextIter*");
  return(C_TO_XEN_gchar_(gtk_text_iter_get_slice(XEN_TO_C_GtkTextIter_(start), XEN_TO_C_GtkTextIter_(end))));
}
static XEN gxg_gtk_text_iter_get_text(XEN start, XEN end)
{
  #define H_gtk_text_iter_get_text "gchar* gtk_text_iter_get_text(GtkTextIter* start, GtkTextIter* end)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(start), start, 1, "gtk_text_iter_get_text", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(end), end, 2, "gtk_text_iter_get_text", "GtkTextIter*");
  return(C_TO_XEN_gchar_(gtk_text_iter_get_text(XEN_TO_C_GtkTextIter_(start), XEN_TO_C_GtkTextIter_(end))));
}
static XEN gxg_gtk_text_iter_get_visible_slice(XEN start, XEN end)
{
  #define H_gtk_text_iter_get_visible_slice "gchar* gtk_text_iter_get_visible_slice(GtkTextIter* start, \
GtkTextIter* end)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(start), start, 1, "gtk_text_iter_get_visible_slice", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(end), end, 2, "gtk_text_iter_get_visible_slice", "GtkTextIter*");
  return(C_TO_XEN_gchar_(gtk_text_iter_get_visible_slice(XEN_TO_C_GtkTextIter_(start), XEN_TO_C_GtkTextIter_(end))));
}
static XEN gxg_gtk_text_iter_get_visible_text(XEN start, XEN end)
{
  #define H_gtk_text_iter_get_visible_text "gchar* gtk_text_iter_get_visible_text(GtkTextIter* start, \
GtkTextIter* end)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(start), start, 1, "gtk_text_iter_get_visible_text", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(end), end, 2, "gtk_text_iter_get_visible_text", "GtkTextIter*");
  return(C_TO_XEN_gchar_(gtk_text_iter_get_visible_text(XEN_TO_C_GtkTextIter_(start), XEN_TO_C_GtkTextIter_(end))));
}
static XEN gxg_gtk_text_iter_get_pixbuf(XEN iter)
{
  #define H_gtk_text_iter_get_pixbuf "GdkPixbuf* gtk_text_iter_get_pixbuf(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_get_pixbuf", "GtkTextIter*");
  return(C_TO_XEN_GdkPixbuf_(gtk_text_iter_get_pixbuf(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_get_marks(XEN iter)
{
  #define H_gtk_text_iter_get_marks "GSList* gtk_text_iter_get_marks(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_get_marks", "GtkTextIter*");
  return(C_TO_XEN_GSList_(gtk_text_iter_get_marks(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_get_child_anchor(XEN iter)
{
  #define H_gtk_text_iter_get_child_anchor "GtkTextChildAnchor* gtk_text_iter_get_child_anchor(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_get_child_anchor", "GtkTextIter*");
  return(C_TO_XEN_GtkTextChildAnchor_(gtk_text_iter_get_child_anchor(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_get_toggled_tags(XEN iter, XEN toggled_on)
{
  #define H_gtk_text_iter_get_toggled_tags "GSList* gtk_text_iter_get_toggled_tags(GtkTextIter* iter, \
gboolean toggled_on)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_get_toggled_tags", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(toggled_on), toggled_on, 2, "gtk_text_iter_get_toggled_tags", "gboolean");
  return(C_TO_XEN_GSList_(gtk_text_iter_get_toggled_tags(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gboolean(toggled_on))));
}
static XEN gxg_gtk_text_iter_begins_tag(XEN iter, XEN tag)
{
  #define H_gtk_text_iter_begins_tag "gboolean gtk_text_iter_begins_tag(GtkTextIter* iter, GtkTextTag* tag)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_begins_tag", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextTag__P(tag) || XEN_FALSE_P(tag), tag, 2, "gtk_text_iter_begins_tag", "GtkTextTag*");
  return(C_TO_XEN_gboolean(gtk_text_iter_begins_tag(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_GtkTextTag_(tag))));
}
static XEN gxg_gtk_text_iter_ends_tag(XEN iter, XEN tag)
{
  #define H_gtk_text_iter_ends_tag "gboolean gtk_text_iter_ends_tag(GtkTextIter* iter, GtkTextTag* tag)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_ends_tag", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextTag__P(tag) || XEN_FALSE_P(tag), tag, 2, "gtk_text_iter_ends_tag", "GtkTextTag*");
  return(C_TO_XEN_gboolean(gtk_text_iter_ends_tag(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_GtkTextTag_(tag))));
}
static XEN gxg_gtk_text_iter_toggles_tag(XEN iter, XEN tag)
{
  #define H_gtk_text_iter_toggles_tag "gboolean gtk_text_iter_toggles_tag(GtkTextIter* iter, GtkTextTag* tag)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_toggles_tag", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextTag__P(tag), tag, 2, "gtk_text_iter_toggles_tag", "GtkTextTag*");
  return(C_TO_XEN_gboolean(gtk_text_iter_toggles_tag(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_GtkTextTag_(tag))));
}
static XEN gxg_gtk_text_iter_has_tag(XEN iter, XEN tag)
{
  #define H_gtk_text_iter_has_tag "gboolean gtk_text_iter_has_tag(GtkTextIter* iter, GtkTextTag* tag)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_has_tag", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextTag__P(tag), tag, 2, "gtk_text_iter_has_tag", "GtkTextTag*");
  return(C_TO_XEN_gboolean(gtk_text_iter_has_tag(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_GtkTextTag_(tag))));
}
static XEN gxg_gtk_text_iter_get_tags(XEN iter)
{
  #define H_gtk_text_iter_get_tags "GSList* gtk_text_iter_get_tags(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_get_tags", "GtkTextIter*");
  return(C_TO_XEN_GSList_(gtk_text_iter_get_tags(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_editable(XEN iter, XEN default_setting)
{
  #define H_gtk_text_iter_editable "gboolean gtk_text_iter_editable(GtkTextIter* iter, gboolean default_setting)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_editable", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(default_setting), default_setting, 2, "gtk_text_iter_editable", "gboolean");
  return(C_TO_XEN_gboolean(gtk_text_iter_editable(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gboolean(default_setting))));
}
static XEN gxg_gtk_text_iter_can_insert(XEN iter, XEN default_editability)
{
  #define H_gtk_text_iter_can_insert "gboolean gtk_text_iter_can_insert(GtkTextIter* iter, gboolean default_editability)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_can_insert", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(default_editability), default_editability, 2, "gtk_text_iter_can_insert", "gboolean");
  return(C_TO_XEN_gboolean(gtk_text_iter_can_insert(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gboolean(default_editability))));
}
static XEN gxg_gtk_text_iter_starts_word(XEN iter)
{
  #define H_gtk_text_iter_starts_word "gboolean gtk_text_iter_starts_word(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_starts_word", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_iter_starts_word(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_ends_word(XEN iter)
{
  #define H_gtk_text_iter_ends_word "gboolean gtk_text_iter_ends_word(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_ends_word", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_iter_ends_word(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_inside_word(XEN iter)
{
  #define H_gtk_text_iter_inside_word "gboolean gtk_text_iter_inside_word(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_inside_word", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_iter_inside_word(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_starts_sentence(XEN iter)
{
  #define H_gtk_text_iter_starts_sentence "gboolean gtk_text_iter_starts_sentence(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_starts_sentence", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_iter_starts_sentence(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_ends_sentence(XEN iter)
{
  #define H_gtk_text_iter_ends_sentence "gboolean gtk_text_iter_ends_sentence(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_ends_sentence", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_iter_ends_sentence(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_inside_sentence(XEN iter)
{
  #define H_gtk_text_iter_inside_sentence "gboolean gtk_text_iter_inside_sentence(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_inside_sentence", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_iter_inside_sentence(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_starts_line(XEN iter)
{
  #define H_gtk_text_iter_starts_line "gboolean gtk_text_iter_starts_line(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_starts_line", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_iter_starts_line(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_ends_line(XEN iter)
{
  #define H_gtk_text_iter_ends_line "gboolean gtk_text_iter_ends_line(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_ends_line", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_iter_ends_line(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_is_cursor_position(XEN iter)
{
  #define H_gtk_text_iter_is_cursor_position "gboolean gtk_text_iter_is_cursor_position(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_is_cursor_position", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_iter_is_cursor_position(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_get_chars_in_line(XEN iter)
{
  #define H_gtk_text_iter_get_chars_in_line "gint gtk_text_iter_get_chars_in_line(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_get_chars_in_line", "GtkTextIter*");
  return(C_TO_XEN_gint(gtk_text_iter_get_chars_in_line(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_get_bytes_in_line(XEN iter)
{
  #define H_gtk_text_iter_get_bytes_in_line "gint gtk_text_iter_get_bytes_in_line(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_get_bytes_in_line", "GtkTextIter*");
  return(C_TO_XEN_gint(gtk_text_iter_get_bytes_in_line(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_get_attributes(XEN iter, XEN values)
{
  #define H_gtk_text_iter_get_attributes "gboolean gtk_text_iter_get_attributes(GtkTextIter* iter, GtkTextAttributes* values)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_get_attributes", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextAttributes__P(values), values, 2, "gtk_text_iter_get_attributes", "GtkTextAttributes*");
  return(C_TO_XEN_gboolean(gtk_text_iter_get_attributes(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_GtkTextAttributes_(values))));
}
static XEN gxg_gtk_text_iter_get_language(XEN iter)
{
  #define H_gtk_text_iter_get_language "PangoLanguage* gtk_text_iter_get_language(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_get_language", "GtkTextIter*");
  return(C_TO_XEN_PangoLanguage_(gtk_text_iter_get_language(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_is_end(XEN iter)
{
  #define H_gtk_text_iter_is_end "gboolean gtk_text_iter_is_end(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_is_end", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_iter_is_end(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_is_start(XEN iter)
{
  #define H_gtk_text_iter_is_start "gboolean gtk_text_iter_is_start(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_is_start", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_iter_is_start(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_forward_char(XEN iter)
{
  #define H_gtk_text_iter_forward_char "gboolean gtk_text_iter_forward_char(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_forward_char", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_iter_forward_char(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_backward_char(XEN iter)
{
  #define H_gtk_text_iter_backward_char "gboolean gtk_text_iter_backward_char(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_backward_char", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_iter_backward_char(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_forward_chars(XEN iter, XEN count)
{
  #define H_gtk_text_iter_forward_chars "gboolean gtk_text_iter_forward_chars(GtkTextIter* iter, gint count)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_forward_chars", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gint_P(count), count, 2, "gtk_text_iter_forward_chars", "gint");
  return(C_TO_XEN_gboolean(gtk_text_iter_forward_chars(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gint(count))));
}
static XEN gxg_gtk_text_iter_backward_chars(XEN iter, XEN count)
{
  #define H_gtk_text_iter_backward_chars "gboolean gtk_text_iter_backward_chars(GtkTextIter* iter, gint count)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_backward_chars", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gint_P(count), count, 2, "gtk_text_iter_backward_chars", "gint");
  return(C_TO_XEN_gboolean(gtk_text_iter_backward_chars(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gint(count))));
}
static XEN gxg_gtk_text_iter_forward_line(XEN iter)
{
  #define H_gtk_text_iter_forward_line "gboolean gtk_text_iter_forward_line(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_forward_line", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_iter_forward_line(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_backward_line(XEN iter)
{
  #define H_gtk_text_iter_backward_line "gboolean gtk_text_iter_backward_line(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_backward_line", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_iter_backward_line(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_forward_lines(XEN iter, XEN count)
{
  #define H_gtk_text_iter_forward_lines "gboolean gtk_text_iter_forward_lines(GtkTextIter* iter, gint count)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_forward_lines", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gint_P(count), count, 2, "gtk_text_iter_forward_lines", "gint");
  return(C_TO_XEN_gboolean(gtk_text_iter_forward_lines(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gint(count))));
}
static XEN gxg_gtk_text_iter_backward_lines(XEN iter, XEN count)
{
  #define H_gtk_text_iter_backward_lines "gboolean gtk_text_iter_backward_lines(GtkTextIter* iter, gint count)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_backward_lines", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gint_P(count), count, 2, "gtk_text_iter_backward_lines", "gint");
  return(C_TO_XEN_gboolean(gtk_text_iter_backward_lines(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gint(count))));
}
static XEN gxg_gtk_text_iter_forward_word_end(XEN iter)
{
  #define H_gtk_text_iter_forward_word_end "gboolean gtk_text_iter_forward_word_end(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_forward_word_end", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_iter_forward_word_end(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_backward_word_start(XEN iter)
{
  #define H_gtk_text_iter_backward_word_start "gboolean gtk_text_iter_backward_word_start(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_backward_word_start", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_iter_backward_word_start(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_forward_word_ends(XEN iter, XEN count)
{
  #define H_gtk_text_iter_forward_word_ends "gboolean gtk_text_iter_forward_word_ends(GtkTextIter* iter, \
gint count)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_forward_word_ends", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gint_P(count), count, 2, "gtk_text_iter_forward_word_ends", "gint");
  return(C_TO_XEN_gboolean(gtk_text_iter_forward_word_ends(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gint(count))));
}
static XEN gxg_gtk_text_iter_backward_word_starts(XEN iter, XEN count)
{
  #define H_gtk_text_iter_backward_word_starts "gboolean gtk_text_iter_backward_word_starts(GtkTextIter* iter, \
gint count)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_backward_word_starts", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gint_P(count), count, 2, "gtk_text_iter_backward_word_starts", "gint");
  return(C_TO_XEN_gboolean(gtk_text_iter_backward_word_starts(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gint(count))));
}
static XEN gxg_gtk_text_iter_forward_sentence_end(XEN iter)
{
  #define H_gtk_text_iter_forward_sentence_end "gboolean gtk_text_iter_forward_sentence_end(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_forward_sentence_end", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_iter_forward_sentence_end(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_backward_sentence_start(XEN iter)
{
  #define H_gtk_text_iter_backward_sentence_start "gboolean gtk_text_iter_backward_sentence_start(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_backward_sentence_start", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_iter_backward_sentence_start(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_forward_sentence_ends(XEN iter, XEN count)
{
  #define H_gtk_text_iter_forward_sentence_ends "gboolean gtk_text_iter_forward_sentence_ends(GtkTextIter* iter, \
gint count)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_forward_sentence_ends", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gint_P(count), count, 2, "gtk_text_iter_forward_sentence_ends", "gint");
  return(C_TO_XEN_gboolean(gtk_text_iter_forward_sentence_ends(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gint(count))));
}
static XEN gxg_gtk_text_iter_backward_sentence_starts(XEN iter, XEN count)
{
  #define H_gtk_text_iter_backward_sentence_starts "gboolean gtk_text_iter_backward_sentence_starts(GtkTextIter* iter, \
gint count)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_backward_sentence_starts", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gint_P(count), count, 2, "gtk_text_iter_backward_sentence_starts", "gint");
  return(C_TO_XEN_gboolean(gtk_text_iter_backward_sentence_starts(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gint(count))));
}
static XEN gxg_gtk_text_iter_forward_cursor_position(XEN iter)
{
  #define H_gtk_text_iter_forward_cursor_position "gboolean gtk_text_iter_forward_cursor_position(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_forward_cursor_position", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_iter_forward_cursor_position(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_backward_cursor_position(XEN iter)
{
  #define H_gtk_text_iter_backward_cursor_position "gboolean gtk_text_iter_backward_cursor_position(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_backward_cursor_position", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_iter_backward_cursor_position(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_forward_cursor_positions(XEN iter, XEN count)
{
  #define H_gtk_text_iter_forward_cursor_positions "gboolean gtk_text_iter_forward_cursor_positions(GtkTextIter* iter, \
gint count)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_forward_cursor_positions", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gint_P(count), count, 2, "gtk_text_iter_forward_cursor_positions", "gint");
  return(C_TO_XEN_gboolean(gtk_text_iter_forward_cursor_positions(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gint(count))));
}
static XEN gxg_gtk_text_iter_backward_cursor_positions(XEN iter, XEN count)
{
  #define H_gtk_text_iter_backward_cursor_positions "gboolean gtk_text_iter_backward_cursor_positions(GtkTextIter* iter, \
gint count)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_backward_cursor_positions", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gint_P(count), count, 2, "gtk_text_iter_backward_cursor_positions", "gint");
  return(C_TO_XEN_gboolean(gtk_text_iter_backward_cursor_positions(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gint(count))));
}
static XEN gxg_gtk_text_iter_set_offset(XEN iter, XEN char_offset)
{
  #define H_gtk_text_iter_set_offset "void gtk_text_iter_set_offset(GtkTextIter* iter, gint char_offset)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_set_offset", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gint_P(char_offset), char_offset, 2, "gtk_text_iter_set_offset", "gint");
  gtk_text_iter_set_offset(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gint(char_offset));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_iter_set_line(XEN iter, XEN line_number)
{
  #define H_gtk_text_iter_set_line "void gtk_text_iter_set_line(GtkTextIter* iter, gint line_number)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_set_line", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gint_P(line_number), line_number, 2, "gtk_text_iter_set_line", "gint");
  gtk_text_iter_set_line(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gint(line_number));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_iter_set_line_offset(XEN iter, XEN char_on_line)
{
  #define H_gtk_text_iter_set_line_offset "void gtk_text_iter_set_line_offset(GtkTextIter* iter, gint char_on_line)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_set_line_offset", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gint_P(char_on_line), char_on_line, 2, "gtk_text_iter_set_line_offset", "gint");
  gtk_text_iter_set_line_offset(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gint(char_on_line));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_iter_set_line_index(XEN iter, XEN byte_on_line)
{
  #define H_gtk_text_iter_set_line_index "void gtk_text_iter_set_line_index(GtkTextIter* iter, gint byte_on_line)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_set_line_index", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gint_P(byte_on_line), byte_on_line, 2, "gtk_text_iter_set_line_index", "gint");
  gtk_text_iter_set_line_index(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gint(byte_on_line));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_iter_forward_to_end(XEN iter)
{
  #define H_gtk_text_iter_forward_to_end "void gtk_text_iter_forward_to_end(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_forward_to_end", "GtkTextIter*");
  gtk_text_iter_forward_to_end(XEN_TO_C_GtkTextIter_(iter));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_iter_forward_to_line_end(XEN iter)
{
  #define H_gtk_text_iter_forward_to_line_end "gboolean gtk_text_iter_forward_to_line_end(GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_forward_to_line_end", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_iter_forward_to_line_end(XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_iter_set_visible_line_offset(XEN iter, XEN char_on_line)
{
  #define H_gtk_text_iter_set_visible_line_offset "void gtk_text_iter_set_visible_line_offset(GtkTextIter* iter, \
gint char_on_line)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_set_visible_line_offset", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gint_P(char_on_line), char_on_line, 2, "gtk_text_iter_set_visible_line_offset", "gint");
  gtk_text_iter_set_visible_line_offset(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gint(char_on_line));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_iter_set_visible_line_index(XEN iter, XEN byte_on_line)
{
  #define H_gtk_text_iter_set_visible_line_index "void gtk_text_iter_set_visible_line_index(GtkTextIter* iter, \
gint byte_on_line)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_set_visible_line_index", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gint_P(byte_on_line), byte_on_line, 2, "gtk_text_iter_set_visible_line_index", "gint");
  gtk_text_iter_set_visible_line_index(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gint(byte_on_line));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_iter_forward_to_tag_toggle(XEN iter, XEN tag)
{
  #define H_gtk_text_iter_forward_to_tag_toggle "gboolean gtk_text_iter_forward_to_tag_toggle(GtkTextIter* iter, \
GtkTextTag* tag)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_forward_to_tag_toggle", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextTag__P(tag) || XEN_FALSE_P(tag), tag, 2, "gtk_text_iter_forward_to_tag_toggle", "GtkTextTag*");
  return(C_TO_XEN_gboolean(gtk_text_iter_forward_to_tag_toggle(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_GtkTextTag_(tag))));
}
static XEN gxg_gtk_text_iter_backward_to_tag_toggle(XEN iter, XEN tag)
{
  #define H_gtk_text_iter_backward_to_tag_toggle "gboolean gtk_text_iter_backward_to_tag_toggle(GtkTextIter* iter, \
GtkTextTag* tag)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_backward_to_tag_toggle", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextTag__P(tag) || XEN_FALSE_P(tag), tag, 2, "gtk_text_iter_backward_to_tag_toggle", "GtkTextTag*");
  return(C_TO_XEN_gboolean(gtk_text_iter_backward_to_tag_toggle(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_GtkTextTag_(tag))));
}
static XEN gxg_gtk_text_iter_forward_find_char(XEN iter, XEN pred, XEN func_data, XEN limit)
{
  #define H_gtk_text_iter_forward_find_char "gboolean gtk_text_iter_forward_find_char(GtkTextIter* iter, \
GtkTextCharPredicate pred, lambda_data func_data, GtkTextIter* limit)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_forward_find_char", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextCharPredicate_P(pred), pred, 2, "gtk_text_iter_forward_find_char", "GtkTextCharPredicate");
  XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 3, "gtk_text_iter_forward_find_char", "lambda_data");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(limit) || XEN_FALSE_P(limit), limit, 4, "gtk_text_iter_forward_find_char", "GtkTextIter*");
  {
    XEN result = XEN_FALSE;
    int loc;
    XEN gxg_ptr = XEN_LIST_5(XEN_FALSE, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    loc = xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 2, C_TO_XEN_INT(loc));
    result = C_TO_XEN_gboolean(gtk_text_iter_forward_find_char(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_GtkTextCharPredicate(pred), 
                                                               XEN_TO_C_lambda_data(func_data), XEN_TO_C_GtkTextIter_(limit)));
    xm_unprotect_at(loc);
    return(result);
   }
}
static XEN gxg_gtk_text_iter_backward_find_char(XEN iter, XEN pred, XEN func_data, XEN limit)
{
  #define H_gtk_text_iter_backward_find_char "gboolean gtk_text_iter_backward_find_char(GtkTextIter* iter, \
GtkTextCharPredicate pred, lambda_data func_data, GtkTextIter* limit)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_backward_find_char", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextCharPredicate_P(pred), pred, 2, "gtk_text_iter_backward_find_char", "GtkTextCharPredicate");
  XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 3, "gtk_text_iter_backward_find_char", "lambda_data");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(limit) || XEN_FALSE_P(limit), limit, 4, "gtk_text_iter_backward_find_char", "GtkTextIter*");
  {
    XEN result = XEN_FALSE;
    int loc;
    XEN gxg_ptr = XEN_LIST_5(XEN_FALSE, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    loc = xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 2, C_TO_XEN_INT(loc));
    result = C_TO_XEN_gboolean(gtk_text_iter_backward_find_char(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_GtkTextCharPredicate(pred), 
                                                                XEN_TO_C_lambda_data(func_data), XEN_TO_C_GtkTextIter_(limit)));
    xm_unprotect_at(loc);
    return(result);
   }
}
static XEN gxg_gtk_text_iter_forward_search(XEN iter, XEN str, XEN flags, XEN match_start, XEN match_end, XEN limit)
{
  #define H_gtk_text_iter_forward_search "gboolean gtk_text_iter_forward_search(GtkTextIter* iter, gchar* str, \
GtkTextSearchFlags flags, GtkTextIter* match_start, GtkTextIter* match_end, GtkTextIter* limit)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_forward_search", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gchar__P(str), str, 2, "gtk_text_iter_forward_search", "gchar*");
  XEN_ASSERT_TYPE(XEN_GtkTextSearchFlags_P(flags), flags, 3, "gtk_text_iter_forward_search", "GtkTextSearchFlags");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(match_start) || XEN_FALSE_P(match_start), match_start, 4, "gtk_text_iter_forward_search", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(match_end) || XEN_FALSE_P(match_end), match_end, 5, "gtk_text_iter_forward_search", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(limit) || XEN_FALSE_P(limit), limit, 6, "gtk_text_iter_forward_search", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_iter_forward_search(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gchar_(str), XEN_TO_C_GtkTextSearchFlags(flags), 
                                                        XEN_TO_C_GtkTextIter_(match_start), XEN_TO_C_GtkTextIter_(match_end), 
                                                        XEN_TO_C_GtkTextIter_(limit))));
}
static XEN gxg_gtk_text_iter_backward_search(XEN iter, XEN str, XEN flags, XEN match_start, XEN match_end, XEN limit)
{
  #define H_gtk_text_iter_backward_search "gboolean gtk_text_iter_backward_search(GtkTextIter* iter, \
gchar* str, GtkTextSearchFlags flags, GtkTextIter* match_start, GtkTextIter* match_end, GtkTextIter* limit)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_backward_search", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gchar__P(str), str, 2, "gtk_text_iter_backward_search", "gchar*");
  XEN_ASSERT_TYPE(XEN_GtkTextSearchFlags_P(flags), flags, 3, "gtk_text_iter_backward_search", "GtkTextSearchFlags");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(match_start) || XEN_FALSE_P(match_start), match_start, 4, "gtk_text_iter_backward_search", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(match_end) || XEN_FALSE_P(match_end), match_end, 5, "gtk_text_iter_backward_search", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(limit) || XEN_FALSE_P(limit), limit, 6, "gtk_text_iter_backward_search", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_iter_backward_search(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gchar_(str), XEN_TO_C_GtkTextSearchFlags(flags), 
                                                         XEN_TO_C_GtkTextIter_(match_start), XEN_TO_C_GtkTextIter_(match_end), 
                                                         XEN_TO_C_GtkTextIter_(limit))));
}
static XEN gxg_gtk_text_iter_equal(XEN lhs, XEN rhs)
{
  #define H_gtk_text_iter_equal "gboolean gtk_text_iter_equal(GtkTextIter* lhs, GtkTextIter* rhs)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(lhs), lhs, 1, "gtk_text_iter_equal", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(rhs), rhs, 2, "gtk_text_iter_equal", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_iter_equal(XEN_TO_C_GtkTextIter_(lhs), XEN_TO_C_GtkTextIter_(rhs))));
}
static XEN gxg_gtk_text_iter_compare(XEN lhs, XEN rhs)
{
  #define H_gtk_text_iter_compare "gint gtk_text_iter_compare(GtkTextIter* lhs, GtkTextIter* rhs)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(lhs), lhs, 1, "gtk_text_iter_compare", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(rhs), rhs, 2, "gtk_text_iter_compare", "GtkTextIter*");
  return(C_TO_XEN_gint(gtk_text_iter_compare(XEN_TO_C_GtkTextIter_(lhs), XEN_TO_C_GtkTextIter_(rhs))));
}
static XEN gxg_gtk_text_iter_in_range(XEN iter, XEN start, XEN end)
{
  #define H_gtk_text_iter_in_range "gboolean gtk_text_iter_in_range(GtkTextIter* iter, GtkTextIter* start, \
GtkTextIter* end)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 1, "gtk_text_iter_in_range", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(start), start, 2, "gtk_text_iter_in_range", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(end), end, 3, "gtk_text_iter_in_range", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_iter_in_range(XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_GtkTextIter_(start), XEN_TO_C_GtkTextIter_(end))));
}
static XEN gxg_gtk_text_iter_order(XEN first, XEN second)
{
  #define H_gtk_text_iter_order "void gtk_text_iter_order(GtkTextIter* first, GtkTextIter* second)"
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(first), first, 1, "gtk_text_iter_order", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(second), second, 2, "gtk_text_iter_order", "GtkTextIter*");
  gtk_text_iter_order(XEN_TO_C_GtkTextIter_(first), XEN_TO_C_GtkTextIter_(second));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_mark_get_type(void)
{
  #define H_gtk_text_mark_get_type "GType gtk_text_mark_get_type( void)"
  return(C_TO_XEN_GType(gtk_text_mark_get_type()));
}
static XEN gxg_gtk_text_mark_set_visible(XEN mark, XEN setting)
{
  #define H_gtk_text_mark_set_visible "void gtk_text_mark_set_visible(GtkTextMark* mark, gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GtkTextMark__P(mark), mark, 1, "gtk_text_mark_set_visible", "GtkTextMark*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gtk_text_mark_set_visible", "gboolean");
  gtk_text_mark_set_visible(XEN_TO_C_GtkTextMark_(mark), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_mark_get_visible(XEN mark)
{
  #define H_gtk_text_mark_get_visible "gboolean gtk_text_mark_get_visible(GtkTextMark* mark)"
  XEN_ASSERT_TYPE(XEN_GtkTextMark__P(mark), mark, 1, "gtk_text_mark_get_visible", "GtkTextMark*");
  return(C_TO_XEN_gboolean(gtk_text_mark_get_visible(XEN_TO_C_GtkTextMark_(mark))));
}
static XEN gxg_gtk_text_mark_get_name(XEN mark)
{
  #define H_gtk_text_mark_get_name "char* gtk_text_mark_get_name(GtkTextMark* mark)"
  XEN_ASSERT_TYPE(XEN_GtkTextMark__P(mark), mark, 1, "gtk_text_mark_get_name", "GtkTextMark*");
  return(C_TO_XEN_char_(gtk_text_mark_get_name(XEN_TO_C_GtkTextMark_(mark))));
}
static XEN gxg_gtk_text_mark_get_deleted(XEN mark)
{
  #define H_gtk_text_mark_get_deleted "gboolean gtk_text_mark_get_deleted(GtkTextMark* mark)"
  XEN_ASSERT_TYPE(XEN_GtkTextMark__P(mark), mark, 1, "gtk_text_mark_get_deleted", "GtkTextMark*");
  return(C_TO_XEN_gboolean(gtk_text_mark_get_deleted(XEN_TO_C_GtkTextMark_(mark))));
}
static XEN gxg_gtk_text_mark_get_buffer(XEN mark)
{
  #define H_gtk_text_mark_get_buffer "GtkTextBuffer* gtk_text_mark_get_buffer(GtkTextMark* mark)"
  XEN_ASSERT_TYPE(XEN_GtkTextMark__P(mark), mark, 1, "gtk_text_mark_get_buffer", "GtkTextMark*");
  return(C_TO_XEN_GtkTextBuffer_(gtk_text_mark_get_buffer(XEN_TO_C_GtkTextMark_(mark))));
}
static XEN gxg_gtk_text_mark_get_left_gravity(XEN mark)
{
  #define H_gtk_text_mark_get_left_gravity "gboolean gtk_text_mark_get_left_gravity(GtkTextMark* mark)"
  XEN_ASSERT_TYPE(XEN_GtkTextMark__P(mark), mark, 1, "gtk_text_mark_get_left_gravity", "GtkTextMark*");
  return(C_TO_XEN_gboolean(gtk_text_mark_get_left_gravity(XEN_TO_C_GtkTextMark_(mark))));
}
static XEN gxg_gtk_text_tag_get_type(void)
{
  #define H_gtk_text_tag_get_type "GType gtk_text_tag_get_type( void)"
  return(C_TO_XEN_GType(gtk_text_tag_get_type()));
}
static XEN gxg_gtk_text_tag_new(XEN name)
{
  #define H_gtk_text_tag_new "GtkTextTag* gtk_text_tag_new(gchar* name)"
  XEN_ASSERT_TYPE(XEN_gchar__P(name), name, 1, "gtk_text_tag_new", "gchar*");
  return(C_TO_XEN_GtkTextTag_(gtk_text_tag_new(XEN_TO_C_gchar_(name))));
}
static XEN gxg_gtk_text_tag_get_priority(XEN tag)
{
  #define H_gtk_text_tag_get_priority "gint gtk_text_tag_get_priority(GtkTextTag* tag)"
  XEN_ASSERT_TYPE(XEN_GtkTextTag__P(tag), tag, 1, "gtk_text_tag_get_priority", "GtkTextTag*");
  return(C_TO_XEN_gint(gtk_text_tag_get_priority(XEN_TO_C_GtkTextTag_(tag))));
}
static XEN gxg_gtk_text_tag_set_priority(XEN tag, XEN priority)
{
  #define H_gtk_text_tag_set_priority "void gtk_text_tag_set_priority(GtkTextTag* tag, gint priority)"
  XEN_ASSERT_TYPE(XEN_GtkTextTag__P(tag), tag, 1, "gtk_text_tag_set_priority", "GtkTextTag*");
  XEN_ASSERT_TYPE(XEN_gint_P(priority), priority, 2, "gtk_text_tag_set_priority", "gint");
  gtk_text_tag_set_priority(XEN_TO_C_GtkTextTag_(tag), XEN_TO_C_gint(priority));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_tag_event(XEN tag, XEN event_object, XEN event, XEN iter)
{
  #define H_gtk_text_tag_event "gboolean gtk_text_tag_event(GtkTextTag* tag, GObject* event_object, GdkEvent* event, \
GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextTag__P(tag), tag, 1, "gtk_text_tag_event", "GtkTextTag*");
  XEN_ASSERT_TYPE(XEN_GObject__P(event_object), event_object, 2, "gtk_text_tag_event", "GObject*");
  XEN_ASSERT_TYPE(XEN_GdkEvent__P(event), event, 3, "gtk_text_tag_event", "GdkEvent*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 4, "gtk_text_tag_event", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_tag_event(XEN_TO_C_GtkTextTag_(tag), XEN_TO_C_GObject_(event_object), XEN_TO_C_GdkEvent_(event), 
                                              XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_attributes_new(void)
{
  #define H_gtk_text_attributes_new "GtkTextAttributes* gtk_text_attributes_new( void)"
  return(C_TO_XEN_GtkTextAttributes_(gtk_text_attributes_new()));
}
static XEN gxg_gtk_text_attributes_copy(XEN src)
{
  #define H_gtk_text_attributes_copy "GtkTextAttributes* gtk_text_attributes_copy(GtkTextAttributes* src)"
  XEN_ASSERT_TYPE(XEN_GtkTextAttributes__P(src), src, 1, "gtk_text_attributes_copy", "GtkTextAttributes*");
  return(C_TO_XEN_GtkTextAttributes_(gtk_text_attributes_copy(XEN_TO_C_GtkTextAttributes_(src))));
}
static XEN gxg_gtk_text_attributes_copy_values(XEN src, XEN dest)
{
  #define H_gtk_text_attributes_copy_values "void gtk_text_attributes_copy_values(GtkTextAttributes* src, \
GtkTextAttributes* dest)"
  XEN_ASSERT_TYPE(XEN_GtkTextAttributes__P(src), src, 1, "gtk_text_attributes_copy_values", "GtkTextAttributes*");
  XEN_ASSERT_TYPE(XEN_GtkTextAttributes__P(dest), dest, 2, "gtk_text_attributes_copy_values", "GtkTextAttributes*");
  gtk_text_attributes_copy_values(XEN_TO_C_GtkTextAttributes_(src), XEN_TO_C_GtkTextAttributes_(dest));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_attributes_unref(XEN values)
{
  #define H_gtk_text_attributes_unref "void gtk_text_attributes_unref(GtkTextAttributes* values)"
  XEN_ASSERT_TYPE(XEN_GtkTextAttributes__P(values), values, 1, "gtk_text_attributes_unref", "GtkTextAttributes*");
  gtk_text_attributes_unref(XEN_TO_C_GtkTextAttributes_(values));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_attributes_ref(XEN values)
{
  #define H_gtk_text_attributes_ref "void gtk_text_attributes_ref(GtkTextAttributes* values)"
  XEN_ASSERT_TYPE(XEN_GtkTextAttributes__P(values), values, 1, "gtk_text_attributes_ref", "GtkTextAttributes*");
  gtk_text_attributes_ref(XEN_TO_C_GtkTextAttributes_(values));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_tag_table_get_type(void)
{
  #define H_gtk_text_tag_table_get_type "GType gtk_text_tag_table_get_type( void)"
  return(C_TO_XEN_GType(gtk_text_tag_table_get_type()));
}
static XEN gxg_gtk_text_tag_table_new(void)
{
  #define H_gtk_text_tag_table_new "GtkTextTagTable* gtk_text_tag_table_new( void)"
  return(C_TO_XEN_GtkTextTagTable_(gtk_text_tag_table_new()));
}
static XEN gxg_gtk_text_tag_table_add(XEN table, XEN tag)
{
  #define H_gtk_text_tag_table_add "void gtk_text_tag_table_add(GtkTextTagTable* table, GtkTextTag* tag)"
  XEN_ASSERT_TYPE(XEN_GtkTextTagTable__P(table), table, 1, "gtk_text_tag_table_add", "GtkTextTagTable*");
  XEN_ASSERT_TYPE(XEN_GtkTextTag__P(tag), tag, 2, "gtk_text_tag_table_add", "GtkTextTag*");
  gtk_text_tag_table_add(XEN_TO_C_GtkTextTagTable_(table), XEN_TO_C_GtkTextTag_(tag));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_tag_table_remove(XEN table, XEN tag)
{
  #define H_gtk_text_tag_table_remove "void gtk_text_tag_table_remove(GtkTextTagTable* table, GtkTextTag* tag)"
  XEN_ASSERT_TYPE(XEN_GtkTextTagTable__P(table), table, 1, "gtk_text_tag_table_remove", "GtkTextTagTable*");
  XEN_ASSERT_TYPE(XEN_GtkTextTag__P(tag), tag, 2, "gtk_text_tag_table_remove", "GtkTextTag*");
  gtk_text_tag_table_remove(XEN_TO_C_GtkTextTagTable_(table), XEN_TO_C_GtkTextTag_(tag));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_tag_table_lookup(XEN table, XEN name)
{
  #define H_gtk_text_tag_table_lookup "GtkTextTag* gtk_text_tag_table_lookup(GtkTextTagTable* table, \
gchar* name)"
  XEN_ASSERT_TYPE(XEN_GtkTextTagTable__P(table), table, 1, "gtk_text_tag_table_lookup", "GtkTextTagTable*");
  XEN_ASSERT_TYPE(XEN_gchar__P(name), name, 2, "gtk_text_tag_table_lookup", "gchar*");
  return(C_TO_XEN_GtkTextTag_(gtk_text_tag_table_lookup(XEN_TO_C_GtkTextTagTable_(table), XEN_TO_C_gchar_(name))));
}
static XEN gxg_gtk_text_tag_table_foreach(XEN table, XEN func, XEN func_data)
{
  #define H_gtk_text_tag_table_foreach "void gtk_text_tag_table_foreach(GtkTextTagTable* table, GtkTextTagTableForeach func, \
lambda_data func_data)"
  XEN_ASSERT_TYPE(XEN_GtkTextTagTable__P(table), table, 1, "gtk_text_tag_table_foreach", "GtkTextTagTable*");
  XEN_ASSERT_TYPE(XEN_GtkTextTagTableForeach_P(func), func, 2, "gtk_text_tag_table_foreach", "GtkTextTagTableForeach");
  XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 3, "gtk_text_tag_table_foreach", "lambda_data");
  {
    int loc;
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    loc = xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 2, C_TO_XEN_INT(loc));
    gtk_text_tag_table_foreach(XEN_TO_C_GtkTextTagTable_(table), XEN_TO_C_GtkTextTagTableForeach(func), XEN_TO_C_lambda_data(func_data));
    xm_unprotect_at(loc);
    return(XEN_FALSE);
   }
}
static XEN gxg_gtk_text_tag_table_get_size(XEN table)
{
  #define H_gtk_text_tag_table_get_size "gint gtk_text_tag_table_get_size(GtkTextTagTable* table)"
  XEN_ASSERT_TYPE(XEN_GtkTextTagTable__P(table), table, 1, "gtk_text_tag_table_get_size", "GtkTextTagTable*");
  return(C_TO_XEN_gint(gtk_text_tag_table_get_size(XEN_TO_C_GtkTextTagTable_(table))));
}
static XEN gxg_gtk_text_view_get_type(void)
{
  #define H_gtk_text_view_get_type "GtkType gtk_text_view_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_text_view_get_type()));
}
static XEN gxg_gtk_text_view_new(void)
{
  #define H_gtk_text_view_new "GtkWidget* gtk_text_view_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_text_view_new()));
}
static XEN gxg_gtk_text_view_new_with_buffer(XEN buffer)
{
  #define H_gtk_text_view_new_with_buffer "GtkWidget* gtk_text_view_new_with_buffer(GtkTextBuffer* buffer)"
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 1, "gtk_text_view_new_with_buffer", "GtkTextBuffer*");
  return(C_TO_XEN_GtkWidget_(gtk_text_view_new_with_buffer(XEN_TO_C_GtkTextBuffer_(buffer))));
}
static XEN gxg_gtk_text_view_set_buffer(XEN text_view, XEN buffer)
{
  #define H_gtk_text_view_set_buffer "void gtk_text_view_set_buffer(GtkTextView* text_view, GtkTextBuffer* buffer)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_set_buffer", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_GtkTextBuffer__P(buffer), buffer, 2, "gtk_text_view_set_buffer", "GtkTextBuffer*");
  gtk_text_view_set_buffer(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_GtkTextBuffer_(buffer));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_view_get_buffer(XEN text_view)
{
  #define H_gtk_text_view_get_buffer "GtkTextBuffer* gtk_text_view_get_buffer(GtkTextView* text_view)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_get_buffer", "GtkTextView*");
  return(C_TO_XEN_GtkTextBuffer_(gtk_text_view_get_buffer(XEN_TO_C_GtkTextView_(text_view))));
}
static XEN gxg_gtk_text_view_scroll_to_iter(XEN text_view, XEN iter, XEN within_margin, XEN use_align, XEN xalign, XEN yalign)
{
  #define H_gtk_text_view_scroll_to_iter "gboolean gtk_text_view_scroll_to_iter(GtkTextView* text_view, \
GtkTextIter* iter, gdouble within_margin, gboolean use_align, gdouble xalign, gdouble yalign)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_scroll_to_iter", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 2, "gtk_text_view_scroll_to_iter", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gdouble_P(within_margin), within_margin, 3, "gtk_text_view_scroll_to_iter", "gdouble");
  XEN_ASSERT_TYPE(XEN_gboolean_P(use_align), use_align, 4, "gtk_text_view_scroll_to_iter", "gboolean");
  XEN_ASSERT_TYPE(XEN_gdouble_P(xalign), xalign, 5, "gtk_text_view_scroll_to_iter", "gdouble");
  XEN_ASSERT_TYPE(XEN_gdouble_P(yalign), yalign, 6, "gtk_text_view_scroll_to_iter", "gdouble");
  return(C_TO_XEN_gboolean(gtk_text_view_scroll_to_iter(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gdouble(within_margin), 
                                                        XEN_TO_C_gboolean(use_align), XEN_TO_C_gdouble(xalign), XEN_TO_C_gdouble(yalign))));
}
static XEN gxg_gtk_text_view_scroll_to_mark(XEN text_view, XEN mark, XEN within_margin, XEN use_align, XEN xalign, XEN yalign)
{
  #define H_gtk_text_view_scroll_to_mark "void gtk_text_view_scroll_to_mark(GtkTextView* text_view, GtkTextMark* mark, \
gdouble within_margin, gboolean use_align, gdouble xalign, gdouble yalign)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_scroll_to_mark", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_GtkTextMark__P(mark), mark, 2, "gtk_text_view_scroll_to_mark", "GtkTextMark*");
  XEN_ASSERT_TYPE(XEN_gdouble_P(within_margin), within_margin, 3, "gtk_text_view_scroll_to_mark", "gdouble");
  XEN_ASSERT_TYPE(XEN_gboolean_P(use_align), use_align, 4, "gtk_text_view_scroll_to_mark", "gboolean");
  XEN_ASSERT_TYPE(XEN_gdouble_P(xalign), xalign, 5, "gtk_text_view_scroll_to_mark", "gdouble");
  XEN_ASSERT_TYPE(XEN_gdouble_P(yalign), yalign, 6, "gtk_text_view_scroll_to_mark", "gdouble");
  gtk_text_view_scroll_to_mark(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_GtkTextMark_(mark), XEN_TO_C_gdouble(within_margin), 
                               XEN_TO_C_gboolean(use_align), XEN_TO_C_gdouble(xalign), XEN_TO_C_gdouble(yalign));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_view_scroll_mark_onscreen(XEN text_view, XEN mark)
{
  #define H_gtk_text_view_scroll_mark_onscreen "void gtk_text_view_scroll_mark_onscreen(GtkTextView* text_view, \
GtkTextMark* mark)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_scroll_mark_onscreen", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_GtkTextMark__P(mark), mark, 2, "gtk_text_view_scroll_mark_onscreen", "GtkTextMark*");
  gtk_text_view_scroll_mark_onscreen(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_GtkTextMark_(mark));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_view_move_mark_onscreen(XEN text_view, XEN mark)
{
  #define H_gtk_text_view_move_mark_onscreen "gboolean gtk_text_view_move_mark_onscreen(GtkTextView* text_view, \
GtkTextMark* mark)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_move_mark_onscreen", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_GtkTextMark__P(mark), mark, 2, "gtk_text_view_move_mark_onscreen", "GtkTextMark*");
  return(C_TO_XEN_gboolean(gtk_text_view_move_mark_onscreen(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_GtkTextMark_(mark))));
}
static XEN gxg_gtk_text_view_place_cursor_onscreen(XEN text_view)
{
  #define H_gtk_text_view_place_cursor_onscreen "gboolean gtk_text_view_place_cursor_onscreen(GtkTextView* text_view)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_place_cursor_onscreen", "GtkTextView*");
  return(C_TO_XEN_gboolean(gtk_text_view_place_cursor_onscreen(XEN_TO_C_GtkTextView_(text_view))));
}
static XEN gxg_gtk_text_view_get_visible_rect(XEN text_view, XEN visible_rect)
{
  #define H_gtk_text_view_get_visible_rect "void gtk_text_view_get_visible_rect(GtkTextView* text_view, \
GdkRectangle* visible_rect)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_get_visible_rect", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(visible_rect), visible_rect, 2, "gtk_text_view_get_visible_rect", "GdkRectangle*");
  gtk_text_view_get_visible_rect(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_GdkRectangle_(visible_rect));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_view_set_cursor_visible(XEN text_view, XEN setting)
{
  #define H_gtk_text_view_set_cursor_visible "void gtk_text_view_set_cursor_visible(GtkTextView* text_view, \
gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_set_cursor_visible", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gtk_text_view_set_cursor_visible", "gboolean");
  gtk_text_view_set_cursor_visible(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_view_get_cursor_visible(XEN text_view)
{
  #define H_gtk_text_view_get_cursor_visible "gboolean gtk_text_view_get_cursor_visible(GtkTextView* text_view)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_get_cursor_visible", "GtkTextView*");
  return(C_TO_XEN_gboolean(gtk_text_view_get_cursor_visible(XEN_TO_C_GtkTextView_(text_view))));
}
static XEN gxg_gtk_text_view_get_iter_location(XEN text_view, XEN iter, XEN location)
{
  #define H_gtk_text_view_get_iter_location "void gtk_text_view_get_iter_location(GtkTextView* text_view, \
GtkTextIter* iter, GdkRectangle* location)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_get_iter_location", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 2, "gtk_text_view_get_iter_location", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(location), location, 3, "gtk_text_view_get_iter_location", "GdkRectangle*");
  gtk_text_view_get_iter_location(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_GdkRectangle_(location));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_view_get_iter_at_location(XEN text_view, XEN iter, XEN x, XEN y)
{
  #define H_gtk_text_view_get_iter_at_location "void gtk_text_view_get_iter_at_location(GtkTextView* text_view, \
GtkTextIter* iter, gint x, gint y)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_get_iter_at_location", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 2, "gtk_text_view_get_iter_at_location", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 3, "gtk_text_view_get_iter_at_location", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 4, "gtk_text_view_get_iter_at_location", "gint");
  gtk_text_view_get_iter_at_location(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gint(x), XEN_TO_C_gint(y));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_view_get_line_yrange(XEN text_view, XEN iter, XEN y, XEN height)
{
  #define H_gtk_text_view_get_line_yrange "void gtk_text_view_get_line_yrange(GtkTextView* text_view, \
GtkTextIter* iter, gint* [y], gint* [height])"
  gint ref_y;
  gint ref_height;
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_get_line_yrange", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 2, "gtk_text_view_get_line_yrange", "GtkTextIter*");
  gtk_text_view_get_line_yrange(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_GtkTextIter_(iter), &ref_y, &ref_height);
  return(XEN_LIST_2(C_TO_XEN_gint(ref_y), C_TO_XEN_gint(ref_height)));
}
static XEN gxg_gtk_text_view_get_line_at_y(XEN text_view, XEN target_iter, XEN y, XEN line_top)
{
  #define H_gtk_text_view_get_line_at_y "void gtk_text_view_get_line_at_y(GtkTextView* text_view, GtkTextIter* target_iter, \
gint y, gint* [line_top])"
  gint ref_line_top;
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_get_line_at_y", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(target_iter), target_iter, 2, "gtk_text_view_get_line_at_y", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 3, "gtk_text_view_get_line_at_y", "gint");
  gtk_text_view_get_line_at_y(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_GtkTextIter_(target_iter), XEN_TO_C_gint(y), &ref_line_top);
  return(XEN_LIST_1(C_TO_XEN_gint(ref_line_top)));
}
static XEN gxg_gtk_text_view_buffer_to_window_coords(XEN text_view, XEN win, XEN buffer_x, XEN buffer_y, XEN window_x, XEN window_y)
{
  #define H_gtk_text_view_buffer_to_window_coords "void gtk_text_view_buffer_to_window_coords(GtkTextView* text_view, \
GtkTextWindowType win, gint buffer_x, gint buffer_y, gint* [window_x], gint* [window_y])"
  gint ref_window_x;
  gint ref_window_y;
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_buffer_to_window_coords", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_GtkTextWindowType_P(win), win, 2, "gtk_text_view_buffer_to_window_coords", "GtkTextWindowType");
  XEN_ASSERT_TYPE(XEN_gint_P(buffer_x), buffer_x, 3, "gtk_text_view_buffer_to_window_coords", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(buffer_y), buffer_y, 4, "gtk_text_view_buffer_to_window_coords", "gint");
  gtk_text_view_buffer_to_window_coords(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_GtkTextWindowType(win), XEN_TO_C_gint(buffer_x), 
                                        XEN_TO_C_gint(buffer_y), &ref_window_x, &ref_window_y);
  return(XEN_LIST_2(C_TO_XEN_gint(ref_window_x), C_TO_XEN_gint(ref_window_y)));
}
static XEN gxg_gtk_text_view_window_to_buffer_coords(XEN text_view, XEN win, XEN window_x, XEN window_y, XEN buffer_x, XEN buffer_y)
{
  #define H_gtk_text_view_window_to_buffer_coords "void gtk_text_view_window_to_buffer_coords(GtkTextView* text_view, \
GtkTextWindowType win, gint window_x, gint window_y, gint* [buffer_x], gint* [buffer_y])"
  gint ref_buffer_x;
  gint ref_buffer_y;
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_window_to_buffer_coords", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_GtkTextWindowType_P(win), win, 2, "gtk_text_view_window_to_buffer_coords", "GtkTextWindowType");
  XEN_ASSERT_TYPE(XEN_gint_P(window_x), window_x, 3, "gtk_text_view_window_to_buffer_coords", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(window_y), window_y, 4, "gtk_text_view_window_to_buffer_coords", "gint");
  gtk_text_view_window_to_buffer_coords(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_GtkTextWindowType(win), XEN_TO_C_gint(window_x), 
                                        XEN_TO_C_gint(window_y), &ref_buffer_x, &ref_buffer_y);
  return(XEN_LIST_2(C_TO_XEN_gint(ref_buffer_x), C_TO_XEN_gint(ref_buffer_y)));
}
static XEN gxg_gtk_text_view_get_window(XEN text_view, XEN win)
{
  #define H_gtk_text_view_get_window "GdkWindow* gtk_text_view_get_window(GtkTextView* text_view, GtkTextWindowType win)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_get_window", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_GtkTextWindowType_P(win), win, 2, "gtk_text_view_get_window", "GtkTextWindowType");
  return(C_TO_XEN_GdkWindow_(gtk_text_view_get_window(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_GtkTextWindowType(win))));
}
static XEN gxg_gtk_text_view_get_window_type(XEN text_view, XEN window)
{
  #define H_gtk_text_view_get_window_type "GtkTextWindowType gtk_text_view_get_window_type(GtkTextView* text_view, \
GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_get_window_type", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 2, "gtk_text_view_get_window_type", "GdkWindow*");
  return(C_TO_XEN_GtkTextWindowType(gtk_text_view_get_window_type(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_GdkWindow_(window))));
}
static XEN gxg_gtk_text_view_set_border_window_size(XEN text_view, XEN type, XEN size)
{
  #define H_gtk_text_view_set_border_window_size "void gtk_text_view_set_border_window_size(GtkTextView* text_view, \
GtkTextWindowType type, gint size)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_set_border_window_size", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_GtkTextWindowType_P(type), type, 2, "gtk_text_view_set_border_window_size", "GtkTextWindowType");
  XEN_ASSERT_TYPE(XEN_gint_P(size), size, 3, "gtk_text_view_set_border_window_size", "gint");
  gtk_text_view_set_border_window_size(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_GtkTextWindowType(type), XEN_TO_C_gint(size));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_view_get_border_window_size(XEN text_view, XEN type)
{
  #define H_gtk_text_view_get_border_window_size "gint gtk_text_view_get_border_window_size(GtkTextView* text_view, \
GtkTextWindowType type)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_get_border_window_size", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_GtkTextWindowType_P(type), type, 2, "gtk_text_view_get_border_window_size", "GtkTextWindowType");
  return(C_TO_XEN_gint(gtk_text_view_get_border_window_size(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_GtkTextWindowType(type))));
}
static XEN gxg_gtk_text_view_forward_display_line(XEN text_view, XEN iter)
{
  #define H_gtk_text_view_forward_display_line "gboolean gtk_text_view_forward_display_line(GtkTextView* text_view, \
GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_forward_display_line", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 2, "gtk_text_view_forward_display_line", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_view_forward_display_line(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_view_backward_display_line(XEN text_view, XEN iter)
{
  #define H_gtk_text_view_backward_display_line "gboolean gtk_text_view_backward_display_line(GtkTextView* text_view, \
GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_backward_display_line", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 2, "gtk_text_view_backward_display_line", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_view_backward_display_line(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_view_forward_display_line_end(XEN text_view, XEN iter)
{
  #define H_gtk_text_view_forward_display_line_end "gboolean gtk_text_view_forward_display_line_end(GtkTextView* text_view, \
GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_forward_display_line_end", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 2, "gtk_text_view_forward_display_line_end", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_view_forward_display_line_end(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_view_backward_display_line_start(XEN text_view, XEN iter)
{
  #define H_gtk_text_view_backward_display_line_start "gboolean gtk_text_view_backward_display_line_start(GtkTextView* text_view, \
GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_backward_display_line_start", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 2, "gtk_text_view_backward_display_line_start", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_view_backward_display_line_start(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_view_starts_display_line(XEN text_view, XEN iter)
{
  #define H_gtk_text_view_starts_display_line "gboolean gtk_text_view_starts_display_line(GtkTextView* text_view, \
GtkTextIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_starts_display_line", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 2, "gtk_text_view_starts_display_line", "GtkTextIter*");
  return(C_TO_XEN_gboolean(gtk_text_view_starts_display_line(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_GtkTextIter_(iter))));
}
static XEN gxg_gtk_text_view_move_visually(XEN text_view, XEN iter, XEN count)
{
  #define H_gtk_text_view_move_visually "gboolean gtk_text_view_move_visually(GtkTextView* text_view, \
GtkTextIter* iter, gint count)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_move_visually", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_GtkTextIter__P(iter), iter, 2, "gtk_text_view_move_visually", "GtkTextIter*");
  XEN_ASSERT_TYPE(XEN_gint_P(count), count, 3, "gtk_text_view_move_visually", "gint");
  return(C_TO_XEN_gboolean(gtk_text_view_move_visually(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_GtkTextIter_(iter), XEN_TO_C_gint(count))));
}
static XEN gxg_gtk_text_view_add_child_at_anchor(XEN text_view, XEN child, XEN anchor)
{
  #define H_gtk_text_view_add_child_at_anchor "void gtk_text_view_add_child_at_anchor(GtkTextView* text_view, \
GtkWidget* child, GtkTextChildAnchor* anchor)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_add_child_at_anchor", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_text_view_add_child_at_anchor", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkTextChildAnchor__P(anchor), anchor, 3, "gtk_text_view_add_child_at_anchor", "GtkTextChildAnchor*");
  gtk_text_view_add_child_at_anchor(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_GtkWidget_(child), XEN_TO_C_GtkTextChildAnchor_(anchor));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_view_add_child_in_window(XEN text_view, XEN child, XEN which_window, XEN xpos, XEN ypos)
{
  #define H_gtk_text_view_add_child_in_window "void gtk_text_view_add_child_in_window(GtkTextView* text_view, \
GtkWidget* child, GtkTextWindowType which_window, gint xpos, gint ypos)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_add_child_in_window", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_text_view_add_child_in_window", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkTextWindowType_P(which_window), which_window, 3, "gtk_text_view_add_child_in_window", "GtkTextWindowType");
  XEN_ASSERT_TYPE(XEN_gint_P(xpos), xpos, 4, "gtk_text_view_add_child_in_window", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(ypos), ypos, 5, "gtk_text_view_add_child_in_window", "gint");
  gtk_text_view_add_child_in_window(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_GtkWidget_(child), XEN_TO_C_GtkTextWindowType(which_window), 
                                    XEN_TO_C_gint(xpos), XEN_TO_C_gint(ypos));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_view_move_child(XEN text_view, XEN child, XEN xpos, XEN ypos)
{
  #define H_gtk_text_view_move_child "void gtk_text_view_move_child(GtkTextView* text_view, GtkWidget* child, \
gint xpos, gint ypos)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_move_child", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(child), child, 2, "gtk_text_view_move_child", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gint_P(xpos), xpos, 3, "gtk_text_view_move_child", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(ypos), ypos, 4, "gtk_text_view_move_child", "gint");
  gtk_text_view_move_child(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_GtkWidget_(child), XEN_TO_C_gint(xpos), XEN_TO_C_gint(ypos));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_view_set_wrap_mode(XEN text_view, XEN wrap_mode)
{
  #define H_gtk_text_view_set_wrap_mode "void gtk_text_view_set_wrap_mode(GtkTextView* text_view, GtkWrapMode wrap_mode)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_set_wrap_mode", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_GtkWrapMode_P(wrap_mode), wrap_mode, 2, "gtk_text_view_set_wrap_mode", "GtkWrapMode");
  gtk_text_view_set_wrap_mode(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_GtkWrapMode(wrap_mode));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_view_get_wrap_mode(XEN text_view)
{
  #define H_gtk_text_view_get_wrap_mode "GtkWrapMode gtk_text_view_get_wrap_mode(GtkTextView* text_view)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_get_wrap_mode", "GtkTextView*");
  return(C_TO_XEN_GtkWrapMode(gtk_text_view_get_wrap_mode(XEN_TO_C_GtkTextView_(text_view))));
}
static XEN gxg_gtk_text_view_set_editable(XEN text_view, XEN setting)
{
  #define H_gtk_text_view_set_editable "void gtk_text_view_set_editable(GtkTextView* text_view, gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_set_editable", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gtk_text_view_set_editable", "gboolean");
  gtk_text_view_set_editable(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_view_get_editable(XEN text_view)
{
  #define H_gtk_text_view_get_editable "gboolean gtk_text_view_get_editable(GtkTextView* text_view)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_get_editable", "GtkTextView*");
  return(C_TO_XEN_gboolean(gtk_text_view_get_editable(XEN_TO_C_GtkTextView_(text_view))));
}
static XEN gxg_gtk_text_view_set_pixels_above_lines(XEN text_view, XEN pixels_above_lines)
{
  #define H_gtk_text_view_set_pixels_above_lines "void gtk_text_view_set_pixels_above_lines(GtkTextView* text_view, \
gint pixels_above_lines)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_set_pixels_above_lines", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_gint_P(pixels_above_lines), pixels_above_lines, 2, "gtk_text_view_set_pixels_above_lines", "gint");
  gtk_text_view_set_pixels_above_lines(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_gint(pixels_above_lines));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_view_get_pixels_above_lines(XEN text_view)
{
  #define H_gtk_text_view_get_pixels_above_lines "gint gtk_text_view_get_pixels_above_lines(GtkTextView* text_view)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_get_pixels_above_lines", "GtkTextView*");
  return(C_TO_XEN_gint(gtk_text_view_get_pixels_above_lines(XEN_TO_C_GtkTextView_(text_view))));
}
static XEN gxg_gtk_text_view_set_pixels_below_lines(XEN text_view, XEN pixels_below_lines)
{
  #define H_gtk_text_view_set_pixels_below_lines "void gtk_text_view_set_pixels_below_lines(GtkTextView* text_view, \
gint pixels_below_lines)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_set_pixels_below_lines", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_gint_P(pixels_below_lines), pixels_below_lines, 2, "gtk_text_view_set_pixels_below_lines", "gint");
  gtk_text_view_set_pixels_below_lines(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_gint(pixels_below_lines));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_view_get_pixels_below_lines(XEN text_view)
{
  #define H_gtk_text_view_get_pixels_below_lines "gint gtk_text_view_get_pixels_below_lines(GtkTextView* text_view)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_get_pixels_below_lines", "GtkTextView*");
  return(C_TO_XEN_gint(gtk_text_view_get_pixels_below_lines(XEN_TO_C_GtkTextView_(text_view))));
}
static XEN gxg_gtk_text_view_set_pixels_inside_wrap(XEN text_view, XEN pixels_inside_wrap)
{
  #define H_gtk_text_view_set_pixels_inside_wrap "void gtk_text_view_set_pixels_inside_wrap(GtkTextView* text_view, \
gint pixels_inside_wrap)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_set_pixels_inside_wrap", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_gint_P(pixels_inside_wrap), pixels_inside_wrap, 2, "gtk_text_view_set_pixels_inside_wrap", "gint");
  gtk_text_view_set_pixels_inside_wrap(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_gint(pixels_inside_wrap));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_view_get_pixels_inside_wrap(XEN text_view)
{
  #define H_gtk_text_view_get_pixels_inside_wrap "gint gtk_text_view_get_pixels_inside_wrap(GtkTextView* text_view)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_get_pixels_inside_wrap", "GtkTextView*");
  return(C_TO_XEN_gint(gtk_text_view_get_pixels_inside_wrap(XEN_TO_C_GtkTextView_(text_view))));
}
static XEN gxg_gtk_text_view_set_justification(XEN text_view, XEN justification)
{
  #define H_gtk_text_view_set_justification "void gtk_text_view_set_justification(GtkTextView* text_view, \
GtkJustification justification)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_set_justification", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_GtkJustification_P(justification), justification, 2, "gtk_text_view_set_justification", "GtkJustification");
  gtk_text_view_set_justification(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_GtkJustification(justification));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_view_get_justification(XEN text_view)
{
  #define H_gtk_text_view_get_justification "GtkJustification gtk_text_view_get_justification(GtkTextView* text_view)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_get_justification", "GtkTextView*");
  return(C_TO_XEN_GtkJustification(gtk_text_view_get_justification(XEN_TO_C_GtkTextView_(text_view))));
}
static XEN gxg_gtk_text_view_set_left_margin(XEN text_view, XEN left_margin)
{
  #define H_gtk_text_view_set_left_margin "void gtk_text_view_set_left_margin(GtkTextView* text_view, \
gint left_margin)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_set_left_margin", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_gint_P(left_margin), left_margin, 2, "gtk_text_view_set_left_margin", "gint");
  gtk_text_view_set_left_margin(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_gint(left_margin));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_view_get_left_margin(XEN text_view)
{
  #define H_gtk_text_view_get_left_margin "gint gtk_text_view_get_left_margin(GtkTextView* text_view)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_get_left_margin", "GtkTextView*");
  return(C_TO_XEN_gint(gtk_text_view_get_left_margin(XEN_TO_C_GtkTextView_(text_view))));
}
static XEN gxg_gtk_text_view_set_right_margin(XEN text_view, XEN right_margin)
{
  #define H_gtk_text_view_set_right_margin "void gtk_text_view_set_right_margin(GtkTextView* text_view, \
gint right_margin)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_set_right_margin", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_gint_P(right_margin), right_margin, 2, "gtk_text_view_set_right_margin", "gint");
  gtk_text_view_set_right_margin(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_gint(right_margin));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_view_get_right_margin(XEN text_view)
{
  #define H_gtk_text_view_get_right_margin "gint gtk_text_view_get_right_margin(GtkTextView* text_view)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_get_right_margin", "GtkTextView*");
  return(C_TO_XEN_gint(gtk_text_view_get_right_margin(XEN_TO_C_GtkTextView_(text_view))));
}
static XEN gxg_gtk_text_view_set_indent(XEN text_view, XEN indent)
{
  #define H_gtk_text_view_set_indent "void gtk_text_view_set_indent(GtkTextView* text_view, gint indent)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_set_indent", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_gint_P(indent), indent, 2, "gtk_text_view_set_indent", "gint");
  gtk_text_view_set_indent(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_gint(indent));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_view_get_indent(XEN text_view)
{
  #define H_gtk_text_view_get_indent "gint gtk_text_view_get_indent(GtkTextView* text_view)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_get_indent", "GtkTextView*");
  return(C_TO_XEN_gint(gtk_text_view_get_indent(XEN_TO_C_GtkTextView_(text_view))));
}
static XEN gxg_gtk_text_view_set_tabs(XEN text_view, XEN tabs)
{
  #define H_gtk_text_view_set_tabs "void gtk_text_view_set_tabs(GtkTextView* text_view, PangoTabArray* tabs)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_set_tabs", "GtkTextView*");
  XEN_ASSERT_TYPE(XEN_PangoTabArray__P(tabs), tabs, 2, "gtk_text_view_set_tabs", "PangoTabArray*");
  gtk_text_view_set_tabs(XEN_TO_C_GtkTextView_(text_view), XEN_TO_C_PangoTabArray_(tabs));
  return(XEN_FALSE);
}
static XEN gxg_gtk_text_view_get_tabs(XEN text_view)
{
  #define H_gtk_text_view_get_tabs "PangoTabArray* gtk_text_view_get_tabs(GtkTextView* text_view)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_get_tabs", "GtkTextView*");
  return(C_TO_XEN_PangoTabArray_(gtk_text_view_get_tabs(XEN_TO_C_GtkTextView_(text_view))));
}
static XEN gxg_gtk_text_view_get_default_attributes(XEN text_view)
{
  #define H_gtk_text_view_get_default_attributes "GtkTextAttributes* gtk_text_view_get_default_attributes(GtkTextView* text_view)"
  XEN_ASSERT_TYPE(XEN_GtkTextView__P(text_view), text_view, 1, "gtk_text_view_get_default_attributes", "GtkTextView*");
  return(C_TO_XEN_GtkTextAttributes_(gtk_text_view_get_default_attributes(XEN_TO_C_GtkTextView_(text_view))));
}
static XEN gxg_gtk_toggle_button_get_type(void)
{
  #define H_gtk_toggle_button_get_type "GtkType gtk_toggle_button_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_toggle_button_get_type()));
}
static XEN gxg_gtk_toggle_button_new(void)
{
  #define H_gtk_toggle_button_new "GtkWidget* gtk_toggle_button_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_toggle_button_new()));
}
static XEN gxg_gtk_toggle_button_new_with_label(XEN label)
{
  #define H_gtk_toggle_button_new_with_label "GtkWidget* gtk_toggle_button_new_with_label(gchar* label)"
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 1, "gtk_toggle_button_new_with_label", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_toggle_button_new_with_label(XEN_TO_C_gchar_(label))));
}
static XEN gxg_gtk_toggle_button_new_with_mnemonic(XEN label)
{
  #define H_gtk_toggle_button_new_with_mnemonic "GtkWidget* gtk_toggle_button_new_with_mnemonic(gchar* label)"
  XEN_ASSERT_TYPE(XEN_gchar__P(label), label, 1, "gtk_toggle_button_new_with_mnemonic", "gchar*");
  return(C_TO_XEN_GtkWidget_(gtk_toggle_button_new_with_mnemonic(XEN_TO_C_gchar_(label))));
}
static XEN gxg_gtk_toggle_button_set_mode(XEN toggle_button, XEN draw_indicator)
{
  #define H_gtk_toggle_button_set_mode "void gtk_toggle_button_set_mode(GtkToggleButton* toggle_button, \
gboolean draw_indicator)"
  XEN_ASSERT_TYPE(XEN_GtkToggleButton__P(toggle_button), toggle_button, 1, "gtk_toggle_button_set_mode", "GtkToggleButton*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(draw_indicator), draw_indicator, 2, "gtk_toggle_button_set_mode", "gboolean");
  gtk_toggle_button_set_mode(XEN_TO_C_GtkToggleButton_(toggle_button), XEN_TO_C_gboolean(draw_indicator));
  return(XEN_FALSE);
}
static XEN gxg_gtk_toggle_button_get_mode(XEN toggle_button)
{
  #define H_gtk_toggle_button_get_mode "gboolean gtk_toggle_button_get_mode(GtkToggleButton* toggle_button)"
  XEN_ASSERT_TYPE(XEN_GtkToggleButton__P(toggle_button), toggle_button, 1, "gtk_toggle_button_get_mode", "GtkToggleButton*");
  return(C_TO_XEN_gboolean(gtk_toggle_button_get_mode(XEN_TO_C_GtkToggleButton_(toggle_button))));
}
static XEN gxg_gtk_toggle_button_set_active(XEN toggle_button, XEN is_active)
{
  #define H_gtk_toggle_button_set_active "void gtk_toggle_button_set_active(GtkToggleButton* toggle_button, \
gboolean is_active)"
  XEN_ASSERT_TYPE(XEN_GtkToggleButton__P(toggle_button), toggle_button, 1, "gtk_toggle_button_set_active", "GtkToggleButton*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(is_active), is_active, 2, "gtk_toggle_button_set_active", "gboolean");
  gtk_toggle_button_set_active(XEN_TO_C_GtkToggleButton_(toggle_button), XEN_TO_C_gboolean(is_active));
  return(XEN_FALSE);
}
static XEN gxg_gtk_toggle_button_get_active(XEN toggle_button)
{
  #define H_gtk_toggle_button_get_active "gboolean gtk_toggle_button_get_active(GtkToggleButton* toggle_button)"
  XEN_ASSERT_TYPE(XEN_GtkToggleButton__P(toggle_button), toggle_button, 1, "gtk_toggle_button_get_active", "GtkToggleButton*");
  return(C_TO_XEN_gboolean(gtk_toggle_button_get_active(XEN_TO_C_GtkToggleButton_(toggle_button))));
}
static XEN gxg_gtk_toggle_button_toggled(XEN toggle_button)
{
  #define H_gtk_toggle_button_toggled "void gtk_toggle_button_toggled(GtkToggleButton* toggle_button)"
  XEN_ASSERT_TYPE(XEN_GtkToggleButton__P(toggle_button), toggle_button, 1, "gtk_toggle_button_toggled", "GtkToggleButton*");
  gtk_toggle_button_toggled(XEN_TO_C_GtkToggleButton_(toggle_button));
  return(XEN_FALSE);
}
static XEN gxg_gtk_toggle_button_set_inconsistent(XEN toggle_button, XEN setting)
{
  #define H_gtk_toggle_button_set_inconsistent "void gtk_toggle_button_set_inconsistent(GtkToggleButton* toggle_button, \
gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GtkToggleButton__P(toggle_button), toggle_button, 1, "gtk_toggle_button_set_inconsistent", "GtkToggleButton*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gtk_toggle_button_set_inconsistent", "gboolean");
  gtk_toggle_button_set_inconsistent(XEN_TO_C_GtkToggleButton_(toggle_button), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_toggle_button_get_inconsistent(XEN toggle_button)
{
  #define H_gtk_toggle_button_get_inconsistent "gboolean gtk_toggle_button_get_inconsistent(GtkToggleButton* toggle_button)"
  XEN_ASSERT_TYPE(XEN_GtkToggleButton__P(toggle_button), toggle_button, 1, "gtk_toggle_button_get_inconsistent", "GtkToggleButton*");
  return(C_TO_XEN_gboolean(gtk_toggle_button_get_inconsistent(XEN_TO_C_GtkToggleButton_(toggle_button))));
}
static XEN gxg_gtk_toolbar_get_type(void)
{
  #define H_gtk_toolbar_get_type "GtkType gtk_toolbar_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_toolbar_get_type()));
}
static XEN gxg_gtk_toolbar_new(void)
{
  #define H_gtk_toolbar_new "GtkWidget* gtk_toolbar_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_toolbar_new()));
}
static XEN gxg_gtk_toolbar_set_orientation(XEN toolbar, XEN orientation)
{
  #define H_gtk_toolbar_set_orientation "void gtk_toolbar_set_orientation(GtkToolbar* toolbar, GtkOrientation orientation)"
  XEN_ASSERT_TYPE(XEN_GtkToolbar__P(toolbar), toolbar, 1, "gtk_toolbar_set_orientation", "GtkToolbar*");
  XEN_ASSERT_TYPE(XEN_GtkOrientation_P(orientation), orientation, 2, "gtk_toolbar_set_orientation", "GtkOrientation");
  gtk_toolbar_set_orientation(XEN_TO_C_GtkToolbar_(toolbar), XEN_TO_C_GtkOrientation(orientation));
  return(XEN_FALSE);
}
static XEN gxg_gtk_toolbar_set_style(XEN toolbar, XEN style)
{
  #define H_gtk_toolbar_set_style "void gtk_toolbar_set_style(GtkToolbar* toolbar, GtkToolbarStyle style)"
  XEN_ASSERT_TYPE(XEN_GtkToolbar__P(toolbar), toolbar, 1, "gtk_toolbar_set_style", "GtkToolbar*");
  XEN_ASSERT_TYPE(XEN_GtkToolbarStyle_P(style), style, 2, "gtk_toolbar_set_style", "GtkToolbarStyle");
  gtk_toolbar_set_style(XEN_TO_C_GtkToolbar_(toolbar), XEN_TO_C_GtkToolbarStyle(style));
  return(XEN_FALSE);
}
static XEN gxg_gtk_toolbar_set_tooltips(XEN toolbar, XEN enable)
{
  #define H_gtk_toolbar_set_tooltips "void gtk_toolbar_set_tooltips(GtkToolbar* toolbar, gboolean enable)"
  XEN_ASSERT_TYPE(XEN_GtkToolbar__P(toolbar), toolbar, 1, "gtk_toolbar_set_tooltips", "GtkToolbar*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(enable), enable, 2, "gtk_toolbar_set_tooltips", "gboolean");
  gtk_toolbar_set_tooltips(XEN_TO_C_GtkToolbar_(toolbar), XEN_TO_C_gboolean(enable));
  return(XEN_FALSE);
}
static XEN gxg_gtk_toolbar_unset_style(XEN toolbar)
{
  #define H_gtk_toolbar_unset_style "void gtk_toolbar_unset_style(GtkToolbar* toolbar)"
  XEN_ASSERT_TYPE(XEN_GtkToolbar__P(toolbar), toolbar, 1, "gtk_toolbar_unset_style", "GtkToolbar*");
  gtk_toolbar_unset_style(XEN_TO_C_GtkToolbar_(toolbar));
  return(XEN_FALSE);
}
static XEN gxg_gtk_toolbar_get_orientation(XEN toolbar)
{
  #define H_gtk_toolbar_get_orientation "GtkOrientation gtk_toolbar_get_orientation(GtkToolbar* toolbar)"
  XEN_ASSERT_TYPE(XEN_GtkToolbar__P(toolbar), toolbar, 1, "gtk_toolbar_get_orientation", "GtkToolbar*");
  return(C_TO_XEN_GtkOrientation(gtk_toolbar_get_orientation(XEN_TO_C_GtkToolbar_(toolbar))));
}
static XEN gxg_gtk_toolbar_get_style(XEN toolbar)
{
  #define H_gtk_toolbar_get_style "GtkToolbarStyle gtk_toolbar_get_style(GtkToolbar* toolbar)"
  XEN_ASSERT_TYPE(XEN_GtkToolbar__P(toolbar), toolbar, 1, "gtk_toolbar_get_style", "GtkToolbar*");
  return(C_TO_XEN_GtkToolbarStyle(gtk_toolbar_get_style(XEN_TO_C_GtkToolbar_(toolbar))));
}
static XEN gxg_gtk_toolbar_get_icon_size(XEN toolbar)
{
  #define H_gtk_toolbar_get_icon_size "GtkIconSize gtk_toolbar_get_icon_size(GtkToolbar* toolbar)"
  XEN_ASSERT_TYPE(XEN_GtkToolbar__P(toolbar), toolbar, 1, "gtk_toolbar_get_icon_size", "GtkToolbar*");
  return(C_TO_XEN_GtkIconSize(gtk_toolbar_get_icon_size(XEN_TO_C_GtkToolbar_(toolbar))));
}
static XEN gxg_gtk_toolbar_get_tooltips(XEN toolbar)
{
  #define H_gtk_toolbar_get_tooltips "gboolean gtk_toolbar_get_tooltips(GtkToolbar* toolbar)"
  XEN_ASSERT_TYPE(XEN_GtkToolbar__P(toolbar), toolbar, 1, "gtk_toolbar_get_tooltips", "GtkToolbar*");
  return(C_TO_XEN_gboolean(gtk_toolbar_get_tooltips(XEN_TO_C_GtkToolbar_(toolbar))));
}
static XEN gxg_gtk_tooltips_get_type(void)
{
  #define H_gtk_tooltips_get_type "GtkType gtk_tooltips_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_tooltips_get_type()));
}
static XEN gxg_gtk_tooltips_new(void)
{
  #define H_gtk_tooltips_new "GtkTooltips* gtk_tooltips_new( void)"
  return(C_TO_XEN_GtkTooltips_(gtk_tooltips_new()));
}
static XEN gxg_gtk_tooltips_enable(XEN tooltips)
{
  #define H_gtk_tooltips_enable "void gtk_tooltips_enable(GtkTooltips* tooltips)"
  XEN_ASSERT_TYPE(XEN_GtkTooltips__P(tooltips), tooltips, 1, "gtk_tooltips_enable", "GtkTooltips*");
  gtk_tooltips_enable(XEN_TO_C_GtkTooltips_(tooltips));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tooltips_disable(XEN tooltips)
{
  #define H_gtk_tooltips_disable "void gtk_tooltips_disable(GtkTooltips* tooltips)"
  XEN_ASSERT_TYPE(XEN_GtkTooltips__P(tooltips), tooltips, 1, "gtk_tooltips_disable", "GtkTooltips*");
  gtk_tooltips_disable(XEN_TO_C_GtkTooltips_(tooltips));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tooltips_set_tip(XEN tooltips, XEN widget, XEN tip_text, XEN tip_private)
{
  #define H_gtk_tooltips_set_tip "void gtk_tooltips_set_tip(GtkTooltips* tooltips, GtkWidget* widget, \
gchar* tip_text, gchar* tip_private)"
  XEN_ASSERT_TYPE(XEN_GtkTooltips__P(tooltips), tooltips, 1, "gtk_tooltips_set_tip", "GtkTooltips*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 2, "gtk_tooltips_set_tip", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(tip_text), tip_text, 3, "gtk_tooltips_set_tip", "gchar*");
  XEN_ASSERT_TYPE(XEN_gchar__P(tip_private), tip_private, 4, "gtk_tooltips_set_tip", "gchar*");
  gtk_tooltips_set_tip(XEN_TO_C_GtkTooltips_(tooltips), XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(tip_text), XEN_TO_C_gchar_(tip_private));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tooltips_data_get(XEN widget)
{
  #define H_gtk_tooltips_data_get "GtkTooltipsData* gtk_tooltips_data_get(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_tooltips_data_get", "GtkWidget*");
  return(C_TO_XEN_GtkTooltipsData_(gtk_tooltips_data_get(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_tooltips_force_window(XEN tooltips)
{
  #define H_gtk_tooltips_force_window "void gtk_tooltips_force_window(GtkTooltips* tooltips)"
  XEN_ASSERT_TYPE(XEN_GtkTooltips__P(tooltips), tooltips, 1, "gtk_tooltips_force_window", "GtkTooltips*");
  gtk_tooltips_force_window(XEN_TO_C_GtkTooltips_(tooltips));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_drag_source_get_type(void)
{
  #define H_gtk_tree_drag_source_get_type "GType gtk_tree_drag_source_get_type( void)"
  return(C_TO_XEN_GType(gtk_tree_drag_source_get_type()));
}
static XEN gxg_gtk_tree_drag_source_row_draggable(XEN drag_source, XEN path)
{
  #define H_gtk_tree_drag_source_row_draggable "gboolean gtk_tree_drag_source_row_draggable(GtkTreeDragSource* drag_source, \
GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GtkTreeDragSource__P(drag_source), drag_source, 1, "gtk_tree_drag_source_row_draggable", "GtkTreeDragSource*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 2, "gtk_tree_drag_source_row_draggable", "GtkTreePath*");
  return(C_TO_XEN_gboolean(gtk_tree_drag_source_row_draggable(XEN_TO_C_GtkTreeDragSource_(drag_source), XEN_TO_C_GtkTreePath_(path))));
}
static XEN gxg_gtk_tree_drag_source_drag_data_delete(XEN drag_source, XEN path)
{
  #define H_gtk_tree_drag_source_drag_data_delete "gboolean gtk_tree_drag_source_drag_data_delete(GtkTreeDragSource* drag_source, \
GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GtkTreeDragSource__P(drag_source), drag_source, 1, "gtk_tree_drag_source_drag_data_delete", "GtkTreeDragSource*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 2, "gtk_tree_drag_source_drag_data_delete", "GtkTreePath*");
  return(C_TO_XEN_gboolean(gtk_tree_drag_source_drag_data_delete(XEN_TO_C_GtkTreeDragSource_(drag_source), XEN_TO_C_GtkTreePath_(path))));
}
static XEN gxg_gtk_tree_drag_source_drag_data_get(XEN drag_source, XEN path, XEN selection_data)
{
  #define H_gtk_tree_drag_source_drag_data_get "gboolean gtk_tree_drag_source_drag_data_get(GtkTreeDragSource* drag_source, \
GtkTreePath* path, GtkSelectionData* selection_data)"
  XEN_ASSERT_TYPE(XEN_GtkTreeDragSource__P(drag_source), drag_source, 1, "gtk_tree_drag_source_drag_data_get", "GtkTreeDragSource*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 2, "gtk_tree_drag_source_drag_data_get", "GtkTreePath*");
  XEN_ASSERT_TYPE(XEN_GtkSelectionData__P(selection_data), selection_data, 3, "gtk_tree_drag_source_drag_data_get", "GtkSelectionData*");
  return(C_TO_XEN_gboolean(gtk_tree_drag_source_drag_data_get(XEN_TO_C_GtkTreeDragSource_(drag_source), XEN_TO_C_GtkTreePath_(path), 
                                                              XEN_TO_C_GtkSelectionData_(selection_data))));
}
static XEN gxg_gtk_tree_drag_dest_get_type(void)
{
  #define H_gtk_tree_drag_dest_get_type "GType gtk_tree_drag_dest_get_type( void)"
  return(C_TO_XEN_GType(gtk_tree_drag_dest_get_type()));
}
static XEN gxg_gtk_tree_drag_dest_drag_data_received(XEN drag_dest, XEN dest, XEN selection_data)
{
  #define H_gtk_tree_drag_dest_drag_data_received "gboolean gtk_tree_drag_dest_drag_data_received(GtkTreeDragDest* drag_dest, \
GtkTreePath* dest, GtkSelectionData* selection_data)"
  XEN_ASSERT_TYPE(XEN_GtkTreeDragDest__P(drag_dest), drag_dest, 1, "gtk_tree_drag_dest_drag_data_received", "GtkTreeDragDest*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(dest), dest, 2, "gtk_tree_drag_dest_drag_data_received", "GtkTreePath*");
  XEN_ASSERT_TYPE(XEN_GtkSelectionData__P(selection_data), selection_data, 3, "gtk_tree_drag_dest_drag_data_received", "GtkSelectionData*");
  return(C_TO_XEN_gboolean(gtk_tree_drag_dest_drag_data_received(XEN_TO_C_GtkTreeDragDest_(drag_dest), XEN_TO_C_GtkTreePath_(dest), 
                                                                 XEN_TO_C_GtkSelectionData_(selection_data))));
}
static XEN gxg_gtk_tree_drag_dest_row_drop_possible(XEN drag_dest, XEN dest_path, XEN selection_data)
{
  #define H_gtk_tree_drag_dest_row_drop_possible "gboolean gtk_tree_drag_dest_row_drop_possible(GtkTreeDragDest* drag_dest, \
GtkTreePath* dest_path, GtkSelectionData* selection_data)"
  XEN_ASSERT_TYPE(XEN_GtkTreeDragDest__P(drag_dest), drag_dest, 1, "gtk_tree_drag_dest_row_drop_possible", "GtkTreeDragDest*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(dest_path), dest_path, 2, "gtk_tree_drag_dest_row_drop_possible", "GtkTreePath*");
  XEN_ASSERT_TYPE(XEN_GtkSelectionData__P(selection_data), selection_data, 3, "gtk_tree_drag_dest_row_drop_possible", "GtkSelectionData*");
  return(C_TO_XEN_gboolean(gtk_tree_drag_dest_row_drop_possible(XEN_TO_C_GtkTreeDragDest_(drag_dest), XEN_TO_C_GtkTreePath_(dest_path), 
                                                                XEN_TO_C_GtkSelectionData_(selection_data))));
}
static XEN gxg_gtk_tree_set_row_drag_data(XEN selection_data, XEN tree_model, XEN path)
{
  #define H_gtk_tree_set_row_drag_data "gboolean gtk_tree_set_row_drag_data(GtkSelectionData* selection_data, \
GtkTreeModel* tree_model, GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GtkSelectionData__P(selection_data), selection_data, 1, "gtk_tree_set_row_drag_data", "GtkSelectionData*");
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(tree_model), tree_model, 2, "gtk_tree_set_row_drag_data", "GtkTreeModel*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 3, "gtk_tree_set_row_drag_data", "GtkTreePath*");
  return(C_TO_XEN_gboolean(gtk_tree_set_row_drag_data(XEN_TO_C_GtkSelectionData_(selection_data), XEN_TO_C_GtkTreeModel_(tree_model), 
                                                      XEN_TO_C_GtkTreePath_(path))));
}
static XEN gxg_gtk_tree_get_row_drag_data(XEN selection_data, XEN tree_model, XEN path)
{
  #define H_gtk_tree_get_row_drag_data "gboolean gtk_tree_get_row_drag_data(GtkSelectionData* selection_data, \
GtkTreeModel** [tree_model], GtkTreePath** [path])"
  GtkTreeModel* ref_tree_model = NULL;
  GtkTreePath* ref_path = NULL;
  XEN_ASSERT_TYPE(XEN_GtkSelectionData__P(selection_data), selection_data, 1, "gtk_tree_get_row_drag_data", "GtkSelectionData*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gtk_tree_get_row_drag_data(XEN_TO_C_GtkSelectionData_(selection_data), &ref_tree_model, &ref_path));
    return(XEN_LIST_3(result, C_TO_XEN_GtkTreeModel_(ref_tree_model), C_TO_XEN_GtkTreePath_(ref_path)));
   }
}
static XEN gxg_gtk_tree_path_new(void)
{
  #define H_gtk_tree_path_new "GtkTreePath* gtk_tree_path_new( void)"
  return(C_TO_XEN_GtkTreePath_(gtk_tree_path_new()));
}
static XEN gxg_gtk_tree_path_new_from_string(XEN path)
{
  #define H_gtk_tree_path_new_from_string "GtkTreePath* gtk_tree_path_new_from_string(gchar* path)"
  XEN_ASSERT_TYPE(XEN_gchar__P(path), path, 1, "gtk_tree_path_new_from_string", "gchar*");
  return(C_TO_XEN_GtkTreePath_(gtk_tree_path_new_from_string(XEN_TO_C_gchar_(path))));
}
static XEN gxg_gtk_tree_path_to_string(XEN path)
{
  #define H_gtk_tree_path_to_string "gchar* gtk_tree_path_to_string(GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 1, "gtk_tree_path_to_string", "GtkTreePath*");
  return(C_TO_XEN_gchar_(gtk_tree_path_to_string(XEN_TO_C_GtkTreePath_(path))));
}
static XEN gxg_gtk_tree_path_new_first(void)
{
  #define H_gtk_tree_path_new_first "GtkTreePath* gtk_tree_path_new_first( void)"
  return(C_TO_XEN_GtkTreePath_(gtk_tree_path_new_first()));
}
static XEN gxg_gtk_tree_path_append_index(XEN path, XEN index)
{
  #define H_gtk_tree_path_append_index "void gtk_tree_path_append_index(GtkTreePath* path, gint index)"
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 1, "gtk_tree_path_append_index", "GtkTreePath*");
  XEN_ASSERT_TYPE(XEN_gint_P(index), index, 2, "gtk_tree_path_append_index", "gint");
  gtk_tree_path_append_index(XEN_TO_C_GtkTreePath_(path), XEN_TO_C_gint(index));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_path_prepend_index(XEN path, XEN index)
{
  #define H_gtk_tree_path_prepend_index "void gtk_tree_path_prepend_index(GtkTreePath* path, gint index)"
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 1, "gtk_tree_path_prepend_index", "GtkTreePath*");
  XEN_ASSERT_TYPE(XEN_gint_P(index), index, 2, "gtk_tree_path_prepend_index", "gint");
  gtk_tree_path_prepend_index(XEN_TO_C_GtkTreePath_(path), XEN_TO_C_gint(index));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_path_get_depth(XEN path)
{
  #define H_gtk_tree_path_get_depth "gint gtk_tree_path_get_depth(GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 1, "gtk_tree_path_get_depth", "GtkTreePath*");
  return(C_TO_XEN_gint(gtk_tree_path_get_depth(XEN_TO_C_GtkTreePath_(path))));
}
static XEN gxg_gtk_tree_path_get_indices(XEN path)
{
  #define H_gtk_tree_path_get_indices "gint* gtk_tree_path_get_indices(GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 1, "gtk_tree_path_get_indices", "GtkTreePath*");
  return(C_TO_XEN_gint_(gtk_tree_path_get_indices(XEN_TO_C_GtkTreePath_(path))));
}
static XEN gxg_gtk_tree_path_free(XEN path)
{
  #define H_gtk_tree_path_free "void gtk_tree_path_free(GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 1, "gtk_tree_path_free", "GtkTreePath*");
  gtk_tree_path_free(XEN_TO_C_GtkTreePath_(path));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_path_copy(XEN path)
{
  #define H_gtk_tree_path_copy "GtkTreePath* gtk_tree_path_copy(GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 1, "gtk_tree_path_copy", "GtkTreePath*");
  return(C_TO_XEN_GtkTreePath_(gtk_tree_path_copy(XEN_TO_C_GtkTreePath_(path))));
}
static XEN gxg_gtk_tree_path_compare(XEN a, XEN b)
{
  #define H_gtk_tree_path_compare "gint gtk_tree_path_compare(GtkTreePath* a, GtkTreePath* b)"
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(a), a, 1, "gtk_tree_path_compare", "GtkTreePath*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(b), b, 2, "gtk_tree_path_compare", "GtkTreePath*");
  return(C_TO_XEN_gint(gtk_tree_path_compare(XEN_TO_C_GtkTreePath_(a), XEN_TO_C_GtkTreePath_(b))));
}
static XEN gxg_gtk_tree_path_next(XEN path)
{
  #define H_gtk_tree_path_next "void gtk_tree_path_next(GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 1, "gtk_tree_path_next", "GtkTreePath*");
  gtk_tree_path_next(XEN_TO_C_GtkTreePath_(path));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_path_prev(XEN path)
{
  #define H_gtk_tree_path_prev "gboolean gtk_tree_path_prev(GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 1, "gtk_tree_path_prev", "GtkTreePath*");
  return(C_TO_XEN_gboolean(gtk_tree_path_prev(XEN_TO_C_GtkTreePath_(path))));
}
static XEN gxg_gtk_tree_path_up(XEN path)
{
  #define H_gtk_tree_path_up "gboolean gtk_tree_path_up(GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 1, "gtk_tree_path_up", "GtkTreePath*");
  return(C_TO_XEN_gboolean(gtk_tree_path_up(XEN_TO_C_GtkTreePath_(path))));
}
static XEN gxg_gtk_tree_path_down(XEN path)
{
  #define H_gtk_tree_path_down "void gtk_tree_path_down(GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 1, "gtk_tree_path_down", "GtkTreePath*");
  gtk_tree_path_down(XEN_TO_C_GtkTreePath_(path));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_path_is_ancestor(XEN path, XEN descendant)
{
  #define H_gtk_tree_path_is_ancestor "gboolean gtk_tree_path_is_ancestor(GtkTreePath* path, GtkTreePath* descendant)"
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 1, "gtk_tree_path_is_ancestor", "GtkTreePath*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(descendant), descendant, 2, "gtk_tree_path_is_ancestor", "GtkTreePath*");
  return(C_TO_XEN_gboolean(gtk_tree_path_is_ancestor(XEN_TO_C_GtkTreePath_(path), XEN_TO_C_GtkTreePath_(descendant))));
}
static XEN gxg_gtk_tree_path_is_descendant(XEN path, XEN ancestor)
{
  #define H_gtk_tree_path_is_descendant "gboolean gtk_tree_path_is_descendant(GtkTreePath* path, GtkTreePath* ancestor)"
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 1, "gtk_tree_path_is_descendant", "GtkTreePath*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(ancestor), ancestor, 2, "gtk_tree_path_is_descendant", "GtkTreePath*");
  return(C_TO_XEN_gboolean(gtk_tree_path_is_descendant(XEN_TO_C_GtkTreePath_(path), XEN_TO_C_GtkTreePath_(ancestor))));
}
static XEN gxg_gtk_tree_row_reference_new(XEN model, XEN path)
{
  #define H_gtk_tree_row_reference_new "GtkTreeRowReference* gtk_tree_row_reference_new(GtkTreeModel* model, \
GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(model), model, 1, "gtk_tree_row_reference_new", "GtkTreeModel*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 2, "gtk_tree_row_reference_new", "GtkTreePath*");
  return(C_TO_XEN_GtkTreeRowReference_(gtk_tree_row_reference_new(XEN_TO_C_GtkTreeModel_(model), XEN_TO_C_GtkTreePath_(path))));
}
static XEN gxg_gtk_tree_row_reference_new_proxy(XEN proxy, XEN model, XEN path)
{
  #define H_gtk_tree_row_reference_new_proxy "GtkTreeRowReference* gtk_tree_row_reference_new_proxy(GObject* proxy, \
GtkTreeModel* model, GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GObject__P(proxy), proxy, 1, "gtk_tree_row_reference_new_proxy", "GObject*");
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(model), model, 2, "gtk_tree_row_reference_new_proxy", "GtkTreeModel*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 3, "gtk_tree_row_reference_new_proxy", "GtkTreePath*");
  return(C_TO_XEN_GtkTreeRowReference_(gtk_tree_row_reference_new_proxy(XEN_TO_C_GObject_(proxy), XEN_TO_C_GtkTreeModel_(model), 
                                                                        XEN_TO_C_GtkTreePath_(path))));
}
static XEN gxg_gtk_tree_row_reference_get_path(XEN reference)
{
  #define H_gtk_tree_row_reference_get_path "GtkTreePath* gtk_tree_row_reference_get_path(GtkTreeRowReference* reference)"
  XEN_ASSERT_TYPE(XEN_GtkTreeRowReference__P(reference), reference, 1, "gtk_tree_row_reference_get_path", "GtkTreeRowReference*");
  return(C_TO_XEN_GtkTreePath_(gtk_tree_row_reference_get_path(XEN_TO_C_GtkTreeRowReference_(reference))));
}
static XEN gxg_gtk_tree_row_reference_valid(XEN reference)
{
  #define H_gtk_tree_row_reference_valid "gboolean gtk_tree_row_reference_valid(GtkTreeRowReference* reference)"
  XEN_ASSERT_TYPE(XEN_GtkTreeRowReference__P(reference), reference, 1, "gtk_tree_row_reference_valid", "GtkTreeRowReference*");
  return(C_TO_XEN_gboolean(gtk_tree_row_reference_valid(XEN_TO_C_GtkTreeRowReference_(reference))));
}
static XEN gxg_gtk_tree_row_reference_free(XEN reference)
{
  #define H_gtk_tree_row_reference_free "void gtk_tree_row_reference_free(GtkTreeRowReference* reference)"
  XEN_ASSERT_TYPE(XEN_GtkTreeRowReference__P(reference), reference, 1, "gtk_tree_row_reference_free", "GtkTreeRowReference*");
  gtk_tree_row_reference_free(XEN_TO_C_GtkTreeRowReference_(reference));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_row_reference_inserted(XEN proxy, XEN path)
{
  #define H_gtk_tree_row_reference_inserted "void gtk_tree_row_reference_inserted(GObject* proxy, GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GObject__P(proxy), proxy, 1, "gtk_tree_row_reference_inserted", "GObject*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 2, "gtk_tree_row_reference_inserted", "GtkTreePath*");
  gtk_tree_row_reference_inserted(XEN_TO_C_GObject_(proxy), XEN_TO_C_GtkTreePath_(path));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_row_reference_deleted(XEN proxy, XEN path)
{
  #define H_gtk_tree_row_reference_deleted "void gtk_tree_row_reference_deleted(GObject* proxy, GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GObject__P(proxy), proxy, 1, "gtk_tree_row_reference_deleted", "GObject*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 2, "gtk_tree_row_reference_deleted", "GtkTreePath*");
  gtk_tree_row_reference_deleted(XEN_TO_C_GObject_(proxy), XEN_TO_C_GtkTreePath_(path));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_row_reference_reordered(XEN proxy, XEN path, XEN iter, XEN new_order)
{
  #define H_gtk_tree_row_reference_reordered "void gtk_tree_row_reference_reordered(GObject* proxy, GtkTreePath* path, \
GtkTreeIter* iter, gint* new_order)"
  XEN_ASSERT_TYPE(XEN_GObject__P(proxy), proxy, 1, "gtk_tree_row_reference_reordered", "GObject*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 2, "gtk_tree_row_reference_reordered", "GtkTreePath*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 3, "gtk_tree_row_reference_reordered", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_gint__P(new_order), new_order, 4, "gtk_tree_row_reference_reordered", "gint*");
  gtk_tree_row_reference_reordered(XEN_TO_C_GObject_(proxy), XEN_TO_C_GtkTreePath_(path), XEN_TO_C_GtkTreeIter_(iter), XEN_TO_C_gint_(new_order));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_iter_copy(XEN iter)
{
  #define H_gtk_tree_iter_copy "GtkTreeIter* gtk_tree_iter_copy(GtkTreeIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 1, "gtk_tree_iter_copy", "GtkTreeIter*");
  return(C_TO_XEN_GtkTreeIter_(gtk_tree_iter_copy(XEN_TO_C_GtkTreeIter_(iter))));
}
static XEN gxg_gtk_tree_iter_free(XEN iter)
{
  #define H_gtk_tree_iter_free "void gtk_tree_iter_free(GtkTreeIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 1, "gtk_tree_iter_free", "GtkTreeIter*");
  gtk_tree_iter_free(XEN_TO_C_GtkTreeIter_(iter));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_model_get_type(void)
{
  #define H_gtk_tree_model_get_type "GtkType gtk_tree_model_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_tree_model_get_type()));
}
static XEN gxg_gtk_tree_model_get_flags(XEN tree_model)
{
  #define H_gtk_tree_model_get_flags "GtkTreeModelFlags gtk_tree_model_get_flags(GtkTreeModel* tree_model)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(tree_model), tree_model, 1, "gtk_tree_model_get_flags", "GtkTreeModel*");
  return(C_TO_XEN_GtkTreeModelFlags(gtk_tree_model_get_flags(XEN_TO_C_GtkTreeModel_(tree_model))));
}
static XEN gxg_gtk_tree_model_get_n_columns(XEN tree_model)
{
  #define H_gtk_tree_model_get_n_columns "gint gtk_tree_model_get_n_columns(GtkTreeModel* tree_model)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(tree_model), tree_model, 1, "gtk_tree_model_get_n_columns", "GtkTreeModel*");
  return(C_TO_XEN_gint(gtk_tree_model_get_n_columns(XEN_TO_C_GtkTreeModel_(tree_model))));
}
static XEN gxg_gtk_tree_model_get_column_type(XEN tree_model, XEN index)
{
  #define H_gtk_tree_model_get_column_type "GType gtk_tree_model_get_column_type(GtkTreeModel* tree_model, \
gint index)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(tree_model), tree_model, 1, "gtk_tree_model_get_column_type", "GtkTreeModel*");
  XEN_ASSERT_TYPE(XEN_gint_P(index), index, 2, "gtk_tree_model_get_column_type", "gint");
  return(C_TO_XEN_GType(gtk_tree_model_get_column_type(XEN_TO_C_GtkTreeModel_(tree_model), XEN_TO_C_gint(index))));
}
static XEN gxg_gtk_tree_model_get_iter(XEN tree_model, XEN iter, XEN path)
{
  #define H_gtk_tree_model_get_iter "gboolean gtk_tree_model_get_iter(GtkTreeModel* tree_model, GtkTreeIter* iter, \
GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(tree_model), tree_model, 1, "gtk_tree_model_get_iter", "GtkTreeModel*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_tree_model_get_iter", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 3, "gtk_tree_model_get_iter", "GtkTreePath*");
  return(C_TO_XEN_gboolean(gtk_tree_model_get_iter(XEN_TO_C_GtkTreeModel_(tree_model), XEN_TO_C_GtkTreeIter_(iter), XEN_TO_C_GtkTreePath_(path))));
}
static XEN gxg_gtk_tree_model_get_iter_from_string(XEN tree_model, XEN iter, XEN path_string)
{
  #define H_gtk_tree_model_get_iter_from_string "gboolean gtk_tree_model_get_iter_from_string(GtkTreeModel* tree_model, \
GtkTreeIter* iter, gchar* path_string)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(tree_model), tree_model, 1, "gtk_tree_model_get_iter_from_string", "GtkTreeModel*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_tree_model_get_iter_from_string", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_gchar__P(path_string), path_string, 3, "gtk_tree_model_get_iter_from_string", "gchar*");
  return(C_TO_XEN_gboolean(gtk_tree_model_get_iter_from_string(XEN_TO_C_GtkTreeModel_(tree_model), XEN_TO_C_GtkTreeIter_(iter), 
                                                               XEN_TO_C_gchar_(path_string))));
}
static XEN gxg_gtk_tree_model_get_iter_first(XEN tree_model, XEN iter)
{
  #define H_gtk_tree_model_get_iter_first "gboolean gtk_tree_model_get_iter_first(GtkTreeModel* tree_model, \
GtkTreeIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(tree_model), tree_model, 1, "gtk_tree_model_get_iter_first", "GtkTreeModel*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_tree_model_get_iter_first", "GtkTreeIter*");
  return(C_TO_XEN_gboolean(gtk_tree_model_get_iter_first(XEN_TO_C_GtkTreeModel_(tree_model), XEN_TO_C_GtkTreeIter_(iter))));
}
static XEN gxg_gtk_tree_model_get_path(XEN tree_model, XEN iter)
{
  #define H_gtk_tree_model_get_path "GtkTreePath* gtk_tree_model_get_path(GtkTreeModel* tree_model, GtkTreeIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(tree_model), tree_model, 1, "gtk_tree_model_get_path", "GtkTreeModel*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_tree_model_get_path", "GtkTreeIter*");
  return(C_TO_XEN_GtkTreePath_(gtk_tree_model_get_path(XEN_TO_C_GtkTreeModel_(tree_model), XEN_TO_C_GtkTreeIter_(iter))));
}
static XEN gxg_gtk_tree_model_iter_next(XEN tree_model, XEN iter)
{
  #define H_gtk_tree_model_iter_next "gboolean gtk_tree_model_iter_next(GtkTreeModel* tree_model, GtkTreeIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(tree_model), tree_model, 1, "gtk_tree_model_iter_next", "GtkTreeModel*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_tree_model_iter_next", "GtkTreeIter*");
  return(C_TO_XEN_gboolean(gtk_tree_model_iter_next(XEN_TO_C_GtkTreeModel_(tree_model), XEN_TO_C_GtkTreeIter_(iter))));
}
static XEN gxg_gtk_tree_model_iter_children(XEN tree_model, XEN iter, XEN parent)
{
  #define H_gtk_tree_model_iter_children "gboolean gtk_tree_model_iter_children(GtkTreeModel* tree_model, \
GtkTreeIter* iter, GtkTreeIter* parent)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(tree_model), tree_model, 1, "gtk_tree_model_iter_children", "GtkTreeModel*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_tree_model_iter_children", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(parent), parent, 3, "gtk_tree_model_iter_children", "GtkTreeIter*");
  return(C_TO_XEN_gboolean(gtk_tree_model_iter_children(XEN_TO_C_GtkTreeModel_(tree_model), XEN_TO_C_GtkTreeIter_(iter), 
                                                        XEN_TO_C_GtkTreeIter_(parent))));
}
static XEN gxg_gtk_tree_model_iter_has_child(XEN tree_model, XEN iter)
{
  #define H_gtk_tree_model_iter_has_child "gboolean gtk_tree_model_iter_has_child(GtkTreeModel* tree_model, \
GtkTreeIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(tree_model), tree_model, 1, "gtk_tree_model_iter_has_child", "GtkTreeModel*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_tree_model_iter_has_child", "GtkTreeIter*");
  return(C_TO_XEN_gboolean(gtk_tree_model_iter_has_child(XEN_TO_C_GtkTreeModel_(tree_model), XEN_TO_C_GtkTreeIter_(iter))));
}
static XEN gxg_gtk_tree_model_iter_n_children(XEN tree_model, XEN iter)
{
  #define H_gtk_tree_model_iter_n_children "gint gtk_tree_model_iter_n_children(GtkTreeModel* tree_model, \
GtkTreeIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(tree_model), tree_model, 1, "gtk_tree_model_iter_n_children", "GtkTreeModel*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter) || XEN_FALSE_P(iter), iter, 2, "gtk_tree_model_iter_n_children", "GtkTreeIter*");
  return(C_TO_XEN_gint(gtk_tree_model_iter_n_children(XEN_TO_C_GtkTreeModel_(tree_model), XEN_TO_C_GtkTreeIter_(iter))));
}
static XEN gxg_gtk_tree_model_iter_nth_child(XEN tree_model, XEN iter, XEN parent, XEN n)
{
  #define H_gtk_tree_model_iter_nth_child "gboolean gtk_tree_model_iter_nth_child(GtkTreeModel* tree_model, \
GtkTreeIter* iter, GtkTreeIter* parent, gint n)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(tree_model), tree_model, 1, "gtk_tree_model_iter_nth_child", "GtkTreeModel*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_tree_model_iter_nth_child", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(parent) || XEN_FALSE_P(parent), parent, 3, "gtk_tree_model_iter_nth_child", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_gint_P(n), n, 4, "gtk_tree_model_iter_nth_child", "gint");
  return(C_TO_XEN_gboolean(gtk_tree_model_iter_nth_child(XEN_TO_C_GtkTreeModel_(tree_model), XEN_TO_C_GtkTreeIter_(iter), 
                                                         XEN_TO_C_GtkTreeIter_(parent), XEN_TO_C_gint(n))));
}
static XEN gxg_gtk_tree_model_iter_parent(XEN tree_model, XEN iter, XEN child)
{
  #define H_gtk_tree_model_iter_parent "gboolean gtk_tree_model_iter_parent(GtkTreeModel* tree_model, \
GtkTreeIter* iter, GtkTreeIter* child)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(tree_model), tree_model, 1, "gtk_tree_model_iter_parent", "GtkTreeModel*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_tree_model_iter_parent", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(child), child, 3, "gtk_tree_model_iter_parent", "GtkTreeIter*");
  return(C_TO_XEN_gboolean(gtk_tree_model_iter_parent(XEN_TO_C_GtkTreeModel_(tree_model), XEN_TO_C_GtkTreeIter_(iter), XEN_TO_C_GtkTreeIter_(child))));
}
static XEN gxg_gtk_tree_model_ref_node(XEN tree_model, XEN iter)
{
  #define H_gtk_tree_model_ref_node "void gtk_tree_model_ref_node(GtkTreeModel* tree_model, GtkTreeIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(tree_model), tree_model, 1, "gtk_tree_model_ref_node", "GtkTreeModel*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_tree_model_ref_node", "GtkTreeIter*");
  gtk_tree_model_ref_node(XEN_TO_C_GtkTreeModel_(tree_model), XEN_TO_C_GtkTreeIter_(iter));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_model_unref_node(XEN tree_model, XEN iter)
{
  #define H_gtk_tree_model_unref_node "void gtk_tree_model_unref_node(GtkTreeModel* tree_model, GtkTreeIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(tree_model), tree_model, 1, "gtk_tree_model_unref_node", "GtkTreeModel*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_tree_model_unref_node", "GtkTreeIter*");
  gtk_tree_model_unref_node(XEN_TO_C_GtkTreeModel_(tree_model), XEN_TO_C_GtkTreeIter_(iter));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_model_foreach(XEN model, XEN func, XEN func_data)
{
  #define H_gtk_tree_model_foreach "void gtk_tree_model_foreach(GtkTreeModel* model, GtkTreeModelForeachFunc func, \
lambda_data func_data)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(model), model, 1, "gtk_tree_model_foreach", "GtkTreeModel*");
  XEN_ASSERT_TYPE(XEN_GtkTreeModelForeachFunc_P(func), func, 2, "gtk_tree_model_foreach", "GtkTreeModelForeachFunc");
  if (XEN_NOT_BOUND_P(func_data)) func_data = XEN_FALSE; 
  else XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 3, "gtk_tree_model_foreach", "lambda_data");
  {
    int loc;
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    loc = xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 2, C_TO_XEN_INT(loc));
    gtk_tree_model_foreach(XEN_TO_C_GtkTreeModel_(model), XEN_TO_C_GtkTreeModelForeachFunc(func), XEN_TO_C_lambda_data(func_data));
    xm_unprotect_at(loc);
    return(XEN_FALSE);
   }
}
static XEN gxg_gtk_tree_model_row_changed(XEN tree_model, XEN path, XEN iter)
{
  #define H_gtk_tree_model_row_changed "void gtk_tree_model_row_changed(GtkTreeModel* tree_model, GtkTreePath* path, \
GtkTreeIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(tree_model), tree_model, 1, "gtk_tree_model_row_changed", "GtkTreeModel*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 2, "gtk_tree_model_row_changed", "GtkTreePath*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 3, "gtk_tree_model_row_changed", "GtkTreeIter*");
  gtk_tree_model_row_changed(XEN_TO_C_GtkTreeModel_(tree_model), XEN_TO_C_GtkTreePath_(path), XEN_TO_C_GtkTreeIter_(iter));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_model_row_inserted(XEN tree_model, XEN path, XEN iter)
{
  #define H_gtk_tree_model_row_inserted "void gtk_tree_model_row_inserted(GtkTreeModel* tree_model, GtkTreePath* path, \
GtkTreeIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(tree_model), tree_model, 1, "gtk_tree_model_row_inserted", "GtkTreeModel*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 2, "gtk_tree_model_row_inserted", "GtkTreePath*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 3, "gtk_tree_model_row_inserted", "GtkTreeIter*");
  gtk_tree_model_row_inserted(XEN_TO_C_GtkTreeModel_(tree_model), XEN_TO_C_GtkTreePath_(path), XEN_TO_C_GtkTreeIter_(iter));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_model_row_has_child_toggled(XEN tree_model, XEN path, XEN iter)
{
  #define H_gtk_tree_model_row_has_child_toggled "void gtk_tree_model_row_has_child_toggled(GtkTreeModel* tree_model, \
GtkTreePath* path, GtkTreeIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(tree_model), tree_model, 1, "gtk_tree_model_row_has_child_toggled", "GtkTreeModel*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 2, "gtk_tree_model_row_has_child_toggled", "GtkTreePath*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 3, "gtk_tree_model_row_has_child_toggled", "GtkTreeIter*");
  gtk_tree_model_row_has_child_toggled(XEN_TO_C_GtkTreeModel_(tree_model), XEN_TO_C_GtkTreePath_(path), XEN_TO_C_GtkTreeIter_(iter));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_model_row_deleted(XEN tree_model, XEN path)
{
  #define H_gtk_tree_model_row_deleted "void gtk_tree_model_row_deleted(GtkTreeModel* tree_model, GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(tree_model), tree_model, 1, "gtk_tree_model_row_deleted", "GtkTreeModel*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 2, "gtk_tree_model_row_deleted", "GtkTreePath*");
  gtk_tree_model_row_deleted(XEN_TO_C_GtkTreeModel_(tree_model), XEN_TO_C_GtkTreePath_(path));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_model_rows_reordered(XEN tree_model, XEN path, XEN iter, XEN new_order)
{
  #define H_gtk_tree_model_rows_reordered "void gtk_tree_model_rows_reordered(GtkTreeModel* tree_model, \
GtkTreePath* path, GtkTreeIter* iter, gint* new_order)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(tree_model), tree_model, 1, "gtk_tree_model_rows_reordered", "GtkTreeModel*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 2, "gtk_tree_model_rows_reordered", "GtkTreePath*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 3, "gtk_tree_model_rows_reordered", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_gint__P(new_order), new_order, 4, "gtk_tree_model_rows_reordered", "gint*");
  gtk_tree_model_rows_reordered(XEN_TO_C_GtkTreeModel_(tree_model), XEN_TO_C_GtkTreePath_(path), XEN_TO_C_GtkTreeIter_(iter), 
                                XEN_TO_C_gint_(new_order));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_model_sort_get_type(void)
{
  #define H_gtk_tree_model_sort_get_type "GType gtk_tree_model_sort_get_type( void)"
  return(C_TO_XEN_GType(gtk_tree_model_sort_get_type()));
}
static XEN gxg_gtk_tree_model_sort_new_with_model(XEN child_model)
{
  #define H_gtk_tree_model_sort_new_with_model "GtkTreeModel* gtk_tree_model_sort_new_with_model(GtkTreeModel* child_model)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(child_model), child_model, 1, "gtk_tree_model_sort_new_with_model", "GtkTreeModel*");
  return(C_TO_XEN_GtkTreeModel_(gtk_tree_model_sort_new_with_model(XEN_TO_C_GtkTreeModel_(child_model))));
}
static XEN gxg_gtk_tree_model_sort_get_model(XEN tree_model)
{
  #define H_gtk_tree_model_sort_get_model "GtkTreeModel* gtk_tree_model_sort_get_model(GtkTreeModelSort* tree_model)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModelSort__P(tree_model), tree_model, 1, "gtk_tree_model_sort_get_model", "GtkTreeModelSort*");
  return(C_TO_XEN_GtkTreeModel_(gtk_tree_model_sort_get_model(XEN_TO_C_GtkTreeModelSort_(tree_model))));
}
static XEN gxg_gtk_tree_model_sort_convert_child_path_to_path(XEN tree_model_sort, XEN child_path)
{
  #define H_gtk_tree_model_sort_convert_child_path_to_path "GtkTreePath* gtk_tree_model_sort_convert_child_path_to_path(GtkTreeModelSort* tree_model_sort, \
GtkTreePath* child_path)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModelSort__P(tree_model_sort), tree_model_sort, 1, "gtk_tree_model_sort_convert_child_path_to_path", "GtkTreeModelSort*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(child_path), child_path, 2, "gtk_tree_model_sort_convert_child_path_to_path", "GtkTreePath*");
  return(C_TO_XEN_GtkTreePath_(gtk_tree_model_sort_convert_child_path_to_path(XEN_TO_C_GtkTreeModelSort_(tree_model_sort), 
                                                                              XEN_TO_C_GtkTreePath_(child_path))));
}
static XEN gxg_gtk_tree_model_sort_convert_child_iter_to_iter(XEN tree_model_sort, XEN sort_iter, XEN child_iter)
{
  #define H_gtk_tree_model_sort_convert_child_iter_to_iter "void gtk_tree_model_sort_convert_child_iter_to_iter(GtkTreeModelSort* tree_model_sort, \
GtkTreeIter* sort_iter, GtkTreeIter* child_iter)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModelSort__P(tree_model_sort), tree_model_sort, 1, "gtk_tree_model_sort_convert_child_iter_to_iter", "GtkTreeModelSort*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(sort_iter), sort_iter, 2, "gtk_tree_model_sort_convert_child_iter_to_iter", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(child_iter), child_iter, 3, "gtk_tree_model_sort_convert_child_iter_to_iter", "GtkTreeIter*");
  gtk_tree_model_sort_convert_child_iter_to_iter(XEN_TO_C_GtkTreeModelSort_(tree_model_sort), XEN_TO_C_GtkTreeIter_(sort_iter), 
                                                 XEN_TO_C_GtkTreeIter_(child_iter));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_model_sort_convert_path_to_child_path(XEN tree_model_sort, XEN sorted_path)
{
  #define H_gtk_tree_model_sort_convert_path_to_child_path "GtkTreePath* gtk_tree_model_sort_convert_path_to_child_path(GtkTreeModelSort* tree_model_sort, \
GtkTreePath* sorted_path)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModelSort__P(tree_model_sort), tree_model_sort, 1, "gtk_tree_model_sort_convert_path_to_child_path", "GtkTreeModelSort*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(sorted_path), sorted_path, 2, "gtk_tree_model_sort_convert_path_to_child_path", "GtkTreePath*");
  return(C_TO_XEN_GtkTreePath_(gtk_tree_model_sort_convert_path_to_child_path(XEN_TO_C_GtkTreeModelSort_(tree_model_sort), 
                                                                              XEN_TO_C_GtkTreePath_(sorted_path))));
}
static XEN gxg_gtk_tree_model_sort_convert_iter_to_child_iter(XEN tree_model_sort, XEN child_iter, XEN sorted_iter)
{
  #define H_gtk_tree_model_sort_convert_iter_to_child_iter "void gtk_tree_model_sort_convert_iter_to_child_iter(GtkTreeModelSort* tree_model_sort, \
GtkTreeIter* child_iter, GtkTreeIter* sorted_iter)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModelSort__P(tree_model_sort), tree_model_sort, 1, "gtk_tree_model_sort_convert_iter_to_child_iter", "GtkTreeModelSort*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(child_iter), child_iter, 2, "gtk_tree_model_sort_convert_iter_to_child_iter", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(sorted_iter), sorted_iter, 3, "gtk_tree_model_sort_convert_iter_to_child_iter", "GtkTreeIter*");
  gtk_tree_model_sort_convert_iter_to_child_iter(XEN_TO_C_GtkTreeModelSort_(tree_model_sort), XEN_TO_C_GtkTreeIter_(child_iter), 
                                                 XEN_TO_C_GtkTreeIter_(sorted_iter));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_model_sort_reset_default_sort_func(XEN tree_model_sort)
{
  #define H_gtk_tree_model_sort_reset_default_sort_func "void gtk_tree_model_sort_reset_default_sort_func(GtkTreeModelSort* tree_model_sort)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModelSort__P(tree_model_sort), tree_model_sort, 1, "gtk_tree_model_sort_reset_default_sort_func", "GtkTreeModelSort*");
  gtk_tree_model_sort_reset_default_sort_func(XEN_TO_C_GtkTreeModelSort_(tree_model_sort));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_model_sort_clear_cache(XEN tree_model_sort)
{
  #define H_gtk_tree_model_sort_clear_cache "void gtk_tree_model_sort_clear_cache(GtkTreeModelSort* tree_model_sort)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModelSort__P(tree_model_sort), tree_model_sort, 1, "gtk_tree_model_sort_clear_cache", "GtkTreeModelSort*");
  gtk_tree_model_sort_clear_cache(XEN_TO_C_GtkTreeModelSort_(tree_model_sort));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_selection_get_type(void)
{
  #define H_gtk_tree_selection_get_type "GtkType gtk_tree_selection_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_tree_selection_get_type()));
}
static XEN gxg_gtk_tree_selection_set_mode(XEN selection, XEN type)
{
  #define H_gtk_tree_selection_set_mode "void gtk_tree_selection_set_mode(GtkTreeSelection* selection, \
GtkSelectionMode type)"
  XEN_ASSERT_TYPE(XEN_GtkTreeSelection__P(selection), selection, 1, "gtk_tree_selection_set_mode", "GtkTreeSelection*");
  XEN_ASSERT_TYPE(XEN_GtkSelectionMode_P(type), type, 2, "gtk_tree_selection_set_mode", "GtkSelectionMode");
  gtk_tree_selection_set_mode(XEN_TO_C_GtkTreeSelection_(selection), XEN_TO_C_GtkSelectionMode(type));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_selection_get_mode(XEN selection)
{
  #define H_gtk_tree_selection_get_mode "GtkSelectionMode gtk_tree_selection_get_mode(GtkTreeSelection* selection)"
  XEN_ASSERT_TYPE(XEN_GtkTreeSelection__P(selection), selection, 1, "gtk_tree_selection_get_mode", "GtkTreeSelection*");
  return(C_TO_XEN_GtkSelectionMode(gtk_tree_selection_get_mode(XEN_TO_C_GtkTreeSelection_(selection))));
}
static XEN gxg_gtk_tree_selection_set_select_function(XEN selection, XEN func, XEN func_data, XEN destroy)
{
  #define H_gtk_tree_selection_set_select_function "void gtk_tree_selection_set_select_function(GtkTreeSelection* selection, \
GtkTreeSelectionFunc func, lambda_data func_data, GtkDestroyNotify destroy)"
  XEN_ASSERT_TYPE(XEN_GtkTreeSelection__P(selection), selection, 1, "gtk_tree_selection_set_select_function", "GtkTreeSelection*");
  XEN_ASSERT_TYPE(XEN_GtkTreeSelectionFunc_P(func), func, 2, "gtk_tree_selection_set_select_function", "GtkTreeSelectionFunc");
  XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 3, "gtk_tree_selection_set_select_function", "lambda_data");
  XEN_ASSERT_TYPE(XEN_GtkDestroyNotify_P(destroy), destroy, 4, "gtk_tree_selection_set_select_function", "GtkDestroyNotify");
  {
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 3, destroy);
    gtk_tree_selection_set_select_function(XEN_TO_C_GtkTreeSelection_(selection), XEN_TO_C_GtkTreeSelectionFunc(func), XEN_TO_C_lambda_data(func_data), 
                                       XEN_TO_C_GtkDestroyNotify(destroy));
    return(XEN_FALSE);
   }
}
static XEN gxg_gtk_tree_selection_get_user_data(XEN selection)
{
  #define H_gtk_tree_selection_get_user_data "gpointer gtk_tree_selection_get_user_data(GtkTreeSelection* selection)"
  XEN_ASSERT_TYPE(XEN_GtkTreeSelection__P(selection), selection, 1, "gtk_tree_selection_get_user_data", "GtkTreeSelection*");
  return(C_TO_XEN_gpointer(gtk_tree_selection_get_user_data(XEN_TO_C_GtkTreeSelection_(selection))));
}
static XEN gxg_gtk_tree_selection_get_tree_view(XEN selection)
{
  #define H_gtk_tree_selection_get_tree_view "GtkTreeView* gtk_tree_selection_get_tree_view(GtkTreeSelection* selection)"
  XEN_ASSERT_TYPE(XEN_GtkTreeSelection__P(selection), selection, 1, "gtk_tree_selection_get_tree_view", "GtkTreeSelection*");
  return(C_TO_XEN_GtkTreeView_(gtk_tree_selection_get_tree_view(XEN_TO_C_GtkTreeSelection_(selection))));
}
static XEN gxg_gtk_tree_selection_get_selected(XEN selection, XEN model, XEN iter)
{
  #define H_gtk_tree_selection_get_selected "gboolean gtk_tree_selection_get_selected(GtkTreeSelection* selection, \
GtkTreeModel** model, GtkTreeIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTreeSelection__P(selection), selection, 1, "gtk_tree_selection_get_selected", "GtkTreeSelection*");
  XEN_ASSERT_TYPE(XEN_GtkTreeModel___P(model), model, 2, "gtk_tree_selection_get_selected", "GtkTreeModel**");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 3, "gtk_tree_selection_get_selected", "GtkTreeIter*");
  return(C_TO_XEN_gboolean(gtk_tree_selection_get_selected(XEN_TO_C_GtkTreeSelection_(selection), XEN_TO_C_GtkTreeModel__(model), 
                                                           XEN_TO_C_GtkTreeIter_(iter))));
}
static XEN gxg_gtk_tree_selection_selected_foreach(XEN selection, XEN func, XEN func_data)
{
  #define H_gtk_tree_selection_selected_foreach "void gtk_tree_selection_selected_foreach(GtkTreeSelection* selection, \
GtkTreeSelectionForeachFunc func, lambda_data func_data)"
  XEN_ASSERT_TYPE(XEN_GtkTreeSelection__P(selection), selection, 1, "gtk_tree_selection_selected_foreach", "GtkTreeSelection*");
  XEN_ASSERT_TYPE(XEN_GtkTreeSelectionForeachFunc_P(func), func, 2, "gtk_tree_selection_selected_foreach", "GtkTreeSelectionForeachFunc");
  if (XEN_NOT_BOUND_P(func_data)) func_data = XEN_FALSE; 
  else XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 3, "gtk_tree_selection_selected_foreach", "lambda_data");
  {
    int loc;
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    loc = xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 2, C_TO_XEN_INT(loc));
    gtk_tree_selection_selected_foreach(XEN_TO_C_GtkTreeSelection_(selection), XEN_TO_C_GtkTreeSelectionForeachFunc(func), XEN_TO_C_lambda_data(func_data));
    xm_unprotect_at(loc);
    return(XEN_FALSE);
   }
}
static XEN gxg_gtk_tree_selection_select_path(XEN selection, XEN path)
{
  #define H_gtk_tree_selection_select_path "void gtk_tree_selection_select_path(GtkTreeSelection* selection, \
GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GtkTreeSelection__P(selection), selection, 1, "gtk_tree_selection_select_path", "GtkTreeSelection*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 2, "gtk_tree_selection_select_path", "GtkTreePath*");
  gtk_tree_selection_select_path(XEN_TO_C_GtkTreeSelection_(selection), XEN_TO_C_GtkTreePath_(path));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_selection_unselect_path(XEN selection, XEN path)
{
  #define H_gtk_tree_selection_unselect_path "void gtk_tree_selection_unselect_path(GtkTreeSelection* selection, \
GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GtkTreeSelection__P(selection), selection, 1, "gtk_tree_selection_unselect_path", "GtkTreeSelection*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 2, "gtk_tree_selection_unselect_path", "GtkTreePath*");
  gtk_tree_selection_unselect_path(XEN_TO_C_GtkTreeSelection_(selection), XEN_TO_C_GtkTreePath_(path));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_selection_select_iter(XEN selection, XEN iter)
{
  #define H_gtk_tree_selection_select_iter "void gtk_tree_selection_select_iter(GtkTreeSelection* selection, \
GtkTreeIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTreeSelection__P(selection), selection, 1, "gtk_tree_selection_select_iter", "GtkTreeSelection*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_tree_selection_select_iter", "GtkTreeIter*");
  gtk_tree_selection_select_iter(XEN_TO_C_GtkTreeSelection_(selection), XEN_TO_C_GtkTreeIter_(iter));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_selection_unselect_iter(XEN selection, XEN iter)
{
  #define H_gtk_tree_selection_unselect_iter "void gtk_tree_selection_unselect_iter(GtkTreeSelection* selection, \
GtkTreeIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTreeSelection__P(selection), selection, 1, "gtk_tree_selection_unselect_iter", "GtkTreeSelection*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_tree_selection_unselect_iter", "GtkTreeIter*");
  gtk_tree_selection_unselect_iter(XEN_TO_C_GtkTreeSelection_(selection), XEN_TO_C_GtkTreeIter_(iter));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_selection_path_is_selected(XEN selection, XEN path)
{
  #define H_gtk_tree_selection_path_is_selected "gboolean gtk_tree_selection_path_is_selected(GtkTreeSelection* selection, \
GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GtkTreeSelection__P(selection), selection, 1, "gtk_tree_selection_path_is_selected", "GtkTreeSelection*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 2, "gtk_tree_selection_path_is_selected", "GtkTreePath*");
  return(C_TO_XEN_gboolean(gtk_tree_selection_path_is_selected(XEN_TO_C_GtkTreeSelection_(selection), XEN_TO_C_GtkTreePath_(path))));
}
static XEN gxg_gtk_tree_selection_iter_is_selected(XEN selection, XEN iter)
{
  #define H_gtk_tree_selection_iter_is_selected "gboolean gtk_tree_selection_iter_is_selected(GtkTreeSelection* selection, \
GtkTreeIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTreeSelection__P(selection), selection, 1, "gtk_tree_selection_iter_is_selected", "GtkTreeSelection*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_tree_selection_iter_is_selected", "GtkTreeIter*");
  return(C_TO_XEN_gboolean(gtk_tree_selection_iter_is_selected(XEN_TO_C_GtkTreeSelection_(selection), XEN_TO_C_GtkTreeIter_(iter))));
}
static XEN gxg_gtk_tree_selection_select_all(XEN selection)
{
  #define H_gtk_tree_selection_select_all "void gtk_tree_selection_select_all(GtkTreeSelection* selection)"
  XEN_ASSERT_TYPE(XEN_GtkTreeSelection__P(selection), selection, 1, "gtk_tree_selection_select_all", "GtkTreeSelection*");
  gtk_tree_selection_select_all(XEN_TO_C_GtkTreeSelection_(selection));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_selection_unselect_all(XEN selection)
{
  #define H_gtk_tree_selection_unselect_all "void gtk_tree_selection_unselect_all(GtkTreeSelection* selection)"
  XEN_ASSERT_TYPE(XEN_GtkTreeSelection__P(selection), selection, 1, "gtk_tree_selection_unselect_all", "GtkTreeSelection*");
  gtk_tree_selection_unselect_all(XEN_TO_C_GtkTreeSelection_(selection));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_selection_select_range(XEN selection, XEN start_path, XEN end_path)
{
  #define H_gtk_tree_selection_select_range "void gtk_tree_selection_select_range(GtkTreeSelection* selection, \
GtkTreePath* start_path, GtkTreePath* end_path)"
  XEN_ASSERT_TYPE(XEN_GtkTreeSelection__P(selection), selection, 1, "gtk_tree_selection_select_range", "GtkTreeSelection*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(start_path), start_path, 2, "gtk_tree_selection_select_range", "GtkTreePath*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(end_path), end_path, 3, "gtk_tree_selection_select_range", "GtkTreePath*");
  gtk_tree_selection_select_range(XEN_TO_C_GtkTreeSelection_(selection), XEN_TO_C_GtkTreePath_(start_path), XEN_TO_C_GtkTreePath_(end_path));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_sortable_get_type(void)
{
  #define H_gtk_tree_sortable_get_type "GType gtk_tree_sortable_get_type( void)"
  return(C_TO_XEN_GType(gtk_tree_sortable_get_type()));
}
static XEN gxg_gtk_tree_sortable_sort_column_changed(XEN sortable)
{
  #define H_gtk_tree_sortable_sort_column_changed "void gtk_tree_sortable_sort_column_changed(GtkTreeSortable* sortable)"
  XEN_ASSERT_TYPE(XEN_GtkTreeSortable__P(sortable), sortable, 1, "gtk_tree_sortable_sort_column_changed", "GtkTreeSortable*");
  gtk_tree_sortable_sort_column_changed(XEN_TO_C_GtkTreeSortable_(sortable));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_sortable_get_sort_column_id(XEN sortable, XEN sort_column_id, XEN order)
{
  #define H_gtk_tree_sortable_get_sort_column_id "gboolean gtk_tree_sortable_get_sort_column_id(GtkTreeSortable* sortable, \
gint* [sort_column_id], GtkSortType* [order])"
  gint ref_sort_column_id;
  GtkSortType ref_order;
  XEN_ASSERT_TYPE(XEN_GtkTreeSortable__P(sortable), sortable, 1, "gtk_tree_sortable_get_sort_column_id", "GtkTreeSortable*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gtk_tree_sortable_get_sort_column_id(XEN_TO_C_GtkTreeSortable_(sortable), &ref_sort_column_id, 
                                                                    &ref_order));
    return(XEN_LIST_3(result, C_TO_XEN_gint(ref_sort_column_id), C_TO_XEN_GtkSortType(ref_order)));
   }
}
static XEN gxg_gtk_tree_sortable_set_sort_column_id(XEN sortable, XEN sort_column_id, XEN order)
{
  #define H_gtk_tree_sortable_set_sort_column_id "void gtk_tree_sortable_set_sort_column_id(GtkTreeSortable* sortable, \
gint sort_column_id, GtkSortType order)"
  XEN_ASSERT_TYPE(XEN_GtkTreeSortable__P(sortable), sortable, 1, "gtk_tree_sortable_set_sort_column_id", "GtkTreeSortable*");
  XEN_ASSERT_TYPE(XEN_gint_P(sort_column_id), sort_column_id, 2, "gtk_tree_sortable_set_sort_column_id", "gint");
  XEN_ASSERT_TYPE(XEN_GtkSortType_P(order), order, 3, "gtk_tree_sortable_set_sort_column_id", "GtkSortType");
  gtk_tree_sortable_set_sort_column_id(XEN_TO_C_GtkTreeSortable_(sortable), XEN_TO_C_gint(sort_column_id), XEN_TO_C_GtkSortType(order));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_sortable_set_sort_func(XEN sortable, XEN sort_column_id, XEN func, XEN func_data, XEN destroy)
{
  #define H_gtk_tree_sortable_set_sort_func "void gtk_tree_sortable_set_sort_func(GtkTreeSortable* sortable, \
gint sort_column_id, GtkTreeIterCompareFunc func, lambda_data func_data, GtkDestroyNotify destroy)"
  XEN_ASSERT_TYPE(XEN_GtkTreeSortable__P(sortable), sortable, 1, "gtk_tree_sortable_set_sort_func", "GtkTreeSortable*");
  XEN_ASSERT_TYPE(XEN_gint_P(sort_column_id), sort_column_id, 2, "gtk_tree_sortable_set_sort_func", "gint");
  XEN_ASSERT_TYPE(XEN_GtkTreeIterCompareFunc_P(func), func, 3, "gtk_tree_sortable_set_sort_func", "GtkTreeIterCompareFunc");
  XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 4, "gtk_tree_sortable_set_sort_func", "lambda_data");
  XEN_ASSERT_TYPE(XEN_GtkDestroyNotify_P(destroy), destroy, 5, "gtk_tree_sortable_set_sort_func", "GtkDestroyNotify");
  {
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 3, destroy);
    gtk_tree_sortable_set_sort_func(XEN_TO_C_GtkTreeSortable_(sortable), XEN_TO_C_gint(sort_column_id), XEN_TO_C_GtkTreeIterCompareFunc(func), 
                                XEN_TO_C_lambda_data(func_data), XEN_TO_C_GtkDestroyNotify(destroy));
    return(XEN_FALSE);
   }
}
static XEN gxg_gtk_tree_sortable_set_default_sort_func(XEN sortable, XEN func, XEN func_data, XEN destroy)
{
  #define H_gtk_tree_sortable_set_default_sort_func "void gtk_tree_sortable_set_default_sort_func(GtkTreeSortable* sortable, \
GtkTreeIterCompareFunc func, lambda_data func_data, GtkDestroyNotify destroy)"
  XEN_ASSERT_TYPE(XEN_GtkTreeSortable__P(sortable), sortable, 1, "gtk_tree_sortable_set_default_sort_func", "GtkTreeSortable*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIterCompareFunc_P(func), func, 2, "gtk_tree_sortable_set_default_sort_func", "GtkTreeIterCompareFunc");
  XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 3, "gtk_tree_sortable_set_default_sort_func", "lambda_data");
  XEN_ASSERT_TYPE(XEN_GtkDestroyNotify_P(destroy), destroy, 4, "gtk_tree_sortable_set_default_sort_func", "GtkDestroyNotify");
  {
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 3, destroy);
    gtk_tree_sortable_set_default_sort_func(XEN_TO_C_GtkTreeSortable_(sortable), XEN_TO_C_GtkTreeIterCompareFunc(func), XEN_TO_C_lambda_data(func_data), 
                                        XEN_TO_C_GtkDestroyNotify(destroy));
    return(XEN_FALSE);
   }
}
static XEN gxg_gtk_tree_sortable_has_default_sort_func(XEN sortable)
{
  #define H_gtk_tree_sortable_has_default_sort_func "gboolean gtk_tree_sortable_has_default_sort_func(GtkTreeSortable* sortable)"
  XEN_ASSERT_TYPE(XEN_GtkTreeSortable__P(sortable), sortable, 1, "gtk_tree_sortable_has_default_sort_func", "GtkTreeSortable*");
  return(C_TO_XEN_gboolean(gtk_tree_sortable_has_default_sort_func(XEN_TO_C_GtkTreeSortable_(sortable))));
}
static XEN gxg_gtk_tree_store_get_type(void)
{
  #define H_gtk_tree_store_get_type "GtkType gtk_tree_store_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_tree_store_get_type()));
}
static XEN gxg_gtk_tree_store_new(XEN n_columns, XEN types)
{
  #define H_gtk_tree_store_new "GtkTreeStore* gtk_tree_store_new(gint n_columns, etc types)"
  XEN_ASSERT_TYPE(XEN_gint_P(n_columns), n_columns, 1, "gtk_tree_store_new", "gint");
  XEN_ASSERT_TYPE(XEN_etc_P(types), types, 2, "gtk_tree_store_new", "etc");
  {
    int etc_len = 0;
    GtkTreeStore* result = NULL;
    gint p_arg0;
    if (XEN_LIST_P(types)) etc_len = XEN_LIST_LENGTH(types);
    if (etc_len < 1) XEN_OUT_OF_RANGE_ERROR("gtk_tree_store_new", 1, types, "... list must have at least 1 entry");
    if (etc_len > 6) XEN_OUT_OF_RANGE_ERROR("gtk_tree_store_new", 1, types, "... list too long (max len: 6)");
    p_arg0 = XEN_TO_C_gint(n_columns);
    switch (etc_len)
      {
        case 1: result = gtk_tree_store_new(p_arg0, XLG(types, 0)); break;
        case 2: result = gtk_tree_store_new(p_arg0, XLG(types, 0), XLG(types, 1)); break;
        case 3: result = gtk_tree_store_new(p_arg0, XLG(types, 0), XLG(types, 1), XLG(types, 2)); break;
        case 4: result = gtk_tree_store_new(p_arg0, XLG(types, 0), XLG(types, 1), XLG(types, 2), XLG(types, 3)); break;
        case 5: result = gtk_tree_store_new(p_arg0, XLG(types, 0), XLG(types, 1), XLG(types, 2), XLG(types, 3), XLG(types, 4)); break;
        case 6: result = gtk_tree_store_new(p_arg0, XLG(types, 0), XLG(types, 1), XLG(types, 2), XLG(types, 3), XLG(types, 4), XLG(types, 5)); break;
      }
    return(C_TO_XEN_GtkTreeStore_(result));
  }
}
static XEN gxg_gtk_tree_store_newv(XEN n_columns, XEN types)
{
  #define H_gtk_tree_store_newv "GtkTreeStore* gtk_tree_store_newv(gint n_columns, GType* types)"
  XEN_ASSERT_TYPE(XEN_gint_P(n_columns), n_columns, 1, "gtk_tree_store_newv", "gint");
  XEN_ASSERT_TYPE(XEN_GType__P(types), types, 2, "gtk_tree_store_newv", "GType*");
  return(C_TO_XEN_GtkTreeStore_(gtk_tree_store_newv(XEN_TO_C_gint(n_columns), XEN_TO_C_GType_(types))));
}
static XEN gxg_gtk_tree_store_set_column_types(XEN tree_store, XEN n_columns, XEN types)
{
  #define H_gtk_tree_store_set_column_types "void gtk_tree_store_set_column_types(GtkTreeStore* tree_store, \
gint n_columns, GType* types)"
  XEN_ASSERT_TYPE(XEN_GtkTreeStore__P(tree_store), tree_store, 1, "gtk_tree_store_set_column_types", "GtkTreeStore*");
  XEN_ASSERT_TYPE(XEN_gint_P(n_columns), n_columns, 2, "gtk_tree_store_set_column_types", "gint");
  XEN_ASSERT_TYPE(XEN_GType__P(types), types, 3, "gtk_tree_store_set_column_types", "GType*");
  gtk_tree_store_set_column_types(XEN_TO_C_GtkTreeStore_(tree_store), XEN_TO_C_gint(n_columns), XEN_TO_C_GType_(types));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_store_set(XEN tree_store, XEN iter, XEN values)
{
  #define H_gtk_tree_store_set "void gtk_tree_store_set(GtkTreeStore* tree_store, GtkTreeIter* iter, \
etc values)"
  XEN_ASSERT_TYPE(XEN_GtkTreeStore__P(tree_store), tree_store, 1, "gtk_tree_store_set", "GtkTreeStore*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_tree_store_set", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_etc_P(values), values, 3, "gtk_tree_store_set", "etc");
  {
    int etc_len = 0;
    GtkTreeStore* p_arg0;
    GtkTreeIter* p_arg1;
    if (XEN_LIST_P(values)) etc_len = XEN_LIST_LENGTH(values);
    if (etc_len < 2) XEN_OUT_OF_RANGE_ERROR("gtk_tree_store_set", 2, values, "... list must have at least 2 entries");
    if (etc_len > 10) XEN_OUT_OF_RANGE_ERROR("gtk_tree_store_set", 2, values, "... list too long (max len: 10)");
    if ((etc_len % 2) != 0) XEN_OUT_OF_RANGE_ERROR("gtk_tree_store_set", 2, values, "... list len must be multiple of 2");
    p_arg0 = XEN_TO_C_GtkTreeStore_(tree_store);
    p_arg1 = XEN_TO_C_GtkTreeIter_(iter);
    switch (etc_len)
      {
        case 2: gtk_tree_store_set(p_arg0, p_arg1, XLI(values, 0), XLS(values, 1), -1); break;
        case 4: gtk_tree_store_set(p_arg0, p_arg1, XLI(values, 0), XLS(values, 1), XLI(values, 2), XLS(values, 3), -1); break;
        case 6: gtk_tree_store_set(p_arg0, p_arg1, XLI(values, 0), XLS(values, 1), XLI(values, 2), XLS(values, 3), XLI(values, 4), XLS(values, 5), -1); break;
        case 8: gtk_tree_store_set(p_arg0, p_arg1, XLI(values, 0), XLS(values, 1), XLI(values, 2), XLS(values, 3), XLI(values, 4), XLS(values, 5), XLI(values, 6), XLS(values, 7), -1); break;
        case 10: gtk_tree_store_set(p_arg0, p_arg1, XLI(values, 0), XLS(values, 1), XLI(values, 2), XLS(values, 3), XLI(values, 4), XLS(values, 5), XLI(values, 6), XLS(values, 7), XLI(values, 8), XLS(values, 9), -1); break;
      }
    return(XEN_FALSE);
  }
}
static XEN gxg_gtk_tree_store_remove(XEN tree_store, XEN iter)
{
  #define H_gtk_tree_store_remove "void gtk_tree_store_remove(GtkTreeStore* tree_store, GtkTreeIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTreeStore__P(tree_store), tree_store, 1, "gtk_tree_store_remove", "GtkTreeStore*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_tree_store_remove", "GtkTreeIter*");
  gtk_tree_store_remove(XEN_TO_C_GtkTreeStore_(tree_store), XEN_TO_C_GtkTreeIter_(iter));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_store_insert(XEN tree_store, XEN iter, XEN parent, XEN position)
{
  #define H_gtk_tree_store_insert "void gtk_tree_store_insert(GtkTreeStore* tree_store, GtkTreeIter* iter, \
GtkTreeIter* parent, gint position)"
  XEN_ASSERT_TYPE(XEN_GtkTreeStore__P(tree_store), tree_store, 1, "gtk_tree_store_insert", "GtkTreeStore*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_tree_store_insert", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(parent) || XEN_FALSE_P(parent), parent, 3, "gtk_tree_store_insert", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_gint_P(position), position, 4, "gtk_tree_store_insert", "gint");
  gtk_tree_store_insert(XEN_TO_C_GtkTreeStore_(tree_store), XEN_TO_C_GtkTreeIter_(iter), XEN_TO_C_GtkTreeIter_(parent), XEN_TO_C_gint(position));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_store_insert_before(XEN tree_store, XEN iter, XEN parent, XEN sibling)
{
  #define H_gtk_tree_store_insert_before "void gtk_tree_store_insert_before(GtkTreeStore* tree_store, \
GtkTreeIter* iter, GtkTreeIter* parent, GtkTreeIter* sibling)"
  XEN_ASSERT_TYPE(XEN_GtkTreeStore__P(tree_store), tree_store, 1, "gtk_tree_store_insert_before", "GtkTreeStore*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_tree_store_insert_before", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(parent) || XEN_FALSE_P(parent), parent, 3, "gtk_tree_store_insert_before", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(sibling) || XEN_FALSE_P(sibling), sibling, 4, "gtk_tree_store_insert_before", "GtkTreeIter*");
  gtk_tree_store_insert_before(XEN_TO_C_GtkTreeStore_(tree_store), XEN_TO_C_GtkTreeIter_(iter), XEN_TO_C_GtkTreeIter_(parent), 
                               XEN_TO_C_GtkTreeIter_(sibling));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_store_insert_after(XEN tree_store, XEN iter, XEN parent, XEN sibling)
{
  #define H_gtk_tree_store_insert_after "void gtk_tree_store_insert_after(GtkTreeStore* tree_store, GtkTreeIter* iter, \
GtkTreeIter* parent, GtkTreeIter* sibling)"
  XEN_ASSERT_TYPE(XEN_GtkTreeStore__P(tree_store), tree_store, 1, "gtk_tree_store_insert_after", "GtkTreeStore*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_tree_store_insert_after", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(parent) || XEN_FALSE_P(parent), parent, 3, "gtk_tree_store_insert_after", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(sibling) || XEN_FALSE_P(sibling), sibling, 4, "gtk_tree_store_insert_after", "GtkTreeIter*");
  gtk_tree_store_insert_after(XEN_TO_C_GtkTreeStore_(tree_store), XEN_TO_C_GtkTreeIter_(iter), XEN_TO_C_GtkTreeIter_(parent), 
                              XEN_TO_C_GtkTreeIter_(sibling));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_store_prepend(XEN tree_store, XEN iter, XEN parent)
{
  #define H_gtk_tree_store_prepend "void gtk_tree_store_prepend(GtkTreeStore* tree_store, GtkTreeIter* iter, \
GtkTreeIter* parent)"
  XEN_ASSERT_TYPE(XEN_GtkTreeStore__P(tree_store), tree_store, 1, "gtk_tree_store_prepend", "GtkTreeStore*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_tree_store_prepend", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(parent) || XEN_FALSE_P(parent), parent, 3, "gtk_tree_store_prepend", "GtkTreeIter*");
  gtk_tree_store_prepend(XEN_TO_C_GtkTreeStore_(tree_store), XEN_TO_C_GtkTreeIter_(iter), XEN_TO_C_GtkTreeIter_(parent));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_store_append(XEN tree_store, XEN iter, XEN parent)
{
  #define H_gtk_tree_store_append "void gtk_tree_store_append(GtkTreeStore* tree_store, GtkTreeIter* iter, \
GtkTreeIter* parent)"
  XEN_ASSERT_TYPE(XEN_GtkTreeStore__P(tree_store), tree_store, 1, "gtk_tree_store_append", "GtkTreeStore*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_tree_store_append", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(parent) || XEN_FALSE_P(parent), parent, 3, "gtk_tree_store_append", "GtkTreeIter*");
  gtk_tree_store_append(XEN_TO_C_GtkTreeStore_(tree_store), XEN_TO_C_GtkTreeIter_(iter), XEN_TO_C_GtkTreeIter_(parent));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_store_is_ancestor(XEN tree_store, XEN iter, XEN descendant)
{
  #define H_gtk_tree_store_is_ancestor "gboolean gtk_tree_store_is_ancestor(GtkTreeStore* tree_store, \
GtkTreeIter* iter, GtkTreeIter* descendant)"
  XEN_ASSERT_TYPE(XEN_GtkTreeStore__P(tree_store), tree_store, 1, "gtk_tree_store_is_ancestor", "GtkTreeStore*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_tree_store_is_ancestor", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(descendant), descendant, 3, "gtk_tree_store_is_ancestor", "GtkTreeIter*");
  return(C_TO_XEN_gboolean(gtk_tree_store_is_ancestor(XEN_TO_C_GtkTreeStore_(tree_store), XEN_TO_C_GtkTreeIter_(iter), XEN_TO_C_GtkTreeIter_(descendant))));
}
static XEN gxg_gtk_tree_store_iter_depth(XEN tree_store, XEN iter)
{
  #define H_gtk_tree_store_iter_depth "gint gtk_tree_store_iter_depth(GtkTreeStore* tree_store, GtkTreeIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTreeStore__P(tree_store), tree_store, 1, "gtk_tree_store_iter_depth", "GtkTreeStore*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_tree_store_iter_depth", "GtkTreeIter*");
  return(C_TO_XEN_gint(gtk_tree_store_iter_depth(XEN_TO_C_GtkTreeStore_(tree_store), XEN_TO_C_GtkTreeIter_(iter))));
}
static XEN gxg_gtk_tree_store_clear(XEN tree_store)
{
  #define H_gtk_tree_store_clear "void gtk_tree_store_clear(GtkTreeStore* tree_store)"
  XEN_ASSERT_TYPE(XEN_GtkTreeStore__P(tree_store), tree_store, 1, "gtk_tree_store_clear", "GtkTreeStore*");
  gtk_tree_store_clear(XEN_TO_C_GtkTreeStore_(tree_store));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_column_get_type(void)
{
  #define H_gtk_tree_view_column_get_type "GtkType gtk_tree_view_column_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_tree_view_column_get_type()));
}
static XEN gxg_gtk_tree_view_column_new(void)
{
  #define H_gtk_tree_view_column_new "GtkTreeViewColumn* gtk_tree_view_column_new( void)"
  return(C_TO_XEN_GtkTreeViewColumn_(gtk_tree_view_column_new()));
}
static XEN gxg_gtk_tree_view_column_new_with_attributes(XEN title, XEN cell, XEN attributes)
{
  #define H_gtk_tree_view_column_new_with_attributes "GtkTreeViewColumn* gtk_tree_view_column_new_with_attributes(gchar* title, \
GtkCellRenderer* cell, etc attributes)"
  XEN_ASSERT_TYPE(XEN_gchar__P(title), title, 1, "gtk_tree_view_column_new_with_attributes", "gchar*");
  XEN_ASSERT_TYPE(XEN_GtkCellRenderer__P(cell), cell, 2, "gtk_tree_view_column_new_with_attributes", "GtkCellRenderer*");
  XEN_ASSERT_TYPE(XEN_etc_P(attributes), attributes, 3, "gtk_tree_view_column_new_with_attributes", "etc");
  {
    int etc_len = 0;
    GtkTreeViewColumn* result = NULL;
    gchar* p_arg0;
    GtkCellRenderer* p_arg1;
    if (XEN_LIST_P(attributes)) etc_len = XEN_LIST_LENGTH(attributes);
    if (etc_len < 2) XEN_OUT_OF_RANGE_ERROR("gtk_tree_view_column_new_with_attributes", 2, attributes, "... list must have at least 2 entries");
    if (etc_len > 10) XEN_OUT_OF_RANGE_ERROR("gtk_tree_view_column_new_with_attributes", 2, attributes, "... list too long (max len: 10)");
    if ((etc_len % 2) != 0) XEN_OUT_OF_RANGE_ERROR("gtk_tree_view_column_new_with_attributes", 2, attributes, "... list len must be multiple of 2");
    p_arg0 = XEN_TO_C_gchar_(title);
    p_arg1 = XEN_TO_C_GtkCellRenderer_(cell);
    switch (etc_len)
      {
        case 2: result = gtk_tree_view_column_new_with_attributes(p_arg0, p_arg1, XLS(attributes, 0), XLI(attributes, 1), NULL); break;
        case 4: result = gtk_tree_view_column_new_with_attributes(p_arg0, p_arg1, XLS(attributes, 0), XLI(attributes, 1), XLS(attributes, 2), XLI(attributes, 3), NULL); break;
        case 6: result = gtk_tree_view_column_new_with_attributes(p_arg0, p_arg1, XLS(attributes, 0), XLI(attributes, 1), XLS(attributes, 2), XLI(attributes, 3), XLS(attributes, 4), XLI(attributes, 5), NULL); break;
        case 8: result = gtk_tree_view_column_new_with_attributes(p_arg0, p_arg1, XLS(attributes, 0), XLI(attributes, 1), XLS(attributes, 2), XLI(attributes, 3), XLS(attributes, 4), XLI(attributes, 5), XLS(attributes, 6), XLI(attributes, 7), NULL); break;
        case 10: result = gtk_tree_view_column_new_with_attributes(p_arg0, p_arg1, XLS(attributes, 0), XLI(attributes, 1), XLS(attributes, 2), XLI(attributes, 3), XLS(attributes, 4), XLI(attributes, 5), XLS(attributes, 6), XLI(attributes, 7), XLS(attributes, 8), XLI(attributes, 9), NULL); break;
      }
    return(C_TO_XEN_GtkTreeViewColumn_(result));
  }
}
static XEN gxg_gtk_tree_view_column_pack_start(XEN tree_column, XEN cell, XEN expand)
{
  #define H_gtk_tree_view_column_pack_start "void gtk_tree_view_column_pack_start(GtkTreeViewColumn* tree_column, \
GtkCellRenderer* cell, gboolean expand)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_pack_start", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_GtkCellRenderer__P(cell), cell, 2, "gtk_tree_view_column_pack_start", "GtkCellRenderer*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(expand), expand, 3, "gtk_tree_view_column_pack_start", "gboolean");
  gtk_tree_view_column_pack_start(XEN_TO_C_GtkTreeViewColumn_(tree_column), XEN_TO_C_GtkCellRenderer_(cell), XEN_TO_C_gboolean(expand));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_column_pack_end(XEN tree_column, XEN cell, XEN expand)
{
  #define H_gtk_tree_view_column_pack_end "void gtk_tree_view_column_pack_end(GtkTreeViewColumn* tree_column, \
GtkCellRenderer* cell, gboolean expand)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_pack_end", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_GtkCellRenderer__P(cell), cell, 2, "gtk_tree_view_column_pack_end", "GtkCellRenderer*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(expand), expand, 3, "gtk_tree_view_column_pack_end", "gboolean");
  gtk_tree_view_column_pack_end(XEN_TO_C_GtkTreeViewColumn_(tree_column), XEN_TO_C_GtkCellRenderer_(cell), XEN_TO_C_gboolean(expand));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_column_clear(XEN tree_column)
{
  #define H_gtk_tree_view_column_clear "void gtk_tree_view_column_clear(GtkTreeViewColumn* tree_column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_clear", "GtkTreeViewColumn*");
  gtk_tree_view_column_clear(XEN_TO_C_GtkTreeViewColumn_(tree_column));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_column_get_cell_renderers(XEN tree_column)
{
  #define H_gtk_tree_view_column_get_cell_renderers "GList* gtk_tree_view_column_get_cell_renderers(GtkTreeViewColumn* tree_column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_get_cell_renderers", "GtkTreeViewColumn*");
  return(C_TO_XEN_GList_(gtk_tree_view_column_get_cell_renderers(XEN_TO_C_GtkTreeViewColumn_(tree_column))));
}
static XEN gxg_gtk_tree_view_column_add_attribute(XEN tree_column, XEN cell_renderer, XEN attribute, XEN column)
{
  #define H_gtk_tree_view_column_add_attribute "void gtk_tree_view_column_add_attribute(GtkTreeViewColumn* tree_column, \
GtkCellRenderer* cell_renderer, gchar* attribute, gint column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_add_attribute", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_GtkCellRenderer__P(cell_renderer), cell_renderer, 2, "gtk_tree_view_column_add_attribute", "GtkCellRenderer*");
  XEN_ASSERT_TYPE(XEN_gchar__P(attribute), attribute, 3, "gtk_tree_view_column_add_attribute", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(column), column, 4, "gtk_tree_view_column_add_attribute", "gint");
  gtk_tree_view_column_add_attribute(XEN_TO_C_GtkTreeViewColumn_(tree_column), XEN_TO_C_GtkCellRenderer_(cell_renderer), 
                                     XEN_TO_C_gchar_(attribute), XEN_TO_C_gint(column));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_column_set_attributes(XEN tree_column, XEN cell_renderer, XEN attributes)
{
  #define H_gtk_tree_view_column_set_attributes "void gtk_tree_view_column_set_attributes(GtkTreeViewColumn* tree_column, \
GtkCellRenderer* cell_renderer, etc attributes)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_set_attributes", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_GtkCellRenderer__P(cell_renderer), cell_renderer, 2, "gtk_tree_view_column_set_attributes", "GtkCellRenderer*");
  XEN_ASSERT_TYPE(XEN_etc_P(attributes), attributes, 3, "gtk_tree_view_column_set_attributes", "etc");
  {
    int etc_len = 0;
    GtkTreeViewColumn* p_arg0;
    GtkCellRenderer* p_arg1;
    if (XEN_LIST_P(attributes)) etc_len = XEN_LIST_LENGTH(attributes);
    if (etc_len < 2) XEN_OUT_OF_RANGE_ERROR("gtk_tree_view_column_set_attributes", 2, attributes, "... list must have at least 2 entries");
    if (etc_len > 10) XEN_OUT_OF_RANGE_ERROR("gtk_tree_view_column_set_attributes", 2, attributes, "... list too long (max len: 10)");
    if ((etc_len % 2) != 0) XEN_OUT_OF_RANGE_ERROR("gtk_tree_view_column_set_attributes", 2, attributes, "... list len must be multiple of 2");
    p_arg0 = XEN_TO_C_GtkTreeViewColumn_(tree_column);
    p_arg1 = XEN_TO_C_GtkCellRenderer_(cell_renderer);
    switch (etc_len)
      {
        case 2: gtk_tree_view_column_set_attributes(p_arg0, p_arg1, XLS(attributes, 0), XLI(attributes, 1), NULL); break;
        case 4: gtk_tree_view_column_set_attributes(p_arg0, p_arg1, XLS(attributes, 0), XLI(attributes, 1), XLS(attributes, 2), XLI(attributes, 3), NULL); break;
        case 6: gtk_tree_view_column_set_attributes(p_arg0, p_arg1, XLS(attributes, 0), XLI(attributes, 1), XLS(attributes, 2), XLI(attributes, 3), XLS(attributes, 4), XLI(attributes, 5), NULL); break;
        case 8: gtk_tree_view_column_set_attributes(p_arg0, p_arg1, XLS(attributes, 0), XLI(attributes, 1), XLS(attributes, 2), XLI(attributes, 3), XLS(attributes, 4), XLI(attributes, 5), XLS(attributes, 6), XLI(attributes, 7), NULL); break;
        case 10: gtk_tree_view_column_set_attributes(p_arg0, p_arg1, XLS(attributes, 0), XLI(attributes, 1), XLS(attributes, 2), XLI(attributes, 3), XLS(attributes, 4), XLI(attributes, 5), XLS(attributes, 6), XLI(attributes, 7), XLS(attributes, 8), XLI(attributes, 9), NULL); break;
      }
    return(XEN_FALSE);
  }
}
static XEN gxg_gtk_tree_view_column_set_cell_data_func(XEN tree_column, XEN cell_renderer, XEN func, XEN func_data, XEN destroy)
{
  #define H_gtk_tree_view_column_set_cell_data_func "void gtk_tree_view_column_set_cell_data_func(GtkTreeViewColumn* tree_column, \
GtkCellRenderer* cell_renderer, GtkTreeCellDataFunc func, lambda_data func_data, GtkDestroyNotify destroy)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_set_cell_data_func", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_GtkCellRenderer__P(cell_renderer), cell_renderer, 2, "gtk_tree_view_column_set_cell_data_func", "GtkCellRenderer*");
  XEN_ASSERT_TYPE(XEN_GtkTreeCellDataFunc_P(func), func, 3, "gtk_tree_view_column_set_cell_data_func", "GtkTreeCellDataFunc");
  XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 4, "gtk_tree_view_column_set_cell_data_func", "lambda_data");
  XEN_ASSERT_TYPE(XEN_GtkDestroyNotify_P(destroy), destroy, 5, "gtk_tree_view_column_set_cell_data_func", "GtkDestroyNotify");
  {
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 3, destroy);
    gtk_tree_view_column_set_cell_data_func(XEN_TO_C_GtkTreeViewColumn_(tree_column), XEN_TO_C_GtkCellRenderer_(cell_renderer), 
                                        XEN_TO_C_GtkTreeCellDataFunc(func), XEN_TO_C_lambda_data(func_data), XEN_TO_C_GtkDestroyNotify(destroy));
    return(XEN_FALSE);
   }
}
static XEN gxg_gtk_tree_view_column_clear_attributes(XEN tree_column, XEN cell_renderer)
{
  #define H_gtk_tree_view_column_clear_attributes "void gtk_tree_view_column_clear_attributes(GtkTreeViewColumn* tree_column, \
GtkCellRenderer* cell_renderer)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_clear_attributes", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_GtkCellRenderer__P(cell_renderer), cell_renderer, 2, "gtk_tree_view_column_clear_attributes", "GtkCellRenderer*");
  gtk_tree_view_column_clear_attributes(XEN_TO_C_GtkTreeViewColumn_(tree_column), XEN_TO_C_GtkCellRenderer_(cell_renderer));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_column_set_spacing(XEN tree_column, XEN spacing)
{
  #define H_gtk_tree_view_column_set_spacing "void gtk_tree_view_column_set_spacing(GtkTreeViewColumn* tree_column, \
gint spacing)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_set_spacing", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_gint_P(spacing), spacing, 2, "gtk_tree_view_column_set_spacing", "gint");
  gtk_tree_view_column_set_spacing(XEN_TO_C_GtkTreeViewColumn_(tree_column), XEN_TO_C_gint(spacing));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_column_get_spacing(XEN tree_column)
{
  #define H_gtk_tree_view_column_get_spacing "gint gtk_tree_view_column_get_spacing(GtkTreeViewColumn* tree_column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_get_spacing", "GtkTreeViewColumn*");
  return(C_TO_XEN_gint(gtk_tree_view_column_get_spacing(XEN_TO_C_GtkTreeViewColumn_(tree_column))));
}
static XEN gxg_gtk_tree_view_column_set_visible(XEN tree_column, XEN visible)
{
  #define H_gtk_tree_view_column_set_visible "void gtk_tree_view_column_set_visible(GtkTreeViewColumn* tree_column, \
gboolean visible)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_set_visible", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(visible), visible, 2, "gtk_tree_view_column_set_visible", "gboolean");
  gtk_tree_view_column_set_visible(XEN_TO_C_GtkTreeViewColumn_(tree_column), XEN_TO_C_gboolean(visible));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_column_get_visible(XEN tree_column)
{
  #define H_gtk_tree_view_column_get_visible "gboolean gtk_tree_view_column_get_visible(GtkTreeViewColumn* tree_column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_get_visible", "GtkTreeViewColumn*");
  return(C_TO_XEN_gboolean(gtk_tree_view_column_get_visible(XEN_TO_C_GtkTreeViewColumn_(tree_column))));
}
static XEN gxg_gtk_tree_view_column_set_resizable(XEN tree_column, XEN resizable)
{
  #define H_gtk_tree_view_column_set_resizable "void gtk_tree_view_column_set_resizable(GtkTreeViewColumn* tree_column, \
gboolean resizable)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_set_resizable", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(resizable), resizable, 2, "gtk_tree_view_column_set_resizable", "gboolean");
  gtk_tree_view_column_set_resizable(XEN_TO_C_GtkTreeViewColumn_(tree_column), XEN_TO_C_gboolean(resizable));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_column_get_resizable(XEN tree_column)
{
  #define H_gtk_tree_view_column_get_resizable "gboolean gtk_tree_view_column_get_resizable(GtkTreeViewColumn* tree_column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_get_resizable", "GtkTreeViewColumn*");
  return(C_TO_XEN_gboolean(gtk_tree_view_column_get_resizable(XEN_TO_C_GtkTreeViewColumn_(tree_column))));
}
static XEN gxg_gtk_tree_view_column_set_sizing(XEN tree_column, XEN type)
{
  #define H_gtk_tree_view_column_set_sizing "void gtk_tree_view_column_set_sizing(GtkTreeViewColumn* tree_column, \
GtkTreeViewColumnSizing type)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_set_sizing", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumnSizing_P(type), type, 2, "gtk_tree_view_column_set_sizing", "GtkTreeViewColumnSizing");
  gtk_tree_view_column_set_sizing(XEN_TO_C_GtkTreeViewColumn_(tree_column), XEN_TO_C_GtkTreeViewColumnSizing(type));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_column_get_sizing(XEN tree_column)
{
  #define H_gtk_tree_view_column_get_sizing "GtkTreeViewColumnSizing gtk_tree_view_column_get_sizing(GtkTreeViewColumn* tree_column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_get_sizing", "GtkTreeViewColumn*");
  return(C_TO_XEN_GtkTreeViewColumnSizing(gtk_tree_view_column_get_sizing(XEN_TO_C_GtkTreeViewColumn_(tree_column))));
}
static XEN gxg_gtk_tree_view_column_get_width(XEN tree_column)
{
  #define H_gtk_tree_view_column_get_width "gint gtk_tree_view_column_get_width(GtkTreeViewColumn* tree_column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_get_width", "GtkTreeViewColumn*");
  return(C_TO_XEN_gint(gtk_tree_view_column_get_width(XEN_TO_C_GtkTreeViewColumn_(tree_column))));
}
static XEN gxg_gtk_tree_view_column_get_fixed_width(XEN tree_column)
{
  #define H_gtk_tree_view_column_get_fixed_width "gint gtk_tree_view_column_get_fixed_width(GtkTreeViewColumn* tree_column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_get_fixed_width", "GtkTreeViewColumn*");
  return(C_TO_XEN_gint(gtk_tree_view_column_get_fixed_width(XEN_TO_C_GtkTreeViewColumn_(tree_column))));
}
static XEN gxg_gtk_tree_view_column_set_fixed_width(XEN tree_column, XEN fixed_width)
{
  #define H_gtk_tree_view_column_set_fixed_width "void gtk_tree_view_column_set_fixed_width(GtkTreeViewColumn* tree_column, \
gint fixed_width)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_set_fixed_width", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_gint_P(fixed_width), fixed_width, 2, "gtk_tree_view_column_set_fixed_width", "gint");
  gtk_tree_view_column_set_fixed_width(XEN_TO_C_GtkTreeViewColumn_(tree_column), XEN_TO_C_gint(fixed_width));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_column_set_min_width(XEN tree_column, XEN min_width)
{
  #define H_gtk_tree_view_column_set_min_width "void gtk_tree_view_column_set_min_width(GtkTreeViewColumn* tree_column, \
gint min_width)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_set_min_width", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_gint_P(min_width), min_width, 2, "gtk_tree_view_column_set_min_width", "gint");
  gtk_tree_view_column_set_min_width(XEN_TO_C_GtkTreeViewColumn_(tree_column), XEN_TO_C_gint(min_width));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_column_get_min_width(XEN tree_column)
{
  #define H_gtk_tree_view_column_get_min_width "gint gtk_tree_view_column_get_min_width(GtkTreeViewColumn* tree_column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_get_min_width", "GtkTreeViewColumn*");
  return(C_TO_XEN_gint(gtk_tree_view_column_get_min_width(XEN_TO_C_GtkTreeViewColumn_(tree_column))));
}
static XEN gxg_gtk_tree_view_column_set_max_width(XEN tree_column, XEN max_width)
{
  #define H_gtk_tree_view_column_set_max_width "void gtk_tree_view_column_set_max_width(GtkTreeViewColumn* tree_column, \
gint max_width)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_set_max_width", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_gint_P(max_width), max_width, 2, "gtk_tree_view_column_set_max_width", "gint");
  gtk_tree_view_column_set_max_width(XEN_TO_C_GtkTreeViewColumn_(tree_column), XEN_TO_C_gint(max_width));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_column_get_max_width(XEN tree_column)
{
  #define H_gtk_tree_view_column_get_max_width "gint gtk_tree_view_column_get_max_width(GtkTreeViewColumn* tree_column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_get_max_width", "GtkTreeViewColumn*");
  return(C_TO_XEN_gint(gtk_tree_view_column_get_max_width(XEN_TO_C_GtkTreeViewColumn_(tree_column))));
}
static XEN gxg_gtk_tree_view_column_clicked(XEN tree_column)
{
  #define H_gtk_tree_view_column_clicked "void gtk_tree_view_column_clicked(GtkTreeViewColumn* tree_column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_clicked", "GtkTreeViewColumn*");
  gtk_tree_view_column_clicked(XEN_TO_C_GtkTreeViewColumn_(tree_column));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_column_set_title(XEN tree_column, XEN title)
{
  #define H_gtk_tree_view_column_set_title "void gtk_tree_view_column_set_title(GtkTreeViewColumn* tree_column, \
gchar* title)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_set_title", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_gchar__P(title), title, 2, "gtk_tree_view_column_set_title", "gchar*");
  gtk_tree_view_column_set_title(XEN_TO_C_GtkTreeViewColumn_(tree_column), XEN_TO_C_gchar_(title));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_column_get_title(XEN tree_column)
{
  #define H_gtk_tree_view_column_get_title "gchar* gtk_tree_view_column_get_title(GtkTreeViewColumn* tree_column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_get_title", "GtkTreeViewColumn*");
  return(C_TO_XEN_gchar_(gtk_tree_view_column_get_title(XEN_TO_C_GtkTreeViewColumn_(tree_column))));
}
static XEN gxg_gtk_tree_view_column_set_clickable(XEN tree_column, XEN clickable)
{
  #define H_gtk_tree_view_column_set_clickable "void gtk_tree_view_column_set_clickable(GtkTreeViewColumn* tree_column, \
gboolean clickable)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_set_clickable", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(clickable), clickable, 2, "gtk_tree_view_column_set_clickable", "gboolean");
  gtk_tree_view_column_set_clickable(XEN_TO_C_GtkTreeViewColumn_(tree_column), XEN_TO_C_gboolean(clickable));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_column_get_clickable(XEN tree_column)
{
  #define H_gtk_tree_view_column_get_clickable "gboolean gtk_tree_view_column_get_clickable(GtkTreeViewColumn* tree_column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_get_clickable", "GtkTreeViewColumn*");
  return(C_TO_XEN_gboolean(gtk_tree_view_column_get_clickable(XEN_TO_C_GtkTreeViewColumn_(tree_column))));
}
static XEN gxg_gtk_tree_view_column_set_widget(XEN tree_column, XEN widget)
{
  #define H_gtk_tree_view_column_set_widget "void gtk_tree_view_column_set_widget(GtkTreeViewColumn* tree_column, \
GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_set_widget", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget) || XEN_FALSE_P(widget), widget, 2, "gtk_tree_view_column_set_widget", "GtkWidget*");
  gtk_tree_view_column_set_widget(XEN_TO_C_GtkTreeViewColumn_(tree_column), XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_column_get_widget(XEN tree_column)
{
  #define H_gtk_tree_view_column_get_widget "GtkWidget* gtk_tree_view_column_get_widget(GtkTreeViewColumn* tree_column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_get_widget", "GtkTreeViewColumn*");
  return(C_TO_XEN_GtkWidget_(gtk_tree_view_column_get_widget(XEN_TO_C_GtkTreeViewColumn_(tree_column))));
}
static XEN gxg_gtk_tree_view_column_set_alignment(XEN tree_column, XEN xalign)
{
  #define H_gtk_tree_view_column_set_alignment "void gtk_tree_view_column_set_alignment(GtkTreeViewColumn* tree_column, \
gfloat xalign)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_set_alignment", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_gfloat_P(xalign), xalign, 2, "gtk_tree_view_column_set_alignment", "gfloat");
  gtk_tree_view_column_set_alignment(XEN_TO_C_GtkTreeViewColumn_(tree_column), XEN_TO_C_gfloat(xalign));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_column_get_alignment(XEN tree_column)
{
  #define H_gtk_tree_view_column_get_alignment "gfloat gtk_tree_view_column_get_alignment(GtkTreeViewColumn* tree_column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_get_alignment", "GtkTreeViewColumn*");
  return(C_TO_XEN_gfloat(gtk_tree_view_column_get_alignment(XEN_TO_C_GtkTreeViewColumn_(tree_column))));
}
static XEN gxg_gtk_tree_view_column_set_reorderable(XEN tree_column, XEN reorderable)
{
  #define H_gtk_tree_view_column_set_reorderable "void gtk_tree_view_column_set_reorderable(GtkTreeViewColumn* tree_column, \
gboolean reorderable)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_set_reorderable", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(reorderable), reorderable, 2, "gtk_tree_view_column_set_reorderable", "gboolean");
  gtk_tree_view_column_set_reorderable(XEN_TO_C_GtkTreeViewColumn_(tree_column), XEN_TO_C_gboolean(reorderable));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_column_get_reorderable(XEN tree_column)
{
  #define H_gtk_tree_view_column_get_reorderable "gboolean gtk_tree_view_column_get_reorderable(GtkTreeViewColumn* tree_column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_get_reorderable", "GtkTreeViewColumn*");
  return(C_TO_XEN_gboolean(gtk_tree_view_column_get_reorderable(XEN_TO_C_GtkTreeViewColumn_(tree_column))));
}
static XEN gxg_gtk_tree_view_column_set_sort_column_id(XEN tree_column, XEN sort_column_id)
{
  #define H_gtk_tree_view_column_set_sort_column_id "void gtk_tree_view_column_set_sort_column_id(GtkTreeViewColumn* tree_column, \
gint sort_column_id)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_set_sort_column_id", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_gint_P(sort_column_id), sort_column_id, 2, "gtk_tree_view_column_set_sort_column_id", "gint");
  gtk_tree_view_column_set_sort_column_id(XEN_TO_C_GtkTreeViewColumn_(tree_column), XEN_TO_C_gint(sort_column_id));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_column_get_sort_column_id(XEN tree_column)
{
  #define H_gtk_tree_view_column_get_sort_column_id "gint gtk_tree_view_column_get_sort_column_id(GtkTreeViewColumn* tree_column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_get_sort_column_id", "GtkTreeViewColumn*");
  return(C_TO_XEN_gint(gtk_tree_view_column_get_sort_column_id(XEN_TO_C_GtkTreeViewColumn_(tree_column))));
}
static XEN gxg_gtk_tree_view_column_set_sort_indicator(XEN tree_column, XEN setting)
{
  #define H_gtk_tree_view_column_set_sort_indicator "void gtk_tree_view_column_set_sort_indicator(GtkTreeViewColumn* tree_column, \
gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_set_sort_indicator", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gtk_tree_view_column_set_sort_indicator", "gboolean");
  gtk_tree_view_column_set_sort_indicator(XEN_TO_C_GtkTreeViewColumn_(tree_column), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_column_get_sort_indicator(XEN tree_column)
{
  #define H_gtk_tree_view_column_get_sort_indicator "gboolean gtk_tree_view_column_get_sort_indicator(GtkTreeViewColumn* tree_column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_get_sort_indicator", "GtkTreeViewColumn*");
  return(C_TO_XEN_gboolean(gtk_tree_view_column_get_sort_indicator(XEN_TO_C_GtkTreeViewColumn_(tree_column))));
}
static XEN gxg_gtk_tree_view_column_set_sort_order(XEN tree_column, XEN order)
{
  #define H_gtk_tree_view_column_set_sort_order "void gtk_tree_view_column_set_sort_order(GtkTreeViewColumn* tree_column, \
GtkSortType order)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_set_sort_order", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_GtkSortType_P(order), order, 2, "gtk_tree_view_column_set_sort_order", "GtkSortType");
  gtk_tree_view_column_set_sort_order(XEN_TO_C_GtkTreeViewColumn_(tree_column), XEN_TO_C_GtkSortType(order));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_column_get_sort_order(XEN tree_column)
{
  #define H_gtk_tree_view_column_get_sort_order "GtkSortType gtk_tree_view_column_get_sort_order(GtkTreeViewColumn* tree_column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_get_sort_order", "GtkTreeViewColumn*");
  return(C_TO_XEN_GtkSortType(gtk_tree_view_column_get_sort_order(XEN_TO_C_GtkTreeViewColumn_(tree_column))));
}
static XEN gxg_gtk_tree_view_column_cell_set_cell_data(XEN tree_column, XEN tree_model, XEN iter, XEN is_expander, XEN is_expanded)
{
  #define H_gtk_tree_view_column_cell_set_cell_data "void gtk_tree_view_column_cell_set_cell_data(GtkTreeViewColumn* tree_column, \
GtkTreeModel* tree_model, GtkTreeIter* iter, gboolean is_expander, gboolean is_expanded)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_cell_set_cell_data", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(tree_model), tree_model, 2, "gtk_tree_view_column_cell_set_cell_data", "GtkTreeModel*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 3, "gtk_tree_view_column_cell_set_cell_data", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(is_expander), is_expander, 4, "gtk_tree_view_column_cell_set_cell_data", "gboolean");
  XEN_ASSERT_TYPE(XEN_gboolean_P(is_expanded), is_expanded, 5, "gtk_tree_view_column_cell_set_cell_data", "gboolean");
  gtk_tree_view_column_cell_set_cell_data(XEN_TO_C_GtkTreeViewColumn_(tree_column), XEN_TO_C_GtkTreeModel_(tree_model), XEN_TO_C_GtkTreeIter_(iter), 
                                          XEN_TO_C_gboolean(is_expander), XEN_TO_C_gboolean(is_expanded));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_column_cell_get_size(XEN tree_column, XEN cell_area, XEN x_offset, XEN y_offset, XEN width, XEN height)
{
  #define H_gtk_tree_view_column_cell_get_size "void gtk_tree_view_column_cell_get_size(GtkTreeViewColumn* tree_column, \
GdkRectangle* cell_area, gint* [x_offset], gint* [y_offset], gint* [width], gint* [height])"
  gint ref_x_offset;
  gint ref_y_offset;
  gint ref_width;
  gint ref_height;
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_cell_get_size", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(cell_area), cell_area, 2, "gtk_tree_view_column_cell_get_size", "GdkRectangle*");
  gtk_tree_view_column_cell_get_size(XEN_TO_C_GtkTreeViewColumn_(tree_column), XEN_TO_C_GdkRectangle_(cell_area), &ref_x_offset, 
                                     &ref_y_offset, &ref_width, &ref_height);
  return(XEN_LIST_4(C_TO_XEN_gint(ref_x_offset), C_TO_XEN_gint(ref_y_offset), C_TO_XEN_gint(ref_width), C_TO_XEN_gint(ref_height)));
}
static XEN gxg_gtk_tree_view_column_cell_is_visible(XEN tree_column)
{
  #define H_gtk_tree_view_column_cell_is_visible "gboolean gtk_tree_view_column_cell_is_visible(GtkTreeViewColumn* tree_column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_cell_is_visible", "GtkTreeViewColumn*");
  return(C_TO_XEN_gboolean(gtk_tree_view_column_cell_is_visible(XEN_TO_C_GtkTreeViewColumn_(tree_column))));
}
static XEN gxg_gtk_tree_view_get_type(void)
{
  #define H_gtk_tree_view_get_type "GtkType gtk_tree_view_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_tree_view_get_type()));
}
static XEN gxg_gtk_tree_view_new(void)
{
  #define H_gtk_tree_view_new "GtkWidget* gtk_tree_view_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_tree_view_new()));
}
static XEN gxg_gtk_tree_view_new_with_model(XEN model)
{
  #define H_gtk_tree_view_new_with_model "GtkWidget* gtk_tree_view_new_with_model(GtkTreeModel* model)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(model), model, 1, "gtk_tree_view_new_with_model", "GtkTreeModel*");
  return(C_TO_XEN_GtkWidget_(gtk_tree_view_new_with_model(XEN_TO_C_GtkTreeModel_(model))));
}
static XEN gxg_gtk_tree_view_get_model(XEN tree_view)
{
  #define H_gtk_tree_view_get_model "GtkTreeModel* gtk_tree_view_get_model(GtkTreeView* tree_view)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_get_model", "GtkTreeView*");
  return(C_TO_XEN_GtkTreeModel_(gtk_tree_view_get_model(XEN_TO_C_GtkTreeView_(tree_view))));
}
static XEN gxg_gtk_tree_view_set_model(XEN tree_view, XEN model)
{
  #define H_gtk_tree_view_set_model "void gtk_tree_view_set_model(GtkTreeView* tree_view, GtkTreeModel* model)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_set_model", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(model) || XEN_FALSE_P(model), model, 2, "gtk_tree_view_set_model", "GtkTreeModel*");
  gtk_tree_view_set_model(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_GtkTreeModel_(model));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_get_selection(XEN tree_view)
{
  #define H_gtk_tree_view_get_selection "GtkTreeSelection* gtk_tree_view_get_selection(GtkTreeView* tree_view)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_get_selection", "GtkTreeView*");
  return(C_TO_XEN_GtkTreeSelection_(gtk_tree_view_get_selection(XEN_TO_C_GtkTreeView_(tree_view))));
}
static XEN gxg_gtk_tree_view_get_hadjustment(XEN tree_view)
{
  #define H_gtk_tree_view_get_hadjustment "GtkAdjustment* gtk_tree_view_get_hadjustment(GtkTreeView* tree_view)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_get_hadjustment", "GtkTreeView*");
  return(C_TO_XEN_GtkAdjustment_(gtk_tree_view_get_hadjustment(XEN_TO_C_GtkTreeView_(tree_view))));
}
static XEN gxg_gtk_tree_view_set_hadjustment(XEN tree_view, XEN adjustment)
{
  #define H_gtk_tree_view_set_hadjustment "void gtk_tree_view_set_hadjustment(GtkTreeView* tree_view, \
GtkAdjustment* adjustment)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_set_hadjustment", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(adjustment) || XEN_FALSE_P(adjustment), adjustment, 2, "gtk_tree_view_set_hadjustment", "GtkAdjustment*");
  gtk_tree_view_set_hadjustment(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_GtkAdjustment_(adjustment));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_get_vadjustment(XEN tree_view)
{
  #define H_gtk_tree_view_get_vadjustment "GtkAdjustment* gtk_tree_view_get_vadjustment(GtkTreeView* tree_view)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_get_vadjustment", "GtkTreeView*");
  return(C_TO_XEN_GtkAdjustment_(gtk_tree_view_get_vadjustment(XEN_TO_C_GtkTreeView_(tree_view))));
}
static XEN gxg_gtk_tree_view_set_vadjustment(XEN tree_view, XEN adjustment)
{
  #define H_gtk_tree_view_set_vadjustment "void gtk_tree_view_set_vadjustment(GtkTreeView* tree_view, \
GtkAdjustment* adjustment)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_set_vadjustment", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(adjustment) || XEN_FALSE_P(adjustment), adjustment, 2, "gtk_tree_view_set_vadjustment", "GtkAdjustment*");
  gtk_tree_view_set_vadjustment(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_GtkAdjustment_(adjustment));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_get_headers_visible(XEN tree_view)
{
  #define H_gtk_tree_view_get_headers_visible "gboolean gtk_tree_view_get_headers_visible(GtkTreeView* tree_view)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_get_headers_visible", "GtkTreeView*");
  return(C_TO_XEN_gboolean(gtk_tree_view_get_headers_visible(XEN_TO_C_GtkTreeView_(tree_view))));
}
static XEN gxg_gtk_tree_view_set_headers_visible(XEN tree_view, XEN headers_visible)
{
  #define H_gtk_tree_view_set_headers_visible "void gtk_tree_view_set_headers_visible(GtkTreeView* tree_view, \
gboolean headers_visible)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_set_headers_visible", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(headers_visible), headers_visible, 2, "gtk_tree_view_set_headers_visible", "gboolean");
  gtk_tree_view_set_headers_visible(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_gboolean(headers_visible));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_columns_autosize(XEN tree_view)
{
  #define H_gtk_tree_view_columns_autosize "void gtk_tree_view_columns_autosize(GtkTreeView* tree_view)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_columns_autosize", "GtkTreeView*");
  gtk_tree_view_columns_autosize(XEN_TO_C_GtkTreeView_(tree_view));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_set_headers_clickable(XEN tree_view, XEN setting)
{
  #define H_gtk_tree_view_set_headers_clickable "void gtk_tree_view_set_headers_clickable(GtkTreeView* tree_view, \
gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_set_headers_clickable", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gtk_tree_view_set_headers_clickable", "gboolean");
  gtk_tree_view_set_headers_clickable(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_set_rules_hint(XEN tree_view, XEN setting)
{
  #define H_gtk_tree_view_set_rules_hint "void gtk_tree_view_set_rules_hint(GtkTreeView* tree_view, gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_set_rules_hint", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gtk_tree_view_set_rules_hint", "gboolean");
  gtk_tree_view_set_rules_hint(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_get_rules_hint(XEN tree_view)
{
  #define H_gtk_tree_view_get_rules_hint "gboolean gtk_tree_view_get_rules_hint(GtkTreeView* tree_view)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_get_rules_hint", "GtkTreeView*");
  return(C_TO_XEN_gboolean(gtk_tree_view_get_rules_hint(XEN_TO_C_GtkTreeView_(tree_view))));
}
static XEN gxg_gtk_tree_view_append_column(XEN tree_view, XEN column)
{
  #define H_gtk_tree_view_append_column "gint gtk_tree_view_append_column(GtkTreeView* tree_view, GtkTreeViewColumn* column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_append_column", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(column), column, 2, "gtk_tree_view_append_column", "GtkTreeViewColumn*");
  return(C_TO_XEN_gint(gtk_tree_view_append_column(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_GtkTreeViewColumn_(column))));
}
static XEN gxg_gtk_tree_view_remove_column(XEN tree_view, XEN column)
{
  #define H_gtk_tree_view_remove_column "gint gtk_tree_view_remove_column(GtkTreeView* tree_view, GtkTreeViewColumn* column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_remove_column", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(column), column, 2, "gtk_tree_view_remove_column", "GtkTreeViewColumn*");
  return(C_TO_XEN_gint(gtk_tree_view_remove_column(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_GtkTreeViewColumn_(column))));
}
static XEN gxg_gtk_tree_view_insert_column(XEN tree_view, XEN column, XEN position)
{
  #define H_gtk_tree_view_insert_column "gint gtk_tree_view_insert_column(GtkTreeView* tree_view, GtkTreeViewColumn* column, \
gint position)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_insert_column", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(column), column, 2, "gtk_tree_view_insert_column", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_gint_P(position), position, 3, "gtk_tree_view_insert_column", "gint");
  return(C_TO_XEN_gint(gtk_tree_view_insert_column(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_GtkTreeViewColumn_(column), 
                                                   XEN_TO_C_gint(position))));
}
static XEN gxg_gtk_tree_view_insert_column_with_attributes(XEN tree_view, XEN position, XEN title, XEN cell, XEN attributes)
{
  #define H_gtk_tree_view_insert_column_with_attributes "gint gtk_tree_view_insert_column_with_attributes(GtkTreeView* tree_view, \
gint position, gchar* title, GtkCellRenderer* cell, etc attributes)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_insert_column_with_attributes", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_gint_P(position), position, 2, "gtk_tree_view_insert_column_with_attributes", "gint");
  XEN_ASSERT_TYPE(XEN_gchar__P(title), title, 3, "gtk_tree_view_insert_column_with_attributes", "gchar*");
  XEN_ASSERT_TYPE(XEN_GtkCellRenderer__P(cell), cell, 4, "gtk_tree_view_insert_column_with_attributes", "GtkCellRenderer*");
  XEN_ASSERT_TYPE(XEN_etc_P(attributes), attributes, 5, "gtk_tree_view_insert_column_with_attributes", "etc");
  {
    int etc_len = 0;
    gint result = 0;
    GtkTreeView* p_arg0;
    gint p_arg1;
    gchar* p_arg2;
    GtkCellRenderer* p_arg3;
    if (XEN_LIST_P(attributes)) etc_len = XEN_LIST_LENGTH(attributes);
    if (etc_len < 2) XEN_OUT_OF_RANGE_ERROR("gtk_tree_view_insert_column_with_attributes", 4, attributes, "... list must have at least 2 entries");
    if (etc_len > 10) XEN_OUT_OF_RANGE_ERROR("gtk_tree_view_insert_column_with_attributes", 4, attributes, "... list too long (max len: 10)");
    if ((etc_len % 2) != 0) XEN_OUT_OF_RANGE_ERROR("gtk_tree_view_insert_column_with_attributes", 4, attributes, "... list len must be multiple of 2");
    p_arg0 = XEN_TO_C_GtkTreeView_(tree_view);
    p_arg1 = XEN_TO_C_gint(position);
    p_arg2 = XEN_TO_C_gchar_(title);
    p_arg3 = XEN_TO_C_GtkCellRenderer_(cell);
    switch (etc_len)
      {
        case 2: result = gtk_tree_view_insert_column_with_attributes(p_arg0, p_arg1, p_arg2, p_arg3, XLS(attributes, 0), XLI(attributes, 1), NULL); break;
        case 4: result = gtk_tree_view_insert_column_with_attributes(p_arg0, p_arg1, p_arg2, p_arg3, XLS(attributes, 0), XLI(attributes, 1), XLS(attributes, 2), XLI(attributes, 3), NULL); break;
        case 6: result = gtk_tree_view_insert_column_with_attributes(p_arg0, p_arg1, p_arg2, p_arg3, XLS(attributes, 0), XLI(attributes, 1), XLS(attributes, 2), XLI(attributes, 3), XLS(attributes, 4), XLI(attributes, 5), NULL); break;
        case 8: result = gtk_tree_view_insert_column_with_attributes(p_arg0, p_arg1, p_arg2, p_arg3, XLS(attributes, 0), XLI(attributes, 1), XLS(attributes, 2), XLI(attributes, 3), XLS(attributes, 4), XLI(attributes, 5), XLS(attributes, 6), XLI(attributes, 7), NULL); break;
        case 10: result = gtk_tree_view_insert_column_with_attributes(p_arg0, p_arg1, p_arg2, p_arg3, XLS(attributes, 0), XLI(attributes, 1), XLS(attributes, 2), XLI(attributes, 3), XLS(attributes, 4), XLI(attributes, 5), XLS(attributes, 6), XLI(attributes, 7), XLS(attributes, 8), XLI(attributes, 9), NULL); break;
      }
    return(C_TO_XEN_gint(result));
  }
}
static XEN gxg_gtk_tree_view_insert_column_with_data_func(XEN tree_view, XEN position, XEN title, XEN cell, XEN func, XEN func_data, XEN dnotify)
{
  #define H_gtk_tree_view_insert_column_with_data_func "gint gtk_tree_view_insert_column_with_data_func(GtkTreeView* tree_view, \
gint position, gchar* title, GtkCellRenderer* cell, GtkTreeCellDataFunc func, lambda_data func_data, \
GtkDestroyNotify dnotify)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_insert_column_with_data_func", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_gint_P(position), position, 2, "gtk_tree_view_insert_column_with_data_func", "gint");
  XEN_ASSERT_TYPE(XEN_gchar__P(title), title, 3, "gtk_tree_view_insert_column_with_data_func", "gchar*");
  XEN_ASSERT_TYPE(XEN_GtkCellRenderer__P(cell), cell, 4, "gtk_tree_view_insert_column_with_data_func", "GtkCellRenderer*");
  XEN_ASSERT_TYPE(XEN_GtkTreeCellDataFunc_P(func), func, 5, "gtk_tree_view_insert_column_with_data_func", "GtkTreeCellDataFunc");
  XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 6, "gtk_tree_view_insert_column_with_data_func", "lambda_data");
  XEN_ASSERT_TYPE(XEN_GtkDestroyNotify_P(dnotify), dnotify, 7, "gtk_tree_view_insert_column_with_data_func", "GtkDestroyNotify");
  {
    XEN result = XEN_FALSE;
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 3, dnotify);
    result = C_TO_XEN_gint(gtk_tree_view_insert_column_with_data_func(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_gint(position), 
                                                                      XEN_TO_C_gchar_(title), XEN_TO_C_GtkCellRenderer_(cell), 
                                                                      XEN_TO_C_GtkTreeCellDataFunc(func), XEN_TO_C_lambda_data(func_data), 
                                                                      XEN_TO_C_GtkDestroyNotify(dnotify)));
    return(result);
   }
}
static XEN gxg_gtk_tree_view_get_column(XEN tree_view, XEN n)
{
  #define H_gtk_tree_view_get_column "GtkTreeViewColumn* gtk_tree_view_get_column(GtkTreeView* tree_view, \
gint n)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_get_column", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_gint_P(n), n, 2, "gtk_tree_view_get_column", "gint");
  return(C_TO_XEN_GtkTreeViewColumn_(gtk_tree_view_get_column(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_gint(n))));
}
static XEN gxg_gtk_tree_view_get_columns(XEN tree_view)
{
  #define H_gtk_tree_view_get_columns "GList* gtk_tree_view_get_columns(GtkTreeView* tree_view)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_get_columns", "GtkTreeView*");
  return(C_TO_XEN_GList_(gtk_tree_view_get_columns(XEN_TO_C_GtkTreeView_(tree_view))));
}
static XEN gxg_gtk_tree_view_move_column_after(XEN tree_view, XEN column, XEN base_column)
{
  #define H_gtk_tree_view_move_column_after "void gtk_tree_view_move_column_after(GtkTreeView* tree_view, \
GtkTreeViewColumn* column, GtkTreeViewColumn* base_column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_move_column_after", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(column), column, 2, "gtk_tree_view_move_column_after", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(base_column) || XEN_FALSE_P(base_column), base_column, 3, "gtk_tree_view_move_column_after", "GtkTreeViewColumn*");
  gtk_tree_view_move_column_after(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_GtkTreeViewColumn_(column), XEN_TO_C_GtkTreeViewColumn_(base_column));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_set_expander_column(XEN tree_view, XEN column)
{
  #define H_gtk_tree_view_set_expander_column "void gtk_tree_view_set_expander_column(GtkTreeView* tree_view, \
GtkTreeViewColumn* column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_set_expander_column", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(column) || XEN_FALSE_P(column), column, 2, "gtk_tree_view_set_expander_column", "GtkTreeViewColumn*");
  gtk_tree_view_set_expander_column(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_GtkTreeViewColumn_(column));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_get_expander_column(XEN tree_view)
{
  #define H_gtk_tree_view_get_expander_column "GtkTreeViewColumn* gtk_tree_view_get_expander_column(GtkTreeView* tree_view)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_get_expander_column", "GtkTreeView*");
  return(C_TO_XEN_GtkTreeViewColumn_(gtk_tree_view_get_expander_column(XEN_TO_C_GtkTreeView_(tree_view))));
}
static XEN gxg_gtk_tree_view_set_column_drag_function(XEN tree_view, XEN func, XEN func_data, XEN destroy)
{
  #define H_gtk_tree_view_set_column_drag_function "void gtk_tree_view_set_column_drag_function(GtkTreeView* tree_view, \
GtkTreeViewColumnDropFunc func, lambda_data func_data, GtkDestroyNotify destroy)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_set_column_drag_function", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumnDropFunc_P(func), func, 2, "gtk_tree_view_set_column_drag_function", "GtkTreeViewColumnDropFunc");
  XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 3, "gtk_tree_view_set_column_drag_function", "lambda_data");
  XEN_ASSERT_TYPE(XEN_GtkDestroyNotify_P(destroy), destroy, 4, "gtk_tree_view_set_column_drag_function", "GtkDestroyNotify");
  {
    int loc;
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    loc = xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 2, C_TO_XEN_INT(loc));
    XEN_LIST_SET(gxg_ptr, 3, destroy);
    gtk_tree_view_set_column_drag_function(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_GtkTreeViewColumnDropFunc(func), XEN_TO_C_lambda_data(func_data), 
                                       XEN_TO_C_GtkDestroyNotify(destroy));
    xm_unprotect_at(loc);
    return(XEN_FALSE);
   }
}
static XEN gxg_gtk_tree_view_scroll_to_point(XEN tree_view, XEN tree_x, XEN tree_y)
{
  #define H_gtk_tree_view_scroll_to_point "void gtk_tree_view_scroll_to_point(GtkTreeView* tree_view, \
gint tree_x, gint tree_y)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_scroll_to_point", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_gint_P(tree_x), tree_x, 2, "gtk_tree_view_scroll_to_point", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(tree_y), tree_y, 3, "gtk_tree_view_scroll_to_point", "gint");
  gtk_tree_view_scroll_to_point(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_gint(tree_x), XEN_TO_C_gint(tree_y));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_scroll_to_cell(XEN tree_view, XEN path, XEN column, XEN use_align, XEN row_align, XEN col_align)
{
  #define H_gtk_tree_view_scroll_to_cell "void gtk_tree_view_scroll_to_cell(GtkTreeView* tree_view, GtkTreePath* path, \
GtkTreeViewColumn* column, gboolean use_align, gfloat row_align, gfloat col_align)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_scroll_to_cell", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path) || XEN_FALSE_P(path), path, 2, "gtk_tree_view_scroll_to_cell", "GtkTreePath*");
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(column) || XEN_FALSE_P(column), column, 3, "gtk_tree_view_scroll_to_cell", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(use_align), use_align, 4, "gtk_tree_view_scroll_to_cell", "gboolean");
  XEN_ASSERT_TYPE(XEN_gfloat_P(row_align), row_align, 5, "gtk_tree_view_scroll_to_cell", "gfloat");
  XEN_ASSERT_TYPE(XEN_gfloat_P(col_align), col_align, 6, "gtk_tree_view_scroll_to_cell", "gfloat");
  gtk_tree_view_scroll_to_cell(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_GtkTreePath_(path), XEN_TO_C_GtkTreeViewColumn_(column), 
                               XEN_TO_C_gboolean(use_align), XEN_TO_C_gfloat(row_align), XEN_TO_C_gfloat(col_align));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_row_activated(XEN tree_view, XEN path, XEN column)
{
  #define H_gtk_tree_view_row_activated "void gtk_tree_view_row_activated(GtkTreeView* tree_view, GtkTreePath* path, \
GtkTreeViewColumn* column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_row_activated", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 2, "gtk_tree_view_row_activated", "GtkTreePath*");
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(column), column, 3, "gtk_tree_view_row_activated", "GtkTreeViewColumn*");
  gtk_tree_view_row_activated(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_GtkTreePath_(path), XEN_TO_C_GtkTreeViewColumn_(column));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_expand_all(XEN tree_view)
{
  #define H_gtk_tree_view_expand_all "void gtk_tree_view_expand_all(GtkTreeView* tree_view)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_expand_all", "GtkTreeView*");
  gtk_tree_view_expand_all(XEN_TO_C_GtkTreeView_(tree_view));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_collapse_all(XEN tree_view)
{
  #define H_gtk_tree_view_collapse_all "void gtk_tree_view_collapse_all(GtkTreeView* tree_view)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_collapse_all", "GtkTreeView*");
  gtk_tree_view_collapse_all(XEN_TO_C_GtkTreeView_(tree_view));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_expand_row(XEN tree_view, XEN path, XEN open_all)
{
  #define H_gtk_tree_view_expand_row "gboolean gtk_tree_view_expand_row(GtkTreeView* tree_view, GtkTreePath* path, \
gboolean open_all)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_expand_row", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 2, "gtk_tree_view_expand_row", "GtkTreePath*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(open_all), open_all, 3, "gtk_tree_view_expand_row", "gboolean");
  return(C_TO_XEN_gboolean(gtk_tree_view_expand_row(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_GtkTreePath_(path), XEN_TO_C_gboolean(open_all))));
}
static XEN gxg_gtk_tree_view_collapse_row(XEN tree_view, XEN path)
{
  #define H_gtk_tree_view_collapse_row "gboolean gtk_tree_view_collapse_row(GtkTreeView* tree_view, GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_collapse_row", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 2, "gtk_tree_view_collapse_row", "GtkTreePath*");
  return(C_TO_XEN_gboolean(gtk_tree_view_collapse_row(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_GtkTreePath_(path))));
}
static XEN gxg_gtk_tree_view_map_expanded_rows(XEN tree_view, XEN func, XEN func_data)
{
  #define H_gtk_tree_view_map_expanded_rows "void gtk_tree_view_map_expanded_rows(GtkTreeView* tree_view, \
GtkTreeViewMappingFunc func, lambda_data func_data)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_map_expanded_rows", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_GtkTreeViewMappingFunc_P(func), func, 2, "gtk_tree_view_map_expanded_rows", "GtkTreeViewMappingFunc");
  if (XEN_NOT_BOUND_P(func_data)) func_data = XEN_FALSE; 
  else XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 3, "gtk_tree_view_map_expanded_rows", "lambda_data");
  {
    int loc;
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    loc = xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 2, C_TO_XEN_INT(loc));
    gtk_tree_view_map_expanded_rows(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_GtkTreeViewMappingFunc(func), XEN_TO_C_lambda_data(func_data));
    xm_unprotect_at(loc);
    return(XEN_FALSE);
   }
}
static XEN gxg_gtk_tree_view_row_expanded(XEN tree_view, XEN path)
{
  #define H_gtk_tree_view_row_expanded "gboolean gtk_tree_view_row_expanded(GtkTreeView* tree_view, GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_row_expanded", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 2, "gtk_tree_view_row_expanded", "GtkTreePath*");
  return(C_TO_XEN_gboolean(gtk_tree_view_row_expanded(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_GtkTreePath_(path))));
}
static XEN gxg_gtk_tree_view_set_reorderable(XEN tree_view, XEN reorderable)
{
  #define H_gtk_tree_view_set_reorderable "void gtk_tree_view_set_reorderable(GtkTreeView* tree_view, \
gboolean reorderable)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_set_reorderable", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(reorderable), reorderable, 2, "gtk_tree_view_set_reorderable", "gboolean");
  gtk_tree_view_set_reorderable(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_gboolean(reorderable));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_get_reorderable(XEN tree_view)
{
  #define H_gtk_tree_view_get_reorderable "gboolean gtk_tree_view_get_reorderable(GtkTreeView* tree_view)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_get_reorderable", "GtkTreeView*");
  return(C_TO_XEN_gboolean(gtk_tree_view_get_reorderable(XEN_TO_C_GtkTreeView_(tree_view))));
}
static XEN gxg_gtk_tree_view_set_cursor(XEN tree_view, XEN path, XEN focus_column, XEN start_editing)
{
  #define H_gtk_tree_view_set_cursor "void gtk_tree_view_set_cursor(GtkTreeView* tree_view, GtkTreePath* path, \
GtkTreeViewColumn* focus_column, gboolean start_editing)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_set_cursor", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 2, "gtk_tree_view_set_cursor", "GtkTreePath*");
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(focus_column), focus_column, 3, "gtk_tree_view_set_cursor", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(start_editing), start_editing, 4, "gtk_tree_view_set_cursor", "gboolean");
  gtk_tree_view_set_cursor(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_GtkTreePath_(path), XEN_TO_C_GtkTreeViewColumn_(focus_column), 
                           XEN_TO_C_gboolean(start_editing));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_get_cursor(XEN tree_view, XEN path, XEN focus_column)
{
  #define H_gtk_tree_view_get_cursor "void gtk_tree_view_get_cursor(GtkTreeView* tree_view, GtkTreePath** [path], \
GtkTreeViewColumn** [focus_column])"
  GtkTreePath* ref_path = NULL;
  GtkTreeViewColumn* ref_focus_column = NULL;
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_get_cursor", "GtkTreeView*");
  gtk_tree_view_get_cursor(XEN_TO_C_GtkTreeView_(tree_view), &ref_path, &ref_focus_column);
  return(XEN_LIST_2(C_TO_XEN_GtkTreePath_(ref_path), C_TO_XEN_GtkTreeViewColumn_(ref_focus_column)));
}
static XEN gxg_gtk_tree_view_get_bin_window(XEN tree_view)
{
  #define H_gtk_tree_view_get_bin_window "GdkWindow* gtk_tree_view_get_bin_window(GtkTreeView* tree_view)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_get_bin_window", "GtkTreeView*");
  return(C_TO_XEN_GdkWindow_(gtk_tree_view_get_bin_window(XEN_TO_C_GtkTreeView_(tree_view))));
}
static XEN gxg_gtk_tree_view_get_path_at_pos(XEN tree_view, XEN x, XEN y, XEN path, XEN column, XEN cell_x, XEN cell_y)
{
  #define H_gtk_tree_view_get_path_at_pos "gboolean gtk_tree_view_get_path_at_pos(GtkTreeView* tree_view, \
gint x, gint y, GtkTreePath** [path], GtkTreeViewColumn** [column], gint* [cell_x], gint* [cell_y])"
  GtkTreePath* ref_path = NULL;
  GtkTreeViewColumn* ref_column = NULL;
  gint ref_cell_x;
  gint ref_cell_y;
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_get_path_at_pos", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 2, "gtk_tree_view_get_path_at_pos", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 3, "gtk_tree_view_get_path_at_pos", "gint");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gtk_tree_view_get_path_at_pos(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_gint(x), XEN_TO_C_gint(y), 
                                                             &ref_path, &ref_column, &ref_cell_x, &ref_cell_y));
    return(XEN_LIST_5(result, C_TO_XEN_GtkTreePath_(ref_path), C_TO_XEN_GtkTreeViewColumn_(ref_column), C_TO_XEN_gint(ref_cell_x), C_TO_XEN_gint(ref_cell_y)));
   }
}
static XEN gxg_gtk_tree_view_get_cell_area(XEN tree_view, XEN path, XEN column, XEN rect)
{
  #define H_gtk_tree_view_get_cell_area "void gtk_tree_view_get_cell_area(GtkTreeView* tree_view, GtkTreePath* path, \
GtkTreeViewColumn* column, GdkRectangle* rect)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_get_cell_area", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path) || XEN_FALSE_P(path), path, 2, "gtk_tree_view_get_cell_area", "GtkTreePath*");
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(column) || XEN_FALSE_P(column), column, 3, "gtk_tree_view_get_cell_area", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(rect), rect, 4, "gtk_tree_view_get_cell_area", "GdkRectangle*");
  gtk_tree_view_get_cell_area(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_GtkTreePath_(path), XEN_TO_C_GtkTreeViewColumn_(column), 
                              XEN_TO_C_GdkRectangle_(rect));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_get_background_area(XEN tree_view, XEN path, XEN column, XEN rect)
{
  #define H_gtk_tree_view_get_background_area "void gtk_tree_view_get_background_area(GtkTreeView* tree_view, \
GtkTreePath* path, GtkTreeViewColumn* column, GdkRectangle* rect)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_get_background_area", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path) || XEN_FALSE_P(path), path, 2, "gtk_tree_view_get_background_area", "GtkTreePath*");
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(column) || XEN_FALSE_P(column), column, 3, "gtk_tree_view_get_background_area", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(rect), rect, 4, "gtk_tree_view_get_background_area", "GdkRectangle*");
  gtk_tree_view_get_background_area(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_GtkTreePath_(path), XEN_TO_C_GtkTreeViewColumn_(column), 
                                    XEN_TO_C_GdkRectangle_(rect));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_get_visible_rect(XEN tree_view, XEN visible_rect)
{
  #define H_gtk_tree_view_get_visible_rect "void gtk_tree_view_get_visible_rect(GtkTreeView* tree_view, \
GdkRectangle* visible_rect)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_get_visible_rect", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(visible_rect), visible_rect, 2, "gtk_tree_view_get_visible_rect", "GdkRectangle*");
  gtk_tree_view_get_visible_rect(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_GdkRectangle_(visible_rect));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_widget_to_tree_coords(XEN tree_view, XEN wx, XEN wy, XEN tx, XEN ty)
{
  #define H_gtk_tree_view_widget_to_tree_coords "void gtk_tree_view_widget_to_tree_coords(GtkTreeView* tree_view, \
gint wx, gint wy, gint* [tx], gint* [ty])"
  gint ref_tx;
  gint ref_ty;
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_widget_to_tree_coords", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_gint_P(wx), wx, 2, "gtk_tree_view_widget_to_tree_coords", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(wy), wy, 3, "gtk_tree_view_widget_to_tree_coords", "gint");
  gtk_tree_view_widget_to_tree_coords(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_gint(wx), XEN_TO_C_gint(wy), &ref_tx, &ref_ty);
  return(XEN_LIST_2(C_TO_XEN_gint(ref_tx), C_TO_XEN_gint(ref_ty)));
}
static XEN gxg_gtk_tree_view_tree_to_widget_coords(XEN tree_view, XEN tx, XEN ty, XEN wx, XEN wy)
{
  #define H_gtk_tree_view_tree_to_widget_coords "void gtk_tree_view_tree_to_widget_coords(GtkTreeView* tree_view, \
gint tx, gint ty, gint* [wx], gint* [wy])"
  gint ref_wx;
  gint ref_wy;
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_tree_to_widget_coords", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_gint_P(tx), tx, 2, "gtk_tree_view_tree_to_widget_coords", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(ty), ty, 3, "gtk_tree_view_tree_to_widget_coords", "gint");
  gtk_tree_view_tree_to_widget_coords(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_gint(tx), XEN_TO_C_gint(ty), &ref_wx, &ref_wy);
  return(XEN_LIST_2(C_TO_XEN_gint(ref_wx), C_TO_XEN_gint(ref_wy)));
}
static XEN gxg_gtk_tree_view_enable_model_drag_source(XEN tree_view, XEN start_button_mask, XEN targets, XEN n_targets, XEN actions)
{
  #define H_gtk_tree_view_enable_model_drag_source "void gtk_tree_view_enable_model_drag_source(GtkTreeView* tree_view, \
GdkModifierType start_button_mask, GtkTargetEntry* targets, gint n_targets, GdkDragAction actions)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_enable_model_drag_source", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_GdkModifierType_P(start_button_mask), start_button_mask, 2, "gtk_tree_view_enable_model_drag_source", "GdkModifierType");
  XEN_ASSERT_TYPE(XEN_GtkTargetEntry__P(targets), targets, 3, "gtk_tree_view_enable_model_drag_source", "GtkTargetEntry*");
  XEN_ASSERT_TYPE(XEN_gint_P(n_targets), n_targets, 4, "gtk_tree_view_enable_model_drag_source", "gint");
  XEN_ASSERT_TYPE(XEN_GdkDragAction_P(actions), actions, 5, "gtk_tree_view_enable_model_drag_source", "GdkDragAction");
  gtk_tree_view_enable_model_drag_source(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_GdkModifierType(start_button_mask), XEN_TO_C_GtkTargetEntry_(targets), 
                                         XEN_TO_C_gint(n_targets), XEN_TO_C_GdkDragAction(actions));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_enable_model_drag_dest(XEN tree_view, XEN targets, XEN n_targets, XEN actions)
{
  #define H_gtk_tree_view_enable_model_drag_dest "void gtk_tree_view_enable_model_drag_dest(GtkTreeView* tree_view, \
GtkTargetEntry* targets, gint n_targets, GdkDragAction actions)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_enable_model_drag_dest", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_GtkTargetEntry__P(targets), targets, 2, "gtk_tree_view_enable_model_drag_dest", "GtkTargetEntry*");
  XEN_ASSERT_TYPE(XEN_gint_P(n_targets), n_targets, 3, "gtk_tree_view_enable_model_drag_dest", "gint");
  XEN_ASSERT_TYPE(XEN_GdkDragAction_P(actions), actions, 4, "gtk_tree_view_enable_model_drag_dest", "GdkDragAction");
  gtk_tree_view_enable_model_drag_dest(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_GtkTargetEntry_(targets), XEN_TO_C_gint(n_targets), 
                                       XEN_TO_C_GdkDragAction(actions));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_unset_rows_drag_source(XEN tree_view)
{
  #define H_gtk_tree_view_unset_rows_drag_source "void gtk_tree_view_unset_rows_drag_source(GtkTreeView* tree_view)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_unset_rows_drag_source", "GtkTreeView*");
  gtk_tree_view_unset_rows_drag_source(XEN_TO_C_GtkTreeView_(tree_view));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_unset_rows_drag_dest(XEN tree_view)
{
  #define H_gtk_tree_view_unset_rows_drag_dest "void gtk_tree_view_unset_rows_drag_dest(GtkTreeView* tree_view)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_unset_rows_drag_dest", "GtkTreeView*");
  gtk_tree_view_unset_rows_drag_dest(XEN_TO_C_GtkTreeView_(tree_view));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_set_drag_dest_row(XEN tree_view, XEN path, XEN pos)
{
  #define H_gtk_tree_view_set_drag_dest_row "void gtk_tree_view_set_drag_dest_row(GtkTreeView* tree_view, \
GtkTreePath* path, GtkTreeViewDropPosition pos)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_set_drag_dest_row", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 2, "gtk_tree_view_set_drag_dest_row", "GtkTreePath*");
  XEN_ASSERT_TYPE(XEN_GtkTreeViewDropPosition_P(pos), pos, 3, "gtk_tree_view_set_drag_dest_row", "GtkTreeViewDropPosition");
  gtk_tree_view_set_drag_dest_row(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_GtkTreePath_(path), XEN_TO_C_GtkTreeViewDropPosition(pos));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_get_drag_dest_row(XEN tree_view, XEN path, XEN pos)
{
  #define H_gtk_tree_view_get_drag_dest_row "void gtk_tree_view_get_drag_dest_row(GtkTreeView* tree_view, \
GtkTreePath** [path], GtkTreeViewDropPosition* [pos])"
  GtkTreePath* ref_path = NULL;
  GtkTreeViewDropPosition ref_pos;
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_get_drag_dest_row", "GtkTreeView*");
  gtk_tree_view_get_drag_dest_row(XEN_TO_C_GtkTreeView_(tree_view), &ref_path, &ref_pos);
  return(XEN_LIST_2(C_TO_XEN_GtkTreePath_(ref_path), C_TO_XEN_GtkTreeViewDropPosition(ref_pos)));
}
static XEN gxg_gtk_tree_view_get_dest_row_at_pos(XEN tree_view, XEN drag_x, XEN drag_y, XEN path, XEN pos)
{
  #define H_gtk_tree_view_get_dest_row_at_pos "gboolean gtk_tree_view_get_dest_row_at_pos(GtkTreeView* tree_view, \
gint drag_x, gint drag_y, GtkTreePath** [path], GtkTreeViewDropPosition* [pos])"
  GtkTreePath* ref_path = NULL;
  GtkTreeViewDropPosition ref_pos;
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_get_dest_row_at_pos", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_gint_P(drag_x), drag_x, 2, "gtk_tree_view_get_dest_row_at_pos", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(drag_y), drag_y, 3, "gtk_tree_view_get_dest_row_at_pos", "gint");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gtk_tree_view_get_dest_row_at_pos(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_gint(drag_x), 
                                                                 XEN_TO_C_gint(drag_y), &ref_path, &ref_pos));
    return(XEN_LIST_3(result, C_TO_XEN_GtkTreePath_(ref_path), C_TO_XEN_GtkTreeViewDropPosition(ref_pos)));
   }
}
static XEN gxg_gtk_tree_view_create_row_drag_icon(XEN tree_view, XEN path)
{
  #define H_gtk_tree_view_create_row_drag_icon "GdkPixmap* gtk_tree_view_create_row_drag_icon(GtkTreeView* tree_view, \
GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_create_row_drag_icon", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 2, "gtk_tree_view_create_row_drag_icon", "GtkTreePath*");
  return(C_TO_XEN_GdkPixmap_(gtk_tree_view_create_row_drag_icon(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_GtkTreePath_(path))));
}
static XEN gxg_gtk_tree_view_set_enable_search(XEN tree_view, XEN enable_search)
{
  #define H_gtk_tree_view_set_enable_search "void gtk_tree_view_set_enable_search(GtkTreeView* tree_view, \
gboolean enable_search)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_set_enable_search", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(enable_search), enable_search, 2, "gtk_tree_view_set_enable_search", "gboolean");
  gtk_tree_view_set_enable_search(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_gboolean(enable_search));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_get_enable_search(XEN tree_view)
{
  #define H_gtk_tree_view_get_enable_search "gboolean gtk_tree_view_get_enable_search(GtkTreeView* tree_view)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_get_enable_search", "GtkTreeView*");
  return(C_TO_XEN_gboolean(gtk_tree_view_get_enable_search(XEN_TO_C_GtkTreeView_(tree_view))));
}
static XEN gxg_gtk_tree_view_get_search_column(XEN tree_view)
{
  #define H_gtk_tree_view_get_search_column "gint gtk_tree_view_get_search_column(GtkTreeView* tree_view)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_get_search_column", "GtkTreeView*");
  return(C_TO_XEN_gint(gtk_tree_view_get_search_column(XEN_TO_C_GtkTreeView_(tree_view))));
}
static XEN gxg_gtk_tree_view_set_search_column(XEN tree_view, XEN column)
{
  #define H_gtk_tree_view_set_search_column "void gtk_tree_view_set_search_column(GtkTreeView* tree_view, \
gint column)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_set_search_column", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_gint_P(column), column, 2, "gtk_tree_view_set_search_column", "gint");
  gtk_tree_view_set_search_column(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_gint(column));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_get_search_equal_func(XEN tree_view)
{
  #define H_gtk_tree_view_get_search_equal_func "GtkTreeViewSearchEqualFunc gtk_tree_view_get_search_equal_func(GtkTreeView* tree_view)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_get_search_equal_func", "GtkTreeView*");
  return(C_TO_XEN_GtkTreeViewSearchEqualFunc(gtk_tree_view_get_search_equal_func(XEN_TO_C_GtkTreeView_(tree_view))));
}
static XEN gxg_gtk_tree_view_set_search_equal_func(XEN tree_view, XEN func, XEN func_data, XEN search_destroy)
{
  #define H_gtk_tree_view_set_search_equal_func "void gtk_tree_view_set_search_equal_func(GtkTreeView* tree_view, \
GtkTreeViewSearchEqualFunc func, lambda_data func_data, GtkDestroyNotify search_destroy)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_set_search_equal_func", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_GtkTreeViewSearchEqualFunc_P(func), func, 2, "gtk_tree_view_set_search_equal_func", "GtkTreeViewSearchEqualFunc");
  XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 3, "gtk_tree_view_set_search_equal_func", "lambda_data");
  XEN_ASSERT_TYPE(XEN_GtkDestroyNotify_P(search_destroy), search_destroy, 4, "gtk_tree_view_set_search_equal_func", "GtkDestroyNotify");
  {
    int loc;
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    loc = xm_protect(gxg_ptr);
    XEN_LIST_SET(gxg_ptr, 2, C_TO_XEN_INT(loc));
    XEN_LIST_SET(gxg_ptr, 3, search_destroy);
    gtk_tree_view_set_search_equal_func(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_GtkTreeViewSearchEqualFunc(func), XEN_TO_C_lambda_data(func_data), 
                                    XEN_TO_C_GtkDestroyNotify(search_destroy));
    xm_unprotect_at(loc);
    return(XEN_FALSE);
   }
}
static XEN gxg_gtk_vbutton_box_get_type(void)
{
  #define H_gtk_vbutton_box_get_type "GtkType gtk_vbutton_box_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_vbutton_box_get_type()));
}
static XEN gxg_gtk_vbutton_box_new(void)
{
  #define H_gtk_vbutton_box_new "GtkWidget* gtk_vbutton_box_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_vbutton_box_new()));
}
static XEN gxg_gtk_viewport_get_type(void)
{
  #define H_gtk_viewport_get_type "GtkType gtk_viewport_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_viewport_get_type()));
}
static XEN gxg_gtk_viewport_new(XEN hadjustment, XEN vadjustment)
{
  #define H_gtk_viewport_new "GtkWidget* gtk_viewport_new(GtkAdjustment* hadjustment, GtkAdjustment* vadjustment)"
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(hadjustment), hadjustment, 1, "gtk_viewport_new", "GtkAdjustment*");
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(vadjustment), vadjustment, 2, "gtk_viewport_new", "GtkAdjustment*");
  return(C_TO_XEN_GtkWidget_(gtk_viewport_new(XEN_TO_C_GtkAdjustment_(hadjustment), XEN_TO_C_GtkAdjustment_(vadjustment))));
}
static XEN gxg_gtk_viewport_get_hadjustment(XEN viewport)
{
  #define H_gtk_viewport_get_hadjustment "GtkAdjustment* gtk_viewport_get_hadjustment(GtkViewport* viewport)"
  XEN_ASSERT_TYPE(XEN_GtkViewport__P(viewport), viewport, 1, "gtk_viewport_get_hadjustment", "GtkViewport*");
  return(C_TO_XEN_GtkAdjustment_(gtk_viewport_get_hadjustment(XEN_TO_C_GtkViewport_(viewport))));
}
static XEN gxg_gtk_viewport_get_vadjustment(XEN viewport)
{
  #define H_gtk_viewport_get_vadjustment "GtkAdjustment* gtk_viewport_get_vadjustment(GtkViewport* viewport)"
  XEN_ASSERT_TYPE(XEN_GtkViewport__P(viewport), viewport, 1, "gtk_viewport_get_vadjustment", "GtkViewport*");
  return(C_TO_XEN_GtkAdjustment_(gtk_viewport_get_vadjustment(XEN_TO_C_GtkViewport_(viewport))));
}
static XEN gxg_gtk_viewport_set_hadjustment(XEN viewport, XEN adjustment)
{
  #define H_gtk_viewport_set_hadjustment "void gtk_viewport_set_hadjustment(GtkViewport* viewport, GtkAdjustment* adjustment)"
  XEN_ASSERT_TYPE(XEN_GtkViewport__P(viewport), viewport, 1, "gtk_viewport_set_hadjustment", "GtkViewport*");
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(adjustment), adjustment, 2, "gtk_viewport_set_hadjustment", "GtkAdjustment*");
  gtk_viewport_set_hadjustment(XEN_TO_C_GtkViewport_(viewport), XEN_TO_C_GtkAdjustment_(adjustment));
  return(XEN_FALSE);
}
static XEN gxg_gtk_viewport_set_vadjustment(XEN viewport, XEN adjustment)
{
  #define H_gtk_viewport_set_vadjustment "void gtk_viewport_set_vadjustment(GtkViewport* viewport, GtkAdjustment* adjustment)"
  XEN_ASSERT_TYPE(XEN_GtkViewport__P(viewport), viewport, 1, "gtk_viewport_set_vadjustment", "GtkViewport*");
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(adjustment), adjustment, 2, "gtk_viewport_set_vadjustment", "GtkAdjustment*");
  gtk_viewport_set_vadjustment(XEN_TO_C_GtkViewport_(viewport), XEN_TO_C_GtkAdjustment_(adjustment));
  return(XEN_FALSE);
}
static XEN gxg_gtk_viewport_set_shadow_type(XEN viewport, XEN type)
{
  #define H_gtk_viewport_set_shadow_type "void gtk_viewport_set_shadow_type(GtkViewport* viewport, GtkShadowType type)"
  XEN_ASSERT_TYPE(XEN_GtkViewport__P(viewport), viewport, 1, "gtk_viewport_set_shadow_type", "GtkViewport*");
  XEN_ASSERT_TYPE(XEN_GtkShadowType_P(type), type, 2, "gtk_viewport_set_shadow_type", "GtkShadowType");
  gtk_viewport_set_shadow_type(XEN_TO_C_GtkViewport_(viewport), XEN_TO_C_GtkShadowType(type));
  return(XEN_FALSE);
}
static XEN gxg_gtk_viewport_get_shadow_type(XEN viewport)
{
  #define H_gtk_viewport_get_shadow_type "GtkShadowType gtk_viewport_get_shadow_type(GtkViewport* viewport)"
  XEN_ASSERT_TYPE(XEN_GtkViewport__P(viewport), viewport, 1, "gtk_viewport_get_shadow_type", "GtkViewport*");
  return(C_TO_XEN_GtkShadowType(gtk_viewport_get_shadow_type(XEN_TO_C_GtkViewport_(viewport))));
}
static XEN gxg_gtk_vpaned_get_type(void)
{
  #define H_gtk_vpaned_get_type "GtkType gtk_vpaned_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_vpaned_get_type()));
}
static XEN gxg_gtk_vpaned_new(void)
{
  #define H_gtk_vpaned_new "GtkWidget* gtk_vpaned_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_vpaned_new()));
}
static XEN gxg_gtk_vruler_get_type(void)
{
  #define H_gtk_vruler_get_type "GtkType gtk_vruler_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_vruler_get_type()));
}
static XEN gxg_gtk_vruler_new(void)
{
  #define H_gtk_vruler_new "GtkWidget* gtk_vruler_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_vruler_new()));
}
static XEN gxg_gtk_vscale_get_type(void)
{
  #define H_gtk_vscale_get_type "GtkType gtk_vscale_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_vscale_get_type()));
}
static XEN gxg_gtk_vscale_new(XEN adjustment)
{
  #define H_gtk_vscale_new "GtkWidget* gtk_vscale_new(GtkAdjustment* adjustment)"
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(adjustment), adjustment, 1, "gtk_vscale_new", "GtkAdjustment*");
  return(C_TO_XEN_GtkWidget_(gtk_vscale_new(XEN_TO_C_GtkAdjustment_(adjustment))));
}
static XEN gxg_gtk_vscale_new_with_range(XEN min, XEN max, XEN step)
{
  #define H_gtk_vscale_new_with_range "GtkWidget* gtk_vscale_new_with_range(gdouble min, gdouble max, \
gdouble step)"
  XEN_ASSERT_TYPE(XEN_gdouble_P(min), min, 1, "gtk_vscale_new_with_range", "gdouble");
  XEN_ASSERT_TYPE(XEN_gdouble_P(max), max, 2, "gtk_vscale_new_with_range", "gdouble");
  XEN_ASSERT_TYPE(XEN_gdouble_P(step), step, 3, "gtk_vscale_new_with_range", "gdouble");
  return(C_TO_XEN_GtkWidget_(gtk_vscale_new_with_range(XEN_TO_C_gdouble(min), XEN_TO_C_gdouble(max), XEN_TO_C_gdouble(step))));
}
static XEN gxg_gtk_vscrollbar_get_type(void)
{
  #define H_gtk_vscrollbar_get_type "GtkType gtk_vscrollbar_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_vscrollbar_get_type()));
}
static XEN gxg_gtk_vscrollbar_new(XEN adjustment)
{
  #define H_gtk_vscrollbar_new "GtkWidget* gtk_vscrollbar_new(GtkAdjustment* adjustment)"
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(adjustment), adjustment, 1, "gtk_vscrollbar_new", "GtkAdjustment*");
  return(C_TO_XEN_GtkWidget_(gtk_vscrollbar_new(XEN_TO_C_GtkAdjustment_(adjustment))));
}
static XEN gxg_gtk_vseparator_get_type(void)
{
  #define H_gtk_vseparator_get_type "GtkType gtk_vseparator_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_vseparator_get_type()));
}
static XEN gxg_gtk_vseparator_new(void)
{
  #define H_gtk_vseparator_new "GtkWidget* gtk_vseparator_new( void)"
  return(C_TO_XEN_GtkWidget_(gtk_vseparator_new()));
}
static XEN gxg_GTK_WIDGET_STATE(XEN wid)
{
  #define H_GTK_WIDGET_STATE "int GTK_WIDGET_STATE(GtkWidget* wid)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(wid), wid, 1, "GTK_WIDGET_STATE", "GtkWidget*");
  return(C_TO_XEN_int(GTK_WIDGET_STATE(XEN_TO_C_GtkWidget_(wid))));
}
static XEN gxg_GTK_WIDGET_SAVED_STATE(XEN wid)
{
  #define H_GTK_WIDGET_SAVED_STATE "int GTK_WIDGET_SAVED_STATE(GtkWidget* wid)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(wid), wid, 1, "GTK_WIDGET_SAVED_STATE", "GtkWidget*");
  return(C_TO_XEN_int(GTK_WIDGET_SAVED_STATE(XEN_TO_C_GtkWidget_(wid))));
}
static XEN gxg_GTK_WIDGET_FLAGS(XEN wid)
{
  #define H_GTK_WIDGET_FLAGS "int GTK_WIDGET_FLAGS(GtkWidget* wid)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(wid), wid, 1, "GTK_WIDGET_FLAGS", "GtkWidget*");
  return(C_TO_XEN_int(GTK_WIDGET_FLAGS(XEN_TO_C_GtkWidget_(wid))));
}
static XEN gxg_GTK_WIDGET_TOPLEVEL(XEN wid)
{
  #define H_GTK_WIDGET_TOPLEVEL "gboolean GTK_WIDGET_TOPLEVEL(GtkWidget* wid)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(wid), wid, 1, "GTK_WIDGET_TOPLEVEL", "GtkWidget*");
  return(C_TO_XEN_gboolean(GTK_WIDGET_TOPLEVEL(XEN_TO_C_GtkWidget_(wid))));
}
static XEN gxg_GTK_WIDGET_NO_WINDOW(XEN wid)
{
  #define H_GTK_WIDGET_NO_WINDOW "gboolean GTK_WIDGET_NO_WINDOW(GtkWidget* wid)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(wid), wid, 1, "GTK_WIDGET_NO_WINDOW", "GtkWidget*");
  return(C_TO_XEN_gboolean(GTK_WIDGET_NO_WINDOW(XEN_TO_C_GtkWidget_(wid))));
}
static XEN gxg_GTK_WIDGET_REALIZED(XEN wid)
{
  #define H_GTK_WIDGET_REALIZED "gboolean GTK_WIDGET_REALIZED(GtkWidget* wid)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(wid), wid, 1, "GTK_WIDGET_REALIZED", "GtkWidget*");
  return(C_TO_XEN_gboolean(GTK_WIDGET_REALIZED(XEN_TO_C_GtkWidget_(wid))));
}
static XEN gxg_GTK_WIDGET_MAPPED(XEN wid)
{
  #define H_GTK_WIDGET_MAPPED "gboolean GTK_WIDGET_MAPPED(GtkWidget* wid)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(wid), wid, 1, "GTK_WIDGET_MAPPED", "GtkWidget*");
  return(C_TO_XEN_gboolean(GTK_WIDGET_MAPPED(XEN_TO_C_GtkWidget_(wid))));
}
static XEN gxg_GTK_WIDGET_VISIBLE(XEN wid)
{
  #define H_GTK_WIDGET_VISIBLE "gboolean GTK_WIDGET_VISIBLE(GtkWidget* wid)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(wid), wid, 1, "GTK_WIDGET_VISIBLE", "GtkWidget*");
  return(C_TO_XEN_gboolean(GTK_WIDGET_VISIBLE(XEN_TO_C_GtkWidget_(wid))));
}
static XEN gxg_GTK_WIDGET_DRAWABLE(XEN wid)
{
  #define H_GTK_WIDGET_DRAWABLE "gboolean GTK_WIDGET_DRAWABLE(GtkWidget* wid)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(wid), wid, 1, "GTK_WIDGET_DRAWABLE", "GtkWidget*");
  return(C_TO_XEN_gboolean(GTK_WIDGET_DRAWABLE(XEN_TO_C_GtkWidget_(wid))));
}
static XEN gxg_GTK_WIDGET_SENSITIVE(XEN wid)
{
  #define H_GTK_WIDGET_SENSITIVE "gboolean GTK_WIDGET_SENSITIVE(GtkWidget* wid)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(wid), wid, 1, "GTK_WIDGET_SENSITIVE", "GtkWidget*");
  return(C_TO_XEN_gboolean(GTK_WIDGET_SENSITIVE(XEN_TO_C_GtkWidget_(wid))));
}
static XEN gxg_GTK_WIDGET_PARENT_SENSITIVE(XEN wid)
{
  #define H_GTK_WIDGET_PARENT_SENSITIVE "gboolean GTK_WIDGET_PARENT_SENSITIVE(GtkWidget* wid)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(wid), wid, 1, "GTK_WIDGET_PARENT_SENSITIVE", "GtkWidget*");
  return(C_TO_XEN_gboolean(GTK_WIDGET_PARENT_SENSITIVE(XEN_TO_C_GtkWidget_(wid))));
}
static XEN gxg_GTK_WIDGET_IS_SENSITIVE(XEN wid)
{
  #define H_GTK_WIDGET_IS_SENSITIVE "gboolean GTK_WIDGET_IS_SENSITIVE(GtkWidget* wid)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(wid), wid, 1, "GTK_WIDGET_IS_SENSITIVE", "GtkWidget*");
  return(C_TO_XEN_gboolean(GTK_WIDGET_IS_SENSITIVE(XEN_TO_C_GtkWidget_(wid))));
}
static XEN gxg_GTK_WIDGET_CAN_FOCUS(XEN wid)
{
  #define H_GTK_WIDGET_CAN_FOCUS "gboolean GTK_WIDGET_CAN_FOCUS(GtkWidget* wid)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(wid), wid, 1, "GTK_WIDGET_CAN_FOCUS", "GtkWidget*");
  return(C_TO_XEN_gboolean(GTK_WIDGET_CAN_FOCUS(XEN_TO_C_GtkWidget_(wid))));
}
static XEN gxg_GTK_WIDGET_HAS_FOCUS(XEN wid)
{
  #define H_GTK_WIDGET_HAS_FOCUS "gboolean GTK_WIDGET_HAS_FOCUS(GtkWidget* wid)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(wid), wid, 1, "GTK_WIDGET_HAS_FOCUS", "GtkWidget*");
  return(C_TO_XEN_gboolean(GTK_WIDGET_HAS_FOCUS(XEN_TO_C_GtkWidget_(wid))));
}
static XEN gxg_GTK_WIDGET_CAN_DEFAULT(XEN wid)
{
  #define H_GTK_WIDGET_CAN_DEFAULT "gboolean GTK_WIDGET_CAN_DEFAULT(GtkWidget* wid)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(wid), wid, 1, "GTK_WIDGET_CAN_DEFAULT", "GtkWidget*");
  return(C_TO_XEN_gboolean(GTK_WIDGET_CAN_DEFAULT(XEN_TO_C_GtkWidget_(wid))));
}
static XEN gxg_GTK_WIDGET_HAS_DEFAULT(XEN wid)
{
  #define H_GTK_WIDGET_HAS_DEFAULT "gboolean GTK_WIDGET_HAS_DEFAULT(GtkWidget* wid)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(wid), wid, 1, "GTK_WIDGET_HAS_DEFAULT", "GtkWidget*");
  return(C_TO_XEN_gboolean(GTK_WIDGET_HAS_DEFAULT(XEN_TO_C_GtkWidget_(wid))));
}
static XEN gxg_GTK_WIDGET_HAS_GRAB(XEN wid)
{
  #define H_GTK_WIDGET_HAS_GRAB "gboolean GTK_WIDGET_HAS_GRAB(GtkWidget* wid)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(wid), wid, 1, "GTK_WIDGET_HAS_GRAB", "GtkWidget*");
  return(C_TO_XEN_gboolean(GTK_WIDGET_HAS_GRAB(XEN_TO_C_GtkWidget_(wid))));
}
static XEN gxg_GTK_WIDGET_RC_STYLE(XEN wid)
{
  #define H_GTK_WIDGET_RC_STYLE "gboolean GTK_WIDGET_RC_STYLE(GtkWidget* wid)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(wid), wid, 1, "GTK_WIDGET_RC_STYLE", "GtkWidget*");
  return(C_TO_XEN_gboolean(GTK_WIDGET_RC_STYLE(XEN_TO_C_GtkWidget_(wid))));
}
static XEN gxg_GTK_WIDGET_COMPOSITE_CHILD(XEN wid)
{
  #define H_GTK_WIDGET_COMPOSITE_CHILD "gboolean GTK_WIDGET_COMPOSITE_CHILD(GtkWidget* wid)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(wid), wid, 1, "GTK_WIDGET_COMPOSITE_CHILD", "GtkWidget*");
  return(C_TO_XEN_gboolean(GTK_WIDGET_COMPOSITE_CHILD(XEN_TO_C_GtkWidget_(wid))));
}
static XEN gxg_GTK_WIDGET_APP_PAINTABLE(XEN wid)
{
  #define H_GTK_WIDGET_APP_PAINTABLE "gboolean GTK_WIDGET_APP_PAINTABLE(GtkWidget* wid)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(wid), wid, 1, "GTK_WIDGET_APP_PAINTABLE", "GtkWidget*");
  return(C_TO_XEN_gboolean(GTK_WIDGET_APP_PAINTABLE(XEN_TO_C_GtkWidget_(wid))));
}
static XEN gxg_GTK_WIDGET_RECEIVES_DEFAULT(XEN wid)
{
  #define H_GTK_WIDGET_RECEIVES_DEFAULT "gboolean GTK_WIDGET_RECEIVES_DEFAULT(GtkWidget* wid)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(wid), wid, 1, "GTK_WIDGET_RECEIVES_DEFAULT", "GtkWidget*");
  return(C_TO_XEN_gboolean(GTK_WIDGET_RECEIVES_DEFAULT(XEN_TO_C_GtkWidget_(wid))));
}
static XEN gxg_GTK_WIDGET_DOUBLE_BUFFERED(XEN wid)
{
  #define H_GTK_WIDGET_DOUBLE_BUFFERED "gboolean GTK_WIDGET_DOUBLE_BUFFERED(GtkWidget* wid)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(wid), wid, 1, "GTK_WIDGET_DOUBLE_BUFFERED", "GtkWidget*");
  return(C_TO_XEN_gboolean(GTK_WIDGET_DOUBLE_BUFFERED(XEN_TO_C_GtkWidget_(wid))));
}
static XEN gxg_GTK_WIDGET_SET_FLAGS(XEN wid, XEN flag)
{
  #define H_GTK_WIDGET_SET_FLAGS "void GTK_WIDGET_SET_FLAGS(GtkWidget* wid, int flag)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(wid), wid, 1, "GTK_WIDGET_SET_FLAGS", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_int_P(flag), flag, 2, "GTK_WIDGET_SET_FLAGS", "int");
  GTK_WIDGET_SET_FLAGS(XEN_TO_C_GtkWidget_(wid), XEN_TO_C_int(flag));
  return(XEN_FALSE);
}
static XEN gxg_GTK_WIDGET_UNSET_FLAGS(XEN wid, XEN flag)
{
  #define H_GTK_WIDGET_UNSET_FLAGS "void GTK_WIDGET_UNSET_FLAGS(GtkWidget* wid, int flag)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(wid), wid, 1, "GTK_WIDGET_UNSET_FLAGS", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_int_P(flag), flag, 2, "GTK_WIDGET_UNSET_FLAGS", "int");
  GTK_WIDGET_UNSET_FLAGS(XEN_TO_C_GtkWidget_(wid), XEN_TO_C_int(flag));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_get_type(void)
{
  #define H_gtk_widget_get_type "GtkType gtk_widget_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_widget_get_type()));
}
static XEN gxg_gtk_widget_ref(XEN widget)
{
  #define H_gtk_widget_ref "GtkWidget* gtk_widget_ref(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_ref", "GtkWidget*");
  return(C_TO_XEN_GtkWidget_(gtk_widget_ref(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_widget_unref(XEN widget)
{
  #define H_gtk_widget_unref "void gtk_widget_unref(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_unref", "GtkWidget*");
  gtk_widget_unref(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_destroy(XEN widget)
{
  #define H_gtk_widget_destroy "void gtk_widget_destroy(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_destroy", "GtkWidget*");
  gtk_widget_destroy(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_destroyed(XEN widget, XEN widget_pointer)
{
  #define H_gtk_widget_destroyed "void gtk_widget_destroyed(GtkWidget* widget, GtkWidget** [widget_pointer])"
  GtkWidget* ref_widget_pointer = NULL;
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_destroyed", "GtkWidget*");
  gtk_widget_destroyed(XEN_TO_C_GtkWidget_(widget), &ref_widget_pointer);
  return(XEN_LIST_1(C_TO_XEN_GtkWidget_(ref_widget_pointer)));
}
static XEN gxg_gtk_widget_unparent(XEN widget)
{
  #define H_gtk_widget_unparent "void gtk_widget_unparent(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_unparent", "GtkWidget*");
  gtk_widget_unparent(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_show(XEN widget)
{
  #define H_gtk_widget_show "void gtk_widget_show(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_show", "GtkWidget*");
  gtk_widget_show(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_show_now(XEN widget)
{
  #define H_gtk_widget_show_now "void gtk_widget_show_now(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_show_now", "GtkWidget*");
  gtk_widget_show_now(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_hide(XEN widget)
{
  #define H_gtk_widget_hide "void gtk_widget_hide(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_hide", "GtkWidget*");
  gtk_widget_hide(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_show_all(XEN widget)
{
  #define H_gtk_widget_show_all "void gtk_widget_show_all(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_show_all", "GtkWidget*");
  gtk_widget_show_all(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_hide_all(XEN widget)
{
  #define H_gtk_widget_hide_all "void gtk_widget_hide_all(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_hide_all", "GtkWidget*");
  gtk_widget_hide_all(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_map(XEN widget)
{
  #define H_gtk_widget_map "void gtk_widget_map(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_map", "GtkWidget*");
  gtk_widget_map(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_unmap(XEN widget)
{
  #define H_gtk_widget_unmap "void gtk_widget_unmap(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_unmap", "GtkWidget*");
  gtk_widget_unmap(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_realize(XEN widget)
{
  #define H_gtk_widget_realize "void gtk_widget_realize(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_realize", "GtkWidget*");
  gtk_widget_realize(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_unrealize(XEN widget)
{
  #define H_gtk_widget_unrealize "void gtk_widget_unrealize(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_unrealize", "GtkWidget*");
  gtk_widget_unrealize(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_queue_draw(XEN widget)
{
  #define H_gtk_widget_queue_draw "void gtk_widget_queue_draw(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_queue_draw", "GtkWidget*");
  gtk_widget_queue_draw(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_queue_draw_area(XEN widget, XEN x, XEN y, XEN width, XEN height)
{
  #define H_gtk_widget_queue_draw_area "void gtk_widget_queue_draw_area(GtkWidget* widget, gint x, gint y, \
gint width, gint height)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_queue_draw_area", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 2, "gtk_widget_queue_draw_area", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 3, "gtk_widget_queue_draw_area", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 4, "gtk_widget_queue_draw_area", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 5, "gtk_widget_queue_draw_area", "gint");
  gtk_widget_queue_draw_area(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gint(x), XEN_TO_C_gint(y), XEN_TO_C_gint(width), XEN_TO_C_gint(height));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_queue_resize(XEN widget)
{
  #define H_gtk_widget_queue_resize "void gtk_widget_queue_resize(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_queue_resize", "GtkWidget*");
  gtk_widget_queue_resize(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_size_request(XEN widget, XEN requisition)
{
  #define H_gtk_widget_size_request "void gtk_widget_size_request(GtkWidget* widget, GtkRequisition* requisition)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_size_request", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkRequisition__P(requisition), requisition, 2, "gtk_widget_size_request", "GtkRequisition*");
  gtk_widget_size_request(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GtkRequisition_(requisition));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_size_allocate(XEN widget, XEN allocation)
{
  #define H_gtk_widget_size_allocate "void gtk_widget_size_allocate(GtkWidget* widget, GtkAllocation* allocation)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_size_allocate", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkAllocation__P(allocation), allocation, 2, "gtk_widget_size_allocate", "GtkAllocation*");
  gtk_widget_size_allocate(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GtkAllocation_(allocation));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_get_child_requisition(XEN widget, XEN requisition)
{
  #define H_gtk_widget_get_child_requisition "void gtk_widget_get_child_requisition(GtkWidget* widget, \
GtkRequisition* requisition)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_get_child_requisition", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkRequisition__P(requisition), requisition, 2, "gtk_widget_get_child_requisition", "GtkRequisition*");
  gtk_widget_get_child_requisition(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GtkRequisition_(requisition));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_add_accelerator(XEN widget, XEN accel_signal, XEN accel_group, XEN accel_key, XEN accel_mods, XEN accel_flags)
{
  #define H_gtk_widget_add_accelerator "void gtk_widget_add_accelerator(GtkWidget* widget, gchar* accel_signal, \
GtkAccelGroup* accel_group, guint accel_key, GdkModifierType accel_mods, GtkAccelFlags accel_flags)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_add_accelerator", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(accel_signal), accel_signal, 2, "gtk_widget_add_accelerator", "gchar*");
  XEN_ASSERT_TYPE(XEN_GtkAccelGroup__P(accel_group), accel_group, 3, "gtk_widget_add_accelerator", "GtkAccelGroup*");
  XEN_ASSERT_TYPE(XEN_guint_P(accel_key), accel_key, 4, "gtk_widget_add_accelerator", "guint");
  XEN_ASSERT_TYPE(XEN_GdkModifierType_P(accel_mods), accel_mods, 5, "gtk_widget_add_accelerator", "GdkModifierType");
  XEN_ASSERT_TYPE(XEN_GtkAccelFlags_P(accel_flags), accel_flags, 6, "gtk_widget_add_accelerator", "GtkAccelFlags");
  gtk_widget_add_accelerator(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(accel_signal), XEN_TO_C_GtkAccelGroup_(accel_group), 
                             XEN_TO_C_guint(accel_key), XEN_TO_C_GdkModifierType(accel_mods), XEN_TO_C_GtkAccelFlags(accel_flags));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_remove_accelerator(XEN widget, XEN accel_group, XEN accel_key, XEN accel_mods)
{
  #define H_gtk_widget_remove_accelerator "gboolean gtk_widget_remove_accelerator(GtkWidget* widget, \
GtkAccelGroup* accel_group, guint accel_key, GdkModifierType accel_mods)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_remove_accelerator", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkAccelGroup__P(accel_group), accel_group, 2, "gtk_widget_remove_accelerator", "GtkAccelGroup*");
  XEN_ASSERT_TYPE(XEN_guint_P(accel_key), accel_key, 3, "gtk_widget_remove_accelerator", "guint");
  XEN_ASSERT_TYPE(XEN_GdkModifierType_P(accel_mods), accel_mods, 4, "gtk_widget_remove_accelerator", "GdkModifierType");
  return(C_TO_XEN_gboolean(gtk_widget_remove_accelerator(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GtkAccelGroup_(accel_group), 
                                                         XEN_TO_C_guint(accel_key), XEN_TO_C_GdkModifierType(accel_mods))));
}
static XEN gxg_gtk_widget_list_accel_closures(XEN widget)
{
  #define H_gtk_widget_list_accel_closures "GList* gtk_widget_list_accel_closures(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_list_accel_closures", "GtkWidget*");
  return(C_TO_XEN_GList_(gtk_widget_list_accel_closures(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_widget_mnemonic_activate(XEN widget, XEN group_cycling)
{
  #define H_gtk_widget_mnemonic_activate "gboolean gtk_widget_mnemonic_activate(GtkWidget* widget, gboolean group_cycling)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_mnemonic_activate", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(group_cycling), group_cycling, 2, "gtk_widget_mnemonic_activate", "gboolean");
  return(C_TO_XEN_gboolean(gtk_widget_mnemonic_activate(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gboolean(group_cycling))));
}
static XEN gxg_gtk_widget_event(XEN widget, XEN event)
{
  #define H_gtk_widget_event "gboolean gtk_widget_event(GtkWidget* widget, GdkEvent* event)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_event", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GdkEvent__P(event), event, 2, "gtk_widget_event", "GdkEvent*");
  return(C_TO_XEN_gboolean(gtk_widget_event(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GdkEvent_(event))));
}
static XEN gxg_gtk_widget_send_expose(XEN widget, XEN event)
{
  #define H_gtk_widget_send_expose "gint gtk_widget_send_expose(GtkWidget* widget, GdkEvent* event)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_send_expose", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GdkEvent__P(event), event, 2, "gtk_widget_send_expose", "GdkEvent*");
  return(C_TO_XEN_gint(gtk_widget_send_expose(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GdkEvent_(event))));
}
static XEN gxg_gtk_widget_activate(XEN widget)
{
  #define H_gtk_widget_activate "gboolean gtk_widget_activate(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_activate", "GtkWidget*");
  return(C_TO_XEN_gboolean(gtk_widget_activate(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_widget_set_scroll_adjustments(XEN widget, XEN hadjustment, XEN vadjustment)
{
  #define H_gtk_widget_set_scroll_adjustments "gboolean gtk_widget_set_scroll_adjustments(GtkWidget* widget, \
GtkAdjustment* hadjustment, GtkAdjustment* vadjustment)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_set_scroll_adjustments", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(hadjustment) || XEN_FALSE_P(hadjustment), hadjustment, 2, "gtk_widget_set_scroll_adjustments", "GtkAdjustment*");
  XEN_ASSERT_TYPE(XEN_GtkAdjustment__P(vadjustment) || XEN_FALSE_P(vadjustment), vadjustment, 3, "gtk_widget_set_scroll_adjustments", "GtkAdjustment*");
  return(C_TO_XEN_gboolean(gtk_widget_set_scroll_adjustments(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GtkAdjustment_(hadjustment), 
                                                             XEN_TO_C_GtkAdjustment_(vadjustment))));
}
static XEN gxg_gtk_widget_reparent(XEN widget, XEN new_parent)
{
  #define H_gtk_widget_reparent "void gtk_widget_reparent(GtkWidget* widget, GtkWidget* new_parent)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_reparent", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(new_parent), new_parent, 2, "gtk_widget_reparent", "GtkWidget*");
  gtk_widget_reparent(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GtkWidget_(new_parent));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_intersect(XEN widget, XEN area, XEN intersection)
{
  #define H_gtk_widget_intersect "gboolean gtk_widget_intersect(GtkWidget* widget, GdkRectangle* area, \
GdkRectangle* intersection)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_intersect", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(area), area, 2, "gtk_widget_intersect", "GdkRectangle*");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(intersection) || XEN_FALSE_P(intersection), intersection, 3, "gtk_widget_intersect", "GdkRectangle*");
  return(C_TO_XEN_gboolean(gtk_widget_intersect(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GdkRectangle_(area), XEN_TO_C_GdkRectangle_(intersection))));
}
static XEN gxg_gtk_widget_region_intersect(XEN widget, XEN region)
{
  #define H_gtk_widget_region_intersect "GdkRegion* gtk_widget_region_intersect(GtkWidget* widget, GdkRegion* region)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_region_intersect", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GdkRegion__P(region), region, 2, "gtk_widget_region_intersect", "GdkRegion*");
  return(C_TO_XEN_GdkRegion_(gtk_widget_region_intersect(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GdkRegion_(region))));
}
static XEN gxg_gtk_widget_freeze_child_notify(XEN widget)
{
  #define H_gtk_widget_freeze_child_notify "void gtk_widget_freeze_child_notify(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_freeze_child_notify", "GtkWidget*");
  gtk_widget_freeze_child_notify(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_child_notify(XEN widget, XEN child_property)
{
  #define H_gtk_widget_child_notify "void gtk_widget_child_notify(GtkWidget* widget, gchar* child_property)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_child_notify", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(child_property), child_property, 2, "gtk_widget_child_notify", "gchar*");
  gtk_widget_child_notify(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(child_property));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_thaw_child_notify(XEN widget)
{
  #define H_gtk_widget_thaw_child_notify "void gtk_widget_thaw_child_notify(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_thaw_child_notify", "GtkWidget*");
  gtk_widget_thaw_child_notify(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_is_focus(XEN widget)
{
  #define H_gtk_widget_is_focus "gboolean gtk_widget_is_focus(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_is_focus", "GtkWidget*");
  return(C_TO_XEN_gboolean(gtk_widget_is_focus(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_widget_grab_focus(XEN widget)
{
  #define H_gtk_widget_grab_focus "void gtk_widget_grab_focus(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_grab_focus", "GtkWidget*");
  gtk_widget_grab_focus(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_grab_default(XEN widget)
{
  #define H_gtk_widget_grab_default "void gtk_widget_grab_default(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_grab_default", "GtkWidget*");
  gtk_widget_grab_default(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_set_name(XEN widget, XEN name)
{
  #define H_gtk_widget_set_name "void gtk_widget_set_name(GtkWidget* widget, gchar* name)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_set_name", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(name), name, 2, "gtk_widget_set_name", "gchar*");
  gtk_widget_set_name(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(name));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_get_name(XEN widget)
{
  #define H_gtk_widget_get_name "gchar* gtk_widget_get_name(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_get_name", "GtkWidget*");
  return(C_TO_XEN_gchar_(gtk_widget_get_name(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_widget_set_state(XEN widget, XEN state)
{
  #define H_gtk_widget_set_state "void gtk_widget_set_state(GtkWidget* widget, GtkStateType state)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_set_state", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state), state, 2, "gtk_widget_set_state", "GtkStateType");
  gtk_widget_set_state(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GtkStateType(state));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_set_sensitive(XEN widget, XEN sensitive)
{
  #define H_gtk_widget_set_sensitive "void gtk_widget_set_sensitive(GtkWidget* widget, gboolean sensitive)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_set_sensitive", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(sensitive), sensitive, 2, "gtk_widget_set_sensitive", "gboolean");
  gtk_widget_set_sensitive(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gboolean(sensitive));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_set_app_paintable(XEN widget, XEN app_paintable)
{
  #define H_gtk_widget_set_app_paintable "void gtk_widget_set_app_paintable(GtkWidget* widget, gboolean app_paintable)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_set_app_paintable", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(app_paintable), app_paintable, 2, "gtk_widget_set_app_paintable", "gboolean");
  gtk_widget_set_app_paintable(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gboolean(app_paintable));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_set_double_buffered(XEN widget, XEN double_buffered)
{
  #define H_gtk_widget_set_double_buffered "void gtk_widget_set_double_buffered(GtkWidget* widget, gboolean double_buffered)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_set_double_buffered", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(double_buffered), double_buffered, 2, "gtk_widget_set_double_buffered", "gboolean");
  gtk_widget_set_double_buffered(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gboolean(double_buffered));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_set_redraw_on_allocate(XEN widget, XEN redraw_on_allocate)
{
  #define H_gtk_widget_set_redraw_on_allocate "void gtk_widget_set_redraw_on_allocate(GtkWidget* widget, \
gboolean redraw_on_allocate)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_set_redraw_on_allocate", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(redraw_on_allocate), redraw_on_allocate, 2, "gtk_widget_set_redraw_on_allocate", "gboolean");
  gtk_widget_set_redraw_on_allocate(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gboolean(redraw_on_allocate));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_set_parent(XEN widget, XEN parent)
{
  #define H_gtk_widget_set_parent "void gtk_widget_set_parent(GtkWidget* widget, GtkWidget* parent)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_set_parent", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(parent), parent, 2, "gtk_widget_set_parent", "GtkWidget*");
  gtk_widget_set_parent(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GtkWidget_(parent));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_set_parent_window(XEN widget, XEN parent_window)
{
  #define H_gtk_widget_set_parent_window "void gtk_widget_set_parent_window(GtkWidget* widget, GdkWindow* parent_window)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_set_parent_window", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(parent_window), parent_window, 2, "gtk_widget_set_parent_window", "GdkWindow*");
  gtk_widget_set_parent_window(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GdkWindow_(parent_window));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_set_child_visible(XEN widget, XEN is_visible)
{
  #define H_gtk_widget_set_child_visible "void gtk_widget_set_child_visible(GtkWidget* widget, gboolean is_visible)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_set_child_visible", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(is_visible), is_visible, 2, "gtk_widget_set_child_visible", "gboolean");
  gtk_widget_set_child_visible(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gboolean(is_visible));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_set_accel_path(XEN widget, XEN accel_path, XEN accel_group)
{
  #define H_gtk_widget_set_accel_path "void gtk_widget_set_accel_path(GtkWidget* widget, gchar* accel_path, \
GtkAccelGroup* accel_group)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_set_accel_path", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(accel_path), accel_path, 2, "gtk_widget_set_accel_path", "gchar*");
  XEN_ASSERT_TYPE(XEN_GtkAccelGroup__P(accel_group), accel_group, 3, "gtk_widget_set_accel_path", "GtkAccelGroup*");
  gtk_widget_set_accel_path(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(accel_path), XEN_TO_C_GtkAccelGroup_(accel_group));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_get_child_visible(XEN widget)
{
  #define H_gtk_widget_get_child_visible "gboolean gtk_widget_get_child_visible(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_get_child_visible", "GtkWidget*");
  return(C_TO_XEN_gboolean(gtk_widget_get_child_visible(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_widget_get_parent(XEN widget)
{
  #define H_gtk_widget_get_parent "GtkWidget* gtk_widget_get_parent(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_get_parent", "GtkWidget*");
  return(C_TO_XEN_GtkWidget_(gtk_widget_get_parent(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_widget_get_parent_window(XEN widget)
{
  #define H_gtk_widget_get_parent_window "GdkWindow* gtk_widget_get_parent_window(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_get_parent_window", "GtkWidget*");
  return(C_TO_XEN_GdkWindow_(gtk_widget_get_parent_window(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_widget_child_focus(XEN widget, XEN direction)
{
  #define H_gtk_widget_child_focus "gboolean gtk_widget_child_focus(GtkWidget* widget, GtkDirectionType direction)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_child_focus", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkDirectionType_P(direction), direction, 2, "gtk_widget_child_focus", "GtkDirectionType");
  return(C_TO_XEN_gboolean(gtk_widget_child_focus(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GtkDirectionType(direction))));
}
static XEN gxg_gtk_widget_set_size_request(XEN widget, XEN width, XEN height)
{
  #define H_gtk_widget_set_size_request "void gtk_widget_set_size_request(GtkWidget* widget, gint width, \
gint height)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_set_size_request", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 2, "gtk_widget_set_size_request", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 3, "gtk_widget_set_size_request", "gint");
  gtk_widget_set_size_request(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gint(width), XEN_TO_C_gint(height));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_get_size_request(XEN widget, XEN width, XEN height)
{
  #define H_gtk_widget_get_size_request "void gtk_widget_get_size_request(GtkWidget* widget, gint* [width], \
gint* [height])"
  gint ref_width;
  gint ref_height;
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_get_size_request", "GtkWidget*");
  gtk_widget_get_size_request(XEN_TO_C_GtkWidget_(widget), &ref_width, &ref_height);
  return(XEN_LIST_2(C_TO_XEN_gint(ref_width), C_TO_XEN_gint(ref_height)));
}
static XEN gxg_gtk_widget_set_events(XEN widget, XEN events)
{
  #define H_gtk_widget_set_events "void gtk_widget_set_events(GtkWidget* widget, gint events)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_set_events", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gint_P(events), events, 2, "gtk_widget_set_events", "gint");
  gtk_widget_set_events(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gint(events));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_add_events(XEN widget, XEN events)
{
  #define H_gtk_widget_add_events "void gtk_widget_add_events(GtkWidget* widget, gint events)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_add_events", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gint_P(events), events, 2, "gtk_widget_add_events", "gint");
  gtk_widget_add_events(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gint(events));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_set_extension_events(XEN widget, XEN mode)
{
  #define H_gtk_widget_set_extension_events "void gtk_widget_set_extension_events(GtkWidget* widget, \
GdkExtensionMode mode)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_set_extension_events", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GdkExtensionMode_P(mode), mode, 2, "gtk_widget_set_extension_events", "GdkExtensionMode");
  gtk_widget_set_extension_events(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GdkExtensionMode(mode));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_get_extension_events(XEN widget)
{
  #define H_gtk_widget_get_extension_events "GdkExtensionMode gtk_widget_get_extension_events(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_get_extension_events", "GtkWidget*");
  return(C_TO_XEN_GdkExtensionMode(gtk_widget_get_extension_events(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_widget_get_toplevel(XEN widget)
{
  #define H_gtk_widget_get_toplevel "GtkWidget* gtk_widget_get_toplevel(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_get_toplevel", "GtkWidget*");
  return(C_TO_XEN_GtkWidget_(gtk_widget_get_toplevel(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_widget_get_ancestor(XEN widget, XEN widget_type)
{
  #define H_gtk_widget_get_ancestor "GtkWidget* gtk_widget_get_ancestor(GtkWidget* widget, GtkType widget_type)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_get_ancestor", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkType_P(widget_type), widget_type, 2, "gtk_widget_get_ancestor", "GtkType");
  return(C_TO_XEN_GtkWidget_(gtk_widget_get_ancestor(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GtkType(widget_type))));
}
static XEN gxg_gtk_widget_get_colormap(XEN widget)
{
  #define H_gtk_widget_get_colormap "GdkColormap* gtk_widget_get_colormap(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_get_colormap", "GtkWidget*");
  return(C_TO_XEN_GdkColormap_(gtk_widget_get_colormap(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_widget_get_visual(XEN widget)
{
  #define H_gtk_widget_get_visual "GdkVisual* gtk_widget_get_visual(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_get_visual", "GtkWidget*");
  return(C_TO_XEN_GdkVisual_(gtk_widget_get_visual(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_widget_get_accessible(XEN widget)
{
  #define H_gtk_widget_get_accessible "AtkObject* gtk_widget_get_accessible(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_get_accessible", "GtkWidget*");
  return(C_TO_XEN_AtkObject_(gtk_widget_get_accessible(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_widget_set_colormap(XEN widget, XEN colormap)
{
  #define H_gtk_widget_set_colormap "void gtk_widget_set_colormap(GtkWidget* widget, GdkColormap* colormap)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_set_colormap", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GdkColormap__P(colormap), colormap, 2, "gtk_widget_set_colormap", "GdkColormap*");
  gtk_widget_set_colormap(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GdkColormap_(colormap));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_get_events(XEN widget)
{
  #define H_gtk_widget_get_events "gint gtk_widget_get_events(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_get_events", "GtkWidget*");
  return(C_TO_XEN_gint(gtk_widget_get_events(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_widget_get_pointer(XEN widget, XEN x, XEN y)
{
  #define H_gtk_widget_get_pointer "void gtk_widget_get_pointer(GtkWidget* widget, gint* [x], gint* [y])"
  gint ref_x;
  gint ref_y;
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_get_pointer", "GtkWidget*");
  gtk_widget_get_pointer(XEN_TO_C_GtkWidget_(widget), &ref_x, &ref_y);
  return(XEN_LIST_2(C_TO_XEN_gint(ref_x), C_TO_XEN_gint(ref_y)));
}
static XEN gxg_gtk_widget_is_ancestor(XEN widget, XEN ancestor)
{
  #define H_gtk_widget_is_ancestor "gboolean gtk_widget_is_ancestor(GtkWidget* widget, GtkWidget* ancestor)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_is_ancestor", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(ancestor), ancestor, 2, "gtk_widget_is_ancestor", "GtkWidget*");
  return(C_TO_XEN_gboolean(gtk_widget_is_ancestor(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GtkWidget_(ancestor))));
}
static XEN gxg_gtk_widget_translate_coordinates(XEN src_widget, XEN dest_widget, XEN src_x, XEN src_y, XEN dest_x, XEN dest_y)
{
  #define H_gtk_widget_translate_coordinates "gboolean gtk_widget_translate_coordinates(GtkWidget* src_widget, \
GtkWidget* dest_widget, gint src_x, gint src_y, gint* [dest_x], gint* [dest_y])"
  gint ref_dest_x;
  gint ref_dest_y;
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(src_widget), src_widget, 1, "gtk_widget_translate_coordinates", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(dest_widget), dest_widget, 2, "gtk_widget_translate_coordinates", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gint_P(src_x), src_x, 3, "gtk_widget_translate_coordinates", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(src_y), src_y, 4, "gtk_widget_translate_coordinates", "gint");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gtk_widget_translate_coordinates(XEN_TO_C_GtkWidget_(src_widget), XEN_TO_C_GtkWidget_(dest_widget), 
                                                                XEN_TO_C_gint(src_x), XEN_TO_C_gint(src_y), &ref_dest_x, 
                                                                &ref_dest_y));
    return(XEN_LIST_3(result, C_TO_XEN_gint(ref_dest_x), C_TO_XEN_gint(ref_dest_y)));
   }
}
static XEN gxg_gtk_widget_hide_on_delete(XEN widget)
{
  #define H_gtk_widget_hide_on_delete "gboolean gtk_widget_hide_on_delete(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_hide_on_delete", "GtkWidget*");
  return(C_TO_XEN_gboolean(gtk_widget_hide_on_delete(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_widget_set_style(XEN widget, XEN style)
{
  #define H_gtk_widget_set_style "void gtk_widget_set_style(GtkWidget* widget, GtkStyle* style)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_set_style", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkStyle__P(style), style, 2, "gtk_widget_set_style", "GtkStyle*");
  gtk_widget_set_style(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GtkStyle_(style));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_ensure_style(XEN widget)
{
  #define H_gtk_widget_ensure_style "void gtk_widget_ensure_style(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_ensure_style", "GtkWidget*");
  gtk_widget_ensure_style(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_get_style(XEN widget)
{
  #define H_gtk_widget_get_style "GtkStyle* gtk_widget_get_style(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_get_style", "GtkWidget*");
  return(C_TO_XEN_GtkStyle_(gtk_widget_get_style(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_widget_modify_style(XEN widget, XEN style)
{
  #define H_gtk_widget_modify_style "void gtk_widget_modify_style(GtkWidget* widget, GtkRcStyle* style)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_modify_style", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkRcStyle__P(style), style, 2, "gtk_widget_modify_style", "GtkRcStyle*");
  gtk_widget_modify_style(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GtkRcStyle_(style));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_get_modifier_style(XEN widget)
{
  #define H_gtk_widget_get_modifier_style "GtkRcStyle* gtk_widget_get_modifier_style(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_get_modifier_style", "GtkWidget*");
  return(C_TO_XEN_GtkRcStyle_(gtk_widget_get_modifier_style(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_widget_modify_fg(XEN widget, XEN state, XEN color)
{
  #define H_gtk_widget_modify_fg "void gtk_widget_modify_fg(GtkWidget* widget, GtkStateType state, GdkColor* color)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_modify_fg", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state), state, 2, "gtk_widget_modify_fg", "GtkStateType");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(color), color, 3, "gtk_widget_modify_fg", "GdkColor*");
  gtk_widget_modify_fg(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GtkStateType(state), XEN_TO_C_GdkColor_(color));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_modify_bg(XEN widget, XEN state, XEN color)
{
  #define H_gtk_widget_modify_bg "void gtk_widget_modify_bg(GtkWidget* widget, GtkStateType state, GdkColor* color)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_modify_bg", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state), state, 2, "gtk_widget_modify_bg", "GtkStateType");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(color), color, 3, "gtk_widget_modify_bg", "GdkColor*");
  gtk_widget_modify_bg(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GtkStateType(state), XEN_TO_C_GdkColor_(color));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_modify_text(XEN widget, XEN state, XEN color)
{
  #define H_gtk_widget_modify_text "void gtk_widget_modify_text(GtkWidget* widget, GtkStateType state, \
GdkColor* color)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_modify_text", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state), state, 2, "gtk_widget_modify_text", "GtkStateType");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(color), color, 3, "gtk_widget_modify_text", "GdkColor*");
  gtk_widget_modify_text(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GtkStateType(state), XEN_TO_C_GdkColor_(color));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_modify_base(XEN widget, XEN state, XEN color)
{
  #define H_gtk_widget_modify_base "void gtk_widget_modify_base(GtkWidget* widget, GtkStateType state, \
GdkColor* color)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_modify_base", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkStateType_P(state), state, 2, "gtk_widget_modify_base", "GtkStateType");
  XEN_ASSERT_TYPE(XEN_GdkColor__P(color), color, 3, "gtk_widget_modify_base", "GdkColor*");
  gtk_widget_modify_base(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GtkStateType(state), XEN_TO_C_GdkColor_(color));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_modify_font(XEN widget, XEN font_desc)
{
  #define H_gtk_widget_modify_font "void gtk_widget_modify_font(GtkWidget* widget, PangoFontDescription* font_desc)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_modify_font", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(font_desc), font_desc, 2, "gtk_widget_modify_font", "PangoFontDescription*");
  gtk_widget_modify_font(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_PangoFontDescription_(font_desc));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_create_pango_context(XEN widget)
{
  #define H_gtk_widget_create_pango_context "PangoContext* gtk_widget_create_pango_context(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_create_pango_context", "GtkWidget*");
  return(C_TO_XEN_PangoContext_(gtk_widget_create_pango_context(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_widget_get_pango_context(XEN widget)
{
  #define H_gtk_widget_get_pango_context "PangoContext* gtk_widget_get_pango_context(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_get_pango_context", "GtkWidget*");
  return(C_TO_XEN_PangoContext_(gtk_widget_get_pango_context(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_widget_create_pango_layout(XEN widget, XEN text)
{
  #define H_gtk_widget_create_pango_layout "PangoLayout* gtk_widget_create_pango_layout(GtkWidget* widget, \
gchar* text)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_create_pango_layout", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(text), text, 2, "gtk_widget_create_pango_layout", "gchar*");
  return(C_TO_XEN_PangoLayout_(gtk_widget_create_pango_layout(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(text))));
}
static XEN gxg_gtk_widget_render_icon(XEN widget, XEN stock_id, XEN size, XEN detail)
{
  #define H_gtk_widget_render_icon "GdkPixbuf* gtk_widget_render_icon(GtkWidget* widget, gchar* stock_id, \
GtkIconSize size, gchar* detail)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_render_icon", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(stock_id), stock_id, 2, "gtk_widget_render_icon", "gchar*");
  XEN_ASSERT_TYPE(XEN_GtkIconSize_P(size), size, 3, "gtk_widget_render_icon", "GtkIconSize");
  XEN_ASSERT_TYPE(XEN_gchar__P(detail), detail, 4, "gtk_widget_render_icon", "gchar*");
  return(C_TO_XEN_GdkPixbuf_(gtk_widget_render_icon(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(stock_id), XEN_TO_C_GtkIconSize(size), 
                                                    XEN_TO_C_gchar_(detail))));
}
static XEN gxg_gtk_widget_set_composite_name(XEN widget, XEN name)
{
  #define H_gtk_widget_set_composite_name "void gtk_widget_set_composite_name(GtkWidget* widget, gchar* name)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_set_composite_name", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_gchar__P(name), name, 2, "gtk_widget_set_composite_name", "gchar*");
  gtk_widget_set_composite_name(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_gchar_(name));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_get_composite_name(XEN widget)
{
  #define H_gtk_widget_get_composite_name "gchar* gtk_widget_get_composite_name(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_get_composite_name", "GtkWidget*");
  return(C_TO_XEN_gchar_(gtk_widget_get_composite_name(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_widget_reset_rc_styles(XEN widget)
{
  #define H_gtk_widget_reset_rc_styles "void gtk_widget_reset_rc_styles(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_reset_rc_styles", "GtkWidget*");
  gtk_widget_reset_rc_styles(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_push_colormap(XEN cmap)
{
  #define H_gtk_widget_push_colormap "void gtk_widget_push_colormap(GdkColormap* cmap)"
  XEN_ASSERT_TYPE(XEN_GdkColormap__P(cmap), cmap, 1, "gtk_widget_push_colormap", "GdkColormap*");
  gtk_widget_push_colormap(XEN_TO_C_GdkColormap_(cmap));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_push_composite_child(void)
{
  #define H_gtk_widget_push_composite_child "void gtk_widget_push_composite_child( void)"
  gtk_widget_push_composite_child();
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_pop_composite_child(void)
{
  #define H_gtk_widget_pop_composite_child "void gtk_widget_pop_composite_child( void)"
  gtk_widget_pop_composite_child();
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_pop_colormap(void)
{
  #define H_gtk_widget_pop_colormap "void gtk_widget_pop_colormap( void)"
  gtk_widget_pop_colormap();
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_set_default_colormap(XEN colormap)
{
  #define H_gtk_widget_set_default_colormap "void gtk_widget_set_default_colormap(GdkColormap* colormap)"
  XEN_ASSERT_TYPE(XEN_GdkColormap__P(colormap), colormap, 1, "gtk_widget_set_default_colormap", "GdkColormap*");
  gtk_widget_set_default_colormap(XEN_TO_C_GdkColormap_(colormap));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_get_default_style(void)
{
  #define H_gtk_widget_get_default_style "GtkStyle* gtk_widget_get_default_style( void)"
  return(C_TO_XEN_GtkStyle_(gtk_widget_get_default_style()));
}
static XEN gxg_gtk_widget_get_default_colormap(void)
{
  #define H_gtk_widget_get_default_colormap "GdkColormap* gtk_widget_get_default_colormap( void)"
  return(C_TO_XEN_GdkColormap_(gtk_widget_get_default_colormap()));
}
static XEN gxg_gtk_widget_get_default_visual(void)
{
  #define H_gtk_widget_get_default_visual "GdkVisual* gtk_widget_get_default_visual( void)"
  return(C_TO_XEN_GdkVisual_(gtk_widget_get_default_visual()));
}
static XEN gxg_gtk_widget_set_direction(XEN widget, XEN dir)
{
  #define H_gtk_widget_set_direction "void gtk_widget_set_direction(GtkWidget* widget, GtkTextDirection dir)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_set_direction", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GtkTextDirection_P(dir), dir, 2, "gtk_widget_set_direction", "GtkTextDirection");
  gtk_widget_set_direction(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GtkTextDirection(dir));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_get_direction(XEN widget)
{
  #define H_gtk_widget_get_direction "GtkTextDirection gtk_widget_get_direction(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_get_direction", "GtkWidget*");
  return(C_TO_XEN_GtkTextDirection(gtk_widget_get_direction(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_widget_set_default_direction(XEN dir)
{
  #define H_gtk_widget_set_default_direction "void gtk_widget_set_default_direction(GtkTextDirection dir)"
  XEN_ASSERT_TYPE(XEN_GtkTextDirection_P(dir), dir, 1, "gtk_widget_set_default_direction", "GtkTextDirection");
  gtk_widget_set_default_direction(XEN_TO_C_GtkTextDirection(dir));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_get_default_direction(void)
{
  #define H_gtk_widget_get_default_direction "GtkTextDirection gtk_widget_get_default_direction( void)"
  return(C_TO_XEN_GtkTextDirection(gtk_widget_get_default_direction()));
}
static XEN gxg_gtk_widget_shape_combine_mask(XEN widget, XEN shape_mask, XEN offset_x, XEN offset_y)
{
  #define H_gtk_widget_shape_combine_mask "void gtk_widget_shape_combine_mask(GtkWidget* widget, GdkBitmap* shape_mask, \
gint offset_x, gint offset_y)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_shape_combine_mask", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GdkBitmap__P(shape_mask) || XEN_FALSE_P(shape_mask), shape_mask, 2, "gtk_widget_shape_combine_mask", "GdkBitmap*");
  XEN_ASSERT_TYPE(XEN_gint_P(offset_x), offset_x, 3, "gtk_widget_shape_combine_mask", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(offset_y), offset_y, 4, "gtk_widget_shape_combine_mask", "gint");
  gtk_widget_shape_combine_mask(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GdkBitmap_(shape_mask), XEN_TO_C_gint(offset_x), XEN_TO_C_gint(offset_y));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_reset_shapes(XEN widget)
{
  #define H_gtk_widget_reset_shapes "void gtk_widget_reset_shapes(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_reset_shapes", "GtkWidget*");
  gtk_widget_reset_shapes(XEN_TO_C_GtkWidget_(widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_widget_path(XEN widget, XEN path_length, XEN path, XEN path_reversed)
{
  #define H_gtk_widget_path "void gtk_widget_path(GtkWidget* widget, guint* path_length, gchar** [path], \
gchar** [path_reversed])"
  gchar* ref_path = NULL;
  gchar* ref_path_reversed = NULL;
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_path", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_guint__P(path_length), path_length, 2, "gtk_widget_path", "guint*");
  gtk_widget_path(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_guint_(path_length), &ref_path, &ref_path_reversed);
  return(XEN_LIST_2(C_TO_XEN_gchar_(ref_path), C_TO_XEN_gchar_(ref_path_reversed)));
}
static XEN gxg_gtk_widget_class_path(XEN widget, XEN path_length, XEN path, XEN path_reversed)
{
  #define H_gtk_widget_class_path "void gtk_widget_class_path(GtkWidget* widget, guint* path_length, \
gchar** [path], gchar** [path_reversed])"
  gchar* ref_path = NULL;
  gchar* ref_path_reversed = NULL;
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_class_path", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_guint__P(path_length), path_length, 2, "gtk_widget_class_path", "guint*");
  gtk_widget_class_path(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_guint_(path_length), &ref_path, &ref_path_reversed);
  return(XEN_LIST_2(C_TO_XEN_gchar_(ref_path), C_TO_XEN_gchar_(ref_path_reversed)));
}
static XEN gxg_gtk_requisition_copy(XEN requisition)
{
  #define H_gtk_requisition_copy "GtkRequisition* gtk_requisition_copy(GtkRequisition* requisition)"
  XEN_ASSERT_TYPE(XEN_GtkRequisition__P(requisition), requisition, 1, "gtk_requisition_copy", "GtkRequisition*");
  return(C_TO_XEN_GtkRequisition_(gtk_requisition_copy(XEN_TO_C_GtkRequisition_(requisition))));
}
static XEN gxg_gtk_requisition_free(XEN requisition)
{
  #define H_gtk_requisition_free "void gtk_requisition_free(GtkRequisition* requisition)"
  XEN_ASSERT_TYPE(XEN_GtkRequisition__P(requisition), requisition, 1, "gtk_requisition_free", "GtkRequisition*");
  gtk_requisition_free(XEN_TO_C_GtkRequisition_(requisition));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_get_type(void)
{
  #define H_gtk_window_get_type "GtkType gtk_window_get_type( void)"
  return(C_TO_XEN_GtkType(gtk_window_get_type()));
}
static XEN gxg_gtk_window_new(XEN type)
{
  #define H_gtk_window_new "GtkWidget* gtk_window_new(GtkWindowType type)"
  XEN_ASSERT_TYPE(XEN_GtkWindowType_P(type), type, 1, "gtk_window_new", "GtkWindowType");
  return(C_TO_XEN_GtkWidget_(gtk_window_new(XEN_TO_C_GtkWindowType(type))));
}
static XEN gxg_gtk_window_set_title(XEN window, XEN title)
{
  #define H_gtk_window_set_title "void gtk_window_set_title(GtkWindow* window, gchar* title)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_set_title", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_gchar__P(title), title, 2, "gtk_window_set_title", "gchar*");
  gtk_window_set_title(XEN_TO_C_GtkWindow_(window), XEN_TO_C_gchar_(title));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_get_title(XEN window)
{
  #define H_gtk_window_get_title "gchar* gtk_window_get_title(GtkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_get_title", "GtkWindow*");
  return(C_TO_XEN_gchar_(gtk_window_get_title(XEN_TO_C_GtkWindow_(window))));
}
static XEN gxg_gtk_window_set_wmclass(XEN window, XEN wmclass_name, XEN wmclass_class)
{
  #define H_gtk_window_set_wmclass "void gtk_window_set_wmclass(GtkWindow* window, gchar* wmclass_name, \
gchar* wmclass_class)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_set_wmclass", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_gchar__P(wmclass_name), wmclass_name, 2, "gtk_window_set_wmclass", "gchar*");
  XEN_ASSERT_TYPE(XEN_gchar__P(wmclass_class), wmclass_class, 3, "gtk_window_set_wmclass", "gchar*");
  gtk_window_set_wmclass(XEN_TO_C_GtkWindow_(window), XEN_TO_C_gchar_(wmclass_name), XEN_TO_C_gchar_(wmclass_class));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_set_role(XEN window, XEN role)
{
  #define H_gtk_window_set_role "void gtk_window_set_role(GtkWindow* window, gchar* role)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_set_role", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_gchar__P(role), role, 2, "gtk_window_set_role", "gchar*");
  gtk_window_set_role(XEN_TO_C_GtkWindow_(window), XEN_TO_C_gchar_(role));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_get_role(XEN window)
{
  #define H_gtk_window_get_role "gchar* gtk_window_get_role(GtkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_get_role", "GtkWindow*");
  return(C_TO_XEN_gchar_(gtk_window_get_role(XEN_TO_C_GtkWindow_(window))));
}
static XEN gxg_gtk_window_add_accel_group(XEN window, XEN accel_group)
{
  #define H_gtk_window_add_accel_group "void gtk_window_add_accel_group(GtkWindow* window, GtkAccelGroup* accel_group)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_add_accel_group", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkAccelGroup__P(accel_group), accel_group, 2, "gtk_window_add_accel_group", "GtkAccelGroup*");
  gtk_window_add_accel_group(XEN_TO_C_GtkWindow_(window), XEN_TO_C_GtkAccelGroup_(accel_group));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_remove_accel_group(XEN window, XEN accel_group)
{
  #define H_gtk_window_remove_accel_group "void gtk_window_remove_accel_group(GtkWindow* window, GtkAccelGroup* accel_group)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_remove_accel_group", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkAccelGroup__P(accel_group), accel_group, 2, "gtk_window_remove_accel_group", "GtkAccelGroup*");
  gtk_window_remove_accel_group(XEN_TO_C_GtkWindow_(window), XEN_TO_C_GtkAccelGroup_(accel_group));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_set_position(XEN window, XEN position)
{
  #define H_gtk_window_set_position "void gtk_window_set_position(GtkWindow* window, GtkWindowPosition position)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_set_position", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkWindowPosition_P(position), position, 2, "gtk_window_set_position", "GtkWindowPosition");
  gtk_window_set_position(XEN_TO_C_GtkWindow_(window), XEN_TO_C_GtkWindowPosition(position));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_activate_focus(XEN window)
{
  #define H_gtk_window_activate_focus "gboolean gtk_window_activate_focus(GtkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_activate_focus", "GtkWindow*");
  return(C_TO_XEN_gboolean(gtk_window_activate_focus(XEN_TO_C_GtkWindow_(window))));
}
static XEN gxg_gtk_window_set_focus(XEN window, XEN focus)
{
  #define H_gtk_window_set_focus "void gtk_window_set_focus(GtkWindow* window, GtkWidget* focus)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_set_focus", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(focus) || XEN_FALSE_P(focus), focus, 2, "gtk_window_set_focus", "GtkWidget*");
  gtk_window_set_focus(XEN_TO_C_GtkWindow_(window), XEN_TO_C_GtkWidget_(focus));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_get_focus(XEN window)
{
  #define H_gtk_window_get_focus "GtkWidget* gtk_window_get_focus(GtkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_get_focus", "GtkWindow*");
  return(C_TO_XEN_GtkWidget_(gtk_window_get_focus(XEN_TO_C_GtkWindow_(window))));
}
static XEN gxg_gtk_window_set_default(XEN window, XEN default_widget)
{
  #define H_gtk_window_set_default "void gtk_window_set_default(GtkWindow* window, GtkWidget* default_widget)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_set_default", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(default_widget) || XEN_FALSE_P(default_widget), default_widget, 2, "gtk_window_set_default", "GtkWidget*");
  gtk_window_set_default(XEN_TO_C_GtkWindow_(window), XEN_TO_C_GtkWidget_(default_widget));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_activate_default(XEN window)
{
  #define H_gtk_window_activate_default "gboolean gtk_window_activate_default(GtkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_activate_default", "GtkWindow*");
  return(C_TO_XEN_gboolean(gtk_window_activate_default(XEN_TO_C_GtkWindow_(window))));
}
static XEN gxg_gtk_window_set_transient_for(XEN window, XEN parent)
{
  #define H_gtk_window_set_transient_for "void gtk_window_set_transient_for(GtkWindow* window, GtkWindow* parent)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_set_transient_for", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(parent), parent, 2, "gtk_window_set_transient_for", "GtkWindow*");
  gtk_window_set_transient_for(XEN_TO_C_GtkWindow_(window), XEN_TO_C_GtkWindow_(parent));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_get_transient_for(XEN window)
{
  #define H_gtk_window_get_transient_for "GtkWindow* gtk_window_get_transient_for(GtkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_get_transient_for", "GtkWindow*");
  return(C_TO_XEN_GtkWindow_(gtk_window_get_transient_for(XEN_TO_C_GtkWindow_(window))));
}
static XEN gxg_gtk_window_set_type_hint(XEN window, XEN hint)
{
  #define H_gtk_window_set_type_hint "void gtk_window_set_type_hint(GtkWindow* window, GdkWindowTypeHint hint)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_set_type_hint", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkWindowTypeHint_P(hint), hint, 2, "gtk_window_set_type_hint", "GdkWindowTypeHint");
  gtk_window_set_type_hint(XEN_TO_C_GtkWindow_(window), XEN_TO_C_GdkWindowTypeHint(hint));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_get_type_hint(XEN window)
{
  #define H_gtk_window_get_type_hint "GdkWindowTypeHint gtk_window_get_type_hint(GtkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_get_type_hint", "GtkWindow*");
  return(C_TO_XEN_GdkWindowTypeHint(gtk_window_get_type_hint(XEN_TO_C_GtkWindow_(window))));
}
static XEN gxg_gtk_window_set_destroy_with_parent(XEN window, XEN setting)
{
  #define H_gtk_window_set_destroy_with_parent "void gtk_window_set_destroy_with_parent(GtkWindow* window, \
gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_set_destroy_with_parent", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gtk_window_set_destroy_with_parent", "gboolean");
  gtk_window_set_destroy_with_parent(XEN_TO_C_GtkWindow_(window), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_get_destroy_with_parent(XEN window)
{
  #define H_gtk_window_get_destroy_with_parent "gboolean gtk_window_get_destroy_with_parent(GtkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_get_destroy_with_parent", "GtkWindow*");
  return(C_TO_XEN_gboolean(gtk_window_get_destroy_with_parent(XEN_TO_C_GtkWindow_(window))));
}
static XEN gxg_gtk_window_set_resizable(XEN window, XEN resizable)
{
  #define H_gtk_window_set_resizable "void gtk_window_set_resizable(GtkWindow* window, gboolean resizable)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_set_resizable", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(resizable), resizable, 2, "gtk_window_set_resizable", "gboolean");
  gtk_window_set_resizable(XEN_TO_C_GtkWindow_(window), XEN_TO_C_gboolean(resizable));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_get_resizable(XEN window)
{
  #define H_gtk_window_get_resizable "gboolean gtk_window_get_resizable(GtkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_get_resizable", "GtkWindow*");
  return(C_TO_XEN_gboolean(gtk_window_get_resizable(XEN_TO_C_GtkWindow_(window))));
}
static XEN gxg_gtk_window_set_gravity(XEN window, XEN gravity)
{
  #define H_gtk_window_set_gravity "void gtk_window_set_gravity(GtkWindow* window, GdkGravity gravity)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_set_gravity", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkGravity_P(gravity), gravity, 2, "gtk_window_set_gravity", "GdkGravity");
  gtk_window_set_gravity(XEN_TO_C_GtkWindow_(window), XEN_TO_C_GdkGravity(gravity));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_get_gravity(XEN window)
{
  #define H_gtk_window_get_gravity "GdkGravity gtk_window_get_gravity(GtkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_get_gravity", "GtkWindow*");
  return(C_TO_XEN_GdkGravity(gtk_window_get_gravity(XEN_TO_C_GtkWindow_(window))));
}
static XEN gxg_gtk_window_set_geometry_hints(XEN window, XEN geometry_widget, XEN geometry, XEN geom_mask)
{
  #define H_gtk_window_set_geometry_hints "void gtk_window_set_geometry_hints(GtkWindow* window, GtkWidget* geometry_widget, \
GdkGeometry* geometry, GdkWindowHints geom_mask)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_set_geometry_hints", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(geometry_widget), geometry_widget, 2, "gtk_window_set_geometry_hints", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GdkGeometry__P(geometry), geometry, 3, "gtk_window_set_geometry_hints", "GdkGeometry*");
  XEN_ASSERT_TYPE(XEN_GdkWindowHints_P(geom_mask), geom_mask, 4, "gtk_window_set_geometry_hints", "GdkWindowHints");
  gtk_window_set_geometry_hints(XEN_TO_C_GtkWindow_(window), XEN_TO_C_GtkWidget_(geometry_widget), XEN_TO_C_GdkGeometry_(geometry), 
                                XEN_TO_C_GdkWindowHints(geom_mask));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_set_has_frame(XEN window, XEN setting)
{
  #define H_gtk_window_set_has_frame "void gtk_window_set_has_frame(GtkWindow* window, gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_set_has_frame", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gtk_window_set_has_frame", "gboolean");
  gtk_window_set_has_frame(XEN_TO_C_GtkWindow_(window), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_get_has_frame(XEN window)
{
  #define H_gtk_window_get_has_frame "gboolean gtk_window_get_has_frame(GtkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_get_has_frame", "GtkWindow*");
  return(C_TO_XEN_gboolean(gtk_window_get_has_frame(XEN_TO_C_GtkWindow_(window))));
}
static XEN gxg_gtk_window_set_frame_dimensions(XEN window, XEN left, XEN top, XEN right, XEN bottom)
{
  #define H_gtk_window_set_frame_dimensions "void gtk_window_set_frame_dimensions(GtkWindow* window, \
gint left, gint top, gint right, gint bottom)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_set_frame_dimensions", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_gint_P(left), left, 2, "gtk_window_set_frame_dimensions", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(top), top, 3, "gtk_window_set_frame_dimensions", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(right), right, 4, "gtk_window_set_frame_dimensions", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(bottom), bottom, 5, "gtk_window_set_frame_dimensions", "gint");
  gtk_window_set_frame_dimensions(XEN_TO_C_GtkWindow_(window), XEN_TO_C_gint(left), XEN_TO_C_gint(top), XEN_TO_C_gint(right), 
                                  XEN_TO_C_gint(bottom));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_get_frame_dimensions(XEN window, XEN left, XEN top, XEN right, XEN bottom)
{
  #define H_gtk_window_get_frame_dimensions "void gtk_window_get_frame_dimensions(GtkWindow* window, \
gint* [left], gint* [top], gint* [right], gint* [bottom])"
  gint ref_left;
  gint ref_top;
  gint ref_right;
  gint ref_bottom;
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_get_frame_dimensions", "GtkWindow*");
  gtk_window_get_frame_dimensions(XEN_TO_C_GtkWindow_(window), &ref_left, &ref_top, &ref_right, &ref_bottom);
  return(XEN_LIST_4(C_TO_XEN_gint(ref_left), C_TO_XEN_gint(ref_top), C_TO_XEN_gint(ref_right), C_TO_XEN_gint(ref_bottom)));
}
static XEN gxg_gtk_window_set_decorated(XEN window, XEN setting)
{
  #define H_gtk_window_set_decorated "void gtk_window_set_decorated(GtkWindow* window, gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_set_decorated", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gtk_window_set_decorated", "gboolean");
  gtk_window_set_decorated(XEN_TO_C_GtkWindow_(window), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_get_decorated(XEN window)
{
  #define H_gtk_window_get_decorated "gboolean gtk_window_get_decorated(GtkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_get_decorated", "GtkWindow*");
  return(C_TO_XEN_gboolean(gtk_window_get_decorated(XEN_TO_C_GtkWindow_(window))));
}
static XEN gxg_gtk_window_set_icon_list(XEN window, XEN list)
{
  #define H_gtk_window_set_icon_list "void gtk_window_set_icon_list(GtkWindow* window, GList* list)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_set_icon_list", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_GList__P(list), list, 2, "gtk_window_set_icon_list", "GList*");
  gtk_window_set_icon_list(XEN_TO_C_GtkWindow_(window), XEN_TO_C_GList_(list));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_get_icon_list(XEN window)
{
  #define H_gtk_window_get_icon_list "GList* gtk_window_get_icon_list(GtkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_get_icon_list", "GtkWindow*");
  return(C_TO_XEN_GList_(gtk_window_get_icon_list(XEN_TO_C_GtkWindow_(window))));
}
static XEN gxg_gtk_window_set_icon(XEN window, XEN icon)
{
  #define H_gtk_window_set_icon "void gtk_window_set_icon(GtkWindow* window, GdkPixbuf* icon)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_set_icon", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(icon) || XEN_FALSE_P(icon), icon, 2, "gtk_window_set_icon", "GdkPixbuf*");
  gtk_window_set_icon(XEN_TO_C_GtkWindow_(window), XEN_TO_C_GdkPixbuf_(icon));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_get_icon(XEN window)
{
  #define H_gtk_window_get_icon "GdkPixbuf* gtk_window_get_icon(GtkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_get_icon", "GtkWindow*");
  return(C_TO_XEN_GdkPixbuf_(gtk_window_get_icon(XEN_TO_C_GtkWindow_(window))));
}
static XEN gxg_gtk_window_set_default_icon_list(XEN list)
{
  #define H_gtk_window_set_default_icon_list "void gtk_window_set_default_icon_list(GList* list)"
  XEN_ASSERT_TYPE(XEN_GList__P(list), list, 1, "gtk_window_set_default_icon_list", "GList*");
  gtk_window_set_default_icon_list(XEN_TO_C_GList_(list));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_get_default_icon_list(void)
{
  #define H_gtk_window_get_default_icon_list "GList* gtk_window_get_default_icon_list( void)"
  return(C_TO_XEN_GList_(gtk_window_get_default_icon_list()));
}
static XEN gxg_gtk_window_set_modal(XEN window, XEN modal)
{
  #define H_gtk_window_set_modal "void gtk_window_set_modal(GtkWindow* window, gboolean modal)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_set_modal", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(modal), modal, 2, "gtk_window_set_modal", "gboolean");
  gtk_window_set_modal(XEN_TO_C_GtkWindow_(window), XEN_TO_C_gboolean(modal));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_get_modal(XEN window)
{
  #define H_gtk_window_get_modal "gboolean gtk_window_get_modal(GtkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_get_modal", "GtkWindow*");
  return(C_TO_XEN_gboolean(gtk_window_get_modal(XEN_TO_C_GtkWindow_(window))));
}
static XEN gxg_gtk_window_list_toplevels(void)
{
  #define H_gtk_window_list_toplevels "GList* gtk_window_list_toplevels( void)"
  return(C_TO_XEN_GList_(gtk_window_list_toplevels()));
}
static XEN gxg_gtk_window_add_mnemonic(XEN window, XEN keyval, XEN target)
{
  #define H_gtk_window_add_mnemonic "void gtk_window_add_mnemonic(GtkWindow* window, guint keyval, GtkWidget* target)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_add_mnemonic", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_guint_P(keyval), keyval, 2, "gtk_window_add_mnemonic", "guint");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(target), target, 3, "gtk_window_add_mnemonic", "GtkWidget*");
  gtk_window_add_mnemonic(XEN_TO_C_GtkWindow_(window), XEN_TO_C_guint(keyval), XEN_TO_C_GtkWidget_(target));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_remove_mnemonic(XEN window, XEN keyval, XEN target)
{
  #define H_gtk_window_remove_mnemonic "void gtk_window_remove_mnemonic(GtkWindow* window, guint keyval, \
GtkWidget* target)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_remove_mnemonic", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_guint_P(keyval), keyval, 2, "gtk_window_remove_mnemonic", "guint");
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(target), target, 3, "gtk_window_remove_mnemonic", "GtkWidget*");
  gtk_window_remove_mnemonic(XEN_TO_C_GtkWindow_(window), XEN_TO_C_guint(keyval), XEN_TO_C_GtkWidget_(target));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_mnemonic_activate(XEN window, XEN keyval, XEN modifier)
{
  #define H_gtk_window_mnemonic_activate "gboolean gtk_window_mnemonic_activate(GtkWindow* window, guint keyval, \
GdkModifierType modifier)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_mnemonic_activate", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_guint_P(keyval), keyval, 2, "gtk_window_mnemonic_activate", "guint");
  XEN_ASSERT_TYPE(XEN_GdkModifierType_P(modifier), modifier, 3, "gtk_window_mnemonic_activate", "GdkModifierType");
  return(C_TO_XEN_gboolean(gtk_window_mnemonic_activate(XEN_TO_C_GtkWindow_(window), XEN_TO_C_guint(keyval), XEN_TO_C_GdkModifierType(modifier))));
}
static XEN gxg_gtk_window_set_mnemonic_modifier(XEN window, XEN modifier)
{
  #define H_gtk_window_set_mnemonic_modifier "void gtk_window_set_mnemonic_modifier(GtkWindow* window, \
GdkModifierType modifier)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_set_mnemonic_modifier", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkModifierType_P(modifier), modifier, 2, "gtk_window_set_mnemonic_modifier", "GdkModifierType");
  gtk_window_set_mnemonic_modifier(XEN_TO_C_GtkWindow_(window), XEN_TO_C_GdkModifierType(modifier));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_get_mnemonic_modifier(XEN window)
{
  #define H_gtk_window_get_mnemonic_modifier "GdkModifierType gtk_window_get_mnemonic_modifier(GtkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_get_mnemonic_modifier", "GtkWindow*");
  return(C_TO_XEN_GdkModifierType(gtk_window_get_mnemonic_modifier(XEN_TO_C_GtkWindow_(window))));
}
static XEN gxg_gtk_window_present(XEN window)
{
  #define H_gtk_window_present "void gtk_window_present(GtkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_present", "GtkWindow*");
  gtk_window_present(XEN_TO_C_GtkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_iconify(XEN window)
{
  #define H_gtk_window_iconify "void gtk_window_iconify(GtkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_iconify", "GtkWindow*");
  gtk_window_iconify(XEN_TO_C_GtkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_deiconify(XEN window)
{
  #define H_gtk_window_deiconify "void gtk_window_deiconify(GtkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_deiconify", "GtkWindow*");
  gtk_window_deiconify(XEN_TO_C_GtkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_stick(XEN window)
{
  #define H_gtk_window_stick "void gtk_window_stick(GtkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_stick", "GtkWindow*");
  gtk_window_stick(XEN_TO_C_GtkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_unstick(XEN window)
{
  #define H_gtk_window_unstick "void gtk_window_unstick(GtkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_unstick", "GtkWindow*");
  gtk_window_unstick(XEN_TO_C_GtkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_maximize(XEN window)
{
  #define H_gtk_window_maximize "void gtk_window_maximize(GtkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_maximize", "GtkWindow*");
  gtk_window_maximize(XEN_TO_C_GtkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_unmaximize(XEN window)
{
  #define H_gtk_window_unmaximize "void gtk_window_unmaximize(GtkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_unmaximize", "GtkWindow*");
  gtk_window_unmaximize(XEN_TO_C_GtkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_begin_resize_drag(XEN window, XEN edge, XEN button, XEN root_x, XEN root_y, XEN timestamp)
{
  #define H_gtk_window_begin_resize_drag "void gtk_window_begin_resize_drag(GtkWindow* window, GdkWindowEdge edge, \
gint button, gint root_x, gint root_y, guint32 timestamp)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_begin_resize_drag", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_GdkWindowEdge_P(edge), edge, 2, "gtk_window_begin_resize_drag", "GdkWindowEdge");
  XEN_ASSERT_TYPE(XEN_gint_P(button), button, 3, "gtk_window_begin_resize_drag", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(root_x), root_x, 4, "gtk_window_begin_resize_drag", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(root_y), root_y, 5, "gtk_window_begin_resize_drag", "gint");
  XEN_ASSERT_TYPE(XEN_guint32_P(timestamp), timestamp, 6, "gtk_window_begin_resize_drag", "guint32");
  gtk_window_begin_resize_drag(XEN_TO_C_GtkWindow_(window), XEN_TO_C_GdkWindowEdge(edge), XEN_TO_C_gint(button), XEN_TO_C_gint(root_x), 
                               XEN_TO_C_gint(root_y), XEN_TO_C_guint32(timestamp));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_begin_move_drag(XEN window, XEN button, XEN root_x, XEN root_y, XEN timestamp)
{
  #define H_gtk_window_begin_move_drag "void gtk_window_begin_move_drag(GtkWindow* window, gint button, \
gint root_x, gint root_y, guint32 timestamp)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_begin_move_drag", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_gint_P(button), button, 2, "gtk_window_begin_move_drag", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(root_x), root_x, 3, "gtk_window_begin_move_drag", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(root_y), root_y, 4, "gtk_window_begin_move_drag", "gint");
  XEN_ASSERT_TYPE(XEN_guint32_P(timestamp), timestamp, 5, "gtk_window_begin_move_drag", "guint32");
  gtk_window_begin_move_drag(XEN_TO_C_GtkWindow_(window), XEN_TO_C_gint(button), XEN_TO_C_gint(root_x), XEN_TO_C_gint(root_y), 
                             XEN_TO_C_guint32(timestamp));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_set_default_size(XEN window, XEN width, XEN height)
{
  #define H_gtk_window_set_default_size "void gtk_window_set_default_size(GtkWindow* window, gint width, \
gint height)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_set_default_size", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 2, "gtk_window_set_default_size", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 3, "gtk_window_set_default_size", "gint");
  gtk_window_set_default_size(XEN_TO_C_GtkWindow_(window), XEN_TO_C_gint(width), XEN_TO_C_gint(height));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_get_default_size(XEN window, XEN width, XEN height)
{
  #define H_gtk_window_get_default_size "void gtk_window_get_default_size(GtkWindow* window, gint* [width], \
gint* [height])"
  gint ref_width;
  gint ref_height;
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_get_default_size", "GtkWindow*");
  gtk_window_get_default_size(XEN_TO_C_GtkWindow_(window), &ref_width, &ref_height);
  return(XEN_LIST_2(C_TO_XEN_gint(ref_width), C_TO_XEN_gint(ref_height)));
}
static XEN gxg_gtk_window_resize(XEN window, XEN width, XEN height)
{
  #define H_gtk_window_resize "void gtk_window_resize(GtkWindow* window, gint width, gint height)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_resize", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_gint_P(width), width, 2, "gtk_window_resize", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(height), height, 3, "gtk_window_resize", "gint");
  gtk_window_resize(XEN_TO_C_GtkWindow_(window), XEN_TO_C_gint(width), XEN_TO_C_gint(height));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_get_size(XEN window, XEN width, XEN height)
{
  #define H_gtk_window_get_size "void gtk_window_get_size(GtkWindow* window, gint* [width], gint* [height])"
  gint ref_width;
  gint ref_height;
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_get_size", "GtkWindow*");
  gtk_window_get_size(XEN_TO_C_GtkWindow_(window), &ref_width, &ref_height);
  return(XEN_LIST_2(C_TO_XEN_gint(ref_width), C_TO_XEN_gint(ref_height)));
}
static XEN gxg_gtk_window_move(XEN window, XEN x, XEN y)
{
  #define H_gtk_window_move "void gtk_window_move(GtkWindow* window, gint x, gint y)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_move", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 2, "gtk_window_move", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 3, "gtk_window_move", "gint");
  gtk_window_move(XEN_TO_C_GtkWindow_(window), XEN_TO_C_gint(x), XEN_TO_C_gint(y));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_get_position(XEN window, XEN root_x, XEN root_y)
{
  #define H_gtk_window_get_position "void gtk_window_get_position(GtkWindow* window, gint* [root_x], \
gint* [root_y])"
  gint ref_root_x;
  gint ref_root_y;
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_get_position", "GtkWindow*");
  gtk_window_get_position(XEN_TO_C_GtkWindow_(window), &ref_root_x, &ref_root_y);
  return(XEN_LIST_2(C_TO_XEN_gint(ref_root_x), C_TO_XEN_gint(ref_root_y)));
}
static XEN gxg_gtk_window_parse_geometry(XEN window, XEN geometry)
{
  #define H_gtk_window_parse_geometry "gboolean gtk_window_parse_geometry(GtkWindow* window, gchar* geometry)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_parse_geometry", "GtkWindow*");
  XEN_ASSERT_TYPE(XEN_gchar__P(geometry), geometry, 2, "gtk_window_parse_geometry", "gchar*");
  return(C_TO_XEN_gboolean(gtk_window_parse_geometry(XEN_TO_C_GtkWindow_(window), XEN_TO_C_gchar_(geometry))));
}
static XEN gxg_gtk_window_reshow_with_initial_size(XEN window)
{
  #define H_gtk_window_reshow_with_initial_size "void gtk_window_reshow_with_initial_size(GtkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GtkWindow__P(window), window, 1, "gtk_window_reshow_with_initial_size", "GtkWindow*");
  gtk_window_reshow_with_initial_size(XEN_TO_C_GtkWindow_(window));
  return(XEN_FALSE);
}
static XEN gxg_gtk_window_group_get_type(void)
{
  #define H_gtk_window_group_get_type "GType gtk_window_group_get_type( void)"
  return(C_TO_XEN_GType(gtk_window_group_get_type()));
}
static XEN gxg_pango_color_get_type(void)
{
  #define H_pango_color_get_type "GType pango_color_get_type( void)"
  return(C_TO_XEN_GType(pango_color_get_type()));
}
static XEN gxg_pango_color_copy(XEN src)
{
  #define H_pango_color_copy "PangoColor* pango_color_copy(PangoColor* src)"
  XEN_ASSERT_TYPE(XEN_PangoColor__P(src), src, 1, "pango_color_copy", "PangoColor*");
  return(C_TO_XEN_PangoColor_(pango_color_copy(XEN_TO_C_PangoColor_(src))));
}
static XEN gxg_pango_color_free(XEN color)
{
  #define H_pango_color_free "void pango_color_free(PangoColor* color)"
  XEN_ASSERT_TYPE(XEN_PangoColor__P(color), color, 1, "pango_color_free", "PangoColor*");
  pango_color_free(XEN_TO_C_PangoColor_(color));
  return(XEN_FALSE);
}
static XEN gxg_pango_color_parse(XEN color, XEN spec)
{
  #define H_pango_color_parse "gboolean pango_color_parse(PangoColor* color, char* spec)"
  XEN_ASSERT_TYPE(XEN_PangoColor__P(color), color, 1, "pango_color_parse", "PangoColor*");
  XEN_ASSERT_TYPE(XEN_char__P(spec), spec, 2, "pango_color_parse", "char*");
  return(C_TO_XEN_gboolean(pango_color_parse(XEN_TO_C_PangoColor_(color), XEN_TO_C_char_(spec))));
}
static XEN gxg_pango_attr_type_register(XEN name)
{
  #define H_pango_attr_type_register "PangoAttrType pango_attr_type_register(gchar* name)"
  XEN_ASSERT_TYPE(XEN_gchar__P(name), name, 1, "pango_attr_type_register", "gchar*");
  return(C_TO_XEN_PangoAttrType(pango_attr_type_register(XEN_TO_C_gchar_(name))));
}
static XEN gxg_pango_attribute_copy(XEN attr)
{
  #define H_pango_attribute_copy "PangoAttribute* pango_attribute_copy(PangoAttribute* attr)"
  XEN_ASSERT_TYPE(XEN_PangoAttribute__P(attr), attr, 1, "pango_attribute_copy", "PangoAttribute*");
  return(C_TO_XEN_PangoAttribute_(pango_attribute_copy(XEN_TO_C_PangoAttribute_(attr))));
}
static XEN gxg_pango_attribute_destroy(XEN attr)
{
  #define H_pango_attribute_destroy "void pango_attribute_destroy(PangoAttribute* attr)"
  XEN_ASSERT_TYPE(XEN_PangoAttribute__P(attr), attr, 1, "pango_attribute_destroy", "PangoAttribute*");
  pango_attribute_destroy(XEN_TO_C_PangoAttribute_(attr));
  return(XEN_FALSE);
}
static XEN gxg_pango_attribute_equal(XEN attr1, XEN attr2)
{
  #define H_pango_attribute_equal "gboolean pango_attribute_equal(PangoAttribute* attr1, PangoAttribute* attr2)"
  XEN_ASSERT_TYPE(XEN_PangoAttribute__P(attr1), attr1, 1, "pango_attribute_equal", "PangoAttribute*");
  XEN_ASSERT_TYPE(XEN_PangoAttribute__P(attr2), attr2, 2, "pango_attribute_equal", "PangoAttribute*");
  return(C_TO_XEN_gboolean(pango_attribute_equal(XEN_TO_C_PangoAttribute_(attr1), XEN_TO_C_PangoAttribute_(attr2))));
}
static XEN gxg_pango_attr_language_new(XEN language)
{
  #define H_pango_attr_language_new "PangoAttribute* pango_attr_language_new(PangoLanguage* language)"
  XEN_ASSERT_TYPE(XEN_PangoLanguage__P(language), language, 1, "pango_attr_language_new", "PangoLanguage*");
  return(C_TO_XEN_PangoAttribute_(pango_attr_language_new(XEN_TO_C_PangoLanguage_(language))));
}
static XEN gxg_pango_attr_family_new(XEN family)
{
  #define H_pango_attr_family_new "PangoAttribute* pango_attr_family_new(char* family)"
  XEN_ASSERT_TYPE(XEN_char__P(family), family, 1, "pango_attr_family_new", "char*");
  return(C_TO_XEN_PangoAttribute_(pango_attr_family_new(XEN_TO_C_char_(family))));
}
static XEN gxg_pango_attr_foreground_new(XEN red, XEN green, XEN blue)
{
  #define H_pango_attr_foreground_new "PangoAttribute* pango_attr_foreground_new(guint16 red, guint16 green, \
guint16 blue)"
  XEN_ASSERT_TYPE(XEN_guint16_P(red), red, 1, "pango_attr_foreground_new", "guint16");
  XEN_ASSERT_TYPE(XEN_guint16_P(green), green, 2, "pango_attr_foreground_new", "guint16");
  XEN_ASSERT_TYPE(XEN_guint16_P(blue), blue, 3, "pango_attr_foreground_new", "guint16");
  return(C_TO_XEN_PangoAttribute_(pango_attr_foreground_new(XEN_TO_C_guint16(red), XEN_TO_C_guint16(green), XEN_TO_C_guint16(blue))));
}
static XEN gxg_pango_attr_background_new(XEN red, XEN green, XEN blue)
{
  #define H_pango_attr_background_new "PangoAttribute* pango_attr_background_new(guint16 red, guint16 green, \
guint16 blue)"
  XEN_ASSERT_TYPE(XEN_guint16_P(red), red, 1, "pango_attr_background_new", "guint16");
  XEN_ASSERT_TYPE(XEN_guint16_P(green), green, 2, "pango_attr_background_new", "guint16");
  XEN_ASSERT_TYPE(XEN_guint16_P(blue), blue, 3, "pango_attr_background_new", "guint16");
  return(C_TO_XEN_PangoAttribute_(pango_attr_background_new(XEN_TO_C_guint16(red), XEN_TO_C_guint16(green), XEN_TO_C_guint16(blue))));
}
static XEN gxg_pango_attr_size_new(XEN size)
{
  #define H_pango_attr_size_new "PangoAttribute* pango_attr_size_new(int size)"
  XEN_ASSERT_TYPE(XEN_int_P(size), size, 1, "pango_attr_size_new", "int");
  return(C_TO_XEN_PangoAttribute_(pango_attr_size_new(XEN_TO_C_int(size))));
}
static XEN gxg_pango_attr_style_new(XEN style)
{
  #define H_pango_attr_style_new "PangoAttribute* pango_attr_style_new(PangoStyle style)"
  XEN_ASSERT_TYPE(XEN_PangoStyle_P(style), style, 1, "pango_attr_style_new", "PangoStyle");
  return(C_TO_XEN_PangoAttribute_(pango_attr_style_new(XEN_TO_C_PangoStyle(style))));
}
static XEN gxg_pango_attr_weight_new(XEN weight)
{
  #define H_pango_attr_weight_new "PangoAttribute* pango_attr_weight_new(PangoWeight weight)"
  XEN_ASSERT_TYPE(XEN_PangoWeight_P(weight), weight, 1, "pango_attr_weight_new", "PangoWeight");
  return(C_TO_XEN_PangoAttribute_(pango_attr_weight_new(XEN_TO_C_PangoWeight(weight))));
}
static XEN gxg_pango_attr_variant_new(XEN variant)
{
  #define H_pango_attr_variant_new "PangoAttribute* pango_attr_variant_new(PangoVariant variant)"
  XEN_ASSERT_TYPE(XEN_PangoVariant_P(variant), variant, 1, "pango_attr_variant_new", "PangoVariant");
  return(C_TO_XEN_PangoAttribute_(pango_attr_variant_new(XEN_TO_C_PangoVariant(variant))));
}
static XEN gxg_pango_attr_stretch_new(XEN stretch)
{
  #define H_pango_attr_stretch_new "PangoAttribute* pango_attr_stretch_new(PangoStretch stretch)"
  XEN_ASSERT_TYPE(XEN_PangoStretch_P(stretch), stretch, 1, "pango_attr_stretch_new", "PangoStretch");
  return(C_TO_XEN_PangoAttribute_(pango_attr_stretch_new(XEN_TO_C_PangoStretch(stretch))));
}
static XEN gxg_pango_attr_font_desc_new(XEN desc)
{
  #define H_pango_attr_font_desc_new "PangoAttribute* pango_attr_font_desc_new(PangoFontDescription* desc)"
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 1, "pango_attr_font_desc_new", "PangoFontDescription*");
  return(C_TO_XEN_PangoAttribute_(pango_attr_font_desc_new(XEN_TO_C_PangoFontDescription_(desc))));
}
static XEN gxg_pango_attr_underline_new(XEN underline)
{
  #define H_pango_attr_underline_new "PangoAttribute* pango_attr_underline_new(PangoUnderline underline)"
  XEN_ASSERT_TYPE(XEN_PangoUnderline_P(underline), underline, 1, "pango_attr_underline_new", "PangoUnderline");
  return(C_TO_XEN_PangoAttribute_(pango_attr_underline_new(XEN_TO_C_PangoUnderline(underline))));
}
static XEN gxg_pango_attr_strikethrough_new(XEN strikethrough)
{
  #define H_pango_attr_strikethrough_new "PangoAttribute* pango_attr_strikethrough_new(gboolean strikethrough)"
  XEN_ASSERT_TYPE(XEN_gboolean_P(strikethrough), strikethrough, 1, "pango_attr_strikethrough_new", "gboolean");
  return(C_TO_XEN_PangoAttribute_(pango_attr_strikethrough_new(XEN_TO_C_gboolean(strikethrough))));
}
static XEN gxg_pango_attr_rise_new(XEN rise)
{
  #define H_pango_attr_rise_new "PangoAttribute* pango_attr_rise_new(int rise)"
  XEN_ASSERT_TYPE(XEN_int_P(rise), rise, 1, "pango_attr_rise_new", "int");
  return(C_TO_XEN_PangoAttribute_(pango_attr_rise_new(XEN_TO_C_int(rise))));
}
static XEN gxg_pango_attr_shape_new(XEN ink_rect, XEN logical_rect)
{
  #define H_pango_attr_shape_new "PangoAttribute* pango_attr_shape_new(PangoRectangle* ink_rect, PangoRectangle* logical_rect)"
  XEN_ASSERT_TYPE(XEN_PangoRectangle__P(ink_rect), ink_rect, 1, "pango_attr_shape_new", "PangoRectangle*");
  XEN_ASSERT_TYPE(XEN_PangoRectangle__P(logical_rect), logical_rect, 2, "pango_attr_shape_new", "PangoRectangle*");
  return(C_TO_XEN_PangoAttribute_(pango_attr_shape_new(XEN_TO_C_PangoRectangle_(ink_rect), XEN_TO_C_PangoRectangle_(logical_rect))));
}
static XEN gxg_pango_attr_scale_new(XEN scale_factor)
{
  #define H_pango_attr_scale_new "PangoAttribute* pango_attr_scale_new(double scale_factor)"
  XEN_ASSERT_TYPE(XEN_double_P(scale_factor), scale_factor, 1, "pango_attr_scale_new", "double");
  return(C_TO_XEN_PangoAttribute_(pango_attr_scale_new(XEN_TO_C_double(scale_factor))));
}
static XEN gxg_pango_attr_list_get_type(void)
{
  #define H_pango_attr_list_get_type "GType pango_attr_list_get_type( void)"
  return(C_TO_XEN_GType(pango_attr_list_get_type()));
}
static XEN gxg_pango_attr_list_new(void)
{
  #define H_pango_attr_list_new "PangoAttrList* pango_attr_list_new( void)"
  return(C_TO_XEN_PangoAttrList_(pango_attr_list_new()));
}
static XEN gxg_pango_attr_list_ref(XEN list)
{
  #define H_pango_attr_list_ref "void pango_attr_list_ref(PangoAttrList* list)"
  XEN_ASSERT_TYPE(XEN_PangoAttrList__P(list), list, 1, "pango_attr_list_ref", "PangoAttrList*");
  pango_attr_list_ref(XEN_TO_C_PangoAttrList_(list));
  return(XEN_FALSE);
}
static XEN gxg_pango_attr_list_unref(XEN list)
{
  #define H_pango_attr_list_unref "void pango_attr_list_unref(PangoAttrList* list)"
  XEN_ASSERT_TYPE(XEN_PangoAttrList__P(list), list, 1, "pango_attr_list_unref", "PangoAttrList*");
  pango_attr_list_unref(XEN_TO_C_PangoAttrList_(list));
  return(XEN_FALSE);
}
static XEN gxg_pango_attr_list_copy(XEN list)
{
  #define H_pango_attr_list_copy "PangoAttrList* pango_attr_list_copy(PangoAttrList* list)"
  XEN_ASSERT_TYPE(XEN_PangoAttrList__P(list), list, 1, "pango_attr_list_copy", "PangoAttrList*");
  return(C_TO_XEN_PangoAttrList_(pango_attr_list_copy(XEN_TO_C_PangoAttrList_(list))));
}
static XEN gxg_pango_attr_list_insert(XEN list, XEN attr)
{
  #define H_pango_attr_list_insert "void pango_attr_list_insert(PangoAttrList* list, PangoAttribute* attr)"
  XEN_ASSERT_TYPE(XEN_PangoAttrList__P(list), list, 1, "pango_attr_list_insert", "PangoAttrList*");
  XEN_ASSERT_TYPE(XEN_PangoAttribute__P(attr), attr, 2, "pango_attr_list_insert", "PangoAttribute*");
  pango_attr_list_insert(XEN_TO_C_PangoAttrList_(list), XEN_TO_C_PangoAttribute_(attr));
  return(XEN_FALSE);
}
static XEN gxg_pango_attr_list_insert_before(XEN list, XEN attr)
{
  #define H_pango_attr_list_insert_before "void pango_attr_list_insert_before(PangoAttrList* list, PangoAttribute* attr)"
  XEN_ASSERT_TYPE(XEN_PangoAttrList__P(list), list, 1, "pango_attr_list_insert_before", "PangoAttrList*");
  XEN_ASSERT_TYPE(XEN_PangoAttribute__P(attr), attr, 2, "pango_attr_list_insert_before", "PangoAttribute*");
  pango_attr_list_insert_before(XEN_TO_C_PangoAttrList_(list), XEN_TO_C_PangoAttribute_(attr));
  return(XEN_FALSE);
}
static XEN gxg_pango_attr_list_change(XEN list, XEN attr)
{
  #define H_pango_attr_list_change "void pango_attr_list_change(PangoAttrList* list, PangoAttribute* attr)"
  XEN_ASSERT_TYPE(XEN_PangoAttrList__P(list), list, 1, "pango_attr_list_change", "PangoAttrList*");
  XEN_ASSERT_TYPE(XEN_PangoAttribute__P(attr), attr, 2, "pango_attr_list_change", "PangoAttribute*");
  pango_attr_list_change(XEN_TO_C_PangoAttrList_(list), XEN_TO_C_PangoAttribute_(attr));
  return(XEN_FALSE);
}
static XEN gxg_pango_attr_list_splice(XEN list, XEN other, XEN pos, XEN len)
{
  #define H_pango_attr_list_splice "void pango_attr_list_splice(PangoAttrList* list, PangoAttrList* other, \
gint pos, gint len)"
  XEN_ASSERT_TYPE(XEN_PangoAttrList__P(list), list, 1, "pango_attr_list_splice", "PangoAttrList*");
  XEN_ASSERT_TYPE(XEN_PangoAttrList__P(other), other, 2, "pango_attr_list_splice", "PangoAttrList*");
  XEN_ASSERT_TYPE(XEN_gint_P(pos), pos, 3, "pango_attr_list_splice", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(len), len, 4, "pango_attr_list_splice", "gint");
  pango_attr_list_splice(XEN_TO_C_PangoAttrList_(list), XEN_TO_C_PangoAttrList_(other), XEN_TO_C_gint(pos), XEN_TO_C_gint(len));
  return(XEN_FALSE);
}
static XEN gxg_pango_attr_list_get_iterator(XEN list)
{
  #define H_pango_attr_list_get_iterator "PangoAttrIterator* pango_attr_list_get_iterator(PangoAttrList* list)"
  XEN_ASSERT_TYPE(XEN_PangoAttrList__P(list), list, 1, "pango_attr_list_get_iterator", "PangoAttrList*");
  return(C_TO_XEN_PangoAttrIterator_(pango_attr_list_get_iterator(XEN_TO_C_PangoAttrList_(list))));
}
static XEN gxg_pango_attr_iterator_range(XEN iterator, XEN start, XEN end)
{
  #define H_pango_attr_iterator_range "void pango_attr_iterator_range(PangoAttrIterator* iterator, gint* [start], \
gint* [end])"
  gint ref_start;
  gint ref_end;
  XEN_ASSERT_TYPE(XEN_PangoAttrIterator__P(iterator), iterator, 1, "pango_attr_iterator_range", "PangoAttrIterator*");
  pango_attr_iterator_range(XEN_TO_C_PangoAttrIterator_(iterator), &ref_start, &ref_end);
  return(XEN_LIST_2(C_TO_XEN_gint(ref_start), C_TO_XEN_gint(ref_end)));
}
static XEN gxg_pango_attr_iterator_next(XEN iterator)
{
  #define H_pango_attr_iterator_next "gboolean pango_attr_iterator_next(PangoAttrIterator* iterator)"
  XEN_ASSERT_TYPE(XEN_PangoAttrIterator__P(iterator), iterator, 1, "pango_attr_iterator_next", "PangoAttrIterator*");
  return(C_TO_XEN_gboolean(pango_attr_iterator_next(XEN_TO_C_PangoAttrIterator_(iterator))));
}
static XEN gxg_pango_attr_iterator_copy(XEN iterator)
{
  #define H_pango_attr_iterator_copy "PangoAttrIterator* pango_attr_iterator_copy(PangoAttrIterator* iterator)"
  XEN_ASSERT_TYPE(XEN_PangoAttrIterator__P(iterator), iterator, 1, "pango_attr_iterator_copy", "PangoAttrIterator*");
  return(C_TO_XEN_PangoAttrIterator_(pango_attr_iterator_copy(XEN_TO_C_PangoAttrIterator_(iterator))));
}
static XEN gxg_pango_attr_iterator_destroy(XEN iterator)
{
  #define H_pango_attr_iterator_destroy "void pango_attr_iterator_destroy(PangoAttrIterator* iterator)"
  XEN_ASSERT_TYPE(XEN_PangoAttrIterator__P(iterator), iterator, 1, "pango_attr_iterator_destroy", "PangoAttrIterator*");
  pango_attr_iterator_destroy(XEN_TO_C_PangoAttrIterator_(iterator));
  return(XEN_FALSE);
}
static XEN gxg_pango_attr_iterator_get(XEN iterator, XEN type)
{
  #define H_pango_attr_iterator_get "PangoAttribute* pango_attr_iterator_get(PangoAttrIterator* iterator, \
PangoAttrType type)"
  XEN_ASSERT_TYPE(XEN_PangoAttrIterator__P(iterator), iterator, 1, "pango_attr_iterator_get", "PangoAttrIterator*");
  XEN_ASSERT_TYPE(XEN_PangoAttrType_P(type), type, 2, "pango_attr_iterator_get", "PangoAttrType");
  return(C_TO_XEN_PangoAttribute_(pango_attr_iterator_get(XEN_TO_C_PangoAttrIterator_(iterator), XEN_TO_C_PangoAttrType(type))));
}
static XEN gxg_pango_attr_iterator_get_font(XEN iterator, XEN desc, XEN language, XEN extra_attrs)
{
  #define H_pango_attr_iterator_get_font "void pango_attr_iterator_get_font(PangoAttrIterator* iterator, \
PangoFontDescription* desc, PangoLanguage** [language], GSList** [extra_attrs])"
  PangoLanguage* ref_language = NULL;
  GSList* ref_extra_attrs = NULL;
  XEN_ASSERT_TYPE(XEN_PangoAttrIterator__P(iterator), iterator, 1, "pango_attr_iterator_get_font", "PangoAttrIterator*");
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 2, "pango_attr_iterator_get_font", "PangoFontDescription*");
  pango_attr_iterator_get_font(XEN_TO_C_PangoAttrIterator_(iterator), XEN_TO_C_PangoFontDescription_(desc), &ref_language, 
                               &ref_extra_attrs);
  return(XEN_LIST_2(C_TO_XEN_PangoLanguage_(ref_language), C_TO_XEN_GSList_(ref_extra_attrs)));
}
static XEN gxg_pango_parse_markup(XEN markup_text, XEN length, XEN accel_marker, XEN attr_list, XEN text, XEN accel_char, XEN error)
{
  #define H_pango_parse_markup "gboolean pango_parse_markup(char* markup_text, int length, gunichar accel_marker, \
PangoAttrList** attr_list, char** text, gunichar* accel_char, GError** [error])"
  GError* ref_error = NULL;
  XEN_ASSERT_TYPE(XEN_char__P(markup_text), markup_text, 1, "pango_parse_markup", "char*");
  XEN_ASSERT_TYPE(XEN_int_P(length), length, 2, "pango_parse_markup", "int");
  XEN_ASSERT_TYPE(XEN_gunichar_P(accel_marker), accel_marker, 3, "pango_parse_markup", "gunichar");
  XEN_ASSERT_TYPE(XEN_PangoAttrList___P(attr_list), attr_list, 4, "pango_parse_markup", "PangoAttrList**");
  XEN_ASSERT_TYPE(XEN_char___P(text), text, 5, "pango_parse_markup", "char**");
  XEN_ASSERT_TYPE(XEN_gunichar__P(accel_char), accel_char, 6, "pango_parse_markup", "gunichar*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(pango_parse_markup(XEN_TO_C_char_(markup_text), XEN_TO_C_int(length), XEN_TO_C_gunichar(accel_marker), 
                                                  XEN_TO_C_PangoAttrList__(attr_list), XEN_TO_C_char__(text), XEN_TO_C_gunichar_(accel_char), 
                                                  &ref_error));
    return(XEN_LIST_2(result, C_TO_XEN_GError_(ref_error)));
   }
}
static XEN gxg_pango_break(XEN text, XEN length, XEN analysis, XEN attrs, XEN attrs_len)
{
  #define H_pango_break "void pango_break(gchar* text, int length, PangoAnalysis* analysis, PangoLogAttr* attrs, \
int attrs_len)"
  XEN_ASSERT_TYPE(XEN_gchar__P(text), text, 1, "pango_break", "gchar*");
  XEN_ASSERT_TYPE(XEN_int_P(length), length, 2, "pango_break", "int");
  XEN_ASSERT_TYPE(XEN_PangoAnalysis__P(analysis), analysis, 3, "pango_break", "PangoAnalysis*");
  XEN_ASSERT_TYPE(XEN_PangoLogAttr__P(attrs), attrs, 4, "pango_break", "PangoLogAttr*");
  XEN_ASSERT_TYPE(XEN_int_P(attrs_len), attrs_len, 5, "pango_break", "int");
  pango_break(XEN_TO_C_gchar_(text), XEN_TO_C_int(length), XEN_TO_C_PangoAnalysis_(analysis), XEN_TO_C_PangoLogAttr_(attrs), 
              XEN_TO_C_int(attrs_len));
  return(XEN_FALSE);
}
static XEN gxg_pango_find_paragraph_boundary(XEN text, XEN length, XEN paragraph_delimiter_index, XEN next_paragraph_start)
{
  #define H_pango_find_paragraph_boundary "void pango_find_paragraph_boundary(gchar* text, gint length, \
gint* [paragraph_delimiter_index], gint* [next_paragraph_start])"
  gint ref_paragraph_delimiter_index;
  gint ref_next_paragraph_start;
  XEN_ASSERT_TYPE(XEN_gchar__P(text), text, 1, "pango_find_paragraph_boundary", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(length), length, 2, "pango_find_paragraph_boundary", "gint");
  pango_find_paragraph_boundary(XEN_TO_C_gchar_(text), XEN_TO_C_gint(length), &ref_paragraph_delimiter_index, &ref_next_paragraph_start);
  return(XEN_LIST_2(C_TO_XEN_gint(ref_paragraph_delimiter_index), C_TO_XEN_gint(ref_next_paragraph_start)));
}
static XEN gxg_pango_get_log_attrs(XEN text, XEN length, XEN level, XEN language, XEN log_attrs, XEN attrs_len)
{
  #define H_pango_get_log_attrs "void pango_get_log_attrs(char* text, int length, int level, PangoLanguage* language, \
PangoLogAttr* log_attrs, int attrs_len)"
  XEN_ASSERT_TYPE(XEN_char__P(text), text, 1, "pango_get_log_attrs", "char*");
  XEN_ASSERT_TYPE(XEN_int_P(length), length, 2, "pango_get_log_attrs", "int");
  XEN_ASSERT_TYPE(XEN_int_P(level), level, 3, "pango_get_log_attrs", "int");
  XEN_ASSERT_TYPE(XEN_PangoLanguage__P(language), language, 4, "pango_get_log_attrs", "PangoLanguage*");
  XEN_ASSERT_TYPE(XEN_PangoLogAttr__P(log_attrs), log_attrs, 5, "pango_get_log_attrs", "PangoLogAttr*");
  XEN_ASSERT_TYPE(XEN_int_P(attrs_len), attrs_len, 6, "pango_get_log_attrs", "int");
  pango_get_log_attrs(XEN_TO_C_char_(text), XEN_TO_C_int(length), XEN_TO_C_int(level), XEN_TO_C_PangoLanguage_(language), 
                      XEN_TO_C_PangoLogAttr_(log_attrs), XEN_TO_C_int(attrs_len));
  return(XEN_FALSE);
}
static XEN gxg_pango_context_get_type(void)
{
  #define H_pango_context_get_type "GType pango_context_get_type( void)"
  return(C_TO_XEN_GType(pango_context_get_type()));
}
static XEN gxg_pango_context_list_families(XEN context, XEN families, XEN n_families)
{
  #define H_pango_context_list_families "void pango_context_list_families(PangoContext* context, PangoFontFamily*** [families], \
int* [n_families])"
  PangoFontFamily** ref_families = NULL;
  int ref_n_families;
  XEN_ASSERT_TYPE(XEN_PangoContext__P(context), context, 1, "pango_context_list_families", "PangoContext*");
  pango_context_list_families(XEN_TO_C_PangoContext_(context), &ref_families, &ref_n_families);
  return(XEN_LIST_2(C_TO_XEN_PangoFontFamily__(ref_families), C_TO_XEN_int(ref_n_families)));
}
static XEN gxg_pango_context_load_font(XEN context, XEN desc)
{
  #define H_pango_context_load_font "PangoFont* pango_context_load_font(PangoContext* context, PangoFontDescription* desc)"
  XEN_ASSERT_TYPE(XEN_PangoContext__P(context), context, 1, "pango_context_load_font", "PangoContext*");
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 2, "pango_context_load_font", "PangoFontDescription*");
  return(C_TO_XEN_PangoFont_(pango_context_load_font(XEN_TO_C_PangoContext_(context), XEN_TO_C_PangoFontDescription_(desc))));
}
static XEN gxg_pango_context_load_fontset(XEN context, XEN desc, XEN language)
{
  #define H_pango_context_load_fontset "PangoFontset* pango_context_load_fontset(PangoContext* context, \
PangoFontDescription* desc, PangoLanguage* language)"
  XEN_ASSERT_TYPE(XEN_PangoContext__P(context), context, 1, "pango_context_load_fontset", "PangoContext*");
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 2, "pango_context_load_fontset", "PangoFontDescription*");
  XEN_ASSERT_TYPE(XEN_PangoLanguage__P(language), language, 3, "pango_context_load_fontset", "PangoLanguage*");
  return(C_TO_XEN_PangoFontset_(pango_context_load_fontset(XEN_TO_C_PangoContext_(context), XEN_TO_C_PangoFontDescription_(desc), 
                                                           XEN_TO_C_PangoLanguage_(language))));
}
static XEN gxg_pango_context_get_metrics(XEN context, XEN desc, XEN language)
{
  #define H_pango_context_get_metrics "PangoFontMetrics* pango_context_get_metrics(PangoContext* context, \
PangoFontDescription* desc, PangoLanguage* language)"
  XEN_ASSERT_TYPE(XEN_PangoContext__P(context), context, 1, "pango_context_get_metrics", "PangoContext*");
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 2, "pango_context_get_metrics", "PangoFontDescription*");
  XEN_ASSERT_TYPE(XEN_PangoLanguage__P(language), language, 3, "pango_context_get_metrics", "PangoLanguage*");
  return(C_TO_XEN_PangoFontMetrics_(pango_context_get_metrics(XEN_TO_C_PangoContext_(context), XEN_TO_C_PangoFontDescription_(desc), 
                                                              XEN_TO_C_PangoLanguage_(language))));
}
static XEN gxg_pango_context_set_font_description(XEN context, XEN desc)
{
  #define H_pango_context_set_font_description "void pango_context_set_font_description(PangoContext* context, \
PangoFontDescription* desc)"
  XEN_ASSERT_TYPE(XEN_PangoContext__P(context), context, 1, "pango_context_set_font_description", "PangoContext*");
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 2, "pango_context_set_font_description", "PangoFontDescription*");
  pango_context_set_font_description(XEN_TO_C_PangoContext_(context), XEN_TO_C_PangoFontDescription_(desc));
  return(XEN_FALSE);
}
static XEN gxg_pango_context_get_font_description(XEN context)
{
  #define H_pango_context_get_font_description "PangoFontDescription* pango_context_get_font_description(PangoContext* context)"
  XEN_ASSERT_TYPE(XEN_PangoContext__P(context), context, 1, "pango_context_get_font_description", "PangoContext*");
  return(C_TO_XEN_PangoFontDescription_(pango_context_get_font_description(XEN_TO_C_PangoContext_(context))));
}
static XEN gxg_pango_context_get_language(XEN context)
{
  #define H_pango_context_get_language "PangoLanguage* pango_context_get_language(PangoContext* context)"
  XEN_ASSERT_TYPE(XEN_PangoContext__P(context), context, 1, "pango_context_get_language", "PangoContext*");
  return(C_TO_XEN_PangoLanguage_(pango_context_get_language(XEN_TO_C_PangoContext_(context))));
}
static XEN gxg_pango_context_set_language(XEN context, XEN language)
{
  #define H_pango_context_set_language "void pango_context_set_language(PangoContext* context, PangoLanguage* language)"
  XEN_ASSERT_TYPE(XEN_PangoContext__P(context), context, 1, "pango_context_set_language", "PangoContext*");
  XEN_ASSERT_TYPE(XEN_PangoLanguage__P(language), language, 2, "pango_context_set_language", "PangoLanguage*");
  pango_context_set_language(XEN_TO_C_PangoContext_(context), XEN_TO_C_PangoLanguage_(language));
  return(XEN_FALSE);
}
static XEN gxg_pango_context_set_base_dir(XEN context, XEN direction)
{
  #define H_pango_context_set_base_dir "void pango_context_set_base_dir(PangoContext* context, PangoDirection direction)"
  XEN_ASSERT_TYPE(XEN_PangoContext__P(context), context, 1, "pango_context_set_base_dir", "PangoContext*");
  XEN_ASSERT_TYPE(XEN_PangoDirection_P(direction), direction, 2, "pango_context_set_base_dir", "PangoDirection");
  pango_context_set_base_dir(XEN_TO_C_PangoContext_(context), XEN_TO_C_PangoDirection(direction));
  return(XEN_FALSE);
}
static XEN gxg_pango_context_get_base_dir(XEN context)
{
  #define H_pango_context_get_base_dir "PangoDirection pango_context_get_base_dir(PangoContext* context)"
  XEN_ASSERT_TYPE(XEN_PangoContext__P(context), context, 1, "pango_context_get_base_dir", "PangoContext*");
  return(C_TO_XEN_PangoDirection(pango_context_get_base_dir(XEN_TO_C_PangoContext_(context))));
}
static XEN gxg_pango_itemize(XEN context, XEN text, XEN start_index, XEN length, XEN attrs, XEN cached_iter)
{
  #define H_pango_itemize "GList* pango_itemize(PangoContext* context, char* text, int start_index, int length, \
PangoAttrList* attrs, PangoAttrIterator* cached_iter)"
  XEN_ASSERT_TYPE(XEN_PangoContext__P(context), context, 1, "pango_itemize", "PangoContext*");
  XEN_ASSERT_TYPE(XEN_char__P(text), text, 2, "pango_itemize", "char*");
  XEN_ASSERT_TYPE(XEN_int_P(start_index), start_index, 3, "pango_itemize", "int");
  XEN_ASSERT_TYPE(XEN_int_P(length), length, 4, "pango_itemize", "int");
  XEN_ASSERT_TYPE(XEN_PangoAttrList__P(attrs), attrs, 5, "pango_itemize", "PangoAttrList*");
  XEN_ASSERT_TYPE(XEN_PangoAttrIterator__P(cached_iter), cached_iter, 6, "pango_itemize", "PangoAttrIterator*");
  return(C_TO_XEN_GList_(pango_itemize(XEN_TO_C_PangoContext_(context), XEN_TO_C_char_(text), XEN_TO_C_int(start_index), 
                                       XEN_TO_C_int(length), XEN_TO_C_PangoAttrList_(attrs), XEN_TO_C_PangoAttrIterator_(cached_iter))));
}
static XEN gxg_pango_coverage_new(void)
{
  #define H_pango_coverage_new "PangoCoverage* pango_coverage_new( void)"
  return(C_TO_XEN_PangoCoverage_(pango_coverage_new()));
}
static XEN gxg_pango_coverage_ref(XEN coverage)
{
  #define H_pango_coverage_ref "PangoCoverage* pango_coverage_ref(PangoCoverage* coverage)"
  XEN_ASSERT_TYPE(XEN_PangoCoverage__P(coverage), coverage, 1, "pango_coverage_ref", "PangoCoverage*");
  return(C_TO_XEN_PangoCoverage_(pango_coverage_ref(XEN_TO_C_PangoCoverage_(coverage))));
}
static XEN gxg_pango_coverage_unref(XEN coverage)
{
  #define H_pango_coverage_unref "void pango_coverage_unref(PangoCoverage* coverage)"
  XEN_ASSERT_TYPE(XEN_PangoCoverage__P(coverage), coverage, 1, "pango_coverage_unref", "PangoCoverage*");
  pango_coverage_unref(XEN_TO_C_PangoCoverage_(coverage));
  return(XEN_FALSE);
}
static XEN gxg_pango_coverage_copy(XEN coverage)
{
  #define H_pango_coverage_copy "PangoCoverage* pango_coverage_copy(PangoCoverage* coverage)"
  XEN_ASSERT_TYPE(XEN_PangoCoverage__P(coverage), coverage, 1, "pango_coverage_copy", "PangoCoverage*");
  return(C_TO_XEN_PangoCoverage_(pango_coverage_copy(XEN_TO_C_PangoCoverage_(coverage))));
}
static XEN gxg_pango_coverage_get(XEN coverage, XEN index)
{
  #define H_pango_coverage_get "PangoCoverageLevel pango_coverage_get(PangoCoverage* coverage, int index)"
  XEN_ASSERT_TYPE(XEN_PangoCoverage__P(coverage), coverage, 1, "pango_coverage_get", "PangoCoverage*");
  XEN_ASSERT_TYPE(XEN_int_P(index), index, 2, "pango_coverage_get", "int");
  return(C_TO_XEN_PangoCoverageLevel(pango_coverage_get(XEN_TO_C_PangoCoverage_(coverage), XEN_TO_C_int(index))));
}
static XEN gxg_pango_coverage_set(XEN coverage, XEN index, XEN level)
{
  #define H_pango_coverage_set "void pango_coverage_set(PangoCoverage* coverage, int index, PangoCoverageLevel level)"
  XEN_ASSERT_TYPE(XEN_PangoCoverage__P(coverage), coverage, 1, "pango_coverage_set", "PangoCoverage*");
  XEN_ASSERT_TYPE(XEN_int_P(index), index, 2, "pango_coverage_set", "int");
  XEN_ASSERT_TYPE(XEN_PangoCoverageLevel_P(level), level, 3, "pango_coverage_set", "PangoCoverageLevel");
  pango_coverage_set(XEN_TO_C_PangoCoverage_(coverage), XEN_TO_C_int(index), XEN_TO_C_PangoCoverageLevel(level));
  return(XEN_FALSE);
}
static XEN gxg_pango_coverage_max(XEN coverage, XEN other)
{
  #define H_pango_coverage_max "void pango_coverage_max(PangoCoverage* coverage, PangoCoverage* other)"
  XEN_ASSERT_TYPE(XEN_PangoCoverage__P(coverage), coverage, 1, "pango_coverage_max", "PangoCoverage*");
  XEN_ASSERT_TYPE(XEN_PangoCoverage__P(other), other, 2, "pango_coverage_max", "PangoCoverage*");
  pango_coverage_max(XEN_TO_C_PangoCoverage_(coverage), XEN_TO_C_PangoCoverage_(other));
  return(XEN_FALSE);
}
static XEN gxg_pango_coverage_to_bytes(XEN coverage, XEN bytes, XEN n_bytes)
{
  #define H_pango_coverage_to_bytes "void pango_coverage_to_bytes(PangoCoverage* coverage, guchar** [bytes], \
int* [n_bytes])"
  guchar* ref_bytes = NULL;
  int ref_n_bytes;
  XEN_ASSERT_TYPE(XEN_PangoCoverage__P(coverage), coverage, 1, "pango_coverage_to_bytes", "PangoCoverage*");
  pango_coverage_to_bytes(XEN_TO_C_PangoCoverage_(coverage), &ref_bytes, &ref_n_bytes);
  return(XEN_LIST_2(C_TO_XEN_guchar_(ref_bytes), C_TO_XEN_int(ref_n_bytes)));
}
static XEN gxg_pango_coverage_from_bytes(XEN bytes, XEN n_bytes)
{
  #define H_pango_coverage_from_bytes "PangoCoverage* pango_coverage_from_bytes(guchar* bytes, int n_bytes)"
  XEN_ASSERT_TYPE(XEN_guchar__P(bytes), bytes, 1, "pango_coverage_from_bytes", "guchar*");
  XEN_ASSERT_TYPE(XEN_int_P(n_bytes), n_bytes, 2, "pango_coverage_from_bytes", "int");
  return(C_TO_XEN_PangoCoverage_(pango_coverage_from_bytes(XEN_TO_C_guchar_(bytes), XEN_TO_C_int(n_bytes))));
}
static XEN gxg_pango_attr_type_get_type(void)
{
  #define H_pango_attr_type_get_type "GType pango_attr_type_get_type( void)"
  return(C_TO_XEN_GType(pango_attr_type_get_type()));
}
static XEN gxg_pango_underline_get_type(void)
{
  #define H_pango_underline_get_type "GType pango_underline_get_type( void)"
  return(C_TO_XEN_GType(pango_underline_get_type()));
}
static XEN gxg_pango_coverage_level_get_type(void)
{
  #define H_pango_coverage_level_get_type "GType pango_coverage_level_get_type( void)"
  return(C_TO_XEN_GType(pango_coverage_level_get_type()));
}
static XEN gxg_pango_style_get_type(void)
{
  #define H_pango_style_get_type "GType pango_style_get_type( void)"
  return(C_TO_XEN_GType(pango_style_get_type()));
}
static XEN gxg_pango_variant_get_type(void)
{
  #define H_pango_variant_get_type "GType pango_variant_get_type( void)"
  return(C_TO_XEN_GType(pango_variant_get_type()));
}
static XEN gxg_pango_weight_get_type(void)
{
  #define H_pango_weight_get_type "GType pango_weight_get_type( void)"
  return(C_TO_XEN_GType(pango_weight_get_type()));
}
static XEN gxg_pango_stretch_get_type(void)
{
  #define H_pango_stretch_get_type "GType pango_stretch_get_type( void)"
  return(C_TO_XEN_GType(pango_stretch_get_type()));
}
static XEN gxg_pango_font_mask_get_type(void)
{
  #define H_pango_font_mask_get_type "GType pango_font_mask_get_type( void)"
  return(C_TO_XEN_GType(pango_font_mask_get_type()));
}
static XEN gxg_pango_alignment_get_type(void)
{
  #define H_pango_alignment_get_type "GType pango_alignment_get_type( void)"
  return(C_TO_XEN_GType(pango_alignment_get_type()));
}
static XEN gxg_pango_wrap_mode_get_type(void)
{
  #define H_pango_wrap_mode_get_type "GType pango_wrap_mode_get_type( void)"
  return(C_TO_XEN_GType(pango_wrap_mode_get_type()));
}
static XEN gxg_pango_tab_align_get_type(void)
{
  #define H_pango_tab_align_get_type "GType pango_tab_align_get_type( void)"
  return(C_TO_XEN_GType(pango_tab_align_get_type()));
}
static XEN gxg_pango_direction_get_type(void)
{
  #define H_pango_direction_get_type "GType pango_direction_get_type( void)"
  return(C_TO_XEN_GType(pango_direction_get_type()));
}
static XEN gxg_pango_font_description_get_type(void)
{
  #define H_pango_font_description_get_type "GType pango_font_description_get_type( void)"
  return(C_TO_XEN_GType(pango_font_description_get_type()));
}
static XEN gxg_pango_font_description_new(void)
{
  #define H_pango_font_description_new "PangoFontDescription* pango_font_description_new( void)"
  return(C_TO_XEN_PangoFontDescription_(pango_font_description_new()));
}
static XEN gxg_pango_font_description_copy(XEN desc)
{
  #define H_pango_font_description_copy "PangoFontDescription* pango_font_description_copy(PangoFontDescription* desc)"
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 1, "pango_font_description_copy", "PangoFontDescription*");
  return(C_TO_XEN_PangoFontDescription_(pango_font_description_copy(XEN_TO_C_PangoFontDescription_(desc))));
}
static XEN gxg_pango_font_description_copy_static(XEN desc)
{
  #define H_pango_font_description_copy_static "PangoFontDescription* pango_font_description_copy_static(PangoFontDescription* desc)"
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 1, "pango_font_description_copy_static", "PangoFontDescription*");
  return(C_TO_XEN_PangoFontDescription_(pango_font_description_copy_static(XEN_TO_C_PangoFontDescription_(desc))));
}
static XEN gxg_pango_font_description_hash(XEN desc)
{
  #define H_pango_font_description_hash "guint pango_font_description_hash(PangoFontDescription* desc)"
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 1, "pango_font_description_hash", "PangoFontDescription*");
  return(C_TO_XEN_guint(pango_font_description_hash(XEN_TO_C_PangoFontDescription_(desc))));
}
static XEN gxg_pango_font_description_equal(XEN desc1, XEN desc2)
{
  #define H_pango_font_description_equal "gboolean pango_font_description_equal(PangoFontDescription* desc1, \
PangoFontDescription* desc2)"
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc1), desc1, 1, "pango_font_description_equal", "PangoFontDescription*");
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc2), desc2, 2, "pango_font_description_equal", "PangoFontDescription*");
  return(C_TO_XEN_gboolean(pango_font_description_equal(XEN_TO_C_PangoFontDescription_(desc1), XEN_TO_C_PangoFontDescription_(desc2))));
}
static XEN gxg_pango_font_description_free(XEN desc)
{
  #define H_pango_font_description_free "void pango_font_description_free(PangoFontDescription* desc)"
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 1, "pango_font_description_free", "PangoFontDescription*");
  pango_font_description_free(XEN_TO_C_PangoFontDescription_(desc));
  return(XEN_FALSE);
}
static XEN gxg_pango_font_descriptions_free(XEN descs, XEN n_descs)
{
  #define H_pango_font_descriptions_free "void pango_font_descriptions_free(PangoFontDescription** descs, \
int n_descs)"
  XEN_ASSERT_TYPE(XEN_PangoFontDescription___P(descs), descs, 1, "pango_font_descriptions_free", "PangoFontDescription**");
  XEN_ASSERT_TYPE(XEN_int_P(n_descs), n_descs, 2, "pango_font_descriptions_free", "int");
  pango_font_descriptions_free(XEN_TO_C_PangoFontDescription__(descs), XEN_TO_C_int(n_descs));
  return(XEN_FALSE);
}
static XEN gxg_pango_font_description_set_family(XEN desc, XEN family)
{
  #define H_pango_font_description_set_family "void pango_font_description_set_family(PangoFontDescription* desc, \
char* family)"
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 1, "pango_font_description_set_family", "PangoFontDescription*");
  XEN_ASSERT_TYPE(XEN_char__P(family), family, 2, "pango_font_description_set_family", "char*");
  pango_font_description_set_family(XEN_TO_C_PangoFontDescription_(desc), XEN_TO_C_char_(family));
  return(XEN_FALSE);
}
static XEN gxg_pango_font_description_set_family_static(XEN desc, XEN family)
{
  #define H_pango_font_description_set_family_static "void pango_font_description_set_family_static(PangoFontDescription* desc, \
char* family)"
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 1, "pango_font_description_set_family_static", "PangoFontDescription*");
  XEN_ASSERT_TYPE(XEN_char__P(family), family, 2, "pango_font_description_set_family_static", "char*");
  pango_font_description_set_family_static(XEN_TO_C_PangoFontDescription_(desc), XEN_TO_C_char_(family));
  return(XEN_FALSE);
}
static XEN gxg_pango_font_description_get_family(XEN desc)
{
  #define H_pango_font_description_get_family "char* pango_font_description_get_family(PangoFontDescription* desc)"
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 1, "pango_font_description_get_family", "PangoFontDescription*");
  return(C_TO_XEN_char_(pango_font_description_get_family(XEN_TO_C_PangoFontDescription_(desc))));
}
static XEN gxg_pango_font_description_set_style(XEN desc, XEN style)
{
  #define H_pango_font_description_set_style "void pango_font_description_set_style(PangoFontDescription* desc, \
PangoStyle style)"
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 1, "pango_font_description_set_style", "PangoFontDescription*");
  XEN_ASSERT_TYPE(XEN_PangoStyle_P(style), style, 2, "pango_font_description_set_style", "PangoStyle");
  pango_font_description_set_style(XEN_TO_C_PangoFontDescription_(desc), XEN_TO_C_PangoStyle(style));
  return(XEN_FALSE);
}
static XEN gxg_pango_font_description_get_style(XEN desc)
{
  #define H_pango_font_description_get_style "PangoStyle pango_font_description_get_style(PangoFontDescription* desc)"
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 1, "pango_font_description_get_style", "PangoFontDescription*");
  return(C_TO_XEN_PangoStyle(pango_font_description_get_style(XEN_TO_C_PangoFontDescription_(desc))));
}
static XEN gxg_pango_font_description_set_variant(XEN desc, XEN variant)
{
  #define H_pango_font_description_set_variant "void pango_font_description_set_variant(PangoFontDescription* desc, \
PangoVariant variant)"
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 1, "pango_font_description_set_variant", "PangoFontDescription*");
  XEN_ASSERT_TYPE(XEN_PangoVariant_P(variant), variant, 2, "pango_font_description_set_variant", "PangoVariant");
  pango_font_description_set_variant(XEN_TO_C_PangoFontDescription_(desc), XEN_TO_C_PangoVariant(variant));
  return(XEN_FALSE);
}
static XEN gxg_pango_font_description_get_variant(XEN desc)
{
  #define H_pango_font_description_get_variant "PangoVariant pango_font_description_get_variant(PangoFontDescription* desc)"
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 1, "pango_font_description_get_variant", "PangoFontDescription*");
  return(C_TO_XEN_PangoVariant(pango_font_description_get_variant(XEN_TO_C_PangoFontDescription_(desc))));
}
static XEN gxg_pango_font_description_set_weight(XEN desc, XEN weight)
{
  #define H_pango_font_description_set_weight "void pango_font_description_set_weight(PangoFontDescription* desc, \
PangoWeight weight)"
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 1, "pango_font_description_set_weight", "PangoFontDescription*");
  XEN_ASSERT_TYPE(XEN_PangoWeight_P(weight), weight, 2, "pango_font_description_set_weight", "PangoWeight");
  pango_font_description_set_weight(XEN_TO_C_PangoFontDescription_(desc), XEN_TO_C_PangoWeight(weight));
  return(XEN_FALSE);
}
static XEN gxg_pango_font_description_get_weight(XEN desc)
{
  #define H_pango_font_description_get_weight "PangoWeight pango_font_description_get_weight(PangoFontDescription* desc)"
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 1, "pango_font_description_get_weight", "PangoFontDescription*");
  return(C_TO_XEN_PangoWeight(pango_font_description_get_weight(XEN_TO_C_PangoFontDescription_(desc))));
}
static XEN gxg_pango_font_description_set_stretch(XEN desc, XEN stretch)
{
  #define H_pango_font_description_set_stretch "void pango_font_description_set_stretch(PangoFontDescription* desc, \
PangoStretch stretch)"
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 1, "pango_font_description_set_stretch", "PangoFontDescription*");
  XEN_ASSERT_TYPE(XEN_PangoStretch_P(stretch), stretch, 2, "pango_font_description_set_stretch", "PangoStretch");
  pango_font_description_set_stretch(XEN_TO_C_PangoFontDescription_(desc), XEN_TO_C_PangoStretch(stretch));
  return(XEN_FALSE);
}
static XEN gxg_pango_font_description_get_stretch(XEN desc)
{
  #define H_pango_font_description_get_stretch "PangoStretch pango_font_description_get_stretch(PangoFontDescription* desc)"
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 1, "pango_font_description_get_stretch", "PangoFontDescription*");
  return(C_TO_XEN_PangoStretch(pango_font_description_get_stretch(XEN_TO_C_PangoFontDescription_(desc))));
}
static XEN gxg_pango_font_description_set_size(XEN desc, XEN size)
{
  #define H_pango_font_description_set_size "void pango_font_description_set_size(PangoFontDescription* desc, \
gint size)"
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 1, "pango_font_description_set_size", "PangoFontDescription*");
  XEN_ASSERT_TYPE(XEN_gint_P(size), size, 2, "pango_font_description_set_size", "gint");
  pango_font_description_set_size(XEN_TO_C_PangoFontDescription_(desc), XEN_TO_C_gint(size));
  return(XEN_FALSE);
}
static XEN gxg_pango_font_description_get_size(XEN desc)
{
  #define H_pango_font_description_get_size "gint pango_font_description_get_size(PangoFontDescription* desc)"
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 1, "pango_font_description_get_size", "PangoFontDescription*");
  return(C_TO_XEN_gint(pango_font_description_get_size(XEN_TO_C_PangoFontDescription_(desc))));
}
static XEN gxg_pango_font_description_get_set_fields(XEN desc)
{
  #define H_pango_font_description_get_set_fields "PangoFontMask pango_font_description_get_set_fields(PangoFontDescription* desc)"
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 1, "pango_font_description_get_set_fields", "PangoFontDescription*");
  return(C_TO_XEN_PangoFontMask(pango_font_description_get_set_fields(XEN_TO_C_PangoFontDescription_(desc))));
}
static XEN gxg_pango_font_description_unset_fields(XEN desc, XEN to_unset)
{
  #define H_pango_font_description_unset_fields "void pango_font_description_unset_fields(PangoFontDescription* desc, \
PangoFontMask to_unset)"
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 1, "pango_font_description_unset_fields", "PangoFontDescription*");
  XEN_ASSERT_TYPE(XEN_PangoFontMask_P(to_unset), to_unset, 2, "pango_font_description_unset_fields", "PangoFontMask");
  pango_font_description_unset_fields(XEN_TO_C_PangoFontDescription_(desc), XEN_TO_C_PangoFontMask(to_unset));
  return(XEN_FALSE);
}
static XEN gxg_pango_font_description_merge(XEN desc, XEN desc_to_merge, XEN replace_existing)
{
  #define H_pango_font_description_merge "void pango_font_description_merge(PangoFontDescription* desc, \
PangoFontDescription* desc_to_merge, gboolean replace_existing)"
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 1, "pango_font_description_merge", "PangoFontDescription*");
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc_to_merge), desc_to_merge, 2, "pango_font_description_merge", "PangoFontDescription*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(replace_existing), replace_existing, 3, "pango_font_description_merge", "gboolean");
  pango_font_description_merge(XEN_TO_C_PangoFontDescription_(desc), XEN_TO_C_PangoFontDescription_(desc_to_merge), XEN_TO_C_gboolean(replace_existing));
  return(XEN_FALSE);
}
static XEN gxg_pango_font_description_merge_static(XEN desc, XEN desc_to_merge, XEN replace_existing)
{
  #define H_pango_font_description_merge_static "void pango_font_description_merge_static(PangoFontDescription* desc, \
PangoFontDescription* desc_to_merge, gboolean replace_existing)"
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 1, "pango_font_description_merge_static", "PangoFontDescription*");
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc_to_merge), desc_to_merge, 2, "pango_font_description_merge_static", "PangoFontDescription*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(replace_existing), replace_existing, 3, "pango_font_description_merge_static", "gboolean");
  pango_font_description_merge_static(XEN_TO_C_PangoFontDescription_(desc), XEN_TO_C_PangoFontDescription_(desc_to_merge), 
                                      XEN_TO_C_gboolean(replace_existing));
  return(XEN_FALSE);
}
static XEN gxg_pango_font_description_better_match(XEN desc, XEN old_match, XEN new_match)
{
  #define H_pango_font_description_better_match "gboolean pango_font_description_better_match(PangoFontDescription* desc, \
PangoFontDescription* old_match, PangoFontDescription* new_match)"
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 1, "pango_font_description_better_match", "PangoFontDescription*");
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(old_match), old_match, 2, "pango_font_description_better_match", "PangoFontDescription*");
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(new_match), new_match, 3, "pango_font_description_better_match", "PangoFontDescription*");
  return(C_TO_XEN_gboolean(pango_font_description_better_match(XEN_TO_C_PangoFontDescription_(desc), XEN_TO_C_PangoFontDescription_(old_match), 
                                                               XEN_TO_C_PangoFontDescription_(new_match))));
}
static XEN gxg_pango_font_description_from_string(XEN str)
{
  #define H_pango_font_description_from_string "PangoFontDescription* pango_font_description_from_string(char* str)"
  XEN_ASSERT_TYPE(XEN_char__P(str), str, 1, "pango_font_description_from_string", "char*");
  return(C_TO_XEN_PangoFontDescription_(pango_font_description_from_string(XEN_TO_C_char_(str))));
}
static XEN gxg_pango_font_description_to_string(XEN desc)
{
  #define H_pango_font_description_to_string "char* pango_font_description_to_string(PangoFontDescription* desc)"
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 1, "pango_font_description_to_string", "PangoFontDescription*");
  return(C_TO_XEN_char_(pango_font_description_to_string(XEN_TO_C_PangoFontDescription_(desc))));
}
static XEN gxg_pango_font_description_to_filename(XEN desc)
{
  #define H_pango_font_description_to_filename "char* pango_font_description_to_filename(PangoFontDescription* desc)"
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 1, "pango_font_description_to_filename", "PangoFontDescription*");
  return(C_TO_XEN_char_(pango_font_description_to_filename(XEN_TO_C_PangoFontDescription_(desc))));
}
static XEN gxg_pango_font_metrics_get_type(void)
{
  #define H_pango_font_metrics_get_type "GType pango_font_metrics_get_type( void)"
  return(C_TO_XEN_GType(pango_font_metrics_get_type()));
}
static XEN gxg_pango_font_metrics_ref(XEN metrics)
{
  #define H_pango_font_metrics_ref "PangoFontMetrics* pango_font_metrics_ref(PangoFontMetrics* metrics)"
  XEN_ASSERT_TYPE(XEN_PangoFontMetrics__P(metrics), metrics, 1, "pango_font_metrics_ref", "PangoFontMetrics*");
  return(C_TO_XEN_PangoFontMetrics_(pango_font_metrics_ref(XEN_TO_C_PangoFontMetrics_(metrics))));
}
static XEN gxg_pango_font_metrics_unref(XEN metrics)
{
  #define H_pango_font_metrics_unref "void pango_font_metrics_unref(PangoFontMetrics* metrics)"
  XEN_ASSERT_TYPE(XEN_PangoFontMetrics__P(metrics), metrics, 1, "pango_font_metrics_unref", "PangoFontMetrics*");
  pango_font_metrics_unref(XEN_TO_C_PangoFontMetrics_(metrics));
  return(XEN_FALSE);
}
static XEN gxg_pango_font_metrics_get_ascent(XEN metrics)
{
  #define H_pango_font_metrics_get_ascent "int pango_font_metrics_get_ascent(PangoFontMetrics* metrics)"
  XEN_ASSERT_TYPE(XEN_PangoFontMetrics__P(metrics), metrics, 1, "pango_font_metrics_get_ascent", "PangoFontMetrics*");
  return(C_TO_XEN_int(pango_font_metrics_get_ascent(XEN_TO_C_PangoFontMetrics_(metrics))));
}
static XEN gxg_pango_font_metrics_get_descent(XEN metrics)
{
  #define H_pango_font_metrics_get_descent "int pango_font_metrics_get_descent(PangoFontMetrics* metrics)"
  XEN_ASSERT_TYPE(XEN_PangoFontMetrics__P(metrics), metrics, 1, "pango_font_metrics_get_descent", "PangoFontMetrics*");
  return(C_TO_XEN_int(pango_font_metrics_get_descent(XEN_TO_C_PangoFontMetrics_(metrics))));
}
static XEN gxg_pango_font_metrics_get_approximate_char_width(XEN metrics)
{
  #define H_pango_font_metrics_get_approximate_char_width "int pango_font_metrics_get_approximate_char_width(PangoFontMetrics* metrics)"
  XEN_ASSERT_TYPE(XEN_PangoFontMetrics__P(metrics), metrics, 1, "pango_font_metrics_get_approximate_char_width", "PangoFontMetrics*");
  return(C_TO_XEN_int(pango_font_metrics_get_approximate_char_width(XEN_TO_C_PangoFontMetrics_(metrics))));
}
static XEN gxg_pango_font_metrics_get_approximate_digit_width(XEN metrics)
{
  #define H_pango_font_metrics_get_approximate_digit_width "int pango_font_metrics_get_approximate_digit_width(PangoFontMetrics* metrics)"
  XEN_ASSERT_TYPE(XEN_PangoFontMetrics__P(metrics), metrics, 1, "pango_font_metrics_get_approximate_digit_width", "PangoFontMetrics*");
  return(C_TO_XEN_int(pango_font_metrics_get_approximate_digit_width(XEN_TO_C_PangoFontMetrics_(metrics))));
}
static XEN gxg_pango_font_family_get_type(void)
{
  #define H_pango_font_family_get_type "GType pango_font_family_get_type( void)"
  return(C_TO_XEN_GType(pango_font_family_get_type()));
}
static XEN gxg_pango_font_family_list_faces(XEN family, XEN faces, XEN n_faces)
{
  #define H_pango_font_family_list_faces "void pango_font_family_list_faces(PangoFontFamily* family, \
PangoFontFace*** [faces], int* [n_faces])"
  PangoFontFace** ref_faces = NULL;
  int ref_n_faces;
  XEN_ASSERT_TYPE(XEN_PangoFontFamily__P(family), family, 1, "pango_font_family_list_faces", "PangoFontFamily*");
  pango_font_family_list_faces(XEN_TO_C_PangoFontFamily_(family), &ref_faces, &ref_n_faces);
  return(XEN_LIST_2(C_TO_XEN_PangoFontFace__(ref_faces), C_TO_XEN_int(ref_n_faces)));
}
static XEN gxg_pango_font_family_get_name(XEN family)
{
  #define H_pango_font_family_get_name "char* pango_font_family_get_name(PangoFontFamily* family)"
  XEN_ASSERT_TYPE(XEN_PangoFontFamily__P(family), family, 1, "pango_font_family_get_name", "PangoFontFamily*");
  return(C_TO_XEN_char_(pango_font_family_get_name(XEN_TO_C_PangoFontFamily_(family))));
}
static XEN gxg_pango_font_face_get_type(void)
{
  #define H_pango_font_face_get_type "GType pango_font_face_get_type( void)"
  return(C_TO_XEN_GType(pango_font_face_get_type()));
}
static XEN gxg_pango_font_face_describe(XEN face)
{
  #define H_pango_font_face_describe "PangoFontDescription* pango_font_face_describe(PangoFontFace* face)"
  XEN_ASSERT_TYPE(XEN_PangoFontFace__P(face), face, 1, "pango_font_face_describe", "PangoFontFace*");
  return(C_TO_XEN_PangoFontDescription_(pango_font_face_describe(XEN_TO_C_PangoFontFace_(face))));
}
static XEN gxg_pango_font_face_get_face_name(XEN face)
{
  #define H_pango_font_face_get_face_name "char* pango_font_face_get_face_name(PangoFontFace* face)"
  XEN_ASSERT_TYPE(XEN_PangoFontFace__P(face), face, 1, "pango_font_face_get_face_name", "PangoFontFace*");
  return(C_TO_XEN_char_(pango_font_face_get_face_name(XEN_TO_C_PangoFontFace_(face))));
}
static XEN gxg_pango_font_get_type(void)
{
  #define H_pango_font_get_type "GType pango_font_get_type( void)"
  return(C_TO_XEN_GType(pango_font_get_type()));
}
static XEN gxg_pango_font_describe(XEN font)
{
  #define H_pango_font_describe "PangoFontDescription* pango_font_describe(PangoFont* font)"
  XEN_ASSERT_TYPE(XEN_PangoFont__P(font), font, 1, "pango_font_describe", "PangoFont*");
  return(C_TO_XEN_PangoFontDescription_(pango_font_describe(XEN_TO_C_PangoFont_(font))));
}
static XEN gxg_pango_font_get_coverage(XEN font, XEN language)
{
  #define H_pango_font_get_coverage "PangoCoverage* pango_font_get_coverage(PangoFont* font, PangoLanguage* language)"
  XEN_ASSERT_TYPE(XEN_PangoFont__P(font), font, 1, "pango_font_get_coverage", "PangoFont*");
  XEN_ASSERT_TYPE(XEN_PangoLanguage__P(language), language, 2, "pango_font_get_coverage", "PangoLanguage*");
  return(C_TO_XEN_PangoCoverage_(pango_font_get_coverage(XEN_TO_C_PangoFont_(font), XEN_TO_C_PangoLanguage_(language))));
}
static XEN gxg_pango_font_get_metrics(XEN font, XEN language)
{
  #define H_pango_font_get_metrics "PangoFontMetrics* pango_font_get_metrics(PangoFont* font, PangoLanguage* language)"
  XEN_ASSERT_TYPE(XEN_PangoFont__P(font), font, 1, "pango_font_get_metrics", "PangoFont*");
  XEN_ASSERT_TYPE(XEN_PangoLanguage__P(language), language, 2, "pango_font_get_metrics", "PangoLanguage*");
  return(C_TO_XEN_PangoFontMetrics_(pango_font_get_metrics(XEN_TO_C_PangoFont_(font), XEN_TO_C_PangoLanguage_(language))));
}
static XEN gxg_pango_font_get_glyph_extents(XEN font, XEN glyph, XEN ink_rect, XEN logical_rect)
{
  #define H_pango_font_get_glyph_extents "void pango_font_get_glyph_extents(PangoFont* font, PangoGlyph glyph, \
PangoRectangle* ink_rect, PangoRectangle* logical_rect)"
  XEN_ASSERT_TYPE(XEN_PangoFont__P(font), font, 1, "pango_font_get_glyph_extents", "PangoFont*");
  XEN_ASSERT_TYPE(XEN_PangoGlyph_P(glyph), glyph, 2, "pango_font_get_glyph_extents", "PangoGlyph");
  XEN_ASSERT_TYPE(XEN_PangoRectangle__P(ink_rect), ink_rect, 3, "pango_font_get_glyph_extents", "PangoRectangle*");
  XEN_ASSERT_TYPE(XEN_PangoRectangle__P(logical_rect), logical_rect, 4, "pango_font_get_glyph_extents", "PangoRectangle*");
  pango_font_get_glyph_extents(XEN_TO_C_PangoFont_(font), XEN_TO_C_PangoGlyph(glyph), XEN_TO_C_PangoRectangle_(ink_rect), 
                               XEN_TO_C_PangoRectangle_(logical_rect));
  return(XEN_FALSE);
}
static XEN gxg_pango_font_map_get_type(void)
{
  #define H_pango_font_map_get_type "GType pango_font_map_get_type( void)"
  return(C_TO_XEN_GType(pango_font_map_get_type()));
}
static XEN gxg_pango_font_map_load_font(XEN fontmap, XEN context, XEN desc)
{
  #define H_pango_font_map_load_font "PangoFont* pango_font_map_load_font(PangoFontMap* fontmap, PangoContext* context, \
PangoFontDescription* desc)"
  XEN_ASSERT_TYPE(XEN_PangoFontMap__P(fontmap), fontmap, 1, "pango_font_map_load_font", "PangoFontMap*");
  XEN_ASSERT_TYPE(XEN_PangoContext__P(context), context, 2, "pango_font_map_load_font", "PangoContext*");
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 3, "pango_font_map_load_font", "PangoFontDescription*");
  return(C_TO_XEN_PangoFont_(pango_font_map_load_font(XEN_TO_C_PangoFontMap_(fontmap), XEN_TO_C_PangoContext_(context), XEN_TO_C_PangoFontDescription_(desc))));
}
static XEN gxg_pango_font_map_load_fontset(XEN fontmap, XEN context, XEN desc, XEN language)
{
  #define H_pango_font_map_load_fontset "PangoFontset* pango_font_map_load_fontset(PangoFontMap* fontmap, \
PangoContext* context, PangoFontDescription* desc, PangoLanguage* language)"
  XEN_ASSERT_TYPE(XEN_PangoFontMap__P(fontmap), fontmap, 1, "pango_font_map_load_fontset", "PangoFontMap*");
  XEN_ASSERT_TYPE(XEN_PangoContext__P(context), context, 2, "pango_font_map_load_fontset", "PangoContext*");
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 3, "pango_font_map_load_fontset", "PangoFontDescription*");
  XEN_ASSERT_TYPE(XEN_PangoLanguage__P(language), language, 4, "pango_font_map_load_fontset", "PangoLanguage*");
  return(C_TO_XEN_PangoFontset_(pango_font_map_load_fontset(XEN_TO_C_PangoFontMap_(fontmap), XEN_TO_C_PangoContext_(context), 
                                                            XEN_TO_C_PangoFontDescription_(desc), XEN_TO_C_PangoLanguage_(language))));
}
static XEN gxg_pango_font_map_list_families(XEN fontmap, XEN families, XEN n_families)
{
  #define H_pango_font_map_list_families "void pango_font_map_list_families(PangoFontMap* fontmap, PangoFontFamily*** [families], \
int* [n_families])"
  PangoFontFamily** ref_families = NULL;
  int ref_n_families;
  XEN_ASSERT_TYPE(XEN_PangoFontMap__P(fontmap), fontmap, 1, "pango_font_map_list_families", "PangoFontMap*");
  pango_font_map_list_families(XEN_TO_C_PangoFontMap_(fontmap), &ref_families, &ref_n_families);
  return(XEN_LIST_2(C_TO_XEN_PangoFontFamily__(ref_families), C_TO_XEN_int(ref_n_families)));
}
static XEN gxg_pango_glyph_string_new(void)
{
  #define H_pango_glyph_string_new "PangoGlyphString* pango_glyph_string_new( void)"
  return(C_TO_XEN_PangoGlyphString_(pango_glyph_string_new()));
}
static XEN gxg_pango_glyph_string_set_size(XEN string, XEN new_len)
{
  #define H_pango_glyph_string_set_size "void pango_glyph_string_set_size(PangoGlyphString* string, gint new_len)"
  XEN_ASSERT_TYPE(XEN_PangoGlyphString__P(string), string, 1, "pango_glyph_string_set_size", "PangoGlyphString*");
  XEN_ASSERT_TYPE(XEN_gint_P(new_len), new_len, 2, "pango_glyph_string_set_size", "gint");
  pango_glyph_string_set_size(XEN_TO_C_PangoGlyphString_(string), XEN_TO_C_gint(new_len));
  return(XEN_FALSE);
}
static XEN gxg_pango_glyph_string_get_type(void)
{
  #define H_pango_glyph_string_get_type "GType pango_glyph_string_get_type( void)"
  return(C_TO_XEN_GType(pango_glyph_string_get_type()));
}
static XEN gxg_pango_glyph_string_copy(XEN string)
{
  #define H_pango_glyph_string_copy "PangoGlyphString* pango_glyph_string_copy(PangoGlyphString* string)"
  XEN_ASSERT_TYPE(XEN_PangoGlyphString__P(string), string, 1, "pango_glyph_string_copy", "PangoGlyphString*");
  return(C_TO_XEN_PangoGlyphString_(pango_glyph_string_copy(XEN_TO_C_PangoGlyphString_(string))));
}
static XEN gxg_pango_glyph_string_free(XEN string)
{
  #define H_pango_glyph_string_free "void pango_glyph_string_free(PangoGlyphString* string)"
  XEN_ASSERT_TYPE(XEN_PangoGlyphString__P(string), string, 1, "pango_glyph_string_free", "PangoGlyphString*");
  pango_glyph_string_free(XEN_TO_C_PangoGlyphString_(string));
  return(XEN_FALSE);
}
static XEN gxg_pango_glyph_string_extents(XEN glyphs, XEN font, XEN ink_rect, XEN logical_rect)
{
  #define H_pango_glyph_string_extents "void pango_glyph_string_extents(PangoGlyphString* glyphs, PangoFont* font, \
PangoRectangle* ink_rect, PangoRectangle* logical_rect)"
  XEN_ASSERT_TYPE(XEN_PangoGlyphString__P(glyphs), glyphs, 1, "pango_glyph_string_extents", "PangoGlyphString*");
  XEN_ASSERT_TYPE(XEN_PangoFont__P(font), font, 2, "pango_glyph_string_extents", "PangoFont*");
  XEN_ASSERT_TYPE(XEN_PangoRectangle__P(ink_rect), ink_rect, 3, "pango_glyph_string_extents", "PangoRectangle*");
  XEN_ASSERT_TYPE(XEN_PangoRectangle__P(logical_rect), logical_rect, 4, "pango_glyph_string_extents", "PangoRectangle*");
  pango_glyph_string_extents(XEN_TO_C_PangoGlyphString_(glyphs), XEN_TO_C_PangoFont_(font), XEN_TO_C_PangoRectangle_(ink_rect), 
                             XEN_TO_C_PangoRectangle_(logical_rect));
  return(XEN_FALSE);
}
static XEN gxg_pango_glyph_string_extents_range(XEN glyphs, XEN start, XEN end, XEN font, XEN ink_rect, XEN logical_rect)
{
  #define H_pango_glyph_string_extents_range "void pango_glyph_string_extents_range(PangoGlyphString* glyphs, \
int start, int end, PangoFont* font, PangoRectangle* ink_rect, PangoRectangle* logical_rect)"
  XEN_ASSERT_TYPE(XEN_PangoGlyphString__P(glyphs), glyphs, 1, "pango_glyph_string_extents_range", "PangoGlyphString*");
  XEN_ASSERT_TYPE(XEN_int_P(start), start, 2, "pango_glyph_string_extents_range", "int");
  XEN_ASSERT_TYPE(XEN_int_P(end), end, 3, "pango_glyph_string_extents_range", "int");
  XEN_ASSERT_TYPE(XEN_PangoFont__P(font), font, 4, "pango_glyph_string_extents_range", "PangoFont*");
  XEN_ASSERT_TYPE(XEN_PangoRectangle__P(ink_rect), ink_rect, 5, "pango_glyph_string_extents_range", "PangoRectangle*");
  XEN_ASSERT_TYPE(XEN_PangoRectangle__P(logical_rect), logical_rect, 6, "pango_glyph_string_extents_range", "PangoRectangle*");
  pango_glyph_string_extents_range(XEN_TO_C_PangoGlyphString_(glyphs), XEN_TO_C_int(start), XEN_TO_C_int(end), XEN_TO_C_PangoFont_(font), 
                                   XEN_TO_C_PangoRectangle_(ink_rect), XEN_TO_C_PangoRectangle_(logical_rect));
  return(XEN_FALSE);
}
static XEN gxg_pango_glyph_string_get_logical_widths(XEN glyphs, XEN text, XEN length, XEN embedding_level, XEN logical_widths)
{
  #define H_pango_glyph_string_get_logical_widths "void pango_glyph_string_get_logical_widths(PangoGlyphString* glyphs, \
char* text, int length, int embedding_level, int* [logical_widths])"
  int ref_logical_widths;
  XEN_ASSERT_TYPE(XEN_PangoGlyphString__P(glyphs), glyphs, 1, "pango_glyph_string_get_logical_widths", "PangoGlyphString*");
  XEN_ASSERT_TYPE(XEN_char__P(text), text, 2, "pango_glyph_string_get_logical_widths", "char*");
  XEN_ASSERT_TYPE(XEN_int_P(length), length, 3, "pango_glyph_string_get_logical_widths", "int");
  XEN_ASSERT_TYPE(XEN_int_P(embedding_level), embedding_level, 4, "pango_glyph_string_get_logical_widths", "int");
  pango_glyph_string_get_logical_widths(XEN_TO_C_PangoGlyphString_(glyphs), XEN_TO_C_char_(text), XEN_TO_C_int(length), XEN_TO_C_int(embedding_level), 
                                        &ref_logical_widths);
  return(XEN_LIST_1(C_TO_XEN_int(ref_logical_widths)));
}
static XEN gxg_pango_glyph_string_index_to_x(XEN glyphs, XEN text, XEN length, XEN analysis, XEN index, XEN trailing, XEN x_pos)
{
  #define H_pango_glyph_string_index_to_x "void pango_glyph_string_index_to_x(PangoGlyphString* glyphs, \
char* text, int length, PangoAnalysis* analysis, int index, gboolean trailing, int* [x_pos])"
  int ref_x_pos;
  XEN_ASSERT_TYPE(XEN_PangoGlyphString__P(glyphs), glyphs, 1, "pango_glyph_string_index_to_x", "PangoGlyphString*");
  XEN_ASSERT_TYPE(XEN_char__P(text), text, 2, "pango_glyph_string_index_to_x", "char*");
  XEN_ASSERT_TYPE(XEN_int_P(length), length, 3, "pango_glyph_string_index_to_x", "int");
  XEN_ASSERT_TYPE(XEN_PangoAnalysis__P(analysis), analysis, 4, "pango_glyph_string_index_to_x", "PangoAnalysis*");
  XEN_ASSERT_TYPE(XEN_int_P(index), index, 5, "pango_glyph_string_index_to_x", "int");
  XEN_ASSERT_TYPE(XEN_gboolean_P(trailing), trailing, 6, "pango_glyph_string_index_to_x", "gboolean");
  pango_glyph_string_index_to_x(XEN_TO_C_PangoGlyphString_(glyphs), XEN_TO_C_char_(text), XEN_TO_C_int(length), XEN_TO_C_PangoAnalysis_(analysis), 
                                XEN_TO_C_int(index), XEN_TO_C_gboolean(trailing), &ref_x_pos);
  return(XEN_LIST_1(C_TO_XEN_int(ref_x_pos)));
}
static XEN gxg_pango_glyph_string_x_to_index(XEN glyphs, XEN text, XEN length, XEN analysis, XEN x_pos, XEN index, XEN trailing)
{
  #define H_pango_glyph_string_x_to_index "void pango_glyph_string_x_to_index(PangoGlyphString* glyphs, \
char* text, int length, PangoAnalysis* analysis, int x_pos, int* [index], int* [trailing])"
  int ref_index;
  int ref_trailing;
  XEN_ASSERT_TYPE(XEN_PangoGlyphString__P(glyphs), glyphs, 1, "pango_glyph_string_x_to_index", "PangoGlyphString*");
  XEN_ASSERT_TYPE(XEN_char__P(text), text, 2, "pango_glyph_string_x_to_index", "char*");
  XEN_ASSERT_TYPE(XEN_int_P(length), length, 3, "pango_glyph_string_x_to_index", "int");
  XEN_ASSERT_TYPE(XEN_PangoAnalysis__P(analysis), analysis, 4, "pango_glyph_string_x_to_index", "PangoAnalysis*");
  XEN_ASSERT_TYPE(XEN_int_P(x_pos), x_pos, 5, "pango_glyph_string_x_to_index", "int");
  pango_glyph_string_x_to_index(XEN_TO_C_PangoGlyphString_(glyphs), XEN_TO_C_char_(text), XEN_TO_C_int(length), XEN_TO_C_PangoAnalysis_(analysis), 
                                XEN_TO_C_int(x_pos), &ref_index, &ref_trailing);
  return(XEN_LIST_2(C_TO_XEN_int(ref_index), C_TO_XEN_int(ref_trailing)));
}
static XEN gxg_pango_shape(XEN text, XEN length, XEN analysis, XEN glyphs)
{
  #define H_pango_shape "void pango_shape(gchar* text, gint length, PangoAnalysis* analysis, PangoGlyphString* glyphs)"
  XEN_ASSERT_TYPE(XEN_gchar__P(text), text, 1, "pango_shape", "gchar*");
  XEN_ASSERT_TYPE(XEN_gint_P(length), length, 2, "pango_shape", "gint");
  XEN_ASSERT_TYPE(XEN_PangoAnalysis__P(analysis), analysis, 3, "pango_shape", "PangoAnalysis*");
  XEN_ASSERT_TYPE(XEN_PangoGlyphString__P(glyphs), glyphs, 4, "pango_shape", "PangoGlyphString*");
  pango_shape(XEN_TO_C_gchar_(text), XEN_TO_C_gint(length), XEN_TO_C_PangoAnalysis_(analysis), XEN_TO_C_PangoGlyphString_(glyphs));
  return(XEN_FALSE);
}
static XEN gxg_pango_reorder_items(XEN logical_items)
{
  #define H_pango_reorder_items "GList* pango_reorder_items(GList* logical_items)"
  XEN_ASSERT_TYPE(XEN_GList__P(logical_items), logical_items, 1, "pango_reorder_items", "GList*");
  return(C_TO_XEN_GList_(pango_reorder_items(XEN_TO_C_GList_(logical_items))));
}
static XEN gxg_pango_item_new(void)
{
  #define H_pango_item_new "PangoItem* pango_item_new( void)"
  return(C_TO_XEN_PangoItem_(pango_item_new()));
}
static XEN gxg_pango_item_copy(XEN item)
{
  #define H_pango_item_copy "PangoItem* pango_item_copy(PangoItem* item)"
  XEN_ASSERT_TYPE(XEN_PangoItem__P(item), item, 1, "pango_item_copy", "PangoItem*");
  return(C_TO_XEN_PangoItem_(pango_item_copy(XEN_TO_C_PangoItem_(item))));
}
static XEN gxg_pango_item_free(XEN item)
{
  #define H_pango_item_free "void pango_item_free(PangoItem* item)"
  XEN_ASSERT_TYPE(XEN_PangoItem__P(item), item, 1, "pango_item_free", "PangoItem*");
  pango_item_free(XEN_TO_C_PangoItem_(item));
  return(XEN_FALSE);
}
static XEN gxg_pango_item_split(XEN orig, XEN split_index, XEN split_offset)
{
  #define H_pango_item_split "PangoItem* pango_item_split(PangoItem* orig, int split_index, int split_offset)"
  XEN_ASSERT_TYPE(XEN_PangoItem__P(orig), orig, 1, "pango_item_split", "PangoItem*");
  XEN_ASSERT_TYPE(XEN_int_P(split_index), split_index, 2, "pango_item_split", "int");
  XEN_ASSERT_TYPE(XEN_int_P(split_offset), split_offset, 3, "pango_item_split", "int");
  return(C_TO_XEN_PangoItem_(pango_item_split(XEN_TO_C_PangoItem_(orig), XEN_TO_C_int(split_index), XEN_TO_C_int(split_offset))));
}
static XEN gxg_pango_layout_get_type(void)
{
  #define H_pango_layout_get_type "GType pango_layout_get_type( void)"
  return(C_TO_XEN_GType(pango_layout_get_type()));
}
static XEN gxg_pango_layout_new(XEN context)
{
  #define H_pango_layout_new "PangoLayout* pango_layout_new(PangoContext* context)"
  XEN_ASSERT_TYPE(XEN_PangoContext__P(context), context, 1, "pango_layout_new", "PangoContext*");
  return(C_TO_XEN_PangoLayout_(pango_layout_new(XEN_TO_C_PangoContext_(context))));
}
static XEN gxg_pango_layout_copy(XEN src)
{
  #define H_pango_layout_copy "PangoLayout* pango_layout_copy(PangoLayout* src)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(src), src, 1, "pango_layout_copy", "PangoLayout*");
  return(C_TO_XEN_PangoLayout_(pango_layout_copy(XEN_TO_C_PangoLayout_(src))));
}
static XEN gxg_pango_layout_get_context(XEN layout)
{
  #define H_pango_layout_get_context "PangoContext* pango_layout_get_context(PangoLayout* layout)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_get_context", "PangoLayout*");
  return(C_TO_XEN_PangoContext_(pango_layout_get_context(XEN_TO_C_PangoLayout_(layout))));
}
static XEN gxg_pango_layout_set_attributes(XEN layout, XEN attrs)
{
  #define H_pango_layout_set_attributes "void pango_layout_set_attributes(PangoLayout* layout, PangoAttrList* attrs)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_set_attributes", "PangoLayout*");
  XEN_ASSERT_TYPE(XEN_PangoAttrList__P(attrs), attrs, 2, "pango_layout_set_attributes", "PangoAttrList*");
  pango_layout_set_attributes(XEN_TO_C_PangoLayout_(layout), XEN_TO_C_PangoAttrList_(attrs));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_get_attributes(XEN layout)
{
  #define H_pango_layout_get_attributes "PangoAttrList* pango_layout_get_attributes(PangoLayout* layout)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_get_attributes", "PangoLayout*");
  return(C_TO_XEN_PangoAttrList_(pango_layout_get_attributes(XEN_TO_C_PangoLayout_(layout))));
}
static XEN gxg_pango_layout_set_text(XEN layout, XEN text, XEN length)
{
  #define H_pango_layout_set_text "void pango_layout_set_text(PangoLayout* layout, char* text, int length)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_set_text", "PangoLayout*");
  XEN_ASSERT_TYPE(XEN_char__P(text), text, 2, "pango_layout_set_text", "char*");
  XEN_ASSERT_TYPE(XEN_int_P(length), length, 3, "pango_layout_set_text", "int");
  pango_layout_set_text(XEN_TO_C_PangoLayout_(layout), XEN_TO_C_char_(text), XEN_TO_C_int(length));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_get_text(XEN layout)
{
  #define H_pango_layout_get_text "char* pango_layout_get_text(PangoLayout* layout)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_get_text", "PangoLayout*");
  return(C_TO_XEN_char_(pango_layout_get_text(XEN_TO_C_PangoLayout_(layout))));
}
static XEN gxg_pango_layout_set_markup(XEN layout, XEN markup, XEN length)
{
  #define H_pango_layout_set_markup "void pango_layout_set_markup(PangoLayout* layout, char* markup, \
int length)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_set_markup", "PangoLayout*");
  XEN_ASSERT_TYPE(XEN_char__P(markup), markup, 2, "pango_layout_set_markup", "char*");
  XEN_ASSERT_TYPE(XEN_int_P(length), length, 3, "pango_layout_set_markup", "int");
  pango_layout_set_markup(XEN_TO_C_PangoLayout_(layout), XEN_TO_C_char_(markup), XEN_TO_C_int(length));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_set_markup_with_accel(XEN layout, XEN markup, XEN length, XEN accel_marker, XEN accel_char)
{
  #define H_pango_layout_set_markup_with_accel "void pango_layout_set_markup_with_accel(PangoLayout* layout, \
char* markup, int length, gunichar accel_marker, gunichar* accel_char)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_set_markup_with_accel", "PangoLayout*");
  XEN_ASSERT_TYPE(XEN_char__P(markup), markup, 2, "pango_layout_set_markup_with_accel", "char*");
  XEN_ASSERT_TYPE(XEN_int_P(length), length, 3, "pango_layout_set_markup_with_accel", "int");
  XEN_ASSERT_TYPE(XEN_gunichar_P(accel_marker), accel_marker, 4, "pango_layout_set_markup_with_accel", "gunichar");
  XEN_ASSERT_TYPE(XEN_gunichar__P(accel_char), accel_char, 5, "pango_layout_set_markup_with_accel", "gunichar*");
  pango_layout_set_markup_with_accel(XEN_TO_C_PangoLayout_(layout), XEN_TO_C_char_(markup), XEN_TO_C_int(length), XEN_TO_C_gunichar(accel_marker), 
                                     XEN_TO_C_gunichar_(accel_char));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_set_font_description(XEN layout, XEN desc)
{
  #define H_pango_layout_set_font_description "void pango_layout_set_font_description(PangoLayout* layout, \
PangoFontDescription* desc)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_set_font_description", "PangoLayout*");
  XEN_ASSERT_TYPE(XEN_PangoFontDescription__P(desc), desc, 2, "pango_layout_set_font_description", "PangoFontDescription*");
  pango_layout_set_font_description(XEN_TO_C_PangoLayout_(layout), XEN_TO_C_PangoFontDescription_(desc));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_set_width(XEN layout, XEN width)
{
  #define H_pango_layout_set_width "void pango_layout_set_width(PangoLayout* layout, int width)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_set_width", "PangoLayout*");
  XEN_ASSERT_TYPE(XEN_int_P(width), width, 2, "pango_layout_set_width", "int");
  pango_layout_set_width(XEN_TO_C_PangoLayout_(layout), XEN_TO_C_int(width));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_get_width(XEN layout)
{
  #define H_pango_layout_get_width "int pango_layout_get_width(PangoLayout* layout)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_get_width", "PangoLayout*");
  return(C_TO_XEN_int(pango_layout_get_width(XEN_TO_C_PangoLayout_(layout))));
}
static XEN gxg_pango_layout_set_wrap(XEN layout, XEN wrap)
{
  #define H_pango_layout_set_wrap "void pango_layout_set_wrap(PangoLayout* layout, PangoWrapMode wrap)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_set_wrap", "PangoLayout*");
  XEN_ASSERT_TYPE(XEN_PangoWrapMode_P(wrap), wrap, 2, "pango_layout_set_wrap", "PangoWrapMode");
  pango_layout_set_wrap(XEN_TO_C_PangoLayout_(layout), XEN_TO_C_PangoWrapMode(wrap));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_get_wrap(XEN layout)
{
  #define H_pango_layout_get_wrap "PangoWrapMode pango_layout_get_wrap(PangoLayout* layout)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_get_wrap", "PangoLayout*");
  return(C_TO_XEN_PangoWrapMode(pango_layout_get_wrap(XEN_TO_C_PangoLayout_(layout))));
}
static XEN gxg_pango_layout_set_indent(XEN layout, XEN indent)
{
  #define H_pango_layout_set_indent "void pango_layout_set_indent(PangoLayout* layout, int indent)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_set_indent", "PangoLayout*");
  XEN_ASSERT_TYPE(XEN_int_P(indent), indent, 2, "pango_layout_set_indent", "int");
  pango_layout_set_indent(XEN_TO_C_PangoLayout_(layout), XEN_TO_C_int(indent));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_get_indent(XEN layout)
{
  #define H_pango_layout_get_indent "int pango_layout_get_indent(PangoLayout* layout)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_get_indent", "PangoLayout*");
  return(C_TO_XEN_int(pango_layout_get_indent(XEN_TO_C_PangoLayout_(layout))));
}
static XEN gxg_pango_layout_set_spacing(XEN layout, XEN spacing)
{
  #define H_pango_layout_set_spacing "void pango_layout_set_spacing(PangoLayout* layout, int spacing)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_set_spacing", "PangoLayout*");
  XEN_ASSERT_TYPE(XEN_int_P(spacing), spacing, 2, "pango_layout_set_spacing", "int");
  pango_layout_set_spacing(XEN_TO_C_PangoLayout_(layout), XEN_TO_C_int(spacing));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_get_spacing(XEN layout)
{
  #define H_pango_layout_get_spacing "int pango_layout_get_spacing(PangoLayout* layout)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_get_spacing", "PangoLayout*");
  return(C_TO_XEN_int(pango_layout_get_spacing(XEN_TO_C_PangoLayout_(layout))));
}
static XEN gxg_pango_layout_set_justify(XEN layout, XEN justify)
{
  #define H_pango_layout_set_justify "void pango_layout_set_justify(PangoLayout* layout, gboolean justify)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_set_justify", "PangoLayout*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(justify), justify, 2, "pango_layout_set_justify", "gboolean");
  pango_layout_set_justify(XEN_TO_C_PangoLayout_(layout), XEN_TO_C_gboolean(justify));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_get_justify(XEN layout)
{
  #define H_pango_layout_get_justify "gboolean pango_layout_get_justify(PangoLayout* layout)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_get_justify", "PangoLayout*");
  return(C_TO_XEN_gboolean(pango_layout_get_justify(XEN_TO_C_PangoLayout_(layout))));
}
static XEN gxg_pango_layout_set_alignment(XEN layout, XEN alignment)
{
  #define H_pango_layout_set_alignment "void pango_layout_set_alignment(PangoLayout* layout, PangoAlignment alignment)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_set_alignment", "PangoLayout*");
  XEN_ASSERT_TYPE(XEN_PangoAlignment_P(alignment), alignment, 2, "pango_layout_set_alignment", "PangoAlignment");
  pango_layout_set_alignment(XEN_TO_C_PangoLayout_(layout), XEN_TO_C_PangoAlignment(alignment));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_get_alignment(XEN layout)
{
  #define H_pango_layout_get_alignment "PangoAlignment pango_layout_get_alignment(PangoLayout* layout)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_get_alignment", "PangoLayout*");
  return(C_TO_XEN_PangoAlignment(pango_layout_get_alignment(XEN_TO_C_PangoLayout_(layout))));
}
static XEN gxg_pango_layout_set_tabs(XEN layout, XEN tabs)
{
  #define H_pango_layout_set_tabs "void pango_layout_set_tabs(PangoLayout* layout, PangoTabArray* tabs)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_set_tabs", "PangoLayout*");
  XEN_ASSERT_TYPE(XEN_PangoTabArray__P(tabs), tabs, 2, "pango_layout_set_tabs", "PangoTabArray*");
  pango_layout_set_tabs(XEN_TO_C_PangoLayout_(layout), XEN_TO_C_PangoTabArray_(tabs));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_get_tabs(XEN layout)
{
  #define H_pango_layout_get_tabs "PangoTabArray* pango_layout_get_tabs(PangoLayout* layout)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_get_tabs", "PangoLayout*");
  return(C_TO_XEN_PangoTabArray_(pango_layout_get_tabs(XEN_TO_C_PangoLayout_(layout))));
}
static XEN gxg_pango_layout_set_single_paragraph_mode(XEN layout, XEN setting)
{
  #define H_pango_layout_set_single_paragraph_mode "void pango_layout_set_single_paragraph_mode(PangoLayout* layout, \
gboolean setting)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_set_single_paragraph_mode", "PangoLayout*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "pango_layout_set_single_paragraph_mode", "gboolean");
  pango_layout_set_single_paragraph_mode(XEN_TO_C_PangoLayout_(layout), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_get_single_paragraph_mode(XEN layout)
{
  #define H_pango_layout_get_single_paragraph_mode "gboolean pango_layout_get_single_paragraph_mode(PangoLayout* layout)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_get_single_paragraph_mode", "PangoLayout*");
  return(C_TO_XEN_gboolean(pango_layout_get_single_paragraph_mode(XEN_TO_C_PangoLayout_(layout))));
}
static XEN gxg_pango_layout_context_changed(XEN layout)
{
  #define H_pango_layout_context_changed "void pango_layout_context_changed(PangoLayout* layout)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_context_changed", "PangoLayout*");
  pango_layout_context_changed(XEN_TO_C_PangoLayout_(layout));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_get_log_attrs(XEN layout, XEN attrs, XEN n_attrs)
{
  #define H_pango_layout_get_log_attrs "void pango_layout_get_log_attrs(PangoLayout* layout, PangoLogAttr** [attrs], \
gint* [n_attrs])"
  PangoLogAttr* ref_attrs = NULL;
  gint ref_n_attrs;
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_get_log_attrs", "PangoLayout*");
  pango_layout_get_log_attrs(XEN_TO_C_PangoLayout_(layout), &ref_attrs, &ref_n_attrs);
  return(XEN_LIST_2(C_TO_XEN_PangoLogAttr_(ref_attrs), C_TO_XEN_gint(ref_n_attrs)));
}
static XEN gxg_pango_layout_index_to_pos(XEN layout, XEN index, XEN pos)
{
  #define H_pango_layout_index_to_pos "void pango_layout_index_to_pos(PangoLayout* layout, int index, \
PangoRectangle* pos)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_index_to_pos", "PangoLayout*");
  XEN_ASSERT_TYPE(XEN_int_P(index), index, 2, "pango_layout_index_to_pos", "int");
  XEN_ASSERT_TYPE(XEN_PangoRectangle__P(pos), pos, 3, "pango_layout_index_to_pos", "PangoRectangle*");
  pango_layout_index_to_pos(XEN_TO_C_PangoLayout_(layout), XEN_TO_C_int(index), XEN_TO_C_PangoRectangle_(pos));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_get_cursor_pos(XEN layout, XEN index, XEN strong_pos, XEN weak_pos)
{
  #define H_pango_layout_get_cursor_pos "void pango_layout_get_cursor_pos(PangoLayout* layout, int index, \
PangoRectangle* strong_pos, PangoRectangle* weak_pos)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_get_cursor_pos", "PangoLayout*");
  XEN_ASSERT_TYPE(XEN_int_P(index), index, 2, "pango_layout_get_cursor_pos", "int");
  XEN_ASSERT_TYPE(XEN_PangoRectangle__P(strong_pos), strong_pos, 3, "pango_layout_get_cursor_pos", "PangoRectangle*");
  XEN_ASSERT_TYPE(XEN_PangoRectangle__P(weak_pos), weak_pos, 4, "pango_layout_get_cursor_pos", "PangoRectangle*");
  pango_layout_get_cursor_pos(XEN_TO_C_PangoLayout_(layout), XEN_TO_C_int(index), XEN_TO_C_PangoRectangle_(strong_pos), XEN_TO_C_PangoRectangle_(weak_pos));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_move_cursor_visually(XEN layout, XEN strong, XEN old_index, XEN old_trailing, XEN direction, XEN new_index, XEN new_trailing)
{
  #define H_pango_layout_move_cursor_visually "void pango_layout_move_cursor_visually(PangoLayout* layout, \
gboolean strong, int old_index, int old_trailing, int direction, int* new_index, int* new_trailing)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_move_cursor_visually", "PangoLayout*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(strong), strong, 2, "pango_layout_move_cursor_visually", "gboolean");
  XEN_ASSERT_TYPE(XEN_int_P(old_index), old_index, 3, "pango_layout_move_cursor_visually", "int");
  XEN_ASSERT_TYPE(XEN_int_P(old_trailing), old_trailing, 4, "pango_layout_move_cursor_visually", "int");
  XEN_ASSERT_TYPE(XEN_int_P(direction), direction, 5, "pango_layout_move_cursor_visually", "int");
  XEN_ASSERT_TYPE(XEN_int__P(new_index), new_index, 6, "pango_layout_move_cursor_visually", "int*");
  XEN_ASSERT_TYPE(XEN_int__P(new_trailing), new_trailing, 7, "pango_layout_move_cursor_visually", "int*");
  pango_layout_move_cursor_visually(XEN_TO_C_PangoLayout_(layout), XEN_TO_C_gboolean(strong), XEN_TO_C_int(old_index), XEN_TO_C_int(old_trailing), 
                                    XEN_TO_C_int(direction), XEN_TO_C_int_(new_index), XEN_TO_C_int_(new_trailing));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_xy_to_index(XEN layout, XEN x, XEN y, XEN index, XEN trailing)
{
  #define H_pango_layout_xy_to_index "gboolean pango_layout_xy_to_index(PangoLayout* layout, int x, int y, \
int* [index], int* [trailing])"
  int ref_index;
  int ref_trailing;
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_xy_to_index", "PangoLayout*");
  XEN_ASSERT_TYPE(XEN_int_P(x), x, 2, "pango_layout_xy_to_index", "int");
  XEN_ASSERT_TYPE(XEN_int_P(y), y, 3, "pango_layout_xy_to_index", "int");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(pango_layout_xy_to_index(XEN_TO_C_PangoLayout_(layout), XEN_TO_C_int(x), XEN_TO_C_int(y), 
                                                        &ref_index, &ref_trailing));
    return(XEN_LIST_3(result, C_TO_XEN_int(ref_index), C_TO_XEN_int(ref_trailing)));
   }
}
static XEN gxg_pango_layout_get_extents(XEN layout, XEN ink_rect, XEN logical_rect)
{
  #define H_pango_layout_get_extents "void pango_layout_get_extents(PangoLayout* layout, PangoRectangle* ink_rect, \
PangoRectangle* logical_rect)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_get_extents", "PangoLayout*");
  XEN_ASSERT_TYPE(XEN_PangoRectangle__P(ink_rect), ink_rect, 2, "pango_layout_get_extents", "PangoRectangle*");
  XEN_ASSERT_TYPE(XEN_PangoRectangle__P(logical_rect), logical_rect, 3, "pango_layout_get_extents", "PangoRectangle*");
  pango_layout_get_extents(XEN_TO_C_PangoLayout_(layout), XEN_TO_C_PangoRectangle_(ink_rect), XEN_TO_C_PangoRectangle_(logical_rect));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_get_pixel_extents(XEN layout, XEN ink_rect, XEN logical_rect)
{
  #define H_pango_layout_get_pixel_extents "void pango_layout_get_pixel_extents(PangoLayout* layout, \
PangoRectangle* ink_rect, PangoRectangle* logical_rect)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_get_pixel_extents", "PangoLayout*");
  XEN_ASSERT_TYPE(XEN_PangoRectangle__P(ink_rect), ink_rect, 2, "pango_layout_get_pixel_extents", "PangoRectangle*");
  XEN_ASSERT_TYPE(XEN_PangoRectangle__P(logical_rect), logical_rect, 3, "pango_layout_get_pixel_extents", "PangoRectangle*");
  pango_layout_get_pixel_extents(XEN_TO_C_PangoLayout_(layout), XEN_TO_C_PangoRectangle_(ink_rect), XEN_TO_C_PangoRectangle_(logical_rect));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_get_size(XEN layout, XEN width, XEN height)
{
  #define H_pango_layout_get_size "void pango_layout_get_size(PangoLayout* layout, int* [width], int* [height])"
  int ref_width;
  int ref_height;
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_get_size", "PangoLayout*");
  pango_layout_get_size(XEN_TO_C_PangoLayout_(layout), &ref_width, &ref_height);
  return(XEN_LIST_2(C_TO_XEN_int(ref_width), C_TO_XEN_int(ref_height)));
}
static XEN gxg_pango_layout_get_pixel_size(XEN layout, XEN width, XEN height)
{
  #define H_pango_layout_get_pixel_size "void pango_layout_get_pixel_size(PangoLayout* layout, int* [width], \
int* [height])"
  int ref_width;
  int ref_height;
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_get_pixel_size", "PangoLayout*");
  pango_layout_get_pixel_size(XEN_TO_C_PangoLayout_(layout), &ref_width, &ref_height);
  return(XEN_LIST_2(C_TO_XEN_int(ref_width), C_TO_XEN_int(ref_height)));
}
static XEN gxg_pango_layout_get_line_count(XEN layout)
{
  #define H_pango_layout_get_line_count "int pango_layout_get_line_count(PangoLayout* layout)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_get_line_count", "PangoLayout*");
  return(C_TO_XEN_int(pango_layout_get_line_count(XEN_TO_C_PangoLayout_(layout))));
}
static XEN gxg_pango_layout_get_line(XEN layout, XEN line)
{
  #define H_pango_layout_get_line "PangoLayoutLine* pango_layout_get_line(PangoLayout* layout, int line)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_get_line", "PangoLayout*");
  XEN_ASSERT_TYPE(XEN_int_P(line), line, 2, "pango_layout_get_line", "int");
  return(C_TO_XEN_PangoLayoutLine_(pango_layout_get_line(XEN_TO_C_PangoLayout_(layout), XEN_TO_C_int(line))));
}
static XEN gxg_pango_layout_get_lines(XEN layout)
{
  #define H_pango_layout_get_lines "GSList* pango_layout_get_lines(PangoLayout* layout)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_get_lines", "PangoLayout*");
  return(C_TO_XEN_GSList_(pango_layout_get_lines(XEN_TO_C_PangoLayout_(layout))));
}
static XEN gxg_pango_layout_line_ref(XEN line)
{
  #define H_pango_layout_line_ref "void pango_layout_line_ref(PangoLayoutLine* line)"
  XEN_ASSERT_TYPE(XEN_PangoLayoutLine__P(line), line, 1, "pango_layout_line_ref", "PangoLayoutLine*");
  pango_layout_line_ref(XEN_TO_C_PangoLayoutLine_(line));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_line_unref(XEN line)
{
  #define H_pango_layout_line_unref "void pango_layout_line_unref(PangoLayoutLine* line)"
  XEN_ASSERT_TYPE(XEN_PangoLayoutLine__P(line), line, 1, "pango_layout_line_unref", "PangoLayoutLine*");
  pango_layout_line_unref(XEN_TO_C_PangoLayoutLine_(line));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_line_x_to_index(XEN line, XEN x_pos, XEN index, XEN trailing)
{
  #define H_pango_layout_line_x_to_index "gboolean pango_layout_line_x_to_index(PangoLayoutLine* line, \
int x_pos, int* [index], int* [trailing])"
  int ref_index;
  int ref_trailing;
  XEN_ASSERT_TYPE(XEN_PangoLayoutLine__P(line), line, 1, "pango_layout_line_x_to_index", "PangoLayoutLine*");
  XEN_ASSERT_TYPE(XEN_int_P(x_pos), x_pos, 2, "pango_layout_line_x_to_index", "int");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(pango_layout_line_x_to_index(XEN_TO_C_PangoLayoutLine_(line), XEN_TO_C_int(x_pos), &ref_index, 
                                                            &ref_trailing));
    return(XEN_LIST_3(result, C_TO_XEN_int(ref_index), C_TO_XEN_int(ref_trailing)));
   }
}
static XEN gxg_pango_layout_line_index_to_x(XEN line, XEN index, XEN trailing, XEN x_pos)
{
  #define H_pango_layout_line_index_to_x "void pango_layout_line_index_to_x(PangoLayoutLine* line, int index, \
gboolean trailing, int* [x_pos])"
  int ref_x_pos;
  XEN_ASSERT_TYPE(XEN_PangoLayoutLine__P(line), line, 1, "pango_layout_line_index_to_x", "PangoLayoutLine*");
  XEN_ASSERT_TYPE(XEN_int_P(index), index, 2, "pango_layout_line_index_to_x", "int");
  XEN_ASSERT_TYPE(XEN_gboolean_P(trailing), trailing, 3, "pango_layout_line_index_to_x", "gboolean");
  pango_layout_line_index_to_x(XEN_TO_C_PangoLayoutLine_(line), XEN_TO_C_int(index), XEN_TO_C_gboolean(trailing), &ref_x_pos);
  return(XEN_LIST_1(C_TO_XEN_int(ref_x_pos)));
}
static XEN gxg_pango_layout_line_get_x_ranges(XEN line, XEN start_index, XEN end_index, XEN ranges, XEN n_ranges)
{
  #define H_pango_layout_line_get_x_ranges "void pango_layout_line_get_x_ranges(PangoLayoutLine* line, \
int start_index, int end_index, int** [ranges], int* [n_ranges])"
  int* ref_ranges = NULL;
  int ref_n_ranges;
  XEN_ASSERT_TYPE(XEN_PangoLayoutLine__P(line), line, 1, "pango_layout_line_get_x_ranges", "PangoLayoutLine*");
  XEN_ASSERT_TYPE(XEN_int_P(start_index), start_index, 2, "pango_layout_line_get_x_ranges", "int");
  XEN_ASSERT_TYPE(XEN_int_P(end_index), end_index, 3, "pango_layout_line_get_x_ranges", "int");
  pango_layout_line_get_x_ranges(XEN_TO_C_PangoLayoutLine_(line), XEN_TO_C_int(start_index), XEN_TO_C_int(end_index), &ref_ranges, 
                                 &ref_n_ranges);
  return(XEN_LIST_2(C_TO_XEN_int_(ref_ranges), C_TO_XEN_int(ref_n_ranges)));
}
static XEN gxg_pango_layout_line_get_extents(XEN line, XEN ink_rect, XEN logical_rect)
{
  #define H_pango_layout_line_get_extents "void pango_layout_line_get_extents(PangoLayoutLine* line, \
PangoRectangle* ink_rect, PangoRectangle* logical_rect)"
  XEN_ASSERT_TYPE(XEN_PangoLayoutLine__P(line), line, 1, "pango_layout_line_get_extents", "PangoLayoutLine*");
  XEN_ASSERT_TYPE(XEN_PangoRectangle__P(ink_rect), ink_rect, 2, "pango_layout_line_get_extents", "PangoRectangle*");
  XEN_ASSERT_TYPE(XEN_PangoRectangle__P(logical_rect), logical_rect, 3, "pango_layout_line_get_extents", "PangoRectangle*");
  pango_layout_line_get_extents(XEN_TO_C_PangoLayoutLine_(line), XEN_TO_C_PangoRectangle_(ink_rect), XEN_TO_C_PangoRectangle_(logical_rect));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_line_get_pixel_extents(XEN layout_line, XEN ink_rect, XEN logical_rect)
{
  #define H_pango_layout_line_get_pixel_extents "void pango_layout_line_get_pixel_extents(PangoLayoutLine* layout_line, \
PangoRectangle* ink_rect, PangoRectangle* logical_rect)"
  XEN_ASSERT_TYPE(XEN_PangoLayoutLine__P(layout_line), layout_line, 1, "pango_layout_line_get_pixel_extents", "PangoLayoutLine*");
  XEN_ASSERT_TYPE(XEN_PangoRectangle__P(ink_rect), ink_rect, 2, "pango_layout_line_get_pixel_extents", "PangoRectangle*");
  XEN_ASSERT_TYPE(XEN_PangoRectangle__P(logical_rect), logical_rect, 3, "pango_layout_line_get_pixel_extents", "PangoRectangle*");
  pango_layout_line_get_pixel_extents(XEN_TO_C_PangoLayoutLine_(layout_line), XEN_TO_C_PangoRectangle_(ink_rect), XEN_TO_C_PangoRectangle_(logical_rect));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_get_iter(XEN layout)
{
  #define H_pango_layout_get_iter "PangoLayoutIter* pango_layout_get_iter(PangoLayout* layout)"
  XEN_ASSERT_TYPE(XEN_PangoLayout__P(layout), layout, 1, "pango_layout_get_iter", "PangoLayout*");
  return(C_TO_XEN_PangoLayoutIter_(pango_layout_get_iter(XEN_TO_C_PangoLayout_(layout))));
}
static XEN gxg_pango_layout_iter_free(XEN iter)
{
  #define H_pango_layout_iter_free "void pango_layout_iter_free(PangoLayoutIter* iter)"
  XEN_ASSERT_TYPE(XEN_PangoLayoutIter__P(iter), iter, 1, "pango_layout_iter_free", "PangoLayoutIter*");
  pango_layout_iter_free(XEN_TO_C_PangoLayoutIter_(iter));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_iter_get_index(XEN iter)
{
  #define H_pango_layout_iter_get_index "int pango_layout_iter_get_index(PangoLayoutIter* iter)"
  XEN_ASSERT_TYPE(XEN_PangoLayoutIter__P(iter), iter, 1, "pango_layout_iter_get_index", "PangoLayoutIter*");
  return(C_TO_XEN_int(pango_layout_iter_get_index(XEN_TO_C_PangoLayoutIter_(iter))));
}
static XEN gxg_pango_layout_iter_get_run(XEN iter)
{
  #define H_pango_layout_iter_get_run "PangoLayoutRun* pango_layout_iter_get_run(PangoLayoutIter* iter)"
  XEN_ASSERT_TYPE(XEN_PangoLayoutIter__P(iter), iter, 1, "pango_layout_iter_get_run", "PangoLayoutIter*");
  return(C_TO_XEN_PangoLayoutRun_(pango_layout_iter_get_run(XEN_TO_C_PangoLayoutIter_(iter))));
}
static XEN gxg_pango_layout_iter_get_line(XEN iter)
{
  #define H_pango_layout_iter_get_line "PangoLayoutLine* pango_layout_iter_get_line(PangoLayoutIter* iter)"
  XEN_ASSERT_TYPE(XEN_PangoLayoutIter__P(iter), iter, 1, "pango_layout_iter_get_line", "PangoLayoutIter*");
  return(C_TO_XEN_PangoLayoutLine_(pango_layout_iter_get_line(XEN_TO_C_PangoLayoutIter_(iter))));
}
static XEN gxg_pango_layout_iter_at_last_line(XEN iter)
{
  #define H_pango_layout_iter_at_last_line "gboolean pango_layout_iter_at_last_line(PangoLayoutIter* iter)"
  XEN_ASSERT_TYPE(XEN_PangoLayoutIter__P(iter), iter, 1, "pango_layout_iter_at_last_line", "PangoLayoutIter*");
  return(C_TO_XEN_gboolean(pango_layout_iter_at_last_line(XEN_TO_C_PangoLayoutIter_(iter))));
}
static XEN gxg_pango_layout_iter_next_char(XEN iter)
{
  #define H_pango_layout_iter_next_char "gboolean pango_layout_iter_next_char(PangoLayoutIter* iter)"
  XEN_ASSERT_TYPE(XEN_PangoLayoutIter__P(iter), iter, 1, "pango_layout_iter_next_char", "PangoLayoutIter*");
  return(C_TO_XEN_gboolean(pango_layout_iter_next_char(XEN_TO_C_PangoLayoutIter_(iter))));
}
static XEN gxg_pango_layout_iter_next_cluster(XEN iter)
{
  #define H_pango_layout_iter_next_cluster "gboolean pango_layout_iter_next_cluster(PangoLayoutIter* iter)"
  XEN_ASSERT_TYPE(XEN_PangoLayoutIter__P(iter), iter, 1, "pango_layout_iter_next_cluster", "PangoLayoutIter*");
  return(C_TO_XEN_gboolean(pango_layout_iter_next_cluster(XEN_TO_C_PangoLayoutIter_(iter))));
}
static XEN gxg_pango_layout_iter_next_run(XEN iter)
{
  #define H_pango_layout_iter_next_run "gboolean pango_layout_iter_next_run(PangoLayoutIter* iter)"
  XEN_ASSERT_TYPE(XEN_PangoLayoutIter__P(iter), iter, 1, "pango_layout_iter_next_run", "PangoLayoutIter*");
  return(C_TO_XEN_gboolean(pango_layout_iter_next_run(XEN_TO_C_PangoLayoutIter_(iter))));
}
static XEN gxg_pango_layout_iter_next_line(XEN iter)
{
  #define H_pango_layout_iter_next_line "gboolean pango_layout_iter_next_line(PangoLayoutIter* iter)"
  XEN_ASSERT_TYPE(XEN_PangoLayoutIter__P(iter), iter, 1, "pango_layout_iter_next_line", "PangoLayoutIter*");
  return(C_TO_XEN_gboolean(pango_layout_iter_next_line(XEN_TO_C_PangoLayoutIter_(iter))));
}
static XEN gxg_pango_layout_iter_get_char_extents(XEN iter, XEN logical_rect)
{
  #define H_pango_layout_iter_get_char_extents "void pango_layout_iter_get_char_extents(PangoLayoutIter* iter, \
PangoRectangle* logical_rect)"
  XEN_ASSERT_TYPE(XEN_PangoLayoutIter__P(iter), iter, 1, "pango_layout_iter_get_char_extents", "PangoLayoutIter*");
  XEN_ASSERT_TYPE(XEN_PangoRectangle__P(logical_rect), logical_rect, 2, "pango_layout_iter_get_char_extents", "PangoRectangle*");
  pango_layout_iter_get_char_extents(XEN_TO_C_PangoLayoutIter_(iter), XEN_TO_C_PangoRectangle_(logical_rect));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_iter_get_cluster_extents(XEN iter, XEN ink_rect, XEN logical_rect)
{
  #define H_pango_layout_iter_get_cluster_extents "void pango_layout_iter_get_cluster_extents(PangoLayoutIter* iter, \
PangoRectangle* ink_rect, PangoRectangle* logical_rect)"
  XEN_ASSERT_TYPE(XEN_PangoLayoutIter__P(iter), iter, 1, "pango_layout_iter_get_cluster_extents", "PangoLayoutIter*");
  XEN_ASSERT_TYPE(XEN_PangoRectangle__P(ink_rect), ink_rect, 2, "pango_layout_iter_get_cluster_extents", "PangoRectangle*");
  XEN_ASSERT_TYPE(XEN_PangoRectangle__P(logical_rect), logical_rect, 3, "pango_layout_iter_get_cluster_extents", "PangoRectangle*");
  pango_layout_iter_get_cluster_extents(XEN_TO_C_PangoLayoutIter_(iter), XEN_TO_C_PangoRectangle_(ink_rect), XEN_TO_C_PangoRectangle_(logical_rect));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_iter_get_run_extents(XEN iter, XEN ink_rect, XEN logical_rect)
{
  #define H_pango_layout_iter_get_run_extents "void pango_layout_iter_get_run_extents(PangoLayoutIter* iter, \
PangoRectangle* ink_rect, PangoRectangle* logical_rect)"
  XEN_ASSERT_TYPE(XEN_PangoLayoutIter__P(iter), iter, 1, "pango_layout_iter_get_run_extents", "PangoLayoutIter*");
  XEN_ASSERT_TYPE(XEN_PangoRectangle__P(ink_rect), ink_rect, 2, "pango_layout_iter_get_run_extents", "PangoRectangle*");
  XEN_ASSERT_TYPE(XEN_PangoRectangle__P(logical_rect), logical_rect, 3, "pango_layout_iter_get_run_extents", "PangoRectangle*");
  pango_layout_iter_get_run_extents(XEN_TO_C_PangoLayoutIter_(iter), XEN_TO_C_PangoRectangle_(ink_rect), XEN_TO_C_PangoRectangle_(logical_rect));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_iter_get_line_extents(XEN iter, XEN ink_rect, XEN logical_rect)
{
  #define H_pango_layout_iter_get_line_extents "void pango_layout_iter_get_line_extents(PangoLayoutIter* iter, \
PangoRectangle* ink_rect, PangoRectangle* logical_rect)"
  XEN_ASSERT_TYPE(XEN_PangoLayoutIter__P(iter), iter, 1, "pango_layout_iter_get_line_extents", "PangoLayoutIter*");
  XEN_ASSERT_TYPE(XEN_PangoRectangle__P(ink_rect), ink_rect, 2, "pango_layout_iter_get_line_extents", "PangoRectangle*");
  XEN_ASSERT_TYPE(XEN_PangoRectangle__P(logical_rect), logical_rect, 3, "pango_layout_iter_get_line_extents", "PangoRectangle*");
  pango_layout_iter_get_line_extents(XEN_TO_C_PangoLayoutIter_(iter), XEN_TO_C_PangoRectangle_(ink_rect), XEN_TO_C_PangoRectangle_(logical_rect));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_iter_get_line_yrange(XEN iter, XEN y0, XEN y1)
{
  #define H_pango_layout_iter_get_line_yrange "void pango_layout_iter_get_line_yrange(PangoLayoutIter* iter, \
int* [y0], int* [y1])"
  int ref_y0;
  int ref_y1;
  XEN_ASSERT_TYPE(XEN_PangoLayoutIter__P(iter), iter, 1, "pango_layout_iter_get_line_yrange", "PangoLayoutIter*");
  pango_layout_iter_get_line_yrange(XEN_TO_C_PangoLayoutIter_(iter), &ref_y0, &ref_y1);
  return(XEN_LIST_2(C_TO_XEN_int(ref_y0), C_TO_XEN_int(ref_y1)));
}
static XEN gxg_pango_layout_iter_get_layout_extents(XEN iter, XEN ink_rect, XEN logical_rect)
{
  #define H_pango_layout_iter_get_layout_extents "void pango_layout_iter_get_layout_extents(PangoLayoutIter* iter, \
PangoRectangle* ink_rect, PangoRectangle* logical_rect)"
  XEN_ASSERT_TYPE(XEN_PangoLayoutIter__P(iter), iter, 1, "pango_layout_iter_get_layout_extents", "PangoLayoutIter*");
  XEN_ASSERT_TYPE(XEN_PangoRectangle__P(ink_rect), ink_rect, 2, "pango_layout_iter_get_layout_extents", "PangoRectangle*");
  XEN_ASSERT_TYPE(XEN_PangoRectangle__P(logical_rect), logical_rect, 3, "pango_layout_iter_get_layout_extents", "PangoRectangle*");
  pango_layout_iter_get_layout_extents(XEN_TO_C_PangoLayoutIter_(iter), XEN_TO_C_PangoRectangle_(ink_rect), XEN_TO_C_PangoRectangle_(logical_rect));
  return(XEN_FALSE);
}
static XEN gxg_pango_layout_iter_get_baseline(XEN iter)
{
  #define H_pango_layout_iter_get_baseline "int pango_layout_iter_get_baseline(PangoLayoutIter* iter)"
  XEN_ASSERT_TYPE(XEN_PangoLayoutIter__P(iter), iter, 1, "pango_layout_iter_get_baseline", "PangoLayoutIter*");
  return(C_TO_XEN_int(pango_layout_iter_get_baseline(XEN_TO_C_PangoLayoutIter_(iter))));
}
static XEN gxg_pango_language_get_type(void)
{
  #define H_pango_language_get_type "GType pango_language_get_type( void)"
  return(C_TO_XEN_GType(pango_language_get_type()));
}
static XEN gxg_pango_language_from_string(XEN language)
{
  #define H_pango_language_from_string "PangoLanguage* pango_language_from_string(char* language)"
  XEN_ASSERT_TYPE(XEN_char__P(language), language, 1, "pango_language_from_string", "char*");
  return(C_TO_XEN_PangoLanguage_(pango_language_from_string(XEN_TO_C_char_(language))));
}
static XEN gxg_pango_language_matches(XEN language, XEN range_list)
{
  #define H_pango_language_matches "gboolean pango_language_matches(PangoLanguage* language, char* range_list)"
  XEN_ASSERT_TYPE(XEN_PangoLanguage__P(language), language, 1, "pango_language_matches", "PangoLanguage*");
  XEN_ASSERT_TYPE(XEN_char__P(range_list), range_list, 2, "pango_language_matches", "char*");
  return(C_TO_XEN_gboolean(pango_language_matches(XEN_TO_C_PangoLanguage_(language), XEN_TO_C_char_(range_list))));
}
static XEN gxg_G_OBJECT_TYPE(XEN object)
{
  #define H_G_OBJECT_TYPE "GType G_OBJECT_TYPE(GtkObject* object)"
  XEN_ASSERT_TYPE(XEN_GtkObject__P(object), object, 1, "G_OBJECT_TYPE", "GtkObject*");
  return(C_TO_XEN_GType(G_OBJECT_TYPE(XEN_TO_C_GtkObject_(object))));
}
static XEN gxg_g_list_free(XEN list)
{
  #define H_g_list_free "void g_list_free(GList* list)"
  XEN_ASSERT_TYPE(XEN_GList__P(list), list, 1, "g_list_free", "GList*");
  g_list_free(XEN_TO_C_GList_(list));
  return(XEN_FALSE);
}
static XEN gxg_g_list_reverse(XEN list)
{
  #define H_g_list_reverse "GList* g_list_reverse(GList* list)"
  XEN_ASSERT_TYPE(XEN_GList__P(list), list, 1, "g_list_reverse", "GList*");
  return(C_TO_XEN_GList_(g_list_reverse(XEN_TO_C_GList_(list))));
}
static XEN gxg_g_list_copy(XEN list)
{
  #define H_g_list_copy "GList* g_list_copy(GList* list)"
  XEN_ASSERT_TYPE(XEN_GList__P(list), list, 1, "g_list_copy", "GList*");
  return(C_TO_XEN_GList_(g_list_copy(XEN_TO_C_GList_(list))));
}
static XEN gxg_g_list_last(XEN list)
{
  #define H_g_list_last "GList* g_list_last(GList* list)"
  XEN_ASSERT_TYPE(XEN_GList__P(list), list, 1, "g_list_last", "GList*");
  return(C_TO_XEN_GList_(g_list_last(XEN_TO_C_GList_(list))));
}
static XEN gxg_g_list_first(XEN list)
{
  #define H_g_list_first "GList* g_list_first(GList* list)"
  XEN_ASSERT_TYPE(XEN_GList__P(list), list, 1, "g_list_first", "GList*");
  return(C_TO_XEN_GList_(g_list_first(XEN_TO_C_GList_(list))));
}
static XEN gxg_g_list_length(XEN list)
{
  #define H_g_list_length "guint g_list_length(GList* list)"
  XEN_ASSERT_TYPE(XEN_GList__P(list), list, 1, "g_list_length", "GList*");
  return(C_TO_XEN_guint(g_list_length(XEN_TO_C_GList_(list))));
}
static XEN gxg_g_free(XEN mem)
{
  #define H_g_free "void g_free(gpointer mem)"
  XEN_ASSERT_TYPE(XEN_gpointer_P(mem), mem, 1, "g_free", "gpointer");
  g_free(XEN_TO_C_gpointer(mem));
  return(XEN_FALSE);
}
static XEN gxg_g_list_remove_link(XEN list, XEN llink)
{
  #define H_g_list_remove_link "GList* g_list_remove_link(GList* list, GList* llink)"
  XEN_ASSERT_TYPE(XEN_GList__P(list), list, 1, "g_list_remove_link", "GList*");
  XEN_ASSERT_TYPE(XEN_GList__P(llink), llink, 2, "g_list_remove_link", "GList*");
  return(C_TO_XEN_GList_(g_list_remove_link(XEN_TO_C_GList_(list), XEN_TO_C_GList_(llink))));
}
static XEN gxg_g_object_get_data(XEN object, XEN key)
{
  #define H_g_object_get_data "gpointer g_object_get_data(GObject* object, gchar* key)"
  XEN_ASSERT_TYPE(XEN_GObject__P(object), object, 1, "g_object_get_data", "GObject*");
  XEN_ASSERT_TYPE(XEN_gchar__P(key), key, 2, "g_object_get_data", "gchar*");
  return(C_TO_XEN_gpointer(g_object_get_data(XEN_TO_C_GObject_(object), (const gchar*)XEN_TO_C_gchar_(key))));
}
static XEN gxg_g_object_set_data(XEN object, XEN key, XEN data)
{
  #define H_g_object_set_data "void g_object_set_data(GObject* object, gchar* key, gpointer data)"
  XEN_ASSERT_TYPE(XEN_GObject__P(object), object, 1, "g_object_set_data", "GObject*");
  XEN_ASSERT_TYPE(XEN_gchar__P(key), key, 2, "g_object_set_data", "gchar*");
  XEN_ASSERT_TYPE(XEN_gpointer_P(data), data, 3, "g_object_set_data", "gpointer");
  g_object_set_data(XEN_TO_C_GObject_(object), (const gchar*)XEN_TO_C_gchar_(key), XEN_TO_C_gpointer(data));
  return(XEN_FALSE);
}
static XEN gxg_g_list_nth_data(XEN list, XEN n)
{
  #define H_g_list_nth_data "gpointer g_list_nth_data(GList* list, guint n)"
  XEN_ASSERT_TYPE(XEN_GList__P(list), list, 1, "g_list_nth_data", "GList*");
  XEN_ASSERT_TYPE(XEN_guint_P(n), n, 2, "g_list_nth_data", "guint");
  return(C_TO_XEN_gpointer(g_list_nth_data(XEN_TO_C_GList_(list), XEN_TO_C_guint(n))));
}
static XEN gxg_g_quark_from_string(XEN string)
{
  #define H_g_quark_from_string "GQuark g_quark_from_string(gchar* string)"
  XEN_ASSERT_TYPE(XEN_gchar__P(string), string, 1, "g_quark_from_string", "gchar*");
  return(C_TO_XEN_GQuark(g_quark_from_string(XEN_TO_C_gchar_(string))));
}
static XEN gxg_g_quark_to_string(XEN quark)
{
  #define H_g_quark_to_string "gchar* g_quark_to_string(GQuark quark)"
  XEN_ASSERT_TYPE(XEN_GQuark_P(quark), quark, 1, "g_quark_to_string", "GQuark");
  return(C_TO_XEN_gchar_(g_quark_to_string(XEN_TO_C_GQuark(quark))));
}
#if HAVE_GDK_DRAW_PIXBUF
static XEN gxg_gdk_draw_pixbuf(XEN arglist)
{
  #define H_gdk_draw_pixbuf "void gdk_draw_pixbuf(GdkDrawable* drawable, GdkGC* gc, GdkPixbuf* pixbuf, \
int src_x, int src_y, int dest_x, int dest_y, int width, int height, GdkRgbDither dither, int x_dither, \
int y_dither)"
  XEN drawable, gc, pixbuf, src_x, src_y, dest_x, dest_y, width, height, dither, x_dither, y_dither;
  drawable = XEN_LIST_REF(arglist, 0);
  gc = XEN_LIST_REF(arglist, 1);
  pixbuf = XEN_LIST_REF(arglist, 2);
  src_x = XEN_LIST_REF(arglist, 3);
  src_y = XEN_LIST_REF(arglist, 4);
  dest_x = XEN_LIST_REF(arglist, 5);
  dest_y = XEN_LIST_REF(arglist, 6);
  width = XEN_LIST_REF(arglist, 7);
  height = XEN_LIST_REF(arglist, 8);
  dither = XEN_LIST_REF(arglist, 9);
  x_dither = XEN_LIST_REF(arglist, 10);
  y_dither = XEN_LIST_REF(arglist, 11);
  XEN_ASSERT_TYPE(XEN_GdkDrawable__P(drawable), drawable, 1, "gdk_draw_pixbuf", "GdkDrawable*");
  XEN_ASSERT_TYPE(XEN_GdkGC__P(gc), gc, 2, "gdk_draw_pixbuf", "GdkGC*");
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(pixbuf), pixbuf, 3, "gdk_draw_pixbuf", "GdkPixbuf*");
  XEN_ASSERT_TYPE(XEN_int_P(src_x), src_x, 4, "gdk_draw_pixbuf", "int");
  XEN_ASSERT_TYPE(XEN_int_P(src_y), src_y, 5, "gdk_draw_pixbuf", "int");
  XEN_ASSERT_TYPE(XEN_int_P(dest_x), dest_x, 6, "gdk_draw_pixbuf", "int");
  XEN_ASSERT_TYPE(XEN_int_P(dest_y), dest_y, 7, "gdk_draw_pixbuf", "int");
  XEN_ASSERT_TYPE(XEN_int_P(width), width, 8, "gdk_draw_pixbuf", "int");
  XEN_ASSERT_TYPE(XEN_int_P(height), height, 9, "gdk_draw_pixbuf", "int");
  XEN_ASSERT_TYPE(XEN_GdkRgbDither_P(dither), dither, 10, "gdk_draw_pixbuf", "GdkRgbDither");
  XEN_ASSERT_TYPE(XEN_int_P(x_dither), x_dither, 11, "gdk_draw_pixbuf", "int");
  XEN_ASSERT_TYPE(XEN_int_P(y_dither), y_dither, 12, "gdk_draw_pixbuf", "int");
  gdk_draw_pixbuf(XEN_TO_C_GdkDrawable_(drawable), XEN_TO_C_GdkGC_(gc), XEN_TO_C_GdkPixbuf_(pixbuf), XEN_TO_C_int(src_x), 
                  XEN_TO_C_int(src_y), XEN_TO_C_int(dest_x), XEN_TO_C_int(dest_y), XEN_TO_C_int(width), XEN_TO_C_int(height), 
                  XEN_TO_C_GdkRgbDither(dither), XEN_TO_C_int(x_dither), XEN_TO_C_int(y_dither));
  return(xen_return_first(XEN_FALSE, arglist));
}
static XEN gxg_gtk_tree_model_get_string_from_iter(XEN tree_model, XEN iter)
{
  #define H_gtk_tree_model_get_string_from_iter "gchar* gtk_tree_model_get_string_from_iter(GtkTreeModel* tree_model, \
GtkTreeIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModel__P(tree_model), tree_model, 1, "gtk_tree_model_get_string_from_iter", "GtkTreeModel*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_tree_model_get_string_from_iter", "GtkTreeIter*");
  return(C_TO_XEN_gchar_(gtk_tree_model_get_string_from_iter(XEN_TO_C_GtkTreeModel_(tree_model), XEN_TO_C_GtkTreeIter_(iter))));
}
static XEN gxg_gtk_tree_model_sort_iter_is_valid(XEN tree_model_sort, XEN iter)
{
  #define H_gtk_tree_model_sort_iter_is_valid "gboolean gtk_tree_model_sort_iter_is_valid(GtkTreeModelSort* tree_model_sort, \
GtkTreeIter* iter)"
  XEN_ASSERT_TYPE(XEN_GtkTreeModelSort__P(tree_model_sort), tree_model_sort, 1, "gtk_tree_model_sort_iter_is_valid", "GtkTreeModelSort*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_tree_model_sort_iter_is_valid", "GtkTreeIter*");
  return(C_TO_XEN_gboolean(gtk_tree_model_sort_iter_is_valid(XEN_TO_C_GtkTreeModelSort_(tree_model_sort), XEN_TO_C_GtkTreeIter_(iter))));
}
static XEN gxg_gtk_tree_view_expand_to_path(XEN tree_view, XEN path)
{
  #define H_gtk_tree_view_expand_to_path "void gtk_tree_view_expand_to_path(GtkTreeView* tree_view, GtkTreePath* path)"
  XEN_ASSERT_TYPE(XEN_GtkTreeView__P(tree_view), tree_view, 1, "gtk_tree_view_expand_to_path", "GtkTreeView*");
  XEN_ASSERT_TYPE(XEN_GtkTreePath__P(path), path, 2, "gtk_tree_view_expand_to_path", "GtkTreePath*");
  gtk_tree_view_expand_to_path(XEN_TO_C_GtkTreeView_(tree_view), XEN_TO_C_GtkTreePath_(path));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_selection_get_selected_rows(XEN selection, XEN model)
{
  #define H_gtk_tree_selection_get_selected_rows "GList* gtk_tree_selection_get_selected_rows(GtkTreeSelection* selection, \
GtkTreeModel** model)"
  XEN_ASSERT_TYPE(XEN_GtkTreeSelection__P(selection), selection, 1, "gtk_tree_selection_get_selected_rows", "GtkTreeSelection*");
  XEN_ASSERT_TYPE(XEN_GtkTreeModel___P(model), model, 2, "gtk_tree_selection_get_selected_rows", "GtkTreeModel**");
  return(C_TO_XEN_GList_(gtk_tree_selection_get_selected_rows(XEN_TO_C_GtkTreeSelection_(selection), XEN_TO_C_GtkTreeModel__(model))));
}
static XEN gxg_gtk_tree_selection_count_selected_rows(XEN selection)
{
  #define H_gtk_tree_selection_count_selected_rows "int gtk_tree_selection_count_selected_rows(GtkTreeSelection* selection)"
  XEN_ASSERT_TYPE(XEN_GtkTreeSelection__P(selection), selection, 1, "gtk_tree_selection_count_selected_rows", "GtkTreeSelection*");
  return(C_TO_XEN_int(gtk_tree_selection_count_selected_rows(XEN_TO_C_GtkTreeSelection_(selection))));
}
static XEN gxg_gtk_menu_shell_select_first(XEN menu_shell, XEN search_sensitive)
{
  #define H_gtk_menu_shell_select_first "void gtk_menu_shell_select_first(GtkMenuShell* menu_shell, gboolean search_sensitive)"
  XEN_ASSERT_TYPE(XEN_GtkMenuShell__P(menu_shell), menu_shell, 1, "gtk_menu_shell_select_first", "GtkMenuShell*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(search_sensitive), search_sensitive, 2, "gtk_menu_shell_select_first", "gboolean");
  gtk_menu_shell_select_first(XEN_TO_C_GtkMenuShell_(menu_shell), XEN_TO_C_gboolean(search_sensitive));
  return(XEN_FALSE);
}
static XEN gxg_gtk_notebook_get_n_pages(XEN notebook)
{
  #define H_gtk_notebook_get_n_pages "int gtk_notebook_get_n_pages(GtkNotebook* notebook)"
  XEN_ASSERT_TYPE(XEN_GtkNotebook__P(notebook), notebook, 1, "gtk_notebook_get_n_pages", "GtkNotebook*");
  return(C_TO_XEN_int(gtk_notebook_get_n_pages(XEN_TO_C_GtkNotebook_(notebook))));
}
static XEN gxg_gtk_list_store_reorder(XEN store, XEN new_order)
{
  #define H_gtk_list_store_reorder "void gtk_list_store_reorder(GtkListStore* store, int* new_order)"
  XEN_ASSERT_TYPE(XEN_GtkListStore__P(store), store, 1, "gtk_list_store_reorder", "GtkListStore*");
  XEN_ASSERT_TYPE(XEN_int__P(new_order), new_order, 2, "gtk_list_store_reorder", "int*");
  gtk_list_store_reorder(XEN_TO_C_GtkListStore_(store), XEN_TO_C_int_(new_order));
  return(XEN_FALSE);
}
static XEN gxg_gtk_list_store_swap(XEN store, XEN a, XEN b)
{
  #define H_gtk_list_store_swap "void gtk_list_store_swap(GtkListStore* store, GtkTreeIter* a, GtkTreeIter* b)"
  XEN_ASSERT_TYPE(XEN_GtkListStore__P(store), store, 1, "gtk_list_store_swap", "GtkListStore*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(a), a, 2, "gtk_list_store_swap", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(b), b, 3, "gtk_list_store_swap", "GtkTreeIter*");
  gtk_list_store_swap(XEN_TO_C_GtkListStore_(store), XEN_TO_C_GtkTreeIter_(a), XEN_TO_C_GtkTreeIter_(b));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_store_reorder(XEN tree_store, XEN parent, XEN new_order)
{
  #define H_gtk_tree_store_reorder "void gtk_tree_store_reorder(GtkTreeStore* tree_store, GtkTreeIter* parent, \
int* new_order)"
  XEN_ASSERT_TYPE(XEN_GtkTreeStore__P(tree_store), tree_store, 1, "gtk_tree_store_reorder", "GtkTreeStore*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(parent), parent, 2, "gtk_tree_store_reorder", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_int__P(new_order), new_order, 3, "gtk_tree_store_reorder", "int*");
  gtk_tree_store_reorder(XEN_TO_C_GtkTreeStore_(tree_store), XEN_TO_C_GtkTreeIter_(parent), XEN_TO_C_int_(new_order));
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_store_swap(XEN tree_store, XEN a, XEN b)
{
  #define H_gtk_tree_store_swap "void gtk_tree_store_swap(GtkTreeStore* tree_store, GtkTreeIter* a, GtkTreeIter* b)"
  XEN_ASSERT_TYPE(XEN_GtkTreeStore__P(tree_store), tree_store, 1, "gtk_tree_store_swap", "GtkTreeStore*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(a), a, 2, "gtk_tree_store_swap", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(b), b, 3, "gtk_tree_store_swap", "GtkTreeIter*");
  gtk_tree_store_swap(XEN_TO_C_GtkTreeStore_(tree_store), XEN_TO_C_GtkTreeIter_(a), XEN_TO_C_GtkTreeIter_(b));
  return(XEN_FALSE);
}
static XEN gxg_gdk_display_get_type(void)
{
  #define H_gdk_display_get_type "GType gdk_display_get_type( void)"
  return(C_TO_XEN_GType(gdk_display_get_type()));
}
static XEN gxg_gdk_display_open(XEN display_name)
{
  #define H_gdk_display_open "GdkDisplay* gdk_display_open(gchar* display_name)"
  XEN_ASSERT_TYPE(XEN_gchar__P(display_name), display_name, 1, "gdk_display_open", "gchar*");
  return(C_TO_XEN_GdkDisplay_(gdk_display_open(XEN_TO_C_gchar_(display_name))));
}
static XEN gxg_gdk_display_get_name(XEN display)
{
  #define H_gdk_display_get_name "gchar* gdk_display_get_name(GdkDisplay* display)"
  XEN_ASSERT_TYPE(XEN_GdkDisplay__P(display), display, 1, "gdk_display_get_name", "GdkDisplay*");
  return(C_TO_XEN_gchar_(gdk_display_get_name(XEN_TO_C_GdkDisplay_(display))));
}
static XEN gxg_gdk_display_get_n_screens(XEN display)
{
  #define H_gdk_display_get_n_screens "int gdk_display_get_n_screens(GdkDisplay* display)"
  XEN_ASSERT_TYPE(XEN_GdkDisplay__P(display), display, 1, "gdk_display_get_n_screens", "GdkDisplay*");
  return(C_TO_XEN_int(gdk_display_get_n_screens(XEN_TO_C_GdkDisplay_(display))));
}
static XEN gxg_gdk_display_get_screen(XEN display, XEN screen_num)
{
  #define H_gdk_display_get_screen "GdkScreen* gdk_display_get_screen(GdkDisplay* display, int screen_num)"
  XEN_ASSERT_TYPE(XEN_GdkDisplay__P(display), display, 1, "gdk_display_get_screen", "GdkDisplay*");
  XEN_ASSERT_TYPE(XEN_int_P(screen_num), screen_num, 2, "gdk_display_get_screen", "int");
  return(C_TO_XEN_GdkScreen_(gdk_display_get_screen(XEN_TO_C_GdkDisplay_(display), XEN_TO_C_int(screen_num))));
}
static XEN gxg_gdk_display_get_default_screen(XEN display)
{
  #define H_gdk_display_get_default_screen "GdkScreen* gdk_display_get_default_screen(GdkDisplay* display)"
  XEN_ASSERT_TYPE(XEN_GdkDisplay__P(display), display, 1, "gdk_display_get_default_screen", "GdkDisplay*");
  return(C_TO_XEN_GdkScreen_(gdk_display_get_default_screen(XEN_TO_C_GdkDisplay_(display))));
}
static XEN gxg_gdk_display_pointer_ungrab(XEN display, XEN time)
{
  #define H_gdk_display_pointer_ungrab "void gdk_display_pointer_ungrab(GdkDisplay* display, guint32 time)"
  XEN_ASSERT_TYPE(XEN_GdkDisplay__P(display), display, 1, "gdk_display_pointer_ungrab", "GdkDisplay*");
  XEN_ASSERT_TYPE(XEN_guint32_P(time), time, 2, "gdk_display_pointer_ungrab", "guint32");
  gdk_display_pointer_ungrab(XEN_TO_C_GdkDisplay_(display), XEN_TO_C_guint32(time));
  return(XEN_FALSE);
}
static XEN gxg_gdk_display_keyboard_ungrab(XEN display, XEN time)
{
  #define H_gdk_display_keyboard_ungrab "void gdk_display_keyboard_ungrab(GdkDisplay* display, guint32 time)"
  XEN_ASSERT_TYPE(XEN_GdkDisplay__P(display), display, 1, "gdk_display_keyboard_ungrab", "GdkDisplay*");
  XEN_ASSERT_TYPE(XEN_guint32_P(time), time, 2, "gdk_display_keyboard_ungrab", "guint32");
  gdk_display_keyboard_ungrab(XEN_TO_C_GdkDisplay_(display), XEN_TO_C_guint32(time));
  return(XEN_FALSE);
}
static XEN gxg_gdk_display_pointer_is_grabbed(XEN display)
{
  #define H_gdk_display_pointer_is_grabbed "gboolean gdk_display_pointer_is_grabbed(GdkDisplay* display)"
  XEN_ASSERT_TYPE(XEN_GdkDisplay__P(display), display, 1, "gdk_display_pointer_is_grabbed", "GdkDisplay*");
  return(C_TO_XEN_gboolean(gdk_display_pointer_is_grabbed(XEN_TO_C_GdkDisplay_(display))));
}
static XEN gxg_gdk_display_beep(XEN display)
{
  #define H_gdk_display_beep "void gdk_display_beep(GdkDisplay* display)"
  XEN_ASSERT_TYPE(XEN_GdkDisplay__P(display), display, 1, "gdk_display_beep", "GdkDisplay*");
  gdk_display_beep(XEN_TO_C_GdkDisplay_(display));
  return(XEN_FALSE);
}
static XEN gxg_gdk_display_sync(XEN display)
{
  #define H_gdk_display_sync "void gdk_display_sync(GdkDisplay* display)"
  XEN_ASSERT_TYPE(XEN_GdkDisplay__P(display), display, 1, "gdk_display_sync", "GdkDisplay*");
  gdk_display_sync(XEN_TO_C_GdkDisplay_(display));
  return(XEN_FALSE);
}
static XEN gxg_gdk_display_close(XEN display)
{
  #define H_gdk_display_close "void gdk_display_close(GdkDisplay* display)"
  XEN_ASSERT_TYPE(XEN_GdkDisplay__P(display), display, 1, "gdk_display_close", "GdkDisplay*");
  gdk_display_close(XEN_TO_C_GdkDisplay_(display));
  return(XEN_FALSE);
}
static XEN gxg_gdk_display_list_devices(XEN display)
{
  #define H_gdk_display_list_devices "GList* gdk_display_list_devices(GdkDisplay* display)"
  XEN_ASSERT_TYPE(XEN_GdkDisplay__P(display), display, 1, "gdk_display_list_devices", "GdkDisplay*");
  return(C_TO_XEN_GList_(gdk_display_list_devices(XEN_TO_C_GdkDisplay_(display))));
}
static XEN gxg_gdk_display_get_event(XEN display)
{
  #define H_gdk_display_get_event "GdkEvent* gdk_display_get_event(GdkDisplay* display)"
  XEN_ASSERT_TYPE(XEN_GdkDisplay__P(display), display, 1, "gdk_display_get_event", "GdkDisplay*");
  return(C_TO_XEN_GdkEvent_(gdk_display_get_event(XEN_TO_C_GdkDisplay_(display))));
}
static XEN gxg_gdk_display_peek_event(XEN display)
{
  #define H_gdk_display_peek_event "GdkEvent* gdk_display_peek_event(GdkDisplay* display)"
  XEN_ASSERT_TYPE(XEN_GdkDisplay__P(display), display, 1, "gdk_display_peek_event", "GdkDisplay*");
  return(C_TO_XEN_GdkEvent_(gdk_display_peek_event(XEN_TO_C_GdkDisplay_(display))));
}
static XEN gxg_gdk_display_put_event(XEN display, XEN event)
{
  #define H_gdk_display_put_event "void gdk_display_put_event(GdkDisplay* display, GdkEvent* event)"
  XEN_ASSERT_TYPE(XEN_GdkDisplay__P(display), display, 1, "gdk_display_put_event", "GdkDisplay*");
  XEN_ASSERT_TYPE(XEN_GdkEvent__P(event), event, 2, "gdk_display_put_event", "GdkEvent*");
  gdk_display_put_event(XEN_TO_C_GdkDisplay_(display), XEN_TO_C_GdkEvent_(event));
  return(XEN_FALSE);
}
static XEN gxg_gdk_display_add_client_message_filter(XEN display, XEN message_type, XEN func, XEN func_data)
{
  #define H_gdk_display_add_client_message_filter "void gdk_display_add_client_message_filter(GdkDisplay* display, \
GdkAtom message_type, GdkFilterFunc func, lambda_data func_data)"
  XEN_ASSERT_TYPE(XEN_GdkDisplay__P(display), display, 1, "gdk_display_add_client_message_filter", "GdkDisplay*");
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(message_type), message_type, 2, "gdk_display_add_client_message_filter", "GdkAtom");
  XEN_ASSERT_TYPE(XEN_GdkFilterFunc_P(func), func, 3, "gdk_display_add_client_message_filter", "GdkFilterFunc");
  if (XEN_NOT_BOUND_P(func_data)) func_data = XEN_FALSE; 
  else XEN_ASSERT_TYPE(XEN_lambda_data_P(func_data), func_data, 4, "gdk_display_add_client_message_filter", "lambda_data");
  {
    XEN gxg_ptr = XEN_LIST_5(func, func_data, XEN_FALSE, XEN_FALSE, XEN_FALSE);
    xm_protect(gxg_ptr);
    gdk_display_add_client_message_filter(XEN_TO_C_GdkDisplay_(display), XEN_TO_C_GdkAtom(message_type), XEN_TO_C_GdkFilterFunc(func), 
                                      XEN_TO_C_lambda_data(func_data));
    return(XEN_FALSE);
   }
}
static XEN gxg_gdk_display_set_double_click_time(XEN display, XEN msec)
{
  #define H_gdk_display_set_double_click_time "void gdk_display_set_double_click_time(GdkDisplay* display, \
guint msec)"
  XEN_ASSERT_TYPE(XEN_GdkDisplay__P(display), display, 1, "gdk_display_set_double_click_time", "GdkDisplay*");
  XEN_ASSERT_TYPE(XEN_guint_P(msec), msec, 2, "gdk_display_set_double_click_time", "guint");
  gdk_display_set_double_click_time(XEN_TO_C_GdkDisplay_(display), XEN_TO_C_guint(msec));
  return(XEN_FALSE);
}
static XEN gxg_gdk_display_get_default(void)
{
  #define H_gdk_display_get_default "GdkDisplay* gdk_display_get_default( void)"
  return(C_TO_XEN_GdkDisplay_(gdk_display_get_default()));
}
static XEN gxg_gdk_display_get_core_pointer(XEN display)
{
  #define H_gdk_display_get_core_pointer "GdkDevice* gdk_display_get_core_pointer(GdkDisplay* display)"
  XEN_ASSERT_TYPE(XEN_GdkDisplay__P(display), display, 1, "gdk_display_get_core_pointer", "GdkDisplay*");
  return(C_TO_XEN_GdkDevice_(gdk_display_get_core_pointer(XEN_TO_C_GdkDisplay_(display))));
}
static XEN gxg_gdk_display_get_pointer(XEN display, XEN screen, XEN x, XEN y, XEN mask)
{
  #define H_gdk_display_get_pointer "void gdk_display_get_pointer(GdkDisplay* display, GdkScreen** [screen], \
int* [x], int* [y], GdkModifierType* [mask])"
  GdkScreen* ref_screen = NULL;
  int ref_x;
  int ref_y;
  GdkModifierType ref_mask;
  XEN_ASSERT_TYPE(XEN_GdkDisplay__P(display), display, 1, "gdk_display_get_pointer", "GdkDisplay*");
  gdk_display_get_pointer(XEN_TO_C_GdkDisplay_(display), &ref_screen, &ref_x, &ref_y, &ref_mask);
  return(XEN_LIST_4(C_TO_XEN_GdkScreen_(ref_screen), C_TO_XEN_int(ref_x), C_TO_XEN_int(ref_y), C_TO_XEN_GdkModifierType(ref_mask)));
}
static XEN gxg_gdk_display_get_window_at_pointer(XEN display, XEN win_x, XEN win_y)
{
  #define H_gdk_display_get_window_at_pointer "GdkWindow* gdk_display_get_window_at_pointer(GdkDisplay* display, \
int* [win_x], int* [win_y])"
  int ref_win_x;
  int ref_win_y;
  XEN_ASSERT_TYPE(XEN_GdkDisplay__P(display), display, 1, "gdk_display_get_window_at_pointer", "GdkDisplay*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_GdkWindow_(gdk_display_get_window_at_pointer(XEN_TO_C_GdkDisplay_(display), &ref_win_x, &ref_win_y));
    return(XEN_LIST_3(result, C_TO_XEN_int(ref_win_x), C_TO_XEN_int(ref_win_y)));
   }
}
static XEN gxg_gdk_screen_get_type(void)
{
  #define H_gdk_screen_get_type "GType gdk_screen_get_type( void)"
  return(C_TO_XEN_GType(gdk_screen_get_type()));
}
static XEN gxg_gdk_screen_get_default_colormap(XEN screen)
{
  #define H_gdk_screen_get_default_colormap "GdkColormap* gdk_screen_get_default_colormap(GdkScreen* screen)"
  XEN_ASSERT_TYPE(XEN_GdkScreen__P(screen), screen, 1, "gdk_screen_get_default_colormap", "GdkScreen*");
  return(C_TO_XEN_GdkColormap_(gdk_screen_get_default_colormap(XEN_TO_C_GdkScreen_(screen))));
}
static XEN gxg_gdk_screen_set_default_colormap(XEN screen, XEN colormap)
{
  #define H_gdk_screen_set_default_colormap "void gdk_screen_set_default_colormap(GdkScreen* screen, \
GdkColormap* colormap)"
  XEN_ASSERT_TYPE(XEN_GdkScreen__P(screen), screen, 1, "gdk_screen_set_default_colormap", "GdkScreen*");
  XEN_ASSERT_TYPE(XEN_GdkColormap__P(colormap), colormap, 2, "gdk_screen_set_default_colormap", "GdkColormap*");
  gdk_screen_set_default_colormap(XEN_TO_C_GdkScreen_(screen), XEN_TO_C_GdkColormap_(colormap));
  return(XEN_FALSE);
}
static XEN gxg_gdk_screen_get_system_colormap(XEN screen)
{
  #define H_gdk_screen_get_system_colormap "GdkColormap* gdk_screen_get_system_colormap(GdkScreen* screen)"
  XEN_ASSERT_TYPE(XEN_GdkScreen__P(screen), screen, 1, "gdk_screen_get_system_colormap", "GdkScreen*");
  return(C_TO_XEN_GdkColormap_(gdk_screen_get_system_colormap(XEN_TO_C_GdkScreen_(screen))));
}
static XEN gxg_gdk_screen_get_system_visual(XEN screen)
{
  #define H_gdk_screen_get_system_visual "GdkVisual* gdk_screen_get_system_visual(GdkScreen* screen)"
  XEN_ASSERT_TYPE(XEN_GdkScreen__P(screen), screen, 1, "gdk_screen_get_system_visual", "GdkScreen*");
  return(C_TO_XEN_GdkVisual_(gdk_screen_get_system_visual(XEN_TO_C_GdkScreen_(screen))));
}
static XEN gxg_gdk_screen_get_rgb_colormap(XEN screen)
{
  #define H_gdk_screen_get_rgb_colormap "GdkColormap* gdk_screen_get_rgb_colormap(GdkScreen* screen)"
  XEN_ASSERT_TYPE(XEN_GdkScreen__P(screen), screen, 1, "gdk_screen_get_rgb_colormap", "GdkScreen*");
  return(C_TO_XEN_GdkColormap_(gdk_screen_get_rgb_colormap(XEN_TO_C_GdkScreen_(screen))));
}
static XEN gxg_gdk_screen_get_rgb_visual(XEN screen)
{
  #define H_gdk_screen_get_rgb_visual "GdkVisual* gdk_screen_get_rgb_visual(GdkScreen* screen)"
  XEN_ASSERT_TYPE(XEN_GdkScreen__P(screen), screen, 1, "gdk_screen_get_rgb_visual", "GdkScreen*");
  return(C_TO_XEN_GdkVisual_(gdk_screen_get_rgb_visual(XEN_TO_C_GdkScreen_(screen))));
}
static XEN gxg_gdk_screen_get_root_window(XEN screen)
{
  #define H_gdk_screen_get_root_window "GdkWindow* gdk_screen_get_root_window(GdkScreen* screen)"
  XEN_ASSERT_TYPE(XEN_GdkScreen__P(screen), screen, 1, "gdk_screen_get_root_window", "GdkScreen*");
  return(C_TO_XEN_GdkWindow_(gdk_screen_get_root_window(XEN_TO_C_GdkScreen_(screen))));
}
static XEN gxg_gdk_screen_get_display(XEN screen)
{
  #define H_gdk_screen_get_display "GdkDisplay* gdk_screen_get_display(GdkScreen* screen)"
  XEN_ASSERT_TYPE(XEN_GdkScreen__P(screen), screen, 1, "gdk_screen_get_display", "GdkScreen*");
  return(C_TO_XEN_GdkDisplay_(gdk_screen_get_display(XEN_TO_C_GdkScreen_(screen))));
}
static XEN gxg_gdk_screen_get_number(XEN screen)
{
  #define H_gdk_screen_get_number "int gdk_screen_get_number(GdkScreen* screen)"
  XEN_ASSERT_TYPE(XEN_GdkScreen__P(screen), screen, 1, "gdk_screen_get_number", "GdkScreen*");
  return(C_TO_XEN_int(gdk_screen_get_number(XEN_TO_C_GdkScreen_(screen))));
}
static XEN gxg_gdk_screen_get_width(XEN screen)
{
  #define H_gdk_screen_get_width "int gdk_screen_get_width(GdkScreen* screen)"
  XEN_ASSERT_TYPE(XEN_GdkScreen__P(screen), screen, 1, "gdk_screen_get_width", "GdkScreen*");
  return(C_TO_XEN_int(gdk_screen_get_width(XEN_TO_C_GdkScreen_(screen))));
}
static XEN gxg_gdk_screen_get_height(XEN screen)
{
  #define H_gdk_screen_get_height "int gdk_screen_get_height(GdkScreen* screen)"
  XEN_ASSERT_TYPE(XEN_GdkScreen__P(screen), screen, 1, "gdk_screen_get_height", "GdkScreen*");
  return(C_TO_XEN_int(gdk_screen_get_height(XEN_TO_C_GdkScreen_(screen))));
}
static XEN gxg_gdk_screen_get_width_mm(XEN screen)
{
  #define H_gdk_screen_get_width_mm "int gdk_screen_get_width_mm(GdkScreen* screen)"
  XEN_ASSERT_TYPE(XEN_GdkScreen__P(screen), screen, 1, "gdk_screen_get_width_mm", "GdkScreen*");
  return(C_TO_XEN_int(gdk_screen_get_width_mm(XEN_TO_C_GdkScreen_(screen))));
}
static XEN gxg_gdk_screen_get_height_mm(XEN screen)
{
  #define H_gdk_screen_get_height_mm "int gdk_screen_get_height_mm(GdkScreen* screen)"
  XEN_ASSERT_TYPE(XEN_GdkScreen__P(screen), screen, 1, "gdk_screen_get_height_mm", "GdkScreen*");
  return(C_TO_XEN_int(gdk_screen_get_height_mm(XEN_TO_C_GdkScreen_(screen))));
}
static XEN gxg_gdk_screen_list_visuals(XEN screen)
{
  #define H_gdk_screen_list_visuals "GList* gdk_screen_list_visuals(GdkScreen* screen)"
  XEN_ASSERT_TYPE(XEN_GdkScreen__P(screen), screen, 1, "gdk_screen_list_visuals", "GdkScreen*");
  return(C_TO_XEN_GList_(gdk_screen_list_visuals(XEN_TO_C_GdkScreen_(screen))));
}
static XEN gxg_gdk_screen_get_toplevel_windows(XEN screen)
{
  #define H_gdk_screen_get_toplevel_windows "GList* gdk_screen_get_toplevel_windows(GdkScreen* screen)"
  XEN_ASSERT_TYPE(XEN_GdkScreen__P(screen), screen, 1, "gdk_screen_get_toplevel_windows", "GdkScreen*");
  return(C_TO_XEN_GList_(gdk_screen_get_toplevel_windows(XEN_TO_C_GdkScreen_(screen))));
}
static XEN gxg_gdk_screen_make_display_name(XEN screen)
{
  #define H_gdk_screen_make_display_name "gchar* gdk_screen_make_display_name(GdkScreen* screen)"
  XEN_ASSERT_TYPE(XEN_GdkScreen__P(screen), screen, 1, "gdk_screen_make_display_name", "GdkScreen*");
  return(C_TO_XEN_gchar_(gdk_screen_make_display_name(XEN_TO_C_GdkScreen_(screen))));
}
static XEN gxg_gdk_screen_get_n_monitors(XEN screen)
{
  #define H_gdk_screen_get_n_monitors "int gdk_screen_get_n_monitors(GdkScreen* screen)"
  XEN_ASSERT_TYPE(XEN_GdkScreen__P(screen), screen, 1, "gdk_screen_get_n_monitors", "GdkScreen*");
  return(C_TO_XEN_int(gdk_screen_get_n_monitors(XEN_TO_C_GdkScreen_(screen))));
}
static XEN gxg_gdk_screen_get_monitor_geometry(XEN screen, XEN monitor_num, XEN dest)
{
  #define H_gdk_screen_get_monitor_geometry "void gdk_screen_get_monitor_geometry(GdkScreen* screen, \
int monitor_num, GdkRectangle* dest)"
  XEN_ASSERT_TYPE(XEN_GdkScreen__P(screen), screen, 1, "gdk_screen_get_monitor_geometry", "GdkScreen*");
  XEN_ASSERT_TYPE(XEN_int_P(monitor_num), monitor_num, 2, "gdk_screen_get_monitor_geometry", "int");
  XEN_ASSERT_TYPE(XEN_GdkRectangle__P(dest), dest, 3, "gdk_screen_get_monitor_geometry", "GdkRectangle*");
  gdk_screen_get_monitor_geometry(XEN_TO_C_GdkScreen_(screen), XEN_TO_C_int(monitor_num), XEN_TO_C_GdkRectangle_(dest));
  return(XEN_FALSE);
}
static XEN gxg_gdk_screen_get_monitor_at_point(XEN screen, XEN x, XEN y)
{
  #define H_gdk_screen_get_monitor_at_point "int gdk_screen_get_monitor_at_point(GdkScreen* screen, int x, \
int y)"
  XEN_ASSERT_TYPE(XEN_GdkScreen__P(screen), screen, 1, "gdk_screen_get_monitor_at_point", "GdkScreen*");
  XEN_ASSERT_TYPE(XEN_int_P(x), x, 2, "gdk_screen_get_monitor_at_point", "int");
  XEN_ASSERT_TYPE(XEN_int_P(y), y, 3, "gdk_screen_get_monitor_at_point", "int");
  return(C_TO_XEN_int(gdk_screen_get_monitor_at_point(XEN_TO_C_GdkScreen_(screen), XEN_TO_C_int(x), XEN_TO_C_int(y))));
}
static XEN gxg_gdk_screen_get_monitor_at_window(XEN screen, XEN window)
{
  #define H_gdk_screen_get_monitor_at_window "int gdk_screen_get_monitor_at_window(GdkScreen* screen, \
GdkWindow* window)"
  XEN_ASSERT_TYPE(XEN_GdkScreen__P(screen), screen, 1, "gdk_screen_get_monitor_at_window", "GdkScreen*");
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 2, "gdk_screen_get_monitor_at_window", "GdkWindow*");
  return(C_TO_XEN_int(gdk_screen_get_monitor_at_window(XEN_TO_C_GdkScreen_(screen), XEN_TO_C_GdkWindow_(window))));
}
static XEN gxg_gdk_screen_broadcast_client_message(XEN screen, XEN event)
{
  #define H_gdk_screen_broadcast_client_message "void gdk_screen_broadcast_client_message(GdkScreen* screen, \
GdkEvent* event)"
  XEN_ASSERT_TYPE(XEN_GdkScreen__P(screen), screen, 1, "gdk_screen_broadcast_client_message", "GdkScreen*");
  XEN_ASSERT_TYPE(XEN_GdkEvent__P(event), event, 2, "gdk_screen_broadcast_client_message", "GdkEvent*");
  gdk_screen_broadcast_client_message(XEN_TO_C_GdkScreen_(screen), XEN_TO_C_GdkEvent_(event));
  return(XEN_FALSE);
}
static XEN gxg_gdk_screen_get_default(void)
{
  #define H_gdk_screen_get_default "GdkScreen* gdk_screen_get_default( void)"
  return(C_TO_XEN_GdkScreen_(gdk_screen_get_default()));
}
static XEN gxg_gtk_clipboard_get_for_display(XEN display, XEN selection)
{
  #define H_gtk_clipboard_get_for_display "GtkClipboard* gtk_clipboard_get_for_display(GdkDisplay* display, \
GdkAtom selection)"
  XEN_ASSERT_TYPE(XEN_GdkDisplay__P(display), display, 1, "gtk_clipboard_get_for_display", "GdkDisplay*");
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(selection), selection, 2, "gtk_clipboard_get_for_display", "GdkAtom");
  return(C_TO_XEN_GtkClipboard_(gtk_clipboard_get_for_display(XEN_TO_C_GdkDisplay_(display), XEN_TO_C_GdkAtom(selection))));
}
static XEN gxg_gtk_clipboard_get_display(XEN clipboard)
{
  #define H_gtk_clipboard_get_display "GdkDisplay* gtk_clipboard_get_display(GtkClipboard* clipboard)"
  XEN_ASSERT_TYPE(XEN_GtkClipboard__P(clipboard), clipboard, 1, "gtk_clipboard_get_display", "GtkClipboard*");
  return(C_TO_XEN_GdkDisplay_(gtk_clipboard_get_display(XEN_TO_C_GtkClipboard_(clipboard))));
}
static XEN gxg_gtk_widget_get_screen(XEN widget)
{
  #define H_gtk_widget_get_screen "GdkScreen* gtk_widget_get_screen(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_get_screen", "GtkWidget*");
  return(C_TO_XEN_GdkScreen_(gtk_widget_get_screen(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_widget_has_screen(XEN widget)
{
  #define H_gtk_widget_has_screen "gboolean gtk_widget_has_screen(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_has_screen", "GtkWidget*");
  return(C_TO_XEN_gboolean(gtk_widget_has_screen(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_widget_get_display(XEN widget)
{
  #define H_gtk_widget_get_display "GdkDisplay* gtk_widget_get_display(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_get_display", "GtkWidget*");
  return(C_TO_XEN_GdkDisplay_(gtk_widget_get_display(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_widget_get_root_window(XEN widget)
{
  #define H_gtk_widget_get_root_window "GdkWindow* gtk_widget_get_root_window(GtkWidget* widget)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_get_root_window", "GtkWidget*");
  return(C_TO_XEN_GdkWindow_(gtk_widget_get_root_window(XEN_TO_C_GtkWidget_(widget))));
}
static XEN gxg_gtk_widget_get_clipboard(XEN widget, XEN selection)
{
  #define H_gtk_widget_get_clipboard "GtkClipboard* gtk_widget_get_clipboard(GtkWidget* widget, GdkAtom selection)"
  XEN_ASSERT_TYPE(XEN_GtkWidget__P(widget), widget, 1, "gtk_widget_get_clipboard", "GtkWidget*");
  XEN_ASSERT_TYPE(XEN_GdkAtom_P(selection), selection, 2, "gtk_widget_get_clipboard", "GdkAtom");
  return(C_TO_XEN_GtkClipboard_(gtk_widget_get_clipboard(XEN_TO_C_GtkWidget_(widget), XEN_TO_C_GdkAtom(selection))));
}
#endif

#ifdef GTK_CELL_RENDERER_FOCUSED
static XEN gxg_gdk_get_display_arg_name(void)
{
  #define H_gdk_get_display_arg_name "gchar* gdk_get_display_arg_name( void)"
  return(C_TO_XEN_gchar_(gdk_get_display_arg_name()));
}
static XEN gxg_gdk_notify_startup_complete(void)
{
  #define H_gdk_notify_startup_complete "void gdk_notify_startup_complete( void)"
  gdk_notify_startup_complete();
  return(XEN_FALSE);
}
static XEN gxg_gtk_tree_view_column_cell_get_position(XEN tree_column, XEN cell_renderer, XEN start_pos, XEN width)
{
  #define H_gtk_tree_view_column_cell_get_position "gboolean gtk_tree_view_column_cell_get_position(GtkTreeViewColumn* tree_column, \
GtkCellRenderer* cell_renderer, gint* [start_pos], gint* [width])"
  gint ref_start_pos;
  gint ref_width;
  XEN_ASSERT_TYPE(XEN_GtkTreeViewColumn__P(tree_column), tree_column, 1, "gtk_tree_view_column_cell_get_position", "GtkTreeViewColumn*");
  XEN_ASSERT_TYPE(XEN_GtkCellRenderer__P(cell_renderer), cell_renderer, 2, "gtk_tree_view_column_cell_get_position", "GtkCellRenderer*");
  {
    XEN result = XEN_FALSE;
    result = C_TO_XEN_gboolean(gtk_tree_view_column_cell_get_position(XEN_TO_C_GtkTreeViewColumn_(tree_column), XEN_TO_C_GtkCellRenderer_(cell_renderer), 
                                                                      &ref_start_pos, &ref_width));
    return(XEN_LIST_3(result, C_TO_XEN_gint(ref_start_pos), C_TO_XEN_gint(ref_width)));
   }
}
static XEN gxg_gtk_window_set_auto_startup_notification(XEN setting)
{
  #define H_gtk_window_set_auto_startup_notification "void gtk_window_set_auto_startup_notification(gboolean setting)"
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 1, "gtk_window_set_auto_startup_notification", "gboolean");
  gtk_window_set_auto_startup_notification(XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gtk_list_store_move_after(XEN store, XEN iter, XEN position)
{
  #define H_gtk_list_store_move_after "void gtk_list_store_move_after(GtkListStore* store, GtkTreeIter* iter, \
GtkTreeIter* position)"
  XEN_ASSERT_TYPE(XEN_GtkListStore__P(store), store, 1, "gtk_list_store_move_after", "GtkListStore*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_list_store_move_after", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(position), position, 3, "gtk_list_store_move_after", "GtkTreeIter*");
  gtk_list_store_move_after(XEN_TO_C_GtkListStore_(store), XEN_TO_C_GtkTreeIter_(iter), XEN_TO_C_GtkTreeIter_(position));
  return(XEN_FALSE);
}
static XEN gxg_gtk_list_store_move_before(XEN store, XEN iter, XEN position)
{
  #define H_gtk_list_store_move_before "void gtk_list_store_move_before(GtkListStore* store, GtkTreeIter* iter, \
GtkTreeIter* position)"
  XEN_ASSERT_TYPE(XEN_GtkListStore__P(store), store, 1, "gtk_list_store_move_before", "GtkListStore*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(iter), iter, 2, "gtk_list_store_move_before", "GtkTreeIter*");
  XEN_ASSERT_TYPE(XEN_GtkTreeIter__P(position), position, 3, "gtk_list_store_move_before", "GtkTreeIter*");
  gtk_list_store_move_before(XEN_TO_C_GtkListStore_(store), XEN_TO_C_GtkTreeIter_(iter), XEN_TO_C_GtkTreeIter_(position));
  return(XEN_FALSE);
}
#endif

#if HAVE_GTK_FILE_CHOOSER_DIALOG_NEW
static XEN gxg_gdk_cursor_new_from_pixbuf(XEN display, XEN pixbuf, XEN x, XEN y)
{
  #define H_gdk_cursor_new_from_pixbuf "GdkCursor* gdk_cursor_new_from_pixbuf(GdkDisplay* display, GdkPixbuf* pixbuf, \
gint x, gint y)"
  XEN_ASSERT_TYPE(XEN_GdkDisplay__P(display), display, 1, "gdk_cursor_new_from_pixbuf", "GdkDisplay*");
  XEN_ASSERT_TYPE(XEN_GdkPixbuf__P(pixbuf), pixbuf, 2, "gdk_cursor_new_from_pixbuf", "GdkPixbuf*");
  XEN_ASSERT_TYPE(XEN_gint_P(x), x, 3, "gdk_cursor_new_from_pixbuf", "gint");
  XEN_ASSERT_TYPE(XEN_gint_P(y), y, 4, "gdk_cursor_new_from_pixbuf", "gint");
  return(C_TO_XEN_GdkCursor_(gdk_cursor_new_from_pixbuf(XEN_TO_C_GdkDisplay_(display), XEN_TO_C_GdkPixbuf_(pixbuf), XEN_TO_C_gint(x), 
                                                        XEN_TO_C_gint(y))));
}
static XEN gxg_gdk_display_flush(XEN display)
{
  #define H_gdk_display_flush "void gdk_display_flush(GdkDisplay* display)"
  XEN_ASSERT_TYPE(XEN_GdkDisplay__P(display), display, 1, "gdk_display_flush", "GdkDisplay*");
  gdk_display_flush(XEN_TO_C_GdkDisplay_(display));
  return(XEN_FALSE);
}
static XEN gxg_gdk_display_supports_cursor_alpha(XEN display)
{
  #define H_gdk_display_supports_cursor_alpha "gboolean gdk_display_supports_cursor_alpha(GdkDisplay* display)"
  XEN_ASSERT_TYPE(XEN_GdkDisplay__P(display), display, 1, "gdk_display_supports_cursor_alpha", "GdkDisplay*");
  return(C_TO_XEN_gboolean(gdk_display_supports_cursor_alpha(XEN_TO_C_GdkDisplay_(display))));
}
static XEN gxg_gdk_display_supports_cursor_color(XEN display)
{
  #define H_gdk_display_supports_cursor_color "gboolean gdk_display_supports_cursor_color(GdkDisplay* display)"
  XEN_ASSERT_TYPE(XEN_GdkDisplay__P(display), display, 1, "gdk_display_supports_cursor_color", "GdkDisplay*");
  return(C_TO_XEN_gboolean(gdk_display_supports_cursor_color(XEN_TO_C_GdkDisplay_(display))));
}
static XEN gxg_gdk_display_get_default_cursor_size(XEN display)
{
  #define H_gdk_display_get_default_cursor_size "guint gdk_display_get_default_cursor_size(GdkDisplay* display)"
  XEN_ASSERT_TYPE(XEN_GdkDisplay__P(display), display, 1, "gdk_display_get_default_cursor_size", "GdkDisplay*");
  return(C_TO_XEN_guint(gdk_display_get_default_cursor_size(XEN_TO_C_GdkDisplay_(display))));
}
static XEN gxg_gdk_display_get_maximal_cursor_size(XEN display, XEN width, XEN height)
{
  #define H_gdk_display_get_maximal_cursor_size "void gdk_display_get_maximal_cursor_size(GdkDisplay* display, \
guint* [width], guint* [height])"
  guint ref_width;
  guint ref_height;
  XEN_ASSERT_TYPE(XEN_GdkDisplay__P(display), display, 1, "gdk_display_get_maximal_cursor_size", "GdkDisplay*");
  gdk_display_get_maximal_cursor_size(XEN_TO_C_GdkDisplay_(display), &ref_width, &ref_height);
  return(XEN_LIST_2(C_TO_XEN_guint(ref_width), C_TO_XEN_guint(ref_height)));
}
static XEN gxg_gdk_window_set_keep_above(XEN window, XEN setting)
{
  #define H_gdk_window_set_keep_above "void gdk_window_set_keep_above(GdkWindow* window, gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_set_keep_above", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gdk_window_set_keep_above", "gboolean");
  gdk_window_set_keep_above(XEN_TO_C_GdkWindow_(window), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
static XEN gxg_gdk_window_set_keep_below(XEN window, XEN setting)
{
  #define H_gdk_window_set_keep_below "void gdk_window_set_keep_below(GdkWindow* window, gboolean setting)"
  XEN_ASSERT_TYPE(XEN_GdkWindow__P(window), window, 1, "gdk_window_set_keep_below", "GdkWindow*");
  XEN_ASSERT_TYPE(XEN_gboolean_P(setting), setting, 2, "gdk_window_set_keep_below", "gboolean");
  gdk_window_set_keep_below(XEN_TO_C_GdkWindow_(window), XEN_TO_C_gboolean(setting));
  return(XEN_FALSE);
}
