#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix);
};

vector<int> Solution::spiralOrder(vector<vector<int>>& matrix)
{
    if(matrix.empty() || matrix[0].empty()) return {};
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> res={};
    int i=0, j=0;
    int leftbound=0, rightbound=n-1;
    int upperbound=0, downbound=m-1;
    while (upperbound<=downbound && leftbound<=rightbound)
    {
        for(; j<=rightbound; j++)
        {
            res.push_back(matrix[i][j]);
        }
        i++;
        j--;

        for(; i<=downbound; i++)
        {
            res.push_back(matrix[i][j]);
        }
        i--;
        j--;

        if(leftbound<rightbound && upperbound<downbound)
        {
            for(; j>leftbound; j--)
            {
                res.push_back(matrix[i][j]);
            }

            for(; i>upperbound; i--)
            {
                res.push_back(matrix[i][j]);
            }
        }

        upperbound++;
        downbound--;
        leftbound++;
        rightbound--;

        i++;
        j++;
    }
    return res;
}

int main()
{
    // vector<vector<int>> matrix = {
    //     {1,2,3,4},
    //     {5,6,7,8},
    //     {9,10,11,12}
    // };
    vector<vector<int>> matrix = {
        {1}
    };

    Solution obj;
    vector<int> result =obj.spiralOrder(matrix);
    return 0;
}