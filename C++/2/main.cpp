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
    //链表加法
    /*The pseudocode is as following:
    Initialize current node to dummy head of the returning list.
    Initialize carry to 0.
    Initialize p and q to head of l1 and l2 respectively.
    Loop through lists l1 and l2 until you reach both ends.
    Set x to node p's value. If p has reached the end of l1, set to 0.
    Set y to node q's value. If q has reached the end of l2, set to 0.
    Set sum = x + y + carry.
    Update carry = sum / 10.
    Create a new node with the digit value of (sum mod 10) and set it to current node's next, then advance current node to next.
    Advance both p and q.
    Check if carry = 1, if so append a new node with digit 11 to the returning list.
    Return dummy head's next node.
    */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *cur1,*cur2;
        ListNode *l3,*cur3;
        l3 = new ListNode(0);
        cur1 = l1;
        cur2 = l2;
        cur3 = l3;
        int carry = 0;    // 考虑进位情况,将进位的值存储
        while(cur1!=NULL || cur2!=NULL){
            int x = (cur1 != NULL) ? cur1->val : 0;
            int y = (cur2 != NULL) ? cur2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;    //每次更新进位值 如果只判断sum>10，有些情况会出错
            cur3->next = new ListNode(sum%10);
            cur3 = cur3->next;
            if(cur1 != NULL){
                cur1 = cur1 -> next;
            }
            if(cur2 != NULL){
                cur2 = cur2 -> next;
            }
        }
        if(carry > 0){
            cur3 -> next = new ListNode(carry);
        }
        return l3->next;
    }
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
