# 贪心算法
class Solution(object):
    def cuttingRope(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 3:
            return n-1
        elif n == 4:
            return 4
        res = 1
        while n > 4:
            res *= 3
            res = res % 1000000007
            n -= 3
        return (res * n) % 1000000007


if __name__ == '__main__':
    obj = Solution()
    result = obj.cuttingRope(120)
    print(result)
