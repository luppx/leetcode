package firstround

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

func constructMaximumBinaryTree(nums []int) *TreeNode {
	if nums == nil || len(nums) == 0 {
		return nil
	}

	// 找到nums 中最大值的索引
	idx := 0
	for i, n := range nums {
		if n > nums[idx] {
			idx = i
		}
	}

	node := &TreeNode{Val: nums[idx]}
	node.Left = constructMaximumBinaryTree(nums[:idx])
	node.Right = constructMaximumBinaryTree(nums[idx+1:])
	return node
}