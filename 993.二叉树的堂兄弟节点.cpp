/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 二叉树的堂兄弟节点
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int dep = -1;

    bool traversal(TreeNode* root, int& x, int& y, int depth) {
        if(!root) return false;
        //是否是同一个父节点
        int i = 0, j = 0;
        if(root->left) i = root->left->val;
        if(root->right) j = root->right->val;
        if((i == x && j == y) || (i == y && j == x)) return false;
        
        //深度是否相同
        if(root->val == x || root->val == y) {
            if(dep != -1) {
                return dep == depth;
            }
            dep = depth;
            return false;
        }

        
        return traversal(root->left, x, y , depth + 1) 
        || traversal(root->right, x, y , depth + 1) ;
    }   

    bool isCousins(TreeNode* root, int x, int y) {
        return traversal(root, x, y, 1);
    }
};
// @lc code=end

