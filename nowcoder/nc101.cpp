#include <vector>
using namespace std;

class Solution
{
public:
    int solve(vector<int>& nums);
};

int Solution::solve(vector<int>& nums)
{
    if(nums.empty()) return -1;
    else if(nums.size()<2 && nums[0]!=0) return 0;
    
    int left=0, right=nums.size()-1;
    while (left<right)
    {
        int mid = left + (right-left)/2;
        if(nums[mid]>mid) right = mid;
        else left = mid+1;
    }

    if(nums.back()==left) return left+1;
    return left;
}

int main()
{
    vector<int> nums = {0,1,2,3,4,6,7};
    Solution obj;
    int result = obj.solve(nums);
    return 0;
}