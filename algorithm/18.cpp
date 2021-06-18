#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target);
};

vector<vector<int>> Solution::fourSum(vector<int>& nums, int target)
{
    int n = nums.size();
    if(n<4) return {};

    vector<vector<int>> res = {};
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n-3; i++)
    {
        if(i>0 && nums[i]==nums[i-1]) continue;

        for (int j = i+1; j < n-2; j++)
        {
            if(j>i+1 && nums[j]==nums[j-1]) continue;

            int left = j+1, right = n-1;
            while (left<right)
            {
                if(nums[i]+nums[j]+nums[left]+nums[right]<target)
                {
                    left++;
                }
                else if(nums[i]+nums[j]+nums[left]+nums[right]>target)
                {
                    right--;
                }
                else
                {
                    res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    while(left<right && nums[left]==nums[left+1]) left++;
                    while(left<right && nums[right]==nums[right-1]) right--;
                    left++;
                    right--;
                }
            }
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {2,2,2,2,2,2,2};
    int target = 8;
    Solution obj;
    vector<vector<int>> result = obj.fourSum(nums, target);
    return 0;
}