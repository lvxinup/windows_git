#define  _CRT_SECURE_NO_WARNINGS 1

// Ñî»ÔÈý½Ç


#include<stdio.h>  
int main()
{
	int arr[50][50] = {0};
	int a = 0;
	int i = 0;               
	int j = 0;               
	scanf("%d", &a);
	for (j = 0; j < a; j++)
		arr[j][0] = 1;
	for (i = 1; i < a; i++)
	{
		for (j = 1; j < a; j++)
		{
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
		}
	}
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < a; j++)
		{
			if (arr[i][j])
				printf("%d\t", arr[i][j]);
		}
		printf("\n");	
	}
	system("pause");
	return 0;

}