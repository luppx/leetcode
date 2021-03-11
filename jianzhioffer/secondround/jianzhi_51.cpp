#include <vector>
using namespace std;

class Solution
{
public:
    Solution();
    ~Solution();
    int reversePairs(vector<int>& nums);

private:
    int mergeSort(vector<int>& nums, vector<int>& tmp, int left, int right);
};

Solution::Solution() {}

Solution::~Solution() {}


//归并排序。时间复杂度O(NlogN)，空间复杂度O(N)
int Solution::reversePairs(vector<int>& nums)
{
    if(nums.empty()) return 0;
    int n = nums.size();
    vector<int> tmp(n);
    return mergeSort(nums, tmp, 0, n-1);
}

int Solution::mergeSort(vector<int>&nums, vector<int>& tmp, int left, int right)
{
    if(left>=right) return 0;

    int mid = (left+right)/2;
    int reverse_count = mergeSort(nums, tmp, left, mid) + mergeSort(nums, tmp, mid+1, right);
    int i = left, j = mid+1;
    int pos = left;
    while (i<=mid && j<=right)
    {
        if(nums[i]<=nums[j])
        {
            tmp[pos++] = nums[i];
            i++;
            reverse_count += j - (mid+1);
        }
        else
        {
            tmp[pos++] = nums[j];
            j++;
        }
    }
    
    for (int k = i; k <= mid; k++)
    {
        tmp[pos++] = nums[k];
        reverse_count += j - (mid+1);
    }
    for (int k = j; k <= right; k++)
    {
        tmp[pos++] = nums[k];
    }
    copy(tmp.begin()+left, tmp.begin()+right+1, nums.begin()+left);
    return reverse_count;
}

// //暴力法。时间复杂度O(N^2)，空间复杂度O(1)
// int Solution::reversePairs(vector<int>& nums)
// {
//     if(nums.empty() || nums.size()==1) return 0;
//     int res = 0;
//     for (int i = 0; i < nums.size()-1; i++)
//     {
//         for (int j = i+1; j < nums.size(); j++)
//         {
//             if(nums[i]>nums[j]) res++;
//         }
//     }
//     return res;
// }

int main(int argc, char const *argv[])
{
    vector<int> nums={7,5,6,4};
    Solution obj;
    int result = obj.reversePairs(nums);
    return 0;
}
