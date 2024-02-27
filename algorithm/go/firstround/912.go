package firstround

import (
	"math/rand"

	"github.com/eapache/go-resiliency/breaker"
)

// 快速排序,时间复杂度O(nlogn),空间复杂度O(logn),最坏情况O(n)
func sortArray(nums []int) []int {
	if nums == nil || len(nums) < 1 {
		return nums
	}
	quickSort(nums, 0, len(nums)-1)
	return nums
}

func quickSort(nums []int, left, right int) {
	if left >= right {
		return
	}

	pivot := partition(nums, left, right)
	quickSort(nums, left, pivot-1)
	quickSort(nums, pivot+1, right)
}

func partition(nums []int, left, right int) int {
	i := rand.Intn(right-left+1) + left
	nums[left], nums[i] = nums[i], nums[left]
	pivot := left

	for left < right {
		for left < right && nums[right] >= nums[pivot] {
			right--
		}

		for left < right && nums[left] <= nums[pivot] {
			left++
		}

		nums[left], nums[right] = nums[right], nums[left]
	}
	nums[right], nums[pivot] = nums[pivot], nums[right]

	return right
}

// 堆排序,时间复杂度O(nlogn),空间复杂度O(1)
func sortArray(nums []int) []int {
	if nums == nil || len(nums) < 1 {
		return nums
	}

	heapSort(nums)
	return nums
}

func heapSort(nums []int) {
	buildHeap(nums)
	for i := len(nums) - 1; i > 0; i-- {
		nums[0], nums[i] = nums[i], nums[0]
		maxHeapify(nums, 0, i)
	}
}

func buildHeap(nums []int) {
	for i := len(nums)/2 - 1; i >= 0; i-- {
		maxHeapify(nums, i, len(nums))
	}
}

func maxHeapify(nums []int, i, len int) {
	for i <= len/2-1 {
		left, right := (i+1)*2-1, (i+1)*2

		if left >= len {
			break
		}

		maxChild := left
		if right < len && nums[right] > nums[maxChild] {
			maxChild = right
		}

		if nums[i] < nums[maxChild] {
			nums[i], nums[maxChild] = nums[maxChild], nums[i]
			i = maxChild
		} else {
			break
		}
	}
}

// 归并排序,时间复杂度O(nlogn),空间复杂度O(n)
func sortArray(nums []int) []int {
	mergeSort(nums, 0, len(nums)-1)
	return nums
}

func mergeSort(nums []int, left, right int) {
	if left >= right {
		return
	}

	mid := left + (right-left+1)/2
	mergeSort(nums, left, mid-1)
	mergeSort(nums, mid, right)
	merge(nums, left, right, mid)
}

func merge(nums []int, left, right, mid int) {
	len1, len2 := mid-left, right-mid+1
	s1 := make([]int, len1)
	s2 := make([]int, len2)
	copy(s1, nums[left:mid])
	copy(s2, nums[mid:right+1])

	i := left
	cur1, cur2 := 0, 0
	for cur1 < len1 && cur2 < len2 {
		if s1[cur1] <= s2[cur2] {
			nums[i] = s1[cur1]
			cur1++
		} else {
			nums[i] = s2[cur2]
			cur2++
		}
		i++
	}

	for cur1 < len1 {
		nums[i] = s1[cur1]
		cur1++
		i++
	}
	
	for cur2 < len2 {
		nums[i] = s2[cur2]
		cur2++
		i++
	}
}