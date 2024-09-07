/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 *
 * https://leetcode.cn/problems/rotate-list/description/
 *
 * algorithms
 * Medium (41.43%)
 * Likes:    1082
 * Dislikes: 0
 * Total Accepted:    406.9K
 * Total Submissions: 982K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表的头节点 tmp_h ，旋转链表，将链表每个节点向右移动 k 个位置。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：tmp_h = [1,2,3,4,5], k = 2
 * 输出：[4,5,1,2,3]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：tmp_h = [0,1,2], k = 4
 * 输出：[2,0,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目在范围 [0, 500] 内
 * -100 <= Node.val <= 100
 * 0 <= k <= 2 * 10^9
 * 
 * 
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || head == 0)
            return nullptr;
        //  先计算链表长度
        int len = 1;
        auto tail = head;
        while(tail->next != nullptr)
        {
            tail = tail->next;
            len++;
        }
        //  找倒数第 n + 1 个节点
        int n = k % len;
        if(n == 0)
            return head;
        auto po = head;
        auto pe = head;
        while(n--)
            po = po->next;
        while(po->next != nullptr)
        {
            po = po->next;
            pe = pe->next;
        }
        po = pe->next;
        tail->next = head;
        pe->next = nullptr;
        return po;
    }
};
// @lc code=end

