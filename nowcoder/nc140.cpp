#include <vector>
#include <cstdlib>
using namespace std;

class Solution
{
public:
    vector<int> MySort(vector<int>& nums);

private:
    void QuickSort(vector<int>& nums, int left, int right);
    int Partition(vector<int>& nums, int left, int right);
};

vector<int> Solution::MySort(vector<int>& nums)
{
    if(nums.size()<2) return nums;
    QuickSort(nums, 0, nums.size()-1);
    return nums;
}

void Solution::QuickSort(vector<int>& nums, int left, int right)
{
    if(left>=right) return;
    int pivotIdx = Partition(nums, left, right);
    QuickSort(nums, left, pivotIdx-1);
    QuickSort(nums, pivotIdx+1, right);
    return ;
}

int Solution::Partition(vector<int>& nums, int left, int right)
{
    int i = left + rand() % (right-left+1);  //随机选一个元素作为哨兵，使partition划分的区间尽量等长
    swap(nums[left], nums[i]);
    int pivot = nums[left];
    while (left<right)
    {
        while(left<right && nums[right]>=pivot) right--;
        nums[left]=nums[right];
        while(left<right && nums[left]<=pivot) left++;
        nums[right]=nums[left];
    }
    nums[left]=pivot;
    return left;
}

int main()
{
    vector<int> nums = {5,1,6,2,5};
    Solution obj;
    vector<int> result = obj.MySort(nums);
    return 0;
}