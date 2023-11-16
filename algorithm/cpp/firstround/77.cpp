#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k);

private:
    void recur(int start);
    vector<vector<int>> res;
    vector<int> cur;
    int n;
    int k;
};

vector<vector<int>> Solution::combine(int n, int k) {
    if(k>n) return {};
    else if(n==k)
    {
        vector<int> tmp;
        for(int i=1; i<=n; i++)
        {
            tmp.emplace_back(i);
        }
        return {tmp};
    }

    this->n = n;
    this->k = k;
    recur(1);
    return res;
}

void Solution::recur(int start)
{
    if(cur.size()==k)
    {
        res.emplace_back(cur);
        return;
    }

    int end = n-(k-cur.size())+1;
    for(int i=start; i<=end; i++)
    {
        cur.emplace_back(i);
        recur(i+1);
        cur.pop_back();
    }
    return ;
}
int main()
{
    int n = 4;
    int k = 2;
    Solution obj;
    vector<vector<int>> result = obj.combine(n, k);
    return 0;
}