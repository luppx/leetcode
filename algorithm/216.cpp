#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n);

private:
    void recur(int startIndex, int curSum);
    vector<int> cur;
    vector<vector<int>> res;
    int n;
    int k;
};

vector<vector<int>> Solution::combinationSum3(int k, int n) {
    if(n<k) return {};

    this->k = k;
    this->n = n;
    recur(1,0);
    return res;
}

void Solution::recur(int startIndex, int curSum)
{
    if(curSum>n || cur.size()>k) return;
    else if(curSum==n)
    {
        if(cur.size()==k) res.emplace_back(cur);
        return;
    }

    for(int i=startIndex; i<=min(n-curSum+1, 9); i++)
    {
        cur.emplace_back(i);
        recur(i+1, curSum+i);
        cur.pop_back();
    }
    return;
}