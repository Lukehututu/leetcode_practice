/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
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
    //先序遍历

    void preOrder(TreeNode* root, string& res) {
        if (!root) {
            res += "()";
            return;
        }
        res += '(';
        res += to_string(root->val);
        if (root->left || root->right) {
            preOrder(root->left, res);
            if(root->right)
                preOrder(root->right, res);
        }
        res += ')';
        return;
    }

    string tree2str(TreeNode* root) {
        if(!root) return "";
        string res = to_string(root->val);
        if(root->left || root->right) {
            preOrder(root->left, res);
            if(root->right)
                preOrder(root->right, res);
        }
        
        return res;
    }
};
// @lc code=end

