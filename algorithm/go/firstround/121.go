package firstround

import "math"

// 动态规划, 时间复杂度O(N), 空间复杂度O(1)
func maxProfit(prices []int) int {
	// dp_i_0表示第i天没有持有股票情况下的利润, dp_i_1表示第i天持有股票情况下的利润
	dp_i_0, dp_i_1 := 0, math.MinInt64
	for i := 0; i < len(prices); i++ {
		dp_i_0 = max(dp_i_0, dp_i_1+prices[i])
		dp_i_1 = max(dp_i_1, -prices[i])
	}
	return dp_i_0
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}
