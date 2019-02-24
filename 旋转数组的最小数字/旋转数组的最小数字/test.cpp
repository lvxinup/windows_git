#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<stdio.h>

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int begin = 0;
		int end = rotateArray.size() - 1;
		int index = (begin + end) / 2;
		while (rotateArray[begin] >= rotateArray[end])
		{
			if (end - begin == 1)
			{
				index = end;
				break;
			}
			index = begin + (end - begin) / 2;
			if (rotateArray[index] >= rotateArray[begin])
			{    //说明最小值在index的右边
				begin = index;
			}
			else if (rotateArray[index] <= rotateArray[end])  //说明最小值在index的右边
			{
				end = index;
			}
		}
		return rotateArray[index];
	}
};
