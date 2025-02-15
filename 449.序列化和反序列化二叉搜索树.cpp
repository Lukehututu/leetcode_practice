/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "null,";
        }
    
        string str = to_string(root->val) + ',';
        str += serialize(root->left);
        str += serialize(root->right);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* preOrder(vector<string>& val, int& index) {
        if (val.empty()) {
            return nullptr;
        }
        string tmp = val[index++];
        if (tmp == "null") return nullptr;
        TreeNode* root = new TreeNode(stoi(tmp));
    
        root->left = preOrder(val, index);
        root->right = preOrder(val, index);
        return root;
    }
    
    TreeNode* deserialize(string data) {
        //先读取每一个val
        vector<string> val;
        stringstream ss(data);
        string tmp;
        while (getline(ss, tmp, ',')) {
            val.push_back(tmp);
        }
        //根据preorder来构建树
        int idx = 0;
        return preOrder(val, idx);
    
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

