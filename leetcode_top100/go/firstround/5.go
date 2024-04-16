package firstround

// 时间复杂度O(n^2),空间复杂度O(1)
func longestPalindrome(s string) string {
	resLeft, resRight := 0, 0
	for i := range s {
		// 回文串为奇数的情况
		evenResLeft, evenResRight := subPalindrome(s, i, i)
		if evenResRight-evenResLeft > resRight-resLeft {
			resLeft, resRight = evenResLeft, evenResRight
		}
		// 回文串为偶数的情况
		oddResLeft, oddResRight := subPalindrome(s, i, i+1)
		if oddResRight-oddResLeft > resRight-resLeft {
			resLeft, resRight = oddResLeft, oddResRight
		}
	}

	return s[resLeft : resRight+1]
}

func subPalindrome(s string, l, r int) (int, int) {
	for l >= 0 && r < len(s) {
		if s[l] != s[r] {
			break
		}
		l--
		r++
	}
	return l + 1, r - 1
}
