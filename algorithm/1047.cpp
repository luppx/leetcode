#include <stack>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string& s);
};

string Solution::removeDuplicates(string& s)
{
    int n = s.size();
    if(n<2) return s;

    string res = "";
    for (auto ch : s)
    {
        if(res.empty() || res.back()!=ch) res.push_back(ch);
        else res.pop_back();
    }
    return res;
}

int main()
{
    return 0;
}