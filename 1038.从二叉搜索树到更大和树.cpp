/*
 * @lc app=leetcode.cn id=1038 lang=cpp
 *
 * [1038] 从二叉搜索树到更大和树
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

    void dfs(TreeNode* root, int& num) {
        if(!root) return;
        dfs(root->right, num);
        root->val += num;
        num = root->val;
        dfs(root->left, num);
        return;
    }

    TreeNode* bstToGst(TreeNode* root) {
        int num = 0;
        dfs(root, num);
        return root;
    }
};
// @lc code=end

