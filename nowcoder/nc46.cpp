#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &num, int target);

private:
    void dfs(vector<int> &num, vector<int>& path, int sum, int cur_idx);
    int target;
    int size;
    vector<vector<int>> paths;
};

vector<vector<int>> Solution::combinationSum2(vector<int> &num, int target)
{
    if(num.empty()) return {};

    this->target = target;
    this->size = num.size();
    this->paths = {};
    vector<int> path = {};
    vector<int> indexs = {};
    sort(num.begin(), num.end());
    dfs(num, path, 0, 0);
    return paths;
}

void Solution::dfs(vector<int> &num, vector<int>& path, int sum, int cur_idx)
{
    if(sum==target)
    {
        paths.push_back(path);
        return;
    }

    for (int i = cur_idx; i < size; i++)
    {
        if(i>cur_idx && num[i]==num[i-1]) continue; //去重
        if(sum+num[i]>target) break;  //剪枝
        path.push_back(num[i]);
        dfs(num, path, sum+num[i], i+1);
        path.pop_back();
    }
    return ;
}

int main()
{
    vector<int> num = {100,10,20,70,60,10,50};
    int target = 80;
    Solution obj;
    vector<vector<int>> reuslt = obj.combinationSum2(num, target);
    return 0;
}