package firstround

func generateMatrix(n int) [][]int {
	if n < 1 {
		return nil
	}

	// 构造正方形矩阵
	res := make([][]int, n)
	for i := 0; i < n; i++ {
		res[i] = make([]int, n)
	}

	num := 1
	leftBound, rightBound, upBound, downBound := 0, n-1, 0, n-1
	for leftBound <= rightBound && upBound <= downBound {
		// 向右遍历
		for j := leftBound; j <= rightBound; j++ {
			res[upBound][j] = num
			num++
		}

		// 如果围成的子矩阵只有一行，则向右遍历完即可break
		if upBound == downBound {
			break
		}

		// 向下遍历
		for i := upBound+1; i <= downBound; i++ {
			res[i][rightBound] = num
			num++
		}

		// 如果围成的子矩阵只有一列，则向右+向下遍历完即可break
		if leftBound == rightBound {
			break
		}

		// 向左遍历
		for j := rightBound-1; j >= leftBound; j-- {
			res[downBound][j] = num
			num++
		}

		// 向上遍历
		for i := downBound-1; i > upBound; i-- {
			res[i][leftBound] = num
			num++
		}

		leftBound++
		rightBound--
		upBound++
		downBound--
	}

	return res
}