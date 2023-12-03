package firstround

import "strings"

// 滑动窗口，时间复杂度O(N)，空间复杂度O(N)
func minWindow(s string, t string) string {
	left, right := 0, 0
	resLeft, resRight := -1, len(s)+1
	// 记录t中各字符的出现次数
	subMap := make(map[byte]int)
	for i, _ := range t {
		subMap[t[i]]++
	}

	// 滑动窗口，记录窗口中包含的t中各字符的出现次数
	windowMap := make(map[byte]int)

	for right < len(s) {
		ch := s[right]
		if _, ok := subMap[ch]; ok {
			windowMap[ch]++
		}
		right++

		// 滑动窗口可以收缩的情况：
		// 1.窗口左边界字符不是t中的字符
		// 2.左边界字符是t中的字符，但在窗口内的出现次数已经大于t中该字符的出现次数
		for left < right && (!strings.ContainsRune(t, rune(s[left])) || windowMap[s[left]] > subMap[s[left]]) {
			// 从窗口中移除元素
			if _, ok := windowMap[s[left]]; ok {
				windowMap[s[left]]--
			}
			// 缩小窗口
			left++
		}

		// 判断窗口是否已包含t中的所有字符
		cnt := 0
		for k, v := range subMap {
			if windowMap[k] < v {
				break
			}
			cnt++
		}

		// 如果包括t中所有字符，判断该窗口是否为包含t的最小窗口
		if cnt == len(subMap) && right - left < resRight - resLeft {
			resLeft, resRight = left, right
		}
	}
	
	// s中没有包含t的子串
	if resLeft == -1 {
		return ""
	}
	return s[resLeft:resRight]
}

// 滑动窗口，另一种缩小窗口的思路
func minWindow(s string, t string) string {
	// 记录t中各字符的出现次数
	need := make(map[byte]int)
	for i, _ := range t {
		need[t[i]]++
	}
	// 滑动窗口，记录窗口中包含的t中各字符的出现次数
	window := make(map[byte]int)

	left, right := 0, 0
	resLeft, resRight := -1, len(s)+1
	// 记录t中字符出现次数等于滑动窗口中该字符出现次数的字符数量，即当valid=len(need)时，说明t中的字符在滑动窗口中都已包含
	valid := 0

	for right < len(s) {
		ch := s[right]
		if _, ok := need[ch]; ok {
			window[ch]++
			if window[ch] == need[ch] {
				valid++
			}
		}
		right++

		// 当滑动窗口包含t中所有字符时，判断是否收缩窗口
		for valid == len(need) && left < right {
			// 判断该窗口是否为包含t的最小窗口
			if right - left < resRight - resLeft {
				resLeft, resRight = left, right
			}

			// 缩小窗口，从窗口中移除元素
			if _, ok := need[s[left]]; ok {
				window[s[left]]--
				if window[s[left]] < need[s[left]] {
					valid--
				}
			}
			
			left++
		}
	}
	
	// s中没有包含t的子串
	if resLeft == -1 {
		return ""
	}
	return s[resLeft:resRight]
}