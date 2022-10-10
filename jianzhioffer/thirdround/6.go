package main

// ListNode Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

//func reversePrint(head *ListNode) []int {
//	if head == nil {
//		return []int{}
//	}
//
//	res := make([]int, 0)
//	cur := head
//
//	for cur != nil {
//		res = append(res, cur.Val)
//		cur = cur.Next
//	}
//
//	for i, j := 0, len(res)-1; i < j; i, j = i+1, j-1 {
//		res[i], res[j] = res[j], res[i]
//	}
//	return res
//}

// 递归
//func reversePrint(head *ListNode) []int {
//	if head == nil {
//		return []int{}
//	}
//
//	return append(reversePrint(head.Next), head.Val)
//}

// 反转链表
func reversePrint(head *ListNode) []int {
	if head == nil {
		return []int{}
	}

	var prev *ListNode
	cur := head
	for cur != nil {
		next := cur.Next
		cur.Next = prev
		prev = cur
		cur = next
	}

	res := make([]int, 0)
	for prev != nil {
		res = append(res, prev.Val)
		prev = prev.Next
	}
	return res
}

func main() {
	n1 := ListNode{1, nil}
	n2 := ListNode{2, nil}
	n3 := ListNode{3, nil}
	n1.Next = &n2
	n2.Next = &n3

	result := reversePrint(&n1)
	for _, v := range result {
		println(v)
	}
}
