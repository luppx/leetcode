package firstround

type ListNode struct {
	Val  int
	Next *ListNode
}

// 递归，时间复杂度O(N)，空间复杂度O(N)
func reverseBetween(head *ListNode, left, right int) *ListNode {
	if left == 1 {
		return reverseN(head, right)
	}

	head.Next = reverseBetween(head.Next, left-1, right-1)
	return head
}

// 反转从链表头节点开始的前n个节点
// 后继节点
var successor *ListNode

func reverseN(head *ListNode, n int) *ListNode {
	if n == 1 {
		successor = head.Next
		return head
	}

	last := reverseN(head.Next, n-1)
	head.Next.Next = head
	head.Next = successor
	return last
}

// 迭代，时间复杂度O(N)，空间复杂度O(1)
func reverseBetween(head *ListNode, left, right int) *ListNode {
	virtualHead := &ListNode{Next: head}
	cur := head
	prev := virtualHead
	for i := 0; i < left-1; i++ {
		prev = cur
		cur = cur.Next
	}
	prev.Next = reverseN(cur, right-left+1)
	return virtualHead.Next
}

func reverseN(head *ListNode, n int) *ListNode {
	headNode := head
	cur := head
	var prev *ListNode
	for i := 0; i < n; i++ {
		next := cur.Next
		cur.Next = prev
		prev = cur
		cur = next
	}
	headNode.Next = cur
	return prev
}
