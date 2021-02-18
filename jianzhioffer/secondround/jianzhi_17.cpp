#include <vector>
#include <cmath>
#include <string>
using namespace std;


//按序从小到大打印。因为题目返回int型数组，说明默认测试用例不会超过int存储范围，故不用考虑大数问题。
//时间复杂度O(10^N)，空间复杂度O(1)
// class Solution {
// public:
//     vector<int> printNumbers(int n) {
//         vector<int> res;
//         if(n<=0) return res;
//         for (int i = 1; i < pow(10,n); i++)
//         {
//             res.push_back(i);
//         }
//         return res;
//     }
// };

//方法二，考虑大数问题，递归，从高位到低位，一位一位固定
//时间复杂度O(10^N)，空间复杂度O(10^N)
class Solution {
public:
    vector<int> printNumbers(int n) {
        if(n<=0) return res;
        num = n;
        dfs(0);
        return res;
    }

    void dfs(int pos)
    {
        if(pos==num)
        {
            if(strs!="")
            {
                res.push_back(stoi(strs));
            }
            return;
        }
        for (int i = 0; i <= 9; i++)
        {
            if(strs!="" || (strs=="" && i!=0))
                strs += to_string(i);
            dfs(pos+1);
            strs = strs.substr(0, strs.size()-1);
        }
        
    }

private:
    vector<int> res;
    int num;
    string strs;
};

int main(int argc, char const *argv[])
{
    Solution obj;
    vector<int> result = obj.printNumbers(2);
    return 0;
}
