#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>
void Init_Queue (Queue **q)
{
	*q = (Queue *) malloc (sizeof (Queue));
	(*q)->front = (*q)->rear = MAX - 1;
}

bool IsEmpty_Queue (Queue *q)
{
	if (q->rear == q->front)
		return true;
	else
		return false;
}

bool IsFull_Queue (Queue *q)
{
	if ((q->rear+1) % MAX == q->front)
		return true;
	else 
		return false;
}

void In_Queue (Queue *q, DataType x)
{
	if (!IsFull_Queue (q))
	{
		q->rear = (q->rear+1) % MAX;
		q->data[q->rear] = x;
	}
	else
	{
		printf ("The Queue is empty!\n");
		return;
	}
}

void Out_Queue (Queue *q, DataType *x)
{
	if (!IsEmpty_Queue (q))
	{
		q->front = (q->front + 1) % MAX;
		*x = q->data[q->front];
	}
	else
	{
		printf ("The Queue is full!\n");
		return;
	}
}
