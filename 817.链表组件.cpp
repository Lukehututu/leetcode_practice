/*
 * @lc app=leetcode.cn id=817 lang=cpp
 *
 * [817] 链表组件
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
    int numComponents(ListNode* head, vector<int>& nums) {
        int res = 0;
        set<int> s;
        for(auto i : nums) {
            s.emplace(i);
        }
        auto cur = head;
        bool flag = false;
        while(cur) {
            int val = cur->val;
            auto it = s.find(val);
            if(it == s.end()) {
                cur = cur->next;
                res += flag;
                flag = false;
                continue;
            }
            else {
                flag = true;
                cur = cur->next;
                s.erase(it);
            }
        }
        res += flag;
        return res;
    }
};
// @lc code=end

