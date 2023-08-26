package firstround

import "sort"

func subsetsWithDup(nums []int) [][]int {
	if nums == nil || len(nums) < 1 {
		return nil
	}

	res := make([][]int, 0)
	res = append(res, make([]int, 0))
	track := make([]int, 0)

	sort.Slice(nums, func(i, j int) bool {
		return nums[i] <= nums[j]
	})
	backtrack(nums, track, &res, 0)
	return res
}

func backtrack(nums, track []int, res *[][]int, start int) {
	if start >= len(nums) {
		return
	}

	for i := start; i < len(nums); i++ {
		// 剪枝
		if i > start && nums[i] == nums[i-1] {
			continue
		}

		track = append(track, nums[i])
		tmp := make([]int, len(track))
		copy(tmp, track)
		*res = append(*res, tmp)

		backtrack(nums, track, res, i+1)
		track = track[:len(track)-1]
	}
}
