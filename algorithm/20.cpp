#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    bool isValid(string& s);
};

bool Solution::isValid(string& s)
{
    if(s.empty()) return true;
    int n = s.size();
    if(n&1) return false; //奇数个括号，肯定不匹配

    stack<char> stk;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='(' || s[i]=='[' || s[i]=='{') stk.push(s[i]);
        else
        {
            if(stk.empty()) return false;
            char tmp = stk.top();

            if((s[i]==')' && tmp=='(') || (s[i]==']' && tmp=='[') || (s[i]=='}' && tmp=='{'))
            {
                stk.pop();
            }
            else return false;
        }
    }
    return stk.empty();
}

int main()
{
    return 0;
}