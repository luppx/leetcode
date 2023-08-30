package firstround

import "sort"

func combinationSum(candidates []int, target int) [][]int {
	if candidates == nil || len(candidates) < 1 {
		return nil
	}

	res := make([][]int, 0)
	track := make([]int, 0)
	sort.Ints(candidates)
	backtrack(candidates, track, &res, target, 0, 0)
	return res
}

func backtrack(candidates, track []int, res *[][]int, target, sum, idx int) {
	if sum == target {
		tmp := make([]int, len(track))
		copy(tmp, track)
		*res = append(*res, tmp)
		return
	} else if idx >= len(candidates) || sum > target {
		return
	}

	count := 0
	for sum <= target {
		backtrack(candidates, track, res, target, sum, idx+1)

		track = append(track, candidates[idx])
		sum += candidates[idx]
		count++
	}
	track = track[:len(track)-count]
}
