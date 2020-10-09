#include <stdio.h>
#include <stdlib.h>

int sortie = 0;
int nombre;
float note;
char saisie = ' ';
int compteurabsences = 0;
int totalnotes = 0;
int notemin;
int notemax;

int notes[29];

int main() {
    for (int i = 0 ; i<=29 ; i++) {  //programme tourne pour 30 notes
        printf("Entrer la note  no %d :",i);
        scanf("%f",&note);
        if (note<0 || note>20) {
            printf("\nÉlève absent ? Ou voulez-vous arrêter la saisie des notes ? A/O/N");
            scanf("%s",&saisie);
            if (saisie == 'A') { 
                printf("\nL'élève no %d est absent",i);     //Absence pas de note
                compteurabsences = compteurabsences + 1;
            }
            if (saisie == 'O') {                   //Sortie du programme
                break; 
            }
            if (saisie == 'N') {                //On retape la note (erreur de saisie)
                printf("\nRetapez la note %d",i);
                scanf("%2f",&note);
                totalnotes = totalnotes + note;
            }
        }
        totalnotes = totalnotes + note;
        if (i == 0) {
            notemin = note;             //On initialise notemin et notemax avec la première note rentrée
            notemax = note;
        }
        if (i>0 && notemin>note) {     //On change notemin pour obtenir la plus petite note
            notemin=note;
        }
        if (i>0 && notemax<note) {      //On change notemax pour obtenir la plus grande note
            notemax=note;
        }
    }
    printf("\n Il y a %d notes valides",30-compteurabsences);
    printf("\n Il y %d absences",compteurabsences);
    printf("\n La moyenne des notes valides est %d",totalnotes/(30-compteurabsences));
    printf("\n La plus petite note est %d et la plus grande est %d \n",notemin,notemax);
}