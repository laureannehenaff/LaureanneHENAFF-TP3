#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned int MyAddress_w = 192;
unsigned int MyAddress_x = 168;
unsigned int MyAddress_y = 129;         //On initialise les variables pour l'addresse 192.168.129.10 / 24
unsigned int MyAddress_z = 10;
unsigned int IPv4MaskLength = 24;

unsigned int Adresse_machine = 0;

unsigned int masque = 0;

int main() {
	Adresse_machine = (MyAddress_w << 24) + (MyAddress_x << 16) + (MyAddress_y << 8) + MyAddress_z;
	printf("\n%d", MyAddress_w);
	printf(".%d", MyAddress_x);
	printf(".%d", MyAddress_y);
	printf(".%d", MyAddress_z);
	printf(" /%d\n", IPv4MaskLength);

	
	for (int i = 0; i < 24; i++) {
		masque = masque + pow(2, 31 - i);
	}

	unsigned int Adresse_reseau = 0;
	Adresse_reseau = Adresse_machine & masque;
	unsigned int tmp = Adresse_reseau;

	printf("\n%d", Adresse_reseau >> 24);
	Adresse_reseau = Adresse_reseau<<8;
	Adresse_reseau = Adresse_reseau >> 8;
	printf(".%d", (Adresse_reseau >> 16));
	Adresse_reseau = Adresse_reseau << 16;
	Adresse_reseau = Adresse_reseau >> 16;
	printf(".%d", (Adresse_reseau >> 8));
	Adresse_reseau = Adresse_reseau << 24;
	Adresse_reseau = Adresse_reseau >> 24;
	printf(".%d", (Adresse_reseau));
	printf(" /%d", IPv4MaskLength);

	printf("\n");
	unsigned int Adresse_broadcast;
	Adresse_reseau = tmp;
	Adresse_broadcast = Adresse_reseau | ~(masque);		//L’adresse de broadcast permet de s’adresser à l’ensemble des machines d’un même réseau local

	printf("\n%d", Adresse_broadcast >> 24);
	Adresse_broadcast = Adresse_broadcast << 8;
	Adresse_broadcast = Adresse_broadcast >> 8;
	printf(".%d", (Adresse_broadcast >> 16));
	Adresse_broadcast = Adresse_broadcast << 16;
	Adresse_broadcast = Adresse_broadcast >> 16;
	printf(".%d", (Adresse_broadcast >> 8));
	Adresse_broadcast = Adresse_broadcast << 24;
	Adresse_broadcast = Adresse_broadcast >> 24;
	printf(".%d", (Adresse_broadcast));
	printf(" /%d", IPv4MaskLength);

}