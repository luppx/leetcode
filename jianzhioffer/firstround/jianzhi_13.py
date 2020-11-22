# 方法一：深度优先遍历
# class Solution(object):
#     def movingCount(self, m, n, k):
#         """
#         :type m: int
#         :type n: int
#         :type k: int
#         :rtype: int
#         """
#         def dfs(i, j):
#             tmp = i % 10 + i//10 + j % 10 + j//10
#             if i >= m or j >= n or (i % 10 + i//10 + j % 10 + j//10) > k or (i, j) in visited:
#                 return 0
#             visited.add((i, j))
#             return 1 + dfs(i+1, j) + dfs(i, j+1)
#
#         visited = set()
#         return dfs(0, 0)

# 方法二：广度优先遍历。
class Solution(object):
    def movingCount(self, m, n, k):
        """
        :type m: int
        :type n: int
        :type k: int
        :rtype: int
        """
        queue = [(0, 0)]
        visited = set()
        while queue:
            i, j = queue.pop(0)
            if i >= m or j >= n or (i % 10 + i//10 + j % 10 + j//10) > k or (i, j) in visited:
                continue
            visited.add((i, j))
            queue.append((i+1, j))
            queue.append((i, j+1))
        return len(visited)


if __name__ == '__main__':
    obj = Solution()
    result = obj.movingCount(2, 3, 1)
    print(result)
