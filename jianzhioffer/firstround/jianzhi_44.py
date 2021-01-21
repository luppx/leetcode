class Solution(object):
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        if 0 <= n <= 9:
            return n
        digit, start, count = 1, 1, 10
        while n > count:
            n -= count
            digit += 1
            start *= 10
            count = 9 * start * digit
        num = start + n // digit
        res = str(num)[n % digit]
        return int(res)


if __name__ == '__main__':
    obj = Solution()
    result = obj.findNthDigit(11)
    print(result)
