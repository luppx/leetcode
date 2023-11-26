package firstround

type NumMatrix struct {
	preSum [][]int
}

// 分别记录矩阵每一行的前缀和，SumRegion为每行目标矩阵元素和相加，SumRegion时间复杂度O(N)
// func Constructor(matrix [][]int) NumMatrix {
// 	if matrix == nil || len(matrix) == 0 || len(matrix[0]) == 0 {
// 		return NumMatrix{}
// 	}

// 	preSum := make([][]int, len(matrix))
// 	for i := 0; i < len(matrix); i++ {
// 		rowPreSum := make([]int, len(matrix[0])+1)
// 		for j := 1; j <= len(matrix[0]); j++ {
// 			rowPreSum[j] = rowPreSum[j-1] + matrix[i][j-1]
// 		}
// 		preSum[i] = rowPreSum
// 	}
// 	return NumMatrix{preSum: preSum}
// }

// func (this *NumMatrix) SumRegion(row1 int, col1 int, row2 int, col2 int) int {
// 	if this.preSum == nil || row1 < 0 || row1 > row2 || row2 > len(this.preSum) ||
// 	col1 < 0 || col1 > col2 || col2 >= len(this.preSum[0]) - 1 {
// 		return -1
// 	}

// 	res := 0
// 	for i := row1; i <= row2; i++ {
// 		rowSum := this.preSum[i][col2+1] - this.preSum[i][col1]
// 		res += rowSum
// 	}
// 	return res
// }

// 优化：前缀和数组记录从原点到(x,y)所形成的范围内元素和，
// 计算SumRegion时可将原点到(x2,y2)的大矩阵拆成4个小范围，随后通过加减即可计算出目标矩阵的元素和
// 这样可将SumRegion的时间复杂度优化至O(1)
func Constructor(matrix [][]int) NumMatrix {
	if matrix == nil || len(matrix) == 0 || len(matrix[0]) == 0 {
		return NumMatrix{}
	}

	preSum := make([][]int, len(matrix)+1)
	for n := 0; n <= len(matrix); n++ {
		preSum[n] = make([]int, len(matrix[0])+1)
	}

	for i := 1; i < len(preSum); i++ {
		for j := 1; j < len(preSum[0]); j++ {
			preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] + matrix[i-1][j-1] - preSum[i-1][j-1]
		}
	}

	return NumMatrix{preSum: preSum}
}

func (this *NumMatrix) SumRegion(row1 int, col1 int, row2 int, col2 int) int {
	if this.preSum == nil || row1 < 0 || row1 > row2 || row2 > len(this.preSum) ||
		col1 < 0 || col1 > col2 || col2 >= len(this.preSum[0])-1 {
		return -1
	}

	return this.preSum[row2+1][col2+1] - this.preSum[row1][col2+1] - this.preSum[row2+1][col1] + this.preSum[row1][col1]
}
