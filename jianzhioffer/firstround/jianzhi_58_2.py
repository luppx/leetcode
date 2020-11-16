class Solution(object):
    def reverseLeftWords(self, s, n):
        """
        :type s: str
        :type n: int
        :rtype: str
        """
        end = s[:n]
        start = s[n:]
        return start + end


if __name__ == '__main__':
    obj = Solution()
    s = "abcdefg"
    result = obj.reverseLeftWords(s, 2)
    print(result)
