#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix);
};

vector<int> Solution::spiralOrder(vector<vector<int> > &matrix)
{
    if(matrix.empty()) return {};
    int up_bound = -1, down_bound = matrix.size();
    int left_bound = -1, right_bound = matrix[0].size();
    int i=0, j=0;

    vector<int> res = {};
    while (up_bound+1!=down_bound && left_bound+1!=right_bound)
    {
        if(i==up_bound+1 && j==left_bound+1)
        {
            while (j<right_bound)
            {
                res.push_back(matrix[i][j++]);
            }
            i++;
            j--;
            up_bound++;
        }
        else if(i==up_bound+1 && j==right_bound-1)
        {
            while (i<down_bound)
            {
                res.push_back(matrix[i++][j]);
            }
            i--;
            j--;
            right_bound--;
        }
        else if(i==down_bound-1 && j==right_bound-1)
        {
            while (j>left_bound)
            {
                res.push_back(matrix[i][j--]);
            }
            i--;
            j++;
            down_bound--;
        }
        else if(i==down_bound-1 && j==left_bound+1)
        {
            while (i>up_bound)
            {
                res.push_back(matrix[i--][j]);
            }
            i++;
            j++;
            left_bound++;
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    // vector<vector<int>> matrix = {
    // {1,2},
    // {3,4}
    // };
    Solution obj;
    vector<int> result = obj.spiralOrder(matrix);
    return 0;
}