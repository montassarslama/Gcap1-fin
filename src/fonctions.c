#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#include <gtk/gtk.h>

enum
{
    EIDCAPTEUR,
    EZONE_AJOUT,
    ETYPE,
    EMARQUE,
    EETAT_FCT,
    EJOUR_FCT,
    EMOIS_FCT,
    EANNEE_FCT,
    COLUMNS,
};

    
void ajouter(capteur c)
{

 FILE *f;
 f=fopen("liste_des_capteurs.txt","a+");
 if(f!=NULL)
 {
 fprintf(f,"%s %s %s %s %s %d %d %d\n",c.idcapteur,c.zone_ajout,c.type,c.marque,c.etat_fonctionnement,c.date_mise_fct.jour,c.date_mise_fct.mois,c.date_mise_fct.annee);

 fclose(f);
 }

}

void afficher(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char idcapteur[20];
char zone_ajout[20];
char type[20];
char marque[20];
char etat_fct[20];
char jour_fct[20];
char mois_fct[20];
char annee_fct[20];


store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);

if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("idcapteur",renderer,"text",EIDCAPTEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("zone_ajout",renderer,"text",EZONE_AJOUT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("marque",renderer,"text",EMARQUE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	
	
renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("etat_fct",renderer,"text",EETAT_FCT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	
		
renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("jour_fct",renderer,"text",EJOUR_FCT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("mois_fct",renderer,"text",EMOIS_FCT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("annee_fct",renderer,"text",EANNEE_FCT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	


	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("liste_des_capteurs.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("liste_des_capteurs.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s \n",idcapteur,zone_ajout,type,marque,etat_fct,jour_fct,mois_fct,annee_fct)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EIDCAPTEUR,idcapteur,EZONE_AJOUT,zone_ajout,ETYPE,type,EMARQUE,marque,EETAT_FCT,etat_fct,EJOUR_FCT,jour_fct,EMOIS_FCT,mois_fct,EANNEE_FCT,annee_fct,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}


void chercher(GtkWidget *liste, char id[])
{
    
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char idcapteur[20];
char zone_ajout[20];
char type[20];
char marque[20];
char etat_fct[20];
char jour_fct[20];
char mois_fct[20];
char annee_fct[20];


store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);

if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("idcapteur",renderer,"text",EIDCAPTEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("zone_ajout",renderer,"text",EZONE_AJOUT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("marque",renderer,"text",EMARQUE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	
	
renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("etat_fct",renderer,"text",EETAT_FCT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("jour_fct",renderer,"text",EJOUR_FCT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("mois_fct",renderer,"text",EMOIS_FCT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("annee_fct",renderer,"text",EANNEE_FCT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	


	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("liste_des_capteurs.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("liste_des_capteurs.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s \n",idcapteur,zone_ajout,type,marque,etat_fct,jour_fct,mois_fct,annee_fct)!=EOF)
		{
            if(strcmp(idcapteur,id)==0)
{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EIDCAPTEUR,idcapteur,EZONE_AJOUT,zone_ajout,ETYPE,type,EMARQUE,marque,EETAT_FCT,etat_fct,EJOUR_FCT,jour_fct,EMOIS_FCT,mois_fct,EANNEE_FCT,annee_fct,-1);
}
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}

void modifier(capteur c)
{
    char idcapteur1[20];	
    char zone_ajout1[20];
    char type1[20];
    char marque1[20];
    char etat_fonctionnement1[20];
    int jdf;
    int mdf;
    int adf;
	

FILE *f;
FILE *f1;

f=fopen("liste_des_capteurs.txt","r");
f1=fopen("modif.txt","a+");
while (fscanf(f,"%s %s %s %s %s %d %d %d \n",idcapteur1,zone_ajout1,type1,marque1,etat_fonctionnement1,&jdf,&mdf,&adf)!=EOF)
{
if (strcmp(c.idcapteur,idcapteur1)==0)
	fprintf(f1,"%s %s %s %s %s %d %d %d\n",c.idcapteur,c.zone_ajout,c.type,c.marque,c.etat_fonctionnement,c.date_mise_fct.jour,c.date_mise_fct.mois,c.date_mise_fct.annee);

else
	fprintf(f1,"%s %s %s %s %s %d %d %d\n",idcapteur1,zone_ajout1,type1,marque1,etat_fonctionnement1,jdf,mdf,adf);

}
fclose(f);
fclose(f1);
remove("liste_des_capteurs.txt");
rename("modif.txt","liste_des_capteurs.txt");
}

void supprimer(char idsp[])
{
FILE *f;
FILE *f1;
capteur c;
f=fopen("liste_des_capteurs.txt","r");
f1=fopen("doc.txt","a+");
while (fscanf(f,"%s %s %s %s %s %d %d %d \n",c.idcapteur,c.zone_ajout,c.type,c.marque,c.etat_fonctionnement,&c.date_mise_fct.jour,&c.date_mise_fct.mois,&c.date_mise_fct.annee)!=EOF)
{
	if (strcmp(c.idcapteur,idsp)!=0)	
	fprintf(f1,"%s %s %s %s %s %d %d %d\n",c.idcapteur,c.zone_ajout,c.type,c.marque,c.etat_fonctionnement,c.date_mise_fct.jour,c.date_mise_fct.mois,c.date_mise_fct.annee);

}
fclose(f);
fclose(f1);
remove("liste_des_capteurs.txt");
rename("doc.txt","liste_des_capteurs.txt");
}


int verif(char id[])
{
    
    FILE *f=NULL;
    capteur c;
    int test;
    f=fopen("liste_des_capteurs.txt","r");
    test=0;
    if(f!=NULL)
    {
       while(fscanf(f,"%s %s %s %s %s %d %d %d\n",c.idcapteur,c.zone_ajout,c.type,c.marque,c.etat_fonctionnement,&c.date_mise_fct.jour,&c.date_mise_fct.mois,&c.date_mise_fct.annee)!=EOF)
       {
         if(strcmp(c.idcapteur,id)==0)
        {
          test=1;
          break;
        }

       }
     fclose(f);
     }
return(test);
}

void supprimertree(capteur c1)
{
FILE *f;
FILE *f1;
capteur c;
f=fopen("liste_des_capteurs.txt","r");
f1=fopen("doc.txt","a+");
while (fscanf(f,"%s %s %s %s %s %d %d %d \n",c.idcapteur,c.zone_ajout,c.type,c.marque,c.etat_fonctionnement,&c.date_mise_fct.jour,&c.date_mise_fct.mois,&c.date_mise_fct.annee)!=EOF)
{
	if (strcmp(c.idcapteur,c1.idcapteur)!=0 || strcmp(c.zone_ajout,c1.zone_ajout)!=0 ||
strcmp(c.type,c1.type)!=0 ||
strcmp(c.marque,c1.marque)!=0 || strcmp(c.etat_fonctionnement,c1.etat_fonctionnement)!=0)	
	fprintf(f1,"%s %s %s %s %s %d %d %d\n",c.idcapteur,c.zone_ajout,c.type,c.marque,c.etat_fonctionnement,c.date_mise_fct.jour,c.date_mise_fct.mois,c.date_mise_fct.annee);

}
fclose(f);
fclose(f1);
remove("liste_des_capteurs.txt");
rename("doc.txt","liste_des_capteurs.txt");
}


int verifrech(char crt[])
{
    
    FILE *f=NULL;
char idcapteur[20];
char zone_ajout[20];
char type[20];
char marque[20];
char etat_fct[20];
char jour_fct[20];
char mois_fct[20];
char annee_fct[20];
    int test;
    f=fopen("liste_des_capteurs.txt","r");
    test=0;
    if(f!=NULL)
    {
 		while(fscanf(f,"%s %s %s %s %s %s %s %s \n",idcapteur,zone_ajout,type,marque,etat_fct,jour_fct,mois_fct,annee_fct)!=EOF)
       {
         if(strcmp(idcapteur,crt)==0)
        {
          test=1;
          break;
        }
        if(strcmp(type,crt)==0)
        {
          test=1;
          break;
        }
        if(strcmp(zone_ajout,crt)==0)
        {
          test=1;
          break;
        }
        if(strcmp(marque,crt)==0)
        {
          test=1;
          break;
        }
       if(strcmp(etat_fct,crt)==0)
        {
          test=1;
          break;
        }
       if(strcmp(annee_fct,crt)==0)
        {
          test=1;
          break;
        }
       }
     fclose(f);
     }
return(test);
}


void filtrecritere(GtkWidget *liste, char critere[], char filtre[])
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char idcapteur[20];
char zone_ajout[20];
char type[20];
char marque[20];
char etat_fct[20];
char jour_fct[20];
char mois_fct[20];
char annee_fct[20];


store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);

if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("idcapteur",renderer,"text",EIDCAPTEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("zone_ajout",renderer,"text",EZONE_AJOUT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("marque",renderer,"text",EMARQUE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	
	
renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("etat_fct",renderer,"text",EETAT_FCT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	
		
renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("jour_fct",renderer,"text",EJOUR_FCT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("mois_fct",renderer,"text",EMOIS_FCT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("annee_fct",renderer,"text",EANNEE_FCT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	


	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("liste_des_capteurs.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("liste_des_capteurs.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s \n",idcapteur,zone_ajout,type,marque,etat_fct,jour_fct,mois_fct,annee_fct)!=EOF)
		{
            if(strcmp(critere,"identifiant")==0)
{
         if(strcmp(filtre,idcapteur)==0)
      {
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EIDCAPTEUR,idcapteur,EZONE_AJOUT,zone_ajout,ETYPE,type,EMARQUE,marque,EETAT_FCT,etat_fct,EJOUR_FCT,jour_fct,EMOIS_FCT,mois_fct,EANNEE_FCT,annee_fct,-1);
}
}
            if(strcmp(critere,"type")==0)
{
         if(strcmp(filtre,type)==0)
      {
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EIDCAPTEUR,idcapteur,EZONE_AJOUT,zone_ajout,ETYPE,type,EMARQUE,marque,EETAT_FCT,etat_fct,EJOUR_FCT,jour_fct,EMOIS_FCT,mois_fct,EANNEE_FCT,annee_fct,-1);
}
}
            if(strcmp(critere,"marque")==0)
{
         if(strcmp(filtre,marque)==0)
      {
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EIDCAPTEUR,idcapteur,EZONE_AJOUT,zone_ajout,ETYPE,type,EMARQUE,marque,EETAT_FCT,etat_fct,EJOUR_FCT,jour_fct,EMOIS_FCT,mois_fct,EANNEE_FCT,annee_fct,-1);
}
}
            if(strcmp(critere,"zone_ajout")==0)
{
         if(strcmp(filtre,zone_ajout)==0)
      {
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EIDCAPTEUR,idcapteur,EZONE_AJOUT,zone_ajout,ETYPE,type,EMARQUE,marque,EETAT_FCT,etat_fct,EJOUR_FCT,jour_fct,EMOIS_FCT,mois_fct,EANNEE_FCT,annee_fct,-1);
}
}
            if(strcmp(critere,"etat_fonctionnement")==0)
{
         if(strcmp(filtre,etat_fct)==0)
      {
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EIDCAPTEUR,idcapteur,EZONE_AJOUT,zone_ajout,ETYPE,type,EMARQUE,marque,EETAT_FCT,etat_fct,EJOUR_FCT,jour_fct,EMOIS_FCT,mois_fct,EANNEE_FCT,annee_fct,-1);
}
}
            if(strcmp(critere,"annee_installation")==0)
{
         if(strcmp(filtre,annee_fct)==0)
      {
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EIDCAPTEUR,idcapteur,EZONE_AJOUT,zone_ajout,ETYPE,type,EMARQUE,marque,EETAT_FCT,etat_fct,EJOUR_FCT,jour_fct,EMOIS_FCT,mois_fct,EANNEE_FCT,annee_fct,-1);
}
}
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}

