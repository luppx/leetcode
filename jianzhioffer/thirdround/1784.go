package main

func checkOnesSegment(s string) bool {
	if len(s) <= 1 {
		return true
	}

	var index int = 1
	for ; index < len(s); index++ {
		if s[index] != '1' {
			break
		}

	}

	for i := index; i < len(s); i++ {
		if s[i] == '1' {
			return false
		}
	}

	return true
}
