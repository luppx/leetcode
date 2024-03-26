package firstround

type ListNode struct {
	Val  int
	Next *ListNode
}

// 时间复杂度O(n),空间复杂度O(1)
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1.Val==0 && l1.Next==nil {
		return l2
	} else if l2.Val==0 && l2.Next==nil {
		return l1
	}

	dummy := &ListNode{}
	cur, cur1, cur2 := dummy, l1, l2
	mod := 0
	for cur1 != nil || cur2 != nil {
		sum := 0
		if cur1 != nil && cur2 != nil {
			sum = cur1.Val + cur2.Val + mod
			cur1 = cur1.Next
			cur2 = cur2.Next
		} else if cur1 != nil {
			sum = cur1.Val + mod
			cur1 = cur1.Next
		} else {
			sum = cur2.Val + mod
			cur2 = cur2.Next
		}

		node := &ListNode{Val: sum % 10}
		cur.Next = node
		cur = cur.Next
		mod = sum / 10
	}

	if mod != 0 {
		cur.Next = &ListNode{Val: mod}
	}
	return dummy.Next
} 