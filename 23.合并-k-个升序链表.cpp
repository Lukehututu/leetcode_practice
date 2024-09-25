/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 *
 * https://leetcode.cn/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (60.29%)
 * Likes:    2875
 * Dislikes: 0
 * Total Accepted:    860.6K
 * Total Submissions: 1.4M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 给你一个链表数组，每个链表都已经按升序排列。
 * 
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：lists = [[1,4,5],[1,3,4],[2,6]]
 * 输出：[1,1,2,3,4,4,5,6]
 * 解释：链表数组如下：
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * 将它们合并到一个有序链表中得到。
 * 1->1->2->3->4->4->5->6
 * 
 * 
 * 示例 2：
 * 
 * 输入：lists = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 输入：lists = [[]]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] 按 升序 排列
 * lists[i].length 的总和不超过 10^4
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;
        mergeSort(lists,0,lists.size()-1);
        return lists[0];
    }

    void merge(vector<ListNode*>& lists, int i, int j)
    {

        if(!lists[i] || !lists[j])
        {
            lists[i] = lists[i]? lists[i] : lists[j];
            return;
        }
        auto pi = lists[i];
        auto pj = lists[j];
        //  都往i上接
        while (pi && pj)
        {
            if(pi->val <= pj->val )
            {
                while(pi->next && pi->next->val <= pj->val)
                {
                    pi = pi->next;       
                }
                auto tmp = pi;
                pi = pi->next;
                tmp->next = pj;
            }
            else
            {
                while(pj->next && pj->next->val <= pi->val)
                {
                    pj = pj->next;
                }
                auto tmp = pj;
                pj = pj->next;
                tmp->next = pi;
            }
        }
        //  再将链表强制放在i中
        if(lists[i]->val > lists[j]->val)
        {
           swap(lists[i],lists[j]);
        }
    }
    void mergeSort(vector<ListNode*>& lists, int i, int j)
    {
        if(i >= j)
            return;
        int mid = (i + j) / 2;
        mergeSort(lists,i,mid);
        mergeSort(lists,mid + 1, j);
        merge( lists, i, mid + 1);
        return;
    }
};
// @lc code=end

