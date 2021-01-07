#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctions.h"
#include "capteur.h"

int x,y,z,t=1;
int T1[2]={0,0};
int T2[2]={0,0};


void
on_button_ajtcap_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregcap;
    GtkWidget *Fenetreajcap;
    Fenetregcap=lookup_widget(objet,"gcap");
    gtk_widget_destroy(Fenetregcap);
    Fenetreajcap=create_ajcap();
    gtk_widget_show(Fenetreajcap);
}


void
on_button_mdfcap_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregcap;
    GtkWidget *Fenetremdfcap;
    Fenetregcap=lookup_widget(objet,"gcap");
    gtk_widget_destroy(Fenetregcap);
    Fenetremdfcap=create_mdfcap();
    gtk_widget_show(Fenetremdfcap);
}


void
on_button_suppcap_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregcap;
    GtkWidget *Fenetresuppcap;
    Fenetregcap=lookup_widget(objet,"gcap");
    gtk_widget_destroy(Fenetregcap);
    Fenetresuppcap=create_suppcap();
    gtk_widget_show(Fenetresuppcap);
}


void
on_button_retgcap_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button_rechcap_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregcap;
    GtkWidget *Fenetrerechcap;
    Fenetregcap=lookup_widget(objet,"gcap");
    gtk_widget_destroy(Fenetregcap);
    Fenetrerechcap=create_rechcap();
    gtk_widget_show(Fenetrerechcap);
}


void
on_treeview_lcap_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
        GtkTreeIter iter;
	gchar* idcapteur;
	gchar* zone_ajout;
	gchar* type;
	gchar* marque;
	gchar* etat_fct;
	gchar* jour_fct;
        gchar* mois_fct;
        gchar* annee_fct;

	capteur c;
        FILE *f=NULL;
        
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model, &iter ,path))
	{
		
		gtk_tree_model_get (GTK_LIST_STORE(model),&iter, 0, &idcapteur, 1, &zone_ajout, 2, &type , 3, &marque, 4, &etat_fct, 5, &jour_fct , 6, &mois_fct , 7, &annee_fct ,-1);
  		strcpy(c.idcapteur,idcapteur);
		strcpy(c.zone_ajout,zone_ajout);
		strcpy(c.type,type);
                strcpy(c.marque,marque);
		strcpy(c.etat_fonctionnement,etat_fct);
                c.date_mise_fct.jour=jour_fct;
                c.date_mise_fct.mois=mois_fct;
                c.date_mise_fct.annee=annee_fct;
                
                supprimertree(c);
                afficher(treeview);
                
}
}


void
on_button_affcap_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeviewlcap;
GtkWidget *Fenetregcap;

treeviewlcap=lookup_widget(objet,"treeview_lcap");
Fenetregcap=lookup_widget(objet,"gcap");

afficher(treeviewlcap);
}


void
on_button_msfctcap_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregcap;
    GtkWidget *Fenetrefctcap;
    Fenetregcap=lookup_widget(objet,"gcap");
    gtk_widget_destroy(Fenetregcap);
    Fenetrefctcap=create_fctcap();
    gtk_widget_show(Fenetrefctcap);
}


void
on_button_mscnfaj_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
  capteur n;
  GtkWidget *Fenetrescajcap;
  GtkWidget *Fenetreajcap;
  GtkWidget *input1, *input2;
  GtkWidget *jour,*mois,*annee;
  GtkWidget *zone;
  GtkWidget *output1, *output2;
  char text1[20]="temperature";
  char text2[20]="humidite";
  char id[20];
  int b=1,v;


Fenetrescajcap=lookup_widget(objet,"scajcap");
input1=lookup_widget(objet,"entry_msidaj");
input2=lookup_widget(objet,"entry_msmraj");
zone=lookup_widget(objet,"combobox_msempaj");
jour=lookup_widget(objet,"spinbutton_msjdiaj");
mois=lookup_widget(objet,"spinbutton_msmdiaj");
annee=lookup_widget(objet,"spinbutton_msadiaj");
output1=lookup_widget(objet,"label_msaltaj");
output2=lookup_widget(objet,"label_mssmraj");

strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(n.idcapteur,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(n.marque,gtk_entry_get_text(GTK_ENTRY(input2)));

if(strcmp(n.marque,"")==0)
{
gtk_widget_show (output2);
b=0;
}

strcpy(n.zone_ajout,gtk_combo_box_get_active_text(GTK_COMBO_BOX(zone)));
n.date_mise_fct.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
n.date_mise_fct.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
n.date_mise_fct.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
if(x==1)
{strcpy(n.type,text1);}
else
if(x==2)
{strcpy(n.type,text2);}

if(T1[0]==1)
{strcpy(n.etat_fonctionnement,"oui");}
else
if(T1[1]==1)
{strcpy(n.etat_fonctionnement,"non");}

v=verif(id);
if (v==1)
{
gtk_widget_show (output1);
}
else
{
  if(b==1)
{
ajouter(n);

    gtk_widget_destroy(Fenetreajcap);
    Fenetrescajcap=create_scajcap();
    gtk_widget_show(Fenetrescajcap);
}
}

}


void
on_button_msanlaj_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregcap;
    GtkWidget *Fenetreajcap;
    Fenetreajcap=lookup_widget(objet,"ajcap");
    gtk_widget_destroy(Fenetreajcap);
    Fenetregcap=create_gcap();
    gtk_widget_show(Fenetregcap);
}


void
on_radiobutton_mstajt_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
x=1;
}
}


void
on_radiobutton_mshaj_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
x=2;
}
}


void
on_checkbutton_msofctaj_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{
T1[0]=1;
}
}


void
on_checkbutton_msnfctaj_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{
T1[1]=1;
}
}


void
on_button_mscnfmdf_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
  capteur n;
    GtkWidget *Fenetrescmdfcap;
    GtkWidget *Fenetremdfcap;
  GtkWidget *input1, *input2;
  GtkWidget *jour,*mois,*annee;
  GtkWidget *zone;
  char text1[20]="temperature";
  char text2[20]="humidite";


Fenetremdfcap=lookup_widget(objet,"mdfcap");
input1=lookup_widget(objet,"combobox_msidmdf");
input2=lookup_widget(objet,"entry_msmrmdf");
zone=lookup_widget(objet,"combobox_msempmdf");
jour=lookup_widget(objet,"spinbutton_msjdimdf");
mois=lookup_widget(objet,"spinbutton_msmdimdf");
annee=lookup_widget(objet,"spinbutton_msadimdf");

strcpy(n.idcapteur,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
strcpy(n.marque,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(n.zone_ajout,gtk_combo_box_get_active_text(GTK_COMBO_BOX(zone)));
n.date_mise_fct.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
n.date_mise_fct.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
n.date_mise_fct.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
if(y==1)
{strcpy(n.type,text1);}
else
if(y==2)
{strcpy(n.type,text2);}

if(T2[0]==1)
{strcpy(n.etat_fonctionnement,"oui");}
else
if(T2[1]==1)
{strcpy(n.etat_fonctionnement,"non");}

modifier(n);

    gtk_widget_destroy(Fenetremdfcap);
    Fenetrescmdfcap=create_scmdfcap();
    gtk_widget_show(Fenetrescmdfcap);
}


void
on_button_msanlmdf_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregcap;
    GtkWidget *Fenetremdfcap;
    Fenetremdfcap=lookup_widget(objet,"mdfcap");
    gtk_widget_destroy(Fenetremdfcap);
    Fenetregcap=create_gcap();
    gtk_widget_show(Fenetregcap);
}


void
on_radiobutton_mshmdf_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
y=2;
}
}


void
on_radiobutton_mstmdf_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
y=1;
}
}


void
on_checkbutton_msnfctmdf_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{
T2[1]=1;
}
}


void
on_checkbutton_msofctmdf_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{
T2[0]=1;
}
}


void
on_button_msretrech_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregcap;
    GtkWidget *Fenetrerechcap;
    Fenetrerechcap=lookup_widget(objet,"rechcap");
    gtk_widget_destroy(Fenetrerechcap);
    Fenetregcap=create_gcap();
    gtk_widget_show(Fenetregcap);
}


