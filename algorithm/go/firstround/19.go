package firstround

type ListNode struct {
	Val  int
	Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	if head == nil {
		return nil
	}

	dummy := &ListNode{Next: head}
	right := dummy
	for i := 0; i < n; i++ {
		right = right.Next
		// n大于链表长度
		if right == nil {
			return head
		}
	}

	left := dummy
	for right.Next != nil {
		left = left.Next
		right = right.Next
	}

	left.Next = left.Next.Next

	return dummy.Next
}
