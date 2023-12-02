package firstround

// 顺时针旋转90度
func rotate(matrix [][]int)  {
	if matrix == nil {
		return
	}
	// 沿主对角线对称交换矩阵元素
	for i := 0; i < len(matrix); i++ {
		for j := i; j< len(matrix[i]); j++ {
			matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
		}
	}

	// 再反转交换后矩阵每一行的元素，即实现顺时针旋转90度
	for _, row := range matrix {
		left, right := 0, len(row)-1
		for left < right {
			row[left], row[right] = row[right], row[left]
			left++
			right--
		}
	}
}

// 逆时针旋转90度
func rotate(matrix [][]int) {
	if matrix == nil {
		return
	}

	// 沿副对角线对称交换矩阵元素
	n := len(matrix)-1
	for i := 0; i <= n; i++ {
		for j := 0; j <= n-i; j++ {
			matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
		}
	}

	// 将交换后的矩阵按行分别reverse，即得到逆时针旋转90度的矩阵
	for _, row := range matrix{
		left, right := 0, n
		for left < right {
			row[left], row[right] = row[right], row[left]
		}
	}
}