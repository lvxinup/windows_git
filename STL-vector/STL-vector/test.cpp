#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<stdio.h>
#include<Windows.h>
#include<vector>
using namespace std;

void PrintVector(const vector<int>& v)
{
	//ʹ��const���������д�ӡ
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
	//vector<int> first;			//�޲ι���
	//vector<int> second(4, 100);	//���첢��ʼ���ĸ�100
	//vector<int>	third(second.begin(), second.end());	//���������г�ʼ�����죬�������൱��ָ��
	//vector<int>	fourth(third);	//��������
	//	
	////ʹ�õ�������ʼ��
	//int array[] = { 1, 2, 3, 4, 5 };
	//vector<int> fifth(array, array + sizeof(array) / sizeof(int) );
	////ʹ�õ�������ӡ
	//cout << "the contents of fif are:";
	//for (vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
	//{
	//	cout << ' ' << *it;
	//}
	//cout << '\n';


	//ʹ��push_back�����ĸ�����
	//vector<int> v;
	//v.push_back(1);
	//v.push_back(2);
	//v.push_back(3);
	//v.push_back(4);

	////ʹ�õ��������б�����ӡ
	//vector<int>::iterator it = v.begin();
	//while (it != v.end())
	//{

	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;

	////ʹ�õ����������޸�
	//it = v.begin();
	//while (it != v.end())
	//{
	//	*it *= 2;
	//	++it;
	//}

	////ʹ�÷�����������б����ڴ�ӡ
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

	//ʹ��find����3����λ�õ�iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);

	//��posλ��֮ǰ����30
	v.insert(pos, 30);

	vector<int>


	system("pause");
	return 0;
}
