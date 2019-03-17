#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
	int a;
	while (cin >> a)
	{
		int flag = 0;
		int maxcount = 0;
		while (a)
		{
			if (a & 1)
			{
				flag++;
				maxcount = max(flag, maxcount);
			}
			else
			{
				flag = 0;
			}
			a = a >> 1;
		}

		cout << maxcount << endl;
	}

	return 0;
}