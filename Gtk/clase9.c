#include <gtk/gtk.h>

gboolean delete_event(GtkWidget *window, GdkEvent *event) {
    printf("Delete event\n");
    return FALSE;
}

void exit_callback(GtkWidget *window, gpointer data) {
    printf("Terminando prograna\n");
    gtk_main_quit();
}

int main(int argc, char **argv)
{
    GtkWidget *wgtAplicacion;
    GtkWidget *vboxContenedor;
    GtkWidget *btn1;
    GtkWidget *btn2;
    GtkWidget *btn3;
    GtkWidget *btn4;
    GtkWidget *btn5;

    gtk_init(&argc, &argv);

    wgtAplicacion = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    g_signal_connect( G_OBJECT(wgtAplicacion), "delete_event", G_CALLBACK(delete_event), NULL);
    g_signal_connect( G_OBJECT(wgtAplicacion), "destroy", G_CALLBACK(exit_callback), NULL);

    gtk_window_set_position(GTK_WINDOW(wgtAplicacion), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(wgtAplicacion), 400, 400);
    gtk_window_set_title( GTK_WINDOW(wgtAplicacion), "Clase 9 GTK Vbox" );

    gtk_container_set_border_width(GTK_CONTAINER(wgtAplicacion), 5);

    vboxContenedor = gtk_vbox_new(TRUE, 1);

    gtk_container_add(GTK_CONTAINER(wgtAplicacion), vboxContenedor);

    btn1 = gtk_button_new_with_label("Uno");
    btn2 = gtk_button_new_with_label("Dos");
    btn3 = gtk_button_new_with_label("Tres");
    btn4 = gtk_button_new_with_label("Cuatro");
    btn5 = gtk_button_new_with_label("Cinco");

    gtk_box_pack_start(GTK_BOX(vboxContenedor), btn1, TRUE, TRUE, 1 );
    gtk_box_pack_start(GTK_BOX(vboxContenedor), btn2, TRUE, TRUE, 1 );
    gtk_box_pack_start(GTK_BOX(vboxContenedor), btn3, TRUE, TRUE, 1 );

    gtk_widget_show_all(wgtAplicacion);

    gtk_main ();

}