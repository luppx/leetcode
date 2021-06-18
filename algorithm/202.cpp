#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool isHappy(int n);
};


bool Solution::isHappy(int n)
{
    unordered_set<int> set;
    int num = n;
    while (num!=1)
    {
        int sum=0;
        while (num>0)
        {
            int x = num%10;
            sum += x*x;
            num /= 10;
        }
        num=sum;
        if (set.find(num)!=set.end())
        {
            return false;
        }
        set.insert(num);
    }
    return true;
}

int main()
{
    int n = 19;
    Solution obj;
    bool result = obj.isHappy(n);
    return 0;
}