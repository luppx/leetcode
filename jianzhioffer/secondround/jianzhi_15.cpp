#include <cstdint>
using namespace std;

// //方法一，移位运算，时间复杂度O(log2N)，空间复杂度O(1)
// //逐位判断需循环 log2 n次，其中 log2 n代表数字n最高位1的所在位数（例如 log2 4=2, log2 16=4）
// class Solution {
// public:
//     int hammingWeight(uint32_t n) {
//         int res=0;
        
//         while (n)
//         {
//             res += n&1;
//             n >>= 1;
//         }
//         return res;
//     }
// };

//方法二：n&(n-1)，时间复杂度O(M)(M为二进制串中1的个数)，空间复杂度O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res=0;
        while (n)
        {
            res++;
            n &= (n-1);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution obj;
    uint32_t num = 001011;
    int result = obj.hammingWeight(num);
    return 0;
}
