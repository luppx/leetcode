# class Solution(object): #顺序查找，时间复杂度O(n)
#     def minArray(self, numbers):
#         """
#         :type numbers: List[int]
#         :rtype: int
#         """
#         if len(numbers)==0:
#             return -1
#         elif len(numbers)==1:
#             return numbers[0]
#         else:
#             min = numbers[0]
#             for i in range(1, len(numbers)):
#                 if numbers[i]<min:
#                     min = numbers[i]
#                     break
#             return min

class Solution(object): #二分查找，时间复杂度O(logn)
    def minArray(self, numbers):
        """
        :type numbers: List[int]
        :rtype: int
        """
        if len(numbers)==0:
            return -1
        elif len(numbers)==1:
            return numbers[0]
        else:
            low, high = 0, len(numbers)-1
            while low<high:
                mid = low + (high-low)//2
                if numbers[mid]<numbers[high]:
                    high = mid
                elif numbers[mid]>numbers[high]:
                    low = mid+1
                else:
                    high -= 1
            return numbers[low]


if __name__ == '__main__':
    obj = Solution()
    output = obj.minArray([2,2,2,0,1])
    print(output)