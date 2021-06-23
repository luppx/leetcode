#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string reverseWords(string& s);

private:
    void removeExtraSpace(string& s, int start, int end);
    void reverse(string& s, int left, int right);
};

string Solution::reverseWords(string& s)
{
    int start = s.find_first_not_of(' ');
    int end = s.find_last_not_of(' ');
    if(start>end) return "";
    removeExtraSpace(s, start, end);
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        if(s[i]==' ') continue;
        int j=i;
        while (j<n && s[j]!=' ')
        {
            j++;
        }
        reverse(s, i, j-1);
        i=j;
    }
    reverse(s, 0, n-1);
    return s;
}

void Solution::removeExtraSpace(string& s, int start, int end)
{
    int slowIndex=0, fastIndex=start;
    while (fastIndex<=end)
    {
        while(fastIndex>0 && s[fastIndex]==' ' && s[fastIndex-1]==' ')
        {
            fastIndex++;
        }
        s[slowIndex++] = s[fastIndex++];
    }
    s.resize(slowIndex);
    return;
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
    string s = "   hello  world  ";
    Solution obj;
    string result = obj.reverseWords(s);
    cout<<result<<endl;
    return 0;
}