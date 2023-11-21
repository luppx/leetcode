package firstround

type ListNode struct {
	Val  int
	Next *ListNode
}

// 时间复杂度O(N), 空间复杂度O(1)
func isPalindrome(head *ListNode) bool {
	if head == nil {
		return false
	}

	// 快慢指针找到中点
	slow, fast := head, head
	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}

	// 链表节点数量为奇数
	if fast != nil {
		slow = slow.Next
	}

	// 反转后半部份链表，然后比较前后一半链表是否为回文链表
	q := reverseList(slow)
	p := head
	for q != nil {
		if p.Val != q.Val {
			return false
		}
		p = p.Next
		q = q.Next
	}

	return true
}

func reverseList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	var prev *ListNode
	cur := head
	for cur != nil {
		next := cur.Next
		cur.Next = prev
		prev = cur
		cur = next
	}
	return prev
}
