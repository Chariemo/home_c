#ifndef _BITREE_H_
#define _BITREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char DataType;
typedef struct Node
{
	DataType data;
	struct Node *LChild;
	struct Node *RChild;
}BiNode, *BiTree;

void creatTree (BiTree *root);

void visit (DataType data);

void preOrder1 (BiTree root);
void preOrder2 (BiTree root);

void inOrder1 (BiTree root);
void inOrder2 (BiTree root);

void postOrder1 (BiTree root);
void postOrder2 (BiTree root);

void printTree (BiTree root, int h);

void leafPath (BiTree root, DataType path[], int pathlength);

BiTree createByPI (DataType *pre, DataType *in, int n);

BiTree createByIP (DataType *in, DataType *post, int n);

void leafCount (BiTree root, int n, int h);
#endif 
