#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums);
};

vector<vector<int>> Solution::threeSum(vector<int>& nums)
{
    int n = nums.size();
    if(n<3) return {};

    sort(nums.begin(), nums.end());
    vector<vector<int>> res = {};
    int left=1, right=n-1;
    for (int i=0; i<n-2; i++)
    {
        while(i>0 && i<n-2 && nums[i]==nums[i-1]) i++;
        if(i==n-2 || nums[i]>0) break;
        left = i+1;
        right = n-1;
        while (left<right)
        {
            if(nums[left]+nums[right]+nums[i]<0)
            {
                left++;
            }
            else if(nums[left]+nums[right]+nums[i]>0)
            {
                right--;
            }
            else
            {
                res.push_back({nums[i], nums[left], nums[right]});
                while(left<right && nums[left]==nums[left+1]) left++;
                while(left<right && nums[right]==nums[right-1]) right--;
                left++;
                right--;
            }
        }
        
    }
    return res;
}

int main()
{
    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution obj;
    vector<vector<int>> result = obj.threeSum(nums);
    return 0;
}