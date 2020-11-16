# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    # def maxDepth(self, root):  # DFS
    #     """
    #     :type root: TreeNode
    #     :rtype: int
    #     """
    #     if not root:
    #         return 0
    #     return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1

    def maxDepth(self, root):  # BFS
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        queue, depth = [root], 0
        while queue:
            tmp = []
            for node in queue:
                if node.left:
                    tmp.append(node.left)
                if node.right:
                    tmp.append(node.right)
            queue = tmp
            depth += 1
        return depth


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
    number = obj.maxDepth(n1)
    print(number)
