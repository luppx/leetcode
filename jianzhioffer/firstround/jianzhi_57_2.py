class Solution(object):
    def findContinuousSequence(self, target):
        """
        :type target: int
        :rtype: List[List[int]]
        """
        # 数组连续递增，输出的序列必须是连续正整数序列，且至少包含2个数
        if target <= 2:
            return []
        result = []
        i, j = 1, 2
        while i <= target//2:  # 因为输出的序列至少包含2个数，所以只需要递增到target/2就不用再找了
            sum = (i + j) * (j - i + 1) // 2
            if sum == target:
                result.append([x for x in range(i, j+1)])
                i += 1
            elif sum > target:
                i += 1
            else:
                j += 1
        return result


if __name__ == '__main__':
    obj = Solution()
    result = obj.findContinuousSequence(9)
    print(result)

