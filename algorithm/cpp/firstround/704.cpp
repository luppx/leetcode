#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int>& nums, int target);
};


int Solution::search(vector<int>& nums, int target)
{
    if(nums.empty()) return -1;

    int low=0, high=nums.size()-1;
    while (low<=high)
    {
        int mid = low + ((high-low)>>1);
        if(nums[mid]>target) high = mid-1;
        else if(nums[mid]<target) low = mid+1;
        else return mid;
    }
    return -1;
}

int main()
{
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    Solution obj;
    int result = obj.search(nums, target);
    return 0;
}