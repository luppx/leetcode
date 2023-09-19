package firstround

import "math"

// 动态规划, 时间复杂度O(N), 空间复杂度O(N)
//func maxProfit(prices []int) int {
//	dp := make([][]int, 0)
//	dp = append(dp, []int{0, math.MinInt64})
//	for i := 0; i < len(prices); i++ {
//		dp = append(dp, []int{0, 0})
//	}
//
//	for i := 1; i <= len(prices); i++ {
//		dp[i][0] = max(dp[i][0], dp[i-1][1]+prices[i-1])
//		dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i-1])
//	}
//	return dp[len(prices)][0]
//}

// 优化空间复杂度
func maxProfit(prices []int) int {
	dp_i_0, dp_i_1 := 0, math.MinInt64
	for _, p := range prices {
		yesterday_0, yesterday_1 := dp_i_0, dp_i_1
		dp_i_0 = max(yesterday_0, yesterday_1+p)
		dp_i_1 = max(yesterday_1, yesterday_0-p)
	}
	return dp_i_0
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}
