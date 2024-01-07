package firstround

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

// 递归,时间复杂度O(N),空间复杂度O(N)(递归遍历树的N个节点)
// func flatten(root *TreeNode)  {
// 	if root == nil {
// 		return
// 	}

// 	traverse(root)
// 	return
// }

// func traverse(node *TreeNode) *TreeNode {
// 	if node == nil || (node.Left == nil && node.Right == nil) {
// 		return node
// 	}

// 	// 左右子树的最后一个节点
// 	leftLast := traverse(node.Left)
// 	rightLast := traverse(node.Right)

// 	rightChild := node.Right
// 	// 左子树不为空,则应将其换到右子树,再将原右子树拼接到原左子树的最后一个节点
// 	if node.Left != nil {
// 		node.Right = node.Left
// 		node.Left = nil
// 		// 判断右子树是否为空
// 		if rightChild != nil {
// 			leftLast.Right = rightChild
// 			return rightLast
// 		} else {
// 			return leftLast
// 		}
// 	}

// 	// 左子树为空,则返回右子树最后一个节点
// 	return rightLast
// }

// 迭代,时间复杂度O(N),空间复杂度O(1)
func flatten(root *TreeNode)  {
	if root == nil {
		return
	}

	cur := root
	// 先处理大的左子树和大的右子树,再在遍历过程中不断处理缩小的左子树和右子树
	for cur != nil {
		if cur.Left != nil {
			// 左子树的最右叶子节点,也就是右子树的前驱节点
			leftLast := cur.Left

			for leftLast.Right != nil {
				leftLast = leftLast.Right
			}

			leftLast.Right = cur.Right
			cur.Left, cur.Right = nil, cur.Left
		}
		
		cur = cur.Right
	}
}