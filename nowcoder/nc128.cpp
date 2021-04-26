#include <vector>
using namespace std;

class Solution
{
public:
    long long maxWater(vector<int>& nums);
};

long long Solution::maxWater(vector<int>& nums)
{
    if(nums.size()<3) return 0;
    long long res = 0;
    int left=0, right=nums.size()-1, min_bound=0;
    while (left<right)
    {
        min_bound = min(nums[left], nums[right]); //左右边界的最低水位

        while (left<right && nums[left]<=min_bound) //从左向右遍历，直到左边界的水位高于min_bound
        {
            res += min_bound - nums[left];
            left++;
        }
        
        while(left<right && nums[right]<=min_bound) //从右向左遍历，直到左边界的水位高于min_bound
        {
            res += min_bound - nums[right];
            right--;
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {3,1,2,1};
    Solution obj;
    long long result = obj.maxWater(nums);
    return 0;
}