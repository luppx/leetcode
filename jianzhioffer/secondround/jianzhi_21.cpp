#include <vector>
using namespace std;

//辅助数组存储奇偶数，时间复杂度O(N)，空间复杂度O(N)
// class Solution {
// public:
//     vector<int> exchange(vector<int>& nums) {
//         vector<int> odd;
//         vector<int> even;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if(nums[i]%2) odd.push_back(nums[i]);
//             else even.push_back(nums[i]);
//         }
//         odd.insert(odd.end(), even.begin(), even.end());
//         return odd;
//     }
// };

//左右双指针，时间复杂度O(N)，空间复杂度O(1)
// class Solution {
// public:
//     vector<int> exchange(vector<int>& nums) {
//         int left = 0;
//         int right = nums.size()-1;
//         while (left<right)
//         {
//             if(nums[left]&1)
//             {
//                 left++;
//                 continue;
//             }
//             if((nums[right]&1) != 1)
//             {
//                 right--;
//                 continue;
//             }
//             swap(nums[left++],nums[right--]);  
//         }
//         return nums;
//     }
// };

//快慢指针，快指针找奇数位置，慢指针指下一个奇数要放置的位置
//(按理说慢指针应该指向下一个偶数的位置，但题解里直接slow++，也就是被交换的可能是奇数也可能是偶数，
//这样的话如果只有一个偶数，该方法要交换若干次，最差N-1次，而双指针法只用交换1次)
//时间复杂度O(N)，空间复杂度O(1)
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int slow = 0, fast=0;
        while (fast<nums.size())
        {
            if(nums[fast]&1)
            {
                swap(nums[slow], nums[fast]);
                slow++;
            }
            fast++;
        }
        
        return nums;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> n = {1,2,3,4};
    Solution obj;
    vector<int> result = obj.exchange(n);
    return 0;
}
