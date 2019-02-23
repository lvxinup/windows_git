#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>
#include<malloc.h>

typedef int DataType;

typedef struct DListNode
{
	struct DListNode* _next;
	struct DListNode* _prev;
	DataType _data;
}DListNode;


DListNode* BuyDListNode(DataType x)
{
	DListNode* DListNode;
	DListNode = (DataType*)malloc(sizeof(DataType));
	if (DListNode != NULL)
	{
		DListNode->_next = NULL;
		DListNode->_prev = NULL;
		DListNode->_data = x;
	}
	return DListNode;
}
DListNode* DListInit()
{

}
void DListDestory(DListNode* head)
{
	free(head);
	head = NULL;
}
void DListPrint(DListNode* head)
{
	DListNode* cur = head;
	while (cur)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("\n");	
}

void DListPushBack(DListNode* head, DataType x);
void DListPushFront(DListNode* head, DataType x);
void DListPopBack(DListNode* head);
void DListPopFront(DListNode* head);

DListNode* DListFind(DListNode* head, DataType x);
void DListInsert(DListNode* pos, DataType x);
void DListErase(DListNode* pos);

void DListPrint(DListNode* head);
DListNode* DListInit();

void TestDList1()
{
	DListNode* list = DListInit();
	DListPushBack(list, 1);
	DListPushBack(list, 2);
	DListPushBack(list, 3);
	DListPushBack(list, 4);
	DListPushBack(list, 5);
	DListPrint(list);

	DListPopBack(list);
	DListPopBack(list);
	DListPopBack(list);
	DListPopBack(list);
	DListPopBack(list);
	DListPrint(list);
}

void TestDList2()
{
	DListNode* list = DListInit();
	DListPushFront(list, 1);
	DListPushFront(list, 2);
	DListPushFront(list, 3);
	DListPushFront(list, 4);
	DListPushFront(list, 5);
	DListPrint(list);

	DListPopFront(list);
	DListPopFront(list);
	DListPopFront(list);
	DListPopFront(list);
	DListPopFront(list);
	DListPrint(list);
}

int main()
{

	system("pause");
	return 0;
}