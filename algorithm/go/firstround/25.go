package firstround

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	if head == nil || head.Next == nil || k < 2 {
		return head
	}

	dummy := &ListNode{Next: head}
	prev := dummy
	cur := head
	for cur != nil {
		node := cur
		// 判断剩余节点数量是否大于等于k，小于k则无需反转
		for i := 0; i < k; i++ {
			if cur == nil {
				return dummy.Next
			}
			cur = cur.Next
		}

		// 反转从node开始的k个节点
		h := node
		var p *ListNode
		for i := 0; i < k; i++ {
			next := node.Next
			node.Next = p
			p = node
			node = next
		}
		prev.Next = p
		h.Next = cur

		// 反转完成之后更新prev
		prev = h
	}

	return dummy.Next
}
