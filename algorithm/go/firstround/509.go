package firstround

func fib(n int) int {
	if n < 1 {
		return 0
	}

	res1, res2 := 0, 1
	for i := 2; i <= n; i++ {
		sum := res1 + res2
		res1 = res2
		res2 = sum
	}
	return res2
}
