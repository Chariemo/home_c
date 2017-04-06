/*学生信息　学号　姓名　三门课成绩　总平均成绩　*/

#include <stdio.h>
#define N 3

typedef struct student 
{
	char num[10];
	char name[20];
	int score[3];
	float aver;
}STU, * PSTU;

void input (STU *);
void output (STU *);
void func(STU *);
int main (void)
{
	STU stu[N];
	input (stu);
	func(stu);
	output (stu);
	return 0;
}

void input (STU *stu)
{
	register int i;
	for (i = 0; i < N; i++)
	{
		printf ("Enter NO.%d student's information:\n", i+1);
		puts ("Num:");
		gets (stu[i].num);
		puts ("Name:");
		gets (stu[i].name);
		puts ("Three lessons' score:");
		scanf ("%d %d %d", &stu[i].score[0], &stu[i].score[1],
			&stu[i].score[2]);
		getchar ();
	}
}

void func (STU *stu)
{
	register int i, j;
	int change = 1;
	STU temp;
	for (i = 0; i < N; i++)
		stu[i].aver = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2])
			*1.0/3;
	for (i = 0; i < N && change; i++)
	{
		change = 0;
		for (j = 0; j < N-i-1; j++)
			if (stu[j].aver < stu[j+1].aver)
			{	
				temp = stu[j];
				stu[j] = stu[j+1];
				stu[j+1] = temp;
				change = 1;
			}	
	}
}

void output (STU *stu)
{
	register int i;
	puts ("Three lessons' average score:");
		for (i = 0; i < N; i++)
			printf ("NO.%d: %.2f\n", i+1, stu[i].aver);
	
	puts ("The best of them:");
	printf ("Num: %s  Name: %s  Score: %d %d %d  Average: %.2f\n",
		stu[0].num, stu[0].name, stu[0].score[0], stu[0].score[1],
		stu[0].score[2], stu[0].aver);
}
