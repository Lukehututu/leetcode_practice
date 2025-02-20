/*
 * @lc app=leetcode.cn id=1669 lang=cpp
 *
 * [1669] 合并两个链表
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        //找到 a - 1 和 b + 1两个节点
        int index = 0;
        ListNode* node1 = list1;
        ListNode* node2 = list1;
        ListNode* head = (a == 0) ? list2 : list1;
        while (index != b + 1) {
            if (index < a - 1) {
                node1 = node1->next;
                node2 = node1;
            }
            else if (index < b + 1) {
                node2 = node2->next;
                node1->next = nullptr;
            }
            index++;
        }

        if (a != 0) {
            node1->next = list2;
        }
        auto end = list2;
        while (end->next) {
            end = end->next;
        }
        end->next = node2;
        return head;
    }
};
// @lc code=end

