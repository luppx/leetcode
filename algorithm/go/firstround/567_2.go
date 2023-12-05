package firstround

// 滑动窗口，时间复杂度O(N)，空间复杂度O(N)(使用了两个map存储字符出现次数)
func checkInclusion(s1 string, s2 string) bool {
	if s1 == "" {
		return true
	}

	needs := make(map[byte]int)
	for i := range s1 {
		needs[s1[i]]++
	}

	window := make(map[byte]int)
	valid := 0
	left, right := 0, 0
	for right < len(s2) {
		if v, ok := needs[s2[right]]; ok {
			window[s2[right]]++
			if window[s2[right]] == v {
				valid++
			}
		}
		right++

		// fmt.Printf("[%d, %d), window: %+v\n", left, right, window)
		for valid == len(needs) {
			if right-left == len(s1) {
				return true
			}

			if v, ok := needs[s2[left]]; ok {
				if window[s2[left]] == v {
					valid--
				}
				window[s2[left]]--
			}

			left++
		}
	}
	return false
}