/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
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

    void traversal(TreeNode* root, int val, int depth, int curDep) {
        if(!root) return;
        if(curDep == depth - 1) {
            TreeNode* lNode = new TreeNode(val);
            TreeNode* rNode = new TreeNode(val);
            lNode->left = root->left;
            rNode->right = root->right;
            root->left = lNode;
            root->right = rNode;
            return;
        }
        traversal(root->left, val, depth, curDep + 1);
        traversal(root->right, val, depth, curDep + 1);
        return;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }

        traversal(root, val, depth, 1);
        return root;
    }
};
// @lc code=end

