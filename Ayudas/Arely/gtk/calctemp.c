#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>

void exit_callback(GtkWidget *window, gpointer data);
GtkWidget *addButton1(GtkWidget *theBox, const gchar *buttonText, gpointer CallBackFunction, GtkWidget *EntryBox);
GtkWidget *addButton2(GtkWidget *theBox, const gchar *buttonText, gpointer CallBackFunction, GtkWidget *EntryBox);
void ButtonClicked(GtkButton *button, gpointer data);

typedef struct t{
    GtkWidget *entry1;
    GtkWidget *entry2;
} EntryHandler;

int main(int argc, char **argv) {

    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window),250,200);
    gtk_window_set_title( GTK_WINDOW(window), "Conversión de Temperatura");
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    gtk_widget_set_size_request(window, 500,200);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    GtkWidget *hboxPrincipal = gtk_hbox_new(FALSE, 0);
    GtkWidget *paddingL = gtk_vbox_new(FALSE, 10);
    GtkWidget *paddingR = gtk_vbox_new(FALSE, 10);
    GtkWidget *paddingV1 = gtk_vbox_new(FALSE, 0);
    GtkWidget *paddingV2 = gtk_vbox_new(FALSE, 0);
    GtkWidget *paddingV3 = gtk_vbox_new(FALSE, 0);
    GtkWidget *vbox1 = gtk_vbox_new(FALSE, 0);
    GtkWidget *vbox2 = gtk_vbox_new(FALSE, 0);
    GtkWidget *vbox3 = gtk_vbox_new(FALSE, 0);

    GtkWidget *frame = gtk_frame_new(NULL);

    GtkWidget *label1 = gtk_label_new("Centigrados");
    GtkWidget *label2 = gtk_label_new("Fahrenheit");

    EntryHandler entrys;
    entrys.entry1 = gtk_entry_new();
    entrys.entry2 = gtk_entry_new();

    gtk_entry_set_editable(entrys.entry1,TRUE);
    gtk_entry_set_editable(entrys.entry2,TRUE);

    gtk_entry_set_alignment(entrys.entry1,0);
    gtk_entry_set_alignment(entrys.entry2,0);

    GtkWidget *hboxMid = gtk_hbox_new(TRUE, 0);

    GtkWidget *btn1 = addButton1(hboxMid, "   A Far    ", ButtonClicked, (gpointer) &entrys);
    GtkWidget *btn2 = addButton2(hboxMid, "   A Cen  \t", ButtonClicked, (gpointer) &entrys);

    gtk_box_pack_start(GTK_BOX(vbox1),paddingV1,FALSE,FALSE,20);
    gtk_box_pack_start(GTK_BOX(vbox1),label1,FALSE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(vbox3),paddingV3,FALSE,FALSE,20);
    gtk_box_pack_start(GTK_BOX(vbox3),label2,FALSE,FALSE,0);

    gtk_box_pack_start(GTK_BOX(vbox1),entrys.entry1,FALSE,FALSE,10);
    gtk_box_pack_start(GTK_BOX(vbox3),entrys.entry2,FALSE,FALSE,10);


    gtk_box_pack_start(GTK_BOX(vbox2),paddingV2,FALSE,FALSE,30);
    gtk_box_pack_start(GTK_BOX(vbox2),hboxMid,FALSE,FALSE,10);

    gtk_box_pack_start(GTK_BOX(hboxPrincipal),paddingL,FALSE,FALSE,15);
    gtk_container_add(GTK_CONTAINER(hboxPrincipal),vbox1);
    gtk_container_add(GTK_CONTAINER(hboxPrincipal),vbox2);
    gtk_container_add(GTK_CONTAINER(hboxPrincipal),vbox3);
    gtk_box_pack_start(GTK_BOX(hboxPrincipal),paddingR,FALSE,FALSE,15);
    gtk_container_add(GTK_CONTAINER(frame),hboxPrincipal);
    gtk_container_add(GTK_CONTAINER(window),frame);
    g_signal_connect( G_OBJECT(window), "destroy", G_CALLBACK(exit_callback), NULL);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

void exit_callback(GtkWidget *window, gpointer data) {
    gtk_main_quit();
}

GtkWidget *addButton1(GtkWidget *theBox, const gchar *buttonText, gpointer CallBackFunction, GtkWidget *EntryBox)
{
    GtkWidget *button;
    button = gtk_button_new_with_label(buttonText);
    gtk_box_pack_start(GTK_BOX(theBox),button,FALSE,TRUE,0);
    gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(CallBackFunction),EntryBox);
    return button;
}

GtkWidget *addButton2(GtkWidget *theBox, const gchar *buttonText, gpointer CallBackFunction, GtkWidget *EntryBox)
{
    GtkWidget *button;
    button = gtk_button_new_with_label(buttonText);
    gtk_box_pack_start(GTK_BOX(theBox),button,FALSE,TRUE,0);
    gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(CallBackFunction),EntryBox);
    return button;
}


void ButtonClicked(GtkButton *button, gpointer data)
{
    const gchar *text, *text2;
    char texto2[22];
    EntryHandler *tmp = (EntryHandler *) data;
    text = gtk_button_get_label(GTK_BUTTON(button));
    if( strcmp(text,"   A Far    ") == 0) {
        text = gtk_entry_get_text(GTK_ENTRY(tmp->entry1));
        float x = atof(text);
        float f = ((1.8f)*x) + 32;
        int len = snprintf(NULL, 0, "%f", f);
        char *result = (char *)malloc(len + 1);
        snprintf(result, len + 1, "%f", f);
        gtk_entry_set_text(GTK_ENTRY(tmp->entry2),result);
        gtk_entry_set_text(GTK_ENTRY(tmp->entry1),"");
    } else {
        text = gtk_entry_get_text(GTK_ENTRY(tmp->entry2));
        float x = atof(text);
        float c = (x-32) / 1.8f;
        int len = snprintf(NULL, 0, "%f", c);
        char *result = (char *)malloc(len + 1);
        snprintf(result, len + 1, "%f", c);
        gtk_entry_set_text(GTK_ENTRY(tmp->entry1),result);
        gtk_entry_set_text(GTK_ENTRY(tmp->entry2),"");
    }
}