#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    string minWindow(string& s, string& t);
};

string Solution::minWindow(string& s, string& t)
{
    if(s.empty() || t.empty()) return "";

    int m=s.size();
    int n=t.size();
    string res = "";

    unordered_map<char, int> map_s, map_t;
    for (int i = 0; i < n; i++)
    {
        map_t[t[i]]++;
        map_s[t[i]] = 0;
    }
    
    int left=0, right=0;
    int count=0;

    while(left<m && map_s.find(s[left])==map_s.end()) left++;
    right = left+1;
    map_s[s[left]]++;
    count++;

    while (right<=m)
    {
        if(count<n)
        {
            if(right==m) break;
            if(map_s.find(s[right])!=map_s.end())
            {
                if(map_s[s[right]]<map_t[s[right]]) count++;
                map_s[s[right]]++;
            }
            right++;
        }
        else
        {
            if(res.empty() || res.size()>(right-left))
            {
                res = s.substr(left, right-left);
            }

            char target = s[left];
            map_s[target]--;
            left++;
            while(left<right && map_s.find(s[left])==map_s.end()) left++;
            
            if(map_s[target]<map_t[target])
            {
                count--;
            }
        }
    }
    return res;
}

int main()
{
    string s,t;
    cin>>s>>t;
    Solution obj;
    string result = obj.minWindow(s, t);
    cout<<result<<endl;
    return 0;
}