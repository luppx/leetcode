#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n);
};

// vector<vector<int>> Solution::generateMatrix(int n)
// {
//     if(n<1) return {};

//     vector<vector<int>> res(n, vector<int>(n,0));
//     int i=0, j=0;
//     int num=1;
//     int upperbound=0, downbound=n-1;
//     int leftbound=0, rightbound=n-1;
//     while (upperbound<=downbound && leftbound<=rightbound)
//     {
//         if(i==upperbound && j==leftbound)
//         {
//             while (j<=rightbound)
//             {
//                 res[i][j] = num;
//                 j++;
//                 num++;
//             }
//             i++;
//             j--;
//             upperbound++;
//         }
//         else if(i==upperbound && j==rightbound)
//         {
//             while (i<=downbound)
//             {
//                 res[i][j] = num;
//                 i++;
//                 num++;
//             }
//             i--;
//             j--;
//             rightbound--;
//         }
//         else if(i==downbound && j==rightbound)
//         {
//             while (j>=leftbound)
//             {
//                 res[i][j] = num;
//                 j--;
//                 num++;
//             }
//             i--;
//             j++;
//             downbound--;
//         }
//         else if(i==downbound && j==leftbound)
//         {
//             while (i>=upperbound)
//             {
//                 res[i][j] = num;
//                 i--;
//                 num++;
//             }
//             i++;
//             j++;
//             leftbound++;
//         }
//     }
//     return res;
// }

vector<vector<int>> Solution::generateMatrix(int n)
{
    if(n<1) return {};

    vector<vector<int>> res(n, vector<int>(n,0));

    int startx=0, starty=0;
    int loop= n/2;
    int mid = n/2;  //如果是奇数，最中间的那个位置放到最后判断
    int offset = 1;
    int num=1;

    while (loop--)
    {
        int i=startx, j=starty;

        for(; j<startx+n-offset; j++)
        {
            res[i][j] = num++;
        }

        for(; i<starty+n-offset; i++)
        {
            res[i][j] = num++;
        }

        for(; j>startx; j--)
        {
            res[i][j] = num++;
        }

        for(; i>starty; i--)
        {
            res[i][j] = num++;
        }

        startx++;
        starty++;
        offset += 2;
    }

    if(n&1) res[mid][mid] = num;
    return res;
}

int main()
{
    int n;
    cout<<"input n: ";
    cin>>n;
    Solution obj;
    vector<vector<int>> result = obj.generateMatrix(n);
    return 0;
}