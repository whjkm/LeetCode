#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

/***
双指针法：设置快慢两个指针，快指针先往前遍历N个节点，
然后两个指针同时向后遍历，直到快指针指向NULL，这时慢指针指向的就是倒数第N个节点。
然后删除慢指针指向的指针值。
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

// 遍历两遍，第一遍先求出链表的长度，第二遍找到倒数第N个节点。
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
