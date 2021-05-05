#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> restoreIpAddresses(string& s);

private:
    void dfs(string& str, string& ip, int idx, int pointCount);
    int strSize;
    vector<string> res;
};

vector<string> Solution::restoreIpAddresses(string& s)
{
    strSize = s.size();
    if(strSize<4) return {};

    res = {};
    string tmp = "";
    dfs(s, tmp, 0, 0);
    return res;
}

void Solution::dfs(string& str, string& ip, int idx, int pointCount)
{
    if(idx==strSize || ((strSize-idx)>(4-pointCount)*3)) return;

    if(str[idx]=='0')
    {
        if(pointCount<3)
        {
            ip += "0.";
            dfs(str, ip, idx+1, pointCount+1);
            ip.pop_back();
            ip.pop_back();
            return;
        }
        else if(pointCount==3 && idx+1==strSize)
        {
            res.push_back(ip+"0");
            return;
        }
        else return;
    }

    string tmp = "";
    if(pointCount<3)
    {
        for (int i = 0; i < 3 && ((idx+i)<strSize); i++)
        {
            tmp.push_back(str[idx+i]);
            if(stoi(tmp)<256)
            {
                ip += tmp + ".";
                dfs(str, ip, idx+i+1, pointCount+1);
                for (int j = i+1; j >= 0; j--)
                {
                    ip.pop_back(); //多一次循环，以去掉"."
                }
            }
            else break;
        }
    }
    else if(pointCount==3 && strSize-idx<=3)
    {
        tmp = str.substr(idx);
        if(stoi(tmp)<256)
        {
            res.push_back(ip+tmp);
            return;
        }
    }
    return ;
}

int main()
{
    string s = "1040";
    Solution obj;
    vector<string> result = obj.restoreIpAddresses(s);
    return 0;
}