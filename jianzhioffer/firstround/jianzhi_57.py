class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if not nums or len(nums) == 1:
            return []
        left, right = 0, len(nums)-1
        while left < right:
            sum = nums[left] + nums[right]
            if sum < target:
                left += 1
            elif sum > target:
                right -= 1
            else:
                return [nums[left], nums[right]]
        return []


if __name__ == '__main__':
    n = [2,7,11,15]
    target = 18
    obj = Solution()
    result = obj.twoSum(n, target)
    print(result)
