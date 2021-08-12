#include <vector>
#include <algorithm>
using namespace std;

// class Solution {
// public:
//     vector<vector<int>> permuteUnique(vector<int>& nums);

// private:
//     void recur(vector<int>& nums, int startIndex);
//     vector<vector<int>> res;
//     vector<int> path;
// };

// vector<vector<int>> Solution::permuteUnique(vector<int>& nums) {
//     if(nums.empty()) return {};
//     else if(nums.size()==1)
//     {
//         res.emplace_back(nums);
//         return res;
//     }

//     recur(nums, 0);
//     return res;
// }

// void Solution::recur(vector<int>& nums, int startIndex)
// {
//     if(startIndex>=nums.size())
//     {
//         res.emplace_back(path);
//         return;
//     }

//     bool used[21] = {0};

//     for(int i=startIndex; i<nums.size(); i++)
//     {
//         if(used[nums[i]+10]==true) continue;
//         used[nums[i]+10] = true;
        
//         swap(nums[startIndex], nums[i]);
//         path.emplace_back(nums[startIndex]);
        
//         recur(nums, startIndex+1);
        
//         swap(nums[startIndex], nums[i]);
//         path.pop_back();
//     }
//     return;
// }

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums);

private:
    void recur(vector<int>& nums, vector<bool>& used);
    vector<vector<int>> res;
    vector<int> path;
};

vector<vector<int>> Solution::permuteUnique(vector<int>& nums) {
    if(nums.empty()) return {};
    else if(nums.size()==1)
    {
        res.emplace_back(nums);
        return res;
    }

    sort(nums.begin(), nums.end());
    vector<bool> used(nums.size(), 0);
    recur(nums, used);
    return res;
}

void Solution::recur(vector<int>& nums, vector<bool>& used)
{
    if(path.size()==nums.size())
    {
        res.emplace_back(path);
        return;
    }

    for(int i=0; i<nums.size(); i++)
    {
        if(used[i] || (i>0 && nums[i]==nums[i-1] && used[i-1]==false)) continue;

        used[i]=true;
        path.emplace_back(nums[i]);

        recur(nums, used);

        used[i]=false;
        path.pop_back();
    }
    return;
}