#include <string>
using namespace std;

class Solution
{
public:
    bool backspaceCompare(string& s, string& t);

private:
    int processBackSpace(string& str);
};

bool Solution::backspaceCompare(string& s, string& t)
{
    int n_s = processBackSpace(s);
    int n_t = processBackSpace(t);
    if(n_s!=n_t) return false;

    for (int i = 0; i < n_s; i++)
    {
        if(s[i]!=t[i]) return false;
    }
    return true;
}

int Solution::processBackSpace(string &str)
{
    if(str.empty()) return 0;
    int n = str.size();
    int slowIndex = 0;
    for (int fastIndex = 0; fastIndex < n; fastIndex++)
    {
        if (str[fastIndex]=='#')
        {
            slowIndex = max(0, slowIndex-1);
        }
        else
        {
            str[slowIndex] = str[fastIndex];
            slowIndex++;
        }
    }
    return slowIndex;
}

int main()
{
    string s = "a##bc";
    string t = "d#b###bc";
    Solution obj;
    bool result = obj.backspaceCompare(s, t);
    return 0;
}