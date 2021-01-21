class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i, j = 0, len(nums)-1
        while i <= j:
            mid = (i + j) // 2
            if nums[mid] <= mid:
                i = mid + 1
            else:
                j = mid - 1
        return i


if __name__ == '__main__':
    arr = [0,1,2,4,5,6,7,8,9]
    obj = Solution()
    num = obj.missingNumber(arr)
    print(num)

