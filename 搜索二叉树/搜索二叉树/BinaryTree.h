#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>
#include<malloc.h>
#include<assert.h>

typedef int DataType;

typedef struct BSTreeNode
{
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;

	DataType _data;
}BSTreeNode;

/////////////////////////////////////////////////////// 
// 非递归 
BSTreeNode* BuyBSTreeNode(DataType x);
int BSTreeInsert(BSTreeNode** tree, DataType x);
const BSTreeNode* BSTreeFind(BSTreeNode* tree, DataType x);
int BSTreeRemove(BSTreeNode** tree, DataType x);
void BSTreeDestory(BSTreeNode* tree);

/////////////////////////////////////////////////////// 
// 递归 
int BSTreeInsertR(BSTreeNode** tree, DataType x);
const BSTreeNode* BSTreeFindR(BSTreeNode* tree, DataType x);
int BSTreeRemoveR(BSTreeNode** tree, DataType x);


/////////////////////////////////////////////////////// 
// 非递归 
BSTreeNode* BuyBSTreeNode(DataType x)
{
	BSTreeNode* node;
	node = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	assert(node);
	node->_data = x;
	node->_left = NULL;
	node->_right = NULL;
	return node;
}
int BSTreeInsert(BSTreeNode** tree, DataType x)
{
	assert(tree);
	BSTreeNode* cur = *tree;
	BSTreeNode* parent = NULL;
	if (tree = NULL)
	{
		*tree = BuyBSTreeNode(x);//空树直接插入
		return 0;
	}
	while (cur)//找到插入位置
	{
		if (cur->_data < x)
		{
			parent = cur;//记录父节点的位置
			cur = cur->_right;
		}
		else if (cur->_data > x)
		{
			parent = cur;
			cur = cur->_left;
		}
		else
			return 1;
	}
	if (parent->_data > x)
		parent->_left = BuyBSTreeNode(x);
	else if (parent->_data < x)
		parent->_right = BuyBSTreeNode(x);
}
const BSTreeNode* BSTreeFind(BSTreeNode* tree, DataType x)
{
	assert(tree);
	BSTreeNode* cur = tree;
	if (cur->_data == x)
	{
		return cur;
	}
	while (cur)
	{
		if (cur->_data < x)
			cur = cur->_right;
		else if (cur->_data > x)
			cur = cur->_left;
		else
			return cur;
	}
	return NULL;
}
int BSTreeRemove(BSTreeNode** tree, DataType x)
{
	assert(tree);
	BSTreeNode* cur = *tree;
	BSTreeNode* parent = NULL;
	//查找是否存在x
	while (cur)
	{
		if (cur->_data < x)
		{
			parent = cur;
			cur = cur->_right;
		}
		else if (cur->_data > x)
		{
			parent = cur;
			cur = cur->_left;
		}
		else // cur->_data = x
		{
			break;
		}

	}	
	
	// 没找到，X不在二叉树中
	if (cur == NULL)
		{
			printf("x不在二叉树中\n");
			return -1;
		}

	//找到了，分情况讨论
	// 1.要删除的结点没有左孩子，即只有右孩子或者左右孩子都没有
	if (cur->_left == NULL)
	{
		if (cur == *tree)
			*tree = cur->_right;
		else
		{
			if (cur == parent->_left)
			{
				parent->_left = cur->_right;
			}
			else
			{
				parent->_right = cur->_right;
			}
		}
	}
	// 2.要删除的结点没有右孩子，即只有左孩子或者左右孩子都没有
	else if (cur->_right == NULL)
	{
		if (cur == *tree)
			*tree = cur->_left;
		else
		{
			if (cur == parent->_left)
			{
				parent->_left = cur->_left;
			}
			else
			{
				parent->_right = cur->_left;
			}
		}
	}
	// 3.要删除的孩子有左孩子和右孩子,在右子树找到最小的结点，替代删除结点
	else
	{
		BSTreeNode* Del = cur->_right;
		BSTreeNode* parent = cur;
		while (Del->_left)   // 找到最小的结点
		{
			parent = Del;
			Del = Del->_left;
		}
		cur->_data = Del->_data;
		if (Del = parent->_left)
			parent->_left = Del->_right;
		else
			parent->_right = Del->_right;
		cur = Del;
		free(Del);	
	}

}
void BSTreeDestory(BSTreeNode* tree);

