/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* post = head->next;
        ListNode* end = nullptr;
        bool getHead = false;
        int cnt{};
        while(1) {
            //1.剩下的要不要反转
            cnt = k - 1;
            auto tmp = cur;
            while(cnt--) {
                if(tmp) tmp = tmp->next;
                else break;
            }
            if(cnt != 0) break;
            cnt = k;
            auto start = cur;
            while(cnt--) {
                cur->next = pre;
                pre = cur;
                cur = post;
                post = cur->next;
                if(post == nullptr) {
                    cur->next = pre;
                    break;
                }
            }

            //拼接前一组
            if(cnt == 0) { // 说明pre是这一组最后一个
                if(!end) end->next = pre;
            }
            else {//否则就是cur是最后一个
                if(!end) end->next = cur;
            }
            start->next = cur;
            if(!getHead) {
                head = pre;
                getHead = true;
                end = start;
            }

        }
        return head;
    }
};
// @lc code=end

