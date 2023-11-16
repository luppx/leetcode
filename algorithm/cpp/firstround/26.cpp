#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums);
};

//快慢指针，时间复杂度O(N)
int Solution::removeDuplicates(vector<int>& nums)
{
    int n = nums.size();
    if(n<2) return n;

    int slowIndex=0;
    for (int fastIndex = 1; fastIndex < n; fastIndex++)
    {
        if(nums[slowIndex]!=nums[fastIndex])
        {
            nums[++slowIndex] = nums[fastIndex];
        }
    }
    return slowIndex+1;
}

int main()
{
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    Solution obj;
    int result = obj.removeDuplicates(nums);
    for (int i = 0; i < result; i++)
    {
        cout<<nums[i]<<" ";
    }
    return 0;
}