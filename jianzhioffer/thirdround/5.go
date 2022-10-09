package main

//func replaceSpace(s string) string {
//	if len(s) == 0 {
//		return s
//	}
//
//	var res string
//	for i := 0; i < len(s); i++ {
//		if s[i] == ' ' {
//			res += "%20"
//		} else {
//			res += string(s[i])
//		}
//	}
//	return res
//}

//func replaceSpace(s string) string {
//	if len(s) == 0 {
//		return s
//	}
//
//	b := []byte(s)
//	res := make([]byte, 0)
//	for i := 0; i < len(b); i++ {
//		if b[i] == ' ' {
//			res = append(res, []byte("%20")...)
//		} else {
//			res = append(res, b[i])
//		}
//	}
//
//	return string(res)
//}

//原地替换
func replaceSpace(s string) string {
	if len(s) == 0 {
		return s
	}

	b := []byte(s)

	countSpace := 0
	for _, v := range b {
		if v == ' ' {
			countSpace++
		}
	}

	if countSpace == 0 {
		return s
	}

	tmp := make([]byte, countSpace*2)
	b = append(b, tmp...)

	i, j := len(s)-1, len(b)-1
	for countSpace > 0 && i >= 0 && j >= i {
		if b[i] == ' ' {
			b[j] = '0'
			b[j-1] = '2'
			b[j-2] = '%'
			i--
			j -= 3
			countSpace--
		} else {
			b[j] = b[i]
			i--
			j--
		}
	}
	return string(b)
}

func main() {
	var s string = "We Are Happy."
	println(replaceSpace(s))
}
