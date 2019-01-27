#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//树的结构
typedef struct Node
{
	int val;
	struct Node *left;
	struct Node *right;
}	Node;




//递归前序遍历
void preorder(Node *root)
{
	if (root == NULL)//递归停下条件
		return;

	printf("%d ", root->val);

	preorder(root->left);
	preorder(root->right);
}




//递归中序遍历
void inorder(Node *root)
{
	if (root == NULL)//递归停下条件
		return;

	inorder(root->left);

	printf("%d ", root->val);

	inorder(root->right);
}




//递归后续遍历
void posorder(Node *root)
{
	if (root == NULL)//递归停下条件
		return;

	posorder(root->left);
	posorder(root->right);

	printf("%d ", root->val);
}




Node *BuyNode(int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	if (!node)
		exit(EXIT_FAILURE);

	node->val = val;
	node->left = node->right = NULL;

	return node;
}





void TestBinaryTreeOrder()
{
	Node *a = BuyNode(1);
	Node *b = BuyNode(2);
	Node *c = BuyNode(3);
	Node *d = BuyNode(4);
	Node *e = BuyNode(5);
	Node *f = BuyNode(6);
	Node *g = BuyNode(7);

	a->left = b;
	a->right = c;
	b->left = d;
	c->left = e;
	c->right = f;
	f->right = g;

	preorder(a);
	printf("\n");
	inorder(a);
	printf("\n");
	posorder(a);
	printf("\n");



}