#define  _CRT_SECURE_NO_WARNINGS 1

//һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж������������Ⱥ����ͬ�㲻ͬ�Ľ������

class Solution {
public:
	int jumpFloor(int number) {
		int first = 1;
		int second = 2;
		int result = 0;
		if (number <= 0)
			result = 0;
		if (number == 1)
			result = 1;
		if (number == 2)
			result = 2;
		for (int i = 3; i <= number; i++)
		{
			result = first + second;
			first = second;
			second = result;
		}
		return result;
	}
};