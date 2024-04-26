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
        int new_data = head->val;//设置一个new来存放应该放进新链表的数       
        ListNode* tmp = head;//设置一个指针来实现遍历
        ListNode* new_list = new ListNode(new_data);//设置一个新的链表来存数据
        ListNode* cur_node = new_list;//同时设置一个指针来帮助插入数据
        //开始遍历整个链表，遇到不同的就new一个新的结点将数据放进去
        while (tmp != nullptr) {
            tmp = tmp->next;
            if (!tmp)
                break;
            //如果tmp指的结点的值不等于new_data,那就更新new_data并插入新结点
            if (tmp->val != new_data) {
                new_data = tmp->val;
                cur_node->next = new ListNode(new_data);
                cur_node = cur_node->next;
            }
        }
        //此时已经得到新的链表 
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
            //相等情况
            if (post->val == pre->val)
            {
                //释放空间
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
        ListNode* nnode = new ListNode(input); // 在堆上分配节点对象
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
    // 释放链表的内存
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}