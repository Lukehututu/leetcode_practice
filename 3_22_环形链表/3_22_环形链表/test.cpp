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
      ListNode* dummy = new ListNode(0); // ����һ������ͷ�ڵ�
      ListNode* current = dummy; // ���ڵ�����ָ��

      for (int num : nums) {
          current->next = new ListNode(num); // �����½ڵ�
          current = current->next; // �ƶ���ǰָ�뵽�½ڵ�
      }

      return dummy->next; // ������ʵͷ�ڵ�
  }

  // ��ӡ����
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

      // �ͷ��ڴ�
      ListNode* temp;
      while (head) {
          temp = head;
          head = head->next;
          delete temp;
      }

      return 0;
  }




