package firstround

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func generateTrees(n int) []*TreeNode {
	if n < 1 {
		return make([]*TreeNode, 0)
	}

	return generateTree(1, n)
}

func generateTree(lower, upper int) []*TreeNode {
	if lower > upper {
		return []*TreeNode{nil}
	}

	trees := make([]*TreeNode, 0)

	for i := lower; i <= upper; i++ {
		leftSubTrees := generateTree(lower, i-1)
		rightSubTrees := generateTree(i+1, upper)

		for _, l := range leftSubTrees {
			for _, r := range rightSubTrees {
				root := &TreeNode{Val: i, Left: l, Right: r}
				trees = append(trees, root)
			}
		}
	}

	return trees
}
