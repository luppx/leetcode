package firstround

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 时间复杂度O(n),空间复杂度O(1)
func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	var minVal, maxVal int
	if p.Val <= q.Val {
		minVal = p.Val
		maxVal = q.Val
	} else {
		minVal = q.Val
		maxVal = p.Val
	}

	// p,q分别在root的左右子树上,或者p,q中的一个节点为当前root节点
	if (root.Val > minVal && root.Val < maxVal) || root == p || root == q {
		return root
	} else if root.Val > maxVal { // root.Val比两个节点值都大,往左子树查找
		return lowestCommonAncestor(root.Left, p, q)
	} else if root.Val < minVal { // root.Val比两个节点值都小,往右子树查找
		return lowestCommonAncestor(root.Right, p, q)
	}

	return nil
}
