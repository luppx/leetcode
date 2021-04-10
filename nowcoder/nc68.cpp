#include <iostream>
using namespace std;

class Solution
{
public:
    int jumpFloor(int number);
};

int Solution::jumpFloor(int number)
{
    if(number<1) return 0;
    else if(number==1) return 1;
    else if(number==2) return 2;

    int a=1, b=2;
    int c=0;
    for (int i = 3; i <= number; i++)
    {
        c = a+b;
        a = b;
        b = c;
    }
    return c;
}