package main

//func min(a, b int) int {
//	if a > b {
//		return b
//	}
//	return a
//}

// 双指针,时间复杂度O(n),空间复杂度O(1)
//func minArray(numbers []int) int {
//	if len(numbers) == 0 {
//		return -1
//	} else if len(numbers) == 1 {
//		return numbers[0]
//	}
//
//	m := numbers[0]
//	for i, j := 0, len(numbers)-1; i <= j; i, j = i+1, j-1 {
//		if numbers[i] < numbers[j] {
//			m = min(numbers[i], m)
//			break
//		} else if numbers[i] == numbers[j] {
//			m = min(numbers[i], m)
//		} else {
//			m = min(numbers[j], m)
//		}
//	}
//	return m
//}

// 二分,时间复杂度O(log n),空间复杂度O(1)
func minArray(numbers []int) int {
	if len(numbers) == 0 {
		return -1
	} else if len(numbers) == 1 {
		return numbers[0]
	}

	i, j := 0, len(numbers)-1
	for i < j {
		mid := i + (j-i)/2 // 用(i+j)/2可能会溢出，用减法可避免溢出
		if numbers[mid] < numbers[j] {
			j = mid
		} else if numbers[mid] > numbers[j] {
			i = mid + 1
		} else {
			j--
		}
	}
	return numbers[i]
}
