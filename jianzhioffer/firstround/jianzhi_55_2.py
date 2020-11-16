# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# class Solution(object):
#     def dfs(self, node):
#         if not node:
#             return 0
#         return max(self.dfs(node.left), self.dfs(node.right)) + 1
#
#     def isBalanced(self, root):
#         """
#         :type root: TreeNode
#         :rtype: bool
#         """
#         if not root:
#             return True
#         return abs(self.dfs(root.left) - self.dfs(root.right)) <= 1 and self.isBalanced(root.left) \
#                and self.isBalanced(root.right)


class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def recur(node):
            if not node:
                return 0
            left = recur(node.left)
            if left == -1:
                return -1
            right = recur(node.right)
            if right == -1:
                return -1
            return max(left, right) + 1 if abs(left - right) <= 1 else -1

        return recur(root) != -1


if __name__ == '__main__':
    n1 = TreeNode(3)
    n2 = TreeNode(9)
    n3 = TreeNode(20)
    n4 = TreeNode(15)
    n5 = TreeNode(7)
    # n6 = TreeNode(1)

    n1.left = n2
    n1.right = n3
    n3.left = n4
    n3.right = n5

    obj = Solution()
    isBalance = obj.isBalanced(n1)
    print(isBalance)
