#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	//int a = 10;
	//int b = 2;
	//int ret = a%2;
	int a = 1;
	a = a<<1;
	a = a<<1;
	a = a>>1;
	
	a<<3;
	//000000000000000000000000000001010
	//000000000000000000000000000000101

	//a = a<<1;
	printf("%d\n", a);//1

	//为什么存补码？
	
	//100000000000000000000000000000001
	//111111111111111111111111111111110
	//111111111111111111111111111111111
	
	//000000000000000000000000000000001
	//
	return 0;
}


//
//void menu()
//{
//	printf("*******************************\n");
//	printf("**    1.play       0.exit    **\n");
//	printf("*******************************\n");
//}
//void game()
//{
//	//1.生成随机值
//	int num = 0;
//	int input = 0;
//	num = rand()%100+1;
//	//2.猜数字
//	while(1)
//	{
//		printf("请猜数字:>");
//		scanf("%d", &input);
//		if(input == num)
//		{
//			printf("恭喜你，猜对了\n");
//			break;
//		}
//		else if(input>num)
//		{
//			printf("猜大了\n");
//		}
//		else
//		{
//			printf("猜小了\n");
//		}
//	}
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch(input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	}
//	while(input);
//	return 0;
//}
//


//
//int binary_search(int arr[], int key, int left, int right)
//{
//	while(left<=right)
//	{
//		int mid = left+(right-left)/2;
//		if(arr[mid] > key)
//			right = mid-1;
//		else if(arr[mid] < key)
//			left  = mid+1;
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	//二分查找
//	//折半查找
// 	int arr[] = {1,2,3,4,5,6,7,8,9,10};
// 	int key = 7;
//	int ret = 0;
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	ret = binary_search(arr, key, 2, 8);
//	if(ret == -1)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("找到了:%d\n", ret);
//	}
//	return 0;
//}

//
//int main()
//{
//	int n = 0;
//	int i = 0;
//	int ret = 1;
//	int j = 0;
//	int sum = 0;
//	for(j=1; j<=3; j++)
//	{
//// 		ret = 1;
//// 		for(i=1; i<=j; i++)
//// 		{
//// 			ret = ret*i;
//// 		}
//		ret = ret*j;
//		sum = sum + ret;
//	}
//	
//	printf("%d\n", sum);
//	return 0;
//}
//
//int main()
//{
//	int arr[1024][1024] = {0};
//	int i = 0;
//	int j = 0;
//	int sum = 0;
//	int start = 0;
//	int end = 0;
//	start = GetTickCount();
//	for(i=0; i<5; i++)
//	{
//		for(j=0; j<100; j++)
//		{
//			sum  = sum + arr[i][j];
//		}
//	}
//	end = GetTickCount();
//	printf("%d\n", end-start);
//	start = GetTickCount();
//	for(i=0; i<100; i++)
//	{
//		for(j=0; j<5; j++)
//		{
//			sum = sum + arr[j][i];
//		}
//	}
//	end = GetTickCount();
//	printf("%d\n", end-start);
//
//	return 0;
//}
//
//int main()
//{
//	int i = 0;
//	do
//	{
//		printf("%d\n", i);
//		if(i == 5)
//			continue;
//		i = i+1;
//	}
//	while(i<10);
//
//	return 0;
//}
//


//
//int main()
//{
//	int ch = 0;
//	int count = 0;
//	//{}{}}{
//	//}{
//	//}}{{
//	//{{{}}}}{
//	//{{}}
//
//	while((ch=getchar()) != EOF)
//	{
//		if(ch == '{')
//			count++;
//		else if(ch == '}' && count==0)
//		{
//			printf("不匹配\n");
//			return 0;
//		}
//		else if(ch == '}')
//		{
//			count--;
//		}
//	}
//	if(count == 0)
//	{
//		printf("匹配\n");
//	}
//	else
//	{
//		printf("不匹配\n");
//	}
//	return 0;
//}

// int main()
// {
// 	int a = 0;
// 	int n = 0;
// 	int sum = 0;
// 	int i = 0;
// 	int tmp = 0;
// 	scanf("%d%d", &a, &n);
// 	for(i=0; i<n; i++)
// 	{
// 		tmp = tmp*10+a;
// 		sum  = sum + tmp;
// 	}
// 	printf("sum = %d\n", sum);
// 	return 0;
// }

//
//1111111111111111111111111111111111
//2222222222222222222222222222222222
//大数运算
//

//
//int main()
//{
//	int i = 0;
//	for(i=0; i<=10000000; i++)
//	{
//		int count = 1;
//		int tmp = i;
//		int sum = 0;
//		//计算i是几位数
//		//123
//		while(tmp>9)
//		{
//			count++;
//			tmp = tmp/10;
//		}
//		//得到i的每一位，计算
//		tmp = i;
//		while(tmp)
//		{
//			sum  = sum + pow(tmp%10, count);
//			tmp = tmp/10;
//		}
//		if(sum == i)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	int n = 0;
//	int i  =0;
//	scanf("%d", &n);
//	//打印上半部分
//	for(i=0; i<n; i++)
//	{
//		//打印一行
//		//打印空格
//		int j = 0;
//		for(j=0; j<n-1-i; j++)
//		{
//			printf(" ");
//		}
//		//打印*
//		for(j=0; j<2*i+1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	//打印下半部分
//	for(i=0; i<n-1; i++)
//	{
//		int j = 0;
//		for(j=0; j<i+1; j++)
//		{
//			printf(" ");
//		}
//		for(j=0; j<2*(n-1-i)-1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}
