#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s);
};

int Solution::findContentChildren(vector<int>& g, vector<int>& s) {
    if(s.empty() || g.empty()) return 0;

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int res = 0;
    int i=0, j=0;
    while(i<g.size() && j<s.size())
    {
        if(s[j]>=g[i])
        {
            res++;
            i++;
            j++;
        }
        else j++;
    }
    return res;
}