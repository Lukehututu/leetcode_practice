/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 *
 * https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (68.03%)
 * Likes:    2037
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 1.7M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[3],[9,20],[15,7]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1]
 * 输出：[[1]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = []
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [0, 2000] 内
 * -1000 <= Node.val <= 1000
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

    struct TreePeer
    {
        TreePeer(TreeNode* n,int lev)
            :node(n)
            ,level(lev){}

        TreeNode* node;
        int level;
    };
    

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return vector<vector<int>>();
        vector<vector<int>> ans;
        vector<int> layer;
        queue<TreePeer> que;

        //  第一个peer
        TreePeer tmp(root,1);
        int lev = 1;//  用来记录当前层级
        que.push(tmp);

        while(!que.empty())
        {
            auto tmp = que.front();
            que.pop();
            //  说明已经到了下一层第一个
            if(tmp.level > lev)
            {
                //  此时将该层的所有节点加入到ans中，并清空layer
                ans.push_back(layer);
                layer.clear();
                //  同时更新层级
                lev++;
            }
            layer.push_back(tmp.node->val);

            if(tmp.node->left)
            {
                TreePeer a(tmp.node->left,tmp.level+1);
                que.push(a);
            }
            if(tmp.node->right)
            {
                TreePeer b(tmp.node->right,tmp.level+1);
                que.push(b);
            }
        } 

        //  然后把最后一层也放进去
        ans.push_back(layer);
        return ans;
    }
};
// @lc code=end

