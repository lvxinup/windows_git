#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>
#include<assert.h>

using namespace std;
typedef int DataType;

/*连续存储结构：vector是可以实现动态增长的对象数组，支持对数组高效率的访问和在数组尾端的删除和插入操作，
在中间和头部删除和插入相对不易，需要挪动大量的数据。
它与数组最大的区别就是vector不需程序员自己去考虑容量问题，库里面本身已经实现了容量的动态增长，
而数组需要程序员手动写入扩容函数进形扩容。 */
class Vector
{
public:
	Vector()
		:_first(NULL), _finish(NULL), _endofstorage(NULL)
	{
	}
	Vector(const Vector& v)
	{
		_first = v._first;
		_finish = v._finish;
		_endofstorage = v._endofstorage;
	}
	Vector *v;
	Vector& operator=(const Vector& v)
	{
		if (this != &v)
		{
			_first = v._first;
			_finish = v._finish;
			_endofstorage = v._endofstorage;
		}
	}
	~Vector()
	{
	}
	size_t Size()
	{
		return _finish - _first;
	}
	size_t Capacity()
	{
		return _finish - _endofstorage;
	}
	void Expand(size_t n)
	{
		const size_t size = Size();
		const size_t capacity = Capacity();
		if (n > capacity)
		{
			Vector *tmp = new Vector[n];//开辟一段临时空间，大小为要扩展的大小
			for (size_t i = 0; i < capacity; i++)
			{
				tmp[i] = v[i];
			}
			delete[] v;
			v = tmp;
			_finish = _first + size;
			_endofstorage = _first + n;
		}
	}
	void PushBack(DataType x)
	{
		if (_finish == _endofstorage)//检查空间是否充足
		{
			size_t len = Capacity();
			Expand(2 * len);
		}
		*_finish= x;
		++_finish;
	}
	void Reserve(size_t n)//不用初始化空间，直接增容
	{
		Expand(n);
	}
	void PopBack()
	{
		*(_finish - 1) = NULL;
		--_finish;
	}
	void Insert(DataType* pos, DataType x)
	{
		DataType n = pos - _first;
		if (_finish == _endofstorage)
		{
			//检查空间是否充足
			size_t len = Capacity();
			Expand(2 * len);
		}
		pos = _first + n;
		for (DataType* i = _finish; i > pos; --_finish)
		{
			//所有的数据依次往后移动
			*_finish = *(_finish - 1);
		}
		*pos = x;
		++_finish;

	}
	void Erase(DataType* pos)
	{
		//删除元素，把删除位置后的所有元素往前移动，并覆盖
		for (DataType* i = pos; i < _finish; i++)
		{
			*pos = *(pos + 1);
		}
		--_finish;
	}
	DataType* Find(DataType x)
	{
		for (DataType* i = _first; i < _finish; i++)
		{
			if (*i == x)
			{
				return i;
			}
		}
		return false;
	}
private:
	DataType* _first;//指向第一个元素的节点
	DataType* _finish;//指向最后一个元素所在节点的下一个节点
	DataType* _endofstorage;//可用内存空间的末尾节点
};
/*非连续存储结构：list是一个双链表结构，支持对链表的双向遍历。
每个节点包括三个信息：元素本身，指向前一个元素的节点（prev）和指向下一个元素的节点（next）。
因此list可以高效率的对数据元素任意位置进行访问和插入删除等操作。
由于涉及对额外指针的维护，所以开销比较大。*/ 
struct ListNode
{
	ListNode* _next;
	ListNode* _prev;
	DataType _data;

	ListNode(DataType x)
		:_data(x)
		, _next(NULL)
		, _prev(NULL)
	{}
};
class List
{
	typedef ListNode Node;
public:
	List()
		:_head(new Node(DataType()))
	{
		_head->_next = _head;
		_head->_prev = _head;
	}

	List(const List& l)
	{
		_head = new Node(DataType());
		_head->_next = _head;
		_head->_prev = _head;
		Node *cur = l._head->_next;
		while (cur != l._head)
		{
			Node *tail = _head->_prev;
			Node* Newnode = new Node(cur->_data);
			tail->_next = Newnode;
			Newnode->_prev = tail;
			Newnode->_next = _head;
			_head->_prev = Newnode;
			cur = cur->_next;
		}
	}
	List& operator=(const List& l)
	{
		_head = l._head;
		return *this;
	}
	~List();

	void PushBack(DataType x)//头插
	{
		Node *tail = _head->_prev;
		Node* Newnode = new Node(x);
		tail->_next = Newnode;
		Newnode->_prev = tail;
		Newnode->_next = _head;
		_head->_prev = Newnode;
	}
	void PushFront(DataType x)//尾插
	{
		Insert(_head->_next, x);
	}
	void PopBack()//头删
	{
		assert(_head->_next != _head);
		//_head next next->_next	删除next
		Node *next = _head->_next;
		_head->_next = next->_next;
		next->_next->_prev = _head;
		delete next;
		next = NULL;

		//或者直接用Erase删除_head的下一个位置
		//Erase(_head->_next);
	}
	void PopFront()//尾删
	{
		assert(_head->_prev != _head);
		Erase(_head->_prev);
	}
	Node* Find(DataType x)
	{
		Node *cur = _head->_next;
		while (cur != _head && cur->_data != x)
		{
			cur = cur->_next;
		}
		if (cur == _head)//遍历一遍之后没有找到
		{
			return NULL;
		}
		return cur;
	}
	void Insert(Node* pos, DataType x)
	{
		Node *prev = pos->_prev;
		Node *newnode = new Node(x);
		prev->_next = newnode;
		newnode->_prev = prev;
		newnode->_next = pos;
		pos->_prev = newnode;
	}
	void Erase(Node* pos)
	{
		assert(pos != _head);
		Node *prev = pos->_prev;
		Node *next = pos->_next;
		prev->_next = next;
		next->_prev = prev;
		delete pos;
		pos = NULL;
	}
private:
	Node* _head;
};

int main()
{
	system("pause");
	return 0;
}