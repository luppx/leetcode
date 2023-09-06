package firstround

// BFS
func openLock(deadends []string, target string) int {
	// 记录已访问的密码, 避免重复, 也可将deadends中的密码放在visited中, 节省一个map的空间, 否则还要另建一个map保存deadends中的密码
	visited := make(map[string]bool)
	for _, dead := range deadends {
		visited[dead] = true
	}

	q := []string{"0000"}
	step := 0

	for len(q) > 0 {
		length := len(q)
		for i := 0; i < length; i++ {
			cur := q[0]
			q = q[1:]

			// 判断这组密码是否已访问过, 以及是否属于deadends中不可访问的密码
			if visited[cur] == true {
				continue
			}

			if cur == target {
				return step
			}

			visited[cur] = true
			for j := 0; j < 4; j++ {
				up := plusOne(cur, j)
				if !visited[up] { // 判断密码是否已访问过, 避免重复遍历
					q = append(q, up)
				}

				down := minusOne(cur, j)
				if !visited[down] { // 判断密码是否已访问过, 避免重复遍历
					q = append(q, down)
				}
			}
		}
		step++
	}

	return -1
}

func plusOne(str string, i int) string {
	chs := []byte(str)
	if chs[i] == '9' {
		chs[i] = '0'
	} else {
		chs[i]++
	}

	return string(chs)
}

func minusOne(str string, i int) string {
	chs := []byte(str)
	if chs[i] == '0' {
		chs[i] = '9'
	} else {
		chs[i]--
	}

	return string(chs)
}
