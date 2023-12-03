package firstround

func spiralOrder(matrix [][]int) []int {
	if matrix == nil || len(matrix) == 0 || matrix[0] == nil || len(matrix[0]) == 0 {
		return nil
	}
	res := make([]int, 0)
	leftBound, rightBound, upBound, downBound := 0, len(matrix[0])-1, 0, len(matrix)-1
	for leftBound <= rightBound && upBound <= downBound {
		// 向右遍历
		for i := leftBound; i <= rightBound; i++ {
			res = append(res, matrix[upBound][i])
		}

		// 向下遍历
		for i := upBound+1; i <= downBound; i++ {
			res = append(res, matrix[i][rightBound])
		}

		// 向左遍历
		for i := rightBound-1; i >= leftBound; i-- {
			res = append(res, matrix[downBound][i])
		}

		// 向上遍历
		for i := downBound-1; i > upBound; i-- {
			res = append(res, matrix[i][leftBound])
		}

		leftBound++
		rightBound--
		upBound++
		downBound--
	}

	return res
}