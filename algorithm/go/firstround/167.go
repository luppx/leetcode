package firstround

func twoSum(numbers []int, target int) []int {
	if numbers == nil || len(numbers) < 2 {
		return nil
	}

	left, right := 0, len(numbers)-1
	for left < right {
		sum := numbers[left] + numbers[right]
		if sum == target {
			return []int{left + 1, right + 1}
		} else if sum > target {
			right--
		} else {
			left++
		}
	}
	return nil
}
