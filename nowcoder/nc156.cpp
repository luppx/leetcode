#include <vector>
#include <unordered_map>
#include <array>
using namespace std;

class Solution
{
public:
    int foundOnceNumber(vector<int>& nums, int k);
};

//方法一，用哈希表存储各数字出现的次数然后遍历哈希表。时间复杂度O(N)，空间复杂度O(N/K+1)=O(N)
// int Solution::foundOnceNumber(vector<int>& nums, int k)
// {
//     if(nums.empty() || k<0) return -1;

//     unordered_map<int,int> m;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         m[nums[i]]++;
//     }
    
//     for (auto it = m.begin(); it != m.end(); it++)
//     {
//         if(it->second==1) return it->first;
//     }
//     return -1;
// }

//方法二，位运算。每个出现k次的数字，它的二进制的每一位也出现k次，所以可以记录所有数字每个二进制位的出现次数，如果某位%K!=0
//则说明该二进制位是结果的一部分。时间复杂度O(N)，空间复杂度O(1)
int Solution::foundOnceNumber(vector<int>& nums, int k)
{
    if(nums.empty() || k<2) return -1;

    array<int, 32> arr = {};
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < 32; j++)
        {
            if(nums[i]==0) break;
            arr[j] += nums[i]&1;
            nums[i] = nums[i]>>1;
        }
    }
    
    int res = 0;
    for (int i = 0; i < 32; i++)
    {
        if(arr[i]%k!=0) res += 1<<i;
    }

    return res;
}


int main()
{
    vector<int> nums = {5,4,1,1,5,1,5};
    int k = 3;
    Solution obj;
    int result = obj.foundOnceNumber(nums, k);
    return 0;
}