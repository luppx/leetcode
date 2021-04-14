#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution
{
public:
    int reverse(int x);
};

int Solution::reverse(int x)
{
    string origin = to_string(x);
    string res = "";
    string tmp = "";
    if(x<0)
    {
        res += "-";
        tmp = origin.substr(1, origin.size()-1);
    }
    else tmp = origin;
    
    res += tmp.back();

    for (int i = tmp.size()-2; i >=0; i--)
    {
        if (stol(res)<INT_MIN || stol(res)>INT_MAX)
        {
            return -1;
        }
        res += tmp[i];
    }
    return stoi(res);
}

int main()
{
    int x = -123;
    Solution obj;
    int result = obj.reverse(x);
    return 0;
}