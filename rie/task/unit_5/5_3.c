/*统计3行 每行80个字符文章中英文大写 小写 数字 空格 其他字符个数*/

#include <stdio.h>
#define ROWS 3
#define COLS 3

int main (void)
{
	char essay[ROWS][COLS];
	register int r, c;
	int cap_c = 0, low_c = 0, num_c = 0, oth_c = 0, spa_c = 0;
	puts ("Enter the essay:");
	gets (essay);
	
	for (r = 0; r < ROWS; r++)
		for (c = 0; c <COLS; c++)
		{
			if (essay[r][c] >= 'A' && essay[r][c] <= 'Z')
				cap_c++;
			else if (essay[r][c] >= 'a' && essay[r][c] < 'z')
				low_c++;
			else if (essay[r][c] == ' ')
				spa_c++;
			else if (essay[r][c] >= '0' && essay[r][c] <= '9')
				num_c++;
			else
				oth_c++;
		}
	printf ("Capital: %d\nLowercase: %d\nNumber: %d\nSpace: %d\nOther: %d\n",
		cap_c, low_c, num_c, spa_c, oth_c);
	return 0;
}
