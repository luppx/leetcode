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
        树为二叉搜索树。二叉搜索树的性质：root.left.val<root.val<root.right.val
        且题目已经说明，所有节点的值都是唯一的
        """
        if not root:
            return None
        while root:
            if root.val > p.val and root.val > q.val:  # p、q的值都大于/小于root，根据二叉搜索树性质，p q都在root的同一侧，则root不为它们的公共祖先
                root = root.left
            elif root.val < p.val and root.val < q.val:
                root = root.right
            else:  # 只要p、q不在同一边，那么根据二叉搜索树的性质，root就是p q的公共祖先，而且肯定是最近公共祖先
                break
        return root


if __name__ == '__main__':
    obj = Solution()
    l1 = TreeNode(6)
    l2 = TreeNode(2)
    l3 = TreeNode(8)
    l4 = TreeNode(0)
    l5 = TreeNode(4)
    l6 = TreeNode(7)
    l7 = TreeNode(9)
    l8 = TreeNode(3)
    l9 = TreeNode(5)
    l1.left = l2
    l1.right = l3
    l2.left = l4
    l2.right = l5
    l3.left = l6
    l3.right = l7
    l5.left = l8
    l5.right = l9
    result = obj.lowestCommonAncestor(l1, l2, l5)
    print(result.val)
