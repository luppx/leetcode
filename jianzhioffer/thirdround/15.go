package main

// 位运算, 时间复杂度O(log2^n)即O(logn), 空间复杂度O(1)
func hammingWeight(num uint32) int {
	res := 0
	for num > 0 {
		if num%2 == 1 {
			res++
		}
		num /= 2
	}
	return res
}
