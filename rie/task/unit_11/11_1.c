/* 从键盘输入学生信息写入文档*/

#include <stdio.h>
#include <stdlib.h>
#define N 3

typedef struct student
{
	char num[10];
	char name[20];
	char class[15];
	char address[30];
}STU, *PSTU;

int main (void)
{
	FILE *fp;
	STU stu[N];
	register int i;
	for (i = 0; i < N; i++)
	{
		printf ("Enter NO.%d student's message:\n", i+1);
		puts ("Num:");
		scanf ("%s", stu[i].num);
		puts ("Name:");
		scanf ("%s", stu[i].name);
		puts ("Class:");
		scanf ("%s", stu[i].class);
		puts ("address:");
		scanf ("%s", stu[i].address);
	}
	
	if ((fp = fopen ("stu.dat", "w")) == NULL)
	{
		printf ("Can't open the file!");
		exit (1);
	}
	
	fwrite (stu, sizeof (STU), N, fp);
	fclose (fp);
	return 0;
}
