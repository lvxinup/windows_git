#include "pSeq.h"

void test1()
{
	SeqList SeqList;
	SeqInit(&SeqList);
	SeqPushBack(&SeqList, 1);
	SeqPushBack(&SeqList, 2);
	SeqPushBack(&SeqList, 3);
	SeqPushBack(&SeqList, 4);
	SeqPrint(&SeqList);
	SeqPopBack(&SeqList);
	SeqPrint(&SeqList);

	SeqDestory(&SeqList);
}
void test2()
{
	SeqList SeqList;
	SeqInit(&SeqList);
	SeqPushFront(&SeqList, 1);
	SeqPushFront(&SeqList, 2);
	SeqPushFront(&SeqList, 3);
	SeqPushFront(&SeqList, 4);
	SeqPrint(&SeqList);
	SeqPopFront(&SeqList);
	SeqPrint(&SeqList);
	SeqPopFront(&SeqList);
	SeqPrint(&SeqList);

	SeqDestory(&SeqList);
}
void test3()
{
	int bos = 0;
	SeqList SeqList;
	SeqInit(&SeqList);
	SeqPushFront(&SeqList, 1);
	SeqPushFront(&SeqList, 2);
	SeqPushFront(&SeqList, 3);
	SeqPushFront(&SeqList, 4);

	bos = SeqFind(&SeqList, 1);
	if (bos == -1)
	{
		printf("要查找的元素不存在\n");
	}
	else
	{
		SeqInsert(&SeqList, 2, bos);
	}
	SeqPrint(&SeqList);
	SeqErase(&SeqList, 2);
	SeqPrint(&SeqList);
	SeqAt(&SeqList, 2, 9);
	SeqPrint(&SeqList);

	SeqDestory(&SeqList);

}
void test4()
{
	int bos = 0;
	SeqList SeqList;
	SeqInit(&SeqList);
	SeqPushFront(&SeqList, 3);
	SeqPushFront(&SeqList, 2);
	SeqPushFront(&SeqList, 3);
	SeqPushFront(&SeqList, 4);
	SeqPushFront(&SeqList, 3);
	SeqPushFront(&SeqList, 1);
	SeqPrint(&SeqList);
	printf("\n");
	BubbleSort(&SeqList);
	SeqPrint(&SeqList);
	bos = BinarySearch(&SeqList, 4);
	printf("%d\n", bos);
	printf("\n");
	SelectSort(&SeqList);
	SeqPrint(&SeqList);
	bos = BinarySearch(&SeqList, 4);
	printf("%d\n", bos);


	SeqDestory(&SeqList);
}

int main()
{
	test1();
	test2();
	test3();
	test4();

	system("pause");
	return 0;
}
