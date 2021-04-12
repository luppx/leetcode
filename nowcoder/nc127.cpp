#include <vector>
#include <string>
#include <cstdlib>
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
    int maxlen = 0;
    int end = 0;
    //dp[i][j]表示以str1[i-1]和str2[j-1]结尾的最长公共子串
    vector<vector<int>> dp(m+1, vector<int>(n+1,0));


    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
                maxlen = max(maxlen, dp[i][j]);
                end = i-1;
            }
            else dp[i][j] = 0;
        }    
    }
    
    string res = str1.substr(end-maxlen+1, maxlen);
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
