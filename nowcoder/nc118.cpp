#include <vector>
using namespace std;

class Solution
{
public:
    int InversePairs(vector<int>& nums);

private:
    int mergeSort(vector<int>& nums, int left, int right);
    int merge(vector<int>& nums, int left, int left_bound, int right);
};


//利用归并排序。时间复杂度O(NlogN)，空间复杂度O(N)
int Solution::InversePairs(vector<int>& nums)
{
    int n = nums.size();
    if(n<2) return 0;
    else if(n==2) return nums[0]>nums[1];

    int res = mergeSort(nums, 0, n-1) % 1000000007;
    return res;
}

int Solution::mergeSort(vector<int>& nums, int left, int right)
{
    if(left>=right) return 0;
    int mid = left + ((right-left)>>1);
    return mergeSort(nums, left, mid) + mergeSort(nums, mid+1, right) + merge(nums, left, mid, right);
}
    
int Solution::merge(vector<int>& nums, int left, int left_bound, int right)
{
    if(left>=right) return 0;
    vector<int> tmp = {};

    int i=left, j=left_bound+1;
    int num_inverse_pairs = 0;
    int count=0;
    
    while(i<=left_bound)
    {
        while(j<=right && nums[i]>nums[j])
        {
            count++;
            tmp.push_back(nums[j++]);
        }
        num_inverse_pairs += count;
        tmp.push_back(nums[i++]);
    }
    
    while(i<=left_bound) tmp.push_back(nums[i++]);
    while(j<=right) tmp.push_back(nums[j++]);

    copy(tmp.begin(), tmp.end(), nums.begin()+left);
    return num_inverse_pairs % 1000000007;
}

int main()
{
    vector<int> nums = {1,2,3,4,5,6,7,0};
    Solution obj;
    int result = obj.InversePairs(nums);
    return 0;
}