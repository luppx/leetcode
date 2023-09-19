package firstround

import "math"

func maxProfit(prices []int) int {
	// 动态转移方程, k(1<=k<=K)表示截止目前已交易次数(买入的时候交易次数加一)
	// dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
	// dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])

	// 初始化
	// dp[i][0][0] = 0, dp[i][0][1] = math.MinInt64, dp[-1][k][0] = 0, dp[-1][k][1] = math.MinInt64
	dp := make([][3][2]int, len(prices)+1)
	dp[0][1][1], dp[0][2][1] = math.MinInt64, math.MinInt64
	for i := 0; i <= len(prices); i++ {
		dp[i][0][1] = math.MinInt64
	}

	for i := 1; i <= len(prices); i++ {
		p := prices[i-1]
		for k := 1; k <= 2; k++ {
			dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1]+p)
			dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0]-p)
		}
	}

	return dp[len(prices)][2][0]
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}
