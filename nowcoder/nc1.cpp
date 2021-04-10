#include <iostream>
#include <cstring>
using namespace std;

class Solution
{
public:
    string solve(string s, string t);
};

string Solution::solve(string s, string t)
{
    if(s.empty()) return t;
    else if(t.empty()) return s;


    int carry = 0;
    if(s.size()>=t.size())
    {
        int i=t.size()-1, j=s.size()-1;
        for (; i>=0 ; i--,j--)
        {
            int sum = s[j]-'0' + t[i]-'0' + carry;
            s[j] = sum%10 + '0';
            carry = sum/10;
        }
        
        if(carry==0) return s;
        else
        {
            while (j>=0 && carry>0)
            {
                int sum = s[j] + carry - '0';
                s[j] = sum%10 + '0';
                carry = sum/10;
                j--;
            }
            if(j<0 && carry>0) return "1"+s;
            else return s;
        }
    }
    else
    {
        int i=t.size()-1, j=s.size()-1;
        for (; j>=0 ; i--,j--)
        {
            int sum = s[j]-'0' + t[i]-'0' + carry;
            t[i] = sum%10 + '0';
            carry = sum/10;
        }
        
        if(carry==0) return t;
        else
        {
            while (i>=0 && carry>0)
            {
                int sum = t[i] + carry - '0';
                t[i] = sum%10 + '0';
                carry = sum/10;
                i--;
            }
            if(i<0 && carry>0) return "1"+t;
            else return t;
        }
    }
}

int main()
{
    string s = "1";
    string t = "99";
    Solution obj;
    string result = obj.solve(s,t);
    cout<<result<<endl;
    return 0;
}