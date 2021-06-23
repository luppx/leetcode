#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string replaceSpace(string& s);
};

string Solution::replaceSpace(string& s)
{
    int n = s.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i]==' ')
        {
            count++;
        }
    }

    if(count==0) return s;
    s.resize(n+count*2);
    for (int i = n-1, j = n+count*2-1; i >= 0; i--, j--)
    {
        if(s[i]==' ')
        {
            s[j--] = '0';
            s[j--] = '2';
            s[j] = '%';
        }
        else
        {
            s[j] = s[i];
        }
        
    }
    return s;
}

int main()
{
    return 0;
}