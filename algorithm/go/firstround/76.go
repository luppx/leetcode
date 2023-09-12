package firstround

import "math"

// 滑动窗口, 左闭右开区间, 时间复杂度O(N), 空间复杂度O(N)
func minWindow(s, t string) string {
	if len(s) < 1 || len(t) < 1 || len(s) < len(t) {
		return ""
	}

	window := make(map[byte]int)
	needs := make(map[byte]int)
	for i := range t {
		needs[t[i]]++
	}

	start, resLen := 0, math.MaxInt32
	valid := 0 // 用于判断窗口中是否已包含t
	left, right := 0, 0
	for right < len(s) {
		// 先往右滑动窗口, 直到窗口中包含t为止
		c := s[right]
		right++
		if tNum, ok := needs[c]; ok {
			window[c]++
			// 如果窗口中该字符的个数已等于t中该字符的个数, 则valid值加1, 当valid==len(needs)时, 表明窗口中已包含t
			if window[c] == tNum {
				valid++
			}
		}

		// 缩小窗口, 直到窗口中不包含t
		for valid == len(needs) {
			if right-left < resLen {
				start = left
				resLen = right - left
			}

			c := s[left]
			left++
			if tNum, ok := needs[c]; ok {
				// 如果窗口中该字符的个数减1后不再等于t中该字符的个数, 则窗口不再包含t, valid值要减1
				if window[c] == tNum {
					valid--
				}
				window[c]--
			}
		}
	}

	if resLen == math.MaxInt32 {
		return ""
	}
	return s[start:(start + resLen)]
}
