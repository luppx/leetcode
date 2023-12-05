package firstround

// 滑动窗口，时间复杂度O(N)，空间复杂度O(N)(使用了两个map存储字符出现次数)
func findAnagrams(s string, p string) []int {
	needs := make(map[byte]int)
	for i := range p {
		needs[p[i]]++
	}

	window := make(map[byte]int)
	left, right := 0, 0
	valid := 0
	res := make([]int, 0)
	for right < len(s) {
		if v, ok := needs[s[right]]; ok {
			window[s[right]]++
			if window[s[right]] == v {
				valid++
			}
		}
		right++

		for valid == len(needs) {
			if right - left == len(p) {
				res = append(res, left)
			}

			if v, ok := needs[s[left]]; ok {
				if window[s[left]] == v {
					valid--
				}
				window[s[left]]--
			}
			left++
		}
	}
	return res	
}