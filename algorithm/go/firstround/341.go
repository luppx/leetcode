package firstround

/**
* // This is the interface that allows for creating nested lists.
* // You should not implement it, or speculate about its implementation
* type NestedInteger struct {
* }
*
* // Return true if this NestedInteger holds a single integer, rather than a nested list.
* func (this NestedInteger) IsInteger() bool {}
*
* // Return the single integer that this NestedInteger holds, if it holds a single integer
* // The result is undefined if this NestedInteger holds a nested list
* // So before calling this method, you should have a check
* func (this NestedInteger) GetInteger() int {}
*
* // Set this NestedInteger to hold a single integer.
* func (n *NestedInteger) SetInteger(value int) {}
*
* // Set this NestedInteger to hold a nested list and adds a nested integer to it.
* func (this *NestedInteger) Add(elem NestedInteger) {}
*
* // Return the nested list that this NestedInteger holds, if it holds a nested list
* // The list length is zero if this NestedInteger holds a single integer
* // You can access NestedInteger's List element directly if you want to modify it
* func (this NestedInteger) GetList() []*NestedInteger {}
 */

type NestedIterator struct {
	idx  int
	nums []int
}

// dfs,时间复杂度O(n),空间复杂度O(n)
func Constructor(nestedList []*NestedInteger) *NestedIterator {
	nums := make([]int, 0)

	var traverse func([]*NestedInteger)
	traverse = func(nestedList []*NestedInteger) {
		for _, nestedInteger := range nestedList {
			if nestedInteger.IsInteger() {
				nums = append(nums, nestedInteger.GetInteger())
			} else {
				traverse(nestedInteger.GetList())
			}
		}
	}

	traverse(nestedList)

	return &NestedIterator{
		idx:  0,
		nums: nums,
	}
}
func (this *NestedIterator) Next() int {
	n := this.nums[this.idx]
	this.idx++
	return n
}

func (this *NestedIterator) HasNext() bool {
	return this.idx < len(this.nums)
}
