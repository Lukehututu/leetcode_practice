#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>

//Definition for a binary tree node.
struct TreeNode {
   int val;
   struct TreeNode* left;
   struct TreeNode* right;
   
};

int minDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    else
    {
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        if (r > 0 && l > 0)
            return r > l ? l + 1 : r + 1;
        else
            return l > r ? l + 1 : r + 1;
    }
}