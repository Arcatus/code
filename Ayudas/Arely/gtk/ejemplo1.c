#include<gtk/gtk.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdio_ext.h>

//Estructura
typedef struct nodo
{
  /*
  int Edad;
  int Peso;
  float Hr_max;
  int Resultado;*/
  char z1[20], z2[20],z3[20], z4[20], z5[20];
  int Bandera;
  GtkWidget *entry1;
  GtkWidget *entry2, *l1, *l2, *l3, *l4, *l5;
  GtkWidget *rb1, *rb2;
}NODO;


//Prototipo de funciones
void StopTheApp(GtkWidget *window, gpointer data);
void Calcular(GtkWidget *button, gpointer data);
void CambiaOpcion1(GtkToggleButton *button, gpointer data);
int Redondear(float decimal);
void ButtonClicked(GtkButton *button, gpointer data);

gint main(gint argc, gchar *argv[])
{
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *label;
  GtkWidget *hbox, *vbox, *bigbox;  
  //GtkWidget *entrybox1, *entrybox2;
  //GtkWidget *rb1, *rb2;

  // char z1[20], z2[20],z3[20], z4[20], z5[20];

  NODO Datos;
  
  
  gtk_init(&argc, &argv);

  strcpy(Datos.z1, "");strcpy(Datos.z2, "");strcpy(Datos.z3, "");strcpy(Datos.z4, "");strcpy(Datos.z5, "");
  Datos.Bandera=1;
  //creo window
  window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(window), 280,280);
  gtk_container_border_width(GTK_CONTAINER(window),5);
  gtk_window_set_title(GTK_WINDOW(window), "Zonas cardiacas");
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_widget_set_size_request(window,350,300);
  
  //primer renglon
  bigbox=gtk_vbox_new(TRUE,0);
  hbox=gtk_hbox_new(TRUE,0);
  label=gtk_label_new("Edad");
  gtk_box_pack_start(GTK_BOX(hbox),label,FALSE,TRUE,0);
  Datos.entry1=gtk_entry_new();
  gtk_box_pack_start(GTK_BOX(hbox),Datos.entry1,FALSE,TRUE,0);
  gtk_box_pack_start(GTK_BOX(bigbox),hbox,TRUE,TRUE,0);

  //segundo renglon
  hbox=gtk_hbox_new(TRUE,0);
  label=gtk_label_new("Peso (libras):");
  gtk_box_pack_start(GTK_BOX(hbox),label,FALSE,TRUE,0);
  Datos.entry2=gtk_entry_new();
  gtk_box_pack_start(GTK_BOX(hbox),Datos.entry2,FALSE,TRUE,0);
  gtk_box_pack_start(GTK_BOX(bigbox),hbox,TRUE,TRUE,0);

  
  //fila de radiobuttons
  hbox=gtk_hbox_new(TRUE,0);
  vbox=gtk_vbox_new(TRUE,0);
  label=gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(hbox),label,FALSE,TRUE,0);
  //se crean radiobuttons,

  Datos.rb1 = gtk_radio_button_new_with_label (NULL, "Hombre");
  gtk_box_pack_start (GTK_BOX(vbox), Datos.rb1, FALSE, FALSE, 0);
  gtk_signal_connect (GTK_OBJECT(Datos.rb1), "toggled", GTK_SIGNAL_FUNC(CambiaOpcion1), "Hombre");


  Datos.rb2 = gtk_radio_button_new_with_label (gtk_radio_button_get_group(GTK_RADIO_BUTTON (Datos.rb1)), "Mujer");
  gtk_box_pack_start (GTK_BOX(vbox), Datos.rb2, FALSE, FALSE, 0);
  gtk_signal_connect (GTK_OBJECT(Datos.rb2), "toggled", GTK_SIGNAL_FUNC(CambiaOpcion1), "Mujer");

  
 
  gtk_box_pack_start(GTK_BOX(hbox),vbox,FALSE,TRUE,0);
  gtk_box_pack_start(GTK_BOX(bigbox),hbox,TRUE,TRUE,0);

  //fila del boton Calcula
  hbox=gtk_hbox_new(TRUE,0);
  button=gtk_button_new_with_label("Calcula");
  gtk_box_pack_start(GTK_BOX(hbox),button,FALSE,TRUE,0);
  gtk_signal_connect(GTK_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(Calcular), &Datos);
  gtk_widget_show(button);
  label=gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(hbox),label,FALSE,TRUE,0);
  
  //gtk_box_pack_start(GTK_BOX(hbox),entrybox2,FALSE,TRUE,0);
  gtk_box_pack_start(GTK_BOX(bigbox),hbox,TRUE,TRUE,0);

  //Zonas
  //vbox=gtk_vbox_new(TRUE,0);
  label=gtk_label_new("Zonas");
  gtk_box_pack_start(GTK_BOX(bigbox),label,FALSE,TRUE,0);

  //Zona 1
  hbox=gtk_hbox_new(TRUE,0);
  label=gtk_label_new("Zona 1");
  gtk_box_pack_start(GTK_BOX(hbox),label,FALSE,TRUE,0);
  label=gtk_label_new("50% - 60%");
  gtk_box_pack_start(GTK_BOX(hbox),label,FALSE,TRUE,0);
  Datos.l1=gtk_label_new(Datos.z1);
  //gtk_label_set_text (GTK_LABEL(label),(const gchar*)Datos.z1);
  gtk_box_pack_start(GTK_BOX(hbox),Datos.l1,FALSE,TRUE,0);
  gtk_box_pack_start(GTK_BOX(bigbox),hbox,TRUE,TRUE,0);  

  //Zona 2
  hbox=gtk_hbox_new(TRUE,0);
  label=gtk_label_new("Zona 2");
  gtk_box_pack_start(GTK_BOX(hbox),label,FALSE,TRUE,0);
  label=gtk_label_new("60% - 70%");
  gtk_box_pack_start(GTK_BOX(hbox),label,FALSE,TRUE,0);
  Datos.l2=gtk_label_new(Datos.z2);
  //gtk_label_set_text (GTK_LABEL(label),(const gchar*)Datos.z2);
  gtk_box_pack_start(GTK_BOX(hbox),Datos.l2,FALSE,TRUE,0);
  gtk_box_pack_start(GTK_BOX(bigbox),hbox,TRUE,TRUE,0);

  //Zona 3
  hbox=gtk_hbox_new(TRUE,0);
  label=gtk_label_new("Zona 3");
  gtk_box_pack_start(GTK_BOX(hbox),label,FALSE,TRUE,0);
  label=gtk_label_new("70% - 80%");
  gtk_box_pack_start(GTK_BOX(hbox),label,FALSE,TRUE,0);
  Datos.l3=gtk_label_new(Datos.z3);
  //gtk_label_set_text (GTK_LABEL(label),(const gchar*)Datos.z3);
  gtk_box_pack_start(GTK_BOX(hbox),Datos.l3,FALSE,TRUE,0);
  gtk_box_pack_start(GTK_BOX(bigbox),hbox,TRUE,TRUE,0);

  //Zona 4
  hbox=gtk_hbox_new(TRUE,0);
  label=gtk_label_new("Zona 4");
  gtk_box_pack_start(GTK_BOX(hbox),label,FALSE,TRUE,0);
  label=gtk_label_new("80% - 90%");
  gtk_box_pack_start(GTK_BOX(hbox),label,FALSE,TRUE,0);
  Datos.l4=gtk_label_new(Datos.z4);
  //gtk_label_set_text (GTK_LABEL(label),(const gchar*)Datos.z4);
  gtk_box_pack_start(GTK_BOX(hbox),Datos.l4,FALSE,TRUE,0);
  gtk_box_pack_start(GTK_BOX(bigbox),hbox,TRUE,TRUE,0);
  
  //Zona 5
  hbox=gtk_hbox_new(TRUE,0);
  label=gtk_label_new("Zona 5");
  gtk_box_pack_start(GTK_BOX(hbox),label,FALSE,TRUE,0);
  label=gtk_label_new("90% - 100%");
  gtk_box_pack_start(GTK_BOX(hbox),label,FALSE,TRUE,0);
  Datos.l5=gtk_label_new(Datos.z5);
  //gtk_label_set_text (GTK_LABEL(label),(const gchar*)Datos.z5);
  gtk_box_pack_start(GTK_BOX(hbox),Datos.l5,FALSE,TRUE,0);
  gtk_box_pack_start(GTK_BOX(bigbox),hbox,TRUE,TRUE,0);

  //gtk_box_pack_start(GTK_BOX(bigbox),vbox,TRUE,TRUE,0);

  //destroy window
  gtk_signal_connect(GTK_OBJECT(window), "destroy",GTK_SIGNAL_FUNC(StopTheApp), NULL);
  
  gtk_container_add(GTK_CONTAINER(window), bigbox);
  gtk_widget_show_all(window);

  gtk_main();

  
  return 0;
  
}



