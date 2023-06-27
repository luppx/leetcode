package main

// 循环求解, 时间复杂度O(n)
//func myPow(x float64, n int) float64 {
//	if x == 0 {
//		if n == 0 {
//			return -1
//		} else {
//			return 0
//		}
//	} else if x == 1 {
//		return x
//	} else if x == -1 {
//		if n%2 == 0 {
//			return 1
//		} else {
//			return -1
//		}
//	} else if n == 0 {
//		return 1
//	}
//
//	absX := math.Abs(x)
//	absN := int(math.Abs(float64(n)))
//	symbolNum := 1
//	// 判断结果是否为负
//	if x < 0 && absN%2 != 0 {
//		symbolNum = -1
//	}
//
//	res := 1.0
//	for i := 0; i < absN; i++ {
//		res *= absX
//	}
//
//	// 乘以符号位
//	res *= float64(symbolNum)
//
//	// 如果指数为负数, 则返回倒数
//	if n < 0 {
//		return 1.0 / res
//	}
//	return res
//}

// 快速幂, 时间复杂度O(log2^n)
func myPow(x float64, n int) float64 {
	if x == 0 {
		return 0
	}

	if n > 0 {
		return quickMul(x, n)
	}
	return 1 / quickMul(x, -n)
}

func quickMul(x float64, n int) float64 {
	if x == 0 {
		return 0
	}

	res := 1.0
	p := x // 记录x^(2^k)
	for ; n > 0; n /= 2 {
		if n%2 == 1 {
			res *= p
		}
		p *= p
	}
	return res
}
