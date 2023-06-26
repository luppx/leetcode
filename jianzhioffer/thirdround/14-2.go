package main

// 贪心, 时间复杂度O(n), 空间复杂度O(1)
//func cuttingRope(n int) int {
//	if n < 2 {
//		return -1
//	}
//	if n == 2 {
//		return 1
//	}
//	if n == 3 {
//		return 2
//	}
//	if n == 4 {
//		return 4
//	}
//
//	const MOD = 1000000007
//	res := 1
//	for ; n > 4; n -= 3 {
//		res = (res * 3) % MOD
//	}
//	return (res * n) % MOD
//}

// 贪心加循环求余, 时间复杂度O(log3^n)即log(n), 空间复杂度O(1)
func cuttingRope(n int) int {
	if n < 2 {
		return -1
	} else if n < 4 {
		return n - 1
	}

	const MOD = 1000000007
	// n = 3^a + b
	a, b := n/3, n%3
	// 留一个3, 用于最后分类讨论, 即先求3^(a-1) + b
	a -= 1

	remainder := 1

	// 循环求余: x^a % p = ((x^(a-1) % p) * (x % p)) % p
	// 由于这里x为3, 所以x % p 可以简化为x, 变为:
	// x^a % p = ((x^(a-1) % p) * x) % p
	for i := 0; i < a; i++ {
		remainder = (remainder * 3) % MOD
	}

	// b=n%3,取值只能为0,1,2
	// 这里讨论对b以及此前故意留下的一个3的处理
	if b == 0 { // 余数为0, 即3能被n整除, 则直接乘以最后一个3
		return (remainder * 3) % MOD
	} else if b == 1 { // 余数为1, 则剩下1+3=4, 把4分为2+2是最大的
		return (remainder * 4) % MOD
	} else { // 余数为2, 则剩下2+3=5, 分为2和3就已经是最大的了
		return (remainder * 6) % MOD
	}
}
