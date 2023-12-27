package firstround

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

func maxDepth(root *TreeNode) int {
	if (root == nil) {
		return 0
	}

	leftDepth := maxDepth(root.Left)
	rightDepth := maxDepth(root.Right)
	depth := leftDepth
	if rightDepth > leftDepth {
		depth = rightDepth
	}
	return depth+1
}