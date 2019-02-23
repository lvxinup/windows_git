#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>
#include <assert.h>
#include <malloc.h>

typedef int DataType;

typedef struct SListNode//定义结点类型
{
	struct SListNode* _next;//指向链表中下一个节点
	DataType _data;//当前结点所保存的元素
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