package firstround

import "sort"

func combinationSum2(candidates []int, target int) [][]int {
	if candidates == nil || len(candidates) < 1 {
		return nil
	}

	res := make([][]int, 0)
	track := make([]int, 0)

	sort.Ints(candidates)
	backtrack(candidates, track, &res, target, 0, 0)
	return res
}

func backtrack(candidates, track []int, res *[][]int, target, sum, start int) {
	if sum == target {
		tmp := make([]int, len(track))
		copy(tmp, track)
		*res = append(*res, tmp)
		return
	}

	for i := start; i < len(candidates); i++ {
		// 剪枝, 避免重复答案
		if i > start && candidates[i] == candidates[i-1] {
			continue
		}

		sum += candidates[i]
		// 剪枝, 提前返回
		if sum > target {
			return
		}
		track = append(track, candidates[i])

		backtrack(candidates, track, res, target, sum, i+1)

		sum -= candidates[i]
		track = track[:len(track)-1]
	}
}
