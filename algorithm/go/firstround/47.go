package firstround

import "sort"

func permuteUnique(nums []int) [][]int {
	if nums == nil || len(nums) < 1 {
		return nil
	}

	res := make([][]int, 0)
	track := make([]int, 0)

	sort.Ints(nums)
	backtrack(nums, track, &res, 0)
	return res
}

func backtrack(nums, track []int, res *[][]int, start int) {
	if start >= len(nums) {
		tmp := make([]int, len(track))
		copy(tmp, track)
		*res = append(*res, tmp)
		return
	}

	for i := start; i < len(nums); i++ {
		// 剪枝, 避免重复
		if i > start && nums[i] == nums[i-1] {
			continue
		}

		nums[i], nums[start] = nums[start], nums[i]
		track = append(track, nums[start])

		backtrack(nums, track, res, start+1)

		nums[i], nums[start] = nums[start], nums[i]
		track = track[:len(track)-1]
	}
}
