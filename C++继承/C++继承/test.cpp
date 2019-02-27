#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<Windows.h>

using namespace std;

//class person
//{
//public:
//	char* name;
//	char* sex;
//	int age;
//public:
//	void display()
//	{
//		cout << "name:" << name << "  sex:" << sex << "  age:" << age << endl;
//	}
//};
//class student :public person
//{
//public:
//	int stdnum;
//public:
//	void show()
//	{
//		cout << "stdnum:" << stdnum << endl;
//	}
//};

//int main()
//{
//	student s;
//	s.name = "xiaowang";
//	s.sex = "man";
//	s.age = 18;
//	s.stdnum = 2016;
//	s.display();
//	s.show();
//
//	system("pause");
//	return 0;
//}

//class person
//{
//public:
//	char* name;
//	char* sex;
//	int age;
//public:
//	void display()
//	{
//		cout << "name:" << name << "  sex:" << sex << "  age:" << age << endl;
//	}
//};
//class student :public person
//{
//public:
//	int stdnum;
//public:
//	void show()
//	{
//		cout << "stdnum:" << stdnum << endl;
//	}
//};
//
//int main()
//{
//	person p;
//	p.name = "xiaozhang";
//	p.age = 18;
//	
//	student s;
//	s.name = "xiaowang";
//	p.age = 20;
//	
//	// 切割/切片
//	// 子类可以给父类赋值
//	p = s;	
//	//父类不能给给子类赋值
//	//s=p;
//
//	//父类的指针可以指向子类对象
//	person* p1 = &s;	
//	//父类的引用可以指向子类对象
//	person& r1 = s;	
//
//	p1->name = "xx";
//	r1.name = "yy";
//
//	//子类的指针/引用不能指向父类（可以通过强制类型转换完成）
//	student* p2 = (student*)&p;
//	student& r2 = (student&)p;
//
//	p2->name = "xx";
//	r2.name = "yy";
//
//	system("pause");
//	return 0;
//}

//class person
//{
//public:
//	void show()
//	{
//		cout <<"person::show()"<< endl;
//	}
//
//	//protected:
//	string _name;
//	int _age;
//};
//
//class student : public person
//{
//public:
//	void show(int i)
//	{
//		cout << "student::show()" << endl;
//	}
//
//	//protected:
//	string _name;
//	int _stunum; // 学号
//};
//
//int main()
//{
//	student s;
//	s._name = "xxx";
//	s.person::_name = "yyy";
//
//	s.show(1);
//	s.person::show();
//
//	system("pause");
//	return 0;
//}

class Person
{
public:
	Person(const char* name = "", int age = 0)
		:_name(name)
		, _age(age)
	{
		cout << "Person()" << endl;
	}

	Person(const Person& p)
		:_name(p._name)
		, _age(p._age)
	{
		cout << "Person(const Person& p)" << endl;
	}

	Person& operator=(const Person& p)
	{
		if (this != &p)
		{
			_name = p._name;
			_age = p._age;
		}

		return *this;
	}

	~Person()
	{
		cout << "~Person()" << endl;
	}

public:
	string _name;
	int _age;
};

class Student : public Person
{
public:
	Student(const char* name, int age, int stunum)
		:Person(name, age)
	{
		_stunum = stunum;
		cout << "Student()" << endl;
	}

	Student(const Student& s)
		:Person(s)
	{
		_stunum = s._stunum;
	}

	Student& operator=(const Student& s)
	{
		if (this != &s)
		{
			Person::operator=(s);
			_stunum = s._stunum;
		}

		return *this;
	}

	~Student() //隐藏了父类的析构函数
	{
		Person::~Person();
		cout << "~Student()" << endl;
	}

public:
	int _stunum; // 学号
};

int main()
{
	Student s1("xx", 1, 1);
	//Student s2(s1);
	//Student s3("yy", 1, 1);

	//s2 = s3;

	system("pause");
	return 0;
}