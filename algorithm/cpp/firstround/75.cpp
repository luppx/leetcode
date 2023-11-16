#include <vector>
#include <stdlib.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int>& nums);
};

void Solution::sortColors(vector<int>& nums)
{
    if(nums.size()<2) return;
    
    //[0,zero) 表示0区间；[zero,two)表示1区间；[two,nums.size())表示2区间
    int zero = 0;
    int two = nums.size();
    int i=0;
    while(i<two)
    {
        if(nums[i]==0)
        {
            swap(nums[zero], nums[i]);
            zero++;
            i++;
        }
        else if(nums[i]==1)
        {
            i++;
        }
        else
        {
            two--;
            swap(nums[i], nums[two]);
        }
    }
    return;
}


int main()
{
    vector<int> nums = {1,2,0};
    Solution obj;
    obj.sortColors(nums);
    return 0;
}