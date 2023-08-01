package main

import (
	"fmt"
	"strconv"
	"strings"
)

// 时间复杂度O(10^n), 空间复杂度O(1)
//func printNumbers(n int) []int {
//	if n < 1 {
//		return make([]int, 0)
//	}
//
//	num := int(math.Pow10(n) - 1)
//	res := make([]int, num)
//	for i := 1; i <= num; i++ {
//		res[i-1] = i
//	}
//	return res
//}

// 大数全排列, 时间复杂度O(10^n), 空间复杂度O(10^n)
func printNumbers(n int) []int {
	if n < 1 {
		return make([]int, 0)
	}

	res := make([]int, 0)
	num := make([]string, n)
	start, nine := n-1, 0

	dfs(res, num, n, &start, &nine, 0)

	return res
}

// start 表示去除掉高位为0后数字的位数, nine 表示9的个数
func dfs(res *[]int, num []string, n int, start, nine *int, x int) {
	fmt.Printf("len(res): %d, len(num): %d", len(*res), len(num))
	if x == n {
		s := strings.Join(num[*start:], "")
		if s != "0" {
			number, _ := strconv.Atoi(s)
			*res = append(*res, number)
		}

		if n-(*start) == *nine {
			*start -= 1
		}
		return
	}

	for i := 0; i < 10; i++ {
		if i == 9 {
			*nine += 1
		}
		num[x] = strconv.Itoa(i)
		dfs(res, num, n, start, nine, x+1)
	}
	*nine -= 1

	return
}
