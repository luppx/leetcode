package main

// 双指针+原地交换, 时间复杂度O(n), 空间复杂度O(1)
func exchange(nums []int) []int {
	if len(nums) < 2 {
		return nums
	}

	i, j := 0, len(nums)-1
	for i < j {
		// 从左往右找到第一个不为奇数的nums[i]
		for ; nums[i]%2 != 0 && i < j; i++ {
		}

		// 从右往左找到第一个不为偶数的nums[j]
		for ; nums[j]%2 == 0 && j > i; j-- {
		}

		// 交换
		nums[i], nums[j] = nums[j], nums[i]
	}
	return nums
}
