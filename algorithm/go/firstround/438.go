package firstround

// 滑动窗口, 时间复杂度O(N), 空间复杂度O(N)
func findAnagrams(s string, p string) []int {
	if s == "" || p == "" {
		return nil
	}

	window := make(map[byte]int)
	need := make(map[byte]int)
	for i := range p {
		need[p[i]]++
	}

	res := make([]int, 0)
	left, right, validate := 0, 0, 0
	for right < len(s) {
		c := s[right]
		right++
		if v, ok := need[c]; ok {
			window[c]++
			if window[c] == v {
				validate++
			}
		}

		for validate == len(need) {
			if right-left == len(p) {
				res = append(res, left)
			}

			c := s[left]
			left++
			if v, ok := need[c]; ok {
				if window[c] == v {
					validate--
				}
				window[c]--
			}
		}
	}

	return res
}
