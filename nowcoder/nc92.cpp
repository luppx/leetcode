#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string LCS(string str1, string str2);
};

string Solution::LCS(string str1, string str2)
{
    if(str1.empty() || str2.empty()) return "-1";

    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1,0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    string res = "";
    for (int i=m, j=n; i>=0 && j>=0 && dp[i][j]>=1;)
    {
        if(str1[i-1]==str2[j-1])
        {
            res.push_back(str1[i-1]);
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>=dp[i][j-1]) i--;
            else j--;
        }
    }
    
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string str1 = "1AB2345CD";
    string str2 = "12345EF";
    Solution obj;
    string result = obj.LCS(str1, str2);
    printf(&result[0]);
    return 0;
}