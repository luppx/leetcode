class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if not nums or (target < nums[0]) or (target > nums[-1]):
            return 0

        i, j = 0, len(nums)-1
        while i <= j:   # 先查找右边界
            mid = (i + j) // 2
            if nums[mid] <= target:
                i = mid + 1
            else:
                j = mid - 1

        if j >= 0 and nums[j] != target:   # 如果右边界的值不等于target，说明数组中没有target，直接返回0
            return 0
        right = i
        i = 0
        while i <= j:   # 查找左边界
            mid = (i + j) // 2
            if nums[mid] < target:
                i = mid + 1
            else:
                j = mid - 1
        left = j
        return right - left - 1


if __name__ == '__main__':
    arr = [5, 7, 7, 8, 8, 10]
    obj = Solution()
    num = obj.search(arr, 8)
    print(num)
