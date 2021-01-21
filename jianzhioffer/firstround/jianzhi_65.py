# 参考题解：
# 1.https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/solution/mian-shi-ti-65-bu-yong-jia-jian-cheng-chu-zuo-ji-7/
# 2.https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/solution/er-jin-zhi-qiu-he-chao-xiang-xi-da-bai-10000yong-h/
class Solution(object):
    def add(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        x = 0xffffffff
        a = a & x
        b = b & x
        while b != 0:
            c = ((a & b) << 1) & x  # 进位
            a = a ^ b
            b = c
        return a if a <= 0x7fffffff else ~(a ^ x)


if __name__ == '__main__':
    obj = Solution()
    result = obj.add(5, 7)
    print(result)
