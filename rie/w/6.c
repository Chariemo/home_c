/*若干个学生某门课的平均成绩*/
#include<stdio.h>
int main (void)
{
	int score,sum,num;
	float ava;
	sum = 0;
	num = 0;
	
	printf("Please enter student's score:");
	scanf("%d",&score);
	while (score > 0)
	{
		if (score < 60)
			printf("%d不及格\n",score);
		sum += score;
		num++;
		printf("Please enter student's score:(负数结束）");
		scanf("%d",&score);
	}
	ava = sum/num;
	printf("ava=%.2f\n",ava);
	return 0;
}
