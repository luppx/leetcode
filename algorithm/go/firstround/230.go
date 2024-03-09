package firstround

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 中序遍历,时间复杂度O(logn),空间复杂度O(n)
func kthSmallest(root *TreeNode, k int) int {
	if root == nil || k < 1 {
		return -1
	}
	cnt, val = 0, 0
	midOrder(root, k)
	return val
}

var (
	cnt, val int
)

func midOrder(node *TreeNode, k int) {
	if node == nil || cnt >= k {
		return
	}

	midOrder(node.Left, k)

	if cnt >= k {
		return
	} else if cnt == k-1 {
		cnt++
		val = node.Val
		return
	} else {
		cnt++
	}

	midOrder(node.Right, k)
}
