#include <gtk/gtk.h>

void print_event(GtkWidget *widget, GdkEventMotion *event, gpointer p)
{
    static int last = -1;
    if (last != -1) {
        printf(">%.0f, %.0f: %d\n", event->x, event->y, event->time -last);
    }
    last = event->time-last;
}

int main( int argc, char *argv[])
{
    GtkWidget *window;
    GdkWindow *gdkwin;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 800);

    gtk_widget_set_events(window, GDK_POINTER_MOTION_MASK);

    gtk_widget_show(window);

    g_signal_connect(window, "motion_notify_event",
                     G_CALLBACK (print_event), NULL);

    g_signal_connect_swapped(G_OBJECT(window), "destroy",
                             G_CALLBACK(gtk_main_quit), NULL);

    gdkwin = gtk_widget_get_window(window);

    gdk_window_set_event_compression(gdkwin, FALSE);
    gdk_window_set_event_compression(gdkwin, TRUE);

    gtk_main();

    return 0;
}
