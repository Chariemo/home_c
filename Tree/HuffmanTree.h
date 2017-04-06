#ifndef _HUFFMANTREE_
#define _HUFFMANTREE_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5
#define M 2*N-1
#define MAXINT 32787
typedef char* HuffmanCode[N+1];
typedef struct
{
	int weight;
	int parent;
	int LChild;
	int RChild;
}HTNode, HuffmanTree[M+1];

void select_ht (HuffmanTree ht, int pos, int *s1, int *s2);

void CrtHuffmanTree (HuffmanTree ht, int w[], int n);

void CrtHuffmanCode (HuffmanTree ht, HuffmanCode hc, int n);
#endif 
