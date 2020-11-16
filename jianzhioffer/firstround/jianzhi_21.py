class Solution(object):
    def exchange(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        length = len(nums)
        if length <= 1:
            return nums
        odd = []
        even = []
        now = 0

        while now < length:
            if nums[now] % 2 == 0:
                even.append(nums[now])
            else:
                odd.append(nums[now])
            now += 1

        exchange = odd + even

        return exchange


if __name__ == '__main__':
    nums = [1,1,4,3]

    obj = Solution()
    obj.exchange(nums)
    print(nums)
