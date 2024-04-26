#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<vector>

  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
  ListNode* createLinkedList(const std::vector<int>& nums) {
      ListNode* dummy = new ListNode(0); // 创建一个虚拟头节点
      ListNode* current = dummy; // 用于迭代的指针

      for (int num : nums) {
          current->next = new ListNode(num); // 创建新节点
          current = current->next; // 移动当前指针到新节点
      }

      return dummy->next; // 返回真实头节点
  }

  // 打印链表
  void printLinkedList(ListNode* head) {
      while (head) {
          std::cout << head->val << " -> ";
          head = head->next;
      }
      std::cout << "NULL" << std::endl;
  }

  class Solution {
  public:
      bool hasCycle(ListNode* head) {
          if (head == nullptr) return false;
          ListNode* slow = head;
          ListNode* fast = head->next;
          while (fast != nullptr && fast->next != nullptr) {
              fast = fast->next->next;
              slow = slow->next;
              if (fast == slow) return true;
          }
          return false;
      }
  };

 
  int main() {
      std::vector<int> nums = { -21,10,17,8,4,26,5,35,33,-7,-16,27,-12,6,29,-12,5,9,20,14,14,2,13,-24,21,23,-21,5 };
      ListNode* head = createLinkedList(nums);
      //printLinkedList(head);
      cout << Solution().hasCycle(head);

      // 释放内存
      ListNode* temp;
      while (head) {
          temp = head;
          head = head->next;
          delete temp;
      }

      return 0;
  }




