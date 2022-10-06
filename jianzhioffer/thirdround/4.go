package main

func findNumberIn2DArray(matrix [][]int, target int) bool {
	if matrix == nil || len(matrix) == 0 {
		return false
	}

	//从左下角开始遍历
	for i, j := len(matrix)-1, 0; i >= 0 && j < len(matrix[i]); {
		if matrix[i][j] == target {
			return true
		} else if matrix[i][j] > target {
			i--
		} else {
			j++
		}
	}

	return false
}

func main() {
	m := [][]int{
		{1, 4, 7, 11, 15},
		{2, 5, 8, 12, 19},
		{3, 6, 9, 16, 22},
		{10, 13, 14, 17, 24},
		{18, 21, 23, 26, 30},
	}
	println(findNumberIn2DArray(m, 20))
}
