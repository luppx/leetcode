#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums);
};

//排序+双指针。先对数组排序，然后遍历数组，遍历每个元素时用双指针指向其后面的区间，在这个区间里面找到三数之和为0的数
//时间复杂度O(N^2)，空间复杂度O(1)
vector<vector<int>> Solution::threeSum(vector<int>& nums)
{
    if(nums.size()<3) return {};
    sort(nums.begin(), nums.end());

    vector<vector<int>> res = {};
    int left=0, right = nums.size()-1;
    while (left<=right-2)
    {   
        while(left<=right-2 && left>0 && nums[left]==nums[left-1])  //去重
        {
            left++;
            continue;
        }
        while(left<=right-2 && right<nums.size()-1 && nums[right]==nums[right+1])  //去重
        {
            right--;
            continue;
        }

        if(nums[left]>0) break; //如果区间最左边的元素已经大于0，则后面的元素肯定都大于0，比不可能存在相加为0的三个数，直接跳出

        int i = left+1, j=right;
        while (i<j)
        {
            if(nums[i]+nums[j]+nums[left]<0) i++;
            else if(nums[i]+nums[j]+nums[left]>0) j--;
            else
            {
                res.push_back({nums[left], nums[i], nums[j]});
                i++;
                j--;
                while(i<j && i>left+1 && nums[i]==nums[i-1]) i++;
                while(i<j && j<right && nums[j]==nums[j+1]) j--;
            }
        }
        left++;
    }
    return res;
}

int main()
{
    // vector<int> nums = {-1,0,1,2,-1,-4};
    vector<int> nums = {0,0,0};
    Solution obj;
    vector<vector<int>> res = obj.threeSum(nums);
    return 0;
}