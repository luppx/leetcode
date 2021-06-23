#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string reverseLeftWords(string& s, int n);

private:
    void reverse(string& s, int left, int right);
};

string Solution::reverseLeftWords(string& s, int n)
{
    int size = s.size();
    if(size<2 || n<1 || n>=size) return s;
    reverse(s, 0, n-1);
    reverse(s, n, size-1);
    reverse(s, 0, size-1);
    return s;
}

void Solution::reverse(string& s, int left, int right)
{
    while (left<right)
    {
        swap(s[left++], s[right--]);
    }
    return ;
}

int main()
{
    return 0;
}