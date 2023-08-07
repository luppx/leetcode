package main

type ListNode struct {
	Val  int
	Next *ListNode
}

// 双指针+虚拟头节点, 时间复杂度O(n), 空间复杂度O(1)
//func getKthFromEnd(head *ListNode, k int) *ListNode {
//	if head == nil {
//		return head
//	}
//
//	vHead := ListNode{
//		Val:  -1,
//		Next: head,
//	}
//	left, right := &vHead, &vHead
//
//	for i := 0; i < k; i++ {
//		right = right.Next
//		// k大于链表长度
//		if right == nil {
//			return nil
//		}
//	}
//
//	for right != nil {
//		left = left.Next
//		right = right.Next
//	}
//	return left
//}

// 双指针, 时间复杂度O(n), 空间复杂度O(1)
func getKthFromEnd(head *ListNode, k int) *ListNode {
	if head == nil {
		return head
	}

	left, right := head, head

	for i := 0; i < k; i++ {
		// k大于链表长度
		if right == nil {
			return nil
		}
		right = right.Next
	}

	for right != nil {
		left = left.Next
		right = right.Next
	}
	return left
}
