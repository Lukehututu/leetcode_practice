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
        if (!head || k == 1) return head;
        ListNode* cur = head;
        ListNode* end = nullptr;
        ListNode* lastEnd = nullptr;
        bool getHead = false;
        //看够不够k个
        while (1) {

            int cnt = k - 1;
            end = cur;
            while (cnt) {
                if (end) {
                    end = end->next;
                }
                if (!end) {
                    break;
                }
                cnt--;
            }
            if (cnt != 0) { //直接结束
                break;
            }
            if(lastEnd)
                lastEnd->next = end;
            //记录下一组第一个
            ListNode* nextHead = end->next;
            lastEnd = cur;
            //上一组最后一个
            //否则维护每一组的头尾节点 然后头插法
            while (cur != end) {
                auto tmp = cur;
                cur = cur->next;
                tmp->next = end->next;
                end->next = tmp;
            }
            //如果是第一次那要修改头节点
            if (!getHead) {
                head = end;
                getHead = true;
            }
            cur = nextHead;

        }
        return head;
    }
};
// @lc code=end

