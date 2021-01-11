# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# queue.Queue()比collections.deque()慢很多，
# 以后如果要用队列的话尽量使用collections.deque()，而且collections.deque()还是双端队列
# import queue
import collections
class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return "[]"
        que = collections.deque()
        que.append(root)
        res = []
        while que:
            node = que.popleft()
            if node:
                res.append(str(node.val))
                que.append(node.left)
                que.append(node.right)
            else:
                res.append("null")

        return "[" + ','.join(res) + "]"

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        if data == "[]":
            return None
        vals = data[1:-1].split(',')
        i = 1
        root = TreeNode(int(vals[0]))
        que = collections.deque()
        que.append(root)
        while que:
            node = que.popleft()
            if vals[i] != "null":
                node.left = TreeNode(int(vals[i]))
                que.append(node.left)
            i += 1
            if vals[i] != "null":
                node.right = TreeNode(int(vals[i]))
                que.append(node.right)
            i += 1
        return root


if __name__ == '__main__':
    # Your Codec object will be instantiated and called as such:
    # codec = Codec()
    # codec.deserialize(codec.serialize(root))
    codec = Codec()
    l1 = TreeNode(1)
    l2 = TreeNode(2)
    l3 = TreeNode(3)
    l4 = TreeNode(4)
    l5 = TreeNode(5)
    l1.left = l2
    l1.right = l3
    l3.left = l4
    l3.right = l5
    # res = codec.serialize(l1)
    # print(res)
    destr = "[1,2,3,null,null,4,5,null,null,null,null]"
    de_res = codec.deserialize(destr)
    print(de_res)
