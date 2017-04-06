/*参加计算机水平考试职员信息*/
#include <stdio.h>
#define N 3

union result
{
	int score;
	char grade;
};

typedef struct emploree 
{
	char num[10];
	char name[20];
	int age;
	union result final;
}EM, *PEM;

void inp (PEM);
int func (PEM, int);
void outp (PEM, int);

int main (void)
{	
	int count = 0;
	EM emp[N];
	inp (emp);
	count =	func (emp, count);
	outp (emp, count);
	return 0;
}

void inp (PEM emp)
{
	register int i;
	for (i = 0; i < N; i++)
	{
		printf ("Enter NO.%d emploree's message:\n", i+1);
		puts ("Num:");	
		scanf ("%s", emp[i].num);
		puts ("Name:");
		scanf ("%s", emp[i].name);
		puts ("Age:");
		scanf ("%d", &emp[i].age);
		if (emp[i].age <= 30)
		{
			puts ("Score:");
			scanf ("%d", &emp[i].final.score);
		}
		else 
		{
			puts ("Grade:");
			getchar ();
			scanf ("%c", &emp[i].final.grade);
		}
	}
}

int func (PEM emp, int count)
{
	register int i;
	for (i = 0; i < N; i++)
	{
		if (emp[i].age <=30 && emp[i].final.score >= 60)
			count ++;
		else if (emp[i].age > 30 && emp[i].final.grade <= 'C')
			count++;
	}
	return count;
}

void outp (PEM emp, int count)
{
	register int i;
	printf ("    NUM       NAME      AGE      RESULT     \n");   
	for (i = 0; i < N; i++)
	{
		if (emp[i].age <= 30)
			printf ("%7s%11s%8d%11d\n", emp[i].num, emp[i].name, emp[i].age,
				emp[i].final.score);
		else 
			printf ("%7s%11s%8d%11c\n", emp[i].num, emp[i].name, emp[i].age,
				emp[i].final.grade);
	}
	printf ("及格人数: %d\n", count);
}
