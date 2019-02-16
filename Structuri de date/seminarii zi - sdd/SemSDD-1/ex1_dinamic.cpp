# include <stdio.h>
# include <malloc.h>
# include <conio.h>

void traversarematrice(float **mag, int n)
{
	int i,j;
    printf("\nCod Cantitate Pret");
	printf("\n");
	for (i=0;i<n;i++) {
		for (j=0;j<3;j++) 
			printf("%5.2f",mag[i][j]);
		    printf("\n");
		}
    float val=0,valori[100];
    for (i=0;i<n;i++) { 
		valori[i]=mag[i][1]*mag[i][2];
	    val+=valori[i];
	}
	printf("\nValoare");
	printf("\n");
	for (i=0;i<n;i++) printf("%5.2f ",valori[i]);
	printf("\nValoare totala=%5.2f",val);
}

void main()
{
	int i,j,n;

	printf("Numar produse=");
	scanf("%d",&n);

	//alocare
	float **mag = (float**)malloc(n*sizeof(float*));
	for (i=0;i<n;i++) mag[i]=(float*)malloc(3*sizeof(float));

	for (i=0;i<n;i++)
		for (j=0;j<3;j++) 
		{
			printf("mag[%d][%d]=",i+1,j+1);
			scanf("%f",&mag[i][j]);
		}

    traversarematrice(mag,n);

	//dezalocare
	for (i=0;i<n;i++) free(mag[i]);
	free(mag);

	getch();
}
