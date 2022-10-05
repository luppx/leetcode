package main

// 原地交换
func findRepeatNumber(nums []int) int {
	if len(nums) <= 1 {
		return -1
	}

	for i := 0; i < len(nums); {
		if i == nums[i] {
			i++
			continue
		}
		if nums[nums[i]] == nums[i] {
			return nums[i]
		}

		nums[i], nums[nums[i]] = nums[nums[i]], nums[i]
	}
	return -1
}

func main() {
	nums := []int{1, 2, 3, 5, 2, 1}
	println(findRepeatNumber(nums))
}
