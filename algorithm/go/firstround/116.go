package firstround

type Node struct {
	Val int
	Left *Node
	Right *Node
	Next *Node
}

// 层序遍历,时间复杂度O(N),空间复杂度O(N)
// func connect(root *Node) *Node {
// 	if root == nil {
// 		return root
// 	}

// 	nodes := make([]*Node, 0)
// 	nodes = append(nodes, root)

// 	for len(nodes) > 0 {
// 		sz := len(nodes)
// 		for i := 0; i < sz; i++ {
// 			node := nodes[0]

// 			if node.Left != nil {
// 				nodes = append(nodes, node.Left)
// 			}
// 			if node.Right != nil {
// 				nodes = append(nodes, node.Right)
// 			}
// 			nodes = nodes[1:]
			
// 			// 连接next节点
// 			if i < sz-1 {
// 				node.Next = nodes[0]
// 			}
// 		}
// 	}

// 	return root
// }

// 利用Next指针遍历,时间复杂度O(N),空间复杂度O(1)
func connect(root *Node) *Node {
	if root == nil {
		return root
	}

	// 从每一层的最左侧节点开始遍历
	for leftMost := root; leftMost.Left != nil; leftMost = leftMost.Left {
		// 遍历该层节点,为下一层的节点连接Next指针
		for node := leftMost; node != nil; node = node.Next {
			node.Left.Next = node.Right
			if node.Next != nil {
				node.Right.Next = node.Next.Left
			}
		}
	}

	return root
}