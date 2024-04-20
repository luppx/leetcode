package firstround

import "sort"

// 双指针,时间复杂度O(n^2),空间复杂度O(logn)(对数组排序的空间复杂度)
func threeSum(nums []int) [][]int {
	if len(nums) < 3 {
		return nil
	}

	res := make([][]int, 0)
	sort.Ints(nums)
	// fmt.Println(nums)
	for i := 0; i < len(nums)-2; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		target := 0 - nums[i]
		left, right := i+1, len(nums)-1
		for left < right {
			if left > i+1 && nums[left] == nums[left-1] {
				left++
				continue
			}
			if right < len(nums)-1 && nums[right] == nums[right+1] {
				right--
				continue
			}
			// fmt.Printf("left: %d, right: %d, nums[i]+nums[l]+nums[r]= %d + %d + %d = %d\n", left, right, nums[i], nums[left], nums[right], nums[i]+nums[left]+nums[right])
			if nums[left]+nums[right] == target {
				res = append(res, []int{nums[i], nums[left], nums[right]})
				left++
			} else if nums[left]+nums[right] > target {
				right--
			} else {
				left++
			}
		}
	}

	return res
}
