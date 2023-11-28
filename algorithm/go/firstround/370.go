package firstround

type DifferenceNum struct {
	diff []int
}

// 差分数组，对数组进行加减操作(func Increment)的时间复杂度O(1)，空间复杂度O(N)
func NewDifferenceNum(num []int) DifferenceNum {
	diff := make([]int, len(num))
	diff[0] = num[0]
	for i := 1; i < len(num); i++ {
		diff[i] = num[i] - num[i-1]
	}
	return DifferenceNum{diff: diff}
}

func (d *DifferenceNum) Increment(startIndex, endIndex, inc int) {
	if startIndex > endIndex || startIndex < 0 || endIndex >= len(d.diff) {
		return
	}

	d.diff[startIndex] += inc
	if endIndex+1 < len(d.diff) {
		d.diff[endIndex+1] -= inc
	}
	return
}

func (d *DifferenceNum) Result() []int {
	res := make([]int, len(d.diff))
	res[0] = d.diff[0]

	for i := 1; i < len(d.diff); i++ {
		res[i] = res[i-1] + d.diff[i]
	}
	return res
}

func getModifiedArray(length int, updates [][]int) []int {
	num := make([]int, length)
	differenceNum := NewDifferenceNum(num)

	for i := 0; i < len(updates); i++ {
		if len(updates[i]) != 3 {
			return nil
		}
		differenceNum.Increment(updates[i][0], updates[i][1], updates[i][2])
	}
	return differenceNum.Result()
}
