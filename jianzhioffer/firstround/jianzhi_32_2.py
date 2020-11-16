import collections

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        nodelist = []
        queue = collections.deque()
        queue.append(root)
        while queue:
            tmp = []
            for _ in range(len(queue)):
                node = queue.popleft()
                tmp.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            nodelist.append(tmp)
        return nodelist


if __name__ == '__main__':
    l1 = TreeNode(3)
    l2 = TreeNode(9)
    l3 = TreeNode(20)
    l4 = TreeNode(15)
    l5 = TreeNode(7)
    # l6 = TreeNode(4)
    # l7 = TreeNode(3)

    l1.left = l2
    l1.right = l3
    l3.left = l4
    l3.right = l5
    # l2.left = l4
    # l2.right = l5
    # l3.left = l6
    # l3.right = l7
    obj = Solution()
    result = obj.levelOrder(l1)
    print(result)
