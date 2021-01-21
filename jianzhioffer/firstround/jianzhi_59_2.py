"""
方法一：遍历队列求最大值，时间复杂度O(n)，入队(list.append())时间复杂度O(1)，
出队时间复杂度O(n)(list.pop()时间复杂度为O(1)，list.pop(i)的时间复杂度为O(n))
"""
# class MaxQueue(object):
#
#     def __init__(self):
#         self.queue = []
#
#     def max_value(self):
#         """
#         :rtype: int
#         """
#         return max(self.queue) if self.queue else -1
#
#     def push_back(self, value):
#         """
#         :type value: int
#         :rtype: None
#         """
#         self.queue.append(value)
#
#     def pop_front(self):
#         """
#         :rtype: int
#         """
#         return self.queue.pop(0) if self.queue else -1


"""
方法二：维护一个单调递减的队列
"""
import queue
import collections
class MaxQueue(object):

    def __init__(self):
        self.queue = queue.Queue()  # 辅助队列
        self.deque = collections.deque()  # 单调递减队列

    def max_value(self):
        """
        :rtype: int
        """
        return self.deque[0] if self.deque else -1

    def push_back(self, value):
        """
        :type value: int
        :rtype: None
        """
        while self.deque and self.deque[-1] < value:
            self.deque.pop()  # 删除队尾元素
        self.queue.put(value)
        self.deque.append(value)

    def pop_front(self):
        """
        :rtype: int
        """
        if not self.deque:  # 如果判断self.queue是否为空，会超时
            return -1
        head = self.queue.get()
        if head == self.deque[0]:
            self.deque.popleft()
        return head


if __name__ == '__main__':
    obj = MaxQueue()
    obj.push_back(1)
    obj.push_back(2)
    param_1 = obj.max_value()
    param_2 = obj.pop_front()
    param_3 = obj.max_value()
    print("Done")
