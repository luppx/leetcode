#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int>& nums, int val);

private:
    int findIndex(vector<int>& nums, int val, int size, bool first=true);
};

//方法一，二分查找分别找到等于val的第一个和最后一个元素(start、end)
//然后将end后的元素与[start,end]区间内的元素交换
//但这题数组并不是有序的，所以需要先排序。
//时间复杂度：O(NlogN)(排序)+O(logN)(二分查找)+O(N)(交换元素)=O(NlogN)，空间复杂度O(1)
// int Solution::removeElement(vector<int>& nums, int val)
// {
//     if(nums.empty()) return 0;
    
//     sort(nums.begin(), nums.end());
//     int n=nums.size();
//     int start = findIndex(nums, val, n, true);
//     int end = findIndex(nums, val, n, false);

//     if(start==-1 || end==-1) return n;  //数组中不存在等于val的目标元素
//     else if(end==n-1) return n-(end-start+1);   //删除的元素在数组末尾，则直接返回删除后元素数量即可
//     else
//     {
//         int i=start, j=n-1;
//         while (i<=end && j>end)
//         {
//             swap(nums[i], nums[j]);
//             i++;
//             j--;
//         }
//         return n-(end-start+1);
//     }
// }

// int Solution::findIndex(vector<int>& nums, int val, int size, bool first)
// {
//     int low=0, high=size-1, mid=0;
//     while(low<=high)
//     {
//         mid = low + ((high-low)>>1);
//         if(nums[mid]>val) high = mid-1;
//         else if(nums[mid]<val) low = mid+1;
//         else
//         {
//             if(first) //找第一个等于val的元素
//             {
//                 if(mid==0 || nums[mid-1]<val) return mid;
//                 else high = mid-1;
//             }
//             else //找最后一个等于val的元素
//             {
//                 if(mid==size-1 || nums[mid+1]>val) return mid;
//                 else low = mid+1;
//             }
//         }
//     }
//     return -1;
// }


//方法二，快慢指针。时间复杂度O(N)
int Solution::removeElement(vector<int>& nums, int val)
{
    if(nums.empty()) return 0;
    int n = nums.size();
    int slowIndex = 0;
    for (int fastIndex = 0; fastIndex < n; fastIndex++)
    {
        if(nums[fastIndex]!=val)
        {
            nums[slowIndex] = nums[fastIndex];
            slowIndex++;
        }
    }
    return slowIndex;
}

int main()
{
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    Solution obj;
    int result = obj.removeElement(nums, val);

    for (int i = 0; i < result; i++)
    {
        cout<<nums[i]<<" ";
    }
    return 0;
}