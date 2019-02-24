#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<Windows.h>

template <class T>
struct BSTNode		//���������
{
	BSTNode(const T& data = T())
		:_pLeft(nullptr)
		,_pRight(nullptr)
		, _data(data)
	{}

	BSTNode<T>* _pLeft;
	BSTNode<T>* _pRight;
	T _data;
};

template <class T>
class BSTree	
{
	typedef BSTNode<T> Node;
	typedef Node* PNode;

public:
	BSTree()	//���캯��
		:_pRoot(nullptr)
	{}

	~BSTree()
	{
		_Destroy(_pRoot);
	}

	PNode Find(const T& data)	//�������Ĳ���
	{
		PNode Cur = _pRoot;
		while (Cur)
		{
			if (data == Cur->_data)
			{
				return Cur;
			}
			else if (data > Cur->_data)
			{
				Cur = Cur->_pRight;
			}
			else
			{
				Cur = Cur->_pLeft;
			}
		}

		return nullptr;	//�ߵ�����˵��û���ҵ�
	}

	bool Insert(const T& data)
	{
		//a.��Ϊ�գ�ֱ�Ӳ���
		if (_pRoot == nullptr)
		{
			_pRoot = new Node(data);
			return true;
		}

		//b.�����գ����������������ʲ��Ҳ���λ�ã������½ڵ㡣
		PNode Cur = _pRoot;
		PNode Parent = nullptr;

		while (Cur)	//���ҵ�Ҫ�����λ��
		{
			Parent = Cur;
			if (data < Cur->_data)
			{
				Cur = Cur->_pLeft;
			}
			else if (data > Cur->_data)
			{
				Cur = Cur->_pRight;
			}
			else	//Ԫ���Ѿ������д���
			{
				return false;
			}
		}

		//����Ԫ��
		Cur = new Node(data);
		if (data < Cur->_data)
			Parent->_pLeft = Cur;
		else
			Parent->_pRight = Cur;

		return true;
	}

	bool Erase(const T& data)
	{
		if (_pRoot == nullptr)	//��Ϊ�գ���ɾ��ʧ��
			return false;

		//����data�����е�λ��
		PNode Cur = _pRoot;
		PNode Parent = nullptr;
		while (Cur)
		{
			Parent = Cur;
			if (data == Cur->_data)
				break;
			else if (data < Cur->_data)
			{
				Cur = Cur->_pLeft;
			}
			else
			{
				Cur = Cur->_pRight;
			}
		}
			
		//data���ڶ������У��޷�ɾ��
		if (Cur == nullptr)	//Curһֱ�ߵ����û���ҵ�
			return false;

		//data�ڶ������У�Ҫ�ж����Һ��ӵ����
		if (nullptr == Cur->_pLeft)
		{
			//��ǰ�ڵ�û�����ӻ�������Ϊ��---ֱ��ɾ��
			
		}
		else if (nullptr == Cur->_pRight)
		{
			//��ǰ�ڵ�û���Һ��ӻ����Һ���Ϊ��---ֱ��ɾ��
		}
		else
		{
			//��ǰ�ڵ����Һ��Ӷ�����
		}
	}

private:
	PNode _pRoot;
};