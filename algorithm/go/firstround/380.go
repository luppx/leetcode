package firstround

import "math/rand"

type RandomizedSet struct {
	valToIndex map[int]int
	nums []int
}


func Constructor() RandomizedSet {
	return RandomizedSet{
		valToIndex: make(map[int]int),
		nums: make([]int, 0),
	}
}


func (this *RandomizedSet) Insert(val int) bool {
	// val已经存在
	if _, ok := this.valToIndex[val]; ok {
		return true
	}

	this.valToIndex[val] = len(this.nums)
	this.nums = append(this.nums, val)
	return false
}


func (this *RandomizedSet) Remove(val int) bool {
	// val不存在
	if _, ok := this.valToIndex[val]; !ok {
		return false
	}

	valIdx := this.valToIndex[val]
	lastVal := this.nums[len(this.nums)-1]

	// 将要删除的元素交换到数组最后
	this.nums[valIdx], this.nums[len(this.nums)-1] = this.nums[len(this.nums)-1], this.nums[valIdx]
	// 从数组中删除元素
	this.nums = this.nums[:len(this.nums)-1]
	// 更新原本数组最后一个元素在数组的index
	this.valToIndex[lastVal] = valIdx
	// 从map中删除val
	delete(this.valToIndex, val)

	return true
}


func (this *RandomizedSet) GetRandom() int {
	// 题目确保RandomizedSet中必须至少有一个元素，所以无需考虑没有元素的情况
	return this.nums[rand.Intn(len(this.nums))]
}