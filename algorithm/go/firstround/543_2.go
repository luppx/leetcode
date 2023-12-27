package firstround

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

var res int = 0
func diameterOfBinaryTree(root *TreeNode) int {
	if root == nil {
		return 0
	}
	res = 0
	maxDepth(root)
	return res
}

func maxDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}

	leftDepth := maxDepth(root.Left)
	rightDepth := maxDepth(root.Right)

	// 更新最大直径
	if leftDepth + rightDepth > res {
		res = leftDepth + rightDepth
	}

	if leftDepth >= rightDepth {
		return leftDepth+1
	}
	return rightDepth+1
}