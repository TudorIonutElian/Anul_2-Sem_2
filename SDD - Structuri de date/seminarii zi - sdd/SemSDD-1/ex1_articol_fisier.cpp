# include <stdio.h>
# include <malloc.h>
# include <conio.h>
# include <string.h>

struct produs
{	
	int cod;
	char *denumire;
	float cantitate;
	float pret;
};

void traversare(produs *p, int n)
{
	int i;

    printf("\nCod Denumire Cantitate Pret");
	printf("\n");
	for (i=0;i<n;i++) printf("\n %d %s %5.2f %5.2f",p[i].cod,p[i].denumire,p[i].cantitate,p[i].pret);
	printf("\n");
    
    float val=0,valori[100];

    for (i=0;i<n;i++) { 
		valori[i]= p[i].cantitate * p[i].pret;
	    val+=valori[i];
	}

	printf("\nValoare");
	printf("\n");
	for (i=0;i<n;i++) printf("%5.2f ",valori[i]);
	printf("\nValoare totala=%5.2f",val);
}

void main()
{
	int i,n;
	char buffer[20];
	produs *p;

	FILE* f=fopen("fisier.txt","r");
	if (f)
	{
		fscanf(f,"%d",&n);
		//alocare
		p = (produs*)malloc(n*sizeof(produs));
		for (i=0;i<n;i++)
		{
			fscanf(f,"%d",&p[i].cod);	
			fscanf(f,"%s",buffer);
			//alocare
			p[i].denumire = (char*)malloc((strlen(buffer)+1)*sizeof(char));
			strcpy(p[i].denumire,buffer);
			fscanf(f,"%f",&p[i].cantitate);
			fscanf(f,"%f",&p[i].pret);
		}
	}
	else printf("\n Fisierul nu exista!");
	fclose(f);
	
    traversare(p,n);

	//dezalocare
	for (i=0;i<n;i++) free(p[i].denumire);
	free(p);

	getch();
}