package firstround

//func diameterOfBinaryTree(root *TreeNode) int {
//	if root == nil {
//		return 0
//	}
//	res := 0
//	traverse(root, &res)
//	return res
//}
//
//func traverse(node *TreeNode, res *int) int {
//	if node == nil {
//		return 0
//	}
//
//	leftMaxEdgeNum, rightMaxEdgeNum := 0, 0
//	if node.Left != nil {
//		leftMaxEdgeNum = traverse(node.Left, res) + 1
//	}
//
//	if node.Right != nil {
//		rightMaxEdgeNum = traverse(node.Right, res) + 1
//	}
//
//	*res = max(*res, leftMaxEdgeNum+rightMaxEdgeNum)
//
//	return max(leftMaxEdgeNum, rightMaxEdgeNum)
//}
//
//func max(a, b int) int {
//	if a < b {
//		return b
//	}
//	return a
//}

func diameterOfBinaryTree(root *TreeNode) int {
	if root == nil {
		return 0
	}
	res := 0
	traverse(root, &res)
	return res
}

func traverse(node *TreeNode, res *int) int {
	if node == nil {
		return 0
	}

	leftMaxDepth := traverse(node.Left, res)
	rightMaxDepth := traverse(node.Right, res)

	*res = max(*res, leftMaxDepth+rightMaxDepth)

	return max(leftMaxDepth, rightMaxDepth) + 1
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}
