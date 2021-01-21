"""
方法一：暴力法，遍历数组，时间复杂度O(n^2)，空间复杂度O(1)，会超时
"""
# class Solution(object):
#     def constructArr(self, a):
#         """
#         :type a: List[int]
#         :rtype: List[int]
#         """
#         if not a:
#             return []
#         b = []
#         for i in range(len(a)):
#             tmp = 1
#             for j in range(len(a)):
#                 if j == i:
#                     continue
#                 tmp *= a[j]
#             b.append(tmp)
#         return b


"""
方法二：对称遍历。计算B[i]，其实就是把A[i]的值变为1，再计算A[0]*A[1]*...*A[n-1]，
列一个表格，可以发现，表格主对角线的元素都是1。那么计算时就可以分成两部分计算，即A[0]*...*A[i-1]和A[i+1]*...*A[n-1]这两部分
时间复杂度O(n)，空间复杂度O(1)
"""
class Solution(object):
    def constructArr(self, a):
        """
        :type a: List[int]
        :rtype: List[int]
        """
        if not a:
            return []
        b = [1]*len(a)
        for i in range(1, len(a)):  # 计算A[0]*...*A[i-1]这部分的乘积
            b[i] = b[i-1] * a[i-1]
        tmp = 1
        for i in range(len(a)-2, -1, -1):
            tmp *= a[i+1]  # tmp表示A[i+1]*...*A[n-1]这部分的乘积
            b[i] *= tmp
        return b

if __name__ == '__main__':
    nums = [1,2,3,4,5]
    obj = Solution()
    result = obj.constructArr(nums)
    print(result)
