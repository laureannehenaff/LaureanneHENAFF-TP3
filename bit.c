#include <stdio.h>
#include <stdlib.h>

unsigned int nb =2868838400;


int main() {
    printf("On utilise %lu octets pour représenter le nombre",sizeof(nb));
    printf("\nOn utilise %lu bits pour représenter le nombre",sizeof(nb)*8);
    
    int n = sizeof(nb)*8;

    for (int i = 0; i<=n ; i++) {
        if ((nb & 1) == 1) {
            printf("\nbit %d : ON",i);
        }
        else {
            printf("\nbit %d : OFF",i);
        }
        nb = nb>>1;
    }
    printf("\n Bye !");
}