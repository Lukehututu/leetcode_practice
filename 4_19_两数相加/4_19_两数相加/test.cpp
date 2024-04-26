using namespace std;
#include<iostream>
#include<vector>



  //Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* L = new ListNode;
        ListNode* tmp = L;

        //ֻҪ��һ���������˾�����ѭ��
        while (l1 && l2) {

            tmp->val +=(l1->val + l2->val);
           
            l1 = l1->next;
            l2 = l2->next;
            if (!l1 || !l2)
                break;
            ListNode* newnode = new ListNode;
            tmp->next = newnode;
            tmp->next->val = tmp->val / 10;
            tmp->val = tmp->val % 10;
            tmp = newnode;
        }

        //�ټ���û�м��ϵ�
        while(l1) {
            
            ListNode* newnode = new ListNode;
            tmp->next = newnode;
            tmp->next->val = tmp->val / 10;
            tmp->val = tmp->val % 10;
            tmp = newnode;
            tmp->val += l1->val;
            l1 = l1->next;
        }
        while(l2) {
            ListNode* newnode = new ListNode;
            tmp->next = newnode;
            tmp->next->val = tmp->val / 10;
            tmp->val = tmp->val % 10;
            tmp = newnode;
            tmp->val += l2->val;
            l2 = l2->next;
        }


        //������һλ
        if (tmp->val >= 10) {
            ListNode* newnode = new ListNode(tmp->val / 10);
            tmp->val %= 10;
            tmp->next = newnode;
        }

        return L;


    }
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

void printLinkedList(ListNode* head) {
    while (head) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    std::vector<int> nums = { 9,9,9,9,9,9,9 };
    ListNode* l1= createLinkedList(nums);

    std::vector<int> num2 = { 9,9,9,9 };
    ListNode* l2 = createLinkedList(num2);


    //printLinkedList(l1);
   // printLinkedList(l2);

    printLinkedList(Solution().addTwoNumbers(l1,l2));






    // �ͷ��ڴ�
    ListNode* temp;
    while (l1) {
        temp = l1;
        l1 = l1->next;
        delete temp;
    }

    while (l2) {
        temp = l2;
        l2 = l2->next;
        delete temp;
    }
    return 0;




}