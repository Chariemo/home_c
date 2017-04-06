#include "Stack.h"
#include <string.h>
int lcount = 0;
int main (void)
{
	BiTree root;
	creatTree (&root);
	postOrder2 (root);
	return 0;
}


void creatTree (BiTree *root)
{
	DataType temp;
	temp = getchar ();
	if (temp == '#')
		*root = NULL;
	else
	{
		*root = (BiTree) malloc (sizeof (BiNode));
		(*root)->data = temp;
		creatTree (&((*root)->LChild));
		creatTree (&((*root)->RChild));
	}
}


void visit (DataType data)
{
	printf ("%c ", data);
}


void preOrder1 (BiTree root)
{
	if (root)
	{
		visit (root->data);
		preOrder1 (root->LChild);
		preOrder1 (root->RChild);
	}
}

void preOrder2 (BiTree root)
{
	Stack *s;
	initStack (&s);
	BiNode *p;
	p = root;
	while (p != NULL || !IsEmpty (s))
	{
		if (p)
		{
			Push (s, p);
			visit (p->data);
			p = p->LChild;
		}
		else
		{
			Pop (s, &p);
			p = p->RChild;
		}
	}
}


void inOrder1 (BiTree root)
{
	if (root)
	{
		preOrder1 (root->LChild);
		visit (root->data);
		preOrder1 (root->RChild);
	}
}


void inOrder2 (BiTree root)
{
	Stack *s;
	initStack (&s);
	BiNode *p = root;
	while (p != NULL || !IsEmpty (s))
	{
		if (p)
		{
			Push (s, p);
			p = p->LChild;
		}
		else
		{
			Pop (s, &p);
			visit (p->data);
			p = p->RChild;
		}
	}
}



void postOrder1 (BiTree root)
{
	Stack *s;
	initStack (&s);
	BiTree p, q;
	p = root;
	q = NULL;
	while (p != NULL || !IsEmpty (s))
	{
		while (p != NULL)
		{
			Push (s, p);
			p = p->LChild;
		}
		if (!IsEmpty (s))
		{
			getTop (s, &p);
			if ((p->RChild == NULL) || (p->RChild == q))
			{
				Pop (s, &p);
				visit (p->data);
				q = p; p = NULL;
			}
			else
				p = p->RChild;
		}
	}
}


void postOrder2 (BiTree root)
{
	Stack *s;
	initStack (&s);
	BiTree q, p;
	p = root; q = NULL;
	while (p != NULL || !IsEmpty (s))
	{
		if (p)
		{
			Push (s, p);
			p = p->LChild;
		}
		else
		{
			getTop (s, &p);
			p = p->RChild;
			if (p == NULL || p == q)
			{
				Pop (s, &p);
				visit (p->data);
				q = p;
				p = NULL;
			}
		}
	}
}
void printTree (BiTree root, int h)
{
	int i;
	if (root == NULL) 
		return;
	printTree (root->RChild, h+1);
	for (i = 0; i < h; i++)
		printf ("   ");
	printf ("%c\n", root->data);
	printTree (root->LChild, h+1);
}

void leafPath (BiTree root, DataType path[], int pathlength)
{
	int i;
	if (root)
	{
		if (root->LChild == NULL && root->RChild == NULL)
		{
			printf ("%c: ", root->data);
			for (i = 0; i < pathlength; i++)
				printf ("%c ", path[i]);
			printf ("\n");
		}
		else
		{
			path[pathlength] = root->data;
			pathlength++;
			leafPath (root->LChild, path, pathlength);
			leafPath (root->RChild, path, pathlength);
			pathlength--;
		}
	}
}	

BiTree createByPI (DataType *pre, DataType *in, int n)
{
	BiNode *s; int pos; DataType *p;
	if (n <= 0)
		return NULL;
	s = (BiTree) malloc (sizeof (BiNode));
	s->data = *pre;
	for (p = in; p < in+n; p++)
		if (*pre == *p)
			break;
	pos = p - in;
	s->LChild = createByPI (pre+1, in, pos);
	s->RChild = createByPI (pre+1+pos, p+1, n-pos-1);
	return s;
}

BiTree createByIP (DataType *in, DataType *post, int n)
{
	BiNode *s; int pos; DataType *p;
	if (n <= 0)	
		return NULL;
	s = (BiTree) malloc (sizeof (BiNode));
	s->data = *(post+n-1);
	for (p = in; p < in+n; p++)
		if (*p == *(post+n-1))
			break;
	pos = p - in;
	s->LChild = createByIP (in, post, pos);
	s->RChild = createByIP (p+1, post+pos, n-pos-1);
	return s;
}

void leafCount (BiTree root, int n, int h)
{
	if (root == NULL)
		return;
	if (h == n &&root->LChild == NULL && root->RChild == NULL)
		lcount++;
	leafCount (root->LChild, n+1, h);
	leafCount (root->RChild, n+1, h);
}
