# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def mirrorTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if not root:
            return
        stack = [root]
        while stack:
            node = stack.pop()
            if node.left: stack.append(node.left)
            if node.right: stack.append(node.right)
            node.left, node.right = node.right, node.left
        return root


if __name__ == '__main__':
    l1 = TreeNode(4)
    l2 = TreeNode(2)
    l3 = TreeNode(7)
    l4 = TreeNode(1)
    l5 = TreeNode(3)
    l6 = TreeNode(6)
    #l7 = TreeNode(9)

    l1.left = l2
    l1.right = l3
    l2.left = l4
    l2.right = l5
    l3.left = l6
    #l3.right = l7
    obj = Solution()
    node = obj.mirrorTree(l1)
    while node.left or node.right:
        print(node.left)
        print(node.right)
        node = node.left


