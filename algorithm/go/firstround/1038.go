package firstround

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 反向中序遍历,先遍历右子树,再遍历左子树.时间复杂度O(n),空间复杂度O(n)
func bstToGst(root *TreeNode) *TreeNode {
	if root == nil || (root.Left == nil && root.Right == nil) {
		return root
	}
	traverse(root, 0)
	return root
}

func traverse(node *TreeNode, greaterSum int) int {
	if node == nil {
		return greaterSum
	}

	sumRight := traverse(node.Right, greaterSum)
	node.Val += sumRight
	sumLeft := traverse(node.Left, node.Val)
	return sumLeft
}
