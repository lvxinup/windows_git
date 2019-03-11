#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<Windows.h>
using namespace std;
int main()
{
	int N, begin = 0, end = 1;
	vector<int> v;
	v.push_back(begin);
	v.push_back(end);
	cin >> N;
	if (N == 0 || N == 1)
	{
		printf("%d", begin);
		return 0;
	}
	while (v[v.size() - 1]+v[v.size()-2]<N)
	{
		int tmp = begin + end;
		begin = end;
		end = tmp;
		v.push_back(tmp);
	}
	if (N == v[v.size() - 1])
	{
		printf("0");
		return 0;
	}
	int sma = N - v[v.size() - 1];
	int big = v[v.size() - 1] + v[v.size() - 2] - N;
	if (sma < big)
		printf("%d", sma);
	else
		printf("%d", big);

	system("pause");
	return 0;
}