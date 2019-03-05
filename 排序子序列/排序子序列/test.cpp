#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include<vector>
#include<Windows.h>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	int a[20];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	bool up;
	short order = -1;   //…Ë÷√≥ı º÷µ
	int result = 0;
	for (int i = 0; i < n - 1; i++) {
		up = (a[i + 1] > a[i]);
		if (order == -1) {
			if (a[i + 1] != a[i]) {
				order = up;
			}
			else {
				order = -1;
			}
		}
		else if (up != order && a[i + 1] != a[i]) {
			order = -1;
			result++;
		}
	}
	cout << ++result;

	system("pause");
	return 0;
}