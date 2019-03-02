#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<windows.h>

int main()
{
	printf("%s,%d,%s,%s",__FILE__,__LINE__,__DATE__,__TIME__);

	system("pause");
	return 0;
}