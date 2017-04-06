#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct film {
	char title[20];
	int rating;
	struct film *next;
}FL, *PFL;

int main (void)
{
	PFL head = NULL;
	PFL prev, current;
	char input[20];
	puts ("Title:");
	while (gets (input) != NULL && input[0] != '\0')
	{
		if ((current = (PFL) malloc (sizeof (FL))) == NULL)
			puts ("create faile");
		if (head == NULL)
			head = current;
		else 
			prev->next = current;
		strcpy (current->title, input);
		puts ("Rating:");
		scanf ("%d", &current->rating);
		current->next = NULL;
		while (getchar () != '\n')
			continue;
		prev = current;
		puts ("Title(empty line to quit)");
	}
	current = head;
	while (current != NULL)
	{
		printf ("Title: %-20s  Rating: %d\n", current->title,
			current->rating);
		current = current->next;
	}
		
	current = head;
	while (current != NULL)
	{
		free (current);
		current = current->next;
	}
	return 0;
}
