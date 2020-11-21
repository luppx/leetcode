# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        def recur(pre_root, in_left, in_right):
            '''
            :param pre_root: 先序遍历中当前子树根节点的下标
            :param in_left: 中序遍历中子树的左边界
            :param in_right: 中序遍历中子树的右边界
            :return: 每个子树的根节点
            in_root：中序遍历中当前子树根节点的下标
            '''
            if in_left > in_right:
                return
            node = TreeNode(preorder[pre_root])
            in_root = dic[preorder[pre_root]]
            node.left = recur(pre_root + 1, in_left, in_root - 1)
            node.right = recur(in_root - in_left + pre_root + 1, in_root + 1, in_right)
            return node

        dic = {}
        for i in range(len(inorder)):
            dic[inorder[i]] = i
        return recur(0, 0, len(inorder) - 1)


if __name__ == '__main__':
    obj = Solution()
    preorder = [3,9,20,15,7]
    inorder = [9,3,15,20,7]
    result = obj.buildTree(preorder, inorder)
    print(result.val)
