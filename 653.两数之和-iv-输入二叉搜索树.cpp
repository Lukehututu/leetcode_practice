/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入二叉搜索树
 *
 * https://leetcode.cn/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (63.59%)
 * Likes:    516
 * Dislikes: 0
 * Total Accepted:    125.8K
 * Total Submissions: 198K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * 给定一个二叉搜索树 root 和一个目标结果 k，如果二叉搜索树中存在两个元素且它们的和等于给定的目标结果，则返回 true。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: root = [5,3,6,2,4,null,7], k = 9
 * 输出: true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入: root = [5,3,6,2,4,null,7], k = 28
 * 输出: false
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 二叉树的节点个数的范围是  [1, 10^4].
 * -10^4 <= Node.val <= 10^4
 * 题目数据保证，输入的 root 是一棵 有效 的二叉搜索树
 * -10^5 <= k <= 10^5
 * 
 * 
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

    void traversal(TreeNode* root, vector<int>& vec, int& k) {
        if(!root) return;
        vec.push_back(root->val);
        traversal(root->left, vec, k);
        traversal(root->right, vec, k);
        return;
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> vec;
        traversal(root, vec, k);
        sort(vec.begin(), vec.end());
        if(vec.size() == 0) return false;
        for(int i = 0; i < vec.size() - 1; ++i) {
            for(int j = i + 1; j < vec.size(); ++j) {
                if(vec[i] + vec[j] == k) return true;
            }
        }
        return false;
    }
};
// @lc code=end

