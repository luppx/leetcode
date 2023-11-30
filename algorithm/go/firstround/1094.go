package firstround

type DifferenceNum struct{
	diff []int
	capacity int
}

func NewDifferenceNum(capacity int) DifferenceNum {
	diff := make([]int, 0)
	return DifferenceNum{diff: diff, capacity: capacity}
}

func (d *DifferenceNum) Increment(i, j, val int) {
	if j >= len(d.diff) {
		d.diff = append(d.diff, make([]int, j-len(d.diff)+1)...)
	}

	d.diff[i] += val
	// 到第j公里乘客就下车了，所以要减去下车的乘客数
	d.diff[j] -= val
}

func (d *DifferenceNum) IsOverLoad() bool {
	if d.diff == nil || len(d.diff) == 0 {
		return true
	}
	
	num := d.diff[0]
	if num > d.capacity {
		return true
	}
	for i := 1; i < len(d.diff); i++ {
		num += d.diff[i]
		if num > d.capacity {
			return true
		}
	}
	return false
}

func carPooling(trips [][]int, capacity int) bool {
	df := NewDifferenceNum(capacity)
	for _, trip := range trips {
		val, i, j := trip[0], trip[1], trip[2]
		df.Increment(i, j, val)
		if df.IsOverLoad() {
			return false
		}
	}
	return true
}