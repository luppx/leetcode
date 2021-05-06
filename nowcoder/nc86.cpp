#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findElement(vector<vector<int>>& mat, int n, int m, int x);
};

//线性查找。时间复杂度O(M+N)，空间复杂度O(1)
vector<int> Solution::findElement(vector<vector<int>>& mat, int n, int m, int x)
{
    if(n==0 && m==0) return {};
    int i=0, j=m-1;
    while (i<n && j>=0)
    {
        if(mat[i][j]>x)
        {
            j--;
        }
        else if(mat[i][j]<x)
        {
            i++;
        }
        else return {i,j};
    }
    return {};
}

int main()
{
    // vector<vector<int>> mat = {
    //     {1,2,3},
    //     {4,5,6},
    //     {7,8,9}
    // };
    vector<vector<int>> mat = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    Solution obj;
    vector<int> result = obj.findElement(mat, mat.size(), mat[0].size(), 5);
    return 0;
}