package firstround

type ListNode struct {
	Val  int
	Next *ListNode
}

// 时间复杂度O(m+n),空间复杂度O(1)
func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	if list1 == nil {
		return list2
	}
	if list2 == nil {
		return list1
	}

	dummy := &ListNode{}
	cur, cur1, cur2 := dummy, list1, list2
	for cur1 != nil && cur2 != nil {
		if cur1.Val <= cur2.Val {
			cur.Next = cur1
			cur1 = cur1.Next
		} else {
			cur.Next = cur2
			cur2 = cur2.Next
		}
		cur = cur.Next
	}

	if cur1 != nil {
		cur.Next = cur1
	}
	if cur2 != nil {
		cur.Next = cur2
	}

	return dummy.Next
}
