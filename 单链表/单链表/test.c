#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>
#include <assert.h>
#include <malloc.h>

typedef int DataType;

typedef struct SListNode//����������
{
	struct SListNode* _next;//ָ����������һ���ڵ�
	DataType _data;//��ǰ����������Ԫ��
}SListNode;

int main()
{
	SListNode* Node=NULL;
	SListNode * Newnode;
	SListNode* number;

	SListPushBack(&Node, 1);
	SListPushBack(&Node, 2);
	SListPushBack(&Node, 3);
	SListPushBack(&Node, 4);
	SListPrint(Node);
	printf("\n");
	SListPushFront(&Node, 5);
	SListPushFront(&Node, 6);
	SListPushFront(&Node, 7);
	SListPushFront(&Node, 8);
	SListPrint(Node);
	printf("\n");
	SListPopFront(&Node);
	SListPopFront(&Node);
	SListPrint(Node);
	printf("\n");
	SListPopBack(&Node);
	SListPopBack(&Node);
	SListPrint(Node);
	printf("\n");
	number=SListFind(Node, 5);
	printf("%d\n", number->_data);
	SListInsest(&Node,number,9);
	SListPrint(Node);
	printf("\n");
	SListErase(&Node, number);
	SListPrint(Node);
	printf("\n");
	SListPushBack(&Node, 3);
	SListPushBack(&Node, 4);
	SListPushBack(&Node, 2);
	SListPushBack(&Node, 5);
	SListbubblesort(&Node);
	SListPrint(Node);
	printf("\n");
	SListDestory(&Node);

	system("pause");
	return 0;
}