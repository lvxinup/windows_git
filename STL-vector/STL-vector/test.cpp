#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<stdio.h>
#include<Windows.h>
#include<vector>
using namespace std;

void PrintVector(const vector<int>& v)
{
	//使用const迭代器进行打印
	vector<int>::const_iterator it = v.cbegin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main()
{
	//vector<int> first;			//无参构造
	//vector<int> second(4, 100);	//构造并初始化四个100
	//vector<int>	third(second.begin(), second.end());	//迭代器进行初始化构造，迭代器相当于指针
	//vector<int>	fourth(third);	//拷贝构造
	//	
	////使用迭代器初始化
	//int array[] = { 1, 2, 3, 4, 5 };
	//vector<int> fifth(array, array + sizeof(array) / sizeof(int) );
	////使用迭代器打印
	//cout << "the contents of fif are:";
	//for (vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
	//{
	//	cout << ' ' << *it;
	//}
	//cout << '\n';


	//使用push_back插入四个数据
	//vector<int> v;
	//v.push_back(1);
	//v.push_back(2);
	//v.push_back(3);
	//v.push_back(4);

	////使用迭代器进行遍历打印
	//vector<int>::iterator it = v.begin();
	//while (it != v.end())
	//{

	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;

	////使用迭代器进行修改
	//it = v.begin();
	//while (it != v.end())
	//{
	//	*it *= 2;
	//	++it;
	//}

	////使用反向迭代器进行遍历在打印
	//vector<int>::reverse_iterator rit (v.rbegin());
	//while (rit != v.rend())
	//{
	//	cout << *rit << " ";
	//	++rit;
	//}
	//cout << endl;

	//PrintVector(v);


	////vector::reserve
	//size_t sz;
	//vector<int> v;
	//sz = v.capacity();
	//cout << "making v grow:\n";
	//for (int i = 0; i < 100; ++i)
	//{
	//	v.push_back(i);
	//	if (sz != v.capacity())
	//	{
	//		sz = v.capacity();
	//		cout << "capacity changed: " << sz << '\n';
	//	}
	//}
	//
	//vector<int> cur;
	//sz = cur.capacity();
	//cur.reserve(100);
	//cout << "making cur grow:\n";
	//for (int i = 0; i < 100; ++i)
	//{
	//	cur.push_back(i);
	//	if (sz != cur.capacity())
	//	{
	//		sz = cur.capacity();
	//		cout << "capacity changed: " << sz << '\n';
	//	}
	//}


	////vector::resize
	//vector<int> myvector;
	//for (int i = 1; i < 10; i++)
	//{
	//	myvector.push_back(i);
	//}
	//myvector.resize(5);
	//myvector.resize(8, 100);
	//myvector.resize(12);

	//cout << "myvector contains:";
	//for (int i = 0; i < myvector.size(); i++)
	//	std::cout << ' ' << myvector[i];
	//cout << '\n';

	
	////push_back/pop_back
	//int a[] = { 1, 2, 3, 4 };
	//vector<int> v(a, a + sizeof(a) / sizeof(int));

	//vector<int>::iterator it = v.begin();

	//while (it != v.end())
	//{
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;

	//v.pop_back();
	//v.pop_back();

	//it = v.begin();
	//while (it != v.end())
	//{
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;


	//find / insert / erase
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	//使用find查找3所在位置的iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);

	//在pos位置之前插入30
	v.insert(pos, 30);

	vector<int>


	system("pause");
	return 0;
}
