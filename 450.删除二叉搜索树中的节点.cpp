/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        //先找key
        TreeNode* ptr = root;
        TreeNode* parent = nullptr;
        while(ptr) {
            if(ptr->val == key) {
                break;
            }
            else if(ptr->val > key) {
                parent = ptr;
                ptr = ptr->left;
            }
            else {
                parent = ptr;
                ptr = ptr->right;
            }
        }
        if(ptr == nullptr) return root;

        //如果左右孩子都有，先找到直接前驱，然后转化成删除叶子节点，或只有一个孩子的问题
        if(ptr->left && ptr->right) {
            parent = ptr;
            TreeNode* pre = ptr->left;
            while(pre->right) {
                parent = pre;
                pre = pre->right;
            }
            ptr->val = pre->val;
            ptr = pre;//转化成删除直接前驱
        }        
        
        //此时ptr可能有1个也可能没有孩子（这种写法包括了删除叶子节点的情况了）
        TreeNode* child = ptr->left ? ptr->left : ptr->right;
        if(parent == nullptr) root = child; //有可能删除的是根节点
        else {
            if(parent->left == ptr) {
                parent->left = child;
            }
            else parent->right = child;
        }
        

        return root;
    }
};
// @lc code=end

