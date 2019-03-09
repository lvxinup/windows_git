#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;
bool huiwen(string& tmp)
{
	string cur(tmp);
	size_t begin = 0;
	size_t end = cur.size()-1;
	while (begin < end)
	{
		if (cur[begin] ==  cur[end])
		{
			begin++;
			end--;
		}
		else
			return false;
	}
	return true;
}
int main()
{
	string a, b;
	string tmp1, tmp2;
	int count = 0;
	size_t pos = 0;
	getline(cin, a);
	getline(cin, b);
	//string& insert (size_t pos, const string& str);
	while (pos<a.size())
	{
		tmp1 = a;
		tmp2 = tmp1.insert(pos, b);
		if (huiwen(tmp2))
			count++;
		pos++;
	}
	tmp2 = a;
	tmp2 += b;
	if (huiwen(tmp2))
		count++;
	cout << count << endl;

	system("pause");
	return 0;
}