void
on_button_mscnfrech_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Fenetrerechcap;
   GtkWidget *id,*crt;
   GtkWidget *treeviewrech;
   GtkWidget *output1,*output2;
   char filtre[20];
   char critere[30];
   int v;

Fenetrerechcap=lookup_widget(objet,"rechcap");
id=lookup_widget(objet,"entry_msidrech");
treeviewrech=lookup_widget(objet,"treeview_mstxtrech");
output1=lookup_widget(objet,"label_mstxtrech");
output2=lookup_widget(objet,"label_msidaltrech");
crt=lookup_widget(objet,"combobox_mscrrech");

strcpy(filtre,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(critere,gtk_combo_box_get_active_text(GTK_COMBO_BOX(crt)));

v=verifrech(filtre);
if(v!=1)
{
   gtk_widget_hide(output1);
    gtk_widget_show (output2);
}
else
{
   gtk_widget_hide(output2);
   gtk_widget_show (output1);
filtrecritere(treeviewrech, critere, filtre);
}
}


void
on_button_mscnfsp_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetrespcap;
    GtkWidget *Fenetresuppcap;
    GtkWidget *id;
    GtkWidget *output;
    char idsp[20];
    int v;

id=lookup_widget(objet,"entry_msidsp");
output=lookup_widget(objet,"label_msaltsp");
strcpy(idsp,gtk_entry_get_text(GTK_ENTRY(id)));

v=verif(idsp);

if(v!=1)
{
    gtk_widget_show (output);
}
else
{
 if(t==1)
{
supprimer(idsp);

    gtk_widget_destroy(Fenetresuppcap);
    Fenetrespcap=create_spcap();
    gtk_widget_show(Fenetrespcap);
}
}
}


void
on_button_msanlsp_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregcap;
    GtkWidget *Fenetresuppcap;
    Fenetresuppcap=lookup_widget(objet,"suppcap");
    gtk_widget_destroy(Fenetresuppcap);
    Fenetregcap=create_gcap();
    gtk_widget_show(Fenetregcap);
}


void
on_button_msretfct_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregcap;
    GtkWidget *Fenetrefctcap;
    Fenetrefctcap=lookup_widget(objet,"fctcap");
    gtk_widget_destroy(Fenetrefctcap);
    Fenetregcap=create_gcap();
    gtk_widget_show(Fenetregcap);
}


void
on_treeview_mscapfct_row_activated     (GtkTreeView     *treeview1,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
       GtkTreeIter iter;
	gchar* identifiant;
	gchar* jour;
	gchar* mois;
	gchar* annee;
	gchar* val;	

	fctcapteur n;
        FILE *f=NULL;
        
	GtkTreeModel *model = gtk_tree_view_get_model(treeview1);
	if (gtk_tree_model_get_iter(model, &iter ,path))
	{
		
		gtk_tree_model_get (GTK_LIST_STORE(model),&iter, 0, &identifiant, 1, &jour, 2, &mois , 3, &annee, 4, &val ,-1);
  		strcpy(n.identifiant,identifiant);
		strcpy(n.val,val);
                n.date_fct.jour=jour;
                n.date_fct.mois=mois;
                n.date_fct.annee=annee;
                affichercapt(treeview1);
                affichercaph(treeview1);
}  
}


void
on_button_mscnffct_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
    fctcapteur n;
    GtkWidget *Fenetrefctcap;
    GtkWidget *id,*jour,*mois,*annee,*val;
    GtkWidget *output1,*output2,*output3,*output4,*output5;
    int b=1;
    int t,h,j,m,a;

Fenetrefctcap=lookup_widget(objet,"fctcap");
id=lookup_widget(objet,"combobox_idfct");
val=lookup_widget(objet,"spinbutton_msvalfct");
jour=lookup_widget(objet,"spinbutton_msjdfct");
mois=lookup_widget(objet,"spinbutton_msmdfct");
annee=lookup_widget(objet,"spinbutton_msadfct");
output1=lookup_widget(objet,"label_msajfct");
output2=lookup_widget(objet,"label_msmdffct");
output3=lookup_widget(objet,"label_msspfct");
output4=lookup_widget(objet,"label_mssvalfct");
output5=lookup_widget(objet,"label_msvrdt");

