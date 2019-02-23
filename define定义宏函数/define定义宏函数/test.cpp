#define  _CRT_SECURE_NO_WARNINGS 1

#define SQUARE(x) x*x
#define MAX(a,b) (a>b?a:b)

#include<stdio.h>
#include<Windows.h>

int main()
{
	int a = 5;
	int b = 3;
	//printf("SQUARE(a): %d\n",SQUARE(a));	//这个值为25
	//printf("SQUARE(a+1): %d\n", SQUARE(a + 1));	//第一反应是打印36，其实打印的是11
	printf("MAX(a, b): %d\n", MAX(a, b));
	printf("MAX(a&1, b&1	): %d\n", MAX(a&1, b&1));


	system("pause");
	return 0;
}