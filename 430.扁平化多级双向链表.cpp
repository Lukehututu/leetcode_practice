/*
 * @lc app=leetcode.cn id=430 lang=cpp
 *
 * [430] 扁平化多级双向链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;
        //存放有子节点的next
        stack<Node*> st;
        auto cur = head;
        while (1) {
            if (!cur->next && !cur->child) {
                break;
            }
            if (cur->child) {
                if (cur->next) {
                    st.push(cur->next);
                }
                cur->next = cur->child;
                cur->child->prev = cur;
                cur->child = nullptr;
            }
            cur = cur->next;

        }

        //在弹栈然后接到cur后面
        while (!st.empty()) {
            auto node = st.top();
            st.pop();
            cur->next = node;
            node->prev = cur;
            while(cur->next) {
                cur = cur->next;
            }
        }

        return head;
    }
};
// @lc code=end

