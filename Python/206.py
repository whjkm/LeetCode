# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:

    # 链表逆置
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        pre = None
        cur = head
        while cur:
            temp = cur.next
            cur.next = pre
            pre = cur
            cur = temp
        return pre


    def reverseList1(self, head):
        pre = None
        while head:
            cur = head
            head = head.next
            cur.next = pre
            pre = cur
        return pre

if __name__ == "__main__":
    head = ListNode(0)
    cur = head
    for i in range(5):
        temp = ListNode(i)
        head.next = temp
        head = head.next







