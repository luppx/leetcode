package firstround

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

func buildTree(inorder []int, postorder []int) *TreeNode {
	if inorder == nil || postorder == nil || len(inorder) != len(postorder) || len(inorder) == 0 {
		return nil
	}

	ioIdxMap := make(map[int]int)
	for i, n := range inorder {
		ioIdxMap[n] = i
	}

	return build(inorder, postorder, ioIdxMap, len(postorder)-1, 0, len(inorder)-1)
}

func build(inorder, postorder []int, ioIdxMap map[int]int, poRootIdx, ioLeftBound, ioRightBound int) *TreeNode {
	if ioLeftBound > ioRightBound {
		return nil
	}

	ioRootIdx := ioIdxMap[postorder[poRootIdx]]
	rightTreeLen := ioRightBound - ioRootIdx
	poLeftRootIdx := poRootIdx - rightTreeLen - 1

	node := &TreeNode{Val: postorder[poRootIdx]}
	node.Left = build(inorder, postorder, ioIdxMap, poLeftRootIdx, ioLeftBound, ioRootIdx-1)
	node.Right = build(inorder, postorder, ioIdxMap, poRootIdx-1, ioRootIdx+1, ioRightBound)
	return node
}