import functools

class Solution(object):
    def singleNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ret = functools.reduce(lambda x, y: x ^ y, nums)
        div = 1
        while div & ret == 0:
            div <<= 1
        a, b = 0, 0
        for n in nums:
            if n & div:
                a ^= n
            else:
                b ^= n
        return [a, b]


if __name__ == '__main__':
    num = [1,2,10,4,1,4,3,3]
    obj = Solution()
    result = obj.singleNumbers(num)
    print(result)
