#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string solve(string s);
};

string Solution::solve(string s)
{
    if(s.size()<2) return s;
    int n = s.size();

    for (int i = 0; i < n/2; i++)
    {
        swap(s[i], s[n-i-1]);
    }
    return s;
}

int main()
{
    string s = "abcd";
    Solution obj;
    string result = obj.solve(s);
    cout<<result<<"\n";
    return 0;
}