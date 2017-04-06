#include <stdio.h>
#include <stdlib.h>

struct Student
{
	char name[20];
	int number;
	struct Student *next;
};

int count;
struct Student *Create ()
{
	struct Student *pHead = NULL;
	struct Student *pEnd, *pNew;
	count = 0;
	pEnd = pNew = (struct Student *) malloc (sizeof (struct Student));
	printf ("请输入学生的姓名和学号:\n");
	scanf ("%s", pNew->name);
	scanf ("%d", &pNew->number);
	while (pNew->number != 0)
	{
		count++;
		if (count == 1)
		{
			pNew->next = NULL;
			pEnd = pNew;
			pHead = pNew;
		}
		else 
		{
			pNew->next = NULL;
			pEnd = pNew;
			pEnd->next = pNew;
		}
		pNew = (struct Student *) malloc (sizeof (struct Student));
		scanf ("%s", pNew->name);
		scanf ("%d", &pNew->number);
	}
	free (pNew);
	return pHead;
}

void Print (struct Student *pHead)
{
	struct Student *pTemp;
	int index = 1;
	printf ("**************本名单有%d个学生:**************", count);
	pTemp = pHead;
	while (pTemp != NULL)
	{
		printf ("第%d个学生的姓名和学号:\n", index);
		printf ("姓名: %s\n", pTemp->name);
		printf ("学号: %d\n", pTemp->number);
		index++;
		pTemp = pTemp->next;
	}
}

struct Student *Insert (struct Student *pHead)
{
	struct Student *pNew;
	printf ("请输入学生的姓名和学号:\n");
	pNew = (struct Student *) malloc (sizeof (struct Student));
	scanf ("%s", pNew->name);
	scanf ("%d", &pNew->number);
	pNew->next = pHead;
	pHead = pNew;
	count++;
	return pHead;
}

void Delete (struct Student *pHead, int index)
{
	int i;
	struct Student *pTemp;
	struct Student *pPre;
	pTemp = pHead;
	pPre = pTemp;
	printf ("----------删除第%d个学生----------\n", index);
	for (i = 1; i < index; i++)
	{
		pPre = pTemp;
		pTemp = pTemp->next;
	}
	pPre->next = pTemp->next;
	free (pTemp);
	count--;
}

int main (void)
{
	struct Student *pHead;
	pHead = Create ();
	pHead = Insert (pHead);
	Delete(pHead, 2);
	Print (pHead);
	return 0;
} 
