#include <iostream>

//typedef, daca vrei sa definesti global
struct Apartament {
	float suprafata;
	int nr_camere;
	char* proprietar; //avem un sir de caractere nu unul simplu
};


//facem un vector
struct Hotel {
	int nr_apartamente;
	Apartament* apartamente;
};

//citesc apartament de la tastatura o facem functie separata ca sa putem sa o apelam de cate ori avem nevoie

//tip returnat Apartament
//intre paranteze parametrii
//void - nici un parametre
Apartament citesteApartament() {
	//creez apartament
	Apartament a;
	printf("Suprafata: ");
	scanf("%f", &a.suprafata);//de ce &? sa pot sa modific valoarea(se salveaza), scaf se salveaza modificarea la adresa nu in stiva. Stiva se sterge dupa.
	//scanf primeste un pointer
	printf("Numar camere: ");
	scanf("%f", &a.nr_camere);

	//buffer //sir de caractere alocat static
	char  buffer[20];

	printf("Proprietarul: ");
	scanf("%s", buffer);

	//v[i]; //v+sizeof(tip)*1;
	//c++
	//a.proprietar = new char[strlen(buffer) + 1];
	//(char*) - cast la char
	//c
	a.proprietar = (char*)malloc(sizeof(char)*(strlen(buffer)+1));
		strcpy(a.proprietar, buffer);
	return a;
}

void afisareApartament(Apartament a) {
	printf("Apartamentul lui %s are o suprafata de %5.2f si %d camere\t\t", a.proprietar, a.suprafata, a.nr_camere);
}

void citesteHotel(Hotel *h) {
	//pt ca avem mai multe atribute folosim container care contine toate atributele, ca sa nu le delar din nou pe toate
	printf("Numarul de apartamente: ");
	//hotel pointer, deferentiez 
	//citesc numarul de apartamente
	scanf("%d", &h->nr_apartamente);

	//aloc memorie hotel de apartamente
	h->apartamente = (Apartament*)malloc(sizeof(Apartament)*h->nr_apartamente);

	//for ca sa citim

	for (int i = 0; i < h->nr_apartamente; i++) {
		h->apartamente[i] = citesteApartament();
	}
	//nu trebuie sa returnez nimic pentru ca e void
}


void afisareHotel(Hotel hotel) {
	printf("Hotelul are %d apartamente\n", hotel.nr_apartamente);
	for (int i = 0; i < hotel.nr_apartamente; i++) {
		afisareApartament(hotel.apartamente[i]);
	}
}

//=
Apartament copiazaApartament(Apartament apartament) {
	//creem un nou apartament
	Apartament a;
	a.suprafata = apartament.suprafata;
	a.nr_camere = apartament.nr_camere;
	a.proprietar = (char*)malloc(sizeof(char)*(strlen(apartament.proprietar) + 1));
	//copiem cu functia string copu strcpy
	strcpy(a.proprietar, apartament.proprietar);
	return a;
}
//functia de afisare a matricei
void afisareBloc(Apartament**m, int nrLinii, int* nrColoane) {
	for (int i = 0; i < nrLinii; i++) {
		for (int j = 0; j < nrColoane[i]; j++) {
			afisareApartament(m[i][j]);
		}
		printf("\n");
	}
}

void citesteBloc(Apartament ** *m, int *nrLinii, int* *nrColoane) {
	//citim numarul de linii ca sa nu hardcodam
	printf("Nr linii");
	scanf("%d", &nrLinii);
	//aloc spatiu pentru matricwe
	(*m) = (Apartament**)malloc(sizeof(Apartament*)*(*nrLinii));
	//aloc spatiu pentru coloane?#
	(*nrColoane) = (int*)malloc(sizeof(int)*(*nrLinii));

	for (int i = 0; i < (*nrLinii); i++) {
		printf("Numarul de apartamente de la etajul %d", (i + 1));
		scanf("%d", &(*nrColoane)[i]);//---------------------------
		(*m)[i] = (Apartament*)malloc(sizeof(Apartament)*(*nrColoane)[i]);
		//acum citesc numarul de apartamente, pt ca i-am alocat spatiu mai devreme
		for (int j = 0; j < (*nrColoane)[i]; j++) {
			(*m)[i][j] = citesteApartament();
			//cum verific daca am citit toate apartamentele, facem o functie
		}
	}
}

void main() {
	/*  --comentez pentru ca incep sa lucrez matricile, si nu  mai am nevoie de bucata asta
	//declar apartament in main

	Apartament apartament;
	apartament = citesteApartament();
	//facem functie ca sa vedem daca am citit corect apartament = citesceApartament();

	//apelam afisareApartament 
	afisareApartament(apartament);

	Hotel hotel;
	//declar o functie citesteHotel

	//hotel.apartamente[0] = apartament; //shallow copy, copiez doar adresa, este gresit

	
	citesteHotel(&hotel);
	if (hotel.apartamente[0].proprietar) {
		free(hotel.apartamente[0].proprietar);
	}

	hotel.apartamente[0] = copiazaApartament(apartament);
	afisareHotel(hotel);
	for (int i = 0; i < hotel.nr_apartamente; i++) {
		free(hotel.apartamente[i].proprietar);
	}

	free(hotel.apartamente);
	free(apartament.proprietar); //dezalocam 

	*/
	int nrLinii = 3; //nrEtaje - linii din matrice, e harcodat
	//int nrColoane[3] = {3, 1, 2}; //nrApartamente pe etaj
	int nrColoane;
	Apartament ** bloc; //pointre la pointre
	
						
	/* --comentat pt void citeste Bloc
	bloc = (Apartament**)malloc(sizeof(Apartament*)*nrLinii);
	// (Apartament) - cast explicit
	//aloc spatiu pentrui fiecare pointer cu un for

	for (int i = 0; i < nrLinii; i++) {
		bloc[i] = (Apartament*)malloc(sizeof(Apartament)*nrColoane[i]);
		//acum citesc numarul de apartamente, pt ca i-am alocat spatiu mai devreme
		for (int j = 0; j < nrColoane[i]; j++) {
			bloc[i][j] = citesteApartament();
			//cum verific daca am citit toate apartamentele, facem o functie
		}
	}
	*/

	citesteBloc(&bloc, &nrLinii, &nrColoane);
	afisareBloc(bloc, nrLinii, nrColoane);

	//acum dezalocam invers fata de alocare

	for (int i = 0; i < nrLinii; i++) {
		for (int j = 0; j < nrColoane[i]; j++) {
			free(bloc[i][j].proprietar);
		}
		free(bloc[i]);
	}
	free(bloc);

}