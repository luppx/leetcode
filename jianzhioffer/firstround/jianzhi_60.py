class Solution(object):
    def dicesProbability(self, n):
        """
        :type n: int
        :rtype: List[float]
        """
        dp = [0] + [1]*6  # 初始状态，只有一个骰子时，数字和为1-6，且各个数字只出现一次，为了让数组下标和实际情况吻合，故令dp[0]=0，从dp[1]开始计算

        for i in range(2, n+1):
            dp += [0]*6
            for j in range(i*6, i-1, -1):  # n个骰子的最大数字和为6n，最小数字和为n。比如n=2时，显然可知2个骰子的最大数字和为12，最小数字和为2。
                dp[j] = 0  # 注意要令dp[j]=0，因为不考虑n-1个骰子的结果。比如n=2时，那么要先令dp[6]=0，即不考虑原本n=1时骰子和为6的情况了。
                for cur in range(j-1, j-7, -1):
                    if cur < i-1:
                        break
                    dp[j] += dp[cur]
        # 最后返回结果也是取dp[n:]，因为n个骰子的最小数字和为n，所以前面dp[:n]的值舍弃掉
        return [x / pow(6, n) for x in list(map(float, dp[n:]))]


if __name__ == '__main__':
    obj = Solution()
    result = obj.dicesProbability(2)
    print(result)
