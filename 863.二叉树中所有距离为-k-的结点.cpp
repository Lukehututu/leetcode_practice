/*
 * @lc app=leetcode.cn id=863 lang=cpp
 *
 * [863] 二叉树中所有距离为 K 的结点
 *
 * https://leetcode.cn/problems/all-nodes-distance-k-in-binary-tree/description/
 *
 * algorithms
 * Medium (61.42%)
 * Likes:    719
 * Dislikes: 0
 * Total Accepted:    60.9K
 * Total Submissions: 99K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n2'
 *
 * 给定一个二叉树（具有根结点 root）， 一个目标结点 target ，和一个整数值 k ，返回到目标结点 target 距离为 k
 * 的所有结点的值的数组。
 * 
 * 答案可以以 任何顺序 返回。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
 * 输出：[7,4,1]
 * 解释：所求结点为与目标结点（值为 5）距离为 2 的结点，值分别为 7，4，以及 1
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: root = [1], target = 1, k = 3
 * 输出: []
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 节点数在 [1, 500] 范围内
 * 0 <= Node.val <= 500
 * Node.val 中所有值 不同
 * 目标结点 target 是树上的结点。
 * 0 <= k <= 1000
 * 
 * 
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    vector<int> ans;
    unordered_map<int, TreeNode*> parents;

    //拆分成两部分 
    //1.以target为root的
    void traversal(TreeNode* root, TreeNode* pre, int depth, int k) {
        if(!root) return;
        if(depth == k) {
            ans.push_back(root->val);
            return;
        }
        //左右根
        if(root->left != pre)
            traversal(root->left, root, depth + 1,k);
        if(root->right != pre)
            traversal(root->right, root, depth + 1,k);
        TreeNode* par = parents[root->val];
        if(par != pre)
            traversal(par, root, depth + 1,k);
    }
    
    //2.记录每一个节点的父节点
    void logParent(TreeNode* root) {
        if(!root) return;
        if(root->left) {
            parents[root->left->val] = root;
            logParent(root->left);
        }
        if(root->right) {
            parents[root->right->val] = root;
            logParent(root->right);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        logParent(root);
        traversal(target, nullptr, 0, k);
        return ans;
    }
};
// @lc code=end

