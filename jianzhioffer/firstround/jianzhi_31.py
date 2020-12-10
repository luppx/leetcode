class Solution(object):
    def validateStackSequences(self, pushed, popped):
        """
        :type pushed: List[int]
        :type popped: List[int]
        :rtype: bool
        """
        if not pushed and not popped:
            return True
        elif not pushed or not popped:
            return False
        query = [pushed.pop(0)]
        while popped:
            if popped[0] not in query:
                query.append(pushed.pop(0))
            elif query[-1] != popped[0]:
                return False
            else:
                query.pop(-1)
                popped.pop(0)
        return True


if __name__ == '__main__':
    p = [1,2,3,4,5]
    q = [[4,3,5,1,2]]
    obj = Solution()
    result = obj.validateStackSequences(p, q)
    print(result)
