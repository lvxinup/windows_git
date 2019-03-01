#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>

union ip_addr
{
	unsigned long addr;
	struct
	{
		unsigned char c1;
		unsigned char c2;
		unsigned char c3;
		unsigned char c4;
	}ip;
};

int main()
{
	union ip_addr my_ip;
	my_ip.addr = 176238749;
	printf("%d.%d.%d.%d\n", my_ip.ip.c4, my_ip.ip.c3, my_ip.ip.c2, my_ip.ip.c1);

	system("pause");
	return 0;
}