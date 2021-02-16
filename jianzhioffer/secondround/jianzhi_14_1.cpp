#include <vector>
#include <cmath>
using namespace std;

// //动态规划，时间复杂度O(N^2)，空间复杂度O(N)
// class Solution {
// public:
//     int cuttingRope(int n) {
//         if(n==2) return 1;
//         else if(n==3) return 2;
//         vector<int> dp(n+1,0);
//         dp[2] = 1;
//         dp[3] = 2;
//         //dp[i]表示长度为i的绳子分解成若干段后的最大乘积
//         for (int i = 4; i <= n; i++)
//         {
//             for (int j = 1; j < i; j++) //绳子分成长度为j和i-j，再分别分成更短的若干段
//             {
//                 dp[i] = max(dp[i], max(j*dp[i-j], (i-j)*j));
//             }
            
//         }
//         return dp[n];
//     }
// };

//贪心法、数学方法。这两种方法代码都是一样的，时间复杂度O(1)，空间复杂度O(1)
//具体证明见题解https://leetcode-cn.com/problems/jian-sheng-zi-lcof/solution/mian-shi-ti-14-i-jian-sheng-zi-tan-xin-si-xiang-by/
class Solution {
public:
    int cuttingRope(int n) {
        if(n==2) return 1;
        else if(n==3) return 2;
        int a,b;
        a = n / 3;
        b = n % 3;
        if(b==0) return (int)pow(3,a);
        else if(b==1) return (int)pow(3,a-1)*4;
        else return (int)pow(3,a)*2;
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution obj;
    int result = obj.cuttingRope(10);
    return 0;
}
