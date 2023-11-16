#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string& s);

private:
    void recur(string&s, int index);
    bool isHuiWen(string&s, int start, int end);
    vector<string> path;
    vector<vector<string>> res;
};

vector<vector<string>> Solution::partition(string& s) {
    if(s.size()<2) return {{s}};
    recur(s, 0);
    return res;
}

void Solution::recur(string&s, int index)
{
    if(index>=s.size())
    {
        res.emplace_back(path);
        return;
    }

    for(int i=index; i<s.size(); i++)
    {
        if(isHuiWen(s, index, i))
        {
            path.emplace_back(s.substr(index,i-index+1));
            recur(s, i+1);
            path.pop_back();
        }
    }
    return;
}

bool Solution::isHuiWen(string& s, int start, int end)
{
    if(start==end) return true;
    int left=start, right=end;

    while(left<right)
    {
        if(s[left]!=s[right]) return false;
        left++;
        right--;
    }
    return true;
}