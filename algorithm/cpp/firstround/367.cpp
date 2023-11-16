#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPerfectSquare(int num);
};

bool Solution::isPerfectSquare(int num)
{
    if(num<0) return false;
    else if(num==0 || num==1) return true;

    int low=0, high=num;
    while (low<=high)
    {
        long mid = low + ((high-low)>>1);
        if(mid*mid>num) high = mid-1;
        else if(mid*mid<num) low = mid+1;
        else return true;
    }
    return false;
}

int main()
{
    int num = 19;
    Solution obj;
    bool result = obj.isPerfectSquare(num);
    cout<<result<<endl;
    return 0;
}