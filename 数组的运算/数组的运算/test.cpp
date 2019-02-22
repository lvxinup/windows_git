#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>

int main()
{
	/*int a[] = { 1, 2, 3, 4 };*/
	/*char a[] = { 'a', 'b', 'c', 'd', 'e', 'f'};*/
	//char *a = "abcdef";
	int a[3][4] = { 0 };
	printf("sizeof(a):%d\n", sizeof(a));
	printf("sizeof(a[0][0]):%d\n", sizeof(a[0][0])); 
	printf("sizeof(a[0]):%d\n", sizeof(a[0]));
	printf("sizeof(a[0]+1):%d\n", sizeof(a[0]+1));
	printf("sizeof(a+1):%d\n", sizeof(a+1));
	printf("sizeof(&a[0]+1):%d\n", sizeof(&a[0]+1));  
	printf("sizeof(*a)%d\n", sizeof(*a));
	printf("sizeof(a[3])%d\n", sizeof(a[3]));

	//printf("strlen(a) : %d\n", strlen(a));
	//printf("strlen(a+1) : %d\n", strlen(a+1));
	////printf("strlen(*a) : %d\n", strlen(*a));
	////printf("strlen(a[1]) : %d\n", strlen(a[1]));
	////printf("strlen(&a) : %d\n", strlen(&a));
	////printf("strlen(&a+1) : %d\n", strlen(&a+1));
	//printf("strlen(&a[0] + 1) : %d\n", strlen(&a[0] + 1));

	system("pause");
	return 0;
}