package main

// 递归,超时, 时间复杂度O(2^n),空间复杂度O(log n)
// func fib(n int) int {
// 	if n < 2 {
// 		return n
// 	}
// 	return (fib(n-1) + fib(n-2)) % 1000000007
// }

// 迭代,时间O(n),空间O(n)
// func fib(n int) int {
// 	if n < 2 {
// 		return n
// 	}

// 	v := []int{0,1}
// 	for i := 2; i <= n; i++ {
// 		v = append(v, (v[i-2]+v[i-1])%1000000007)
// 	}
// 	return v[n]
// }

// 动态规划,时间O(n),空间O(1)
func fib(n int) int {
	if n < 2 {
		return n
	}

	i, j, r := 0, 0, 1
	for k := 2; k <= n; k++ {
		i = j
		j = r
		r = (i + j) % 1000000007
	}
	return r
}
