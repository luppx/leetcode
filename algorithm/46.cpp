#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums);

private:
    void recur(vector<int>& nums, int startIndex);
    vector<vector<int>> res;
    vector<int> path;
};

vector<vector<int>> Solution::permute(vector<int>& nums) {
    if(nums.empty()) return {};

    recur(nums, 0);
    return res;
}

void Solution::recur(vector<int>& nums, int startIndex)
{
    if(startIndex>=nums.size())
    {
        res.emplace_back(path);
        return;
    }

    for(int i=startIndex; i<nums.size(); i++)
    {
        swap(nums[startIndex], nums[i]);
        path.emplace_back(nums[startIndex]);
        recur(nums, startIndex+1);
        swap(nums[startIndex], nums[i]);
        path.pop_back();
    }
    return;
}