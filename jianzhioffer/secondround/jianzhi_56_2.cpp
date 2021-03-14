#include <vector>
#include <unordered_map>
using namespace std;

// class Solution
// {
// public:
//     int singleNumber(vector<int>& nums);
// };

// //哈希表，时间复杂度O(N)，空间复杂度O(N)
// int Solution::singleNumber(vector<int>& nums)
// {
//     if(nums.empty()) return 0;
//     unordered_map<int, int> map;
//     for(int num:nums)
//     {
//         map[num]++;
//     }

//     for (unordered_map<int,int>::iterator it = map.begin(); it!=map.end(); it++)
//     {
//         if(it->second!=3) return it->first;
//     }
//     return 0;
// }


// class Solution
// {
// public:
//     int singleNumber(vector<int>& nums);
// private:
//     void QuickSort(vector<int>& nums, int left, int right);
//     int Partition(vector<int>& nums, int left, int right);
// };

// //方法二，对数组排序，然后遍历数组，找到只出现一次的数。时间复杂度O(NlogN)，空间复杂度O(1)
// int Solution::singleNumber(vector<int>& nums)
// {
//     if(nums.empty()) return 0;
//     QuickSort(nums, 0, nums.size()-1);
//     for (int i = 0; i < nums.size(); )
//     {
//         if(i+2>=nums.size()) return nums[i];
//         else if(nums[i]!=nums[i+2]) return nums[i];
//         else i += 3;
//     }
    
//     return 0;
// }

// void Solution::QuickSort(vector<int>& nums, int left, int right)
// {
//     if(left>=right) return;
//     int pivot_position = Partition(nums, left, right);
//     QuickSort(nums, left, pivot_position-1);
//     QuickSort(nums, pivot_position+1, right);
//     return;
// }

// int Solution::Partition(vector<int>& nums, int left, int right)
// {
//     int pivot = nums[left];
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

class Solution
{
public:
    int singleNumber(vector<int>& nums);
};

//方法三，将每个数字都看成二进制，用一个32位数组(题目说明数组元素最大值为2^31，故数组大小只用32)存储每个二进制位出现的次数
//然后每个二进制位对3取余，结果不为0的二进制位组合起来即为要返回的结果
//时间复杂度O(N)，空间复杂度O(1)
int Solution::singleNumber(vector<int>& nums)
{
    if(nums.empty()) return 0;
    int* counts = new int[32] ();
    
    for(int num:nums)
    {
        for (int j = 0; j < 32; j++)
        {
            *(counts+j) += num&1;
            num >>= 1;
        }
    }
   
    int res = 0;
    for (int i = 31; i>=0; i--)
    {
        res<<=1;
        res |= *(counts+i) % 3;
    }

    delete[] counts;
    return res;
}



int main(int argc, char const *argv[])
{
    vector<int> nums {3,4,3,3};
    Solution obj;
    int res = obj.singleNumber(nums);
    return 0;
}
