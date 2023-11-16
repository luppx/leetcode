#include <vector>
using namespace std;

class Solution
{
public:
    int mySqrt(int x);
};

//找最后一个小于等于给定值的元素
int Solution::mySqrt(int x)
{
    if(x<0) return -1;
    int low=0, high = x;
    while (low<=high)
    {
        long mid = low + ((high-low)>>1);
        if(mid*mid<=x)
        {
            if(mid==x || ((mid+1)*(mid+1)>x)) return mid;
            else low = mid+1;
        }
        else high = mid-1;
    }
    return -1;
}

int main()
{
    int x = 8;
    Solution obj;
    int result = obj.mySqrt(x);
    return 0;
}