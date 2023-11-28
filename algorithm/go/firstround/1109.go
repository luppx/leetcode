package firstround

// 差分数组，对数组进行加减操作(func Increment)的时间复杂度O(1)，空间复杂度O(N)
type DifferenceNum struct {
	diff []int
}

func NewDifferenceNum(nums []int) DifferenceNum {
	if nums == nil || len(nums) == 0 {
		return DifferenceNum{}
	}

	diff := make([]int, len(nums))
	diff[0] = nums[0]
	for i := 1; i < len(nums); i++ {
		diff[i] = nums[i] - nums[i-1]
	}

	return DifferenceNum{diff: diff}
}

func (d *DifferenceNum) Increment(i, j, val int) {
	if d.diff == nil || i < 0 || i > j || j >= len(d.diff) {
		return
	}

	d.diff[i] += val
	if j+1 < len(d.diff) {
		d.diff[j+1] -= val
	}

	return
}

func (d *DifferenceNum) Result() []int {
	if d.diff == nil {
		return nil
	}

	res := make([]int, len(d.diff))
	res[0] = d.diff[0]
	for i := 1; i < len(d.diff); i++ {
		res[i] = res[i-1] + d.diff[i]
	}

	return res
}

func corpFlightBookings(bookings [][]int, n int) []int {
	nums := make([]int, n)
	df := NewDifferenceNum(nums)

	for _, booking := range bookings {
		if len(booking) != 2 {
			return nil
		}
		// 航班编号是从1开始，差分数组下标是从0开始，所以first、least需要减1
		first, last, seat := booking[0]-1, booking[1]-1, booking[2]
		df.Increment(first, last, seat)
	}
	return df.Result()
}
