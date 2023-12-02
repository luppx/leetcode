package firstround

// 先反转整个字符串，再分别反转每个单词
func reverseWords(s string) string { 
	// 寻找前导空格
	i := 0
	for i < len(s) && s[i] == ' '{
		i++
	}
	if i >= len(s) {
		return ""
	}

	// 寻找后导空格
	j := len(s)-1
	for j > i && s[j] == ' ' {
		j--
	}

	sBytes := []byte(s[i:j+1])
	slow, fast := 0, 0
	// 去除单词间的多余空格
	for ; fast < len(sBytes); fast++ {
		// 碰到多余空格
		if fast-1 > 0 && sBytes[fast] == ' ' && sBytes[fast] == sBytes[fast-1] {
			continue
		}

		sBytes[slow] = sBytes[fast]
		slow++
	}

	// 反转整个字符串
	subBytes := sBytes[:slow]
	reverse(subBytes, 0, len(subBytes)-1)

	// 分别反转每个单词
	for i := 0; i < slow; {
		if subBytes[i] == ' ' {
			i++
			continue
		}

		// 寻找单词
		j := i
		for j < slow && subBytes[j] != ' ' {
			j++
		}
		// 反转单词
		reverse(subBytes, i, j-1)
		
		i = j
	}
	return string(subBytes)
}

func reverse(sBytes []byte, i, j int) {
	if i < 0 || j >= len(sBytes) || i >= j {
		return
	}
	for left ,right := i, j; left < right; left, right = left+1, right-1 {
		sBytes[left], sBytes[right] = sBytes[right], sBytes[left]
	}
	return
}