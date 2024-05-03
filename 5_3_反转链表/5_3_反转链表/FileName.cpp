using namespace std;
#include<iostream>


 //Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

//ͷ�巨
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return nullptr;
        ListNode* p = head;
        //ͷ�巨
        ListNode* node = new ListNode(0);
        while (p) {
            //�����½ڵ�
            ListNode* emp = new ListNode(p->val);
            emp->next = node->next;
            node->next = emp;
            p = p->next;
        }

        return node->next;
    }

};

//�����ķ���
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || head->next == nullptr)
            return head;
        ListNode* left, * mid, * right;
        left = nullptr;
        mid = head;
        right = head->next;
        while (right) {
            mid->next = left;
            left = mid;
            mid = right;
            right = right->next;
        }
        mid->next = left;
        return mid;

    }
};