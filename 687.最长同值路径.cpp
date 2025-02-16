/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
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
    int res = 0;

    //只关注跟该点同值的最长路径 最大的已经记录在res中了
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int left = dfs(root->left), right = dfs(root->right);
        int left1{}, right1{};
        if(root->left && root->left->val == root->val) left1 = left + 1;
        if(root->right && root->right->val == root->val) right1 = right + 1;
        res = max(res, left1 + right1);
        return max(left1,right1); //只传递最长的同值的一边，因为是一整条路不能分叉
    }

    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return res;
    }
};
// @lc code=end

