#define  _CRT_SECURE_NO_WARNINGS 1

/*日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯 
的一个。以下为4个嫌疑犯的供词。 
A说：不是我。 
B说：是C。 
C说：是D。 
D说：C在胡说 
已知3个人说了真话，1个人说的是假话。 
现在请根据这些信息，写一个程序来确定到底谁是凶手。*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
		char ch = 0;
		for (ch = 'a'; ch <= 'd'; ch++)
		{
			if (((ch != 'a') + (ch == 'c') + (ch == 'd') + (ch != 'd')) == 3)
			{
				printf("%c", ch);
				break;
			}
		}
		printf("\n");
	system("pause");
	return 0;
}