#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 递归
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;
        ListNode *cur = head -> next;
        int val = head -> val;
        if(val != cur -> val)
        {
            head -> next = deleteDuplicates(cur);
            return head;
        }
        else
        {
            while(cur && cur ->val == val)
                cur = cur -> next;
            return deleteDuplicates(cur);
        }
    }
};
// 设置前置结点，保存前置结点的位置。
/*
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;
        ListNode *dummy = new ListNode(NULL);
        dummy -> next = head;
        ListNode *pre = dummy, *cur = head;
        while(cur && cur -> next)
        {
            while(cur ->next && cur->val == cur->next->val)
            {
                cur = cur -> next;
            }
            if(pre->next == cur)
            {
                pre = cur;
                cur = cur -> next;
            }
            else{
                cur = cur -> next;
                pre->next = cur;
            }
        }
        return dummy->next;
    }
};
*/
int main()
{

    return 0;
}
