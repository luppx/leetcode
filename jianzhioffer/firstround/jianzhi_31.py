class Solution(object):
    def validateStackSequences(self, pushed, popped):
        """
        :type pushed: List[int]
        :type popped: List[int]
        :rtype: bool
        """
        stack, i = [], 0
        for num in pushed:
            stack.append(num)
            while stack and stack[-1] == popped[i]:
                stack.pop()
                i += 1
        return not stack


if __name__ == '__main__':
    p = [1,2,3,4,5]
    q = [4,5,3,2,1]
    obj = Solution()
    result = obj.validateStackSequences(p, q)
    print(result)
