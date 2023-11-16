#include <vector>
using namespace std;

#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board);

private:
    bool recur(vector<vector<char>>& board);
    bool isValid(vector<vector<char>>& board, int i, int j, char n);
};

void Solution::solveSudoku(vector<vector<char>>& board) {
    recur(board);
    return;
}

bool Solution::recur(vector<vector<char>>& board)
{
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[0].size(); j++)
        {
            if(board[i][j]!='.') continue;

            for(char k='1'; k<='9'; k++)
            {
                if(!isValid(board, i, j, k)) continue;

                board[i][j] = k;
                if(recur(board)) return true;
                board[i][j] = '.';
            }
            return false;
        }
    }

    return true;
}

bool Solution::isValid(vector<vector<char>>& board, int i, int j, char n)
{
    for(int k=0; k<board[0].size(); k++)  //判断同一行是否出现相同数字
    {
        if(board[i][k]==n) return false;
    }

    for(int k=0; k<board.size(); k++)  //判断同一列是否出现相同数字
    {
        if(board[k][j]==n) return false;
    }

    for(int x=(i/3+1)*3-1; x>=(i/3)*3; x--)
    {
        for(int y=(j/3+1)*3-1; y>=(j/3)*3; y--)
        {
            if(board[x][y]==n) return false;
        }
    }
    return true;
}


int main()
{
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution obj;
    obj.solveSudoku(board);
    return 0;
}