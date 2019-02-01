#pragma once

#include <stdio.h>
#include <stdlib.h>

//1. ��������ǰ�����
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 /**
  * Return an array of size *returnSize.
  * Note: The returned array must be malloced, assume caller calls free().
  */
int *array;
int size;

void _preorderTraversal(struct TreeNode *root)
{
	if (root == NULL)
		return;

	array[size++] = root->val;
	_preorderTraversal(root->left);
	_preorderTraversal(root->right);
}


int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	array = (int *)malloc(sizeof(int) * 100 * 1000);
	size = 0;

	_preorderTraversal(root);

	*returnSize = size;

	return array;

}




//2. ���������������
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 /**
  * Return an array of size *returnSize.
  * Note: The returned array must be malloced, assume caller calls free().
  */
int *array;
int size;

void _inorderTraversal(struct TreeNode *root)
{
	if (root == NULL)
		return;

	_inorderTraversal(root->left);
	array[size++] = root->val;
	_inorderTraversal(root->right);


}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	size = 0;
	array = (int *)malloc(sizeof(int) * 100 * 10000);

	_inorderTraversal(root);

	*returnSize = size;
	return array;
}




//3. �������ĺ������
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 /**
  * Return an array of size *returnSize.
  * Note: The returned array must be malloced, assume caller calls free().
  */

int *array;
int size;

void _postorderTraversal(struct TreeNode *root)
{
	if (root == NULL)
		return;

	_postorderTraversal(root->left);
	_postorderTraversal(root->right);
	array[size++] = root->val;



}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
	size = 0;
	array = (int *)malloc(sizeof(int) * 100 * 10000);

	_postorderTraversal(root);

	*returnSize = size;
	return array;
}




//4. �ж����ö������Ƿ�����ͬ����
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (!p && !q)
		return true;
	if (!p || !q)
		return false;

	return p->val == q->val &&\
		isSameTree(p->left, q->left) && \
		isSameTree(p->right, q->right);
}




//5. �ж�һ�����Ƿ�����һ����������
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 //����������Ƿ���ͬ
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (!p && !q)
		return true;
	if (!p || !q)
		return false;

	return p->val == q->val &&\
		isSameTree(p->left, q->left) && \
		isSameTree(p->right, q->right);
}

//ǰ�����s��
preorderTraversal(struct TreeNode *s, struct TreeNode *t)
{
	if (!s)
		return false;

	if (s->val == t->val && isSameTree(s, t))
		return true;

	bool left_ret = preorderTraversal(s->left, t);
	if (left_ret)
		return true;

	return preorderTraversal(s->right, t);
}


bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
	if (t == NULL)
		return true;

	return preorderTraversal(s, t);
}





//6. ��������������
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
	if (!root)
		return 0;

	int left = maxDepth(root->left);
	int right = maxDepth(root->right);

	return (left > right ? left : right) + 1;
}




//7.�ж�һ�����Ƿ���ƽ�������
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
	if (!root)
		return 0;

	int left = maxDepth(root->left);
	int right = maxDepth(root->right);

	return (left > right ? left : right) + 1;
}

bool isBalanced(struct TreeNode* root) {
	if (!root)
		return true;

	bool left = isBalanced(root->left);
	if (!left)
		return false;

	bool right = isBalanced(root->right);
	if (!right)
		return false;

	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);

	int diff = leftDepth - rightDepth;
	if (diff >= -1 && diff <= 1)
		return true;

	return false;
}




//8. �ж�һ�����Ƿ�Գ�
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isMirror(struct TreeNode *p, struct TreeNode *q)
{
	if (!p && !q)
		return true;

	if (!p || !q)
		return false;

	return p->val == q->val &&\
		isMirror(p->left, q->right) && \
		isMirror(p->right, q->left);
}
bool isSymmetric(struct TreeNode* root) {
	if (!root)
		return true;

	return isMirror(root->left, root->right);
}