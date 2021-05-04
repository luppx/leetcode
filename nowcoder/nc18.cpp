#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> rotateMatrix(vector<vector<int>>& mat, int n);
};

vector<vector<int>> Solution::rotateMatrix(vector<vector<int>>& mat, int n)
{
    if(n<2) return mat;

    vector<vector<int>> res(n, vector<int>(n,0));
    for (int j = 0; j < n; j++)
    {
        int i = 0;
        int k = n-1-j;
        for (int v = 0; v < n; v++)
        {
            res[i][j] = mat[k][v];
            i++;
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> mat = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
        };
    
    Solution obj;
    vector<vector<int>> result = obj.rotateMatrix(mat, mat.size());
    return 0;
}