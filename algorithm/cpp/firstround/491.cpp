#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums);

private:
    void recur(vector<int>& nums, int startIndex);
    vector<vector<int>> res;
    vector<int> path;
};

vector<vector<int>> Solution::findSubsequences(vector<int>& nums) {
    if(nums.size()<2) return {};
    
    recur(nums, 0);
    return res;
}

void Solution::recur(vector<int>& nums, int startIndex)
{
    if(path.size()>1) res.emplace_back(path);
    if(startIndex>=nums.size()) return;

    // unordered_map<int, bool> umap;
    bool used[201] = {0};
    for(int i=startIndex; i<nums.size(); i++)
    {
        // if(umap.find(nums[i])!=umap.end()) continue;
        // umap[nums[i]]=true;
        if((used[nums[i]+100]==true) || !path.empty() && nums[i]<path.back()) continue;
        used[nums[i]+100] = true;
        path.emplace_back(nums[i]);
        recur(nums, i+1);
        path.pop_back();
    }
    return;
}

int main()
{
    vector<int> nums = {4,6,7,7};
    Solution obj;
    vector<vector<int>> result = obj.findSubsequences(nums);
    for (int i=0; i<result.size(); i++)
    {
        for(int j=0; j<result[i].size(); j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}