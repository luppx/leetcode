package main

import "fmt"

// 大顶堆排序
// 将最大的节点调整至子树根节点
func heapSort(num []int) {
	// 建堆
	for i := len(num) / 2; i >= 0; i-- {
		heapify(num, i, len(num))
	}

	// 排序
	for i := len(num) - 1; i > 0; i-- {
		num[0], num[i] = num[i], num[0]
		heapify(num, 0, i)
	}
}

// heapify 堆化
func heapify(num []int, i, n int) {
	left, right := 2*i+1, 2*i+2
	largest := i

	if left < n && num[left] > num[largest] {
		largest = left
	}

	if right < n && num[right] > num[largest] {
		largest = right
	}

	if largest != i {
		num[i], num[largest] = num[largest], num[i]
		heapify(num, largest, n)
	}
}

func main() {
	num := []int{7, 3, 8, 5, 1, 2}
	heapSort(num)
	fmt.Println(num)
}
