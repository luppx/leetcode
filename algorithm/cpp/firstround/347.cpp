#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k);
};

vector<int> Solution::topKFrequent(vector<int>& nums, int k)
{
    int n = nums.size();
    if(n<1 || k<1) return {};
    else if(n<2) return nums;

    vector<int> res;
    unordered_map<int, int> umap;

    struct compare
    {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b)
        {
            return a.second>b.second;
        }
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> que;

    for(int i=0; i<n; i++)
    {
        umap[nums[i]]++;
    }

    for(auto it=umap.begin(); it!=umap.end(); it++)
    {
        que.push(*it);
        if(que.size()>k)
        {
            que.pop();
        }
    }
    
    while(!que.empty())
    {
        res.emplace_back(que.top().first);
        que.pop();
    }
    
    return res;
}

int main()
{
    vector<int> nums = {5,2,5,3,5,3,1,1,3};
    int k = 2;
    Solution obj;
    vector<int> result = obj.topKFrequent(nums, k);
    return 0;
}