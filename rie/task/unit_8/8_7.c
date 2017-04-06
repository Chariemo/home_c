/*学生信息　外语成绩排序*/

#include <stdio.h>
#define N 3

typedef struct student
{
	char name[20];
	int ch;
	int ma;
	int en;	
	int sum;
}STU, *PSTU;

void inp (PSTU);
void func (PSTU);
void outp (PSTU);
	
int main (void)
{
	STU stu[N];
	inp (stu);
	func (stu);
	outp (stu);
	return 0;
}

void inp (PSTU stu)
{
	register int i;
	for (i = 0; i < N; i++)
	{
		printf ("Enter NO.%d student's message:\n", i+1);
		puts ("Name:");
		scanf ("%s", stu[i].name);
		puts ("scores of chinese math and english:");
		scanf ("%d %d %d", &stu[i].ch, &stu[i].ma, &stu[i].en);
	}
}

void func (PSTU stu)
{
	register int i, j;
	STU temp;
	for (i = 0; i < N; i++)
		stu[i].sum = stu[i].ch + stu[i].ma + stu[i].en;
	
	for (i = 0; i < N; i++)
		for (j = 0; j < N-i-1; j++)
		{
			if (stu[j].sum < stu[j+1].sum)
			{
				temp = stu[j];
				stu[j] = stu[j+1];
				stu[j+1] = temp;
			}
			else if (stu[j].sum == stu[j+1].sum)
				if (stu[j].en < stu[j+1].en)
				{
					temp =stu[j];
					stu[j] = stu[j+1];
					stu[j+1] = temp;
				}
		}
}

void outp (PSTU stu)
{
	register int i;
	puts ("Student's message:");
	puts ("  Name    Chinese    Math    English    Sum    ");
	for (i = 0; i < N; i++)
		printf ("%6s%9d%9d%10d%9d\n", stu[i].name, stu[i].ch,
			stu[i].ma, stu[i].en, stu[i].sum);
}
			
