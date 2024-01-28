package firstround

import "fmt"

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

// 方法一:序列化
// Reference: https://leetcode.cn/problems/find-duplicate-subtrees/solutions/1798953/xun-zhao-zhong-fu-de-zi-shu-by-leetcode-zoncw/
// func findDuplicateSubtrees(root *TreeNode) []*TreeNode {
// 	if root == nil {
// 		return nil
// 	}

// 	// 记录各节点的后序遍历顺序
// 	found := make(map[string]*TreeNode)
// 	// 记录找到的重复子树
// 	repeat := make(map[*TreeNode]struct{})

// 	postOrder(root, found, repeat)

// 	res := make([]*TreeNode, 0)
// 	for node, _ := range repeat {
// 		res = append(res, node)
// 	}
// 	return res
// }

// func postOrder(node *TreeNode, found map[string]*TreeNode, repeat map[*TreeNode]struct{}) string {
// 	if node == nil {
// 		return ""
// 	}

// 	leftPostOrder := postOrder(node.Left, found, repeat)
// 	rightPostOrder := postOrder(node.Right, found, repeat)

// 	nodePostOrder := fmt.Sprintf("(%s)(%s)%d", leftPostOrder, rightPostOrder, node.Val)
// 	// 判断是否存在重复子树
// 	if n, ok := found[nodePostOrder]; ok {
// 		repeat[n] = struct{}{}
// 	} else {
// 		found[nodePostOrder] = node
// 	}

// 	return nodePostOrder
// }

// 方法二:三元组,时间复杂度O(n),空间复杂度O(n)
// pair记录一棵子树的根节点以及这棵子树的唯一序号idx
// 如果两棵子树是重复子树,那么这两棵子树的序号idx是相同的
type pair struct {
	node *TreeNode
	idx int
}

func findDuplicateSubtrees(root *TreeNode) []*TreeNode {
	if root == nil {
		return nil
	}

	found := make(map[[3]int]*pair)
	repeat := make(map[*TreeNode]struct{})
	idx := 0
	postOrder(root, found, repeat, &idx)

	res := make([]*TreeNode, 0)
	for node, _ := range repeat {
		res = append(res, node)
	}
	return res
}

// 使用序号idx来代表一棵子树,如果两棵子树是重复子树,那么这两棵子树的序号idx相同
func postOrder(node *TreeNode, found map[[3]int]*pair, repeat map[*TreeNode]struct{}, idx *int) int {
	if node == nil {
		return 0
	}

	leftIdx := postOrder(node.Left, found, repeat, idx)
	rightIdx := postOrder(node.Right, found, repeat, idx)

	// 通过三元组唯一确定一棵子树
	tripple := [3]int{node.Val, leftIdx, rightIdx}
	// 判断是否有重复子树,如果存在相同的三元组则有重复的子树
	if p, ok := found[tripple]; ok {
		repeat[p.node] = struct{}{}

		// 存在重复的三元组,则说明该子树并不是新的子树,因此返回这个代表这个已知子树的序号idx
		return p.idx
	}

	// 未找到重复三元组,说明该子树是新发现的子树,要用一个新序号idx来表示该子树
	(*idx) += 1
	p := &pair{node: node, idx: (*idx)}
	found[tripple] = p
	
	return *idx
}