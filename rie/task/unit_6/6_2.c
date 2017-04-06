/* 调用函数求高于平均成绩的人数 */
#include <stdio.h>
#define N 5
int num_h (int *, float);

int main (void)
{
	int score[N], sum = 0;
	float aver;
	register i;
	printf ("Enter %d students' score:", N);
	for (i = 0; i < N; i++)
		scanf ("%d", &score[i]);
	
	for (i = 0; i < N; i++)
		sum += score[i];
	aver = sum*1.0 / N;
	printf("%d个学生中成绩高于平均成绩的人数为%d\n", N, num_h(score, aver));
	return 0;
}

int num_h (int *score, float aver)
{
	register int i, count = 0;
	for (i = 1; i <= N; i++)
		if (*(score+i) > aver)
			count++;
	return count;
}
