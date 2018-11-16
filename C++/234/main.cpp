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
    // ��vector�洢�����е�ֵ��Ȼ�����жϻ���
    bool isPalindrome(ListNode* head) {
        ListNode *cur;
        cur = head;
        vector<int> res;
        while(cur != NULL){
            res.push_back(cur->val);
            cur = cur->next;
        }
        for(int i=0; i<res.size(); i++){
            if(res[i] != res[res.size()-i-1]){   //�жϻ���
                return false;
            }
        }
        return true;
    }

    //�������벿�ֽ��з�ת��Ȼ���ٽ��л����ж�
    //���ÿ���ָ�룬����head��ʼ������fastÿ����������slowÿ����һ��
    //��fast��������ʱ��slow�պ�ָ���м��λ��
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
    //��������
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
