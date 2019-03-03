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
}SeqList;

void SeqPrint(SeqList* pSeq);//打印
void SeqInit(SeqList* pSeq);//创建
void SeqDestory(SeqList* pSeq);//销毁

void SeqPushBack(SeqList* pSeq, DataType x);//尾部插入
void SeqPopBack(SeqList* pSeq);//尾部删除
void SeqPushFront(SeqList* pSeq, DataType x);//头部插入
void SeqPopFront(SeqList* pSeq);//头部删除

void SeqInsert(SeqList* pSeq, size_t pos, DataType x);//在顺序表的pos位置上插入元素x
void SeqErase(SeqList* pSeq, size_t pos);//删除顺序表pos位置上的元素

int SeqFind(SeqList* pSeq, DataType x);//顺序表中查找数据x，返回该元素在顺序表中的位置
void SeqAt(SeqList* pSeq, size_t pos, DataType x); //修改pos位置的数据

void BubbleSort(SeqList* pSeq);//冒泡排序
void SelectSort(SeqList* pSeq);//选择排序
int BinarySearch(SeqList* pSeq, DataType x);//查找已排序顺序表中的元素x