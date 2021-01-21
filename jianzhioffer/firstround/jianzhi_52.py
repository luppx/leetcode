# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        node1 = headA
        node2 = headB

        while node1 != node2:
            node1 = node1.next if node1 else headB
            node2 = node2.next if node2 else headA
        return node1


if __name__ == '__main__':
    l11 = ListNode(1)
    l12 = ListNode(2)
    l13 = ListNode(3)
    l14 = ListNode(4)
    #l5 = ListNode(5)
    l11.next = l12
    l12.next = l13
    l13.next = l14
    #l4.next = l5

    l21 = ListNode(-1)

    obj = Solution()
    node = obj.getIntersectionNode(l11, l21)
    print(node.val)
