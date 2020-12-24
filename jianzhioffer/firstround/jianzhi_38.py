class Solution(object):
    def permutation(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        c, res = list(s), []

        def dfs(x):
            if x == len(c) - 1:
                res.append(''.join(c))
                return

            dic = set()
            for i in range(x, len(c)):
                if c[i] in dic:
                    continue
                dic.add(c[i])
                c[i], c[x] = c[x], c[i]
                dfs(x+1)
                c[i], c[x] = c[x], c[i]

        dfs(0)
        return res


if __name__ == '__main__':
    s = "abc"
    obj = Solution()
    result = obj.permutation(s)
    print(result)
