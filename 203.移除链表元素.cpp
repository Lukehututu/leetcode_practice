/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        vector<int> vec;
        auto cur = head;
        while(cur) {
            if(cur->val != val) {
                vec.push_back(cur->val);
            }
            cur = cur->next;
        }
        auto changed = false;
        cur = head;
        auto tmp = cur;
        for(int i : vec) {
            cur->val = i;
            tmp = cur;
            cur = cur->next;
            changed = true;
        }
        if(!changed) return nullptr;
        tmp->next = nullptr;
        return head;
    }
};
// @lc code=end

