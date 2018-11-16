# Definition for singly-linked list.
class ListNode:
     def __init__(self, x):
        self.val = x
        self.next = None

class Solution:

    # 用list存储链表中的值，再进行回文判断
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        res = []
        while head != None:
            res.append(head.val)
            head = head.next
        for i in range(len(res)//2):
            if res[i] != res[len(res)-i-1]:
                return False
        return True


    def isPalindrome1(self, head):
        if head == None or head.next == None:
            return True
        slow = head
        fast = head
        while fast.next != None and fast.next.next != None:
            slow = slow.next
            fast = fast.next.next
        def reverselist(head):
            pre = None
            cur = head
            while cur != None:
                temp = cur.next
                cur.next = pre
                pre = cur
                cur = temp
            return pre
        slow.next = reverselist(slow.next)
        slow = slow.next
        while slow != None:
            if slow.val != head.val:
                return False
            slow = slow.next
            head = head.next
        return True

