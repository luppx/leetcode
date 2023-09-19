package firstround

import "math"

// 动态规划, 时间复杂度O(N), 空间复杂度O(1)
func maxProfit(prices []int, fee int) int {
	// 动态转移方程(卖出的时候再算手续费)
	// dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - fee)
	// dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])

	dp_i_0, dp_i_1 := 0, math.MinInt64
	for _, p := range prices {
		yesterday_0 := dp_i_0
		dp_i_0 = max(dp_i_0, dp_i_1+p-fee)
		dp_i_1 = max(dp_i_1, yesterday_0-p)
	}
	return dp_i_0
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}
