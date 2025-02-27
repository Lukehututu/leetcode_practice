/*
 * @lc app=leetcode.cn id=814 lang=cpp
 *
 * [814] 二叉树剪枝
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

    bool trimTree(TreeNode* root) {
        if(!root) return false;
        bool l = trimTree(root->left);
        bool r = trimTree(root->right);
        root->left = l ? root->left : nullptr;
        root->right = r ? root->right : nullptr;
        return (root->val == 1) || l || r;
    }

    TreeNode* pruneTree(TreeNode* root) {
        trimTree(root);
        if(!root->left && !root->right && (root->val == 0)) root = nullptr;
        return root;
    }
};
// @lc code=end

