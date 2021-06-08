#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int>& nums, int target);
};

int Solution::searchInsert(vector<int>& nums, int target)
{
    if(nums.empty()) return 0;

    int low=0, high=nums.size()-1;
    while (low<=high)
    {
        int mid = low + ((high-low)>>1);

        if(nums[mid]>=target)
        {
            if(mid==0 || (nums[mid-1]<target)) return mid;
            else high = mid-1;
        }
        else low = mid+1;
    }
    return -1;
}

int main()
{
    vector<int> nums = {1,3,5,6};
    int target = 7;
    Solution obj;
    int result = obj.searchInsert(nums, target);
    return 0;
}