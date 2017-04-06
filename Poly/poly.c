#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Polynomial
{
	float coef;
	int expn;
	struct Polynomial *next;
}Poly, *Polyn;

Polyn CreatPoly (void)
{
	Poly *head, *rear, *s;
	float c;
	int e;
	head = (Polyn) malloc (sizeof (Poly));
	rear = head;
	puts ("Please enter coef and expn: ");
	scanf ("%f %d", &c, &e);
	while (c != 0)
	{
		s = (Polyn) malloc (sizeof (Poly));
		s->coef = c;
		s->expn = e;
		rear->next = s;
		rear = s;
		puts ("Please enter coef and expn: ");
		scanf ("%f %d", &c, &e);
	}
	rear = NULL;
	return (head);
}

void ShowPoly (Polyn head)
{
	Polyn p = head->next;
	int flag = 1;
	if (!p)
	{
		putchar ('0');
		printf ("\n");
		return;
	}
	while (p)
	{
		if (p->coef > 0 && flag != 1)
			putchar ('+');
		if (p->coef != 1 && p->coef != -1)
		{
			printf ("%g", p->coef);
			if (p->expn == 1)  
				putchar ('X');
			else if (p->expn)
				printf ("X^%d", p->expn);
		}
		else 
		{
			if (p->coef == 1)
			{
				if (!p->expn) 
					putchar ('1');
				else if (p->expn == 1)
					putchar ('X');
				else 
					printf ("X^%d", p->expn);
			}
			if (p->coef == -1)
			{
				if (!p->expn)		
					printf ("-1");
				else if (p->expn == 1)
					putchar ('X');
				else 
					printf ("X^%d", p->expn);
			}
		}
			p = p->next;
			flag++;
	}
	putchar ('\n');
}

Polyn AddPolyn (Polyn pa, Polyn pb)
{
	Polyn qa = pa->next;
	Polyn qb = pb->next;
	Polyn headc, pc, qc;
	pc = (Polyn) malloc (sizeof (Poly));
	headc = pc;
	pc->next = NULL;
	while (qa != NULL && qb != NULL)
	{
		qc = (Polyn) malloc (sizeof (Poly));
		if (qa->expn < qb->expn)
		{
			qc->expn = qa->expn;
			qc->coef = qa->coef;
			qa = qa->next;
		}
		else if (qa->expn > qb->expn)
		{
			qc->expn = qb->expn;
			qc->coef = qb->coef;
			qb = qb->next;
		}
		else
		{
			qc->expn = qb->expn;
			qc->coef = qa->coef + qb->coef;
			qa = qa->next;
			qb = qb->next;
		}
		if (qc->coef != 0)
		{
			qc->next = pc->next;
			pc->next = qc;
			pc = qc;
		}
		else 
			free (qc);
	}
	while (qa != NULL)
	{
		qc = (Polyn) malloc (sizeof (Poly));
		qc->coef = qa->coef;
		qc->expn = qa->expn;
		qa = qa->next;
		qc->next = pc->next;
		pc->next = qc;
		pc = qc;
	}
	while (qb != NULL)
	{
		qc = (Polyn) malloc (sizeof (Poly));
		qc->coef = qb->coef;
		qc->expn = qb->expn;
		qb = qb->next;
		qc->next = pc->next;
		pc->next = qc;
		pc = qc;
	}
	return headc;
}

Polyn SubtractPolyn (Polyn pa, Polyn pb)
{
	Polyn h = pb;
	Polyn p = pb->next;
	Polyn pd;
	while (p)
	{
		p->coef *= -1;
		p = p->next;
	}
	pd = AddPolyn (pa,h);
	for (p = h->next; p; p = p->next)
		p->coef *= -1;
	return pd;
}
		
int main (void)
{
	Polyn heada, headb, headc,headd;
	puts ("Enter Polya: ");
	heada = CreatPoly ();
	puts ("Enter Polyb: ");
	headb = CreatPoly ();
	puts ("Polya: ");
	ShowPoly (heada);
	puts ("Polyb: ");
	ShowPoly (headb);
	headc = AddPolyn (heada, headb);
	puts ("Polyc:(a+b) ");
	ShowPoly (headc);
	headd = SubtractPolyn (heada, headb);
	puts ("Polyd:(a-b) ");
	ShowPoly (headd);
	return 0;
}		
		
		

