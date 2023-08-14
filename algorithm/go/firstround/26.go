package firstround

func removeDuplicates(nums []int) int {
	if nums == nil || len(nums) < 1 {
		return 0
	}

	slow, fast := 0, 0
	for fast < len(nums) {
		if nums[slow] != nums[fast] {
			slow++
			nums[slow] = nums[fast]
		}
		fast++
	}
	return slow + 1
}
