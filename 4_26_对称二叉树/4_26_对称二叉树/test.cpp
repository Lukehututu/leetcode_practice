using namespace std;
#include<iostream>
#include<vector>
#include <string>

 /** Definition for a binary tree node.*/
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
      right(right) {}
  };
 
  class Solution {
  public:
      bool isSymmetricHelp(TreeNode* left, TreeNode* right) {
          if (!left && !right) return true;
          if (!left || !right) return false;

          return isSymmetricHelp(left->right, right->left) &&
              isSymmetricHelp(left->left, right->right) &&
              left->val == right->val;
      }

      bool isSymmetric(TreeNode* root) {
          return isSymmetricHelp(root->left, root->right);
      }
  };


