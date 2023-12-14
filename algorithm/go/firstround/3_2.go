package firstround

// 滑动窗口, 时间复杂度O(N), 空间复杂度O(N)
func lengthOfLongestSubstring(s string) int {
	res := 0
	left, right := 0, 0
	window := make(map[byte]int)
	for right < len(s) {
		ch := s[right]
		window[ch]++
		right++

		for window[ch] > 1 {
			window[s[left]]--
			left++
		}

		if res < right - left {
			res = right - left
		}
	}
	return res
}