package firstround

//func solveNQueens(n int) [][]string {
//	if n < 1 {
//		return nil
//	}
//
//	res := make([][]string, 0)
//	invaded := make([][]int, n)
//	for i := 0; i < n; i++ {
//		inv := make([]int, n)
//		invaded[i] = inv
//	}
//
//	track := make([][]byte, n)
//	for i := 0; i < n; i++ {
//		s := make([]byte, n)
//		for j := 0; j < n; j++ {
//			s[j] = '.'
//		}
//		track[i] = s
//	}
//
//	backtrack(&res, invaded, track, 0)
//
//	return res
//}
//
//func backtrack(res *[][]string, invaded [][]int, track [][]byte, cnt int) {
//	// 所有皇后均已放置到棋盘上
//	if cnt == len(track) {
//		ans := make([]string, len(track))
//		for i, t := range track {
//			ans[i] = string(t)
//		}
//
//		*res = append(*res, ans)
//		//fmt.Printf("res[%d] = %v", len(*res)-1, ans)
//		//fmt.Printf("res = %v", *res)
//		return
//	}
//
//	i := cnt
//	for j, c := range track[cnt] {
//		// 该棋盘位置已有皇后
//		if c == 'Q' {
//			continue
//		}
//
//		// 检查该位置能否放置皇后
//		if invaded[i][j] > 0 {
//			continue
//		}
//
//		// 将皇后放在棋盘, 并占领相应的棋盘位置
//		track[i][j] = 'Q'
//		invade(i, j, invaded)
//
//		backtrack(res, invaded, track, cnt+1)
//
//		// 将皇后移除, 并还原占领的棋盘位置
//		track[i][j] = '.'
//		withdraw(i, j, invaded)
//
//	}
//}
//
//func invade(x, y int, invaded [][]int) {
//	invaded[x][y] += 1
//
//	// 同一行
//	for j := 0; j < len(invaded[0]); j++ {
//		if j == y {
//			continue
//		}
//		invaded[x][j] += 1
//	}
//
//	// 同一列
//	for i := 0; i < len(invaded); i++ {
//		if i == x {
//			continue
//		}
//		invaded[i][y] += 1
//	}
//
//	// 斜线
//	// 左上方
//	for i, j := x-1, y-1; i >= 0 && j >= 0; i, j = i-1, j-1 {
//		invaded[i][j] += 1
//	}
//
//	// 左下方
//	for i, j := x+1, y-1; i < len(invaded) && j >= 0; i, j = i+1, j-1 {
//		invaded[i][j] += 1
//	}
//
//	// 右上方
//	for i, j := x-1, y+1; i >= 0 && j < len(invaded[0]); i, j = i-1, j+1 {
//		invaded[i][j] += 1
//	}
//
//	// 右下方
//	for i, j := x+1, y+1; i < len(invaded) && j < len(invaded[0]); i, j = i+1, j+1 {
//		invaded[i][j] += 1
//	}
//
//	return
//}
//
//func withdraw(x, y int, invaded [][]int) {
//	invaded[x][y] -= 1
//
//	// 同一行
//	for j := 0; j < len(invaded[0]); j++ {
//		if j == y {
//			continue
//		}
//		invaded[x][j] -= 1
//	}
//
//	// 同一列
//	for i := 0; i < len(invaded); i++ {
//		if i == x {
//			continue
//		}
//		invaded[i][y] -= 1
//	}
//
//	// 斜线
//	// 左上方
//	for i, j := x-1, y-1; i >= 0 && j >= 0; i, j = i-1, j-1 {
//		invaded[i][j] -= 1
//	}
//
//	// 左下方
//	for i, j := x+1, y-1; i < len(invaded) && j >= 0; i, j = i+1, j-1 {
//		invaded[i][j] -= 1
//	}
//
//	// 右上方
//	for i, j := x-1, y+1; i >= 0 && j < len(invaded[0]); i, j = i-1, j+1 {
//		invaded[i][j] -= 1
//	}
//
//	// 右下方
//	for i, j := x+1, y+1; i < len(invaded) && j < len(invaded[0]); i, j = i+1, j+1 {
//		invaded[i][j] -= 1
//	}
//
//	return
//}

func solveNQueens(n int) [][]string {
	if n < 1 {
		return nil
	}

	res := make([][]string, 0)

	track := make([][]byte, n)
	for i := 0; i < n; i++ {
		s := make([]byte, n)
		for j := 0; j < n; j++ {
			s[j] = '.'
		}
		track[i] = s
	}

	backtrack(&res, track, 0)

	return res
}

func backtrack(res *[][]string, track [][]byte, cnt int) {
	// 所有皇后均已放置到棋盘上
	if cnt == len(track) {
		ans := make([]string, len(track))
		for i, t := range track {
			ans[i] = string(t)
		}

		*res = append(*res, ans)
		return
	}

	for j, c := range track[cnt] {
		// 该棋盘位置已有皇后
		if c == 'Q' {
			continue
		}

		// 检查该位置能否放置皇后
		if !check(cnt, j, track) {
			continue
		}

		// 将皇后放在棋盘, 并占领相应的棋盘位置
		track[cnt][j] = 'Q'

		backtrack(res, track, cnt+1)

		// 将皇后移除, 并还原占领的棋盘位置
		track[cnt][j] = '.'
	}
}

func check(x, y int, track [][]byte) bool {
	// 同一列
	for i := 0; i < len(track); i++ {
		if track[i][y] == 'Q' {
			return false
		}
	}

	// 斜线
	// 左上方
	for i, j := x-1, y-1; i >= 0 && j >= 0; i, j = i-1, j-1 {
		if track[i][j] == 'Q' {
			return false
		}
	}

	// 右上方
	for i, j := x-1, y+1; i >= 0 && j < len(track[0]); i, j = i-1, j+1 {
		if track[i][j] == 'Q' {
			return false
		}
	}

	return true
}
