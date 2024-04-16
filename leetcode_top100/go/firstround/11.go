package firstround

// 双指针,左边矮则左指针向右移动,右边矮则右指针向左移动
// 时间复杂度O(n),空间复杂度O(1)
func maxArea(height []int) int {
	if height == nil || len(height) < 2 {
		return 0
	}

	res := 0
	left, right := 0, len(height)-1
	for left < right {
		// area = min(height[left],height[right])*(right-left)
		area := (right - left) * height[left]
		if height[left] > height[right] {
			area = (right - left) * height[right]
		}

		if area > res {
			res = area
		}
		// 左边矮则左指针向右移动,右边矮则右指针向左移动
		if height[left] <= height[right] {
			left++
		} else {
			right--
		}
	}
	return res
}
