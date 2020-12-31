class Solution(object):
    def translateNum(self, num):
        """
        :type num: int
        :rtype: int
        """
        # a:dp[i-2], b:dp[i-1]
        # initialize a:dp[0]=1, b:dp[1]=1，即num为空或num只有1位时，翻译方案数量均为1
        a, b = 1, 1
        strs = str(num)
        t = list(strs)
        for i in range(2, len(strs)+1):
            tmp = strs[i-2:i]
            if '10' <= tmp <= '25':
                c = a + b  # dp[i] = dp[i-2] + dp[i-1]
            else:
                c = b  # dp[i] =dp[i-1]
            a = b
            b = c
        return b


if __name__ == '__main__':
    num = 12258
    obj = Solution()
    result = obj.translateNum(num)
    print(result)
