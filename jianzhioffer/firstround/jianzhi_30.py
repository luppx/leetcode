class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack, self.stack2 = list(), list()

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.stack.append(x)
        if not self.stack2 or self.stack2[-1] >= x:
            self.stack2.append(x)

    def pop(self):
        """
        :rtype: None
        """
        val = self.stack.pop()
        if val == self.stack2[-1]:
            self.stack2.pop()

    def top(self):
        """
        :rtype: int
        """
        return self.stack[-1]

    def min(self):
        """
        :rtype: int
        """
        return self.stack2[-1]


if __name__ == '__main__':
    # Your MinStack object will be instantiated and called as such:
    obj = MinStack()
    obj.push(0)
    obj.push(1)
    obj.push(0)

    param_3 = obj.min()
    obj.pop()
    param_4 = obj.top()
    param_5 = obj.min()
    print('D')
