package firstround

type ListNode struct {
	Val  int
	Next *ListNode
}

// 双指针.时间复杂度O(n),空间复杂度O(1)
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	dummy := &ListNode{Next: head}
	right := dummy
	i := 0
	for ; i < n && right != nil; i++ {
		right = right.Next
	}
	// n > length of list
	if i < n {
		return head
	}

	pre, left := dummy, dummy
	for right != nil {
		pre = left
		left = left.Next
		right = right.Next
	}
	pre.Next = left.Next
	return dummy.Next
}
