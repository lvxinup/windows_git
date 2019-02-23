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


SListNode* BuySListNode(DataType x)//创建单链表
{
	SListNode *Node;
	Node = (SListNode *)malloc(sizeof(SListNode));
	if (Node)
	{
		Node->_data = x;
		Node->_next = NULL;
		return Node;
	}
}
void SListPrint(SListNode* pHead)//打印单链表
{
	SListNode* cur = pHead;
	while (cur != NULL)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL");
	printf("\n");
}
void SListDestory(SListNode** ppHead)//销毁单链表
{
	free(* ppHead);
	*ppHead = NULL;
}
//
void SListPushBack(SListNode** ppHead, DataType x)//尾部插入
{
	SListNode *cur = *ppHead;;
	if ((*ppHead) == NULL)
	{
		*ppHead = BuySListNode(x);
	}
	else
	{
		while (cur->_next!=NULL)//找到尾结点
		{
			cur = cur->_next;//
		}
		cur->_next = BuySListNode(x);//在尾结点插入
	}

}
void SListPopBack(SListNode** ppHead)//尾部删除
{
	SListNode *cur = *ppHead;;
	if ((*ppHead) == NULL)
	{
		return;
	}
	else
	{
		while (cur->_next->_next != NULL)//找到尾结点
		{
			cur = cur->_next;
		}
		cur->_next = NULL;
	}
}
void SListPushFront(SListNode** ppHead, DataType x)//头部插入
{
	if (*ppHead == NULL)
	{
		*ppHead = BuySListNode(x);
	}
	else
	{
		SListNode * Newnode = BuySListNode(x);
		Newnode->_next = *ppHead;
		*ppHead = Newnode;
	}
}
void SListPopFront(SListNode** ppHead)//头部删除
{
	SListNode *cur = *ppHead;
	if (*ppHead == NULL)
	{
		return;
	}
	else
	{
		if (cur->_next != NULL)
		{
			cur = cur->_next;
		}
		*ppHead = cur;
	}
}
SListNode* SListFind(SListNode* pHead, DataType x)//查找
{
	SListNode* cur = pHead;
	if (pHead == NULL)
	{
		return 0;
	}
	else
	{
		while (cur->_next != NULL)//判断循环终点
		{
			if (cur->_data == x)
			{
				return cur;
			}
			cur = cur->_next;
		}
		return -1;
	}
}
void SListInsest(SListNode** ppHead, SListNode* pos, DataType x)//在pos位置插入元素x
{
	SListNode *cur = *ppHead;
	if (*ppHead == NULL)
	{
		return;
	}
	else
	{
		if (cur->_next == pos)
		{
			cur->_next=pos;
			pos->_data = x;
			pos = cur->_next->_next;
		}
	}
}
void SListErase(SListNode** ppHead, SListNode* pos)//删除pos位置上的元素
{
	SListNode *cur = *ppHead;
	if (*ppHead == NULL)
	{
		return;
	}
	else
	{
		if (cur->_next == pos)
		{
			cur->_next = cur->_next->_next;
		}
	}
}
void SListbubblesort(SListNode** ppHead)//冒泡排序
{
	int count = sizeof(*ppHead);
	SListNode *cur = *ppHead;
	if (*ppHead == NULL)
	{
		return;
	}
	else
	{
		while (count>1)
		{
			while (cur->_next != NULL)
			{
				if (cur->_data > cur->_next->_data)
				{
					int tmp = 0;
					tmp = cur->_data;
					cur->_data = cur->_next->_data;
					cur->_next->_data = tmp;

				}
				cur = cur->_next;
			}
			count--;
			cur = *ppHead;//重新定义头节点
		}
		
	}
}