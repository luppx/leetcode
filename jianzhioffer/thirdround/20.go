package main

import (
	"strings"
)

// 正则表达式
//func isNumber(s string) bool {
//	matched, err := regexp.MatchString(`^\s*([+-]?((\d+)|((\d*\.\d+)|(\d+\.\d*)))([eE][+-]\d+)?)\s*$`, s)
//	if err != nil {
//		fmt.Printf("err: %v", err)
//	}
//
//	if matched {
//		return true
//	}
//	return false
//}

// 遍历
func isNumber(s string) bool {
	// 去除空格
	s = strings.TrimRight(strings.TrimLeft(s, " "), " ")
	if len(s) < 1 {
		return false
	}

	// 将字符串按底数、指数部分拆分, 分别判断
	var strSlice []string
	if strings.Contains(s, "e") {
		strSlice = strings.Split(s, "e")
		// 有多个e
		if len(strSlice) != 2 {
			return false
		}
	} else if strings.Contains(s, "E") {
		strSlice = strings.Split(s, "E")
		// 有多个E
		if len(strSlice) != 2 {
			return false
		}
	} else { // 不是指数,即不包含e或E
		return judgeNum(s)
	}

	num, pow := strSlice[0], strSlice[1]
	if len(num) < 1 || len(pow) < 1 { // 如果包含e或E,则必须有底数和指数部分
		return false
	}
	return judgeNum(num) && judgeInt(pow)
}

// 判断是否为小数或整数
func judgeNum(s string) bool {
	hasSign := hasSignPrefix(s)
	if hasSign {
		if len(s) < 2 {
			return false
		}
		s = s[1:]
	}

	s1, s2 := "", ""
	if strings.Contains(s, ".") {
		strSlice := strings.Split(s, ".")
		// 只能有一个小数点
		if len(strSlice) != 2 {
			return false
		}
		s1, s2 = strSlice[0], strSlice[1]
	} else {
		s1 = s
	}

	if len(s1) < 1 && len(s2) < 1 { // 只有一个字符且为.
		return false
	} else if len(s1) < 1 {
		return judgeIsInt(s2)
	} else if len(s2) < 1 {
		return judgeIsInt(s1)
	}
	return judgeIsInt(s1) && judgeIsInt(s2)
}

func judgeInt(s string) bool {
	hasSign := hasSignPrefix(s)
	if hasSign {
		if len(s) < 2 {
			return false
		}
		s = s[1:]
	}

	return judgeIsInt(s)
}

func hasSignPrefix(s string) bool {
	return s[0] == '+' || s[0] == '-'
}

func judgeIsInt(s string) bool {
	if len(s) < 1 {
		return false
	}

	for _, c := range s {
		// 不为数字
		if c < '0' || c > '9' {
			return false
		}
	}
	return true
}

func main() {
	println(isNumber("12 3."))
}
