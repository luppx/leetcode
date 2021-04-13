#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int solve(vector<vector<char>>& grid);

private:
    void DFS(vector<vector<char>>& grid, int i, int j);
    int num;
};

// //BFS
// int Solution::solve(vector<vector<char>>& grid)
// {
//     if(grid.empty() || grid[0].empty()) return 0;
//     num = 0;
//     queue<pair<int,int>> q;

//     for (int i = 0; i < grid.size(); i++)
//     {
//         for (int j = 0; j < grid[0].size(); j++)
//         {
//             if(grid[i][j]=='1')
//             {
//                 grid[i][j]=0;
//                 q.push(pair<int,int>(i,j));
//                 while (!q.empty())
//                 {
//                     pair<int,int> tmp = q.front();
//                     q.pop();
//                     int r = tmp.first;
//                     int c = tmp.second;
//                     if(r>0 && grid[r-1][c]=='1')
//                     {
//                         q.push(pair<int,int>(r-1,c));
//                         grid[r-1][c]=0;
//                     }
//                     if(r<grid.size()-1 && grid[r+1][c]=='1')
//                     {
//                         q.push(pair<int,int>(r+1,c));
//                         grid[r+1][c]=0;
//                     }
//                     if(c>0 && grid[r][c-1]=='1')
//                     {
//                         q.push(pair<int,int>(r,c-1));
//                         grid[r][c-1]=0;
//                     }
//                     if(c<grid[0].size()-1 && grid[r][c+1]=='1')
//                     {
//                         q.push(pair<int,int>(r,c+1));
//                         grid[r][c+1]=0;
//                     }
//                 }
//                 num++;
//             }
            
//         }
        
//     }
//     return num;
// }

//DFS
int Solution::solve(vector<vector<char>>& grid)
{
    if(grid.empty() || grid[0].empty()) return 0;
    num = 0;
    queue<pair<int,int>> q;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if(grid[i][j]=='1')
            {
                DFS(grid, i, j);
                num++;
            }   
        }
    }
    return num;
}

void Solution::DFS(vector<vector<char>>& grid, int i, int j)
{
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!='1') return;

    grid[i][j] = 0;
    DFS(grid, i-1, j);
    DFS(grid, i+1, j);
    DFS(grid, i, j-1);
    DFS(grid, i, j+1);
    return ;
}

int main()
{
    vector<vector<char>> v = {
        {'1','1',0,0,0},
        {0,'1',0,'1','1'},
        {0,0,0,'1','1'},
        {0,0,0,0,0},
        {0,0,'1','1','1'}
    };
    Solution obj;
    int result = obj.solve(v);
    return 0;
}