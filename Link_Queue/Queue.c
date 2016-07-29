#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 10

typedef int DataType;
typedef struct
{
	DataType data[MAXSIZE];
	int rear, front;
}Queue;

void Init_Queue (Queue **q)
{
	*q = (Queue *) malloc (sizeof (Queue));
	(*q)->front = (*q)->rear = MAXSIZE - 1;
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
	if ((q->rear+1) % MAXSIZE == q->front)
		return true;
	else
		return false;
}

void In_Queue (Queue *q, DataType x)
{
	if (!IsFull_Queue (q))
	{
		q->rear = (q->rear+1) % MAXSIZE;
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
		q->front = (q->front + 1) % MAXSIZE;
		*x = q->data[q->front];
	}
	else
	{
		printf ("The Queue is full!\n");
		return;
	}
}

int main (void)
{
	Queue * q;
	Init_Queue (&q);
	DataType temp;
	while (!IsFull_Queue(q))
	{
		temp = getchar ();
		In_Queue (q, temp);
	}

	while (!IsEmpty_Queue(q))
	{
		Out_Queue (q, &temp);
		printf ("%c", temp);
	}
	return 0;
}
