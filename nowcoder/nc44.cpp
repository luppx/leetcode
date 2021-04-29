#include <string>
#include <vector>
using namespace std;


// //回溯。超时
// class Solution
// {
// public:
//     bool isMatch(string s, string p);

// private:
//     void match(string s, string p, int s_idx, int p_idx);
//     bool matched;
//     int s_len;
//     int p_len;
// };

// bool Solution::isMatch(string s, string p)
// {
//     if(p.empty()) return s.empty(); //正则表达式为空时，如果s也为空，则可以匹配，否则无法匹配
//     matched = false;
//     s_len = s.size();
//     p_len = p.size();
//     match(s, p, 0, 0);
//     return matched;
// }

// void Solution::match(string s, string p, int s_idx, int p_idx)
// {
//     if(matched) return;

//     if(p_idx==p_len)  //正则表达式遍历完了
//     {
//         if(s_idx==s_len) matched = true;  //如果字符串也遍历完了，则可以匹配           
//         return ;
//     }

//     else if(p[p_idx]=='*')
//     {
//         for (int i = 0; i<=s_len-s_idx; i++)
//         {
//             match(s, p, s_idx+i, p_idx+1);
//         }
//     }
//     else if(p[p_idx]=='?')  //"?"可以匹配0个或1个字符
//     {
//         match(s, p, s_idx, p_idx+1); //匹配0个字符
//         match(s, p, s_idx+1, p_idx+1); //匹配1个字符
//     }
//     else if(s_idx<s_len && s[s_idx]==p[p_idx])
//     {
//         match(s, p, s_idx+1, p_idx+1);
//     }

//     return ;
// }

//DP。时间复杂度O(M*N)，空间复杂度O(M*N)
class Solution
{
public:
    bool isMatch(string s, string p);

};

bool Solution::isMatch(string s, string p)
{
    if(p.empty()) return s.empty(); //正则表达式为空时，如果s也为空，则可以匹配，否则无法匹配

    int m = s.size();
    int n = p.size();
    vector<vector<bool>> dp(m+1, vector<bool>(n+1,false));  //dp[i][j]表示s的前i个字符与p的前j个字符是否匹配

    dp[0][0] = true;
    for(int i=1; i<=n; i++)
    {
        if(p[i-1]=='*')
        {
            dp[0][i] = true;
        }
        else break;
    }

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j] = dp[i-1][j-1];  //如果s[i-1]与p[j-1]匹配
            else if(p[j-1]=='*')  //'*'可匹配任意多个任意字符
            {
                dp[i][j] = dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1];
            }

        }
    }

    return dp[m][n];
}

int main()
{
    string s = "";
    string p = "*";
    Solution obj;
    bool result = obj.isMatch(s,p);
    return 0;
}