package firstround

func totalNQueens(n int) int {
	if n < 1 {
		return 0
	}

	totalRes := 0
	board := make([][]byte, 0)
	for i := 0; i < n; i++ {
		b := make([]byte, n)
		for j := 0; j < n; j++ {
			b[j] = '.'
		}
		board = append(board, b)
	}

	backtrack(board, &totalRes, 0)

	return totalRes
}

func backtrack(board [][]byte, res *int, row int) {
	if row == len(board) {
		*res += 1
		return
	}

	for j, _ := range board[row] {
		if !isValid(board, row, j) {
			continue
		}

		board[row][j] = 'Q'
		backtrack(board, res, row+1)
		board[row][j] = '.'
	}
}

func isValid(board [][]byte, x, y int) bool {
	// 检查同一列的上方是否存在女皇
	for i := 0; i < x; i++ {
		if board[i][y] == 'Q' {
			return false
		}
	}

	// 左上方
	for i, j := x-1, y-1; i >= 0 && j >= 0; i, j = i-1, j-1 {
		if board[i][j] == 'Q' {
			return false
		}
	}

	// 右上方
	for i, j := x-1, y+1; i >= 0 && j < len(board[0]); i, j = i-1, j+1 {
		if board[i][j] == 'Q' {
			return false
		}
	}

	return true
}
