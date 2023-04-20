package main

func exist(board [][]byte, word string) bool {
	if len(word) < 1 {
		return false
	}

	for i := 0; i < len(board); i++ {
		for j := 0; j < len(board[0]); j++ {
			if dfs(board, word, i, j) {
				return true
			}
		}
	}
	return false
}

// DFS+剪枝,时间复杂度O(3^K MN),空间复杂度O(MN)
// 复杂度解析见:https://leetcode.cn/problems/ju-zhen-zhong-de-lu-jing-lcof/solutions/103929/mian-shi-ti-12-ju-zhen-zhong-de-lu-jing-shen-du-yo/
func dfs(board [][]byte, word string, i, j int) bool {
	if i < 0 || i >= len(board) || j < 0 || j >= len(board[0]) || board[i][j] != word[0] {
		return false
	}
	if len(word) < 1 || (len(word) == 1 && board[i][j] == word[0]) {
		return true
	}

	v := board[i][j]
	board[i][j] = '/'
	// 往左，找到直接返回，不用继续查找其他方向
	if dfs(board, word[1:], i, j-1) || dfs(board, word[1:], i, j+1) || dfs(board, word[1:], i-1, j) ||
		dfs(board, word[1:], i+1, j) {
		return true
	}

	board[i][j] = v
	return false
}
