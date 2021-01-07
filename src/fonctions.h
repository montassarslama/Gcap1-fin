#include <gtk/gtk.h>
typedef struct
{
   int jour;
   int mois;
   int annee;
}date;

typedef struct
{
    char idcapteur[20];
    char zone_ajout[20];
    char type[20];
    char marque[20];
    date date_mise_fct;
    char etat_fonctionnement[20];
}capteur;


void ajouter(capteur c);
void afficher(GtkWidget *liste);
void supprimer(char idsp[]);
void modifier(capteur c);
void chercher(GtkWidget *liste, char id[]);
int verif(char id[]);
void filtrecritere(GtkWidget *liste, char critere[], char filtre[]);
void supprimertree(capteur c1);
int verifrech(char crt[]);


