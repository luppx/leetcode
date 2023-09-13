package firstround

// 滑动窗口, 左闭右开区间, 时间复杂度O(N), 空间复杂度O(N)
func checkInclusion(s1, s2 string) bool {
	if s1 == "" {
		return true
	} else if s2 == "" {
		return false
	}

	window := make(map[byte]int)
	need := make(map[byte]int)
	for i := range s1 {
		need[s1[i]]++
	}

	valid := 0
	left, right := 0, 0
	for right < len(s2) {
		c := s2[right]
		right++
		if v, ok := need[c]; ok {
			window[c]++
			if window[c] == v {
				valid++
			}
		}

		for valid == len(need) {
			if right-left == len(s1) {
				return true
			}

			c := s2[left]
			left++
			if v, ok := need[c]; ok {
				if window[c] == v {
					valid--
				}
				window[c]--
			}
		}
	}
	return false
}
