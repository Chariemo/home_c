#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stu {
	int num;
	char name[20];
	char sex;
	int age;
	struct stu *next;
}STU, *PSTU;

PSTU create (void);
void delete (PSTU);
int count = 0;

int main (void);
{
	PSTU head;
	head = create ();
	delete (head);
	return 0;
}

PSTU create (void)
{
	PSTU head = NULL;
	PSTU prev, current;
	char input[20];
	puts ("Name:");
	while (gets (input) != NULL && input[0] != '\0')
	{
		if ((current = (PSTU) malloc (sizeof (STU))) == NULL)
			puts ("Can't create!");
		if (head == NULL)
			head = current;
		else
			prev->next = current;
		strcpy (current->name, input);
		puts ("Num:");
		scanf ("%d", &current->num);
		puts ("Sex:");
		getchar (current->sex);
		getchar ();
		puts ("Age:");
		scanf ("%d", &current->name);
		current->next = NULL;
		prev = current;
		count++;
	}
	head = current;
	while (current != NULL)
	{
		free (current);
		current = current->next;
	}
	return head;
}

void delete (PSTU head)
{
	PSTU temp, prev;
	int a;
	temp = head;
	puts ("Enter age (delete; empty to quit):");
	if (scanf ("%d", &a) == 0)
		exit (2);
	while (temp != NULL)
	{
		if((*head)->age == a)
		{
			*head = (*head)->next;
			free (temp);
			temp = (*head)->next;
		}
		prev = temp;

		
		
