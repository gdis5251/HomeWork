#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//树的结构
typedef struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}	TreeNode;




//构建树的根结点
typedef struct Result
{
	struct TreeNode *root;
	int used;
}	Result;




//根据字符串创建树
Result CreateTree(const char *preorder, int size)
{
	if (size == 0)
	{
		Result result;
		result.root = NULL;
		result.used = 0;

		return result;
	}

	char rootVal = preorder[0];
	if (rootVal == '#')
	{
		Result result;
		result.root = NULL;
		result.used = 1;

		return result;
	}
	
	TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
	root->val = rootVal;
	root->left = root->right = NULL;

	Result leftResult = CreateTree(preorder + 1, size - 1);//左递归
	Result rightResult = CreateTree(preorder + 1 + leftResult.used, size - 1 - leftResult.used);//右递归

	root->left = leftResult.root;
	root->right = rightResult.root;

	Result result;
	result.root = root;
	result.used = 1 + leftResult.used + rightResult.used;

	return result;
}




//求二叉树所有结点个数
//遍历的思想
void TreeSize(TreeNode *root, int *size)
{
	if (root == NULL)
		return;

	(*size)++;
	TreeSize(root->left, size);
	TreeSize(root->right, size);
}

//递归的思想
int TreeSize2(TreeNode *root)
{
	if (root == NULL)
		return 0;

	return 1 + TreeSize2(root->left) + TreeSize2(root->right);
}




//叶子结点个数
//遍历的思想
void LeafSize(TreeNode *root, int *size)
{
	if (root == NULL)
		return;

	if (root->left == NULL && root->right == NULL)
		(*size)++;
	
	LeafSize(root->left, size);
	LeafSize(root->right, size);
}

//递归的思想
int LeafSize2(TreeNode *root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;


	return LeafSize2(root->left) + LeafSize2(root->right);
}




//求第K层的结点个数
//递归的思想
int LevelK(TreeNode *root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;

	return LevelK(root->left, k - 1) + LevelK(root->right, k - 1);

}




//查找元素是X的结点
TreeNode *FindX(TreeNode *root, int x)
{
	if (root == NULL)
		return NULL;

	if (root->val == x)
		return root;

	TreeNode *result = FindX(root->left, x);
	if (result != NULL)
		return result;

	//走到这里说明左子树没有找到
	result = FindX(root->right, x);
	if (result != NULL)
		return result;
	else
		return NULL;
}




//层序遍历
//需要用到队列，为了方便起见，这里用C++去写
#include <queue>

void LevelOrderTraversal(TreeNode *root)
{
	if (root == NULL)
		return;


	std::queue<TreeNode *> qu;
	qu.push(root);

	//用队列来一层一层的遍历树
	while (!qu.empty())
	{
		TreeNode *front = qu.front();
		qu.pop();

		printf("%c ", front->val);

		if (front->left != NULL)
			qu.push(front->left);
		if (front->right != NULL)
			qu.push(front->right);
	}

}






//判断是否是完全二叉树
bool IsCompeleteBinaryTree(TreeNode *root)
{
	if (root == NULL)
		return true;

	std::queue<TreeNode *> qu;

	qu.push(root);

	//遇到空结点之前，把所有的结点都放进去
	while (1)
	{
		TreeNode *front = qu.front();
		qu.pop();

		if (front == NULL)
			break;

		qu.push(front->left);
		qu.push(front->right);

	}

	while (!qu.empty())
	{
		TreeNode *front = qu.front();
		if (front != NULL)
			return false;

		qu.pop();
	}

	return true;
}






//二叉树的前|中|后序遍历的非递归版本
//用栈来实现
#include <stack>

//前序遍历
void PreOrderTraversalNor(TreeNode *root)
{
	if (root == NULL)
		return;

	TreeNode *cur = root;	//遍历树结点的指针
	TreeNode *top = NULL;	//栈顶指针
	
	std::stack<TreeNode *> st;

	while (!st.empty() || cur != NULL)
	{
		//第一次访问
		while (cur != NULL)
		{
			printf("%c ", cur->val);
			st.push(cur);
			cur = cur->left;
		}

		//第二次和第三次访问
		//因为是前序遍历所以这里不区分
		top = st.top();
		cur = top->right;
		st.pop();
	}
}


//中序遍历
void InOrderTraversalNor(TreeNode *root)
{
	if (root == NULL)
		return;

	TreeNode *cur = root;
	TreeNode *top = NULL;

	std::stack<TreeNode *> st;

	while (!st.empty() || cur != NULL)
	{	
		//第一次访问
		while (cur != NULL)
		{
			st.push(cur);
			cur = cur->left;
		}

		top = st.top();
		//第二次访问也是第三次访问
		printf("%c ", top->val);
		cur = top->right;
		st.pop();
	}
}

//后序遍历
void PosOrderTraversalNor(TreeNode *root)
{
	if (root == NULL)
		return;

	TreeNode *cur = root;
	TreeNode *top = NULL;
	TreeNode *last = NULL;

	std::stack<TreeNode *> st;

	while (!st.empty() || cur != NULL)
	{
		//第一次访问
		while (cur != NULL)
		{
			st.push(cur);
			cur = cur->left;
		}

		top = st.top();

		//第二次也是第三次访问
		if (top->right == NULL)
		{
			printf("%c ", top->val);
			cur = top->right;
			st.pop();
			last = top;
		}
		else
		{
			//第二次访问
			if (top->right != last)
				cur = top->right;
			//第三次访问
			else
			{
				printf("%c ", top->val);
				st.pop();
				last = top;
			}

		}
	}
}






//测试
void Test()
{
	//构建一颗二叉树
	const char *tree = "abd###c#ef";
	int len = strlen(tree);
	Result r = CreateTree(tree, len);


#if 0
	//求二叉树的结点个数
	int size = 0;
	//TreeSize(r.root, &size); 遍历的思想
	size = TreeSize2(r.root); //递归的思想
	printf("%d\n", size);
#endif

#if 0
	//求二叉树叶子节点个数
	int size = 0;
	//LeafSize(r.root, &size);	//遍历的思想
	size = LeafSize2(r.root);	//递归的思想
	printf("%d\n", size);
#endif


#if 0
	//求第K层结点个数
	int size = 0;
	size = LevelK(r.root, 2);
	printf("%d\n", size);
#endif




	//层序遍历
	LevelOrderTraversal(r.root);
	printf("\n");
	//非递归前序遍历
	PreOrderTraversalNor(r.root);
	printf("\n");
	//非递归中序遍历
	InOrderTraversalNor(r.root);
	printf("\n");
	//非递归后序遍历
	PosOrderTraversalNor(r.root);
	printf("\n");
}
