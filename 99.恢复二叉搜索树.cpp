/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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

    void traversal(vector<int>& arr, TreeNode* root) {
        if(!root) return;
        traversal(arr, root->left);
        arr.push_back(root->val);
        traversal(arr, root->right);
        return; 
    }
    int i = 0;
    void update(vector<int>& arr, TreeNode* root) {
        if(!root) return;
        update(arr, root->left);
        root->val = arr[i++];
        update(arr, root->right);
        return; 
    }

    void recoverTree(TreeNode* root) {
        vector<int> arr;
        traversal(arr, root);
        sort(arr.begin(), arr.end());
        update(arr, root);
        return;
    }
};
// @lc code=end

