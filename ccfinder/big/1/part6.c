#if HAVE_GUILE
static void define_structs(void)
{

#if (!WITH_GTK_AND_X11)
  XG_DEFINE_READER(parent, gxg_parent, 1, 0, 0, NULL);
#endif
  XG_DEFINE_READER(style, gxg_style, 1, 0, 0, NULL);
  XG_DEFINE_READER(saved_state, gxg_saved_state, 1, 0, 0, NULL);
  XG_DEFINE_READER(icon_factories, gxg_icon_factories, 1, 0, 0, NULL);
  XG_DEFINE_READER(property_cache, gxg_property_cache, 1, 0, 0, NULL);
  XG_DEFINE_READER(styles, gxg_styles, 1, 0, 0, NULL);
  XG_DEFINE_READER(rc_style, gxg_rc_style, 1, 0, 0, NULL);
  XG_DEFINE_READER(attach_count, gxg_attach_count, 1, 0, 0, NULL);
  XG_DEFINE_READER(bg_pixmap, gxg_bg_pixmap, 1, 0, 0, NULL);
  XG_DEFINE_READER(white_gc, gxg_white_gc, 1, 0, 0, NULL);
  XG_DEFINE_READER(black_gc, gxg_black_gc, 1, 0, 0, NULL);
  XG_DEFINE_READER(text_aa_gc, gxg_text_aa_gc, 1, 0, 0, NULL);
  XG_DEFINE_READER(base_gc, gxg_base_gc, 1, 0, 0, NULL);
  XG_DEFINE_READER(text_gc, gxg_text_gc, 1, 0, 0, NULL);
  XG_DEFINE_READER(mid_gc, gxg_mid_gc, 1, 0, 0, NULL);
  XG_DEFINE_READER(dark_gc, gxg_dark_gc, 1, 0, 0, NULL);
  XG_DEFINE_READER(light_gc, gxg_light_gc, 1, 0, 0, NULL);
  XG_DEFINE_READER(bg_gc, gxg_bg_gc, 1, 0, 0, NULL);
  XG_DEFINE_READER(fg_gc, gxg_fg_gc, 1, 0, 0, NULL);
  XG_DEFINE_READER(ythickness, gxg_ythickness, 1, 0, 0, NULL);
  XG_DEFINE_READER(xthickness, gxg_xthickness, 1, 0, 0, NULL);
  XG_DEFINE_READER(font_desc, gxg_font_desc, 1, 0, 0, NULL);
  XG_DEFINE_READER(text_aa, gxg_text_aa, 1, 0, 0, NULL);
  XG_DEFINE_READER(base, gxg_base, 1, 0, 0, NULL);
  XG_DEFINE_READER(text, gxg_text, 1, 0, 0, NULL);
  XG_DEFINE_READER(mid, gxg_mid, 1, 0, 0, NULL);
  XG_DEFINE_READER(dark, gxg_dark, 1, 0, 0, NULL);
  XG_DEFINE_READER(light, gxg_light, 1, 0, 0, NULL);
  XG_DEFINE_READER(bg, gxg_bg, 1, 0, 0, NULL);
  XG_DEFINE_READER(fg, gxg_fg, 1, 0, 0, NULL);
  XG_DEFINE_READER(auto_resize, gxg_auto_resize, 1, 0, 0, NULL);
  XG_DEFINE_READER(dialog_width, gxg_dialog_width, 1, 0, 0, NULL);
  XG_DEFINE_READER(apply_button, gxg_apply_button, 1, 0, 0, NULL);
  XG_DEFINE_READER(fontsel, gxg_fontsel, 1, 0, 0, NULL);
  XG_DEFINE_READER(button_area, gxg_button_area, 1, 0, 0, NULL);
  XG_DEFINE_READER(fileop_ren_file, gxg_fileop_ren_file, 1, 0, 0, NULL);
  XG_DEFINE_READER(fileop_del_file, gxg_fileop_del_file, 1, 0, 0, NULL);
  XG_DEFINE_READER(fileop_c_dir, gxg_fileop_c_dir, 1, 0, 0, NULL);
  XG_DEFINE_READER(cmpl_state, gxg_cmpl_state, 1, 0, 0, NULL);
  XG_DEFINE_READER(fileop_file, gxg_fileop_file, 1, 0, 0, NULL);
  XG_DEFINE_READER(fileop_entry, gxg_fileop_entry, 1, 0, 0, NULL);
  XG_DEFINE_READER(fileop_dialog, gxg_fileop_dialog, 1, 0, 0, NULL);
  XG_DEFINE_READER(history_list, gxg_history_list, 1, 0, 0, NULL);
  XG_DEFINE_READER(history_menu, gxg_history_menu, 1, 0, 0, NULL);
  XG_DEFINE_READER(history_pulldown, gxg_history_pulldown, 1, 0, 0, NULL);
  XG_DEFINE_READER(main_vbox, gxg_main_vbox, 1, 0, 0, NULL);
  XG_DEFINE_READER(selection_text, gxg_selection_text, 1, 0, 0, NULL);
  XG_DEFINE_READER(selection_entry, gxg_selection_entry, 1, 0, 0, NULL);
  XG_DEFINE_READER(file_list, gxg_file_list, 1, 0, 0, NULL);
  XG_DEFINE_READER(dir_list, gxg_dir_list, 1, 0, 0, NULL);
  XG_DEFINE_READER(separator, gxg_separator, 1, 0, 0, NULL);
  XG_DEFINE_READER(action_area, gxg_action_area, 1, 0, 0, NULL);
  XG_DEFINE_READER(vbox, gxg_vbox, 1, 0, 0, NULL);
  XG_DEFINE_READER(help_button, gxg_help_button, 1, 0, 0, NULL);
  XG_DEFINE_READER(cancel_button, gxg_cancel_button, 1, 0, 0, NULL);
  XG_DEFINE_READER(ok_button, gxg_ok_button, 1, 0, 0, NULL);
  XG_DEFINE_READER(colorsel, gxg_colorsel, 1, 0, 0, NULL);
  XG_DEFINE_READER(page_size, gxg_page_size, 1, 0, 0, NULL);
  XG_DEFINE_READER(page_increment, gxg_page_increment, 1, 0, 0, NULL);
  XG_DEFINE_READER(step_increment, gxg_step_increment, 1, 0, 0, NULL);
  XG_DEFINE_READER(upper, gxg_upper, 1, 0, 0, NULL);
  XG_DEFINE_READER(lower, gxg_lower, 1, 0, 0, NULL);
#if (!WITH_GTK_AND_X11)
  XG_DEFINE_READER(win_gravity, gxg_win_gravity, 1, 0, 0, NULL);
#endif
  XG_DEFINE_READER(max_aspect, gxg_max_aspect, 1, 0, 0, NULL);
  XG_DEFINE_READER(min_aspect, gxg_min_aspect, 1, 0, 0, NULL);
#if (!WITH_GTK_AND_X11)
  XG_DEFINE_READER(height_inc, gxg_height_inc, 1, 0, 0, NULL);
  XG_DEFINE_READER(width_inc, gxg_width_inc, 1, 0, 0, NULL);
#endif
  XG_DEFINE_READER(base_height, gxg_base_height, 1, 0, 0, NULL);
  XG_DEFINE_READER(base_width, gxg_base_width, 1, 0, 0, NULL);
#if (!WITH_GTK_AND_X11)
  XG_DEFINE_READER(max_height, gxg_max_height, 1, 0, 0, NULL);
  XG_DEFINE_READER(max_width, gxg_max_width, 1, 0, 0, NULL);
  XG_DEFINE_READER(min_height, gxg_min_height, 1, 0, 0, NULL);
  XG_DEFINE_READER(min_width, gxg_min_width, 1, 0, 0, NULL);
  XG_DEFINE_READER(override_redirect, gxg_override_redirect, 1, 0, 0, NULL);
#endif
  XG_DEFINE_READER(wmclass_class, gxg_wmclass_class, 1, 0, 0, NULL);
  XG_DEFINE_READER(wmclass_name, gxg_wmclass_name, 1, 0, 0, NULL);
#if (!WITH_GTK_AND_X11)
  XG_DEFINE_READER(cursor, gxg_cursor, 1, 0, 0, NULL);
#endif
  XG_DEFINE_READER(window_type, gxg_window_type, 1, 0, 0, NULL);
#if (!WITH_GTK_AND_X11)
  XG_DEFINE_READER(event_mask, gxg_event_mask, 1, 0, 0, NULL);
#endif
  XG_DEFINE_READER(title, gxg_title, 1, 0, 0, NULL);
  XG_DEFINE_READER(blue_prec, gxg_blue_prec, 1, 0, 0, NULL);
  XG_DEFINE_READER(blue_shift, gxg_blue_shift, 1, 0, 0, NULL);
#if (!WITH_GTK_AND_X11)
  XG_DEFINE_READER(blue_mask, gxg_blue_mask, 1, 0, 0, NULL);
#endif
  XG_DEFINE_READER(green_prec, gxg_green_prec, 1, 0, 0, NULL);
  XG_DEFINE_READER(green_shift, gxg_green_shift, 1, 0, 0, NULL);
#if (!WITH_GTK_AND_X11)
  XG_DEFINE_READER(green_mask, gxg_green_mask, 1, 0, 0, NULL);
#endif
  XG_DEFINE_READER(red_prec, gxg_red_prec, 1, 0, 0, NULL);
  XG_DEFINE_READER(red_shift, gxg_red_shift, 1, 0, 0, NULL);
#if (!WITH_GTK_AND_X11)
  XG_DEFINE_READER(red_mask, gxg_red_mask, 1, 0, 0, NULL);
  XG_DEFINE_READER(bits_per_rgb, gxg_bits_per_rgb, 1, 0, 0, NULL);
  XG_DEFINE_READER(colormap_size, gxg_colormap_size, 1, 0, 0, NULL);
#endif
  XG_DEFINE_READER(info_list, gxg_info_list, 1, 0, 0, NULL);
  XG_DEFINE_READER(n_colors, gxg_n_colors, 1, 0, 0, NULL);
  XG_DEFINE_READER(level, gxg_level, 1, 0, 0, NULL);
#if (!WITH_GTK_AND_X11)
  XG_DEFINE_READER(keycode, gxg_keycode, 1, 0, 0, NULL);
#endif
  XG_DEFINE_READER(keys, gxg_keys, 1, 0, 0, NULL);
  XG_DEFINE_READER(num_keys, gxg_num_keys, 1, 0, 0, NULL);
  XG_DEFINE_READER(num_axes, gxg_num_axes, 1, 0, 0, NULL);
  XG_DEFINE_READER(has_cursor, gxg_has_cursor, 1, 0, 0, NULL);
  XG_DEFINE_READER(source, gxg_source, 1, 0, 0, NULL);
  XG_DEFINE_READER(mem, gxg_mem, 1, 0, 0, NULL);
#if (!WITH_GTK_AND_X11)
  XG_DEFINE_READER(bits_per_pixel, gxg_bits_per_pixel, 1, 0, 0, NULL);
#endif
  XG_DEFINE_READER(bpl, gxg_bpl, 1, 0, 0, NULL);
  XG_DEFINE_READER(bpp, gxg_bpp, 1, 0, 0, NULL);
#if (!WITH_GTK_AND_X11)
  XG_DEFINE_READER(depth, gxg_depth, 1, 0, 0, NULL);
  XG_DEFINE_READER(byte_order, gxg_byte_order, 1, 0, 0, NULL);
  XG_DEFINE_READER(colormap, gxg_colormap, 1, 0, 0, NULL);
  XG_DEFINE_READER(join_style, gxg_join_style, 1, 0, 0, NULL);
  XG_DEFINE_READER(cap_style, gxg_cap_style, 1, 0, 0, NULL);
  XG_DEFINE_READER(line_style, gxg_line_style, 1, 0, 0, NULL);
  XG_DEFINE_READER(line_width, gxg_line_width, 1, 0, 0, NULL);
  XG_DEFINE_READER(graphics_exposures, gxg_graphics_exposures, 1, 0, 0, NULL);
  XG_DEFINE_READER(clip_y_origin, gxg_clip_y_origin, 1, 0, 0, NULL);
  XG_DEFINE_READER(clip_x_origin, gxg_clip_x_origin, 1, 0, 0, NULL);
  XG_DEFINE_READER(ts_y_origin, gxg_ts_y_origin, 1, 0, 0, NULL);
  XG_DEFINE_READER(ts_x_origin, gxg_ts_x_origin, 1, 0, 0, NULL);
  XG_DEFINE_READER(subwindow_mode, gxg_subwindow_mode, 1, 0, 0, NULL);
  XG_DEFINE_READER(clip_mask, gxg_clip_mask, 1, 0, 0, NULL);
  XG_DEFINE_READER(stipple, gxg_stipple, 1, 0, 0, NULL);
  XG_DEFINE_READER(tile, gxg_tile, 1, 0, 0, NULL);
#endif
  XG_DEFINE_READER(fill, gxg_fill, 1, 0, 0, NULL);
#if (!WITH_GTK_AND_X11)
  XG_DEFINE_READER(function, gxg_function, 1, 0, 0, NULL);
#endif
  XG_DEFINE_READER(context, gxg_context, 1, 0, 0, NULL);
  XG_DEFINE_READER(new_window_state, gxg_new_window_state, 1, 0, 0, NULL);
  XG_DEFINE_READER(changed_mask, gxg_changed_mask, 1, 0, 0, NULL);
#if (!WITH_GTK_AND_X11)
  XG_DEFINE_READER(name, gxg_name, 1, 0, 0, NULL);
  XG_DEFINE_READER(requestor, gxg_requestor, 1, 0, 0, NULL);
  XG_DEFINE_READER(property, gxg_property, 1, 0, 0, NULL);
  XG_DEFINE_READER(target, gxg_target, 1, 0, 0, NULL);
  XG_DEFINE_READER(selection, gxg_selection, 1, 0, 0, NULL);
  XG_DEFINE_READER(atom, gxg_atom, 1, 0, 0, NULL);
  XG_DEFINE_READER(height, gxg_height, 1, 0, 0, NULL);
  XG_DEFINE_READER(width, gxg_width, 1, 0, 0, NULL);
#endif
  XG_DEFINE_READER(in, gxg_in, 1, 0, 0, NULL);
#if (!WITH_GTK_AND_X11)
  XG_DEFINE_READER(focus, gxg_focus, 1, 0, 0, NULL);
  XG_DEFINE_READER(detail, gxg_detail, 1, 0, 0, NULL);
  XG_DEFINE_READER(mode, gxg_mode, 1, 0, 0, NULL);
  XG_DEFINE_READER(subwindow, gxg_subwindow, 1, 0, 0, NULL);
#endif
  XG_DEFINE_READER(group, gxg_group, 1, 0, 0, NULL);
  XG_DEFINE_READER(hardware_keycode, gxg_hardware_keycode, 1, 0, 0, NULL);
  XG_DEFINE_READER(string, gxg_string, 1, 0, 0, NULL);
  XG_DEFINE_READER(length, gxg_length, 1, 0, 0, NULL);
  XG_DEFINE_READER(keyval, gxg_keyval, 1, 0, 0, NULL);
  XG_DEFINE_READER(direction, gxg_direction, 1, 0, 0, NULL);
#if (!WITH_GTK_AND_X11)
  XG_DEFINE_READER(button, gxg_button, 1, 0, 0, NULL);
  XG_DEFINE_READER(y_root, gxg_y_root, 1, 0, 0, NULL);
  XG_DEFINE_READER(x_root, gxg_x_root, 1, 0, 0, NULL);
#endif
  XG_DEFINE_READER(device, gxg_device, 1, 0, 0, NULL);
#if (!WITH_GTK_AND_X11)
  XG_DEFINE_READER(is_hint, gxg_is_hint, 1, 0, 0, NULL);
#endif
  XG_DEFINE_READER(axes, gxg_axes, 1, 0, 0, NULL);
#if (!WITH_GTK_AND_X11)
  XG_DEFINE_READER(y, gxg_y, 1, 0, 0, NULL);
  XG_DEFINE_READER(x, gxg_x, 1, 0, 0, NULL);
  XG_DEFINE_READER(time, gxg_time, 1, 0, 0, NULL);
  XG_DEFINE_READER(state, gxg_state, 1, 0, 0, NULL);
  XG_DEFINE_READER(count, gxg_count, 1, 0, 0, NULL);
#endif
  XG_DEFINE_READER(region, gxg_region, 1, 0, 0, NULL);
#if (!WITH_GTK_AND_X11)
  XG_DEFINE_READER(send_event, gxg_send_event, 1, 0, 0, NULL);
  XG_DEFINE_READER(window, gxg_window, 1, 0, 0, NULL);
#endif
  XG_DEFINE_READER(start_time, gxg_start_time, 1, 0, 0, NULL);
  XG_DEFINE_READER(action, gxg_action, 1, 0, 0, NULL);
  XG_DEFINE_READER(suggested_action, gxg_suggested_action, 1, 0, 0, NULL);
  XG_DEFINE_READER(actions, gxg_actions, 1, 0, 0, NULL);
  XG_DEFINE_READER(targets, gxg_targets, 1, 0, 0, NULL);
  XG_DEFINE_READER(dest_window, gxg_dest_window, 1, 0, 0, NULL);
  XG_DEFINE_READER(source_window, gxg_source_window, 1, 0, 0, NULL);
  XG_DEFINE_READER(is_source, gxg_is_source, 1, 0, 0, NULL);
  XG_DEFINE_READER(protocol, gxg_protocol, 1, 0, 0, NULL);
  XG_DEFINE_READER(ref_count, gxg_ref_count, 1, 0, 0, NULL);
#if (!WITH_GTK_AND_X11)
  XG_DEFINE_READER(type, gxg_type, 1, 0, 0, NULL);
#endif
  XG_DEFINE_READER(windowing_data, gxg_windowing_data, 1, 0, 0, NULL);
#if (!WITH_GTK_AND_X11)
  XG_DEFINE_READER(visual, gxg_visual, 1, 0, 0, NULL);
#endif
  XG_DEFINE_READER(colors, gxg_colors, 1, 0, 0, NULL);
  XG_DEFINE_READER(size, gxg_size, 1, 0, 0, NULL);
  XG_DEFINE_ACCESSOR(value, gxg_value, gxg_set_value, 1, 0, 2, 0);
#if (!WITH_GTK_AND_X11)
  XG_DEFINE_ACCESSOR(blue, gxg_blue, gxg_set_blue, 1, 0, 2, 0);
  XG_DEFINE_ACCESSOR(green, gxg_green, gxg_set_green, 1, 0, 2, 0);
  XG_DEFINE_ACCESSOR(red, gxg_red, gxg_set_red, 1, 0, 2, 0);
  XG_DEFINE_ACCESSOR(pixel, gxg_pixel, gxg_set_pixel, 1, 0, 2, 0);
#endif
  XG_DEFINE_PROCEDURE(GdkColor, gxg_make_GdkColor, 0, 0, 1, NULL);
  XG_DEFINE_PROCEDURE(GdkCursor, gxg_make_GdkCursor, 0, 0, 1, NULL);
  XG_DEFINE_PROCEDURE(GdkPoint, gxg_make_GdkPoint, 0, 0, 1, NULL);
  XG_DEFINE_PROCEDURE(GdkRectangle, gxg_make_GdkRectangle, 0, 0, 1, NULL);
  XG_DEFINE_PROCEDURE(GtkStockItem, gxg_make_GtkStockItem, 0, 0, 0, NULL);
  XG_DEFINE_PROCEDURE(GtkTextIter, gxg_make_GtkTextIter, 0, 0, 0, NULL);
  XG_DEFINE_PROCEDURE(GtkTreeIter, gxg_make_GtkTreeIter, 0, 0, 0, NULL);
  XG_DEFINE_PROCEDURE(GtkRequisition, gxg_make_GtkRequisition, 0, 0, 1, NULL);
  XG_DEFINE_PROCEDURE(PangoColor, gxg_make_PangoColor, 0, 0, 0, NULL);
  XG_DEFINE_PROCEDURE(PangoRectangle, gxg_make_PangoRectangle, 0, 0, 0, NULL);
  XG_DEFINE_PROCEDURE(PangoLogAttr, gxg_make_PangoLogAttr, 0, 0, 0, NULL);
}

#else
  #include "xg-ruby.c"
#endif
