/*
 * @lc app=leetcode.cn id=655 lang=cpp
 *
 * [655] 输出二叉树
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

    int getHeight(TreeNode* root) {
        if(!root) return 0;
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        return l > r ? (l + 1) : (r + 1);
    }

    void fillMatrix(TreeNode* root, vector<vector<string>>& matrix, int c, int r, int height) {
        int p = pow(2, (height - r - 1));
        if(root->left) {
            matrix[r + 1][c - p] = to_string(root->left->val);
            fillMatrix(root->left, matrix, c - p, r + 1, height);
        }
        if(root->right) {
            matrix[r + 1][c + p] = to_string(root->right->val);
            fillMatrix(root->right, matrix, c + p, r + 1, height);
        }
    }

    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root) - 1;
        int m = height + 1;
        int n = pow(2, (height + 1)) - 1;
        vector<vector<string>> matrix(m, vector<string>(n, ""));
        matrix[0][(n - 1) / 2] = to_string(root->val);
        fillMatrix(root,matrix, (n - 1) / 2, 0, height);
        fillMatrix(root,matrix, (n - 1) / 2, 0, height);
        return matrix;
    }
};
// @lc code=end

