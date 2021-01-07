#include <gtk/gtk.h>
typedef struct
{
   int jour;
   int mois;
   int annee;
}dates;

typedef struct
{
    char identifiant[20];
    char val[20];
    dates date_fct;

    
}fctcapteur;


void temperature(fctcapteur n);
void humidite(fctcapteur n);
void modifierhmd(fctcapteur n);
void modifiertmp(fctcapteur n);
void affichercapt(GtkWidget *liste);
void affichercaph(GtkWidget *liste);
void rechcapt(GtkWidget *liste, char id[], char moisaff[], char anneeaff[]);
void rechcaph(GtkWidget *liste, char id[], char moisaff[], char anneeaff[]);
void supprimertmp(char idsp[]);
void supprimerhmd(char idsp[]);
int verifdatet(int j, int m, int a);
int verifdateh(int j, int m, int a);

