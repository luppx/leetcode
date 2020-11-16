class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: str
        """
        dic = {}
        for str in s:
            dic[str] = str not in dic

        for c in dic:
            if dic[c]:
                return c
        return " "


if __name__ == '__main__':
    s = "leetcode"
    obj = Solution()
    str = obj.firstUniqChar(s)
    print(str)