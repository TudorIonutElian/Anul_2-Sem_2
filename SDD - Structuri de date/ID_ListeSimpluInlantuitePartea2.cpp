//#include<iostream>
//
//struct ContBancar {
//	char*titular;
//	int nrTranzactii;
//	float sold;
//};
//
//ContBancar citesteCont() {
//	ContBancar cb;
//	char buffer[20];
//	printf("Titular:");
//	scanf("%s", buffer);
//	cb.titular = (char*)malloc(sizeof(char)*(strlen(buffer) + 1));
//	strcpy(cb.titular, buffer);
//
//	printf("Numar tranzactii:");
//	scanf("%d", &cb.nrTranzactii);
//	printf("Sold:");
//	scanf("%f", &cb.sold);
//
//	return cb;
//}
//
//void afisareContBancar(ContBancar cb) {
//	printf("%s are in cont %5.2f lei, in urma a %d tranzactii\n",
//		cb.titular, cb.sold, cb.nrTranzactii);
//}
//
//struct nod {
//	ContBancar info;
//	nod* next;
//};
//
//ContBancar copiazaCont(ContBancar cb) {
//	ContBancar c;
//	c.titular = (char*)malloc(sizeof(char)*(strlen(cb.titular) + 1));
//	strcpy(c.titular, cb.titular);
//	c.nrTranzactii = cb.nrTranzactii;
//	c.sold = cb.sold;
//	return c;
//}
//
//nod* inserareInceput(nod* cap, ContBancar cb) {
//	nod* nou = (nod*)malloc(sizeof(nod));
//	nou->info = copiazaCont(cb);
//	nou->next = cap;
//	return nou;
//}
//
//nod* inserareSfarsit(nod* cap, ContBancar cb) {
//	nod* nou = (nod*)malloc(sizeof(nod));
//	nou->info = copiazaCont(cb);
//	nou->next = NULL;
//	if (cap) {
//		nod*p = cap;
//		while (p->next)
//			p = p->next;
//		p->next = nou;
//	}
//	else
//	{
//		cap = nou;
//	}
//	return cap;
//}
//
//nod*inserareSF2(nod*cap, ContBancar cb) {
//	if (cap) {
//		nod*p = cap;
//		while (p->next)
//			p = p->next;
//		p->next = inserareInceput(NULL, cb);
//	}
//	else {
//		cap = inserareInceput(cap, cb);
//	}
//	return cap;
//}
//
//void afisareLista(nod* cap) {
//	nod*p = cap;
//	while (p) {
//		afisareContBancar(p->info);
//		p = p->next;
//	}
//}
//
//void stergereLista(nod* cap) {
//	while (cap) {
//		free(cap->info.titular);
//		nod*temp = cap;
//		cap = cap->next;
//		free(temp);
//	}
//}
//
//void main() {
//
//	nod* lista = NULL;
//
//	lista = inserareInceput(lista, citesteCont());
//	lista = inserareInceput(lista, citesteCont());
//	lista = inserareInceput(lista, citesteCont());
//	lista = inserareSfarsit(lista, citesteCont());
//	lista = inserareSfarsit(lista, citesteCont());
//
//	afisareLista(lista);
//
//	stergereLista(lista);
//	lista = NULL;
//
//}