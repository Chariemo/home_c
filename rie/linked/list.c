/*支持列表操作的函数*/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void CopyToNode (Item item, Node * pnode); //局部函数原型

void InitializeList (List * plist) //把列表设置为空列表
{
	* plist = NULL;
}

bool ListIsEmpty (const List plist) //如果列表为空则返回真
{
	if (plist == NULL)
		return true;
	else
		return false;
}

bool ListIsFull (const List  plist) //如果列表已满则返回真
{
	Node *pt;
	bool full;
	
	pt = (Node *) malloc (sizeof (Node));
	if (pt == NULL)
		full = true;
	else 
		full = false;
	free (pt);
	return full;
}

unsigned int ListItemCount (const List plist) //返回节点数
{
	unsigned int count = 0;
	Node * pnode = plist;
	
	while (pnode != NULL)
	{
		++count;
		pnode = pnode->next;
	}
	return count;
}

bool AddItem (Item item, List * plist) /*创建存放项目的节点，并把它添加到
有plist指向的列表（较慢的实现方法）尾部*/
{
	Node * pnew;
	Node * scan = *plist;

	pnew = (Node *) malloc (sizeof (Node));
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

void Traverse (const List  plist, void (* pfun) (Item item))
//访问每个节点并对它们分别执行由pfun指向的函数
{
	Node * pnode = plist;
	while (pnode != NULL)
	{
		(*pfun) (pnode->item);
		pnode = pnode->next;
	}
}

void EmptyTheList (List * plist) //释放由malloc() 分配的内存
{
	Node * psave;
	while (* plist != NULL)
	{
		psave = (*plist)->next;
		free (*plist);
		*plist = psave;
	}
}

static void CopyToNode (Item item, Node *pnode)
{
	pnode->item = item;
}
