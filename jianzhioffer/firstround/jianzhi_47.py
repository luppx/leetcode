class Solution(object):
    def maxValue(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        for i in range(len(grid)):  # rows
            for j in range(len(grid[0])):  # cols
                # 起点，dp[0][0] = grid[0][0]
                if i == 0 and j == 0:
                    continue
                # 行号固定为0，列号动，即从起点出发横着走的情况
                elif i == 0 and j != 0:
                    grid[0][j] += grid[0][j-1]
                # 行号动，列号固定为0，即从起点出发竖着走的情况
                elif i != 0 and j == 0:
                    grid[i][0] += grid[i-1][0]
                # 行号列号都动，则某个点可能向下走到达，也可能向右走到达，最大价值即为max{该点上方点的最大价值，该点左边点的最大价值}+该点的价值
                else:
                    grid[i][j] += max(grid[i-1][j], grid[i][j-1])
        return grid[-1][-1]


# class Solution(object):
#     # 跟方法一差不多，区别在于先计算第一行和第一列各点的累计最大价值，这样就可以减少循环内的判断次数
#     def maxValue(self, grid):
#         """
#         :type grid: List[List[int]]
#         :rtype: int
#         """
#         rows, cols = len(grid), len(grid[0])
#         # 计算第一行各点的累计最大价值
#         for j in range(1, cols):
#             grid[0][j] += grid[0][j-1]
#         # 计算第一列各点的累计最大价值
#         for i in range(1, rows):
#             grid[i][0] += grid[i-1][0]
#
#         for i in range(1, rows):  # row
#             for j in range(1, cols):  # col
#                 # 行号列号都动，则某个点可能向下走到达，也可能向右走到达，最大价值即为max{该点上方点的最大价值，该点左边点的最大价值}+该点的价值
#                 grid[i][j] += max(grid[i-1][j], grid[i][j-1])
#
#         return grid[-1][-1]


if __name__ == '__main__':
    grid = [
              [1,3,1],
              [1,5,1],
              [4,2,1]
            ]
    obj = Solution()
    result = obj.maxValue(grid)
    print(result)
