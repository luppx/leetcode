#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int kmp(string& pattern, string& text);

private:
    vector<int> getNexts(string& pattern);
};

int Solution::kmp(string& pattern, string& text)
{
    if(text.empty() || pattern.size()>text.size()) return 0;

    vector<int> next = getNexts(pattern);

    int res = 0;
    int j=0;
    for (int i = 0; i < text.size(); i++)
    {
        while (j>0 && text[i]!=pattern[j])
        {
            j = next[j-1]+1;
        }

        if(text[i]==pattern[j]) j++;
        if(j==pattern.size()) res++;
    }
    return res;
}

vector<int> Solution::getNexts(string& pattern)
{
    int n = pattern.size();
    vector<int> next(n, -1);

    int k=-1;
    for (int i = 1; i < n; i++)
    {
        while (k!=-1 && pattern[k+1]!=pattern[i])
        {
            k = next[k];
        }
        
        if(pattern[k+1]==pattern[i]) k++;
        next[i] = k;
    }
    return next;
}

int main()
{
    string text = "abababab";
    string pattern = "ababab";
    Solution obj;
    int result = obj.kmp(pattern, text);
    return 0;
}