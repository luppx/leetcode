#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minEditCost(string& str1, string& str2, int ic, int dc, int rc);
};

int Solution::minEditCost(string& str1, string& str2, int ic, int dc, int rc)
{
    if(str2.empty()) return (int)str1.size()*dc;

    int m = str1.size();
    int n = str2.size();
    
    //dp[i][j]表示以str1前i个字符转换为str2前j个字符所需花费的代价
    int dp[m+1][n+1];

    for (int i = 0; i < m; i++)
    {
        dp[i][0] = i*dc;
    }
    
    for (int i = 0; i < n; i++)
    {
        dp[0][i] = i*ic;
    }
    
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            //如果相等，则不用编辑
            if(str1[i]==str2[j]) dp[i][j] = dp[i-1][j-1];
            else
            {
                //如果不等，考虑插入、删除、替换操作的最小代价
                int insert = dp[i][j-1] + ic;
                int del = dp[i-1][j] + dc;
                int replace = dp[i-1][j-1] + rc;
                dp[i][j] = min(insert, min(del, replace));
            }
            
        }
    }
    
    return dp[m][n];
}

int main()
{
    return 0;
}