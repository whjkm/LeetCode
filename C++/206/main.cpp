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
    // 链表逆置，改变指针的指向
    // 遍历链表，将链表的下一个节点指向前一个节点
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
    head = new ListNode(0);   //给头结点分配内存
    head -> next = NULL;      //将头结点的指针域清空
    p = head;
    for(int i=0; i<5;){
        temp = new ListNode(++i);     //创建新节点
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
