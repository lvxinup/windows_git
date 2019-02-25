#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//class person
//{
//public:
//	string _name;//姓名
//	person()
//	{
//		cout << "person()" << endl;
//	}
//	~person()
//	{
//		cout << "~person() " << endl;
//	}
//	void display()
//	{
//		cout << &_name << endl;
//	}
//};
//class student:virtual public person
//{
//public:
//	int _num;//学号
//	student()
//	{
//		cout << "student() " << endl;
//	}
//	~student()
//	{
//		cout << "~student() " << endl;
//	}
//	void display1()
//	{
//		cout << _num << endl;
//	}
//};
//class teacher:virtual public person
//{
//public:
//	int _id;//编号
//	teacher()
//	{
//		cout <<"teacher() "<< endl;
//	}
//	~teacher()
//	{
//		cout << "~teacher() " << endl;
//	}
//	void display2()
//	{
//		cout << _id << endl;
//	}
//};
//class assistant :public student, public teacher
//{
//public:
//	string _majorcourse;//主修课程
//	assistant()
//	{
//		cout << "assistant() " << endl;
//	}
//	~assistant()
//	{
//		cout << "~assistant() " << endl;
//	}
//};
//int main()
//{
//	assistant a;
//	//a._name = "xxx";
//	a.student::_name = "xxx";
//	a.teacher::_name = "yyy";
//	a.teacher::_id = 001;
//	a.student::_num = 002;
//	a.assistant::_majorcourse= "数学";
//
//	system("pause");
//	return 0;
//}
class A
{
public:
	int _a;
};
class B : virtual  public A
{
public:
	int _b;
};
class C : virtual public  A
{
public:
	int _c;
};
class D : public B, public C
{
public:
	int _d;
};
int main()
{

	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;

	system("pause");
	return 0;
}
//class person
//{
//	virtual void display() = 0;
//protected:
//	string _name;
//};
//class student:public person
//{
//	virtual void display()
//	{
//		cout << "hahh" << endl;
//	}
//};
//
//int main()
//{
//	person p;
//	student s;
//	system("pause");
//	return 0;
//}