strcpy(n.identifiant,gtk_combo_box_get_active_text(GTK_COMBO_BOX(id)));
sprintf(n.val,"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(val)));
if(strcmp(n.val,"")==0)
{
gtk_widget_show (output4);
b=0;
}
n.date_fct.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
n.date_fct.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
n.date_fct.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
if(z==1)
{
if (b==1)
{
t=verifdatet(j,m,a);
  if(t==1)
 {
 gtk_widget_show (output5);
 }
else
 {
temperature(n);
gtk_widget_show (output1);
gtk_widget_hide (output4);
 }
}
}
else
if(z==2)
{
if (b==1)
{
h=verifdatet(j,m,a);
  if(t==1)
 {
 gtk_widget_show (output5);
 }
else
 {
humidite(n);
gtk_widget_show (output1);
gtk_widget_hide (output4);
 }
}
}
gtk_widget_hide (output2);
gtk_widget_hide (output3);
}


void
on_button_msmdffct_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
    fctcapteur n;
    GtkWidget *Fenetrefctcap;
    GtkWidget *id,*jour,*mois,*annee,*val;
    GtkWidget *output1,*output2,*output3,*output4;
    int b=1;


Fenetrefctcap=lookup_widget(objet,"fctcap");
id=lookup_widget(objet,"combobox_idfct");
val=lookup_widget(objet,"spinbutton_msvalfct");
jour=lookup_widget(objet,"spinbutton_msjdfct");
mois=lookup_widget(objet,"spinbutton_msmdfct");
annee=lookup_widget(objet,"spinbutton_msadfct");
output1=lookup_widget(objet,"label_msajfct");
output2=lookup_widget(objet,"label_msmdffct");
output3=lookup_widget(objet,"label_msspfct");
output4=lookup_widget(objet,"label_mssvalfct");

strcpy(n.identifiant,gtk_combo_box_get_active_text(GTK_COMBO_BOX(id)));
sprintf(n.val,"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(val)));
if(strcmp(n.val,"")==0)
{
gtk_widget_show (output4);
b=0;
}
n.date_fct.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
n.date_fct.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
n.date_fct.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
if(z==1)
{
if (b==1)
{
modifiertmp(n);
gtk_widget_show (output2);
gtk_widget_hide (output4);
}
}
else if(z==2)
{
if (b==1)
{
modifierhmd(n);
gtk_widget_show (output2);
gtk_widget_hide (output4);
}
}
gtk_widget_hide (output1);
gtk_widget_hide (output3);
}


void
on_button_msspfcap_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetrefctcap;
   GtkWidget *id;
GtkWidget *output1,*output2,*output3;
   char idsp[20];
    Fenetrefctcap=lookup_widget(objet,"fctcap");
id=lookup_widget(objet,"combobox_idfct");
output1=lookup_widget(objet,"label_msajfct");
output2=lookup_widget(objet,"label_msmdffct");
output3=lookup_widget(objet,"label_msspfct");
strcpy(idsp,gtk_combo_box_get_active_text(GTK_COMBO_BOX(id)));
if(z==1)
{
supprimertmp(idsp);
gtk_widget_show (output3);
}
else
if(z==2)
{
supprimerhmd(idsp);
gtk_widget_show (output3);
}
gtk_widget_hide (output1);
gtk_widget_hide (output2);
}


void
on_button_msafffct_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
    fctcapteur n;
    GtkWidget *Fenetrefctcap;
    GtkWidget *id,*mois,*annee;
    GtkWidget *treeviewfct;
    char idcap[20];
    char moisaff[20];
    char anneeaff[20];

Fenetrefctcap=lookup_widget(objet,"fctcap");
id=lookup_widget(objet,"combobox_idfct");
treeviewfct=lookup_widget(objet,"treeview_mscapfct");
mois=lookup_widget(objet,"spinbutton_msmafffct");
annee=lookup_widget(objet,"spinbutton_msaafffct");

