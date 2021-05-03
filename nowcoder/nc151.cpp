#include <iostream>
using namespace std;

class Solution
{
public:
    int gcd(int a, int b);
};

int Solution::gcd(int a, int b)
{
    if(a%b==0) return b;
    else return gcd(b, a%b);
}

int main()
{
    int a = 3;
    int b = 6;
    Solution obj;
    int result = obj.gcd(a, b);
    return 0;
}