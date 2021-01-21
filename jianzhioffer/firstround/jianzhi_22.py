#Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def getKthFromEnd(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head.next == None:
            return head
        former = head
        latter = head
        for _ in range(k):
            former = former.next
        while former:
            former = former.next
            latter = latter.next
        return latter


if __name__ == '__main__':
    l1 = ListNode(1)
    l2 = ListNode(2)
    l3 = ListNode(3)
    l4 = ListNode(4)
    #l5 = ListNode(5)
    l1.next = l2
    l2.next = l3
    l3.next = l4
    #l4.next = l5

    obj = Solution()
    node = obj.getKthFromEnd(l1, 2)
    print(node)