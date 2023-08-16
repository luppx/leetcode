package firstround

// 暴力解法, 遍历
//func isPalindrome(s string) bool {
//	if len(s) < 2 {
//		return true
//	}
//
//	for left, right := 0, len(s)-1; left < right; left, right = left+1, right-1 {
//		if s[left] != s[right] {
//			return false
//		}
//	}
//	return true
//}
//
//func longestPalindrome(s string) string {
//	if len(s) < 2 {
//		return s
//	}
//
//	maxLen, maxPalindrome := 1, s[0:0]
//	println(maxPalindrome)
//	for j := 1; j < len(s); j++ {
//		for i := 0; i < j; i++ {
//			if isPalindrome(s[i:j]) && (j-i+1) > maxLen {
//				maxPalindrome = s[i:j]
//			}
//		}
//	}
//	return maxPalindrome
//}

// 从中心向两边查找回文子串, 时间复杂度O(n^2), 空间复杂度O(1)
func find(s string, left, right int) string {
	for left >= 0 && right < len(s) && s[left] == s[right] {
		left--
		right++
	}
	return s[left+1 : right]
}

func longestPalindrome(s string) string {
	if len(s) < 2 {
		return s
	}

	res := ""
	for i := 0; i < len(s); i++ {
		// 寻找以s[i]为中心的奇数回文子串
		s1 := find(s, i, i)
		if len(s1) > len(res) {
			res = s1
		}

		// 寻找以s[i],s[i+1]为中心的偶数回文子串
		s2 := find(s, i, i+1)
		if len(s2) > len(res) {
			res = s2
		}
	}
	return res
}
