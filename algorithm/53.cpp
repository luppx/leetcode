#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums);
};

int Solution::maxSubArray(vector<int>& nums) {
    if(nums.empty()) return 0;
    else if(nums.size()<2) return nums.back();


    int res=nums[0];
    int sum=0;    

    int right=0;
    while(right<nums.size())
    {
        sum += nums[right];
        res = max(res, sum);
        if(sum<=0)
        {
            sum = 0;
        }
        right++;
    }
    return res;
}