package firstround

func reverseString(s []byte) {
	if s == nil || len(s) < 2 {
		return
	}

	for left, right := 0, len(s)-1; left < right; left, right = left+1, right-1 {
		s[left], s[right] = s[right], s[left]
	}
	return
}
