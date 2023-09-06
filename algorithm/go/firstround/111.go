package firstround

type TreeNode struct {
	Val         int
	Left, Right *TreeNode
}

func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}

	q := make([]*TreeNode, 0)
	q = append(q, root)
	res := 1
	for len(q) > 0 {
		length := len(q)
		for i := 0; i < length; i++ {
			node := q[0]
			q = q[1:]

			// 判断是否为叶子结点
			if node.Left == nil && node.Right == nil {
				return res
			}

			if node.Left != nil {
				q = append(q, node.Left)
			}

			if node.Right != nil {
				q = append(q, node.Right)
			}
		}
		res++
	}

	return -1
}
