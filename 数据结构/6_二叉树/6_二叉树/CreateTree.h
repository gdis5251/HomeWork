#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//���Ľṹ
typedef struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}	TreeNode;




//�������ĸ����
typedef struct Result
{
	struct TreeNode *root;
	int used;
}	Result;




//�����ַ���������
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

	Result leftResult = CreateTree(preorder + 1, size - 1);//��ݹ�
	Result rightResult = CreateTree(preorder + 1 + leftResult.used, size - 1 - leftResult.used);//�ҵݹ�

	root->left = leftResult.root;
	root->right = rightResult.root;

	Result result;
	result.root = root;
	result.used = 1 + leftResult.used + rightResult.used;

	return result;
}




//����������н�����
//������˼��
void TreeSize(TreeNode *root, int *size)
{
	if (root == NULL)
		return;

	(*size)++;
	TreeSize(root->left, size);
	TreeSize(root->right, size);
}

//�ݹ��˼��
int TreeSize2(TreeNode *root)
{
	if (root == NULL)
		return 0;

	return 1 + TreeSize2(root->left) + TreeSize2(root->right);
}




//Ҷ�ӽ�����
//������˼��
void LeafSize(TreeNode *root, int *size)
{
	if (root == NULL)
		return;

	if (root->left == NULL && root->right == NULL)
		(*size)++;
	
	LeafSize(root->left, size);
	LeafSize(root->right, size);
}

//�ݹ��˼��
int LeafSize2(TreeNode *root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;


	return LeafSize2(root->left) + LeafSize2(root->right);
}




//���K��Ľ�����
//�ݹ��˼��
int LevelK(TreeNode *root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;

	return LevelK(root->left, k - 1) + LevelK(root->right, k - 1);

}




//����Ԫ����X�Ľ��
TreeNode *FindX(TreeNode *root, int x)
{
	if (root == NULL)
		return NULL;

	if (root->val == x)
		return root;

	TreeNode *result = FindX(root->left, x);
	if (result != NULL)
		return result;

	//�ߵ�����˵��������û���ҵ�
	result = FindX(root->right, x);
	if (result != NULL)
		return result;
	else
		return NULL;
}




//�������
//��Ҫ�õ����У�Ϊ�˷��������������C++ȥд
#include <queue>

void LevelOrderTraversal(TreeNode *root)
{
	if (root == NULL)
		return;


	std::queue<TreeNode *> qu;
	qu.push(root);

	//�ö�����һ��һ��ı�����
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






//�ж��Ƿ�����ȫ������
bool IsCompeleteBinaryTree(TreeNode *root)
{
	if (root == NULL)
		return true;

	std::queue<TreeNode *> qu;

	qu.push(root);

	//�����ս��֮ǰ�������еĽ�㶼�Ž�ȥ
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






//��������ǰ|��|��������ķǵݹ�汾
//��ջ��ʵ��
#include <stack>

//ǰ�����
void PreOrderTraversalNor(TreeNode *root)
{
	if (root == NULL)
		return;

	TreeNode *cur = root;	//����������ָ��
	TreeNode *top = NULL;	//ջ��ָ��
	
	std::stack<TreeNode *> st;

	while (!st.empty() || cur != NULL)
	{
		//��һ�η���
		while (cur != NULL)
		{
			printf("%c ", cur->val);
			st.push(cur);
			cur = cur->left;
		}

		//�ڶ��κ͵����η���
		//��Ϊ��ǰ������������ﲻ����
		top = st.top();
		cur = top->right;
		st.pop();
	}
}


//�������
void InOrderTraversalNor(TreeNode *root)
{
	if (root == NULL)
		return;

	TreeNode *cur = root;
	TreeNode *top = NULL;

	std::stack<TreeNode *> st;

	while (!st.empty() || cur != NULL)
	{	
		//��һ�η���
		while (cur != NULL)
		{
			st.push(cur);
			cur = cur->left;
		}

		top = st.top();
		//�ڶ��η���Ҳ�ǵ����η���
		printf("%c ", top->val);
		cur = top->right;
		st.pop();
	}
}

//�������
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
		//��һ�η���
		while (cur != NULL)
		{
			st.push(cur);
			cur = cur->left;
		}

		top = st.top();

		//�ڶ���Ҳ�ǵ����η���
		if (top->right == NULL)
		{
			printf("%c ", top->val);
			cur = top->right;
			st.pop();
			last = top;
		}
		else
		{
			//�ڶ��η���
			if (top->right != last)
				cur = top->right;
			//�����η���
			else
			{
				printf("%c ", top->val);
				st.pop();
				last = top;
			}

		}
	}
}






//����
void Test()
{
	//����һ�Ŷ�����
	const char *tree = "abd###c#ef";
	int len = strlen(tree);
	Result r = CreateTree(tree, len);


#if 0
	//��������Ľ�����
	int size = 0;
	//TreeSize(r.root, &size); ������˼��
	size = TreeSize2(r.root); //�ݹ��˼��
	printf("%d\n", size);
#endif

#if 0
	//�������Ҷ�ӽڵ����
	int size = 0;
	//LeafSize(r.root, &size);	//������˼��
	size = LeafSize2(r.root);	//�ݹ��˼��
	printf("%d\n", size);
#endif


#if 0
	//���K�������
	int size = 0;
	size = LevelK(r.root, 2);
	printf("%d\n", size);
#endif




	//�������
	LevelOrderTraversal(r.root);
	printf("\n");
	//�ǵݹ�ǰ�����
	PreOrderTraversalNor(r.root);
	printf("\n");
	//�ǵݹ��������
	InOrderTraversalNor(r.root);
	printf("\n");
	//�ǵݹ�������
	PosOrderTraversalNor(r.root);
	printf("\n");
}
