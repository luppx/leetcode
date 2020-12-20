# Definition for a Node.
class Node(object):
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def __init__(self):
        self.head = None
        self.pre = None

    def treeToDoublyList(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        def dfs(node):
            if not node:
                return
            dfs(node.left)
            if self.pre:
                self.pre.right = node
                node.left = self.pre
            else:
                self.head = node
            self.pre = node
            dfs(node.right)

        if not root:
            return
        dfs(root)
        self.head.left = self.pre
        self.pre.right = self.head
        return self.head


if __name__ == '__main__':
    l1 = Node(4)
    l2 = Node(2)
    l3 = Node(5)
    l4 = Node(1)
    l5 = Node(3)

    l1.left = l2
    l1.right = l3
    l2.left = l4
    l2.right = l5

    obj = Solution()
    result = obj.treeToDoublyList(l1)
    print(result.val, result.left.val)
