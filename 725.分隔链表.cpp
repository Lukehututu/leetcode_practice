/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<int> num(k,0);
        int n = 0;
        auto tmp = head;
        while(tmp) {
            tmp = tmp->next;
            n++;
        }
        for(auto& i : num) {
            i = n / k;
        }
        int off = n % k;
        for(int i = 0; i < off; ++i) {
            num[i]++;
        }
        vector<ListNode*> res;

        for(auto i : num) {
            if(i == 0) {
                res.push_back(nullptr);
                continue;
            }
            //这一个开头长度为i
            auto cur = head;
            int cnt = i - 1;
            while(cnt) {
                cur = cur->next;
                cnt--;
            } 
            res.push_back(head);
            head = cur->next;
            cur->next = nullptr;
        }
        return res;
    }
};
// @lc code=end

