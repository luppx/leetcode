package firstround

// 从中心向两边扩散，需要找两次，即子串长为奇数(中点只有一个元素)、子串为偶数(中点为两个元素的组合)这两种情况
// 时间复杂度O(N^2)，空间复杂度O(1)
func longestPalindrome(s string) string {
	if len(s) < 2 {
		return s
	}
	maxLength, maxLeft, maxRight := 0, 0, 0
	for i := 0; i < len(s); i++ {
		// 子串长为奇数的情况
		l1, left1, right1 := findSubLongestPalindrome(s, i, i)
		// 子串长为偶数的情况
		l2, left2, right2 := findSubLongestPalindrome(s, i, i+1)

		if l1 > maxLength {
			maxLength, maxLeft, maxRight = l1, left1, right1
		}

		if l2 > maxLength {
			maxLength, maxLeft, maxRight = l2, left2, right2
		}
	}

	return s[maxLeft:(maxRight + 1)]
}

func findSubLongestPalindrome(s string, left, right int) (int, int, int) {
	for left >= 0 && right < len(s) && s[left] == s[right] {
		left--
		right++
	}

	return right - left - 1, left + 1, right - 1
}
