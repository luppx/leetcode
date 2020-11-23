# 方法一：动态规划
# class Solution(object):
#     def cuttingRope(self, n):
#         """
#         :type n: int
#         :rtype: int
#         """
#         dp = [0] * (n+1)
#         for i in range(2, n+1):
#             for j in range(1, i):
#                 dp[i] = max(dp[i], j*(i-j), dp[i-j]*j)
#         return dp[n]

# 优化的动态规划
class Solution(object):
    def cuttingRope(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 3:
            return n-1
        dp = [0] * (n+1)
        dp[2] = 1
        dp[3] = 2
        for i in range(4, n+1):
            dp[i] = max(2*(i-2), 2*dp[i-2], 3*(i-3), 3*dp[i-3])
        return dp[n]

# # 方法二：贪心算法
# class Solution(object):
#     def cuttingRope(self, n):
#         """
#         :type n: int
#         :rtype: int
#         """
#         if n <= 3:
#             return n-1
#         elif n == 4:
#             return 4
#         res = 1
#         while n > 4:
#             res *= 3
#             n -= 3
#         return res * n


if __name__ == '__main__':
    obj = Solution()
    result = obj.cuttingRope(10)
    print(result)
