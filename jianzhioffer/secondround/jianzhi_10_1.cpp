# include <vector>
using namespace std;

// //方法一：递归，但存在大量重复计算，会超时
// class Solution {
// public:
//     int fib(int n) {
//         if (n==0)
//         {
//             return 0;
//         }
//         else if (n==1)
//         {
//             return 1;
//         }
//         return fib(n-1) + fib(n-2);
//     }
// };


// //方法二，建立辅助数组，记录n取不同值时的fib(n)(其实就是动态规划)
// //注意：计算到后面值会很大，超过int、long的取值范围，所以每次计算都取模。
// //时间复杂度O(N)，空间复杂度O(N)(leetcode结果，运行0ms，100%；内存5.9MB，85%)
// class Solution {
// public:
//     int fib(int n) {
//         if(n==0) return 0;
//         else if(n==1) return 1;
//         vector<int> dp;
//         dp.push_back(0);
//         dp.push_back(1);
//         for (int i = 2; i <= n; i++)
//         {
//             dp.push_back((dp[i-2]+dp[i-1]) % 1000000007);
//         }
//         return dp.back();
//     }
// };

//方法三，针对方法二动态规划的优化，只需要记录3个值dp[i-2]、dp[i-1]、dp[i]的值，再前面的值都无关了,
//可以进一步优化空间复杂度。时间复杂度O(N),空间复杂度O(1)，leetcode能达到双百。
class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        else if(n==1) return 1;
        int a = 0;
        int b = 1;
        int sum = 0;
        for (int i = 2; i <= n; i++)
        {
            sum = (a + b) % 1000000007;
            a = b;
            b = sum;
        }
        return sum;
    }
};


int main(int argc, char const *argv[])
{
    Solution obj;
    int result = obj.fib(5);
    return 0;
}
