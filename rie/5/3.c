#include<stdio.h>
int main(void)
{
	float w;  // 用户的体重
	float v;  //相等重量的铑的价值
	printf("Are you worth your weight in rhodium?\n");
	printf("Let's check it out.\n");
	printf("Please enter your weight in pounds:");
	scanf("%f",&w);
	v=770*w*14.5833;
	printf("Your weight in rhodium is worth $%.2f.\n",v);
	printf("You are easily worth that!If rhodium prices drop.\n");
	printf("eat more to maintain yout value.\n");
	return 0; 



}
