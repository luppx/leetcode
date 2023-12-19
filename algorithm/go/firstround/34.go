package firstround

func searchRange(nums []int, target int) []int {
	left := findLeftBound(nums, target)
	right := findRightBound(nums, target)
	return []int{left, right}
}

// 寻找左侧边界
func findLeftBound(nums []int, target int) int {
	left, right := 0, len(nums)-1

	for left <= right {
		mid := left + (right-left)/2
		if nums[mid] == target {
			right = mid-1
		} else if nums[mid] > target {
			right = mid-1
		} else if nums[mid] < target {
			left = mid+1
		}
	}

	// 判断left是否越界或者nums[left]是否等于target
	if left < 0 || left >= len(nums) || nums[left] != target {
		return -1
	}
	return left
}

// 寻找右侧边界
func findRightBound(nums []int, target int) int {
	left, right := 0, len(nums)-1
	for left <= right {
		mid := left + (right-left)/2
		if nums[mid] == target {
			left = mid+1
		} else if nums[mid] < target {
			left = mid+1
		} else if nums[mid] > target {
			right = mid-1
		}
	}

	// 判断right是否越界或者nums[right]是否等于target
	if right < 0 || right >= len(nums) || nums[right] != target {
		return -1
	}
	return right
}
