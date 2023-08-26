package firstround

func combine(n, k int) [][]int {
	if n < 1 || k < 1 {
		return nil
	}

	res := make([][]int, 0)
	track := make([]int, 0)
	backtrack(&res, track, n, k, 1)
	return res
}

func backtrack(res *[][]int, track []int, n, k, idx int) {
	if len(track) == k {
		tmp := make([]int, k)
		copy(tmp, track)
		*res = append(*res, tmp)
		return
	}

	for i := idx; i <= n; i++ {
		track = append(track, i)
		backtrack(res, track, n, k, i+1)
		track = track[:len(track)-1]
	}
}
