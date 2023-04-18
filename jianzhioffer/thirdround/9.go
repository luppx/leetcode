package main

import "fmt"

type CQueue struct {
	s1 []int // append
	s2 []int // delete
}

func Constructor() CQueue {
	return CQueue{
		s1: make([]int, 0),
		s2: make([]int, 0),
	}
}

func (this *CQueue) AppendTail(value int) {
	this.s1 = append(this.s1, value)
}

func (this *CQueue) DeleteHead() int {
	if len(this.s1) == 0 && len(this.s2) == 0 {
		fmt.Printf("case1\ns1: %+v\ns2:%+v\n", this.s1, this.s2)
		return -1
	} else if len(this.s2) > 0 {
		val := this.s2[len(this.s2)-1]
		this.s2 = this.s2[0 : len(this.s2)-1]
		fmt.Printf("case2\ns1: %+v\ns2:%+v\n", this.s1, this.s2)
		return val
	}

	for i := len(this.s1) - 1; i > 0; i-- {
		this.s2 = append(this.s2, this.s1[i])
		this.s1 = this.s1[0:i]
	}
	fmt.Printf("case3\ns1: %+v\ns2:%+v\n", this.s1, this.s2)
	val := this.s1[0]
	this.s1 = this.s1[0:0]
	return val
}

/**
 * Your CQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AppendTail(value);
 * param_2 := obj.DeleteHead();
 */
