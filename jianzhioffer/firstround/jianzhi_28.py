# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def judge(L, R):
            if not L and not R:
                return True
            elif not L or not R or (L.val != R.val):
                return False
            return judge(L.left, R.right) and judge(L.right, R.left)

        return judge(root.left, root.right) if root else True


if __name__ == '__main__':
    l1 = TreeNode(1)
    l2 = TreeNode(2)
    l3 = TreeNode(2)
    l4 = TreeNode(3)
    l5 = TreeNode(4)
    l6 = TreeNode(4)
    l7 = TreeNode(3)

    l1.left = l2
    l1.right = l3
    l2.left = l4
    l2.right = l5
    #l3.left = l6
    #l3.right = l7
    obj = Solution()
    result = obj.isSymmetric(l1)
    print(result)
