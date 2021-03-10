#include <iostream>
#include <string>
using namespace std;

// //回溯法
// class Solution
// {
// public:
//     Solution();
//     ~Solution();
//     int translateNum(int num);

// private:
//     int count;
//     void DFS(string& str, int begin, int end);
// };

// Solution::Solution():count(0)
// {
//     cout<<"Construct object"<<endl;
// }

// Solution::~Solution()
// {
//     cout<<"Destruct object"<<endl;
// }

// int Solution::translateNum(int num)
// {
//     if(num>=0 && num<=9) return 1;
//     string str = to_string(num);
//     DFS(str, 0, 0);
//     return count;
// }

// void Solution::DFS(string& str, int begin, int end)
// {
//     if(end>=str.size()) return;
//     string tmp = str.substr(begin, end-begin+1);
//     int tmp_num = stoi(tmp);
//     if(tmp_num>=0 && tmp_num<=25)
//     {
//         if(end==str.size()-1)
//         {
//             count++;
//             return ;
//         }
//         else
//         {
//             //tmp_num>0:如果数值为0，则不能将它往下组成两位数，比如01不能看作是1，不属于题目的翻译规则
//             //tmp_num<10:如果数值已经是两位数了，就不用再继续增加位数了，因为再增加位数就变成三位数，肯定大于25
//             if(tmp_num>0 && tmp_num<10) DFS(str, begin, end+1);
//             DFS(str, end+1, end+1);
//         }
//     }
//     return ;
// }

//DP。
//时间复杂度O(logN)，DP循环的次数是N的位数，即logN次
//空间复杂度O(logN)，这里使用滚动数组，空间复杂度是O(1)，但使用了string变量存储由数字转换为字符串的结果，占用O(logN)空间，故空间复杂度是O(logN)
class Solution
{
public:
    Solution();
    ~Solution();
    int translateNum(int num);
};

Solution::Solution()
{

}

Solution::~Solution()
{

}

//dp[i]= dp[i-1]+dp[i-2]
//(如果第i位单独翻译，则方案为dp[i-1]；如果第i位和第i-1位连在一起翻译，假设形成的数字为x，则需10<=x<=25，方案数为dp[i-2])
int Solution::translateNum(int num)
{
    if(num>=0 && num<=9) return 1;
    string str = to_string(num);
    int pprev = 1, prev = 1, cur = 0;
    for(int i=1; i<str.size(); i++)
    {
        cur = 0;
        string substr = str.substr(i-1, 2);
        cur += prev;
        if(substr>="10" && substr<="25")
        {
            cur += pprev;
        }
        
        pprev = prev;
        prev = cur;
    }
    return cur;
}

int main(int argc, char const *argv[])
{
    Solution obj;
    int result = obj.translateNum(12258);
    return 0;
}
