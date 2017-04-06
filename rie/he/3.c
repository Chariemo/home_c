/*求成绩最高者的序号和成绩*/
#include<stdio.h>
#define NUM 10
int main (void)
{
    int stu[NUM], i, max, n;
    
    printf("Please enter %d student's score:\n",NUM);
    for (i = 0; i < NUM; i ++)
	scanf("%d",&stu[i]);
    
    max =  stu[0];
    n = 1;
    for (i = 1; i < NUM; i ++)
	if (max < stu[i])
	{
	    max = stu[i];
	    n = i + 1;
	}
    printf("NO.%d : %d",n, max);
    return 0;
}
