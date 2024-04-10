package firstround

// 滑动窗口,时间复杂度O(N),空间复杂度O(k)
func lengthOfLongestSubstring(s string) int {
	left, right := 0, 0
	res := 0
	charMap := make(map[rune]int)

	for _, ch := range s {
		charMap[ch]++
		right++

		for charMap[ch] > 1 {
			c := rune(s[left])
			charMap[c]--
			left++
		}

		if res < right-left {
			res = right - left
		}
	}

	return res
}
