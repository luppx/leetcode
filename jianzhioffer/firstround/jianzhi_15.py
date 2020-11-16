class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        num = 0
        while n:
            num += n&1
            n >>= 1
        return num


if __name__ == '__main__':
    obj = Solution()
    num = obj.hammingWeight(0b11111111111111111111111111111101)
    print(num)
