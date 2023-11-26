package firstround

type NumArray struct {
	preSum []int
}

func Constructor(nums []int) NumArray {
	preSum := make([]int, len(nums)+1)
	for i := 1; i <= len(nums); i++ {
		preSum[i] = preSum[i-1] + nums[i-1]
	}
	return NumArray{preSum: preSum}
}

func (this *NumArray) SumRange(left int, right int) int {
	if left < 0 || left > right || right >= len(this.preSum)-1 {
		return -1
	}

	return this.preSum[right+1] - this.preSum[left]
}
