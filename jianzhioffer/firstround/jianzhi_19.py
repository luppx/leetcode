class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        if not s and not p:
            return True
        elif (not s and p) or (s and not p):
            return False
        s = list(s)
        p = list(p)
        length = 0
        i, j = 0, 0
        while i < len(s):
            while j < len(p):
                if p[j] == '.' or p[j] == s[i]:
                    length += 1
                    i += 1
                    j += 1
                elif p[j] == '*' and j > 0:
                    tmp = p[j-1]
                    if p[j-1] == '.':
                        tmp = s[i]
                    while i < len(s) and s[i] == tmp:
                        length += 1
                        i += 1
                    j += 1
                elif length == 0 and j < len(p)-1 and p[j+1] == '*':
                    j += 2
                else:
                    break
                if length == len(s):
                    return True
            i += 1
            j = 0
            length = 0
        return False


if __name__ == '__main__':
    s = "mississippi"
    p = "mis*is*p*."
    obj = Solution()
    result = obj.isMatch(s, p)
    print(result)
