#include <vector>
using namespace std;

class Solution
{
public:
    Solution();
    ~Solution();
    int maxValue(vector<vector<int>> grid);
};

Solution::Solution()
{

}

Solution::~Solution()
{

}

//DP。时间复杂度O(M*N)，空间复杂度O(1)
int Solution::maxValue(vector<vector<int>> grid)
{
    if(grid.empty() || grid[0].empty()) return 0;

    int rows = grid.size();
    int cols = grid[0].size();
    for (int i=0; i < rows; i++)
    {
        for (int j=0; j < cols; j++)
        {
            if(i>0 && j>0) grid[i][j] += max(grid[i-1][j], grid[i][j-1]);
            else if(i>0) grid[i][j] += grid[i-1][j];
            else if(j>0) grid[i][j] += grid[i][j-1];
        }
        
    }
    return grid[rows-1][cols-1];
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    Solution obj;
    int result = obj.maxValue(grid);
    return 0;
}
