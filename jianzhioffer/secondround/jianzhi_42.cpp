#include <vector>
using namespace std;

class Solution
{
public:
    Solution();
    ~Solution();
    int maxSubArray(vector<int>& nums);

};

Solution::Solution()
{
}

Solution::~Solution()
{
}

int Solution::maxSubArray(vector<int>& nums)
{
    if(nums.empty()) return -1;
    else if(nums.size()==1) return nums.back();
    int prev_sum = nums[0];
    int max_sum = nums[0];
    for(int i=1; i<nums.size(); i++)
    {
        int num = prev_sum+nums[i];
        int cur_sum = num>nums[i] ? num:nums[i];
        max_sum = max_sum>=cur_sum ? max_sum:cur_sum;
        prev_sum = cur_sum;
    }
    return max_sum;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution obj;
    int result = obj.maxSubArray(nums);
    return 0;
}
