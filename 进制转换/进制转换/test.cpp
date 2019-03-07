#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
using namespace std;
int main()
{
	string s = "";
	string tmp = "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;
	while (m)
	{
		if (m<0){
			m = -m;
			cout << "-";
		}
		if (m == 0)
		{
			cout << "0";
			return 0;
		}
		s = tmp[m%n] + s;
		m /= n;
	}
	cout << s << endl;
	return 0;
}