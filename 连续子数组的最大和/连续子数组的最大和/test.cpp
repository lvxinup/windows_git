#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n, x, i=0, pos = 0;
	cin >> n;
	vector<int> v;
	for (i = 0; i <n; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	int max=v[0], cur = v[0];
	while (pos<v.size())
	{
		cur += v[pos];
		if (cur<v[pos])
			cur = v[pos];
		if (cur>max)
			max = cur;
		pos++;
	}
	cout << max;
	
	return 0;
}