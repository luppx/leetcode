#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums);
};

bool Solution::canJump(vector<int>& nums) {
    if(nums.size()<2) return true;

    int maxIndex=nums[0];
    for(int i=1; i<=maxIndex; i++)
    {
        maxIndex = max(maxIndex, i+nums[i]);
        if(maxIndex>=(nums.size()-1)) return true;
    }
    return false;
}