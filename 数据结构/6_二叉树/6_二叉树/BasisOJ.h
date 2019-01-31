#pragma once

#include <stdio.h>
#include <stdlib.h>

//1. 二叉树的前序遍历
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




//2. 二叉树的中序遍历
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




//3. 二叉树的后序遍历
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




//4. 判断两棵二叉树是否是相同的树
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