package firstround

// 双指针
//func removeElement(nums []int, val int) int {
//	if len(nums) < 1 {
//		return 0
//	}
//
//	left, right := 0, len(nums)-1
//	for left <= right {
//		// 从左往右找到第一个等于val的数
//		for ; left < right && nums[left] != val; left++ {
//		}
//
//		// 从右往左找到第一个不等于val的数
//		for ; right > left && nums[right] == val; right-- {
//		}
//
//		if left == right {
//			// 双指针相遇的元素值如果等于val, 则该元素应删除, 数组长度减1
//			if nums[left] == val {
//				left--
//			}
//			break
//		}
//
//		// 交换双指针对应的元素值
//		nums[left], nums[right] = nums[right], nums[left]
//	}
//	return left + 1
//}

// 快慢指针
func removeElement(nums []int, val int) int {
	slow, fast := 0, 0
	for fast < len(nums) {
		if nums[fast] != val {
			nums[slow] = nums[fast]
			slow++
		}
		fast++
	}
	return slow
}

func testRemoveElement() {

}
