package firstround

// 滑动窗口, 时间复杂度O(N), 空间复杂度O(N)
func lengthOfLongestSubstring(s string) int {
	if s == "" {
		return 0
	}

	window := make(map[byte]int)
	res := 0
	left, right := 0, 0
	for right < len(s) {
		c := s[right]
		right++
		window[c]++

		for window[c] > 1 {
			d := s[left]
			left++
			window[d]--
		}

		if right-left > res {
			res = right - left
		}
	}

	return res
}
