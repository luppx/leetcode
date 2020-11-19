# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        树为二叉树。题目说明，所有节点的值都是唯一的
        """
        if not root or root == p or root == q:  # 遇到节点p或q直接返回，表明已经找到相应节点，不用再往下递归了
            return root
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        if not left and not right:
            return
        elif not left:
            return right
        elif not right:
            return left
        return root


if __name__ == '__main__':
    obj = Solution()
    l1 = TreeNode(3)
    l2 = TreeNode(5)
    l3 = TreeNode(1)
    l4 = TreeNode(6)
    l5 = TreeNode(2)
    l6 = TreeNode(0)
    l7 = TreeNode(8)
    l8 = TreeNode(7)
    l9 = TreeNode(4)
    l1.left = l2
    l1.right = l3
    l2.left = l4
    l2.right = l5
    l3.left = l6
    l3.right = l7
    l5.left = l8
    l5.right = l9
    result = obj.lowestCommonAncestor(l1, l5, l6)
    print(result.val)
