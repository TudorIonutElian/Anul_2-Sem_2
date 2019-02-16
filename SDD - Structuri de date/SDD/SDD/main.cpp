#include<iostream>

struct Apartament {
	float suprafata;
	int nr_camere;
	char* propietar;
};


//vector de apartamente:
struct Hotel {
	int nr_apartamente;
	Apartament *apartamente; //pointer la apartament
};

Apartament citesteApartament() {
	Apartament a;
	printf("Suprafata: ");
	scanf("%f", &a.suprafata); //& (adresa) il adaugam pentru a face modificarea pt a se duce la adresa, %f ca returnam float
	printf("Numar camere: ");
	scanf("%d", &a.nr_camere);

	//alocam spatiu pt proprietar, pt ca este pointer - ne folosim de un buffer
	char buffer[20]; //bufferul este deja o adresa
	printf("Proprietarul: ");
	scanf("%s", buffer);
	//alocam memorie:
	//a.propietar = new char[strlen(buffer) + 1];
	a.propietar = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
	strcpy(a.propietar, buffer);

	return a;
}

void afisareApartament(Apartament a) {
	printf("Apartamentul lui %s are o suprafata de %5.2f si %d camere\t\t", a.propietar, a.suprafata, a.nr_camere);
}

void citesteHotel(Hotel *h) {
	printf("Numarul de apartamente: ");
	scanf("%d", &h->nr_apartamente);
	h->apartamente = (Apartament*)malloc(sizeof(Apartament)*h->nr_apartamente);
	for (int i = 0; i < h->nr_apartamente; i++) {
		h->apartamente[i] = citesteApartament();
	}
}

void afisareHotel(Hotel hotel) {
	printf("Hotelul are %d apartamente\n,", hotel.nr_apartamente);
	for (int i = 0; i < hotel.nr_apartamente; i++) {
		afisareApartament(hotel.apartamente[i]);
	}
}


//operator =
Apartament copiazaApartament(Apartament apartament) {
	Apartament a;
	a.suprafata = apartament.suprafata;
	a.nr_camere = apartament.nr_camere;
	a.propietar = (char*)malloc(sizeof(char)*(strlen(apartament.propietar) + 1));
	strcpy(a.propietar, apartament.propietar);
	return a;
}


//functie de afisare a matricei - for in alt for
void afisareBloc(Apartament **m, int nrLinii, int*nrColoane) {//m=matrice
	for (int i = 0; i < nrLinii; i++) {
		for (int j = 0; j < nrColoane[i]; j++) {
			afisareApartament(m[i][j]);
		}

		printf("\n");
	}
}

void citesteBloc(Apartament** *m, int *nrLinii, int* *nrColoane) {
	printf("Numar linii: ");
	scanf("%d", nrLinii);

	(*m) = (Apartament**)malloc(sizeof(Apartament*)*(*nrLinii)); //aloc spatiu de nr linii pt elem de tip apartament
	(*nrColoane) = (int*)malloc(sizeof(int)*(*nrLinii));
	//parcurgerea liniilor: - prin FOR
	for (int i = 0; i < (*nrLinii); i++) {
		printf("Numarul de apartamente de la etajul %d", (i + 1));
		scanf("%d", &(*nrColoane)[i]);
		(*m)[i] = (Apartament*)malloc(sizeof(Apartament)*(*nrColoane)[i]);
		//parcurgerea coloanelor: prin FOR
		for (int j = 0; j < (*nrColoane)[i]; j++) {
			(*m)[i][j] = citesteApartament();
		}
	}

}


Apartament* filtrareApartamente(Apartament**m, int nrLinii, int *nrColoane, int pragNrCamere, int*dim) {
	//parcurgem matricea si comparam numarul de camere cu pragul
	//creem un vector de apartamente pe care sa il returnal=m la starsit
	Apartament* rezultat;

	//luam un countre de la 0, aprcurgem toata matricea, daca a gasit incrementam counterul cu 1

	int  contor = 0;
	for (int i = 0; i < nrLinii; i++) {
		for (int j = 0; j < nrColoane[i]; j++) {
			if (m[i][j].nr_camere <= pragNrCamere) {
				contor++;
			}
		}
	}
	rezultat = (Apartament*)malloc(sizeof(Apartament)*contor);
	for (int i = 0; i < nrLinii; i++) 
	{
		for (int j = 0; j < nrColoane[i]; j++)
		{
			if (m[i][j].nr_camere <= pragNrCamere)
			{
				rezultat[contor++] = copiazaApartament(m[i][j]);
			}
		}
	}
	*dim = contor;
	return rezultat;
	//acum apelez functia in main
}

void main() {
	//Apartament apartament;
	//apartament = citesteApartament();
	//afisareApartament(apartament);

	//Hotel hotel;
	//citesteHotel(&hotel);

	////verificam daca e ceva, eliberam memoria
	//if (hotel.apartamente[0].propietar) {
	//	free(hotel.apartamente[0].propietar);
	//}
	//hotel.apartamente[0] = copiazaApartament(apartament);

	//
	//afisareHotel(hotel);

	//for (int i = 0;i < hotel.nr_apartamente;i++) {
	//	free(hotel.apartamente[i].propietar);
	//}

	//free(apartament.propietar);
	//free(hotel.apartamente);


	//Matrice:
	int nrLinii = 3; //liniile din matrice
	int *nrColoane;

	Apartament **bloc; //vector la pointer de vectori

	citesteBloc(&bloc, &nrLinii, &nrColoane);

	afisareBloc(bloc, nrLinii, nrColoane);

	Apartament *vector;
	int dimensiune;
	vector = filtrareApartamente(bloc, nrLinii, nrColoane, 3, &dimensiune);

	//&dimensiune transmis prin adresa, restul sunt transmise prin valoare

	printf("Vector: \n");
	for (int i = 0; i < dimensiune; i++) {
		afisareApartament(vector[i]);
		printf("\n");
	}
	for (int i = 0; i < dimensiune; i++) {
		free(vector[i].propietar);
	}
	free (vector);

	for (int i = 0; i < nrLinii; i++) {
		for (int j = 0; j < nrColoane[i]; j++) {
			free(bloc[i][j].propietar);
		}
		free(bloc[i]);
	}

	free(bloc);

}