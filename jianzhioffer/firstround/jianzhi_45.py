# 选择排序
# class Solution(object):
#     def minNumber(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: str
#         """
#         if not nums:
#             return ""
#         nums = [str(num) for num in nums]
#
#         for i in range(len(nums)-1):
#             min_idx = i
#             for j in range(i+1, len(nums)):
#                 if nums[j] + nums[min_idx] < nums[min_idx] + nums[j]:
#                     min_idx = j
#             nums[i], nums[min_idx] = nums[min_idx], nums[i]
#         return ''.join(nums)

# 快速排序
class Solution(object):
    def minNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        if not nums:
            return ""

        def fast_sort(left, right):
            if left >= right:
                return
            i, j = left, right
            while i < j:
                while i < j and nums[j] + nums[left] >= nums[left] + nums[j]:
                    j -= 1
                while i < j and nums[i] + nums[left] <= nums[left] + nums[i]:
                    i += 1
                nums[i], nums[j] = nums[j], nums[i]
            nums[i], nums[left] = nums[left], nums[i]
            fast_sort(left, i-1)
            fast_sort(i+1, right)

        nums = [str(num) for num in nums]
        fast_sort(0, len(nums)-1)
        return ''.join(nums)

if __name__ == '__main__':
    nums = [1,4,7,2,5,8,0,3,6,9]
    nums.sort()
    obj = Solution()
    res = obj.minNumber(nums)
    print(res)
