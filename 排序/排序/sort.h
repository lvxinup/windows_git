#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>
#include<assert.h>

//��������
void InsertSort(int* array,size_t n);     //ֱ�Ӳ�������
void HillSort(int* array, size_t n);         //ϣ������
//ѡ������
void SelectSort(int* array, size_t n);	   //ѡ������
void HeapSort(int* array, size_t n);         //������
//��������
void BubbleSort(int* array, size_t n);	   //ð������
void QuickSort(int* array, int left, int right); //��������
//�鲢����-
void MergerSort(int* arrray, size_t n);	   //�鲢����
//��������
void CountSort(int* array, size_t n);	   //��������

void Swap(int *a1, int *a2)
{
	int c = *a1;
	*a1 = *a2;
	*a2 = c;
}
void InsertSort(int* array, size_t n)       //ֱ�Ӳ�������
{
	assert(array);
	int end = 0;
	for (int i = 0; i < n-1; ++i)
	{
		end = i;
		int tmp = array[end + 1];   //end+1ΪҪ���������
		while (end >= 0 && array[end]>tmp)    //�ҵ�tmp�Ĳ���λ��
		{
			//������������ں�ǰ�������������ݽ��бȽ���С��
			//������end=-1,��ôҲ���Թ�Ϊ[end+1]=[-1+1]=tmp;
			array[end + 1] = array[end];//�������������ƶ�	
			end--;
		}
		array[end + 1] = tmp;
	}
}
void HillSort(int* array, size_t n)         //ϣ������
{
	assert(array);
	int end = 0;
	int gap = n;   //���
	while (gap > 1) // �������0����Ϊ��ѭ��
	{
		gap = gap / 3 + 1;   //������Сgap,ʹ����ӽ�����.   ��1ʹ�����һ��Ϊֱ�Ӳ�������
		for (int i = 0; i < n- gap; ++i)    //ѭ����������Ϊ n-gap �������һ��gap���ö�Ӧ���һ��ֵ
		{
			end = i;
			int tmp = array[end + gap];
			while (end >= 0 && array[end]>tmp)  //�ҵ�tmp �Ĳ���λ��
			{
				array[end + gap] = array[end];   //������������ƶ�
				end = end - gap;
			}
			array[end + gap] = tmp;//endС��0����array[end]<tmp��tmp��array[end+gap]����
		}
	}
}

