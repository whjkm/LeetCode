#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // �������ã��ı�ָ���ָ��
    // �����������������һ���ڵ�ָ��ǰһ���ڵ�
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL;
        ListNode *cur = head;
        while(cur != NULL){
            ListNode *temp = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }

    ListNode* reverseList1(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *p = reverseList1(head->next);
        head ->next ->next = head;
        head ->next =NULL;
        return p;
    }
};

int main()
{
    ListNode *head,*p;
    ListNode *temp;
    head = new ListNode(0);   //��ͷ�������ڴ�
    head -> next = NULL;      //��ͷ����ָ�������
    p = head;
    for(int i=0; i<5;){
        temp = new ListNode(++i);     //�����½ڵ�
        //temp ->val = ++i;
        //temp ->next = NULL;
        p -> next = temp;
        p = temp;
    }

    Solution s;
    head = s.reverseList1(head);
    ListNode *cur;
    cur = head;
    while(cur ->next!= NULL){
       cout << cur -> val << endl;
       cur = cur -> next;
    }
    return 0;
}
