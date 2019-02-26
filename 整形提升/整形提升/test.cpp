#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>

int main()
{
	//char a = -1;
	//signed char b = -1;
	//unsigned char c = -1;
	//printf("a=%d,b=%d,c=%d", a, b, c);	// a=-1 ,b=-1, c==255

	char a = -128;
	printf("%u\n", a);	//a=4294967168

	//char a = 128;
	//printf("%u\n", a);		//a=4294967168

	//int i = -20;
	//unsigned int j = 10;
	//printf("%d\n", i + j);

	//unsigned i;
	//for (i = 9; i >= 0; i--)
	//{
	//	printf("%u\n", i);	//死循环，i为无符号数，不可能为负数
	//}

	//short num = 32767;
	//short int a = num + 1;
	//printf("%d\n", a);		//-32768

	//int a = -3;
	//unsigned int b = 3;

	//if (a>b)
	//	printf("a > b,a = %d,b = %u\n", a, b);
	//else
	//	printf("a < b,a = %d,b = %u\n", a, b);

	system("pause");
	return 0;
}