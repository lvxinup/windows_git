#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include<Windows.h>


typedef int DataType;

typedef struct SeqList
{
	DataType* _a;//���ݿ�ָ��
	size_t _size; // ��Ч���ݸ��� 
	size_t _capacity; // ���� 
}SeqList, *PSeqList;

void SeqPrint(SeqList* pSeq)//��ӡ
{
	int i = 0;
	assert(pSeq != NULL);
	for (i = 0; i<pSeq->_size; i++)
	{
		printf("%d ", pSeq->_a[i]);
	}
	printf("\n");
}
void SeqInit(SeqList* pSeq)//����
{
	pSeq-> _size = 0;
	pSeq->_capacity = 5;
	pSeq->_a = (DataType*)malloc(pSeq->_capacity*sizeof(DataType));
	if (pSeq->_a == NULL)
	{
		printf("˳����ʼ��ʧ��");
	}
}
void SeqDestory(SeqList* pSeq)//����
{
	if (pSeq->_a == NULL)
	{
		printf("˳����ʼ��ʧ��");
	}
	pSeq->_capacity = 0;
}
void SeqPushBack(SeqList* pSeq, DataType x)//β������
{
	if (pSeq->_a == NULL)
	{
		printf("˳����ʼ��ʧ��");
	}
	assert(pSeq != NULL);
	pSeq->_a[pSeq->_size] = x;
	pSeq->_size++;
}
void SeqPopBack(SeqList* pSeq)//β��ɾ��
{	
	assert(pSeq != NULL);
	if (pSeq->_size == 0)
	{
		return;
	}
	pSeq->_size--;
}
void SeqPushFront(SeqList* pSeq, DataType x)//ͷ������
{
	assert(pSeq !=  NULL);
	int i = 0;
	pSeq->_size++;
	for (i = pSeq->_size; i > 0; i--)
	{
		pSeq->_a[i] = pSeq->_a[i - 1];//������������Ų��
	}
	pSeq->_a[0] = x;
}
void SeqPopFront(SeqList* pSeq)//ͷ��ɾ��
{
	assert(pSeq != NULL);
	if (pSeq->_size == 0)
	{
		return;
	}
	int i = 0;
	for (i = 0; i < pSeq->_size; i++)
	{
		pSeq->_a[i] = pSeq->_a[i + 1];//������������Ų��
	}
	pSeq->_size--;
}

void SeqInsert(SeqList* pSeq, size_t pos, DataType x)//��˳����posλ���ϲ���Ԫ��x
{
	assert(pSeq != NULL);
	if (pSeq->_size == 0)
	{
		return;
	}
	pSeq->_size++;
	int i = 0;
	for (i = pSeq->_size; i > pos; i--)
	{
		pSeq->_a[i] = pSeq->_a[i - 1];
	}
	pSeq->_a[pos] = x;
}
void SeqErase(SeqList* pSeq, size_t pos)//ɾ��˳���posλ���ϵ�Ԫ��
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		printf("˳�����û������Ԫ��\n");
		return;
	}
	int i = 0;
	for (i = pos ; i < pSeq->_size; i++)
	{
		pSeq->_a[i] = pSeq->_a[i + 1];
	}
	pSeq->_size--;
}

int SeqFind(SeqList* pSeq, DataType x)//˳����в�������x�����ظ�Ԫ����˳����е�λ��
{
	assert(pSeq != NULL);
	if (pSeq->_size == 0)
	{
		return;
	}
	int i = 0;
	for (i = 0; i < pSeq->_size; i++)
	{
		if (x == pSeq->_a[i])
			return i+1;
	}
}
void SeqAt(SeqList* pSeq, size_t pos, DataType x)//�޸�posλ�õ�����
{
	assert(pSeq != NULL);
	if (pSeq->_size == 0)
	{
		return;
	}
	pSeq->_a[pos] = x;

}
void BubbleSort(SeqList* pSeq)//ð������
{
	assert(pSeq != NULL);
	if (pSeq->_size == 0)
	{
		return;
	}
	int j = 0;
	int i = 0;
	int temp = 0;
	for (i = 0; i < pSeq->_size-1; i++)
	{
		for (j = 0; j < pSeq->_size - i - 1; j++)
		{
			if (pSeq->_a[j] < pSeq->_a[j + 1])
			{
				temp = pSeq->_a[j];
				pSeq->_a[j] = pSeq->_a[j + 1];
				pSeq->_a[j + 1] = temp;
			}
		}
	}
}

void SelectSort(SeqList* pSeq)//ѡ������
{
	assert(pSeq != NULL);
	if (pSeq->_size == 0)
	{
		return;
	}
	int j = 0;//�����������е�����
	int i = 0;//�����������бȽϳ����ֵ
	int min = 0;
	int temp = 0;
	for (i = 0; i < pSeq->_size ; i++)    //�����������е�����
	{
		min = i;
		for (j = i + 1; j < pSeq->_size; j++)
		{
			if (pSeq->_a[j] > pSeq->_a[min])
				min = j;
			if (pSeq->_a[j] < pSeq->_a[min])
			{
				temp = pSeq->_a[j];
				pSeq->_a[j] = pSeq->_a[min];
				pSeq->_a[min] = temp;
			}
		}
	}
}
int BinarySearch(SeqList* pSeq, DataType x)//����������˳����е�Ԫ��x
{
	assert(pSeq != NULL);
	if (pSeq->_size == 0)
	{
		return;
	}
	int i = 0;
	for (i = 0; i < pSeq->_size; i++)
	{
		if (x == pSeq->_a[i])
			return i;
	}
	return -1;
}