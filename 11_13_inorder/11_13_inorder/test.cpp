#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<stdlib.h>



struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};
 


void inorder(struct TreeNode* root, int* pt)
{
    static int i = 0;
    if (root != NULL)
    {
        inorder(root->left, pt);
        pt[i] = root->val;
        i++;
        inorder(root->right, pt);
    }
}



int* inorderTraversal(struct TreeNode* root, int* returnSize)
{

   /* int* pt = (int*)malloc(20 * sizeof(int));*/
    int pt[10] = { 0 };
    inorder(root, pt);
    returnSize = pt;
    return returnSize;
}



int main()
{
    TreeNode* root = (TreeNode*)malloc(1 * sizeof(TreeNode));
    root->val = 1;
    root->left = NULL;
    TreeNode* p2 = (TreeNode*)malloc(1 * sizeof(TreeNode));
    root->right = p2;
    p2->val = 2;
    p2->right = NULL;
    TreeNode* p3 = (TreeNode*)malloc(1 * sizeof(TreeNode));
    p2->left = p3;
    p3->val = 3;
    p3->left = NULL;
    p3->right = NULL;

    int* returnSize=NULL;

    inorderTraversal(root, returnSize);


}