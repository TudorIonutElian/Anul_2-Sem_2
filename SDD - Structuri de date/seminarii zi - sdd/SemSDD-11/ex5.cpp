//Algoritmul lui Dijkstra

#include <stdio.h>
#include <conio.h>

const int maxn = 30000;

struct nodls
{
    int nod, cost;
    nodls *next;
};

int n, m;
nodls *a[maxn];
int d[maxn], q[maxn];

void adauga(int sursa, int dest, int cost)
{
    nodls *q = new nodls;
    q->nod = dest;
    q->cost = cost;
    q->next = a[sursa];
    a[sursa] = q;
}

void citeste()
{
	FILE *f = fopen("ex5_date.txt","r");

    fscanf(f, "%d %d", &n, &m);

    int x, y, z;
    for (int i = 1; i <= m; i++)
    {
        fscanf(f, "%d %d %d", &x, &y, &z);
        adauga(x, y, z);
    }
}

void dijkstra()
{
    for (int i = 2; i <= n; ++i )
		d[i]=maxn;

    int min, pmin = 0;

    for (int i = 1; i <= n; ++i )
    {
		min = maxn;
        for (int j = 1; j <= n; ++j )
            if ( d[j] < min && !q[j] )
			{ 
				min = d[j]; 
				pmin = j; 
			}

        q[pmin] = 1;

        nodls *t = a[pmin];

        while (t)
        {
            if ( d[t->nod] > d[pmin] + t->cost )
                d[t->nod] = d[pmin] + t->cost;
            t = t->next;
        }
    }
}

void main()
{
    citeste();

    dijkstra();

	for (int i = 2; i <= n; i++)
		printf("\nLungimea drumului minim de la nodul 1 la nodul %d este %d", i,  d[i]);
	
	getch();
}
