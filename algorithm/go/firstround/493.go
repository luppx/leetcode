package firstround

// 归并排序,时间复杂度O(nlogn),空间复杂度O(n)
func reversePairs(nums []int) int {
	if nums == nil || len(nums) == 0 {
		return 0
	}

	tmpNums = make([]int, len(nums))

	res := mergeSort(nums, 0, len(nums)-1)
	return res
}

var tmpNums []int

func mergeSort(nums []int, left, right int) int {
	if left >= right {
		return 0
	}

	mid := left + (right-left)/2
	cntLeft := mergeSort(nums, left, mid)
	cntRight := mergeSort(nums, mid+1, right)
	cnt := merge(nums, left, mid, right)

	return cnt + cntLeft + cntRight
}

func merge(nums []int, left, mid, right int) int {
	r := mid + 1
	cnt := 0
	for _, v := range nums[left:mid+1] {
		for r <= right && v > 2*nums[r] {
			r++
		}
		cnt += r-(mid+1)
	}

	curL, curR := left, mid+1
	p := left
	for curL <= mid && curR <= right {
		if nums[curL] <= nums[curR] {
			tmpNums[p] = nums[curL]
			curL++
		} else {
			tmpNums[p] = nums[curR]
			curR++
		}

		p++
	}

	for curL <= mid {
		tmpNums[p] = nums[curL]
		curL++
		p++
	}

	for curR <= right {
		tmpNums[p] = nums[curR]
		curR++
		p++
	}

	for i := left; i <= right; i++ {
		nums[i] = tmpNums[i]
	}

	return cnt
}
