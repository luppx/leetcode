package firstround

import "math"

func maxProfit(k int, prices []int) int {
	dp := make([][][2]int, 0)
	// dp[0][j][0] = 0, dp[0][j][1] = -infinity
	// dp[i][0][0] = 0, dp[i][0][1] = -infinity
	for i := 0; i <= len(prices); i++ {
		tmp := make([][2]int, k+1)
		for j := 0; j <= k; j++ {
			tmp[j][1] = math.MinInt64
		}
		dp = append(dp, tmp)
	}

	for i := 1; i <= len(prices); i++ {
		p := prices[i-1]
		for j := 1; j <= k; j++ {
			dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+p)
			dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-p)
		}
	}
	return dp[len(prices)][k][0]
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}
