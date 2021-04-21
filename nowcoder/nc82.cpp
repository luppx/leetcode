#include <vector>
#include <algorithm>
#include <climits>
#include <deque>
using namespace std;

class Solution
{
public:
    vector<int> maxInWindows(vector<int>& nums, int size);
};

// //方法一，遍历，时间复杂度O(n*size)，空间复杂度O(1)
// vector<int> Solution::maxInWindows(vector<int>& nums, int size)
// {
//     int n = nums.size();
//     if(size<1 || n<size) return {};

//     vector<int> res = {};
//     int windowMax = INT_MIN;
//     int maxIndex = -1;
    
//     //第一个窗口的最大值
//     for (int i = 0, j=size-1; i <= j; i++, j--)
//     {
//         if(nums[i]>windowMax)
//         {
//             windowMax = nums[i];
//             maxIndex = i;
//         }
//         else if(nums[i]==windowMax)
//         {
//             windowMax = nums[i];
//             maxIndex = max(maxIndex, i);
//         }

//         if(nums[j]>windowMax)
//         {
//             windowMax = nums[j];
//             maxIndex = j;
//         }
//         else if(nums[j]==windowMax)
//         {
//             windowMax = nums[j];
//             maxIndex = max(maxIndex, j);
//         }
//     }
//     res.push_back(windowMax);

//     //剩余窗口的最大值
//     for (int i = size; i < n; i++)
//     {
//         //最大值仍在窗口内
//         if(i-size<maxIndex)
//         {
//             if(nums[i]>=windowMax)
//             {
//                 windowMax = nums[i];
//                 maxIndex = i;
//             }
//         }
//         else  //最大值不在窗口内
//         {
//             windowMax = nums[i];
//             for (int j = i-size+1, k=i; j <= k; j++, k--)
//             {
//                 if(nums[j]>windowMax)
//                 {
//                     windowMax = nums[j];
//                     maxIndex = j;
//                 }
//                 else if(nums[j]==windowMax)
//                 {
//                     windowMax = nums[j];
//                     maxIndex = max(maxIndex, j);
//                 }

//                 if(nums[k]>windowMax)
//                 {
//                     windowMax = nums[k];
//                     maxIndex = k;
//                 }
//                 else if(nums[k]==windowMax)
//                 {
//                     windowMax = nums[k];
//                     maxIndex = max(maxIndex, k);
//                 }
//             }
        
//         }
        
//         res.push_back(windowMax);
//     }
    
//     return res;
// }

//方法二，单调队列。思想类似于O(1)时间复杂度求栈的最小值。时间复杂度O(N)，空间复杂度O(size)(窗口大小)
vector<int> Solution::maxInWindows(vector<int>& nums, int size)
{
    if(size<1 || size>nums.size()) return {};

    vector<int> res = {};
    deque<int> dq;
    
    for (int i = 0; i < size; i++)
    {
        while (!dq.empty() && dq.back()<nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(nums[i]);
        
    }
    res.push_back(dq.front());

    for (int i = size; i < nums.size(); i++)
    {
        if(nums[i-size]==dq.front()) dq.pop_front();

        while (!dq.empty() && dq.back()<nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(nums[i]);

        res.push_back(dq.front());
    }
    return res;
}

int main()
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    //vector<int> nums = {1,3,1,2,0,5};
    int size = 3;
    Solution obj;
    vector<int> result = obj.maxInWindows(nums, size);
    return 0;
}