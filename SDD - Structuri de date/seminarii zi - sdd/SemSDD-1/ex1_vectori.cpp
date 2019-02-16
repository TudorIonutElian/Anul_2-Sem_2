# include <stdio.h>
# include <malloc.h>
# include <conio.h>

void traversare(int *c, float *q, float *p, int n)
{
	int i;

    printf("\nCod Cantitate Pret");
	printf("\n");
	for (i=0;i<n;i++) printf("%d",c[i]);
	printf("\n");
    for (i=0;i<n;i++) printf("%5.2f",q[i]);
	printf("\n");
	for (i=0;i<n;i++) printf("%5.2f",p[i]);
	printf("\n");

    float val=0,valori[100];

    for (i=0;i<n;i++) { 
		valori[i]= q[i] * p[i];
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
	int *c = (int*)malloc(n*sizeof(int));
	float *q = (float*)malloc(n*sizeof(float));
	float *p = (float*)malloc(n*sizeof(float));

	for (i=0;i<n;i++)
	{
		printf("c[%d]=",i+1);
		scanf("%d",&c[i]);
		printf("q[%d]=",i+1);
		scanf("%f",&q[i]);
		printf("p[%d]=",i+1);
		scanf("%f",&p[i]);
	}
	
    traversare(c,q,p,n);

	//dezalocare
	free(c);
	free(q);
	free(p);

	getch();
}