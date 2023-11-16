#include <vector>
#include <stdlib.h>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k);

private:
    void quickSort(vector<int>& nums, int left, int right);
    int partition(vector<int>& nums, int left, int right);
    int idx;
};

int Solution::findKthLargest(vector<int>& nums, int k)
{
    if(nums.empty() || k>nums.size()) return -1;

    int n = nums.size();
    this->idx = n-k;
    quickSort(nums, 0, n-1);
    return nums[this->idx];
}

//利用快排找topK，时间复杂度O(N)，空间复杂度O(logN)。
// void Solution::quickSort(vector<int>& nums, int left, int right)
// {
//     if(left>=right) return;
//     int pivot_idx = partition(nums, left, right);
//     if(pivot_idx>idx) quickSort(nums, left, pivot_idx-1);
//     else if(pivot_idx<idx) quickSort(nums, pivot_idx+1, right);
//     else return;
// }

// int Solution::partition(vector<int>& nums, int left, int right)
// {
//     int i = rand() % (right-left+1) + left;
//     int pivot = nums[i];
//     swap(nums[left], nums[i]);
//     while (left<right)
//     {
//         while(left<right && nums[right]>=pivot) right--;
//         nums[left] = nums[right];
//         while(left<right && nums[left]<=pivot) left++;
//         nums[right] = nums[left];
//     }
//     nums[left] = pivot;
//     return left;
// }

//快排优化。当数组中存在大量重复元素时，采用双指针，把等于pivot的元素都放到一起，可以大大减小递归区间
//时间复杂度O(N)，空间复杂度O(logN)
void Solution::quickSort(vector<int>& nums, int left, int right)
{
    if(left>=right) return;
    
    int i = rand() % (right-left+1) + left;
    int pivot = nums[i];
    swap(nums[left], nums[i]);

    //[left,p1) 表示小于pivot的区间
    //[p1, p2) 表示等于pivot的区间
    //[p2,right+1) 表示大于pivot的区间
    int p1 = left;
    int p2 = right+1;
    i = left;
    while (i<p2)
    {
        if(nums[i]<pivot)
        {
            swap(nums[i], nums[p1]);
            p1++;
            i++;
        }
        else if(nums[i]==pivot)
        {
            i++;
        }
        else
        {
            p2--;
            swap(nums[i], nums[p2]);
        }
    }
    
    if(p1>idx) quickSort(nums, left, p1);
    else if(p2-1<idx) quickSort(nums, p2, right);
    else return;
}


int main()
{
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    Solution obj;
    int result = obj.findKthLargest(nums, k);
    return 0;
}