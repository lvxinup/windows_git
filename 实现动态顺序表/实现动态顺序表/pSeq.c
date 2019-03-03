#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include<Windows.h>


typedef int DataType;

typedef struct SeqList
{
	DataType* _a;//数据块指针
	size_t _size; // 有效数据个数 
	size_t _capacity; // 容量 
}SeqList, *PSeqList;

void SeqPrint(SeqList* pSeq)//打印
{
	int i = 0;
	assert(pSeq != NULL);
	for (i = 0; i<pSeq->_size; i++)
	{
		printf("%d ", pSeq->_a[i]);
	}
	printf("\n");
}
void SeqInit(SeqList* pSeq)//创建
{
	pSeq-> _size = 0;
	pSeq->_capacity = 5;
	pSeq->_a = (DataType*)malloc(pSeq->_capacity*sizeof(DataType));
	if (pSeq->_a == NULL)
	{
		printf("顺序表初始化失败");
	}
}
void SeqDestory(SeqList* pSeq)//销毁
{
	if (pSeq->_a == NULL)
	{
		printf("顺序表初始化失败");
	}
	pSeq->_capacity = 0;
}
void SeqPushBack(SeqList* pSeq, DataType x)//尾部插入
{
	if (pSeq->_a == NULL)
	{
		printf("顺序表初始化失败");
	}
	assert(pSeq != NULL);
	pSeq->_a[pSeq->_size] = x;
	pSeq->_size++;
}
void SeqPopBack(SeqList* pSeq)//尾部删除
{	
	assert(pSeq != NULL);
	if (pSeq->_size == 0)
	{
		return;
	}
	pSeq->_size--;
}
void SeqPushFront(SeqList* pSeq, DataType x)//头部插入
{
	assert(pSeq !=  NULL);
	int i = 0;
	pSeq->_size++;
	for (i = pSeq->_size; i > 0; i--)
	{
		pSeq->_a[i] = pSeq->_a[i - 1];//所有数据向右挪动
	}
	pSeq->_a[0] = x;
}
void SeqPopFront(SeqList* pSeq)//头部删除
{
	assert(pSeq != NULL);
	if (pSeq->_size == 0)
	{
		return;
	}
	int i = 0;
	for (i = 0; i < pSeq->_size; i++)
	{
		pSeq->_a[i] = pSeq->_a[i + 1];//所有数据向左挪动
	}
	pSeq->_size--;
}

void SeqInsert(SeqList* pSeq, size_t pos, DataType x)//在顺序表的pos位置上插入元素x
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
void SeqErase(SeqList* pSeq, size_t pos)//删除顺序表pos位置上的元素
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		printf("顺序表里没有数据元素\n");
		return;
	}
	int i = 0;
	for (i = pos ; i < pSeq->_size; i++)
	{
		pSeq->_a[i] = pSeq->_a[i + 1];
	}
	pSeq->_size--;
}

int SeqFind(SeqList* pSeq, DataType x)//顺序表中查找数据x，返回该元素在顺序表中的位置
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
void SeqAt(SeqList* pSeq, size_t pos, DataType x)//修改pos位置的数据
{
	assert(pSeq != NULL);
	if (pSeq->_size == 0)
	{
		return;
	}
	pSeq->_a[pos] = x;

}
void BubbleSort(SeqList* pSeq)//冒泡排序
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

void SelectSort(SeqList* pSeq)//选择排序
{
	assert(pSeq != NULL);
	if (pSeq->_size == 0)
	{
		return;
	}
	int j = 0;//控制有序数列的排序
	int i = 0;//控制无序数列比较出最大值
	int min = 0;
	int temp = 0;
	for (i = 0; i < pSeq->_size ; i++)    //控制有序数列的排序
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
int BinarySearch(SeqList* pSeq, DataType x)//查找已排序顺序表中的元素x
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