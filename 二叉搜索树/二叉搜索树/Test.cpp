#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<Windows.h>

template <class T>
struct BSTNode		//二叉树结点
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
	BSTree()	//构造函数
		:_pRoot(nullptr)
	{}

	~BSTree()
	{
		_Destroy(_pRoot);
	}

	PNode Find(const T& data)	//二叉树的查找
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

		return nullptr;	//走到这里说明没有找到
	}

	bool Insert(const T& data)
	{
		//a.树为空，直接插入
		if (_pRoot == nullptr)
		{
			_pRoot = new Node(data);
			return true;
		}

		//b.树不空，按二叉搜索树性质查找插入位置，插入新节点。
		PNode Cur = _pRoot;
		PNode Parent = nullptr;

		while (Cur)	//先找到要插入的位置
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
			else	//元素已经在树中存在
			{
				return false;
			}
		}

		//插入元素
		Cur = new Node(data);
		if (data < Cur->_data)
			Parent->_pLeft = Cur;
		else
			Parent->_pRight = Cur;

		return true;
	}

	bool Erase(const T& data)
	{
		if (_pRoot == nullptr)	//树为空，则删除失败
			return false;

		//查找data在树中的位置
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
			
		//data不在二叉树中，无法删除
		if (Cur == nullptr)	//Cur一直走到最后还没有找到
			return false;

		//data在二叉树中，要判断左右孩子的情况
		if (nullptr == Cur->_pLeft)
		{
			//当前节点没有左孩子或者左孩子为空---直接删除
			
		}
		else if (nullptr == Cur->_pRight)
		{
			//当前节点没有右孩子或者右孩子为空---直接删除
		}
		else
		{
			//当前节点左右孩子都存在
		}
	}

private:
	PNode _pRoot;
};