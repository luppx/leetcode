package firstround

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

// 递归，时间复杂度O(n),空间复杂度O(n)
// 当找到要删除节点时:
// 1.如果左孩子不为空，则用左孩子替代它。如果要删除节点的右孩子不为空，则将要删除节点的左孩子的右孩子插入到要删除节点的右子树中
// 2.如果右孩子不为空，因为进入到条件2，说明不满足条件1，即左孩子为空，所以则直接用右孩子替代它即可
// 这样形成的新二叉搜索树会较高(因为将左孩子的右子树给插入到要删除节点的右子树中了)
// 可以改进:
// 找到要删除节点时，找到它左子树中的最大值，或者它右子树中的最小值来替代它，然后将这个节点从原来的位置上给删除
func deleteNode(root *TreeNode, key int) *TreeNode {
	if root == nil {
		return nil
	}

	if root.Val == key {
		return adjustTree(root)
	} else if root.Val > key {
		root.Left = deleteNode(root.Left, key)
	} else {
		root.Right = deleteNode(root.Right, key)
	}

	return root
}

func adjustTree(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	
	var newRoot *TreeNode
	if root.Left != nil {
		newRoot = root.Left

		newRootOriginRightChild := newRoot.Right
		if root.Right != nil {
			newRoot.Right = root.Right
			if newRootOriginRightChild != nil {
				newRoot.Right = insertIntoBST(newRoot.Right, newRootOriginRightChild)
			}
		}
	} else if root.Right != nil {
		newRoot = root.Right
	}

	return newRoot
}

func insertIntoBST(root *TreeNode, node *TreeNode) *TreeNode {
	if root == nil {
		return node
	}

	if root.Val > node.Val {
		root.Left = insertIntoBST(root.Left, node)
	} else if root.Val < node.Val {
		root.Right = insertIntoBST(root.Right, node)
	}

	return root
}