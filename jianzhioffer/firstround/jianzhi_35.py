# Definition for a Node.
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        if not head:
            return
        dic = {}
        node = head
        while node:
            dic[node] = Node(node.val)
            node = node.next

        node = head
        while node:
            dic[node].random = dic.get(node.random)
            dic[node].next = dic.get(node.next)
            node = node.next
        return dic[head]


if __name__ == '__main__':
    l1 = Node(7)
    l2 = Node(13)
    l3 = Node(11)
    l4 = Node(10)
    l5 = Node(1)

    l1.next = l2
    l2.next = l3
    l3.next = l4
    l4.next = l5

    l1.random = None
    l2.random = l1
    l3.random = l5
    l4.random = l3
    l5.random = l1

    obj = Solution()
    result = obj.copyRandomList(l1)
    print(result)
