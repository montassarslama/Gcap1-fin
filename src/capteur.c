#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "capteur.h"
#include <gtk/gtk.h>

enum
{
    EIDENTIFIANT,
    EJ,
    EM,
    EA,
    EVAL,
    
    COLUMNS,
};

void temperature(fctcapteur n)
{
 FILE *f;
 f=fopen("temperature.txt","a+");
 if(f!=NULL)
 {
   fprintf(f,"%s %d %d %d %s \n",n.identifiant,n.date_fct.jour,n.date_fct.mois,n.date_fct.annee,n.val);
fclose(f);
}
}

void humidite(fctcapteur n)
{
 FILE *f;
 f=fopen("humidite.txt","a+");
 if(f!=NULL)
 {
   fprintf(f,"%s %d %d %d %s \n",n.identifiant,n.date_fct.jour,n.date_fct.mois,n.date_fct.annee,n.val);
fclose(f);
}
}

void modifiertmp(fctcapteur n)
{
char id1[20];
char val1[20];
    int jda;
    int mda;
    int ada;
    	

FILE *f;
FILE *f1;

f=fopen("temperature.txt","r");
f1=fopen("modif.txt","a+");
while (fscanf(f,"%s %d %d %d %s \n",id1,&jda,&mda,&ada,val1)!=EOF)
{
if ((strcmp(n.identifiant,id1)==0)&&(n.date_fct.jour==jda)&&(n.date_fct.mois==mda)&&(n.date_fct.annee==ada))
	fprintf(f1,"%s %d %d %d %s\n",n.identifiant,n.date_fct.jour,n.date_fct.mois,n.date_fct.annee,n.val);

else
	fprintf(f1,"%s %d %d %d %s\n",id1,jda,mda,ada,val1);

}
fclose(f);
fclose(f1);
remove("temperature.txt");
rename("modif.txt","temperature.txt");
}

void modifierhmd(fctcapteur n)
{
char id1[20];
char val1[20];
    int jda;
    int mda;
    int ada;
    	

FILE *f;
FILE *f1;

f=fopen("humidite.txt","r");
f1=fopen("modif.txt","a+");
while (fscanf(f,"%s %d %d %d %s \n",id1,&jda,&mda,&ada,val1)!=EOF)
{
if ((strcmp(n.identifiant,id1)==0)&&(n.date_fct.jour==jda)&&(n.date_fct.mois==mda)&&(n.date_fct.annee==ada))
	fprintf(f1,"%s %d %d %d %s\n",n.identifiant,n.date_fct.jour,n.date_fct.mois,n.date_fct.annee,n.val);

else
	fprintf(f1,"%s %d %d %d %s\n",id1,jda,mda,ada,val1);

}
fclose(f);
fclose(f1);
remove("humidite.txt");
rename("modif.txt","humidite.txt");
}

void supprimertmp(char idsp[])
{
FILE *f;
FILE *f1;
fctcapteur n;
f=fopen("temperature.txt","r");
f1=fopen("doc.txt","a+");
while (fscanf(f,"%s %d %d %d %s \n",n.identifiant,&n.date_fct.jour,&n.date_fct.mois,&n.date_fct.annee,n.val)!=EOF)
{
	if (strcmp(n.identifiant,idsp)!=0)	
	fprintf(f1,"%s %d %d %d %s\n",n.identifiant,n.date_fct.jour,n.date_fct.mois,n.date_fct.annee,n.val);

}
fclose(f);
fclose(f1);
remove("temperature.txt");
rename("doc.txt","temperature.txt");
}

void supprimerhmd(char idsp[])
{
FILE *f;
FILE *f1;
fctcapteur n;
f=fopen("humidite.txt","r");
f1=fopen("doc.txt","a+");
while (fscanf(f,"%s %d %d %d %s \n",n.identifiant,&n.date_fct.jour,&n.date_fct.mois,&n.date_fct.annee,&n.val)!=EOF)
{
	if (strcmp(n.identifiant,idsp)!=0)	
	fprintf(f1,"%s %d %d %d %s\n",n.identifiant,n.date_fct.jour,n.date_fct.mois,n.date_fct.annee,n.val);

}
fclose(f);
fclose(f1);
remove("humidite.txt");
rename("doc.txt","humidite.txt");
}

