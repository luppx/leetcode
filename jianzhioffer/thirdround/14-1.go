package main

import "fmt"

// 方法一: dsp, 超时
//func cuttingRope(n int) int {
//	if n <= 0 {
//		return -1
//	} else if n == 1 {
//		return 1
//	}
//
//	return dsp(n, 1, 0)
//}
//
//func dsp(remainingN, curProduct, m int) int {
//	if remainingN <= 1 {
//		return curProduct
//	}
//
//	maxProduct := curProduct
//	maxLen := remainingN
//	if m > 0 {
//		maxLen = remainingN + 1
//	}
//	for i := 1; i < maxLen; i++ {
//		product := dsp(remainingN-i, curProduct*i, m+1)
//		if product > maxProduct {
//			maxProduct = product
//		}
//	}
//	return maxProduct
//}

// 方法二: 动态规划, 时间复杂度O(n^2), 空间复杂度O(n)
func cuttingRope(n int) int {
	if n <= 0 {
		return -1
	} else if n == 1 {
		return 1
	}

	// dp[i]表示i对应的最大乘积
	dp := make([]int, n+1)
	for i := 2; i <= n; i++ {
		maxProduct := 0
		for j := 1; j <= i/2; j++ {
			p1 := (i - j) * j
			p2 := j * dp[i-j]

			p := p1
			if p2 > p1 {
				p = p2
			}
			if p > maxProduct {
				maxProduct = p
			}
		}
		dp[i] = maxProduct
	}
	return dp[n]
}

func main() {
	res := cuttingRope(4)
	fmt.Println(res)
}
