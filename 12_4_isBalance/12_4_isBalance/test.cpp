#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>


// * Definition for a binary tree node.
  typedef struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  }*Tree,TreeNode;



int height(struct TreeNode* root);


//Ӧ����һ���ȸ�����---����˵���϶��µ��ж�


bool isBalanced(struct TreeNode* root) {
    if (root == NULL)
        return true;
    if (height(root->left) - height(root->right) >= -1 && root->left - root->right <= 1)//��ǰ���ƽ���ȡ�ж����ӽڵ�
    {
        if (isBalanced(root->left) && isBalanced(root->right))//
            return true;
        else
            return false;
    }
    else
        return false;
}


int height(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    else
    {
        int l = height(root->left);
        int r = height(root->right);
        return l > r ? l + 1 : r + 1;
    }
    return 0;
}

