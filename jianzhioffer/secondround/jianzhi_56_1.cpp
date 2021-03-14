#include <cstddef>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> singleNumbers(vector<int>& nums);
};

vector<int> Solution::singleNumbers(vector<int>& nums)
{
    if(nums.empty()) return vector<int> {};
    int k = 0;
    for(int num:nums)
    {
        k ^= num;
    }

    int mask = 1;
    while((mask&k)==0) //==的优先级比&高，因此必须要加括号
    {
        mask <<=1;
    }

    int a=0, b=0;
    for(int num:nums)
    {
        if(num&mask) a ^= num;
        else b ^= num;
    }
    return vector<int>{a,b};
}

int main(int argc, char const *argv[])
{
    vector<int> nums{1,2,10,4,1,4,3,3};
    Solution obj;
    vector<int> result = obj.singelNumbers(nums);
    return 0;
}

