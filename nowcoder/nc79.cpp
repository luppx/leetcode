#include <vector>
using namespace std;

class Solution
{
public:
    int GetUglyNumber_Solution(int index);
};

int Solution::GetUglyNumber_Solution(int index)
{
    if(index<1) return 0;
    else if(index==1) return 1;

    vector<int> dp(index+1, 0);
    dp[1] = 1;
    int p2=1, p3=1, p5=1;
    for (int i = 2; i <= index; i++)
    {
        int n2 = dp[p2]*2;
        int n3 = dp[p3]*3;
        int n5 = dp[p5]*5;
        dp[i] = min(n2, min(n3, n5));
        if(dp[i]==n2) p2++;
        if(dp[i]==n3) p3++;
        if(dp[i]==n5) p5++;
    }
    return dp[index];
}

int main()
{
    int index = 11;
    Solution obj;
    int result = obj.GetUglyNumber_Solution(index);
    return 0;
}