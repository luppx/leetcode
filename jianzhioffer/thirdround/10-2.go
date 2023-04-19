package main

// 递归
//func numWays(n int) int {
//	if n < 2 {
//		return 1
//	}
//	return (numWays(n-1) + numWays(n-2)) % 1000000007
//}

// 动态规划,时间复杂度O(n),空间复杂度O(1)
func numWays(n int) int {
	if n < 2 {
		return 1
	}

	i, j := 1, 1
	for k := 2; k <= n; k++ {
		i, j = j, (i+j)%1000000007
	}
	return j
}
