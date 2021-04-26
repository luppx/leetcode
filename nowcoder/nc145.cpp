#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int knapsack(int V, int n, vector<vector<int> >& vw);
};

int Solution::knapsack(int V, int n, vector<vector<int> >& vw)
{
    if(V<0 || n<1 || vw.empty() || vw.size()!=n) return 0;

    vector<vector<int>> dp(n+1, vector<int>(V+1,0));
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            if(j<vw[i-1][0]) dp[i][j] = dp[i-1][j];
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-vw[i-1][0]] + vw[i-1][1]);
            }
        }
    }
    return dp[n][V];
}

int main()
{
    vector<vector<int>> vw = {{1,3},{10,4}};
    int V = 10;
    int n = vw.size();
    Solution obj;
    int result = obj.knapsack(V,n,vw);
    return 0;
}