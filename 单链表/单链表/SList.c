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


SListNode* BuySListNode(DataType x)//����������
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
void SListPrint(SListNode* pHead)//��ӡ������
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
void SListDestory(SListNode** ppHead)//���ٵ�����
{
	free(* ppHead);
	*ppHead = NULL;
}
//
void SListPushBack(SListNode** ppHead, DataType x)//β������
{
	SListNode *cur = *ppHead;;
	if ((*ppHead) == NULL)
	{
		*ppHead = BuySListNode(x);
	}
	else
	{
		while (cur->_next!=NULL)//�ҵ�β���
		{
			cur = cur->_next;//
		}
		cur->_next = BuySListNode(x);//��β������
	}

}
void SListPopBack(SListNode** ppHead)//β��ɾ��
{
	SListNode *cur = *ppHead;;
	if ((*ppHead) == NULL)
	{
		return;
	}
	else
	{
		while (cur->_next->_next != NULL)//�ҵ�β���
		{
			cur = cur->_next;
		}
		cur->_next = NULL;
	}
}
void SListPushFront(SListNode** ppHead, DataType x)//ͷ������
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
void SListPopFront(SListNode** ppHead)//ͷ��ɾ��
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
SListNode* SListFind(SListNode* pHead, DataType x)//����
{
	SListNode* cur = pHead;
	if (pHead == NULL)
	{
		return 0;
	}
	else
	{
		while (cur->_next != NULL)//�ж�ѭ���յ�
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
void SListInsest(SListNode** ppHead, SListNode* pos, DataType x)//��posλ�ò���Ԫ��x
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
void SListErase(SListNode** ppHead, SListNode* pos)//ɾ��posλ���ϵ�Ԫ��
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
void SListbubblesort(SListNode** ppHead)//ð������
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
			cur = *ppHead;//���¶���ͷ�ڵ�
		}
		
	}
}