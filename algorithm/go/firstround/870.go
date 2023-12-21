package firstround

import (
	"fmt"
	"sort"
)

func advantageCount(nums1 []int, nums2 []int) []int {
	if nums1 == nil || nums2 == nil {
		return nil
	}

	n2 := make([]int, len(nums2))
	copy(n2, nums2)

	sort.IntSlice(nums1).Sort()
	sort.IntSlice(n2).Sort()
	fmt.Printf("n1: %v, n2: %v\n", nums1, n2)

	numMap := make(map[int][]int)
	left, right := 0, len(nums1)-1
	for i := len(nums1)-1; i >= 0; i-- {
		if _, ok := numMap[n2[i]]; !ok {
			numMap[n2[i]] = make([]int, 0)
		}
		
		if nums1[right] > n2[i] {
			numMap[n2[i]] = append(numMap[n2[i]], nums1[right])
			right--
		} else {
			numMap[n2[i]] = append(numMap[n2[i]], nums1[left])
			left++
		}
		fmt.Printf("i=%d, numMap: %v\n", i, numMap)
	}
	fmt.Println(numMap)

	res := make([]int, 0)
	for _, n := range nums2 {
		res = append(res, numMap[n][0])
		if len(numMap[n]) > 1 {
			length := len(numMap[n])
			d := numMap[n][1:length]
			numMap[n] = d
		}
	}

	return res
}