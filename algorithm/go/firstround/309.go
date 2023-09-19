package firstround

import "math"

// 动态规划, 时间复杂度O(N), 空间复杂度O(1)
func maxProfit(prices []int) int {
	// 动态转移方程
	// dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
	// dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i])

	// dp[i-2][0]
	dp_i_2_0 := 0
	// dp[i-1][0], dp[i-1][1]
	dp_i_1_0, dp_i_1_1 := 0, math.MinInt64
	// dp[i][0], dp[i][1]
	dp_i_0, dp_i_1 := 0, math.MinInt64
	for _, p := range prices {
		dp_i_0 = max(dp_i_1_0, dp_i_1_1+p)
		dp_i_1 = max(dp_i_1_1, dp_i_2_0-p)

		dp_i_2_0 = dp_i_1_0
		dp_i_1_0, dp_i_1_1 = dp_i_0, dp_i_1
	}
	return dp_i_0
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}
