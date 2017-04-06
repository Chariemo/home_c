/*使用switch语句 */
#include<stdio.h>
#include<ctype.h>
int main (void)
{
	char ch;
	printf("Give me a letter of the alphabet,and i will give");
	printf("an animal name\n beginning with that letter.\n");
	printf("Please type in a letter :type # to end my act.\n");
	while ((ch = getchar()) != '#')
	{
		if ('\n' == ch)
			continue;
		if (islower(ch))		
			switch (ch)
			{
				case 'a':
					printf("argali,a wild sheep of");
					printf("Asia\n");break;
				case 'b':
					printf("babirusa,s wild pig of");
					printf("Malay\n");break;
				case 'c':
					printf("coati,racoonlike mammal\n");
					break;
				case 'd':
					printf("desman,aquatic,molelike");
					printf("critter\n");break;
				case 'e':
					printf("echidna,the spiny anteater\n");
					break;
				case 'f':
					printf("fisher,brownish marten\n");
					break;
				default:
					printf("that's a stumper!\n");
			}
		else
			printf("Irecognize only lowercase letters.\n");
		while (getchar() != '\n')
			continue;
		printf("Please type another letter or a #.\n");
	}
		printf("Bye!");
		return 0;
}
	
