package firstround

type ListNode struct {
	Val  int
	Next *ListNode
}

func partition(head *ListNode, x int) *ListNode {
	if head == nil {
		return head
	}

	dummy := &ListNode{Val: -1, Next: head}
	right := dummy
	for right.Next != nil && right.Next.Val < x {
		right = right.Next
	}

	// 遍历到链表最后一个节点都还没有找到大于等于x的节点, 说明链表所有节点都小于x
	if right.Next == nil {
		return head
	}

	left, preRight := right, right
	right = right.Next
	for right != nil {
		if right.Val >= x {
			preRight = right
			right = right.Next
			continue
		}

		// 找到小于x的节点, 将它插入到所有小于x节点的末尾
		preRight.Next = right.Next

		tmp := left.Next
		left.Next = right
		right.Next = tmp

		left = right
		right = preRight.Next
	}

	return dummy.Next
}
