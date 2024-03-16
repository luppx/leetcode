package firstround

import (
	"math/rand"
)

// 利用快速每次都能将一个元素排到他最终位置的特点:
// 如果排完后的元素partition正好是倒数第k,即partition=len(nums)-k,则已找到,无需继续排序
// 如果partition<len(nums)-k,则只需继续排序右子区间,不用再排序左子区间
// 如果partition>len(nums)-k,则继续排序左子区间
// 这样就只用排序一个子区间,不用两个子区间都排序
// 时间复杂度官方题解说这个思路是O(n),不是快排的O(nlogn): https://leetcode.cn/problems/kth-largest-element-in-an-array/solutions/307351/shu-zu-zhong-de-di-kge-zui-da-yuan-su-by-leetcode-/
// 空间复杂度O(logn)
func findKthLargest(nums []int, k int) int {
	if nums == nil || len(nums) < 1 || k < 1 || k > len(nums) {
		return -1
	}

	quickSort(nums, len(nums)-k, 0, len(nums)-1)
	return nums[len(nums)-k]
}

func quickSort(nums []int, targetIdx, left, right int) {
	if left >= right || found {
		return
	}

	partition := findPartition(nums, left, right)
	if partition == targetIdx {
		return
	} else if partition > targetIdx {
		quickSort(nums, targetIdx, left, partition-1)
	} else {
		quickSort(nums, targetIdx, partition+1, right)
	}
}

func findPartition(nums []int, left, right int) int {
	i := left + rand.Intn(right-left+1)
	pivot := left
	nums[left], nums[i] = nums[i], nums[left]

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
