#include <cstddef>
#include <vector>
using namespace std;

//时间复杂度O(MN)，空间复杂度O(MN)(结果返回一个数组，算法本身的空间复杂度是O(1))
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()) return res;
        int left_bound = 0;
        int right_bound = matrix[0].size()-1;
        int top_bound = 0;
        int bottom_bound = matrix.size()-1;
        while (true)
        {
            for(int i=left_bound; i<=right_bound;i++)
                res.push_back(matrix[top_bound][i]);
            top_bound++;
            if(top_bound>bottom_bound) break;

            for(int i=top_bound; i<=bottom_bound; i++)
                res.push_back(matrix[i][right_bound]);
            right_bound--;
            if(right_bound<left_bound) break;

            for(int i=right_bound; i>=left_bound; i--)
                res.push_back(matrix[bottom_bound][i]);
            bottom_bound--;
            if(bottom_bound<top_bound) break;

            for(int i=bottom_bound; i>=top_bound; i--)
                res.push_back(matrix[i][left_bound]);
            left_bound++;
            if(left_bound>right_bound) break;
        }
        return res;
        
    }
};

int main()
{
    vector<vector<int>> matrix(5, vector<int>(5));
    matrix = {
  {1,   2,  3, 4,5},
  {6,   7,  8, 9,10},
  {11, 12, 13,14,15},
  {16, 17, 18,19,20},
  {21, 22, 23,24,25}};
    Solution obj;
    vector<int> result = obj.spiralOrder(matrix);
    return 0;
}