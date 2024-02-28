package firstround

var (
	index []int
	tempIndex []int
	temp []int
	result []int
)

// 归并排序,时间复杂度O(nlogn),空间复杂度O(n)
func countSmaller(nums []int) []int {
	if nums == nil || len(nums) == 0 {
		return result
	}

	len := len(nums)

	tempIndex = make([]int, len)
	temp = make([]int, len)
	result = make([]int, len)

	index = make([]int, len)
	for i := 0; i < len; i++ {
		index[i] = i
	}

	mergeSort(nums, 0, len-1)
	return result
}

func mergeSort(nums []int, left, right int) {
	if left >= right {
		return
	}

	mid := left + (right-left)/2
	mergeSort(nums, left, mid)
	mergeSort(nums, mid+1, right)
	merge(nums, left, mid, right)
}

func merge(nums []int, left, mid, right int) {
	l, r := left, mid+1
	p := left

	for l <= mid && r <= right {
		if nums[l] <= nums[r] {
			temp[p] = nums[l]
			tempIndex[p] = index[l]

			result[index[l]] += r-mid-1

			l++
		} else {
			temp[p] = nums[r]
			tempIndex[p] = index[r]
			r++
		}

		p++
	}

	for l <= mid {
		temp[p] = nums[l]
		tempIndex[p] = index[l]
		result[index[l]] += r-mid-1
		l++
		p++
	}

	for r <= right {
		temp[p] = nums[r]
		tempIndex[p] = index[r]
		r++
		p++
	}

	for i := left; i <= right; i++ {
		nums[i] = temp[i]
		index[i] = tempIndex[i]
	}
}