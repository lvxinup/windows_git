#define  _CRT_SECURE_NO_WARNINGS 1

/*�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ� 
��һ��������Ϊ4�����ɷ��Ĺ��ʡ� 
A˵�������ҡ� 
B˵����C�� 
C˵����D�� 
D˵��C�ں�˵ 
��֪3����˵���滰��1����˵���Ǽٻ��� 
�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�*/

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