#include "HuffmanTree.h"

int main (void)
{
	HuffmanTree ht;
	printf ("%d weights: ", N);
	int i;	
	int w[N];
	for (i = 1; i <= N; i++)
		scanf ("%d", &w[i]);
	CrtHuffmanTree (ht, w, N);
	HuffmanCode hc;
	CrtHuffmanCode (ht, hc, N);
	for (i = 1; i <= N; i++)
		printf ("%d's Code: %s\n", ht[i].weight, hc[i]);
 	for (i = N+1; i <= M; i++)
		printf ("No.%d:	%d %d %d %d\n", i, ht[i].weight, ht[i].parent, ht[i].LChild, ht[i].RChild);
	return 0;
}

void select_ht (HuffmanTree ht, int pos, int *s1, int *s2)
{
	int m1, m2, i, j;
	m1 = m2 = MAXINT;
	for (i = 1; i <= pos; i++)
	{
		if (ht[i].weight < m1 && ht[i].parent == 0)
		{
			m2 = m1;
			*s2 = *s1;
			*s1 = i;
			m1 = ht[i].weight;
		}
		else if (ht[i].weight < m2 && ht[i].parent == 0)
		{
			m2 = ht[i].weight;
			*s2 = i;
		}	
	}
}

void CrtHuffmanTree (HuffmanTree ht, int w[], int n)
{
	int i, s1, s2, m;
	m = 2 * n - 1;
	for (i = 1; i <= n; i++)
	{
		ht[i].weight = w[i];
		ht[i].parent = 0;
		ht[i].LChild = 0;
		ht[i].RChild = 0;
	}
	for (i = n+1; i <= m; i++)
	{
		ht[i].weight = 0;
		ht[i].parent = 0;
		ht[i].LChild = 0;
		ht[i].RChild = 0;
	}
	for (i = n+1; i <= m; i++)
	{
		select_ht (ht, i-1, &s1, &s2);
		ht[i].weight = ht[s1].weight + ht[s2].weight;
		ht[i].LChild = s1;
		ht[i].RChild = s2;
		ht[s1].parent = ht[s2].parent = i; 
	}
}	


void CrtHuffmanCode (HuffmanTree ht, HuffmanCode hc, int n)
{
	char *cd;
	int start, c, p, i;
	cd = (char *) malloc (n * sizeof (char));
	cd[n-1] = '\0';
	for (i = 1; i <= n; i++)
	{
		start = n - 1;
		c = i;
		p = ht[i].parent;
		while (p != 0)
		{
			--start;
			if (ht[p].LChild == c) 
				cd[start] = '0';
			else
				cd[start] = '1';
			c = p;
			p = ht[p].parent;
		}
		hc[i] = (char *) malloc ((n-start) * sizeof (char));
		strcpy (hc[i], &cd[start]);
	}
	free (cd);
}
