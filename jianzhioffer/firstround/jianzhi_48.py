class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        dic, res, tmp = {}, 0, 0
        for j in range(len(s)):
            i = dic.get(s[j], default=-1)  # 获取dic中键s[j]对应的值，如果键s[j]不存在，则返回设置的默认值-1
            dic[s[j]] = j
            if tmp < j - i:
                tmp += 1
            else:
                tmp = j - i
            res = max(res, tmp)
        return res


if __name__ == '__main__':
    str = "abcabcbb"
    obj = Solution()
    result = obj.lengthOfLongestSubstring(str)
    print(result)
