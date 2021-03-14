#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    Solution() {};
    ~Solution() {};
    vector<int> twoSum(vector<int>& nums, int target);
};

vector<int> Solution::twoSum(vector<int>& nums, int target)
{
    vector<int> res{};
    if(nums.empty() || target<=0) return res;
    int left=0, right=nums.size()-1;
    while (left<right)
    {
        if(nums[left]+nums[right]>target) right--;
        else if(nums[left]+nums[right]<target) left++;
        else
        {
            res = {nums[left], nums[right]};
            break;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,4,5,6,8,10};
    Solution obj;
    vector<int> result = obj.twoSum(nums, 10);
    return 0;
}
