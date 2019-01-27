#pragma once

#include <stdio.h>
#include <stdlib.h>

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
Result CreateTree(char *preorder, int size)
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