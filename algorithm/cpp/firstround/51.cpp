#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n);

private:
    void recur(vector<string>& array, int row);
    vector<vector<string>> result;
    vector<string> path;
};

vector<vector<string>> Solution::solveNQueens(int n) {
    if(n<1) return {};
    else if(n==1)
    {
        vector<string> tmp = {"Q"};
        result.emplace_back(tmp);
        return result;
    }

    vector<string> array(n, string(n, '.'));
    recur(array, 0);
    return result;
}

void Solution::recur(vector<string>& array, int row)
{
    if(path.size()==array.size())
    {
        result.emplace_back(path);
        return;
    }

    
    for(int i=0; i<array[0].size(); i++)  //i表示第row行第i列
    {
        bool hasQueen = false;
        for(int j=0; j<row; j++)  //判断同一纵行是否已有皇后
        {
            if(array[j][i]=='Q')
            {
                hasQueen=true;
                break;
            }
        }
        if(hasQueen) continue;

        for(int j=row-1, k=i-1; j>=0 && k>=0; j--, k--)  //判断左斜线的前面是否已有皇后
        {
            if(array[j][k]=='Q')
            {
                hasQueen=true;
                break;
            }
        }
        if(hasQueen) continue;

        for(int j=row-1, k=i+1; j>=0 && k<array[0].size(); j--, k++)  //判断右斜线的前面是否已有皇后
        {
            if(array[j][k]=='Q')
            {
                hasQueen=true;
                break;
            }
        }
        if(hasQueen) continue;

        array[row][i] = 'Q';
        path.emplace_back(array[row]);
        
        recur(array, row+1);

        array[row][i] = '.';
        path.pop_back();
    }
    return;
}