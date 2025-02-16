/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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

    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        queue<pair<TreeNode*, unsigned long long>> que;
        que.push({root, 0});
        int maxWidth = 0;

        while (!que.empty()) {
            int size = que.size();
            unsigned long long minId = que.front().second;  // 归一化基准
            unsigned long long firstId = 0, lastId = 0;

            for (int i = 0; i < size; i++) {
                auto [node, id] = que.front();
                que.pop();
                id -= minId;  // 归一化，防止溢出
                
                if (i == 0) firstId = id;   // 记录当前层的最左 id
                if (i == size - 1) lastId = id;  // 记录当前层的最右 id

                if (node->left)
                    que.push({node->left, id * 2 + 1});
                if (node->right)
                    que.push({node->right, id * 2 + 2});
            }
            maxWidth = max(maxWidth, static_cast<int>(lastId - firstId + 1));
        }
        return maxWidth;
    }


};
// @lc code=end

