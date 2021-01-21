"""
方法一：暴力解，时间复杂度O(n^2)，空间复杂度O(1)，会超时
"""
# class Solution(object):
#     def reversePairs(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: int
#         """
#         if not nums:
#             return 0
#         res = 0
#         for i in range(len(nums)-1):
#             for j in range(i+1, len(nums)):
#                 if nums[j] < nums[i]:
#                     res += 1
#         return res


"""
方法二：归并排序，时间复杂度O(nlogn)(同归并排序)，空间复杂度O(n)(同归并排序，建立了一个辅助数组tmp来存储排序后的元素)
"""
class Solution(object):
    def mergeSort(self, array, tmp, left, right):
        if left >= right:
            return 0
        mid = (left + right) // 2
        inv_count = self.mergeSort(array, tmp, left, mid) + self.mergeSort(array, tmp, mid+1, right)
        i, j, pos = left, mid+1, left
        while i <= mid and j <= right:
            if array[i] <= array[j]:  # 只在i右移时才计算array[i]的逆序对数，因为i右移表明array[i]<=array[j]，
                tmp[pos] = array[i]  # 但array[i]比array[mid+1,...,j-1]都要大，所以array[i]的逆序对数=j-(mid+1)
                i += 1
                inv_count += (j - (mid + 1))
            else:
                tmp[pos] = array[j]
                j += 1
            pos += 1
        for k in range(i, mid+1):  # 如果i<mid+1，说明前半部分剩下的元素比后半部分所有元素都要大，
            tmp[pos] = array[k]  # 所以前半部分剩下的元素的逆序对数都等于j-(mid+1)，此时该式的值等于后半部分的元素个数
            pos += 1
            inv_count += j - (mid + 1)
        for k in range(j, right+1):
            tmp[pos] = array[k]
            pos += 1
        array[left:right+1] = tmp[left:right+1]
        return inv_count

    def reversePairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        n = len(nums)
        tmp = [0] * n
        res = self.mergeSort(nums, tmp, 0, n-1)
        return res


if __name__ == '__main__':
    nums = [7,5,6,4]
    obj = Solution()
    result = obj.reversePairs(nums)
    print(result)
