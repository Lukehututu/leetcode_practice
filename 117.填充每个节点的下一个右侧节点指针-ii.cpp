/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        vector<vector<Node*>> levelNode;
        levelNode.push_back({root});

        while(1) {
            vector<Node*> tmp;
            for(auto node : levelNode.back()) {
                if(node->left) {
                    tmp.push_back(node->left);
                }
                if(node->right) {
                    tmp.push_back(node->right);
                }
            }
            if(tmp.empty()) break;
            levelNode.push_back(tmp);
        }

        //再循环每一个level倒着来添加节点
        for(auto vec : levelNode) {
            Node* next = nullptr;
            for(int i = vec.size() - 1; i >= 0; --i) {
                vec[i]->next = next;
                next = vec[i]; 
            }
        }

        return root;
    }
};
// @lc code=end

