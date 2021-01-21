import collections
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        if not nums or k == 0:
            return []
        result = []
        deque = collections.deque()
        for i in range(0, k):
            while deque and deque[-1] < nums[i]:  # 先找第一个窗口的最大值
                deque.pop()  # 去除双端队列最右端的元素
            deque.append(nums[i])

        result.append(deque[0])

        for i in range(k, len(nums)):
            if deque[0] == nums[i-k]:
                deque.popleft()  # 去除双端队列最左端的元素
            while deque and deque[-1] < nums[i]:
                deque.pop()
            deque.append(nums[i])
            result.append(deque[0])
        return result


if __name__ == '__main__':
    nums = [1,3,-1,-3,5,3,6,7]
    obj = Solution()
    re = obj.maxSlidingWindow(nums, 3)
    print(re)
