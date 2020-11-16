class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = s.strip()  # 删除句首和句尾的全部空格
        i = j = len(s)-1
        result_list = []
        while i >= 0:
            while i >= 0 and s[i] != ' ':
                i -= 1
            result_list.append(s[i+1:j+1])
            while i >= 0 and s[i] == ' ':
                i -= 1
            j = i
        result = ' '.join(result_list)
        return result


if __name__ == '__main__':
    str = "   the  sky is blue  "
    obj = Solution()
    r = obj.reverseWords(str)
    print(r)
