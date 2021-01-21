"""
方法一：暴力法，即正常插入，等取中位数时再对数组排序。
时间复杂度O(n*logn)，提交代码会超时
"""
# class MedianFinder(object):
#
#     def __init__(self):
#         """
#         initialize your data structure here.
#         """
#         self.nums = []
#
#     def addNum(self, num):
#         """
#         :type num: int
#         :rtype: None
#         """
#         self.nums.append(num)
#
#     def findMedian(self):
#         """
#         :rtype: float
#         """
#         if len(self.nums) == 0:
#             return "null"
#
#         def partition(array, left, right):
#             i, j = left, right
#             pivot = array[i]
#             while i < j:
#                 while i < j and array[j] >= pivot:
#                     j -= 1
#                 if i < j:
#                     array[i] = array[j]
#                 while i < j and array[i] <= pivot:
#                     i += 1
#                 if i < j:
#                     array[j] = array[i]
#             array[i] = pivot
#             return i
#
#         def quicksort(array, low, high):
#             if low < high:
#                 boundary = partition(array, low, high)
#                 quicksort(array, low, boundary-1)
#                 quicksort(array, boundary+1, high)
#
#         length = len(self.nums)
#         quicksort(self.nums, 0, length-1)
#         return self.nums[length//2] if length % 2 else (self.nums[length//2 - 1] + self.nums[length//2]) / 2.0

"""
方法二：二分查找，每次插入时都用二分查找将元素插入到合适位置，使数组始终保持有序。
时间复杂度：O(n)
分析：
addNum()函数中，二分查找的时间复杂度为O(logn)，插入元素的时间复杂度为O(n)(插入元素时后面的元素都得往后移一个位置)
finMedian()函数中，计算中位数的时间复杂度为O(1)
"""
# class MedianFinder(object):
#
#     def __init__(self):
#         """
#         initialize your data structure here.
#         """
#         self.nums = []
#
#     def addNum(self, num):
#         """
#         :type num: int
#         :rtype: None
#         """
#         if not self.nums or num >= self.nums[-1]:
#             self.nums.append(num)
#         else:
#             i, j, idx = 0, len(self.nums)-1, len(self.nums)-1
#             while i <= j:
#                 mid = i + (j-i)//2
#                 if num == self.nums[mid]:
#                     idx = mid
#                     break
#                 elif num < self.nums[mid]:
#                     j = mid - 1
#                 else:
#                     i = mid + 1
#                 idx = i
#             self.nums.insert(idx, num)
#
#     def findMedian(self):
#         """
#         :rtype: float
#         """
#         if len(self.nums) == 0:
#             return "null"
#         length = len(self.nums)
#         return self.nums[length//2] if length % 2 else (self.nums[length//2 - 1] + self.nums[length//2]) / 2.0

"""
方法三：优先队列/堆。维护两个堆，一个小顶堆A，一个大顶堆B。A存储最大的那一半数字，B存储最小的那一半数字。如果总数字个数是奇数的话，A多存储一个数据。
假设A、B的堆顶元素分别为a1、b1，则奇数情况下，中位数median=a1；偶数情况下median=(a1+b1)/2
时间复杂度O(logn)(堆的插入和弹出操作需O(logn)时间)，空间复杂度O(n)(维护2个堆)
分析：
addNum()函数中，二分查找的时间复杂度为O(logn)，插入元素的时间复杂度为O(n)(插入元素时后面的元素都得往后移一个位置)
finMedian()函数中，计算中位数的时间复杂度为O(1)
"""
from heapq import *  # heapq模块实现的是小顶堆，若要实现大顶堆，则在插入大顶堆前将数字取反即可
class MedianFinder(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.A, self.B = [], []

    def addNum(self, num):
        """
        :type num: int
        :rtype: None
        """
        if len(self.A) != len(self.B):
            heappush(self.B, -heappushpop(self.A, num))
        else:
            heappush(self.A, -heappushpop(self.B, -num))

    def findMedian(self):
        """
        :rtype: float
        """
        if not self.B:
            return "null"
        return self.A[0] if len(self.A) != len(self.B) else (self.A[0] - self.B[0]) / 2.0


if __name__ == '__main__':
    obj = MedianFinder()
    param_1 = obj.findMedian()
    obj.addNum(3)
    obj.addNum(2)
    param_2 = obj.findMedian()
    obj.addNum(3)
    param_3 = obj.findMedian()
    print(param_1, param_2, param_3)
