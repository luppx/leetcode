class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        def dfs(i, j, k):
            if not 0 <= i <= len(board)-1 or not 0 <= j <= len(board[0])-1 or board[i][j] != word[k]:
                return False
            if k == len(word) - 1:
                return True
            board[i][j] = ''
            res = dfs(i+1, j, k+1) or dfs(i-1, j, k+1) or dfs(i, j-1, k+1) or dfs(i, j+1, k+1)
            board[i][j] = word[k]
            return res

        for row in range(len(board)):
            for col in range(len(board[0])):
                if dfs(row, col, 0):
                    return True
        return False


if __name__ == '__main__':
    board = [["C","A","A"],["A","A","A"],["B","C","D"]]
    word = "AAB"
    obj = Solution()
    result = obj.exist(board, word)
    print(result)


