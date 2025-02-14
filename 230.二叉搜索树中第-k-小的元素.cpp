/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第 K 小的元素
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

    int index = 0;
    int res = 0;

    void traversal(TreeNode* root, int k) {
        if(!root) return;
        traversal(root->left, k);
        index++;
        if(index == k) {
            res = root->val;
            return;
        }
        traversal(root->right, k);
        return;
    }   

    int kthSmallest(TreeNode* root, int k) {
        traversal(root, k);
        return res;
    }
};
// @lc code=end

