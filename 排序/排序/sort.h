#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>
#include<assert.h>

//插入排序
void InsertSort(int* array,size_t n);     //直接插入排序
void HillSort(int* array, size_t n);         //希尔排序
//选择排序
void SelectSort(int* array, size_t n);	   //选择排序
void HeapSort(int* array, size_t n);         //堆排序
//交换排序
void BubbleSort(int* array, size_t n);	   //冒泡排序
void QuickSort(int* array, int left, int right); //快速排序
//归并排序-
void MergerSort(int* arrray, size_t n);	   //归并排序
//计数排序
void CountSort(int* array, size_t n);	   //计数排序

void Swap(int *a1, int *a2)
{
	int c = *a1;
	*a1 = *a2;
	*a2 = c;
}
void InsertSort(int* array, size_t n)       //直接插入排序
{
	assert(array);
	int end = 0;
	for (int i = 0; i < n-1; ++i)
	{
		end = i;
		int tmp = array[end + 1];   //end+1为要插入的数据
		while (end >= 0 && array[end]>tmp)    //找到tmp的插入位置
		{
			//如果插入数据在和前面有序区间数据进行比较最小，
			//将会有end=-1,那么也可以归为[end+1]=[-1+1]=tmp;
			array[end + 1] = array[end];//将大的数据向后移动	
			end--;
		}
		array[end + 1] = tmp;
	}
}
void HillSort(int* array, size_t n)         //希尔排序
{
	assert(array);
	int end = 0;
	int gap = n;   //间距
	while (gap > 1) // 如果大于0，则为死循环
	{
		gap = gap / 3 + 1;   //不断缩小gap,使数组接近有序.   加1使得最后一次为直接插入排序
		for (int i = 0; i < n- gap; ++i)    //循环结束条件为 n-gap ，即最后一个gap正好对应最后一个值
		{
			end = i;
			int tmp = array[end + gap];
			while (end >= 0 && array[end]>tmp)  //找到tmp 的插入位置
			{
				array[end + gap] = array[end];   //大的数据往后移动
				end = end - gap;
			}
			array[end + gap] = tmp;//end小于0或者array[end]<tmp，tmp在array[end+gap]插入
		}
	}
}

void SelectSort(int* array, size_t n)	   //选择排序
{
	size_t min = 0;
	size_t temp = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)    //找到cur之后 所有数中的最小值
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
void HeapAdjustDown(int* array, size_t n,int parent) //向下调整
{
	int temp = 0;
	int child = parent * 2 + 1;//左孩子
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
void HeapSort(int* array, size_t n)         //堆排序
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

void BubbleSort(int* array, size_t n)	   //冒泡排序
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
int GetMid(int* array, int left, int right)                //三数取中法
{
	int mid = left + ((right - left) >> 1);
	if (array[left] < array[mid])//左比中小
	{
		if (array[mid] < array[right])
			return mid;//mid是中位数 
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
int PartSort1(int* array, int left, int right)       //左右指针法
{
	assert(array);
	int begin = left;
	int end = right;
	int mid = GetMid(array, left, right);
	Swap(&array[mid], &array[right]);
	int key = array[right];
	while (begin < end)
	{
		while (array[begin] <= key && begin < end)//begin找大
		{
			begin++;
		}
		while (array[end] >= key && begin < end)//end找小
		{
			end--;
		}
		if (begin < end)
		{
			Swap(&array[begin], &array[end]);
		}      //begin  end 相遇后，把key放在相遇位置上
	}
	Swap(&array[begin], &array[right]);//begin  end 相遇后，把key放在相遇位置上
	return begin;
}
int PartSort2(int* array, int left, int right)      //挖坑法
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
		array[end] = array[begin];	  //坑变为begin
		while (array[end] >= key && begin < end)
		{
			end--;
		}
		array[begin] = array[end];     // 坑变为end
	}
	array[begin] = key;               //填坑
	return begin;
}
int PartSort3(int* array, int left, int right)    //前后指针
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
void QuickSort(int* array, int left, int right)	       //快速排序
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
//	//分组
//	if (left >= right)    //左大于右时，直接返回
//		return;
//	if (right - left + 1 < 20)
//	{
//		InsertSort(array + left, right - left + 1);//小区间优化：当数据个数（闭区间需要加1）小于20时，直接插入排序
//		return;
//	}
//	int mid = left + (right - left) / 2;
//	_MergerSort(array, left, mid, tmp);//将左边划分有序
//	_MergerSort(array, right, mid, tmp);//将右边划分有序
//
//	//归并
//	int begin1 = left, end1 = mid;
//	int begin2 = mid + 1, end2 = right;
//	int index = left;
//	while (begin1 < end1 && begin2 < end2)  //两个有序数组的合并
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
//	if (begin1 > end1)//说明begin2-end2之中还有数据
//	{
//		while (begin2 <= end2)
//		{
//			tmp[index] = array[begin2];
//			index++;
//			begin2++;
//		}
//	}
//	else//说明begin1-end1之中还有数据
//	{
//		while (begin1 <= end1)
//		{
//			tmp[index] = array[begin1];
//			index++;
//			begin1++;
//		}
//	}
//	index = left;
//	while (index <= right)//tmp是临时数组，需要将有序数据重新放到数组array中
//	{
//		array[index] = tmp[index];
//		index++;
//	}
//}
//void MergerSort(int* array, size_t n)	   //归并排序
//{
//	assert(array);
//	int *tmp = (int *)malloc(sizeof(int)*n);
//	_MergeSort(array, 0, n - 1, tmp);//tmp是临时数组
//	free(tmp);
//	tmp = NULL;
//}

void CountSort(int* array, size_t n)	   //计数排序
{
	assert(array);

	int max = array[0];
	int min = array[0];
	for (int i = 0; i < n; ++i)    //找出最大的数与最小的数
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
	int* counts = (int*)malloc(sizeof(int)*range);       //统计次数
	memset(counts, 0, sizeof(int)*range);				 //数组初始化
	for (int i = 0; i < n; ++i)
	{
		counts[array[i] - min]++;						//相对位置
	}

	int index = 0;                                      //数据存入数组中
	for (int i = 0; i < range; ++i)
	{
	
		while (counts[i]>0)								//根据次数进行插入
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
	//InsertSort(array, 10);     //直接插入排序
	//HillSort(array, 10);      // 希尔排序
	//SelectSort(array, 10); //直接选择排序
	//HeapSort(array, 10);     //堆排序
	QuickSort(array, 0, 9);    //快速排序
	//BubbleSort(array, 10);     //冒泡排序
	//MergerSort(array, 10);      //归并排序
	//CountSort(array, 10);    //计数排序
	int i = 0;
	for (i = 0; i < sizeof(array) / sizeof(array[0]); i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

}


