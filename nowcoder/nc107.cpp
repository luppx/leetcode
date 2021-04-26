#include <vector>
using namespace std;

class Solution
{
public:
    int solve(int* a, int n);
};

int Solution::solve(int* a, int n)
{
    if(n<1) return -1;
    else if(n<2) return a[0];

    int res_idx = -1;
    if(a[0]>=a[1]) res_idx=0;
    if(a[n-1]>=a[n-2]) return n-1;
    for (int i = 1; i < n-1; i++)
    {
        if(a[i]>=a[i-1] && a[i]>=a[i+1])
        {
            res_idx = i;
        }
    }
    return res_idx;
}