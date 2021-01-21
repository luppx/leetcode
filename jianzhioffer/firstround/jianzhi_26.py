# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def isSubStructure(self, A, B):
        """
        :type A: TreeNode
        :type B: TreeNode
        :rtype: bool
        """
        def recur(A, B):
            if not B:
                return True
            if not A or A.val != B.val:
                return False
            return recur(A.left, B.left) and recur(A.right, B.right)

        return bool(A and B) and (recur(A, B) or self.isSubStructure(A.left, B)
                                  or self.isSubStructure(A.right, B))


if __name__ == '__main__':
    a1 = TreeNode(3)
    a2 = TreeNode(4)
    a3 = TreeNode(5)
    a4 = TreeNode(1)
    a5 = TreeNode(2)
    a1.left = a2
    a1.right = a3
    a2.left = a4
    a2.right = a5

    b1 = TreeNode(4)
    b2 = TreeNode(1)
    b1.left = b2

    obj = Solution()
    result = obj.isSubStructure(a1, b1)
    print(result)
