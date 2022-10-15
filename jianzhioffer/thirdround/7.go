package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

//// 递归
//func buildTree(preorder []int, inorder []int) *TreeNode {
//	if len(preorder) != len(preorder) || len(preorder) == 0 {
//		return nil
//	} else if len(preorder) == 1 {
//		return &TreeNode{Val: preorder[0]}
//	}
//
//	m := make(map[int]int)
//	for i, v := range inorder {
//		m[v] = i
//	}
//	return buildSubTree(preorder, inorder, 0, 0, len(inorder)-1, m)
//}
//
//func buildSubTree(preorder []int, inorder []int, preIndex int, inLeftIndex int, inRightIndex int, m map[int]int) *TreeNode {
//	if preIndex >= len(preorder) || inLeftIndex > inRightIndex {
//		return nil
//	}
//	node := &TreeNode{Val: preorder[preIndex]}
//	inIndex := m[preorder[preIndex]] // 父节点在中序遍历序列的位置
//	node.Left = buildSubTree(preorder, inorder, preIndex+1, inLeftIndex, inIndex-1, m)
//	node.Right = buildSubTree(preorder, inorder, preIndex+(inIndex-inLeftIndex)+1, inIndex+1, inRightIndex, m)
//	return node
//}

// 递归，利用golang slice底层共享同一数组的特性
func buildTree(preorder []int, inorder []int) *TreeNode {
	if len(preorder) != len(preorder) || len(preorder) == 0 {
		return nil
	} else if len(preorder) == 1 {
		return &TreeNode{Val: preorder[0]}
	}

	idx := 0
	for ; idx < len(inorder); idx++ {
		if inorder[idx] == preorder[0] {
			break
		}
	}

	node := &TreeNode{preorder[0], nil, nil}
	// slice为左闭右开
	node.Left = buildTree(preorder[1:idx+1], inorder[:idx])
	node.Right = buildTree(preorder[idx+1:], inorder[idx+1:])
	return node
}

func main() {
	preorder := []int{3, 9, 20, 15, 7}
	inorder := []int{9, 3, 15, 20, 7}
	root := buildTree(preorder, inorder)
	print(root.Val)
}
