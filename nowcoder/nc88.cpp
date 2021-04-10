#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findKth(vector<int>& nums, int n, int k);

private:
    void quicksort(vector<int>& nums, int k, int left, int right);
    int partition(vector<int>& nums, int left, int right);
};

int Solution::findKth(vector<int>& nums, int n, int k)
{
    if(n<1 || k>n || k<1) return -1;
    quicksort(nums, k-1, 0, n-1);
    return nums[k-1];
}

void Solution::quicksort(vector<int>& nums, int k, int left, int right)
{
    if(left>=right) return;
    int partition_idx = partition(nums, left, right);
    if(partition_idx == k) return;
    else if(partition_idx>k) quicksort(nums, k, left, partition_idx-1);
    else quicksort(nums, k, partition_idx+1, right);
    return;
}

int Solution::partition(vector<int>& nums, int left, int right)
{
    int pivot = nums[left];
    while (left<right)
    {
        while(left<right && nums[right]<=pivot) right--;
        nums[left] = nums[right];
        while(left<right && nums[left]>=pivot) left++;
        nums[right] = nums[left];
    }
    nums[left] = pivot;
    return left;
}

int main()
{
    vector<int> nums = {1,3,5,2,4};
    int n = nums.size();
    int k = 2;
    Solution obj;
    int result = obj.findKth(nums, n, k);
    return 0;
}
