package firstround

import (
	"math/rand"
	"sort"
)

type Solution struct {
	right int
	changeMap map[int]int
}


func Constructor(n int, blacklist []int) Solution {
	sort.IntSlice(blacklist).Sort()
	
	changeMap := make(map[int]int)
	right := n-1
	for i := len(blacklist)-1; i >= 0; i-- {
		num := blacklist[i]
		// num在[0,n-1]区间,则将num换到区间的最后
		if num >= 0 && num < n {
			if num < right {
                if _, ok := changeMap[right]; ok {
                    changeMap[num] = changeMap[right]
                } else {
                    changeMap[num] = right
                }
			}
			right--
		}
	}
    // fmt.Printf("right: %d, changeMap: %v\n", right, changeMap)
	return Solution{
		right: right,
		changeMap: changeMap,
	}
}


func (this *Solution) Pick() int {
	val := rand.Intn(this.right+1)
	if _, ok := this.changeMap[val]; ok {
		return this.changeMap[val]
	}
	return val
}


/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(n, blacklist);
 * param_1 := obj.Pick();
 */