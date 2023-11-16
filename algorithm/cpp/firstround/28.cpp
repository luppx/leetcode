#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int strStr(string& haystack, string& needle);

private:
    void getNext(int* next, string& str);
};

int Solution::strStr(string& haystack, string& needle)
{
    if(needle.empty()) return 0;

    int next[needle.size()];
    getNext(next, needle);

    int j=-1;
    for (int i = 0; i < haystack.size(); i++)
    {
        while(j>=0 && haystack[i]!=needle[j+1])
        {
            j = next[j];
        }
        if(haystack[i]==needle[j+1])
        {
            j++;
        }
        if(j==needle.size()-1)
        {
            return i-j;
        }
    }
    
    return -1;
}

void Solution::getNext(int* next, string& str)
{
    int j = -1;
    next[0] = j;

    for (int i = 1; i < str.size(); i++)
    {
        while(j>=0 && str[i]!=str[j+1])
        {
            j = next[j];
        }
        if(str[i]==str[j+1])
        {
            j++;
        }
        next[i] = j;
    }
    return ;
}

int main()
{
    string haystack = "hello";
    string needle = "ll";
    Solution obj;
    int result = obj.strStr(haystack, needle);
    cout<<result<<endl;
    return 0;
}