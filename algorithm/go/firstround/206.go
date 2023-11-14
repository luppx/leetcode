package firstround

type ListNode struct {
	Val  int
	Next *ListNode
}

// 递归，时间复杂度O(N)，空间复杂度O(N)
func reverseList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	// last: 表示反转从head.Next到链表末尾的链表，反转后链表的头节点，即原链表的最后一个节点
	last := reverseList(head.Next)
	head.Next.Next = head
	head.Next = nil
	return last
}

// 迭代，时间复杂度O(N)，空间复杂度O(1)
func reverseList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	cur := head
	var prev *ListNode
	for cur != nil {
		next := cur.Next
		cur.Next = prev
		prev = cur
		cur = next
	}
	return prev
}
