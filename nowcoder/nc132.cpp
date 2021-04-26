#include <iostream>
using namespace std;

class Solution
{
public:
    int ysf(int n, int m);
};

int Solution::ysf(int n, int m)
{
    int x=0;
    for (int i = 2; i <= n; i++)
    {
        x = (x+m)%i;
    }
    return x+1;
}

int main()
{
    int n = 5;
    int m = 2;
    Solution obj;
    int result = obj.ysf(n,m);
    return 0;
}