strcpy(idcap,gtk_combo_box_get_active_text(GTK_COMBO_BOX(id)));
sprintf(moisaff,"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois)));
sprintf(anneeaff,"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee)));

if(z==1)
{rechcapt(treeviewfct, idcap, moisaff, anneeaff);}
else
if(z==2)
{rechcaph(treeviewfct, idcap, moisaff , anneeaff);}

}


void
on_radiobutton_mstfct_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
z=1;
}
}


void
on_radiobutton_mshfct_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
z=2;
}
}


void
on_button_mschidmdf_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
  capteur c;
  FILE *f;
  GtkWidget *Fenetremdfcap;
  GtkWidget *id;
  GtkWidget *output1,*output2;
  char text1[20]="temperature";
  char text2[20]="humidite";


Fenetremdfcap=lookup_widget(objet,"mdfcap");
id=lookup_widget(objet,"combobox_msidmdf");
output1=lookup_widget(objet,"label_mschmdf");
output2=lookup_widget(objet,"label_msanlchmdf");

if(y==1)
{
f=fopen("liste_des_capteurs.txt","r");
       while(fscanf(f,"%s %s %s %s %s %d %d %d\n",c.idcapteur,c.zone_ajout,c.type,c.marque,c.etat_fonctionnement,&c.date_mise_fct.jour,&c.date_mise_fct.mois,&c.date_mise_fct.annee)!=EOF)
       {
if(strcmp(c.type,text1)==0)
{
gtk_combo_box_append_text (GTK_COMBO_BOX(id),_(c.idcapteur));
       }
}
fclose(f);
}

if(y==2)
{
f=fopen("liste_des_capteurs.txt","r");
       while(fscanf(f,"%s %s %s %s %s %d %d %d\n",c.idcapteur,c.zone_ajout,c.type,c.marque,c.etat_fonctionnement,&c.date_mise_fct.jour,&c.date_mise_fct.mois,&c.date_mise_fct.annee)!=EOF)
       {
if(strcmp(c.type,text2)==0)
{
gtk_combo_box_append_text (GTK_COMBO_BOX(id),_(c.idcapteur));
       }
}
fclose(f);
}

gtk_widget_hide(output2);
gtk_widget_show (output1);


}


void
on_button_mscnfidmdf_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
  capteur c;
  FILE *f;
  GtkWidget *Fenetremdfcap;
  GtkWidget *id;
  GtkWidget *input1;
  GtkWidget *output1,*output2;
    char id1[20];
    char marque1[20];

Fenetremdfcap=lookup_widget(objet,"mdfcap");
id=lookup_widget(objet,"combobox_msidmdf");
input1=lookup_widget(objet,"entry_msmrmdf");
output1=lookup_widget(objet,"label_mschmdf");
output2=lookup_widget(objet,"label_msanlchmdf");

strcpy(id1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(id)));

f=fopen("liste_des_capteurs.txt","r");
       while(fscanf(f,"%s %s %s %s %s %d %d %d\n",c.idcapteur,c.zone_ajout,c.type,c.marque,c.etat_fonctionnement,&c.date_mise_fct.jour,&c.date_mise_fct.mois,&c.date_mise_fct.annee)!=EOF)
       {
if(strcmp(c.idcapteur,id1)==0)
{ 
strcpy(marque1,c.marque);
}
       }
fclose(f);

gtk_entry_set_text(input1,marque1);

gtk_widget_hide(output2);
gtk_widget_hide(output1);

}


void
on_button_msanlidmdf_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *Fenetremdfcap;
  GtkWidget *output1,*output2;

Fenetremdfcap=lookup_widget(objet,"mdfcap");
output1=lookup_widget(objet,"label_mschmdf");
output2=lookup_widget(objet,"label_msanlchmdf");

gtk_widget_hide(output1);
gtk_widget_show (output2);


}


void
on_radiobutton_msnsp_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Fenetresuppcap;
   GtkWidget *output1;
   GtkWidget *id;

Fenetresuppcap=lookup_widget(objet,"suppcap");
id=lookup_widget(objet,"entry_msidsp");
output1=lookup_widget(objet,"label_msmsgsp");
t=0;

if(strcmp(id,"")!=0)
{
    gtk_widget_hide (output1);
}

}


void
on_radiobutton_msosp_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Fenetresuppcap;
   GtkWidget *output1;
   GtkWidget *id;

