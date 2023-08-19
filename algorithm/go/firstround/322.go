package firstround

// dp, 自顶向下, 假设硬币种类即len(coins)=k, amount=n, 则时间复杂度为O(kn), 空间复杂度为O(n)
//func coinChange(coins []int, amount int) int {
//	if amount < 1 {
//		return 0
//	}
//
//	mem := make([]int, amount+1)
//	for i := 0; i < len(mem); i++ {
//		mem[i] = -2
//	}
//
//	return dp(coins, mem, amount)
//}
//
//func dp(coins, mem []int, amount int) int {
//	if amount == 0 {
//		return 0
//	} else if amount < 0 {
//		return -1
//	} else if mem[amount] != -2 {
//		return mem[amount]
//	}
//
//	res := math.MaxInt32
//	for _, coin := range coins {
//		subProblem := dp(coins, mem, amount-coin)
//		// 子问题无法找零
//		if subProblem == -1 {
//			continue
//		}
//
//		if subProblem+1 < res {
//			res = subProblem + 1
//		}
//	}
//
//	if res == math.MaxInt32 {
//		mem[amount] = -1
//		return -1
//	}
//
//	mem[amount] = res
//	return res
//}

// dp, 自底向上, 时间复杂度O(kn), 空间复杂度O(n)
func coinChange(coins []int, amount int) int {
	if amount < 1 {
		return 0
	} else if coins == nil || len(coins) < 1 {
		return -1
	}

	dp := make([]int, amount+1)
	for i := 1; i < len(dp); i++ {
		dp[i] = amount + 1
	}

	for i := 0; i < len(dp); i++ {
		for _, coin := range coins {
			if i-coin < 0 {
				continue
			}

			dp[i] = min(dp[i-coin]+1, dp[i])
		}
	}

	if dp[amount] == amount+1 {
		return -1
	}
	return dp[amount]
}

func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}
