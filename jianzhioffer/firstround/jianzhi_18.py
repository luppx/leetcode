# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def deleteNode(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        if head.val == val:
            return head.next
        prev, now = head, head.next
        while now and now.val!=val:
            prev, now = now, now.next
        if now:
            prev.next = now.next
        return head

#if __name__ == '__main__':
