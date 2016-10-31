#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct node
{
	ElemType data;
	struct node *next;
}LNode, *LinkList;

void Init_List (LinkList L)
{
	L = (LNode *) malloc (sizeof (LNode));
	L->next = NULL;
}

void Create_List (LinkList L)
{
	ElemType a;
	LNode *prev, *current;
	printf ("Enter a data(number): ");
	while (scanf ("%d", &a))
	{
		current = (LNode *) malloc (sizeof (LNode));
		current->data = a;
		current->next = NULL;
		if (L->next == NULL)
		{	
			prev = current;
			L->next = prev;

		}
		else 
		{	
			prev->next = current;
			prev = current;
		}
		printf ("Enter a data (number): ");
	}
}

void AddHead (LinkList L, ElemType m)
{
	LNode *current;
	current = (LNode *) malloc (sizeof (LNode));
	current->data = m;
	current->next = L->next;
	L->next = current;
	
}

void AddTail (LinkList L, ElemType m)
{
	LNode *current, *H;
	H = L;
	current = (LNode *) malloc (sizeof (LNode));
	current->data = m;
	current->next = NULL;
	while (H->next != NULL)
	{
		H = H->next;
	}
	H->next = current;


}

int Length_List (LinkList L)
{
	int temp = 0;
	LNode *p;
	p = L;
	while (p->next != NULL)
	{
		temp ++;
		p = p->next;
	}
	return temp;

}

LNode * Find_List (LinkList L, ElemType m)
{
	LNode * p = L->next;
	while (p!= NULL)
	{
		if (p->data == m)
			return p;
		else
			p = p->next;
	}
}

void Inset_List (LinkList L, ElemType a, ElemType b)
{
	LNode * p, *q;
	p = L->next;
	while (p != NULL && p->data != a)
		p = p->next;
	q = (LNode *) malloc (sizeof (LNode));
	q->data = b;
	q->next = p->next;
	p->next = q;
}

void Delete_List (LinkList L, ElemType m)
{
	LNode *p, *q;
	p = L;
	while (p->next != NULL && p->next->data != m)
	{
		p = p->next;
	}
	if (p->next != NULL)
	{
		q = p->next;
		p->next = p->next->next;
		free (q);
	}
	else
	{
		if (p->data == m)
			free (p);
		else 
			printf ("The List has no the data!\n");
	}
}

void Reverse (LinkList L)
{
/*	LNode *p, *q, *m;
	p = L->next;
	while (p)
	{
		q = p->next;
		p->next = q->next;
		L->next = q;
		m = q;
		q->next = m;
	}
*/
	LNode *p, *q;
	p = L->next;
	L->next = NULL;
	while (p)
	{
		q = p;
		p = p->next;
		q->next = L->next;
		L->next = q;
	}
}

void Pur_List (LinkList L)
{
	LNode *p, *q, *r;
	p = L->next;
	if (p)
		while (p->next != NULL)
		{
			q = p;
			while (q->next != NULL)
			{
				if (q->next->data == p->data)
				{
					r = p->next;
					p->next = r->next;
					free (r);
				}
				else
					q = q->next;
			}
			p = p->next;
		}
}

void Difference (LinkList A, LinkList B)
{
	
}

void Show_List (LinkList L)
{
	LNode *p = L->next;
	int i = 0;
	while (p != NULL)
	{
		printf ("%5d", p->data);
		p = p->next;
		i++;
		if (i % 5 == 0)
			printf ("\n");
	}
}

int main (void )
{
	LNode head;
	ElemType a;
	Init_List (&head);
	Create_List (&head);
	printf ("List1:\n");
	Show_List (&head);
	
/*	printf ("\nEnter a number to addHead: ");
	getchar ();
	scanf ("%d", &a);
	AddHead (&head, a);
	printf ("\nAddHead List2:\n");
	Show_List (&head);
	
	printf ("\nEnter a number to addTail: ");
	getchar ();
	scanf ("%d", &a);
	AddTail (&head, a);
	printf ("\nAddTail list3:\n");
	Show_List (&head);
	
	printf ("\nEnter a number to delete: ");
	getchar ();
	scanf ("%d", &a);
	Delete_List (&head, a);
	Show_List (&head);
		
	Reverse (&head);
	printf ("\nReversed List4:\n");
	Show_List (&head);
	printf ("\nLength of List: %d\n", Length_List (&head));
	Pur_List (&head);	
	printf ("After Pur:\n");
	Show_List (&head);
*/
	return 0;
}	
	
