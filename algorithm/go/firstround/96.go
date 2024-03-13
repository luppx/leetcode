package firstround

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 回溯
func numTrees(n int) int {
	if n < 1 {
		return 0
	}

	m := make(map[string]int)

	return countTrees(1, n, m)
}

func countTrees(lower, upper int, m map[string]int) int {
	if lower > upper {
		return 1
	}

	cnt := 0
	for i := lower; i <= upper; i++ {
		key := fmt.Sprintf("%d_%d_%d", i, lower, upper)
		if v, ok := m[key]; ok {
			cnt += v
		} else {
			leftSubTreeCnt := countTrees(lower, i-1, m)
			rightSubTreeCnt := countTrees(i+1, upper, m)
			c := leftSubTreeCnt * rightSubTreeCnt
			cnt += c
			m[key] = c
		}
	}
	return cnt
}

// 动态规划,时间复杂度O(n^2),空间复杂度O(n)
func numTrees(n int) int {
	if n < 1 {
		return 0
	}

	// G[i]表示长度为i的序列能构造出的二叉搜索树的个数
	G := make([]int, n+1)
	G[0], G[1] = 1, 1

	for i := 2; i <= n; i++ {
		for j := 1; j <= i; j++ {
			G[i] += G[j-1] * G[i-j]
		}
	}

	return G[n]
}
