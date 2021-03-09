#include <string>
#include <cmath>
using namespace std;

//将0-n分别加入到字符串中，然后返回str[n]，时间复杂度O(N)，空间复杂度O(N)
//会超时，需要找出数字n和str[n]之间的规律
// class Solution
// {
// public:
//     Solution();
//     ~Solution();
//     int findNthDigit(int);
// };

// Solution::Solution()
// {

// }

// Solution::~Solution()
// {

// }

// int Solution::findNthDigit(int n)
// {
//     string str="";
//     for (int i = 0; i <= n; i++)
//     {
//         str += to_string(i);
//     }
//     return str[n]-'0';
// }

//找规律。时间复杂度O(logN)(第一步的循环只用循环N的位数的次数，如N=1000，只用循环3次，故第一步时间复杂度O(logN)，第三步num转string时间复杂度O(logN)，故总时间复杂度O(logN))
//空间复杂度O(logN)(第三步num转string占用O(logN)的空间)
class Solution
{
public:
    Solution();
    ~Solution();
    int findNthDigit(int);
};

Solution::Solution()
{

}

Solution::~Solution()
{

}

int Solution::findNthDigit(int n)
{
    //1.先确定str[n]对应的数字的位数
    long count=9;
    int digit=1;
    long start=1;
    while (n>count)
    {
        n -= count;
        start *= 10;
        digit++;
        count = 9*start*digit;
    }
    
    //2.确定str[n]对应的数字num
    int num = start+ (n-1)/digit;

    //3.确定n对应的是num的哪一位，即要返回num哪一位上的数
    string str = to_string(num);
    int res = str[(n-1)%digit] - '0';
    return res;
}

int main(int argc, char const *argv[])
{
    Solution obj;
    int result = obj.findNthDigit(1000000000);
    return 0;
}
