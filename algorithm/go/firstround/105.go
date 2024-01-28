package firstround

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

func buildTree(preorder []int, inorder []int) *TreeNode {
	if preorder == nil || inorder == nil || (len(preorder) != len(inorder)) || len(preorder) == 0 {
		return nil
	}

	ioIdxMap := make(map[int]int)
	for i, n := range inorder {
		ioIdxMap[n] = i
	}
    // fmt.Printf("ioIdxMap: %v\n", ioIdxMap)
	return buildSubTree(preorder, inorder, ioIdxMap, 0, 0, len(inorder)-1)
}

func buildSubTree(preorder, inorder []int, ioIdxMap map[int]int, poRootIdx, ioLeftBound, ioRightBound int) *TreeNode {
	if poRootIdx >= len(preorder) || ioLeftBound > ioRightBound {
		return nil
	}

	root := &TreeNode{Val: preorder[poRootIdx]}
	ioRootIdx := ioIdxMap[preorder[poRootIdx]]
	leftTreeLen := ioRootIdx - ioLeftBound
	poRightTreeRootIdx := poRootIdx + leftTreeLen + 1

    // fmt.Printf("poRootIdx: %d, ioLeftBound: %d, ioRightBound: %d\n", poRootIdx, ioLeftBound, ioRightBound)
    // fmt.Printf("ioRootIdx: %d, leftTreeLen: %d, poRightTreeRootIdx: %d\n", ioRootIdx, leftTreeLen, poRightTreeRootIdx)
    // fmt.Printf("[left]poRootIdx: %d, ioLeftBound: %d, ioRightBound: %d\n", poRootIdx+1, ioLeftBound, ioRootIdx-1)
    // fmt.Printf("[right]poRootIdx: %d, ioLeftBound: %d, ioRightBound: %d\n\n", poRightTreeRootIdx, ioRootIdx+1, ioRightBound)
	
    root.Left = buildSubTree(preorder, inorder, ioIdxMap, poRootIdx+1, ioLeftBound, ioRootIdx-1)
	root.Right = buildSubTree(preorder, inorder, ioIdxMap, poRightTreeRootIdx, ioRootIdx+1, ioRightBound)
	return root
}