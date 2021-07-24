#include <iostream>
#include <string>
#include <vector>
using namespace std;

//方法一，回溯
// class Solution
// {
// public:
//     int numDistinct(string& s, string& t);

// private:
//     void dfs(string&s, string&t, int s_idx, int t_idx);
//     int t_size;
//     int s_size;
//     int res;
// };

// int Solution::numDistinct(string& s, string& t)
// {
//     t_size = t.size();
//     s_size = s.size();
//     res = 0;
//     dfs(s, t, 0, 0);
//     return res;
// }

// void Solution::dfs(string&s, string&t, int s_idx, int t_idx)
// {
//     if (t_idx==t_size)
//     {
//         res++;
//         return;
//     }
    
//     for (int i = s_idx; i < s_size; i++)
//     {
//         if(s[i]==t[t_idx])
//         {
//             dfs(s, t, i+1, t_idx+1);
//         }
//     }
//     return;
// }

//方法二，动态规划。定义一个二维数组，表示以s[0:i-1]中出现的t[0:j-1]的次数。
//时间复杂度O(M*N)，空间复杂度O(M*N)
class Solution
{
public:
    int numDistinct(string& s, string& t);
};

int Solution::numDistinct(string& s, string& t)
{
    int s_size = s.size();
    int t_size = t.size();
    vector<vector<uint64_t>> dp(s_size+1, vector<uint64_t>(t_size+1, 0));

    for(int i=0; i<=s_size; i++)
    {
        dp[i][0]=1;
    }

    for (int i = 1; i <= s_size; i++)
    {
        for (int j = 1; j <= min(i, t_size); j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else dp[i][j] = dp[i-1][j];
        }        
    }
    return dp[s_size][t_size];
}

int main() {
    string s =  "babgbag";
    string t = "bag";
    Solution obj;
    int result = obj.numDistinct(s, t);
    cout << result << endl;
}