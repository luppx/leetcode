#include <string>
using namespace std;

class Solution
{
public:
    string solve(string s, string t);
};

string Solution::solve(string s, string t)
{
    if(s.empty() || t.empty()) return "0";

    int m = s.size();
    int n = t.size();
    string res(m+n, '0');
    for (int i = m-1; i >= 0; i--)
    {
        for (int j = n-1; j >= 0; j--)
        {
            int cur = (res[i+j+1]-'0') + (s[i]-'0') * (t[j]-'0');
            res[i+j+1] = (cur % 10) + '0';
            res[i+j] += (cur/10);
        }
    }

    int idx = res.find_first_not_of('0');
    if(idx==s.npos) return "0";
    res = res.substr(idx);
    return res;
}

int main()
{
    string s = "0";
    string t = "99";
    Solution obj;
    string result = obj.solve(s, t);
    return 0;
}