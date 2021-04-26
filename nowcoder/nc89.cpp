#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string trans(string s, int n);
};

string Solution::trans(string s, int n)
{
    if(n<1) return s;
    
    string res = "";

    for (int i = n-1; i >= 0; )
    {
        int j = i;
        while (j>=0 && s[j]!=' ')
        {
            if(s[j]>='a' && s[j]<='z') s[j] -= 32;
            else if(s[j]>='A' && s[j]<='Z') s[j] += 32;
            j--;
        }
        
        for (int k = j+1; k <= i; k++)
        {
            res += s[k];
        }
        if(j>=0) res += s[j];
        i = j-1;        
    }
    return res;
}

int main()
{
    string strs = " I H";
    //string strs = "    ";
    Solution obj;
    string result = obj.trans(strs, strs.size());
    return 0;
}