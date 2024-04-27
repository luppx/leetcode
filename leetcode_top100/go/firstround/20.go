package firstround

// 栈.时间复杂度O(n),空间复杂度O(n)
func isValid(s string) bool {
	stack := make([]int32, len(s))
	top := -1

	for _, ch := range s {
		if ch == '(' || ch == '[' || ch == '{' {
			top++
			stack[top] = ch
			continue
		}
		if (ch == ')' && stack[top] != '(') || (ch == ']' && stack[top] != '[') || (ch == '}' && stack[top] != '{') {
			return false
		}
		top--
	}
	return true
}
