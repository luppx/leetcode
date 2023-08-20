package firstround

// 交换元素位置进行回溯, 可以少用一个记忆数组
func permute(nums []int) [][]int {
	if nums == nil {
		return nil
	}

	res := make([][]int, 0)
	perm := make([]int, 0)
	dfs(nums, perm, &res, 0)
	return res
}

func dfs(nums, perm []int, res *[][]int, idx int) {
	if idx >= len(nums) {
		p := make([]int, len(perm))
		for i := 0; i < len(perm); i++ {
			p[i] = perm[i]
		}
		*res = append(*res, p)
		return
	}

	for i := idx; i < len(nums); i++ {
		nums[i], nums[idx] = nums[idx], nums[i]
		perm = append(perm, nums[idx])
		dfs(nums, perm, res, idx+1)
		nums[i], nums[idx] = nums[idx], nums[i]
		perm = perm[0 : len(perm)-1]
	}
	return
}

// 使用记忆数组进行回溯
//func permute(nums []int) [][]int {
//	if nums == nil {
//		return nil
//	}
//
//	res := make([][]int, 0)
//	perm := make([]int, 0)
//	used := make([]bool, len(nums))
//	dfs(nums, perm, used, &res)
//	return res
//}
//
//func dfs(nums, track []int, used []bool, res *[][]int) {
//	if len(track) == len(nums) {
//		p := make([]int, len(track))
//		copy(p, track)
//		*res = append(*res, p)
//		return
//	}
//
//	for _, n := range nums {
//		if used[n] {
//			continue
//		}
//
//		used[n] = true
//		track = append(track, n)
//		dfs(nums, track, used, res)
//		used[n] = false
//		track = track[0 : len(track)-1]
//	}
//}
