/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        //不足两个节点直接返回
        if(!head || !head->next) {
            return head;
        }

        ListNode* cur = head;
        ListNode* post = cur->next;
        ListNode* pre = nullptr;
        head = post;

        while(post) {
            cur->next = post->next;
            post->next = cur;
            pre = cur;
            cur = cur->next;
            post = cur ? cur->next : nullptr;
            pre->next = post ? post : pre->next;
        }
        return head;
    }
};
// @lc code=end

