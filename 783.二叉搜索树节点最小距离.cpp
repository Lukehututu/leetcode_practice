/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
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

    void dfs(TreeNode* root, vector<int>& res) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left, res);
        res.push_back(root->val);
        dfs(root->right, res);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> res;
        dfs(root, res);
        int min = INT_MAX;
        for(int i = 0; i < res.size() - 1; i++) {
            if (res[i + 1] - res[i] < min) {
                min = res[i + 1] - res[i];
            }
        }
        return min;
    }
};
// @lc code=end

