#include <cstddef>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
        vector<vector<int>> threeSum(vector<int> nums);
};

vector<vector<int>> Solution::threeSum(vector<int> nums)
{
        vector<vector<int>> res = {}; 

        sort(nums.begin(), nums.end());
        for (int i = 0; i < ((int)nums.size()-2); i++)
        {
            if(nums[i]>0) break; //因为已经升序排序，如果第一个数字就已经大于0了，则a+b+c>0必然成立
            if(i>0 && nums[i]==nums[i-1]) continue; //如果重复，则之前已经计算过了，跳过
            int left = i+1, right = nums.size()-1;
            int target = -nums[i];
            while(left<right)
            {
                if(nums[left]+nums[right]<target)
                {
                    left++;
                }
                else if(nums[left]+nums[right]>target)
                {
                    right--;
                }
                else
                {
                    res.push_back({nums[i],nums[left],nums[right]});
                    
                    while(left<right && nums[left]==nums[left+1]) left++;
                    while(left<right && nums[right]==nums[right-1]) right--;
                    left++;
                    right--;
                }
                
            }
        }        
        return res;
}

int main()
{
    vector<int> nums = {1,-1,-2,1,0,2};
    Solution obj;
    vector<vector<int>> result = obj.threeSum(nums);
        return 0;
}

