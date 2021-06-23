#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string reverseStr(string& s, int k);
};

string Solution::reverseStr(string& s, int k)
{
    int n = s.size();
    if(n<2 || k<1) return s;

    for (int i = 0; i < n; i+=k*2)
    {
        int left=i, right=i;
        if (n-i<k)
        {
            right = n-1;
        }
        else
        {
            right = left+k-1;
        }
        
        while (left<right)
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    return s;
}

int main()
{
    return 0;
}