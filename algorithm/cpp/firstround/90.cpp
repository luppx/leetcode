#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums);

private:
    void recur(vector<int>& nums, int startIndex);
    vector<vector<int>> res;
    vector<int> cur;
};

vector<vector<int>> Solution::subsetsWithDup(vector<int>& nums) {
    if(nums.empty()) return {};

    sort(nums.begin(), nums.end());
    recur(nums, 0);
    return res;
}

void Solution::recur(vector<int>& nums, int startIndex)
{
    res.emplace_back(cur);
    if(startIndex>=nums.size())
    {
        return;
    }

    for(int i=startIndex; i<nums.size(); i++)
    {
        if(i>startIndex && nums[i]==nums[i-1])
        {
            continue;
        }

        cur.emplace_back(nums[i]);
        recur(nums, i+1);
        cur.pop_back();
    }
    return;
}

int main()
{
    vector<int> nums = {1,2,2};
    Solution obj;
    vector<vector<int>> result = obj.subsetsWithDup(nums);
    return 0;
}