//Algoritmul lui Prim

#include <stdio.h>
#include <conio.h>

typedef struct min
{
    int lin, col;
} min;

void afisare(int a[50][50],int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		printf("%6d",a[i][j]);
		printf("\n");
	}
}

int in(int v[50],int n,int x)
{
	for(int i=1;i<=n;i++)
		if (v[i]==x) return 1;
	return 0;
}

int n,a[50][50];

min minim(int v[50],int k)
{
	min min0;
	int i,j;
	int min1=30000;
	for(i=1;i<=k;i++)
	for(j=1;j<=n;j++)
		if (a[v[i]][j]<min1 && a[v[i]][j]!=0 && in(v,k,j)==0)  
			{
				min0.lin=v[i];
				min0.col=j;
				min1=a[v[i]][j];
			}
	return min0;
}

void main()
{
	int t[50][50],vec[50],i,j,v,s,k,x,y;

	FILE *f;
	f=fopen("ex6_date.txt","r");
	if (f)
	{
		fscanf(f,"%d",&n);
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			fscanf(f,"%d",&a[i][j]);
	}
	else printf("\nNu exista fisier!");

	printf("\nGraful are %d noduri, matricea sa de adiacenta fiind:\n",n);
	afisare(a,n);

	printf("\nIntroduceti un nod v (1<=v<=%d)",n);
	scanf("%d",&v);
	for(i=1;i<=n;i++)
    for(j=1;j<=n;j++) t[i][j]=0;
	k=1;
	vec[k]=v;
	for(i=1;i<n;i++)
    {
		x=minim(vec,k).lin;
		y=minim(vec,k).col;
		t[x][y]=a[x][y];
		t[y][x]=t[x][y];
		a[x][y]=1000;
		a[y][x]=1000;
		k++;
		vec[k]=y;
    }

	printf("\nArborele de cost minim rezultat este:\n");
	afisare(t,n);

	getch();
}