package firstround

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

func constructFromPrePost(preorder []int, postorder []int) *TreeNode {
	if preorder == nil || postorder == nil || len(preorder) != len(postorder) || len(preorder) == 0 {
		return nil
	}

	postIdxMap := make(map[int]int)
	for i, n := range postorder {
		postIdxMap[n] = i
	}

	return build(preorder, postorder, postIdxMap, 0, len(postorder)-1, 0, len(postorder)-1)
}

func build(preorder, postorder []int, postIdxMap map[int]int, preRootIdx, postRootIdx, postLeftBound, postRightBound int) *TreeNode {
	if preRootIdx >= len(preorder) {
		return nil
	}

	node := &TreeNode{Val: preorder[preRootIdx]}
	// 到达叶子节点
	if postLeftBound == postRightBound {
		return node
	}

	// 左子树
	preLeftTreeRootIdx := preRootIdx+1
	postLeftTreeRootIdx := postIdxMap[preorder[preLeftTreeRootIdx]]
	leftTreeLen := postLeftTreeRootIdx - postLeftBound + 1
	node.Left = build(preorder, postorder, postIdxMap, preLeftTreeRootIdx, postLeftTreeRootIdx, postLeftBound, postLeftTreeRootIdx)

	// 判断是否有右子树
	postRightTreeRootIdx := postRootIdx - 1	
	if postLeftTreeRootIdx < postRightTreeRootIdx {
		preRightTreeRootIdx := preLeftTreeRootIdx + leftTreeLen
		node.Right = build(preorder, postorder, postIdxMap, preRightTreeRootIdx, postRightTreeRootIdx, postLeftTreeRootIdx+1, postRightTreeRootIdx)
	}
	
	return node	
}