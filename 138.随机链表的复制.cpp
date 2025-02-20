/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    //1.朴素查找
    // Node* copyRandomList(Node* head) {
    //     if(!head) return head;
    //     vector<Node*> getRandom;//给一个数组快速找random指针
    //     Node* newHead = nullptr;
    //     Node* pre = nullptr;
    //     Node* tmp = head;
    //     while(tmp) {
    //         newHead = new Node(tmp->val);
    //         if(pre)
    //             pre->next = newHead;
    //         tmp = tmp->next;
    //         pre = newHead;
    //         getRandom.push_back(newHead);
    //     }
    //     newHead = getRandom[0];

    //     //给每一个找next
    //     tmp = head;
    //     int i = 0;
    //     while(tmp) {
    //         auto random = tmp->random;
    //         if(!random) {
    //             getRandom[i]->random = nullptr;                
    //         }
    //         else {
    //             //找到index
    //             int index = 0;
    //             //有可能在前面也有可能在后面
    //             auto findIndex = random;
    //             while(findIndex != tmp && findIndex) {
    //                 findIndex = findIndex->next;
    //                 index++;
    //             }
    //             if(findIndex == tmp) {//是在前面
    //                 getRandom[i]->random = getRandom[i - index];
    //             }
    //             else {//在后面
    //                 index = 0;
    //                 auto findIndex = tmp;
    //                 while(findIndex != random && findIndex) {
    //                     findIndex = findIndex->next;
    //                     index++;
    //                 }
    //                 getRandom[i]->random = getRandom[i + index];
    //             }
                
    //         }
    //         //更新完random迭代tmp和i
    //         tmp = tmp->next;
    //         i++;
    //     }
    //     return getRandom[0];
    // }

    // [原节点，对应新节点]
    unordered_map<Node*, Node*> create;

    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        //说明没创建
        if(create.find(head) == create.end()) {
            Node* newHead = new Node(head->val);
            create[head] = newHead;
            newHead->next = copyRandomList(head->next);
            newHead->random = copyRandomList(head->random); 
        }
        return create[head];
    }
};
// @lc code=end

