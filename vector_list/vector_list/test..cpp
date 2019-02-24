#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>
#include<assert.h>

using namespace std;
typedef int DataType;

/*�����洢�ṹ��vector�ǿ���ʵ�ֶ�̬�����Ķ������飬֧�ֶ������Ч�ʵķ��ʺ�������β�˵�ɾ���Ͳ��������
���м��ͷ��ɾ���Ͳ�����Բ��ף���ҪŲ�����������ݡ�
�������������������vector�������Ա�Լ�ȥ�����������⣬�����汾���Ѿ�ʵ���������Ķ�̬������
��������Ҫ����Ա�ֶ�д�����ݺ����������ݡ� */
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
			Vector *tmp = new Vector[n];//����һ����ʱ�ռ䣬��СΪҪ��չ�Ĵ�С
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
		if (_finish == _endofstorage)//���ռ��Ƿ����
		{
			size_t len = Capacity();
			Expand(2 * len);
		}
		*_finish= x;
		++_finish;
	}
	void Reserve(size_t n)//���ó�ʼ���ռ䣬ֱ������
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
			//���ռ��Ƿ����
			size_t len = Capacity();
			Expand(2 * len);
		}
		pos = _first + n;
		for (DataType* i = _finish; i > pos; --_finish)
		{
			//���е��������������ƶ�
			*_finish = *(_finish - 1);
		}
		*pos = x;
		++_finish;

	}
	void Erase(DataType* pos)
	{
		//ɾ��Ԫ�أ���ɾ��λ�ú������Ԫ����ǰ�ƶ���������
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
	DataType* _first;//ָ���һ��Ԫ�صĽڵ�
	DataType* _finish;//ָ�����һ��Ԫ�����ڽڵ����һ���ڵ�
	DataType* _endofstorage;//�����ڴ�ռ��ĩβ�ڵ�
};
/*�������洢�ṹ��list��һ��˫����ṹ��֧�ֶ������˫�������
ÿ���ڵ����������Ϣ��Ԫ�ر���ָ��ǰһ��Ԫ�صĽڵ㣨prev����ָ����һ��Ԫ�صĽڵ㣨next����
���list���Ը�Ч�ʵĶ�����Ԫ������λ�ý��з��ʺͲ���ɾ���Ȳ�����
�����漰�Զ���ָ���ά�������Կ����Ƚϴ�*/ 
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

	void PushBack(DataType x)//ͷ��
	{
		Node *tail = _head->_prev;
		Node* Newnode = new Node(x);
		tail->_next = Newnode;
		Newnode->_prev = tail;
		Newnode->_next = _head;
		_head->_prev = Newnode;
	}
	void PushFront(DataType x)//β��
	{
		Insert(_head->_next, x);
	}
	void PopBack()//ͷɾ
	{
		assert(_head->_next != _head);
		//_head next next->_next	ɾ��next
		Node *next = _head->_next;
		_head->_next = next->_next;
		next->_next->_prev = _head;
		delete next;
		next = NULL;

		//����ֱ����Eraseɾ��_head����һ��λ��
		//Erase(_head->_next);
	}
	void PopFront()//βɾ
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
		if (cur == _head)//����һ��֮��û���ҵ�
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