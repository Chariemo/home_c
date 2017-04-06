#ifndef _STACK_H_
#define _STACK_H_

#include "Bitree.h"
#define MAXSIZE 20

typedef BiTree DataType_s;
typedef struct
{
	DataType_s data[MAXSIZE];
	int top;
}Stack;


void initStack (Stack ** s);

bool IsEmpty (Stack *s);

void Push (Stack *s, DataType_s x);

void Pop (Stack *s, DataType_s *x);

void getTop (Stack *s, DataType_s *x);

#endif 
