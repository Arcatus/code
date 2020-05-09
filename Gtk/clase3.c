#include <gtk/gtk.h>

void exit_callback(GtkWidget *window, gpointer data) {
    printf("Terminando prograna\n");
    gtk_main_quit();
}

gboolean delete_event(GtkWidget *window, GdkEvent *event) {
    printf("Delete event\n");
    return FALSE;
}

int main(int argc, char **argv) {
    
    GtkWidget *window;
    
    gtk_init(&argc, &argv);
    
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title( GTK_WINDOW(window), "Clase 3 GTK Eventos" );
    gtk_widget_show(window);

    g_signal_connect( G_OBJECT(window), "destroy", G_CALLBACK(exit_callback), NULL);
    g_signal_connect( G_OBJECT(window), "delete_event", G_CALLBACK(delete_event), NULL);
    gtk_main ();

    return 0;
}