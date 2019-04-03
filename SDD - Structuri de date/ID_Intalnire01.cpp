#include<iostream>

struct Apartament {
	float suprafata;
	int nr_camere;
	char* proprietar;
};

struct Hotel {
	int nr_apartamente;
	Apartament *apartamente;
};

Apartament citesteApartament() {
	Apartament a;
	printf("Suprafata:");
	scanf("%f", &a.suprafata);
	printf("numar camere:");
	scanf("%d", &a.nr_camere);

	char buffer[20];

	printf("Proprietarul;:");
	scanf("%s", buffer);
	//a.proprietar = new char[strlen(buffer) + 1];
	a.proprietar = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
	strcpy(a.proprietar, buffer);

	return a;
}

void afisareApartament(Apartament a) {
	printf("Apartametnul lui %s are o suprafata de %5.2f si %d camere\t\t",
		a.proprietar, a.suprafata, a.nr_camere);
}

void citesteHotel(Hotel *h) {
	printf("Numarul de apratamente:");
	scanf("%d", &h->nr_apartamente);
	h->apartamente = (Apartament*)malloc(sizeof(Apartament)*h->nr_apartamente);
	for (int i = 0;i < h->nr_apartamente;i++) {
		h->apartamente[i] = citesteApartament();
	}
}

void afisareHotel(Hotel hotel) {
	printf("Hotelul are %d apartamente\n", hotel.nr_apartamente);
	for (int i = 0;i < hotel.nr_apartamente;i++) {
		afisareApartament(hotel.apartamente[i]);
	}
}

Apartament copiazaApartament(Apartament apartament) {
	Apartament a;
	a.suprafata = apartament.suprafata;
	a.nr_camere = apartament.nr_camere;
	a.proprietar = (char*)malloc(sizeof(char)*(strlen(apartament.proprietar) + 1));
	strcpy(a.proprietar, apartament.proprietar);
	return a;
}

void afisareBloc(Apartament**m, int nrLinii, int*nrColoane) {
	for (int i = 0;i < nrLinii;i++) {
		for (int j = 0;j < nrColoane[i];j++) {
			afisareApartament(m[i][j]);
		}
		printf("\n\n");
	}
}

void citesteBloc(Apartament** *m, int *nrLinii, int* *nrColoane) {
	printf("Numar linii");
	scanf("%d", nrLinii);

	(*m) = (Apartament**)malloc(sizeof(Apartament*)*(*nrLinii));
	(*nrColoane) = (int*)malloc(sizeof(int)*(*nrLinii));
	for (int i = 0;i < (*nrLinii);i++) {
		printf("Numarul de apartamente de la etajul %d", (i + 1));
		scanf("%d", &(*nrColoane)[i]);
		(*m)[i] = (Apartament*)malloc(sizeof(Apartament)*(*nrColoane)[i]);
		for (int j = 0;j < (*nrColoane)[i];j++) {
			(*m)[i][j] = citesteApartament();
		}
	}
}

Apartament* filtareApartamente(Apartament**m, int nrLinii, 
	int*nrColoane, int pragNrCamere, int*dim) {
	Apartament* rezultat;
	int contor = 0;
	for (int i = 0;i < nrLinii;i++) {
		for (int j = 0;j < nrColoane[i];j++) {
			if (m[i][j].nr_camere <= pragNrCamere) {
				contor++;
			}
		}
	}

	rezultat = (Apartament*)malloc(sizeof(Apartament)*contor);
	contor = 0;
	for (int i = 0;i < nrLinii;i++) {
		for (int j = 0;j < nrColoane[i];j++) {
			if (m[i][j].nr_camere <= pragNrCamere) {
				rezultat[contor++] = copiazaApartament(m[i][j]);
			}
		}
	}

	*dim = contor;
	return rezultat;
}

void main() {
	//Apartament apartament;
	//apartament = citesteApartament();
	//afisareApartament(apartament);

	//Hotel hotel;
	//citesteHotel(&hotel);
	//if (hotel.apartamente[0].proprietar) {
	//	free(hotel.apartamente[0].proprietar);
	//}
	//hotel.apartamente[0] = copiazaApartament(apartament);

	//afisareHotel(hotel);
	//for (int i = 0;i < hotel.nr_apartamente;i++) {
	//	free(hotel.apartamente[i].proprietar);
	//}
	//free(hotel.apartamente);
	//free(apartament.proprietar);

	int nrLinii = 3;
	int *nrColoane;
	Apartament **bloc;

	citesteBloc(&bloc, &nrLinii, &nrColoane);

	
	afisareBloc(bloc, nrLinii, nrColoane);

	Apartament*vector;
	int dimensiune=0;
	vector = filtareApartamente(bloc, nrLinii, nrColoane, 3, &dimensiune);

	printf("Vector:\n");
	for (int i = 0;i < dimensiune;i++) {
		afisareApartament(vector[i]);
		printf("\n");
	}

	for (int i = 0;i < dimensiune;i++) {
		free(vector[i].proprietar);
	}
	free(vector);

	for (int i = 0;i < nrLinii;i++) {
		for (int j = 0;j < nrColoane[i];j++) {
			free(bloc[i][j].proprietar);
		}
		free(bloc[i]);
	}
	free(bloc);

	

}