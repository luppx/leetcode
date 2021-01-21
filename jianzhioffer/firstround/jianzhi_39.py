class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        vote = 0
        mode = 0    # 众数
        for i in range(len(nums)):
            if vote == 0:   # 遍历数组第一个数字时，vote=0，肯定会执行这条if语句
                mode = nums[i]
                vote += 1
            else:
                if nums[i] == mode:
                    vote += 1
                else:
                    vote -= 1
        return mode


if __name__ == '__main__':
    nums = [6,6,6,7,7]
    obj = Solution()
    num = obj.majorityElement(nums)
    print(num)

