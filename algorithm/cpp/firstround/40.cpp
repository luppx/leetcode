#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target);

private:
    void recur(vector<int>& candidates, int target, int startIndex, int sum);
    vector<int> path;
    vector<vector<int>> res;
};

vector<vector<int>> Solution::combinationSum2(vector<int>& candidates, int target) {
    if(candidates.empty()) return {};

    sort(candidates.begin(), candidates.end());
    if(target<candidates.front()) return {};
    recur(candidates, target, 0, 0);
    return res;
}

void Solution::recur(vector<int>& candidates, int target, int startIndex, int sum)
{
    if(sum==target)
    {
        res.emplace_back(path);
        return;
    }

    for(int i=startIndex; i<candidates.size() && (sum+candidates[i]<=target); i++)
    {
        if(i>startIndex && candidates[i]==candidates[i-1]) continue;
        path.emplace_back(candidates[i]);
        recur(candidates, target, i+1, sum+candidates[i]);
        path.pop_back();
    }
    return;
}