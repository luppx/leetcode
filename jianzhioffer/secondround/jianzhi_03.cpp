# include <vector>
# include <unordered_map>

using namespace std;

// 方法一，用哈希表记录数组的各个数字，查到重复数字时直接返回。
// 时间复杂度O(n)，空间复杂度O(n)
// class Solution {
// public:
//     int findRepeatNumber(vector<int>& nums) {
//         unordered_map<int, bool> map;
//         for (int num: nums)
//         {
//             if (map[num])
//             {
//                 return num;
//             }
//             map[num] = true;
//         }
        
//         return -1;
//     }
// };

// 方法二：原地交换
// 题目说明尚未被充分使用，即 在一个长度为n的数组nums里的所有数字都在0~n-1的范围内。说明数组元素的索引和值是一对多的关系。
// 因此，可遍历数组并通过交换操作，使元素的索引与值一一对应(即nums[i]=i)，因而，就能通过索引映射对应的值，起到与字典等价的作用。
// 遍历中，第一次遇到数字xxx时，将其交换至索引xxx处；而当第二次遇到数字xxx时，一定有nums[x]=x，此时即可得到一组重复数字。
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] == i)
            {
                i++;
                continue;
            }
            if (nums[nums[i]] == nums[i])
            {
                return nums[i];
            }

            swap(nums[i], nums[nums[i]]);          
        } 
        return -1;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(3);
    Solution obj;
    int result = obj.findRepeatNumber(nums);
    return 0;
}
