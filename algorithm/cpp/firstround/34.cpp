#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target);

private:
    int searchLeft(vector<int>& nums, int target);
    int searchRight(vector<int>& nums, int target);
};

vector<int> Solution::searchRange(vector<int>& nums, int target)
{
    if(nums.empty()) return {-1, -1};

    int n = nums.size();
    vector<int> res = {-1,-1};

    res[0] = searchLeft(nums, target);
    res[1] = searchRight(nums, target);
    return res;
}

int Solution::searchLeft(vector<int>& nums, int target) //左边界是找第一个等于target的元素
{
    int n = nums.size();
    int low=0, high=n-1;
    while (low<=high)
    {
        int mid = low + ((high-low)>>1);
        if (nums[mid]>=target)
        {
            if(nums[mid]==target && (mid==0 || nums[mid-1]<target)) return mid;
            else high = mid-1;
        }
        else low = mid+1;
    }
    return -1;
}

int Solution::searchRight(vector<int>& nums, int target) //右边界找最后一个等于target的元素
{
    int n = nums.size();
    int low=0, high=n-1;
    while (low<=high)
    {
        int mid = low + ((high-low)>>1);
        if(nums[mid]<=target)
        {
            if(nums[mid]==target && (mid==n-1 || nums[mid+1]>target)) return mid;
            else low = mid+1;
        }
        else high = mid-1;
    }
    return -1;
}

int main()
{
    vector<int> nums = {5,7,7,8,8,10};
    int target = 6;
    Solution obj;
    vector<int> result = obj.searchRange(nums, target);
    return 0;
}