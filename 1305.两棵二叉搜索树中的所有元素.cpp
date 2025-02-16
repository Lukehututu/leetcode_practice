/*
 * @lc app=leetcode.cn id=1305 lang=cpp
 *
 * [1305] 两棵二叉搜索树中的所有元素
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

    void dfs(TreeNode* root, vector<int>& vec) {
        if(!root) return;
        dfs(root->left, vec);
        vec.push_back(root->val);
        dfs(root->right, vec);
        return;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> vec1, vec2;
        dfs(root1, vec1);
        dfs(root2, vec2);
        vector<int> res;
        int n = vec1.size();
        int m = vec2.size();
        int i = 0, j = 0;
        for(; i < n && j < m;) {
            if(vec1[i] < vec2[j]) {
                res.push_back(vec1[i++]);
            }
            else if(vec1[i] >= vec2[j]) {
                res.push_back(vec2[j++]);
            }
        }
        if(i == n) {//把j的全部放进去
            while(j < m) 
                res.push_back(vec2[j++]);
        }
        else {//把i剩下的放进去
            while(i < n) 
                res.push_back(vec1[i++]);
        }
        return res;
    }
};
// @lc code=end

