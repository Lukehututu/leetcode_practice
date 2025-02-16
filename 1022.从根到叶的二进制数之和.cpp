/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
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
    int sum = 0;

    void backtrace(TreeNode* root, string num) {
        if(!root) return;
        if(!root->left && !root->right) {
            num += root->val + '0';
            int plus = stoi(num, nullptr, 2);
            sum += plus;
        }
        else {
            num += root->val + '0';
            backtrace(root->left, num);
            backtrace(root->right, num);
        }
    } 


    int sumRootToLeaf(TreeNode* root) {
        backtrace(root, "");
        return sum;
    }
};
// @lc code=end