Fenetresuppcap=lookup_widget(objet,"suppcap");
output1=lookup_widget(objet,"label_msmsgsp");
t=1;

    gtk_widget_show (output1);

}


void
on_button_mschidfct_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
    capteur c;
    FILE *f;
    GtkWidget *Fenetrefctcap;
    GtkWidget *id;
  char text1[20]="temperature";
  char text2[20]="humidite";

Fenetrefctcap=lookup_widget(objet,"fctcap");
id=lookup_widget(objet,"combobox_idfct");

if(z==1)
{
f=fopen("liste_des_capteurs.txt","r");
       while(fscanf(f,"%s %s %s %s %s %d %d %d\n",c.idcapteur,c.zone_ajout,c.type,c.marque,c.etat_fonctionnement,&c.date_mise_fct.jour,&c.date_mise_fct.mois,&c.date_mise_fct.annee)!=EOF)
       {
if(strcmp(c.type,text1)==0)
{
gtk_combo_box_append_text (GTK_COMBO_BOX(id),_(c.idcapteur));
}
       }
fclose(f);
}

if(z==2)
{
f=fopen("liste_des_capteurs.txt","r");
       while(fscanf(f,"%s %s %s %s %s %d %d %d\n",c.idcapteur,c.zone_ajout,c.type,c.marque,c.etat_fonctionnement,&c.date_mise_fct.jour,&c.date_mise_fct.mois,&c.date_mise_fct.annee)!=EOF)
       {
if(strcmp(c.type,text2)==0)
{
gtk_combo_box_append_text (GTK_COMBO_BOX(id),_(c.idcapteur));
}
       }
fclose(f);
}

}


void
on_treeview_mstxtrech_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
        GtkTreeIter iter;
	gchar* identifiant;
	gchar* zone;
	gchar* type;
	gchar* marque;
	gchar* etat_fct;
	gchar* jour_fct;
        gchar* mois_fct;
        gchar* annee_fct;

	capteur n;
        FILE *f=NULL;
        
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model, &iter ,path))
	{
		
		gtk_tree_model_get (GTK_LIST_STORE(model),&iter, 0, &identifiant, 1, &zone, 2, &type , 3, &marque, 4, &etat_fct, 5, &jour_fct , 6, &mois_fct , 7, &annee_fct , -1);
  		strcpy(n.idcapteur,identifiant);
		strcpy(n.zone_ajout,zone);
		strcpy(n.type,type);
                strcpy(n.marque,marque);
		strcpy(n.etat_fonctionnement,etat_fct);
                n.date_mise_fct.jour=jour_fct;
                n.date_mise_fct.mois=mois_fct;
                n.date_mise_fct.annee=annee_fct;
                
                
                afficher(treeview);
                
}
}


void
on_button_ok_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregcap;
    GtkWidget *Fenetrescajcap;
    GtkWidget *treeviewlcap;
    Fenetrescajcap=lookup_widget(objet,"scajcap");
    gtk_widget_destroy(Fenetrescajcap);
    Fenetregcap=create_gcap();
    gtk_widget_show(Fenetregcap);
    treeviewlcap=lookup_widget(Fenetregcap,"treeview_lcap");

afficher(treeviewlcap);
}


void
on_button_okmdfcap_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregcap;
    GtkWidget *Fenetrescmdfcap;
    GtkWidget *treeviewlcap;
    Fenetrescmdfcap=lookup_widget(objet,"scmdfcap");
    gtk_widget_destroy(Fenetrescmdfcap);
    Fenetregcap=create_gcap();
    gtk_widget_show(Fenetregcap);
    treeviewlcap=lookup_widget(Fenetregcap,"treeview_lcap");

afficher(treeviewlcap);
}


void
on_button_okspcap_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregcap;
    GtkWidget *Fenetrespcap;
    GtkWidget *treeviewlcap;
    Fenetrespcap=lookup_widget(objet,"spcap");
    gtk_widget_destroy(Fenetrespcap);
    Fenetregcap=create_gcap();
    gtk_widget_show(Fenetregcap);
    treeviewlcap=lookup_widget(Fenetregcap,"treeview_lcap");



afficher(treeviewlcap);
}

