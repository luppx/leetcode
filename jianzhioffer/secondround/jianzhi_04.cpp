# include <vector>
using namespace std;


//方法一：暴力法。时间复杂度O(m*n)(m行n列)，空间复杂度O(1)
// class Solution {
// public:
//     bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
//         if (matrix.empty())
//         {
//             return false;
//         }
//         int row = matrix.size();
//         int col = matrix[0].size();
//         for (int i = 0; i < row; i++)
//         {
//             for (int j = 0; j < col; j++)
//             {
//                 if (matrix[i][j] == target)
//                 {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };


//方法二：线性查找法，从题目描述，每行从左到右递增，每列从上到下递增，因此可从右上角开始查找，
//如果num==target，则返回true；如果num>target则往左一列；如果num<target则往下一行(或从左下角开始查找也可以)
//时间复杂度O(m+n)(m行n列)，空间复杂度O(1)
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
        {
            return false;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        int i = 0;
        int j = col-1;
        while (i<row and j>=0)
        {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] > target) j--;
            else i++;     
        }
        return false;
    }
};


int main()
{
    vector<vector<int>> nums(5, vector<int>(5));
    nums = {
  {1,   4,  7, 11, 15},
  {2,   5,  8, 12, 19},
  {3,   6,  9, 16, 22},
  {10, 13, 14, 17, 24},
  {18, 21, 23, 26, 30}};
    Solution obj;
    bool result = obj.findNumberIn2DArray(nums, 5);
    return 0;
}