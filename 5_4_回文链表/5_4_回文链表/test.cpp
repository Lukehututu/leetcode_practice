#include<iostream>
#include<vector>
using namespace std;


 //* Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head->next)
            return true;
        //先拿一个数组记录链表数据O(n)
        vector<int> arr;
        while (head) {
            arr.push_back(head->val);
            head = head->next;
        }

        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            if (arr[left] != arr[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};