/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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

    vector<TreeNode*> generateTrees(int start, int end) {
        if(start > end) return{nullptr};
        vector<TreeNode*> trees;

        //枚举每一个值当当前根节点
        for(int i = start; i <= end; ++i ) {
            //分别给左边和右边都生成
            auto left = generateTrees(start, i - 1);
            auto right = generateTrees(i + 1, end);
            //左子树任意选一颗
            for(auto l : left) {
                //匹配右子树任意选一颗
                for(auto r : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    trees.emplace_back(root);
                }
            }
        }
        return trees;
    }

    vector<TreeNode*> generateTrees(int n) {
        if(!n) return {};

        return generateTrees(1, n);
    }
};
// @lc code=end

