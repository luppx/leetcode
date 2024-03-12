package firstround

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

// 时间复杂度O(n),空间复杂度O(n),使用迭代可将空间复杂度优化至O(1)
func insertIntoBST(root *TreeNode, val int) *TreeNode {
	if root == nil {
		return &TreeNode{Val: val}
	}

	if root.Val > val {
		root.Left = insertIntoBST(root.Left, val)
	} else if root.Val < val {
		root.Right = insertIntoBST(root.Right, val)
	}

	return root
}