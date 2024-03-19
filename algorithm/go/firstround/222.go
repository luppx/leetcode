package firstround

import "math"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 时间复杂度O(logn * logn)
func countNodes(root *TreeNode) int {
	l, r := root, root
	hl, hr := 0, 0
	for l != nil {
		l = l.Left
		hl++
	}
	for r != nil {
		r = r.Right
		hr++
	}

	// 满二叉树
	if hl == hr {
		return int(math.Pow(2, float64(hl)) - 1)
	} else { // 不是满二叉树则遍历子树计算节点数
		return 1 + countNodes(root.Left) + countNodes(root.Right)
	}
}
