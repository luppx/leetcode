#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char>& s);
};

void Solution::reverseString(vector<char>& s)
{
    int n = s.size();
    if(n<2) return ;

    int left=0, right=n-1;
    while (left<right)
    {
        swap(s[left], s[right]);
        left++;
        right--;
    }
    return ;
}

int main()
{
    return 0;
}