void SelectSort(int* array, size_t n)	   //ѡ������
{
	size_t min = 0;
	size_t temp = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)    //�ҵ�cur֮�� �������е���Сֵ
		{
			if (array[j] < array[min])
			{
				min = j;
			}

		}	
		if (min != i)
			{
				temp = array[i];
				array[i] = array[min];
				array[min] = temp;
			}
	}
}
void HeapAdjustDown(int* array, size_t n,int parent) //���µ���
{
	int temp = 0;
	int child = parent * 2 + 1;//����
	while (child < n)
	{
		if (child + 1 < n && array[child] < array[child + 1])
		{
			++child;
		}
		if (array[child]>array[parent])
		{
			temp = array[child];
			array[child] = array[parent];
			array[parent] = temp;
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* array, size_t n)         //������
{
	assert(array);
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		HeapAdjustDown(array, n, i);
		
	}
	size_t end = n - 1;
	while (end > 0)
	{
		int temp = 0;
		temp = array[0];
		array[0] = array[end];
		array[end] = temp;
		HeapAdjustDown(array, end, 0);
		--end;
	}
}

void BubbleSort(int* array, size_t n)	   //ð������
{
	int i, j = 0;
	int temp = 0;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (array[i]>array[j])
			{

				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}
int GetMid(int* array, int left, int right)                //����ȡ�з�
{
	int mid = left + ((right - left) >> 1);
	if (array[left] < array[mid])//�����С
	{
		if (array[mid] < array[right])
			return mid;//mid����λ�� 
		else if (array[left] > array[right])
			return right;
		else
			return left;
	}
	else
	{
		if (array[mid] > array[right])
			return mid;
		else if (array[left] > array[right])
			return right;
		else
			return left;
	}
}
int PartSort1(int* array, int left, int right)       //����ָ�뷨
{
	assert(array);
	int begin = left;
	int end = right;
	int mid = GetMid(array, left, right);
	Swap(&array[mid], &array[right]);
	int key = array[right];
	while (begin < end)
	{
		while (array[begin] <= key && begin < end)//begin�Ҵ�
		{
			begin++;
		}
		while (array[end] >= key && begin < end)//end��С
		{
			end--;
		}
		if (begin < end)
		{
			Swap(&array[begin], &array[end]);
		}      //begin  end �����󣬰�key��������λ����
	}
	Swap(&array[begin], &array[right]);//begin  end �����󣬰�key��������λ����
	return begin;
}
int PartSort2(int* array, int left, int right)      //�ڿӷ�
{
	assert(array);
	int begin = left;
	int end = right;
	int key = array[right];
	while (begin < end)
	{
		while (array[begin] <= key && begin < end)
		{
			begin++;
		}
		array[end] = array[begin];	  //�ӱ�Ϊbegin
		while (array[end] >= key && begin < end)
		{
			end--;
		}
		array[begin] = array[end];     // �ӱ�Ϊend
	}
	array[begin] = key;               //���
	return begin;
}
int PartSort3(int* array, int left, int right)    //ǰ��ָ��
{
	assert(array);
	int prev = left - 1;
	int cur = left;
	int key = array[right];
	while (cur < right)
	{
		if (array[cur] < key && ++prev != cur)
		{
			Swap(&array[cur], &array[prev]);
		}
		++cur;
	}
	Swap(&array[++prev], &array[right]);
	return prev;
}
void QuickSort(int* array, int left, int right)	       //��������
{
	assert(array);
	if (left >= right)
		return;
	//int div = PartSort1(array, left, right);
	//int div = PartSort2(array, left, right);
	int div = PartSort3(array, left, right);
	printf("div:%d\n", div);
	//left div-1
	QuickSort(array, left, div - 1);
	//div+1  right
	QuickSort(array, div + 1, right);
}
//void _MergerSort(int* array, int left, int right, int *tmp)
//{
//	//����
//	if (left >= right)    //�������ʱ��ֱ�ӷ���
//		return;
//	if (right - left + 1 < 20)
//	{
//		InsertSort(array + left, right - left + 1);//С�����Ż��������ݸ�������������Ҫ��1��С��20ʱ��ֱ�Ӳ�������
//		return;
//	}
//	int mid = left + (right - left) / 2;
//	_MergerSort(array, left, mid, tmp);//����߻�������
//	_MergerSort(array, right, mid, tmp);//���ұ߻�������
//
//	//�鲢
//	int begin1 = left, end1 = mid;
//	int begin2 = mid + 1, end2 = right;
//	int index = left;
//	while (begin1 < end1 && begin2 < end2)  //������������ĺϲ�
//	{
//		if (array[begin1] <= array[begin2])
//		{
//			tmp[index] = array[begin1];
//			index++;
//			begin1++;
//		}
//		else
//		{
//			tmp[index] = array[begin2];
//			index++;
//			begin2++;
//		}
//	}
//	if (begin1 > end1)//˵��begin2-end2֮�л�������
//	{
//		while (begin2 <= end2)
//		{
//			tmp[index] = array[begin2];
//			index++;
//			begin2++;
//		}
//	}
//	else//˵��begin1-end1֮�л�������
//	{
//		while (begin1 <= end1)
//		{
//			tmp[index] = array[begin1];
//			index++;
//			begin1++;
//		}
//	}
//	index = left;
//	while (index <= right)//tmp����ʱ���飬��Ҫ�������������·ŵ�����array��
//	{
//		array[index] = tmp[index];
//		index++;
//	}
//}
//void MergerSort(int* array, size_t n)	   //�鲢����
//{
//	assert(array);
//	int *tmp = (int *)malloc(sizeof(int)*n);
//	_MergeSort(array, 0, n - 1, tmp);//tmp����ʱ����
//	free(tmp);
//	tmp = NULL;
//}

void CountSort(int* array, size_t n)	   //��������
{
	assert(array);

	int max = array[0];
	int min = array[0];
	for (int i = 0; i < n; ++i)    //�ҳ�����������С����
	{
		if (array[i]>max)
		{
			max = array[i];
		}
		if (array[i] < min)
		{
			min = array[i];
		}
	}

	int range = max - min + 1;
	int* counts = (int*)malloc(sizeof(int)*range);       //ͳ�ƴ���
	memset(counts, 0, sizeof(int)*range);				 //�����ʼ��
	for (int i = 0; i < n; ++i)
	{
		counts[array[i] - min]++;						//���λ��
	}

	int index = 0;                                      //���ݴ���������
	for (int i = 0; i < range; ++i)
	{
	
		while (counts[i]>0)								//���ݴ������в���
		{
			array[index] = i + min;
			--counts[i];
			++index;
		}
	}
	free(counts);
}

void TestSort()
 {
	int array[] = { 1, 9, 0, 5, 4, 6, 3, 7, 2, 8 };
	//InsertSort(array, 10);     //ֱ�Ӳ�������
	//HillSort(array, 10);      // ϣ������
	//SelectSort(array, 10); //ֱ��ѡ������
	//HeapSort(array, 10);     //������
	QuickSort(array, 0, 9);    //��������
	//BubbleSort(array, 10);     //ð������
	//MergerSort(array, 10);      //�鲢����
	//CountSort(array, 10);    //��������
	int i = 0;
	for (i = 0; i < sizeof(array) / sizeof(array[0]); i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

}


