package firstround

// 二分查找,时间复杂度O(logn),空间复杂度O(1)
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	totalLength := len(nums1) + len(nums2)
	if totalLength%2 == 1 {
		return float64(getKthElement(nums1, nums2, totalLength/2+1))
	} else {
		return float64(getKthElement(nums1, nums2, totalLength/2)+getKthElement(nums1, nums2, totalLength/2+1)) / 2
	}
}

// k表示两个数据合并后新数组的中位数,即新数组中第k小的数(k从1开始)
func getKthElement(nums1, nums2 []int, k int) int {
	index1, index2 := 0, 0
	for {
		// 如果有一个数组已经为空,则直接返回另一个数组的第index+k个数
		if index1 == len(nums1) {
			return nums2[index2+k-1]
		}
		if index2 == len(nums2) {
			return nums1[index1+k-1]
		}
		// 如果k=1,则返回min(nums1[index1],nums2[index2])
		if k == 1 {
			return min(nums1[index1], nums2[index2])
		}

		mid := k / 2
		// 分别找到两个数组的第k/2个数的下标,跟len(nums)比较取最小值是为了防止数组越界
		newIndex1 := min(index1+mid, len(nums1)) - 1
		newIndex2 := min(index2+mid, len(nums2)) - 1

		pivot1, pivot2 := nums1[newIndex1], nums2[newIndex2]
		if pivot1 <= pivot2 {
			k -= newIndex1 - index1 + 1
			index1 = newIndex1 + 1
		} else {
			k -= newIndex2 - index2 + 1
			index2 = newIndex2 + 1
		}
	}
}

func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}
