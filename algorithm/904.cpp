#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int>& tree);
};

int Solution::totalFruit(vector<int>& tree)
{
    int n=tree.size();
    if(n<3) return n;

    int left=0, right=0;
    int ret=0;
    unordered_map<int, int> m;

    while (right<n)
    {
        if(m.size()<2 || m.find(tree[right])!=m.end())
        {
            m[tree[right]] = right;
        }
        else
        {
            ret = max(ret, right-left);

            auto iter = m.begin();
            int f1 = iter->first;
            int idx1 = iter->second;
            iter++;
            int f2 = iter->first;
            int idx2 = iter->second;
            left = min(idx1, idx2) + 1;

            if(idx1<idx2) m.erase(f1);
            else m.erase(f2);

            m[tree[right]] = right;
            
        }
        right++;
    }
    ret = max(ret, right-left);
    return ret;
}

int main()
{
    vector<int> tree = {1,2,3,2,2};
    Solution obj;
    int result = obj.totalFruit(tree);
    cout<<result<<endl;
    return 0;
}