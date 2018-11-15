# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # 链表加法
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        l3 = cur3 = ListNode(0)
        carry = 0                         # 进位
        while l1 or l2 or carry:          # 考虑最后一位产生进位的情况
            v1 = v2 = 0
            if l1:
                v1 = l1.val
                l1 = l1.next
            if l2:
                v2 = l2.val
                l2 = l2.next
            carry, val = divmod(v1 + v2 + carry, 10)    # 将除数和余数结合起来
            cur3.next = ListNode(val)
            cur3 = cur3.next
        return l3.next