void affichercapt(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char identifiant[20];
char jour[20];
char mois[20];
char annee[20];
char val[20];

store =NULL;

FILE *f1;

store=gtk_tree_view_get_model(liste);

if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",EIDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EA,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("val",renderer,"text",EVAL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f1=fopen("temperature.txt","r");

	if(f1==NULL)
	{
		return;
	}
	else 
	{ 
	f1=fopen("temperature.txt","a+");
		while(fscanf(f1,"%s %s %s %s %s \n",identifiant,jour,mois,annee,val)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EIDENTIFIANT,identifiant,EJ,jour,EM,mois,EA,annee,EVAL,val,-1);

		}
	   fclose(f1);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	   }
 
}

}

void rechcapt(GtkWidget *liste, char id[], char moisaff[], char anneeaff[])
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char identifiant[20];
char jour[20];
char mois[20];
char annee[20];
char val[20];

store =NULL;

FILE *f1;

store=gtk_tree_view_get_model(liste);

if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",EIDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EA,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("val",renderer,"text",EVAL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f1=fopen("temperature.txt","r");

	if(f1==NULL)
	{
		return;
	}
	else
	
	{ 
	f1=fopen("temperature.txt","a+");
		while(fscanf(f1,"%s %s %s %s %s \n",identifiant,jour,mois,annee,val)!=EOF)
		{
if(strcmp(identifiant,id)==0&&strcmp(mois,moisaff)==0&&strcmp(annee,anneeaff)==0)
{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EIDENTIFIANT,identifiant,EJ,jour,EM,mois,EA,annee,EVAL,val,-1);
}
		}
	   fclose(f1);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	   }
}

}

void affichercaph(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char identifiant[20];
char jour[20];
char mois[20];
char annee[20];
char val[20];

store =NULL;

FILE *f1;

store=gtk_tree_view_get_model(liste);

if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",EIDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EA,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("val",renderer,"text",EVAL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f1=fopen("humidite.txt","r");

	if(f1==NULL)
	{
		return;
	}
	else 
	{ 
	f1=fopen("humidite.txt","a+");
		while(fscanf(f1,"%s %s %s %s %s \n",identifiant,jour,mois,annee,val)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EIDENTIFIANT,identifiant,EJ,jour,EM,mois,EA,annee,EVAL,val,-1);

		}
	   fclose(f1);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	   }
 
}

}


void rechcaph(GtkWidget *liste, char id[], char moisaff[], char anneeaff[])
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char identifiant[20];
char jour[20];
char mois[20];
char annee[20];
char val[20];

store =NULL;

FILE *f1;

store=gtk_tree_view_get_model(liste);

if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",EIDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EA,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("val",renderer,"text",EVAL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f1=fopen("humidite.txt","r");

	if(f1==NULL)
	{
		return;
	}
	else
	
	{ 
	f1=fopen("humidite.txt","a+");
		while(fscanf(f1,"%s %s %s %s %s \n",identifiant,jour,mois,annee,val)!=EOF)
		{
            if(strcmp(identifiant,id)==0&&strcmp(mois,moisaff)==0&&strcmp(annee,anneeaff)==0)
{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EIDENTIFIANT,identifiant,EJ,jour,EM,mois,EA,annee,EVAL,val,-1);
}
		}
	   fclose(f1);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	   }
}

}

int verifdatet(int j, int m, int a)
{
    
    FILE *f=NULL;
fctcapteur n;
    int test;
    f=fopen("temperature.txt","r");
    test=0;
    if(f!=NULL)
    {
       while (fscanf(f,"%s %d %d %d %s \n",n.identifiant,&n.date_fct.jour,&n.date_fct.mois,&n.date_fct.annee,n.val)!=EOF)
       {
         if((n.date_fct.jour==j)&&(n.date_fct.mois==m)&&(n.date_fct.annee==a))
        {
          test=1;
          break;
        }

       }
     fclose(f);
     }
return(test);
}


int verifdateh(int j, int m, int a)
{
    
    FILE *f=NULL;
fctcapteur n;
    int test;
    f=fopen("humidite.txt","r");
    test=0;
    if(f!=NULL)
    {
       while (fscanf(f,"%s %d %d %d %s \n",n.identifiant,&n.date_fct.jour,&n.date_fct.mois,&n.date_fct.annee,n.val)!=EOF)
       {
         if((n.date_fct.jour==j)&&(n.date_fct.mois==m)&&(n.date_fct.annee==a))
        {
          test=1;
          break;
        }

       }
     fclose(f);
     }
return(test);
}


