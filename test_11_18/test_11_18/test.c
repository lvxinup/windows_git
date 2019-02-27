#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//welcome to bit.
//###############
//w#############.
//we###########t.
//wel#########it.
//...
//welcome to bit.
#include <windows.h>
//"123456"
int main()
{
	int i = 0;
	char passwd[10] = {0};
	//for(i=0; i<3; i++)
	//{
	//	printf("请输入密码:>");
	//	scanf("%s", passwd);
	//	if(strcmp(passwd, "123456") == 0)
	//	{
	//		printf("登录成功\n");
	//		break;
	//	}
	//	else
	//	{
	//		printf("密码错误， 请重新输入！\n");
	//	}
	//}
	//if(i == 3)
	//{
	//	printf("三次密码输入错误, 退出系统\n");
	//	exit(1);
	//}
	return 0;
}

//
//int main()
//{
//	char arr1[] = "###############";
//	char arr2[] = "welcome to bit.";
//	int left = 0;
//	int right = strlen(arr1)-1;
//	printf("%s\n", arr1);
//	while(left<=right)
//	{
//		Sleep(1000);
//		arr1[left] = arr2[left];
//		arr1[right] = arr2[right];
//		left++;
//		right--;
//		printf("%s\n", arr1);
//	}
//	return 0;
//}
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for(i=0,j=0; i<2, j<5; i++, j++)
//	{
//		printf("hehe\n");
//	}
//	return 0;
//}
//int main()
//{
//// 	int i = 0;
//// 	int j = 0;
//// 	for(i=0; i<10; i++)
//// 	{
//// 		for(j=0; j<10; j++)
//// 		{
//// 			printf("hehe\n");
//// 		}
//// 	}
//	int i = 0;
//	for(i=100; i<201; i++)
//	{
//
//	}
//	//int arr[10] = {0};
//	//int sz = 10;
//	//for(i=0; i<=9; i++)
//	//{
//	//	arr[i] = 1;
//	//	printf("hehe\n");
//	//}
//	return 0;
//}
//
//int main()
//{
//// 	int i = 0;
//// 
//// 	while(i<10)
//// 	{
//// 		printf("hehe\n");
//// 		i = i+1;
//// 	}
//	int i = 0;
//	for(i=0; i<10; i++)
//	{
//		//printf("hehe\n");
//		if(i == 5)
//			continue;
//		printf("%d ", i);
//	}
//
//	return 0;
//}

//
//int main()
//{
//	int ch = 0;
//	char passwd[10] = {0};
//	printf("请输入密码:>");
//	scanf("%s", passwd);
//	printf("%s\n", passwd);
//	printf("请确认(Y/N)>:");
//	//fflush(stdin);
//	while(((ch=getchar()) != '\n') && (ch != EOF))
//	{
//		;
//	}
//	ch = getchar();
//	if(ch == 'Y')
//	{
//		printf("确认成功\n");
//	}
//	else
//	{
//		printf("确认失败\n");
//	}
//	//end of file
//	/*while((ch=getchar()) !=EOF)
//	{
//		putchar(ch);
//	}*/
//	//system("pause");
//// 	fflush(stdin);
//// 	getchar();
//	return 0;
//}

//int main()
//{
//	//int i = 0;
//	//while(i == 0)
//	//{
//	//	printf("hehe\n");
//	//}
//
//	int i = 1;//初始化
//
//
//
//	while(i<=10)//判断
//	{
//		if(i == 5)
//			continue;
//		printf("%d\n", i);
//		i = i+1;//调整部分
//	}
//	return 0;
//}
//int main()
//{
//flag:
//	printf("hehe\n");
//	goto flag;
//	return 0;
//}
////
//int main()
//{
////	char input[10] = {0};
////	system("shutdown -s -t 60");
////flag:
////	printf("电脑在1分钟内关机，如果输入：我是猪, 就取消关机\n");
////	scanf("%s", input);
////	if(strcmp(input, "我是猪") == 0)
////	{
////		system("shutdown -a");
////	}
////	else
////	{
////		goto flag;
////	}
//	//char input[10] = {0};
//	//system("shutdown -s -t 60");
//	//while(1)
//	//{
//	//	printf("电脑在1分钟内关机，如果输入：我是猪, 就取消关机\n");
//	//	scanf("%s", input);
//	//	if(strcmp(input, "我是猪") == 0)
//	//	{
//	//		system("shutdown -a");
//	//		break;
//	//	}
//	//}
//	return 0;
//}
//
//#include <stdio.h>
//int main()
//{
//	int n = 1;
//	int m = 2;
//	switch (n)
//	{
//	case 1:	m++;//m=3
//	case 2:	n++;//n=2
//	case 3://
//		switch (n)
//		{//switch允许嵌套使用
//		case 1:	n++;
//		case 2:	m++;	n++;break;//m=4,n=3
//		}
//	case 4://
//		m++;//m=5
//		break;
//	default:
//		break;
//	}
//
//	printf("m = %d, n = %d\n", m, n);
//	return 0;
//}

//
//int main()
//{
//	int day = 0;
//	int n = 1;
//	scanf("%d", &day);//5
//	switch(day)//整型表达式
//	{
//	case 1://整型常量表达式
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("workday\n");
//		break;
//	case 6:
//	case 7:
//		printf("weekend\n");
//		break;
//	default:
//		printf("输入错误\n");
//		break;
//	}
//	//
//	return 0;
//}



//
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for(i=1; i<100; i++)
//	{
//		if(i%10 == 9)
//			count++;
//		if(i/10==9)
//			count++;
//	}
//	printf("count = %d\n", count);
//	return 0;
//}

// int main()
// {
// 	int i = 0;
// 	double sum = 0.0;
// 	int flag = 1;
// 	for(i=1; i<=100; i++)
// 	{
// 		sum  = sum + flag*1.0/i;
// 		flag = -flag;
// 		//if(i%2==0)
// 		//{
// 		//	sum  = sum - 1.0/i;
// 		//}
// 		//else
// 		//{
// 		//	sum  = sum + 1.0/i;
// 		//}
// 	}
// 	printf("%lf\n", sum);
// 	return 0;
// }
//
//int main()
//{
//	int arr1[] = {1,2,3,4,5};
//	int arr2[] = {2,3,4,5,6};
//	int i = 0;
//
//	for(i=0; i<sizeof(arr1)/sizeof(arr1[0]); i++)
//	{
//		int tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//
//	return 0;
//}


