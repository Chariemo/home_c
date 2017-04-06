#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void CopyToNode (Item item, List pnode);

void InitializeList (List * plist)
{
	* plist = NULL;
}

bool ListIsEmpty (const List  plist)
{
	if (plist == NULL)
		return true;
	else
		return false;
}

bool ListIsFull (const List plist)
{
	List pt;
	bool full;
	
	pt = (List)malloc (sizeof (Node));
	if (pt == NULL)
		full = true;
	else
		full = false;
	free (pt);
	return full;
}

unsigned int ListItemCount (const List *plist)
{
	unsigned int count = 0;
	List pnode = *plist;
	
	while (pnode != NULL)
	{
		++count;
		pnode = pnode->next;
	}
	return count;
}

bool AddItem (Item item, List * plist)
{
	List pnew;
	List scan = *plist;
	
	pnew = (List) malloc (sizeof (Node));
	if (pnew == NULL)
		return false;
	CopyToNode (item, pnew);
	pnew->next = NULL;
	if (scan == NULL)
		*plist = pnew;
	else 
	{
		while (scan->next != NULL)	
			scan = scan->next;
		scan->next = pnew;
	}
	return true;
}

void Traverse (const List * plist, void (* pfun) (Item item))
{
	List pnode = * plist;
	while (pnode != NULL)
	{
		(* pfun) (pnode->item);
		pnode = pnode->next;
	}
}

void EmptyTheList (List * plist)
{
	List psave;
	while (*plist != NULL)
	{
		psave = (*plist)->next;
		free (*plist);
		*plist = psave;
	}
}

static void CopyToNode (Item item, List pnode)
{
	pnode->item = item;
}
