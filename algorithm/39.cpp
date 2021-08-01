#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);

private:
    void recur(vector<int>& candidates, int startIndex, int sum);
    int target;
    vector<vector<int>> res;
    vector<int> path;
};

vector<vector<int>> Solution::combinationSum(vector<int>& candidates, int target) {
    if(candidates.empty()) return {};
    sort(candidates.begin(), candidates.end());
    if(target<candidates.front()) return {};
    this->target = target;
    recur(candidates, 0, 0);
    return res;
}

void Solution::recur(vector<int>& candidates, int startIndex, int sum)
{
    if(sum==target)
    {
        res.emplace_back(path);
        return;
    }
    
    for(int i=startIndex; i<candidates.size(); i++)
    {
        if(sum+candidates[i]>target) return;  //剪枝
        path.emplace_back(candidates[i]);
        recur(candidates, i, sum+candidates[i]);
        path.pop_back();
    }
    return;
}

int main()
{
    vector<int> candidates = {7,3,9,6};
    int target = 6;
    Solution obj;
    vector<vector<int>> result = obj.combinationSum(candidates, target);
    return 0;
}