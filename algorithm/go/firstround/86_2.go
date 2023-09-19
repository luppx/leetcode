package firstround

type ListNode struct {
	Val  int
	Next *ListNode
}

func partition(head *ListNode, x int) *ListNode {
	if head == nil {
		return head
	}

	dummyOrigin := &ListNode{Next: head}
	dummyNew := &ListNode{}
	curOrigin, curNew := dummyOrigin, dummyNew
	for curOrigin.Next != nil {
		if curOrigin.Next.Val < x {
			curNew.Next = curOrigin.Next
			curNew = curNew.Next

			curOrigin.Next = curOrigin.Next.Next
		} else {
			curOrigin = curOrigin.Next
		}
	}

	curNew.Next = dummyOrigin.Next
	return dummyNew.Next
}
