#include <string>
#include <vector>
using namespace std;

//快速排序，时间复杂度O(NlogN)，空间复杂度O(N)
//能使用排序解题的证明见leetcode题解
class Solution
{
public:
    Solution();
    ~Solution();
    string minNumber(vector<int>& nums);


};

Solution::Solution()
{

}

Solution::~Solution()
{

}

int Partition(vector<int>& nums, int left, int right)
{
    int pivot = nums[left];
    while (left<right)
    {
        while(left<right && ((to_string(nums[right])+to_string(pivot))>=(to_string(pivot)+to_string(nums[right])))) right--;
        nums[left] = nums[right];
        while(left<right && ((to_string(nums[left])+to_string(pivot))<=(to_string(pivot)+to_string(nums[left])))) left++;
        nums[right] = nums[left];
    }
    nums[left] = pivot;
    return left;   
}

void QuickSort(vector<int>& nums, int left, int right)
{
    if(left>=right) return;
    int pivot_position = Partition(nums, left, right);
    QuickSort(nums, left, pivot_position-1);
    QuickSort(nums, pivot_position+1, right);
}

string Solution::minNumber(vector<int>& nums)
{
    if(nums.empty()) return "";
    QuickSort(nums, 0, nums.size()-1);
    string res = "";
    for (int i = 0; i < nums.size(); i++)
    {
        res += to_string(nums[i]);
    }
    return res;
}


int main(int argc, char const *argv[])
{
    vector<int> nums = {3,30,34,5,9};
    Solution obj;
    string result = obj.minNumber(nums);
    return 0;
}
