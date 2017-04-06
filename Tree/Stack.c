#include "Stack.h"

void initStack (Stack ** s)
{
	*s = (Stack *) malloc (sizeof (Stack));
	(*s)->top = -1;
}

bool IsEmpty (Stack *s)
{
	if (s->top == -1)
		return true;
	else 
		return false;
}

void Push (Stack *s, DataType_s x)
{
	if (s->top != MAXSIZE -1)
	{
		s->top ++;
		s->data[s->top] = x;
	}
	else
	{
		printf ("The Stack is fulled!\n");
		return;
	}
}

void Pop (Stack *s, DataType_s *x)
{
	if (!IsEmpty (s))
	{
		*x = s->data[s->top];
		s->top--;
	}
	else
	{
		printf ("The Stack is empty!\n");
		return;
	}
}

void getTop (Stack *s, DataType_s *x)
{
	if (!IsEmpty (s))
		*x = s->data[s->top];
}

