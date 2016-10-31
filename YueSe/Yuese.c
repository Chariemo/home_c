#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct NodeType
{
	int id;
	int password;
	struct NodeType *next;
}NodeType, *LinkList;

void CreatList (LinkList *L)
{	
	NodeType * current, *prev;
	int n, i, word;
	printf ("Enter the number of the list: ");
	scanf ("%d", &n);
	for (i = 1; i <= n; i++)
	{
		printf ("NO.%d's password: ", i);
		scanf ("%d", &word);
		if((current = (LinkList) malloc (sizeof (NodeType))) == NULL)
		{
			printf ("Malloc Failed!\n");
			exit (1);
		}
		current->id = i;
		current->password = word;
		if (*L == NULL)
		{
			*L = current;
			current->next = *L;
			prev = current;
		}
		else
		{	
			current->next = *L;
			prev->next = current;
			prev = current;
		}
	}
}

bool IsEmpty (LinkList L)
{
	if (L == NULL)
		return true;
	else
		return false;
}


NodeType * GetNode (LinkList L, int m)
{
	NodeType *p = L;
	int i;
	for (i = 1; i < m; i++)
		p = p->next;
	return p;
}



void DeleteNode (LinkList *L, int id)
{
	NodeType *p = *L, *prev;
	if (!IsEmpty (*L))
	{
		if (p->next != *L)
		{
			while(p->id !=id && p->next != *L)
				p = p->next;
			if (p->id == id && p != *L)
			{
				for (prev = p; prev->next != p; prev = prev->next);
				prev->next = p->next;
				free (p);
			}
			else if (p->id == id && p == *L)
			{
				for (prev = p; prev->next != p; prev = prev->next);
				*L = (*L)->next;
				prev->next  = *L;
				free (p);
			}
				
		}
		else
			if (p->id == id)
				*L = NULL;
	}
	else
	{
		printf ("The list is empty!\n");
		return;
	}	
}

void ShowList (LinkList L)
{
	NodeType *p = L;
	if (L->next == L )
	{
		printf ("List has no node!\n");
		return;
	}

	puts ("The list is as follow: ");
	printf ("----id-----password-----\n");
	do
	{
		printf ("    %d         %d\n", p->id, p->password);
		p = p->next;
	}while (p != L);
}


void Func (LinkList *L)
{
	NodeType * temp;
	int m;
	printf ("Enter the Beginning number(m): ");
	scanf ("%d", &m);	
	while (!IsEmpty (*L))
	{
		temp = GetNode (*L, m);
		printf("No.%d is out!(password:%d).\n", temp->id, temp->password);
		m = temp->password;
		*L = temp;
		DeleteNode (L, temp->id);
	}
}
int main (void)
{
	LinkList L = NULL;
	CreatList (&L);
	ShowList (L);
	Func (&L);
	return 0;
}
