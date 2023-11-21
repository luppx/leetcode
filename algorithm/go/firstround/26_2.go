package firstround

// 时间复杂度O(N), 空间复杂度O(1)
func removeDuplicates(nums []int) int {
	if nums == nil || len(nums) == 0 {
		return 0
	} else if len(nums) == 1 {
		return 1
	}

	left, right := 0, 0
	for right < len(nums) {
		if nums[left] != nums[right] {
			left++
			nums[left] = nums[right]
		}
		right++
	}

	return left + 1
}
