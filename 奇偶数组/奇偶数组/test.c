#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
int main()
{
	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int arr2[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int i = 0;
	int count = 0;
	for (i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
	{
		if (arr1[i] % 2 == 1)
		{
			arr2[count]=arr1[i];
			count++;
		}
	}
	for (i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
	{
		if (arr1[i] % 2 == 0)
		{
			arr2[count] = arr1[i];
			count++;
		}
	}
	for (i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++)
	{
		printf("%d ", arr2[i]);
	}
	system("pause");
	return 0;
}