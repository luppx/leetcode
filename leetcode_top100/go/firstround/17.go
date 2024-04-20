package firstround

import "strings"

var res []string

func letterCombinations(digits string) []string {
	if len(digits) < 1 {
		return []string{}
	}

	letterMap := map[string][]string{
		"2": {"a", "b", "c"},
		"3": {"d", "e", "f"},
		"4": {"g", "h", "i"},
		"5": {"j", "k", "l"},
		"6": {"m", "n", "o"},
		"7": {"p", "q", "r", "s"},
		"8": {"t", "u", "v"},
		"9": {"w", "x", "y", "z"},
	}

	res = make([]string, 0)
	chs := make([]string, len(digits))
	dfs(digits, 0, chs, letterMap)
	return res
}

func dfs(digits string, idx int, chs []string, letterMap map[string][]string) {
	if idx >= len(digits) {
		str := strings.Join(chs, "")
		res = append(res, str)
		return
	}

	characters := letterMap[string(digits[idx])]
	for i := 0; i < len(characters); i++ {
		chs[idx] = characters[i]
		dfs(digits, idx+1, chs, letterMap)
	}
	return
}
