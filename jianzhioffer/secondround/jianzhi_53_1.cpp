#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int search(vector<int>& nums, int target);
};

// //哈希表。时间复杂度O(N)，空间复杂度O(N)
// int Solution::search(vector<int>& nums, int target)
// {
//     if(nums.empty()) return 0;
//     unordered_map<int, int> map;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         map[nums[i]]++;
//     }
    
//     return map[target];
// }

//二分查找。分别查找出数组中target的左边界和右边界，即可得到target的数量
//时间复杂度O(logN)，空间复杂度O(1)
int Solution::search(vector<int>& nums, int target)
{
    if(nums.empty()) return 0;
    int left = 0, right = nums.size()-1;

    while (left<=right)
    {
        int mid = (left+right)/2;
        if(nums[mid]<=target) left = mid+1;
        else right = mid-1;
    }
    int res_right = left; //target右边界的后一个位置。因为left==right时会执行最后一次循环，最后一次循环结束后，left一定比right大1，所以left指向区间右边界的后一个位置，而right指向区间的右边界
    
    if(right<0 || (right>=0 && nums[right]!=target)) return 0; //找到右边界后，判断一下数组中是否存在target，不存在则返回0

    left = 0;
    while(left<=right)
    {
        int mid = (left+right)/2;
        if(nums[mid]<target) left = mid+1;
        else right = mid-1;
    }
    int res_left = right;  //target左边界的前一个位置

    return res_right - res_left - 1;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {5,7,7,8,8,10};
    Solution obj;
    int result = obj.search(nums, 5);
    return 0;
}
