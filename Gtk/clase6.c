#include <gtk/gtk.h>

void exit_callback(GtkWidget *window, gpointer data) {
    printf("Terminando prograna\n");
    gtk_main_quit();
}

gboolean delete_event(GtkWidget *window, GdkEvent *event) {
    printf("Delete event\n");
    return FALSE;
}

gboolean window_event(GtkWidget *window, GdkEventWindowState *event) {
    if ( event->new_window_state & GDK_WINDOW_STATE_MAXIMIZED ) {
        printf("La ventana se maximizo\n");
    } else {
        printf("Window event\n");
    }
    return FALSE;
}

GdkPixbuf* create_pixbuf(const gchar * filename) {
    GdkPixbuf *pixbuf;
    GError *error = NULL;
    pixbuf = gdk_pixbuf_new_from_file(filename, &error);
    if (!pixbuf) {
        fprintf(stderr, "%s \n", error->message);
        g_error_free(error);
    }
    return pixbuf;
}

int main(int argc, char **argv) {
    
    GtkWidget *window;
    
    gtk_init(&argc, &argv);
    
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title( GTK_WINDOW(window), "Clase 6 GTK Ventanas" );
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);
    gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("icon.png"));

    g_signal_connect( G_OBJECT(window), "destroy", G_CALLBACK(exit_callback), NULL);
    g_signal_connect( G_OBJECT(window), "delete_event", G_CALLBACK(delete_event), NULL);
    g_signal_connect( G_OBJECT(window), "window_state_event", G_CALLBACK(window_event), NULL);

    //tamanio minimo disponible
    gtk_widget_set_size_request(window, 400,400);

    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    gtk_widget_show(window);
    //maximizar
    //gtk_window_maximize(GTK_WINDOW(window));
    //minimizar
    //gtk_window_iconify(GTK_WINDOW(window));
    gtk_main ();

    return 0;
}