#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string& text1, string& text2);
};

//二维dp，时间复杂度、空间复杂度均为O(MN)
// int Solution::longestCommonSubsequence(string& text1, string& text2)
// {
//     if(text1.empty() || text2.empty()) return 0;

//     int m = text1.size();
//     int n = text2.size();
//     vector<vector<int>> dp(m+1, vector<int>(n+1, 0));  //dp[i][j]表示以text1[i-1]、text2[j-1]结尾的最长公共子序列

//     for (int i = 1; i <= m; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             if(text1[i-1]==text2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
//             else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//         }
//     }
//     return dp[m][n];
// }

//优化，一维dp，计算dp[i][j]时，只需用到dp[i-1][j-1]、dp[i-1][j]、dp[i][j-1]，所以只要记录相应的数据就可以
//把二维数组压缩成一维了
int Solution::longestCommonSubsequence(string& text1, string& text2)
{
    if(text1.empty() || text2.empty()) return 0;

    int m = text1.size();
    int n = text2.size();
    vector<int> dp(n+1,0);

    for (int i = 1; i <= m; i++)
    {
        int upLeft = dp[0];
        for (int j = 1; j <= n; j++)
        {
            int tmpVal = dp[j];
            if(text1[i-1]==text2[j-1]) dp[j] = upLeft+1;
            else dp[j] = max(dp[j], dp[j-1]);
            upLeft = tmpVal;
        }
    }
    return dp.back();
}