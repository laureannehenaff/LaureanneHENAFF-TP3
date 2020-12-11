#include <stdio.h>
#include <stdlib.h>
#define NBMAXNOTES 2 //On généralise l'effectif
#include <math.h>
#define carre(x) (x) * (x)

int sortie = 0;
int nombre;
float note;
char saisie = ' ';
int compteurabsences = 0;
int totalnotes = 0;
int notemin;
int notemax;

int notes[29];
int j;

float ecart_type;
float coefficient;
float somme;

int main() {
    for (int l = 0; l<=NBMAXNOTES-1; l++) {
        notes[l]=-2;                    //On initialise le tableau avec -2
        printf("\n %i",notes[l]);
    }
    for (int i = 1 ; i<=NBMAXNOTES ; i++) {  //programme tourne pour 30 notes
        printf("\n Entrer la note  n°%d :",i);
        scanf("%f",&note);
        j=i-1;
        notes[j]=note;
        if (note<0 || note>20) {
            printf("\nÉlève absent ? Ou voulez-vous arrêter la saisie des notes ? A/O/N");
            scanf("%s",&saisie);
            if (saisie == 'A') { 
                printf("\nL'élève no %d est absent",i);     //Absence pas de note
                compteurabsences = compteurabsences + 1;
                notes[j]=-1;
            }
            if (saisie == 'O') {                   //Sortie du programme
                break; 
            }
            if (saisie == 'N') {                //On retape la note (erreur de saisie)
                printf("\nRetapez la note %d",i);
                scanf("%2f",&note);
                totalnotes = totalnotes + note;
                notes[j]=note;
            }
        }
        totalnotes = totalnotes + note;
        if (i == 1) {
            notemin = note;             //On initialise notemin et notemax avec la première note rentrée
            notemax = note;
        }
        if (i>1 && notemin>note) {     //On change notemin pour obtenir la plus petite note
            notemin = note;
        }
        if (i>1 && notemax<note) {      //On change notemax pour obtenir la plus grande note
            notemax = note;
        }
    }
    printf("\n Il y a %d notes valides",NBMAXNOTES-compteurabsences);
    printf("\n Il y %d absences",compteurabsences);
    printf("\n La moyenne des notes valides est %d",totalnotes/(NBMAXNOTES-compteurabsences));
    printf("\n La plus petite note est %d et la plus grande est %d",notemin,notemax);
    
    coefficient=1/(NBMAXNOTES-compteurabsences-1);
    for (int m = 0; m<=NBMAXNOTES-1; m++) {                     //on décompose le calcul de l'écart-type
        somme= somme + carre((notes[m]-totalnotes/(NBMAXNOTES-compteurabsences)));
    }
    ecart_type=sqrt(coefficient*somme);   //somme=somme des (note - moyenne)^2
    printf("\n L'écart-type est de %2f",ecart_type);

    for (int k = 0; k<=NBMAXNOTES-1; k++) {     //On lit le tableau de notes
        printf("\n %d \n",notes[k]);
    }
}