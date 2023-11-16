#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums);
};

int Solution::jump(vector<int>& nums) {
    if(nums.size()<2) return 0;
    
    int maxPos=0; //当前元素能跳达的最远位置
    int end=0;
    int res=0;
    for(int i=0; i<nums.size()-1; i++)
    {
        maxPos = max(maxPos, i+nums[i]);
        if(i==end)
        {
            res++;
            end = maxPos;
        }
    }
    return res;
}