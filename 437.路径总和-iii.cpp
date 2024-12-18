/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 *
 * https://leetcode.cn/problems/path-sum-iii/description/
 *
 * algorithms
 * Medium (47.53%)
 * Likes:    1928
 * Dislikes: 0
 * Total Accepted:    353.5K
 * Total Submissions: 744K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * 给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
 * 
 * 路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
 * 输出：3
 * 解释：和等于 8 的路径有 3 条，如图所示。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 二叉树的节点个数的范围是 [0,1000]
 * -10^9  
 * -1000  
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
    
    //  用前缀和的思想解决 跟560一样

    unordered_map<long long,int> map;

    int rootSum(TreeNode* root, int targetSum,long long pre) {
        if(root == nullptr)
            return 0;
        
        pre += root->val;
        int ret = 0;
        if(map.find(pre - targetSum) != map.end())
        {
            ret += map[pre - targetSum];
        }
        
        //  往下就++
        map[pre]++;
        ret += rootSum(root->left,targetSum,pre);
        ret += rootSum(root->right,targetSum,pre);
        //  要回溯了就恢复
        map[pre]--;

        return ret;
    }

    int pathSum(TreeNode* root, int targetSum) {
        //  维护的前缀和的哈希表
        map[0] = 1;
        return  rootSum(root,targetSum, 0);
    }

};
// @lc code=end

