/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode.cn/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (56.65%)
 * Likes:    1860
 * Dislikes: 0
 * Total Accepted:    567.1K
 * Total Submissions: 997.6K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left  。请你反转从位置 left 到位置 right 的链表节点，返回
 * 反转后的链表 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5], left = 2, right = 4
 * 输出：[1,4,3,2,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [5], left = 1, right = 1
 * 输出：[5]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点数目为 n
 * 1 
 * -500 
 * 1 
 * 
 * 
 * 
 * 
 * 进阶： 你可以使用一趟扫描完成反转吗？
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //  边界条件处理
        if(left == right)
            return head;

        //  先将cur和h迭代到目标位置
        ListNode* cur = nullptr;
        ListNode* index = head;

        int n = 1;
        while(n < left)
        {
            cur = index;
            index = index->next;
            n++;
        }
        auto first = index;
        //  h_left 是left - 1的位置
        auto h_left = cur;
        //  h_right 是right+1的位置
        ListNode* h_right = nullptr;
        while( n < right)
        {
            auto tmp = index;
            index = index->next;
            h_right = index->next;
            tmp->next = cur;
            cur = tmp;
            n++;
        }
        index->next = cur;


        //  接上链表

        //  h_left 可能是空指针
        if(h_left == nullptr)
        {
            first->next = h_right;
            return index;
        }

        //  h_left 不为空 h_right为不为空不重要
        first->next = h_right;
        h_left->next = index;

        return head;
    }
};
// @lc code=end

