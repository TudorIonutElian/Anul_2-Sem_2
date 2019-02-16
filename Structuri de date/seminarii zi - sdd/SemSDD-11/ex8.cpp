//Algoritmul Roy-Floyd - determinarea matricei drumurilor minime

#include <stdio.h>
#include <conio.h>

int min(int a, int b)
{
	if(a<=b) return a;
	else return b;
}

void main()
{
	int i,j,k,n,a[20][20];

	FILE *f=fopen("ex8_date.txt","r");
	if (f)
	{
		fscanf(f,"%d",&n);
		for(i=0;i<n;i++)
		 for(j=0;j<n;j++)
		  fscanf(f,"%d",&a[i][j]);
	}
	else printf("\nNu exista fisier!");

	for(k=0;k<n;k++)
	  for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		 if((i!=k)&&(j!=k)&&(i!=j)) a[i][j]=min(a[i][j], a[i][k]+a[k][j]);

	printf("Matricea drumurilor minime este:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		printf(" %d ",a[i][j]);
		printf("\n");
	}

	getch();
}