void Calcular(GtkWidget *button, gpointer data)
{ 
  NODO *Data=(NODO *)data;
  int edad, peso,k;//, z1,z2,z3,z4,z5;
  int n90,n80,n70,n60,n50,n100;
  float r90,r80,r70,r60,r50;
  float porcentaje, max;
  const gchar *e,*p;
  char ed[10], pe[10];

  e=gtk_entry_get_text(GTK_ENTRY(Data->entry1));
  p=gtk_entry_get_text(GTK_ENTRY(Data->entry2));
  strcpy(ed,e);
  strcpy(pe,p);
  sscanf(ed,"%d", &edad);
  sscanf(pe,"%d", &peso);
  
  
  if (gtk_toggle_button_get_active((GtkToggleButton *)GTK_TOGGLE_BUTTON(Data->rb1)))
    {
      k=4;
      porcentaje=0.05;
      
    }
  else//if (gtk_toggle_button_get_active((GtkToggleButton *)Data->rb2))
    {
      porcentaje=0.01;
      k=0;
    }
    
  max = 210-(edad/2)-(peso*porcentaje)+k;
  
  r50 = max*(.5);
  r60 = max*(.6);
  r70 = max*(.7);
  r80 = max*(.8);
  r90 = max*(.9);

  n50 = Redondear(r50);
  n60 = Redondear(r60);
  n70 = Redondear(r70);
  n80 = Redondear(r80);
  n90 = Redondear(r90);
  n100= Redondear(max);

  sprintf(Data->z1,"%d - %d ppm", n50,n60);
  sprintf(Data->z2,"%d - %d ppm", n60,n70);
  sprintf(Data->z3,"%d - %d ppm", n70,n80);
  sprintf(Data->z4,"%d - %d ppm", n80,n90);
  sprintf(Data->z5,"%d - %d ppm", n90,n100);

  
  gtk_label_set_text (GTK_LABEL(Data->l1),(const gchar*)Data->z1);
  gtk_label_set_text (GTK_LABEL(Data->l2),(const gchar*)Data->z2);
  gtk_label_set_text (GTK_LABEL(Data->l3),(const gchar*)Data->z3);
  gtk_label_set_text (GTK_LABEL(Data->l4),(const gchar*)Data->z4);
  gtk_label_set_text (GTK_LABEL(Data->l5),(const gchar*)Data->z5);
  
}

int Redondear(float decimal)
{
  int entero;
  float dec=decimal;
  float fdec;

  fdec=dec-(int)dec;
  if(fdec >=0.5)    
      entero=(int)dec +1;  
  else    
    entero=(int)dec;
  
  return entero;  
}

void ButtonClicked(GtkButton *button, gpointer data)
{
  NODO *Data=(NODO *)data;
    g_print("No me piques \n");
    gtk_entry_set_text(GTK_ENTRY(Data->entry1),"No se te ocurrio nada o que");
    
    

}

void CambiaOpcion1(GtkToggleButton *button, gpointer data)
{
  
  char *cad = (char *)data;
  if (gtk_toggle_button_get_active(button))//Entra cuando lo seleccionaste, no cuando se deja de seleccionar.
    {
      g_print ("boton seleccionado %s \n", cad);
      
    }
  
}

void StopTheApp(GtkWidget *window, gpointer data)
{
  gtk_main_quit();
}