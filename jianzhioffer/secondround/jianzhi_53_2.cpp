#include <vector>
using namespace std;

class Solution
{
public:
    Solution();
    ~Solution();
    int missingNumber(vector<int>& nums);
};

Solution::Solution() {}

Solution::~Solution() {}

//折半查找，时间复杂度O(logN)，空间复杂度O(1)
int Solution::missingNumber(vector<int>& nums)
{
    if(nums.empty()) return -1;
    int left=0, right=nums.size()-1, mid=0;
    while (left<=right)
    {
        mid = (left+right)/2;
        if(nums[mid]==mid) left=mid+1;
        else right=mid-1;
    }
    return left;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {0};
    Solution obj;
    int result = obj.missingNumber(nums);
    return 0;
}
