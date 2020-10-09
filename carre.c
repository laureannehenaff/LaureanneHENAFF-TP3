# define carre(x) (x) * (x)
# include <stdio.h>
# include <stdlib.h>

int Nb = 5;
int carre = 0;
int carre2 = 0;

int main() {
    carre = carre(Nb);
    printf("le carré vaut %d",carre);
    carre2 = carre(Nb+1);  //Sans les parenthèses le *  se trouve après le Nb
    printf("\nle carré de %d vaut %d",Nb+1,carre2);
}
