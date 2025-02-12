/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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

    vector<vector<int>> res;

    void traversal(TreeNode* root, int target, vector<int> nums) {
        //到叶子节点才终止
        if(!root->left && !root->right) {
            if(root->val == target) {
                nums.push_back(root->val);
                res.push_back(nums);
            }
        }
        else {
            nums.push_back(root->val);
            if(root->left) {
                traversal(root->left, target - root->val, nums);
            }
            if(root->right) {
                traversal(root->right, target - root->val, nums);
            }
        }
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        vector<int> nums;
        traversal(root, targetSum, nums);
        return res;
    }
};
// @lc code=end

