#define _CRT_SECURE_NO_WARNINGS 1
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
 
class SolutionV_1 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        int new_data = head->val;//����һ��new�����Ӧ�÷Ž����������       
        ListNode* tmp = head;//����һ��ָ����ʵ�ֱ���
        ListNode* new_list = new ListNode(new_data);//����һ���µ�������������
        ListNode* cur_node = new_list;//ͬʱ����һ��ָ����������������
        //��ʼ������������������ͬ�ľ�newһ���µĽ�㽫���ݷŽ�ȥ
        while (tmp != nullptr) {
            tmp = tmp->next;
            if (!tmp)
                break;
            //���tmpָ�Ľ���ֵ������new_data,�Ǿ͸���new_data�������½��
            if (tmp->val != new_data) {
                new_data = tmp->val;
                cur_node->next = new ListNode(new_data);
                cur_node = cur_node->next;
            }
        }
        //��ʱ�Ѿ��õ��µ����� 
        head = new_list;
        return head;
    }
};


class SolutionV_2 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* pre = head;
        ListNode* post = head->next;

        while (post)
        {
            //������
            if (post->val == pre->val)
            {
                //�ͷſռ�
                ListNode* tmp = post;
                post = post->next;
                delete tmp;
            }
            else
            {
                pre->next = post;
                pre = post;
                post = post->next;
            }
        }
        pre->next = nullptr;
        return head;
    }
};









void PrintList(ListNode* head)
{
    ListNode* tmp = head;
    for (; tmp != nullptr; tmp = tmp->next)
    {
        cout << tmp->val << " ";
    }
}

int main()
{
  /*  ListNode* head;
    head = new ListNode(1);
    ListNode* cur = head;
    int input = 0;
    int rnd = 0;
    cin >> rnd;
    while (rnd--)
    {
        cin >> input;
        ListNode nnode(input);
        cur->next = &nnode;
        cur = &nnode;
    }
    Solution S;
    ListNode* L = S.deleteDuplicates(head);
    PrintList(L);*/


    ListNode* head = new ListNode(1);
    ListNode* cur = head;
    int input = 0;
    int rnd = 0;
    cin >> rnd;
    while (rnd--) {
        cin >> input;
        ListNode* nnode = new ListNode(input); // �ڶ��Ϸ���ڵ����
        cur->next = nnode;
        cur = nnode;
    }
    PrintList(head);
    cout << endl;
    /*SolutionV_1 S;
    ListNode* L = S.deleteDuplicates(head);*/
    SolutionV_2 S;
    ListNode* L = S.deleteDuplicates(head);
    PrintList(L);
    // �ͷ�������ڴ�
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}