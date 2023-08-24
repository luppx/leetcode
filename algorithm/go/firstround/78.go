package firstround

// 时间复杂度O(n * 2^n), 空间复杂度O(n)
// 复杂度分析见方法二: https://leetcode.cn/problems/subsets/solutions/420294/zi-ji-by-leetcode-solution/
func subsets(nums []int) [][]int {
	res := make([][]int, 0)
	res = append(res, make([]int, 0))

	if nums == nil || len(nums) < 1 {
		return res
	}

	subset := make([]int, 0)
	backtrack(nums, subset, &res, 0)
	return res
}

func backtrack(nums, subset []int, res *[][]int, idx int) {
	if idx >= len(nums) {
		return
	}

	for i := idx; i < len(nums); i++ {
		subset = append(subset, nums[i])

		newSet := make([]int, len(subset))
		copy(newSet, subset)
		*res = append(*res, newSet)

		backtrack(nums, subset, res, i+1)

		subset = subset[:len(subset)-1]
	}
}
