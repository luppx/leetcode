# 方法一：对整个数组排序，然后返回前n个值
# class Solution(object):
#     def getLeastNumbers(self, arr, k):
#         """
#         :type arr: List[int]
#         :type k: int
#         :rtype: List[int]
#         """
#         def QuickSort(begin, end):
#             if begin < end:
#                 i, j = begin, end
#                 tmp = arr[i]
#                 while i < j:
#                     while i < j and arr[j] > tmp:
#                         j -= 1
#                     arr[i] = arr[j]
#                     while i < j and arr[i] <= tmp:
#                         i += 1
#                     arr[j] = arr[i]
#                 arr[i] = tmp
#                 QuickSort(begin, i-1)
#                 QuickSort(i+1, end)
#
#         if len(arr) == 0 or len(arr) == 1:
#             return arr
#         elif k == 0:
#             return []
#         QuickSort(0, len(arr)-1)
#         minlist = [arr[x] for x in range(k)]
#         return minlist
#
#
# if __name__ == '__main__':
#     arr = [0,0,1,2,4,2,2,3,1,4]
#     obj = Solution()
#     minlist = obj.getLeastNumbers(arr, 8)
#     print(minlist)

# 方法二：利用快排思想，仅对某一侧排序，假设第一次排序完后分界点的下标为pos
# 如果pos-left+1 == k，则说明pos是第k个最小的值，返回left到post的值即可
# 如果pos-left+1 < k，则说明第k个最小值在pos右边，继续对pos右侧的值排序
# 如果pos-left+1 > k，则说明第k个最小值在pos左边，继续对pos左侧的值排序
# 因为返回结果只要是最小的k个值即可，并不要求返回的值要有序，所以不需要对数组全部排序
class Solution(object):
    def partition(self, arr, begin, end):
        i, j = begin, end
        tmp = arr[i]
        while i < j:
            while i < j and arr[j] > tmp:
                j -= 1
            arr[i] = arr[j]
            while i < j and arr[i] <= tmp:
                i += 1
            arr[j] = arr[i]
        arr[i] = tmp
        return i

    def find_k_num(self, arr, begin, end, k):
        pos = self.partition(arr, begin, end)
        num = pos - begin + 1
        if num < k:  # 第k个最小值在pos右侧
            self.find_k_num(arr, pos+1, end, k-num)
        elif num > k:  # 第k个最小值在pos左侧
            self.find_k_num(arr, begin, pos-1, k)

    def getLeastNumbers(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: List[int]
        """
        if len(arr) == 0 or len(arr) == 1:
            return arr
        elif k == 0:
            return []
        self.find_k_num(arr, 0, len(arr)-1, k)
        return arr[:k]


if __name__ == '__main__':
    arr = [0,0,1,2,4,2,2,3,1,4]
    obj = Solution()
    minlist = obj.getLeastNumbers(arr, 8)
    print(minlist)