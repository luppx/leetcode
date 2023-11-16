#include <string>
#include <iostream>
using namespace std;

//方法一，中心扩展法。遍历字符串，以每个字符作为中心(回文串长度为奇数的情况)，或者以当前字符和下一个字符之间作为回文串中心(回文串长度为偶数)
//判断每个字符的回文串长度，然后求最长回文子串。
//时间复杂度O(N^2)，空间复杂度O(1)
class Solution
{
public:
    string longestPalindrome(string& s);

private:
    int getsubPalindromeLen(string& s, int left, int right);
};

string Solution::longestPalindrome(string& s)
{
    if(s.size()<2) return s;

    int left=0, right=0;
    int maxLen=0;
    for (int i = 0; i < s.size(); i++)
    {
        int len1 = getsubPalindromeLen(s, i, i);
        int len2 = getsubPalindromeLen(s, i, i+1);
        maxLen = max(len1, len2);
        if(maxLen>right-left+1)
        {
            left = i - (maxLen-1)/2;
            right = i + maxLen/2;
        }
    }
    return s.substr(left, right-left+1);
}

int Solution::getsubPalindromeLen(string& s, int left, int right)
{
    while (left>=0 && right<s.size() && s[left]==s[right])
    {
        left--;
        right++;
    }
    return right-left-1;
}

int main()
{
    string s = "ac";
    Solution obj;
    string result = obj.longestPalindrome(s);
    cout<<result<<endl;
    return 0;
}