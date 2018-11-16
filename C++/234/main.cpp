#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
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
    // 用vector存储链表中的值，然后再判断回文
    bool isPalindrome(ListNode* head) {
        ListNode *cur;
        cur = head;
        vector<int> res;
        while(cur != NULL){
            res.push_back(cur->val);
            cur = cur->next;
        }
        for(int i=0; i<res.size(); i++){
            if(res[i] != res[res.size()-i-1]){   //判断回文
                return false;
            }
        }
        return true;
    }

    //将链表后半部分进行反转，然后再进行回文判断
    //设置快慢指针，都从head开始遍历，fast每次走两步，slow每次走一步
    //当fast遍历结束时，slow刚好指在中间的位置
    bool isPalindrome1(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }
        ListNode *slow,*fast,*cur;
        slow = head;
        fast = head;
        while(fast->next !=NULL && fast ->next ->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow -> next = reverseList(slow->next);
        slow = slow -> next;
        cur = head;
        while(slow != NULL){
            if(cur->val != slow->val){
                return false;
            }
            cur = cur->next;
            slow = slow->next;
        }
        return true;
    }
    //链表逆置
    ListNode *reverseList(ListNode* head){
        ListNode *cur,*pre;
        pre = NULL;
        cur = head;
        while(cur != NULL){
            ListNode *temp = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};

int main()
{

    return 0;
}
