#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// //遍历数组，用哈希表记录每个数字出现的次数。再遍历哈希表找出出现最多次的数字。
// //时间复杂度O(N)，空间复杂度O(N)
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         if(nums.empty()) return 0;
//         unordered_map<int,int> map;
//         while (!nums.empty())
//         {
//             int num = nums.back();
//             nums.pop_back();
//             if (map.find(num)==map.end())
//             {
//                 map[num] = 1;
//             }
//             else
//                 map[num]++;
//         }

//         int max_num = map.begin()->first;
//         int max_count = map.begin()->second;
//         for(unordered_map<int,int>::iterator it = map.begin(); it!=map.end(); it++)
//         {
//             if(it->second>max_count)
//             {
//                 max_num = it->first;
//                 max_count = it->second;
//             }
//         }

//         return max_num;    
//     }
// };

// //对数组排序，数字出现的次数超过数组长度的一半，那么排完序后数组中点肯定是众数。
// //快排：时间复杂度O(NlogN)，空间复杂度O(logN)(递归的栈深度)
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         if(nums.empty()) return 0;
//         QuickSort(nums, 0, nums.size()-1);
//         return nums[nums.size()/2];
//     }

//     void QuickSort(vector<int>& nums, int left, int right)
//     {
//         if(left<right)
//         {
//             int pivot_position = Partition(nums, left, right);
//             QuickSort(nums, left, pivot_position-1);
//             QuickSort(nums, pivot_position+1, right);
//         }
//     }

//     int Partition(vector<int>& nums, int left, int right)
//     {
//         int pivot = nums[left];  //选择nums[left]作为要确定位置的pivot
//         while (left<right)
//         {
//             while(left<right && nums[right]>=pivot) right--;
//             nums[left] = nums[right];
//             while(left<right && nums[left]<=pivot) left++;
//             nums[right] = nums[left];
//         }
//         nums[left] = pivot;
//         return left;
//     }
// };

//摩尔投票法。当count=0时，设当前数为targe，如果下一个数字与target相等，则count++，如果不相等则count--,count减为0时，更换target
//最后target一定会大于0，因为题目假设数组中一定存在众数。
//时间复杂度O(N)，空间复杂度O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.empty()) return 0;
        int target = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if(count==0)
            {
                target = nums[i];
                count++;
            }
            else if(nums[i]==target) count++;
            else count--;
        }
        return target;

        // //如果题目没有说明一定存在多数元素，那么还要考虑不存在多数元素的情况，也就是没有元素出现的次数超过数组长度的一半
        // //需要遍历数组，判断target的出现次数是否超过数组长度一半
        // count = 0;
        // for(int num: nums)
        // {
        //     if(num==target) count++;
        // }
        // return count>nums.size()/2 ? target:0;       
    }

};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    Solution obj;
    int result = obj.majorityElement(nums);
    return 0;
}
