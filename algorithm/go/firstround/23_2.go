package firstround

type ListNode struct {
	Val  int
	Next *ListNode
}

// 优先队列,时间复杂度O(n*logk),空间复杂度O(k)
func mergeKLists(lists []*ListNode) *ListNode {
	if lists == nil || len(lists) < 1 {
		return nil
	}

	// 建小顶堆
	nums := make([]*ListNode, 0)
	for _, head := range lists {
		if head == nil {
			continue
		}
		nums = append(nums, head)
	}

	dummy := &ListNode{}
	cur := dummy
	for len(nums) > 0 {
		getMinElement(nums)
		node := nums[len(nums)-1]
		if node.Next != nil {
			nums[len(nums)-1] = node.Next
		} else {
			nums = nums[:len(nums)-1]
		}

		node.Next = nil
		cur.Next = node
		cur = cur.Next
	}

	return dummy.Next
}

// 建小顶堆
func buildHeap(nums []*ListNode) {
	for i := len(nums)/2 - 1; i >= 0; i-- {
		adjust(nums, i)
	}
}

func adjust(nums []*ListNode, i int) {
	for {
		left, right := i*2+1, (i+1)*2
		minIdx := i
		if left < len(nums) && nums[minIdx].Val > nums[left].Val {
			minIdx = left
		}
		if right < len(nums) && nums[minIdx].Val > nums[right].Val {
			minIdx = right
		}

		if minIdx == i {
			return
		}

		nums[i], nums[minIdx] = nums[minIdx], nums[i]
		i = minIdx
	}
}

func heapSort(nums []*ListNode) {
	buildHeap(nums)
	for i := len(nums) - 1; i > 0; i-- {
		nums[0], nums[i] = nums[i], nums[0]
		adjust(nums[:i], 0)
	}
}

func getMinElement(nums []*ListNode) {
	buildHeap(nums)
	nums[0], nums[len(nums)-1] = nums[len(nums)-1], nums[0]
	adjust(nums[:len(nums)-1], 0)
}