/////////////////////////////////////////////////////// 
// 递归 
int BSTreeInsertR(BSTreeNode** tree, DataType x)
{
	if (tree == NULL)
	{
		*tree = BuyBSTreeNode(x);
		return 1;
	}
	else
	{
		if ((*tree)->_data > x)
			BSTreeInsertR(&(*tree)->_left, x);
		else if ((*tree)->_data < x)
			BSTreeInsertR(&(*tree)->_right, x);
		else
			return 1;
	}
}
const BSTreeNode* BSTreeFindR(BSTreeNode* tree, DataType x)
{
	if (tree == NULL)
		printf("树为空\n");
	while (tree)
	{
		if (tree->_data == x)
			return tree;
		else if (tree->_data > x)
		{
			BSTreeFindR(tree->_left, x);
		}
		else if (tree->_data < x)
		{
			BSTreeFindR(tree->_right, x);
		}
		else
			return 0;
	}
	return 0;
}
int BSTreeRemoveR(BSTreeNode** tree, DataType x)
{
	if (NULL == *tree)
	{
		return 0;
	}
	if (x == (*tree)->_data)
		return 1;
	else if (x > (*tree)->_data)
		return BSTreeRemoveR(&(*tree)->_right, x);
	else if (x < (*tree)->_data)
		return BSTreeRemoveR(&(*tree)->_left, x);
	else
	{
		BSTreeNode* Del = *tree;
		if (NULL == Del->_left)
			(*tree) = Del->_right;
		else if (NULL == Del->_right)
			(*tree) = Del->_left;
		else
		{
			//左右子树都存在
			BSTreeNode* Del = (*tree)->_right;
			while (Del->_left)
			{
				Del = Del->_left;
			}
			(*tree)->_data = Del->_data;
			return BSTreeRemoveR(&(*tree)->_right, Del->_data);
		}
	}
}
void BSTreeInOrder(BSTreeNode* root)
{
	if (root == NULL)
		return;
	BSTreeInOrder(root->_left);
	printf("%s", root->_data);
	BSTreeInOrder(root->_right);
}
void TestBSTree() 
{ 
 //BSTreeNode* tree = NULL; 
 //BSTreeInsert(&tree, 4); 
 //BSTreeInsert(&tree, 2); 
 //BSTreeInsert(&tree, 1); 
 //BSTreeInsert(&tree, 3); 
 //BSTreeInsert(&tree, 2); 
 
 //const BSTreeNode* node = BSTreeFind(tree, 2); 
 //printf("Find 2? %d\n", node->_data); 
 
 int a[] = {5,3,4,1,7,8,2,6,0,9}; 
 BSTreeNode* tree = NULL; 
 
 for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i) 
 { 
 BSTreeInsert(&tree, a[i]); 
 } 
 
 BSTreeInOrder(tree); 
 printf("\n"); 
 
 BSTreeRemove(&tree, 4); 
 BSTreeRemove(&tree, 8); 
 BSTreeRemove(&tree, 3); 
 BSTreeRemove(&tree, 7); 
 BSTreeRemove(&tree, 5); 
 
 BSTreeInOrder(tree); 
 printf("\n"); 
 
 BSTreeRemove(&tree, 0); 
 BSTreeRemove(&tree, 1); 
 BSTreeRemove(&tree, 2); 
 BSTreeRemove(&tree, 3); 
 BSTreeRemove(&tree, 4); 
 BSTreeRemove(&tree, 5); 
 BSTreeRemove(&tree, 6); 
 BSTreeRemove(&tree, 7); 
 BSTreeRemove(&tree, 8); 
 BSTreeRemove(&tree, 9); 
 
 BSTreeInOrder(tree); 
 printf("\n"); 
}; 