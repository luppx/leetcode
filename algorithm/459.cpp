#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool repeatedSubstringPattern(string& s);

private:
    void getNext(int* next, string& str);
};

bool Solution::repeatedSubstringPattern(string& s)
{
    if(s.empty()) return false;

    int n = s.size();
    int next[n];
    getNext(next, s);

    if(next[n-1]!=-1 && (n % (n-next[n-1]-1)==0))
    {
        return true;
    }
    return false;
}

void Solution::getNext(int* next, string& str)
{
    int j=-1;
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
    string str = "abcabcabcabc";
    Solution obj;
    bool result = obj.repeatedSubstringPattern(str);
    cout<<result<<endl;
    return 0;
}