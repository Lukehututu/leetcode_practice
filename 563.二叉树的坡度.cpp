/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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

    //1.
    // int Sum(TreeNode* root) {
    //     if(!root) return 0;
    //     int l = Sum(root->left);
    //     int r = Sum(root->right);
    //     return l + r + root->val;
    // }

    // int findTilt(TreeNode* root) {
    //     if(!root) return 0;
    //     //子树节点之和 
    //     //节点坡度之和
    //     int left = findTilt(root->left);
    //     int right = findTilt(root->right);

    //     int lSum = Sum(root->left);
    //     int rSum = Sum(root->right);

    //     return left + right + abs(lSum - rSum);
    // }

    //2.采用ans来记录 不用双重递归算大小
    int ans = 0;
    int dfs(TreeNode* root) {
        if(!root) return 0;

        int leftSum = dfs(root->left);
        int rightSum = dfs(root->right);

        ans += abs(leftSum - rightSum);
        return leftSum + rightSum + root->val;
    }

    int findTilt(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return ans;
    }
};
// @lc code=end

