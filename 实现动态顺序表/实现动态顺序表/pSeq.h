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
}SeqList;

void SeqPrint(SeqList* pSeq);//��ӡ
void SeqInit(SeqList* pSeq);//����
void SeqDestory(SeqList* pSeq);//����

void SeqPushBack(SeqList* pSeq, DataType x);//β������
void SeqPopBack(SeqList* pSeq);//β��ɾ��
void SeqPushFront(SeqList* pSeq, DataType x);//ͷ������
void SeqPopFront(SeqList* pSeq);//ͷ��ɾ��

void SeqInsert(SeqList* pSeq, size_t pos, DataType x);//��˳����posλ���ϲ���Ԫ��x
void SeqErase(SeqList* pSeq, size_t pos);//ɾ��˳���posλ���ϵ�Ԫ��

int SeqFind(SeqList* pSeq, DataType x);//˳����в�������x�����ظ�Ԫ����˳����е�λ��
void SeqAt(SeqList* pSeq, size_t pos, DataType x); //�޸�posλ�õ�����

void BubbleSort(SeqList* pSeq);//ð������
void SelectSort(SeqList* pSeq);//ѡ������
int BinarySearch(SeqList* pSeq, DataType x);//����������˳����е�Ԫ��x