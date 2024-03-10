package firstround

import "math"

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

// 后序遍历,时间复杂度O(n),空间复杂度O(n)
func isValidBST(root *TreeNode) bool {
	if root == nil {
		return true
	}
	res, _, _ := traverse(root)
	return res
}


func traverse(node *TreeNode) (bool, int, int) {
	if node == nil {
		return true, math.MaxInt32, math.MinInt32
	}

	leftMin, leftMax, rightMin, rightMax := node.Val, node.Val, node.Val, node.Val
	leftValid, rightValid := false, false
	
	if node.Left != nil {
		leftValid, leftMin, leftMax = traverse(node.Left)
		if !leftValid || node.Val <= leftMax {
			return false, 0, 0
		}
	}
	
	if node.Right != nil {
		rightValid, rightMin, rightMax = traverse(node.Right)
		if !rightValid || node.Val >= rightMin {
			return false, 0, 0
		}
	}

	return true, leftMin, rightMax
}

// 前序遍历
func isValidBST(root *TreeNode) bool {
	if root == nil {
		return true
	}
	return traverse(root, math.MinInt64, math.MaxInt64)
}

func traverse(node *TreeNode, lower, upper int) bool {
	if node == nil {
		return true
	}

	if node.Val <= lower || node.Val >= upper {
		return false
	}

	return traverse(node.Left, lower, node.Val) && traverse(node.Right, node.Val, upper)
}

// 中序遍历,二叉搜索树中序遍历是一个递增序列
func isValidBST(root *TreeNode) bool {
	if root == nil {
		return true
	}
	res, _ := traverse(root, math.MinInt64)
	return res
}

func traverse(node *TreeNode, preNum int) (bool, int) {
	if node == nil {
		return true, preNum
	}

	leftValid, leftNum := traverse(node.Left, preNum)
	
	if !leftValid || node.Val <= leftNum {
		return false, 0
	}
	
	return traverse(node.Right, node.Val)
}