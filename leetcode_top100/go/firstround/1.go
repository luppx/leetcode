package firstround

// 哈希表存储target-n的下标,遍历nums时判断哈希表中是否存在target-n的元素,存在则直接返回
// 时间复杂度O(n),空间复杂度O(n)
func twoSum(nums []int, target int) []int {
	if nums == nil || len(nums) < 2 {
		return nil
	}

	hashTable := make(map[int]int)
	for i, n := range nums {
		if idx, ok := hashTable[target-n]; ok {
			return []int{idx, i}
		}
		hashTable[n] = i
	}

	return nil
}
