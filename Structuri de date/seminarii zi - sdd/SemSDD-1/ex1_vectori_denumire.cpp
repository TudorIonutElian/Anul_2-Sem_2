# include <stdio.h>
# include <malloc.h>
# include <conio.h>
# include <string.h>

void traversare(float *c, char *d[20], float *q, float *p, int n)
{
	int i;

    printf("\nCod Denumire Cantitate Pret");
	printf("\n");
	for (i=0;i<n;i++) printf("%5.2f",c[i]);
	printf("\n");
	for (i=0;i<n;i++) printf("%s ",d[i]);
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
	char buffer[20];

	printf("Numar produse=");
	scanf("%d",&n);

	//alocare
	float *c = (float*)malloc(n*sizeof(float));
	char *d[20];
	float *q = (float*)malloc(n*sizeof(float));
	float *p = (float*)malloc(n*sizeof(float));

	for (i=0;i<n;i++)
	{
		printf("c[%d]=",i+1);
		scanf("%f",&c[i]);
		printf("d[%d]=",i+1);
		scanf("%s",buffer);
		//alocare
		d[i] = (char*)malloc((strlen(buffer)+1)*sizeof(char));
		strcpy(d[i],buffer);
		printf("q[%d]=",i+1);
		scanf("%f",&q[i]);
		printf("p[%d]=",i+1);
		scanf("%f",&p[i]);
	}
	
    traversare(c,d,q,p,n);

	//dezalocare
	for (i=0;i<n;i++) free(d[i]);
	free(c);
	free(q);
	free(p);

	getch();
}