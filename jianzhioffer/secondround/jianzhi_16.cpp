//方法一，循环求幂法，时间复杂度O(N)，空间复杂度O(1)，leetcode会超时
// class Solution {
// public:
//     double myPow(double x, int n) {
//         if(x==0) return 0;
//         else if(n==0) return 1;
//         int tmp = 0;
//         int negative = 0;
//         if(n<0)
//         {
//             tmp = -n;
//             negative = 1;
//         }
//         else
//             tmp = n;
//         double pow = 1;
//         while (tmp>0)
//         {
//             pow *= x;
//             tmp--;
//         }
//         if(negative)
//             pow = 1.0 / pow;
//         return pow;
//     }
// };

//方法二，快速求幂法(利用了二分思想)，时间复杂度O(log2N)，空间复杂度O(1)
class Solution {
public:
    double myPow(double x, int n) {
        if(x==0) return 0;
        else if(n==0 || x==1) return 1;
        long num = n; // n取左边界时，用int变量存储他的绝对值会超出int的存储右边界导致报错，因此用long变量存储
        if(n<0)
        {
            x = 1/x;
            num = -num;
        }
        double res = 1;
        while (num)
        {
            if(num&1)
                res *= x;
            x *= x;
            num >>= 1;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution obj;
    double result = obj.myPow(2.10000, 3);
    return 0;
}
