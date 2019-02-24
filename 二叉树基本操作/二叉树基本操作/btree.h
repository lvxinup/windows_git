#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>
#include<malloc.h>


typedef int BTDataType;

//typedef struct TreeNode 
//{ 
// BTDataType _data; 
// struct TreeNode* _firstChild; 
// struct TreeNode* _nextBrother; 
//}TreeNode; 

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
	BTDataType _data;
}BTNode;


BTNode* BuyBTNode(BTDataType x)
{
	BTNode* newnode;
	newnode = (BTNode*)malloc(sizeof(BinaryTreeNode));
	if (newnode == NULL)
		return;
	newnode->_data = x;
	newnode->_left = NULL;
	newnode->_right = NULL;
	return newnode;
}
// 创建二叉树 
BTNode* CreateBTree(BTDataType* a, size_t* pIndex, BTDataType invalid)
{
	BTNode* root;
	if (pIndex == 0)
		return;
	while (pIndex)
	{
		root = (BTNode*)malloc(sizeof(BTDataType));
		root->_data = invalid;
		root->_left = CreateBTree(a, pIndex, '#');
		root->_right = CreateBTree(a, pIndex, '#');
	}
	return root;
}
void BTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%s", root->_data);
	BTreePrevOrder(root->_left);
	BTreePrevOrder(root->_right);
}
void BTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BTreePrevOrder(root->_left);
	printf("%s", root->_data);
	BTreePrevOrder(root->_right);
}
void BTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BTreePrevOrder(root->_left);
	BTreePrevOrder(root->_right);
	printf("%s", root->_data);
}
size_t BTreeSize(BTNode* root)
{
	if (root == NULL)
		return;
	else
	{
		return(BTreeSize(root->_left) + BTreeSize(root->_right) + 1);
	}
}
size_t BTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return;
	if (root->_left)
	{
		return  BTreeLeafSize(root->_left) + 1;
	}
	if (root->_right)
	{
		return  BTreeLeafSize(root->_right) + 1;
	}
}
size_t BTreeKLevelSize(BTNode* root, size_t k)
{
	if (root == NULL)
		return;
	while (k--)
	{
		return BTreeKLevelSize(root->_left, k) + BTreeKLevelSize(root->_right, k)+1;
	}

}
int MaxOfTwo(int a, int b)
{
	if (a >= b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
size_t BTreeDepth(BTNode* root)
{
	if (root == NULL)
		return;
	else
	{
		return MaxOfTwo(BTreeDepth(root->_left), BTreeDepth(root->_right)) + 1;
	}
}
BTNode* BTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return;
	if (root->_data == x)
		return root;
	else
	{
		BTreeFind(root->_left, x);
		BTreeFind(root->_right, x);
	}

}
void BTreeLevelOrder(BTNode* root);
// 判断完全二叉树 
int IsCompleteBTree(BTNode* root);
int IsCompleteBTree1(BTNode* root);// flag的方式判断 
// 非递归遍历 
void BTreePrevOrderNonR(BTNode* root);
void BTreeInOrderNonR(BTNode* root);
void BTreePostOrderNonR(BTNode* root);

void TestBinaryTree()
{
	int a[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6, '#', '#', '#' };
	size_t index = 0;
	BTNode* tree = CreateBTree(a, &index, '#');
	BTreePrevOrder(tree);
	printf("\n");
	BTreePrevOrderNonR(tree);
	BTreeInOrder(tree);
	printf("\n");
	BTreePostOrder(tree);
	printf("\n");

	printf("BTreeSize?%d\n", BTreeSize(tree));
	printf("BTreeLeafSize?%d\n", BTreeLeafSize(tree));
	printf("BTreeKLevelSize?%d\n", BTreeKLevelSize(tree, 2));
	printf("BTreeDepth?%d\n", BTreeDepth(tree));
	printf("IsCompleteBTree?%d\n", IsCompleteBTree1(tree));
	BTreeLevelOrder(tree);
}