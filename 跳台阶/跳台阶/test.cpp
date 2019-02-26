#define  _CRT_SECURE_NO_WARNINGS 1

//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。

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