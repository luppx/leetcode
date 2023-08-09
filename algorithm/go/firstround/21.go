package firstround

type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	if list1 == nil {
		return list2
	} else if list2 == nil {
		return list1
	}

	resHead := &ListNode{Val: -1}
	resNode, node1, node2 := resHead, list1, list2
	for node1 != nil && node2 != nil {
		if node1.Val <= node2.Val {
			resNode.Next = node1
			node1 = node1.Next
		} else {
			resNode.Next = node2
			node2 = node2.Next
		}

		resNode = resNode.Next
	}

	if node1 == nil && node2 != nil {
		resNode.Next = node2
	} else if node2 == nil && node1 != nil {
		resNode.Next = node1
	}

	return resHead.Next
}
