/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode* cur = head;
        map<int, int> m;

        while (cur != nullptr) {
            m[cur->val]++;
            cur = cur->next;
        }

        cur = head;
        auto tmp = cur;
        bool changed = false;
        for (auto pair : m) {
            if (pair.second > 1) {
                continue;
            }
            cur->val = pair.first;
            tmp = cur;
            cur = cur->next;
            changed = true;
        }
        if (!changed) return nullptr;
        tmp->next = nullptr;
        return head;
    }
};
// @lc code=end

