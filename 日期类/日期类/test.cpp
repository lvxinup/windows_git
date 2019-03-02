#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
#include<Windows.h>
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)    //初始化列表
		//:_year(year)
		//, _month(month)
		//, _day(day)
	{
		//if (!IsInvalid()) // this->IsInvalid(this) 
		//{
		//	//assert(false);
		//	cout << "非法日期" << endl; //exit(-1); 
		//}
		if (year > 0 && month < 13 && month>0 &&
			GetMonthDay(year, month) >= day&&day > 0)
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
			cout << "非法日期" << endl;
	}

	Date(const Date& d)    //拷贝构造函数
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	Date& operator=(const Date& d)   //赋值运算符的重载
	{
		if (this != &d)//不能自己给自己赋值
		{
			this->_year = d._year;
			this->_month = d._month;
			this->_day = d._day;
		}
		return *this;  //指向d1
	}
	~Date()//析构函数  栈先进后出，先构造的对象后析构
	{
		//if (this)
		//{
		//	free(this);
		//	*this = 0;
		//}
	}
	bool IsInvalid() //判断非法日期
	{
		if (this->_month < 13 && this->_day < GetMonthDay(this->_year, this->_month))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	bool isLeapYear(int year)  //判断闰年
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	int GetMonthDay(int year, int month)
	{
		assert(year > 0 && month > 0 && month<13);
		int Month[13] = { 0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = Month[month];
		if (month == 2 && (isLeapYear(year)))  //判断闰年
		{
			day++;
		}
		return day;
	}
	void Show()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	bool operator==(const Date& d)
	{
		return this->_year == d._year && this->_month == d._month && this->_day == d._day;
	}
	bool operator!=(const Date& d)
	{
		return !(this->_year == d._year && this->_month == d._month && this->_day == d._day);
	}
	bool operator>=(const Date& d)
	{
		if (*this > d || *this == d)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator<=(const Date& d)
	{
		if (*this < d || *this == d)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator>(const Date& d)
	{
		if (_year > d._year)
			return true;
		if (_year == d._year && _month > d._month)
			return true;
		if (_year == d._year&&_month == d._month&&_day > d._day)
			return true;
		else
			return false;
	}
	// d1 < d2 
	bool operator<(const Date& d)
	{
		if (!(*this >= d))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	// d1 + 10 
	Date operator+(int day)
	{
		Date tmp = *this;
		if (day < 0)
		{
			return tmp - day;
		}
		tmp._day += day;
		if (GetMonthDay(tmp._year, tmp._day) >= tmp._day)
			return tmp;
		else
		{
			while (tmp._day > GetMonthDay(tmp._year, tmp._month))
			{
				tmp._day -= GetMonthDay(tmp._year, tmp._month);
				tmp._month++;
				if (tmp._month == 13)
				{
					tmp._year += 1;
					tmp._month -= 12;
				}
			}
			return tmp;
		}
	}
	Date& operator+=(int day)
	{
		*this = *this + day;//直接调用+运算操作符
		return *this;
	}
	Date operator-(int day)
	{
		Date tmp = *this;
		if (day < 0)
		{
			return tmp + (-day);
		}
		tmp._day -= day;
		if (tmp._day >0)
		{
			return tmp;
		}
		else
		{
			while (tmp._day <= 0)
			{
				if (tmp._month > 1)
				{
					tmp._month -= 1;
					tmp._day += GetMonthDay(tmp._year, tmp._month);
				}
				else  //年减1
				{
					tmp._year -= 1;
					assert(tmp._year > 0);
					tmp._month += 12;
					tmp._month -= 1;
					tmp._day += GetMonthDay(tmp._year, tmp._month);
				}
			}
		}
	}
	Date& operator-=(int day)
	{
		*this = *this - day;//直接调用-运算操作符
		return *this;
	}
	int operator-(const Date& d)//日期减日期，小的日期一直+1直到两者相等，加了多少次即为多少天
	{
		//先判断大小
		int flag = 1;
		Date max = *this;
		Date min = (Date)d;
		if (*this < d)
		{
			max = (Date)d;
			min = *this;
			flag = -1;
		}
		int day = 0;
		while (min < max)
		{
			min += 1;//调用+=，+=调用+
			day++;
		}
		return day*flag;
	}

	//++d1 
	Date& operator++() // 前置 
	{
		*this = *this + 1;//直接调用+运算操作符
		return *this;
	}
	//d1++ 
	Date operator++(int) // 后置  有int 就是后置++
	{
		Date tmp = *this;
		*this += 1;
		return tmp;
	}
	Date operator--()
	{
		Date tmp = *this;
		*this -= 1;//直接调用-=
		return tmp;
	}
	Date operator--(int)
	{
		*this -= 1;//直接调用-=
		return *this;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	d1.Show(); 

	Date d2(2017, 2, 28);
	d2.Show(); 


	++d1; // d1.operator++(&d1); 
	d1++; // d1.operator++(&d1, 0); 
	d1.Show();
	

	system("pause");
	return 0;
}