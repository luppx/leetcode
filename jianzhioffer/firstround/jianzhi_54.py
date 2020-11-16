# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def kthLargest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        def dfs(node):
            if not node:
                return
            dfs(node.right)
            if self.k == 0:
                return
            self.k -= 1
            if self.k == 0:
                self.val = node.val
            dfs(node.left)

        self.k = k
        dfs(root)
        return self.val


if __name__ == '__main__':
    # n1 = TreeNode(3)
    # n2 = TreeNode(1)
    # n3 = TreeNode(4)
    # n4 = TreeNode(2)
    #
    # n1.left = n2
    # n1.right = n3
    # n2.right = n4

    n1 = TreeNode(5)
    n2 = TreeNode(3)
    n3 = TreeNode(6)
    n4 = TreeNode(2)
    n5 = TreeNode(4)
    n6 = TreeNode(1)

    n1.left = n2
    n1.right = n3
    n2.left = n4
    n2.right = n5
    n4.left = n6

    obj = Solution()
    number = obj.kthLargest(n1, 3)
    print(number)
