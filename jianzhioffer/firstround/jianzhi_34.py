# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        节点值和sum值可能为正也可能为负
        """
        def recur(node, subsum):
            if not node:
                return
            subsum += node.val
            path.append(node.val)
            if subsum == sum and not node.left and not node.right:
                # 记录路径时若直接执行res.append(path)，则是将path对象加入了res后续path改变时，
                # res中的path对象也会随之改变。正确做法：res.append(list(path))，
                # 相当于复制了一个 path 并加入到 res 。
                res.append(list(path))
            if node.left:
                recur(node.left, subsum)
            if node.right:
                recur(node.right, subsum)
            path.pop()

        if not root:
            return []
        res, path = [], []
        recur(root, 0)
        return res


if __name__ == '__main__':
    l1 = TreeNode(1)
    l2 = TreeNode(0)
    l3 = TreeNode(1)
    l4 = TreeNode(1)
    l5 = TreeNode(2)
    l6 = TreeNode(0)
    l7 = TreeNode(-1)
    l8 = TreeNode(0)
    l9 = TreeNode(1)
    l10 = TreeNode(-1)
    l11 = TreeNode(0)
    l12 = TreeNode(-1)
    l13 = TreeNode(0)
    l14 = TreeNode(1)
    l15 = TreeNode(0)

    l1.left = l2
    l1.right = l3
    l2.left = l4
    l2.right = l5
    l3.left = l6
    l3.right = l7
    l4.left = l8
    l4.right = l9
    l5.left = l10
    l5.right = l11
    l6.left = l12
    l6.right = l13
    l7.left = l14
    l7.right = l15

    obj = Solution()
    result = obj.pathSum(l1, 2)
    print(result)
