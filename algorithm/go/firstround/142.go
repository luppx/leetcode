package firstround

type ListNode struct {
	Val  int
	Next *ListNode
}

func hasCycle(head *ListNode) (*ListNode, bool) {
	slow, fast := head, head

	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
		if slow == fast {
			return slow, true
		}
	}

	return nil, false
}

func detectCycle(head *ListNode) *ListNode {
	// 先判断是否有环, 有环找到快慢指针在环中相遇的节点
	p1, isCycle := hasCycle(head)

	// 无环
	if !isCycle {
		return nil
	}

	// 令一个指针指向链表头节点, 让p1 p2以相同速度前进, 当他们再次相遇时就是环的入口节点
	p2 := head
	for p1 != p2 {
		p1 = p1.Next
		p2 = p2.Next
	}

	return p1
}
