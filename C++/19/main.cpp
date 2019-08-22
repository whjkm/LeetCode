#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

/***
˫ָ�뷨�����ÿ�������ָ�룬��ָ������ǰ����N���ڵ㣬
Ȼ������ָ��ͬʱ��������ֱ����ָ��ָ��NULL����ʱ��ָ��ָ��ľ��ǵ�����N���ڵ㡣
Ȼ��ɾ����ָ��ָ���ָ��ֵ��
***/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first = new ListNode(NULL);
        ListNode *second = new ListNode(NULL);
        ListNode *dup = new ListNode(NULL);
        dup -> next = head;
        first = dup;
        second = dup;

        for(int i = 0; i <= n; ++i)
        {
            first = first -> next;
        }

        while(first != NULL)
        {
            first = first -> next;
            second = second -> next;
        }
        ListNode *to_be_dele = second ->next;
        second -> next = second -> next -> next;
        delete to_be_dele;
        return dup -> next;
    }
};

// �������飬��һ�����������ĳ��ȣ��ڶ����ҵ�������N���ڵ㡣
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1);
        ListNode *first = new ListNode(NULL);
        dummy -> next = head;
        first = head;
        int size = 0;
        while(first != NULL)
        {
            first = first -> next;
            size++;
        }
        first = dummy;
        size -= n;
        while(size > 0)
        {
            first = first -> next;
            size--;
        }
        first ->next = first ->next->next;
        return dummy->next;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
