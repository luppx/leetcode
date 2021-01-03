"""
方法一：统计各数字出现的次数，最后找到出现次数为1的值即可
"""
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dic = {}
        for num in nums:
            dic[num] = dic.get(num, 0) + 1
        for key in dic.keys():
            if dic[key] == 1:
                return key
        return -1


"""
方法二：将数字转换为二进制，统计所有位出现的次数，因为只有1个数字出现1次，其他所有数字都出现3次，
所以最后各个位模3之后得到的结果即为只出现1次的这个数字的二进制形式
"""
# class Solution(object):
#     def singleNumber(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: int
#         """
#         counts = [0]*32
#         for num in nums:
#             for i in range(32):
#                 counts[i] += num & 1
#                 num >>= 1
#                 if num == 0:
#                     break
#         res = 0
#         for i in range(32):
#             res <<= 1
#             res |= counts[31-i] % 3
#         return res if counts[31] % 3 == 0 else ~(res ^ 0xffffffff)


if __name__ == '__main__':
    nums = [3,4,3,3]
    obj = Solution()
    result = obj.singleNumber(nums)
    print(result)
