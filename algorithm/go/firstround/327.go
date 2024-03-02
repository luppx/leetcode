package firstround

// 归并排序,时间复杂度O(nlogn),空间复杂度O(n)
func countRangeSum(nums []int, lower int, upper int) int {
	if lower > upper {
		return 0
	}

	prefixSum := make([]int, len(nums)+1)
	for i, n := range nums {
		prefixSum[i+1] = prefixSum[i] + n
	}

	return mergeAndCount(prefixSum, lower, upper)
}

func mergeAndCount(preSum []int, lower, upper int) int {
	len := len(preSum)
	if len <= 1 {
		return 0
	}

	cntLeft := mergeAndCount(preSum[:len/2], lower, upper)
	cntRight := mergeAndCount(preSum[len/2:], lower, upper)

	cntLeftAndRight := merge(preSum, lower, upper)

	return cntLeft + cntRight + cntLeftAndRight
}

func merge(preSum []int, lower, upper int) int {
	cnt := 0
	mid := len(preSum) / 2
	l, r := mid, mid
	for _, v := range preSum[:mid] {
		for l < len(preSum) && preSum[l]-v < lower {
			l++
		}

		for r < len(preSum) && preSum[r]-v <= upper {
			r++
		}

		cnt += r - l
	}

	tmp := make([]int, len(preSum))
	copy(tmp, preSum)

	cur1, cur2, p := 0, mid, 0
	for cur1 < mid && cur2 < len(tmp) {
		if tmp[cur1] <= tmp[cur2] {
			preSum[p] = tmp[cur1]
			cur1++
		} else {
			preSum[p] = tmp[cur2]
			cur2++
		}
		p++
	}

	for cur1 < mid {
		preSum[p] = tmp[cur1]
		cur1++
		p++
	}

	for cur2 < len(tmp) {
		preSum[p] = tmp[cur2]
		cur2++
		p++
	}

	return cnt
}
