package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func deleteNode(head *ListNode, val int) *ListNode {
	if head == nil {
		return nil
	}

	virtualHead := &ListNode{Next: head}
	i, j := virtualHead, head
	for j != nil {
		if j.Val == val {
			i.Next = j.Next
			return virtualHead.Next
		}

		i = j
		j = j.Next
	}
	return virtualHead.Next
}
