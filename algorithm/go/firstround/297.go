package firstround

import (
	"strconv"
	"strings"
)

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

type Codec struct {
}

func Constructor() Codec {
    return Codec{}
}

// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {
    nodeSlice := make([]string, 0)
	var preOrder func(*TreeNode)
	preOrder = func (node *TreeNode) {
		if node == nil {
			nodeSlice = append(nodeSlice, "null")
			return
		}

		nodeSlice = append(nodeSlice, strconv.Itoa(node.Val))

		preOrder(node.Left)
		preOrder(node.Right)
	}

	preOrder(root)
	return strings.Join(nodeSlice, ",")
}

// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {    
    if data == "" || data == "null" {
		return nil
	}

	nodes := strings.Split(data, ",")

	var build func() *TreeNode
	build = func () *TreeNode {
        if nodes == nil || len(nodes) == 0 || nodes[0] == "null" {
			nodes = nodes[1:]
			return nil
		}

		val, _ := strconv.Atoi(nodes[0])
		node := &TreeNode{Val: val}

		nodes = nodes[1:]
		node.Left = build()
		node.Right = build()
		return node
	}

	return build()
}