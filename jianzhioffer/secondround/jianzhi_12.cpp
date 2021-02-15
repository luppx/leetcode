#include <vector>
#include <string>
using namespace std;

//DFS+剪枝
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty() || board.empty())
            return false;
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }

private:
    int rows, cols;
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k){
        if (i>=rows || i<0 || j>=cols || j<0 || board[i][j]!=word[k])
            return false;
        else if (k==word.size()-1)
            return true;
        board[i][j] = '\0';
        bool res = dfs(board, word, i-1, j, k+1) || dfs(board, word, i, j-1, k+1) || 
                   dfs(board, word, i, j+1, k+1) || dfs(board, word, i+1, j, k+1);
        board[i][j] = word[k];
        return res;
    }
};

int main(int argc, char const *argv[])
{
    int m = 3;
    int n = 4;
    vector<vector<char>> nums(m, vector<char>(n));

    nums[0] = {'A','B','C','E'};
    nums[1] = {'S','F','C','S'},
    nums[2] = {'A','D','E','E'};
    string w = "ABCCED";
    Solution obj;
    bool result = obj.exist(nums, w);
    return 0;
}
