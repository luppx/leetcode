#include <vector>
using namespace std;

class Solution
{
public:
    Solution();
    ~Solution();
    int nthUglyNumber(int n);
};

Solution::Solution()
{

}

Solution::~Solution()
{

}


// //暴力解法，从小到大依次判断每个数是否为丑数，直到找到第n个丑数。
// //leetcode超时
// int Solution::nthUglyNumber(int n)
// {
//     if(n<=0) return 0;
//     vector<int> uglyNumbers = {1,2,3,4,5,6,8,9,10,12};
//     if(n<=10) return uglyNumbers[n-1];
    
//     for (int i = 13; uglyNumbers.size() < n; i++)
//     {
//         int j = i;
//         bool isugly = true;
//         while (j>5)
//         {
//             if(j%2==0)
//             {
//                 j /= 2;
//             }
//             else if(j%3==0)
//             {
//                 j /= 3;
//             }
//             else if(j%5==0)
//             {
//                 j /= 5;
//             }
//             else
//             {
//                 isugly = false;
//                 break;
//             }
//         }
//         if(isugly) uglyNumbers.push_back(i);
//     }
//     return uglyNumbers.back();
// }

//动态规划。时间复杂度O(N)，空间复杂度O(N)
//设dp[i]表示第i个丑数。dp[i]={dp[a]*2, dp[b]*3, dp[c]*5}这3种情况中的一种。
//dp[i]是距离dp[i-1]最近的丑数，所以dp[i]=min(dp[a]*2, dp[b]*3, dp[c]*5)，且dp[a]*2是首个乘以2后大于dp[i-1]的整数，dp[b]*3是首个乘以3后大于dp[i-1]的整数，dp[c]*5是首个乘以5后大于dp[i-1]的整数
//可设立3个指针a,b,c，分别指向dp[i-1]前满足乘2、乘3、乘5为首个大于dp[i-1]的数字这一条件的元素位置
int Solution::nthUglyNumber(int n)
{
    if(n<=0) return 0;
    int a=0, b=0, c=0;
    int dp[n];
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int n2 = dp[a]*2;
        int n3 = dp[b]*3;
        int n5 = dp[c]*5;
        dp[i] = min(min(n2,n3), n5);
        if(dp[i]==n2) a++;
        if(dp[i]==n3) b++;
        if(dp[i]==n5) c++;
    }
    return dp[n-1];
}

int main(int argc, char const *argv[])
{
    Solution obj;
    int result = obj.nthUglyNumber(11);
    return 0;
}

