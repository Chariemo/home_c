/*调用函数求两个整数的最大公约数和最大公倍数*/

#include <stdio.h>

int gy(int, int);
int gb(int, int, int);

int main (void)
{
	int num1, num2, gy_m, gb_m;
	puts("Please enter two numbers:");
	scanf ("%d %d", &num1, &num2);
	gy_m = gy(num1, num2);
	gb_m = gb(num1, num2, gy_m);
	printf ("%d和%d的最小公倍数为%d; 最大公约数为%d;\n", num1, num2,
		 gb_m, gy_m);
	return 0;
}

int gy (int num1, int num2)
{
	int min = (num1 < num2) ? num1:num2;
	register int i;
	for (i = min; i > 0; i--)
		if (num1%i == 0 && num2%i == 0)
			return i;
}
	
int gb (int num1, int num2, int gy_m)
{
	return (num1*num2/gy_m);
}
