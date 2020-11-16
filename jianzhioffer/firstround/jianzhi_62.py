class Solution(object):
    def lastRemaining(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        if n == 1:
            return n - 1
        f = 0
        for i in range(2, n+1):
            f = (f + m) % i
        return f


if __name__ == '__main__':
    obj = Solution()
    result = obj.lastRemaining(5, 3)
    print(result)
