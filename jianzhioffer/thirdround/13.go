package main

import "container/list"

// dfs,时间空间复杂度均为O(mn)
//func movingCount(m int, n int, k int) int {
//	if k < 1 {
//		return 1
//	}
//
//	isVisit := make([][]bool, m)
//	for i := 0; i < m; i++ {
//		r := make([]bool, n)
//		isVisit[i] = append(isVisit[i], r...)
//	}
//
//	return dfs(0, 0, k, isVisit)
//}
//
//func dfs(i, j, k int, isVisit [][]bool) int {
//	if i < 0 || i >= len(isVisit) || j < 0 || j >= len(isVisit[0]) {
//		return 0
//	}
//	if isVisit[i][j] || i/10+i%10+j/10+j%10 > k {
//		return 0
//	}
//
//	isVisit[i][j] = true
//	return dfs(i+1, j, k, isVisit) + dfs(i, j+1, k, isVisit) + 1
//}

// bfs,时间空间复杂度均为O(mn)
func movingCount(m, n, k int) int {
	if k < 1 {
		return 1
	}

	isVisit := make([][]bool, m)
	for i := 0; i < m; i++ {
		isVisit[i] = append(isVisit[i], make([]bool, n)...)
	}
	isVisit[0][0] = true
	res := 1

	queue := list.List{}
	queue.PushBack([2]int{0, 0})
	for queue.Len() > 0 {
		p, _ := (queue.Remove(queue.Front())).([2]int)
		i, j := p[0], p[1]

		if j < n-1 && !isVisit[i][j+1] && (i/10+i%10+(j+1)/10+(j+1)%10) <= k {
			isVisit[i][j+1] = true
			queue.PushBack([2]int{i, j + 1})
			res++
		}

		if i < m-1 && !isVisit[i+1][j] && ((i+1)/10+(i+1)%10+j/10+j%10) <= k {
			isVisit[i+1][j] = true
			queue.PushBack([2]int{i + 1, j})
			res++
		}
	}
	return res
}

func main() {
	println(movingCount(38, 15, 9))
}
