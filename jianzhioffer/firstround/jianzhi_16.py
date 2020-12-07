class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if x == 0:
            return 0.0
        if n == 0:
            return 1.0
        res = 1
        if n < 0:
            x = 1 / x
            n = -n
        while n:
            if n & 1:
                res *= x
            x *= x
            n = n >> 1
        return res


if __name__ == '__main__':
    obj = Solution()
    result = obj.myPow(-2.0, 9)
    print(result)
