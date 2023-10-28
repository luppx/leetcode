package firstround

type ListNode struct {
	Val  int
	Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	if head == nil || n < 1 {
		return head
	}

	fast := head
	for i := 0; i < n; i++ {
		// 说明n>len(list)
		if fast == nil {
			return head
		}
		fast = fast.Next
	}

	dummy := &ListNode{Next: head}
	pre := dummy
	slow := head
	for fast != nil {
		pre = slow
		slow = slow.Next
		fast = fast.Next
	}

	pre.Next = slow.Next
	return dummy.Next
}
