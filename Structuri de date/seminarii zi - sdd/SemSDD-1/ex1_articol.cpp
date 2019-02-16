# include <stdio.h>
# include <malloc.h>
# include <conio.h>

struct produs
{	
	int cod;
	float cantitate;
	float pret;
};

void traversare(produs *p, int n)
{
	int i;

    printf("\nCod Cantitate Pret");
	printf("\n");
	for (i=0;i<n;i++) printf("\n %d %5.2f %5.2f",p[i].cod,p[i].cantitate,p[i].pret);
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

	printf("Numar produse=");
	scanf("%d",&n);
	//alocare
	produs *p = (produs*)malloc(n*sizeof(produs));

	for (i=0;i<n;i++)
	{
		printf("c[%d]=",i+1);
		scanf("%d",&p[i].cod);
		printf("q[%d]=",i+1);
		scanf("%f",&p[i].cantitate);
		printf("p[%d]=",i+1);
		scanf("%f",&p[i].pret);
	}
	
    traversare(p,n);
	//dezalocare
	free(p);

	getch();
}