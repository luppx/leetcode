package firstround

import (
	"container/heap"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

//func mergeKLists(lists []*ListNode) *ListNode {
//	if lists == nil || len(lists) < 1 {
//		return nil
//	}
//
//	dummy := &ListNode{Val: -1}
//	curNode := dummy
//	for {
//		minNode := &ListNode{Val: 10001} // -10^4 <= List[i][j] <= 10^4
//		index, endCount := 0, 0
//		for i, node := range lists {
//			if node == nil {
//				endCount++
//				continue
//			}
//
//			if node.Val < minNode.Val {
//				minNode = node
//				index = i
//			}
//		}
//
//		// 如果所有链表都为空, 即已遍历完所有链表, 跳出循环
//		if endCount == len(lists) {
//			break
//		}
//
//		// 将最小节点从原链表中取出, 加入到dummy链表中
//		lists[index] = minNode.Next
//		minNode.Next = nil
//
//		curNode.Next = minNode
//		curNode = curNode.Next
//	}
//	return dummy.Next
//}

type PriorityQueue []*ListNode

func (pq *PriorityQueue) Len() int           { return len(*pq) }
func (pq *PriorityQueue) Less(i, j int) bool { return (*pq)[i].Val < (*pq)[j].Val }
func (pq *PriorityQueue) Swap(i, j int)      { (*pq)[i], (*pq)[j] = (*pq)[j], (*pq)[i] }

func (pq *PriorityQueue) Push(x interface{}) {
	node := x.(*ListNode)
	*pq = append(*pq, node)
}

func (pq *PriorityQueue) Pop() interface{} {
	node := (*pq)[len(*pq)-1]
	*pq = (*pq)[0 : len(*pq)-1]
	return node
}

// 优先队列, 时间复杂度O(nklogk), 空间复杂度O(k)
func mergeKLists(lists []*ListNode) *ListNode {
	if lists == nil || len(lists) < 1 {
		return nil
	}

	dummy := &ListNode{Val: -1}
	curNode := dummy

	pq := make(PriorityQueue, 0)
	heap.Init(&pq)

	// 将k个链表的头节点加入小顶堆
	for _, head := range lists {
		if head != nil {
			heap.Push(&pq, head)
		}
	}

	for pq.Len() > 0 {
		node := heap.Pop(&pq).(*ListNode)
		if node.Next != nil {
			heap.Push(&pq, node.Next)
		}

		curNode.Next = node
		curNode = curNode.Next
	}

	return dummy.Next
}
