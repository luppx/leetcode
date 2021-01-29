//动态规划的优化，只需要记录3个值dp[i-2]、dp[i-1]、dp[i]的值，再前面的值都无关了,
//可以进一步优化空间复杂度。时间复杂度O(N),空间复杂度O(1)，leetcode能达到双百。
class Solution {
public:
    int numWays(int n) {
        if (n==0 || n==1) return 1;
        else if (n==2) return 2;
        int a = 1;
        int b = 2;
        int sum = 0;
        for (int i = 3; i <= n; i++)
        {
            sum = (a+b) % 1000000007;
            a = b;
            b = sum;
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    Solution obj;
    int result = obj.numWays(7);
    return 0;
}

