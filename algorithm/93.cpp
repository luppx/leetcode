#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string& s);

private:
    void recur(string& s, int index, int count);
    vector<string> res;
    string cur;
};

vector<string> Solution::restoreIpAddresses(string& s) {
    if(s.size()<4 || s.size()>12) return {};

    recur(s, 0, 0);
    return res;
}

void Solution::recur(string& s, int index, int count)
{
    if(count==4)
    {
        if(index>=s.size())
        {
            res.emplace_back(cur);
            res.back().pop_back(); //把结尾的最后一个"."给去掉
        }
        return;
    }

    bool firstIsZero = false;
    for(int i=index; i<(s.size()-(4-count)+1); i++)  //得给后面每一段至少留一个数
    {
        string tmp = s.substr(index, i-index+1);
        if(stoi(tmp)>255) break;
        if(i==index && s[i]=='0') firstIsZero=true;
        cur += tmp + ".";
        recur(s, i+1, count+1);
        for(int j=0; j<=tmp.size(); j++)  //要多退一位，因为最后多加了个"."
        {
            cur.pop_back();
        }
        if(firstIsZero) break;
    }
    return;
}