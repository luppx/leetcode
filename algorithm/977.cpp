#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int>& nums);
};

//二分查找找到负数和非负数的分界线，然后利用归并排序
//时间复杂度O(N)，空间复杂度O(1)
// vector<int> Solution::sortedSquares(vector<int>& nums)
// {
//     int n = nums.size();
//     if(n==0) return nums;
//     else if(n==1)
//     {
//         nums.front() = nums.front()*nums.front();
//         return nums;
//     }

//     int positive_idx = n;
//     if(nums.back()>=0)
//     {
//         //找第一个大于等于0的元素
//         int low=0, high=n-1, mid=0;
//         while (low<=high)
//         {
//             mid = low + ((high-low)>>1);
//             if(nums[mid]>=0)
//             {
//                 if(mid==0 || nums[mid-1]<0) break;
//                 else high = mid-1;
//             }
//             else low = mid+1;
//         }
//         positive_idx = mid;
//     } 

//     int i=positive_idx-1, j=positive_idx;
//     vector<int> res = {};
//     while (i>=0 && j<n)
//     {
//         if(nums[i]*nums[i]>=nums[j]*nums[j])
//         {
//             res.push_back(nums[j]*nums[j]);
//             j++;
//         }
//         else
//         {
//             res.push_back(nums[i]*nums[i]);
//             i--;
//         }
//     }
    
//     while (i>=0)
//     {
//         res.push_back(nums[i]*nums[i]);
//         i--;
//     }
    
//     while (j<n)
//     {
//         res.push_back(nums[j]*nums[j]);
//         j++;
//     }
    
//     return res;
// }

//双指针，时间复杂度O(N)，空间复杂度O(1)
vector<int> Solution::sortedSquares(vector<int>& nums)
{
    int n = nums.size();
    if(n==0) return nums;
    else if(n==1)
    {
        nums.front() = nums.front()*nums.front();
        return nums;
    }

    vector<int> res(n,0);
    int i=0, j=n-1, pos=n-1;
    while (i<=j)
    {
        if(nums[i]*nums[i]>=nums[j]*nums[j])
        {
            res[pos] = nums[i]*nums[i];
            i++;
        }
        else
        {
            res[pos] = nums[j]*nums[j];
            j--;
        }
        pos--;
    }
    return res;
}


int main()
{
    vector<int> nums = {-4,-1,0,3,10};
    Solution obj;
    vector<int> result = obj.sortedSquares(nums);
    for (int i = 0; i < result.size()-1; i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<result.back()<<endl;
    return 0;
}