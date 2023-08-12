package firstround

type ListNode struct {
	Val  int
	Next *ListNode
}

// 遍历两次
//func middleNode(head *ListNode) *ListNode {
//	if head == nil {
//		return nil
//	}
//
//	n := 0
//	p := head
//	for p != nil {
//		p = p.Next
//		n++
//	}
//
//	middle := n / 2
//	p = head
//	for i := 0; i < middle; i++ {
//		p = p.Next
//	}
//	return p
//}

// 快慢指针, 快指针走两步, 慢指针走一步
func middleNode(head *ListNode) *ListNode {
	if head == nil {
		return head
	}

	slow, fast := head, head
	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}

	return slow
}
