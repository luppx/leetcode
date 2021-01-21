class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxsum = nums[0]
        for i in range(1, len(nums)):
            if nums[i-1] > 0:
                nums[i] += nums[i-1]
            maxsum = max(maxsum, nums[i])
        return maxsum


if __name__ == '__main__':
    arr = [-2,1,-3,4,-1,2,1,-5,4]
    obj = Solution()
    maxnum = obj.maxSubArray(arr)
    print(maxnum)

