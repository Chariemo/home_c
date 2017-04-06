#include<stdio.h>
int main (void)
{
	int age;int key=1;int answer;
	const float prince = 100.0;
	printf("请输入你的年龄:");
	scanf("%d",&age);
	if ( age <= 12)
		printf("你的票价为:%.2f\n",0.1 *prince);
	else if (age >= 60)
		printf("您的票价为:%.2f\n",0.3 * prince);
	else
	{
		printf("学生?(yes:1 or no:0)");
		scanf("%d",&answer);
		if (answer == key)
			printf("你的票价为:%.2f\n",0.5*prince);
		else
			printf("你的票价为:%.2f\n",prince);
	}
	return 0;
}
