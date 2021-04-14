#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> LIS(vector<int>& nums);
};


// //动态规划，时间复杂度O(N^2)，空间复杂度O(N)，会超时
// vector<int> Solution::LIS(vector<int>& nums)
// {
//     if(nums.size()<2) return nums;

//     int n = nums.size();
//     vector<int> dp(n,1);

//     for (int i = 1; i < n; i++)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             if(nums[j]<nums[i])
//             {
//                 dp[i] = max(dp[i], dp[j]+1);
//             }
//         }
        
//     }
    
//     int length = *max_element(dp.begin(), dp.end());
//     vector<int> res(length,0);
//     for (int i = n-1; i >= 0 && length>0; i--)
//     {
//         if(dp[i]==length)
//         {
//             res[--length] = nums[i];
//         }
//     }

//     return res;
// }

//贪心+二分查找，时间复杂度O(NlogN)，空间复杂度O(N)
vector<int> Solution::LIS(vector<int>& nums)
{
    if(nums.size()<2) return nums;
    vector<int> res = {};  //res存放以nums[i]结尾的递增子序列
    vector<int> maxLen = {};  //maxLen存放以nums[i]结尾的递增子序列的最大长度
    res.push_back(nums[0]);
    maxLen.push_back(1);

    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        if(nums[i]==res.back()) continue;
        else if(nums[i]>res.back())
        {
            res.push_back(nums[i]);
            maxLen.push_back(res.size());
        }
        else
        {
            int left = 0, right = res.size()-1, pos=0;
            while (left<=right)
            {
                int mid = (left+right)/2;
                if(res[mid]<nums[i])
                {
                    left = mid+1;
                }
                else right = mid-1;
            }
            res[left] = nums[i];
            maxLen.push_back(left+1);
        }
        
    }

    for (int i = maxLen.size()-1, j=res.size(); j>0 ;)
    {
        if(maxLen[i]==j)
        {
            res[--j] = nums[i--];
        }
        else i--;
    }
    
    return res;
}

int main()
{
    vector<int> nums = {2,1,5,3,6,4,8,9,7};
    Solution obj;
    vector<int> result = obj.LIS(nums);
    return 0;
}