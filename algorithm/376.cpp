#include <vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums);
};

int Solution::wiggleMaxLength(vector<int>& nums) {
    if(nums.size()<1) return 0;
    else if(nums.size()<2) return 1;

    int res = 1;
    int pre = 0;
    for(int i=1; i<nums.size(); i++)
    {
        int cur = nums[i]-nums[i-1];
        if((pre==0 && cur!=0) || (pre*cur)<0)
        {
            res++;
            pre=cur;
        }
    }
    return res;
}