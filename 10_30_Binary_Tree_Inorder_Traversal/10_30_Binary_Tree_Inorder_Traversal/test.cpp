#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

void Inorder(struct TreeNode* p, int* arr, int* pi)
{
	if (p == NULL)
		return;
	else
	{
		Inorder(p->left, arr, pi);
		arr[*pi] = p->val;
		Inorder(p->right, arr, pi);
	}
	(*pi)++;
}




/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
	int* retarr = (int*)malloc(10 * sizeof(int));
	returnSize = retarr;
	int i = 0;
	int* pi = &i;
	Inorder(root, returnSize, pi);
	return returnSize;
}




int main()
{
	TreeNode* pc = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* root = pc;
	root->val = 1;
	root->left = NULL;
	root->right = NULL;


}