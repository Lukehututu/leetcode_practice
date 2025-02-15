/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
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

    string dfs(TreeNode* node) {
        if(!node) return "";
        string serial = to_string(node->val) + "(" + dfs(node->left) + ")"+ "(" + dfs(node->right) + ")";
        auto it = seen.find(serial);
        if(it != seen.end()) {
            repeat.insert(it->second);
        }
        else {
            seen[serial] = node;
        }
        return serial;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return {repeat.begin(), repeat.end()};
    }

    unordered_map<string, TreeNode*> seen;
    unordered_set<TreeNode*> repeat;

};
// @lc code=end

