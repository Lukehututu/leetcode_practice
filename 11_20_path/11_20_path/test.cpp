#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>





  struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
  };


bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL)
        return false;
    if (root->left == NULL && root->right == NULL) {
        return targetSum == root->val;
    }
    return hasPathSum(root->left, targetSum - root->val) ||
        hasPathSum(root->right, targetSum - root->val);
}