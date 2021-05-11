#include <vector>
#include <stdlib.h>
using namespace std;

class Solution
{
public:
    vector<int> sortArray(vector<int>& nums);

private:
    void mergeSort(vector<int>& nums, int left, int right, vector<int>& tmp);
    void merge(vector<int>& nums, int left, int mid, int right, vector<int>& tmp);
    void quickSort(vector<int>& nums, int left, int right);
    int partition(vector<int>& nums, int left, int right);
};

//选择排序。时间复杂度O(N^2)，空间复杂度O(1)
// vector<int> Solution::sortArray(vector<int>& nums)
// {
//     if(nums.size()<2) return nums;

//     int n = nums.size();
//     for (int i = 0; i < n-1; i++)
//     {
//         int min_idx = i;
//         for (int j = i+1; j < n; j++)
//         {
//             if(nums[min_idx]>nums[j])
//             {
//                 min_idx = j;
//             }
//         }
//         swap(nums[i], nums[min_idx]);
//     }
//     return nums;
// }

//冒泡排序。时间复杂度O(N^2)，空间复杂度O(1)
// vector<int> Solution::sortArray(vector<int>& nums)
// {
//     if(nums.size()<2) return nums;
//     int n = nums.size();

//     for (int i = n-1; i > 0; i--)
//     {
//         bool sorted = true;

//         for (int j = 0; j < i; j++)
//         {
//             if (nums[j]>nums[j+1])
//             {
//                 swap(nums[j],nums[j+1]);
//                 sorted = false;
//             }
//         }
//         if(sorted) break;
//     }
//     return nums;
// }

//插入排序。时间复杂度O(N^2)，空间复杂度O(1)
// vector<int> Solution::sortArray(vector<int>& nums)
// {
//     if(nums.size()<2) return nums;
//     int n = nums.size();

//     for (int i = 1; i < n; i++)
//     {
//         int temp = nums[i];
//         int j = i;
//         while (j>0 && temp<nums[j-1])
//         {
//             nums[j] = nums[j-1];
//             j--;
//         }
//         nums[j] = temp;
//     }
    
//     return nums;
// }

//归并排序。时间复杂度O(NlogN)，空间复杂度O(N)
// vector<int> Solution::sortArray(vector<int>& nums)
// {
//     if(nums.size()<2) return nums;
//     int n = nums.size();
//     vector<int> tmp(n,0);
//     mergeSort(nums, 0, n-1, tmp);
//     return nums;
// }

// void Solution::mergeSort(vector<int>& nums, int left, int right, vector<int>& tmp)
// {
//     if(left>=right) return;
//     int mid = left + ((right-left)>>1);
//     mergeSort(nums, left, mid, tmp);
//     mergeSort(nums, mid+1, right, tmp);
//     merge(nums, left, mid, right, tmp);
//     return ;
// }

// void Solution::merge(vector<int>& nums, int left, int mid, int right, vector<int>& tmp)
// {
//     if(left>=right) return;
//     if(nums[mid]<nums[mid+1]) return; //左右两区间已经有序，不用再排序

//     int i=left, j=mid+1;
//     int idx = left;
//     while (i<=mid && j<=right)
//     {
//         if(nums[i]<=nums[j]) tmp[idx++] = nums[i++];
//         else tmp[idx++] = nums[j++];
//     }
    
//     while(i<=mid) tmp[idx++] = nums[i++];
//     while(j<=right) tmp[idx++] = nums[j++];

//     for (i = left; i <= right; i++)
//     {
//         nums[i] = tmp[i];
//     }
//     return ;
// }

//快排。时间复杂度O(NlogN)，空间复杂度O(logN)
vector<int> Solution::sortArray(vector<int>& nums)
{
    if(nums.size()<2) return nums;
    int n = nums.size();
    quickSort(nums, 0, n-1);
    return nums;
}

void Solution::quickSort(vector<int>& nums, int left, int right)
{
    if(left>=right) return;
    int pivot_idx = partition(nums, left, right);
    quickSort(nums, left, pivot_idx-1);
    quickSort(nums, pivot_idx+1, right);
    return;
}

int Solution::partition(vector<int>& nums, int left, int right)
{
    int i = rand() % (right-left+1) + left;
    int pivot = nums[i];
    swap(nums[left], nums[i]);
    while (left<right)
    {
        while(left<right && nums[right]>=pivot) right--;
        nums[left] = nums[right];

        while(left<right && nums[left]<=pivot) left++;
        nums[right] = nums[left];
    }
    nums[left] = pivot;
    return left;
}

int main()
{
    vector<int> nums = {5,2,3,1};
    Solution obj;
    vector<int> result = obj.sortArray(nums);
    return 0;
}