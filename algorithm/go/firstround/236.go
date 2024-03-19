package firstround

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 递归,时间复杂度O(n),空间复杂度O(n)
func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	if root == nil || p == nil || q == nil {
		return nil
	}

	ansector = nil
	isFind = false

	traverse(root, p, q)
	return ansector
}

var ansector *TreeNode
var isFind bool

func traverse(node, p, q *TreeNode) bool {
	if isFind {
		return true
	}
	if node == nil {
		return false
	}

	isFindLeft := traverse(node.Left, p, q)
	isFindRight := traverse(node.Right, p, q)
	if isFind {
		return true
	} else if (isFindLeft && isFindRight) || ((isFindLeft || isFindRight) && (node == p || node == q)) {
		ansector = node
		isFind = true
		return true
	} else if isFindLeft || isFindRight || node == p || node == q {
		return true
	}

	return false
}
